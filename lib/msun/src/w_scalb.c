begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)w_scalb.c 5.1 93/09/24 */
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
comment|/*  * wrapper scalb(double x, double fn) is provide for  * passing various standard test suite. One  * should use scalbn() instead.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|_SCALB_INT
end_ifdef

begin_decl_stmt
name|double
name|scalb
argument_list|(
name|double
name|x
argument_list|,
name|int
name|fn
argument_list|)
comment|/* wrapper scalb */
else|#
directive|else
name|double
name|scalb
argument_list|(
name|double
name|x
argument_list|,
name|double
name|fn
argument_list|)
comment|/* wrapper scalb */
endif|#
directive|endif
else|#
directive|else
name|double
name|scalb
argument_list|(
name|x
argument_list|,
name|fn
argument_list|)
comment|/* wrapper scalb */
ifdef|#
directive|ifdef
name|_SCALB_INT
name|double
name|x
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fn
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|double
name|x
decl_stmt|,
name|fn
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
ifdef|#
directive|ifdef
name|_IEEE_LIBM
return|return
name|__ieee754_scalb
argument_list|(
name|x
argument_list|,
name|fn
argument_list|)
return|;
else|#
directive|else
name|double
name|z
decl_stmt|;
name|z
operator|=
name|__ieee754_scalb
argument_list|(
name|x
argument_list|,
name|fn
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
operator|!
operator|(
name|finite
argument_list|(
name|z
argument_list|)
operator|||
name|isnan
argument_list|(
name|z
argument_list|)
operator|)
operator|&&
name|finite
argument_list|(
name|x
argument_list|)
condition|)
block|{
return|return
name|__kernel_standard
argument_list|(
name|x
argument_list|,
operator|(
name|double
operator|)
name|fn
argument_list|,
literal|32
argument_list|)
return|;
comment|/* scalb overflow */
block|}
if|if
condition|(
name|z
operator|==
literal|0.0
operator|&&
name|z
operator|!=
name|x
condition|)
block|{
return|return
name|__kernel_standard
argument_list|(
name|x
argument_list|,
operator|(
name|double
operator|)
name|fn
argument_list|,
literal|33
argument_list|)
return|;
comment|/* scalb underflow */
block|}
ifndef|#
directive|ifndef
name|_SCALB_INT
if|if
condition|(
operator|!
name|finite
argument_list|(
name|fn
argument_list|)
condition|)
name|errno
operator|=
name|ERANGE
expr_stmt|;
endif|#
directive|endif
return|return
name|z
return|;
endif|#
directive|endif
block|}
end_block

end_unit

