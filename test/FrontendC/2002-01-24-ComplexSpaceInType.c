begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_comment
comment|// This caused generation of the following type name:
end_comment

begin_comment
comment|//   %Array = uninitialized global [10 x %complex int]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// which caused problems because of the space int the complex int type
end_comment

begin_comment
comment|//
end_comment

begin_struct
struct|struct
block|{
name|int
name|X
decl_stmt|,
name|Y
decl_stmt|;
block|}
name|Array
index|[
literal|10
index|]
struct|;
end_struct

begin_function
name|void
name|foo
parameter_list|()
block|{}
end_function

end_unit

