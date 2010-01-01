begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-darwin9 %s -emit-llvm -o - | FileCheck -check-prefix X32 %s
end_comment

begin_comment
comment|// CHECK-X32: %struct.s0 = type { i64, i64, i32, [12 x i32] }
end_comment

begin_comment
comment|// CHECK-X32: %struct.s1 = type { [15 x i32], %struct.s0 }
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin9 %s -emit-llvm -o - | FileCheck -check-prefix X64 %s
end_comment

begin_comment
comment|// CHECK-X64: %struct.s0 = type<{ i64, i64, i32, [12 x i32] }>
end_comment

begin_comment
comment|// CHECK-X64: %struct.s1 = type<{ [15 x i32], %struct.s0 }>
end_comment

begin_comment
comment|// rdar://problem/7095436
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|4
name|)
end_pragma

begin_struct
struct|struct
name|s0
block|{
name|long
name|long
name|a
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|8
argument_list|)
operator|)
argument_list|)
decl_stmt|;
name|long
name|long
name|b
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|8
argument_list|)
operator|)
argument_list|)
decl_stmt|;
name|unsigned
name|int
name|c
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|8
argument_list|)
operator|)
argument_list|)
decl_stmt|;
name|int
name|d
index|[
literal|12
index|]
decl_stmt|;
block|}
name|a
struct|;
end_struct

begin_struct
struct|struct
name|s1
block|{
name|int
name|a
index|[
literal|15
index|]
decl_stmt|;
name|struct
name|s0
name|b
decl_stmt|;
block|}
name|b
struct|;
end_struct

end_unit

