begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* s_tanf.c -- float version of s_tan.c.  * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.  */
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
name|tanf
parameter_list|(
name|float
name|x
parameter_list|)
else|#
directive|else
function|float tanf
parameter_list|(
name|x
parameter_list|)
name|float
name|x
decl_stmt|;
endif|#
directive|endif
block|{
name|float
name|y
index|[
literal|2
index|]
decl_stmt|,
name|z
init|=
literal|0.0
decl_stmt|;
name|int32_t
name|n
decl_stmt|,
name|ix
decl_stmt|;
name|GET_FLOAT_WORD
argument_list|(
name|ix
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|/* |x| ~< pi/4 */
name|ix
operator|&=
literal|0x7fffffff
expr_stmt|;
if|if
condition|(
name|ix
operator|<=
literal|0x3f490fda
condition|)
return|return
name|__kernel_tanf
argument_list|(
name|x
argument_list|,
name|z
argument_list|,
literal|1
argument_list|)
return|;
comment|/* tan(Inf or NaN) is NaN */
elseif|else
if|if
condition|(
name|ix
operator|>=
literal|0x7f800000
condition|)
return|return
name|x
operator|-
name|x
return|;
comment|/* NaN */
comment|/* argument reduction needed */
else|else
block|{
name|n
operator|=
name|__ieee754_rem_pio2f
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
return|return
name|__kernel_tanf
argument_list|(
name|y
index|[
literal|0
index|]
argument_list|,
name|y
index|[
literal|1
index|]
argument_list|,
literal|1
operator|-
operator|(
operator|(
name|n
operator|&
literal|1
operator|)
operator|<<
literal|1
operator|)
argument_list|)
return|;
comment|/*   1 -- n even 							      -1 -- n odd */
block|}
block|}
end_function

end_unit

