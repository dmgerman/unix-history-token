begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -emit-llvm -o - %s | FileCheck %s
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

begin_comment
comment|// CHECK: @a = global { i32, [2 x i32] } { i32 1, [2 x i32] [i32 7, i32 11] }
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

begin_comment
comment|// CHECK: @b = global { i32, [2 x i32] } { i32 1, [2 x i32] [i32 13, i32 15] }
end_comment

end_unit

