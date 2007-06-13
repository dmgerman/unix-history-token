begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* k_cosf.c -- float version of k_cos.c  * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.  * Debugged and optimized by Bruce D. Evans.  */
end_comment

begin_comment
comment|/*  * ====================================================  * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.  *  * Developed at SunPro, a Sun Microsystems, Inc. business.  * Permission to use, copy, modify, and distribute this  * software is freely granted, provided that this notice  * is preserved.  * ====================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INLINE_KERNEL_COSDF
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
comment|/* |cos(x) - c(x)|< 2**-34.1 (~[-5.37e-11, 5.295e-11]). */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|double
name|one
init|=
literal|1.0
decl_stmt|,
name|C0
init|=
operator|-
literal|0x1ffffffd0c5e81
literal|.0p
operator|-
literal|54
decl_stmt|,
comment|/* -0.499999997251031003120 */
name|C1
init|=
literal|0x155553e1053a42
literal|.0p
operator|-
literal|57
decl_stmt|,
comment|/*  0.0416666233237390631894 */
name|C2
init|=
operator|-
literal|0x16c087e80f1e27
literal|.0p
operator|-
literal|62
decl_stmt|,
comment|/* -0.00138867637746099294692 */
name|C3
init|=
literal|0x199342e0ee5069
literal|.0p
operator|-
literal|68
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  0.0000243904487962774090654 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INLINE_KERNEL_COSDF
end_ifdef

begin_function
specifier|extern
specifier|inline
endif|#
directive|endif
name|float
name|__kernel_cosdf
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|double
name|r
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
name|C2
operator|+
name|z
operator|*
name|C3
expr_stmt|;
return|return
operator|(
operator|(
name|one
operator|+
name|z
operator|*
name|C0
operator|)
operator|+
name|w
operator|*
name|C1
operator|)
operator|+
operator|(
name|w
operator|*
name|z
operator|)
operator|*
name|r
return|;
block|}
end_function

end_unit

