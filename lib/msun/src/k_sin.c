begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)k_sin.c 1.3 95/01/18 */
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
comment|/* __kernel_sin( x, y, iy)  * kernel sin function on [-pi/4, pi/4], pi/4 ~ 0.7854  * Input x is assumed to be bounded by ~pi/4 in magnitude.  * Input y is the tail of x.  * Input iy indicates whether y is 0. (if iy=0, y assume to be 0).   *  * Algorithm  *	1. Since sin(-x) = -sin(x), we need only to consider positive x.   *	2. if x< 2^-27 (hx<0x3e400000 0), return x with inexact if x!=0.  *	3. sin(x) is approximated by a polynomial of degree 13 on  *	   [0,pi/4]  *		  	         3            13  *	   	sin(x) ~ x + S1*x + ... + S6*x  *	   where  *	  * 	|sin(x)         2     4     6     8     10     12  |     -58  * 	|----- - (1+S1*x +S2*x +S3*x +S4*x +S5*x  +S6*x   )|<= 2  * 	|  x 					           |   *   *	4. sin(x+y) = sin(x) + sin'(x')*y  *		    ~ sin(x) + (1-x*x/2)*y  *	   For better accuracy, let   *		     3      2      2      2      2  *		r = x *(S2+x *(S3+x *(S4+x *(S5+x *S6))))  *	   then                   3    2  *		sin(x) = x + (S1*x + (x *(r-y/2)+y))  */
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
name|half
init|=
literal|5.00000000000000000000e-01
decl_stmt|,
comment|/* 0x3FE00000, 0x00000000 */
name|S1
init|=
operator|-
literal|1.66666666666666324348e-01
decl_stmt|,
comment|/* 0xBFC55555, 0x55555549 */
name|S2
init|=
literal|8.33333333332248946124e-03
decl_stmt|,
comment|/* 0x3F811111, 0x1110F8A6 */
name|S3
init|=
operator|-
literal|1.98412698298579493134e-04
decl_stmt|,
comment|/* 0xBF2A01A0, 0x19C161D5 */
name|S4
init|=
literal|2.75573137070700676789e-06
decl_stmt|,
comment|/* 0x3EC71DE3, 0x57B1FE7D */
name|S5
init|=
operator|-
literal|2.50507602534068634195e-08
decl_stmt|,
comment|/* 0xBE5AE5E6, 0x8A2B9CEB */
name|S6
init|=
literal|1.58969099521155010221e-10
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0x3DE5D93A, 0x5ACFD57C */
end_comment

begin_function
name|double
name|__kernel_sin
parameter_list|(
name|double
name|x
parameter_list|,
name|double
name|y
parameter_list|,
name|int
name|iy
parameter_list|)
block|{
name|double
name|z
decl_stmt|,
name|r
decl_stmt|,
name|v
decl_stmt|;
name|z
operator|=
name|x
operator|*
name|x
expr_stmt|;
name|v
operator|=
name|z
operator|*
name|x
expr_stmt|;
name|r
operator|=
name|S2
operator|+
name|z
operator|*
operator|(
name|S3
operator|+
name|z
operator|*
operator|(
name|S4
operator|+
name|z
operator|*
operator|(
name|S5
operator|+
name|z
operator|*
name|S6
operator|)
operator|)
operator|)
expr_stmt|;
if|if
condition|(
name|iy
operator|==
literal|0
condition|)
return|return
name|x
operator|+
name|v
operator|*
operator|(
name|S1
operator|+
name|z
operator|*
name|r
operator|)
return|;
else|else
return|return
name|x
operator|-
operator|(
operator|(
name|z
operator|*
operator|(
name|half
operator|*
name|y
operator|-
name|v
operator|*
name|r
operator|)
operator|-
name|y
operator|)
operator|-
name|v
operator|*
name|S1
operator|)
return|;
block|}
end_function

end_unit

