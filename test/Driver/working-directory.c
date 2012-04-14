begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -ccc-print-options -working-directory "C:\Test" input 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: Option 0 - Name: "-ccc-print-options", Values: {}
end_comment

begin_comment
comment|// CHECK: Option 1 - Name: "-working-directory", Values: {"C:\Test"}
end_comment

begin_comment
comment|// CHECK: Option 2 - Name: "<input>", Values: {"input"}
end_comment

end_unit

