begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)strcatn.c	4.3 (Berkeley) 3/9/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|LIBC_SCCS and not lint
end_endif

begin_comment
comment|/*  * Concatenate s2 on the end of s1.  S1's space must be large enough.  * At most n characters are moved.  * Return s1.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|strcatn
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|,
name|n
argument_list|)
decl|register
name|char
modifier|*
name|s1
decl_stmt|,
modifier|*
name|s2
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|register
name|n
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|os1
decl_stmt|;
name|os1
operator|=
name|s1
expr_stmt|;
while|while
condition|(
operator|*
name|s1
operator|++
condition|)
empty_stmt|;
operator|--
name|s1
expr_stmt|;
while|while
condition|(
operator|*
name|s1
operator|++
operator|=
operator|*
name|s2
operator|++
condition|)
if|if
condition|(
operator|--
name|n
operator|<
literal|0
condition|)
block|{
operator|*
operator|--
name|s1
operator|=
literal|'\0'
expr_stmt|;
break|break;
block|}
return|return
operator|(
name|os1
operator|)
return|;
block|}
end_block

end_unit

