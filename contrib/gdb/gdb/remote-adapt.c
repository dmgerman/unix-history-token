begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* OBSOLETE /* Remote debugging interface for AMD 290*0 Adapt Monitor Version 2.1d18.  */
end_comment

begin_comment
comment|/* OBSOLETE    Copyright 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1998, 1999, 2000, */
end_comment

begin_comment
comment|/* OBSOLETE    2001 Free Software Foundation, Inc. */
end_comment

begin_comment
comment|/* OBSOLETE    Contributed by David Wood at New York University (wood@lab.ultra.nyu.edu). */
end_comment

begin_comment
comment|/* OBSOLETE    Adapted from work done at Cygnus Support in remote-eb.c. */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE    This file is part of GDB. */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE    This program is free software; you can redistribute it and/or modify */
end_comment

begin_comment
comment|/* OBSOLETE    it under the terms of the GNU General Public License as published by */
end_comment

begin_comment
comment|/* OBSOLETE    the Free Software Foundation; either version 2 of the License, or */
end_comment

begin_comment
comment|/* OBSOLETE    (at your option) any later version. */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE    This program is distributed in the hope that it will be useful, */
end_comment

begin_comment
comment|/* OBSOLETE    but WITHOUT ANY WARRANTY; without even the implied warranty of */
end_comment

begin_comment
comment|/* OBSOLETE    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
end_comment

begin_comment
comment|/* OBSOLETE    GNU General Public License for more details. */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE    You should have received a copy of the GNU General Public License */
end_comment

begin_comment
comment|/* OBSOLETE    along with this program; if not, write to the Free Software */
end_comment

begin_comment
comment|/* OBSOLETE    Foundation, Inc., 59 Temple Place - Suite 330, */
end_comment

begin_comment
comment|/* OBSOLETE    Boston, MA 02111-1307, USA.  */
end_comment

begin_expr_stmt
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* This is like remote.c but is for an esoteric situation-- */
comment|/* OBSOLETE    having a 29k board attached to an Adapt inline monitor.  */
comment|/* OBSOLETE    The  monitor is connected via serial line to a unix machine  */
comment|/* OBSOLETE    running gdb.  */
comment|/* OBSOLETE  */
comment|/* OBSOLETE    3/91 -  developed on Sun3 OS 4.1, by David Wood */
comment|/* OBSOLETE    o - I can't get binary coff to load.  */
comment|/* OBSOLETE    o - I can't get 19200 baud rate to work.  */
comment|/* OBSOLETE    7/91 o - Freeze mode tracing can be done on a 29050.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE  */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #include "defs.h" */
comment|/* OBSOLETE #include "gdb_string.h" */
comment|/* OBSOLETE #include "inferior.h" */
comment|/* OBSOLETE #include "value.h" */
comment|/* OBSOLETE #include<ctype.h> */
comment|/* OBSOLETE #include<fcntl.h> */
comment|/* OBSOLETE #include<signal.h> */
comment|/* OBSOLETE #include<errno.h> */
comment|/* OBSOLETE #include "terminal.h" */
comment|/* OBSOLETE #include "target.h" */
comment|/* OBSOLETE #include "gdbcore.h" */
comment|/* OBSOLETE #include "regcache.h" */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* This processor is getting rusty but I am trying to keep it */
comment|/* OBSOLETE    up to date at least with data structure changes. */
comment|/* OBSOLETE    Activate this block to compile just this file. */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE #define COMPILE_CHECK 0 */
comment|/* OBSOLETE #if COMPILE_CHECK */
comment|/* OBSOLETE #define Q_REGNUM 0 */
comment|/* OBSOLETE #define VAB_REGNUM 0 */
comment|/* OBSOLETE #define CPS_REGNUM 0 */
comment|/* OBSOLETE #define IPA_REGNUM 0 */
comment|/* OBSOLETE #define IPB_REGNUM 0 */
comment|/* OBSOLETE #define GR1_REGNUM 0 */
comment|/* OBSOLETE #define LR0_REGNUM 0 */
comment|/* OBSOLETE #define IPC_REGNUM 0 */
comment|/* OBSOLETE #define CR_REGNUM 0 */
comment|/* OBSOLETE #define BP_REGNUM 0 */
comment|/* OBSOLETE #define FC_REGNUM 0 */
comment|/* OBSOLETE #define INTE_REGNUM 0 */
comment|/* OBSOLETE #define EXO_REGNUM 0 */
comment|/* OBSOLETE #define GR96_REGNUM 0 */
comment|/* OBSOLETE #define NPC_REGNUM */
comment|/* OBSOLETE #define FPE_REGNUM 0 */
comment|/* OBSOLETE #define PC2_REGNUM 0 */
comment|/* OBSOLETE #define FPS_REGNUM 0 */
comment|/* OBSOLETE #define ALU_REGNUM 0 */
comment|/* OBSOLETE #define LRU_REGNUM 0 */
comment|/* OBSOLETE #define TERMINAL int */
comment|/* OBSOLETE #define RAW 1 */
comment|/* OBSOLETE #define ANYP 1 */
comment|/* OBSOLETE extern int a29k_freeze_mode; */
comment|/* OBSOLETE extern int processor_type; */
comment|/* OBSOLETE extern char *processor_name; */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* External data declarations */
operator|*
operator|/
comment|/* OBSOLETE extern int stop_soon_quietly;	/* for wait_for_inferior */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Forward data declarations */
operator|*
operator|/
comment|/* OBSOLETE extern struct target_ops adapt_ops;	/* Forward declaration */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Forward function declarations */
operator|*
operator|/
comment|/* OBSOLETE static void adapt_fetch_registers (); */
comment|/* OBSOLETE static void adapt_store_registers (); */
comment|/* OBSOLETE static void adapt_close (); */
comment|/* OBSOLETE static int adapt_clear_breakpoints (); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #define FREEZE_MODE 	(read_register(CPS_REGNUM)&& 0x400) */
comment|/* OBSOLETE #define USE_SHADOW_PC	((processor_type == a29k_freeze_mode)&& FREEZE_MODE) */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Can't seem to get binary coff working */
operator|*
operator|/
comment|/* OBSOLETE #define ASCII_COFF		/* Adapt will be downloaded with ascii coff */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* FIXME: Replace with `set remotedebug'.  */
operator|*
operator|/
comment|/* OBSOLETE #define LOG_FILE "adapt.log" */
comment|/* OBSOLETE #if defined (LOG_FILE) */
comment|/* OBSOLETE FILE *log_file = NULL; */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE  */
comment|/* OBSOLETE static int timeout = 5; */
comment|/* OBSOLETE static char *dev_name; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Descriptor for I/O to remote machine.  Initialize it to -1 so that */
comment|/* OBSOLETE    adapt_open knows that we don't have a file open when the program */
comment|/* OBSOLETE    starts.  */
operator|*
operator|/
comment|/* OBSOLETE int adapt_desc = -1; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* stream which is fdopen'd from adapt_desc.  Only valid when */
comment|/* OBSOLETE    adapt_desc != -1.  */
operator|*
operator|/
comment|/* OBSOLETE FILE *adapt_stream; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #define ON	1 */
comment|/* OBSOLETE #define OFF	0 */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE rawmode (int desc, int turnon) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   TERMINAL sg; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (desc< 0) */
comment|/* OBSOLETE     return; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   ioctl (desc, TIOCGETP,&sg); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (turnon) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE #ifdef HAVE_TERMIO */
comment|/* OBSOLETE       sg.c_lflag&= ~(ICANON); */
comment|/* OBSOLETE #else */
comment|/* OBSOLETE       sg.sg_flags |= RAW; */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE #ifdef HAVE_TERMIO */
comment|/* OBSOLETE       sg.c_lflag |= ICANON; */
comment|/* OBSOLETE #else */
comment|/* OBSOLETE       sg.sg_flags&= ~(RAW); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   ioctl (desc, TIOCSETP,&sg); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Suck up all the input from the adapt */
operator|*
operator|/
comment|/* OBSOLETE slurp_input (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   char buf[8]; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #ifdef HAVE_TERMIO */
comment|/* OBSOLETE   /* termio does the timeout for us.  */
operator|*
operator|/
comment|/* OBSOLETE   while (read (adapt_desc, buf, 8)> 0); */
comment|/* OBSOLETE #else */
comment|/* OBSOLETE   alarm (timeout); */
comment|/* OBSOLETE   while (read (adapt_desc, buf, 8)> 0); */
comment|/* OBSOLETE   alarm (0); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Read a character from the remote system, doing all the fancy */
comment|/* OBSOLETE    timeout stuff.  */
operator|*
operator|/
comment|/* OBSOLETE static int */
comment|/* OBSOLETE readchar (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   char buf; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   buf = '\0'; */
comment|/* OBSOLETE #ifdef HAVE_TERMIO */
comment|/* OBSOLETE   /* termio does the timeout for us.  */
operator|*
operator|/
comment|/* OBSOLETE   read (adapt_desc,&buf, 1); */
comment|/* OBSOLETE #else */
comment|/* OBSOLETE   alarm (timeout); */
comment|/* OBSOLETE   if (read (adapt_desc,&buf, 1)< 0) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       if (errno == EINTR) */
comment|/* OBSOLETE 	error ("Timeout reading from remote system."); */
comment|/* OBSOLETE       else */
comment|/* OBSOLETE 	perror_with_name ("remote"); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   alarm (0); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (buf == '\0') */
comment|/* OBSOLETE     error ("Timeout reading from remote system."); */
comment|/* OBSOLETE #if defined (LOG_FILE) */
comment|/* OBSOLETE   putc (buf& 0x7f, log_file); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE   return buf& 0x7f; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Keep discarding input from the remote system, until STRING is found.  */
comment|/* OBSOLETE    Let the user break out immediately.  */
operator|*
operator|/
comment|/* OBSOLETE static void */
comment|/* OBSOLETE expect (char *string) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   char *p = string; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   fflush (adapt_stream); */
comment|/* OBSOLETE   immediate_quit++; */
comment|/* OBSOLETE   while (1) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       if (readchar () == *p) */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  p++; */
comment|/* OBSOLETE 	  if (*p == '\0') */
comment|/* OBSOLETE 	    { */
comment|/* OBSOLETE 	      immediate_quit--; */
comment|/* OBSOLETE 	      return; */
comment|/* OBSOLETE 	    } */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE       else */
comment|/* OBSOLETE 	p = string; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Keep discarding input until we see the adapt prompt. */
comment|/* OBSOLETE  */
comment|/* OBSOLETE    The convention for dealing with the prompt is that you */
comment|/* OBSOLETE    o give your command */
comment|/* OBSOLETE    o *then* wait for the prompt. */
comment|/* OBSOLETE  */
comment|/* OBSOLETE    Thus the last thing that a procedure does with the serial line */
comment|/* OBSOLETE    will be an expect_prompt().  Exception:  adapt_resume does not */
comment|/* OBSOLETE    wait for the prompt, because the terminal is being handed over */
comment|/* OBSOLETE    to the inferior.  However, the next thing which happens after that */
comment|/* OBSOLETE    is a adapt_wait which does wait for the prompt. */
comment|/* OBSOLETE    Note that this includes abnormal exit, e.g. error().  This is */
comment|/* OBSOLETE    necessary to prevent getting into states from which we can't */
comment|/* OBSOLETE    recover.  */
operator|*
operator|/
comment|/* OBSOLETE static void */
comment|/* OBSOLETE expect_prompt (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE #if defined (LOG_FILE) */
comment|/* OBSOLETE   /* This is a convenient place to do this.  The idea is to do it often */
comment|/* OBSOLETE      enough that we never lose much data if we terminate abnormally.  */
operator|*
operator|/
comment|/* OBSOLETE   fflush (log_file); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE   fflush (adapt_stream); */
comment|/* OBSOLETE   expect ("\n# "); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Get a hex digit from the remote system& return its value. */
comment|/* OBSOLETE    If ignore_space is nonzero, ignore spaces (not newline, tab, etc).  */
operator|*
operator|/
comment|/* OBSOLETE static int */
comment|/* OBSOLETE get_hex_digit (int ignore_space) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int ch; */
comment|/* OBSOLETE   while (1) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       ch = readchar (); */
comment|/* OBSOLETE       if (ch>= '0'&& ch<= '9') */
comment|/* OBSOLETE 	return ch - '0'; */
comment|/* OBSOLETE       else if (ch>= 'A'&& ch<= 'F') */
comment|/* OBSOLETE 	return ch - 'A' + 10; */
comment|/* OBSOLETE       else if (ch>= 'a'&& ch<= 'f') */
comment|/* OBSOLETE 	return ch - 'a' + 10; */
comment|/* OBSOLETE       else if (ch == ' '&& ignore_space) */
comment|/* OBSOLETE 	; */
comment|/* OBSOLETE       else */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  expect_prompt (); */
comment|/* OBSOLETE 	  error ("Invalid hex digit from remote system."); */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Get a byte from adapt_desc and put it in *BYT.  Accept any number */
comment|/* OBSOLETE    leading spaces.  */
operator|*
operator|/
comment|/* OBSOLETE static void */
comment|/* OBSOLETE get_hex_byte (char *byt) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int val; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   val = get_hex_digit (1)<< 4; */
comment|/* OBSOLETE   val |= get_hex_digit (0); */
comment|/* OBSOLETE   *byt = val; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Read a 32-bit hex word from the adapt, preceded by a space  */
operator|*
operator|/
comment|/* OBSOLETE static long */
comment|/* OBSOLETE get_hex_word (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   long val; */
comment|/* OBSOLETE   int j; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   val = 0; */
comment|/* OBSOLETE   for (j = 0; j< 8; j++) */
comment|/* OBSOLETE     val = (val<< 4) + get_hex_digit (j == 0); */
comment|/* OBSOLETE   return val; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE /* Get N 32-bit hex words from remote, each preceded by a space  */
comment|/* OBSOLETE    and put them in registers starting at REGNO.  */
operator|*
operator|/
comment|/* OBSOLETE static void */
comment|/* OBSOLETE get_hex_regs (int n, int regno) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   long val; */
comment|/* OBSOLETE   while (n--) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       val = get_hex_word (); */
comment|/* OBSOLETE       supply_register (regno++, (char *)&val); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE } */
comment|/* OBSOLETE /* Called when SIGALRM signal sent due to alarm() timeout.  */
operator|*
operator|/
comment|/* OBSOLETE #ifndef HAVE_TERMIO */
comment|/* OBSOLETE  */
comment|/* OBSOLETE volatile int n_alarms; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE void */
comment|/* OBSOLETE adapt_timer (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE #if 0 */
comment|/* OBSOLETE   if (kiodebug) */
comment|/* OBSOLETE     printf ("adapt_timer called\n"); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE   n_alarms++; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* malloc'd name of the program on the remote system.  */
operator|*
operator|/
comment|/* OBSOLETE static char *prog_name = NULL; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Number of SIGTRAPs we need to simulate.  That is, the next */
comment|/* OBSOLETE    NEED_ARTIFICIAL_TRAP calls to adapt_wait should just return */
comment|/* OBSOLETE    SIGTRAP without actually waiting for anything.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static int need_artificial_trap = 0; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE void */
comment|/* OBSOLETE adapt_kill (char *arg, int from_tty) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   fprintf (adapt_stream, "K"); */
comment|/* OBSOLETE   fprintf (adapt_stream, "\r"); */
comment|/* OBSOLETE   expect_prompt (); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE /* */
comment|/* OBSOLETE  * Download a file specified in 'args', to the adapt.  */
comment|/* OBSOLETE  * FIXME: Assumes the file to download is a binary coff file. */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE static void */
comment|/* OBSOLETE adapt_load (char *args, int fromtty) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   FILE *fp; */
comment|/* OBSOLETE   int n; */
comment|/* OBSOLETE   char buffer[1024]; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (!adapt_stream) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       printf_filtered ("Adapt not open. Use 'target' command to open adapt\n"); */
comment|/* OBSOLETE       return; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* OK, now read in the file.  Y=read, C=COFF, T=dTe port */
comment|/* OBSOLETE      0=start address.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE #ifdef ASCII_COFF		/* Ascii coff */
operator|*
operator|/
comment|/* OBSOLETE   fprintf (adapt_stream, "YA T,0\r"); */
comment|/* OBSOLETE   fflush (adapt_stream);	/* Just in case */
operator|*
operator|/
comment|/* OBSOLETE   /* FIXME: should check args for only 1 argument */
operator|*
operator|/
comment|/* OBSOLETE   sprintf (buffer, "cat %s | btoa> /tmp/#adapt-btoa", args); */
comment|/* OBSOLETE   system (buffer); */
comment|/* OBSOLETE   fp = fopen ("/tmp/#adapt-btoa", "r"); */
comment|/* OBSOLETE   rawmode (adapt_desc, OFF); */
comment|/* OBSOLETE   while (n = fread (buffer, 1, 1024, fp)) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       do */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  n -= write (adapt_desc, buffer, n); */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE       while (n> 0); */
comment|/* OBSOLETE       if (n< 0) */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  perror ("writing ascii coff"); */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   fclose (fp); */
comment|/* OBSOLETE   rawmode (adapt_desc, ON); */
comment|/* OBSOLETE   system ("rm /tmp/#adapt-btoa"); */
comment|/* OBSOLETE #else /* Binary coff - can't get it to work . */
operator|*
operator|/
comment|/* OBSOLETE   fprintf (adapt_stream, "YC T,0\r"); */
comment|/* OBSOLETE   fflush (adapt_stream);	/* Just in case */
operator|*
operator|/
comment|/* OBSOLETE   if (!(fp = fopen (args, "r"))) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       printf_filtered ("Can't open %s\n", args); */
comment|/* OBSOLETE       return; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   while (n = fread (buffer, 1, 512, fp)) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       do */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  n -= write (adapt_desc, buffer, n); */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE       while (n> 0); */
comment|/* OBSOLETE       if (n< 0) */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  perror ("writing ascii coff"); */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   fclose (fp); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE   expect_prompt ();		/* Skip garbage that comes out */
operator|*
operator|/
comment|/* OBSOLETE   fprintf (adapt_stream, "\r"); */
comment|/* OBSOLETE   expect_prompt (); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* This is called not only when we first attach, but also when the */
comment|/* OBSOLETE    user types "run" after having attached.  */
operator|*
operator|/
comment|/* OBSOLETE void */
comment|/* OBSOLETE adapt_create_inferior (char *execfile, char *args, char **env) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int entry_pt; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (args&& *args) */
comment|/* OBSOLETE     error ("Can't pass arguments to remote adapt process."); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (execfile == 0 || exec_bfd == 0) */
comment|/* OBSOLETE     error ("No executable file specified"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   entry_pt = (int) bfd_get_start_address (exec_bfd); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (adapt_stream) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       adapt_kill (NULL, NULL); */
comment|/* OBSOLETE       adapt_clear_breakpoints (); */
comment|/* OBSOLETE       init_wait_for_inferior (); */
comment|/* OBSOLETE       /* Clear the input because what the adapt sends back is different */
comment|/* OBSOLETE        * depending on whether it was running or not. */
comment|/* OBSOLETE        */
operator|*
operator|/
comment|/* OBSOLETE       slurp_input ();		/* After this there should be a prompt */
operator|*
operator|/
comment|/* OBSOLETE       fprintf (adapt_stream, "\r"); */
comment|/* OBSOLETE       expect_prompt (); */
comment|/* OBSOLETE       printf_filtered ("Do you want to download '%s' (y/n)? [y] : ", prog_name); */
comment|/* OBSOLETE       { */
comment|/* OBSOLETE 	char buffer[10]; */
comment|/* OBSOLETE 	gets (buffer); */
comment|/* OBSOLETE 	if (*buffer != 'n') */
comment|/* OBSOLETE 	  { */
comment|/* OBSOLETE 	    adapt_load (prog_name, 0); */
comment|/* OBSOLETE 	  } */
comment|/* OBSOLETE       } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #ifdef NOTDEF */
comment|/* OBSOLETE       /* Set the PC and wait for a go/cont */
operator|*
operator|/
comment|/* OBSOLETE       fprintf (adapt_stream, "G %x,N\r", entry_pt); */
comment|/* OBSOLETE       printf_filtered ("Now use the 'continue' command to start.\n"); */
comment|/* OBSOLETE       expect_prompt (); */
comment|/* OBSOLETE #else */
comment|/* OBSOLETE       insert_breakpoints ();	/* Needed to get correct instruction in cache */
operator|*
operator|/
comment|/* OBSOLETE       proceed (entry_pt, TARGET_SIGNAL_DEFAULT, 0); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE  */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       printf_filtered ("Adapt not open yet.\n"); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Translate baud rates from integers to damn B_codes.  Unix should */
comment|/* OBSOLETE    have outgrown this crap years ago, but even POSIX wouldn't buck it.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE #ifndef B19200 */
comment|/* OBSOLETE #define B19200 EXTA */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE #ifndef B38400 */
comment|/* OBSOLETE #define B38400 EXTB */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE  */
comment|/* OBSOLETE static struct */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int rate, damn_b; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE baudtab[] = */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   { */
comment|/* OBSOLETE     0, B0 */
comment|/* OBSOLETE   } */
comment|/* OBSOLETE   , */
comment|/* OBSOLETE   { */
comment|/* OBSOLETE     50, B50 */
comment|/* OBSOLETE   } */
comment|/* OBSOLETE   , */
comment|/* OBSOLETE   { */
comment|/* OBSOLETE     75, B75 */
comment|/* OBSOLETE   } */
comment|/* OBSOLETE   , */
comment|/* OBSOLETE   { */
comment|/* OBSOLETE     110, B110 */
comment|/* OBSOLETE   } */
comment|/* OBSOLETE   , */
comment|/* OBSOLETE   { */
comment|/* OBSOLETE     134, B134 */
comment|/* OBSOLETE   } */
comment|/* OBSOLETE   , */
comment|/* OBSOLETE   { */
comment|/* OBSOLETE     150, B150 */
comment|/* OBSOLETE   } */
comment|/* OBSOLETE   , */
comment|/* OBSOLETE   { */
comment|/* OBSOLETE     200, B200 */
comment|/* OBSOLETE   } */
comment|/* OBSOLETE   , */
comment|/* OBSOLETE   { */
comment|/* OBSOLETE     300, B300 */
comment|/* OBSOLETE   } */
comment|/* OBSOLETE   , */
comment|/* OBSOLETE   { */
comment|/* OBSOLETE     600, B600 */
comment|/* OBSOLETE   } */
comment|/* OBSOLETE   , */
comment|/* OBSOLETE   { */
comment|/* OBSOLETE     1200, B1200 */
comment|/* OBSOLETE   } */
comment|/* OBSOLETE   , */
comment|/* OBSOLETE   { */
comment|/* OBSOLETE     1800, B1800 */
comment|/* OBSOLETE   } */
comment|/* OBSOLETE   , */
comment|/* OBSOLETE   { */
comment|/* OBSOLETE     2400, B2400 */
comment|/* OBSOLETE   } */
comment|/* OBSOLETE   , */
comment|/* OBSOLETE   { */
comment|/* OBSOLETE     4800, B4800 */
comment|/* OBSOLETE   } */
comment|/* OBSOLETE   , */
comment|/* OBSOLETE   { */
comment|/* OBSOLETE     9600, B9600 */
comment|/* OBSOLETE   } */
comment|/* OBSOLETE   , */
comment|/* OBSOLETE   { */
comment|/* OBSOLETE     19200, B19200 */
comment|/* OBSOLETE   } */
comment|/* OBSOLETE   , */
comment|/* OBSOLETE   { */
comment|/* OBSOLETE     38400, B38400 */
comment|/* OBSOLETE   } */
comment|/* OBSOLETE   , */
comment|/* OBSOLETE   { */
comment|/* OBSOLETE     -1, -1 */
comment|/* OBSOLETE   } */
comment|/* OBSOLETE   , */
comment|/* OBSOLETE }; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE static int */
comment|/* OBSOLETE damn_b (int rate) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int i; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   for (i = 0; baudtab[i].rate != -1; i++) */
comment|/* OBSOLETE     if (rate == baudtab[i].rate) */
comment|/* OBSOLETE       return baudtab[i].damn_b; */
comment|/* OBSOLETE   return B38400;		/* Random */
operator|*
operator|/
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Open a connection to a remote debugger. */
comment|/* OBSOLETE    NAME is the filename used for communication, then a space, */
comment|/* OBSOLETE    then the baud rate. */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static int baudrate = 9600; */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE adapt_open (char *name, int from_tty) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   TERMINAL sg; */
comment|/* OBSOLETE   unsigned int prl; */
comment|/* OBSOLETE   char *p; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Find the first whitespace character, it separates dev_name from */
comment|/* OBSOLETE      prog_name.  */
operator|*
operator|/
comment|/* OBSOLETE   if (name == 0) */
comment|/* OBSOLETE     goto erroid; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   for (p = name; */
comment|/* OBSOLETE        *p != '\0'&& !isspace (*p); p++) */
comment|/* OBSOLETE     ; */
comment|/* OBSOLETE   if (*p == '\0') */
comment|/* OBSOLETE   erroid: */
comment|/* OBSOLETE     error ("\ */
comment|/* OBSOLETE Please include the name of the device for the serial port,\n\ */
comment|/* OBSOLETE the baud rate, and the name of the program to run on the remote system."); */
comment|/* OBSOLETE   dev_name = (char *) xmalloc (p - name + 1); */
comment|/* OBSOLETE   strncpy (dev_name, name, p - name); */
comment|/* OBSOLETE   dev_name[p - name] = '\0'; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Skip over the whitespace after dev_name */
operator|*
operator|/
comment|/* OBSOLETE   for (; isspace (*p); p++) */
comment|/* OBSOLETE     /*EMPTY */
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (1 != sscanf (p, "%d ",&baudrate)) */
comment|/* OBSOLETE     goto erroid; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Skip the number and then the spaces */
operator|*
operator|/
comment|/* OBSOLETE   for (; isdigit (*p); p++) */
comment|/* OBSOLETE     /*EMPTY */
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
operator|/
comment|/* OBSOLETE   for (; isspace (*p); p++) */
comment|/* OBSOLETE     /*EMPTY */
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (prog_name != NULL) */
comment|/* OBSOLETE     xfree (prog_name); */
comment|/* OBSOLETE   prog_name = savestring (p, strlen (p)); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   adapt_close (0); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   adapt_desc = open (dev_name, O_RDWR); */
comment|/* OBSOLETE   if (adapt_desc< 0) */
comment|/* OBSOLETE     perror_with_name (dev_name); */
comment|/* OBSOLETE   ioctl (adapt_desc, TIOCGETP,&sg); */
comment|/* OBSOLETE #if ! defined(COMPILE_CHECK) */
comment|/* OBSOLETE #ifdef HAVE_TERMIO */
comment|/* OBSOLETE   sg.c_cc[VMIN] = 0;		/* read with timeout.  */
operator|*
operator|/
comment|/* OBSOLETE   sg.c_cc[VTIME] = timeout * 10; */
comment|/* OBSOLETE   sg.c_lflag&= ~(ICANON | ECHO); */
comment|/* OBSOLETE   sg.c_cflag = (sg.c_cflag& ~CBAUD) | damn_b (baudrate); */
comment|/* OBSOLETE #else */
comment|/* OBSOLETE   sg.sg_ispeed = damn_b (baudrate); */
comment|/* OBSOLETE   sg.sg_ospeed = damn_b (baudrate); */
comment|/* OBSOLETE   sg.sg_flags |= RAW | ANYP; */
comment|/* OBSOLETE   sg.sg_flags&= ~ECHO; */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   ioctl (adapt_desc, TIOCSETP,&sg); */
comment|/* OBSOLETE   adapt_stream = fdopen (adapt_desc, "r+"); */
comment|/* OBSOLETE #endif /* compile_check */
operator|*
operator|/
comment|/* OBSOLETE   push_target (&adapt_ops); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #ifndef HAVE_TERMIO */
comment|/* OBSOLETE #ifndef NO_SIGINTERRUPT */
comment|/* OBSOLETE   /* Cause SIGALRM's to make reads fail with EINTR instead of resuming */
comment|/* OBSOLETE      the read.  */
operator|*
operator|/
comment|/* OBSOLETE   if (siginterrupt (SIGALRM, 1) != 0) */
comment|/* OBSOLETE     perror ("adapt_open: error in siginterrupt"); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Set up read timeout timer.  */
operator|*
operator|/
comment|/* OBSOLETE   if ((void (*)) signal (SIGALRM, adapt_timer) == (void (*)) -1) */
comment|/* OBSOLETE     perror ("adapt_open: error in signal"); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #if defined (LOG_FILE) */
comment|/* OBSOLETE   log_file = fopen (LOG_FILE, "w"); */
comment|/* OBSOLETE   if (log_file == NULL) */
comment|/* OBSOLETE     perror_with_name (LOG_FILE); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Put this port into NORMAL mode, send the 'normal' character */
operator|*
operator|/
comment|/* OBSOLETE   write (adapt_desc, "
comment|", 1);	/* Control A */
operator|*
operator|/
comment|/* OBSOLETE   write (adapt_desc, "\r", 1); */
comment|/* OBSOLETE   expect_prompt (); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Hello?  Are you there?  */
operator|*
operator|/
comment|/* OBSOLETE   write (adapt_desc, "\r", 1); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   expect_prompt (); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Clear any break points */
operator|*
operator|/
comment|/* OBSOLETE   adapt_clear_breakpoints (); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Print out some stuff, letting the user now what's going on */
operator|*
operator|/
comment|/* OBSOLETE   printf_filtered ("Connected to an Adapt via %s.\n", dev_name); */
comment|/* OBSOLETE   /* FIXME: can this restriction be removed? */
operator|*
operator|/
comment|/* OBSOLETE   printf_filtered ("Remote debugging using virtual addresses works only\n"); */
comment|/* OBSOLETE   printf_filtered ("\twhen virtual addresses map 1:1 to physical addresses.\n"); */
comment|/* OBSOLETE   if (processor_type != a29k_freeze_mode) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       fprintf_filtered (gdb_stderr, */
comment|/* OBSOLETE 			"Freeze-mode debugging not available, and can only be done on an A29050.\n"); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Close out all files and local state before this target loses control. */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE adapt_close (int quitting) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Clear any break points */
operator|*
operator|/
comment|/* OBSOLETE   adapt_clear_breakpoints (); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Put this port back into REMOTE mode */
operator|*
operator|/
comment|/* OBSOLETE   if (adapt_stream) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       fflush (adapt_stream); */
comment|/* OBSOLETE       sleep (1);		/* Let any output make it all the way back */
operator|*
operator|/
comment|/* OBSOLETE       write (adapt_desc, "R\r", 2); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Due to a bug in Unix, fclose closes not only the stdio stream, */
comment|/* OBSOLETE      but also the file descriptor.  So we don't actually close */
comment|/* OBSOLETE      adapt_desc.  */
operator|*
operator|/
comment|/* OBSOLETE   if (adapt_stream) */
comment|/* OBSOLETE     fclose (adapt_stream);	/* This also closes adapt_desc */
operator|*
operator|/
comment|/* OBSOLETE   if (adapt_desc>= 0) */
comment|/* OBSOLETE     /* close (adapt_desc); */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE     /* Do not try to close adapt_desc again, later in the program.  */
operator|*
operator|/
comment|/* OBSOLETE     adapt_stream = NULL; */
comment|/* OBSOLETE   adapt_desc = -1; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #if defined (LOG_FILE) */
comment|/* OBSOLETE   if (log_file) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       if (ferror (log_file)) */
comment|/* OBSOLETE 	printf_filtered ("Error writing log file.\n"); */
comment|/* OBSOLETE       if (fclose (log_file) != 0) */
comment|/* OBSOLETE 	printf_filtered ("Error closing log file.\n"); */
comment|/* OBSOLETE       log_file = NULL; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Attach to the target that is already loaded and possibly running */
operator|*
operator|/
comment|/* OBSOLETE static void */
comment|/* OBSOLETE adapt_attach (char *args, int from_tty) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (from_tty) */
comment|/* OBSOLETE     printf_filtered ("Attaching to remote program %s.\n", prog_name); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Send the adapt a kill. It is ok if it is not already running */
operator|*
operator|/
comment|/* OBSOLETE   fprintf (adapt_stream, "K\r"); */
comment|/* OBSOLETE   fflush (adapt_stream); */
comment|/* OBSOLETE   expect_prompt ();		/* Slurp the echo */
operator|*
operator|/
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Terminate the open connection to the remote debugger. */
comment|/* OBSOLETE    Use this when you want to detach and do something else */
comment|/* OBSOLETE    with your gdb.  */
operator|*
operator|/
comment|/* OBSOLETE void */
comment|/* OBSOLETE adapt_detach (char *args, int from_tty) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (adapt_stream) */
comment|/* OBSOLETE     {				/* Send it on its way (tell it to continue)  */
operator|*
operator|/
comment|/* OBSOLETE       adapt_clear_breakpoints (); */
comment|/* OBSOLETE       fprintf (adapt_stream, "G\r"); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   pop_target ();		/* calls adapt_close to do the real work */
operator|*
operator|/
comment|/* OBSOLETE   if (from_tty) */
comment|/* OBSOLETE     printf_filtered ("Ending remote %s debugging\n", target_shortname); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Tell the remote machine to resume.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE void */
comment|/* OBSOLETE adapt_resume (ptid_t ptid, int step, enum target_signal sig) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   if (step) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       write (adapt_desc, "t 1,s\r", 6); */
comment|/* OBSOLETE       /* Wait for the echo.  */
operator|*
operator|/
comment|/* OBSOLETE       expect ("t 1,s\r\n"); */
comment|/* OBSOLETE       /* Then comes a line containing the instruction we stepped to.  */
operator|*
operator|/
comment|/* OBSOLETE       expect ("@"); */
comment|/* OBSOLETE       /* Then we get the prompt.  */
operator|*
operator|/
comment|/* OBSOLETE       expect_prompt (); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE       /* Force the next adapt_wait to return a trap.  Not doing anything */
comment|/* OBSOLETE          about I/O from the target means that the user has to type */
comment|/* OBSOLETE          "continue" to see any.  FIXME, this should be fixed.  */
operator|*
operator|/
comment|/* OBSOLETE       need_artificial_trap = 1; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       write (adapt_desc, "G\r", 2); */
comment|/* OBSOLETE       /* Swallow the echo.  */
operator|*
operator|/
comment|/* OBSOLETE       expect_prompt (); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Wait until the remote machine stops, then return, */
comment|/* OBSOLETE    storing status in STATUS just as `wait' would.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE ptid_t */
comment|/* OBSOLETE adapt_wait (ptid_t ptid, struct target_waitstatus *status) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   /* Strings to look for.  '?' means match any single character.   */
comment|/* OBSOLETE      Note that with the algorithm we use, the initial character */
comment|/* OBSOLETE      of the string cannot recur in the string, or we will not */
comment|/* OBSOLETE      find some cases of the string in the input.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   static char bpt[] = "@"; */
comment|/* OBSOLETE   /* It would be tempting to look for "\n[__exit + 0x8]\n" */
comment|/* OBSOLETE      but that requires loading symbols with "yc i" and even if */
comment|/* OBSOLETE      we did do that we don't know that the file has symbols.  */
operator|*
operator|/
comment|/* OBSOLETE   static char exitmsg[] = "@????????I    JMPTI     GR121,LR0"; */
comment|/* OBSOLETE   char *bp = bpt; */
comment|/* OBSOLETE   char *ep = exitmsg; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Large enough for either sizeof (bpt) or sizeof (exitmsg) chars.  */
operator|*
operator|/
comment|/* OBSOLETE   char swallowed[50]; */
comment|/* OBSOLETE   /* Current position in swallowed.  */
operator|*
operator|/
comment|/* OBSOLETE   char *swallowed_p = swallowed; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   int ch; */
comment|/* OBSOLETE   int ch_handled; */
comment|/* OBSOLETE   int old_timeout = timeout; */
comment|/* OBSOLETE   int old_immediate_quit = immediate_quit; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   status->kind = TARGET_WAITKIND_EXITED; */
comment|/* OBSOLETE   status->value.integer = 0; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (need_artificial_trap != 0) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE       status->value.sig = TARGET_SIGNAL_TRAP; */
comment|/* OBSOLETE       need_artificial_trap--; */
comment|/* OBSOLETE       return inferior_ptid; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   timeout = 0;			/* Don't time out -- user program is running. */
operator|*
operator|/
comment|/* OBSOLETE   immediate_quit = 1;		/* Helps ability to QUIT */
operator|*
operator|/
comment|/* OBSOLETE   while (1) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       QUIT;			/* Let user quit and leave process running */
operator|*
operator|/
comment|/* OBSOLETE       ch_handled = 0; */
comment|/* OBSOLETE       ch = readchar (); */
comment|/* OBSOLETE       if (ch == *bp) */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  bp++; */
comment|/* OBSOLETE 	  if (*bp == '\0') */
comment|/* OBSOLETE 	    break; */
comment|/* OBSOLETE 	  ch_handled = 1; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 	  *swallowed_p++ = ch; */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE       else */
comment|/* OBSOLETE 	bp = bpt; */
comment|/* OBSOLETE       if (ch == *ep || *ep == '?') */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  ep++; */
comment|/* OBSOLETE 	  if (*ep == '\0') */
comment|/* OBSOLETE 	    break; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 	  if (!ch_handled) */
comment|/* OBSOLETE 	    *swallowed_p++ = ch; */
comment|/* OBSOLETE 	  ch_handled = 1; */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE       else */
comment|/* OBSOLETE 	ep = exitmsg; */
comment|/* OBSOLETE       if (!ch_handled) */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  char *p; */
comment|/* OBSOLETE 	  /* Print out any characters which have been swallowed.  */
operator|*
operator|/
comment|/* OBSOLETE 	  for (p = swallowed; p< swallowed_p; ++p) */
comment|/* OBSOLETE 	    putc (*p, stdout); */
comment|/* OBSOLETE 	  swallowed_p = swallowed; */
comment|/* OBSOLETE 	  putc (ch, stdout); */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   expect_prompt (); */
comment|/* OBSOLETE   if (*bp == '\0') */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE       status->value.sig = TARGET_SIGNAL_TRAP; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       status->kind = TARGET_WAITKIND_EXITED; */
comment|/* OBSOLETE       status->value.integer = 0; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   timeout = old_timeout; */
comment|/* OBSOLETE   immediate_quit = old_immediate_quit; */
comment|/* OBSOLETE   return inferior_ptid; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Return the name of register number REGNO */
comment|/* OBSOLETE    in the form input and output by adapt. */
comment|/* OBSOLETE  */
comment|/* OBSOLETE    Returns a pointer to a static buffer containing the answer.  */
operator|*
operator|/
comment|/* OBSOLETE static char * */
comment|/* OBSOLETE get_reg_name (int regno) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   static char buf[80]; */
comment|/* OBSOLETE   if (regno>= GR96_REGNUM&& regno< GR96_REGNUM + 32) */
comment|/* OBSOLETE     sprintf (buf, "GR%03d", regno - GR96_REGNUM + 96); */
comment|/* OBSOLETE #if defined(GR64_REGNUM) */
comment|/* OBSOLETE   else if (regno>= GR64_REGNUM&& regno< GR64_REGNUM + 32) */
comment|/* OBSOLETE     sprintf (buf, "GR%03d", regno - GR64_REGNUM + 64); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE   else if (regno>= LR0_REGNUM&& regno< LR0_REGNUM + 128) */
comment|/* OBSOLETE     sprintf (buf, "LR%03d", regno - LR0_REGNUM); */
comment|/* OBSOLETE   else if (regno == Q_REGNUM) */
comment|/* OBSOLETE     strcpy (buf, "SR131"); */
comment|/* OBSOLETE   else if (regno>= BP_REGNUM&& regno<= CR_REGNUM) */
comment|/* OBSOLETE     sprintf (buf, "SR%03d", regno - BP_REGNUM + 133); */
comment|/* OBSOLETE   else if (regno == ALU_REGNUM) */
comment|/* OBSOLETE     strcpy (buf, "SR132"); */
comment|/* OBSOLETE   else if (regno>= IPC_REGNUM&& regno<= IPB_REGNUM) */
comment|/* OBSOLETE     sprintf (buf, "SR%03d", regno - IPC_REGNUM + 128); */
comment|/* OBSOLETE   else if (regno>= VAB_REGNUM&& regno<= LRU_REGNUM) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       /* When a 29050 is in freeze-mode, read shadow pcs instead */
operator|*
operator|/
comment|/* OBSOLETE       if ((regno>= NPC_REGNUM&& regno<= PC2_REGNUM)&& USE_SHADOW_PC) */
comment|/* OBSOLETE 	sprintf (buf, "SR%03d", regno - NPC_REGNUM + 20); */
comment|/* OBSOLETE       else */
comment|/* OBSOLETE 	sprintf (buf, "SR%03d", regno - VAB_REGNUM); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else if (regno == GR1_REGNUM) */
comment|/* OBSOLETE     strcpy (buf, "GR001"); */
comment|/* OBSOLETE   return buf; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Read the remote registers.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE adapt_fetch_registers (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int reg_index; */
comment|/* OBSOLETE   int regnum_index; */
comment|/* OBSOLETE   char tempbuf[10]; */
comment|/* OBSOLETE   int sreg_buf[16]; */
comment|/* OBSOLETE   int i, j; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /*  */
comment|/* OBSOLETE  * Global registers */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE #if defined(GR64_REGNUM) */
comment|/* OBSOLETE   write (adapt_desc, "dw gr64,gr95\r", 13); */
comment|/* OBSOLETE   for (reg_index = 64, regnum_index = GR64_REGNUM; */
comment|/* OBSOLETE        reg_index< 96; */
comment|/* OBSOLETE        reg_index += 4, regnum_index += 4) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       sprintf (tempbuf, "GR%03d ", reg_index); */
comment|/* OBSOLETE       expect (tempbuf); */
comment|/* OBSOLETE       get_hex_regs (4, regnum_index); */
comment|/* OBSOLETE       expect ("\n"); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE   write (adapt_desc, "dw gr96,gr127\r", 14); */
comment|/* OBSOLETE   for (reg_index = 96, regnum_index = GR96_REGNUM; */
comment|/* OBSOLETE        reg_index< 128; */
comment|/* OBSOLETE        reg_index += 4, regnum_index += 4) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       sprintf (tempbuf, "GR%03d ", reg_index); */
comment|/* OBSOLETE       expect (tempbuf); */
comment|/* OBSOLETE       get_hex_regs (4, regnum_index); */
comment|/* OBSOLETE       expect ("\n"); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /*  */
comment|/* OBSOLETE  * Local registers */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE   for (i = 0; i< 128; i += 32) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       /* The PC has a tendency to hang if we get these */
comment|/* OBSOLETE          all in one fell swoop ("dw lr0,lr127").  */
operator|*
operator|/
comment|/* OBSOLETE       sprintf (tempbuf, "dw lr%d\r", i); */
comment|/* OBSOLETE       write (adapt_desc, tempbuf, strlen (tempbuf)); */
comment|/* OBSOLETE       for (reg_index = i, regnum_index = LR0_REGNUM + i; */
comment|/* OBSOLETE 	   reg_index< i + 32; */
comment|/* OBSOLETE 	   reg_index += 4, regnum_index += 4) */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  sprintf (tempbuf, "LR%03d ", reg_index); */
comment|/* OBSOLETE 	  expect (tempbuf); */
comment|/* OBSOLETE 	  get_hex_regs (4, regnum_index); */
comment|/* OBSOLETE 	  expect ("\n"); */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /*  */
comment|/* OBSOLETE  * Special registers */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE   sprintf (tempbuf, "dw sr0\r"); */
comment|/* OBSOLETE   write (adapt_desc, tempbuf, strlen (tempbuf)); */
comment|/* OBSOLETE   for (i = 0; i< 4; i++) */
comment|/* OBSOLETE     {				/* SR0 - SR14 */
operator|*
operator|/
comment|/* OBSOLETE       sprintf (tempbuf, "SR%3d", i * 4); */
comment|/* OBSOLETE       expect (tempbuf); */
comment|/* OBSOLETE       for (j = 0; j< (i == 3 ? 3 : 4); j++) */
comment|/* OBSOLETE 	sreg_buf[i * 4 + j] = get_hex_word (); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   expect_prompt (); */
comment|/* OBSOLETE   /*  */
comment|/* OBSOLETE    * Read the pcs individually if we are in freeze mode. */
comment|/* OBSOLETE    * See get_reg_name(), it translates the register names for the pcs to */
comment|/* OBSOLETE    * the names of the shadow pcs. */
comment|/* OBSOLETE    */
operator|*
operator|/
comment|/* OBSOLETE   if (USE_SHADOW_PC) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       sreg_buf[10] = read_register (NPC_REGNUM);	/* pc0 */
operator|*
operator|/
comment|/* OBSOLETE       sreg_buf[11] = read_register (PC_REGNUM);		/* pc1 */
operator|*
operator|/
comment|/* OBSOLETE       sreg_buf[12] = read_register (PC2_REGNUM);	/* pc2 */
operator|*
operator|/
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   for (i = 0; i< 14; i++)	/* Supply vab -> lru */
operator|*
operator|/
comment|/* OBSOLETE     supply_register (VAB_REGNUM + i, (char *)&sreg_buf[i]); */
comment|/* OBSOLETE   sprintf (tempbuf, "dw sr128\r"); */
comment|/* OBSOLETE   write (adapt_desc, tempbuf, strlen (tempbuf)); */
comment|/* OBSOLETE   for (i = 0; i< 2; i++) */
comment|/* OBSOLETE     {				/* SR128 - SR135 */
operator|*
operator|/
comment|/* OBSOLETE       sprintf (tempbuf, "SR%3d", 128 + i * 4); */
comment|/* OBSOLETE       expect (tempbuf); */
comment|/* OBSOLETE       for (j = 0; j< 4; j++) */
comment|/* OBSOLETE 	sreg_buf[i * 4 + j] = get_hex_word (); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   expect_prompt (); */
comment|/* OBSOLETE   supply_register (IPC_REGNUM, (char *)&sreg_buf[0]); */
comment|/* OBSOLETE   supply_register (IPA_REGNUM, (char *)&sreg_buf[1]); */
comment|/* OBSOLETE   supply_register (IPB_REGNUM, (char *)&sreg_buf[2]); */
comment|/* OBSOLETE   supply_register (Q_REGNUM, (char *)&sreg_buf[3]); */
comment|/* OBSOLETE   /* Skip ALU */
operator|*
operator|/
comment|/* OBSOLETE   supply_register (BP_REGNUM, (char *)&sreg_buf[5]); */
comment|/* OBSOLETE   supply_register (FC_REGNUM, (char *)&sreg_buf[6]); */
comment|/* OBSOLETE   supply_register (CR_REGNUM, (char *)&sreg_buf[7]); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* There doesn't seem to be any way to get these.  */
operator|*
operator|/
comment|/* OBSOLETE   { */
comment|/* OBSOLETE     int val = -1; */
comment|/* OBSOLETE     supply_register (FPE_REGNUM, (char *)&val); */
comment|/* OBSOLETE     supply_register (INTE_REGNUM, (char *)&val); */
comment|/* OBSOLETE     supply_register (FPS_REGNUM, (char *)&val); */
comment|/* OBSOLETE     supply_register (EXO_REGNUM, (char *)&val); */
comment|/* OBSOLETE   } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   write (adapt_desc, "dw gr1,gr1\r", 11); */
comment|/* OBSOLETE   expect ("GR001 "); */
comment|/* OBSOLETE   get_hex_regs (1, GR1_REGNUM); */
comment|/* OBSOLETE   expect_prompt (); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Fetch register REGNO, or all registers if REGNO is -1. */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE static void */
comment|/* OBSOLETE adapt_fetch_register (int regno) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   if (regno == -1) */
comment|/* OBSOLETE     adapt_fetch_registers (); */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       char *name = get_reg_name (regno); */
comment|/* OBSOLETE       fprintf (adapt_stream, "dw %s,%s\r", name, name); */
comment|/* OBSOLETE       expect (name); */
comment|/* OBSOLETE       expect (" "); */
comment|/* OBSOLETE       get_hex_regs (1, regno); */
comment|/* OBSOLETE       expect_prompt (); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Store the remote registers from the contents of the block REGS.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE adapt_store_registers (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int i, j; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   fprintf (adapt_stream, "s gr1,%x\r", read_register (GR1_REGNUM)); */
comment|/* OBSOLETE   expect_prompt (); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #if defined(GR64_REGNUM) */
comment|/* OBSOLETE   for (j = 0; j< 32; j += 16) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       fprintf (adapt_stream, "s gr%d,", j + 64); */
comment|/* OBSOLETE       for (i = 0; i< 15; ++i) */
comment|/* OBSOLETE 	fprintf (adapt_stream, "%x,", read_register (GR64_REGNUM + j + i)); */
comment|/* OBSOLETE       fprintf (adapt_stream, "%x\r", read_register (GR64_REGNUM + j + 15)); */
comment|/* OBSOLETE       expect_prompt (); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE   for (j = 0; j< 32; j += 16) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       fprintf (adapt_stream, "s gr%d,", j + 96); */
comment|/* OBSOLETE       for (i = 0; i< 15; ++i) */
comment|/* OBSOLETE 	fprintf (adapt_stream, "%x,", read_register (GR96_REGNUM + j + i)); */
comment|/* OBSOLETE       fprintf (adapt_stream, "%x\r", read_register (GR96_REGNUM + j + 15)); */
comment|/* OBSOLETE       expect_prompt (); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   for (j = 0; j< 128; j += 16) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       fprintf (adapt_stream, "s lr%d,", j); */
comment|/* OBSOLETE       for (i = 0; i< 15; ++i) */
comment|/* OBSOLETE 	fprintf (adapt_stream, "%x,", read_register (LR0_REGNUM + j + i)); */
comment|/* OBSOLETE       fprintf (adapt_stream, "%x\r", read_register (LR0_REGNUM + j + 15)); */
comment|/* OBSOLETE       expect_prompt (); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   fprintf (adapt_stream, "s sr128,%x,%x,%x\r", read_register (IPC_REGNUM), */
comment|/* OBSOLETE 	   read_register (IPA_REGNUM), read_register (IPB_REGNUM)); */
comment|/* OBSOLETE   expect_prompt (); */
comment|/* OBSOLETE   fprintf (adapt_stream, "s sr133,%x,%x,%x\r", read_register (BP_REGNUM), */
comment|/* OBSOLETE 	   read_register (FC_REGNUM), read_register (CR_REGNUM)); */
comment|/* OBSOLETE   expect_prompt (); */
comment|/* OBSOLETE   fprintf (adapt_stream, "s sr131,%x\r", read_register (Q_REGNUM)); */
comment|/* OBSOLETE   expect_prompt (); */
comment|/* OBSOLETE   fprintf (adapt_stream, "s sr0,"); */
comment|/* OBSOLETE   for (i = 0; i< 7; ++i) */
comment|/* OBSOLETE     fprintf (adapt_stream, "%x,", read_register (VAB_REGNUM + i)); */
comment|/* OBSOLETE   expect_prompt (); */
comment|/* OBSOLETE   fprintf (adapt_stream, "s sr7,"); */
comment|/* OBSOLETE   for (i = 7; i< 14; ++i) */
comment|/* OBSOLETE     fprintf (adapt_stream, "%x,", read_register (VAB_REGNUM + i)); */
comment|/* OBSOLETE   expect_prompt (); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Store register REGNO, or all if REGNO == -1. */
comment|/* OBSOLETE    Return errno value.  */
operator|*
operator|/
comment|/* OBSOLETE void */
comment|/* OBSOLETE adapt_store_register (int regno) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   /* printf("adapt_store_register() called.\n"); fflush(stdout); /* */
operator|*
operator|/
comment|/* OBSOLETE   if (regno == -1) */
comment|/* OBSOLETE     adapt_store_registers (); */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       char *name = get_reg_name (regno); */
comment|/* OBSOLETE       fprintf (adapt_stream, "s %s,%x\r", name, read_register (regno)); */
comment|/* OBSOLETE       /* Setting GR1 changes the numbers of all the locals, so */
comment|/* OBSOLETE          invalidate the register cache.  Do this *after* calling */
comment|/* OBSOLETE          read_register, because we want read_register to return the */
comment|/* OBSOLETE          value that write_register has just stuffed into the registers */
comment|/* OBSOLETE          array, not the value of the register fetched from the */
comment|/* OBSOLETE          inferior.  */
operator|*
operator|/
comment|/* OBSOLETE       if (regno == GR1_REGNUM) */
comment|/* OBSOLETE 	registers_changed (); */
comment|/* OBSOLETE       expect_prompt (); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Get ready to modify the registers array.  On machines which store */
comment|/* OBSOLETE    individual registers, this doesn't need to do anything.  On machines */
comment|/* OBSOLETE    which store all the registers in one fell swoop, this makes sure */
comment|/* OBSOLETE    that registers contains all the registers from the program being */
comment|/* OBSOLETE    debugged.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE void */
comment|/* OBSOLETE adapt_prepare_to_store (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   /* Do nothing, since we can store individual regs */
operator|*
operator|/
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE static CORE_ADDR */
comment|/* OBSOLETE translate_addr (CORE_ADDR addr) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE #if defined(KERNEL_DEBUGGING) */
comment|/* OBSOLETE   /* Check for a virtual address in the kernel */
operator|*
operator|/
comment|/* OBSOLETE   /* Assume physical address of ublock is in  paddr_u register */
operator|*
operator|/
comment|/* OBSOLETE   if (addr>= UVADDR) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       /* PADDR_U register holds the physical address of the ublock */
operator|*
operator|/
comment|/* OBSOLETE       CORE_ADDR i = (CORE_ADDR) read_register (PADDR_U_REGNUM); */
comment|/* OBSOLETE       return (i + addr - (CORE_ADDR) UVADDR); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       return (addr); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE #else */
comment|/* OBSOLETE   return (addr); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* FIXME!  Merge these two.  */
operator|*
operator|/
comment|/* OBSOLETE int */
comment|/* OBSOLETE adapt_xfer_inferior_memory (CORE_ADDR memaddr, char *myaddr, int len, int write, */
comment|/* OBSOLETE 			    struct mem_attrib *attrib ATTRIBUTE_UNUSED, */
comment|/* OBSOLETE 			    struct target_ops *target ATTRIBUTE_UNUSED) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   memaddr = translate_addr (memaddr); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (write) */
comment|/* OBSOLETE     return adapt_write_inferior_memory (memaddr, myaddr, len); */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     return adapt_read_inferior_memory (memaddr, myaddr, len); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE void */
comment|/* OBSOLETE adapt_files_info (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   printf_filtered ("\tAttached to %s at %d baud and running program %s\n", */
comment|/* OBSOLETE 		   dev_name, baudrate, prog_name); */
comment|/* OBSOLETE   printf_filtered ("\ton an %s processor.\n", processor_name[processor_type]); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Copy LEN bytes of data from debugger memory at MYADDR */
comment|/* OBSOLETE    to inferior's memory at MEMADDR.  Returns errno value.   */
comment|/* OBSOLETE    * sb/sh instructions don't work on unaligned addresses, when TU=1.  */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE int */
comment|/* OBSOLETE adapt_write_inferior_memory (CORE_ADDR memaddr, char *myaddr, int len) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int i; */
comment|/* OBSOLETE   unsigned int cps; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Turn TU bit off so we can do 'sb' commands */
operator|*
operator|/
comment|/* OBSOLETE   cps = read_register (CPS_REGNUM); */
comment|/* OBSOLETE   if (cps& 0x00000800) */
comment|/* OBSOLETE     write_register (CPS_REGNUM, cps& ~(0x00000800)); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   for (i = 0; i< len; i++) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       if ((i % 16) == 0) */
comment|/* OBSOLETE 	fprintf (adapt_stream, "sb %x,", memaddr + i); */
comment|/* OBSOLETE       if ((i % 16) == 15 || i == len - 1) */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  fprintf (adapt_stream, "%x\r", ((unsigned char *) myaddr)[i]); */
comment|/* OBSOLETE 	  expect_prompt (); */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE       else */
comment|/* OBSOLETE 	fprintf (adapt_stream, "%x,", ((unsigned char *) myaddr)[i]); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   /* Restore the old value of cps if the TU bit was on */
operator|*
operator|/
comment|/* OBSOLETE   if (cps& 0x00000800) */
comment|/* OBSOLETE     write_register (CPS_REGNUM, cps); */
comment|/* OBSOLETE   return len; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Read LEN bytes from inferior memory at MEMADDR.  Put the result */
comment|/* OBSOLETE    at debugger address MYADDR.  Returns errno value.  */
operator|*
operator|/
comment|/* OBSOLETE int */
comment|/* OBSOLETE adapt_read_inferior_memory (CORE_ADDR memaddr, char *myaddr, int len) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int i; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Number of bytes read so far.  */
operator|*
operator|/
comment|/* OBSOLETE   int count; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Starting address of this pass.  */
operator|*
operator|/
comment|/* OBSOLETE   unsigned long startaddr; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Number of bytes to read in this pass.  */
operator|*
operator|/
comment|/* OBSOLETE   int len_this_pass; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Note that this code works correctly if startaddr is just less */
comment|/* OBSOLETE      than UINT_MAX (well, really CORE_ADDR_MAX if there was such a */
comment|/* OBSOLETE      thing).  That is, something like */
comment|/* OBSOLETE      adapt_read_bytes (CORE_ADDR_MAX - 4, foo, 4) */
comment|/* OBSOLETE      works--it never adds len to memaddr and gets 0.  */
operator|*
operator|/
comment|/* OBSOLETE   /* However, something like */
comment|/* OBSOLETE      adapt_read_bytes (CORE_ADDR_MAX - 3, foo, 4) */
comment|/* OBSOLETE      doesn't need to work.  Detect it and give up if there's an attempt */
comment|/* OBSOLETE      to do that.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (((memaddr - 1) + len)< memaddr) */
comment|/* OBSOLETE     return EIO; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   startaddr = memaddr; */
comment|/* OBSOLETE   count = 0; */
comment|/* OBSOLETE   while (count< len) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       len_this_pass = 16; */
comment|/* OBSOLETE       if ((startaddr % 16) != 0) */
comment|/* OBSOLETE 	len_this_pass -= startaddr % 16; */
comment|/* OBSOLETE       if (len_this_pass> (len - count)) */
comment|/* OBSOLETE 	len_this_pass = (len - count); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE       fprintf (adapt_stream, "db %x,%x\r", startaddr, */
comment|/* OBSOLETE 	       (startaddr - 1) + len_this_pass); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #ifdef NOTDEF			/* Why do this */
operator|*
operator|/
comment|/* OBSOLETE       expect ("\n"); */
comment|/* OBSOLETE       /* Look for 8 hex digits.  */
operator|*
operator|/
comment|/* OBSOLETE       i = 0; */
comment|/* OBSOLETE       while (1) */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  if (isxdigit (readchar ())) */
comment|/* OBSOLETE 	    ++i; */
comment|/* OBSOLETE 	  else */
comment|/* OBSOLETE 	    { */
comment|/* OBSOLETE 	      expect_prompt (); */
comment|/* OBSOLETE 	      error ("Hex digit expected from remote system."); */
comment|/* OBSOLETE 	    } */
comment|/* OBSOLETE 	  if (i>= 8) */
comment|/* OBSOLETE 	    break; */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE #endif /* NOTDEF */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE       expect ("  "); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE       for (i = 0; i< len_this_pass; i++) */
comment|/* OBSOLETE 	get_hex_byte (&myaddr[count++]); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE       expect_prompt (); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE       startaddr += len_this_pass; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   return count; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #define MAX_BREAKS	8 */
comment|/* OBSOLETE static int num_brkpts = 0; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Insert a breakpoint at ADDR.  SAVE is normally the address of the */
comment|/* OBSOLETE    pattern buffer where the instruction that the breakpoint overwrites */
comment|/* OBSOLETE    is saved.  It is unused here since the Adapt Monitor is responsible */
comment|/* OBSOLETE    for saving/restoring the original instruction. */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static int */
comment|/* OBSOLETE adapt_insert_breakpoint (CORE_ADDR addr, char *save) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   if (num_brkpts< MAX_BREAKS) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       num_brkpts++; */
comment|/* OBSOLETE       fprintf (adapt_stream, "B %x", addr); */
comment|/* OBSOLETE       fprintf (adapt_stream, "\r"); */
comment|/* OBSOLETE       expect_prompt (); */
comment|/* OBSOLETE       return (0);		/* Success */
operator|*
operator|/
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       fprintf_filtered (gdb_stderr, */
comment|/* OBSOLETE 		      "Too many break points, break point not installed\n"); */
comment|/* OBSOLETE       return (1);		/* Failure */
operator|*
operator|/
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Remove a breakpoint at ADDR.  SAVE is normally the previously */
comment|/* OBSOLETE    saved pattern, but is unused here as the Adapt Monitor is */
comment|/* OBSOLETE    responsible for saving/restoring instructions. */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static int */
comment|/* OBSOLETE adapt_remove_breakpoint (CORE_ADDR addr, char *save) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   if (num_brkpts> 0) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       num_brkpts--; */
comment|/* OBSOLETE       fprintf (adapt_stream, "BR %x", addr); */
comment|/* OBSOLETE       fprintf (adapt_stream, "\r"); */
comment|/* OBSOLETE       fflush (adapt_stream); */
comment|/* OBSOLETE       expect_prompt (); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   return (0); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Clear the adapts notion of what the break points are */
operator|*
operator|/
comment|/* OBSOLETE static int */
comment|/* OBSOLETE adapt_clear_breakpoints (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   if (adapt_stream) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       fprintf (adapt_stream, "BR");	/* Clear all break points */
operator|*
operator|/
comment|/* OBSOLETE       fprintf (adapt_stream, "\r"); */
comment|/* OBSOLETE       fflush (adapt_stream); */
comment|/* OBSOLETE       expect_prompt (); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   num_brkpts = 0; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE adapt_mourn (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   adapt_clear_breakpoints (); */
comment|/* OBSOLETE   pop_target ();		/* Pop back to no-child state */
operator|*
operator|/
comment|/* OBSOLETE   generic_mourn_inferior (); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Display everthing we read in from the adapt until we match/see the */
comment|/* OBSOLETE  * specified string */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE static int */
comment|/* OBSOLETE display_until (char *str) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int i = 0, j, c; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   while (c = readchar ()) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       if (c == str[i]) */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  i++; */
comment|/* OBSOLETE 	  if (i == strlen (str)) */
comment|/* OBSOLETE 	    return; */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE       else */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  if (i) */
comment|/* OBSOLETE 	    { */
comment|/* OBSOLETE 	      for (j = 0; j< i; j++)	/* Put everthing we matched */
operator|*
operator|/
comment|/* OBSOLETE 		putchar (str[j]); */
comment|/* OBSOLETE 	      i = 0; */
comment|/* OBSOLETE 	    } */
comment|/* OBSOLETE 	  putchar (c); */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Put a command string, in args, out to the adapt.  The adapt is assumed to */
comment|/* OBSOLETE    be in raw mode, all writing/reading done through adapt_desc. */
comment|/* OBSOLETE    Ouput from the adapt is placed on the users terminal until the */
comment|/* OBSOLETE    prompt from the adapt is seen. */
comment|/* OBSOLETE    FIXME: Can't handle commands that take input.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE void */
comment|/* OBSOLETE adapt_com (char *args, int fromtty) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   if (!adapt_stream) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       printf_filtered ("Adapt not open.  Use the 'target' command to open.\n"); */
comment|/* OBSOLETE       return; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Clear all input so only command relative output is displayed */
operator|*
operator|/
comment|/* OBSOLETE   slurp_input (); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   switch (islower (args[0]) ? toupper (args[0]) : args[0]) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE     default: */
comment|/* OBSOLETE       printf_filtered ("Unknown/Unimplemented adapt command '%s'\n", args); */
comment|/* OBSOLETE       break; */
comment|/* OBSOLETE     case 'G':			/* Go, begin execution */
operator|*
operator|/
comment|/* OBSOLETE       write (adapt_desc, args, strlen (args)); */
comment|/* OBSOLETE       write (adapt_desc, "\r", 1); */
comment|/* OBSOLETE       expect_prompt (); */
comment|/* OBSOLETE       break; */
comment|/* OBSOLETE     case 'B':			/* Break points, B or BR */
operator|*
operator|/
comment|/* OBSOLETE     case 'C':			/* Check current 29k status (running/halted) */
operator|*
operator|/
comment|/* OBSOLETE     case 'D':			/* Display data/registers */
operator|*
operator|/
comment|/* OBSOLETE     case 'I':			/* Input from i/o space */
operator|*
operator|/
comment|/* OBSOLETE     case 'J':			/* Jam an instruction */
operator|*
operator|/
comment|/* OBSOLETE     case 'K':			/* Kill, stop execution */
operator|*
operator|/
comment|/* OBSOLETE     case 'L':			/* Disassemble */
operator|*
operator|/
comment|/* OBSOLETE     case 'O':			/* Output to i/o space */
operator|*
operator|/
comment|/* OBSOLETE     case 'T':			/* Trace */
operator|*
operator|/
comment|/* OBSOLETE     case 'P':			/* Pulse an input line */
operator|*
operator|/
comment|/* OBSOLETE     case 'X':			/* Examine special purpose registers */
operator|*
operator|/
comment|/* OBSOLETE     case 'Z':			/* Display trace buffer */
operator|*
operator|/
comment|/* OBSOLETE       write (adapt_desc, args, strlen (args)); */
comment|/* OBSOLETE       write (adapt_desc, "\r", 1); */
comment|/* OBSOLETE       expect (args);		/* Don't display the command */
operator|*
operator|/
comment|/* OBSOLETE       display_until ("# "); */
comment|/* OBSOLETE       break; */
comment|/* OBSOLETE       /* Begin commands that take input in the form 'c x,y[,z...]' */
operator|*
operator|/
comment|/* OBSOLETE     case 'S':			/* Set memory or register */
operator|*
operator|/
comment|/* OBSOLETE       if (strchr (args, ',')) */
comment|/* OBSOLETE 	{			/* Assume it is properly formatted */
operator|*
operator|/
comment|/* OBSOLETE 	  write (adapt_desc, args, strlen (args)); */
comment|/* OBSOLETE 	  write (adapt_desc, "\r", 1); */
comment|/* OBSOLETE 	  expect_prompt (); */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE       break; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Define the target subroutine names */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE struct target_ops adapt_ops; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE init_adapt_ops (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   adapt_ops.to_shortname = "adapt"; */
comment|/* OBSOLETE   adapt_ops.to_longname = "Remote AMD `Adapt' target"; */
comment|/* OBSOLETE   adapt_ops.to_doc = "Remote debug an AMD 290*0 using an `Adapt' monitor via RS232"; */
comment|/* OBSOLETE   adapt_ops.to_open = adapt_open; */
comment|/* OBSOLETE   adapt_ops.to_close = adapt_close; */
comment|/* OBSOLETE   adapt_ops.to_attach = adapt_attach; */
comment|/* OBSOLETE   adapt_ops.to_post_attach = NULL; */
comment|/* OBSOLETE   adapt_ops.to_require_attach = NULL; */
comment|/* OBSOLETE   adapt_ops.to_detach = adapt_detach; */
comment|/* OBSOLETE   adapt_ops.to_require_detach = NULL; */
comment|/* OBSOLETE   adapt_ops.to_resume = adapt_resume; */
comment|/* OBSOLETE   adapt_ops.to_wait = adapt_wait; */
comment|/* OBSOLETE   adapt_ops.to_post_wait = NULL; */
comment|/* OBSOLETE   adapt_ops.to_fetch_registers = adapt_fetch_register; */
comment|/* OBSOLETE   adapt_ops.to_store_registers = adapt_store_register; */
comment|/* OBSOLETE   adapt_ops.to_prepare_to_store = adapt_prepare_to_store; */
comment|/* OBSOLETE   adapt_ops.to_xfer_memory = adapt_xfer_inferior_memory; */
comment|/* OBSOLETE   adapt_ops.to_files_info = adapt_files_info; */
comment|/* OBSOLETE   adapt_ops.to_insert_breakpoint = adapt_insert_breakpoint; */
comment|/* OBSOLETE   adapt_ops.to_remove_breakpoint = adapt_remove_breakpoint; */
comment|/* OBSOLETE   adapt_ops.to_terminal_init = 0; */
comment|/* OBSOLETE   adapt_ops.to_terminal_inferior = 0; */
comment|/* OBSOLETE   adapt_ops.to_terminal_ours_for_output = 0; */
comment|/* OBSOLETE   adapt_ops.to_terminal_ours = 0; */
comment|/* OBSOLETE   adapt_ops.to_terminal_info = 0; */
comment|/* OBSOLETE   adapt_ops.to_kill = adapt_kill; */
comment|/* OBSOLETE   adapt_ops.to_load = adapt_load; */
comment|/* OBSOLETE   adapt_ops.to_lookup_symbol = 0; */
comment|/* OBSOLETE   adapt_ops.to_create_inferior = adapt_create_inferior; */
comment|/* OBSOLETE   adapt_ops.to_post_startup_inferior = NULL; */
comment|/* OBSOLETE   adapt_ops.to_acknowledge_created_inferior = NULL; */
comment|/* OBSOLETE   adapt_ops.to_clone_and_follow_inferior = NULL; */
comment|/* OBSOLETE   adapt_ops.to_post_follow_inferior_by_clone = NULL; */
comment|/* OBSOLETE   adapt_ops.to_insert_fork_catchpoint = NULL; */
comment|/* OBSOLETE   adapt_ops.to_remove_fork_catchpoint = NULL; */
comment|/* OBSOLETE   adapt_ops.to_insert_vfork_catchpoint = NULL; */
comment|/* OBSOLETE   adapt_ops.to_remove_vfork_catchpoint = NULL; */
comment|/* OBSOLETE   adapt_ops.to_has_forked = NULL; */
comment|/* OBSOLETE   adapt_ops.to_has_vforked = NULL; */
comment|/* OBSOLETE   adapt_ops.to_can_follow_vfork_prior_to_exec = NULL; */
comment|/* OBSOLETE   adapt_ops.to_post_follow_vfork = NULL; */
comment|/* OBSOLETE   adapt_ops.to_insert_exec_catchpoint = NULL; */
comment|/* OBSOLETE   adapt_ops.to_remove_exec_catchpoint = NULL; */
comment|/* OBSOLETE   adapt_ops.to_has_execd = NULL; */
comment|/* OBSOLETE   adapt_ops.to_reported_exec_events_per_exec_call = NULL; */
comment|/* OBSOLETE   adapt_ops.to_has_exited = NULL; */
comment|/* OBSOLETE   adapt_ops.to_mourn_inferior = adapt_mourn; */
comment|/* OBSOLETE   adapt_ops.to_can_run = 0; */
comment|/* OBSOLETE   adapt_ops.to_notice_signals = 0; */
comment|/* OBSOLETE   adapt_ops.to_thread_alive = 0; */
comment|/* OBSOLETE   adapt_ops.to_stop = 0;	/* process_stratum; */
operator|*
operator|/
comment|/* OBSOLETE   adapt_ops.to_pid_to_exec_file = NULL; */
comment|/* OBSOLETE   adapt_ops.to_stratum = 0; */
comment|/* OBSOLETE   adapt_ops.DONT_USE = 0; */
comment|/* OBSOLETE   adapt_ops.to_has_all_memory = 1; */
comment|/* OBSOLETE   adapt_ops.to_has_memory = 1; */
comment|/* OBSOLETE   adapt_ops.to_has_stack = 1; */
comment|/* OBSOLETE   adapt_ops.to_has_registers = 1; */
comment|/* OBSOLETE   adapt_ops.to_has_execution = 0; */
comment|/* OBSOLETE   adapt_ops.to_sections = 0; */
comment|/* OBSOLETE   adapt_ops.to_sections_end = 0; */
comment|/* OBSOLETE   adapt_ops.to_magic = OPS_MAGIC; */
comment|/* OBSOLETE }				/* init_adapt_ops */
operator|*
operator|/
end_expr_stmt

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE void */
end_comment

begin_comment
comment|/* OBSOLETE _initialize_remote_adapt (void) */
end_comment

begin_comment
comment|/* OBSOLETE { */
end_comment

begin_comment
comment|/* OBSOLETE   init_adapt_ops (); */
end_comment

begin_comment
comment|/* OBSOLETE   add_target (&adapt_ops); */
end_comment

begin_comment
comment|/* OBSOLETE   add_com ("adapt<command>", class_obscure, adapt_com, */
end_comment

begin_comment
comment|/* OBSOLETE 	   "Send a command to the AMD Adapt remote monitor."); */
end_comment

begin_comment
comment|/* OBSOLETE } */
end_comment

end_unit

