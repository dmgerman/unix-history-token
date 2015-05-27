begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- fixunsdfsi.c - Implement __fixunsdfsi -----------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_define
define|#
directive|define
name|DOUBLE_PRECISION
end_define

begin_include
include|#
directive|include
file|"fp_lib.h"
end_include

begin_typedef
typedef|typedef
name|su_int
name|fixuint_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"fp_fixuint_impl.inc"
end_include

begin_macro
name|ARM_EABI_FNALIAS
argument_list|(
argument|d2uiz
argument_list|,
argument|fixunsdfsi
argument_list|)
end_macro

begin_function
name|COMPILER_RT_ABI
name|su_int
name|__fixunsdfsi
parameter_list|(
name|fp_t
name|a
parameter_list|)
block|{
return|return
name|__fixuint
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

end_unit

