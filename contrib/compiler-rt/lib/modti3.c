begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- modti3.c - Implement __modti3 -------------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __modti3 for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_if
if|#
directive|if
name|__x86_64
end_if

begin_function_decl
name|tu_int
name|__udivmodti4
parameter_list|(
name|tu_int
name|a
parameter_list|,
name|tu_int
name|b
parameter_list|,
name|tu_int
modifier|*
name|rem
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*Returns: a % b */
end_comment

begin_function
name|ti_int
name|__modti3
parameter_list|(
name|ti_int
name|a
parameter_list|,
name|ti_int
name|b
parameter_list|)
block|{
specifier|const
name|int
name|bits_in_tword_m1
init|=
call|(
name|int
call|)
argument_list|(
sizeof|sizeof
argument_list|(
name|ti_int
argument_list|)
operator|*
name|CHAR_BIT
argument_list|)
operator|-
literal|1
decl_stmt|;
name|ti_int
name|s
init|=
name|b
operator|>>
name|bits_in_tword_m1
decl_stmt|;
comment|/* s = b< 0 ? -1 : 0 */
name|b
operator|=
operator|(
name|b
operator|^
name|s
operator|)
operator|-
name|s
expr_stmt|;
comment|/* negate if s == -1 */
name|s
operator|=
name|a
operator|>>
name|bits_in_tword_m1
expr_stmt|;
comment|/* s = a< 0 ? -1 : 0 */
name|a
operator|=
operator|(
name|a
operator|^
name|s
operator|)
operator|-
name|s
expr_stmt|;
comment|/* negate if s == -1 */
name|ti_int
name|r
decl_stmt|;
name|__udivmodti4
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
operator|(
name|tu_int
operator|*
operator|)
operator|&
name|r
argument_list|)
expr_stmt|;
return|return
operator|(
name|r
operator|^
name|s
operator|)
operator|-
name|s
return|;
comment|/* negate if s == -1 */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

