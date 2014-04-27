begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)e_cosh.c 1.3 95/01/18 */
end_comment

begin_comment
comment|/*  * ====================================================  * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.  *  * Developed at SunSoft, a Sun Microsystems, Inc. business.  * Permission to use, copy, modify, and distribute this  * software is freely granted, provided that this notice   * is preserved.  * ====================================================  */
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
comment|/* __ieee754_cosh(x)  * Method :   * mathematically cosh(x) if defined to be (exp(x)+exp(-x))/2  *	1. Replace x by |x| (cosh(x) = cosh(-x)).   *	2.   *		                                        [ exp(x) - 1 ]^2   *	    0<= x<= ln2/2  :  cosh(x) := 1 + -------------------  *			       			           2*exp(x)  *  *		                                  exp(x) +  1/exp(x)  *	    ln2/2<= x<= 22     :  cosh(x) := -------------------  *			       			          2  *	    22<= x<= lnovft :  cosh(x) := exp(x)/2   *	    lnovft<= x<= ln2ovft:  cosh(x) := exp(x/2)/2 * exp(x/2)  *	    ln2ovft<  x	    :  cosh(x) := huge*huge (overflow)  *  * Special cases:  *	cosh(x) is |x| if x is +INF, -INF, or NaN.  *	only cosh(0)=1 is exact for finite x.  */
end_comment

begin_include
include|#
directive|include
file|<float.h>
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

begin_decl_stmt
specifier|static
specifier|const
name|double
name|one
init|=
literal|1.0
decl_stmt|,
name|half
init|=
literal|0.5
decl_stmt|,
name|huge
init|=
literal|1.0e300
decl_stmt|;
end_decl_stmt

begin_function
name|double
name|__ieee754_cosh
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|double
name|t
decl_stmt|,
name|w
decl_stmt|;
name|int32_t
name|ix
decl_stmt|;
comment|/* High word of |x|. */
name|GET_HIGH_WORD
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
comment|/* x is INF or NaN */
if|if
condition|(
name|ix
operator|>=
literal|0x7ff00000
condition|)
return|return
name|x
operator|*
name|x
return|;
comment|/* |x| in [0,0.5*ln2], return 1+expm1(|x|)^2/(2*exp(|x|)) */
if|if
condition|(
name|ix
operator|<
literal|0x3fd62e43
condition|)
block|{
name|t
operator|=
name|expm1
argument_list|(
name|fabs
argument_list|(
name|x
argument_list|)
argument_list|)
expr_stmt|;
name|w
operator|=
name|one
operator|+
name|t
expr_stmt|;
if|if
condition|(
name|ix
operator|<
literal|0x3c800000
condition|)
return|return
name|w
return|;
comment|/* cosh(tiny) = 1 */
return|return
name|one
operator|+
operator|(
name|t
operator|*
name|t
operator|)
operator|/
operator|(
name|w
operator|+
name|w
operator|)
return|;
block|}
comment|/* |x| in [0.5*ln2,22], return (exp(|x|)+1/exp(|x|)/2; */
if|if
condition|(
name|ix
operator|<
literal|0x40360000
condition|)
block|{
name|t
operator|=
name|__ieee754_exp
argument_list|(
name|fabs
argument_list|(
name|x
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|half
operator|*
name|t
operator|+
name|half
operator|/
name|t
return|;
block|}
comment|/* |x| in [22, log(maxdouble)] return half*exp(|x|) */
if|if
condition|(
name|ix
operator|<
literal|0x40862E42
condition|)
return|return
name|half
operator|*
name|__ieee754_exp
argument_list|(
name|fabs
argument_list|(
name|x
argument_list|)
argument_list|)
return|;
comment|/* |x| in [log(maxdouble), overflowthresold] */
if|if
condition|(
name|ix
operator|<=
literal|0x408633CE
condition|)
return|return
name|__ldexp_exp
argument_list|(
name|fabs
argument_list|(
name|x
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
return|;
comment|/* |x|> overflowthresold, cosh(x) overflow */
return|return
name|huge
operator|*
name|huge
return|;
block|}
end_function

begin_if
if|#
directive|if
operator|(
name|LDBL_MANT_DIG
operator|==
literal|53
operator|)
end_if

begin_expr_stmt
name|__weak_reference
argument_list|(
name|cosh
argument_list|,
name|coshl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

