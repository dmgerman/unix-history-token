begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin -emit-llvm -O0 %s -o - 2>&1 | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|size_t
typedef|;
end_typedef

begin_struct
struct|struct
name|Foo
block|{
name|int
name|t
index|[
literal|10
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PS
parameter_list|(
name|N
parameter_list|)
value|__attribute__((pass_object_size(N)))
end_define

begin_decl_stmt
name|int
name|gi
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define i32 @ObjectSize0(i8* %{{.*}}, i64)
end_comment

begin_decl_stmt
name|int
name|ObjectSize0
argument_list|(
name|void
operator|*
specifier|const
name|p
name|PS
argument_list|(
literal|0
argument_list|)
argument_list|)
block|{
comment|// CHECK-NOT: @llvm.objectsize
return|return
name|__builtin_object_size
argument_list|(
name|p
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define i32 @ObjectSize1(i8* %{{.*}}, i64)
end_comment

begin_decl_stmt
name|int
name|ObjectSize1
argument_list|(
name|void
operator|*
specifier|const
name|p
name|PS
argument_list|(
literal|1
argument_list|)
argument_list|)
block|{
comment|// CHECK-NOT: @llvm.objectsize
return|return
name|__builtin_object_size
argument_list|(
name|p
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define i32 @ObjectSize2(i8* %{{.*}}, i64)
end_comment

begin_decl_stmt
name|int
name|ObjectSize2
argument_list|(
name|void
operator|*
specifier|const
name|p
name|PS
argument_list|(
literal|2
argument_list|)
argument_list|)
block|{
comment|// CHECK-NOT: @llvm.objectsize
return|return
name|__builtin_object_size
argument_list|(
name|p
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define i32 @ObjectSize3(i8* %{{.*}}, i64)
end_comment

begin_decl_stmt
name|int
name|ObjectSize3
argument_list|(
name|void
operator|*
specifier|const
name|p
name|PS
argument_list|(
literal|3
argument_list|)
argument_list|)
block|{
comment|// CHECK-NOT: @llvm.objectsize
return|return
name|__builtin_object_size
argument_list|(
name|p
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define void @test1
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
name|struct
name|Foo
name|t
index|[
literal|10
index|]
decl_stmt|;
comment|// CHECK: call i32 @ObjectSize0(i8* %{{.*}}, i64 360)
name|gi
operator|=
name|ObjectSize0
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @ObjectSize1(i8* %{{.*}}, i64 360)
name|gi
operator|=
name|ObjectSize1
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @ObjectSize2(i8* %{{.*}}, i64 360)
name|gi
operator|=
name|ObjectSize2
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @ObjectSize3(i8* %{{.*}}, i64 360)
name|gi
operator|=
name|ObjectSize3
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @ObjectSize0(i8* %{{.*}}, i64 356)
name|gi
operator|=
name|ObjectSize0
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @ObjectSize1(i8* %{{.*}}, i64 36)
name|gi
operator|=
name|ObjectSize1
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @ObjectSize2(i8* %{{.*}}, i64 356)
name|gi
operator|=
name|ObjectSize2
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @ObjectSize3(i8* %{{.*}}, i64 36)
name|gi
operator|=
name|ObjectSize3
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test2
end_comment

begin_function
name|void
name|test2
parameter_list|(
name|struct
name|Foo
modifier|*
name|t
parameter_list|)
block|{
comment|// CHECK: [[VAR:%[0-9]+]] = call i64 @llvm.objectsize
comment|// CHECK: call i32 @ObjectSize1(i8* %{{.*}}, i64 [[VAR]])
name|gi
operator|=
name|ObjectSize1
argument_list|(
operator|&
name|t
operator|->
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @ObjectSize3(i8* %{{.*}}, i64 36)
name|gi
operator|=
name|ObjectSize3
argument_list|(
operator|&
name|t
operator|->
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @_Z27NoViableOverloadObjectSize0Pv
end_comment

begin_function
name|int
name|NoViableOverloadObjectSize0
parameter_list|(
name|void
modifier|*
specifier|const
name|p
parameter_list|)
function|__attribute__
parameter_list|(
function|(overloadable
end_function

begin_block
unit|))
block|{
comment|// CHECK: @llvm.objectsize
return|return
name|__builtin_object_size
argument_list|(
name|p
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_block

begin_comment
comment|// CHECK-LABEL: define i32 @_Z27NoViableOverloadObjectSize1Pv
end_comment

begin_function
name|int
name|NoViableOverloadObjectSize1
parameter_list|(
name|void
modifier|*
specifier|const
name|p
parameter_list|)
function|__attribute__
parameter_list|(
function|(overloadable
end_function

begin_block
unit|))
block|{
comment|// CHECK: @llvm.objectsize
return|return
name|__builtin_object_size
argument_list|(
name|p
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_block

begin_comment
comment|// CHECK-LABEL: define i32 @_Z27NoViableOverloadObjectSize2Pv
end_comment

begin_function
name|int
name|NoViableOverloadObjectSize2
parameter_list|(
name|void
modifier|*
specifier|const
name|p
parameter_list|)
function|__attribute__
parameter_list|(
function|(overloadable
end_function

begin_block
unit|))
block|{
comment|// CHECK: @llvm.objectsize
return|return
name|__builtin_object_size
argument_list|(
name|p
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_block

begin_comment
comment|// CHECK-LABEL: define i32 @_Z27NoViableOverloadObjectSize3Pv
end_comment

begin_function
name|int
name|NoViableOverloadObjectSize3
parameter_list|(
name|void
modifier|*
specifier|const
name|p
parameter_list|)
function|__attribute__
parameter_list|(
function|(overloadable
end_function

begin_block
unit|))
block|{
comment|// CHECK-NOT: @llvm.objectsize
return|return
name|__builtin_object_size
argument_list|(
name|p
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_block

begin_comment
comment|// CHECK-LABEL: define i32 @_Z27NoViableOverloadObjectSize0Pv
end_comment

begin_comment
comment|// CHECK-NOT: @llvm.objectsize
end_comment

begin_decl_stmt
name|int
name|NoViableOverloadObjectSize0
argument_list|(
name|void
operator|*
specifier|const
name|p
name|PS
argument_list|(
literal|0
argument_list|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
block|{
return|return
name|__builtin_object_size
argument_list|(
name|p
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|int
name|NoViableOverloadObjectSize1
argument_list|(
name|void
operator|*
specifier|const
name|p
name|PS
argument_list|(
literal|1
argument_list|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
block|{
return|return
name|__builtin_object_size
argument_list|(
name|p
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|int
name|NoViableOverloadObjectSize2
argument_list|(
name|void
operator|*
specifier|const
name|p
name|PS
argument_list|(
literal|2
argument_list|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
block|{
return|return
name|__builtin_object_size
argument_list|(
name|p
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|int
name|NoViableOverloadObjectSize3
argument_list|(
name|void
operator|*
specifier|const
name|p
name|PS
argument_list|(
literal|3
argument_list|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
block|{
return|return
name|__builtin_object_size
argument_list|(
name|p
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|const
specifier|static
name|int
name|SHOULDNT_BE_CALLED
init|=
operator|-
literal|100
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|NoViableOverloadObjectSize0
argument_list|(
name|void
operator|*
specifier|const
name|p
name|PS
argument_list|(
literal|0
argument_list|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|,
name|enable_if
argument_list|(
name|p
operator|==
literal|0
argument_list|,
literal|"never selected"
argument_list|)
operator|)
argument_list|)
block|{
return|return
name|SHOULDNT_BE_CALLED
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|int
name|NoViableOverloadObjectSize1
argument_list|(
name|void
operator|*
specifier|const
name|p
name|PS
argument_list|(
literal|1
argument_list|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|,
name|enable_if
argument_list|(
name|p
operator|==
literal|0
argument_list|,
literal|"never selected"
argument_list|)
operator|)
argument_list|)
block|{
return|return
name|SHOULDNT_BE_CALLED
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|int
name|NoViableOverloadObjectSize2
argument_list|(
name|void
operator|*
specifier|const
name|p
name|PS
argument_list|(
literal|2
argument_list|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|,
name|enable_if
argument_list|(
name|p
operator|==
literal|0
argument_list|,
literal|"never selected"
argument_list|)
operator|)
argument_list|)
block|{
return|return
name|SHOULDNT_BE_CALLED
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|int
name|NoViableOverloadObjectSize3
argument_list|(
name|void
operator|*
specifier|const
name|p
name|PS
argument_list|(
literal|3
argument_list|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|,
name|enable_if
argument_list|(
name|p
operator|==
literal|0
argument_list|,
literal|"never selected"
argument_list|)
operator|)
argument_list|)
block|{
return|return
name|SHOULDNT_BE_CALLED
return|;
block|}
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define void @test3
end_comment

begin_function
name|void
name|test3
parameter_list|()
block|{
name|struct
name|Foo
name|t
index|[
literal|10
index|]
decl_stmt|;
comment|// CHECK: call i32 @_Z27NoViableOverloadObjectSize0PvU17pass_object_size0(i8* %{{.*}}, i64 360)
name|gi
operator|=
name|NoViableOverloadObjectSize0
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @_Z27NoViableOverloadObjectSize1PvU17pass_object_size1(i8* %{{.*}}, i64 360)
name|gi
operator|=
name|NoViableOverloadObjectSize1
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @_Z27NoViableOverloadObjectSize2PvU17pass_object_size2(i8* %{{.*}}, i64 360)
name|gi
operator|=
name|NoViableOverloadObjectSize2
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @_Z27NoViableOverloadObjectSize3PvU17pass_object_size3(i8* %{{.*}}, i64 360)
name|gi
operator|=
name|NoViableOverloadObjectSize3
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @_Z27NoViableOverloadObjectSize0PvU17pass_object_size0(i8* %{{.*}}, i64 356)
name|gi
operator|=
name|NoViableOverloadObjectSize0
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @_Z27NoViableOverloadObjectSize1PvU17pass_object_size1(i8* %{{.*}}, i64 36)
name|gi
operator|=
name|NoViableOverloadObjectSize1
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @_Z27NoViableOverloadObjectSize2PvU17pass_object_size2(i8* %{{.*}}, i64 356)
name|gi
operator|=
name|NoViableOverloadObjectSize2
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @_Z27NoViableOverloadObjectSize3PvU17pass_object_size3(i8* %{{.*}}, i64 36)
name|gi
operator|=
name|NoViableOverloadObjectSize3
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test4
end_comment

begin_function
name|void
name|test4
parameter_list|(
name|struct
name|Foo
modifier|*
name|t
parameter_list|)
block|{
comment|// CHECK: call i32 @_Z27NoViableOverloadObjectSize0PvU17pass_object_size0(i8* %{{.*}}, i64 %{{.*}})
name|gi
operator|=
name|NoViableOverloadObjectSize0
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @_Z27NoViableOverloadObjectSize1PvU17pass_object_size1(i8* %{{.*}}, i64 %{{.*}})
name|gi
operator|=
name|NoViableOverloadObjectSize1
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @_Z27NoViableOverloadObjectSize2PvU17pass_object_size2(i8* %{{.*}}, i64 %{{.*}})
name|gi
operator|=
name|NoViableOverloadObjectSize2
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @_Z27NoViableOverloadObjectSize3PvU17pass_object_size3(i8* %{{.*}}, i64 0)
name|gi
operator|=
name|NoViableOverloadObjectSize3
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @_Z27NoViableOverloadObjectSize0PvU17pass_object_size0(i8* %{{.*}}, i64 %{{.*}})
name|gi
operator|=
name|NoViableOverloadObjectSize0
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: [[VAR:%[0-9]+]] = call i64 @llvm.objectsize
comment|// CHECK: call i32 @_Z27NoViableOverloadObjectSize1PvU17pass_object_size1(i8* %{{.*}}, i64 [[VAR]])
name|gi
operator|=
name|NoViableOverloadObjectSize1
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @_Z27NoViableOverloadObjectSize2PvU17pass_object_size2(i8* %{{.*}}, i64 %{{.*}})
name|gi
operator|=
name|NoViableOverloadObjectSize2
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @_Z27NoViableOverloadObjectSize3PvU17pass_object_size3(i8* %{{.*}}, i64 36)
name|gi
operator|=
name|NoViableOverloadObjectSize3
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test5
parameter_list|()
block|{
name|struct
name|Foo
name|t
index|[
literal|10
index|]
decl_stmt|;
name|int
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
init|=
operator|&
name|NoViableOverloadObjectSize0
function_decl|;
name|gi
operator|=
name|f
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @IndirectObjectSize0
end_comment

begin_decl_stmt
name|int
name|IndirectObjectSize0
argument_list|(
name|void
operator|*
specifier|const
name|p
name|PS
argument_list|(
literal|0
argument_list|)
argument_list|)
block|{
comment|// CHECK: call i32 @ObjectSize0(i8* %{{.*}}, i64 %{{.*}})
comment|// CHECK-NOT: @llvm.objectsize
return|return
name|ObjectSize0
argument_list|(
name|p
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define i32 @IndirectObjectSize1
end_comment

begin_decl_stmt
name|int
name|IndirectObjectSize1
argument_list|(
name|void
operator|*
specifier|const
name|p
name|PS
argument_list|(
literal|1
argument_list|)
argument_list|)
block|{
comment|// CHECK: call i32 @ObjectSize1(i8* %{{.*}}, i64 %{{.*}})
comment|// CHECK-NOT: @llvm.objectsize
return|return
name|ObjectSize1
argument_list|(
name|p
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define i32 @IndirectObjectSize2
end_comment

begin_decl_stmt
name|int
name|IndirectObjectSize2
argument_list|(
name|void
operator|*
specifier|const
name|p
name|PS
argument_list|(
literal|2
argument_list|)
argument_list|)
block|{
comment|// CHECK: call i32 @ObjectSize2(i8* %{{.*}}, i64 %{{.*}})
comment|// CHECK-NOT: @llvm.objectsize
return|return
name|ObjectSize2
argument_list|(
name|p
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define i32 @IndirectObjectSize3
end_comment

begin_decl_stmt
name|int
name|IndirectObjectSize3
argument_list|(
name|void
operator|*
specifier|const
name|p
name|PS
argument_list|(
literal|3
argument_list|)
argument_list|)
block|{
comment|// CHECK: call i32 @ObjectSize3(i8* %{{.*}}, i64 %{{.*}})
comment|// CHECK-NOT: @llvm.objectsize
return|return
name|ObjectSize3
argument_list|(
name|p
argument_list|)
return|;
block|}
end_decl_stmt

begin_function_decl
name|int
name|Overload0
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|OverloadNoSize
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|OverloadedObjectSize
argument_list|(
name|void
operator|*
specifier|const
name|p
name|PS
argument_list|(
literal|0
argument_list|)
argument_list|,
name|void
operator|*
specifier|const
name|c
name|PS
argument_list|(
literal|0
argument_list|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
name|__asm__
argument_list|(
literal|"Overload0"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|OverloadedObjectSize
argument_list|(
name|void
operator|*
specifier|const
name|p
argument_list|,
name|void
operator|*
specifier|const
name|c
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|overloadable
operator|)
argument_list|)
name|__asm__
argument_list|(
literal|"OverloadNoSize"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define void @test6
end_comment

begin_function
name|void
name|test6
parameter_list|()
block|{
name|int
name|known
index|[
literal|10
index|]
decl_stmt|,
modifier|*
name|opaque
decl_stmt|;
comment|// CHECK: call i32 @"\01Overload0"
name|gi
operator|=
name|OverloadedObjectSize
argument_list|(
operator|&
name|known
index|[
literal|0
index|]
argument_list|,
operator|&
name|known
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @"\01Overload0"
name|gi
operator|=
name|OverloadedObjectSize
argument_list|(
operator|&
name|known
index|[
literal|0
index|]
argument_list|,
name|opaque
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @"\01Overload0"
name|gi
operator|=
name|OverloadedObjectSize
argument_list|(
name|opaque
argument_list|,
operator|&
name|known
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @"\01Overload0"
name|gi
operator|=
name|OverloadedObjectSize
argument_list|(
name|opaque
argument_list|,
name|opaque
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|Identity
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|size_t
name|i
parameter_list|)
block|{
return|return
name|i
return|;
block|}
end_function

begin_comment
comment|// CHECK-NOT: define void @AsmObjectSize
end_comment

begin_decl_stmt
name|int
name|AsmObjectSize0
argument_list|(
name|void
operator|*
specifier|const
name|p
name|PS
argument_list|(
literal|0
argument_list|)
argument_list|)
name|__asm__
argument_list|(
literal|"Identity"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|AsmObjectSize1
argument_list|(
name|void
operator|*
specifier|const
name|p
name|PS
argument_list|(
literal|1
argument_list|)
argument_list|)
name|__asm__
argument_list|(
literal|"Identity"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|AsmObjectSize2
argument_list|(
name|void
operator|*
specifier|const
name|p
name|PS
argument_list|(
literal|2
argument_list|)
argument_list|)
name|__asm__
argument_list|(
literal|"Identity"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|AsmObjectSize3
argument_list|(
name|void
operator|*
specifier|const
name|p
name|PS
argument_list|(
literal|3
argument_list|)
argument_list|)
name|__asm__
argument_list|(
literal|"Identity"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define void @test7
end_comment

begin_function
name|void
name|test7
parameter_list|()
block|{
name|struct
name|Foo
name|t
index|[
literal|10
index|]
decl_stmt|;
comment|// CHECK: call i32 @"\01Identity"(i8* %{{.*}}, i64 360)
name|gi
operator|=
name|AsmObjectSize0
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @"\01Identity"(i8* %{{.*}}, i64 360)
name|gi
operator|=
name|AsmObjectSize1
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @"\01Identity"(i8* %{{.*}}, i64 360)
name|gi
operator|=
name|AsmObjectSize2
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @"\01Identity"(i8* %{{.*}}, i64 360)
name|gi
operator|=
name|AsmObjectSize3
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @"\01Identity"(i8* %{{.*}}, i64 356)
name|gi
operator|=
name|AsmObjectSize0
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @"\01Identity"(i8* %{{.*}}, i64 36)
name|gi
operator|=
name|AsmObjectSize1
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @"\01Identity"(i8* %{{.*}}, i64 356)
name|gi
operator|=
name|AsmObjectSize2
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @"\01Identity"(i8* %{{.*}}, i64 36)
name|gi
operator|=
name|AsmObjectSize3
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test8
end_comment

begin_function
name|void
name|test8
parameter_list|(
name|struct
name|Foo
modifier|*
name|t
parameter_list|)
block|{
comment|// CHECK: [[VAR:%[0-9]+]] = call i64 @llvm.objectsize
comment|// CHECK: call i32 @"\01Identity"(i8* %{{.*}}, i64 [[VAR]])
name|gi
operator|=
name|AsmObjectSize1
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @"\01Identity"(i8* %{{.*}}, i64 36)
name|gi
operator|=
name|AsmObjectSize3
argument_list|(
operator|&
name|t
index|[
literal|1
index|]
operator|.
name|t
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|void
name|DifferingObjectSize0
argument_list|(
name|void
operator|*
specifier|const
name|p
name|__attribute__
argument_list|(
operator|(
name|pass_object_size
argument_list|(
literal|0
argument_list|)
operator|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|DifferingObjectSize1
argument_list|(
name|void
operator|*
specifier|const
name|p
name|__attribute__
argument_list|(
operator|(
name|pass_object_size
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|DifferingObjectSize2
argument_list|(
name|void
operator|*
specifier|const
name|p
name|__attribute__
argument_list|(
operator|(
name|pass_object_size
argument_list|(
literal|2
argument_list|)
operator|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|DifferingObjectSize3
argument_list|(
name|void
operator|*
specifier|const
name|p
name|__attribute__
argument_list|(
operator|(
name|pass_object_size
argument_list|(
literal|3
argument_list|)
operator|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define void @test9
end_comment

begin_decl_stmt
name|void
name|test9
argument_list|(
name|void
operator|*
specifier|const
name|p
name|__attribute__
argument_list|(
operator|(
name|pass_object_size
argument_list|(
literal|0
argument_list|)
operator|)
argument_list|)
argument_list|)
block|{
comment|// CHECK: @llvm.objectsize
name|DifferingObjectSize2
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|// CHECK-NOT: @llvm.objectsize
name|DifferingObjectSize0
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|DifferingObjectSize1
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|// CHECK: call void @DifferingObjectSize3(i8* %{{.*}}, i64 0)
name|DifferingObjectSize3
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define void @test10
end_comment

begin_decl_stmt
name|void
name|test10
argument_list|(
name|void
operator|*
specifier|const
name|p
name|__attribute__
argument_list|(
operator|(
name|pass_object_size
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
argument_list|)
block|{
comment|// CHECK: @llvm.objectsize
name|DifferingObjectSize2
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.objectsize
name|DifferingObjectSize0
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|// CHECK-NOT: @llvm.objectsize
name|DifferingObjectSize1
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|// CHECK: call void @DifferingObjectSize3(i8* %{{.*}}, i64 0)
name|DifferingObjectSize3
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define void @test11
end_comment

begin_decl_stmt
name|void
name|test11
argument_list|(
name|void
operator|*
specifier|const
name|p
name|__attribute__
argument_list|(
operator|(
name|pass_object_size
argument_list|(
literal|2
argument_list|)
operator|)
argument_list|)
argument_list|)
block|{
comment|// CHECK: @llvm.objectsize
name|DifferingObjectSize0
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.objectsize
name|DifferingObjectSize1
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|// CHECK-NOT: @llvm.objectsize
name|DifferingObjectSize2
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|// CHECK: call void @DifferingObjectSize3(i8* %{{.*}}, i64 0)
name|DifferingObjectSize3
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define void @test12
end_comment

begin_decl_stmt
name|void
name|test12
argument_list|(
name|void
operator|*
specifier|const
name|p
name|__attribute__
argument_list|(
operator|(
name|pass_object_size
argument_list|(
literal|3
argument_list|)
operator|)
argument_list|)
argument_list|)
block|{
comment|// CHECK: @llvm.objectsize
name|DifferingObjectSize0
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.objectsize
name|DifferingObjectSize1
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|// CHECK-NOT: @llvm.objectsize
name|DifferingObjectSize2
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|DifferingObjectSize3
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define void @test13
end_comment

begin_function
name|void
name|test13
parameter_list|()
block|{
name|char
name|c
index|[
literal|10
index|]
decl_stmt|;
name|unsigned
name|i
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|p
init|=
name|c
decl_stmt|;
comment|// CHECK: @llvm.objectsize
name|ObjectSize0
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|// Allow side-effects, since they always need to happen anyway. Just make sure
comment|// we don't perform them twice.
comment|// CHECK: = add
comment|// CHECK-NOT: = add
comment|// CHECK: @llvm.objectsize
comment|// CHECK: call i32 @ObjectSize0
name|ObjectSize0
argument_list|(
name|p
operator|+
operator|++
name|i
argument_list|)
expr_stmt|;
comment|// CHECK: = add
comment|// CHECK: @llvm.objectsize
comment|// CHECK-NOT: = add
comment|// CHECK: call i32 @ObjectSize0
name|ObjectSize0
argument_list|(
name|p
operator|+
name|i
operator|++
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// There was a bug where variadic functions with pass_object_size would cause
end_comment

begin_comment
comment|// problems in the form of failed assertions.
end_comment

begin_decl_stmt
name|void
name|my_sprintf
argument_list|(
name|char
operator|*
specifier|const
name|c
name|__attribute__
argument_list|(
operator|(
name|pass_object_size
argument_list|(
literal|0
argument_list|)
operator|)
argument_list|)
argument_list|,
operator|...
argument_list|)
block|{}
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define void @test14
end_comment

begin_function
name|void
name|test14
parameter_list|(
name|char
modifier|*
name|c
parameter_list|)
block|{
comment|// CHECK: @llvm.objectsize
comment|// CHECK: call void (i8*, i64, ...) @my_sprintf
name|my_sprintf
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|// CHECK: @llvm.objectsize
comment|// CHECK: call void (i8*, i64, ...) @my_sprintf
name|my_sprintf
argument_list|(
name|c
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|void
name|pass_size_unsigned
argument_list|(
name|unsigned
operator|*
specifier|const
name|PS
argument_list|(
literal|0
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Bug: we weren't lowering to the proper @llvm.objectsize for pointers that
end_comment

begin_comment
comment|// don't turn into i8*s, which caused crashes.
end_comment

begin_comment
comment|// CHECK-LABEL: define void @test15
end_comment

begin_function
name|void
name|test15
parameter_list|(
name|unsigned
modifier|*
name|I
parameter_list|)
block|{
comment|// CHECK: @llvm.objectsize.i64.p0i32
comment|// CHECK: call void @pass_size_unsigned
name|pass_size_unsigned
argument_list|(
name|I
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|void
name|pass_size_as1
argument_list|(
name|__attribute__
argument_list|(
argument|(address_space(
literal|1
argument|))
argument_list|)
name|void
operator|*
specifier|const
name|PS
argument_list|(
literal|0
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pass_size_unsigned_as1
argument_list|(
name|__attribute__
argument_list|(
argument|(address_space(
literal|1
argument|))
argument_list|)
name|unsigned
operator|*
specifier|const
name|PS
argument_list|(
literal|0
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define void @test16
end_comment

begin_decl_stmt
name|void
name|test16
argument_list|(
name|__attribute__
argument_list|(
argument|(address_space(
literal|1
argument|))
argument_list|)
name|unsigned
operator|*
name|I
argument_list|)
block|{
comment|// CHECK: call i64 @llvm.objectsize.i64.p1i8
comment|// CHECK: call void @pass_size_as1
name|pass_size_as1
argument_list|(
name|I
argument_list|)
expr_stmt|;
comment|// CHECK: call i64 @llvm.objectsize.i64.p1i32
comment|// CHECK: call void @pass_size_unsigned_as1
name|pass_size_unsigned_as1
argument_list|(
name|I
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// This used to cause assertion failures, since we'd try to emit the statement
end_comment

begin_comment
comment|// expression (and definitions for `a`) twice.
end_comment

begin_comment
comment|// CHECK-LABEL: define void @test17
end_comment

begin_function
name|void
name|test17
parameter_list|(
name|char
modifier|*
name|C
parameter_list|)
block|{
comment|// Check for 65535 to see if we're emitting this pointer twice.
comment|// CHECK: 65535
comment|// CHECK-NOT: 65535
comment|// CHECK: @llvm.objectsize.i64.p0i8(i8* [[PTR:%[^,]+]],
comment|// CHECK-NOT: 65535
comment|// CHECK: call i32 @ObjectSize0(i8* [[PTR]]
name|ObjectSize0
argument_list|(
argument|C + ({ int a =
literal|65535
argument|; a; })
argument_list|)
empty_stmt|;
block|}
end_function

end_unit

