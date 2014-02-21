begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_eol_private.h  * @brief Subversion's EOL functions - Internal routines  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_EOL_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_EOL_PRIVATE_H
end_define

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_include
include|#
directive|include
file|<apr_hash.h>
end_include

begin_include
include|#
directive|include
file|"svn_types.h"
end_include

begin_include
include|#
directive|include
file|"svn_error.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* __cplusplus */
comment|/* Constants used by various chunky string processing functions.  */
if|#
directive|if
name|APR_SIZEOF_VOIDP
operator|==
literal|8
define|#
directive|define
name|SVN__LOWER_7BITS_SET
value|0x7f7f7f7f7f7f7f7f
define|#
directive|define
name|SVN__BIT_7_SET
value|0x8080808080808080
define|#
directive|define
name|SVN__R_MASK
value|0x0a0a0a0a0a0a0a0a
define|#
directive|define
name|SVN__N_MASK
value|0x0d0d0d0d0d0d0d0d
else|#
directive|else
define|#
directive|define
name|SVN__LOWER_7BITS_SET
value|0x7f7f7f7f
define|#
directive|define
name|SVN__BIT_7_SET
value|0x80808080
define|#
directive|define
name|SVN__R_MASK
value|0x0a0a0a0a
define|#
directive|define
name|SVN__N_MASK
value|0x0d0d0d0d
endif|#
directive|endif
comment|/* Generic EOL character helper routines */
comment|/* Look for the start of an end-of-line sequence (i.e. CR or LF)  * in the array pointed to by @a buf , of length @a len.  * If such a byte is found, return the pointer to it, else return NULL.  *  * @since New in 1.7  */
name|char
modifier|*
name|svn_eol__find_eol_start
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|apr_size_t
name|len
parameter_list|)
function_decl|;
comment|/* Return the first eol marker found in buffer @a buf as a NUL-terminated  * string, or NULL if no eol marker is found. Do not examine more than  * @a len bytes in @a buf.  *  * If the last valid character of @a buf is the first byte of a  * potentially two-byte eol sequence, just return that single-character  * sequence, that is, assume @a buf represents a CR-only or LF-only file.  * This is correct for callers that pass an entire file at once, and is  * no more likely to be incorrect than correct for any caller that doesn't.  *  * The returned string is statically allocated, i.e. it is NOT a pointer  * to an address within @a buf.  *  * If an eol marker is found and @a eolp is not NULL, store in @a *eolp  * the address within @a buf of the first byte of the eol marker.  * This allows callers to tell whether there might be more than one eol  * sequence in @a buf, as well as detect two-byte eol sequences that  * span buffer boundaries.  *  * @since New in 1.7  */
specifier|const
name|char
modifier|*
name|svn_eol__detect_eol
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|apr_size_t
name|len
parameter_list|,
name|char
modifier|*
modifier|*
name|eolp
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVN_EOL_PRIVATE_H */
end_comment

end_unit

