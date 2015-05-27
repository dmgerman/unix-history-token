begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- negdi2.c - Implement __negdi2 -------------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __negdi2 for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_comment
comment|/* Returns: -a */
end_comment

begin_function
name|COMPILER_RT_ABI
name|di_int
name|__negdi2
parameter_list|(
name|di_int
name|a
parameter_list|)
block|{
comment|/* Note: this routine is here for API compatibility; any sane compiler      * should expand it inline.      */
return|return
operator|-
name|a
return|;
block|}
end_function

end_unit

