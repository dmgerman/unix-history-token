begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003-2005 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HEIM_ANY_H__
end_ifndef

begin_define
define|#
directive|define
name|__HEIM_ANY_H__
value|1
end_define

begin_function_decl
name|int
name|encode_heim_any
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|heim_any
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|decode_heim_any
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|heim_any
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_heim_any
parameter_list|(
name|heim_any
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|length_heim_any
parameter_list|(
specifier|const
name|heim_any
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|copy_heim_any
parameter_list|(
specifier|const
name|heim_any
modifier|*
parameter_list|,
name|heim_any
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|encode_heim_any_set
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|heim_any_set
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|decode_heim_any_set
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|heim_any_set
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_heim_any_set
parameter_list|(
name|heim_any_set
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|length_heim_any_set
parameter_list|(
specifier|const
name|heim_any_set
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|copy_heim_any_set
parameter_list|(
specifier|const
name|heim_any_set
modifier|*
parameter_list|,
name|heim_any_set
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|heim_any_cmp
parameter_list|(
specifier|const
name|heim_any_set
modifier|*
parameter_list|,
specifier|const
name|heim_any_set
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __HEIM_ANY_H__ */
end_comment

end_unit

