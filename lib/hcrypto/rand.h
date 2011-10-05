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
name|_HEIM_RAND_H
end_ifndef

begin_define
define|#
directive|define
name|_HEIM_RAND_H
value|1
end_define

begin_typedef
typedef|typedef
name|struct
name|RAND_METHOD
name|RAND_METHOD
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<hcrypto/engine.h>
end_include

begin_comment
comment|/* symbol renaming */
end_comment

begin_define
define|#
directive|define
name|RAND_bytes
value|hc_RAND_bytes
end_define

begin_define
define|#
directive|define
name|RAND_pseudo_bytes
value|hc_RAND_pseudo_bytes
end_define

begin_define
define|#
directive|define
name|RAND_seed
value|hc_RAND_seed
end_define

begin_define
define|#
directive|define
name|RAND_cleanup
value|hc_RAND_cleanup
end_define

begin_define
define|#
directive|define
name|RAND_add
value|hc_RAND_add
end_define

begin_define
define|#
directive|define
name|RAND_set_rand_method
value|hc_RAND_set_rand_method
end_define

begin_define
define|#
directive|define
name|RAND_get_rand_method
value|hc_RAND_get_rand_method
end_define

begin_define
define|#
directive|define
name|RAND_set_rand_engine
value|hc_RAND_set_rand_engine
end_define

begin_define
define|#
directive|define
name|RAND_file_name
value|hc_RAND_file_name
end_define

begin_define
define|#
directive|define
name|RAND_load_file
value|hc_RAND_load_file
end_define

begin_define
define|#
directive|define
name|RAND_write_file
value|hc_RAND_write_file
end_define

begin_define
define|#
directive|define
name|RAND_status
value|hc_RAND_status
end_define

begin_define
define|#
directive|define
name|RAND_egd
value|hc_RAND_egd
end_define

begin_define
define|#
directive|define
name|RAND_egd_bytes
value|hc_RAND_egd_bytes
end_define

begin_define
define|#
directive|define
name|RAND_fortuna_method
value|hc_RAND_fortuna_method
end_define

begin_define
define|#
directive|define
name|RAND_egd_method
value|hc_RAND_egd_method
end_define

begin_define
define|#
directive|define
name|RAND_unix_method
value|hc_RAND_unix_method
end_define

begin_define
define|#
directive|define
name|RAND_w32crypto_method
value|hc_RAND_w32crypto_method
end_define

begin_comment
comment|/*  *  */
end_comment

begin_struct
struct|struct
name|RAND_METHOD
block|{
name|void
function_decl|(
modifier|*
name|seed
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|bytes
function_decl|)
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|cleanup
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|add
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|double
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pseudorand
function_decl|)
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|status
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *  */
end_comment

begin_function_decl
name|int
name|RAND_bytes
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|RAND_pseudo_bytes
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|RAND_seed
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|RAND_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|RAND_add
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|RAND_set_rand_method
parameter_list|(
specifier|const
name|RAND_METHOD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|RAND_METHOD
modifier|*
name|RAND_get_rand_method
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|RAND_set_rand_engine
parameter_list|(
name|ENGINE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|RAND_file_name
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|RAND_load_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|RAND_write_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|RAND_status
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|RAND_egd
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|RAND_egd_bytes
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|RAND_METHOD
modifier|*
name|RAND_fortuna_method
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|RAND_METHOD
modifier|*
name|RAND_unix_method
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|RAND_METHOD
modifier|*
name|RAND_egd_method
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|RAND_METHOD
modifier|*
name|RAND_w32crypto_method
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
comment|/* _HEIM_RAND_H */
end_comment

end_unit

