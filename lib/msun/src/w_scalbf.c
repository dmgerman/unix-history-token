begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* w_scalbf.c -- float version of w_scalb.c.  * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.  */
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
comment|/*  * wrapper scalbf(float x, float fn) is provide for  * passing various standard test suite. One  * should use scalbn() instead.  */
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
name|float
name|scalbf
argument_list|(
name|float
name|x
argument_list|,
name|int
name|fn
argument_list|)
comment|/* wrapper scalbf */
else|#
directive|else
name|float
name|scalbf
argument_list|(
name|float
name|x
argument_list|,
name|float
name|fn
argument_list|)
comment|/* wrapper scalbf */
endif|#
directive|endif
else|#
directive|else
name|float
name|scalbf
argument_list|(
name|x
argument_list|,
name|fn
argument_list|)
comment|/* wrapper scalbf */
ifdef|#
directive|ifdef
name|_SCALB_INT
name|float
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
name|float
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
name|__ieee754_scalbf
argument_list|(
name|x
argument_list|,
name|fn
argument_list|)
return|;
else|#
directive|else
name|float
name|z
decl_stmt|;
name|z
operator|=
name|__ieee754_scalbf
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
name|finitef
argument_list|(
name|z
argument_list|)
operator|||
name|isnanf
argument_list|(
name|z
argument_list|)
operator|)
operator|&&
name|finitef
argument_list|(
name|x
argument_list|)
condition|)
block|{
comment|/* scalbf overflow */
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
name|fn
argument_list|,
literal|132
argument_list|)
return|;
block|}
if|if
condition|(
name|z
operator|==
operator|(
name|float
operator|)
literal|0.0
operator|&&
name|z
operator|!=
name|x
condition|)
block|{
comment|/* scalbf underflow */
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
name|fn
argument_list|,
literal|133
argument_list|)
return|;
block|}
ifndef|#
directive|ifndef
name|_SCALB_INT
if|if
condition|(
operator|!
name|finitef
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

