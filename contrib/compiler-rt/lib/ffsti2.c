begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- ffsti2.c - Implement __ffsti2 -------------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __ffsti2 for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
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

begin_comment
comment|/* Returns: the index of the least significant 1-bit in a, or  * the value zero if a is zero. The least significant bit is index one.  */
end_comment

begin_function
name|si_int
name|__ffsti2
parameter_list|(
name|ti_int
name|a
parameter_list|)
block|{
name|twords
name|x
decl_stmt|;
name|x
operator|.
name|all
operator|=
name|a
expr_stmt|;
if|if
condition|(
name|x
operator|.
name|s
operator|.
name|low
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|x
operator|.
name|s
operator|.
name|high
operator|==
literal|0
condition|)
return|return
literal|0
return|;
return|return
name|__builtin_ctzll
argument_list|(
name|x
operator|.
name|s
operator|.
name|high
argument_list|)
operator|+
operator|(
literal|1
operator|+
sizeof|sizeof
argument_list|(
name|di_int
argument_list|)
operator|*
name|CHAR_BIT
operator|)
return|;
block|}
return|return
name|__builtin_ctzll
argument_list|(
name|x
operator|.
name|s
operator|.
name|low
argument_list|)
operator|+
literal|1
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __x86_64 */
end_comment

end_unit

