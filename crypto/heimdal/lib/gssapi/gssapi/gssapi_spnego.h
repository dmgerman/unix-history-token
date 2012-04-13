begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 - 2006 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GSSAPI_SPNEGO_H_
end_ifndef

begin_define
define|#
directive|define
name|GSSAPI_SPNEGO_H_
end_define

begin_include
include|#
directive|include
file|<gssapi.h>
end_include

begin_decl_stmt
name|GSSAPI_CPP_START
comment|/*  * RFC2478, SPNEGO:  *  The security mechanism of the initial  *  negotiation token is identified by the Object Identifier  *  iso.org.dod.internet.security.mechanism.snego (1.3.6.1.5.5.2).  */
specifier|extern
name|GSSAPI_LIB_VARIABLE
name|gss_OID_desc
name|__gss_spnego_mechanism_oid_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GSS_SPNEGO_MECHANISM
value|(&__gss_spnego_mechanism_oid_desc)
end_define

begin_define
define|#
directive|define
name|gss_mech_spnego
value|GSS_SPNEGO_MECHANISM
end_define

begin_macro
name|GSSAPI_CPP_END
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GSSAPI_SPNEGO_H_ */
end_comment

end_unit

