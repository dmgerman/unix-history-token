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
literal|"@(#)strcat.c	5.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * Concatenate s2 on the end of s1.  S1's space must be large enough.  * Return s1.  */
end_comment

begin_function
name|char
modifier|*
name|strcat
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
specifier|register
name|char
modifier|*
name|s1
decl_stmt|,
decl|*
name|s2
decl_stmt|;
end_function

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
empty_stmt|;
return|return
operator|(
name|os1
operator|)
return|;
block|}
end_block

end_unit

