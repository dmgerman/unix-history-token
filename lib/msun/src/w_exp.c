begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)w_exp.c 5.1 93/09/24 */
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
comment|/*  * wrapper exp(x)  */
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
name|double
else|#
directive|else
specifier|static
name|double
endif|#
directive|endif
name|o_threshold
init|=
literal|7.09782712893383973096e+02
decl_stmt|,
comment|/* 0x40862E42, 0xFEFA39EF */
name|u_threshold
init|=
operator|-
literal|7.45133219101941108420e+02
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0xc0874910, 0xD52D3051 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function
name|double
name|exp
parameter_list|(
name|double
name|x
parameter_list|)
comment|/* wrapper exp */
else|#
directive|else
function|double exp
parameter_list|(
name|x
parameter_list|)
comment|/* wrapper exp */
name|double
name|x
decl_stmt|;
endif|#
directive|endif
block|{
ifdef|#
directive|ifdef
name|_IEEE_LIBM
return|return
name|__ieee754_exp
argument_list|(
name|x
argument_list|)
return|;
else|#
directive|else
name|double
name|z
decl_stmt|;
name|z
operator|=
name|__ieee754_exp
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
name|finite
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
return|return
name|__kernel_standard
argument_list|(
name|x
argument_list|,
name|x
argument_list|,
literal|6
argument_list|)
return|;
comment|/* exp overflow */
elseif|else
if|if
condition|(
name|x
operator|<
name|u_threshold
condition|)
return|return
name|__kernel_standard
argument_list|(
name|x
argument_list|,
name|x
argument_list|,
literal|7
argument_list|)
return|;
comment|/* exp underflow */
block|}
return|return
name|z
return|;
endif|#
directive|endif
block|}
end_function

end_unit

