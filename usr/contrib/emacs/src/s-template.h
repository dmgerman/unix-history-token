begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Template for s- header files.    This file describes the parameters that s- files should define or not.    Copyright (C) 1985 Richard M. Stallman.  This file is part of GNU Emacs.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU Emacs General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU Emacs, but only under the conditions described in the GNU Emacs General Public License.   A copy of this license is supposed to have been given to you along with GNU Emacs so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/*  *	Define symbols to identify the version of Unix this is.  *	Define all the symbols that apply correctly.  */
end_comment

begin_comment
comment|/* #define UNIPLUS */
end_comment

begin_comment
comment|/* #define USG5 */
end_comment

begin_comment
comment|/* #define USG */
end_comment

begin_comment
comment|/* #define HPUX */
end_comment

begin_comment
comment|/* #define UMAX */
end_comment

begin_comment
comment|/* #define BSD4_1 */
end_comment

begin_comment
comment|/* #define BSD4_2 */
end_comment

begin_comment
comment|/* #define BSD4_3 */
end_comment

begin_comment
comment|/* #define BSD */
end_comment

begin_comment
comment|/* #define VMS */
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
comment|/* NOMULTIPLEJOBS should be defined if your system's shell  does not have "job control" (the ability to stop a program,  run some other program, then continue the first one).  */
end_comment

begin_comment
comment|/* #define NOMULTIPLEJOBS */
end_comment

begin_comment
comment|/* Emacs can read input using SIGIO and buffering characters itself,    or using CBREAK mode and making C-g cause SIGINT.    The choice is controlled by the variable interrupt_input.    Define INTERRUPT_INPUT to make interrupt_input = 1 the default (use SIGIO)     SIGIO can be used only on systems that implement it (4.2 and 4.3).    CBREAK mode has two disadvatages      1) At least in 4.2, it is impossible to handle the Meta key properly.         I hear that in system V this problem does not exist.      2) Control-G causes output to be discarded.         I do not know whether this can be fixed in system V.     Another method of doing input is planned but not implemented.    It would have Emacs fork off a separate process    to read the input and send it to the true Emacs process    through a pipe. */
end_comment

begin_define
define|#
directive|define
name|INTERRUPT_INPUT
end_define

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

begin_comment
comment|/* #define HAVE_SELECT */
end_comment

begin_comment
comment|/*  *	Define HAVE_PTYS if the system supports pty devices.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTYS
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
comment|/* Here, on a separate page, add any special hacks needed    to make Emacs work on this system.  For example,    you might define certain system call names that don't    exist on your system, or that do different things on    your system and must be used only through an encapsulation    (Which you should place, by convention, in sysdep.c).  */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Some compilers tend to put everything declared static    into the initialized data area, which becomes pure after dumping Emacs.    On these systems, you must #define static as nothing to foil this.    Note that emacs carefully avoids static vars inside functions.  */
end_comment

begin_define
define|#
directive|define
name|static
end_define

end_unit

