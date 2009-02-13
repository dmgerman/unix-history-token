begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)k_cos.c 1.3 95/01/18 */
end_comment

begin_comment
comment|/*  * ====================================================  * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.  *  * Developed at SunSoft, a Sun Microsystems, Inc. business.  * Permission to use, copy, modify, and distribute this  * software is freely granted, provided that this notice   * is preserved.  * ====================================================  */
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
comment|/*  * __kernel_cos( x,  y )  * kernel cos function on [-pi/4, pi/4], pi/4 ~ 0.785398164  * Input x is assumed to be bounded by ~pi/4 in magnitude.  * Input y is the tail of x.   *  * Algorithm  *	1. Since cos(-x) = cos(x), we need only to consider positive x.  *	2. if x< 2^-27 (hx<0x3e400000 0), return 1 with inexact if x!=0.  *	3. cos(x) is approximated by a polynomial of degree 14 on  *	   [0,pi/4]  *		  	                 4            14  *	   	cos(x) ~ 1 - x*x/2 + C1*x + ... + C6*x  *	   where the remez error is  *	  * 	|              2     4     6     8     10    12     14 |     -58  * 	|cos(x)-(1-.5*x +C1*x +C2*x +C3*x +C4*x +C5*x  +C6*x  )|<= 2  * 	|    					               |   *   * 	               4     6     8     10    12     14   *	4. let r = C1*x +C2*x +C3*x +C4*x +C5*x  +C6*x  , then  *	       cos(x) ~ 1 - x*x/2 + r  *	   since cos(x+y) ~ cos(x) - sin(x)*y   *			  ~ cos(x) - x*y,  *	   a correction term is necessary in cos(x) and hence  *		cos(x+y) = 1 - (x*x/2 - (r - x*y))  *	   For better accuracy, rearrange to  *		cos(x+y) ~ w + (tmp + (r-x*y))  *	   where w = 1 - x*x/2 and tmp is a tiny correction term  *	   (1 - x*x/2 == w + tmp exactly in infinite precision).  *	   The exactness of w + tmp in infinite precision depends on w  *	   and tmp having the same precision as x.  If they have extra  *	   precision due to compiler bugs, then the extra precision is  *	   only good provided it is retained in all terms of the final  *	   expression for cos().  Retention happens in all cases tested  *	   under FreeBSD, so don't pessimize things by forcibly clipping  *	   any extra precision in w.  */
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

begin_decl_stmt
specifier|static
specifier|const
name|double
name|one
init|=
literal|1.00000000000000000000e+00
decl_stmt|,
comment|/* 0x3FF00000, 0x00000000 */
name|C1
init|=
literal|4.16666666666666019037e-02
decl_stmt|,
comment|/* 0x3FA55555, 0x5555554C */
name|C2
init|=
operator|-
literal|1.38888888888741095749e-03
decl_stmt|,
comment|/* 0xBF56C16C, 0x16C15177 */
name|C3
init|=
literal|2.48015872894767294178e-05
decl_stmt|,
comment|/* 0x3EFA01A0, 0x19CB1590 */
name|C4
init|=
operator|-
literal|2.75573143513906633035e-07
decl_stmt|,
comment|/* 0xBE927E4F, 0x809C52AD */
name|C5
init|=
literal|2.08757232129817482790e-09
decl_stmt|,
comment|/* 0x3E21EE9E, 0xBDB4B1C4 */
name|C6
init|=
operator|-
literal|1.13596475577881948265e-11
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0xBDA8FAE9, 0xBE8838D4 */
end_comment

begin_function
name|double
name|__kernel_cos
parameter_list|(
name|double
name|x
parameter_list|,
name|double
name|y
parameter_list|)
block|{
name|double
name|hz
decl_stmt|,
name|z
decl_stmt|,
name|r
decl_stmt|,
name|w
decl_stmt|;
name|z
operator|=
name|x
operator|*
name|x
expr_stmt|;
name|r
operator|=
name|z
operator|*
operator|(
name|C1
operator|+
name|z
operator|*
operator|(
name|C2
operator|+
name|z
operator|*
operator|(
name|C3
operator|+
name|z
operator|*
operator|(
name|C4
operator|+
name|z
operator|*
operator|(
name|C5
operator|+
name|z
operator|*
name|C6
operator|)
operator|)
operator|)
operator|)
operator|)
expr_stmt|;
name|hz
operator|=
operator|(
name|float
operator|)
literal|0.5
operator|*
name|z
expr_stmt|;
name|w
operator|=
name|one
operator|-
name|hz
expr_stmt|;
return|return
name|w
operator|+
operator|(
operator|(
operator|(
name|one
operator|-
name|w
operator|)
operator|-
name|hz
operator|)
operator|+
operator|(
name|z
operator|*
name|r
operator|-
name|x
operator|*
name|y
operator|)
operator|)
return|;
block|}
end_function

end_unit

