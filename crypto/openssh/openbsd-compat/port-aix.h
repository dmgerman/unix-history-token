begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: port-aix.h,v 1.19 2004/02/10 04:27:35 dtucker Exp $ */
end_comment

begin_comment
comment|/*  *  * Copyright (c) 2001 Gert Doering.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_AIXAUTHENTICATE
end_ifdef

begin_include
include|#
directive|include
file|<login.h>
end_include

begin_include
include|#
directive|include
file|<userpw.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYS_AUDIT_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|AIX_LOGINFAILED_4ARG
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/audit.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<usersec.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some versions define r_type in the above headers, which causes a conflict */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|r_type
end_ifdef

begin_undef
undef|#
directive|undef
name|r_type
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIX 4.2.x doesn't have nanosleep but does have nsleep which is equivalent */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_NANOSLEEP
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_NSLEEP
argument_list|)
end_if

begin_define
define|#
directive|define
name|nanosleep
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|nsleep(a,b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For struct timespec on AIX 4.2.x */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TIMERS_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/timers.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * According to the setauthdb man page, AIX password registries must be 15  * chars or less plus terminating NUL.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SETAUTHDB
end_ifdef

begin_define
define|#
directive|define
name|REGISTRY_SIZE
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|aix_usrinfo
parameter_list|(
name|struct
name|passwd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_AIXAUTHENTICATE
end_ifdef

begin_define
define|#
directive|define
name|CUSTOM_SYS_AUTH_PASSWD
value|1
end_define

begin_define
define|#
directive|define
name|CUSTOM_FAILED_LOGIN
value|1
end_define

begin_function_decl
name|void
name|record_failed_login
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|aix_setauthdb
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aix_restoreauthdb
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aix_remove_embedded_newlines
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AIX */
end_comment

end_unit

