begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* opie_cfg.h: Various configuration-type pieces of information for OPIE.  %%% portions-copyright-cmetz-96 Portions of this software are Copyright 1996-1999 by Craig Metz, All Rights Reserved. The Inner Net License Version 2 applies to these portions of the software. You should have received a copy of the license with this software. If you didn't get a copy, you may request one from<license@inner.net>.  Portions of this software are Copyright 1995 by Randall Atkinson and Dan McDonald, All Rights Reserved. All Rights under this copyright are assigned to the U.S. Naval Research Laboratory (NRL). The NRL Copyright Notice and License Agreement applies to this software.  	History:  	Modified by cmetz for OPIE 2.4. Removed NBBY definition. 	Modified by cmetz for OPIE 2.32. Include<sys/types.h> before<dirent.h> to make *BSD happy. 	Modified by cmetz for OPIE 2.31. Added 4.4BSD-Lite pathnames.h 		definitions from ftpd. Added struct spwd definition and 		HAVE_SHADOW logic for SunOS C2 shadow password support. 		Moved user locking config to configure script. Removed 		options.h. 	Modified by cmetz for OPIE 2.3. Splatted with opie_auto.h. 	        Obseleted many symbols. Changed OPIE_PASS_{MIN,MAX} to 		OPIE_SECRET_{MIN,MAX}. Fixed SHADOW+UTMP definitions. 		Removed a lot of symbols.         Modified by cmetz for OPIE 2.2. Got rid of ANSIPROTO and ARGS.                 Got rid of TRUE and FALSE definitions. Moved UINT4 to                 opie.h and removed UINT2. 	Modified at NRL for OPIE 2.1. Fixed sigprocmask declaration. 		Gutted for autoconf. Split up for autoconf. 	Written at NRL for OPIE 2.0.  	History of opie_auto.h:  	Modified by cmetz for OPIE 2.22. Support the Solaris TTYPROMPT drain 		bamage on all systems -- it doesn't hurt others, and it's 		not something Autoconf can check for yet.         Modified by cmetz for OPIE 2.2. Don't replace sigprocmask by ifdef.                 Added configure check for LS_COMMAND. Added setreuid/setgid                 band-aids.         Modified at NRL for OPIE 2.2. Require /etc/shadow for Linux to use                 shadow passwords.         Modified at NRL for OPIE 2.11. Removed version defines. 	Modified at NRL for OPIE 2.1. Fixed sigprocmask declaration. 		Gutted for autoconf. Split up for autoconf. 	Written at NRL for OPIE 2.0. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPIE_CFG_H
end_ifndef

begin_define
define|#
directive|define
name|_OPIE_CFG_H
value|1
end_define

begin_define
define|#
directive|define
name|VERSION
value|"2.4"
end_define

begin_define
define|#
directive|define
name|DATE
value|"Friday, January 19, 2001"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|unix
end_ifndef

begin_define
define|#
directive|define
name|unix
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* unix */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_comment
comment|/* System characteristics */
end_comment

begin_if
if|#
directive|if
name|HAVE_GETUTXLINE
operator|&&
name|HAVE_UTMPX_H
end_if

begin_define
define|#
directive|define
name|DOUTMPX
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HAVE_GETUTXLINE&& HAVE_UTMPX_H */
end_comment

begin_define
define|#
directive|define
name|DOUTMPX
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_GETUTXLINE&& HAVE_UTMPX_H */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* Adapted from the Autoconf hypertext info pages */
end_comment

begin_if
if|#
directive|if
name|HAVE_DIRENT_H
end_if

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HAVE_DIRENT_H */
end_comment

begin_define
define|#
directive|define
name|dirent
value|direct
end_define

begin_if
if|#
directive|if
name|HAVE_SYS_NDIR_H
end_if

begin_include
include|#
directive|include
file|<sys/ndir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_NDIR_H */
end_comment

begin_if
if|#
directive|if
name|HAVE_SYS_DIR_H
end_if

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_DIR_H */
end_comment

begin_if
if|#
directive|if
name|HAVE_NDIR_H
end_if

begin_include
include|#
directive|include
file|<ndir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_NDIR_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_DIRENT_H */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAIL_DIR
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|PATH_MAIL
end_ifdef

begin_define
define|#
directive|define
name|MAIL_DIR
value|PATH_MAIL
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* PATH_MAIL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_PATH_MAIL
end_ifdef

begin_define
define|#
directive|define
name|MAIL_DIR
value|_PATH_MAIL
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _PATH_MAIL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_PATH_MAILDIR
end_ifdef

begin_define
define|#
directive|define
name|MAIL_DIR
value|_PATH_MAILDIR
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _PATH_MAILDIR */
end_comment

begin_define
define|#
directive|define
name|MAIL_DIR
value|"/usr/spool/mail"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATH_MAILDIR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATH_MAIL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PATH_MAIL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAIL_DIR */
end_comment

begin_if
if|#
directive|if
name|HAVE_SHADOW_H
operator|&&
name|HAVE_GETSPNAM
operator|&&
name|HAVE_ENDSPENT
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|linux
argument_list|)
operator|&&
operator|!
name|HAVE_ETC_SHADOW
end_if

begin_define
define|#
directive|define
name|HAVE_SHADOW
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(linux)&& !HAVE_ETC_SHADOW */
end_comment

begin_define
define|#
directive|define
name|HAVE_SHADOW
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(linux)&& !HAVE_ETC_SHADOW */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SHADOW_H&& HAVE_GETSPNAM&& HAVE_ENDSPENT */
end_comment

begin_if
if|#
directive|if
name|HAVE_SUNOS_C2_SHADOW
operator|&&
operator|!
name|HAVE_SHADOW
end_if

begin_undef
undef|#
directive|undef
name|HAVE_SHADOW
end_undef

begin_define
define|#
directive|define
name|HAVE_SHADOW
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SUNOS_C2_SHADOW&& !HAVE_SHADOW */
end_comment

begin_comment
comment|/* If the user didn't specify, default to MD5 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MDX
end_ifndef

begin_define
define|#
directive|define
name|MDX
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MDX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_BSHELL
end_ifndef

begin_define
define|#
directive|define
name|_PATH_BSHELL
value|"/bin/sh"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DEVNULL
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DEVNULL
value|"/dev/null"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_FTPUSERS
end_ifndef

begin_define
define|#
directive|define
name|_PATH_FTPUSERS
value|"/etc/ftpusers"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_FTPLOGINMESG
end_ifndef

begin_define
define|#
directive|define
name|_PATH_FTPLOGINMESG
value|"/etc/ftpmotd"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATH_FTPLOGINMESG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_FTPWELCOME
end_ifndef

begin_define
define|#
directive|define
name|_PATH_FTPWELCOME
value|"/etc/ftpwelcome"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATH_FTPWELCOME */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_NOLOGIN
end_ifndef

begin_define
define|#
directive|define
name|_PATH_NOLOGIN
value|"/etc/nologin"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATH_NOLOGIN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TTYGRPNAME
end_ifndef

begin_define
define|#
directive|define
name|TTYGRPNAME
value|"tty"
end_define

begin_comment
comment|/* name of group to own ttys */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|QUIET_LOGIN_FILE
end_ifndef

begin_define
define|#
directive|define
name|QUIET_LOGIN_FILE
value|".hushlogin"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OPIE_ALWAYS_FILE
end_ifndef

begin_define
define|#
directive|define
name|OPIE_ALWAYS_FILE
value|".opiealways"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OPIE_LOCK_TIMEOUT
end_ifndef

begin_define
define|#
directive|define
name|OPIE_LOCK_TIMEOUT
value|(30*60)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MOTD_FILE
end_ifndef

begin_define
define|#
directive|define
name|MOTD_FILE
value|"/etc/motd"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOGIN_PATH
end_ifndef

begin_define
define|#
directive|define
name|LOGIN_PATH
value|"/usr/ucb:/bin:/usr/bin"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOGIN_PATH */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|POINTER
end_ifndef

begin_define
define|#
directive|define
name|POINTER
value|unsigned char *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POINTER */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SUNOS_C2_SHADOW
end_ifdef

begin_struct
struct|struct
name|spwd
block|{
name|char
modifier|*
name|sp_pwdp
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SUNOS_C2_SHADOW */
end_comment

begin_define
define|#
directive|define
name|_OPIE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OPIE_CFG_H */
end_comment

end_unit

