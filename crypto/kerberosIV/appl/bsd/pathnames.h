begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)pathnames.h	5.2 (Berkeley) 4/9/90  *	$Id: pathnames.h,v 1.25 1998/02/03 23:29:30 assar Exp $  */
end_comment

begin_comment
comment|/******* First fix default path, we stick to _PATH_DEFPATH everywhere */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_PATH_DEFPATH
argument_list|)
operator|&&
name|defined
argument_list|(
name|_PATH_USERPATH
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PATH_DEFPATH
value|_PATH_USERPATH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_PATH_DEFPATH
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_DEF_PATH
argument_list|)
end_if

begin_define
define|#
directive|define
name|_DEF_PATH
value|_PATH_DEFPATH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_PATH_DEFPATH
argument_list|)
operator|&&
name|defined
argument_list|(
name|_DEF_PATH
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PATH_DEFPATH
value|_DEF_PATH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DEFPATH
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DEFPATH
value|"/usr/ucb:/usr/bin:/bin"
end_define

begin_define
define|#
directive|define
name|_DEF_PATH
value|_PATH_DEFPATH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PATH_DEFPATH */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DEFSUPATH
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DEFSUPATH
value|"/usr/sbin:"  _DEF_PATH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATH_DEFSUPATH */
end_comment

begin_comment
comment|/******* Default PATH fixed! */
end_comment

begin_undef
undef|#
directive|undef
name|_PATH_RLOGIN
end_undef

begin_comment
comment|/* Redifine rlogin */
end_comment

begin_define
define|#
directive|define
name|_PATH_RLOGIN
value|BINDIR  "/rlogin"
end_define

begin_undef
undef|#
directive|undef
name|_PATH_RSH
end_undef

begin_comment
comment|/* Redifine rsh */
end_comment

begin_define
define|#
directive|define
name|_PATH_RSH
value|BINDIR  "/rsh"
end_define

begin_undef
undef|#
directive|undef
name|_PATH_RCP
end_undef

begin_comment
comment|/* Redifine rcp */
end_comment

begin_define
define|#
directive|define
name|_PATH_RCP
value|BINDIR  "/rcp"
end_define

begin_undef
undef|#
directive|undef
name|_PATH_LOGIN
end_undef

begin_define
define|#
directive|define
name|_PATH_LOGIN
value|BINDIR "/login"
end_define

begin_comment
comment|/******* The rest is fallback defaults */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DEV
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DEV
value|"/dev/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_CP
end_ifndef

begin_define
define|#
directive|define
name|_PATH_CP
value|"/bin/cp"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATH_CP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SHELLS
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SHELLS
value|"/etc/shells"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATH_SHELLS */
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

begin_comment
comment|/* _PATH_BSHELL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_CSHELL
end_ifndef

begin_define
define|#
directive|define
name|_PATH_CSHELL
value|"/bin/csh"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATH_CSHELL */
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
name|_PATH_TTY
end_ifndef

begin_define
define|#
directive|define
name|_PATH_TTY
value|"/dev/tty"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATH_TTY */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_HUSHLOGIN
end_ifndef

begin_define
define|#
directive|define
name|_PATH_HUSHLOGIN
value|".hushlogin"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATH_HUSHLOGIN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_NOMAILCHECK
end_ifndef

begin_define
define|#
directive|define
name|_PATH_NOMAILCHECK
value|".nomailcheck"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATH_NOMAILCHECK */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_MOTDFILE
end_ifndef

begin_define
define|#
directive|define
name|_PATH_MOTDFILE
value|"/etc/motd"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATH_MOTDFILE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_LOGACCESS
end_ifndef

begin_define
define|#
directive|define
name|_PATH_LOGACCESS
value|"/etc/login.access"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATH_LOGACCESS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_HEQUIV
end_ifndef

begin_define
define|#
directive|define
name|_PATH_HEQUIV
value|"/etc/hosts.equiv"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_FBTAB
end_ifndef

begin_define
define|#
directive|define
name|_PATH_FBTAB
value|"/etc/fbtab"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATH_FBTAB */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_LOGINDEVPERM
end_ifndef

begin_define
define|#
directive|define
name|_PATH_LOGINDEVPERM
value|"/etc/logindevperm"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATH_LOGINDEVPERM */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_CHPASS
end_ifndef

begin_define
define|#
directive|define
name|_PATH_CHPASS
value|"/usr/bin/passwd"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATH_CHPASS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__hpux
argument_list|)
end_if

begin_define
define|#
directive|define
name|__FALLBACK_MAILDIR__
value|"/usr/mail"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__FALLBACK_MAILDIR__
value|"/usr/spool/mail"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|KRB4_MAILDIR
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_MAILDIR
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|MAILDIR
end_ifdef

begin_define
define|#
directive|define
name|_PATH_MAILDIR
value|MAILDIR
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PATH_MAILDIR
value|__FALLBACK_MAILDIR__
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
comment|/* _PATH_MAILDIR */
end_comment

begin_define
define|#
directive|define
name|KRB4_MAILDIR
value|_PATH_MAILDIR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_LASTLOG
end_ifndef

begin_define
define|#
directive|define
name|_PATH_LASTLOG
value|"/var/adm/lastlog"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|UTMP_FILE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_PATH_UTMP
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PATH_UTMP
value|UTMP_FILE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_UTMP
end_ifndef

begin_define
define|#
directive|define
name|_PATH_UTMP
value|"/etc/utmp"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WTMP_FILE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_PATH_WTMP
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PATH_WTMP
value|WTMP_FILE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_WTMP
end_ifndef

begin_define
define|#
directive|define
name|_PATH_WTMP
value|"/usr/adm/wtmp"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_ETC_DEFAULT_LOGIN
end_ifndef

begin_define
define|#
directive|define
name|_PATH_ETC_DEFAULT_LOGIN
value|"/etc/default/login"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_ETC_ENVIRONMENT
end_ifndef

begin_define
define|#
directive|define
name|_PATH_ETC_ENVIRONMENT
value|"/etc/environment"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_ETC_SECURETTY
end_ifndef

begin_define
define|#
directive|define
name|_PATH_ETC_SECURETTY
value|"/etc/securetty"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * NeXT KLUDGE ALERT!!!!!!!!!!!!!!!!!!  * Some sort of bug in the NEXTSTEP cpp.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NeXT
end_ifdef

begin_undef
undef|#
directive|undef
name|_PATH_DEFSUPATH
end_undef

begin_define
define|#
directive|define
name|_PATH_DEFSUPATH
value|"/usr/sbin:/usr/ucb:/usr/bin:/bin"
end_define

begin_undef
undef|#
directive|undef
name|_PATH_RLOGIN
end_undef

begin_define
define|#
directive|define
name|_PATH_RLOGIN
value|"/usr/athena/bin/rlogin"
end_define

begin_undef
undef|#
directive|undef
name|_PATH_RSH
end_undef

begin_define
define|#
directive|define
name|_PATH_RSH
value|"/usr/athena/bin/rsh"
end_define

begin_undef
undef|#
directive|undef
name|_PATH_RCP
end_undef

begin_define
define|#
directive|define
name|_PATH_RCP
value|"/usr/athena/bin/rcp"
end_define

begin_undef
undef|#
directive|undef
name|_PATH_LOGIN
end_undef

begin_define
define|#
directive|define
name|_PATH_LOGIN
value|"/usr/athena/bin/login"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

