begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)s_isnan.c 5.1 93/09/24 */
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
comment|/*  * isnan(x) returns 1 is x is nan, else 0;  * no branching!  */
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
name|int
name|isnan
parameter_list|(
name|double
name|x
parameter_list|)
else|#
directive|else
function|int isnan
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
name|hx
decl_stmt|,
name|lx
decl_stmt|;
name|EXTRACT_WORDS
argument_list|(
name|hx
argument_list|,
name|lx
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|hx
operator|&=
literal|0x7fffffff
expr_stmt|;
name|hx
operator||=
call|(
name|u_int32_t
call|)
argument_list|(
name|lx
operator||
operator|(
operator|-
name|lx
operator|)
argument_list|)
operator|>>
literal|31
expr_stmt|;
name|hx
operator|=
literal|0x7ff00000
operator|-
name|hx
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
name|hx
argument_list|)
argument_list|)
operator|>>
literal|31
return|;
block|}
end_function

end_unit

