begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | grep "align 2"
end_comment

begin_struct
struct|struct
name|A
block|{
name|short
name|s
decl_stmt|;
name|short
name|t
decl_stmt|;
name|int
name|i
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|q
parameter_list|()
block|{
name|struct
name|A
name|a
init|=
block|{
literal|0
block|}
decl_stmt|;
block|}
end_function

end_unit

