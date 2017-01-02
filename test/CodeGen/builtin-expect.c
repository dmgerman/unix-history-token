begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -o - %s -O1 -disable-llvm-passes | FileCheck %s --check-prefix=ALL --check-prefix=O1
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -o - %s -O0 | FileCheck %s --check-prefix=ALL --check-prefix=O0
end_comment

begin_comment
comment|// In all tests, make sure that no expect is generated if optimizations are off.
end_comment

begin_comment
comment|// If optimizations are on, generate the correct expect and preserve other necessary operations.
end_comment

begin_function
name|int
name|expect_taken
parameter_list|(
name|int
name|x
parameter_list|)
block|{
comment|// ALL-LABEL: define i32 @expect_taken
comment|// O1:        call i64 @llvm.expect.i64(i64 {{%.*}}, i64 1)
comment|// O0-NOT:    @llvm.expect
if|if
condition|(
name|__builtin_expect
argument_list|(
name|x
argument_list|,
literal|1
argument_list|)
condition|)
return|return
literal|0
return|;
return|return
name|x
return|;
block|}
end_function

begin_function
name|int
name|expect_not_taken
parameter_list|(
name|int
name|x
parameter_list|)
block|{
comment|// ALL-LABEL: define i32 @expect_not_taken
comment|// O1:        call i64 @llvm.expect.i64(i64 {{%.*}}, i64 0)
comment|// O0-NOT:    @llvm.expect
if|if
condition|(
name|__builtin_expect
argument_list|(
name|x
argument_list|,
literal|0
argument_list|)
condition|)
return|return
literal|0
return|;
return|return
name|x
return|;
block|}
end_function

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|y
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|expect_value_side_effects
parameter_list|()
block|{
comment|// ALL-LABEL: define void @expect_value_side_effects()
comment|// ALL:       [[CALL:%.*]] = call i32 @y
comment|// O1:        [[SEXT:%.*]] = sext i32 [[CALL]] to i64
comment|// O1:        call i64 @llvm.expect.i64(i64 {{%.*}}, i64 [[SEXT]])
comment|// O0-NOT:    @llvm.expect
if|if
condition|(
name|__builtin_expect
argument_list|(
name|x
argument_list|,
name|y
argument_list|()
argument_list|)
condition|)
name|foo
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// Make sure that issigprocmask() is called before bar()?
end_comment

begin_comment
comment|// There's no compare, so there's nothing to expect?
end_comment

begin_comment
comment|// rdar://9330105
end_comment

begin_function_decl
name|void
name|isigprocmask
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|bar
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// ALL-LABEL: define i32 @main()
comment|// ALL:       call void @isigprocmask()
comment|// ALL:       [[CALL:%.*]] = call i64 (...) @bar()
comment|// O1:        call i64 @llvm.expect.i64(i64 0, i64 [[CALL]])
comment|// O0-NOT:    @llvm.expect
operator|(
name|void
operator|)
name|__builtin_expect
argument_list|(
operator|(
name|isigprocmask
argument_list|()
operator|,
literal|0
operator|)
argument_list|,
name|bar
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|switch_cond
parameter_list|(
name|int
name|x
parameter_list|)
block|{
comment|// ALL-LABEL: define i32 @switch_cond
comment|// O1:        call i64 @llvm.expect.i64(i64 {{%.*}}, i64 5)
comment|// O0-NOT:    @llvm.expect
switch|switch
condition|(
name|__builtin_expect
argument_list|(
name|x
argument_list|,
literal|5
argument_list|)
condition|)
block|{
default|default:
return|return
literal|0
return|;
case|case
literal|0
case|:
case|case
literal|1
case|:
case|case
literal|2
case|:
return|return
literal|1
return|;
case|case
literal|5
case|:
return|return
literal|5
return|;
block|}
empty_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

