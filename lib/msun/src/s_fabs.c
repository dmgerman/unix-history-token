begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)s_fabs.c 5.1 93/09/24 */
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
literal|"$Id: s_fabs.c,v 1.3 1994/02/18 02:26:27 jtc Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * fabs(x) returns the absolute value of x.  */
end_comment

begin_include
include|#
directive|include
file|"math.h"
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
name|one
init|=
literal|1.0
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|double
name|one
init|=
literal|1.0
decl_stmt|;
end_decl_stmt

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
name|fabs
parameter_list|(
name|double
name|x
parameter_list|)
else|#
directive|else
function|double fabs
parameter_list|(
name|x
parameter_list|)
name|double
name|x
decl_stmt|;
endif|#
directive|endif
block|{
operator|*
operator|(
operator|(
operator|(
operator|(
operator|*
operator|(
name|int
operator|*
operator|)
operator|&
name|one
operator|)
operator|>>
literal|29
operator|)
operator|^
literal|1
operator|)
operator|+
operator|(
name|int
operator|*
operator|)
operator|&
name|x
operator|)
operator|&=
literal|0x7fffffff
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

end_unit

