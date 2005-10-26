begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* k_cosf.c -- float version of k_cos.c  * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.  */
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

begin_decl_stmt
specifier|static
specifier|const
name|float
name|one
init|=
literal|1.0000000000e+00
decl_stmt|,
comment|/* 0x3f800000 */
name|C1
init|=
literal|4.1666667908e-02
decl_stmt|,
comment|/* 0x3d2aaaab */
name|C2
init|=
operator|-
literal|1.3888889225e-03
decl_stmt|,
comment|/* 0xbab60b61 */
name|C3
init|=
literal|2.4801587642e-05
decl_stmt|,
comment|/* 0x37d00d01 */
name|C4
init|=
operator|-
literal|2.7557314297e-07
decl_stmt|,
comment|/* 0xb493f27c */
name|C5
init|=
literal|2.0875723372e-09
decl_stmt|,
comment|/* 0x310f74f6 */
name|C6
init|=
operator|-
literal|1.1359647598e-11
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0xad47d74e */
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

