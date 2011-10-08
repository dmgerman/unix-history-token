begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- ctzdi2.c - Implement __ctzdi2 -------------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __ctzdi2 for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"abi.h"
end_include

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_comment
comment|/* Returns: the number of trailing 0-bits  */
end_comment

begin_comment
comment|/* Precondition: a != 0 */
end_comment

begin_function
name|COMPILER_RT_ABI
name|si_int
name|__ctzdi2
parameter_list|(
name|di_int
name|a
parameter_list|)
block|{
name|dwords
name|x
decl_stmt|;
name|x
operator|.
name|all
operator|=
name|a
expr_stmt|;
specifier|const
name|si_int
name|f
init|=
operator|-
operator|(
name|x
operator|.
name|s
operator|.
name|low
operator|==
literal|0
operator|)
decl_stmt|;
return|return
name|__builtin_ctz
argument_list|(
operator|(
name|x
operator|.
name|s
operator|.
name|high
operator|&
name|f
operator|)
operator||
operator|(
name|x
operator|.
name|s
operator|.
name|low
operator|&
operator|~
name|f
operator|)
argument_list|)
operator|+
operator|(
name|f
operator|&
operator|(
call|(
name|si_int
call|)
argument_list|(
sizeof|sizeof
argument_list|(
name|si_int
argument_list|)
operator|*
name|CHAR_BIT
argument_list|)
operator|)
operator|)
return|;
block|}
end_function

end_unit

