begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_decl_stmt
name|struct
name|foo
name|A
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|foo
block|{
name|int
name|x
decl_stmt|;
name|double
name|D
decl_stmt|;
block|}
struct|;
end_struct

end_unit

