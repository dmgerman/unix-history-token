begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$OpenBSD: frexp.c,v 1.2 2001/09/10 22:37:06 millert Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/ieee.h>
end_include

begin_comment
comment|/*  * Split the given value into a fraction in the range [0.5, 1.0) and  * an exponent, such that frac * (2^exp) == value.  If value is 0,  * return 0.  */
end_comment

begin_function
name|double
name|frexp
parameter_list|(
name|value
parameter_list|,
name|eptr
parameter_list|)
name|double
name|value
decl_stmt|;
name|int
modifier|*
name|eptr
decl_stmt|;
block|{
union|union
block|{
name|double
name|v
decl_stmt|;
name|struct
name|ieee_double
name|s
decl_stmt|;
block|}
name|u
union|;
if|if
condition|(
name|value
condition|)
block|{
comment|/* 		 * Fractions in [0.5..1.0) have an exponent of 2^-1. 		 * Leave Inf and NaN alone, however. 		 * WHAT ABOUT DENORMS? 		 */
name|u
operator|.
name|v
operator|=
name|value
expr_stmt|;
if|if
condition|(
name|u
operator|.
name|s
operator|.
name|dbl_exp
operator|!=
name|DBL_EXP_INFNAN
condition|)
block|{
operator|*
name|eptr
operator|=
name|u
operator|.
name|s
operator|.
name|dbl_exp
operator|-
operator|(
name|DBL_EXP_BIAS
operator|-
literal|1
operator|)
expr_stmt|;
name|u
operator|.
name|s
operator|.
name|dbl_exp
operator|=
name|DBL_EXP_BIAS
operator|-
literal|1
expr_stmt|;
block|}
return|return
operator|(
name|u
operator|.
name|v
operator|)
return|;
block|}
else|else
block|{
operator|*
name|eptr
operator|=
literal|0
expr_stmt|;
return|return
operator|(
operator|(
name|double
operator|)
literal|0
operator|)
return|;
block|}
block|}
end_function

end_unit

