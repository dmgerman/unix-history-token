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
literal|"@(#)blkcpy.c	1.4 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_expr_stmt
name|blkcpy
argument_list|(
name|from
argument_list|,
name|to
argument_list|,
name|siz
argument_list|)
specifier|register
name|char
operator|*
name|from
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|char
modifier|*
name|to
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|siz
decl_stmt|;
end_decl_stmt

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
name|to
operator|<
name|from
condition|)
while|while
condition|(
name|size
operator|--
operator|>
literal|0
condition|)
operator|*
name|to
operator|++
operator|=
operator|*
name|from
operator|++
expr_stmt|;
else|else
block|{
name|to
operator|+=
name|size
expr_stmt|;
name|from
operator|+=
name|size
expr_stmt|;
while|while
condition|(
name|size
operator|--
operator|>
literal|0
condition|)
operator|*
operator|--
name|to
operator|=
operator|*
operator|--
name|from
expr_stmt|;
block|}
block|}
end_block

end_unit

