begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * strpcpy() copies string s2 to s1 and returns a pointer to the  * next character after s1.  */
end_comment

begin_function
name|char
modifier|*
name|strpcpy
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
specifier|register
name|char
modifier|*
name|s2
decl_stmt|;
block|{
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
continue|continue;
return|return
operator|(
operator|--
name|s1
operator|)
return|;
block|}
end_function

end_unit

