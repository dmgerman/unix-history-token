begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: /home/hyperion/mu/christos/src/sys/tcsh-6.01/RCS/pathnames.h,v 3.4 1991/12/14 20:45:46 christos Exp $ */
end_comment

begin_comment
comment|/*  * pathnames.h: Location of things to find  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1980, 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
name|CMUCS
end_ifdef

begin_define
define|#
directive|define
name|_PATH_LOCAL
value|"/usr/cs/bin"
end_define

begin_else
else|#
directive|else
end_else

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

begin_define
define|#
directive|define
name|_PATH_USRBIN
value|"/usr/bin"
end_define

begin_define
define|#
directive|define
name|_PATH_USRUCB
value|"/usr/ucb"
end_define

begin_define
define|#
directive|define
name|_PATH_USRBSD
value|"/usr/bsd"
end_define

begin_define
define|#
directive|define
name|_PATH_BIN
value|"/bin"
end_define

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
name|__convex__
argument_list|)
operator|||
name|defined
argument_list|(
name|stellar
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PATH_DOTLOGIN
value|"/etc/login"
end_define

begin_define
define|#
directive|define
name|_PATH_DOTLOGOUT
value|"/etc/logout"
end_define

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
comment|/* convex || __convex__ || stellar */
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
end_if

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
comment|/* sgi || OREO || cray */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NeXT
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PATH_DOTLOGIN
value|"/etc/login.std"
end_define

begin_define
define|#
directive|define
name|_PATH_DOTLOGOUT
value|"/etc/logout.std"
end_define

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
comment|/* NeXT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DOTLOGIN
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DOTCSHRC
value|"/etc/csh.cshrc"
end_define

begin_define
define|#
directive|define
name|_PATH_DOTLOGIN
value|"/etc/csh.login"
end_define

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

begin_define
define|#
directive|define
name|_PATH_DEVNULL
value|"/dev/null"
end_define

begin_define
define|#
directive|define
name|_PATH_BSHELL
value|"/bin/sh"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

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

begin_define
define|#
directive|define
name|_PATH_LOGIN
value|"/bin/login"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NEWGRP
end_ifdef

begin_define
define|#
directive|define
name|_PATH_BIN_NEWGRP
value|"/bin/newgrp"
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _h_pathnames */
end_comment

end_unit

