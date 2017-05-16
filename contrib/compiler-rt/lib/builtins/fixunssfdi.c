begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- fixunssfdi.c - Implement __fixunssfdi -----------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|__SOFT_FP__
end_ifndef

begin_comment
comment|/* Support for systems that have hardware floating-point; can set the invalid  * flag as a side-effect of computation.  */
end_comment

begin_function
name|COMPILER_RT_ABI
name|du_int
name|__fixunssfdi
parameter_list|(
name|float
name|a
parameter_list|)
block|{
if|if
condition|(
name|a
operator|<=
literal|0.0f
condition|)
return|return
literal|0
return|;
name|double
name|da
init|=
name|a
decl_stmt|;
name|su_int
name|high
init|=
name|da
operator|/
literal|4294967296.f
decl_stmt|;
comment|/* da / 0x1p32f; */
name|su_int
name|low
init|=
name|da
operator|-
operator|(
name|double
operator|)
name|high
operator|*
literal|4294967296.f
decl_stmt|;
comment|/* high * 0x1p32f; */
return|return
operator|(
operator|(
name|du_int
operator|)
name|high
operator|<<
literal|32
operator|)
operator||
name|low
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Support for systems that don't have hardware floating-point; there are no  * flags to set, and we don't want to code-gen to an unknown soft-float  * implementation.  */
end_comment

begin_typedef
typedef|typedef
name|du_int
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
name|du_int
name|__fixunssfdi
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

begin_endif
endif|#
directive|endif
end_endif

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
name|du_int
if|#
directive|if
name|defined
argument_list|(
name|__SOFT_FP__
argument_list|)
name|__aeabi_f2ulz
parameter_list|(
name|fp_t
name|a
parameter_list|)
block|{
else|#
directive|else
name|__aeabi_f2ulz
argument_list|(
argument|float a
argument_list|)
block|{
endif|#
directive|endif
return|return
name|__fixunssfdi
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

