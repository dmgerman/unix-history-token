begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_struct
struct|struct
name|S
block|{ }
struct|;
end_struct

begin_function
name|int
name|xxxx
parameter_list|(
name|int
name|a
parameter_list|)
block|{
name|struct
name|S
name|comps
index|[
name|a
index|]
decl_stmt|;
name|comps
index|[
literal|0
index|]
expr_stmt|;
block|}
end_function

end_unit

