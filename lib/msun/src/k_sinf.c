begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* k_sinf.c -- float version of k_sin.c  * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_decl_stmt
specifier|static
specifier|const
name|float
else|#
directive|else
specifier|static
name|float
endif|#
directive|endif
name|half
init|=
literal|5.0000000000e-01
decl_stmt|,
comment|/* 0x3f000000 */
name|S1
init|=
operator|-
literal|1.6666667163e-01
decl_stmt|,
comment|/* 0xbe2aaaab */
name|S2
init|=
literal|8.3333337680e-03
decl_stmt|,
comment|/* 0x3c088889 */
name|S3
init|=
operator|-
literal|1.9841270114e-04
decl_stmt|,
comment|/* 0xb9500d01 */
name|S4
init|=
literal|2.7557314297e-06
decl_stmt|,
comment|/* 0x3638ef1b */
name|S5
init|=
operator|-
literal|2.5050759689e-08
decl_stmt|,
comment|/* 0xb2d72f34 */
name|S6
init|=
literal|1.5896910177e-10
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0x2f2ec9d3 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function
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
else|#
directive|else
function|float __kernel_sinf
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|iy
parameter_list|)
name|float
name|x
decl_stmt|,
name|y
decl_stmt|;
name|int
name|iy
decl_stmt|;
comment|/* iy=0 if y is zero */
endif|#
directive|endif
block|{
name|float
name|z
decl_stmt|,
name|r
decl_stmt|,
name|v
decl_stmt|;
name|int32_t
name|ix
decl_stmt|;
name|GET_FLOAT_WORD
argument_list|(
name|ix
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|ix
operator|&=
literal|0x7fffffff
expr_stmt|;
comment|/* high word of x */
if|if
condition|(
name|ix
operator|<
literal|0x32000000
condition|)
comment|/* |x|< 2**-27 */
block|{
if|if
condition|(
operator|(
name|int
operator|)
name|x
operator|==
literal|0
condition|)
return|return
name|x
return|;
block|}
comment|/* generate inexact */
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

