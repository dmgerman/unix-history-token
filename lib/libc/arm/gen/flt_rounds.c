begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Ian Lepore<freebsd@damnhippie.dyndns.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<fenv.h>
end_include

begin_include
include|#
directive|include
file|<float.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__ARM_PCS_VFP
end_ifndef

begin_include
include|#
directive|include
file|"softfloat-for-gcc.h"
end_include

begin_include
include|#
directive|include
file|"milieu.h"
end_include

begin_include
include|#
directive|include
file|"softfloat.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|__flt_rounds
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|mode
decl_stmt|;
ifndef|#
directive|ifndef
name|__ARM_PCS_VFP
comment|/* 	 * Translate our rounding modes to the unnamed 	 * manifest constants required by C99 et. al. 	 */
name|mode
operator|=
name|__softfloat_float_rounding_mode
expr_stmt|;
else|#
directive|else
comment|/* __ARM_PCS_VFP */
comment|/* 	 * Read the floating-point status and control register 	 */
asm|__asm __volatile("vmrs %0, fpscr" : "=&r"(mode));
name|mode
operator|&=
name|_ROUND_MASK
expr_stmt|;
endif|#
directive|endif
comment|/* __ARM_PCS_VFP */
switch|switch
condition|(
name|mode
condition|)
block|{
case|case
name|FE_TOWARDZERO
case|:
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|FE_TONEAREST
case|:
return|return
operator|(
literal|1
operator|)
return|;
case|case
name|FE_UPWARD
case|:
return|return
operator|(
literal|2
operator|)
return|;
case|case
name|FE_DOWNWARD
case|:
return|return
operator|(
literal|3
operator|)
return|;
block|}
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

end_unit

