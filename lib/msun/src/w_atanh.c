begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)w_atanh.c 5.1 93/09/24 */
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
comment|/*  * wrapper atanh(x)  */
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
name|atanh
parameter_list|(
name|double
name|x
parameter_list|)
comment|/* wrapper atanh */
else|#
directive|else
function|double atanh
parameter_list|(
name|x
parameter_list|)
comment|/* wrapper atanh */
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
name|__ieee754_atanh
argument_list|(
name|x
argument_list|)
return|;
else|#
directive|else
name|double
name|z
decl_stmt|,
name|y
decl_stmt|;
name|z
operator|=
name|__ieee754_atanh
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
name|y
operator|=
name|fabs
argument_list|(
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|y
operator|>=
literal|1.0
condition|)
block|{
if|if
condition|(
name|y
operator|>
literal|1.0
condition|)
return|return
name|__kernel_standard
argument_list|(
name|x
argument_list|,
name|x
argument_list|,
literal|30
argument_list|)
return|;
comment|/* atanh(|x|>1) */
else|else
return|return
name|__kernel_standard
argument_list|(
name|x
argument_list|,
name|x
argument_list|,
literal|31
argument_list|)
return|;
comment|/* atanh(|x|==1) */
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

