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
name|INLINE_KERNEL_SINF
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
comment|/* |sin(x)/x - s(x)|< 2**-32.5 (~[-1.57e-10, 1.572e-10]). */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|float
name|half
init|=
literal|0.5
decl_stmt|,
name|S1
init|=
operator|-
literal|0xaaaaab
literal|.0p
operator|-
literal|26
decl_stmt|,
comment|/* -0.16666667163 */
name|S2
init|=
literal|0x8888bb
literal|.0p
operator|-
literal|30
decl_stmt|,
comment|/*  0.0083333803341 */
name|S3
init|=
operator|-
literal|0xd02de1
literal|.0p
operator|-
literal|36
decl_stmt|,
comment|/* -0.00019853517006 */
name|S4
init|=
literal|0xbe6dbe
literal|.0p
operator|-
literal|42
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  0.0000028376084629 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INLINE_KERNEL_SINF
end_ifdef

begin_function
specifier|extern
specifier|inline
endif|#
directive|endif
name|float
name|__kernel_sinf
parameter_list|(
name|float
name|x
parameter_list|,
name|float
name|y
parameter_list|,
name|int
name|iy
parameter_list|)
block|{
name|float
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
name|S4
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

