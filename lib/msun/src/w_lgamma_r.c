begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)wr_lgamma.c 5.1 93/09/24 */
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
literal|"$Id: w_lgamma_r.c,v 1.1.1.1 1994/08/19 09:39:54 jkh Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * wrapper double lgamma_r(double x, int *signgamp)  */
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

begin_function
name|double
name|lgamma_r
parameter_list|(
name|double
name|x
parameter_list|,
name|int
modifier|*
name|signgamp
parameter_list|)
comment|/* wrapper lgamma_r */
else|#
directive|else
function|double lgamma_r
parameter_list|(
name|x
parameter_list|,
name|signgamp
parameter_list|)
comment|/* wrapper lgamma_r */
name|double
name|x
decl_stmt|;
name|int
modifier|*
name|signgamp
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
name|signgamp
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
name|signgamp
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

