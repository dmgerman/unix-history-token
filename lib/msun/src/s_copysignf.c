begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* s_copysignf.c -- float version of s_copysign.c.  * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.  */
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
comment|/*  * copysignf(float x, float y)  * copysignf(x,y) returns a value with the magnitude of x and  * with the sign bit of y.  */
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
name|float
name|copysignf
parameter_list|(
name|float
name|x
parameter_list|,
name|float
name|y
parameter_list|)
else|#
directive|else
function|float copysignf
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
name|float
name|x
decl_stmt|,
name|y
decl_stmt|;
endif|#
directive|endif
block|{
name|u_int32_t
name|ix
decl_stmt|,
name|iy
decl_stmt|;
name|GET_FLOAT_WORD
argument_list|(
name|ix
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|GET_FLOAT_WORD
argument_list|(
name|iy
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|SET_FLOAT_WORD
argument_list|(
name|x
argument_list|,
operator|(
name|ix
operator|&
literal|0x7fffffff
operator|)
operator||
operator|(
name|iy
operator|&
literal|0x80000000
operator|)
argument_list|)
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

end_unit

