begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, PADL Software Pty Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of PADL Software nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY PADL SOFTWARE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL PADL SOFTWARE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SPNEGO_LOCL_H
end_ifndef

begin_define
define|#
directive|define
name|SPNEGO_LOCL_H
end_define

begin_include
include|#
directive|include
file|<config.h>
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

begin_include
include|#
directive|include
file|<roken.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PTHREAD_H
end_ifdef

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<gssapi.h>
end_include

begin_include
include|#
directive|include
file|<gssapi_krb5.h>
end_include

begin_include
include|#
directive|include
file|<gssapi_spnego.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
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
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
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

begin_include
include|#
directive|include
file|<heim_threads.h>
end_include

begin_include
include|#
directive|include
file|<asn1_err.h>
end_include

begin_include
include|#
directive|include
file|<gssapi_mech.h>
end_include

begin_include
include|#
directive|include
file|"spnego_asn1.h"
end_include

begin_include
include|#
directive|include
file|"utils.h"
end_include

begin_include
include|#
directive|include
file|<der.h>
end_include

begin_include
include|#
directive|include
file|<heimbase.h>
end_include

begin_define
define|#
directive|define
name|ALLOC
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|)
value|(X) = calloc((N), sizeof(*(X)))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|MechTypeList
name|initiator_mech_types
decl_stmt|;
name|gss_OID
name|preferred_mech_type
decl_stmt|;
name|gss_OID
name|negotiated_mech_type
decl_stmt|;
name|gss_ctx_id_t
name|negotiated_ctx_id
decl_stmt|;
name|OM_uint32
name|mech_flags
decl_stmt|;
name|OM_uint32
name|mech_time_rec
decl_stmt|;
name|gss_name_t
name|mech_src_name
decl_stmt|;
name|unsigned
name|int
name|open
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|local
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|require_mic
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|verified_mic
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|maybe_open
range|:
literal|1
decl_stmt|;
name|HEIMDAL_MUTEX
name|ctx_id_mutex
decl_stmt|;
name|gss_name_t
name|target_name
decl_stmt|;
name|u_char
name|oidbuf
index|[
literal|17
index|]
decl_stmt|;
name|size_t
name|oidlen
decl_stmt|;
block|}
typedef|*
name|gssspnego_ctx
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|gss_OID_desc
name|type
decl_stmt|;
name|gss_buffer_desc
name|value
decl_stmt|;
name|gss_name_t
name|mech
decl_stmt|;
block|}
typedef|*
name|spnego_name
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|gss_OID_desc
name|_gss_spnego_mskrb_mechanism_oid_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|gss_OID_desc
name|_gss_spnego_krb5_mechanism_oid_desc
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<spnego-private.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SPNEGO_LOCL_H */
end_comment

end_unit

