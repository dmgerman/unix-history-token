begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sysh.unx -*- C -*-    The header file for the UNIX system dependent routines.     Copyright (C) 1991, 1992, 1993, 1995 Ian Lance Taylor     This file is part of the Taylor UUCP package.     This program is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, 48 Grove Street, Somerville, MA 02144.    */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYSH_UNX_H
end_ifndef

begin_define
define|#
directive|define
name|SYSH_UNX_H
end_define

begin_if
if|#
directive|if
name|ANSI_C
end_if

begin_comment
comment|/* These structures are used in prototypes but are not defined in this    header file.  */
end_comment

begin_struct_decl
struct_decl|struct
name|uuconf_system
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sconnection
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SCO, SVR4 and Sequent lockfiles are basically just like HDB    lockfiles.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_SCO_LOCKFILES
operator|||
name|HAVE_SVR4_LOCKFILES
operator|||
name|HAVE_SEQUENT_LOCKFILES
end_if

begin_undef
undef|#
directive|undef
name|HAVE_HDB_LOCKFILES
end_undef

begin_define
define|#
directive|define
name|HAVE_HDB_LOCKFILES
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_BSD_TTY
operator|+
name|HAVE_SYSV_TERMIO
operator|+
name|HAVE_POSIX_TERMIOS
operator|!=
literal|1
end_if

begin_error
error|#
directive|error
error|Terminal driver define not set or duplicated
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|SPOOLDIR_V2
operator|+
name|SPOOLDIR_BSD42
operator|+
name|SPOOLDIR_BSD43
operator|+
name|SPOOLDIR_HDB
operator|+
name|SPOOLDIR_ULTRIX
operator|+
name|SPOOLDIR_SVR4
operator|+
name|SPOOLDIR_TAYLOR
operator|!=
literal|1
end_if

begin_error
error|#
directive|error
error|Spool directory define not set or duplicated
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If setreuid is broken, don't use it.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_BROKEN_SETREUID
end_if

begin_undef
undef|#
directive|undef
name|HAVE_SETREUID
end_undef

begin_define
define|#
directive|define
name|HAVE_SETREUID
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get some standard types from the configuration header file.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PID_T
end_ifdef

begin_typedef
typedef|typedef
name|PID_T
name|pid_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UID_T
end_ifdef

begin_typedef
typedef|typedef
name|UID_T
name|uid_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|GID_T
end_ifdef

begin_typedef
typedef|typedef
name|GID_T
name|gid_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OFF_T
end_ifdef

begin_typedef
typedef|typedef
name|OFF_T
name|off_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* On Unix, binary files are the same as text files.  */
end_comment

begin_define
define|#
directive|define
name|BINREAD
value|"r"
end_define

begin_define
define|#
directive|define
name|BINWRITE
value|"w"
end_define

begin_comment
comment|/* If we have sigaction, we can force system calls to not be    restarted.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_SIGACTION
end_if

begin_undef
undef|#
directive|undef
name|HAVE_RESTARTABLE_SYSCALLS
end_undef

begin_define
define|#
directive|define
name|HAVE_RESTARTABLE_SYSCALLS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If we have sigvec, and we have HAVE_SIGVEC_SV_FLAGS, and    SV_INTERRUPT is defined, we can force system calls to not be    restarted (signal.h is included by uucp.h before this point, so    SV_INTERRUPT will be defined by now if it it ever is).  */
end_comment

begin_if
if|#
directive|if
name|HAVE_SIGVEC
operator|&&
name|HAVE_SIGVEC_SV_FLAGS
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|SV_INTERRUPT
end_ifdef

begin_undef
undef|#
directive|undef
name|HAVE_RESTARTABLE_SYSCALLS
end_undef

begin_define
define|#
directive|define
name|HAVE_RESTARTABLE_SYSCALLS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If we were cross-configured, we will have a value of -1 for    HAVE_RESTARTABLE_SYSCALLS.  In this case, we try to guess what the    correct value should be.  Yuck.  If we have sigvec, but neither of    the above cases applied (which we know because they would have    changed HAVE_RESTARTABLE_SYSCALLS) then we are probably on 4.2BSD    and system calls are automatically restarted.  Otherwise, assume    that they are not.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_RESTARTABLE_SYSCALLS
operator|==
operator|-
literal|1
end_if

begin_undef
undef|#
directive|undef
name|HAVE_RESTARTABLE_SYSCALLS
end_undef

begin_if
if|#
directive|if
name|HAVE_SIGVEC
end_if

begin_define
define|#
directive|define
name|HAVE_RESTARTABLE_SYSCALLS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HAVE_RESTARTABLE_SYSCALLS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_RESTARTABLE_SYSCALLS == -1 */
end_comment

begin_comment
comment|/* We don't handle sigset in combination with restartable system    calls, so we check for it although this combination will never    happen.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_SIGACTION
operator|&&
operator|!
name|HAVE_SIGVEC
operator|&&
name|HAVE_SIGSET
end_if

begin_if
if|#
directive|if
name|HAVE_RESTARTABLE_SYSCALLS
end_if

begin_undef
undef|#
directive|undef
name|HAVE_SIGSET
end_undef

begin_define
define|#
directive|define
name|HAVE_SIGSET
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If we don't have restartable system calls, we can ignore    fsysdep_catch, usysdep_start_catch and usysdep_end_catch.    Otherwise fsysdep_catch has to do a setjmp.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_RESTARTABLE_SYSCALLS
end_if

begin_define
define|#
directive|define
name|fsysdep_catch
parameter_list|()
value|(TRUE)
end_define

begin_define
define|#
directive|define
name|usysdep_start_catch
parameter_list|()
end_define

begin_define
define|#
directive|define
name|usysdep_end_catch
parameter_list|()
end_define

begin_define
define|#
directive|define
name|CATCH_PROTECT
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HAVE_RESTARTABLE_SYSCALLS */
end_comment

begin_if
if|#
directive|if
name|HAVE_SETRET
operator|&&
operator|!
name|HAVE_SIGSETJMP
end_if

begin_include
include|#
directive|include
file|<setret.h>
end_include

begin_define
define|#
directive|define
name|setjmp
value|setret
end_define

begin_define
define|#
directive|define
name|longjmp
value|longret
end_define

begin_define
define|#
directive|define
name|jmp_buf
value|ret_buf
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_SETRET || HAVE_SIGSETJMP */
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_if
if|#
directive|if
name|HAVE_SIGSETJMP
end_if

begin_undef
undef|#
directive|undef
name|setjmp
end_undef

begin_undef
undef|#
directive|undef
name|longjmp
end_undef

begin_undef
undef|#
directive|undef
name|jmp_buf
end_undef

begin_define
define|#
directive|define
name|setjmp
parameter_list|(
name|s
parameter_list|)
value|sigsetjmp ((s), TRUE)
end_define

begin_define
define|#
directive|define
name|longjmp
value|siglongjmp
end_define

begin_define
define|#
directive|define
name|jmp_buf
value|sigjmp_buf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SIGSETJMP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_SETRET || HAVE_SIGSETJMP */
end_comment

begin_decl_stmt
specifier|extern
specifier|volatile
name|sig_atomic_t
name|fSjmp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|jmp_buf
name|sSjmp_buf
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|fsysdep_catch
parameter_list|()
value|(setjmp (sSjmp_buf) == 0)
end_define

begin_define
define|#
directive|define
name|usysdep_start_catch
parameter_list|()
value|(fSjmp = TRUE)
end_define

begin_define
define|#
directive|define
name|usysdep_end_catch
parameter_list|()
value|(fSjmp = FALSE)
end_define

begin_define
define|#
directive|define
name|CATCH_PROTECT
value|volatile
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_RESTARTABLE_SYSCALLS */
end_comment

begin_comment
comment|/* Get definitions for the terminal driver.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_BSD_TTY
end_if

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_struct
struct|struct
name|sbsd_terminal
block|{
name|struct
name|sgttyb
name|stty
decl_stmt|;
name|struct
name|tchars
name|stchars
decl_stmt|;
name|struct
name|ltchars
name|sltchars
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|sbsd_terminal
name|sterminal
typedef|;
end_typedef

begin_define
define|#
directive|define
name|fgetterminfo
parameter_list|(
name|o
parameter_list|,
name|q
parameter_list|)
define|\
value|(ioctl ((o), TIOCGETP,&(q)->stty) == 0 \&& ioctl ((o), TIOCGETC,&(q)->stchars) == 0 \&& ioctl ((o), TIOCGLTC,&(q)->sltchars) == 0)
end_define

begin_define
define|#
directive|define
name|fsetterminfo
parameter_list|(
name|o
parameter_list|,
name|q
parameter_list|)
define|\
value|(ioctl ((o), TIOCSETN,&(q)->stty) == 0 \&& ioctl ((o), TIOCSETC,&(q)->stchars) == 0 \&& ioctl ((o), TIOCSLTC,&(q)->sltchars) == 0)
end_define

begin_define
define|#
directive|define
name|fsetterminfodrain
parameter_list|(
name|o
parameter_list|,
name|q
parameter_list|)
define|\
value|(ioctl ((o), TIOCSETP,&(q)->stty) == 0 \&& ioctl ((o), TIOCSETC,&(q)->stchars) == 0 \&& ioctl ((o), TIOCSLTC,&(q)->sltchars) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_BSD_TTY */
end_comment

begin_if
if|#
directive|if
name|HAVE_SYSV_TERMIO
end_if

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|termio
name|sterminal
typedef|;
end_typedef

begin_define
define|#
directive|define
name|fgetterminfo
parameter_list|(
name|o
parameter_list|,
name|q
parameter_list|)
value|(ioctl ((o), TCGETA, (q)) == 0)
end_define

begin_define
define|#
directive|define
name|fsetterminfo
parameter_list|(
name|o
parameter_list|,
name|q
parameter_list|)
value|(ioctl ((o), TCSETA, (q)) == 0)
end_define

begin_define
define|#
directive|define
name|fsetterminfodrain
parameter_list|(
name|o
parameter_list|,
name|q
parameter_list|)
value|(ioctl ((o), TCSETAW, (q)) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYSV_TERMIO */
end_comment

begin_if
if|#
directive|if
name|HAVE_POSIX_TERMIOS
end_if

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|termios
name|sterminal
typedef|;
end_typedef

begin_define
define|#
directive|define
name|fgetterminfo
parameter_list|(
name|o
parameter_list|,
name|q
parameter_list|)
value|(tcgetattr ((o), (q)) == 0)
end_define

begin_define
define|#
directive|define
name|fsetterminfo
parameter_list|(
name|o
parameter_list|,
name|q
parameter_list|)
value|(tcsetattr ((o), TCSANOW, (q)) == 0)
end_define

begin_define
define|#
directive|define
name|fsetterminfodrain
parameter_list|(
name|o
parameter_list|,
name|q
parameter_list|)
value|(tcsetattr ((o), TCSADRAIN, (q)) == 0)
end_define

begin_comment
comment|/* On some systems it is not possible to include both<sys/ioctl.h>    and<termios.h> in the same source files; I don't really know why.    On such systems, we pretend that we don't have<sys/ioctl.h>.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_TERMIOS_AND_SYS_IOCTL_H
end_if

begin_undef
undef|#
directive|undef
name|HAVE_SYS_IOCTL_H
end_undef

begin_define
define|#
directive|define
name|HAVE_SYS_IOCTL_H
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_POSIX_TERMIOS */
end_comment

begin_comment
comment|/* The root directory (this is needed by the system independent stuff    as the default for local-send).  */
end_comment

begin_define
define|#
directive|define
name|ZROOTDIR
value|"/"
end_define

begin_comment
comment|/* The name of the execution directory within the spool directory    (this is need by the system independent uuxqt.c).  */
end_comment

begin_define
define|#
directive|define
name|XQTDIR
value|".Xqtdir"
end_define

begin_comment
comment|/* The name of the directory in which we preserve file transfers that    failed.  */
end_comment

begin_define
define|#
directive|define
name|PRESERVEDIR
value|".Preserve"
end_define

begin_comment
comment|/* The name of the directory to which we move corrupt files.  */
end_comment

begin_define
define|#
directive|define
name|CORRUPTDIR
value|".Corrupt"
end_define

begin_comment
comment|/* The name of the directory to which we move failed execution files.  */
end_comment

begin_define
define|#
directive|define
name|FAILEDDIR
value|".Failed"
end_define

begin_comment
comment|/* The length of the sequence number used in a file name.  */
end_comment

begin_define
define|#
directive|define
name|CSEQLEN
value|(4)
end_define

begin_comment
comment|/* Get some standard definitions.  Avoid including the files more than    once--some might have been included by uucp.h.  */
end_comment

begin_if
if|#
directive|if
name|USE_STDIO
operator|&&
name|HAVE_UNISTD_H
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|USE_TYPES_H
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_comment
comment|/* Get definitions for the file permission bits.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRWXU
end_ifndef

begin_define
define|#
directive|define
name|S_IRWXU
value|0700
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRUSR
end_ifndef

begin_define
define|#
directive|define
name|S_IRUSR
value|0400
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IWUSR
end_ifndef

begin_define
define|#
directive|define
name|S_IWUSR
value|0200
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IXUSR
end_ifndef

begin_define
define|#
directive|define
name|S_IXUSR
value|0100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRWXG
end_ifndef

begin_define
define|#
directive|define
name|S_IRWXG
value|0070
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRGRP
end_ifndef

begin_define
define|#
directive|define
name|S_IRGRP
value|0040
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IWGRP
end_ifndef

begin_define
define|#
directive|define
name|S_IWGRP
value|0020
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IXGRP
end_ifndef

begin_define
define|#
directive|define
name|S_IXGRP
value|0010
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRWXO
end_ifndef

begin_define
define|#
directive|define
name|S_IRWXO
value|0007
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IROTH
end_ifndef

begin_define
define|#
directive|define
name|S_IROTH
value|0004
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IWOTH
end_ifndef

begin_define
define|#
directive|define
name|S_IWOTH
value|0002
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IXOTH
end_ifndef

begin_define
define|#
directive|define
name|S_IXOTH
value|0001
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|STAT_MACROS_BROKEN
end_if

begin_undef
undef|#
directive|undef
name|S_ISDIR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISDIR
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFDIR
end_ifdef

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|i
parameter_list|)
value|(((i)& S_IFMT) == S_IFDIR)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (S_IFDIR) */
end_comment

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|i
parameter_list|)
value|(((i)& 0170000) == 040000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (S_IFDIR) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (S_ISDIR) */
end_comment

begin_comment
comment|/* We need the access macros.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|R_OK
end_ifndef

begin_define
define|#
directive|define
name|R_OK
value|4
end_define

begin_define
define|#
directive|define
name|W_OK
value|2
end_define

begin_define
define|#
directive|define
name|X_OK
value|1
end_define

begin_define
define|#
directive|define
name|F_OK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (R_OK) */
end_comment

begin_comment
comment|/* We create files with these modes (should this be configurable?).  */
end_comment

begin_define
define|#
directive|define
name|IPRIVATE_FILE_MODE
value|(S_IRUSR | S_IWUSR)
end_define

begin_define
define|#
directive|define
name|IPUBLIC_FILE_MODE
value|(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
end_define

begin_comment
comment|/* We create directories with this mode (should this be configurable?).  */
end_comment

begin_define
define|#
directive|define
name|IDIRECTORY_MODE
value|(S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH)
end_define

begin_define
define|#
directive|define
name|IPUBLIC_DIRECTORY_MODE
value|(S_IRWXU | S_IRWXG | S_IRWXO)
end_define

begin_if
if|#
directive|if
operator|!
name|HAVE_OPENDIR
end_if

begin_comment
comment|/* Define some structures to use if we don't have opendir, etc.  These    will only work if we have the old Unix filesystem, with a 2 byte    inode and a 14 byte filename.  */
end_comment

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_struct
struct|struct
name|dirent
block|{
name|char
name|d_name
index|[
name|DIRSIZ
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|o
decl_stmt|;
name|struct
name|dirent
name|s
decl_stmt|;
block|}
name|DIR
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|DIR
modifier|*
name|opendir
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zdir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|dirent
modifier|*
name|readdir
name|P
argument_list|(
operator|(
name|DIR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|closedir
name|P
argument_list|(
operator|(
name|DIR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_OPENDIR */
end_comment

begin_escape
end_escape

begin_if
if|#
directive|if
operator|!
name|HAVE_FTW_H
end_if

begin_comment
comment|/* If there is no<ftw.h>, define the ftw constants.  */
end_comment

begin_define
define|#
directive|define
name|FTW_F
value|(0)
end_define

begin_define
define|#
directive|define
name|FTW_D
value|(1)
end_define

begin_define
define|#
directive|define
name|FTW_DNR
value|(2)
end_define

begin_define
define|#
directive|define
name|FTW_NS
value|(3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_FTW_H */
end_comment

begin_escape
end_escape

begin_comment
comment|/* This structure holds the system dependent information we keep for a    connection.  This is used by the TCP and TLI code.  */
end_comment

begin_struct
struct|struct
name|ssysdep_conn
block|{
comment|/* File descriptor.  */
name|int
name|o
decl_stmt|;
comment|/* File descriptor to read from (used by stdin and pipe port types).  */
name|int
name|ord
decl_stmt|;
comment|/* File descriptor to write to (used by stdin and pipe port types).  */
name|int
name|owr
decl_stmt|;
comment|/* Device name.  */
name|char
modifier|*
name|zdevice
decl_stmt|;
comment|/* File status flags.  */
name|int
name|iflags
decl_stmt|;
comment|/* File status flags for write descriptor (-1 if not used).  */
name|int
name|iwr_flags
decl_stmt|;
comment|/* Hold the real descriptor when using a dialer device.  */
name|int
name|ohold
decl_stmt|;
comment|/* TRUE if this is a terminal and the remaining fields are valid.  */
name|boolean
name|fterminal
decl_stmt|;
comment|/* TRUE if this is a TLI descriptor.  */
name|boolean
name|ftli
decl_stmt|;
comment|/* Baud rate.  */
name|long
name|ibaud
decl_stmt|;
comment|/* Original terminal settings.  */
name|sterminal
name|sorig
decl_stmt|;
comment|/* Current terminal settings.  */
name|sterminal
name|snew
decl_stmt|;
comment|/* Process ID of currently executing pipe command, or parent process      of forked TCP or TLI server, or -1.  */
name|pid_t
name|ipid
decl_stmt|;
if|#
directive|if
name|HAVE_COHERENT_LOCKFILES
comment|/* On Coherent we need to hold on to the real port name which will      be used to enable the port.  Ick.  */
name|char
modifier|*
name|zenable
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* These functions do I/O and chat scripts to a port.  They are called    by the TCP and TLI routines.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_conn_read
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
name|char
operator|*
name|zbuf
operator|,
name|size_t
operator|*
name|pclen
operator|,
name|size_t
name|cmin
operator|,
name|int
name|ctimeout
operator|,
name|boolean
name|freport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_conn_write
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
specifier|const
name|char
operator|*
name|zbuf
operator|,
name|size_t
name|clen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_conn_io
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
specifier|const
name|char
operator|*
name|zwrite
operator|,
name|size_t
operator|*
name|pcwrite
operator|,
name|char
operator|*
name|zread
operator|,
name|size_t
operator|*
name|pcread
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fsysdep_conn_chat
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
name|char
operator|*
operator|*
name|pzprog
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Set a signal handler.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|usset_signal
name|P
argument_list|(
operator|(
name|int
name|isig
operator|,
name|RETSIGTYPE
argument_list|(
argument|*pfn
argument_list|)
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
operator|,
name|boolean
name|fforce
operator|,
name|boolean
operator|*
name|pfignored
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default signal handler.  This sets the appropriate element of the    afSignal array.  If system calls are automatically restarted, it    may do a longjmp to an fsysdep_catch.  */
end_comment

begin_decl_stmt
specifier|extern
name|RETSIGTYPE
name|ussignal
name|P
argument_list|(
operator|(
name|int
name|isig
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Try to fork, repeating several times.  */
end_comment

begin_decl_stmt
specifier|extern
name|pid_t
name|ixsfork
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Spawn a job.  Returns the process ID of the spawned job or -1 on    error.  The following macros may be passed in aidescs.  */
end_comment

begin_comment
comment|/* Set descriptor to /dev/null.  */
end_comment

begin_define
define|#
directive|define
name|SPAWN_NULL
value|(-1)
end_define

begin_comment
comment|/* Set element of aidescs to a pipe for caller to read from.  */
end_comment

begin_define
define|#
directive|define
name|SPAWN_READ_PIPE
value|(-2)
end_define

begin_comment
comment|/* Set element of aidescs to a pipe for caller to write to.  */
end_comment

begin_define
define|#
directive|define
name|SPAWN_WRITE_PIPE
value|(-3)
end_define

begin_decl_stmt
specifier|extern
name|pid_t
name|ixsspawn
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|*
name|pazargs
operator|,
name|int
operator|*
name|aidescs
operator|,
name|boolean
name|fkeepuid
operator|,
name|boolean
name|fkeepenv
operator|,
specifier|const
name|char
operator|*
name|zchdir
operator|,
name|boolean
name|fnosigs
operator|,
name|boolean
name|fshell
operator|,
specifier|const
name|char
operator|*
name|zpath
operator|,
specifier|const
name|char
operator|*
name|zuu_machine
operator|,
specifier|const
name|char
operator|*
name|zuu_user
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Do a form of popen using ixsspawn.  */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|espopen
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|*
name|pazargs
operator|,
name|boolean
name|frd
operator|,
name|pid_t
operator|*
name|pipid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Wait for a particular process to finish, returning the exit status.    The process ID should be pid_t, but we can't put that in a    prototype.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ixswait
name|P
argument_list|(
operator|(
name|unsigned
name|long
name|ipid
operator|,
specifier|const
name|char
operator|*
name|zreport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read from a connection using two file descriptors.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsdouble_read
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
name|char
operator|*
name|zbuf
operator|,
name|size_t
operator|*
name|pclen
operator|,
name|size_t
name|cmin
operator|,
name|int
name|ctimeout
operator|,
name|boolean
name|freport
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Write to a connection using two file descriptors.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsdouble_write
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
specifier|const
name|char
operator|*
name|zbuf
operator|,
name|size_t
name|clen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Run a chat program on a connection using two file descriptors.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsdouble_chat
name|P
argument_list|(
operator|(
expr|struct
name|sconnection
operator|*
name|qconn
operator|,
name|char
operator|*
operator|*
name|pzprog
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Find a spool file in the spool directory.  For a local file, the    bgrade argument is the grade of the file.  This is needed for    SPOOLDIR_SVR4.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsfind_file
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zsimple
operator|,
specifier|const
name|char
operator|*
name|zsystem
operator|,
name|int
name|bgrade
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the grade given a sequence number.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bsgrade
name|P
argument_list|(
operator|(
name|pointer
name|pseq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lock a string.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsdo_lock
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|boolean
name|fspooldir
operator|,
name|boolean
operator|*
name|pferr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Unlock a string.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsdo_unlock
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|boolean
name|fspooldir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Check access for a particular user name, or NULL to check access    for any user.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsuser_access
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|stat
operator|*
operator|,
name|int
name|imode
operator|,
specifier|const
name|char
operator|*
name|zuser
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Switch to the permissions of the invoking user.  This sets the    argument to a value to pass to fsuucp_perms.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsuser_perms
name|P
argument_list|(
operator|(
name|uid_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Switch back to the permissions of the UUCP user ID.  This should be    passed the value returned by fsuser_perms in its argument.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsuucp_perms
name|P
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stick two directories and a file name together.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsappend3
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zdir1
operator|,
specifier|const
name|char
operator|*
name|zdir2
operator|,
specifier|const
name|char
operator|*
name|zfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stick three directories and a file name together.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsappend4
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zdir1
operator|,
specifier|const
name|char
operator|*
name|zdir2
operator|,
specifier|const
name|char
operator|*
name|zdir3
operator|,
specifier|const
name|char
operator|*
name|zfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get a temporary file name.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zstemp_file
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get a command file name.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zscmd_file
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|,
name|int
name|bgrade
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get a jobid from a system, a file name, and a grade.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsfile_to_jobid
name|P
argument_list|(
operator|(
specifier|const
expr|struct
name|uuconf_system
operator|*
name|qsys
operator|,
specifier|const
name|char
operator|*
name|zfile
operator|,
name|int
name|bgrade
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get a file name from a jobid.  This also returns the associated system    in *pzsystem and the grade in *pbgrade.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zsjobid_to_file
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zid
operator|,
name|char
operator|*
operator|*
name|pzsystem
operator|,
name|char
operator|*
name|pbgrade
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* See whether there is a spool directory for a system when using    SPOOLDIR_ULTRIX.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|fsultrix_has_spool
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zsystem
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|HAVE_COHERENT_LOCKFILES
end_if

begin_comment
comment|/* Lock a coherent tty.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|lockttyexist
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|z
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|fscoherent_disable_tty
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zdevice
operator|,
name|char
operator|*
operator|*
name|pzenable
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some replacements for standard Unix functions.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_DUP2
end_if

begin_decl_stmt
specifier|extern
name|int
name|dup2
name|P
argument_list|(
operator|(
name|int
name|oold
operator|,
name|int
name|onew
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_FTW
end_if

begin_decl_stmt
specifier|extern
name|int
name|ftw
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zdir
operator|,
name|int
argument_list|(
argument|*pfn
argument_list|)
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zfile
operator|,
expr|struct
name|stat
operator|*
name|qstat
operator|,
name|int
name|iflag
operator|)
argument_list|)
operator|,
name|int
name|cdescriptors
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_GETCWD
operator|&&
operator|!
name|HAVE_GETWD
end_if

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|getcwd
name|P
argument_list|(
operator|(
name|char
operator|*
name|zbuf
operator|,
name|size_t
name|cbuf
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_MKDIR
end_if

begin_decl_stmt
specifier|extern
name|int
name|mkdir
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zdir
operator|,
name|int
name|imode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_RENAME
end_if

begin_decl_stmt
specifier|extern
name|int
name|rename
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zold
operator|,
specifier|const
name|char
operator|*
name|znew
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_RMDIR
end_if

begin_decl_stmt
specifier|extern
name|int
name|rmdir
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|zdir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* The working directory from which the program was run (this is set    by usysdep_initialize if called with INIT_GETCWD).  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|zScwd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The spool directory name.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|zSspooldir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The lock directory name.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|zSlockdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The local UUCP name (needed for some spool directory stuff).  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|zSlocalname
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (SYSH_UNX_H) */
end_comment

end_unit

