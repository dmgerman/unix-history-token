begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* e_gammaf.c -- float version of e_gamma.c.  * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.  */
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
literal|"$Id: e_gammaf.c,v 1.1 1994/08/10 20:30:53 jtc Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ieee754_gammaf(x)  * Return the logarithm of the Gamma function of x.  *  * Method: call __ieee754_gammaf_r  */
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
name|float
name|__ieee754_gammaf
parameter_list|(
name|float
name|x
parameter_list|)
else|#
directive|else
function|float __ieee754_gammaf
parameter_list|(
name|x
parameter_list|)
name|float
name|x
decl_stmt|;
endif|#
directive|endif
block|{
return|return
name|__ieee754_gammaf_r
argument_list|(
name|x
argument_list|,
operator|&
name|signgam
argument_list|)
return|;
block|}
end_function

end_unit

