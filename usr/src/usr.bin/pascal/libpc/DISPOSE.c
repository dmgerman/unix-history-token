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
literal|"@(#)DISPOSE.c	1.4 (Berkeley) %G%"
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

begin_expr_stmt
name|DISPOSE
argument_list|(
name|var
argument_list|,
name|siz
argument_list|)
specifier|register
name|char
operator|*
operator|*
name|var
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* pointer to pointer being deallocated */
end_comment

begin_decl_stmt
name|long
name|siz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sizeof(bletch) */
end_comment

begin_block
block|{
specifier|register
name|int
name|size
init|=
name|siz
decl_stmt|;
if|if
condition|(
operator|*
name|var
operator|==
literal|0
operator|||
operator|*
name|var
operator|+
name|size
operator|>
name|_maxptr
operator|||
operator|*
name|var
operator|<
name|_minptr
condition|)
block|{
name|ERROR
argument_list|(
literal|"Pointer value out of legal range\n"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
name|free
argument_list|(
operator|*
name|var
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|var
operator|==
name|_minptr
condition|)
name|_minptr
operator|+=
name|size
expr_stmt|;
if|if
condition|(
operator|*
name|var
operator|+
name|size
operator|==
name|_maxptr
condition|)
name|_maxptr
operator|-=
name|size
expr_stmt|;
operator|*
name|var
operator|=
operator|(
name|char
operator|*
operator|)
operator|(
literal|0
operator|)
expr_stmt|;
block|}
end_block

end_unit

