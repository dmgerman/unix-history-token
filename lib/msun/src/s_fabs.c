begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)s_fabs.c 5.1 93/09/24 */
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
comment|/*  * fabs(x) returns the absolute value of x.  */
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
name|double
name|fabs
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|u_int32_t
name|high
decl_stmt|;
name|GET_HIGH_WORD
argument_list|(
name|high
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|SET_HIGH_WORD
argument_list|(
name|x
argument_list|,
name|high
operator|&
literal|0x7fffffff
argument_list|)
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

end_unit

