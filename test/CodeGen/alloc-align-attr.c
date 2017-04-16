begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-linux -emit-llvm -o - %s | FileCheck %s
end_comment

begin_function_decl
name|__INT32_TYPE__
modifier|*
name|m1
parameter_list|(
name|__INT32_TYPE__
name|i
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_align
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Condition where parameter to m1 is not size_t.
end_comment

begin_function
name|__INT32_TYPE__
name|test1
parameter_list|(
name|__INT32_TYPE__
name|a
parameter_list|)
block|{
comment|// CHECK: define i32 @test1
return|return
operator|*
name|m1
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: call i32* @m1(i32 [[PARAM1:%[^\)]+]])
comment|// CHECK: [[ALIGNCAST1:%.+]] = sext i32 [[PARAM1]] to i64
comment|// CHECK: [[ISPOS1:%.+]] = icmp sgt i64 [[ALIGNCAST1]], 0
comment|// CHECK: [[POSMASK1:%.+]] = sub i64 [[ALIGNCAST1]], 1
comment|// CHECK: [[MASK1:%.+]] = select i1 [[ISPOS1]], i64 [[POSMASK1]], i64 0
comment|// CHECK: [[PTRINT1:%.+]] = ptrtoint
comment|// CHECK: [[MASKEDPTR1:%.+]] = and i64 [[PTRINT1]], [[MASK1]]
comment|// CHECK: [[MASKCOND1:%.+]] = icmp eq i64 [[MASKEDPTR1]], 0
comment|// CHECK: call void @llvm.assume(i1 [[MASKCOND1]])
block|}
end_function

begin_comment
comment|// Condition where test2 param needs casting.
end_comment

begin_function
name|__INT32_TYPE__
name|test2
parameter_list|(
name|__SIZE_TYPE__
name|a
parameter_list|)
block|{
comment|// CHECK: define i32 @test2
return|return
operator|*
name|m1
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: [[CONV2:%.+]] = trunc i64 %{{.+}} to i32
comment|// CHECK: call i32* @m1(i32 [[CONV2]])
comment|// CHECK: [[ALIGNCAST2:%.+]] = sext i32 [[CONV2]] to i64
comment|// CHECK: [[ISPOS2:%.+]] = icmp sgt i64 [[ALIGNCAST2]], 0
comment|// CHECK: [[POSMASK2:%.+]] = sub i64 [[ALIGNCAST2]], 1
comment|// CHECK: [[MASK2:%.+]] = select i1 [[ISPOS2]], i64 [[POSMASK2]], i64 0
comment|// CHECK: [[PTRINT2:%.+]] = ptrtoint
comment|// CHECK: [[MASKEDPTR2:%.+]] = and i64 [[PTRINT2]], [[MASK2]]
comment|// CHECK: [[MASKCOND2:%.+]] = icmp eq i64 [[MASKEDPTR2]], 0
comment|// CHECK: call void @llvm.assume(i1 [[MASKCOND2]])
block|}
end_function

begin_function_decl
name|__INT32_TYPE__
modifier|*
name|m2
parameter_list|(
name|__SIZE_TYPE__
name|i
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_align
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// test3 param needs casting, but 'm2' is correct.
end_comment

begin_function
name|__INT32_TYPE__
name|test3
parameter_list|(
name|__INT32_TYPE__
name|a
parameter_list|)
block|{
comment|// CHECK: define i32 @test3
return|return
operator|*
name|m2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: [[CONV3:%.+]] = sext i32 %{{.+}} to i64
comment|// CHECK: call i32* @m2(i64 [[CONV3]])
comment|// CHECK: [[ISPOS3:%.+]] = icmp sgt i64 [[CONV3]], 0
comment|// CHECK: [[POSMASK3:%.+]] = sub i64 [[CONV3]], 1
comment|// CHECK: [[MASK3:%.+]] = select i1 [[ISPOS3]], i64 [[POSMASK3]], i64 0
comment|// CHECK: [[PTRINT3:%.+]] = ptrtoint
comment|// CHECK: [[MASKEDPTR3:%.+]] = and i64 [[PTRINT3]], [[MASK3]]
comment|// CHECK: [[MASKCOND3:%.+]] = icmp eq i64 [[MASKEDPTR3]], 0
comment|// CHECK: call void @llvm.assume(i1 [[MASKCOND3]])
block|}
end_function

begin_comment
comment|// Every type matches, canonical example.
end_comment

begin_function
name|__INT32_TYPE__
name|test4
parameter_list|(
name|__SIZE_TYPE__
name|a
parameter_list|)
block|{
comment|// CHECK: define i32 @test4
return|return
operator|*
name|m2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: call i32* @m2(i64 [[PARAM4:%[^\)]+]])
comment|// CHECK: [[ISPOS4:%.+]] = icmp sgt i64 [[PARAM4]], 0
comment|// CHECK: [[POSMASK4:%.+]] = sub i64 [[PARAM4]], 1
comment|// CHECK: [[MASK4:%.+]] = select i1 [[ISPOS4]], i64 [[POSMASK4]], i64 0
comment|// CHECK: [[PTRINT4:%.+]] = ptrtoint
comment|// CHECK: [[MASKEDPTR4:%.+]] = and i64 [[PTRINT4]], [[MASK4]]
comment|// CHECK: [[MASKCOND4:%.+]] = icmp eq i64 [[MASKEDPTR4]], 0
comment|// CHECK: call void @llvm.assume(i1 [[MASKCOND4]])
block|}
end_function

begin_struct
struct|struct
name|Empty
block|{}
struct|;
end_struct

begin_struct
struct|struct
name|MultiArgs
block|{
name|__INT64_TYPE__
name|a
decl_stmt|,
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// Struct parameter doesn't take up an IR parameter, 'i' takes up 2.
end_comment

begin_comment
comment|// Truncation to i64 is permissible, since alignments of greater than 2^64 are insane.
end_comment

begin_function_decl
name|__INT32_TYPE__
modifier|*
name|m3
parameter_list|(
name|struct
name|Empty
name|s
parameter_list|,
name|__int128_t
name|i
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_align
parameter_list|(
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|__INT32_TYPE__
name|test5
parameter_list|(
name|__int128_t
name|a
parameter_list|)
block|{
comment|// CHECK: define i32 @test5
name|struct
name|Empty
name|e
decl_stmt|;
return|return
operator|*
name|m3
argument_list|(
name|e
argument_list|,
name|a
argument_list|)
return|;
comment|// CHECK: call i32* @m3(i64 %{{.*}}, i64 %{{.*}})
comment|// CHECK: [[ALIGNCAST5:%.+]] = trunc i128 %{{.*}} to i64
comment|// CHECK: [[ISPOS5:%.+]] = icmp sgt i64 [[ALIGNCAST5]], 0
comment|// CHECK: [[POSMASK5:%.+]] = sub i64 [[ALIGNCAST5]], 1
comment|// CHECK: [[MASK5:%.+]] = select i1 [[ISPOS5]], i64 [[POSMASK5]], i64 0
comment|// CHECK: [[PTRINT5:%.+]] = ptrtoint
comment|// CHECK: [[MASKEDPTR5:%.+]] = and i64 [[PTRINT5]], [[MASK5]]
comment|// CHECK: [[MASKCOND5:%.+]] = icmp eq i64 [[MASKEDPTR5]], 0
comment|// CHECK: call void @llvm.assume(i1 [[MASKCOND5]])
block|}
end_function

begin_comment
comment|// Struct parameter takes up 2 parameters, 'i' takes up 2.
end_comment

begin_function_decl
name|__INT32_TYPE__
modifier|*
name|m4
parameter_list|(
name|struct
name|MultiArgs
name|s
parameter_list|,
name|__int128_t
name|i
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_align
parameter_list|(
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|__INT32_TYPE__
name|test6
parameter_list|(
name|__int128_t
name|a
parameter_list|)
block|{
comment|// CHECK: define i32 @test6
name|struct
name|MultiArgs
name|e
decl_stmt|;
return|return
operator|*
name|m4
argument_list|(
name|e
argument_list|,
name|a
argument_list|)
return|;
comment|// CHECK: call i32* @m4(i64 %{{.*}}, i64 %{{.*}}, i64 %{{.*}})
comment|// CHECK: [[ALIGNCAST6:%.+]] = trunc i128 %{{.*}} to i64
comment|// CHECK: [[ISPOS6:%.+]] = icmp sgt i64 [[ALIGNCAST6]], 0
comment|// CHECK: [[POSMASK6:%.+]] = sub i64 [[ALIGNCAST6]], 1
comment|// CHECK: [[MASK6:%.+]] = select i1 [[ISPOS6]], i64 [[POSMASK6]], i64 0
comment|// CHECK: [[PTRINT6:%.+]] = ptrtoint
comment|// CHECK: [[MASKEDPTR6:%.+]] = and i64 [[PTRINT6]], [[MASK6]]
comment|// CHECK: [[MASKCOND6:%.+]] = icmp eq i64 [[MASKEDPTR6]], 0
comment|// CHECK: call void @llvm.assume(i1 [[MASKCOND6]])
block|}
end_function

end_unit

