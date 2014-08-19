begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util/storage/lookup3.h - header file for hashing functions.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains header definitions for the hash functions we use.  * The hash functions are public domain (see lookup3.c).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTIL_STORAGE_LOOKUP3_H
end_ifndef

begin_define
define|#
directive|define
name|UTIL_STORAGE_LOOKUP3_H
end_define

begin_comment
comment|/**  * Hash key made of 4byte chunks.  * @param k: the key, an array of uint32_t values  * @param length: the length of the key, in uint32_ts  * @param initval: the previous hash, or an arbitrary value  * @return: hash value.  */
end_comment

begin_function_decl
name|uint32_t
name|hashword
parameter_list|(
specifier|const
name|uint32_t
modifier|*
name|k
parameter_list|,
name|size_t
name|length
parameter_list|,
name|uint32_t
name|initval
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Hash key data.  * @param k: the key, array of uint8_t  * @param length: the length of the key, in uint8_ts  * @param initval: the previous hash, or an arbitrary value  * @return: hash value.  */
end_comment

begin_function_decl
name|uint32_t
name|hashlittle
parameter_list|(
specifier|const
name|void
modifier|*
name|k
parameter_list|,
name|size_t
name|length
parameter_list|,
name|uint32_t
name|initval
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set the randomisation initial value, set this before threads start,  * and before hashing stuff (because it changes subsequent results).  * @param v: value  */
end_comment

begin_function_decl
name|void
name|hash_set_raninit
parameter_list|(
name|uint32_t
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTIL_STORAGE_LOOKUP3_H */
end_comment

end_unit

