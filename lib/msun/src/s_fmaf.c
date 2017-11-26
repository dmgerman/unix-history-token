begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause-FreeBSD  *  * Copyright (c) 2005-2011 David Schultz<das@FreeBSD.ORG>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|"math.h"
end_include

begin_include
include|#
directive|include
file|"math_private.h"
end_include

begin_comment
comment|/*  * Fused multiply-add: Compute x * y + z with a single rounding error.  *  * A double has more than twice as much precision than a float, so  * direct double-precision arithmetic suffices, except where double  * rounding occurs.  */
end_comment

begin_function
name|float
name|fmaf
parameter_list|(
name|float
name|x
parameter_list|,
name|float
name|y
parameter_list|,
name|float
name|z
parameter_list|)
block|{
name|double
name|xy
decl_stmt|,
name|result
decl_stmt|;
name|uint32_t
name|hr
decl_stmt|,
name|lr
decl_stmt|;
name|xy
operator|=
operator|(
name|double
operator|)
name|x
operator|*
name|y
expr_stmt|;
name|result
operator|=
name|xy
operator|+
name|z
expr_stmt|;
name|EXTRACT_WORDS
argument_list|(
name|hr
argument_list|,
name|lr
argument_list|,
name|result
argument_list|)
expr_stmt|;
comment|/* Common case: The double precision result is fine. */
if|if
condition|(
operator|(
name|lr
operator|&
literal|0x1fffffff
operator|)
operator|!=
literal|0x10000000
operator|||
comment|/* not a halfway case */
operator|(
name|hr
operator|&
literal|0x7ff00000
operator|)
operator|==
literal|0x7ff00000
operator|||
comment|/* NaN */
name|result
operator|-
name|xy
operator|==
name|z
operator|||
comment|/* exact */
name|fegetround
argument_list|()
operator|!=
name|FE_TONEAREST
condition|)
comment|/* not round-to-nearest */
return|return
operator|(
name|result
operator|)
return|;
comment|/* 	 * If result is inexact, and exactly halfway between two float values, 	 * we need to adjust the low-order bit in the direction of the error. 	 */
name|fesetround
argument_list|(
name|FE_TOWARDZERO
argument_list|)
expr_stmt|;
specifier|volatile
name|double
name|vxy
init|=
name|xy
decl_stmt|;
comment|/* XXX work around gcc CSE bug */
name|double
name|adjusted_result
init|=
name|vxy
operator|+
name|z
decl_stmt|;
name|fesetround
argument_list|(
name|FE_TONEAREST
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|==
name|adjusted_result
condition|)
name|SET_LOW_WORD
argument_list|(
name|adjusted_result
argument_list|,
name|lr
operator|+
literal|1
argument_list|)
expr_stmt|;
return|return
operator|(
name|adjusted_result
operator|)
return|;
block|}
end_function

end_unit

