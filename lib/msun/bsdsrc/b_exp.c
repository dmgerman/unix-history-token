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
literal|"@(#)exp.c	8.1 (Berkeley) 6/4/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
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

begin_comment
comment|/* EXP(X)  * RETURN THE EXPONENTIAL OF X  * DOUBLE PRECISION (IEEE 53 bits, VAX D FORMAT 56 BITS)  * CODED IN C BY K.C. NG, 1/19/85;  * REVISED BY K.C. NG on 2/6/85, 2/15/85, 3/7/85, 3/24/85, 4/16/85, 6/14/86.  *  * Required system supported functions:  *	scalb(x,n)  *	copysign(x,y)  *	finite(x)  *  * Method:  *	1. Argument Reduction: given the input x, find r and integer k such  *	   that  *	                   x = k*ln2 + r,  |r|<= 0.5*ln2 .  *	   r will be represented as r := z+c for better accuracy.  *  *	2. Compute exp(r) by  *  *		exp(r) = 1 + r + r*R1/(2-R1),  *	   where  *		R1 = x - x^2*(p1+x^2*(p2+x^2*(p3+x^2*(p4+p5*x^2)))).  *  *	3. exp(x) = 2^k * exp(r) .  *  * Special cases:  *	exp(INF) is INF, exp(NaN) is NaN;  *	exp(-INF)=  0;  *	for finite argument, only exp(0)=1 is exact.  *  * Accuracy:  *	exp(x) returns the exponential of x nearly rounded. In a test run  *	with 1,156,000 random arguments on a VAX, the maximum observed  *	error was 0.869 ulps (units in the last place).  */
end_comment

begin_include
include|#
directive|include
file|"mathimpl.h"
end_include

begin_decl_stmt
specifier|const
specifier|static
name|double
name|p1
init|=
literal|0x1
literal|.555555555553ep
operator|-
literal|3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
specifier|static
name|double
name|p2
init|=
operator|-
literal|0x1
literal|.6c16c16bebd93p
operator|-
literal|9
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
specifier|static
name|double
name|p3
init|=
literal|0x1
literal|.1566aaf25de2cp
operator|-
literal|14
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
specifier|static
name|double
name|p4
init|=
operator|-
literal|0x1
operator|.
name|bbd41c5d26bf1p
operator|-
literal|20
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
specifier|static
name|double
name|p5
init|=
literal|0x1
literal|.6376972bea4d0p
operator|-
literal|25
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
specifier|static
name|double
name|ln2hi
init|=
literal|0x1
literal|.62e42fee00000p
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
specifier|static
name|double
name|ln2lo
init|=
literal|0x1
operator|.
name|a39ef35793c76p
operator|-
literal|33
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
specifier|static
name|double
name|lnhuge
init|=
literal|0x1
literal|.6602b15b7ecf2p9
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
specifier|static
name|double
name|lntiny
init|=
operator|-
literal|0x1
literal|.77af8ebeae354p9
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
specifier|static
name|double
name|invln2
init|=
literal|0x1
literal|.71547652b82fep0
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_if
unit|double exp(x) double x; { 	double  z,hi,lo,c; 	int k;
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
end_if

begin_comment
unit|if(x!=x) return(x);
comment|/* x is NaN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(vax)&&!defined(tahoe) */
end_comment

begin_comment
unit|if( x<= lnhuge ) { 		if( x>= lntiny ) {
comment|/* argument reduction : x --> x - k*ln2 */
end_comment

begin_comment
unit|k=invln2*x+copysign(0.5,x);
comment|/* k=NINT(x/ln2) */
end_comment

begin_comment
comment|/* express x-k*ln2 as hi-lo and let x=hi-lo rounded */
end_comment

begin_comment
unit|hi=x-k*ln2hi; 			x=hi-(lo=k*ln2lo);
comment|/* return 2^k*[1+x+x*c/(2+c)]  */
end_comment

begin_comment
unit|z=x*x; 			c= x - z*(p1+z*(p2+z*(p3+z*(p4+z*p5)))); 			return  scalb(1.0+(hi-(lo-(x*c)/(2.0-c))),k);  		}
comment|/* end of x> lntiny */
end_comment

begin_comment
unit|else
comment|/* exp(-big#) underflows to zero */
end_comment

begin_comment
unit|if(finite(x))  return(scalb(1.0,-5000));
comment|/* exp(-INF) is zero */
end_comment

begin_comment
unit|else return(0.0); 	}
comment|/* end of x< lnhuge */
end_comment

begin_comment
unit|else
comment|/* exp(INF) is INF, exp(+big#) overflows to INF */
end_comment

begin_endif
unit|return( finite(x) ?  scalb(1.0,5000)  : x); }
endif|#
directive|endif
end_endif

begin_comment
comment|/* returns exp(r = x + c) for |c|< |x| with no overlap.  */
end_comment

begin_function
name|double
name|__exp__D
parameter_list|(
name|x
parameter_list|,
name|c
parameter_list|)
name|double
name|x
decl_stmt|,
name|c
decl_stmt|;
block|{
name|double
name|z
decl_stmt|,
name|hi
decl_stmt|,
name|lo
decl_stmt|;
name|int
name|k
decl_stmt|;
if|if
condition|(
name|x
operator|!=
name|x
condition|)
comment|/* x is NaN */
return|return
operator|(
name|x
operator|)
return|;
if|if
condition|(
name|x
operator|<=
name|lnhuge
condition|)
block|{
if|if
condition|(
name|x
operator|>=
name|lntiny
condition|)
block|{
comment|/* argument reduction : x --> x - k*ln2 */
name|z
operator|=
name|invln2
operator|*
name|x
expr_stmt|;
name|k
operator|=
name|z
operator|+
name|copysign
argument_list|(
literal|.5
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|/* express (x+c)-k*ln2 as hi-lo and let x=hi-lo rounded */
name|hi
operator|=
operator|(
name|x
operator|-
name|k
operator|*
name|ln2hi
operator|)
expr_stmt|;
comment|/* Exact. */
name|x
operator|=
name|hi
operator|-
operator|(
name|lo
operator|=
name|k
operator|*
name|ln2lo
operator|-
name|c
operator|)
expr_stmt|;
comment|/* return 2^k*[1+x+x*c/(2+c)]  */
name|z
operator|=
name|x
operator|*
name|x
expr_stmt|;
name|c
operator|=
name|x
operator|-
name|z
operator|*
operator|(
name|p1
operator|+
name|z
operator|*
operator|(
name|p2
operator|+
name|z
operator|*
operator|(
name|p3
operator|+
name|z
operator|*
operator|(
name|p4
operator|+
name|z
operator|*
name|p5
operator|)
operator|)
operator|)
operator|)
expr_stmt|;
name|c
operator|=
operator|(
name|x
operator|*
name|c
operator|)
operator|/
operator|(
literal|2.0
operator|-
name|c
operator|)
expr_stmt|;
return|return
name|scalb
argument_list|(
literal|1.
operator|+
operator|(
name|hi
operator|-
operator|(
name|lo
operator|-
name|c
operator|)
operator|)
argument_list|,
name|k
argument_list|)
return|;
block|}
comment|/* end of x> lntiny */
elseif|else
comment|/* exp(-big#) underflows to zero */
if|if
condition|(
name|finite
argument_list|(
name|x
argument_list|)
condition|)
return|return
operator|(
name|scalb
argument_list|(
literal|1.0
argument_list|,
operator|-
literal|5000
argument_list|)
operator|)
return|;
comment|/* exp(-INF) is zero */
else|else
return|return
operator|(
literal|0.0
operator|)
return|;
block|}
comment|/* end of x< lnhuge */
else|else
comment|/* exp(INF) is INF, exp(+big#) overflows to INF */
return|return
operator|(
name|finite
argument_list|(
name|x
argument_list|)
condition|?
name|scalb
argument_list|(
literal|1.0
argument_list|,
literal|5000
argument_list|)
else|:
name|x
operator|)
return|;
block|}
end_function

end_unit

