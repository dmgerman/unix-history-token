begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)w_log10.c 5.1 93/09/24 */
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
comment|/*  * wrapper log10(X)  */
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
name|log10
parameter_list|(
name|double
name|x
parameter_list|)
comment|/* wrapper log10 */
else|#
directive|else
function|double log10
parameter_list|(
name|x
parameter_list|)
comment|/* wrapper log10 */
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
name|__ieee754_log10
argument_list|(
name|x
argument_list|)
return|;
else|#
directive|else
name|double
name|z
decl_stmt|;
name|z
operator|=
name|__ieee754_log10
argument_list|(
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|_LIB_VERSION
operator|==
name|_IEEE_
operator|||
name|isnan
argument_list|(
name|x
argument_list|)
condition|)
return|return
name|z
return|;
if|if
condition|(
name|x
operator|<=
literal|0.0
condition|)
block|{
if|if
condition|(
name|x
operator|==
literal|0.0
condition|)
return|return
name|__kernel_standard
argument_list|(
name|x
argument_list|,
name|x
argument_list|,
literal|18
argument_list|)
return|;
comment|/* log10(0) */
else|else
return|return
name|__kernel_standard
argument_list|(
name|x
argument_list|,
name|x
argument_list|,
literal|19
argument_list|)
return|;
comment|/* log10(x<0) */
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

