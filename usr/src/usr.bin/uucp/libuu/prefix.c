begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1985, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.proprietary.c%  */
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
literal|"@(#)prefix.c	8.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*LINTLIBRARY*/
end_comment

begin_comment
comment|/*  *	check s2 for prefix s1  *  *	return 0 - !=  *	return 1 - ==   */
end_comment

begin_expr_stmt
name|prefix
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|)
specifier|register
name|char
operator|*
name|s1
operator|,
operator|*
name|s2
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|char
name|c
decl_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
operator|*
name|s1
operator|++
operator|)
operator|==
operator|*
name|s2
operator|++
condition|)
if|if
condition|(
name|c
operator|==
literal|'\0'
condition|)
return|return
literal|1
return|;
return|return
name|c
operator|==
literal|'\0'
return|;
block|}
end_block

begin_comment
comment|/*  *	check s2 for prefix s1 with a wildcard character ?  *  *	return 0 - !=  *	return 1 - ==   */
end_comment

begin_expr_stmt
name|wprefix
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|)
specifier|register
name|char
operator|*
name|s1
operator|,
operator|*
name|s2
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|char
name|c
decl_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
operator|*
name|s1
operator|++
operator|)
operator|!=
literal|'\0'
condition|)
if|if
condition|(
operator|*
name|s2
operator|==
literal|'\0'
operator|||
operator|(
name|c
operator|!=
operator|*
name|s2
operator|++
operator|&&
name|c
operator|!=
literal|'?'
operator|)
condition|)
return|return
literal|0
return|;
return|return
literal|1
return|;
block|}
end_block

end_unit

