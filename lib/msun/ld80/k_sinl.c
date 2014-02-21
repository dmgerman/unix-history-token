begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* From: @(#)k_sin.c 1.3 95/01/18 */
end_comment

begin_comment
comment|/*  * ====================================================  * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.  * Copyright (c) 2008 Steven G. Kargl, David Schultz, Bruce D. Evans.  *  * Developed at SunSoft, a Sun Microsystems, Inc. business.  * Permission to use, copy, modify, and distribute this  * software is freely granted, provided that this notice   * is preserved.  * ====================================================  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * ld80 version of k_sin.c.  See ../src/k_sin.c for most comments.  */
end_comment

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
literal|0.5
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Domain [-0.7854, 0.7854], range ~[-1.89e-22, 1.915e-22]  * |sin(x)/x - s(x)|< 2**-72.1  *  * See ../ld80/k_cosl.c for more details about the polynomial.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__amd64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_comment
comment|/* Long double constants are slow on these arches, and broken on i386. */
end_comment

begin_decl_stmt
specifier|static
specifier|const
specifier|volatile
name|double
name|S1hi
init|=
operator|-
literal|0.16666666666666666
decl_stmt|,
comment|/* -0x15555555555555.0p-55 */
name|S1lo
init|=
operator|-
literal|9.2563760475949941e-18
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -0x15580000000000.0p-109 */
end_comment

begin_define
define|#
directive|define
name|S1
value|((long double)S1hi + S1lo)
end_define

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
specifier|const
name|long
name|double
name|S1
init|=
operator|-
literal|0.166666666666666666671L
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -0xaaaaaaaaaaaaaaab.0p-66 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|double
name|S2
init|=
literal|0.0083333333333333332
decl_stmt|,
comment|/*  0x11111111111111.0p-59 */
name|S3
init|=
operator|-
literal|0.00019841269841269427
decl_stmt|,
comment|/* -0x1a01a01a019f81.0p-65 */
name|S4
init|=
literal|0.0000027557319223597490
decl_stmt|,
comment|/*  0x171de3a55560f7.0p-71 */
name|S5
init|=
operator|-
literal|0.000000025052108218074604
decl_stmt|,
comment|/* -0x1ae64564f16cad.0p-78 */
name|S6
init|=
literal|1.6059006598854211e-10
decl_stmt|,
comment|/*  0x161242b90243b5.0p-85 */
name|S7
init|=
operator|-
literal|7.6429779983024564e-13
decl_stmt|,
comment|/* -0x1ae42ebd1b2e00.0p-93 */
name|S8
init|=
literal|2.6174587166648325e-15
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  0x179372ea0b3f64.0p-101 */
end_comment

begin_function
name|long
name|double
name|__kernel_sinl
parameter_list|(
name|long
name|double
name|x
parameter_list|,
name|long
name|double
name|y
parameter_list|,
name|int
name|iy
parameter_list|)
block|{
name|long
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
operator|(
name|S6
operator|+
name|z
operator|*
operator|(
name|S7
operator|+
name|z
operator|*
name|S8
operator|)
operator|)
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

