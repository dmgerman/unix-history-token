begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- negvdi2.c - Implement __negvdi2 -----------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __negvdi2 for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_comment
comment|/* Returns: -a */
end_comment

begin_comment
comment|/* Effects: aborts if -a overflows */
end_comment

begin_function
name|COMPILER_RT_ABI
name|di_int
name|__negvdi2
parameter_list|(
name|di_int
name|a
parameter_list|)
block|{
specifier|const
name|di_int
name|MIN
init|=
operator|(
name|di_int
operator|)
literal|1
operator|<<
operator|(
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
operator|-
literal|1
operator|)
decl_stmt|;
if|if
condition|(
name|a
operator|==
name|MIN
condition|)
name|compilerrt_abort
argument_list|()
expr_stmt|;
return|return
operator|-
name|a
return|;
block|}
end_function

end_unit

