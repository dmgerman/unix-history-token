begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -Os -xc %s -c -o - | llvm-dis | not grep dead_function
end_comment

begin_function
specifier|extern
name|__inline__
name|void
name|dead_function
parameter_list|()
block|{}
end_function

end_unit

