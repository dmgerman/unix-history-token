begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions file for GNU Emacs running on Silicon Graphics Irix system 3.3.    Copyright (C) 1987,1990 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  *	Define symbols to identify the version of Unix this is.  *	Define all the symbols that apply correctly.  */
end_comment

begin_define
define|#
directive|define
name|USG
end_define

begin_define
define|#
directive|define
name|USG5
end_define

begin_define
define|#
directive|define
name|IRIS
end_define

begin_comment
comment|/* SYSTEM_TYPE should indicate the kind of system you are using.  It sets the Lisp variable system-type.  */
end_comment

begin_define
define|#
directive|define
name|SYSTEM_TYPE
value|"silicon-graphics-unix"
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
comment|/* Letter to use in finding device name of first pty,   if system supports pty's.  'a' means it is /dev/ptya0  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PTY_LETTER
value|'a'
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

begin_define
define|#
directive|define
name|HAVE_TIMEVAL
end_define

begin_comment
comment|/* `utime' system call doesn't understand timevals.  */
end_comment

begin_define
define|#
directive|define
name|IRIS_UTIME
end_define

begin_comment
comment|/*  *	Define HAVE_SELECT if the system supports the `select' system call.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SELECT
end_define

begin_comment
comment|/*  *	Define HAVE_PTYS if the system supports pty devices.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTYS
end_define

begin_comment
comment|/* Define HAVE_SOCKETS if system supports 4.2-compatible sockets.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SOCKETS
end_define

begin_comment
comment|/*  *	Define NONSYSTEM_DIR_LIBRARY to make Emacs emulate  *      The 4.2 opendir, etc., library functions.  */
end_comment

begin_comment
comment|/* #define NONSYSTEM_DIR_LIBRARY */
end_comment

begin_comment
comment|/* Define this symbol if your system has the functions bcopy, etc. */
end_comment

begin_define
define|#
directive|define
name|BSTRING
end_define

begin_comment
comment|/* subprocesses should be defined if you want to    have code for asynchronous subprocesses    (as used in M-x compile and M-x shell).    This is generally OS dependent, and not supported    under most USG systems. */
end_comment

begin_define
define|#
directive|define
name|subprocesses
end_define

begin_comment
comment|/* If your system uses COFF (Common Object File Format) then define the    preprocessor symbol "COFF". */
end_comment

begin_comment
comment|/* #define COFF */
end_comment

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
comment|/* We use the Berkeley (and usg5.2.2) interface to nlist.  */
end_comment

begin_define
define|#
directive|define
name|NLIST_STRUCT
end_define

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
comment|/* The symbol in the kernel where the load average is found    is named _avenrun.  (Actually, no such symbol is right;    sysmp must be used to find the address.)  */
end_comment

begin_define
define|#
directive|define
name|LDAV_SYMBOL
value|"avenrun"
end_define

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
comment|/* getwd is defined.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETWD
end_define

begin_define
define|#
directive|define
name|HAVE_SYSVIPC
end_define

end_unit

