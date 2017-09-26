begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- aeabi_div0.c - ARM Runtime ABI support routines for compiler-rt ---===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements the division by zero helper routines as specified by the  * Run-time ABI for the ARM Architecture.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_comment
comment|/*  * RTABI 4.3.2 - Division by zero  *  * The *div0 functions:  * - Return the value passed to them as a parameter  * - Or, return a fixed value defined by the execution environment (such as 0)  * - Or, raise a signal (often SIGFPE) or throw an exception, and do not return  *  * An application may provide its own implementations of the *div0 functions to  * for a particular behaviour from the *div and *divmod functions called out of  * line.  */
end_comment

begin_include
include|#
directive|include
file|"../int_lib.h"
end_include

begin_comment
comment|/* provide an unused declaration to pacify pendantic compilation */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|declaration
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_EABI__
argument_list|)
end_if

begin_decl_stmt
name|AEABI_RTABI
name|int
name|__attribute__
argument_list|(
operator|(
name|weak
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|visibility
argument_list|(
literal|"hidden"
argument_list|)
operator|)
argument_list|)
name|__aeabi_idiv0
argument_list|(
name|int
name|return_value
argument_list|)
block|{
return|return
name|return_value
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|AEABI_RTABI
name|long
name|long
name|__attribute__
argument_list|(
operator|(
name|weak
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|visibility
argument_list|(
literal|"hidden"
argument_list|)
operator|)
argument_list|)
name|__aeabi_ldiv0
argument_list|(
name|long
name|long
name|return_value
argument_list|)
block|{
return|return
name|return_value
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

