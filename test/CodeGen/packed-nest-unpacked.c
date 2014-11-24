begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-apple-macosx10.7.2 -emit-llvm -o - | FileCheck %s
end_comment

begin_struct
struct|struct
name|X
block|{
name|int
name|x
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Y
block|{
name|char
name|x
index|[
literal|13
index|]
decl_stmt|;
name|struct
name|X
name|y
decl_stmt|;
block|}
name|__attribute
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_decl_stmt
name|struct
name|Y
name|g
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|f
parameter_list|(
name|struct
name|X
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|X
name|foo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//<rdar://problem/10463337>
end_comment

begin_function
name|struct
name|X
name|test1
parameter_list|()
block|{
comment|// CHECK: @test1
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i64(i8* {{.*}}, i8* bitcast (%struct.X* getelementptr inbounds (%struct.Y* @g, i32 0, i32 1) to i8*), i64 24, i32 1, i1 false)
return|return
name|g
operator|.
name|y
return|;
block|}
end_function

begin_function
name|struct
name|X
name|test2
parameter_list|()
block|{
comment|// CHECK: @test2
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i64(i8* {{.*}}, i8* bitcast (%struct.X* getelementptr inbounds (%struct.Y* @g, i32 0, i32 1) to i8*), i64 24, i32 1, i1 false)
name|struct
name|X
name|a
init|=
name|g
operator|.
name|y
decl_stmt|;
return|return
name|a
return|;
block|}
end_function

begin_function
name|void
name|test3
parameter_list|(
name|struct
name|X
name|a
parameter_list|)
block|{
comment|// CHECK: @test3
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i64(i8* bitcast (%struct.X* getelementptr inbounds (%struct.Y* @g, i32 0, i32 1) to i8*), i8* {{.*}}, i64 24, i32 1, i1 false)
name|g
operator|.
name|y
operator|=
name|a
expr_stmt|;
block|}
end_function

begin_comment
comment|//<rdar://problem/10530444>
end_comment

begin_function
name|void
name|test4
parameter_list|()
block|{
comment|// CHECK: @test4
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i64(i8* {{.*}}, i8* bitcast (%struct.X* getelementptr inbounds (%struct.Y* @g, i32 0, i32 1) to i8*), i64 24, i32 1, i1 false)
name|f
argument_list|(
name|g
operator|.
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// PR12395
end_comment

begin_function
name|int
name|test5
parameter_list|()
block|{
comment|// CHECK: @test5
comment|// CHECK: load i32* getelementptr inbounds (%struct.Y* @g, i32 0, i32 1, i32 0, i64 0), align 1
return|return
name|g
operator|.
name|y
operator|.
name|x
index|[
literal|0
index|]
return|;
block|}
end_function

begin_comment
comment|//<rdar://problem/11220251>
end_comment

begin_function
name|void
name|test6
parameter_list|()
block|{
comment|// CHECK: @test6
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i64(i8* bitcast (%struct.X* getelementptr inbounds (%struct.Y* @g, i32 0, i32 1) to i8*), i8* %{{.*}}, i64 24, i32 1, i1 false)
name|g
operator|.
name|y
operator|=
name|foo
argument_list|()
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|XBitfield
block|{
name|unsigned
name|b1
range|:
literal|10
decl_stmt|;
name|unsigned
name|b2
range|:
literal|12
decl_stmt|;
name|unsigned
name|b3
range|:
literal|10
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|YBitfield
block|{
name|char
name|x
decl_stmt|;
name|struct
name|XBitfield
name|y
decl_stmt|;
block|}
name|__attribute
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_decl_stmt
name|struct
name|YBitfield
name|gbitfield
decl_stmt|;
end_decl_stmt

begin_function
name|unsigned
name|test7
parameter_list|()
block|{
comment|// CHECK: @test7
comment|// CHECK: load i32* getelementptr inbounds (%struct.YBitfield* @gbitfield, i32 0, i32 1, i32 0), align 4
return|return
name|gbitfield
operator|.
name|y
operator|.
name|b2
return|;
block|}
end_function

end_unit

