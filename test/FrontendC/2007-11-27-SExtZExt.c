begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | grep "signext" | count 4
end_comment

begin_function
name|signed
name|char
name|foo1
parameter_list|()
block|{
return|return
literal|1
return|;
block|}
end_function

begin_function
name|void
name|foo2
parameter_list|(
name|signed
name|short
name|a
parameter_list|)
block|{ }
end_function

begin_function
name|signed
name|char
name|foo3
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

begin_function
name|void
name|foo4
parameter_list|(
name|a
parameter_list|)
name|signed
name|short
name|a
decl_stmt|;
block|{ }
end_function

end_unit

