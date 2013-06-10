begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* from: FreeBSD: head/lib/msun/src/e_acosh.c 176451 2008-02-22 02:30:36Z das */
end_comment

begin_comment
comment|/* @(#)e_acosh.c 1.3 95/01/18 */
end_comment

begin_comment
comment|/*  * ====================================================  * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.  *  * Developed at SunSoft, a Sun Microsystems, Inc. business.  * Permission to use, copy, modify, and distribute this  * software is freely granted, provided that this notice   * is preserved.  * ====================================================  *  */
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
comment|/*  * See e_acosh.c for complete comments.  *  * Converted to long double by David Schultz<das@FreeBSD.ORG> and  * Bruce D. Evans.  */
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
comment|/* EXP_LARGE is the threshold above which we use acosh(x) ~= log(2x). */
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
literal|1.0
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
name|acoshl
parameter_list|(
name|long
name|double
name|x
parameter_list|)
block|{
name|long
name|double
name|t
decl_stmt|;
name|int16_t
name|hx
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
if|if
condition|(
name|hx
operator|<
literal|0x3fff
condition|)
block|{
comment|/* x< 1, or misnormal */
name|RETURNI
argument_list|(
operator|(
name|x
operator|-
name|x
operator|)
operator|/
operator|(
name|x
operator|-
name|x
operator|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|hx
operator|>=
name|BIAS
operator|+
name|EXP_LARGE
condition|)
block|{
comment|/* x>= LARGE */
if|if
condition|(
name|hx
operator|>=
literal|0x7fff
condition|)
block|{
comment|/* x is inf, NaN or misnormal */
name|RETURNI
argument_list|(
name|x
operator|+
name|x
argument_list|)
expr_stmt|;
block|}
else|else
name|RETURNI
argument_list|(
name|logl
argument_list|(
name|x
argument_list|)
operator|+
name|ln2
argument_list|)
expr_stmt|;
comment|/* acosh(huge)=log(2x), or misnormal */
block|}
elseif|else
if|if
condition|(
name|hx
operator|==
literal|0x3fff
operator|&&
name|x
operator|==
literal|1
condition|)
block|{
name|RETURNI
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
comment|/* acosh(1) = 0 */
block|}
elseif|else
if|if
condition|(
name|hx
operator|>=
literal|0x4000
condition|)
block|{
comment|/* LARGE> x>= 2, or misnormal */
name|t
operator|=
name|x
operator|*
name|x
expr_stmt|;
name|RETURNI
argument_list|(
name|logl
argument_list|(
literal|2.0
operator|*
name|x
operator|-
name|one
operator|/
operator|(
name|x
operator|+
name|sqrtl
argument_list|(
name|t
operator|-
name|one
argument_list|)
operator|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* 1<x<2 */
name|t
operator|=
name|x
operator|-
name|one
expr_stmt|;
name|RETURNI
argument_list|(
name|log1pl
argument_list|(
name|t
operator|+
name|sqrtl
argument_list|(
literal|2.0
operator|*
name|t
operator|+
name|t
operator|*
name|t
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

