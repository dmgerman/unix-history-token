begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- fixunssfsi.c - Implement __fixunssfsi -----------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file implements __fixunssfsi for the compiler_rt library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_define
define|#
directive|define
name|SINGLE_PRECISION
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

begin_function
name|COMPILER_RT_ABI
name|su_int
name|__fixunssfsi
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_EABI__
argument_list|)
end_if

begin_function
name|AEABI_RTABI
name|su_int
name|__aeabi_f2uiz
parameter_list|(
name|fp_t
name|a
parameter_list|)
block|{
return|return
name|__fixunssfsi
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

