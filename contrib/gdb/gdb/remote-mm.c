begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* OBSOLETE /* Remote debugging interface for Am290*0 running MiniMON monitor, for GDB. */
end_comment

begin_comment
comment|/* OBSOLETE    Copyright 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1998, 1999, 2000, */
end_comment

begin_comment
comment|/* OBSOLETE    2001 Free Software Foundation, Inc. */
end_comment

begin_comment
comment|/* OBSOLETE    Originally written by Daniel Mann at AMD. */
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
comment|/* OBSOLETE /* This is like remote.c but ecpects MiniMON to be running on the Am29000  */
comment|/* OBSOLETE    target hardware. */
comment|/* OBSOLETE    - David Wood (wood@lab.ultra.nyu.edu) at New York University adapted this */
comment|/* OBSOLETE    file to gdb 3.95.  I was unable to get this working on sun3os4 */
comment|/* OBSOLETE    with termio, only with sgtty.  Because we are only attempting to */
comment|/* OBSOLETE    use this module to debug our kernel, which is already loaded when */
comment|/* OBSOLETE    gdb is started up, I did not code up the file downloading facilities.   */
comment|/* OBSOLETE    As a result this module has only the stubs to download files.  */
comment|/* OBSOLETE    You should get tagged at compile time if you need to make any  */
comment|/* OBSOLETE    changes/additions.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE #include "defs.h" */
comment|/* OBSOLETE #include "inferior.h" */
comment|/* OBSOLETE #include "value.h" */
comment|/* OBSOLETE #include<ctype.h> */
comment|/* OBSOLETE #include<fcntl.h> */
comment|/* OBSOLETE #include<signal.h> */
comment|/* OBSOLETE #include<errno.h> */
comment|/* OBSOLETE #include "gdb_string.h" */
comment|/* OBSOLETE #include "terminal.h" */
comment|/* OBSOLETE #include "minimon.h" */
comment|/* OBSOLETE #include "target.h" */
comment|/* OBSOLETE #include "regcache.h" */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Offset of member MEMBER in a struct of type TYPE.  */
operator|*
operator|/
comment|/* OBSOLETE #define offsetof(TYPE, MEMBER) ((int)&((TYPE *)0)->MEMBER) */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #define DRAIN_INPUT()	(msg_recv_serial((union msg_t*)0)) */
comment|/* OBSOLETE  */
comment|/* OBSOLETE extern int stop_soon_quietly;	/* for wait_for_inferior */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static void mm_resume (ptid_t ptid, int step, enum target_signal sig) */
comment|/* OBSOLETE static void mm_fetch_registers (); */
comment|/* OBSOLETE static int fetch_register (); */
comment|/* OBSOLETE static void mm_store_registers (); */
comment|/* OBSOLETE static int store_register (); */
comment|/* OBSOLETE static int regnum_to_srnum (); */
comment|/* OBSOLETE static void mm_close (); */
comment|/* OBSOLETE static char *msg_str (); */
comment|/* OBSOLETE static char *error_msg_str (); */
comment|/* OBSOLETE static int expect_msg (); */
comment|/* OBSOLETE static void init_target_mm (); */
comment|/* OBSOLETE static int mm_memory_space (); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #define FREEZE_MODE     (read_register(CPS_REGNUM)&& 0x400) */
comment|/* OBSOLETE #define USE_SHADOW_PC	((processor_type == a29k_freeze_mode)&& FREEZE_MODE) */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* FIXME: Replace with `set remotedebug'.  */
operator|*
operator|/
comment|/* OBSOLETE #define LLOG_FILE "minimon.log" */
comment|/* OBSOLETE #if defined (LOG_FILE) */
comment|/* OBSOLETE FILE *log_file; */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /*   */
comment|/* OBSOLETE  * Size of message buffers.  I couldn't get memory reads to work when */
comment|/* OBSOLETE  * the byte_count was larger than 512 (it may be a baud rate problem). */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE #define BUFER_SIZE  512 */
comment|/* OBSOLETE /*  */
comment|/* OBSOLETE  * Size of data area in message buffer on the TARGET (remote system). */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE #define MAXDATA_T  (target_config.max_msg_size - \ */
comment|/* OBSOLETE 			offsetof(struct write_r_msg_t,data[0])) */
comment|/* OBSOLETE /*                */
comment|/* OBSOLETE  * Size of data area in message buffer on the HOST (gdb).  */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE #define MAXDATA_H  (BUFER_SIZE - offsetof(struct write_r_msg_t,data[0])) */
comment|/* OBSOLETE /*  */
comment|/* OBSOLETE  * Defined as the minimum size of data areas of the two message buffers  */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE #define MAXDATA	   (MAXDATA_H< MAXDATA_T ? MAXDATA_H : MAXDATA_T) */
comment|/* OBSOLETE  */
comment|/* OBSOLETE static char out_buf[BUFER_SIZE]; */
comment|/* OBSOLETE static char in_buf[BUFER_SIZE]; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE int msg_recv_serial (); */
comment|/* OBSOLETE int msg_send_serial (); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #define MAX_RETRIES 5000 */
comment|/* OBSOLETE extern struct target_ops mm_ops;	/* Forward declaration */
operator|*
operator|/
comment|/* OBSOLETE struct config_msg_t target_config;	/* HIF needs this */
operator|*
operator|/
comment|/* OBSOLETE union msg_t *out_msg_buf = (union msg_t *) out_buf; */
comment|/* OBSOLETE union msg_t *in_msg_buf = (union msg_t *) in_buf; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE static int timeout = 5; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Descriptor for I/O to remote machine.  Initialize it to -1 so that */
comment|/* OBSOLETE    mm_open knows that we don't have a file open when the program */
comment|/* OBSOLETE    starts.  */
operator|*
operator|/
comment|/* OBSOLETE int mm_desc = -1; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* stream which is fdopen'd from mm_desc.  Only valid when */
comment|/* OBSOLETE    mm_desc != -1.  */
operator|*
operator|/
comment|/* OBSOLETE FILE *mm_stream; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Called when SIGALRM signal sent due to alarm() timeout.  */
operator|*
operator|/
comment|/* OBSOLETE #ifndef HAVE_TERMIO */
comment|/* OBSOLETE  */
comment|/* OBSOLETE volatile int n_alarms; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE mm_timer (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE #if 0 */
comment|/* OBSOLETE   if (kiodebug) */
comment|/* OBSOLETE     printf ("mm_timer called\n"); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE   n_alarms++; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE #endif	/* HAVE_TERMIO */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* malloc'd name of the program on the remote system.  */
operator|*
operator|/
comment|/* OBSOLETE static char *prog_name = NULL; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Number of SIGTRAPs we need to simulate.  That is, the next */
comment|/* OBSOLETE    NEED_ARTIFICIAL_TRAP calls to mm_wait should just return */
comment|/* OBSOLETE    SIGTRAP without actually waiting for anything.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE /**************************************************** REMOTE_CREATE_INFERIOR */
operator|*
operator|/
comment|/* OBSOLETE /* This is called not only when we first attach, but also when the */
comment|/* OBSOLETE    user types "run" after having attached.  */
operator|*
operator|/
end_expr_stmt

begin_comment
comment|/* OBSOLETE static void */
end_comment

begin_comment
comment|/* OBSOLETE mm_create_inferior (char *execfile, char *args, char **env) */
end_comment

begin_comment
comment|/* OBSOLETE { */
end_comment

begin_comment
comment|/* OBSOLETE #define MAX_TOKENS 25 */
end_comment

begin_comment
comment|/* OBSOLETE #define BUFFER_SIZE 256 */
end_comment

begin_comment
comment|/* OBSOLETE   int token_count; */
end_comment

begin_comment
comment|/* OBSOLETE   int result; */
end_comment

begin_comment
comment|/* OBSOLETE   char *token[MAX_TOKENS]; */
end_comment

begin_comment
comment|/* OBSOLETE   char cmd_line[BUFFER_SIZE]; */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE   if (args&& *args) */
end_comment

begin_comment
comment|/* OBSOLETE     error ("Can't pass arguments to remote mm process (yet)."); */
end_comment

begin_comment
comment|/* OBSOLETE  */
end_comment

begin_comment
comment|/* OBSOLETE   if (execfile == 0 /* || exec_bfd == 0 */
end_comment

begin_expr_stmt
unit|)
operator|*
operator|/
comment|/* OBSOLETE     error ("No executable file specified"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (!mm_stream) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       printf ("Minimon not open yet.\n"); */
comment|/* OBSOLETE       return; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* On ultra3 (NYU) we assume the kernel is already running so there is */
comment|/* OBSOLETE      no file to download. */
comment|/* OBSOLETE      FIXME: Fixed required here -> load your program, possibly with mm_load(). */
comment|/* OBSOLETE    */
operator|*
operator|/
comment|/* OBSOLETE   printf_filtered ("\n\ */
comment|/* OBSOLETE Assuming you are at NYU debuging a kernel, i.e., no need to download.\n\n"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* We will get a task spawn event immediately.  */
operator|*
operator|/
comment|/* OBSOLETE   init_wait_for_inferior (); */
comment|/* OBSOLETE   clear_proceed_status (); */
comment|/* OBSOLETE   stop_soon_quietly = 1; */
comment|/* OBSOLETE   proceed (-1, TARGET_SIGNAL_DEFAULT, 0); */
comment|/* OBSOLETE   normal_stop (); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE /**************************************************** REMOTE_MOURN_INFERIOR */
operator|*
operator|/
comment|/* OBSOLETE static void */
comment|/* OBSOLETE mm_mourn (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   pop_target ();		/* Pop back to no-child state */
operator|*
operator|/
comment|/* OBSOLETE   generic_mourn_inferior (); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /********************************************************************** damn_b */
comment|/* OBSOLETE */
operator|*
operator|/
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
comment|/* OBSOLETE /***************************************************************** REMOTE_OPEN */
comment|/* OBSOLETE ** Open a connection to remote minimon. */
comment|/* OBSOLETE    NAME is the filename used for communication, then a space, */
comment|/* OBSOLETE    then the baud rate. */
comment|/* OBSOLETE    'target adapt /dev/ttya 9600 [prognam]' for example. */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static char *dev_name; */
comment|/* OBSOLETE int baudrate = 9600; */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE mm_open (char *name, int from_tty) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   TERMINAL sg; */
comment|/* OBSOLETE   unsigned int prl; */
comment|/* OBSOLETE   char *p; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Find the first whitespace character, it separates dev_name from */
comment|/* OBSOLETE      prog_name.  */
operator|*
operator|/
comment|/* OBSOLETE   for (p = name; */
comment|/* OBSOLETE        p&& *p&& !isspace (*p); p++) */
comment|/* OBSOLETE     ; */
comment|/* OBSOLETE   if (p == 0 || *p == '\0') */
comment|/* OBSOLETE   erroid: */
comment|/* OBSOLETE     error ("Usage :<command><serial-device><baud-rate> [progname]"); */
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
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (mm_desc>= 0) */
comment|/* OBSOLETE     close (mm_desc); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   mm_desc = open (dev_name, O_RDWR); */
comment|/* OBSOLETE   if (mm_desc< 0) */
comment|/* OBSOLETE     perror_with_name (dev_name); */
comment|/* OBSOLETE   ioctl (mm_desc, TIOCGETP,&sg); */
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
comment|/* OBSOLETE   sg.sg_flags |= RAW; */
comment|/* OBSOLETE   sg.sg_flags |= ANYP; */
comment|/* OBSOLETE   sg.sg_flags&= ~ECHO; */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE  */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   ioctl (mm_desc, TIOCSETP,&sg); */
comment|/* OBSOLETE   mm_stream = fdopen (mm_desc, "r+"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   push_target (&mm_ops); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #ifndef HAVE_TERMIO */
comment|/* OBSOLETE #ifndef NO_SIGINTERRUPT */
comment|/* OBSOLETE   /* Cause SIGALRM's to make reads fail with EINTR instead of resuming */
comment|/* OBSOLETE      the read.  */
operator|*
operator|/
comment|/* OBSOLETE   if (siginterrupt (SIGALRM, 1) != 0) */
comment|/* OBSOLETE     perror ("mm_open: error in siginterrupt"); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Set up read timeout timer.  */
operator|*
operator|/
comment|/* OBSOLETE   if ((void (*)) signal (SIGALRM, mm_timer) == (void (*)) -1) */
comment|/* OBSOLETE     perror ("mm_open: error in signal"); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #if defined (LOG_FILE) */
comment|/* OBSOLETE   log_file = fopen (LOG_FILE, "w"); */
comment|/* OBSOLETE   if (log_file == NULL) */
comment|/* OBSOLETE     perror_with_name (LOG_FILE); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE   /* */
comment|/* OBSOLETE      ** Initialize target configuration structure (global) */
comment|/* OBSOLETE    */
operator|*
operator|/
comment|/* OBSOLETE   DRAIN_INPUT (); */
comment|/* OBSOLETE   out_msg_buf->config_req_msg.code = CONFIG_REQ; */
comment|/* OBSOLETE   out_msg_buf->config_req_msg.length = 4 * 0; */
comment|/* OBSOLETE   msg_send_serial (out_msg_buf);	/* send config request message */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   expect_msg (CONFIG, in_msg_buf, 1); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   a29k_get_processor_type (); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Print out some stuff, letting the user now what's going on */
operator|*
operator|/
comment|/* OBSOLETE   printf_filtered ("Connected to MiniMon via %s.\n", dev_name); */
comment|/* OBSOLETE   /* FIXME: can this restriction be removed? */
operator|*
operator|/
comment|/* OBSOLETE   printf_filtered ("Remote debugging using virtual addresses works only\n"); */
comment|/* OBSOLETE   printf_filtered ("\twhen virtual addresses map 1:1 to physical addresses.\n") */
comment|/* OBSOLETE     ; */
comment|/* OBSOLETE   if (processor_type != a29k_freeze_mode) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       fprintf_filtered (gdb_stderr, */
comment|/* OBSOLETE 			"Freeze-mode debugging not available, and can only be done on an A29050.\n"); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   target_config.code = CONFIG; */
comment|/* OBSOLETE   target_config.length = 0; */
comment|/* OBSOLETE   target_config.processor_id = in_msg_buf->config_msg.processor_id; */
comment|/* OBSOLETE   target_config.version = in_msg_buf->config_msg.version; */
comment|/* OBSOLETE   target_config.I_mem_start = in_msg_buf->config_msg.I_mem_start; */
comment|/* OBSOLETE   target_config.I_mem_size = in_msg_buf->config_msg.I_mem_size; */
comment|/* OBSOLETE   target_config.D_mem_start = in_msg_buf->config_msg.D_mem_start; */
comment|/* OBSOLETE   target_config.D_mem_size = in_msg_buf->config_msg.D_mem_size; */
comment|/* OBSOLETE   target_config.ROM_start = in_msg_buf->config_msg.ROM_start; */
comment|/* OBSOLETE   target_config.ROM_size = in_msg_buf->config_msg.ROM_size; */
comment|/* OBSOLETE   target_config.max_msg_size = in_msg_buf->config_msg.max_msg_size; */
comment|/* OBSOLETE   target_config.max_bkpts = in_msg_buf->config_msg.max_bkpts; */
comment|/* OBSOLETE   target_config.coprocessor = in_msg_buf->config_msg.coprocessor; */
comment|/* OBSOLETE   target_config.reserved = in_msg_buf->config_msg.reserved; */
comment|/* OBSOLETE   if (from_tty) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       printf ("Connected to MiniMON :\n"); */
comment|/* OBSOLETE       printf ("    Debugcore version            %d.%d\n", */
comment|/* OBSOLETE 	      0x0f& (target_config.version>> 4), */
comment|/* OBSOLETE 	      0x0f& (target_config.version)); */
comment|/* OBSOLETE       printf ("    Configuration version        %d.%d\n", */
comment|/* OBSOLETE 	      0x0f& (target_config.version>> 12), */
comment|/* OBSOLETE 	      0x0f& (target_config.version>> 8)); */
comment|/* OBSOLETE       printf ("    Message system version       %d.%d\n", */
comment|/* OBSOLETE 	      0x0f& (target_config.version>> 20), */
comment|/* OBSOLETE 	      0x0f& (target_config.version>> 16)); */
comment|/* OBSOLETE       printf ("    Communication driver version %d.%d\n", */
comment|/* OBSOLETE 	      0x0f& (target_config.version>> 28), */
comment|/* OBSOLETE 	      0x0f& (target_config.version>> 24)); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Leave the target running...  */
comment|/* OBSOLETE    * The above message stopped the target in the dbg core (MiniMon),   */
comment|/* OBSOLETE    * so restart the target out of MiniMon,  */
comment|/* OBSOLETE    */
operator|*
operator|/
comment|/* OBSOLETE   out_msg_buf->go_msg.code = GO; */
comment|/* OBSOLETE   out_msg_buf->go_msg.length = 0; */
comment|/* OBSOLETE   msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE   /* No message to expect after a GO */
operator|*
operator|/
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /**************************************************************** REMOTE_CLOSE */
comment|/* OBSOLETE ** Close the open connection to the minimon debugger. */
comment|/* OBSOLETE    Use this when you want to detach and do something else */
comment|/* OBSOLETE    with your gdb.  */
operator|*
operator|/
comment|/* OBSOLETE static void */
comment|/* OBSOLETE mm_close (			/*FIXME: how is quitting used */
operator|*
operator|/
comment|/* OBSOLETE 	   int quitting) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   if (mm_desc< 0) */
comment|/* OBSOLETE     error ("Can't close remote connection: not debugging remotely."); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* We should never get here if there isn't something valid in */
comment|/* OBSOLETE      mm_desc and mm_stream.   */
comment|/* OBSOLETE  */
comment|/* OBSOLETE      Due to a bug in Unix, fclose closes not only the stdio stream, */
comment|/* OBSOLETE      but also the file descriptor.  So we don't actually close */
comment|/* OBSOLETE      mm_desc.  */
operator|*
operator|/
comment|/* OBSOLETE   DRAIN_INPUT (); */
comment|/* OBSOLETE   fclose (mm_stream); */
comment|/* OBSOLETE   /* close (mm_desc); */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Do not try to close mm_desc again, later in the program.  */
operator|*
operator|/
comment|/* OBSOLETE   mm_stream = NULL; */
comment|/* OBSOLETE   mm_desc = -1; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #if defined (LOG_FILE) */
comment|/* OBSOLETE   if (ferror (log_file)) */
comment|/* OBSOLETE     printf ("Error writing log file.\n"); */
comment|/* OBSOLETE   if (fclose (log_file) != 0) */
comment|/* OBSOLETE     printf ("Error closing log file.\n"); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   printf ("Ending remote debugging\n"); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /************************************************************* REMOTE_ATACH */
operator|*
operator|/
comment|/* OBSOLETE /* Attach to a program that is already loaded and running  */
comment|/* OBSOLETE  * Upon exiting the process's execution is stopped. */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE static void */
comment|/* OBSOLETE mm_attach (char *args, int from_tty) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (!mm_stream) */
comment|/* OBSOLETE     error ("MiniMon not opened yet, use the 'target minimon' command.\n"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (from_tty) */
comment|/* OBSOLETE     printf ("Attaching to remote program %s...\n", prog_name); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Make sure the target is currently running, it is supposed to be. */
operator|*
operator|/
comment|/* OBSOLETE   /* FIXME: is it ok to send MiniMon a BREAK if it is already stopped in  */
comment|/* OBSOLETE    *  the dbg core.  If so, we don't need to send this GO. */
comment|/* OBSOLETE    */
operator|*
operator|/
comment|/* OBSOLETE   out_msg_buf->go_msg.code = GO; */
comment|/* OBSOLETE   out_msg_buf->go_msg.length = 0; */
comment|/* OBSOLETE   msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE   sleep (2);			/* At the worst it will stop, receive a message, continue */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Send the mm a break. */
operator|*
operator|/
comment|/* OBSOLETE   out_msg_buf->break_msg.code = BREAK; */
comment|/* OBSOLETE   out_msg_buf->break_msg.length = 0; */
comment|/* OBSOLETE   msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE /********************************************************** REMOTE_DETACH */
operator|*
operator|/
comment|/* OBSOLETE /* Terminate the open connection to the remote debugger. */
comment|/* OBSOLETE    Use this when you want to detach and do something else */
comment|/* OBSOLETE    with your gdb.  Leave remote process running (with no breakpoints set). */
operator|*
operator|/
comment|/* OBSOLETE static void */
comment|/* OBSOLETE mm_detach (char *args, int from_tty) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   remove_breakpoints ();	/* Just in case there were any left in */
operator|*
operator|/
comment|/* OBSOLETE   out_msg_buf->go_msg.code = GO; */
comment|/* OBSOLETE   out_msg_buf->go_msg.length = 0; */
comment|/* OBSOLETE   msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE   pop_target ();		/* calls mm_close to do the real work */
operator|*
operator|/
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /*************************************************************** REMOTE_RESUME */
comment|/* OBSOLETE ** Tell the remote machine to resume.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE mm_resume (ptid_t ptid, int step, enum target_signal sig) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   if (sig != TARGET_SIGNAL_0) */
comment|/* OBSOLETE     warning ("Can't send signals to a remote MiniMon system."); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (step) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       out_msg_buf->step_msg.code = STEP; */
comment|/* OBSOLETE       out_msg_buf->step_msg.length = 1 * 4; */
comment|/* OBSOLETE       out_msg_buf->step_msg.count = 1;	/* step 1 instruction */
operator|*
operator|/
comment|/* OBSOLETE       msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       out_msg_buf->go_msg.code = GO; */
comment|/* OBSOLETE       out_msg_buf->go_msg.length = 0; */
comment|/* OBSOLETE       msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /***************************************************************** REMOTE_WAIT */
comment|/* OBSOLETE ** Wait until the remote machine stops, then return, */
comment|/* OBSOLETE    storing status in STATUS just as `wait' would.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static ptid_t */
comment|/* OBSOLETE mm_wait (ptid_t ptid, struct target_waitstatus *status) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int i, result; */
comment|/* OBSOLETE   int old_timeout = timeout; */
comment|/* OBSOLETE   int old_immediate_quit = immediate_quit; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   status->kind = TARGET_WAITKIND_EXITED; */
comment|/* OBSOLETE   status->value.integer = 0; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* wait for message to arrive. It should be: */
comment|/* OBSOLETE    - A HIF service request. */
comment|/* OBSOLETE    - A HIF exit service request. */
comment|/* OBSOLETE    - A CHANNEL0_ACK. */
comment|/* OBSOLETE    - A CHANNEL1 request. */
comment|/* OBSOLETE    - a debugcore HALT message. */
comment|/* OBSOLETE    HIF services must be responded too, and while-looping continued. */
comment|/* OBSOLETE    If the target stops executing, mm_wait() should return. */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE   timeout = 0;			/* Wait indefinetly for a message */
operator|*
operator|/
comment|/* OBSOLETE   immediate_quit = 1;		/* Helps ability to QUIT */
operator|*
operator|/
comment|/* OBSOLETE   while (1) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       while (msg_recv_serial (in_msg_buf)) */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  QUIT;			/* Let user quit if they want */
operator|*
operator|/
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE       switch (in_msg_buf->halt_msg.code) */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	case HIF_CALL: */
comment|/* OBSOLETE 	  i = in_msg_buf->hif_call_rtn_msg.service_number; */
comment|/* OBSOLETE 	  result = service_HIF (in_msg_buf); */
comment|/* OBSOLETE 	  if (i == 1)		/* EXIT */
operator|*
operator|/
comment|/* OBSOLETE 	    goto exit; */
comment|/* OBSOLETE 	  if (result) */
comment|/* OBSOLETE 	    printf ("Warning: failure during HIF service %d\n", i); */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	case CHANNEL0_ACK: */
comment|/* OBSOLETE 	  service_HIF (in_msg_buf); */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	case CHANNEL1: */
comment|/* OBSOLETE 	  i = in_msg_buf->channel1_msg.length; */
comment|/* OBSOLETE 	  in_msg_buf->channel1_msg.data[i] = '\0'; */
comment|/* OBSOLETE 	  printf ("%s", in_msg_buf->channel1_msg.data); */
comment|/* OBSOLETE 	  gdb_flush (gdb_stdout); */
comment|/* OBSOLETE 	  /* Send CHANNEL1_ACK message */
operator|*
operator|/
comment|/* OBSOLETE 	  out_msg_buf->channel1_ack_msg.code = CHANNEL1_ACK; */
comment|/* OBSOLETE 	  out_msg_buf->channel1_ack_msg.length = 0; */
comment|/* OBSOLETE 	  result = msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	case HALT: */
comment|/* OBSOLETE 	  goto halted; */
comment|/* OBSOLETE 	default: */
comment|/* OBSOLETE 	  goto halted; */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE halted: */
comment|/* OBSOLETE   /* FIXME, these printfs should not be here.  This is a source level  */
comment|/* OBSOLETE      debugger, guys!  */
operator|*
operator|/
comment|/* OBSOLETE   if (in_msg_buf->halt_msg.trap_number == 0) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       printf ("Am290*0 received vector number %d (break point)\n", */
comment|/* OBSOLETE 	      in_msg_buf->halt_msg.trap_number); */
comment|/* OBSOLETE       status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE       status->value.sig = TARGET_SIGNAL_TRAP; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else if (in_msg_buf->halt_msg.trap_number == 1) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       printf ("Am290*0 received vector number %d\n", */
comment|/* OBSOLETE 	      in_msg_buf->halt_msg.trap_number); */
comment|/* OBSOLETE       status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE       status->value.sig = TARGET_SIGNAL_BUS; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else if (in_msg_buf->halt_msg.trap_number == 3 */
comment|/* OBSOLETE 	   || in_msg_buf->halt_msg.trap_number == 4) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       printf ("Am290*0 received vector number %d\n", */
comment|/* OBSOLETE 	      in_msg_buf->halt_msg.trap_number); */
comment|/* OBSOLETE       status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE       status->value.sig = TARGET_SIGNAL_FPE; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else if (in_msg_buf->halt_msg.trap_number == 5) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       printf ("Am290*0 received vector number %d\n", */
comment|/* OBSOLETE 	      in_msg_buf->halt_msg.trap_number); */
comment|/* OBSOLETE       status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE       status->value.sig = TARGET_SIGNAL_ILL; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else if (in_msg_buf->halt_msg.trap_number>= 6 */
comment|/* OBSOLETE&& in_msg_buf->halt_msg.trap_number<= 11) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       printf ("Am290*0 received vector number %d\n", */
comment|/* OBSOLETE 	      in_msg_buf->halt_msg.trap_number); */
comment|/* OBSOLETE       status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE       status->value.sig = TARGET_SIGNAL_SEGV; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else if (in_msg_buf->halt_msg.trap_number == 12 */
comment|/* OBSOLETE 	   || in_msg_buf->halt_msg.trap_number == 13) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       printf ("Am290*0 received vector number %d\n", */
comment|/* OBSOLETE 	      in_msg_buf->halt_msg.trap_number); */
comment|/* OBSOLETE       status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE       status->value.sig = TARGET_SIGNAL_ILL; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else if (in_msg_buf->halt_msg.trap_number == 14) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       printf ("Am290*0 received vector number %d\n", */
comment|/* OBSOLETE 	      in_msg_buf->halt_msg.trap_number); */
comment|/* OBSOLETE       status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE       status->value.sig = TARGET_SIGNAL_ALRM; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else if (in_msg_buf->halt_msg.trap_number == 15) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE       status->value.sig = TARGET_SIGNAL_TRAP; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else if (in_msg_buf->halt_msg.trap_number>= 16 */
comment|/* OBSOLETE&& in_msg_buf->halt_msg.trap_number<= 21) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       printf ("Am290*0 received vector number %d\n", */
comment|/* OBSOLETE 	      in_msg_buf->halt_msg.trap_number); */
comment|/* OBSOLETE       status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE       status->value.sig = TARGET_SIGNAL_INT; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else if (in_msg_buf->halt_msg.trap_number == 22) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       printf ("Am290*0 received vector number %d\n", */
comment|/* OBSOLETE 	      in_msg_buf->halt_msg.trap_number); */
comment|/* OBSOLETE       status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE       status->value.sig = TARGET_SIGNAL_ILL; */
comment|/* OBSOLETE     }				/* BREAK message was sent */
operator|*
operator|/
comment|/* OBSOLETE   else if (in_msg_buf->halt_msg.trap_number == 75) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       status->kind = TARGET_WAITKIND_STOPPED; */
comment|/* OBSOLETE       status->value.sig = TARGET_SIGNAL_TRAP; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE   exit: */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       status->kind = TARGET_WAITKIND_EXITED; */
comment|/* OBSOLETE       status->value.integer = 0; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   timeout = old_timeout;	/* Restore original timeout value */
operator|*
operator|/
comment|/* OBSOLETE   immediate_quit = old_immediate_quit; */
comment|/* OBSOLETE   return inferior_ptid; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /******************************************************* REMOTE_FETCH_REGISTERS */
comment|/* OBSOLETE  * Read a remote register 'regno'.  */
comment|/* OBSOLETE  * If regno==-1 then read all the registers. */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE static void */
comment|/* OBSOLETE mm_fetch_registers (int regno) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   INT32 *data_p; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (regno>= 0) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       fetch_register (regno); */
comment|/* OBSOLETE       return; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Gr1/rsp */
operator|*
operator|/
comment|/* OBSOLETE   out_msg_buf->read_req_msg.byte_count = 4 * 1; */
comment|/* OBSOLETE   out_msg_buf->read_req_msg.memory_space = GLOBAL_REG; */
comment|/* OBSOLETE   out_msg_buf->read_req_msg.address = 1; */
comment|/* OBSOLETE   msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE   expect_msg (READ_ACK, in_msg_buf, 1); */
comment|/* OBSOLETE   data_p =&(in_msg_buf->read_r_ack_msg.data[0]); */
comment|/* OBSOLETE   supply_register (GR1_REGNUM, data_p); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #if defined(GR64_REGNUM)	/* Read gr64-127 */
operator|*
operator|/
comment|/* OBSOLETE /* Global Registers gr64-gr95 */
operator|*
operator|/
comment|/* OBSOLETE   out_msg_buf->read_req_msg.code = READ_REQ; */
comment|/* OBSOLETE   out_msg_buf->read_req_msg.length = 4 * 3; */
comment|/* OBSOLETE   out_msg_buf->read_req_msg.byte_count = 4 * 32; */
comment|/* OBSOLETE   out_msg_buf->read_req_msg.memory_space = GLOBAL_REG; */
comment|/* OBSOLETE   out_msg_buf->read_req_msg.address = 64; */
comment|/* OBSOLETE   msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE   expect_msg (READ_ACK, in_msg_buf, 1); */
comment|/* OBSOLETE   data_p =&(in_msg_buf->read_r_ack_msg.data[0]); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   for (regno = GR64_REGNUM; regno< GR64_REGNUM + 32; regno++) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       supply_register (regno, data_p++); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE #endif /*  GR64_REGNUM */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Global Registers gr96-gr127 */
operator|*
operator|/
comment|/* OBSOLETE   out_msg_buf->read_req_msg.code = READ_REQ; */
comment|/* OBSOLETE   out_msg_buf->read_req_msg.length = 4 * 3; */
comment|/* OBSOLETE   out_msg_buf->read_req_msg.byte_count = 4 * 32; */
comment|/* OBSOLETE   out_msg_buf->read_req_msg.memory_space = GLOBAL_REG; */
comment|/* OBSOLETE   out_msg_buf->read_req_msg.address = 96; */
comment|/* OBSOLETE   msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE   expect_msg (READ_ACK, in_msg_buf, 1); */
comment|/* OBSOLETE   data_p =&(in_msg_buf->read_r_ack_msg.data[0]); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   for (regno = GR96_REGNUM; regno< GR96_REGNUM + 32; regno++) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       supply_register (regno, data_p++); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Local Registers */
operator|*
operator|/
comment|/* OBSOLETE   out_msg_buf->read_req_msg.byte_count = 4 * (128); */
comment|/* OBSOLETE   out_msg_buf->read_req_msg.memory_space = LOCAL_REG; */
comment|/* OBSOLETE   out_msg_buf->read_req_msg.address = 0; */
comment|/* OBSOLETE   msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE   expect_msg (READ_ACK, in_msg_buf, 1); */
comment|/* OBSOLETE   data_p =&(in_msg_buf->read_r_ack_msg.data[0]); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   for (regno = LR0_REGNUM; regno< LR0_REGNUM + 128; regno++) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       supply_register (regno, data_p++); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Protected Special Registers */
operator|*
operator|/
comment|/* OBSOLETE   out_msg_buf->read_req_msg.byte_count = 4 * 15; */
comment|/* OBSOLETE   out_msg_buf->read_req_msg.memory_space = SPECIAL_REG; */
comment|/* OBSOLETE   out_msg_buf->read_req_msg.address = 0; */
comment|/* OBSOLETE   msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE   expect_msg (READ_ACK, in_msg_buf, 1); */
comment|/* OBSOLETE   data_p =&(in_msg_buf->read_r_ack_msg.data[0]); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   for (regno = 0; regno<= 14; regno++) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       supply_register (SR_REGNUM (regno), data_p++); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   if (USE_SHADOW_PC) */
comment|/* OBSOLETE     {				/* Let regno_to_srnum() handle the register number */
operator|*
operator|/
comment|/* OBSOLETE       fetch_register (NPC_REGNUM); */
comment|/* OBSOLETE       fetch_register (PC_REGNUM); */
comment|/* OBSOLETE       fetch_register (PC2_REGNUM); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Unprotected Special Registers */
operator|*
operator|/
comment|/* OBSOLETE   out_msg_buf->read_req_msg.byte_count = 4 * 8; */
comment|/* OBSOLETE   out_msg_buf->read_req_msg.memory_space = SPECIAL_REG; */
comment|/* OBSOLETE   out_msg_buf->read_req_msg.address = 128; */
comment|/* OBSOLETE   msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE   expect_msg (READ_ACK, in_msg_buf, 1); */
comment|/* OBSOLETE   data_p =&(in_msg_buf->read_r_ack_msg.data[0]); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   for (regno = 128; regno<= 135; regno++) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       supply_register (SR_REGNUM (regno), data_p++); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* There doesn't seem to be any way to get these.  */
operator|*
operator|/
comment|/* OBSOLETE   { */
comment|/* OBSOLETE     int val = -1; */
comment|/* OBSOLETE     supply_register (FPE_REGNUM,&val); */
comment|/* OBSOLETE     supply_register (INTE_REGNUM,&val); */
comment|/* OBSOLETE     supply_register (FPS_REGNUM,&val); */
comment|/* OBSOLETE     supply_register (EXO_REGNUM,&val); */
comment|/* OBSOLETE   } */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /****************************************************** REMOTE_STORE_REGISTERS */
comment|/* OBSOLETE  * Store register regno into the target.   */
comment|/* OBSOLETE  * If regno==-1 then store all the registers. */
comment|/* OBSOLETE  * Result is 0 for success, -1 for failure. */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE mm_store_registers (int regno) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int result; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (regno>= 0) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       store_register (regno); */
comment|/* OBSOLETE       return; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   result = 0; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   out_msg_buf->write_r_msg.code = WRITE_REQ; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Gr1/rsp */
operator|*
operator|/
comment|/* OBSOLETE   out_msg_buf->write_r_msg.byte_count = 4 * 1; */
comment|/* OBSOLETE   out_msg_buf->write_r_msg.length = 3 * 4 + out_msg_buf->write_r_msg.byte_count; */
comment|/* OBSOLETE   out_msg_buf->write_r_msg.memory_space = GLOBAL_REG; */
comment|/* OBSOLETE   out_msg_buf->write_r_msg.address = 1; */
comment|/* OBSOLETE   out_msg_buf->write_r_msg.data[0] = read_register (GR1_REGNUM); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE   if (!expect_msg (WRITE_ACK, in_msg_buf, 1)) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       result = -1; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #if defined(GR64_REGNUM) */
comment|/* OBSOLETE /* Global registers gr64-gr95 */
operator|*
operator|/
comment|/* OBSOLETE   out_msg_buf->write_r_msg.byte_count = 4 * (32); */
comment|/* OBSOLETE   out_msg_buf->write_r_msg.length = 3 * 4 + out_msg_buf->write_r_msg.byte_count; */
comment|/* OBSOLETE   out_msg_buf->write_r_msg.address = 64; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   for (regno = GR64_REGNUM; regno< GR64_REGNUM + 32; regno++) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       out_msg_buf->write_r_msg.data[regno - GR64_REGNUM] = read_register (regno); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE   if (!expect_msg (WRITE_ACK, in_msg_buf, 1)) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       result = -1; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE #endif /* GR64_REGNUM */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Global registers gr96-gr127 */
operator|*
operator|/
comment|/* OBSOLETE   out_msg_buf->write_r_msg.byte_count = 4 * (32); */
comment|/* OBSOLETE   out_msg_buf->write_r_msg.length = 3 * 4 + out_msg_buf->write_r_msg.byte_count; */
comment|/* OBSOLETE   out_msg_buf->write_r_msg.address = 96; */
comment|/* OBSOLETE   for (regno = GR96_REGNUM; regno< GR96_REGNUM + 32; regno++) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       out_msg_buf->write_r_msg.data[regno - GR96_REGNUM] = read_register (regno); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE   if (!expect_msg (WRITE_ACK, in_msg_buf, 1)) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       result = -1; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Local Registers */
operator|*
operator|/
comment|/* OBSOLETE   out_msg_buf->write_r_msg.memory_space = LOCAL_REG; */
comment|/* OBSOLETE   out_msg_buf->write_r_msg.byte_count = 4 * 128; */
comment|/* OBSOLETE   out_msg_buf->write_r_msg.length = 3 * 4 + out_msg_buf->write_r_msg.byte_count; */
comment|/* OBSOLETE   out_msg_buf->write_r_msg.address = 0; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   for (regno = LR0_REGNUM; regno< LR0_REGNUM + 128; regno++) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       out_msg_buf->write_r_msg.data[regno - LR0_REGNUM] = read_register (regno); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE   if (!expect_msg (WRITE_ACK, in_msg_buf, 1)) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       result = -1; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Protected Special Registers */
operator|*
operator|/
comment|/* OBSOLETE   /* VAB through TMR */
operator|*
operator|/
comment|/* OBSOLETE   out_msg_buf->write_r_msg.memory_space = SPECIAL_REG; */
comment|/* OBSOLETE   out_msg_buf->write_r_msg.byte_count = 4 * 10; */
comment|/* OBSOLETE   out_msg_buf->write_r_msg.length = 3 * 4 + out_msg_buf->write_r_msg.byte_count; */
comment|/* OBSOLETE   out_msg_buf->write_r_msg.address = 0; */
comment|/* OBSOLETE   for (regno = 0; regno<= 9; regno++)	/* VAB through TMR */
operator|*
operator|/
comment|/* OBSOLETE     out_msg_buf->write_r_msg.data[regno] = read_register (SR_REGNUM (regno)); */
comment|/* OBSOLETE   msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE   if (!expect_msg (WRITE_ACK, in_msg_buf, 1)) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       result = -1; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* PC0, PC1, PC2 possibly as shadow registers */
operator|*
operator|/
comment|/* OBSOLETE   out_msg_buf->write_r_msg.byte_count = 4 * 3; */
comment|/* OBSOLETE   out_msg_buf->write_r_msg.length = 3 * 4 + out_msg_buf->write_r_msg.byte_count; */
comment|/* OBSOLETE   for (regno = 10; regno<= 12; regno++)	/* LRU and MMU */
operator|*
operator|/
comment|/* OBSOLETE     out_msg_buf->write_r_msg.data[regno - 10] = read_register (SR_REGNUM (regno)); */
comment|/* OBSOLETE   if (USE_SHADOW_PC) */
comment|/* OBSOLETE     out_msg_buf->write_r_msg.address = 20;	/* SPC0 */
operator|*
operator|/
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     out_msg_buf->write_r_msg.address = 10;	/* PC0 */
operator|*
operator|/
comment|/* OBSOLETE   msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE   if (!expect_msg (WRITE_ACK, in_msg_buf, 1)) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       result = -1; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* LRU and MMU */
operator|*
operator|/
comment|/* OBSOLETE   out_msg_buf->write_r_msg.byte_count = 4 * 2; */
comment|/* OBSOLETE   out_msg_buf->write_r_msg.length = 3 * 4 + out_msg_buf->write_r_msg.byte_count; */
comment|/* OBSOLETE   out_msg_buf->write_r_msg.address = 13; */
comment|/* OBSOLETE   for (regno = 13; regno<= 14; regno++)	/* LRU and MMU */
operator|*
operator|/
comment|/* OBSOLETE     out_msg_buf->write_r_msg.data[regno - 13] = read_register (SR_REGNUM (regno)); */
comment|/* OBSOLETE   msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE   if (!expect_msg (WRITE_ACK, in_msg_buf, 1)) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       result = -1; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Unprotected Special Registers */
operator|*
operator|/
comment|/* OBSOLETE   out_msg_buf->write_r_msg.byte_count = 4 * 8; */
comment|/* OBSOLETE   out_msg_buf->write_r_msg.length = 3 * 4 + out_msg_buf->write_r_msg.byte_count; */
comment|/* OBSOLETE   out_msg_buf->write_r_msg.address = 128; */
comment|/* OBSOLETE   for (regno = 128; regno<= 135; regno++) */
comment|/* OBSOLETE     out_msg_buf->write_r_msg.data[regno - 128] = read_register (SR_REGNUM (regno)); */
comment|/* OBSOLETE   msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE   if (!expect_msg (WRITE_ACK, in_msg_buf, 1)) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       result = -1; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   registers_changed (); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /*************************************************** REMOTE_PREPARE_TO_STORE */
operator|*
operator|/
comment|/* OBSOLETE /* Get ready to modify the registers array.  On machines which store */
comment|/* OBSOLETE    individual registers, this doesn't need to do anything.  On machines */
comment|/* OBSOLETE    which store all the registers in one fell swoop, this makes sure */
comment|/* OBSOLETE    that registers contains all the registers from the program being */
comment|/* OBSOLETE    debugged.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE mm_prepare_to_store (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   /* Do nothing, since we can store individual regs */
operator|*
operator|/
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /******************************************************* REMOTE_XFER_MEMORY */
operator|*
operator|/
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
comment|/* OBSOLETE   /* FIXME: doesn't work for user virtual addresses */
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
comment|/* OBSOLETE /******************************************************* REMOTE_FILES_INFO */
operator|*
operator|/
comment|/* OBSOLETE static void */
comment|/* OBSOLETE mm_files_info (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   printf ("\tAttached to %s at %d baud and running program %s.\n", */
comment|/* OBSOLETE 	  dev_name, baudrate, prog_name); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /************************************************* REMOTE_INSERT_BREAKPOINT */
operator|*
operator|/
comment|/* OBSOLETE static int */
comment|/* OBSOLETE mm_insert_breakpoint (CORE_ADDR addr, char *contents_cache) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   out_msg_buf->bkpt_set_msg.code = BKPT_SET; */
comment|/* OBSOLETE   out_msg_buf->bkpt_set_msg.length = 4 * 4; */
comment|/* OBSOLETE   out_msg_buf->bkpt_set_msg.memory_space = I_MEM; */
comment|/* OBSOLETE   out_msg_buf->bkpt_set_msg.bkpt_addr = (ADDR32) addr; */
comment|/* OBSOLETE   out_msg_buf->bkpt_set_msg.pass_count = 1; */
comment|/* OBSOLETE   out_msg_buf->bkpt_set_msg.bkpt_type = -1;	/* use illop for 29000 */
operator|*
operator|/
comment|/* OBSOLETE   msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE   if (expect_msg (BKPT_SET_ACK, in_msg_buf, 1)) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       return 0;			/* Success */
operator|*
operator|/
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       return 1;			/* Failure */
operator|*
operator|/
comment|/* OBSOLETE     } */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /************************************************* REMOTE_DELETE_BREAKPOINT */
operator|*
operator|/
comment|/* OBSOLETE static int */
comment|/* OBSOLETE mm_remove_breakpoint (CORE_ADDR addr, char *contents_cache) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   out_msg_buf->bkpt_rm_msg.code = BKPT_RM; */
comment|/* OBSOLETE   out_msg_buf->bkpt_rm_msg.length = 4 * 3; */
comment|/* OBSOLETE   out_msg_buf->bkpt_rm_msg.memory_space = I_MEM; */
comment|/* OBSOLETE   out_msg_buf->bkpt_rm_msg.bkpt_addr = (ADDR32) addr; */
comment|/* OBSOLETE   msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE   if (expect_msg (BKPT_RM_ACK, in_msg_buf, 1)) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       return 0;			/* Success */
operator|*
operator|/
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       return 1;			/* Failure */
operator|*
operator|/
comment|/* OBSOLETE     } */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /******************************************************* REMOTE_KILL */
operator|*
operator|/
comment|/* OBSOLETE static void */
comment|/* OBSOLETE mm_kill (char *arg, int from_tty) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   char buf[4]; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #if defined(KERNEL_DEBUGGING) */
comment|/* OBSOLETE   /* We don't ever kill the kernel */
operator|*
operator|/
comment|/* OBSOLETE   if (from_tty) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       printf ("Kernel not killed, but left in current state.\n"); */
comment|/* OBSOLETE       printf ("Use detach to leave kernel running.\n"); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE #else */
comment|/* OBSOLETE   out_msg_buf->break_msg.code = BREAK; */
comment|/* OBSOLETE   out_msg_buf->bkpt_set_msg.length = 4 * 0; */
comment|/* OBSOLETE   expect_msg (HALT, in_msg_buf, from_tty); */
comment|/* OBSOLETE   if (from_tty) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       printf ("Target has been stopped."); */
comment|/* OBSOLETE       printf ("Would you like to do a hardware reset (y/n) [n] "); */
comment|/* OBSOLETE       fgets (buf, 3, stdin); */
comment|/* OBSOLETE       if (buf[0] == 'y') */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  out_msg_buf->reset_msg.code = RESET; */
comment|/* OBSOLETE 	  out_msg_buf->bkpt_set_msg.length = 4 * 0; */
comment|/* OBSOLETE 	  expect_msg (RESET_ACK, in_msg_buf, from_tty); */
comment|/* OBSOLETE 	  printf ("Target has been reset."); */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   pop_target (); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE  */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /***************************************************************************/
operator|*
operator|/
comment|/* OBSOLETE /*  */
comment|/* OBSOLETE  * Load a program into the target. */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE static void */
comment|/* OBSOLETE mm_load (char *arg_string, int from_tty) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   dont_repeat (); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #if defined(KERNEL_DEBUGGING) */
comment|/* OBSOLETE   printf ("The kernel had better be loaded already!  Loading not done.\n"); */
comment|/* OBSOLETE #else */
comment|/* OBSOLETE   if (arg_string == 0) */
comment|/* OBSOLETE     error ("The load command takes a file name"); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   arg_string = tilde_expand (arg_string); */
comment|/* OBSOLETE   make_cleanup (xfree, arg_string); */
comment|/* OBSOLETE   QUIT; */
comment|/* OBSOLETE   immediate_quit++; */
comment|/* OBSOLETE   error ("File loading is not yet supported for MiniMon."); */
comment|/* OBSOLETE   /* FIXME, code to load your file here... */
operator|*
operator|/
comment|/* OBSOLETE   /* You may need to do an init_target_mm() */
operator|*
operator|/
comment|/* OBSOLETE   /* init_target_mm(?,?,?,?,?,?,?,?); */
operator|*
operator|/
comment|/* OBSOLETE   immediate_quit--; */
comment|/* OBSOLETE   /* symbol_file_add (arg_string, from_tty, text_addr, 0, 0); */
operator|*
operator|/
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE  */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /************************************************ REMOTE_WRITE_INFERIOR_MEMORY */
comment|/* OBSOLETE ** Copy LEN bytes of data from debugger memory at MYADDR */
comment|/* OBSOLETE    to inferior's memory at MEMADDR.  Returns number of bytes written.  */
operator|*
operator|/
comment|/* OBSOLETE static int */
comment|/* OBSOLETE mm_write_inferior_memory (CORE_ADDR memaddr, char *myaddr, int len) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int i, nwritten; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   out_msg_buf->write_req_msg.code = WRITE_REQ; */
comment|/* OBSOLETE   out_msg_buf->write_req_msg.memory_space = mm_memory_space (memaddr); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   nwritten = 0; */
comment|/* OBSOLETE   while (nwritten< len) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       int num_to_write = len - nwritten; */
comment|/* OBSOLETE       if (num_to_write> MAXDATA) */
comment|/* OBSOLETE 	num_to_write = MAXDATA; */
comment|/* OBSOLETE       for (i = 0; i< num_to_write; i++) */
comment|/* OBSOLETE 	out_msg_buf->write_req_msg.data[i] = myaddr[i + nwritten]; */
comment|/* OBSOLETE       out_msg_buf->write_req_msg.byte_count = num_to_write; */
comment|/* OBSOLETE       out_msg_buf->write_req_msg.length = 3 * 4 + num_to_write; */
comment|/* OBSOLETE       out_msg_buf->write_req_msg.address = memaddr + nwritten; */
comment|/* OBSOLETE       msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE       if (expect_msg (WRITE_ACK, in_msg_buf, 1)) */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  nwritten += in_msg_buf->write_ack_msg.byte_count; */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE       else */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   return (nwritten); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /************************************************* REMOTE_READ_INFERIOR_MEMORY */
comment|/* OBSOLETE ** Read LEN bytes from inferior memory at MEMADDR.  Put the result */
comment|/* OBSOLETE    at debugger address MYADDR.  Returns number of bytes read.  */
operator|*
operator|/
comment|/* OBSOLETE static int */
comment|/* OBSOLETE mm_read_inferior_memory (CORE_ADDR memaddr, char *myaddr, int len) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int i, nread; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   out_msg_buf->read_req_msg.code = READ_REQ; */
comment|/* OBSOLETE   out_msg_buf->read_req_msg.memory_space = mm_memory_space (memaddr); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   nread = 0; */
comment|/* OBSOLETE   while (nread< len) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       int num_to_read = (len - nread); */
comment|/* OBSOLETE       if (num_to_read> MAXDATA) */
comment|/* OBSOLETE 	num_to_read = MAXDATA; */
comment|/* OBSOLETE       out_msg_buf->read_req_msg.byte_count = num_to_read; */
comment|/* OBSOLETE       out_msg_buf->read_req_msg.length = 3 * 4 + num_to_read; */
comment|/* OBSOLETE       out_msg_buf->read_req_msg.address = memaddr + nread; */
comment|/* OBSOLETE       msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE       if (expect_msg (READ_ACK, in_msg_buf, 1)) */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  for (i = 0; i< in_msg_buf->read_ack_msg.byte_count; i++) */
comment|/* OBSOLETE 	    myaddr[i + nread] = in_msg_buf->read_ack_msg.data[i]; */
comment|/* OBSOLETE 	  nread += in_msg_buf->read_ack_msg.byte_count; */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE       else */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  break; */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   return (nread); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* FIXME!  Merge these two.  */
operator|*
operator|/
comment|/* OBSOLETE static int */
comment|/* OBSOLETE mm_xfer_inferior_memory (CORE_ADDR memaddr, char *myaddr, int len, int write, */
comment|/* OBSOLETE 			 struct mem_attrib *attrib ATTRIBUTE_UNUSED, */
comment|/* OBSOLETE 			 struct target_ops *target ATTRIBUTE_UNUSED) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   memaddr = translate_addr (memaddr); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (write) */
comment|/* OBSOLETE     return mm_write_inferior_memory (memaddr, myaddr, len); */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     return mm_read_inferior_memory (memaddr, myaddr, len); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /********************************************************** MSG_SEND_SERIAL */
comment|/* OBSOLETE ** This function is used to send a message over the */
comment|/* OBSOLETE ** serial line. */
comment|/* OBSOLETE ** */
comment|/* OBSOLETE ** If the message is successfully sent, a zero is */
comment|/* OBSOLETE ** returned.  If the message was not sendable, a -1 */
comment|/* OBSOLETE ** is returned.  This function blocks.  That is, it */
comment|/* OBSOLETE ** does not return until the message is completely */
comment|/* OBSOLETE ** sent, or until an error is encountered. */
comment|/* OBSOLETE ** */
comment|/* OBSOLETE */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE int */
comment|/* OBSOLETE msg_send_serial (union msg_t *msg_ptr) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   INT32 message_size; */
comment|/* OBSOLETE   int byte_count; */
comment|/* OBSOLETE   int result; */
comment|/* OBSOLETE   char c; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Send message header */
operator|*
operator|/
comment|/* OBSOLETE   byte_count = 0; */
comment|/* OBSOLETE   message_size = msg_ptr->generic_msg.length + (2 * sizeof (INT32)); */
comment|/* OBSOLETE   do */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       c = *((char *) msg_ptr + byte_count); */
comment|/* OBSOLETE       result = write (mm_desc,&c, 1); */
comment|/* OBSOLETE       if (result == 1) */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  byte_count = byte_count + 1; */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   while ((byte_count< message_size)); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   return (0); */
comment|/* OBSOLETE }				/* end msg_send_serial() */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE /********************************************************** MSG_RECV_SERIAL */
comment|/* OBSOLETE ** This function is used to receive a message over a */
comment|/* OBSOLETE ** serial line. */
comment|/* OBSOLETE ** */
comment|/* OBSOLETE ** If the message is waiting in the buffer, a zero is */
comment|/* OBSOLETE ** returned and the buffer pointed to by msg_ptr is filled */
comment|/* OBSOLETE ** in.  If no message was available, a -1 is returned. */
comment|/* OBSOLETE ** If timeout==0, wait indefinetly for a character. */
comment|/* OBSOLETE ** */
comment|/* OBSOLETE */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE int */
comment|/* OBSOLETE msg_recv_serial (union msg_t *msg_ptr) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   static INT32 length = 0; */
comment|/* OBSOLETE   static INT32 byte_count = 0; */
comment|/* OBSOLETE   int result; */
comment|/* OBSOLETE   char c; */
comment|/* OBSOLETE   if (msg_ptr == 0)		/* re-sync request */
operator|*
operator|/
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       length = 0; */
comment|/* OBSOLETE       byte_count = 0; */
comment|/* OBSOLETE #ifdef HAVE_TERMIO */
comment|/* OBSOLETE       /* The timeout here is the prevailing timeout set with VTIME */
operator|*
operator|/
comment|/* OBSOLETE       ->"timeout==0 semantics not supported" */
comment|/* OBSOLETE 	read (mm_desc, in_buf, BUFER_SIZE); */
comment|/* OBSOLETE #else */
comment|/* OBSOLETE       alarm (1); */
comment|/* OBSOLETE       read (mm_desc, in_buf, BUFER_SIZE); */
comment|/* OBSOLETE       alarm (0); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE       return (0); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   /* Receive message */
operator|*
operator|/
comment|/* OBSOLETE #ifdef HAVE_TERMIO */
comment|/* OBSOLETE /* Timeout==0, help support the mm_wait() routine */
operator|*
operator|/
comment|/* OBSOLETE   ->"timeout==0 semantics not supported (and its nice if they are)" */
comment|/* OBSOLETE     result = read (mm_desc,&c, 1); */
comment|/* OBSOLETE #else */
comment|/* OBSOLETE   alarm (timeout); */
comment|/* OBSOLETE   result = read (mm_desc,&c, 1); */
comment|/* OBSOLETE   alarm (0); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE   if (result< 0) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       if (errno == EINTR) */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  error ("Timeout reading from remote system."); */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE       else */
comment|/* OBSOLETE 	perror_with_name ("remote"); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else if (result == 1) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       *((char *) msg_ptr + byte_count) = c; */
comment|/* OBSOLETE       byte_count = byte_count + 1; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Message header received.  Save message length. */
operator|*
operator|/
comment|/* OBSOLETE   if (byte_count == (2 * sizeof (INT32))) */
comment|/* OBSOLETE     length = msg_ptr->generic_msg.length; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (byte_count>= (length + (2 * sizeof (INT32)))) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       /* Message received */
operator|*
operator|/
comment|/* OBSOLETE       byte_count = 0; */
comment|/* OBSOLETE       return (0); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     return (-1); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE }				/* end msg_recv_serial() */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE /********************************************************************* KBD_RAW */
comment|/* OBSOLETE ** This function is used to put the keyboard in "raw" */
comment|/* OBSOLETE ** mode for BSD Unix.  The original status is saved */
comment|/* OBSOLETE ** so that it may be restored later. */
comment|/* OBSOLETE */
operator|*
operator|/
comment|/* OBSOLETE TERMINAL kbd_tbuf; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE int */
comment|/* OBSOLETE kbd_raw (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int result; */
comment|/* OBSOLETE   TERMINAL tbuf; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Get keyboard termio (to save to restore original modes) */
operator|*
operator|/
comment|/* OBSOLETE #ifdef HAVE_TERMIO */
comment|/* OBSOLETE   result = ioctl (0, TCGETA,&kbd_tbuf); */
comment|/* OBSOLETE #else */
comment|/* OBSOLETE   result = ioctl (0, TIOCGETP,&kbd_tbuf); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE   if (result == -1) */
comment|/* OBSOLETE     return (errno); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Get keyboard TERMINAL (for modification) */
operator|*
operator|/
comment|/* OBSOLETE #ifdef HAVE_TERMIO */
comment|/* OBSOLETE   result = ioctl (0, TCGETA,&tbuf); */
comment|/* OBSOLETE #else */
comment|/* OBSOLETE   result = ioctl (0, TIOCGETP,&tbuf); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE   if (result == -1) */
comment|/* OBSOLETE     return (errno); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Set up new parameters */
operator|*
operator|/
comment|/* OBSOLETE #ifdef HAVE_TERMIO */
comment|/* OBSOLETE   tbuf.c_iflag = tbuf.c_iflag& */
comment|/* OBSOLETE     ~(INLCR | ICRNL | IUCLC | ISTRIP | IXON | BRKINT); */
comment|/* OBSOLETE   tbuf.c_lflag = tbuf.c_lflag& ~(ICANON | ISIG | ECHO); */
comment|/* OBSOLETE   tbuf.c_cc[4] = 0;		/* MIN */
operator|*
operator|/
comment|/* OBSOLETE   tbuf.c_cc[5] = 0;		/* TIME */
operator|*
operator|/
comment|/* OBSOLETE #else */
comment|/* OBSOLETE   /* FIXME: not sure if this is correct (matches HAVE_TERMIO). */
operator|*
operator|/
comment|/* OBSOLETE   tbuf.sg_flags |= RAW; */
comment|/* OBSOLETE   tbuf.sg_flags |= ANYP; */
comment|/* OBSOLETE   tbuf.sg_flags&= ~ECHO; */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Set keyboard termio to new mode (RAW) */
operator|*
operator|/
comment|/* OBSOLETE #ifdef HAVE_TERMIO */
comment|/* OBSOLETE   result = ioctl (0, TCSETAF,&tbuf); */
comment|/* OBSOLETE #else */
comment|/* OBSOLETE   result = ioctl (0, TIOCSETP,&tbuf); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE   if (result == -1) */
comment|/* OBSOLETE     return (errno); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   return (0); */
comment|/* OBSOLETE }				/* end kbd_raw() */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE  */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /***************************************************************** KBD_RESTORE */
comment|/* OBSOLETE ** This function is used to put the keyboard back in the */
comment|/* OBSOLETE ** mode it was in before kbk_raw was called.  Note that */
comment|/* OBSOLETE ** kbk_raw() must have been called at least once before */
comment|/* OBSOLETE ** kbd_restore() is called. */
comment|/* OBSOLETE */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE int */
comment|/* OBSOLETE kbd_restore (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int result; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   /* Set keyboard termio to original mode */
operator|*
operator|/
comment|/* OBSOLETE #ifdef HAVE_TERMIO */
comment|/* OBSOLETE   result = ioctl (0, TCSETAF,&kbd_tbuf); */
comment|/* OBSOLETE #else */
comment|/* OBSOLETE   result = ioctl (0, TIOCGETP,&kbd_tbuf); */
comment|/* OBSOLETE #endif */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (result == -1) */
comment|/* OBSOLETE     return (errno); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   return (0); */
comment|/* OBSOLETE }				/* end kbd_cooked() */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /*****************************************************************************/
operator|*
operator|/
comment|/* OBSOLETE /* Fetch a single register indicatated by 'regno'.  */
comment|/* OBSOLETE  * Returns 0/-1 on success/failure.   */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE static int */
comment|/* OBSOLETE fetch_register (int regno) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int result; */
comment|/* OBSOLETE   out_msg_buf->read_req_msg.code = READ_REQ; */
comment|/* OBSOLETE   out_msg_buf->read_req_msg.length = 4 * 3; */
comment|/* OBSOLETE   out_msg_buf->read_req_msg.byte_count = 4; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (regno == GR1_REGNUM) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       out_msg_buf->read_req_msg.memory_space = GLOBAL_REG; */
comment|/* OBSOLETE       out_msg_buf->read_req_msg.address = 1; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else if (regno>= GR96_REGNUM&& regno< GR96_REGNUM + 32) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       out_msg_buf->read_req_msg.memory_space = GLOBAL_REG; */
comment|/* OBSOLETE       out_msg_buf->read_req_msg.address = (regno - GR96_REGNUM) + 96; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE #if defined(GR64_REGNUM) */
comment|/* OBSOLETE   else if (regno>= GR64_REGNUM&& regno< GR64_REGNUM + 32) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       out_msg_buf->read_req_msg.memory_space = GLOBAL_REG; */
comment|/* OBSOLETE       out_msg_buf->read_req_msg.address = (regno - GR64_REGNUM) + 64; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE #endif /* GR64_REGNUM */
operator|*
operator|/
comment|/* OBSOLETE   else if (regno>= LR0_REGNUM&& regno< LR0_REGNUM + 128) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       out_msg_buf->read_req_msg.memory_space = LOCAL_REG; */
comment|/* OBSOLETE       out_msg_buf->read_req_msg.address = (regno - LR0_REGNUM); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else if (regno>= FPE_REGNUM&& regno<= EXO_REGNUM) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       int val = -1; */
comment|/* OBSOLETE       supply_register (160 + (regno - FPE_REGNUM),&val); */
comment|/* OBSOLETE       return 0;			/* Pretend Success */
operator|*
operator|/
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       out_msg_buf->read_req_msg.memory_space = SPECIAL_REG; */
comment|/* OBSOLETE       out_msg_buf->read_req_msg.address = regnum_to_srnum (regno); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (expect_msg (READ_ACK, in_msg_buf, 1)) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       supply_register (regno,&(in_msg_buf->read_r_ack_msg.data[0])); */
comment|/* OBSOLETE       result = 0; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       result = -1; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   return result; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE /*****************************************************************************/
operator|*
operator|/
comment|/* OBSOLETE /* Store a single register indicated by 'regno'.  */
comment|/* OBSOLETE  * Returns 0/-1 on success/failure.   */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE static int */
comment|/* OBSOLETE store_register (int regno) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int result; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   out_msg_buf->write_req_msg.code = WRITE_REQ; */
comment|/* OBSOLETE   out_msg_buf->write_req_msg.length = 4 * 4; */
comment|/* OBSOLETE   out_msg_buf->write_req_msg.byte_count = 4; */
comment|/* OBSOLETE   out_msg_buf->write_r_msg.data[0] = read_register (regno); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (regno == GR1_REGNUM) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       out_msg_buf->write_req_msg.memory_space = GLOBAL_REG; */
comment|/* OBSOLETE       out_msg_buf->write_req_msg.address = 1; */
comment|/* OBSOLETE       /* Setting GR1 changes the numbers of all the locals, so invalidate the  */
comment|/* OBSOLETE        * register cache.  Do this *after* calling read_register, because we want  */
comment|/* OBSOLETE        * read_register to return the value that write_register has just stuffed  */
comment|/* OBSOLETE        * into the registers array, not the value of the register fetched from  */
comment|/* OBSOLETE        * the inferior.   */
comment|/* OBSOLETE        */
operator|*
operator|/
comment|/* OBSOLETE       registers_changed (); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE #if defined(GR64_REGNUM) */
comment|/* OBSOLETE   else if (regno>= GR64_REGNUM&& regno< GR64_REGNUM + 32) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       out_msg_buf->write_req_msg.memory_space = GLOBAL_REG; */
comment|/* OBSOLETE       out_msg_buf->write_req_msg.address = (regno - GR64_REGNUM) + 64; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE #endif /* GR64_REGNUM */
operator|*
operator|/
comment|/* OBSOLETE   else if (regno>= GR96_REGNUM&& regno< GR96_REGNUM + 32) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       out_msg_buf->write_req_msg.memory_space = GLOBAL_REG; */
comment|/* OBSOLETE       out_msg_buf->write_req_msg.address = (regno - GR96_REGNUM) + 96; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else if (regno>= LR0_REGNUM&& regno< LR0_REGNUM + 128) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       out_msg_buf->write_req_msg.memory_space = LOCAL_REG; */
comment|/* OBSOLETE       out_msg_buf->write_req_msg.address = (regno - LR0_REGNUM); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else if (regno>= FPE_REGNUM&& regno<= EXO_REGNUM) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       return 0;			/* Pretend Success */
operator|*
operator|/
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     /* An unprotected or protected special register */
operator|*
operator|/
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       out_msg_buf->write_req_msg.memory_space = SPECIAL_REG; */
comment|/* OBSOLETE       out_msg_buf->write_req_msg.address = regnum_to_srnum (regno); */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (expect_msg (WRITE_ACK, in_msg_buf, 1)) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       result = 0; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       result = -1; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   return result; */
comment|/* OBSOLETE } */
comment|/* OBSOLETE /****************************************************************************/
operator|*
operator|/
comment|/* OBSOLETE /*  */
comment|/* OBSOLETE  * Convert a gdb special register number to a 29000 special register number. */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE static int */
comment|/* OBSOLETE regnum_to_srnum (int regno) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   switch (regno) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE     case VAB_REGNUM: */
comment|/* OBSOLETE       return (0); */
comment|/* OBSOLETE     case OPS_REGNUM: */
comment|/* OBSOLETE       return (1); */
comment|/* OBSOLETE     case CPS_REGNUM: */
comment|/* OBSOLETE       return (2); */
comment|/* OBSOLETE     case CFG_REGNUM: */
comment|/* OBSOLETE       return (3); */
comment|/* OBSOLETE     case CHA_REGNUM: */
comment|/* OBSOLETE       return (4); */
comment|/* OBSOLETE     case CHD_REGNUM: */
comment|/* OBSOLETE       return (5); */
comment|/* OBSOLETE     case CHC_REGNUM: */
comment|/* OBSOLETE       return (6); */
comment|/* OBSOLETE     case RBP_REGNUM: */
comment|/* OBSOLETE       return (7); */
comment|/* OBSOLETE     case TMC_REGNUM: */
comment|/* OBSOLETE       return (8); */
comment|/* OBSOLETE     case TMR_REGNUM: */
comment|/* OBSOLETE       return (9); */
comment|/* OBSOLETE     case NPC_REGNUM: */
comment|/* OBSOLETE       return (USE_SHADOW_PC ? (20) : (10)); */
comment|/* OBSOLETE     case PC_REGNUM: */
comment|/* OBSOLETE       return (USE_SHADOW_PC ? (21) : (11)); */
comment|/* OBSOLETE     case PC2_REGNUM: */
comment|/* OBSOLETE       return (USE_SHADOW_PC ? (22) : (12)); */
comment|/* OBSOLETE     case MMU_REGNUM: */
comment|/* OBSOLETE       return (13); */
comment|/* OBSOLETE     case LRU_REGNUM: */
comment|/* OBSOLETE       return (14); */
comment|/* OBSOLETE     case IPC_REGNUM: */
comment|/* OBSOLETE       return (128); */
comment|/* OBSOLETE     case IPA_REGNUM: */
comment|/* OBSOLETE       return (129); */
comment|/* OBSOLETE     case IPB_REGNUM: */
comment|/* OBSOLETE       return (130); */
comment|/* OBSOLETE     case Q_REGNUM: */
comment|/* OBSOLETE       return (131); */
comment|/* OBSOLETE     case ALU_REGNUM: */
comment|/* OBSOLETE       return (132); */
comment|/* OBSOLETE     case BP_REGNUM: */
comment|/* OBSOLETE       return (133); */
comment|/* OBSOLETE     case FC_REGNUM: */
comment|/* OBSOLETE       return (134); */
comment|/* OBSOLETE     case CR_REGNUM: */
comment|/* OBSOLETE       return (135); */
comment|/* OBSOLETE     case FPE_REGNUM: */
comment|/* OBSOLETE       return (160); */
comment|/* OBSOLETE     case INTE_REGNUM: */
comment|/* OBSOLETE       return (161); */
comment|/* OBSOLETE     case FPS_REGNUM: */
comment|/* OBSOLETE       return (162); */
comment|/* OBSOLETE     case EXO_REGNUM: */
comment|/* OBSOLETE       return (164); */
comment|/* OBSOLETE     default: */
comment|/* OBSOLETE       return (255);		/* Failure ? */
operator|*
operator|/
comment|/* OBSOLETE     } */
comment|/* OBSOLETE } */
comment|/* OBSOLETE /****************************************************************************/
operator|*
operator|/
comment|/* OBSOLETE /*  */
comment|/* OBSOLETE  * Initialize the target debugger (minimon only). */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE static void */
comment|/* OBSOLETE init_target_mm (ADDR32 tstart, ADDR32 tend, ADDR32 dstart, ADDR32 dend, */
comment|/* OBSOLETE 		ADDR32 entry, INT32 ms_size, INT32 rs_size, ADDR32 arg_start) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   out_msg_buf->init_msg.code = INIT; */
comment|/* OBSOLETE   out_msg_buf->init_msg.length = sizeof (struct init_msg_t) - 2 * sizeof (INT32); */
comment|/* OBSOLETE   out_msg_buf->init_msg.text_start = tstart; */
comment|/* OBSOLETE   out_msg_buf->init_msg.text_end = tend; */
comment|/* OBSOLETE   out_msg_buf->init_msg.data_start = dstart; */
comment|/* OBSOLETE   out_msg_buf->init_msg.data_end = dend; */
comment|/* OBSOLETE   out_msg_buf->init_msg.entry_point = entry; */
comment|/* OBSOLETE   out_msg_buf->init_msg.mem_stack_size = ms_size; */
comment|/* OBSOLETE   out_msg_buf->init_msg.reg_stack_size = rs_size; */
comment|/* OBSOLETE   out_msg_buf->init_msg.arg_start = arg_start; */
comment|/* OBSOLETE   msg_send_serial (out_msg_buf); */
comment|/* OBSOLETE   expect_msg (INIT_ACK, in_msg_buf, 1); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE /****************************************************************************/
operator|*
operator|/
comment|/* OBSOLETE /*  */
comment|/* OBSOLETE  * Return a pointer to a string representing the given message code. */
comment|/* OBSOLETE  * Not all messages are represented here, only the ones that we expect */
comment|/* OBSOLETE  * to be called with. */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE static char * */
comment|/* OBSOLETE msg_str (INT32 code) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   static char cbuf[32]; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   switch (code) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE     case BKPT_SET_ACK: */
comment|/* OBSOLETE       sprintf (cbuf, "%s (%d)", "BKPT_SET_ACK", code); */
comment|/* OBSOLETE       break; */
comment|/* OBSOLETE     case BKPT_RM_ACK: */
comment|/* OBSOLETE       sprintf (cbuf, "%s (%d)", "BKPT_RM_ACK", code); */
comment|/* OBSOLETE       break; */
comment|/* OBSOLETE     case INIT_ACK: */
comment|/* OBSOLETE       sprintf (cbuf, "%s (%d)", "INIT_ACK", code); */
comment|/* OBSOLETE       break; */
comment|/* OBSOLETE     case READ_ACK: */
comment|/* OBSOLETE       sprintf (cbuf, "%s (%d)", "READ_ACK", code); */
comment|/* OBSOLETE       break; */
comment|/* OBSOLETE     case WRITE_ACK: */
comment|/* OBSOLETE       sprintf (cbuf, "%s (%d)", "WRITE_ACK", code); */
comment|/* OBSOLETE       break; */
comment|/* OBSOLETE     case ERROR: */
comment|/* OBSOLETE       sprintf (cbuf, "%s (%d)", "ERROR", code); */
comment|/* OBSOLETE       break; */
comment|/* OBSOLETE     case HALT: */
comment|/* OBSOLETE       sprintf (cbuf, "%s (%d)", "HALT", code); */
comment|/* OBSOLETE       break; */
comment|/* OBSOLETE     default: */
comment|/* OBSOLETE       sprintf (cbuf, "UNKNOWN (%d)", code); */
comment|/* OBSOLETE       break; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   return (cbuf); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE /****************************************************************************/
operator|*
operator|/
comment|/* OBSOLETE /* */
comment|/* OBSOLETE  * Selected (not all of them) error codes that we might get. */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE static char * */
comment|/* OBSOLETE error_msg_str (INT32 code) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   static char cbuf[50]; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   switch (code) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE     case EMFAIL: */
comment|/* OBSOLETE       return ("EMFAIL: unrecoverable error"); */
comment|/* OBSOLETE     case EMBADADDR: */
comment|/* OBSOLETE       return ("EMBADADDR: Illegal address"); */
comment|/* OBSOLETE     case EMBADREG: */
comment|/* OBSOLETE       return ("EMBADREG: Illegal register "); */
comment|/* OBSOLETE     case EMACCESS: */
comment|/* OBSOLETE       return ("EMACCESS: Could not access memory"); */
comment|/* OBSOLETE     case EMBADMSG: */
comment|/* OBSOLETE       return ("EMBADMSG: Unknown message type"); */
comment|/* OBSOLETE     case EMMSG2BIG: */
comment|/* OBSOLETE       return ("EMMSG2BIG: Message to large"); */
comment|/* OBSOLETE     case EMNOSEND: */
comment|/* OBSOLETE       return ("EMNOSEND: Could not send message"); */
comment|/* OBSOLETE     case EMNORECV: */
comment|/* OBSOLETE       return ("EMNORECV: Could not recv message"); */
comment|/* OBSOLETE     case EMRESET: */
comment|/* OBSOLETE       return ("EMRESET: Could not RESET target"); */
comment|/* OBSOLETE     case EMCONFIG: */
comment|/* OBSOLETE       return ("EMCONFIG: Could not get target CONFIG"); */
comment|/* OBSOLETE     case EMSTATUS: */
comment|/* OBSOLETE       return ("EMSTATUS: Could not get target STATUS"); */
comment|/* OBSOLETE     case EMREAD: */
comment|/* OBSOLETE       return ("EMREAD: Could not READ target memory"); */
comment|/* OBSOLETE     case EMWRITE: */
comment|/* OBSOLETE       return ("EMWRITE: Could not WRITE target memory"); */
comment|/* OBSOLETE     case EMBKPTSET: */
comment|/* OBSOLETE       return ("EMBKPTSET: Could not set breakpoint"); */
comment|/* OBSOLETE     case EMBKPTRM: */
comment|/* OBSOLETE       return ("EMBKPTRM: Could not remove breakpoint"); */
comment|/* OBSOLETE     case EMBKPTSTAT: */
comment|/* OBSOLETE       return ("EMBKPTSTAT: Could not get breakpoint status"); */
comment|/* OBSOLETE     case EMBKPTNONE: */
comment|/* OBSOLETE       return ("EMBKPTNONE: All breakpoints in use"); */
comment|/* OBSOLETE     case EMBKPTUSED: */
comment|/* OBSOLETE       return ("EMBKPTUSED: Breakpoints already in use"); */
comment|/* OBSOLETE     case EMINIT: */
comment|/* OBSOLETE       return ("EMINIT: Could not init target memory"); */
comment|/* OBSOLETE     case EMGO: */
comment|/* OBSOLETE       return ("EMGO: Could not start execution"); */
comment|/* OBSOLETE     case EMSTEP: */
comment|/* OBSOLETE       return ("EMSTEP: Could not single step"); */
comment|/* OBSOLETE     case EMBREAK: */
comment|/* OBSOLETE       return ("EMBREAK: Could not BREAK"); */
comment|/* OBSOLETE     case EMCOMMERR: */
comment|/* OBSOLETE       return ("EMCOMMERR: Communication error"); */
comment|/* OBSOLETE     default: */
comment|/* OBSOLETE       sprintf (cbuf, "error number %d", code); */
comment|/* OBSOLETE       break; */
comment|/* OBSOLETE     }				/* end switch */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE   return (cbuf); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE /****************************************************************************/
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE /* Receive a message, placing it in MSG_BUF, and expect it to be of */
comment|/* OBSOLETE    type MSGCODE.  If an error occurs, a non-zero FROM_TTY indicates */
comment|/* OBSOLETE    that the message should be printed. */
comment|/* OBSOLETE     */
comment|/* OBSOLETE    Return 0 for failure, 1 for success.  */
operator|*
operator|/
comment|/* OBSOLETE  */
comment|/* OBSOLETE static int */
comment|/* OBSOLETE expect_msg (INT32 msgcode, union msg_t *msg_buf, int from_tty) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   int retries = 0; */
comment|/* OBSOLETE   while (msg_recv_serial (msg_buf)&& (retries++< MAX_RETRIES)); */
comment|/* OBSOLETE   if (retries>= MAX_RETRIES) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       printf ("Expected msg %s, ", msg_str (msgcode)); */
comment|/* OBSOLETE       printf ("no message received!\n"); */
comment|/* OBSOLETE       return (0);		/* Failure */
operator|*
operator|/
comment|/* OBSOLETE     } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (msg_buf->generic_msg.code != msgcode) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       if (from_tty) */
comment|/* OBSOLETE 	{ */
comment|/* OBSOLETE 	  printf ("Expected msg %s, ", msg_str (msgcode)); */
comment|/* OBSOLETE 	  printf ("got msg %s\n", msg_str (msg_buf->generic_msg.code)); */
comment|/* OBSOLETE 	  if (msg_buf->generic_msg.code == ERROR) */
comment|/* OBSOLETE 	    printf ("%s\n", error_msg_str (msg_buf->error_msg.error_code)); */
comment|/* OBSOLETE 	} */
comment|/* OBSOLETE       return (0);		/* Failure */
operator|*
operator|/
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   return (1);			/* Success */
operator|*
operator|/
comment|/* OBSOLETE } */
comment|/* OBSOLETE /****************************************************************************/
operator|*
operator|/
comment|/* OBSOLETE /* */
comment|/* OBSOLETE  * Determine the MiniMon memory space qualifier based on the addr.  */
comment|/* OBSOLETE  * FIXME: Can't distinguis I_ROM/D_ROM.   */
comment|/* OBSOLETE  * FIXME: Doesn't know anything about I_CACHE/D_CACHE. */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE static int */
comment|/* OBSOLETE mm_memory_space (CORE_ADDR *addr) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   ADDR32 tstart = target_config.I_mem_start; */
comment|/* OBSOLETE   ADDR32 tend = tstart + target_config.I_mem_size; */
comment|/* OBSOLETE   ADDR32 dstart = target_config.D_mem_start; */
comment|/* OBSOLETE   ADDR32 dend = tstart + target_config.D_mem_size; */
comment|/* OBSOLETE   ADDR32 rstart = target_config.ROM_start; */
comment|/* OBSOLETE   ADDR32 rend = tstart + target_config.ROM_size; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE   if (((ADDR32) addr>= tstart)&& ((ADDR32) addr< tend)) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       return I_MEM; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else if (((ADDR32) addr>= dstart)&& ((ADDR32) addr< dend)) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       return D_MEM; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else if (((ADDR32) addr>= rstart)&& ((ADDR32) addr< rend)) */
comment|/* OBSOLETE     { */
comment|/* OBSOLETE       /* FIXME: how do we determine between D_ROM and I_ROM */
operator|*
operator|/
comment|/* OBSOLETE       return D_ROM; */
comment|/* OBSOLETE     } */
comment|/* OBSOLETE   else				/* FIXME: what do me do now? */
operator|*
operator|/
comment|/* OBSOLETE     return D_MEM;		/* Hmmm! */
operator|*
operator|/
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE /****************************************************************************/
operator|*
operator|/
comment|/* OBSOLETE /*  */
comment|/* OBSOLETE  *  Define the target subroutine names */
comment|/* OBSOLETE  */
operator|*
operator|/
comment|/* OBSOLETE struct target_ops mm_ops; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE static void */
comment|/* OBSOLETE init_mm_ops (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   mm_ops.to_shortname = "minimon"; */
comment|/* OBSOLETE   mm_ops.to_longname = "Remote AMD/Minimon target"; */
comment|/* OBSOLETE   mm_ops.to_doc = "Remote debug an AMD 290*0 using the MiniMon dbg core on the target"; */
comment|/* OBSOLETE   mm_ops.to_open = mm_open; */
comment|/* OBSOLETE   mm_ops.to_close = mm_close; */
comment|/* OBSOLETE   mm_ops.to_attach = mm_attach; */
comment|/* OBSOLETE   mm_ops.to_post_attach = NULL; */
comment|/* OBSOLETE   mm_ops.to_require_attach = NULL; */
comment|/* OBSOLETE   mm_ops.to_detach = mm_detach; */
comment|/* OBSOLETE   mm_ops.to_require_detach = NULL; */
comment|/* OBSOLETE   mm_ops.to_resume = mm_resume; */
comment|/* OBSOLETE   mm_ops.to_wait = mm_wait; */
comment|/* OBSOLETE   mm_ops.to_post_wait = NULL; */
comment|/* OBSOLETE   mm_ops.to_fetch_registers = mm_fetch_registers; */
comment|/* OBSOLETE   mm_ops.to_store_registers = mm_store_registers; */
comment|/* OBSOLETE   mm_ops.to_prepare_to_store = mm_prepare_to_store; */
comment|/* OBSOLETE   mm_ops.to_xfer_memory = mm_xfer_inferior_memory; */
comment|/* OBSOLETE   mm_ops.to_files_info = mm_files_info; */
comment|/* OBSOLETE   mm_ops.to_insert_breakpoint = mm_insert_breakpoint; */
comment|/* OBSOLETE   mm_ops.to_remove_breakpoint = mm_remove_breakpoint; */
comment|/* OBSOLETE   mm_ops.to_terminal_init = 0; */
comment|/* OBSOLETE   mm_ops.to_terminal_inferior = 0; */
comment|/* OBSOLETE   mm_ops.to_terminal_ours_for_output = 0; */
comment|/* OBSOLETE   mm_ops.to_terminal_ours = 0; */
comment|/* OBSOLETE   mm_ops.to_terminal_info = 0; */
comment|/* OBSOLETE   mm_ops.to_kill = mm_kill; */
comment|/* OBSOLETE   mm_ops.to_load = mm_load; */
comment|/* OBSOLETE   mm_ops.to_lookup_symbol = 0; */
comment|/* OBSOLETE   mm_ops.to_create_inferior = mm_create_inferior; */
comment|/* OBSOLETE   mm_ops.to_post_startup_inferior = NULL; */
comment|/* OBSOLETE   mm_ops.to_acknowledge_created_inferior = NULL; */
comment|/* OBSOLETE   mm_ops.to_clone_and_follow_inferior = NULL; */
comment|/* OBSOLETE   mm_ops.to_post_follow_inferior_by_clone = NULL; */
comment|/* OBSOLETE   mm_ops.to_insert_fork_catchpoint = NULL; */
comment|/* OBSOLETE   mm_ops.to_remove_fork_catchpoint = NULL; */
comment|/* OBSOLETE   mm_ops.to_insert_vfork_catchpoint = NULL; */
comment|/* OBSOLETE   mm_ops.to_remove_vfork_catchpoint = NULL; */
comment|/* OBSOLETE   mm_ops.to_has_forked = NULL; */
comment|/* OBSOLETE   mm_ops.to_has_vforked = NULL; */
comment|/* OBSOLETE   mm_ops.to_can_follow_vfork_prior_to_exec = NULL; */
comment|/* OBSOLETE   mm_ops.to_post_follow_vfork = NULL; */
comment|/* OBSOLETE   mm_ops.to_insert_exec_catchpoint = NULL; */
comment|/* OBSOLETE   mm_ops.to_remove_exec_catchpoint = NULL; */
comment|/* OBSOLETE   mm_ops.to_has_execd = NULL; */
comment|/* OBSOLETE   mm_ops.to_reported_exec_events_per_exec_call = NULL; */
comment|/* OBSOLETE   mm_ops.to_has_exited = NULL; */
comment|/* OBSOLETE   mm_ops.to_mourn_inferior = mm_mourn; */
comment|/* OBSOLETE   mm_ops.to_can_run = 0; */
comment|/* OBSOLETE   mm_ops.to_notice_signals = 0; */
comment|/* OBSOLETE   mm_ops.to_thread_alive = 0; */
comment|/* OBSOLETE   mm_ops.to_stop = 0; */
comment|/* OBSOLETE   mm_ops.to_pid_to_exec_file = NULL; */
comment|/* OBSOLETE   mm_ops.to_stratum = process_stratum; */
comment|/* OBSOLETE   mm_ops.DONT_USE = 0; */
comment|/* OBSOLETE   mm_ops.to_has_all_memory = 1; */
comment|/* OBSOLETE   mm_ops.to_has_memory = 1; */
comment|/* OBSOLETE   mm_ops.to_has_stack = 1; */
comment|/* OBSOLETE   mm_ops.to_has_registers = 1; */
comment|/* OBSOLETE   mm_ops.to_has_execution = 1; */
comment|/* OBSOLETE   mm_ops.to_sections = 0; */
comment|/* OBSOLETE   mm_ops.to_sections_end = 0; */
comment|/* OBSOLETE   mm_ops.to_magic = OPS_MAGIC; */
comment|/* OBSOLETE }; */
comment|/* OBSOLETE  */
comment|/* OBSOLETE void */
comment|/* OBSOLETE _initialize_remote_mm (void) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   init_mm_ops (); */
comment|/* OBSOLETE   add_target (&mm_ops); */
comment|/* OBSOLETE } */
comment|/* OBSOLETE  */
comment|/* OBSOLETE #ifdef NO_HIF_SUPPORT */
comment|/* OBSOLETE service_HIF (union msg_t *msg) */
comment|/* OBSOLETE { */
comment|/* OBSOLETE   return (0);			/* Emulate a failure */
operator|*
operator|/
end_expr_stmt

begin_comment
comment|/* OBSOLETE } */
end_comment

begin_comment
comment|/* OBSOLETE #endif */
end_comment

end_unit

