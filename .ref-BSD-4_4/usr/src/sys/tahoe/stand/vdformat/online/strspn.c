begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
literal|"@(#)strspn.c	1.1 (Berkeley/CCI) 7/5/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*	@(#)strspn.c	1.2	*/
end_comment

begin_comment
comment|/*LINTLIBRARY*/
end_comment

begin_comment
comment|/*  * Return the number of characters in the maximum leading segment  * of string which consists solely of characters from charset.  */
end_comment

begin_function
name|int
name|strspn
parameter_list|(
name|string
parameter_list|,
name|charset
parameter_list|)
name|char
modifier|*
name|string
decl_stmt|;
specifier|register
name|char
modifier|*
name|charset
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|q
decl_stmt|;
for|for
control|(
name|q
operator|=
name|string
init|;
operator|*
name|q
operator|!=
literal|'\0'
condition|;
operator|++
name|q
control|)
block|{
for|for
control|(
name|p
operator|=
name|charset
init|;
operator|*
name|p
operator|!=
literal|'\0'
operator|&&
operator|*
name|p
operator|!=
operator|*
name|q
condition|;
operator|++
name|p
control|)
empty_stmt|;
if|if
condition|(
operator|*
name|p
operator|==
literal|'\0'
condition|)
break|break;
block|}
return|return
operator|(
name|q
operator|-
name|string
operator|)
return|;
block|}
end_function

end_unit

