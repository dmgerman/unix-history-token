begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions file for GNU Emacs running on HPUX release 5.0.    Based on AT&T System V.2.    Copyright (C) 1985 Richard M. Stallman.  This file is part of GNU Emacs.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU Emacs General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU Emacs, but only under the conditions described in the GNU Emacs General Public License.   A copy of this license is supposed to have been given to you along with GNU Emacs so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
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
comment|/* Letter to use in finding device name of first pty,   if system supports pty's.  'p' means it is /dev/ptym/ptyp0  */
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
comment|/*  *	Define HAVE_PTYS if the system supports pty devices.  *      HPUX has them, but csh and some other things work badly with them.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PTYS
end_undef

begin_comment
comment|/*  *	Define NONSYSTEM_DIR_LIBRARY to make Emacs emulate  *      The 4.2 opendir, etc., library functions.  */
end_comment

begin_comment
comment|/* #define NONSYSTEM_DIR_LIBRARY */
end_comment

begin_comment
comment|/* Define this symbol if your system has the functions bcopy, etc. */
end_comment

begin_comment
comment|/* #define BSTRING */
end_comment

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

begin_escape
end_escape

begin_comment
comment|/* Special hacks needed to make Emacs run on this system.  */
end_comment

begin_comment
comment|/* Define this to cause -N to be passed to ld.  This is needed    in uniplus because of its funny memory space layout.  */
end_comment

begin_comment
comment|/* #define LOADER_N_SWITCH */
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

begin_comment
comment|/* Use the system provided termcap(3) library */
end_comment

begin_define
define|#
directive|define
name|TERMINFO
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
comment|/* In hpux, for unknown reasons, S_IFLNK is defined    even though symbolic links do not exist.    Make sure our conditionals based on S_IFLNK are not confused.     Here we assume that stat.h is included before config.h    so that we can override it here.  */
end_comment

begin_undef
undef|#
directive|undef
name|S_IFLNK
end_undef

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

end_unit

