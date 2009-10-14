begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_comment
comment|/* This is apparently legal C.    */
end_comment

begin_function
specifier|extern
name|__inline__
name|void
name|test
parameter_list|()
block|{ }
end_function

begin_function
name|void
name|test
parameter_list|()
block|{ }
end_function

end_unit

