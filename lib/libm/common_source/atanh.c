begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)atanh.c	8.1 (Berkeley) 6/4/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/* ATANH(X)  * RETURN THE HYPERBOLIC ARC TANGENT OF X  * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)  * CODED IN C BY K.C. NG, 1/8/85;  * REVISED BY K.C. NG on 2/7/85, 3/7/85, 8/18/85.  *  * Required kernel function:  *	log1p(x) 	...return log(1+x)  *  * Method :  *	Return  *                          1              2x                          x  *		atanh(x) = --- * log(1 + -------) = 0.5 * log1p(2 * --------)  *                          2             1 - x                      1 - x  *  * Special cases:  *	atanh(x) is NaN if |x|> 1 with signal;  *	atanh(NaN) is that NaN with no signal;  *	atanh(+-1) is +-INF with signal.  *  * Accuracy:  *	atanh(x) returns the exact hyperbolic arc tangent of x nearly rounded.  *	In a test run with 512,000 random arguments on a VAX, the maximum  *	observed error was 1.87 ulps (units in the last place) at  *	x= -3.8962076028810414000e-03.  */
end_comment

begin_include
include|#
directive|include
file|"mathimpl.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
end_if

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(vax)||defined(tahoe) */
end_comment

begin_function
name|double
name|atanh
parameter_list|(
name|x
parameter_list|)
name|double
name|x
decl_stmt|;
block|{
name|double
name|z
decl_stmt|;
name|z
operator|=
name|copysign
argument_list|(
literal|0.5
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|x
operator|=
name|copysign
argument_list|(
name|x
argument_list|,
literal|1.0
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
if|if
condition|(
name|x
operator|==
literal|1.0
condition|)
block|{
return|return
operator|(
name|copysign
argument_list|(
literal|1.0
argument_list|,
name|z
argument_list|)
operator|*
name|infnan
argument_list|(
name|ERANGE
argument_list|)
operator|)
return|;
comment|/* sign(x)*INF */
block|}
endif|#
directive|endif
comment|/* defined(vax)||defined(tahoe) */
name|x
operator|=
name|x
operator|/
operator|(
literal|1.0
operator|-
name|x
operator|)
expr_stmt|;
return|return
operator|(
name|z
operator|*
name|log1p
argument_list|(
name|x
operator|+
name|x
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

