begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2009 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEIM_ECDSA_H
end_ifndef

begin_define
define|#
directive|define
name|HEIM_ECDSA_H
value|1
end_define

begin_define
define|#
directive|define
name|ECDSA_verify
value|hc_ECDSA_verify
end_define

begin_define
define|#
directive|define
name|ECDSA_sign
value|hc_ECDSA_sign
end_define

begin_define
define|#
directive|define
name|ECDSA_size
value|hc_ECDSA_size
end_define

begin_include
include|#
directive|include
file|<hcrypto/ec.h>
end_include

begin_function_decl
name|int
name|ECDSA_verify
parameter_list|(
name|int
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|EC_KEY
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ECDSA_sign
parameter_list|(
name|int
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
modifier|*
parameter_list|,
name|EC_KEY
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ECDSA_size
parameter_list|(
name|EC_KEY
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HEIM_ECDSA_H */
end_comment

end_unit

