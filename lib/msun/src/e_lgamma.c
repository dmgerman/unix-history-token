begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)e_lgamma.c 1.3 95/01/18 */
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
comment|/* __ieee754_lgamma(x)  * Return the logarithm of the Gamma function of x.  *  * Method: call __ieee754_lgamma_r  */
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
specifier|extern
name|int
name|signgam
decl_stmt|;
end_decl_stmt

begin_function
name|double
name|__ieee754_lgamma
parameter_list|(
name|double
name|x
parameter_list|)
block|{
return|return
name|__ieee754_lgamma_r
argument_list|(
name|x
argument_list|,
operator|&
name|signgam
argument_list|)
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
name|lgamma
argument_list|,
name|lgammal
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

