begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mhl.c - the MH message listing program */
end_comment

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|done
argument_list|(
name|mhl
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/* Cheat:  we are loaded with adrparse, which wants a routine called    OfficialName().  We call adrparse:getm() with the correct arguments    to prevent OfficialName() from being called.  Hence, the following    is to keep the loader happy.  */
end_comment

begin_function
name|char
modifier|*
name|OfficialName
parameter_list|(
name|name
parameter_list|)
specifier|register
name|char
modifier|*
name|name
decl_stmt|;
block|{
return|return
name|name
return|;
block|}
end_function

end_unit

