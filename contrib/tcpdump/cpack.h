begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003, 2004 David Young.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of David Young may not be used to endorse or promote  *    products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY DAVID YOUNG ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL DAVID  * YOUNG BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPACK_H
end_ifndef

begin_define
define|#
directive|define
name|_CPACK_H
end_define

begin_struct
struct|struct
name|cpack_state
block|{
name|u_int8_t
modifier|*
name|c_buf
decl_stmt|;
name|u_int8_t
modifier|*
name|c_next
decl_stmt|;
name|size_t
name|c_len
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|cpack_init
parameter_list|(
name|struct
name|cpack_state
modifier|*
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cpack_uint8
parameter_list|(
name|struct
name|cpack_state
modifier|*
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cpack_uint16
parameter_list|(
name|struct
name|cpack_state
modifier|*
parameter_list|,
name|u_int16_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cpack_uint32
parameter_list|(
name|struct
name|cpack_state
modifier|*
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cpack_uint64
parameter_list|(
name|struct
name|cpack_state
modifier|*
parameter_list|,
name|u_int64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|cpack_int8
parameter_list|(
name|__s
parameter_list|,
name|__p
parameter_list|)
value|cpack_uint8((__s),  (u_int8_t*)(__p))
end_define

begin_define
define|#
directive|define
name|cpack_int16
parameter_list|(
name|__s
parameter_list|,
name|__p
parameter_list|)
value|cpack_uint16((__s), (u_int16_t*)(__p))
end_define

begin_define
define|#
directive|define
name|cpack_int32
parameter_list|(
name|__s
parameter_list|,
name|__p
parameter_list|)
value|cpack_uint32((__s), (u_int32_t*)(__p))
end_define

begin_define
define|#
directive|define
name|cpack_int64
parameter_list|(
name|__s
parameter_list|,
name|__p
parameter_list|)
value|cpack_uint64((__s), (u_int64_t*)(__p))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CPACK_H */
end_comment

end_unit

