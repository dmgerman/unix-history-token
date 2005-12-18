begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* s_cbrtf.c -- float version of s_cbrt.c.  * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.  * Debugged and optimized by Bruce D. Evans.  */
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
comment|/* cbrtf(x)  * Return cube root of x  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|B1
init|=
literal|709958130
decl_stmt|,
comment|/* B1 = (127-127.0/3-0.03306235651)*2**23 */
name|B2
init|=
literal|642849266
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* B2 = (127-127.0/3-24/3-0.03306235651)*2**23 */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|float
name|C
init|=
literal|5.4285717010e-01
decl_stmt|,
comment|/* 19/35     = 0x3f0af8b0 */
name|D
init|=
operator|-
literal|7.0530611277e-01
decl_stmt|,
comment|/* -864/1225 = 0xbf348ef1 */
name|E
init|=
literal|1.4142856598e+00
decl_stmt|,
comment|/* 99/70     = 0x3fb50750 */
name|F
init|=
literal|1.6071428061e+00
decl_stmt|,
comment|/* 45/28     = 0x3fcdb6db */
name|G
init|=
literal|3.5714286566e-01
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 5/14      = 0x3eb6db6e */
end_comment

begin_function
name|float
name|cbrtf
parameter_list|(
name|float
name|x
parameter_list|)
block|{
name|float
name|r
decl_stmt|,
name|s
decl_stmt|,
name|t
decl_stmt|,
name|w
decl_stmt|;
name|int32_t
name|hx
decl_stmt|;
name|u_int32_t
name|sign
decl_stmt|;
name|u_int32_t
name|high
decl_stmt|;
name|GET_FLOAT_WORD
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
literal|0x7f800000
condition|)
return|return
operator|(
name|x
operator|+
name|x
operator|)
return|;
comment|/* cbrt(NaN,INF) is itself */
if|if
condition|(
name|hx
operator|==
literal|0
condition|)
return|return
operator|(
name|x
operator|)
return|;
comment|/* cbrt(0) is itself */
comment|/* rough cbrt to 5 bits */
if|if
condition|(
name|hx
operator|<
literal|0x00800000
condition|)
block|{
comment|/* subnormal number */
name|SET_FLOAT_WORD
argument_list|(
name|t
argument_list|,
literal|0x4b800000
argument_list|)
expr_stmt|;
comment|/* set t= 2**24 */
name|t
operator|*=
name|x
expr_stmt|;
name|GET_FLOAT_WORD
argument_list|(
name|high
argument_list|,
name|t
argument_list|)
expr_stmt|;
name|SET_FLOAT_WORD
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
name|SET_FLOAT_WORD
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
comment|/* new cbrt to 23 bits */
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
comment|/*      * Round t away from zero to 12 bits (sloppily except for ensuring that      * the result is larger in magnitude than cbrt(x) but not much more than      * 1 12-bit ulp larger).  With rounding towards zero, the error bound      * would be ~5/6 instead of ~4/6, and with t 2 12-bit ulps larger the      * infinite-precision error in the Newton approximation would affect      * the second digit instead of the third digit of 4/6 = 0.666..., etc.      */
name|GET_FLOAT_WORD
argument_list|(
name|high
argument_list|,
name|t
argument_list|)
expr_stmt|;
name|SET_FLOAT_WORD
argument_list|(
name|t
argument_list|,
operator|(
name|high
operator|+
literal|0x1002
operator|)
operator|&
literal|0xfffff000
argument_list|)
expr_stmt|;
comment|/* one step Newton iteration to 24 bits with error< 0.667 ulps */
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

