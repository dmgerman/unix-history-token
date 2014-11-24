begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -load %llvmshlibdir/PrintFunctionNames%pluginext -plugin print-fns %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// REQUIRES: plugins, examples
end_comment

begin_comment
comment|// CHECK: top-level-decl: "x"
end_comment

begin_function_decl
name|void
name|x
parameter_list|()
function_decl|;
end_function_decl

end_unit

