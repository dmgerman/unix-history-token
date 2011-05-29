begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- absvdi2.c - Implement __absvdi2 -----------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is distributed under the University of Illinois Open Source  * License. See LICENSE.TXT for details.  *  *===----------------------------------------------------------------------===  *  * This file implements __absvdi2 for the compiler_rt library.  *  *===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/* Returns: absolute value */
end_comment

begin_comment
comment|/* Effects: aborts if abs(x)< 0 */
end_comment

begin_function
name|di_int
name|__absvdi2
parameter_list|(
name|di_int
name|a
parameter_list|)
block|{
specifier|const
name|int
name|N
init|=
call|(
name|int
call|)
argument_list|(
sizeof|sizeof
argument_list|(
name|di_int
argument_list|)
operator|*
name|CHAR_BIT
argument_list|)
decl_stmt|;
if|if
condition|(
name|a
operator|==
operator|(
operator|(
name|di_int
operator|)
literal|1
operator|<<
operator|(
name|N
operator|-
literal|1
operator|)
operator|)
condition|)
name|compilerrt_abort
argument_list|()
expr_stmt|;
specifier|const
name|di_int
name|t
init|=
name|a
operator|>>
operator|(
name|N
operator|-
literal|1
operator|)
decl_stmt|;
return|return
operator|(
name|a
operator|^
name|t
operator|)
operator|-
name|t
return|;
block|}
end_function

end_unit

