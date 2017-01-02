begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -disable-llvm-passes -o - %s -O1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -o - %s -O0 | FileCheck %s --check-prefix=CHECK_O0
end_comment

begin_comment
comment|// When optimizing, the builtin should be converted to metadata.
end_comment

begin_comment
comment|// When not optimizing, there should be no metadata created for the builtin.
end_comment

begin_comment
comment|// In both cases, the builtin should be removed from the code.
end_comment

begin_function_decl
name|void
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|branch
parameter_list|(
name|int
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @branch(
comment|// CHECK-NOT: builtin_unpredictable
comment|// CHECK: !unpredictable [[METADATA:.+]]
comment|// CHECK_O0-NOT: builtin_unpredictable
comment|// CHECK_O0-NOT: !unpredictable
if|if
condition|(
name|__builtin_unpredictable
argument_list|(
name|x
operator|>
literal|0
argument_list|)
condition|)
name|foo
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|int
name|unpredictable_switch
parameter_list|(
name|int
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: @unpredictable_switch(
comment|// CHECK-NOT: builtin_unpredictable
comment|// CHECK: !unpredictable [[METADATA:.+]]
comment|// CHECK_O0-NOT: builtin_unpredictable
comment|// CHECK_O0-NOT: !unpredictable
switch|switch
condition|(
name|__builtin_unpredictable
argument_list|(
name|x
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

begin_comment
comment|// CHECK: [[METADATA]] = !{}
end_comment

end_unit

