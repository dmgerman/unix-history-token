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
literal|"@(#)strpbrk.c	5.1 (Berkeley) 6/23/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*LINTLIBRARY*/
end_comment

begin_comment
comment|/*  * this is like index, but takes a string as the second argument  */
end_comment

begin_function
name|char
modifier|*
name|strpbrk
parameter_list|(
name|str
parameter_list|,
name|chars
parameter_list|)
specifier|register
name|char
modifier|*
name|str
decl_stmt|,
decl|*
name|chars
decl_stmt|;
end_function

begin_block
block|{
specifier|register
name|char
modifier|*
name|cp
decl_stmt|;
do|do
block|{
name|cp
operator|=
name|chars
operator|-
literal|1
expr_stmt|;
while|while
condition|(
operator|*
operator|++
name|cp
condition|)
block|{
if|if
condition|(
operator|*
name|str
operator|==
operator|*
name|cp
condition|)
return|return
name|str
return|;
block|}
block|}
do|while
condition|(
operator|*
name|str
operator|++
condition|)
do|;
return|return
operator|(
name|char
operator|*
operator|)
literal|0
return|;
block|}
end_block

end_unit

