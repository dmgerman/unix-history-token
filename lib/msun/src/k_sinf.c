begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* k_sinf.c -- float version of k_sin.c  * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.  * Optimized by Bruce D. Evans.  */
end_comment

begin_comment
comment|/*  * ====================================================  * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.  *  * Developed at SunPro, a Sun Microsystems, Inc. business.  * Permission to use, copy, modify, and distribute this  * software is freely granted, provided that this notice  * is preserved.  * ====================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INLINE_KERNEL_SINDF
end_ifndef

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
comment|/* |sin(x)/x - s(x)|< 2**-37.5 (~[-4.89e-12, 4.824e-12]). */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|double
name|S1
init|=
operator|-
literal|0x15555554cbac77
literal|.0p
operator|-
literal|55
decl_stmt|,
comment|/* -0.166666666416265235595 */
name|S2
init|=
literal|0x111110896efbb2
literal|.0p
operator|-
literal|59
decl_stmt|,
comment|/*  0.0083333293858894631756 */
name|S3
init|=
operator|-
literal|0x1a00f9e2cae774
literal|.0p
operator|-
literal|65
decl_stmt|,
comment|/* -0.000198393348360966317347 */
name|S4
init|=
literal|0x16cd878c3b46a7
literal|.0p
operator|-
literal|71
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  0.0000027183114939898219064 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INLINE_KERNEL_SINDF
end_ifdef

begin_function
specifier|extern
specifier|inline
endif|#
directive|endif
name|float
name|__kernel_sindf
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|double
name|r
decl_stmt|,
name|s
decl_stmt|,
name|w
decl_stmt|,
name|z
decl_stmt|;
comment|/* Try to optimize for parallel evaluation as in k_tanf.c. */
name|z
operator|=
name|x
operator|*
name|x
expr_stmt|;
name|w
operator|=
name|z
operator|*
name|z
expr_stmt|;
name|r
operator|=
name|S3
operator|+
name|z
operator|*
name|S4
expr_stmt|;
name|s
operator|=
name|z
operator|*
name|x
expr_stmt|;
return|return
operator|(
name|x
operator|+
name|s
operator|*
operator|(
name|S1
operator|+
name|z
operator|*
name|S2
operator|)
operator|)
operator|+
name|s
operator|*
name|w
operator|*
name|r
return|;
block|}
end_function

end_unit

