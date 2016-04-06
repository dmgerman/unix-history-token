begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2013 Andrew Turner  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AEABI_VFP_H
end_ifndef

begin_define
define|#
directive|define
name|AEABI_VFP_H
end_define

begin_include
include|#
directive|include
file|<machine/acle-compat.h>
end_include

begin_comment
comment|/*  * ASM helper macros. These allow the functions to be changed depending on  * the endian-ness we are building for.  */
end_comment

begin_comment
comment|/* Allow the name of the function to be changed depending on the ABI */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ARM_PCS_VFP
end_ifndef

begin_define
define|#
directive|define
name|AEABI_ENTRY
parameter_list|(
name|x
parameter_list|)
value|ENTRY(__aeabi_ ## x ## _vfp)
end_define

begin_define
define|#
directive|define
name|AEABI_END
parameter_list|(
name|x
parameter_list|)
value|END(__aeabi_ ## x ## _vfp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AEABI_ENTRY
parameter_list|(
name|x
parameter_list|)
value|ENTRY(__aeabi_ ## x)
end_define

begin_define
define|#
directive|define
name|AEABI_END
parameter_list|(
name|x
parameter_list|)
value|END(__aeabi_ ## x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * These should be used when a function either takes, or returns a floating  * point falue. They will load the data from an ARM to a VFP register(s),  * or from a VFP to an ARM register  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__ARM_BIG_ENDIAN
end_ifdef

begin_define
define|#
directive|define
name|LOAD_DREG
parameter_list|(
name|vreg
parameter_list|,
name|reg0
parameter_list|,
name|reg1
parameter_list|)
value|vmov vreg, reg1, reg0
end_define

begin_define
define|#
directive|define
name|UNLOAD_DREG
parameter_list|(
name|reg0
parameter_list|,
name|reg1
parameter_list|,
name|vreg
parameter_list|)
value|vmov reg1, reg0, vreg
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOAD_DREG
parameter_list|(
name|vreg
parameter_list|,
name|reg0
parameter_list|,
name|reg1
parameter_list|)
value|vmov vreg, reg0, reg1
end_define

begin_define
define|#
directive|define
name|UNLOAD_DREG
parameter_list|(
name|reg0
parameter_list|,
name|reg1
parameter_list|,
name|vreg
parameter_list|)
value|vmov reg0, reg1, vreg
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LOAD_SREGS
parameter_list|(
name|vreg0
parameter_list|,
name|vreg1
parameter_list|,
name|reg0
parameter_list|,
name|reg1
parameter_list|)
value|vmov vreg0, vreg1, reg0, reg1
end_define

begin_define
define|#
directive|define
name|LOAD_SREG
parameter_list|(
name|vreg
parameter_list|,
name|reg
parameter_list|)
value|vmov vreg, reg
end_define

begin_define
define|#
directive|define
name|UNLOAD_SREG
parameter_list|(
name|reg
parameter_list|,
name|vreg
parameter_list|)
value|vmov reg, vreg
end_define

begin_comment
comment|/*  * C Helper macros  */
end_comment

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
end_if

begin_comment
comment|/*  * Generate a function that will either call into the VFP implementation,  * or the soft float version for a given __aeabi_* helper. The function  * will take a single argument of the type given by in_type.  */
end_comment

begin_define
define|#
directive|define
name|AEABI_FUNC
parameter_list|(
name|name
parameter_list|,
name|in_type
parameter_list|,
name|soft_func
parameter_list|)
define|\
value|__aeabi_ ## name(in_type a)					\ {								\ 	if (_libc_arm_fpu_present)				\ 		return __aeabi_ ## name ## _vfp(a);		\ 	else							\ 		return soft_func (a);				\ }
end_define

begin_comment
comment|/* As above, but takes two arguments of the same type */
end_comment

begin_define
define|#
directive|define
name|AEABI_FUNC2
parameter_list|(
name|name
parameter_list|,
name|in_type
parameter_list|,
name|soft_func
parameter_list|)
define|\
value|__aeabi_ ## name(in_type a, in_type b)				\ {								\ 	if (_libc_arm_fpu_present)				\ 		return __aeabi_ ## name ## _vfp(a, b);	\ 	else							\ 		return soft_func (a, b);			\ }
end_define

begin_comment
comment|/* As above, but with the soft float arguments reversed */
end_comment

begin_define
define|#
directive|define
name|AEABI_FUNC2_REV
parameter_list|(
name|name
parameter_list|,
name|in_type
parameter_list|,
name|soft_func
parameter_list|)
define|\
value|__aeabi_ ## name(in_type a, in_type b)				\ {								\ 	if (_libc_arm_fpu_present)				\ 		return __aeabi_ ## name ## _vfp(a, b);	\ 	else							\ 		return soft_func (b, a);			\ }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * Helper macros for when we are only able to use the softfloat  * version of these functions, i.e. on arm before armv6.  */
end_comment

begin_define
define|#
directive|define
name|AEABI_FUNC
parameter_list|(
name|name
parameter_list|,
name|in_type
parameter_list|,
name|soft_func
parameter_list|)
define|\
value|__aeabi_ ## name(in_type a)					\ {								\ 	return soft_func (a);					\ }
end_define

begin_comment
comment|/* As above, but takes two arguments of the same type */
end_comment

begin_define
define|#
directive|define
name|AEABI_FUNC2
parameter_list|(
name|name
parameter_list|,
name|in_type
parameter_list|,
name|soft_func
parameter_list|)
define|\
value|__aeabi_ ## name(in_type a, in_type b)				\ {								\ 	return soft_func (a, b);				\ }
end_define

begin_comment
comment|/* As above, but with the soft float arguments reversed */
end_comment

begin_define
define|#
directive|define
name|AEABI_FUNC2_REV
parameter_list|(
name|name
parameter_list|,
name|in_type
parameter_list|,
name|soft_func
parameter_list|)
define|\
value|__aeabi_ ## name(in_type a, in_type b)				\ {								\ 	return soft_func (b, a);				\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

