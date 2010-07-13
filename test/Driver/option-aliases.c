begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -ccc-print-options \
end_comment

begin_comment
comment|// RUN:  --save-temps --undefine-macro=FOO --undefine-macro FOO \
end_comment

begin_comment
comment|// RUN: --param=FOO --output=FOO 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-OPTIONS< %t %s
end_comment

begin_comment
comment|// CHECK-OPTIONS: Option 0 - Name: "-ccc-print-options", Values: {}
end_comment

begin_comment
comment|// CHECK-OPTIONS: Option 1 - Name: "-save-temps", Values: {}
end_comment

begin_comment
comment|// CHECK-OPTIONS: Option 2 - Name: "-U", Values: {"FOO"}
end_comment

begin_comment
comment|// CHECK-OPTIONS: Option 3 - Name: "-U", Values: {"FOO"}
end_comment

begin_comment
comment|// CHECK-OPTIONS: Option 4 - Name: "--param", Values: {"FOO"}
end_comment

begin_comment
comment|// CHECK-OPTIONS: Option 5 - Name: "-o", Values: {"FOO"}
end_comment

end_unit

