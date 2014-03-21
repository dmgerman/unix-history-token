begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- powitf2.cpp - Implement __powitf2 ---------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __powitf2 for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_if
if|#
directive|if
name|_ARCH_PPC
end_if

begin_comment
comment|/* Returns: a ^ b */
end_comment

begin_function
name|long
name|double
name|__powitf2
parameter_list|(
name|long
name|double
name|a
parameter_list|,
name|si_int
name|b
parameter_list|)
block|{
specifier|const
name|int
name|recip
init|=
name|b
operator|<
literal|0
decl_stmt|;
name|long
name|double
name|r
init|=
literal|1
decl_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
if|if
condition|(
name|b
operator|&
literal|1
condition|)
name|r
operator|*=
name|a
expr_stmt|;
name|b
operator|/=
literal|2
expr_stmt|;
if|if
condition|(
name|b
operator|==
literal|0
condition|)
break|break;
name|a
operator|*=
name|a
expr_stmt|;
block|}
return|return
name|recip
condition|?
literal|1
operator|/
name|r
else|:
name|r
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

