begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, 1996, 1997, 1998 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id: kadm_locl.h,v 1.31 1999/12/02 16:58:36 joda Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"protos.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TIME_WITH_SYS_TIME
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_SYS_TIME_H
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_STAT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SELECT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FCNTL_H
end_ifdef

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_RESOURCE_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_RESOURCE_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_WAIT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PWD_H
end_ifdef

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IN_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETDB_H
end_ifdef

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ARPA_INET_H
end_ifdef

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYSLOG_H
end_ifdef

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SOCKS
end_ifdef

begin_include
include|#
directive|include
file|<socks.h>
end_include

begin_comment
comment|/* This doesn't belong here. */
end_comment

begin_function_decl
name|struct
name|tm
modifier|*
name|localtime
parameter_list|(
specifier|const
name|time_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|gethostbyname
parameter_list|(
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

begin_include
include|#
directive|include
file|<roken.h>
end_include

begin_include
include|#
directive|include
file|<com_err.h>
end_include

begin_include
include|#
directive|include
file|<sl.h>
end_include

begin_include
include|#
directive|include
file|<openssl/des.h>
end_include

begin_include
include|#
directive|include
file|<krb.h>
end_include

begin_include
include|#
directive|include
file|<krb_err.h>
end_include

begin_include
include|#
directive|include
file|<krb_db.h>
end_include

begin_include
include|#
directive|include
file|<kadm.h>
end_include

begin_include
include|#
directive|include
file|<kadm_err.h>
end_include

begin_include
include|#
directive|include
file|<acl.h>
end_include

begin_include
include|#
directive|include
file|<krb_log.h>
end_include

begin_include
include|#
directive|include
file|"kadm_server.h"
end_include

begin_include
include|#
directive|include
file|"pw_check.h"
end_include

begin_comment
comment|/* from libacl */
end_comment

begin_comment
comment|/* int acl_check(char *acl, char *principal); */
end_comment

begin_comment
comment|/* GLOBALS */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|acldir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Kadm_Server
name|server_parm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Utils */
end_comment

begin_function_decl
name|int
name|kadm_change
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
name|des_cblock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kadm_add_entry
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
name|Kadm_vals
modifier|*
parameter_list|,
name|Kadm_vals
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kadm_mod_entry
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
name|Kadm_vals
modifier|*
parameter_list|,
name|Kadm_vals
modifier|*
parameter_list|,
name|Kadm_vals
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kadm_get_entry
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
name|Kadm_vals
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|Kadm_vals
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kadm_delete_entry
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
name|Kadm_vals
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kadm_ser_cpw
parameter_list|(
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|AUTH_DAT
modifier|*
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kadm_ser_add
parameter_list|(
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|AUTH_DAT
modifier|*
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kadm_ser_mod
parameter_list|(
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|AUTH_DAT
modifier|*
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kadm_ser_get
parameter_list|(
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|AUTH_DAT
modifier|*
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kadm_ser_delete
parameter_list|(
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|AUTH_DAT
modifier|*
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kadm_ser_init
parameter_list|(
name|int
name|inter
parameter_list|,
name|char
name|realm
index|[]
parameter_list|,
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kadm_ser_in
parameter_list|(
name|u_char
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_pw_new_pwd
parameter_list|(
name|char
modifier|*
name|pword
parameter_list|,
name|int
name|pwlen
parameter_list|,
name|krb_principal
modifier|*
name|pr
parameter_list|,
name|int
name|print_realm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* cracklib */
end_comment

begin_function_decl
name|char
modifier|*
name|FascistCheck
parameter_list|(
name|char
modifier|*
name|password
parameter_list|,
name|char
modifier|*
name|path
parameter_list|,
name|char
modifier|*
modifier|*
name|strings
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|random_password
parameter_list|(
name|char
modifier|*
name|pw
parameter_list|,
name|size_t
name|len
parameter_list|,
name|u_int32_t
modifier|*
name|low
parameter_list|,
name|u_int32_t
modifier|*
name|high
parameter_list|)
function_decl|;
end_function_decl

end_unit

