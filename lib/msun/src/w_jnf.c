begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* w_jnf.c -- float version of w_jn.c.  * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.  */
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
name|float
name|jnf
parameter_list|(
name|int
name|n
parameter_list|,
name|float
name|x
parameter_list|)
comment|/* wrapper jnf */
else|#
directive|else
function|float jnf
parameter_list|(
name|n
parameter_list|,
name|x
parameter_list|)
comment|/* wrapper jnf */
name|float
name|x
decl_stmt|;
name|int
name|n
decl_stmt|;
endif|#
directive|endif
block|{
ifdef|#
directive|ifdef
name|_IEEE_LIBM
return|return
name|__ieee754_jnf
argument_list|(
name|n
argument_list|,
name|x
argument_list|)
return|;
else|#
directive|else
name|float
name|z
decl_stmt|;
name|z
operator|=
name|__ieee754_jnf
argument_list|(
name|n
argument_list|,
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|_LIB_VERSION
operator|==
name|_IEEE_
operator|||
name|isnanf
argument_list|(
name|x
argument_list|)
condition|)
return|return
name|z
return|;
if|if
condition|(
name|fabsf
argument_list|(
name|x
argument_list|)
operator|>
operator|(
name|float
operator|)
name|X_TLOSS
condition|)
block|{
comment|/* jn(|x|>X_TLOSS,n) */
return|return
operator|(
name|float
operator|)
name|__kernel_standard
argument_list|(
operator|(
name|double
operator|)
name|n
argument_list|,
operator|(
name|double
operator|)
name|x
argument_list|,
literal|138
argument_list|)
return|;
block|}
else|else
return|return
name|z
return|;
endif|#
directive|endif
block|}
end_function

end_unit

