begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is compiled and linked into the S-record format.  */
end_comment

begin_decl_stmt
name|int
name|e1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|e2
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|fn1
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
return|return
name|s
index|[
name|e1
index|]
return|;
block|}
end_function

begin_function
name|int
name|fn2
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
return|return
name|s
index|[
name|e2
index|]
return|;
block|}
end_function

end_unit

