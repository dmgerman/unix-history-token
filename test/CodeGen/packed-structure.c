begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64 -emit-llvm -o - %s | opt -S -strip -o %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-GLOBAL< %t %s
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-FUNCTIONS< %t %s
end_comment

begin_struct
struct|struct
name|s0
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK-GLOBAL: @s0_align_x = global i32 4
end_comment

begin_comment
comment|// CHECK-GLOBAL: @s0_align_y = global i32 1
end_comment

begin_comment
comment|// CHECK-GLOBAL: @s0_align = global i32 4
end_comment

begin_decl_stmt
name|int
name|s0_align_x
init|=
name|__alignof
argument_list|(
operator|(
operator|(
expr|struct
name|s0
operator|*
operator|)
literal|0
operator|)
operator|->
name|x
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|s0_align_y
init|=
name|__alignof
argument_list|(
operator|(
operator|(
expr|struct
name|s0
operator|*
operator|)
literal|0
operator|)
operator|->
name|y
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|s0_align
init|=
name|__alignof
argument_list|(
expr|struct
name|s0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-FUNCTIONS-LABEL: define i32 @s0_load_x
end_comment

begin_comment
comment|// CHECK-FUNCTIONS: [[s0_load_x:%.*]] = load i32* {{.*}}, align 4
end_comment

begin_comment
comment|// CHECK-FUNCTIONS: ret i32 [[s0_load_x]]
end_comment

begin_function
name|int
name|s0_load_x
parameter_list|(
name|struct
name|s0
modifier|*
name|a
parameter_list|)
block|{
return|return
name|a
operator|->
name|x
return|;
block|}
end_function

begin_comment
comment|// FIXME: This seems like it should be align 1. This is actually something which
end_comment

begin_comment
comment|// has changed in llvm-gcc recently, previously both x and y would be loaded
end_comment

begin_comment
comment|// with align 1 (in 2363.1 at least).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-FUNCTIONS-LABEL: define i32 @s0_load_y
end_comment

begin_comment
comment|// CHECK-FUNCTIONS: [[s0_load_y:%.*]] = load i32* {{.*}}, align 1
end_comment

begin_comment
comment|// CHECK-FUNCTIONS: ret i32 [[s0_load_y]]
end_comment

begin_function
name|int
name|s0_load_y
parameter_list|(
name|struct
name|s0
modifier|*
name|a
parameter_list|)
block|{
return|return
name|a
operator|->
name|y
return|;
block|}
end_function

begin_comment
comment|// CHECK-FUNCTIONS-LABEL: define void @s0_copy
end_comment

begin_comment
comment|// CHECK-FUNCTIONS: call void @llvm.memcpy.p0i8.p0i8.i64(i8* {{.*}}, i8* {{.*}}, i64 8, i32 4, i1 false)
end_comment

begin_function
name|void
name|s0_copy
parameter_list|(
name|struct
name|s0
modifier|*
name|a
parameter_list|,
name|struct
name|s0
modifier|*
name|b
parameter_list|)
block|{
operator|*
name|b
operator|=
operator|*
name|a
expr_stmt|;
block|}
end_function

begin_comment
comment|//
end_comment

begin_struct
struct|struct
name|s1
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|// CHECK-GLOBAL: @s1_align_x = global i32 1
end_comment

begin_comment
comment|// CHECK-GLOBAL: @s1_align_y = global i32 1
end_comment

begin_comment
comment|// CHECK-GLOBAL: @s1_align = global i32 1
end_comment

begin_decl_stmt
name|int
name|s1_align_x
init|=
name|__alignof
argument_list|(
operator|(
operator|(
expr|struct
name|s1
operator|*
operator|)
literal|0
operator|)
operator|->
name|x
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|s1_align_y
init|=
name|__alignof
argument_list|(
operator|(
operator|(
expr|struct
name|s1
operator|*
operator|)
literal|0
operator|)
operator|->
name|y
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|s1_align
init|=
name|__alignof
argument_list|(
expr|struct
name|s1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-FUNCTIONS-LABEL: define i32 @s1_load_x
end_comment

begin_comment
comment|// CHECK-FUNCTIONS: [[s1_load_x:%.*]] = load i32* {{.*}}, align 1
end_comment

begin_comment
comment|// CHECK-FUNCTIONS: ret i32 [[s1_load_x]]
end_comment

begin_function
name|int
name|s1_load_x
parameter_list|(
name|struct
name|s1
modifier|*
name|a
parameter_list|)
block|{
return|return
name|a
operator|->
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK-FUNCTIONS-LABEL: define i32 @s1_load_y
end_comment

begin_comment
comment|// CHECK-FUNCTIONS: [[s1_load_y:%.*]] = load i32* {{.*}}, align 1
end_comment

begin_comment
comment|// CHECK-FUNCTIONS: ret i32 [[s1_load_y]]
end_comment

begin_function
name|int
name|s1_load_y
parameter_list|(
name|struct
name|s1
modifier|*
name|a
parameter_list|)
block|{
return|return
name|a
operator|->
name|y
return|;
block|}
end_function

begin_comment
comment|// CHECK-FUNCTIONS-LABEL: define void @s1_copy
end_comment

begin_comment
comment|// CHECK-FUNCTIONS: call void @llvm.memcpy.p0i8.p0i8.i64(i8* {{.*}}, i8* {{.*}}, i64 8, i32 1, i1 false)
end_comment

begin_function
name|void
name|s1_copy
parameter_list|(
name|struct
name|s1
modifier|*
name|a
parameter_list|,
name|struct
name|s1
modifier|*
name|b
parameter_list|)
block|{
operator|*
name|b
operator|=
operator|*
name|a
expr_stmt|;
block|}
end_function

begin_comment
comment|//
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|2
name|)
end_pragma

begin_struct
struct|struct
name|s2
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_comment
comment|// CHECK-GLOBAL: @s2_align_x = global i32 2
end_comment

begin_comment
comment|// CHECK-GLOBAL: @s2_align_y = global i32 2
end_comment

begin_comment
comment|// CHECK-GLOBAL: @s2_align = global i32 2
end_comment

begin_decl_stmt
name|int
name|s2_align_x
init|=
name|__alignof
argument_list|(
operator|(
operator|(
expr|struct
name|s2
operator|*
operator|)
literal|0
operator|)
operator|->
name|x
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|s2_align_y
init|=
name|__alignof
argument_list|(
operator|(
operator|(
expr|struct
name|s2
operator|*
operator|)
literal|0
operator|)
operator|->
name|y
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|s2_align
init|=
name|__alignof
argument_list|(
expr|struct
name|s2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-FUNCTIONS-LABEL: define i32 @s2_load_x
end_comment

begin_comment
comment|// CHECK-FUNCTIONS: [[s2_load_y:%.*]] = load i32* {{.*}}, align 2
end_comment

begin_comment
comment|// CHECK-FUNCTIONS: ret i32 [[s2_load_y]]
end_comment

begin_function
name|int
name|s2_load_x
parameter_list|(
name|struct
name|s2
modifier|*
name|a
parameter_list|)
block|{
return|return
name|a
operator|->
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK-FUNCTIONS-LABEL: define i32 @s2_load_y
end_comment

begin_comment
comment|// CHECK-FUNCTIONS: [[s2_load_y:%.*]] = load i32* {{.*}}, align 2
end_comment

begin_comment
comment|// CHECK-FUNCTIONS: ret i32 [[s2_load_y]]
end_comment

begin_function
name|int
name|s2_load_y
parameter_list|(
name|struct
name|s2
modifier|*
name|a
parameter_list|)
block|{
return|return
name|a
operator|->
name|y
return|;
block|}
end_function

begin_comment
comment|// CHECK-FUNCTIONS-LABEL: define void @s2_copy
end_comment

begin_comment
comment|// CHECK-FUNCTIONS: call void @llvm.memcpy.p0i8.p0i8.i64(i8* {{.*}}, i8* {{.*}}, i64 8, i32 2, i1 false)
end_comment

begin_function
name|void
name|s2_copy
parameter_list|(
name|struct
name|s2
modifier|*
name|a
parameter_list|,
name|struct
name|s2
modifier|*
name|b
parameter_list|)
block|{
operator|*
name|b
operator|=
operator|*
name|a
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(packed, aligned)
argument_list|)
name|s3
block|{
name|short
name|aShort
decl_stmt|;
name|int
name|anInt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK-GLOBAL: @s3_1 = global i32 1
end_comment

begin_decl_stmt
name|int
name|s3_1
init|=
name|__alignof
argument_list|(
operator|(
operator|(
expr|struct
name|s3
operator|*
operator|)
literal|0
operator|)
operator|->
name|anInt
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-FUNCTIONS-LABEL: define i32 @test3(
end_comment

begin_function
name|int
name|test3
parameter_list|(
name|struct
name|s3
modifier|*
name|ptr
parameter_list|)
block|{
comment|// CHECK-FUNCTIONS:      [[PTR:%.*]] = getelementptr inbounds {{%.*}}* {{%.*}}, i32 0, i32 1
comment|// CHECK-FUNCTIONS-NEXT: load i32* [[PTR]], align 1
return|return
name|ptr
operator|->
name|anInt
return|;
block|}
end_function

end_unit

