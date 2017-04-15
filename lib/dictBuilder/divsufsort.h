begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * divsufsort.h for libdivsufsort-lite  * Copyright (c) 2003-2008 Yuta Mori All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person  * obtaining a copy of this software and associated documentation  * files (the "Software"), to deal in the Software without  * restriction, including without limitation the rights to use,  * copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following  * conditions:  *  * The above copyright notice and this permission notice shall be  * included in all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES  * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT  * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,  * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DIVSUFSORT_H
end_ifndef

begin_define
define|#
directive|define
name|_DIVSUFSORT_H
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
comment|/*- Prototypes -*/
comment|/**  * Constructs the suffix array of a given string.  * @param T [0..n-1] The input string.  * @param SA [0..n-1] The output array of suffixes.  * @param n The length of the given string.  * @param openMP enables OpenMP optimization.  * @return 0 if no error occurred, -1 or -2 otherwise.  */
name|int
name|divsufsort
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|T
parameter_list|,
name|int
modifier|*
name|SA
parameter_list|,
name|int
name|n
parameter_list|,
name|int
name|openMP
parameter_list|)
function_decl|;
comment|/**  * Constructs the burrows-wheeler transformed string of a given string.  * @param T [0..n-1] The input string.  * @param U [0..n-1] The output string. (can be T)  * @param A [0..n-1] The temporary array. (can be NULL)  * @param n The length of the given string.  * @param num_indexes The length of secondary indexes array. (can be NULL)  * @param indexes The secondary indexes array. (can be NULL)  * @param openMP enables OpenMP optimization.  * @return The primary index if no error occurred, -1 or -2 otherwise.  */
name|int
name|divbwt
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|T
parameter_list|,
name|unsigned
name|char
modifier|*
name|U
parameter_list|,
name|int
modifier|*
name|A
parameter_list|,
name|int
name|n
parameter_list|,
name|unsigned
name|char
modifier|*
name|num_indexes
parameter_list|,
name|int
modifier|*
name|indexes
parameter_list|,
name|int
name|openMP
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
comment|/* _DIVSUFSORT_H */
end_comment

end_unit

