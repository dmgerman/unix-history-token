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
literal|"@(#)acosh.c	8.1 (Berkeley) 6/4/93"
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
comment|/* ACOSH(X)  * RETURN THE INVERSE HYPERBOLIC COSINE OF X  * DOUBLE PRECISION (VAX D FORMAT 56 BITS, IEEE DOUBLE 53 BITS)  * CODED IN C BY K.C. NG, 2/16/85;  * REVISED BY K.C. NG on 3/6/85, 3/24/85, 4/16/85, 8/17/85.  *  * Required system supported functions :  *	sqrt(x)  *  * Required kernel function:  *	log1p(x) 		...return log(1+x)  *  * Method :  *	Based on  *		acosh(x) = log [ x + sqrt(x*x-1) ]  *	we have  *		acosh(x) := log1p(x)+ln2,	if (x> 1.0E20); else  *		acosh(x) := log1p( sqrt(x-1) * (sqrt(x-1) + sqrt(x+1)) ) .  *	These formulae avoid the over/underflow complication.  *  * Special cases:  *	acosh(x) is NaN with signal if x<1.  *	acosh(NaN) is NaN without signal.  *  * Accuracy:  *	acosh(x) returns the exact inverse hyperbolic cosine of x nearly  *	rounded. In a test run with 512,000 random arguments on a VAX, the  *	maximum observed error was 3.30 ulps (units of the last place) at  *	x=1.0070493753568216 .  *  * Constants:  * The hexadecimal values are the intended ones for the following constants.  * The decimal values may be used, provided that the compiler will convert  * from decimal to binary accurately enough to produce the hexadecimal values  * shown.  */
end_comment

begin_include
include|#
directive|include
file|"mathimpl.h"
end_include

begin_macro
name|vc
argument_list|(
argument|ln2hi
argument_list|,
literal|6.9314718055829871446E
argument|-
literal|1
argument_list|,
literal|7217
argument_list|,
literal|4031
argument_list|,
literal|0000
argument_list|,
argument|f7d0
argument_list|,
literal|0
argument_list|,
argument|.B17217F7D00000
argument_list|)
end_macro

begin_macro
name|vc
argument_list|(
argument|ln2lo
argument_list|,
literal|1.6465949582897081279E
argument|-
literal|12
argument_list|,
argument|bcd5
argument_list|,
literal|2ce7
argument_list|,
argument|d9cc
argument_list|,
argument|e4f1
argument_list|,
argument|-
literal|39
argument_list|,
argument|.E7BCD5E4F1D9CC
argument_list|)
end_macro

begin_macro
name|ic
argument_list|(
argument|ln2hi
argument_list|,
literal|6.9314718036912381649E
argument|-
literal|1
argument_list|,
argument|-
literal|1
argument_list|,
literal|1.62E42FEE00000
argument_list|)
end_macro

begin_macro
name|ic
argument_list|(
argument|ln2lo
argument_list|,
literal|1.9082149292705877000E
argument|-
literal|10
argument_list|,
argument|-
literal|33
argument_list|,
literal|1.A39EF35793C76
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|vccast
end_ifdef

begin_define
define|#
directive|define
name|ln2hi
value|vccast(ln2hi)
end_define

begin_define
define|#
directive|define
name|ln2lo
value|vccast(ln2lo)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|double
name|acosh
parameter_list|(
name|x
parameter_list|)
name|double
name|x
decl_stmt|;
block|{
name|double
name|t
decl_stmt|,
name|big
init|=
literal|1.E20
decl_stmt|;
comment|/* big+1==big */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|vax
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|tahoe
argument_list|)
if|if
condition|(
name|x
operator|!=
name|x
condition|)
return|return
operator|(
name|x
operator|)
return|;
comment|/* x is NaN */
endif|#
directive|endif
comment|/* !defined(vax)&&!defined(tahoe) */
comment|/* return log1p(x) + log(2) if x is large */
if|if
condition|(
name|x
operator|>
name|big
condition|)
block|{
name|t
operator|=
name|log1p
argument_list|(
name|x
argument_list|)
operator|+
name|ln2lo
expr_stmt|;
return|return
operator|(
name|t
operator|+
name|ln2hi
operator|)
return|;
block|}
name|t
operator|=
name|sqrt
argument_list|(
name|x
operator|-
literal|1.0
argument_list|)
expr_stmt|;
return|return
operator|(
name|log1p
argument_list|(
name|t
operator|*
operator|(
name|t
operator|+
name|sqrt
argument_list|(
name|x
operator|+
literal|1.0
argument_list|)
operator|)
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

