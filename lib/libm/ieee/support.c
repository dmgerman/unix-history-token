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
literal|"@(#)support.c	8.1 (Berkeley) 6/4/93"
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
comment|/*  * Some IEEE standard 754 recommended functions and remainder and sqrt for  * supporting the C elementary functions.  ******************************************************************************  * WARNING:  *      These codes are developed (in double) to support the C elementary  * functions temporarily. They are not universal, and some of them are very  * slow (in particular, drem and sqrt is extremely inefficient). Each  * computer system should have its implementation of these functions using  * its own assembler.  ******************************************************************************  *  * IEEE 754 required operations:  *     drem(x,p)  *              returns  x REM y  =  x - [x/y]*y , where [x/y] is the integer  *              nearest x/y; in half way case, choose the even one.  *     sqrt(x)  *              returns the square root of x correctly rounded according to  *		the rounding mod.  *  * IEEE 754 recommended functions:  * (a) copysign(x,y)  *              returns x with the sign of y.  * (b) scalb(x,N)  *              returns  x * (2**N), for integer values N.  * (c) logb(x)  *              returns the unbiased exponent of x, a signed integer in  *              double precision, except that logb(0) is -INF, logb(INF)  *              is +INF, and logb(NAN) is that NAN.  * (d) finite(x)  *              returns the value TRUE if -INF< x< +INF and returns  *              FALSE otherwise.  *  *  * CODED IN C BY K.C. NG, 11/25/84;  * REVISED BY K.C. NG on 1/22/85, 2/13/85, 3/24/85.  */
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

begin_comment
comment|/* VAX D format */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|short
name|msign
init|=
literal|0x7fff
decl_stmt|,
name|mexp
init|=
literal|0x7f80
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|short
name|prep1
init|=
literal|57
decl_stmt|,
name|gap
init|=
literal|7
decl_stmt|,
name|bias
init|=
literal|129
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|double
name|novf
init|=
literal|1.7E38
decl_stmt|,
name|nunf
init|=
literal|3.0E
operator|-
literal|39
decl_stmt|,
name|zero
init|=
literal|0.0
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(vax)||defined(tahoe) */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|short
name|msign
init|=
literal|0x7fff
decl_stmt|,
name|mexp
init|=
literal|0x7ff0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|short
name|prep1
init|=
literal|54
decl_stmt|,
name|gap
init|=
literal|4
decl_stmt|,
name|bias
init|=
literal|1023
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|double
name|novf
init|=
literal|1.7E308
decl_stmt|,
name|nunf
init|=
literal|3.0E
operator|-
literal|308
decl_stmt|,
name|zero
init|=
literal|0.0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(vax)||defined(tahoe) */
end_comment

begin_function
name|double
name|scalb
parameter_list|(
name|x
parameter_list|,
name|N
parameter_list|)
name|double
name|x
decl_stmt|;
name|int
name|N
decl_stmt|;
block|{
name|int
name|k
decl_stmt|;
ifdef|#
directive|ifdef
name|national
name|unsigned
name|short
modifier|*
name|px
init|=
operator|(
name|unsigned
name|short
operator|*
operator|)
operator|&
name|x
operator|+
literal|3
decl_stmt|;
else|#
directive|else
comment|/* national */
name|unsigned
name|short
modifier|*
name|px
init|=
operator|(
name|unsigned
name|short
operator|*
operator|)
operator|&
name|x
decl_stmt|;
endif|#
directive|endif
comment|/* national */
if|if
condition|(
name|x
operator|==
name|zero
condition|)
return|return
operator|(
name|x
operator|)
return|;
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
operator|(
name|k
operator|=
operator|*
name|px
operator|&
name|mexp
operator|)
operator|!=
operator|~
name|msign
condition|)
block|{
if|if
condition|(
name|N
operator|<
operator|-
literal|260
condition|)
return|return
operator|(
name|nunf
operator|*
name|nunf
operator|)
return|;
elseif|else
if|if
condition|(
name|N
operator|>
literal|260
condition|)
block|{
return|return
operator|(
name|copysign
argument_list|(
name|infnan
argument_list|(
name|ERANGE
argument_list|)
argument_list|,
name|x
argument_list|)
operator|)
return|;
block|}
else|#
directive|else
comment|/* defined(vax)||defined(tahoe) */
if|if
condition|(
operator|(
name|k
operator|=
operator|*
name|px
operator|&
name|mexp
operator|)
operator|!=
name|mexp
condition|)
block|{
if|if
condition|(
name|N
operator|<
operator|-
literal|2100
condition|)
return|return
operator|(
name|nunf
operator|*
name|nunf
operator|)
return|;
elseif|else
if|if
condition|(
name|N
operator|>
literal|2100
condition|)
return|return
operator|(
name|novf
operator|+
name|novf
operator|)
return|;
if|if
condition|(
name|k
operator|==
literal|0
condition|)
block|{
name|x
operator|*=
name|scalb
argument_list|(
literal|1.0
argument_list|,
operator|(
name|int
operator|)
name|prep1
argument_list|)
expr_stmt|;
name|N
operator|-=
name|prep1
expr_stmt|;
return|return
operator|(
name|scalb
argument_list|(
name|x
argument_list|,
name|N
argument_list|)
operator|)
return|;
block|}
endif|#
directive|endif
comment|/* defined(vax)||defined(tahoe) */
if|if
condition|(
operator|(
name|k
operator|=
operator|(
name|k
operator|>>
name|gap
operator|)
operator|+
name|N
operator|)
operator|>
literal|0
condition|)
if|if
condition|(
name|k
operator|<
operator|(
name|mexp
operator|>>
name|gap
operator|)
condition|)
operator|*
name|px
operator|=
operator|(
operator|*
name|px
operator|&
operator|~
name|mexp
operator|)
operator||
operator|(
name|k
operator|<<
name|gap
operator|)
expr_stmt|;
else|else
name|x
operator|=
name|novf
operator|+
name|novf
expr_stmt|;
comment|/* overflow */
elseif|else
if|if
condition|(
name|k
operator|>
operator|-
name|prep1
condition|)
comment|/* gradual underflow */
block|{
operator|*
name|px
operator|=
operator|(
operator|*
name|px
operator|&
operator|~
name|mexp
operator|)
operator||
call|(
name|short
call|)
argument_list|(
literal|1
operator|<<
name|gap
argument_list|)
expr_stmt|;
name|x
operator|*=
name|scalb
argument_list|(
literal|1.0
argument_list|,
name|k
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
return|return
operator|(
name|nunf
operator|*
name|nunf
operator|)
return|;
block|}
return|return
operator|(
name|x
operator|)
return|;
block|}
name|double
name|copysign
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
name|double
name|x
decl_stmt|,
name|y
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|national
name|unsigned
name|short
modifier|*
name|px
init|=
operator|(
name|unsigned
name|short
operator|*
operator|)
operator|&
name|x
operator|+
literal|3
decl_stmt|,
modifier|*
name|py
init|=
operator|(
name|unsigned
name|short
operator|*
operator|)
operator|&
name|y
operator|+
literal|3
decl_stmt|;
else|#
directive|else
comment|/* national */
name|unsigned
name|short
modifier|*
name|px
init|=
operator|(
name|unsigned
name|short
operator|*
operator|)
operator|&
name|x
decl_stmt|,
modifier|*
name|py
init|=
operator|(
name|unsigned
name|short
operator|*
operator|)
operator|&
name|y
decl_stmt|;
endif|#
directive|endif
comment|/* national */
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
operator|(
operator|*
name|px
operator|&
name|mexp
operator|)
operator|==
literal|0
condition|)
return|return
operator|(
name|x
operator|)
return|;
endif|#
directive|endif
comment|/* defined(vax)||defined(tahoe) */
operator|*
name|px
operator|=
operator|(
operator|*
name|px
operator|&
name|msign
operator|)
operator||
operator|(
operator|*
name|py
operator|&
operator|~
name|msign
operator|)
expr_stmt|;
return|return
operator|(
name|x
operator|)
return|;
block|}
name|double
name|logb
parameter_list|(
name|x
parameter_list|)
name|double
name|x
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|national
name|short
modifier|*
name|px
init|=
operator|(
name|short
operator|*
operator|)
operator|&
name|x
operator|+
literal|3
decl_stmt|,
name|k
decl_stmt|;
else|#
directive|else
comment|/* national */
name|short
modifier|*
name|px
init|=
operator|(
name|short
operator|*
operator|)
operator|&
name|x
decl_stmt|,
name|k
decl_stmt|;
endif|#
directive|endif
comment|/* national */
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
return|return
call|(
name|int
call|)
argument_list|(
operator|(
operator|(
operator|*
name|px
operator|&
name|mexp
operator|)
operator|>>
name|gap
operator|)
operator|-
name|bias
argument_list|)
return|;
else|#
directive|else
comment|/* defined(vax)||defined(tahoe) */
if|if
condition|(
operator|(
name|k
operator|=
operator|*
name|px
operator|&
name|mexp
operator|)
operator|!=
name|mexp
condition|)
if|if
condition|(
name|k
operator|!=
literal|0
condition|)
return|return
operator|(
operator|(
name|k
operator|>>
name|gap
operator|)
operator|-
name|bias
operator|)
return|;
elseif|else
if|if
condition|(
name|x
operator|!=
name|zero
condition|)
return|return
operator|(
operator|-
literal|1022.0
operator|)
return|;
else|else
return|return
operator|(
operator|-
operator|(
literal|1.0
operator|/
name|zero
operator|)
operator|)
return|;
elseif|else
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
else|else
block|{
operator|*
name|px
operator|&=
name|msign
expr_stmt|;
return|return
operator|(
name|x
operator|)
return|;
block|}
endif|#
directive|endif
comment|/* defined(vax)||defined(tahoe) */
block|}
name|finite
argument_list|(
argument|x
argument_list|)
name|double
name|x
decl_stmt|;
block|{
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
return|return
operator|(
literal|1
operator|)
return|;
else|#
directive|else
comment|/* defined(vax)||defined(tahoe) */
ifdef|#
directive|ifdef
name|national
return|return
operator|(
operator|(
operator|*
operator|(
operator|(
name|short
operator|*
operator|)
operator|&
name|x
operator|+
literal|3
operator|)
operator|&
name|mexp
operator|)
operator|!=
name|mexp
operator|)
return|;
else|#
directive|else
comment|/* national */
return|return
operator|(
operator|(
operator|*
operator|(
operator|(
name|short
operator|*
operator|)
operator|&
name|x
operator|)
operator|&
name|mexp
operator|)
operator|!=
name|mexp
operator|)
return|;
endif|#
directive|endif
comment|/* national */
endif|#
directive|endif
comment|/* defined(vax)||defined(tahoe) */
block|}
name|double
name|drem
parameter_list|(
name|x
parameter_list|,
name|p
parameter_list|)
name|double
name|x
decl_stmt|,
name|p
decl_stmt|;
block|{
name|short
name|sign
decl_stmt|;
name|double
name|hp
decl_stmt|,
name|dp
decl_stmt|,
name|tmp
decl_stmt|;
name|unsigned
name|short
name|k
decl_stmt|;
ifdef|#
directive|ifdef
name|national
name|unsigned
name|short
modifier|*
name|px
init|=
operator|(
name|unsigned
name|short
operator|*
operator|)
operator|&
name|x
operator|+
literal|3
decl_stmt|,
modifier|*
name|pp
init|=
operator|(
name|unsigned
name|short
operator|*
operator|)
operator|&
name|p
operator|+
literal|3
decl_stmt|,
modifier|*
name|pd
init|=
operator|(
name|unsigned
name|short
operator|*
operator|)
operator|&
name|dp
operator|+
literal|3
decl_stmt|,
modifier|*
name|pt
init|=
operator|(
name|unsigned
name|short
operator|*
operator|)
operator|&
name|tmp
operator|+
literal|3
decl_stmt|;
else|#
directive|else
comment|/* national */
name|unsigned
name|short
modifier|*
name|px
init|=
operator|(
name|unsigned
name|short
operator|*
operator|)
operator|&
name|x
decl_stmt|,
modifier|*
name|pp
init|=
operator|(
name|unsigned
name|short
operator|*
operator|)
operator|&
name|p
decl_stmt|,
modifier|*
name|pd
init|=
operator|(
name|unsigned
name|short
operator|*
operator|)
operator|&
name|dp
decl_stmt|,
modifier|*
name|pt
init|=
operator|(
name|unsigned
name|short
operator|*
operator|)
operator|&
name|tmp
decl_stmt|;
endif|#
directive|endif
comment|/* national */
operator|*
name|pp
operator|&=
name|msign
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
operator|(
operator|*
name|px
operator|&
name|mexp
operator|)
operator|==
operator|~
name|msign
condition|)
comment|/* is x a reserved operand? */
else|#
directive|else
comment|/* defined(vax)||defined(tahoe) */
if|if
condition|(
operator|(
operator|*
name|px
operator|&
name|mexp
operator|)
operator|==
name|mexp
condition|)
endif|#
directive|endif
comment|/* defined(vax)||defined(tahoe) */
return|return
operator|(
name|x
operator|-
name|p
operator|)
operator|-
operator|(
name|x
operator|-
name|p
operator|)
return|;
comment|/* create nan if x is inf */
if|if
condition|(
name|p
operator|==
name|zero
condition|)
block|{
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
return|return
operator|(
name|infnan
argument_list|(
name|EDOM
argument_list|)
operator|)
return|;
else|#
directive|else
comment|/* defined(vax)||defined(tahoe) */
return|return
name|zero
operator|/
name|zero
return|;
endif|#
directive|endif
comment|/* defined(vax)||defined(tahoe) */
block|}
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
operator|(
operator|*
name|pp
operator|&
name|mexp
operator|)
operator|==
operator|~
name|msign
condition|)
comment|/* is p a reserved operand? */
else|#
directive|else
comment|/* defined(vax)||defined(tahoe) */
if|if
condition|(
operator|(
operator|*
name|pp
operator|&
name|mexp
operator|)
operator|==
name|mexp
condition|)
endif|#
directive|endif
comment|/* defined(vax)||defined(tahoe) */
block|{
if|if
condition|(
name|p
operator|!=
name|p
condition|)
return|return
name|p
return|;
else|else
return|return
name|x
return|;
block|}
elseif|else
if|if
condition|(
operator|(
operator|(
operator|*
name|pp
operator|&
name|mexp
operator|)
operator|>>
name|gap
operator|)
operator|<=
literal|1
condition|)
comment|/* subnormal p, or almost subnormal p */
block|{
name|double
name|b
decl_stmt|;
name|b
operator|=
name|scalb
argument_list|(
literal|1.0
argument_list|,
operator|(
name|int
operator|)
name|prep1
argument_list|)
expr_stmt|;
name|p
operator|*=
name|b
expr_stmt|;
name|x
operator|=
name|drem
argument_list|(
name|x
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|x
operator|*=
name|b
expr_stmt|;
return|return
operator|(
name|drem
argument_list|(
name|x
argument_list|,
name|p
argument_list|)
operator|/
name|b
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|p
operator|>=
name|novf
operator|/
literal|2
condition|)
block|{
name|p
operator|/=
literal|2
expr_stmt|;
name|x
operator|/=
literal|2
expr_stmt|;
return|return
operator|(
name|drem
argument_list|(
name|x
argument_list|,
name|p
argument_list|)
operator|*
literal|2
operator|)
return|;
block|}
else|else
block|{
name|dp
operator|=
name|p
operator|+
name|p
expr_stmt|;
name|hp
operator|=
name|p
operator|/
literal|2
expr_stmt|;
name|sign
operator|=
operator|*
name|px
operator|&
operator|~
name|msign
expr_stmt|;
operator|*
name|px
operator|&=
name|msign
expr_stmt|;
while|while
condition|(
name|x
operator|>
name|dp
condition|)
block|{
name|k
operator|=
operator|(
operator|*
name|px
operator|&
name|mexp
operator|)
operator|-
operator|(
operator|*
name|pd
operator|&
name|mexp
operator|)
expr_stmt|;
name|tmp
operator|=
name|dp
expr_stmt|;
operator|*
name|pt
operator|+=
name|k
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
operator|<
name|tmp
condition|)
operator|*
name|pt
operator|-=
literal|128
expr_stmt|;
else|#
directive|else
comment|/* defined(vax)||defined(tahoe) */
if|if
condition|(
name|x
operator|<
name|tmp
condition|)
operator|*
name|pt
operator|-=
literal|16
expr_stmt|;
endif|#
directive|endif
comment|/* defined(vax)||defined(tahoe) */
name|x
operator|-=
name|tmp
expr_stmt|;
block|}
if|if
condition|(
name|x
operator|>
name|hp
condition|)
block|{
name|x
operator|-=
name|p
expr_stmt|;
if|if
condition|(
name|x
operator|>=
name|hp
condition|)
name|x
operator|-=
name|p
expr_stmt|;
block|}
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
condition|)
endif|#
directive|endif
comment|/* defined(vax)||defined(tahoe) */
operator|*
name|px
operator|^=
name|sign
expr_stmt|;
return|return
operator|(
name|x
operator|)
return|;
block|}
block|}
name|double
name|sqrt
parameter_list|(
name|x
parameter_list|)
name|double
name|x
decl_stmt|;
block|{
name|double
name|q
decl_stmt|,
name|s
decl_stmt|,
name|b
decl_stmt|,
name|r
decl_stmt|;
name|double
name|t
decl_stmt|;
name|double
specifier|const
name|zero
init|=
literal|0.0
decl_stmt|;
name|int
name|m
decl_stmt|,
name|n
decl_stmt|,
name|i
decl_stmt|;
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
name|int
name|k
init|=
literal|54
decl_stmt|;
else|#
directive|else
comment|/* defined(vax)||defined(tahoe) */
name|int
name|k
init|=
literal|51
decl_stmt|;
endif|#
directive|endif
comment|/* defined(vax)||defined(tahoe) */
comment|/* sqrt(NaN) is NaN, sqrt(+-0) = +-0 */
if|if
condition|(
name|x
operator|!=
name|x
operator|||
name|x
operator|==
name|zero
condition|)
return|return
operator|(
name|x
operator|)
return|;
comment|/* sqrt(negative) is invalid */
if|if
condition|(
name|x
operator|<
name|zero
condition|)
block|{
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
return|return
operator|(
name|infnan
argument_list|(
name|EDOM
argument_list|)
operator|)
return|;
comment|/* NaN */
else|#
directive|else
comment|/* defined(vax)||defined(tahoe) */
return|return
operator|(
name|zero
operator|/
name|zero
operator|)
return|;
endif|#
directive|endif
comment|/* defined(vax)||defined(tahoe) */
block|}
comment|/* sqrt(INF) is INF */
if|if
condition|(
operator|!
name|finite
argument_list|(
name|x
argument_list|)
condition|)
return|return
operator|(
name|x
operator|)
return|;
comment|/* scale x to [1,4) */
name|n
operator|=
name|logb
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|x
operator|=
name|scalb
argument_list|(
name|x
argument_list|,
operator|-
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|m
operator|=
name|logb
argument_list|(
name|x
argument_list|)
operator|)
operator|!=
literal|0
condition|)
name|x
operator|=
name|scalb
argument_list|(
name|x
argument_list|,
operator|-
name|m
argument_list|)
expr_stmt|;
comment|/* subnormal number */
name|m
operator|+=
name|n
expr_stmt|;
name|n
operator|=
name|m
operator|/
literal|2
expr_stmt|;
if|if
condition|(
operator|(
name|n
operator|+
name|n
operator|)
operator|!=
name|m
condition|)
block|{
name|x
operator|*=
literal|2
expr_stmt|;
name|m
operator|-=
literal|1
expr_stmt|;
name|n
operator|=
name|m
operator|/
literal|2
expr_stmt|;
block|}
comment|/* generate sqrt(x) bit by bit (accumulating in q) */
name|q
operator|=
literal|1.0
expr_stmt|;
name|s
operator|=
literal|4.0
expr_stmt|;
name|x
operator|-=
literal|1.0
expr_stmt|;
name|r
operator|=
literal|1
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<=
name|k
condition|;
name|i
operator|++
control|)
block|{
name|t
operator|=
name|s
operator|+
literal|1
expr_stmt|;
name|x
operator|*=
literal|4
expr_stmt|;
name|r
operator|/=
literal|2
expr_stmt|;
if|if
condition|(
name|t
operator|<=
name|x
condition|)
block|{
name|s
operator|=
name|t
operator|+
name|t
operator|+
literal|2
operator|,
name|x
operator|-=
name|t
expr_stmt|;
name|q
operator|+=
name|r
expr_stmt|;
block|}
else|else
name|s
operator|*=
literal|2
expr_stmt|;
block|}
comment|/* generate the last bit and determine the final rounding */
name|r
operator|/=
literal|2
expr_stmt|;
name|x
operator|*=
literal|4
expr_stmt|;
if|if
condition|(
name|x
operator|==
name|zero
condition|)
goto|goto
name|end
goto|;
literal|100
operator|+
name|r
expr_stmt|;
comment|/* trigger inexact flag */
if|if
condition|(
name|s
operator|<
name|x
condition|)
block|{
name|q
operator|+=
name|r
expr_stmt|;
name|x
operator|-=
name|s
expr_stmt|;
name|s
operator|+=
literal|2
expr_stmt|;
name|s
operator|*=
literal|2
expr_stmt|;
name|x
operator|*=
literal|4
expr_stmt|;
name|t
operator|=
operator|(
name|x
operator|-
name|s
operator|)
operator|-
literal|5
expr_stmt|;
name|b
operator|=
literal|1.0
operator|+
literal|3
operator|*
name|r
operator|/
literal|4
expr_stmt|;
if|if
condition|(
name|b
operator|==
literal|1.0
condition|)
goto|goto
name|end
goto|;
comment|/* b==1 : Round-to-zero */
name|b
operator|=
literal|1.0
operator|+
name|r
operator|/
literal|4
expr_stmt|;
if|if
condition|(
name|b
operator|>
literal|1.0
condition|)
name|t
operator|=
literal|1
expr_stmt|;
comment|/* b>1 : Round-to-(+INF) */
if|if
condition|(
name|t
operator|>=
literal|0
condition|)
name|q
operator|+=
name|r
expr_stmt|;
block|}
comment|/* else: Round-to-nearest */
else|else
block|{
name|s
operator|*=
literal|2
expr_stmt|;
name|x
operator|*=
literal|4
expr_stmt|;
name|t
operator|=
operator|(
name|x
operator|-
name|s
operator|)
operator|-
literal|1
expr_stmt|;
name|b
operator|=
literal|1.0
operator|+
literal|3
operator|*
name|r
operator|/
literal|4
expr_stmt|;
if|if
condition|(
name|b
operator|==
literal|1.0
condition|)
goto|goto
name|end
goto|;
name|b
operator|=
literal|1.0
operator|+
name|r
operator|/
literal|4
expr_stmt|;
if|if
condition|(
name|b
operator|>
literal|1.0
condition|)
name|t
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|t
operator|>=
literal|0
condition|)
name|q
operator|+=
name|r
expr_stmt|;
block|}
name|end
label|:
return|return
operator|(
name|scalb
argument_list|(
name|q
argument_list|,
name|n
argument_list|)
operator|)
return|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* DREM(X,Y)  * RETURN X REM Y =X-N*Y, N=[X/Y] ROUNDED (ROUNDED TO EVEN IN THE HALF WAY CASE)  * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)  * INTENDED FOR ASSEMBLY LANGUAGE  * CODED IN C BY K.C. NG, 3/23/85, 4/8/85.  *  * Warning: this code should not get compiled in unless ALL of  * the following machine-dependent routines are supplied.  *  * Required machine dependent functions (not on a VAX):  *     swapINX(i): save inexact flag and reset it to "i"  *     swapENI(e): save inexact enable and reset it to "e"  */
end_comment

begin_ifdef
unit|double drem(x,y) double x,y; {
ifdef|#
directive|ifdef
name|national
end_ifdef

begin_comment
comment|/* order of words in floating point number */
end_comment

begin_else
unit|static const n0=3,n1=2,n2=1,n3=0;
else|#
directive|else
end_else

begin_comment
comment|/* VAX, SUN, ZILOG, TAHOE */
end_comment

begin_endif
unit|static const n0=0,n1=1,n2=2,n3=3;
endif|#
directive|endif
end_endif

begin_comment
unit|static const unsigned short mexp =0x7ff0, m25 =0x0190, m57 =0x0390; 	static const double zero=0.0; 	double hy,y1,t,t1; 	short k; 	long n; 	int i,e; 	unsigned short xexp,yexp, *px  =(unsigned short *)&x  , 	      		nx,nf,	  *py  =(unsigned short *)&y  , 	      		sign,	  *pt  =(unsigned short *)&t  , 	      			  *pt1 =(unsigned short *)&t1 ;  	xexp = px[n0]& mexp ;
comment|/* exponent of x */
end_comment

begin_comment
unit|yexp = py[n0]& mexp ;
comment|/* exponent of y */
end_comment

begin_comment
unit|sign = px[n0]&0x8000;
comment|/* sign of x     */
end_comment

begin_comment
comment|/* return NaN if x is NaN, or y is NaN, or x is INF, or y is zero */
end_comment

begin_comment
unit|if(x!=x) return(x); if(y!=y) return(y);
comment|/* x or y is NaN */
end_comment

begin_comment
unit|if( xexp == mexp )   return(zero/zero);
comment|/* x is INF */
end_comment

begin_comment
unit|if(y==zero) return(y/y);
comment|/* save the inexact flag and inexact enable in i and e respectively  * and reset them to zero  */
end_comment

begin_comment
unit|i=swapINX(0);	e=swapENI(0);
comment|/* subnormal number */
end_comment

begin_comment
unit|nx=0; 	if(yexp==0) {t=1.0,pt[n0]+=m57; y*=t; nx=m57;}
comment|/* if y is tiny (biased exponent<= 57), scale up y to y*2**57 */
end_comment

begin_comment
unit|if( yexp<= m57 ) {py[n0]+=m57; nx+=m57; yexp+=m57;}  	nf=nx; 	py[n0]&= 0x7fff; 	px[n0]&= 0x7fff;
comment|/* mask off the least significant 27 bits of y */
end_comment

begin_comment
unit|t=y; pt[n3]=0; pt[n2]&=0xf800; y1=t;
comment|/* LOOP: argument reduction on x whenever x> y */
end_comment

begin_comment
unit|loop: 	while ( x> y ) 	{ 	    t=y; 	    t1=y1; 	    xexp=px[n0]&mexp;
comment|/* exponent of x */
end_comment

begin_comment
unit|k=xexp-yexp-m25; 	    if(k>0)
comment|/* if x/y>= 2**26, scale up y so that x/y< 2**26 */
end_comment

begin_comment
unit|{pt[n0]+=k;pt1[n0]+=k;} 	    n=x/t; x=(x-n*t1)-n*(t-t1); 	}
comment|/* end while (x> y) */
end_comment

begin_comment
unit|if(nx!=0) {t=1.0; pt[n0]+=nx; x*=t; nx=0; goto loop;}
comment|/* final adjustment */
end_comment

begin_comment
unit|hy=y/2.0; 	if(x>hy||((x==hy)&&n%2==1)) x-=y; 	px[n0] ^= sign; 	if(nf!=0) { t=1.0; pt[n0]-=nf; x*=t;}
comment|/* restore inexact flag and inexact enable */
end_comment

begin_endif
unit|swapINX(i); swapENI(e);  	return(x); }
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* SQRT  * RETURN CORRECTLY ROUNDED (ACCORDING TO THE ROUNDING MODE) SQRT  * FOR IEEE DOUBLE PRECISION ONLY, INTENDED FOR ASSEMBLY LANGUAGE  * CODED IN C BY K.C. NG, 3/22/85.  *  * Warning: this code should not get compiled in unless ALL of  * the following machine-dependent routines are supplied.  *  * Required machine dependent functions:  *     swapINX(i)  ...return the status of INEXACT flag and reset it to "i"  *     swapRM(r)   ...return the current Rounding Mode and reset it to "r"  *     swapENI(e)  ...return the status of inexact enable and reset it to "e"  *     addc(t)     ...perform t=t+1 regarding t as a 64 bit unsigned integer  *     subc(t)     ...perform t=t-1 regarding t as a 64 bit unsigned integer  */
end_comment

begin_comment
unit|static const unsigned long table[] = { 0, 1204, 3062, 5746, 9193, 13348, 18162, 23592, 29598, 36145, 43202, 50740, 58733, 67158, 75992, 85215, 83599, 71378, 60428, 50647, 41945, 34246, 27478, 21581, 16499, 12183, 8588, 5674, 3403, 1742, 661, 130, };  double newsqrt(x) double x; {         double y,z,t,addc(),subc() 	double const b54=134217728.*134217728.;
comment|/* b54=2**54 */
end_comment

begin_ifdef
unit|long mx,scalx; 	long const mexp=0x7ff00000;         int i,j,r,e,swapINX(),swapRM(),swapENI();         unsigned long *py=(unsigned long *)&y   ,                       *pt=(unsigned long *)&t   ,                       *px=(unsigned long *)&x   ;
ifdef|#
directive|ifdef
name|national
end_ifdef

begin_comment
comment|/* ordering of word in a floating point number */
end_comment

begin_else
unit|const int n0=1, n1=0;
else|#
directive|else
end_else

begin_endif
unit|const int n0=0, n1=1;
endif|#
directive|endif
end_endif

begin_comment
comment|/* Rounding Mode:  RN ...round-to-nearest  *                 RZ ...round-towards 0  *                 RP ...round-towards +INF  *		   RM ...round-towards -INF  */
end_comment

begin_comment
unit|const int RN=0,RZ=1,RP=2,RM=3;
comment|/* machine dependent: work on a Zilog Z8070                                  * and a National 32081& 16081                                  */
end_comment

begin_comment
comment|/* exceptions */
end_comment

begin_comment
unit|if(x!=x||x==0.0) return(x);
comment|/* sqrt(NaN) is NaN, sqrt(+-0) = +-0 */
end_comment

begin_comment
unit|if(x<0) return((x-x)/(x-x));
comment|/* sqrt(negative) is invalid */
end_comment

begin_comment
unit|if((mx=px[n0]&mexp)==mexp) return(x);
comment|/* sqrt(+INF) is +INF */
end_comment

begin_comment
comment|/* save, reset, initialize */
end_comment

begin_comment
unit|e=swapENI(0);
comment|/* ...save and reset the inexact enable */
end_comment

begin_comment
unit|i=swapINX(0);
comment|/* ...save INEXACT flag */
end_comment

begin_comment
unit|r=swapRM(RN);
comment|/* ...save and reset the Rounding Mode to RN */
end_comment

begin_comment
unit|scalx=0;
comment|/* subnormal number, scale up x to x*2**54 */
end_comment

begin_comment
unit|if(mx==0) {x *= b54 ; scalx-=0x01b00000;}
comment|/* scale x to avoid intermediate over/underflow:  * if (x> 2**512) x=x/2**512; if (x< 2**-512) x=x*2**512 */
end_comment

begin_comment
unit|if(mx>0x5ff00000) {px[n0] -= 0x20000000; scalx+= 0x10000000;}         if(mx<0x1ff00000) {px[n0] += 0x20000000; scalx-= 0x10000000;}
comment|/* magic initial approximation to almost 8 sig. bits */
end_comment

begin_comment
unit|py[n0]=(px[n0]>>1)+0x1ff80000;         py[n0]=py[n0]-table[(py[n0]>>15)&31];
comment|/* Heron's rule once with correction to improve y to almost 18 sig. bits */
end_comment

begin_comment
unit|t=x/y; y=y+t; py[n0]=py[n0]-0x00100006; py[n1]=0;
comment|/* triple to almost 56 sig. bits; now y approx. sqrt(x) to within 1 ulp */
end_comment

begin_comment
unit|t=y*y; z=t;  pt[n0]+=0x00100000; t+=z; z=(x-z)*y;         t=z/(t+x) ;  pt[n0]+=0x00100000; y+=t;
comment|/* twiddle last bit to force y correctly rounded */
end_comment

begin_comment
unit|swapRM(RZ);
comment|/* ...set Rounding Mode to round-toward-zero */
end_comment

begin_comment
unit|swapINX(0);
comment|/* ...clear INEXACT flag */
end_comment

begin_comment
unit|swapENI(e);
comment|/* ...restore inexact enable status */
end_comment

begin_comment
unit|t=x/y;
comment|/* ...chopped quotient, possibly inexact */
end_comment

begin_comment
unit|j=swapINX(i);
comment|/* ...read and restore inexact flag */
end_comment

begin_comment
unit|if(j==0) { if(t==y) goto end; else t=subc(t); }
comment|/* ...t=t-ulp */
end_comment

begin_comment
unit|b54+0.1;
comment|/* ..trigger inexact flag, sqrt(x) is inexact */
end_comment

begin_comment
unit|if(r==RN) t=addc(t);
comment|/* ...t=t+ulp */
end_comment

begin_comment
unit|else if(r==RP) { t=addc(t);y=addc(y);}
comment|/* ...t=t+ulp;y=y+ulp; */
end_comment

begin_comment
unit|y=y+t;
comment|/* ...chopped sum */
end_comment

begin_comment
unit|py[n0]=py[n0]-0x00100000;
comment|/* ...correctly rounded sqrt(x) */
end_comment

begin_comment
unit|end:    py[n0]=py[n0]+scalx;
comment|/* ...scale back y */
end_comment

begin_comment
unit|swapRM(r);
comment|/* ...restore Rounding Mode */
end_comment

begin_endif
unit|return(y); }
endif|#
directive|endif
end_endif

end_unit

