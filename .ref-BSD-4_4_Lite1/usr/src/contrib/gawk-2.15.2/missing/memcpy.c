begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * memcpy --- copy strings.  *  * We supply this routine for those systems that aren't standard yet.  */
end_comment

begin_function
name|char
modifier|*
name|memcpy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|,
name|l
parameter_list|)
specifier|register
name|char
modifier|*
name|dest
decl_stmt|,
decl|*
name|src
decl_stmt|;
end_function

begin_decl_stmt
specifier|register
name|int
name|l
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|ret
init|=
name|dest
decl_stmt|;
while|while
condition|(
name|l
operator|--
condition|)
operator|*
name|dest
operator|++
operator|=
operator|*
name|src
operator|++
expr_stmt|;
return|return
name|ret
return|;
block|}
end_block

end_unit

