begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)s_cbrt.c 5.1 93/09/24 */
end_comment

begin_comment
comment|/*  * ====================================================  * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.  *  * Developed at SunPro, a Sun Microsystems, Inc. business.  * Permission to use, copy, modify, and distribute this  * software is freely granted, provided that this notice  * is preserved.  * ====================================================  *  * Optimized by Bruce D. Evans.  */
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
comment|/* cbrt(x)  * Return cube root of x  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|u_int32_t
name|B1
init|=
literal|715094163
decl_stmt|,
comment|/* B1 = (1023-1023/3-0.03306235651)*2**20 */
name|B2
init|=
literal|696219795
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* B2 = (1023-1023/3-54/3-0.03306235651)*2**20 */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|double
name|C
init|=
literal|5.42857142857142815906e-01
decl_stmt|,
comment|/* 19/35     = 0x3FE15F15, 0xF15F15F1 */
name|D
init|=
operator|-
literal|7.05306122448979611050e-01
decl_stmt|,
comment|/* -864/1225 = 0xBFE691DE, 0x2532C834 */
name|E
init|=
literal|1.41428571428571436819e+00
decl_stmt|,
comment|/* 99/70     = 0x3FF6A0EA, 0x0EA0EA0F */
name|F
init|=
literal|1.60714285714285720630e+00
decl_stmt|,
comment|/* 45/28     = 0x3FF9B6DB, 0x6DB6DB6E */
name|G
init|=
literal|3.57142857142857150787e-01
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 5/14      = 0x3FD6DB6D, 0xB6DB6DB7 */
end_comment

begin_function
name|double
name|cbrt
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|int32_t
name|hx
decl_stmt|;
union|union
block|{
name|double
name|value
decl_stmt|;
name|uint64_t
name|bits
decl_stmt|;
block|}
name|u
union|;
name|double
name|r
decl_stmt|,
name|s
decl_stmt|,
name|t
init|=
literal|0.0
decl_stmt|,
name|w
decl_stmt|;
name|uint64_t
name|bits
decl_stmt|;
name|u_int32_t
name|sign
decl_stmt|;
name|u_int32_t
name|high
decl_stmt|,
name|low
decl_stmt|;
name|GET_HIGH_WORD
argument_list|(
name|hx
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|sign
operator|=
name|hx
operator|&
literal|0x80000000
expr_stmt|;
comment|/* sign= sign(x) */
name|hx
operator|^=
name|sign
expr_stmt|;
if|if
condition|(
name|hx
operator|>=
literal|0x7ff00000
condition|)
return|return
operator|(
name|x
operator|+
name|x
operator|)
return|;
comment|/* cbrt(NaN,INF) is itself */
name|GET_LOW_WORD
argument_list|(
name|low
argument_list|,
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|hx
operator||
name|low
operator|)
operator|==
literal|0
condition|)
return|return
operator|(
name|x
operator|)
return|;
comment|/* cbrt(0) is itself */
comment|/*      * Rough cbrt to 5 bits:      *    cbrt(2**e*(1+m) ~= 2**(e/3)*(1+(e%3+m)/3)      * where e is integral and>= 0, m is real and in [0, 1), and "/" and      * "%" are integer division and modulus with rounding towards minus      * infinity.  The RHS is always>= the LHS and has a maximum relative      * error of about 1 in 16.  Adding a bias of -0.03306235651 to the      * (e%3+m)/3 term reduces the error to about 1 in 32. With the IEEE      * floating point representation, for finite positive normal values,      * ordinary integer divison of the value in bits magically gives      * almost exactly the RHS of the above provided we first subtract the      * exponent bias (1023 for doubles) and later add it back.  We do the      * subtraction virtually to keep e>= 0 so that ordinary integer      * division rounds towards minus infinity; this is also efficient.      */
if|if
condition|(
name|hx
operator|<
literal|0x00100000
condition|)
block|{
comment|/* subnormal number */
name|SET_HIGH_WORD
argument_list|(
name|t
argument_list|,
literal|0x43500000
argument_list|)
expr_stmt|;
comment|/* set t= 2**54 */
name|t
operator|*=
name|x
expr_stmt|;
name|GET_HIGH_WORD
argument_list|(
name|high
argument_list|,
name|t
argument_list|)
expr_stmt|;
name|SET_HIGH_WORD
argument_list|(
name|t
argument_list|,
name|sign
operator||
operator|(
operator|(
name|high
operator|&
literal|0x7fffffff
operator|)
operator|/
literal|3
operator|+
name|B2
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
name|SET_HIGH_WORD
argument_list|(
name|t
argument_list|,
name|sign
operator||
operator|(
name|hx
operator|/
literal|3
operator|+
name|B1
operator|)
argument_list|)
expr_stmt|;
comment|/*      * New cbrt to 25 bits:      *    cbrt(x) = t*cbrt(x/t**3) ~= t*R(x/t**3)      * where R(r) = (14*r**2 + 35*r + 5)/(5*r**2 + 35*r + 14) is the      * (2,2) Pade approximation to cbrt(r) at r = 1.  We replace      * r = x/t**3 by 1/r = t**3/x since the latter can be evaluated      * more efficiently, and rearrange the expression for R(r) to use      * 4 additions and 2 divisions instead of the 4 additions, 4      * multiplications and 1 division that would be required using      * Horner's rule on the numerator and denominator.  t being good      * to 32 bits means that |t/cbrt(x)-1|< 1/32, so |x/t**3-1|< 0.1      * and for R(r) we can use any approximation to cbrt(r) that is good      * to 20 bits on [0.9, 1.1].  The (2,2) Pade approximation is not an      * especially good choice.      */
name|r
operator|=
name|t
operator|*
name|t
operator|/
name|x
expr_stmt|;
name|s
operator|=
name|C
operator|+
name|r
operator|*
name|t
expr_stmt|;
name|t
operator|*=
name|G
operator|+
name|F
operator|/
operator|(
name|s
operator|+
name|E
operator|+
name|D
operator|/
name|s
operator|)
expr_stmt|;
comment|/*      * Round t away from zero to 25 bits (sloppily except for ensuring that      * the result is larger in magnitude than cbrt(x) but not much more than      * 2 25-bit ulps larger).  With rounding towards zero, the error bound      * would be ~5/6 instead of ~4/6.  With a maximum error of 1 25-bit ulps      * in the rounded t, the infinite-precision error in the Newton      * approximation barely affects third digit in the the final error      * 0.667; the error in the rounded t can be up to about 12 25-bit ulps      * before the final error is larger than 0.667 ulps.      */
name|u
operator|.
name|value
operator|=
name|t
expr_stmt|;
name|u
operator|.
name|bits
operator|=
operator|(
name|u
operator|.
name|bits
operator|+
literal|0x20000000
operator|)
operator|&
literal|0xfffffffff0000000ULL
expr_stmt|;
name|t
operator|=
name|u
operator|.
name|value
expr_stmt|;
comment|/* one step Newton iteration to 53 bits with error< 0.667 ulps */
name|s
operator|=
name|t
operator|*
name|t
expr_stmt|;
comment|/* t*t is exact */
name|r
operator|=
name|x
operator|/
name|s
expr_stmt|;
comment|/* error<= 0.5 ulps; |r|< |t| */
name|w
operator|=
name|t
operator|+
name|t
expr_stmt|;
comment|/* t+t is exact */
name|r
operator|=
operator|(
name|r
operator|-
name|t
operator|)
operator|/
operator|(
name|w
operator|+
name|r
operator|)
expr_stmt|;
comment|/* r-t is exact; w+r ~= 3*t */
name|t
operator|=
name|t
operator|+
name|t
operator|*
name|r
expr_stmt|;
comment|/* error<= 0.5 + 0.5/3 + epsilon */
return|return
operator|(
name|t
operator|)
return|;
block|}
end_function

end_unit

