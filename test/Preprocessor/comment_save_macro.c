begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -E -C %s | FileCheck -check-prefix=CHECK-C -strict-whitespace %s
end_comment

begin_comment
comment|// CHECK-C: boo bork bar // zot
end_comment

begin_comment
comment|// RUN: clang-cc -E -CC %s | FileCheck -check-prefix=CHECK-CC -strict-whitespace %s
end_comment

begin_comment
comment|// CHECK-CC: boo bork /* blah*/ bar // zot
end_comment

begin_comment
comment|// RUN: clang-cc -E %s | FileCheck -check-prefix=CHECK -strict-whitespace %s
end_comment

begin_comment
comment|// CHECK: boo bork bar
end_comment

begin_define
define|#
directive|define
name|FOO
value|bork
end_define

begin_comment
comment|// blah
end_comment

begin_expr_stmt
name|boo
name|FOO
name|bar
end_expr_stmt

begin_comment
comment|// zot
end_comment

end_unit

