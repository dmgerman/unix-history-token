begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* from: FreeBSD: head/lib/msun/src/e_sinhl.c XXX */
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
comment|/*  * See e_sinh.c for complete comments.  *  * Converted to long double by Bruce D. Evans.  */
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
name|long
name|double
name|shuge
init|=
literal|0x1p16383L
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
comment|/*  * Domain [-1, 1], range ~[-6.6749e-22, 6.6749e-22]:  * |sinh(x)/x - s(x)|< 2**-70.3  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|union
name|IEEEl2bits
name|S3u
init|=
name|LD80C
argument_list|(
literal|0xaaaaaaaaaaaaaaaa
argument_list|,
operator|-
literal|3
argument_list|,
literal|1.66666666666666666658e-1L
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|S3
value|S3u.e
end_define

begin_decl_stmt
specifier|static
specifier|const
name|double
name|S5
init|=
literal|8.3333333333333332e-3
decl_stmt|,
comment|/*  0x11111111111111.0p-59 */
name|S7
init|=
literal|1.9841269841270074e-4
decl_stmt|,
comment|/*  0x1a01a01a01a070.0p-65 */
name|S9
init|=
literal|2.7557319223873889e-6
decl_stmt|,
comment|/*  0x171de3a5565fe6.0p-71 */
name|S11
init|=
literal|2.5052108406704084e-8
decl_stmt|,
comment|/*  0x1ae6456857530f.0p-78 */
name|S13
init|=
literal|1.6059042748655297e-10
decl_stmt|,
comment|/*  0x161245fa910697.0p-85 */
name|S15
init|=
literal|7.6470006914396920e-13
decl_stmt|,
comment|/*  0x1ae7ce4eff2792.0p-93 */
name|S17
init|=
literal|2.8346142308424267e-15
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  0x19882ce789ffc6.0p-101 */
end_comment

begin_elif
elif|#
directive|elif
name|LDBL_MANT_DIG
operator|==
literal|113
end_elif

begin_comment
comment|/*  * Domain [-1, 1], range ~[-2.9673e-36, 2.9673e-36]:  * |sinh(x)/x - s(x)|< 2**-118.0  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|long
name|double
name|S3
init|=
literal|1.66666666666666666666666666666666033e-1L
decl_stmt|,
comment|/*  0x1555555555555555555555555553b.0p-115L */
name|S5
init|=
literal|8.33333333333333333333333333337643193e-3L
decl_stmt|,
comment|/*  0x111111111111111111111111180f5.0p-119L */
name|S7
init|=
literal|1.98412698412698412698412697391263199e-4L
decl_stmt|,
comment|/*  0x1a01a01a01a01a01a01a0176aad11.0p-125L */
name|S9
init|=
literal|2.75573192239858906525574406205464218e-6L
decl_stmt|,
comment|/*  0x171de3a556c7338faac243aaa9592.0p-131L */
name|S11
init|=
literal|2.50521083854417187749675637460977997e-8L
decl_stmt|,
comment|/*  0x1ae64567f544e38fe59b3380d7413.0p-138L */
name|S13
init|=
literal|1.60590438368216146368737762431552702e-10L
decl_stmt|,
comment|/*  0x16124613a86d098059c7620850fc2.0p-145L */
name|S15
init|=
literal|7.64716373181980539786802470969096440e-13L
decl_stmt|,
comment|/*  0x1ae7f3e733b814193af09ce723043.0p-153L */
name|S17
init|=
literal|2.81145725434775409870584280722701574e-15L
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  0x1952c77030c36898c3fd0b6dfc562.0p-161L */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|double
name|S19
init|=
literal|8.2206352435411005e-18
decl_stmt|,
comment|/*  0x12f49b4662b86d.0p-109 */
name|S21
init|=
literal|1.9572943931418891e-20
decl_stmt|,
comment|/*  0x171b8f2fab9628.0p-118 */
name|S23
init|=
literal|3.8679983530666939e-23
decl_stmt|,
comment|/*  0x17617002b73afc.0p-127 */
name|S25
init|=
literal|6.5067867911512749e-26
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  0x1423352626048a.0p-136 */
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
name|sinhl
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
decl_stmt|,
name|s
decl_stmt|;
name|int16_t
name|ix
decl_stmt|,
name|jx
decl_stmt|;
name|GET_LDBL_EXPSIGN
argument_list|(
name|jx
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|ix
operator|=
name|jx
operator|&
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
operator|+
name|x
return|;
name|ENTERI
argument_list|()
expr_stmt|;
name|s
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|jx
operator|<
literal|0
condition|)
name|s
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* |x|< 64, return x, s(x), or accurate s*(exp(|x|)/2-1/exp(|x|)/2) */
if|if
condition|(
name|ix
operator|<
literal|0x4005
condition|)
block|{
comment|/* |x|<64 */
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
comment|/* |x|<TINY */
if|if
condition|(
name|shuge
operator|+
name|x
operator|>
literal|1
condition|)
name|RETURNI
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|/* sinh(tiny) = tiny with inexact */
if|if
condition|(
name|ix
operator|<
literal|0x3fff
condition|)
block|{
comment|/* |x|<1 */
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
name|S17
operator|*
name|x2
operator|+
name|S15
operator|)
operator|*
name|x4
operator|+
operator|(
name|S13
operator|*
name|x2
operator|+
name|S11
operator|)
operator|)
operator|*
operator|(
name|x2
operator|*
name|x
operator|*
name|x4
operator|*
name|x4
operator|)
operator|+
operator|(
operator|(
name|S9
operator|*
name|x2
operator|+
name|S7
operator|)
operator|*
name|x2
operator|+
name|S5
operator|)
operator|*
operator|(
name|x2
operator|*
name|x
operator|*
name|x2
operator|)
operator|+
name|S3
operator|*
operator|(
name|x2
operator|*
name|x
operator|)
operator|+
name|x
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
name|S25
operator|*
name|dx2
operator|+
name|S23
operator|)
operator|*
name|dx2
operator|+
name|S21
operator|)
operator|*
name|x2
operator|+
name|S19
operator|)
operator|*
name|x2
operator|+
name|S17
operator|)
operator|*
name|x2
operator|+
name|S15
operator|)
operator|*
name|x2
operator|+
name|S13
operator|)
operator|*
name|x2
operator|+
name|S11
operator|)
operator|*
name|x2
operator|+
name|S9
operator|)
operator|*
name|x2
operator|+
name|S7
operator|)
operator|*
name|x2
operator|+
name|S5
operator|)
operator|*
operator|(
name|x2
operator|*
name|x
operator|*
name|x2
operator|)
operator|+
name|S3
operator|*
operator|(
name|x2
operator|*
name|x
operator|)
operator|+
name|x
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
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
name|s
operator|*
operator|(
name|lo
operator|-
literal|0.25
operator|/
operator|(
name|hi
operator|+
name|lo
operator|)
operator|+
name|hi
operator|)
argument_list|)
expr_stmt|;
block|}
comment|/* |x| in [64, o_threshold], return correctly-overflowing s*exp(|x|)/2 */
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
name|s
operator|*
name|hexpl
argument_list|(
name|fabsl
argument_list|(
name|x
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|/* |x|> o_threshold, sinh(x) overflow */
return|return
name|x
operator|*
name|shuge
return|;
block|}
end_function

end_unit

