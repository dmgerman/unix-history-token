begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1979 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)RELTGE.c	1.3 (Berkeley) %G%"
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
file|"h00vars.h"
end_include

begin_function
name|bool
name|RELTGE
parameter_list|(
name|bytecnt
parameter_list|,
name|left
parameter_list|,
name|right
parameter_list|)
name|long
name|bytecnt
decl_stmt|;
specifier|register
name|long
modifier|*
name|left
decl_stmt|;
specifier|register
name|long
modifier|*
name|right
decl_stmt|;
block|{
specifier|register
name|int
name|longcnt
decl_stmt|;
name|longcnt
operator|=
name|bytecnt
operator|>>
literal|2
expr_stmt|;
do|do
block|{
if|if
condition|(
operator|(
operator|*
name|right
operator|++
operator|&
operator|~
operator|*
name|left
operator|++
operator|)
operator|!=
literal|0
condition|)
return|return
name|FALSE
return|;
block|}
do|while
condition|(
operator|--
name|longcnt
condition|)
do|;
return|return
name|TRUE
return|;
block|}
end_function

end_unit

