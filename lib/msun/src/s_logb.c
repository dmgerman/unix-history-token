begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)s_logb.c 5.1 93/09/24 */
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
comment|/*  * double logb(x)  * IEEE 754 logb. Included to pass IEEE test suite. Not recommend.  * Use ilogb instead.  */
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
name|__generic_logb
parameter_list|(
name|double
name|x
parameter_list|)
else|#
directive|else
function|double __generic_logb
parameter_list|(
name|x
parameter_list|)
name|double
name|x
decl_stmt|;
endif|#
directive|endif
block|{
name|int32_t
name|lx
decl_stmt|,
name|ix
decl_stmt|;
name|EXTRACT_WORDS
argument_list|(
name|ix
argument_list|,
name|lx
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
operator|(
name|ix
operator||
name|lx
operator|)
operator|==
literal|0
condition|)
return|return
operator|-
literal|1.0
operator|/
name|fabs
argument_list|(
name|x
argument_list|)
return|;
if|if
condition|(
name|ix
operator|>=
literal|0x7ff00000
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
literal|20
operator|)
operator|==
literal|0
condition|)
comment|/* IEEE 754 logb */
return|return
operator|-
literal|1022.0
return|;
else|else
return|return
call|(
name|double
call|)
argument_list|(
name|ix
operator|-
literal|1023
argument_list|)
return|;
block|}
end_function

end_unit

