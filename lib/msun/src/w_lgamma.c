begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)w_lgamma.c 5.1 93/09/24 */
end_comment

begin_comment
comment|/*  * ====================================================  * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.  *  * Developed at SunPro, a Sun Microsystems, Inc. business.  * Permission to use, copy, modify, and distribute this  * software is freely granted, provided that this notice   * is preserved.  * ====================================================  */
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
literal|"$Id: w_lgamma.c,v 1.4 1994/08/10 20:34:53 jtc Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* double lgamma(double x)  * Return the logarithm of the Gamma function of x.  *  * Method: call __ieee754_lgamma_r  */
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

begin_decl_stmt
specifier|extern
name|int
name|signgam
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function
name|double
name|lgamma
parameter_list|(
name|double
name|x
parameter_list|)
else|#
directive|else
function|double lgamma
parameter_list|(
name|x
parameter_list|)
name|double
name|x
decl_stmt|;
endif|#
directive|endif
block|{
ifdef|#
directive|ifdef
name|_IEEE_LIBM
return|return
name|__ieee754_lgamma_r
argument_list|(
name|x
argument_list|,
operator|&
name|signgam
argument_list|)
return|;
else|#
directive|else
name|double
name|y
decl_stmt|;
name|y
operator|=
name|__ieee754_lgamma_r
argument_list|(
name|x
argument_list|,
operator|&
name|signgam
argument_list|)
expr_stmt|;
if|if
condition|(
name|_LIB_VERSION
operator|==
name|_IEEE_
condition|)
return|return
name|y
return|;
if|if
condition|(
operator|!
name|finite
argument_list|(
name|y
argument_list|)
operator|&&
name|finite
argument_list|(
name|x
argument_list|)
condition|)
block|{
if|if
condition|(
name|floor
argument_list|(
name|x
argument_list|)
operator|==
name|x
operator|&&
name|x
operator|<=
literal|0.0
condition|)
return|return
name|__kernel_standard
argument_list|(
name|x
argument_list|,
name|x
argument_list|,
literal|15
argument_list|)
return|;
comment|/* lgamma pole */
else|else
return|return
name|__kernel_standard
argument_list|(
name|x
argument_list|,
name|x
argument_list|,
literal|14
argument_list|)
return|;
comment|/* lgamma overflow */
block|}
else|else
return|return
name|y
return|;
endif|#
directive|endif
block|}
end_function

end_unit

