begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.7.0 %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: %{{[a-z0-9]+}} = notail call i32 @callee0(i32 %
end_comment

begin_comment
comment|// CHECK: %{{[a-z0-9]+}} = notail call i32 @callee1(i32 %
end_comment

begin_comment
comment|// Check that indirect calls do not have the notail marker.
end_comment

begin_comment
comment|// CHECK: store i32 (i32)* @callee1, i32 (i32)** [[ALLOCA1:%[A-Za-z0-9]+]], align 8
end_comment

begin_comment
comment|// CHECK: [[INDIRFUNC:%[0-9]+]] = load i32 (i32)*, i32 (i32)** [[ALLOCA1]], align 8
end_comment

begin_comment
comment|// CHECK: %{{[a-z0-9]+}} = call i32 [[INDIRFUNC]](i32 %{{[0-9]+}}
end_comment

begin_comment
comment|// CHECK: %{{[a-z0-9]+}} = call i32 @callee2(i32 %
end_comment

begin_function
name|int
name|callee0
parameter_list|(
name|int
name|a
parameter_list|)
function|__attribute__
parameter_list|(
function|(not_tail_called
end_function

begin_block
unit|))
block|{
return|return
name|a
operator|+
literal|1
return|;
block|}
end_block

begin_function_decl
name|int
name|callee1
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(not_tail_called
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|callee2
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|FuncTy
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef

begin_function
name|int
name|foo0
parameter_list|(
name|int
name|a
parameter_list|)
block|{
if|if
condition|(
name|a
operator|>
literal|1
condition|)
return|return
name|callee0
argument_list|(
name|a
argument_list|)
return|;
if|if
condition|(
name|a
operator|==
literal|1
condition|)
return|return
name|callee1
argument_list|(
name|a
argument_list|)
return|;
if|if
condition|(
name|a
operator|<
literal|0
condition|)
block|{
name|FuncTy
name|F
init|=
name|callee1
decl_stmt|;
return|return
call|(
modifier|*
name|F
call|)
argument_list|(
name|a
argument_list|)
return|;
block|}
return|return
name|callee2
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

end_unit

