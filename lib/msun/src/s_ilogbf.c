begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* s_ilogbf.c -- float version of s_ilogb.c.  * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.  */
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
name|int
name|ilogbf
parameter_list|(
name|float
name|x
parameter_list|)
else|#
directive|else
function|int ilogbf
parameter_list|(
name|x
parameter_list|)
name|float
name|x
decl_stmt|;
endif|#
directive|endif
block|{
name|int32_t
name|hx
decl_stmt|,
name|ix
decl_stmt|;
name|GET_FLOAT_WORD
argument_list|(
name|hx
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|hx
operator|&=
literal|0x7fffffff
expr_stmt|;
if|if
condition|(
name|hx
operator|<
literal|0x00800000
condition|)
block|{
if|if
condition|(
name|hx
operator|==
literal|0
condition|)
return|return
literal|0x80000001
return|;
comment|/* ilogb(0) = 0x80000001 */
else|else
comment|/* subnormal x */
for|for
control|(
name|ix
operator|=
operator|-
literal|126
operator|,
name|hx
operator|<<=
literal|8
init|;
name|hx
operator|>
literal|0
condition|;
name|hx
operator|<<=
literal|1
control|)
name|ix
operator|-=
literal|1
expr_stmt|;
return|return
name|ix
return|;
block|}
elseif|else
if|if
condition|(
name|hx
operator|<
literal|0x7f800000
condition|)
return|return
operator|(
name|hx
operator|>>
literal|23
operator|)
operator|-
literal|127
return|;
else|else
return|return
literal|0x7fffffff
return|;
block|}
end_function

end_unit

