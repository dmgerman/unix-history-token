begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_struct
struct|struct
name|Foo
block|{
name|unsigned
name|a
decl_stmt|;
name|unsigned
name|b
decl_stmt|;
name|unsigned
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Bar
block|{
union|union
block|{
name|void
modifier|*
modifier|*
name|a
decl_stmt|;
name|struct
name|Foo
name|b
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|Bar
name|test
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

end_unit

