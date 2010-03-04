begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: port-aix.h,v 1.31 2009/08/20 06:20:50 dtucker Exp $ */
end_comment

begin_comment
comment|/*  *  * Copyright (c) 2001 Gert Doering.  All rights reserved.  * Copyright (c) 2004,2005,2006 Darren Tucker.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SOCKET_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"buffer.h"
end_include

begin_comment
comment|/* These should be in the system headers but are not. */
end_comment

begin_function_decl
name|int
name|usrinfo
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_SETAUTHDB
argument_list|)
operator|&&
operator|(
name|HAVE_DECL_SETAUTHDB
operator|==
literal|0
operator|)
end_if

begin_function_decl
name|int
name|setauthdb
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
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
comment|/* these may or may not be in the headers depending on the version */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_AUTHENTICATE
argument_list|)
operator|&&
operator|(
name|HAVE_DECL_AUTHENTICATE
operator|==
literal|0
operator|)
end_if

begin_function_decl
name|int
name|authenticate
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_LOGINFAILED
argument_list|)
operator|&&
operator|(
name|HAVE_DECL_LOGINFAILED
operator|==
literal|0
operator|)
end_if

begin_function_decl
name|int
name|loginfailed
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_LOGINRESTRICTIONS
argument_list|)
operator|&&
operator|(
name|HAVE_DECL_LOGINRESTRICTIONS
operator|==
literal|0
operator|)
end_if

begin_function_decl
name|int
name|loginrestrictions
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_LOGINSUCCESS
argument_list|)
operator|&&
operator|(
name|HAVE_DECL_LOGINSUCCESS
operator|==
literal|0
operator|)
end_if

begin_function_decl
name|int
name|loginsuccess
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DECL_PASSWDEXPIRED
argument_list|)
operator|&&
operator|(
name|HAVE_DECL_PASSWDEXPIRED
operator|==
literal|0
operator|)
end_if

begin_function_decl
name|int
name|passwdexpired
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* for setpcred and friends */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_USERSEC_H
end_ifdef

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
name|CUSTOM_SYS_AUTH_ALLOWED_USER
value|1
end_define

begin_function_decl
name|int
name|sys_auth_allowed_user
parameter_list|(
name|struct
name|passwd
modifier|*
parameter_list|,
name|Buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CUSTOM_SYS_AUTH_RECORD_LOGIN
value|1
end_define

begin_function_decl
name|int
name|sys_auth_record_login
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|Buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CUSTOM_SYS_AUTH_GET_LASTLOGIN_MSG
end_define

begin_function_decl
name|char
modifier|*
name|sys_auth_get_lastlogin_msg
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|uid_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CUSTOM_FAILED_LOGIN
value|1
end_define

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AIX_GETNAMEINFO_HACK
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BROKEN_GETADDRINFO
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|getnameinfo
end_ifdef

begin_undef
undef|#
directive|undef
name|getnameinfo
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|sshaix_getnameinfo
parameter_list|(
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|getnameinfo
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|,
name|g
parameter_list|)
value|(sshaix_getnameinfo(a,b,c,d,e,f,g))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * We use getgrset in preference to multiple getgrent calls for efficiency  * plus it supports NIS and LDAP groups.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_GETGROUPLIST
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_GETGRSET
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_GETGROUPLIST
end_define

begin_define
define|#
directive|define
name|USE_GETGRSET
end_define

begin_function_decl
name|int
name|getgrouplist
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|gid_t
parameter_list|,
name|gid_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AIX */
end_comment

end_unit

