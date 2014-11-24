begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ast-print %s | FileCheck %s
end_comment

begin_comment
comment|// This testcase checks the functionality of
end_comment

begin_comment
comment|// Sema::ActOn{Start,End}FunctionDeclarator, specifically checking that
end_comment

begin_comment
comment|// ActOnEndFunctionDeclarator is called after the typedef so the enum
end_comment

begin_comment
comment|// is in the global scope, not the scope of f().
end_comment

begin_comment
comment|// CHECK: typedef void (*g)();
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|g
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_comment
comment|// CHECK: enum {
end_comment

begin_enum
enum|enum
block|{
name|k
init|=
operator|-
literal|1
block|}
enum|;
end_enum

begin_comment
comment|// CHECK: void f() {
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{}
end_function

end_unit

