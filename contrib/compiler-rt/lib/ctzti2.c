begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- ctzti2.c - Implement __ctzti2 -------------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __ctzti2 for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
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
comment|/* Returns: the number of trailing 0-bits */
end_comment

begin_comment
comment|/* Precondition: a != 0 */
end_comment

begin_function
name|si_int
name|__ctzti2
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
specifier|const
name|di_int
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
name|__builtin_ctzll
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
operator|(
name|si_int
operator|)
name|f
operator|&
operator|(
call|(
name|si_int
call|)
argument_list|(
sizeof|sizeof
argument_list|(
name|di_int
argument_list|)
operator|*
name|CHAR_BIT
argument_list|)
operator|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

