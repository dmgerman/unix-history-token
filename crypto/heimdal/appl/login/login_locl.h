begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 - 2001 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_comment
comment|/* $Id: login_locl.h,v 1.22 2001/09/22 11:47:37 assar Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LOGIN_LOCL_H__
end_ifndef

begin_define
define|#
directive|define
name|__LOGIN_LOCL_H__
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
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UTMP_H
end_ifdef

begin_include
include|#
directive|include
file|<utmp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UTMPX_H
end_ifdef

begin_include
include|#
directive|include
file|<utmpx.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UDB_H
end_ifdef

begin_include
include|#
directive|include
file|<udb.h>
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_CATEGORY_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/category.h>
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
name|KRB4
end_ifdef

begin_include
include|#
directive|include
file|<krb.h>
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

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<kafs.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|OTP
end_ifdef

begin_include
include|#
directive|include
file|<otp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_OSFC2
end_ifdef

begin_define
define|#
directive|define
name|getargs
value|OSFgetargs
end_define

begin_include
include|#
directive|include
file|"/usr/include/prot.h"
end_include

begin_undef
undef|#
directive|undef
name|getargs
end_undef

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

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_WTMP
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|WTMP_FILE
end_ifdef

begin_define
define|#
directive|define
name|_PATH_WTMP
value|WTMP_FILE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PATH_WTMP
value|"/var/adm/wtmp"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_UTMP
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|UTMP_FILE
end_ifdef

begin_define
define|#
directive|define
name|_PATH_UTMP
value|UTMP_FILE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PATH_UTMP
value|"/var/adm/utmp"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
name|_PATH_LOGIN_CONF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_LOGIN_CONF
value|"/etc/login.conf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PATH_LOGIN_CONF */
end_comment

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

begin_struct_decl
struct_decl|struct
name|spwd
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|env
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|num_env
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"login_protos.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LOGIN_LOCL_H__ */
end_comment

end_unit

