begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.proprietary.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)d_cnjg.c	5.4 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"complex"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_include
include|#
directive|include
file|<tahoe/math/FP.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|d_cnjg
argument_list|(
argument|r
argument_list|,
argument|z
argument_list|)
end_macro

begin_decl_stmt
name|dcomplex
modifier|*
name|r
decl_stmt|,
modifier|*
name|z
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|r
operator|->
name|dreal
operator|=
name|z
operator|->
name|dreal
expr_stmt|;
ifndef|#
directive|ifndef
name|tahoe
name|r
operator|->
name|dimag
operator|=
operator|-
name|z
operator|->
name|dimag
expr_stmt|;
else|#
directive|else
else|tahoe
name|r
operator|->
name|dimag
operator|=
name|z
operator|->
name|dimag
expr_stmt|;
if|if
condition|(
name|z
operator|->
name|dimag
operator|==
literal|0.0
condition|)
return|return;
else|else
operator|*
operator|(
name|unsigned
name|long
operator|*
operator|)
operator|&
operator|(
name|z
operator|->
name|dimag
operator|)
operator|^=
name|SIGN_BIT
expr_stmt|;
endif|#
directive|endif
endif|tahoe
block|}
end_block

end_unit

