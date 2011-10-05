begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $Id$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HEIM_ENGINE_H
end_ifndef

begin_define
define|#
directive|define
name|_HEIM_ENGINE_H
value|1
end_define

begin_comment
comment|/* symbol renaming */
end_comment

begin_define
define|#
directive|define
name|ENGINE_add_conf_module
value|hc_ENGINE_add_conf_module
end_define

begin_define
define|#
directive|define
name|ENGINE_by_dso
value|hc_ENGINE_by_dso
end_define

begin_define
define|#
directive|define
name|ENGINE_by_id
value|hc_ENGINE_by_id
end_define

begin_define
define|#
directive|define
name|ENGINE_finish
value|hc_ENGINE_finish
end_define

begin_define
define|#
directive|define
name|ENGINE_get_DH
value|hc_ENGINE_get_DH
end_define

begin_define
define|#
directive|define
name|ENGINE_get_RSA
value|hc_ENGINE_get_RSA
end_define

begin_define
define|#
directive|define
name|ENGINE_get_RAND
value|hc_ENGINE_get_RAND
end_define

begin_define
define|#
directive|define
name|ENGINE_get_id
value|hc_ENGINE_get_id
end_define

begin_define
define|#
directive|define
name|ENGINE_get_name
value|hc_ENGINE_get_name
end_define

begin_define
define|#
directive|define
name|ENGINE_load_builtin_engines
value|hc_ENGINE_load_builtin_engines
end_define

begin_define
define|#
directive|define
name|ENGINE_set_DH
value|hc_ENGINE_set_DH
end_define

begin_define
define|#
directive|define
name|ENGINE_set_RSA
value|hc_ENGINE_set_RSA
end_define

begin_define
define|#
directive|define
name|ENGINE_set_id
value|hc_ENGINE_set_id
end_define

begin_define
define|#
directive|define
name|ENGINE_set_name
value|hc_ENGINE_set_name
end_define

begin_define
define|#
directive|define
name|ENGINE_set_destroy_function
value|hc_ENGINE_set_destroy_function
end_define

begin_define
define|#
directive|define
name|ENGINE_new
value|hc_ENGINE_new
end_define

begin_define
define|#
directive|define
name|ENGINE_free
value|hc_ENGINE_free
end_define

begin_define
define|#
directive|define
name|ENGINE_up_ref
value|hc_ENGINE_up_ref
end_define

begin_define
define|#
directive|define
name|ENGINE_get_default_DH
value|hc_ENGINE_get_default_DH
end_define

begin_define
define|#
directive|define
name|ENGINE_get_default_RSA
value|hc_ENGINE_get_default_RSA
end_define

begin_define
define|#
directive|define
name|ENGINE_set_default_DH
value|hc_ENGINE_set_default_DH
end_define

begin_define
define|#
directive|define
name|ENGINE_set_default_RSA
value|hc_ENGINE_set_default_RSA
end_define

begin_comment
comment|/*  *  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|hc_engine
name|ENGINE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NID_md2
value|0
end_define

begin_define
define|#
directive|define
name|NID_md4
value|1
end_define

begin_define
define|#
directive|define
name|NID_md5
value|2
end_define

begin_define
define|#
directive|define
name|NID_sha1
value|4
end_define

begin_define
define|#
directive|define
name|NID_sha256
value|5
end_define

begin_comment
comment|/*  *  */
end_comment

begin_include
include|#
directive|include
file|<hcrypto/rsa.h>
end_include

begin_include
include|#
directive|include
file|<hcrypto/dsa.h>
end_include

begin_include
include|#
directive|include
file|<hcrypto/dh.h>
end_include

begin_include
include|#
directive|include
file|<hcrypto/rand.h>
end_include

begin_define
define|#
directive|define
name|OPENSSL_DYNAMIC_VERSION
value|(unsigned long)0x00020000
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|openssl_bind_engine
function_decl|)
parameter_list|(
name|ENGINE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
function_decl|(
modifier|*
name|openssl_v_check
function_decl|)
parameter_list|(
name|unsigned
name|long
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|ENGINE
modifier|*
name|ENGINE_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ENGINE_free
parameter_list|(
name|ENGINE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ENGINE_add_conf_module
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ENGINE_load_builtin_engines
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ENGINE
modifier|*
name|ENGINE_by_id
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ENGINE
modifier|*
name|ENGINE_by_dso
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

begin_function_decl
name|int
name|ENGINE_finish
parameter_list|(
name|ENGINE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ENGINE_up_ref
parameter_list|(
name|ENGINE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ENGINE_set_id
parameter_list|(
name|ENGINE
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
name|ENGINE_set_name
parameter_list|(
name|ENGINE
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
name|ENGINE_set_RSA
parameter_list|(
name|ENGINE
modifier|*
parameter_list|,
specifier|const
name|RSA_METHOD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ENGINE_set_DH
parameter_list|(
name|ENGINE
modifier|*
parameter_list|,
specifier|const
name|DH_METHOD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ENGINE_set_destroy_function
parameter_list|(
name|ENGINE
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|ENGINE
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|ENGINE_get_id
parameter_list|(
specifier|const
name|ENGINE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|ENGINE_get_name
parameter_list|(
specifier|const
name|ENGINE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|RSA_METHOD
modifier|*
name|ENGINE_get_RSA
parameter_list|(
specifier|const
name|ENGINE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|DH_METHOD
modifier|*
name|ENGINE_get_DH
parameter_list|(
specifier|const
name|ENGINE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|RAND_METHOD
modifier|*
name|ENGINE_get_RAND
parameter_list|(
specifier|const
name|ENGINE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ENGINE_set_default_RSA
parameter_list|(
name|ENGINE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ENGINE
modifier|*
name|ENGINE_get_default_RSA
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ENGINE_set_default_DH
parameter_list|(
name|ENGINE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ENGINE
modifier|*
name|ENGINE_get_default_DH
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _HEIM_ENGINE_H */
end_comment

end_unit

