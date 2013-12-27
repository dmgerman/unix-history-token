begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* from: FreeBSD: head/lib/msun/src/e_acosh.c 176451 2008-02-22 02:30:36Z das */
end_comment

begin_comment
comment|/* @(#)s_asinh.c 5.1 93/09/24 */
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
comment|/*  * See s_asinh.c for complete comments.  *  * Converted to long double by David Schultz<das@FreeBSD.ORG> and  * Bruce D. Evans.  */
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

begin_comment
comment|/* EXP_LARGE is the threshold above which we use asinh(x) ~= log(2x). */
end_comment

begin_comment
comment|/* EXP_TINY is the threshold below which we use asinh(x) ~= x. */
end_comment

begin_if
if|#
directive|if
name|LDBL_MANT_DIG
operator|==
literal|64
end_if

begin_define
define|#
directive|define
name|EXP_LARGE
value|34
end_define

begin_define
define|#
directive|define
name|EXP_TINY
value|-34
end_define

begin_elif
elif|#
directive|elif
name|LDBL_MANT_DIG
operator|==
literal|113
end_elif

begin_define
define|#
directive|define
name|EXP_LARGE
value|58
end_define

begin_define
define|#
directive|define
name|EXP_TINY
value|-58
end_define

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
name|double
name|one
init|=
literal|1.00000000000000000000e+00
decl_stmt|,
comment|/* 0x3FF00000, 0x00000000 */
name|huge
init|=
literal|1.00000000000000000000e+300
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|LDBL_MANT_DIG
operator|==
literal|64
end_if

begin_decl_stmt
specifier|static
specifier|const
name|union
name|IEEEl2bits
name|u_ln2
init|=
name|LD80C
argument_list|(
literal|0xb17217f7d1cf79ac
argument_list|,
operator|-
literal|1
argument_list|,
literal|6.93147180559945309417e-1L
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ln2
value|u_ln2.e
end_define

begin_elif
elif|#
directive|elif
name|LDBL_MANT_DIG
operator|==
literal|113
end_elif

begin_decl_stmt
specifier|static
specifier|const
name|long
name|double
name|ln2
init|=
literal|6.93147180559945309417232121458176568e-1L
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0x162e42fefa39ef35793c7673007e6.0p-113 */
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

begin_function
name|long
name|double
name|asinhl
parameter_list|(
name|long
name|double
name|x
parameter_list|)
block|{
name|long
name|double
name|t
decl_stmt|,
name|w
decl_stmt|;
name|uint16_t
name|hx
decl_stmt|,
name|ix
decl_stmt|;
name|ENTERI
argument_list|()
expr_stmt|;
name|GET_LDBL_EXPSIGN
argument_list|(
name|hx
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|ix
operator|=
name|hx
operator|&
literal|0x7fff
expr_stmt|;
if|if
condition|(
name|ix
operator|>=
literal|0x7fff
condition|)
name|RETURNI
argument_list|(
name|x
operator|+
name|x
argument_list|)
expr_stmt|;
comment|/* x is inf, NaN or misnormal */
if|if
condition|(
name|ix
operator|<
name|BIAS
operator|+
name|EXP_TINY
condition|)
block|{
comment|/* |x|< TINY, or misnormal */
if|if
condition|(
name|huge
operator|+
name|x
operator|>
name|one
condition|)
name|RETURNI
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|/* return x inexact except 0 */
block|}
if|if
condition|(
name|ix
operator|>=
name|BIAS
operator|+
name|EXP_LARGE
condition|)
block|{
comment|/* |x|>= LARGE, or misnormal */
name|w
operator|=
name|logl
argument_list|(
name|fabsl
argument_list|(
name|x
argument_list|)
argument_list|)
operator|+
name|ln2
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ix
operator|>=
literal|0x4000
condition|)
block|{
comment|/* LARGE> |x|>= 2.0, or misnormal */
name|t
operator|=
name|fabsl
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|w
operator|=
name|logl
argument_list|(
literal|2.0
operator|*
name|t
operator|+
name|one
operator|/
operator|(
name|sqrtl
argument_list|(
name|x
operator|*
name|x
operator|+
name|one
argument_list|)
operator|+
name|t
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* 2.0> |x|>= TINY, or misnormal */
name|t
operator|=
name|x
operator|*
name|x
expr_stmt|;
name|w
operator|=
name|log1pl
argument_list|(
name|fabsl
argument_list|(
name|x
argument_list|)
operator|+
name|t
operator|/
operator|(
name|one
operator|+
name|sqrtl
argument_list|(
name|one
operator|+
name|t
argument_list|)
operator|)
argument_list|)
expr_stmt|;
block|}
name|RETURNI
argument_list|(
operator|(
name|hx
operator|&
literal|0x8000
operator|)
operator|==
literal|0
condition|?
name|w
else|:
operator|-
name|w
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

