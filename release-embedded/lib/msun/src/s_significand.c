begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)s_signif.c 5.1 93/09/24 */
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
comment|/*  * significand(x) computes just  * 	scalb(x, (double) -ilogb(x)),  * for exercising the fraction-part(F) IEEE 754-1985 test vector.  */
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
name|significand
parameter_list|(
name|double
name|x
parameter_list|)
block|{
return|return
name|__ieee754_scalb
argument_list|(
name|x
argument_list|,
operator|(
name|double
operator|)
operator|-
name|ilogb
argument_list|(
name|x
argument_list|)
argument_list|)
return|;
block|}
end_function

end_unit

