begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* s_finitef.c -- float version of s_finite.c.  * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.  */
end_comment

begin_comment
comment|/*  * ====================================================  * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.  *  * Developed at SunPro, a Sun Microsystems, Inc. business.  * Permission to use, copy, modify, and distribute this  * software is freely granted, provided that this notice  * is preserved.  * ====================================================  */
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
comment|/*  * finitef(x) returns 1 is x is finite, else 0;  * no branching!  */
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

begin_function
name|int
name|finitef
parameter_list|(
name|float
name|x
parameter_list|)
block|{
name|int32_t
name|ix
decl_stmt|;
name|GET_FLOAT_WORD
argument_list|(
name|ix
argument_list|,
name|x
argument_list|)
expr_stmt|;
return|return
call|(
name|int
call|)
argument_list|(
call|(
name|u_int32_t
call|)
argument_list|(
operator|(
name|ix
operator|&
literal|0x7fffffff
operator|)
operator|-
literal|0x7f800000
argument_list|)
operator|>>
literal|31
argument_list|)
return|;
block|}
end_function

end_unit

