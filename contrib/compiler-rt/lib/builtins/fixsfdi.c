begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- fixsfdi.c - Implement __fixsfdi -----------------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  */
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

begin_function_decl
name|COMPILER_RT_ABI
name|du_int
name|__fixunssfdi
parameter_list|(
name|float
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|COMPILER_RT_ABI
name|di_int
name|__fixsfdi
parameter_list|(
name|float
name|a
parameter_list|)
block|{
if|if
condition|(
name|a
operator|<
literal|0.0f
condition|)
block|{
return|return
operator|-
name|__fixunssfdi
argument_list|(
operator|-
name|a
argument_list|)
return|;
block|}
return|return
name|__fixunssfdi
argument_list|(
name|a
argument_list|)
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
name|di_int
name|fixint_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|du_int
name|fixuint_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"fp_fixint_impl.inc"
end_include

begin_function
name|COMPILER_RT_ABI
name|di_int
name|__fixsfdi
parameter_list|(
name|fp_t
name|a
parameter_list|)
block|{
return|return
name|__fixint
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
name|di_int
if|#
directive|if
name|defined
argument_list|(
name|__SOFT_FP__
argument_list|)
name|__aeabi_f2lz
parameter_list|(
name|fp_t
name|a
parameter_list|)
block|{
else|#
directive|else
name|__aeabi_f2lz
argument_list|(
argument|float a
argument_list|)
block|{
endif|#
directive|endif
return|return
name|__fixsfdi
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

