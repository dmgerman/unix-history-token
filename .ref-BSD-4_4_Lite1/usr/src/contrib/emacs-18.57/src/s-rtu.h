begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions file for GNU Emacs running on RTU 3.0, ucb universe.    Copyright (C) 1986 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  *	Define symbols to identify the version of Unix this is.  *	Define all the symbols that apply correctly.  */
end_comment

begin_define
define|#
directive|define
name|BSD4_2
end_define

begin_define
define|#
directive|define
name|BSD
end_define

begin_define
define|#
directive|define
name|RTU
end_define

begin_comment
comment|/* SYSTEM_TYPE should indicate the kind of system you are using.  It sets the Lisp variable system-type.  */
end_comment

begin_define
define|#
directive|define
name|SYSTEM_TYPE
value|"rtu"
end_define

begin_comment
comment|/* NOMULTIPLEJOBS should be defined if your system's shell  does not have "job control" (the ability to stop a program,  run some other program, then continue the first one).  */
end_comment

begin_define
define|#
directive|define
name|NOMULTIPLEJOBS
end_define

begin_comment
comment|/* Emacs can read input using SIGIO and buffering characters itself,    or using CBREAK mode and making C-g cause SIGINT.    The choice is controlled by the variable interrupt_input.    Define INTERRUPT_INPUT to make interrupt_input = 1 the default (use SIGIO)     SIGIO can be used only on systems that implement it (4.2 and 4.3).    CBREAK mode has two disadvatages      1) At least in 4.2, it is impossible to handle the Meta key properly.         I hear that in system V this problem does not exist.      2) Control-G causes output to be discarded.         I do not know whether this can be fixed in system V.     Another method of doing input is planned but not implemented.    It would have Emacs fork off a separate process    to read the input and send it to the true Emacs process    through a pipe. */
end_comment

begin_undef
undef|#
directive|undef
name|INTERRUPT_INPUT
end_undef

begin_comment
comment|/* Letter to use in finding device name of first pty,   if system supports pty's.  'a' means it is /dev/ptya0  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PTY_LETTER
value|'z'
end_define

begin_comment
comment|/* i.e. no PTY_LETTERs */
end_comment

begin_comment
comment|/*  *	Define HAVE_TIMEVAL if the system supports the BSD style clock values.  *	Look in<sys/time.h> for a timeval structure.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIMEVAL
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

begin_define
define|#
directive|define
name|NONSYSTEM_DIR_LIBRARY
end_define

begin_comment
comment|/* Define this symbol if your system has the functions bcopy, etc. */
end_comment

begin_comment
comment|/* The system library bcopy() is broken in RTU.  For one thing, it expects    the length to be less than 64k. */
end_comment

begin_undef
undef|#
directive|undef
name|BSTRING
end_undef

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

begin_undef
undef|#
directive|undef
name|COFF
end_undef

begin_comment
comment|/* define MAIL_USE_FLOCK if the mailer uses flock    to interlock access to /usr/spool/mail/$USER.    The alternative is that a lock file named    /usr/spool/mail/$USER.lock.  */
end_comment

begin_undef
undef|#
directive|undef
name|MAIL_USE_FLOCK
end_undef

begin_comment
comment|/* Define CLASH_DETECTION if you want lock files to be written    so that Emacs can tell instantly when you try to modify    a file that someone else has modified in his Emacs.  */
end_comment

begin_undef
undef|#
directive|undef
name|CLASH_DETECTION
end_undef

begin_comment
comment|/* We use the Berkeley (and usg5.2.2) interface to nlist.  */
end_comment

begin_define
define|#
directive|define
name|NLIST_STRUCT
end_define

begin_comment
comment|/* The symbol in the kernel where the load average is found    is named _avenrun.  */
end_comment

begin_define
define|#
directive|define
name|LDAV_SYMBOL
value|"_avenrun"
end_define

begin_escape
end_escape

begin_comment
comment|/* Special hacks needed to make Emacs run on this system.  */
end_comment

begin_comment
comment|/* On RTU systems (like USG) the system calls are interruptable by signals  that the user program has elected to catch.  Thus the system call  must be retried in these cases.  To handle this without massive  changes in the source code, we remap the standard system call names  to names for our own functions in sysdep.c that do the system call  with retries. */
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
comment|/* The "fsync" call on RTU versions 3.0 and 3.1 is badly broken!    This hack below isn't the best solution, but without it this    program will cause the whole system to hang!  !@#$#%$ Masscomp!  */
end_comment

begin_define
define|#
directive|define
name|fsync
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_comment
comment|/* "Comment out" fsync calls */
end_comment

begin_comment
comment|/* RTU has IPC instead of Unix-domain sockets.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSVIPC
end_define

end_unit

