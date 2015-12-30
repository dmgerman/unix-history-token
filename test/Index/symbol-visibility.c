begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: c-index-test -test-print-visibility %s | FileCheck %s
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(visibility (
literal|"default"
argument|))
argument_list|)
end_macro

begin_function_decl
name|void
name|foo1
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|__attribute__
argument_list|(
argument|(visibility (
literal|"hidden"
argument|))
argument_list|)
end_macro

begin_function_decl
name|void
name|foo2
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// CHECK: FunctionDecl=foo1:3:47visibility=Default
end_comment

begin_comment
comment|// CHECK: FunctionDecl=foo2:4:46visibility=Hidden
end_comment

end_unit

