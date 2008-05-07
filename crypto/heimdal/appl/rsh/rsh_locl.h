begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 - 2004 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_comment
comment|/* $Id: rsh_locl.h 21553 2007-07-15 09:04:52Z lha $ */
end_comment

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
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
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
name|HAVE_SHADOW_H
end_ifdef

begin_include
include|#
directive|include
file|<shadow.h>
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
name|HAVE_LIMITS_H
end_ifdef

begin_include
include|#
directive|include
file|<limits.h>
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PARAM_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PATHS_H
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
file|<getarg.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|KRB4
end_ifdef

begin_include
include|#
directive|include
file|<krb.h>
end_include

begin_include
include|#
directive|include
file|<prot.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KRB5
end_ifdef

begin_include
include|#
directive|include
file|<krb5.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_struct_decl
struct_decl|struct
name|krb5_pk_identity
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|krb5_pk_cert
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ContentInfo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_krb5_krb_auth_data
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|krb5_dh_moduli
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|"crypto-headers.h"
end_include

begin_include
include|#
directive|include
file|<krb5-private.h>
end_include

begin_comment
comment|/* for _krb5_{get,put}_int */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KRB4
argument_list|)
operator|||
name|defined
argument_list|(
name|KRB5
argument_list|)
end_if

begin_include
include|#
directive|include
file|<kafs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
name|_PATH_DEFPATH
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DEFPATH
value|"/usr/bin:/bin"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"loginpaths.h"
end_include

begin_comment
comment|/*  *  */
end_comment

begin_enum
enum|enum
name|auth_method
block|{
name|AUTH_KRB4
block|,
name|AUTH_KRB5
block|,
name|AUTH_BROKEN
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|auth_method
name|auth_method
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|do_encrypt
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|KRB5
end_ifdef

begin_decl_stmt
specifier|extern
name|krb5_context
name|context
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|krb5_keyblock
modifier|*
name|keyblock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|krb5_crypto
name|crypto
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|key_usage
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|ivec_in
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|ivec_out
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|init_ivecs
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KRB4
end_ifdef

begin_decl_stmt
specifier|extern
name|des_key_schedule
name|schedule
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|des_cblock
name|iv
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KCMD_OLD_VERSION
value|"KCMDV0.1"
end_define

begin_define
define|#
directive|define
name|KCMD_NEW_VERSION
value|"KCMDV0.2"
end_define

begin_define
define|#
directive|define
name|USERNAME_SZ
value|16
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ARG_MAX
end_ifndef

begin_define
define|#
directive|define
name|ARG_MAX
value|8192
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RSH_BUFSIZ
value|(5 * 1024)
end_define

begin_comment
comment|/* MIT kcmd can't handle larger buffers */
end_comment

begin_define
define|#
directive|define
name|RSHD_BUFSIZ
value|(16 * 1024)
end_define

begin_comment
comment|/* Old maxize for Heimdal 0.4 rsh */
end_comment

begin_define
define|#
directive|define
name|PATH_RSH
value|BINDIR "/rsh"
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KRB4
argument_list|)
operator|||
name|defined
argument_list|(
name|KRB5
argument_list|)
end_if

begin_function_decl
name|ssize_t
name|do_read
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|do_write
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|do_write
parameter_list|(
name|F
parameter_list|,
name|B
parameter_list|,
name|L
parameter_list|,
name|I
parameter_list|)
value|write((F), (B), (L))
end_define

begin_define
define|#
directive|define
name|do_read
parameter_list|(
name|F
parameter_list|,
name|B
parameter_list|,
name|L
parameter_list|,
name|I
parameter_list|)
value|read((F), (B), (L))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

