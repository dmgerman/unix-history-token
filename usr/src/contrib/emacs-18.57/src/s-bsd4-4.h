begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions file for GNU Emacs running on bsd 4.4    Copyright (C) 1985, 1986 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Unfortunately, 4.4 and emacs have conflicting uses of BIG_ENDIAN    and LITTLE_ENDIAN.  Emacs assumes BIG_ENDIAN will be defined for    big endian machines and not defined for little endian machines.    endian.h in 4.4 defines both as values with BYTE_ORDER taking on    the appropriate one.  I see no way to reconcile the two.  Just    using the values from endian.h will break a little endian machine    since BIG_ENDIAN is also defined.  Undef'ing the values from    endian.h (in the m- file) and redefining only one won't work since,    for example, wait.h requires both be defined and have values.    At the current time this is not a problem as we can hack around    it.  Emacs' only use of BIG_ENDIAN is in lisp.h and then only    if NO_UNION_TYPE is not defined.  By ensuring that NO_UNION_TYPE    is defined, we avoid the issue.  We also include endian.h now to    make sure that the m- file doesn't override the correct value (in    the big endian case).  */
end_comment

begin_define
define|#
directive|define
name|NO_UNION_TYPE
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|YMAKEFILE
end_ifndef

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	Define symbols to identify the version of Unix this is.  *	Define all the symbols that apply correctly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSD4_4
end_ifndef

begin_define
define|#
directive|define
name|BSD4_4
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD4_4 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSD4_3
end_ifndef

begin_define
define|#
directive|define
name|BSD4_3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD4_3 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSD
end_ifndef

begin_define
define|#
directive|define
name|BSD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

begin_comment
comment|/* SYSTEM_TYPE should indicate the kind of system you are using.  It sets the Lisp variable system-type.  */
end_comment

begin_define
define|#
directive|define
name|SYSTEM_TYPE
value|"berkeley-unix"
end_define

begin_comment
comment|/* nomultiplejobs should be defined if your system's shell  does not have "job control" (the ability to stop a program,  run some other program, then continue the first one).  */
end_comment

begin_comment
comment|/* #define NOMULTIPLEJOBS */
end_comment

begin_comment
comment|/* Do not use interrupt_input = 1 by default, because in 4.3    we can make noninterrupt input work properly.  */
end_comment

begin_undef
undef|#
directive|undef
name|INTERRUPT_INPUT
end_undef

begin_comment
comment|/* First pty name is /dev/ptyp0.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PTY_LETTER
value|'p'
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

begin_define
define|#
directive|define
name|MAIL_USE_FLOCK
end_define

begin_comment
comment|/* Define CLASH_DETECTION if you want lock files to be written    so that Emacs can tell instantly when you try to modify    a file that someone else has modified in his Emacs.  */
end_comment

begin_define
define|#
directive|define
name|CLASH_DETECTION
end_define

begin_comment
comment|/* We use the Berkeley (and usg5.2.2) interface to nlist.  */
end_comment

begin_define
define|#
directive|define
name|NLIST_STRUCT
end_define

begin_comment
comment|/* The file containing the kernel's symbol table is called /vmunix.  */
end_comment

begin_define
define|#
directive|define
name|KERNEL_FILE
value|"/vmunix"
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

begin_comment
comment|/* This macro determines the number of bytes waiting to be written    in a FILE buffer.  */
end_comment

begin_define
define|#
directive|define
name|PENDING_OUTPUT_COUNT
parameter_list|(
name|FILE
parameter_list|)
value|((FILE)->_w - (FILE)->_bf._size)
end_define

begin_comment
comment|/* Have POSIX setsid().  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETSID
end_define

begin_comment
comment|/* Have BSD getloadavg() library routine.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETLOADAVG
end_define

begin_comment
comment|/* Use dkstat.h in loadst.  */
end_comment

begin_define
define|#
directive|define
name|DKSTAT_HEADER_FILE
end_define

begin_comment
comment|/* No special libg for debugging.  */
end_comment

begin_define
define|#
directive|define
name|LIBS_DEBUG
end_define

begin_comment
comment|/* Debugging unexec()ed code is hard enough as is, so why    not make it a little harder.  */
end_comment

begin_define
define|#
directive|define
name|C_DEBUG_SWITCH
value|-g -traditional -O2
end_define

end_unit

