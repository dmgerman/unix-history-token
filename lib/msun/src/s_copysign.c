begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)s_copysign.c 5.1 93/09/24 */
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
comment|/*  * copysign(double x, double y)  * copysign(x,y) returns a value with the magnitude of x and  * with the sign bit of y.  */
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
name|__generic_copysign
parameter_list|(
name|double
name|x
parameter_list|,
name|double
name|y
parameter_list|)
else|#
directive|else
function|double __generic_copysign
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
name|double
name|x
decl_stmt|,
name|y
decl_stmt|;
endif|#
directive|endif
block|{
name|u_int32_t
name|hx
decl_stmt|,
name|hy
decl_stmt|;
name|GET_HIGH_WORD
argument_list|(
name|hx
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|GET_HIGH_WORD
argument_list|(
name|hy
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|SET_HIGH_WORD
argument_list|(
name|x
argument_list|,
operator|(
name|hx
operator|&
literal|0x7fffffff
operator|)
operator||
operator|(
name|hy
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

