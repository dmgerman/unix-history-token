begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// There should not be an unresolved reference to func here.  Believe it or not,
end_comment

begin_comment
comment|// the "expected result" is a function named 'func' which is internal and
end_comment

begin_comment
comment|// referenced by bar().
end_comment

begin_comment
comment|// This is PR244
end_comment

begin_comment
comment|// CHECK-LABEL: define void @bar(
end_comment

begin_comment
comment|// CHECK: call {{.*}} @func
end_comment

begin_comment
comment|// CHECK: define internal {{.*}}i32 @func(
end_comment

begin_function_decl
specifier|static
name|int
name|func
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|bar
parameter_list|()
block|{
name|int
name|func
parameter_list|()
function_decl|;
name|foo
argument_list|(
name|func
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|func
parameter_list|(
name|char
modifier|*
modifier|*
name|A
parameter_list|,
name|char
modifier|*
modifier|*
name|B
parameter_list|)
block|{}
end_function

end_unit

