begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)strcpy.c	4.1 (Berkeley) 12/21/80 */
end_comment

begin_comment
comment|/*  * Copy string s2 to s1.  s1 must be large enough.  * return s1  */
end_comment

begin_function
name|char
modifier|*
name|strcpy
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

