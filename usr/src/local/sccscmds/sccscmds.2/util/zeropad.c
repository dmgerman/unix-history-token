begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
specifier|static
name|char
name|Sccsid
index|[]
literal|"@(#)zeropad	2.2"
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 	Replace initial blanks with '0's in `str'. 	Return `str'. */
end_comment

begin_function
name|char
modifier|*
name|zeropad
parameter_list|(
name|str
parameter_list|)
name|char
modifier|*
name|str
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|s
decl_stmt|;
for|for
control|(
name|s
operator|=
name|str
init|;
operator|*
name|s
operator|==
literal|' '
condition|;
name|s
operator|++
control|)
operator|*
name|s
operator|=
literal|'0'
expr_stmt|;
return|return
operator|(
name|str
operator|)
return|;
block|}
end_function

end_unit

