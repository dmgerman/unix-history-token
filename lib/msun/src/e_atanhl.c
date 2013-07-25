begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* from: FreeBSD: head/lib/msun/src/e_atanh.c 176451 2008-02-22 02:30:36Z das */
end_comment

begin_comment
comment|/* @(#)e_atanh.c 1.3 95/01/18 */
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
comment|/*  * See e_atanh.c for complete comments.  *  * Converted to long double by David Schultz<das@FreeBSD.ORG> and  * Bruce D. Evans.  */
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
comment|/* EXP_TINY is the threshold below which we use atanh(x) ~= x. */
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
literal|1.0
decl_stmt|,
name|huge
init|=
literal|1e300
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|double
name|zero
init|=
literal|0.0
decl_stmt|;
end_decl_stmt

begin_function
name|long
name|double
name|atanhl
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
literal|0x3fff
condition|)
comment|/* |x|>= 1, or NaN or misnormal */
name|RETURNI
argument_list|(
name|fabsl
argument_list|(
name|x
argument_list|)
operator|==
literal|1
condition|?
name|x
operator|/
name|zero
else|:
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
if|if
condition|(
name|ix
operator|<
name|BIAS
operator|+
name|EXP_TINY
operator|&&
operator|(
name|huge
operator|+
name|x
operator|)
operator|>
name|zero
condition|)
name|RETURNI
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|/* x is tiny */
name|SET_LDBL_EXPSIGN
argument_list|(
name|x
argument_list|,
name|ix
argument_list|)
expr_stmt|;
if|if
condition|(
name|ix
operator|<
literal|0x3ffe
condition|)
block|{
comment|/* |x|< 0.5, or misnormal */
name|t
operator|=
name|x
operator|+
name|x
expr_stmt|;
name|t
operator|=
literal|0.5
operator|*
name|log1pl
argument_list|(
name|t
operator|+
name|t
operator|*
name|x
operator|/
operator|(
name|one
operator|-
name|x
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
name|t
operator|=
literal|0.5
operator|*
name|log1pl
argument_list|(
operator|(
name|x
operator|+
name|x
operator|)
operator|/
operator|(
name|one
operator|-
name|x
operator|)
argument_list|)
expr_stmt|;
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
name|t
else|:
operator|-
name|t
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

