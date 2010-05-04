begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -fasm-blocks -o - -O | grep naked
end_comment

begin_comment
comment|// 7533078 (partial).
end_comment

begin_function
name|asm
name|int
name|f
parameter_list|()
block|{
name|xyz
block|}
end_function

end_unit

