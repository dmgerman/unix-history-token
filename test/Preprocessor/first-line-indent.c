begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
name|foo
comment|// RUN: %clang_cc1 -E %s | FileCheck -strict-whitespace %s
name|bar
end_expr_stmt

begin_comment
comment|// CHECK: {{^       }}foo
end_comment

begin_comment
comment|// CHECK: {{^       }}bar
end_comment

end_unit

