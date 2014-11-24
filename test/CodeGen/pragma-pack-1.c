begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.7.0 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// PR4610
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
name|ref
block|{
name|struct
name|ref
modifier|*
name|next
decl_stmt|;
block|}
name|refs
struct|;
end_struct

begin_comment
comment|// PR13580
end_comment

begin_struct
struct|struct
name|S
block|{
name|char
name|a
index|[
literal|3
index|]
decl_stmt|;
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
struct|struct
name|T
block|{
name|char
name|b
decl_stmt|;
name|int
name|c
decl_stmt|;
block|}
name|d
struct|;
pragma|#
directive|pragma
name|pack
name|(
name|)
struct|struct
name|T2
block|{
name|char
name|b
decl_stmt|;
name|int
name|c
decl_stmt|;
block|}
name|d2
struct|;
block|}
name|ss
struct|;
end_struct

begin_struct
struct|struct
name|S3
block|{
name|char
name|a
index|[
literal|3
index|]
decl_stmt|;
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|2
name|)
struct|struct
name|T3
block|{
name|char
name|b
decl_stmt|;
name|int
name|c
decl_stmt|;
block|}
name|d
struct|;
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
struct|struct
name|T32
block|{
name|char
name|b
decl_stmt|;
name|int
name|c
decl_stmt|;
block|}
name|e
struct|;
block|}
name|s3
struct|;
end_struct

begin_struct
struct|struct
name|S4
block|{
name|char
name|a
index|[
literal|3
index|]
decl_stmt|;
pragma|#
directive|pragma
name|align
name|=
name|packed
struct|struct
name|T4
block|{
name|char
name|b
decl_stmt|;
name|int
name|c
decl_stmt|;
block|}
name|d
struct|;
name|int
name|e
decl_stmt|;
block|}
name|s4
struct|;
end_struct

begin_comment
comment|// CHECK: [[struct_ref:%[a-zA-Z0-9_.]+]] = type { [[struct_ref]]* }
end_comment

begin_comment
comment|// CHECK: [[struct_S:%[a-zA-Z0-9_.]+]] = type { [3 x i8], [[struct_T:%[a-zA-Z0-9_.]+]], [[struct_T2:%[a-zA-Z0-9_.]+]] }
end_comment

begin_comment
comment|// CHECK: [[struct_T]] = type<{ i8, i32 }>
end_comment

begin_comment
comment|// CHECK: [[struct_T2]] = type { i8, i32 }
end_comment

begin_comment
comment|// CHECK: %struct.S3 = type { [3 x i8], i8, %struct.T3, %struct.T32 }
end_comment

begin_comment
comment|// CHECK: %struct.T3 = type<{ i8, i8, i32 }>
end_comment

begin_comment
comment|// CHECK: %struct.T32 = type { i8, i32 }
end_comment

begin_comment
comment|// CHECK: %struct.S4 = type { [3 x i8], %struct.T4, i32 }
end_comment

begin_comment
comment|// CHECK: %struct.T4 = type<{ i8, i32 }>
end_comment

begin_comment
comment|// CHECK: @refs = common global [[struct_ref]]
end_comment

begin_comment
comment|// CHECK: @ss = common global [[struct_S]]
end_comment

end_unit

