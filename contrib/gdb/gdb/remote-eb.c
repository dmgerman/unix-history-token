begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* OBSOLETE /* Remote debugging interface for AMD 29000 EBMON on IBM PC, for GDB. */
end_comment

begin_comment
comment|/* OBSOLETE    Copyright 1990, 1991, 1992, 1993, 1994, 1995, 1998, 1999, 2000, 2001 */
end_comment

begin_comment
comment|/* OBSOLETE    Free Software Foundation, Inc. */
end_comment

begin_comment
comment|/* OBSOLETE    Contributed by Cygnus Support.  Written by Jim Kingdon for Cygnus. */
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
comment|/* OBSOLETE    having a a29k board in a PC hooked up to a unix machine with */
comment|/* OBSOLETE    a serial line, and running ctty com1 on the PC, through which */
comment|/* OBSOLETE    the unix machine can run ebmon.  Not to mention that the PC */
comment|/* OBSOLETE    has PC/NFS, so it can access the same executables that gdb can, */
comment|/* OBSOLETE    over the net in real time.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE #include "defs.h" */
comment|/* OBSOLETE #include "gdb_string.h" */
comment|/* OBSOLETE #include "regcache.h" */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #include "inferior.h" */
comment|/* OBSOLETE #include "bfd.h" */
comment|/* OBSOLETE #include "symfile.h" */
comment|/* OBSOLETE #include "value.h" */
comment|/* OBSOLETE #include<ctype.h> */
comment|/* OBSOLETE #include<fcntl.h> */
comment|/* OBSOLETE #include<signal.h> */
comment|/* OBSOLETE #include<errno.h> */
comment|/* OBSOLETE #include "terminal.h" */
comment|/* OBSOLETE #include "target.h" */
comment|/* OBSOLETE #include "gdbcore.h" */
comment|/* OBSOLETE  */
comment|/* OBSOLETE extern struct target_ops eb_ops;	/* Forward declaration */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static void eb_close (); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #define LOG_FILE "eb.log" */
comment|/* OBSOLETE #if defined (LOG_FILE) */
comment|/* OBSOLETE FILE *log_file; */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE  */
comment|/* OBSOLETE static int timeout = 24; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Descriptor for I/O to remote machine.  Initialize it to -1 so that */
comment|/* OBSOLETE    eb_open knows that we don't have a file open when the program */
comment|/* OBSOLETE    starts.  */
operator|*
operator|/
comment|/* OBSOLETE int eb_desc = -1; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* stream which is fdopen'd from eb_desc.  Only valid when */
comment|/* OBSOLETE    eb_desc != -1.  */
operator|*
operator|/
comment|/* OBSOLETE FILE *eb_stream; */
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
comment|/* OBSOLETE   read (eb_desc,&buf, 1); */
comment|/* OBSOLETE #else */
comment|/* OBSOLETE   alarm (timeout); */
comment|/* OBSOLETE   if (read (eb_desc,&buf, 1)< 0) */
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
comment|/* OBSOLETE /* Keep discarding input until we see the ebmon prompt. */
comment|/* OBSOLETE  */
comment|/* OBSOLETE    The convention for dealing with the prompt is that you */
comment|/* OBSOLETE    o give your command */
comment|/* OBSOLETE    o *then* wait for the prompt. */
comment|/* OBSOLETE  */
comment|/* OBSOLETE    Thus the last thing that a procedure does with the serial line */
comment|/* OBSOLETE    will be an expect_prompt().  Exception:  eb_resume does not */
comment|/* OBSOLETE    wait for the prompt, because the terminal is being handed over */
comment|/* OBSOLETE    to the inferior.  However, the next thing which happens after that */
comment|/* OBSOLETE    is a eb_wait which does wait for the prompt. */
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
comment|/* OBSOLETE /* Get a byte from eb_desc and put it in *BYT.  Accept any number */
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
comment|/* OBSOLETE /* Get N 32-bit words from remote, each preceded by a space, */
comment|/* OBSOLETE    and put them in registers starting at REGNO.  */
operator|*
operator|/
comment|/* OBSOLETE static void */
comment|/* OBSOLETE get_hex_regs (int n, int regno) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   long val; */
comment|/* OBSOLETE   int i; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   for (i = 0; i< n; i++) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       int j; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE       val = 0; */
comment|/* OBSOLETE       for (j = 0; j< 8; j++) */
comment|/* OBSOLETE 	val = (val<< 4) + get_hex_digit (j == 0); */
comment|/* OBSOLETE       supply_register (regno++, (char *)&val); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Called when SIGALRM signal sent due to alarm() timeout.  */
operator|*
operator|/
comment|/* OBSOLETE #ifndef HAVE_TERMIO */
comment|/* OBSOLETE  */
comment|/* OBSOLETE volatile int n_alarms; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE void */
comment|/* OBSOLETE eb_timer (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE #if 0 */
comment|/* OBSOLETE   if (kiodebug) */
comment|/* OBSOLETE     printf ("eb_timer called\n"); */
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
comment|/* OBSOLETE /* Nonzero if we have loaded the file ("yc") and not yet issued a "gi" */
comment|/* OBSOLETE    command.  "gi" is supposed to happen exactly once for each "yc".  */
operator|*
operator|/
comment|/* OBSOLETE static int need_gi = 0; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Number of SIGTRAPs we need to simulate.  That is, the next */
comment|/* OBSOLETE    NEED_ARTIFICIAL_TRAP calls to eb_wait should just return */
comment|/* OBSOLETE    SIGTRAP without actually waiting for anything.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static int need_artificial_trap = 0; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* This is called not only when we first attach, but also when the */
comment|/* OBSOLETE    user types "run" after having attached.  */
operator|*
operator|/
comment|/* OBSOLETE static void */
comment|/* OBSOLETE eb_create_inferior (char *execfile, char *args, char **env) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int entry_pt; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (args&& *args) */
comment|/* OBSOLETE     error ("Can't pass arguments to remote EBMON process"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (execfile == 0 || exec_bfd == 0) */
comment|/* OBSOLETE     error ("No executable file specified"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   entry_pt = (int) bfd_get_start_address (exec_bfd); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   { */
comment|/* OBSOLETE     /* OK, now read in the file.  Y=read, C=COFF, D=no symbols */
comment|/* OBSOLETE        0=start address, %s=filename.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE     fprintf (eb_stream, "YC D,0:%s", prog_name); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE     if (args != NULL) */
comment|/* OBSOLETE       fprintf (eb_stream, " %s", args); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE     fprintf (eb_stream, "\n"); */
comment|/* OBSOLETE     fflush (eb_stream); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE     expect_prompt (); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE     need_gi = 1; */
comment|/* OBSOLETE   } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* The "process" (board) is already stopped awaiting our commands, and */
comment|/* OBSOLETE    the program is already downloaded.  We just set its PC and go.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   clear_proceed_status (); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Tell wait_for_inferior that we've started a new process.  */
operator|*
operator|/
comment|/* OBSOLETE   init_wait_for_inferior (); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Set up the "saved terminal modes" of the inferior */
comment|/* OBSOLETE      based on what modes we are starting it with.  */
operator|*
operator|/
comment|/* OBSOLETE   target_terminal_init (); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Install inferior's terminal modes.  */
operator|*
operator|/
comment|/* OBSOLETE   target_terminal_inferior (); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* insert_step_breakpoint ();  FIXME, do we need this?  */
operator|*
operator|/
comment|/* OBSOLETE   proceed ((CORE_ADDR) entry_pt, TARGET_SIGNAL_DEFAULT, 0);	/* Let 'er rip... */
operator|*
operator|/
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
comment|/* OBSOLETE struct */
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
comment|/* OBSOLETE int */
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
comment|/* OBSOLETE    then the name of the program as we should name it to EBMON.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static int baudrate = 9600; */
comment|/* OBSOLETE static char *dev_name; */
comment|/* OBSOLETE void */
comment|/* OBSOLETE eb_open (char *name, int from_tty) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   TERMINAL sg; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   char *p; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   target_preopen (from_tty); */
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
comment|/* OBSOLETE   dev_name = alloca (p - name + 1); */
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
comment|/* OBSOLETE   eb_close (0); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   eb_desc = open (dev_name, O_RDWR); */
comment|/* OBSOLETE   if (eb_desc< 0) */
comment|/* OBSOLETE     perror_with_name (dev_name); */
comment|/* OBSOLETE   ioctl (eb_desc, TIOCGETP,&sg); */
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
comment|/* OBSOLETE   ioctl (eb_desc, TIOCSETP,&sg); */
comment|/* OBSOLETE   eb_stream = fdopen (eb_desc, "r+"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   push_target (&eb_ops); */
comment|/* OBSOLETE   if (from_tty) */
comment|/* OBSOLETE     printf ("Remote %s debugging %s using %s\n", target_shortname, */
comment|/* OBSOLETE 	    prog_name, dev_name); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #ifndef HAVE_TERMIO */
comment|/* OBSOLETE #ifndef NO_SIGINTERRUPT */
comment|/* OBSOLETE   /* Cause SIGALRM's to make reads fail with EINTR instead of resuming */
comment|/* OBSOLETE      the read.  */
operator|*
operator|/
comment|/* OBSOLETE   if (siginterrupt (SIGALRM, 1) != 0) */
comment|/* OBSOLETE     perror ("eb_open: error in siginterrupt"); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Set up read timeout timer.  */
operator|*
operator|/
comment|/* OBSOLETE   if ((void (*)) signal (SIGALRM, eb_timer) == (void (*)) -1) */
comment|/* OBSOLETE     perror ("eb_open: error in signal"); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #if defined (LOG_FILE) */
comment|/* OBSOLETE   log_file = fopen (LOG_FILE, "w"); */
comment|/* OBSOLETE   if (log_file == NULL) */
comment|/* OBSOLETE     perror_with_name (LOG_FILE); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Hello?  Are you there?  */
operator|*
operator|/
comment|/* OBSOLETE   write (eb_desc, "\n", 1); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   expect_prompt (); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Close out all files and local state before this target loses control. */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE eb_close (int quitting) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Due to a bug in Unix, fclose closes not only the stdio stream, */
comment|/* OBSOLETE      but also the file descriptor.  So we don't actually close */
comment|/* OBSOLETE      eb_desc.  */
operator|*
operator|/
comment|/* OBSOLETE   if (eb_stream) */
comment|/* OBSOLETE     fclose (eb_stream);		/* This also closes eb_desc */
operator|*
operator|/
comment|/* OBSOLETE   if (eb_desc>= 0) */
comment|/* OBSOLETE     /* close (eb_desc); */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE     /* Do not try to close eb_desc again, later in the program.  */
operator|*
operator|/
comment|/* OBSOLETE     eb_stream = NULL; */
comment|/* OBSOLETE   eb_desc = -1; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #if defined (LOG_FILE) */
comment|/* OBSOLETE   if (log_file) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       if (ferror (log_file)) */
comment|/* OBSOLETE 	printf ("Error writing log file.\n"); */
comment|/* OBSOLETE       if (fclose (log_file) != 0) */
comment|/* OBSOLETE 	printf ("Error closing log file.\n"); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Terminate the open connection to the remote debugger. */
comment|/* OBSOLETE    Use this when you want to detach and do something else */
comment|/* OBSOLETE    with your gdb.  */
operator|*
operator|/
comment|/* OBSOLETE void */
comment|/* OBSOLETE eb_detach (int from_tty) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   pop_target ();		/* calls eb_close to do the real work */
operator|*
operator|/
comment|/* OBSOLETE   if (from_tty) */
comment|/* OBSOLETE     printf ("Ending remote %s debugging\n", target_shortname); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Tell the remote machine to resume.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE void */
comment|/* OBSOLETE eb_resume (ptid_t ptid, int step, enum target_signal sig) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   if (step) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       write (eb_desc, "t 1,s\n", 6); */
comment|/* OBSOLETE       /* Wait for the echo.  */
operator|*
operator|/
comment|/* OBSOLETE       expect ("t 1,s\r"); */
comment|/* OBSOLETE       /* Then comes a line containing the instruction we stepped to.  */
operator|*
operator|/
comment|/* OBSOLETE       expect ("\n@"); */
comment|/* OBSOLETE       /* Then we get the prompt.  */
operator|*
operator|/
comment|/* OBSOLETE       expect_prompt (); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE       /* Force the next eb_wait to return a trap.  Not doing anything */
comment|/* OBSOLETE          about I/O from the target means that the user has to type */
comment|/* OBSOLETE          "continue" to see any.  This should be fixed.  */
operator|*
operator|/
comment|/* OBSOLETE       need_artificial_trap = 1; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       if (need_gi) */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  need_gi = 0; */
comment|/* OBSOLETE 	  write (eb_desc, "gi\n", 3); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 	  /* Swallow the echo of "gi".  */
operator|*
operator|/
comment|/* OBSOLETE 	  expect ("gi\r"); */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE       else */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  write (eb_desc, "GR\n", 3); */
comment|/* OBSOLETE 	  /* Swallow the echo.  */
operator|*
operator|/
comment|/* OBSOLETE 	  expect ("GR\r"); */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Wait until the remote machine stops, then return, */
comment|/* OBSOLETE    storing status in STATUS just as `wait' would.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE ptid_t */
comment|/* OBSOLETE eb_wait (ptid_t ptid, struct target_waitstatus *status) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   /* Strings to look for.  '?' means match any single character.   */
comment|/* OBSOLETE      Note that with the algorithm we use, the initial character */
comment|/* OBSOLETE      of the string cannot recur in the string, or we will not */
comment|/* OBSOLETE      find some cases of the string in the input.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   static char bpt[] = "Invalid interrupt taken - #0x50 - "; */
comment|/* OBSOLETE   /* It would be tempting to look for "\n[__exit + 0x8]\n" */
comment|/* OBSOLETE      but that requires loading symbols with "yc i" and even if */
comment|/* OBSOLETE      we did do that we don't know that the file has symbols.  */
operator|*
operator|/
comment|/* OBSOLETE   static char exitmsg[] = "\n@????????I    JMPTI     GR121,LR0"; */
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
comment|/* OBSOLETE  */
comment|/* OBSOLETE   int old_timeout = timeout; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   status->kind = TARGET_WAITKIND_EXITED; */
comment|/* OBSOLETE   status->value.integer = 0; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (need_artificial_trap != 0) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE       status->value.sig = TARGET_SIGNAL_TRAP; */
comment|/* OBSOLETE       need_artificial_trap--; */
comment|/* OBSOLETE       return 0; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   timeout = 0;			/* Don't time out -- user program is running. */
operator|*
operator|/
comment|/* OBSOLETE   while (1) */
comment|/* OBSOLETE     { */
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
comment|/* OBSOLETE  */
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
comment|/* OBSOLETE  */
comment|/* OBSOLETE       if (!ch_handled) */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  char *p; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE 	  /* Print out any characters which have been swallowed.  */
operator|*
operator|/
comment|/* OBSOLETE 	  for (p = swallowed; p< swallowed_p; ++p) */
comment|/* OBSOLETE 	    putc (*p, stdout); */
comment|/* OBSOLETE 	  swallowed_p = swallowed; */
comment|/* OBSOLETE  */
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
comment|/* OBSOLETE  */
comment|/* OBSOLETE   return 0; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Return the name of register number REGNO */
comment|/* OBSOLETE    in the form input and output by EBMON. */
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
comment|/* OBSOLETE     sprintf (buf, "SR%03d", regno - VAB_REGNUM); */
comment|/* OBSOLETE   else if (regno == GR1_REGNUM) */
comment|/* OBSOLETE     strcpy (buf, "GR001"); */
comment|/* OBSOLETE   return buf; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Read the remote registers into the block REGS.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE eb_fetch_registers (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int reg_index; */
comment|/* OBSOLETE   int regnum_index; */
comment|/* OBSOLETE   char tempbuf[10]; */
comment|/* OBSOLETE   int i; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #if 0 */
comment|/* OBSOLETE   /* This should not be necessary, because one is supposed to read the */
comment|/* OBSOLETE      registers only when the inferior is stopped (at least with */
comment|/* OBSOLETE      ptrace() and why not make it the same for remote?).  */
operator|*
operator|/
comment|/* OBSOLETE   /* ^A is the "normal character" used to make sure we are talking to EBMON */
comment|/* OBSOLETE      and not to the program being debugged.  */
operator|*
operator|/
comment|/* OBSOLETE   write (eb_desc, "\001\n"); */
comment|/* OBSOLETE   expect_prompt (); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   write (eb_desc, "dw gr96,gr127\n", 14); */
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
comment|/* OBSOLETE   for (i = 0; i< 128; i += 32) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       /* The PC has a tendency to hang if we get these */
comment|/* OBSOLETE          all in one fell swoop ("dw lr0,lr127").  */
operator|*
operator|/
comment|/* OBSOLETE       sprintf (tempbuf, "dw lr%d\n", i); */
comment|/* OBSOLETE       write (eb_desc, tempbuf, strlen (tempbuf)); */
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
comment|/* OBSOLETE   write (eb_desc, "dw sr133,sr133\n", 15); */
comment|/* OBSOLETE   expect ("SR133          "); */
comment|/* OBSOLETE   get_hex_regs (1, BP_REGNUM); */
comment|/* OBSOLETE   expect ("\n"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   write (eb_desc, "dw sr134,sr134\n", 15); */
comment|/* OBSOLETE   expect ("SR134                   "); */
comment|/* OBSOLETE   get_hex_regs (1, FC_REGNUM); */
comment|/* OBSOLETE   expect ("\n"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   write (eb_desc, "dw sr135,sr135\n", 15); */
comment|/* OBSOLETE   expect ("SR135                            "); */
comment|/* OBSOLETE   get_hex_regs (1, CR_REGNUM); */
comment|/* OBSOLETE   expect ("\n"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   write (eb_desc, "dw sr131,sr131\n", 15); */
comment|/* OBSOLETE   expect ("SR131                            "); */
comment|/* OBSOLETE   get_hex_regs (1, Q_REGNUM); */
comment|/* OBSOLETE   expect ("\n"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   write (eb_desc, "dw sr0,sr14\n", 12); */
comment|/* OBSOLETE   for (reg_index = 0, regnum_index = VAB_REGNUM; */
comment|/* OBSOLETE        regnum_index<= LRU_REGNUM; */
comment|/* OBSOLETE        regnum_index += 4, reg_index += 4) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       sprintf (tempbuf, "SR%03d ", reg_index); */
comment|/* OBSOLETE       expect (tempbuf); */
comment|/* OBSOLETE       get_hex_regs (reg_index == 12 ? 3 : 4, regnum_index); */
comment|/* OBSOLETE       expect ("\n"); */
comment|/* OBSOLETE     } */
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
comment|/* OBSOLETE   write (eb_desc, "dw gr1,gr1\n", 11); */
comment|/* OBSOLETE   expect ("GR001 "); */
comment|/* OBSOLETE   get_hex_regs (1, GR1_REGNUM); */
comment|/* OBSOLETE   expect_prompt (); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Fetch register REGNO, or all registers if REGNO is -1. */
comment|/* OBSOLETE    Returns errno value.  */
operator|*
operator|/
comment|/* OBSOLETE void */
comment|/* OBSOLETE eb_fetch_register (int regno) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   if (regno == -1) */
comment|/* OBSOLETE     eb_fetch_registers (); */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       char *name = get_reg_name (regno); */
comment|/* OBSOLETE       fprintf (eb_stream, "dw %s,%s\n", name, name); */
comment|/* OBSOLETE       expect (name); */
comment|/* OBSOLETE       expect (" "); */
comment|/* OBSOLETE       get_hex_regs (1, regno); */
comment|/* OBSOLETE       expect_prompt (); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   return; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Store the remote registers from the contents of the block REGS.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE eb_store_registers (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int i, j; */
comment|/* OBSOLETE   fprintf (eb_stream, "s gr1,%x\n", read_register (GR1_REGNUM)); */
comment|/* OBSOLETE   expect_prompt (); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   for (j = 0; j< 32; j += 16) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       fprintf (eb_stream, "s gr%d,", j + 96); */
comment|/* OBSOLETE       for (i = 0; i< 15; ++i) */
comment|/* OBSOLETE 	fprintf (eb_stream, "%x,", read_register (GR96_REGNUM + j + i)); */
comment|/* OBSOLETE       fprintf (eb_stream, "%x\n", read_register (GR96_REGNUM + j + 15)); */
comment|/* OBSOLETE       expect_prompt (); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   for (j = 0; j< 128; j += 16) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       fprintf (eb_stream, "s lr%d,", j); */
comment|/* OBSOLETE       for (i = 0; i< 15; ++i) */
comment|/* OBSOLETE 	fprintf (eb_stream, "%x,", read_register (LR0_REGNUM + j + i)); */
comment|/* OBSOLETE       fprintf (eb_stream, "%x\n", read_register (LR0_REGNUM + j + 15)); */
comment|/* OBSOLETE       expect_prompt (); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   fprintf (eb_stream, "s sr133,%x,%x,%x\n", read_register (BP_REGNUM), */
comment|/* OBSOLETE 	   read_register (FC_REGNUM), read_register (CR_REGNUM)); */
comment|/* OBSOLETE   expect_prompt (); */
comment|/* OBSOLETE   fprintf (eb_stream, "s sr131,%x\n", read_register (Q_REGNUM)); */
comment|/* OBSOLETE   expect_prompt (); */
comment|/* OBSOLETE   fprintf (eb_stream, "s sr0,"); */
comment|/* OBSOLETE   for (i = 0; i< 11; ++i) */
comment|/* OBSOLETE     fprintf (eb_stream, "%x,", read_register (VAB_REGNUM + i)); */
comment|/* OBSOLETE   fprintf (eb_stream, "%x\n", read_register (VAB_REGNUM + 11)); */
comment|/* OBSOLETE   expect_prompt (); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Store register REGNO, or all if REGNO == 0. */
comment|/* OBSOLETE    Return errno value.  */
operator|*
operator|/
comment|/* OBSOLETE void */
comment|/* OBSOLETE eb_store_register (int regno) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   if (regno == -1) */
comment|/* OBSOLETE     eb_store_registers (); */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       char *name = get_reg_name (regno); */
comment|/* OBSOLETE       fprintf (eb_stream, "s %s,%x\n", name, read_register (regno)); */
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
comment|/* OBSOLETE eb_prepare_to_store (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   /* Do nothing, since we can store individual regs */
operator|*
operator|/
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Transfer LEN bytes between GDB address MYADDR and target address */
comment|/* OBSOLETE    MEMADDR.  If WRITE is non-zero, transfer them to the target, */
comment|/* OBSOLETE    otherwise transfer them from the target.  TARGET is unused. */
comment|/* OBSOLETE  */
comment|/* OBSOLETE    Returns the number of bytes transferred. */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE int */
comment|/* OBSOLETE eb_xfer_inferior_memory (CORE_ADDR memaddr, char *myaddr, int len, int write, */
comment|/* OBSOLETE 			 struct mem_attrib *attrib ATTRIBUTE_UNUSED, */
comment|/* OBSOLETE 			 struct target_ops *target ATTRIBUTE_UNUSED) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   if (write) */
comment|/* OBSOLETE     return eb_write_inferior_memory (memaddr, myaddr, len); */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     return eb_read_inferior_memory (memaddr, myaddr, len); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE void */
comment|/* OBSOLETE eb_files_info (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   printf ("\tAttached to %s at %d baud and running program %s.\n", */
comment|/* OBSOLETE 	  dev_name, baudrate, prog_name); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Copy LEN bytes of data from debugger memory at MYADDR */
comment|/* OBSOLETE    to inferior's memory at MEMADDR.  Returns length moved.  */
operator|*
operator|/
comment|/* OBSOLETE int */
comment|/* OBSOLETE eb_write_inferior_memory (CORE_ADDR memaddr, char *myaddr, int len) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int i; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   for (i = 0; i< len; i++) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       if ((i % 16) == 0) */
comment|/* OBSOLETE 	fprintf (eb_stream, "sb %x,", memaddr + i); */
comment|/* OBSOLETE       if ((i % 16) == 15 || i == len - 1) */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  fprintf (eb_stream, "%x\n", ((unsigned char *) myaddr)[i]); */
comment|/* OBSOLETE 	  expect_prompt (); */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE       else */
comment|/* OBSOLETE 	fprintf (eb_stream, "%x,", ((unsigned char *) myaddr)[i]); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   return len; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Read LEN bytes from inferior memory at MEMADDR.  Put the result */
comment|/* OBSOLETE    at debugger address MYADDR.  Returns length moved.  */
operator|*
operator|/
comment|/* OBSOLETE int */
comment|/* OBSOLETE eb_read_inferior_memory (CORE_ADDR memaddr, char *myaddr, int len) */
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
comment|/* OBSOLETE      eb_read_bytes (CORE_ADDR_MAX - 4, foo, 4) */
comment|/* OBSOLETE      works--it never adds len to memaddr and gets 0.  */
operator|*
operator|/
comment|/* OBSOLETE   /* However, something like */
comment|/* OBSOLETE      eb_read_bytes (CORE_ADDR_MAX - 3, foo, 4) */
comment|/* OBSOLETE      doesn't need to work.  Detect it and give up if there's an attempt */
comment|/* OBSOLETE      to do that.  */
operator|*
operator|/
comment|/* OBSOLETE   if (((memaddr - 1) + len)< memaddr) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       errno = EIO; */
comment|/* OBSOLETE       return 0; */
comment|/* OBSOLETE     } */
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
comment|/* OBSOLETE       fprintf (eb_stream, "db %x,%x\n", startaddr, */
comment|/* OBSOLETE 	       (startaddr - 1) + len_this_pass); */
comment|/* OBSOLETE       expect ("\n"); */
comment|/* OBSOLETE  */
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
comment|/* OBSOLETE   return len; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE eb_kill (char *args, int from_tty) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   return;			/* Ignore attempts to kill target system */
operator|*
operator|/
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Clean up when a program exits. */
comment|/* OBSOLETE  */
comment|/* OBSOLETE    The program actually lives on in the remote processor's RAM, and may be */
comment|/* OBSOLETE    run again without a download.  Don't leave it full of breakpoint */
comment|/* OBSOLETE    instructions.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE void */
comment|/* OBSOLETE eb_mourn_inferior (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   remove_breakpoints (); */
comment|/* OBSOLETE   unpush_target (&eb_ops); */
comment|/* OBSOLETE   generic_mourn_inferior ();	/* Do all the proper things now */
operator|*
operator|/
comment|/* OBSOLETE } */
comment|/* OBSOLETE /* Define the target subroutine names */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE struct target_ops eb_ops; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE init_eb_ops (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   eb_ops.to_shortname = "amd-eb"; */
comment|/* OBSOLETE   eb_ops.to_longname = "Remote serial AMD EBMON target"; */
comment|/* OBSOLETE   eb_ops.to_doc = "Use a remote computer running EBMON connected by a serial line.\n\ */
comment|/* OBSOLETE Arguments are the name of the device for the serial line,\n\ */
comment|/* OBSOLETE the speed to connect at in bits per second, and the filename of the\n\ */
comment|/* OBSOLETE executable as it exists on the remote computer.  For example,\n\ */
comment|/* OBSOLETE target amd-eb /dev/ttya 9600 demo", */
comment|/* OBSOLETE     eb_ops.to_open = eb_open; */
comment|/* OBSOLETE   eb_ops.to_close = eb_close; */
comment|/* OBSOLETE   eb_ops.to_attach = 0; */
comment|/* OBSOLETE   eb_ops.to_post_attach = NULL; */
comment|/* OBSOLETE   eb_ops.to_require_attach = NULL; */
comment|/* OBSOLETE   eb_ops.to_detach = eb_detach; */
comment|/* OBSOLETE   eb_ops.to_require_detach = NULL; */
comment|/* OBSOLETE   eb_ops.to_resume = eb_resume; */
comment|/* OBSOLETE   eb_ops.to_wait = eb_wait; */
comment|/* OBSOLETE   eb_ops.to_post_wait = NULL; */
comment|/* OBSOLETE   eb_ops.to_fetch_registers = eb_fetch_register; */
comment|/* OBSOLETE   eb_ops.to_store_registers = eb_store_register; */
comment|/* OBSOLETE   eb_ops.to_prepare_to_store = eb_prepare_to_store; */
comment|/* OBSOLETE   eb_ops.to_xfer_memory = eb_xfer_inferior_memory; */
comment|/* OBSOLETE   eb_ops.to_files_info = eb_files_info; */
comment|/* OBSOLETE   eb_ops.to_insert_breakpoint = 0; */
comment|/* OBSOLETE   eb_ops.to_remove_breakpoint = 0;	/* Breakpoints */
operator|*
operator|/
comment|/* OBSOLETE   eb_ops.to_terminal_init = 0; */
comment|/* OBSOLETE   eb_ops.to_terminal_inferior = 0; */
comment|/* OBSOLETE   eb_ops.to_terminal_ours_for_output = 0; */
comment|/* OBSOLETE   eb_ops.to_terminal_ours = 0; */
comment|/* OBSOLETE   eb_ops.to_terminal_info = 0;	/* Terminal handling */
operator|*
operator|/
comment|/* OBSOLETE   eb_ops.to_kill = eb_kill; */
comment|/* OBSOLETE   eb_ops.to_load = generic_load;	/* load */
operator|*
operator|/
comment|/* OBSOLETE   eb_ops.to_lookup_symbol = 0;	/* lookup_symbol */
operator|*
operator|/
comment|/* OBSOLETE   eb_ops.to_create_inferior = eb_create_inferior; */
comment|/* OBSOLETE   eb_ops.to_post_startup_inferior = NULL; */
comment|/* OBSOLETE   eb_ops.to_acknowledge_created_inferior = NULL; */
comment|/* OBSOLETE   eb_ops.to_clone_and_follow_inferior = NULL; */
comment|/* OBSOLETE   eb_ops.to_post_follow_inferior_by_clone = NULL; */
comment|/* OBSOLETE   eb_ops.to_insert_fork_catchpoint = NULL; */
comment|/* OBSOLETE   eb_ops.to_remove_fork_catchpoint = NULL; */
comment|/* OBSOLETE   eb_ops.to_insert_vfork_catchpoint = NULL; */
comment|/* OBSOLETE   eb_ops.to_remove_vfork_catchpoint = NULL; */
comment|/* OBSOLETE   eb_ops.to_has_forked = NULL; */
comment|/* OBSOLETE   eb_ops.to_has_vforked = NULL; */
comment|/* OBSOLETE   eb_ops.to_can_follow_vfork_prior_to_exec = NULL; */
comment|/* OBSOLETE   eb_ops.to_post_follow_vfork = NULL; */
comment|/* OBSOLETE   eb_ops.to_insert_exec_catchpoint = NULL; */
comment|/* OBSOLETE   eb_ops.to_remove_exec_catchpoint = NULL; */
comment|/* OBSOLETE   eb_ops.to_has_execd = NULL; */
comment|/* OBSOLETE   eb_ops.to_reported_exec_events_per_exec_call = NULL; */
comment|/* OBSOLETE   eb_ops.to_has_exited = NULL; */
comment|/* OBSOLETE   eb_ops.to_mourn_inferior = eb_mourn_inferior; */
comment|/* OBSOLETE   eb_ops.to_can_run = 0;	/* can_run */
operator|*
operator|/
comment|/* OBSOLETE   eb_ops.to_notice_signals = 0;	/* notice_signals */
operator|*
operator|/
comment|/* OBSOLETE   eb_ops.to_thread_alive = 0;	/* thread-alive */
operator|*
operator|/
comment|/* OBSOLETE   eb_ops.to_stop = 0;		/* to_stop */
operator|*
operator|/
comment|/* OBSOLETE   eb_ops.to_pid_to_exec_file = NULL; */
comment|/* OBSOLETE   eb_ops.to_stratum = process_stratum; */
comment|/* OBSOLETE   eb_ops.DONT_USE = 0;		/* next */
operator|*
operator|/
comment|/* OBSOLETE   eb_ops.to_has_all_memory = 1; */
comment|/* OBSOLETE   eb_ops.to_has_memory = 1; */
comment|/* OBSOLETE   eb_ops.to_has_stack = 1; */
comment|/* OBSOLETE   eb_ops.to_has_registers = 1; */
comment|/* OBSOLETE   eb_ops.to_has_execution = 1;	/* all mem, mem, stack, regs, exec */
operator|*
operator|/
comment|/* OBSOLETE   eb_ops.to_sections = 0;	/* sections */
operator|*
operator|/
comment|/* OBSOLETE   eb_ops.to_sections_end = 0;	/* sections end */
operator|*
operator|/
comment|/* OBSOLETE   eb_ops.to_magic = OPS_MAGIC;	/* Always the last thing */
operator|*
operator|/
end_expr_stmt

begin_comment
comment|/* OBSOLETE }; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE void */
end_comment

begin_comment
comment|/* OBSOLETE _initialize_remote_eb (void) */
end_comment

begin_comment
comment|/* OBSOLETE { */
end_comment

begin_comment
comment|/* OBSOLETE   init_eb_ops (); */
end_comment

begin_comment
comment|/* OBSOLETE   add_target (&eb_ops); */
end_comment

begin_comment
comment|/* OBSOLETE } */
end_comment

end_unit

