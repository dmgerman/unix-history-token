begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * divsufsort64.h for libdivsufsort64  * Copyright (c) 2003-2008 Yuta Mori All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person  * obtaining a copy of this software and associated documentation  * files (the "Software"), to deal in the Software without  * restriction, including without limitation the rights to use,  * copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following  * conditions:  *  * The above copyright notice and this permission notice shall be  * included in all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES  * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT  * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,  * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DIVSUFSORT64_H
end_ifndef

begin_define
define|#
directive|define
name|_DIVSUFSORT64_H
value|1
end_define

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
include|#
directive|include
file|<inttypes.h>
ifndef|#
directive|ifndef
name|DIVSUFSORT_API
ifdef|#
directive|ifdef
name|DIVSUFSORT_BUILD_DLL
define|#
directive|define
name|DIVSUFSORT_API
else|#
directive|else
define|#
directive|define
name|DIVSUFSORT_API
endif|#
directive|endif
endif|#
directive|endif
comment|/*- Datatypes -*/
ifndef|#
directive|ifndef
name|SAUCHAR_T
define|#
directive|define
name|SAUCHAR_T
typedef|typedef
name|uint8_t
name|sauchar_t
typedef|;
endif|#
directive|endif
comment|/* SAUCHAR_T */
ifndef|#
directive|ifndef
name|SAINT_T
define|#
directive|define
name|SAINT_T
typedef|typedef
name|int32_t
name|saint_t
typedef|;
endif|#
directive|endif
comment|/* SAINT_T */
ifndef|#
directive|ifndef
name|SAIDX64_T
define|#
directive|define
name|SAIDX64_T
typedef|typedef
name|int64_t
name|saidx64_t
typedef|;
endif|#
directive|endif
comment|/* SAIDX64_T */
ifndef|#
directive|ifndef
name|PRIdSAINT_T
define|#
directive|define
name|PRIdSAINT_T
value|PRId32
endif|#
directive|endif
comment|/* PRIdSAINT_T */
ifndef|#
directive|ifndef
name|PRIdSAIDX64_T
define|#
directive|define
name|PRIdSAIDX64_T
value|PRId64
endif|#
directive|endif
comment|/* PRIdSAIDX64_T */
comment|/*- Prototypes -*/
comment|/**  * Constructs the suffix array of a given string.  * @param T[0..n-1] The input string.  * @param SA[0..n-1] The output array of suffixes.  * @param n The length of the given string.  * @return 0 if no error occurred, -1 or -2 otherwise.  */
name|DIVSUFSORT_API
name|saint_t
name|divsufsort64
parameter_list|(
specifier|const
name|sauchar_t
modifier|*
name|T
parameter_list|,
name|saidx64_t
modifier|*
name|SA
parameter_list|,
name|saidx64_t
name|n
parameter_list|)
function_decl|;
comment|/**  * Constructs the burrows-wheeler transformed string of a given string.  * @param T[0..n-1] The input string.  * @param U[0..n-1] The output string. (can be T)  * @param A[0..n-1] The temporary array. (can be NULL)  * @param n The length of the given string.  * @return The primary index if no error occurred, -1 or -2 otherwise.  */
name|DIVSUFSORT_API
name|saidx64_t
name|divbwt64
parameter_list|(
specifier|const
name|sauchar_t
modifier|*
name|T
parameter_list|,
name|sauchar_t
modifier|*
name|U
parameter_list|,
name|saidx64_t
modifier|*
name|A
parameter_list|,
name|saidx64_t
name|n
parameter_list|)
function_decl|;
comment|/**  * Returns the version of the divsufsort library.  * @return The version number string.  */
name|DIVSUFSORT_API
specifier|const
name|char
modifier|*
name|divsufsort64_version
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Constructs the burrows-wheeler transformed string of a given string and suffix array.  * @param T[0..n-1] The input string.  * @param U[0..n-1] The output string. (can be T)  * @param SA[0..n-1] The suffix array. (can be NULL)  * @param n The length of the given string.  * @param idx The output primary index.  * @return 0 if no error occurred, -1 or -2 otherwise.  */
name|DIVSUFSORT_API
name|saint_t
name|bw_transform64
parameter_list|(
specifier|const
name|sauchar_t
modifier|*
name|T
parameter_list|,
name|sauchar_t
modifier|*
name|U
parameter_list|,
name|saidx64_t
modifier|*
name|SA
comment|/* can NULL */
parameter_list|,
name|saidx64_t
name|n
parameter_list|,
name|saidx64_t
modifier|*
name|idx
parameter_list|)
function_decl|;
comment|/**  * Inverse BW-transforms a given BWTed string.  * @param T[0..n-1] The input string.  * @param U[0..n-1] The output string. (can be T)  * @param A[0..n-1] The temporary array. (can be NULL)  * @param n The length of the given string.  * @param idx The primary index.  * @return 0 if no error occurred, -1 or -2 otherwise.  */
name|DIVSUFSORT_API
name|saint_t
name|inverse_bw_transform64
parameter_list|(
specifier|const
name|sauchar_t
modifier|*
name|T
parameter_list|,
name|sauchar_t
modifier|*
name|U
parameter_list|,
name|saidx64_t
modifier|*
name|A
comment|/* can NULL */
parameter_list|,
name|saidx64_t
name|n
parameter_list|,
name|saidx64_t
name|idx
parameter_list|)
function_decl|;
comment|/**  * Checks the correctness of a given suffix array.  * @param T[0..n-1] The input string.  * @param SA[0..n-1] The input suffix array.  * @param n The length of the given string.  * @param verbose The verbose mode.  * @return 0 if no error occurred.  */
name|DIVSUFSORT_API
name|saint_t
name|sufcheck64
parameter_list|(
specifier|const
name|sauchar_t
modifier|*
name|T
parameter_list|,
specifier|const
name|saidx64_t
modifier|*
name|SA
parameter_list|,
name|saidx64_t
name|n
parameter_list|,
name|saint_t
name|verbose
parameter_list|)
function_decl|;
comment|/**  * Search for the pattern P in the string T.  * @param T[0..Tsize-1] The input string.  * @param Tsize The length of the given string.  * @param P[0..Psize-1] The input pattern string.  * @param Psize The length of the given pattern string.  * @param SA[0..SAsize-1] The input suffix array.  * @param SAsize The length of the given suffix array.  * @param idx The output index.  * @return The count of matches if no error occurred, -1 otherwise.  */
name|DIVSUFSORT_API
name|saidx64_t
name|sa_search64
parameter_list|(
specifier|const
name|sauchar_t
modifier|*
name|T
parameter_list|,
name|saidx64_t
name|Tsize
parameter_list|,
specifier|const
name|sauchar_t
modifier|*
name|P
parameter_list|,
name|saidx64_t
name|Psize
parameter_list|,
specifier|const
name|saidx64_t
modifier|*
name|SA
parameter_list|,
name|saidx64_t
name|SAsize
parameter_list|,
name|saidx64_t
modifier|*
name|left
parameter_list|)
function_decl|;
comment|/**  * Search for the character c in the string T.  * @param T[0..Tsize-1] The input string.  * @param Tsize The length of the given string.  * @param SA[0..SAsize-1] The input suffix array.  * @param SAsize The length of the given suffix array.  * @param c The input character.  * @param idx The output index.  * @return The count of matches if no error occurred, -1 otherwise.  */
name|DIVSUFSORT_API
name|saidx64_t
name|sa_simplesearch64
parameter_list|(
specifier|const
name|sauchar_t
modifier|*
name|T
parameter_list|,
name|saidx64_t
name|Tsize
parameter_list|,
specifier|const
name|saidx64_t
modifier|*
name|SA
parameter_list|,
name|saidx64_t
name|SAsize
parameter_list|,
name|saint_t
name|c
parameter_list|,
name|saidx64_t
modifier|*
name|left
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_comment
comment|/* extern "C" */
end_comment

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
comment|/* _DIVSUFSORT64_H */
end_comment

end_unit

