begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)s_tan.c 5.1 93/09/24 */
end_comment

begin_comment
comment|/*  * ====================================================  * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.  *  * Developed at SunPro, a Sun Microsystems, Inc. business.  * Permission to use, copy, modify, and distribute this  * software is freely granted, provided that this notice  * is preserved.  * ====================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* tan(x)  * Return tangent function of x.  *  * kernel function:  *	__kernel_tan		... tangent function on [-pi/4,pi/4]  *	__ieee754_rem_pio2	... argument reduction routine  *  * Method.  *      Let S,C and T denote the sin, cos and tan respectively on  *	[-PI/4, +PI/4]. Reduce the argument x to y1+y2 = x-k*pi/2  *	in [-pi/4 , +pi/4], and let n = k mod 4.  *	We have  *  *          n        sin(x)      cos(x)        tan(x)  *     ----------------------------------------------------------  *	    0	       S	   C		 T  *	    1	       C	  -S		-1/T  *	    2	      -S	  -C		 T  *	    3	      -C	   S		-1/T  *     ----------------------------------------------------------  *  * Special cases:  *      Let trig be any of sin, cos, or tan.  *      trig(+-INF)  is NaN, with signals;  *      trig(NaN)    is that NaN;  *  * Accuracy:  *	TRIG(x) returns trig(x) nearly rounded  */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function
name|double
name|tan
parameter_list|(
name|double
name|x
parameter_list|)
else|#
directive|else
function|double tan
parameter_list|(
name|x
parameter_list|)
name|double
name|x
decl_stmt|;
endif|#
directive|endif
block|{
name|double
name|y
index|[
literal|2
index|]
decl_stmt|,
name|z
init|=
literal|0.0
decl_stmt|;
name|int32_t
name|n
decl_stmt|,
name|ix
decl_stmt|;
comment|/* High word of x. */
name|GET_HIGH_WORD
argument_list|(
name|ix
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|/* |x| ~< pi/4 */
name|ix
operator|&=
literal|0x7fffffff
expr_stmt|;
if|if
condition|(
name|ix
operator|<=
literal|0x3fe921fb
condition|)
return|return
name|__kernel_tan
argument_list|(
name|x
argument_list|,
name|z
argument_list|,
literal|1
argument_list|)
return|;
comment|/* tan(Inf or NaN) is NaN */
elseif|else
if|if
condition|(
name|ix
operator|>=
literal|0x7ff00000
condition|)
return|return
name|x
operator|-
name|x
return|;
comment|/* NaN */
comment|/* argument reduction needed */
else|else
block|{
name|n
operator|=
name|__ieee754_rem_pio2
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
return|return
name|__kernel_tan
argument_list|(
name|y
index|[
literal|0
index|]
argument_list|,
name|y
index|[
literal|1
index|]
argument_list|,
literal|1
operator|-
operator|(
operator|(
name|n
operator|&
literal|1
operator|)
operator|<<
literal|1
operator|)
argument_list|)
return|;
comment|/*   1 -- n even 							-1 -- n odd */
block|}
block|}
end_function

end_unit

