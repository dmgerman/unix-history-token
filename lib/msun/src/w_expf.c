begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* w_expf.c -- float version of w_exp.c.  * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.  */
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
comment|/*  * wrapper expf(x)  */
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

begin_decl_stmt
specifier|static
specifier|const
name|float
else|#
directive|else
specifier|static
name|float
endif|#
directive|endif
name|o_threshold
init|=
literal|8.8721679688e+01
decl_stmt|,
comment|/* 0x42b17180 */
name|u_threshold
init|=
operator|-
literal|1.0397208405e+02
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0xc2cff1b5 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function
name|float
name|expf
parameter_list|(
name|float
name|x
parameter_list|)
comment|/* wrapper expf */
else|#
directive|else
function|float expf
parameter_list|(
name|x
parameter_list|)
comment|/* wrapper expf */
name|float
name|x
decl_stmt|;
endif|#
directive|endif
block|{
ifdef|#
directive|ifdef
name|_IEEE_LIBM
return|return
name|__ieee754_expf
argument_list|(
name|x
argument_list|)
return|;
else|#
directive|else
name|float
name|z
decl_stmt|;
name|z
operator|=
name|__ieee754_expf
argument_list|(
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|_LIB_VERSION
operator|==
name|_IEEE_
condition|)
return|return
name|z
return|;
if|if
condition|(
name|finitef
argument_list|(
name|x
argument_list|)
condition|)
block|{
if|if
condition|(
name|x
operator|>
name|o_threshold
condition|)
comment|/* exp overflow */
return|return
operator|(
name|float
operator|)
name|__kernel_standard
argument_list|(
operator|(
name|double
operator|)
name|x
argument_list|,
operator|(
name|double
operator|)
name|x
argument_list|,
literal|106
argument_list|)
return|;
elseif|else
if|if
condition|(
name|x
operator|<
name|u_threshold
condition|)
comment|/* exp underflow */
return|return
operator|(
name|float
operator|)
name|__kernel_standard
argument_list|(
operator|(
name|double
operator|)
name|x
argument_list|,
operator|(
name|double
operator|)
name|x
argument_list|,
literal|107
argument_list|)
return|;
block|}
return|return
name|z
return|;
endif|#
directive|endif
block|}
end_function

end_unit

