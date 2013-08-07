begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_string_private.h  * @brief Non-public string utility functions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_STRING_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_STRING_PRIVATE_H
end_define

begin_include
include|#
directive|include
file|"svn_string.h"
end_include

begin_comment
comment|/* for svn_boolean_t, svn_error_t */
end_comment

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
comment|/**  * @defgroup svn_string String handling  * @{  */
comment|/** Private functions.  *  * @defgroup svn_string_private Private functions  * @{  */
comment|/** A self-contained memory buffer of known size.  *  * Intended to be used where a single variable-sized buffer is needed  * within an iteration, a scratch pool is available and we want to  * avoid the cost of creating another pool just for the iteration.  */
typedef|typedef
struct|struct
name|svn_membuf_t
block|{
comment|/** The a pool from which this buffer was originally allocated, and is not    * necessarily specific to this buffer.  This is used only for allocating    * more memory from when the buffer needs to grow.    */
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
comment|/** pointer to the memory */
name|void
modifier|*
name|data
decl_stmt|;
comment|/** total size of buffer allocated */
name|apr_size_t
name|size
decl_stmt|;
block|}
name|svn_membuf_t
typedef|;
comment|/* Initialize a memory buffer of the given size */
name|void
name|svn_membuf__create
parameter_list|(
name|svn_membuf_t
modifier|*
name|membuf
parameter_list|,
name|apr_size_t
name|size
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Ensure that the given memory buffer has at least the given size */
name|void
name|svn_membuf__ensure
parameter_list|(
name|svn_membuf_t
modifier|*
name|membuf
parameter_list|,
name|apr_size_t
name|size
parameter_list|)
function_decl|;
comment|/* Resize the given memory buffer, preserving its contents. */
name|void
name|svn_membuf__resize
parameter_list|(
name|svn_membuf_t
modifier|*
name|membuf
parameter_list|,
name|apr_size_t
name|size
parameter_list|)
function_decl|;
comment|/* Zero-fill the given memory */
name|void
name|svn_membuf__zero
parameter_list|(
name|svn_membuf_t
modifier|*
name|membuf
parameter_list|)
function_decl|;
comment|/* Zero-fill the given memory buffer up to the smaller of SIZE and the    current buffer size. */
name|void
name|svn_membuf__nzero
parameter_list|(
name|svn_membuf_t
modifier|*
name|membuf
parameter_list|,
name|apr_size_t
name|size
parameter_list|)
function_decl|;
comment|/* Inline implementation of svn_membuf__zero.  * Note that PMEMBUF is evaluated only once.  */
define|#
directive|define
name|SVN_MEMBUF__ZERO
parameter_list|(
name|pmembuf
parameter_list|)
define|\
value|do                                             \     {                                            \       svn_membuf_t *const _m_b_f_ = (pmembuf);   \       memset(_m_b_f_->data, 0, _m_b_f_->size);   \     }                                            \   while(0)
comment|/* Inline implementation of svn_membuf__nzero  * Note that PMEMBUF and PSIZE are evaluated only once.  */
define|#
directive|define
name|SVN_MEMBUF__NZERO
parameter_list|(
name|pmembuf
parameter_list|,
name|psize
parameter_list|)
define|\
value|do                                             \     {                                            \       svn_membuf_t *const _m_b_f_ = (pmembuf);   \       const apr_size_t _s_z_ = (psize);          \       if (_s_z_> _m_b_f_->size)                 \         memset(_m_b_f_->data, 0, _m_b_f_->size); \       else                                       \         memset(_m_b_f_->data, 0, _s_z_);         \     }                                            \   while(0)
ifndef|#
directive|ifndef
name|SVN_DEBUG
comment|/* In non-debug mode, just use these inlie replacements */
define|#
directive|define
name|svn_membuf__zero
parameter_list|(
name|B
parameter_list|)
value|SVN_MEMBUF__ZERO((B))
define|#
directive|define
name|svn_membuf__nzero
parameter_list|(
name|B
parameter_list|,
name|S
parameter_list|)
value|SVN_MEMBUF__NZERO((B), (S))
endif|#
directive|endif
comment|/** Returns the #svn_string_t information contained in the data and  * len members of @a strbuf. This is effectively a typecast, converting  * @a strbuf into an #svn_string_t. This first will become invalid and must  * not be accessed after this function returned.  */
name|svn_string_t
modifier|*
name|svn_stringbuf__morph_into_string
parameter_list|(
name|svn_stringbuf_t
modifier|*
name|strbuf
parameter_list|)
function_decl|;
comment|/** Like apr_strtoff but provided here for backward compatibility  *  with APR 0.9 */
name|apr_status_t
name|svn__strtoff
parameter_list|(
name|apr_off_t
modifier|*
name|offset
parameter_list|,
specifier|const
name|char
modifier|*
name|buf
parameter_list|,
name|char
modifier|*
modifier|*
name|end
parameter_list|,
name|int
name|base
parameter_list|)
function_decl|;
comment|/** Number of chars needed to represent signed (19 places + sign + NUL) or  * unsigned (20 places + NUL) integers as strings.  */
define|#
directive|define
name|SVN_INT64_BUFFER_SIZE
value|21
comment|/** Writes the @a number as string into @a dest. The latter must provide  * space for at least #SVN_INT64_BUFFER_SIZE characters. Returns the number  * chars written excluding the terminating NUL.  */
name|apr_size_t
name|svn__ui64toa
parameter_list|(
name|char
modifier|*
name|dest
parameter_list|,
name|apr_uint64_t
name|number
parameter_list|)
function_decl|;
comment|/** Writes the @a number as string into @a dest. The latter must provide  * space for at least #SVN_INT64_BUFFER_SIZE characters. Returns the number  * chars written excluding the terminating NUL.  */
name|apr_size_t
name|svn__i64toa
parameter_list|(
name|char
modifier|*
name|dest
parameter_list|,
name|apr_int64_t
name|number
parameter_list|)
function_decl|;
comment|/** Returns a decimal string for @a number allocated in @a pool.  Put in  * the @a seperator at each third place.  */
name|char
modifier|*
name|svn__ui64toa_sep
parameter_list|(
name|apr_uint64_t
name|number
parameter_list|,
name|char
name|seperator
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Returns a decimal string for @a number allocated in @a pool.  Put in  * the @a seperator at each third place.  */
name|char
modifier|*
name|svn__i64toa_sep
parameter_list|(
name|apr_int64_t
name|number
parameter_list|,
name|char
name|seperator
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Computes the similarity score of STRA and STRB. Returns the ratio  * of the length of their longest common subsequence and the average  * length of the strings, normalized to the range [0..1000].  * The result is equivalent to Python's  *  *   difflib.SequenceMatcher.ratio  *  * Optionally sets *RLCS to the length of the longest common  * subsequence of STRA and STRB. Using BUFFER for temporary storage,  * requires memory proportional to the length of the shorter string.  *  * The LCS algorithm used is described in, e.g.,  *  *   http://en.wikipedia.org/wiki/Longest_common_subsequence_problem  *  * Q: Why another LCS when we already have one in libsvn_diff?  * A: svn_diff__lcs is too heavyweight and too generic for the  *    purposes of similarity testing. Whilst it would be possible  *    to use a character-based tokenizer with it, we really only need  *    the *length* of the LCS for the similarity score, not all the  *    other information that svn_diff__lcs produces in order to  *    make printing diffs possible.  *  * Q: Is there a limit on the length of the string parameters?  * A: Only available memory. But note that the LCS algorithm used  *    has O(strlen(STRA) * strlen(STRB)) worst-case performance,  *    so do keep a rein on your enthusiasm.  */
name|unsigned
name|int
name|svn_cstring__similarity
parameter_list|(
specifier|const
name|char
modifier|*
name|stra
parameter_list|,
specifier|const
name|char
modifier|*
name|strb
parameter_list|,
name|svn_membuf_t
modifier|*
name|buffer
parameter_list|,
name|apr_size_t
modifier|*
name|rlcs
parameter_list|)
function_decl|;
comment|/**  * Like svn_cstring__similarity, but accepts svn_string_t's instead  * of NUL-terminated character strings.  */
name|unsigned
name|int
name|svn_string__similarity
parameter_list|(
specifier|const
name|svn_string_t
modifier|*
name|stringa
parameter_list|,
specifier|const
name|svn_string_t
modifier|*
name|stringb
parameter_list|,
name|svn_membuf_t
modifier|*
name|buffer
parameter_list|,
name|apr_size_t
modifier|*
name|rlcs
parameter_list|)
function_decl|;
comment|/** @} */
comment|/** @} */
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
comment|/* SVN_STRING_PRIVATE_H */
end_comment

end_unit

