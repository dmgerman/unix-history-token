begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function_decl
name|void
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// RUN: c-index-test -index-file -working-directory=%S %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: [indexDeclaration]: kind: function | name: foo
end_comment

end_unit

