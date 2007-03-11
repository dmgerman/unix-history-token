begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: /p/tcsh/cvsroot/tcsh/pathnames.h,v 3.18 2002/03/08 17:36:46 christos Exp $ */
end_comment

begin_comment
comment|/*  * pathnames.h: Location of things to find  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1980, 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_pathnames
end_ifndef

begin_define
define|#
directive|define
name|_h_pathnames
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4_4
end_ifdef

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CMUCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_PATH_LOCAL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PATH_LOCAL
value|"/usr/cs/bin"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CMUCS&& !_PATH_LOCAL */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|convex
argument_list|)
operator|||
name|defined
argument_list|(
name|stellar
argument_list|)
operator|||
name|defined
argument_list|(
name|INTEL
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DOTLOGIN
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DOTLOGIN
value|"/etc/login"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PATH_DOTLOGIN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DOTLOGOUT
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DOTLOGOUT
value|"/etc/logout"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PATH_DOTLOGOUT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DOTCSHRC
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DOTCSHRC
value|"/etc/cshrc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PATH_DOTCSHRC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* convex || stellar || INTEL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NeXT
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DOTLOGIN
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DOTLOGIN
value|"/etc/login.std"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PATH_DOTLOGIN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DOTLOGOUT
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DOTLOGOUT
value|"/etc/logout.std"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PATH_DOTLOGOUT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DOTCSHRC
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DOTCSHRC
value|"/etc/cshrc.std"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PATH_DOTCSHRC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NeXT */
end_comment

begin_comment
comment|/* for sunos5.  */
end_comment

begin_if
if|#
directive|if
operator|(
operator|(
name|defined
argument_list|(
name|sun
argument_list|)
operator|||
name|defined
argument_list|(
name|__sun__
argument_list|)
operator|)
operator|&&
operator|(
name|SYSVREL
operator|==
literal|4
operator|)
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DOTLOGIN
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DOTLOGIN
value|"/etc/.login"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PATH_DOTLOGIN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DOTLOGOUT
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DOTLOGOUT
value|"/etc/.logout"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PATH_DOTLOGOUT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DOTCSHRC
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DOTCSHRC
value|"/etc/.cshrc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PATH_DOTCSHRC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sun& SVR4 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sgi
argument_list|)
operator|||
name|defined
argument_list|(
name|OREO
argument_list|)
operator|||
name|defined
argument_list|(
name|cray
argument_list|)
operator|||
name|defined
argument_list|(
name|AMIX
argument_list|)
operator|||
name|defined
argument_list|(
name|CDC
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DOTLOGIN
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DOTLOGIN
value|"/etc/cshrc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PATH_DOTLOGIN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sgi || OREO || cray || AMIX || CDC */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_CRAYCOM
argument_list|)
operator|||
name|defined
argument_list|(
name|Lynx
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|_PATH_TCSHELL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PATH_TCSHELL
value|"/bin/tcsh"
end_define

begin_comment
comment|/* 1st class shell */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CRAYCOM&& !_PATH_TCSHELL */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MINIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_PATH_TCSHELL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PATH_TCSHELL
value|"/local/bin/tcsh"
end_define

begin_comment
comment|/* use ram disk */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MINIX&& !_PATH_TCSHELL */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__EMX__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_PATH_DEVNULL
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PATH_DEVNULL
value|"nul"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __EMX__&& !_PATH_DEVNULL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_LOCAL
end_ifndef

begin_define
define|#
directive|define
name|_PATH_LOCAL
value|"/usr/local/bin"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PATH_LOCAL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_USRBIN
end_ifndef

begin_define
define|#
directive|define
name|_PATH_USRBIN
value|"/usr/bin"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PATH_USRBIN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_USRUCB
end_ifndef

begin_define
define|#
directive|define
name|_PATH_USRUCB
value|"/usr/ucb"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PATH_USRUCB */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_USRBSD
end_ifndef

begin_define
define|#
directive|define
name|_PATH_USRBSD
value|"/usr/bsd"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PATH_USRBSD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_BIN
end_ifndef

begin_define
define|#
directive|define
name|_PATH_BIN
value|"/bin"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PATH_BIN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DOTCSHRC
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DOTCSHRC
value|"/etc/csh.cshrc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PATH_DOTCSHRC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DOTLOGIN
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DOTLOGIN
value|"/etc/csh.login"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PATH_DOTLOGIN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DOTLOGOUT
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DOTLOGOUT
value|"/etc/csh.logout"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PATH_DOTLOGOUT */
end_comment

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

begin_comment
comment|/* !_PATH_DEVNULL */
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
comment|/* !_PATH_BSHELL */
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
comment|/* !_PATH_CSHELL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_TCSHELL
end_ifndef

begin_define
define|#
directive|define
name|_PATH_TCSHELL
value|"/usr/local/bin/tcsh"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PATH_TCSHELL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_BIN_LOGIN
end_ifndef

begin_define
define|#
directive|define
name|_PATH_BIN_LOGIN
value|"/bin/login"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PATH_BIN_LOGIN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_USRBIN_LOGIN
end_ifndef

begin_define
define|#
directive|define
name|_PATH_USRBIN_LOGIN
value|"/usr/bin/login"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PATH_USRBIN_LOGIN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_BIN_NEWGRP
end_ifndef

begin_define
define|#
directive|define
name|_PATH_BIN_NEWGRP
value|"/bin/newgrp"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATH_BIN_NEWGRP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_USRBIN_NEWGRP
end_ifndef

begin_define
define|#
directive|define
name|_PATH_USRBIN_NEWGRP
value|"/usr/bin/newgrp"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATH_USRBIN_NEWGRP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _h_pathnames */
end_comment

end_unit

