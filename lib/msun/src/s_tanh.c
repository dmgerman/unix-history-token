begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)s_tanh.c 5.1 93/09/24 */
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

begin_comment
comment|/* Tanh(x)  * Return the Hyperbolic Tangent of x  *  * Method :  *				       x    -x  *				      e  - e  *	0. tanh(x) is defined to be -----------  *				       x    -x  *				      e  + e  *	1. reduce x to non-negative by tanh(-x) = -tanh(x).  *	2.  0<= x<= 2**-55 : tanh(x) := x*(one+x)  *					        -t  *	    2**-55<  x<=  1     : tanh(x) := -----; t = expm1(-2x)  *					       t + 2  *						     2  *	    1<= x<=  22.0  : tanh(x) := 1-  ----- ; t=expm1(2x)  *						   t + 2  *	    22.0<  x<= INF    : tanh(x) := 1.  *  * Special cases:  *	tanh(NaN) is NaN;  *	only tanh(0)=0 is exact for finite argument.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_decl_stmt
specifier|static
specifier|const
name|double
name|one
init|=
literal|1.0
decl_stmt|,
name|two
init|=
literal|2.0
decl_stmt|,
name|tiny
init|=
literal|1.0e-300
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|double
name|one
init|=
literal|1.0
decl_stmt|,
name|two
init|=
literal|2.0
decl_stmt|,
name|tiny
init|=
literal|1.0e-300
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function
name|double
name|tanh
parameter_list|(
name|double
name|x
parameter_list|)
else|#
directive|else
function|double tanh
parameter_list|(
name|x
parameter_list|)
name|double
name|x
decl_stmt|;
endif|#
directive|endif
block|{
name|double
name|t
decl_stmt|,
name|z
decl_stmt|;
name|int32_t
name|jx
decl_stmt|,
name|ix
decl_stmt|;
comment|/* High word of |x|. */
name|GET_HIGH_WORD
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
literal|0x7fffffff
expr_stmt|;
comment|/* x is INF or NaN */
if|if
condition|(
name|ix
operator|>=
literal|0x7ff00000
condition|)
block|{
if|if
condition|(
name|jx
operator|>=
literal|0
condition|)
return|return
name|one
operator|/
name|x
operator|+
name|one
return|;
comment|/* tanh(+-inf)=+-1 */
else|else
return|return
name|one
operator|/
name|x
operator|-
name|one
return|;
comment|/* tanh(NaN) = NaN */
block|}
comment|/* |x|< 22 */
if|if
condition|(
name|ix
operator|<
literal|0x40360000
condition|)
block|{
comment|/* |x|<22 */
if|if
condition|(
name|ix
operator|<
literal|0x3c800000
condition|)
comment|/* |x|<2**-55 */
return|return
name|x
operator|*
operator|(
name|one
operator|+
name|x
operator|)
return|;
comment|/* tanh(small) = small */
if|if
condition|(
name|ix
operator|>=
literal|0x3ff00000
condition|)
block|{
comment|/* |x|>=1  */
name|t
operator|=
name|expm1
argument_list|(
name|two
operator|*
name|fabs
argument_list|(
name|x
argument_list|)
argument_list|)
expr_stmt|;
name|z
operator|=
name|one
operator|-
name|two
operator|/
operator|(
name|t
operator|+
name|two
operator|)
expr_stmt|;
block|}
else|else
block|{
name|t
operator|=
name|expm1
argument_list|(
operator|-
name|two
operator|*
name|fabs
argument_list|(
name|x
argument_list|)
argument_list|)
expr_stmt|;
name|z
operator|=
operator|-
name|t
operator|/
operator|(
name|t
operator|+
name|two
operator|)
expr_stmt|;
block|}
comment|/* |x|> 22, return +-1 */
block|}
else|else
block|{
name|z
operator|=
name|one
operator|-
name|tiny
expr_stmt|;
comment|/* raised inexact flag */
block|}
return|return
operator|(
name|jx
operator|>=
literal|0
operator|)
condition|?
name|z
else|:
operator|-
name|z
return|;
block|}
end_function

end_unit

