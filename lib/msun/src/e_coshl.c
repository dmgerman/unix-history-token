begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* from: FreeBSD: head/lib/msun/src/e_coshl.c XXX */
end_comment

begin_comment
comment|/*  * ====================================================  * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.  *  * Developed at SunPro, a Sun Microsystems, Inc. business.  * Permission to use, copy, modify, and distribute this  * software is freely granted, provided that this notice  * is preserved.  * ====================================================  */
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
comment|/*  * See e_cosh.c for complete comments.  *  * Converted to long double by Bruce D. Evans.  */
end_comment

begin_include
include|#
directive|include
file|<float.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_include
include|#
directive|include
file|<ieeefp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"fpmath.h"
end_include

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

begin_include
include|#
directive|include
file|"k_expl.h"
end_include

begin_if
if|#
directive|if
name|LDBL_MAX_EXP
operator|!=
literal|0x4000
end_if

begin_comment
comment|/* We also require the usual expsign encoding. */
end_comment

begin_error
error|#
directive|error
literal|"Unsupported long double format"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BIAS
value|(LDBL_MAX_EXP - 1)
end_define

begin_decl_stmt
specifier|static
specifier|const
specifier|volatile
name|long
name|double
name|huge
init|=
literal|0x1p10000L
decl_stmt|,
name|tiny
init|=
literal|0x1p
operator|-
literal|10000L
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|LDBL_MANT_DIG
operator|==
literal|64
end_if

begin_comment
comment|/*  * Domain [-1, 1], range ~[-1.8211e-21, 1.8211e-21]:  * |cosh(x) - c(x)|< 2**-68.8  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|union
name|IEEEl2bits
name|C4u
init|=
name|LD80C
argument_list|(
literal|0xaaaaaaaaaaaaac78
argument_list|,
operator|-
literal|5
argument_list|,
literal|4.16666666666666682297e-2L
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|C4
value|C4u.e
end_define

begin_decl_stmt
specifier|static
specifier|const
name|double
name|C2
init|=
literal|0.5
decl_stmt|,
name|C6
init|=
literal|1.3888888888888616e-3
decl_stmt|,
comment|/*  0x16c16c16c16b99.0p-62 */
name|C8
init|=
literal|2.4801587301767953e-5
decl_stmt|,
comment|/*  0x1a01a01a027061.0p-68 */
name|C10
init|=
literal|2.7557319163300398e-7
decl_stmt|,
comment|/*  0x127e4fb6c9b55f.0p-74 */
name|C12
init|=
literal|2.0876768371393075e-9
decl_stmt|,
comment|/*  0x11eed99406a3f4.0p-81 */
name|C14
init|=
literal|1.1469537039374480e-11
decl_stmt|,
comment|/*  0x1938c67cd18c48.0p-89 */
name|C16
init|=
literal|4.8473490896852041e-14
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  0x1b49c429701e45.0p-97 */
end_comment

begin_elif
elif|#
directive|elif
name|LDBL_MANT_DIG
operator|==
literal|113
end_elif

begin_comment
comment|/*  * Domain [-1, 1], range ~[-2.3194e-37, 2.3194e-37]:  * |cosh(x) - c(x)|< 2**-121.69  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|long
name|double
name|C4
init|=
literal|4.16666666666666666666666666666666225e-2L
decl_stmt|,
comment|/*  0x1555555555555555555555555554e.0p-117L */
name|C6
init|=
literal|1.38888888888888888888888888889434831e-3L
decl_stmt|,
comment|/*  0x16c16c16c16c16c16c16c16c1dd7a.0p-122L */
name|C8
init|=
literal|2.48015873015873015873015871870962089e-5L
decl_stmt|,
comment|/*  0x1a01a01a01a01a01a01a017af2756.0p-128L */
name|C10
init|=
literal|2.75573192239858906525574318600800201e-7L
decl_stmt|,
comment|/*  0x127e4fb7789f5c72ef01c8a040640.0p-134L */
name|C12
init|=
literal|2.08767569878680989791444691755468269e-9L
decl_stmt|,
comment|/*  0x11eed8eff8d897b543d0679607399.0p-141L */
name|C14
init|=
literal|1.14707455977297247387801189650495351e-11L
decl_stmt|,
comment|/*  0x193974a8c07c9d24ae169a7fa9b54.0p-149L */
name|C16
init|=
literal|4.77947733238737883626416876486279985e-14L
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  0x1ae7f3e733b814d4e1b90f5727fe4.0p-157L */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|double
name|C2
init|=
literal|0.5
decl_stmt|,
name|C18
init|=
literal|1.5619206968597871e-16
decl_stmt|,
comment|/*  0x16827863b9900b.0p-105 */
name|C20
init|=
literal|4.1103176218528049e-19
decl_stmt|,
comment|/*  0x1e542ba3d3c269.0p-114 */
name|C22
init|=
literal|8.8967926401641701e-22
decl_stmt|,
comment|/*  0x10ce399542a014.0p-122 */
name|C24
init|=
literal|1.6116681626523904e-24
decl_stmt|,
comment|/*  0x1f2c981d1f0cb7.0p-132 */
name|C26
init|=
literal|2.5022374732804632e-27
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  0x18c7ecf8b2c4a0.0p-141 */
end_comment

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"Unsupported long double format"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LDBL_MANT_DIG == 64 */
end_comment

begin_comment
comment|/* log(2**16385 - 0.5) rounded up: */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|float
name|o_threshold
init|=
literal|1.13572168e4
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  0xb174de.0p-10 */
end_comment

begin_function
name|long
name|double
name|coshl
parameter_list|(
name|long
name|double
name|x
parameter_list|)
block|{
name|long
name|double
name|hi
decl_stmt|,
name|lo
decl_stmt|,
name|x2
decl_stmt|,
name|x4
decl_stmt|;
name|double
name|dx2
decl_stmt|;
name|uint16_t
name|ix
decl_stmt|;
name|GET_LDBL_EXPSIGN
argument_list|(
name|ix
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|ix
operator|&=
literal|0x7fff
expr_stmt|;
comment|/* x is INF or NaN */
if|if
condition|(
name|ix
operator|>=
literal|0x7fff
condition|)
return|return
name|x
operator|*
name|x
return|;
name|ENTERI
argument_list|()
expr_stmt|;
comment|/* |x|< 1, return 1 or c(x) */
if|if
condition|(
name|ix
operator|<
literal|0x3fff
condition|)
block|{
if|if
condition|(
name|ix
operator|<
name|BIAS
operator|-
operator|(
name|LDBL_MANT_DIG
operator|+
literal|1
operator|)
operator|/
literal|2
condition|)
comment|/* |x|< TINY */
name|RETURNI
argument_list|(
literal|1
operator|+
name|tiny
argument_list|)
expr_stmt|;
comment|/* cosh(tiny) = 1(+) with inexact */
name|x2
operator|=
name|x
operator|*
name|x
expr_stmt|;
if|#
directive|if
name|LDBL_MANT_DIG
operator|==
literal|64
name|x4
operator|=
name|x2
operator|*
name|x2
expr_stmt|;
name|RETURNI
argument_list|(
operator|(
operator|(
name|C16
operator|*
name|x2
operator|+
name|C14
operator|)
operator|*
name|x4
operator|+
operator|(
name|C12
operator|*
name|x2
operator|+
name|C10
operator|)
operator|)
operator|*
operator|(
name|x4
operator|*
name|x4
operator|*
name|x2
operator|)
operator|+
operator|(
operator|(
name|C8
operator|*
name|x2
operator|+
name|C6
operator|)
operator|*
name|x2
operator|+
name|C4
operator|)
operator|*
name|x4
operator|+
name|C2
operator|*
name|x2
operator|+
literal|1
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|LDBL_MANT_DIG
operator|==
literal|113
name|dx2
operator|=
name|x2
expr_stmt|;
name|RETURNI
argument_list|(
operator|(
operator|(
operator|(
operator|(
operator|(
operator|(
operator|(
operator|(
operator|(
operator|(
operator|(
name|C26
operator|*
name|dx2
operator|+
name|C24
operator|)
operator|*
name|dx2
operator|+
name|C22
operator|)
operator|*
name|dx2
operator|+
name|C20
operator|)
operator|*
name|x2
operator|+
name|C18
operator|)
operator|*
name|x2
operator|+
name|C16
operator|)
operator|*
name|x2
operator|+
name|C14
operator|)
operator|*
name|x2
operator|+
name|C12
operator|)
operator|*
name|x2
operator|+
name|C10
operator|)
operator|*
name|x2
operator|+
name|C8
operator|)
operator|*
name|x2
operator|+
name|C6
operator|)
operator|*
name|x2
operator|+
name|C4
operator|)
operator|*
operator|(
name|x2
operator|*
name|x2
operator|)
operator|+
name|C2
operator|*
name|x2
operator|+
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
comment|/* |x| in [1, 64), return accurate exp(|x|)/2+1/exp(|x|)/2 */
if|if
condition|(
name|ix
operator|<
literal|0x4005
condition|)
block|{
name|k_hexpl
argument_list|(
name|fabsl
argument_list|(
name|x
argument_list|)
argument_list|,
operator|&
name|hi
argument_list|,
operator|&
name|lo
argument_list|)
expr_stmt|;
name|RETURNI
argument_list|(
name|lo
operator|+
literal|0.25
operator|/
operator|(
name|hi
operator|+
name|lo
operator|)
operator|+
name|hi
argument_list|)
expr_stmt|;
block|}
comment|/* |x| in [64, o_threshold], return correctly-overflowing exp(|x|)/2 */
if|if
condition|(
name|fabsl
argument_list|(
name|x
argument_list|)
operator|<=
name|o_threshold
condition|)
name|RETURNI
argument_list|(
name|hexpl
argument_list|(
name|fabsl
argument_list|(
name|x
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|/* |x|> o_threshold, cosh(x) overflow */
name|RETURNI
argument_list|(
name|huge
operator|*
name|huge
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

