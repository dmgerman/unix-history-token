begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* s_logbf.c -- float version of s_logb.c.  * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.  */
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
name|logbf
parameter_list|(
name|float
name|x
parameter_list|)
else|#
directive|else
function|float logbf
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
name|ix
decl_stmt|;
name|GET_FLOAT_WORD
argument_list|(
name|ix
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|ix
operator|&=
literal|0x7fffffff
expr_stmt|;
comment|/* high |x| */
if|if
condition|(
name|ix
operator|==
literal|0
condition|)
return|return
operator|(
name|float
operator|)
operator|-
literal|1.0
operator|/
name|fabsf
argument_list|(
name|x
argument_list|)
return|;
if|if
condition|(
name|ix
operator|>=
literal|0x7f800000
condition|)
return|return
name|x
operator|*
name|x
return|;
if|if
condition|(
operator|(
name|ix
operator|>>=
literal|23
operator|)
operator|==
literal|0
condition|)
comment|/* IEEE 754 logb */
return|return
operator|-
literal|126.0
return|;
else|else
return|return
call|(
name|float
call|)
argument_list|(
name|ix
operator|-
literal|127
argument_list|)
return|;
block|}
end_function

end_unit

