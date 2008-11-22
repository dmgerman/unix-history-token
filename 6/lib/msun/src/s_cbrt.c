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

begin_comment
comment|/* |1/cbrt(x) - p(x)|< 2**-23.5 (~[-7.93e-8, 7.929e-8]). */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|double
name|P0
init|=
literal|1.87595182427177009643
decl_stmt|,
comment|/* 0x3ffe03e6, 0x0f61e692 */
name|P1
init|=
operator|-
literal|1.88497979543377169875
decl_stmt|,
comment|/* 0xbffe28e0, 0x92f02420 */
name|P2
init|=
literal|1.621429720105354466140
decl_stmt|,
comment|/* 0x3ff9f160, 0x4a49d6c2 */
name|P3
init|=
operator|-
literal|0.758397934778766047437
decl_stmt|,
comment|/* 0xbfe844cb, 0xbee751d9 */
name|P4
init|=
literal|0.145996192886612446982
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0x3fc2b000, 0xd4e4edd7 */
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
name|u_int32_t
name|sign
decl_stmt|;
name|u_int32_t
name|high
decl_stmt|,
name|low
decl_stmt|;
name|EXTRACT_WORDS
argument_list|(
name|hx
argument_list|,
name|low
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
comment|/*      * Rough cbrt to 5 bits:      *    cbrt(2**e*(1+m) ~= 2**(e/3)*(1+(e%3+m)/3)      * where e is integral and>= 0, m is real and in [0, 1), and "/" and      * "%" are integer division and modulus with rounding towards minus      * infinity.  The RHS is always>= the LHS and has a maximum relative      * error of about 1 in 16.  Adding a bias of -0.03306235651 to the      * (e%3+m)/3 term reduces the error to about 1 in 32. With the IEEE      * floating point representation, for finite positive normal values,      * ordinary integer divison of the value in bits magically gives      * almost exactly the RHS of the above provided we first subtract the      * exponent bias (1023 for doubles) and later add it back.  We do the      * subtraction virtually to keep e>= 0 so that ordinary integer      * division rounds towards minus infinity; this is also efficient.      */
if|if
condition|(
name|hx
operator|<
literal|0x00100000
condition|)
block|{
comment|/* zero or subnormal? */
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
name|INSERT_WORDS
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
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
name|INSERT_WORDS
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
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/*      * New cbrt to 23 bits:      *    cbrt(x) = t*cbrt(x/t**3) ~= t*P(t**3/x)      * where P(r) is a polynomial of degree 4 that approximates 1/cbrt(r)      * to within 2**-23.5 when |r - 1|< 1/10.  The rough approximation      * has produced t such than |t/cbrt(x) - 1| ~< 1/32, and cubing this      * gives us bounds for r = t**3/x.      *      * Try to optimize for parallel evaluation as in k_tanf.c.      */
name|r
operator|=
operator|(
name|t
operator|*
name|t
operator|)
operator|*
operator|(
name|t
operator|/
name|x
operator|)
expr_stmt|;
name|t
operator|=
name|t
operator|*
operator|(
operator|(
name|P0
operator|+
name|r
operator|*
operator|(
name|P1
operator|+
name|r
operator|*
name|P2
operator|)
operator|)
operator|+
operator|(
operator|(
name|r
operator|*
name|r
operator|)
operator|*
name|r
operator|)
operator|*
operator|(
name|P3
operator|+
name|r
operator|*
name|P4
operator|)
operator|)
expr_stmt|;
comment|/*      * Round t away from zero to 23 bits (sloppily except for ensuring that      * the result is larger in magnitude than cbrt(x) but not much more than      * 2 23-bit ulps larger).  With rounding towards zero, the error bound      * would be ~5/6 instead of ~4/6.  With a maximum error of 2 23-bit ulps      * in the rounded t, the infinite-precision error in the Newton      * approximation barely affects third digit in the the final error      * 0.667; the error in the rounded t can be up to about 3 23-bit ulps      * before the final error is larger than 0.667 ulps.      */
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
literal|0x80000000
operator|)
operator|&
literal|0xffffffffc0000000ULL
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

