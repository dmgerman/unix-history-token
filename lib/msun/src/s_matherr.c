begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)s_matherr.c 5.1 93/09/24 */
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

begin_decl_stmt
name|int
name|matherr
argument_list|(
expr|struct
name|exception
operator|*
name|x
argument_list|)
else|#
directive|else
name|int
name|matherr
argument_list|(
name|x
argument_list|)
decl|struct
name|exception
modifier|*
name|x
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
name|int
name|n
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|x
operator|->
name|arg1
operator|!=
name|x
operator|->
name|arg1
condition|)
return|return
literal|0
return|;
return|return
name|n
return|;
block|}
end_block

end_unit

