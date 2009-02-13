begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 - 2001 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of KTH nor the names of its contributors may be  *    used to endorse or promote products derived from this software without  *    specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY KTH AND ITS CONTRIBUTORS ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL KTH OR ITS CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
end_comment

begin_comment
comment|/* $Id: sia_locl.h,v 1.3 2001/09/13 01:15:34 assar Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__sia_locl_h__
end_ifndef

begin_define
define|#
directive|define
name|__sia_locl_h__
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
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<siad.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<roken.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|KRB5
end_ifdef

begin_define
define|#
directive|define
name|SIA_KRB5
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|KRB4
argument_list|)
end_elif

begin_define
define|#
directive|define
name|SIA_KRB4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SIA_KRB5
end_ifdef

begin_include
include|#
directive|include
file|<krb5.h>
end_include

begin_include
include|#
directive|include
file|<com_err.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SIA_KRB4
end_ifdef

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
file|<kadm.h>
end_include

begin_include
include|#
directive|include
file|<kadm_err.h>
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
file|<kafs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|POSIX_GETPWNAM_R
end_ifndef

begin_define
define|#
directive|define
name|getpwnam_r
value|posix_getpwnam_r
end_define

begin_define
define|#
directive|define
name|getpwuid_r
value|posix_getpwuid_r
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX_GETPWNAM_R */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUG
end_ifndef

begin_define
define|#
directive|define
name|SIA_DEBUG
parameter_list|(
name|X
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIA_DEBUG
parameter_list|(
name|X
parameter_list|)
value|SIALOG X
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|state
block|{
ifdef|#
directive|ifdef
name|SIA_KRB5
name|krb5_context
name|context
decl_stmt|;
name|krb5_auth_context
name|auth_context
decl_stmt|;
endif|#
directive|endif
name|char
name|ticket
index|[
name|MaxPathLen
index|]
decl_stmt|;
name|int
name|valid
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __sia_locl_h__ */
end_comment

end_unit

