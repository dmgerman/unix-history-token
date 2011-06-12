begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-darwin10 -emit-llvm %s -o - | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|ATTR
value|__attribute__((__ms_struct__))
end_define

begin_struct
struct|struct
name|s1
block|{
name|int
name|f32
decl_stmt|;
name|long
name|long
name|f64
decl_stmt|;
block|}
name|ATTR
name|s1
struct|;
end_struct

begin_comment
comment|// CHECK: %struct.s1 = type { i32, [4 x i8], i64 }
end_comment

begin_struct
struct|struct
name|s2
block|{
name|int
name|f32
decl_stmt|;
name|long
name|long
name|f64
index|[
literal|4
index|]
decl_stmt|;
block|}
name|ATTR
name|s2
struct|;
end_struct

begin_comment
comment|// CHECK: %struct.s2 = type { i32, [4 x i8], [4 x i64] }
end_comment

begin_struct
struct|struct
name|s3
block|{
name|int
name|f32
decl_stmt|;
name|struct
name|s1
name|s
decl_stmt|;
block|}
name|ATTR
name|s3
struct|;
end_struct

begin_comment
comment|// CHECK: %struct.s3 = type { i32, [4 x i8], %struct.s1 }
end_comment

end_unit

