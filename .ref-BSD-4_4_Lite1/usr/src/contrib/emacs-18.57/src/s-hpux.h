begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions file for GNU Emacs running on HPUX release 5.0.    Based on AT&T System V.2.    Copyright (C) 1985, 1986 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
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

begin_define
define|#
directive|define
name|HPUX
end_define

begin_comment
comment|/* SYSTEM_TYPE should indicate the kind of system you are using.  It sets the Lisp variable system-type.  */
end_comment

begin_define
define|#
directive|define
name|SYSTEM_TYPE
value|"hpux"
end_define

begin_comment
comment|/* `nomultiplejobs' should be defined if your system's shell  does not have "job control" (the ability to stop a program,  run some other program, then continue the first one).   On hpux this depends on the precise kind of machine in use,  so the m- file defines this symbol if appropriate.  */
end_comment

begin_comment
comment|/* Default is to set interrupt_input to 0: don't do input buffering within Emacs */
end_comment

begin_comment
comment|/* #define INTERRUPT_INPUT */
end_comment

begin_comment
comment|/* Letter to use in finding device name of first pty,   if system supports pty's.  'p' means it is /dev/ptym/ptyp0  */
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

begin_define
define|#
directive|define
name|HAVE_TIMEVAL
end_define

begin_comment
comment|/* With HAVE_TIMEVAL define, Emacs expects to use `utimes'.    But HPUX does not have one.  */
end_comment

begin_define
define|#
directive|define
name|MISSING_UTIMES
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
comment|/* Define this symbol if your system has the functions bcopy, etc.  * s800 and later versions of s300 (s200) kernels have equivilents  * of the BSTRING functions of BSD.  If your s200 kernel doesn't have  * em comment out this section.  */
end_comment

begin_define
define|#
directive|define
name|BSTRING
end_define

begin_comment
comment|/* subprocesses should be defined if you want to  have code for asynchronous subprocesses  (as used in M-x compile and M-x shell).  This is generally OS dependent, and not supported  under most USG systems.  */
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
comment|/* Say we have the SYSV style of interprocess communication.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSVIPC
end_define

begin_comment
comment|/* Define CLASH_DETECTION if you want lock files to be written    so that Emacs can tell instantly when you try to modify    a file that someone else has modified in his Emacs.  */
end_comment

begin_comment
comment|/* #define CLASH_DETECTION */
end_comment

begin_comment
comment|/* Define SHORTNAMES if the C compiler can distinguish only    short names.  It means that the stuff in ../shortnames    must be run to convert the long names to short ones.     Some USG systems support long names.    If yours is one, DO NOT change this file!    Do #undef SHORTNAMES in the m- file or in config.h.  */
end_comment

begin_comment
comment|/* #define SHORTNAMES */
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
comment|/* The file containing the kernel's symbol table is called /hp-ux.  */
end_comment

begin_define
define|#
directive|define
name|KERNEL_FILE
value|"/hp-ux"
end_define

begin_comment
comment|/* The symbol in the kernel where the load average is found    depends on the cpu type, so we let the m- files define LDAV_SYMBOL.  */
end_comment

begin_comment
comment|/* Special hacks needed to make Emacs run on this system.  */
end_comment

begin_comment
comment|/*  *	Make the sigsetmask function go away.  Don't know what the  *	ramifications of this are, but doesn't seem possible to  *	emulate it properly anyway at this point.  */
end_comment

begin_comment
comment|/* HPUX has sigsetmask */
end_comment

begin_comment
comment|/* #define sigsetmask(mask)	/ * Null expansion * / */
end_comment

begin_comment
comment|/* setjmp and longjmp can safely replace _setjmp and _longjmp,    but they will run slower.  */
end_comment

begin_comment
comment|/* HP-UX has _setjmp and _longjmp */
end_comment

begin_comment
comment|/* #define _setjmp setjmp #define _longjmp longjmp */
end_comment

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
comment|/* Use the system provided termcap(3) library */
end_comment

begin_define
define|#
directive|define
name|TERMINFO
end_define

begin_comment
comment|/* The 48-bit versions are more winning for Emacs.  */
end_comment

begin_define
define|#
directive|define
name|rand
value|lrand48
end_define

begin_define
define|#
directive|define
name|srand
value|srand48
end_define

begin_comment
comment|/* In hpux, the symbol SIGIO is defined, but the feature    does not really exist.     Here we assume that signal.h is included before config.h    so that we can override it here.  */
end_comment

begin_undef
undef|#
directive|undef
name|SIGIO
end_undef

begin_comment
comment|/* USG systems tend to put everything declared static    into the initialized data area, which becomes pure after dumping Emacs.    Foil this.  Emacs carefully avoids static vars inside functions.  */
end_comment

begin_define
define|#
directive|define
name|static
end_define

begin_comment
comment|/* Define extra libraries to load.    This should have -lBSD, but that library is said to make    `signal' fail to work.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HPUX_NET
end_ifdef

begin_define
define|#
directive|define
name|LIBS_SYSTEM
value|-ln
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBS_SYSTEM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some additional system facilities exist.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_DUP2
end_define

begin_define
define|#
directive|define
name|HAVE_GETTIMEOFDAY
end_define

begin_define
define|#
directive|define
name|HAVE_VFORK
end_define

begin_define
define|#
directive|define
name|HAVE_RENAME
end_define

begin_comment
comment|/* The following maps shared exec file to demand loaded exec.    Don't do this as demand loaded exec is broken in hpux.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Adjust a header field for the executable file about to be dumped.  */
end_comment

begin_define
define|#
directive|define
name|ADJUST_EXEC_HEADER
define|\
value|hdr.a_magic = ((ohdr.a_magic.file_type == OLDMAGIC.file_type) ?  \ 		 NEWMAGIC : ohdr.a_magic);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Baud-rate values in tty status have nonstandard meanings.  */
end_comment

begin_define
define|#
directive|define
name|BAUD_CONVERT
define|\
value|{ 0, 50, 75, 110, 135, 150, 200, 300, 600, 900, 1200,  \   1800, 2400, 3600, 4800, 7200, 9600, 19200, 38400 }
end_define

begin_comment
comment|/* This is needed for HPUX version 6.2; it may not be needed for 6.2.1.  */
end_comment

begin_define
define|#
directive|define
name|SHORT_CAST_BUG
end_define

begin_comment
comment|/* Define killpg so that we have process group functionality under HP.  */
end_comment

begin_define
define|#
directive|define
name|killpg
parameter_list|(
name|PGRP
parameter_list|,
name|KSIG
parameter_list|)
value|kill (-(PGRP), KSIG)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NOT_C_CODE
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NO_SHORTNAMES
end_ifndef

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_define
define|#
directive|define
name|WAITTYPE
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|WRETCODE
parameter_list|(
name|w
parameter_list|)
value|(((w)>> 8)& 0377)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

