begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)s_copysign.c 5.1 93/09/24 */
end_comment

begin_comment
comment|/*  * ====================================================  * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.  *  * Developed at SunPro, a Sun Microsystems, Inc. business.  * Permission to use, copy, modify, and distribute this  * software is freely granted, provided that this notice   * is preserved.  * ====================================================  */
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
literal|"$Id: s_copysign.c,v 1.4 1994/03/03 17:04:30 jtc Exp $"
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
file|<machine/endian.h>
end_include

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|n0
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|n0
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function
name|double
name|copysign
parameter_list|(
name|double
name|x
parameter_list|,
name|double
name|y
parameter_list|)
else|#
directive|else
function|double copysign
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
operator|*
operator|(
name|n0
operator|+
operator|(
name|unsigned
operator|*
operator|)
operator|&
name|x
operator|)
operator|=
operator|(
operator|*
operator|(
name|n0
operator|+
operator|(
name|unsigned
operator|*
operator|)
operator|&
name|x
operator|)
operator|&
literal|0x7fffffff
operator|)
operator||
operator|(
operator|*
operator|(
name|n0
operator|+
operator|(
name|unsigned
operator|*
operator|)
operator|&
name|y
operator|)
operator|&
literal|0x80000000
operator|)
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

end_unit

