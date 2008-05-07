begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2004 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_comment
comment|/*   * $Id: kadmin_locl.h 17580 2006-05-13 21:28:56Z lha $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ADMIN_LOCL_H__
end_ifndef

begin_define
define|#
directive|define
name|__ADMIN_LOCL_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
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
name|HAVE_NETINET_IN6_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in6.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET6_IN6_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet6/in6.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UTIL_H
end_ifdef

begin_include
include|#
directive|include
file|<util.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LIBUTIL_H
end_ifdef

begin_include
include|#
directive|include
file|<libutil.h>
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
name|HAVE_SYS_UN_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/un.h>
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

begin_include
include|#
directive|include
file|<roken.h>
end_include

begin_include
include|#
directive|include
file|<krb5.h>
end_include

begin_include
include|#
directive|include
file|<krb5_locl.h>
end_include

begin_include
include|#
directive|include
file|<hdb.h>
end_include

begin_include
include|#
directive|include
file|<hdb_err.h>
end_include

begin_include
include|#
directive|include
file|<hex.h>
end_include

begin_include
include|#
directive|include
file|<kadm5/admin.h>
end_include

begin_include
include|#
directive|include
file|<kadm5/private.h>
end_include

begin_include
include|#
directive|include
file|<kadm5/kadm5_err.h>
end_include

begin_include
include|#
directive|include
file|<parse_time.h>
end_include

begin_include
include|#
directive|include
file|<getarg.h>
end_include

begin_decl_stmt
specifier|extern
name|krb5_context
name|context
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|kadm_handle
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|ALLOC
end_undef

begin_define
define|#
directive|define
name|ALLOC
parameter_list|(
name|X
parameter_list|)
value|((X) = malloc(sizeof(*(X))))
end_define

begin_comment
comment|/* util.c */
end_comment

begin_function_decl
name|void
name|attributes2str
parameter_list|(
name|krb5_flags
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|str2attributes
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|krb5_flags
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|parse_attributes
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|krb5_flags
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|edit_attributes
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|krb5_flags
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|time_t2str
parameter_list|(
name|time_t
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

begin_function_decl
name|int
name|str2time_t
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|time_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|parse_timet
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|krb5_timestamp
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|edit_timet
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|krb5_timestamp
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|deltat2str
parameter_list|(
name|unsigned
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|str2deltat
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|krb5_deltat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|parse_deltat
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|krb5_deltat
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|edit_deltat
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|krb5_deltat
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|edit_entry
parameter_list|(
name|kadm5_principal_ent_t
parameter_list|,
name|int
modifier|*
parameter_list|,
name|kadm5_principal_ent_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_defaults
parameter_list|(
name|kadm5_principal_ent_t
parameter_list|,
name|int
modifier|*
parameter_list|,
name|kadm5_principal_ent_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_entry
parameter_list|(
name|krb5_context
parameter_list|,
name|kadm5_principal_ent_t
parameter_list|,
name|int
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|foreach_principal
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|krb5_principal
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|parse_des_key
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|krb5_key_data
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* server.c */
end_comment

begin_function_decl
name|krb5_error_code
name|kadmind_loop
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_auth_context
parameter_list|,
name|krb5_keytab
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* random_password.c */
end_comment

begin_function_decl
name|void
name|random_password
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* kadm_conn.c */
end_comment

begin_decl_stmt
specifier|extern
name|sig_atomic_t
name|term_flag
decl_stmt|,
name|doing_useful_work
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|parse_ports
parameter_list|(
name|krb5_context
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|start_server
parameter_list|(
name|krb5_context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* server.c */
end_comment

begin_function_decl
name|krb5_error_code
name|kadmind_loop
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_auth_context
parameter_list|,
name|krb5_keytab
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ADMIN_LOCL_H__ */
end_comment

end_unit

