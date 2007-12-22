begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)s_floor.c 5.1 93/09/24 */
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
comment|/*  * truncf(x)  * Return x rounded toward 0 to integral value  * Method:  *	Bit twiddling.  * Exception:  *	Inexact flag raised if x not equal to truncf(x).  */
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

begin_decl_stmt
specifier|static
specifier|const
name|float
name|huge
init|=
literal|1.0e30F
decl_stmt|;
end_decl_stmt

begin_function
name|float
name|truncf
parameter_list|(
name|float
name|x
parameter_list|)
block|{
name|int32_t
name|i0
decl_stmt|,
name|j0
decl_stmt|;
name|u_int32_t
name|i
decl_stmt|;
name|GET_FLOAT_WORD
argument_list|(
name|i0
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|j0
operator|=
operator|(
operator|(
name|i0
operator|>>
literal|23
operator|)
operator|&
literal|0xff
operator|)
operator|-
literal|0x7f
expr_stmt|;
if|if
condition|(
name|j0
operator|<
literal|23
condition|)
block|{
if|if
condition|(
name|j0
operator|<
literal|0
condition|)
block|{
comment|/* raise inexact if x != 0 */
if|if
condition|(
name|huge
operator|+
name|x
operator|>
literal|0.0F
condition|)
comment|/* |x|<1, so return 0*sign(x) */
name|i0
operator|&=
literal|0x80000000
expr_stmt|;
block|}
else|else
block|{
name|i
operator|=
operator|(
literal|0x007fffff
operator|)
operator|>>
name|j0
expr_stmt|;
if|if
condition|(
operator|(
name|i0
operator|&
name|i
operator|)
operator|==
literal|0
condition|)
return|return
name|x
return|;
comment|/* x is integral */
if|if
condition|(
name|huge
operator|+
name|x
operator|>
literal|0.0F
condition|)
comment|/* raise inexact flag */
name|i0
operator|&=
operator|(
operator|~
name|i
operator|)
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|j0
operator|==
literal|0x80
condition|)
return|return
name|x
operator|+
name|x
return|;
comment|/* inf or NaN */
else|else
return|return
name|x
return|;
comment|/* x is integral */
block|}
name|SET_FLOAT_WORD
argument_list|(
name|x
argument_list|,
name|i0
argument_list|)
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

end_unit

