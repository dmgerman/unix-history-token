begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: llvmc -c -emit-llvm -o - %s | llvm-dis | grep "@f0()" | count 1
end_comment

begin_function
name|int
name|f0
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

end_unit

