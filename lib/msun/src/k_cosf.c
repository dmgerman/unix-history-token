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
comment|/* |cos(x) - c(x)|< 2**-33.1 (~[-9.39e-11, 1.083e-10]). */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|float
name|one
init|=
literal|1.0
decl_stmt|,
name|C1
init|=
literal|0xaaaaa5
literal|.0p
operator|-
literal|28
decl_stmt|,
comment|/*  0.041666645557 */
name|C2
init|=
operator|-
literal|0xb60615
literal|.0p
operator|-
literal|33
decl_stmt|,
comment|/* -0.0013887310633 */
name|C3
init|=
literal|0xccf47d
literal|.0p
operator|-
literal|39
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  0.000024432542887 */
end_comment

begin_function
name|float
name|__kernel_cosf
parameter_list|(
name|float
name|x
parameter_list|,
name|float
name|y
parameter_list|)
block|{
name|float
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
name|C3
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

