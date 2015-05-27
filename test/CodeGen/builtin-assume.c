begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-mingw32 -fms-extensions -emit-llvm -o - %s | FileCheck %s
end_comment

begin_function_decl
name|int
name|nonconst
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isconst
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(const
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|ispure
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(pure
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK-LABEL: @test1
end_comment

begin_function
name|int
name|test1
parameter_list|(
name|int
modifier|*
name|a
parameter_list|,
name|int
name|i
parameter_list|)
block|{
comment|// CHECK: store i32* %a, i32** [[A_ADDR:%.+]], align
comment|// CHECK: [[A:%.+]] = load i32*, i32** [[A_ADDR]]
comment|// CHECK: [[CMP:%.+]] = icmp ne i32* [[A]], null
comment|// CHECK: call void @llvm.assume(i1 [[CMP]])
comment|// CHECK: [[CALL:%.+]] = call i32 @isconst()
comment|// CHECK: [[BOOL:%.+]] = icmp ne i32 [[CALL]], 0
comment|// CHECK: call void @llvm.assume(i1 [[BOOL]])
comment|// CHECK: [[CALLPURE:%.+]] = call i32 @ispure()
comment|// CHECK: [[BOOLPURE:%.+]] = icmp ne i32 [[CALLPURE]], 0
comment|// CHECK: call void @llvm.assume(i1 [[BOOLPURE]])
ifdef|#
directive|ifdef
name|_MSC_VER
name|__assume
argument_list|(
argument|a !=
literal|0
argument_list|)
name|__assume
argument_list|(
name|isconst
argument_list|()
argument_list|)
expr_stmt|;
name|__assume
argument_list|(
name|ispure
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
name|__builtin_assume
argument_list|(
name|a
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|__builtin_assume
argument_list|(
name|isconst
argument_list|()
argument_list|)
expr_stmt|;
name|__builtin_assume
argument_list|(
name|ispure
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// Nothing is generated for an assume with side effects...
comment|// CHECK-NOT: load i32*, i32** %i.addr
comment|// CHECK-NOT: call void @llvm.assume
comment|// CHECK-NOT: call i32 @nonconst()
ifdef|#
directive|ifdef
name|_MSC_VER
name|__assume
argument_list|(
argument|++i !=
literal|0
argument_list|)
name|__assume
argument_list|(
name|nonconst
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
name|__builtin_assume
argument_list|(
operator|++
name|i
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|__builtin_assume
argument_list|(
name|nonconst
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|a
index|[
literal|0
index|]
return|;
block|}
end_function

end_unit

