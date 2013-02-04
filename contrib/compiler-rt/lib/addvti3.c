begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- addvti3.c - Implement __addvti3 -----------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __addvti3 for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
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
comment|/* Returns: a + b */
end_comment

begin_comment
comment|/* Effects: aborts if a + b overflows */
end_comment

begin_function
name|ti_int
name|__addvti3
parameter_list|(
name|ti_int
name|a
parameter_list|,
name|ti_int
name|b
parameter_list|)
block|{
name|ti_int
name|s
init|=
name|a
operator|+
name|b
decl_stmt|;
if|if
condition|(
name|b
operator|>=
literal|0
condition|)
block|{
if|if
condition|(
name|s
operator|<
name|a
condition|)
name|compilerrt_abort
argument_list|()
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|s
operator|>=
name|a
condition|)
name|compilerrt_abort
argument_list|()
expr_stmt|;
block|}
return|return
name|s
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

