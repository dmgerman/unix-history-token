begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* from: @(#)w_jn.c 5.1 93/09/24 */
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
comment|/*  * wrapper yn(int n, double x)  */
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
name|yn
parameter_list|(
name|int
name|n
parameter_list|,
name|double
name|x
parameter_list|)
comment|/* wrapper yn */
else|#
directive|else
function|double yn
parameter_list|(
name|n
parameter_list|,
name|x
parameter_list|)
comment|/* wrapper yn */
name|double
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
name|__ieee754_yn
argument_list|(
name|n
argument_list|,
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
name|__ieee754_yn
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
comment|/* d= -one/(x-x); */
return|return
name|__kernel_standard
argument_list|(
operator|(
name|double
operator|)
name|n
argument_list|,
name|x
argument_list|,
literal|12
argument_list|)
return|;
else|else
comment|/* d = zero/(x-x); */
return|return
name|__kernel_standard
argument_list|(
operator|(
name|double
operator|)
name|n
argument_list|,
name|x
argument_list|,
literal|13
argument_list|)
return|;
block|}
if|if
condition|(
name|x
operator|>
name|X_TLOSS
condition|)
block|{
return|return
name|__kernel_standard
argument_list|(
operator|(
name|double
operator|)
name|n
argument_list|,
name|x
argument_list|,
literal|39
argument_list|)
return|;
comment|/* yn(x>X_TLOSS,n) */
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

