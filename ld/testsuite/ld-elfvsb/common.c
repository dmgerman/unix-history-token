begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|int
name|foo
decl_stmt|;
end_decl_stmt

begin_asm
asm|asm (".hidden foo");
end_asm

begin_function
name|int
name|_start
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|foo
return|;
block|}
end_function

begin_function
name|int
name|__start
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|_start
argument_list|()
return|;
block|}
end_function

end_unit

