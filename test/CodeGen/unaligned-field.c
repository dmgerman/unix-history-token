begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -fms-extensions -emit-llvm< %s | FileCheck %s
end_comment

begin_comment
comment|// Test that __unaligned does not impact the layout of the fields.
end_comment

begin_struct
struct|struct
name|A
block|{
name|char
name|a
decl_stmt|;
name|__unaligned
name|int
name|b
decl_stmt|;
block|}
name|a
struct|;
end_struct

begin_comment
comment|// CHECK: %struct.A = type { i8, i32 }
end_comment

begin_struct
struct|struct
name|A2
block|{
name|int
name|b
decl_stmt|;
name|char
name|a
decl_stmt|;
name|__unaligned
name|int
name|c
decl_stmt|;
block|}
name|a2
struct|;
end_struct

begin_comment
comment|// CHECK: %struct.A2 = type { i32, i8, i32 }
end_comment

end_unit

