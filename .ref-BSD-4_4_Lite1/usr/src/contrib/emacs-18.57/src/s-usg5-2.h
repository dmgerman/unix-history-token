begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions file for GNU Emacs running on AT&T's System V Release 2.0    Copyright (C) 1985, 1986 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  *	Define symbols to identify the version of Unix this is.  *	Define all the symbols that apply correctly.  */
end_comment

begin_define
define|#
directive|define
name|USG
end_define

begin_comment
comment|/* System III, System V, etc */
end_comment

begin_define
define|#
directive|define
name|USG5
end_define

begin_comment
comment|/* SYSTEM_TYPE should indicate the kind of system you are using.  It sets the Lisp variable system-type.  */
end_comment

begin_define
define|#
directive|define
name|SYSTEM_TYPE
value|"usg-unix-v"
end_define

begin_comment
comment|/* nomultiplejobs should be defined if your system's shell  does not have "job control" (the ability to stop a program,  run some other program, then continue the first one).  */
end_comment

begin_define
define|#
directive|define
name|NOMULTIPLEJOBS
end_define

begin_comment
comment|/* Default is to set interrupt_input to 0: don't do input buffering within Emacs */
end_comment

begin_comment
comment|/* #define INTERRUPT_INPUT */
end_comment

begin_comment
comment|/* Letter to use in finding device name of first pty,   if system supports pty's.  'p' means it is /dev/ptyp0  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PTY_LETTER
value|'p'
end_define

begin_comment
comment|/*  *	Define HAVE_TERMIO if the system provides sysV-style ioctls  *	for terminal control.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIO
end_define

begin_comment
comment|/*  *	Define HAVE_TIMEVAL if the system supports the BSD style clock values.  *	Look in<sys/time.h> for a timeval structure.  */
end_comment

begin_comment
comment|/* #define HAVE_TIMEVAL */
end_comment

begin_comment
comment|/*  *	Define HAVE_SELECT if the system supports the `select' system call.  */
end_comment

begin_comment
comment|/* #define HAVE_SELECT */
end_comment

begin_comment
comment|/*  *	Define HAVE_PTYS if the system supports pty devices.  */
end_comment

begin_comment
comment|/* #define HAVE_PTYS */
end_comment

begin_comment
comment|/* Define HAVE_SOCKETS if system supports 4.2-compatible sockets.  */
end_comment

begin_comment
comment|/* #define HAVE_SOCKETS */
end_comment

begin_comment
comment|/*  *	Define NONSYSTEM_DIR_LIBRARY to make Emacs emulate  *      The 4.2 opendir, etc., library functions.  */
end_comment

begin_define
define|#
directive|define
name|NONSYSTEM_DIR_LIBRARY
end_define

begin_comment
comment|/* Define this symbol if your system has the functions bcopy, etc. */
end_comment

begin_comment
comment|/* #define BSTRING */
end_comment

begin_comment
comment|/* subprocesses should be defined if you want to  have code for asynchronous subprocesses  (as used in M-x compile and M-x shell).  This is supposed to work now on system V release 2.  */
end_comment

begin_define
define|#
directive|define
name|subprocesses
end_define

begin_comment
comment|/* If your system uses COFF (Common Object File Format) then define the    preprocessor symbol "COFF". */
end_comment

begin_define
define|#
directive|define
name|COFF
end_define

begin_comment
comment|/* define MAIL_USE_FLOCK if the mailer uses flock    to interlock access to /usr/spool/mail/$USER.    The alternative is that a lock file named    /usr/spool/mail/$USER.lock.  */
end_comment

begin_comment
comment|/* #define MAIL_USE_FLOCK */
end_comment

begin_comment
comment|/* Define CLASH_DETECTION if you want lock files to be written    so that Emacs can tell instantly when you try to modify    a file that someone else has modified in his Emacs.  */
end_comment

begin_comment
comment|/* #define CLASH_DETECTION */
end_comment

begin_comment
comment|/* Define SHORTNAMES if the C compiler can distinguish only    short names.  It means that the stuff in ../shortnames    must be run to convert the long names to short ones.  */
end_comment

begin_comment
comment|/* #define SHORTNAMES */
end_comment

begin_comment
comment|/* We do NOT use the Berkeley (and usg5.2.2) interface to nlist.  */
end_comment

begin_comment
comment|/* #define NLIST_STRUCT */
end_comment

begin_comment
comment|/* The file containing the kernel's symbol table is called /unix.  */
end_comment

begin_define
define|#
directive|define
name|KERNEL_FILE
value|"/unix"
end_define

begin_comment
comment|/* The symbol in the kernel where the load average is found    is named avenrun.  */
end_comment

begin_define
define|#
directive|define
name|LDAV_SYMBOL
value|"avenrun"
end_define

begin_escape
end_escape

begin_comment
comment|/* Special hacks needed to make Emacs run on this system.  */
end_comment

begin_comment
comment|/*  *	Make the sigsetmask function go away.  Don't know what the  *	ramifications of this are, but doesn't seem possible to  *	emulate it properly anyway at this point.  */
end_comment

begin_define
define|#
directive|define
name|sigsetmask
parameter_list|(
name|mask
parameter_list|)
end_define

begin_comment
comment|/* Null expansion */
end_comment

begin_comment
comment|/* setjmp and longjmp can safely replace _setjmp and _longjmp,    but they will run slower.  */
end_comment

begin_define
define|#
directive|define
name|_setjmp
value|setjmp
end_define

begin_define
define|#
directive|define
name|_longjmp
value|longjmp
end_define

begin_comment
comment|/* On USG systems the system calls are interruptable by signals  that the user program has elected to catch.  Thus the system call  must be retried in these cases.  To handle this without massive  changes in the source code, we remap the standard system call names  to names for our own functions in sysdep.c that do the system call  with retries. */
end_comment

begin_define
define|#
directive|define
name|read
value|sys_read
end_define

begin_define
define|#
directive|define
name|open
value|sys_open
end_define

begin_define
define|#
directive|define
name|write
value|sys_write
end_define

begin_define
define|#
directive|define
name|INTERRUPTABLE_OPEN
end_define

begin_define
define|#
directive|define
name|INTERRUPTABLE_IO
end_define

begin_comment
comment|/* On USG systems these have different names */
end_comment

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

begin_comment
comment|/* USG systems tend to put everything declared static    into the initialized data area, which becomes pure after dumping Emacs.    Foil this.  Emacs carefully avoids static vars inside functions.  */
end_comment

begin_define
define|#
directive|define
name|static
end_define

begin_comment
comment|/* Compiler bug bites on many systems when default ADDR_CORRECT is used.  */
end_comment

begin_define
define|#
directive|define
name|ADDR_CORRECT
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_comment
comment|/* Prevent -lg from being used for debugging.  Not implemented?  */
end_comment

begin_define
define|#
directive|define
name|LIBS_DEBUG
end_define

begin_comment
comment|/* Use terminfo instead of termcap.  */
end_comment

begin_define
define|#
directive|define
name|TERMINFO
end_define

end_unit

