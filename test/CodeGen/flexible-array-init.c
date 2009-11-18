begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple i386-unknown-unknown -emit-llvm -o - %s | grep 7 | count 1
end_comment

begin_comment
comment|// RUN: clang-cc -triple i386-unknown-unknown -emit-llvm -o - %s | grep 11 | count 1
end_comment

begin_comment
comment|// RUN: clang-cc -triple i386-unknown-unknown -emit-llvm -o - %s | grep 13 | count 1
end_comment

begin_comment
comment|// RUN: clang-cc -triple i386-unknown-unknown -emit-llvm -o - %s | grep 15 | count 1
end_comment

begin_struct
struct|struct
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
index|[]
decl_stmt|;
block|}
name|a
init|=
block|{
literal|1
block|,
literal|7
block|,
literal|11
block|}
struct|;
end_struct

begin_struct
struct|struct
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
index|[]
decl_stmt|;
block|}
name|b
init|=
block|{
literal|1
block|,
block|{
literal|13
block|,
literal|15
block|}
block|}
struct|;
end_struct

end_unit

