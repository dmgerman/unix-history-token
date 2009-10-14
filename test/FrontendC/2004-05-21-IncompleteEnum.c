begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -w -S %s -o - | llvm-as -o /dev/null
end_comment

begin_function
name|void
name|test
parameter_list|(
name|enum
name|foo
modifier|*
name|X
parameter_list|)
block|{ }
end_function

end_unit

