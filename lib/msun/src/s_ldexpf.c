begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* s_ldexpf.c -- float version of s_ldexp.c.  * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.  */
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

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function
name|float
name|ldexpf
parameter_list|(
name|float
name|value
parameter_list|,
name|int
name|exp
parameter_list|)
else|#
directive|else
function|float ldexpf
parameter_list|(
name|value
parameter_list|,
name|exp
parameter_list|)
name|float
name|value
decl_stmt|;
name|int
name|exp
decl_stmt|;
endif|#
directive|endif
block|{
if|if
condition|(
operator|!
name|finitef
argument_list|(
name|value
argument_list|)
operator|||
name|value
operator|==
operator|(
name|float
operator|)
literal|0.0
condition|)
return|return
name|value
return|;
name|value
operator|=
name|scalbnf
argument_list|(
name|value
argument_list|,
name|exp
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|finitef
argument_list|(
name|value
argument_list|)
operator|||
name|value
operator|==
operator|(
name|float
operator|)
literal|0.0
condition|)
name|errno
operator|=
name|ERANGE
expr_stmt|;
return|return
name|value
return|;
block|}
end_function

end_unit

