begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* From: @(#)k_tan.c 1.5 04/04/22 SMI */
end_comment

begin_comment
comment|/*  * ====================================================  * Copyright 2004 Sun Microsystems, Inc.  All Rights Reserved.  * Copyright (c) 2008 Steven G. Kargl, David Schultz, Bruce D. Evans.  *  * Permission to use, copy, modify, and distribute this  * software is freely granted, provided that this notice  * is preserved.  * ====================================================  */
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
comment|/*  * ld80 version of k_tan.c.  See ../src/k_tan.c for most comments.  */
end_comment

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
comment|/*  * Domain [-0.67434, 0.67434], range ~[-2.25e-22, 1.921e-22]  * |tan(x)/x - t(x)|< 2**-71.9  *  * See k_cosl.c for more details about the polynomial.  */
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
name|T3hi
init|=
literal|0.33333333333333331
decl_stmt|,
comment|/*  0x15555555555555.0p-54 */
name|T3lo
init|=
literal|1.8350121769317163e-17
decl_stmt|,
comment|/*  0x15280000000000.0p-108 */
name|T5hi
init|=
literal|0.13333333333333336
decl_stmt|,
comment|/*  0x11111111111112.0p-55 */
name|T5lo
init|=
literal|1.3051083651294260e-17
decl_stmt|,
comment|/*  0x1e180000000000.0p-109 */
name|T7hi
init|=
literal|0.053968253968250494
decl_stmt|,
comment|/*  0x1ba1ba1ba1b827.0p-57 */
name|T7lo
init|=
literal|3.1509625637859973e-18
decl_stmt|,
comment|/*  0x1d100000000000.0p-111 */
name|pio4_hi
init|=
literal|0.78539816339744828
decl_stmt|,
comment|/*  0x1921fb54442d18.0p-53 */
name|pio4_lo
init|=
literal|3.0628711372715500e-17
decl_stmt|,
comment|/*  0x11a80000000000.0p-107 */
name|pio4lo_hi
init|=
operator|-
literal|1.2541394031670831e-20
decl_stmt|,
comment|/* -0x1d9cceba3f91f2.0p-119 */
name|pio4lo_lo
init|=
literal|6.1493048227390915e-37
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  0x1a280000000000.0p-173 */
end_comment

begin_define
define|#
directive|define
name|T3
value|((long double)T3hi + T3lo)
end_define

begin_define
define|#
directive|define
name|T5
value|((long double)T5hi + T5lo)
end_define

begin_define
define|#
directive|define
name|T7
value|((long double)T7hi + T7lo)
end_define

begin_define
define|#
directive|define
name|pio4
value|((long double)pio4_hi + pio4_lo)
end_define

begin_define
define|#
directive|define
name|pio4lo
value|((long double)pio4lo_hi + pio4lo_lo)
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
name|T3
init|=
literal|0.333333333333333333180L
decl_stmt|,
comment|/*  0xaaaaaaaaaaaaaaa5.0p-65 */
name|T5
init|=
literal|0.133333333333333372290L
decl_stmt|,
comment|/*  0x88888888888893c3.0p-66 */
name|T7
init|=
literal|0.0539682539682504975744L
decl_stmt|,
comment|/*  0xdd0dd0dd0dc13ba2.0p-68 */
name|pio4
init|=
literal|0.785398163397448309628L
decl_stmt|,
comment|/*  0xc90fdaa22168c235.0p-64 */
name|pio4lo
init|=
operator|-
literal|1.25413940316708300586e-20L
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -0xece675d1fc8f8cbb.0p-130 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|double
name|T9
init|=
literal|0.021869488536312216
decl_stmt|,
comment|/*  0x1664f4882cc1c2.0p-58 */
name|T11
init|=
literal|0.0088632355256619590
decl_stmt|,
comment|/*  0x1226e355c17612.0p-59 */
name|T13
init|=
literal|0.0035921281113786528
decl_stmt|,
comment|/*  0x1d6d3d185d7ff8.0p-61 */
name|T15
init|=
literal|0.0014558334756312418
decl_stmt|,
comment|/*  0x17da354aa3f96b.0p-62 */
name|T17
init|=
literal|0.00059003538700862256
decl_stmt|,
comment|/*  0x13559358685b83.0p-63 */
name|T19
init|=
literal|0.00023907843576635544
decl_stmt|,
comment|/*  0x1f56242026b5be.0p-65 */
name|T21
init|=
literal|0.000097154625656538905
decl_stmt|,
comment|/*  0x1977efc26806f4.0p-66 */
name|T23
init|=
literal|0.000038440165747303162
decl_stmt|,
comment|/*  0x14275a09b3ceac.0p-67 */
name|T25
init|=
literal|0.000018082171885432524
decl_stmt|,
comment|/*  0x12f5e563e5487e.0p-68 */
name|T27
init|=
literal|0.0000024196006108814377
decl_stmt|,
comment|/*  0x144c0d80cc6896.0p-71 */
name|T29
init|=
literal|0.0000078293456938132840
decl_stmt|,
comment|/*  0x106b59141a6cb3.0p-69 */
name|T31
init|=
operator|-
literal|0.0000032609076735050182
decl_stmt|,
comment|/* -0x1b5abef3ba4b59.0p-71 */
name|T33
init|=
literal|0.0000023261313142559411
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  0x13835436c0c87f.0p-71 */
end_comment

begin_function
name|long
name|double
name|__kernel_tanl
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
decl_stmt|,
name|w
decl_stmt|,
name|s
decl_stmt|;
name|long
name|double
name|osign
decl_stmt|;
name|int
name|i
decl_stmt|;
name|iy
operator|=
operator|(
name|iy
operator|==
literal|1
condition|?
operator|-
literal|1
else|:
literal|1
operator|)
expr_stmt|;
comment|/* XXX recover original interface */
name|osign
operator|=
operator|(
name|x
operator|>=
literal|0
condition|?
literal|1.0
else|:
operator|-
literal|1.0
operator|)
expr_stmt|;
comment|/* XXX slow, probably wrong for -0 */
if|if
condition|(
name|fabsl
argument_list|(
name|x
argument_list|)
operator|>=
literal|0.67434
condition|)
block|{
if|if
condition|(
name|x
operator|<
literal|0
condition|)
block|{
name|x
operator|=
operator|-
name|x
expr_stmt|;
name|y
operator|=
operator|-
name|y
expr_stmt|;
block|}
name|z
operator|=
name|pio4
operator|-
name|x
expr_stmt|;
name|w
operator|=
name|pio4lo
operator|-
name|y
expr_stmt|;
name|x
operator|=
name|z
operator|+
name|w
expr_stmt|;
name|y
operator|=
literal|0.0
expr_stmt|;
name|i
operator|=
literal|1
expr_stmt|;
block|}
else|else
name|i
operator|=
literal|0
expr_stmt|;
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
name|T5
operator|+
name|w
operator|*
operator|(
name|T9
operator|+
name|w
operator|*
operator|(
name|T13
operator|+
name|w
operator|*
operator|(
name|T17
operator|+
name|w
operator|*
operator|(
name|T21
operator|+
name|w
operator|*
operator|(
name|T25
operator|+
name|w
operator|*
operator|(
name|T29
operator|+
name|w
operator|*
name|T33
operator|)
operator|)
operator|)
operator|)
operator|)
operator|)
expr_stmt|;
name|v
operator|=
name|z
operator|*
operator|(
name|T7
operator|+
name|w
operator|*
operator|(
name|T11
operator|+
name|w
operator|*
operator|(
name|T15
operator|+
name|w
operator|*
operator|(
name|T19
operator|+
name|w
operator|*
operator|(
name|T23
operator|+
name|w
operator|*
operator|(
name|T27
operator|+
name|w
operator|*
name|T31
operator|)
operator|)
operator|)
operator|)
operator|)
operator|)
expr_stmt|;
name|s
operator|=
name|z
operator|*
name|x
expr_stmt|;
name|r
operator|=
name|y
operator|+
name|z
operator|*
operator|(
name|s
operator|*
operator|(
name|r
operator|+
name|v
operator|)
operator|+
name|y
operator|)
expr_stmt|;
name|r
operator|+=
name|T3
operator|*
name|s
expr_stmt|;
name|w
operator|=
name|x
operator|+
name|r
expr_stmt|;
if|if
condition|(
name|i
operator|==
literal|1
condition|)
block|{
name|v
operator|=
operator|(
name|long
name|double
operator|)
name|iy
expr_stmt|;
return|return
name|osign
operator|*
operator|(
name|v
operator|-
literal|2.0
operator|*
operator|(
name|x
operator|-
operator|(
name|w
operator|*
name|w
operator|/
operator|(
name|w
operator|+
name|v
operator|)
operator|-
name|r
operator|)
operator|)
operator|)
return|;
block|}
if|if
condition|(
name|iy
operator|==
literal|1
condition|)
return|return
name|w
return|;
else|else
block|{
comment|/* 		 * if allow error up to 2 ulp, simply return 		 * -1.0 / (x+r) here 		 */
comment|/* compute -1.0 / (x+r) accurately */
name|long
name|double
name|a
decl_stmt|,
name|t
decl_stmt|;
name|z
operator|=
name|w
expr_stmt|;
name|z
operator|=
name|z
operator|+
literal|0x1p32
operator|-
literal|0x1p32
expr_stmt|;
name|v
operator|=
name|r
operator|-
operator|(
name|z
operator|-
name|x
operator|)
expr_stmt|;
comment|/* z+v = r+x */
name|t
operator|=
name|a
operator|=
operator|-
literal|1.0
operator|/
name|w
expr_stmt|;
comment|/* a = -1.0/w */
name|t
operator|=
name|t
operator|+
literal|0x1p32
operator|-
literal|0x1p32
expr_stmt|;
name|s
operator|=
literal|1.0
operator|+
name|t
operator|*
name|z
expr_stmt|;
return|return
name|t
operator|+
name|a
operator|*
operator|(
name|s
operator|+
name|t
operator|*
name|v
operator|)
return|;
block|}
block|}
end_function

end_unit

