begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- parityti2.c - Implement __parityti2 -------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __parityti2 for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|"int_lib.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CRT_HAS_128BIT
end_ifdef

begin_comment
comment|/* Returns: 1 if number of bits is odd else returns 0 */
end_comment

begin_function_decl
name|si_int
name|__paritydi2
parameter_list|(
name|di_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|si_int
name|__parityti2
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
return|return
name|__paritydi2
argument_list|(
name|x
operator|.
name|s
operator|.
name|high
operator|^
name|x
operator|.
name|s
operator|.
name|low
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRT_HAS_128BIT */
end_comment

end_unit

