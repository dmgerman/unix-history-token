begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * pfxcpy() copies the prefix of s2 to s1.  */
end_comment

begin_function
name|char
modifier|*
name|pfxcpy
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
specifier|register
name|char
modifier|*
name|s1
decl_stmt|;
comment|/* target string */
specifier|register
name|char
modifier|*
name|s2
decl_stmt|;
comment|/* source string */
block|{
name|char
modifier|*
name|ss1
init|=
name|s1
decl_stmt|;
comment|/* start of s1 */
while|while
condition|(
operator|(
operator|*
name|s1
operator|=
operator|*
name|s2
operator|)
operator|&&
operator|*
name|s2
operator|!=
literal|'.'
condition|)
name|s1
operator|++
operator|,
name|s2
operator|++
expr_stmt|;
operator|*
name|s1
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|ss1
operator|)
return|;
block|}
end_function

end_unit

