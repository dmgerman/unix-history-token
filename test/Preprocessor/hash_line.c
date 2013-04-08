begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// The 1 and # should not go on the same line.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E %s | FileCheck --strict-whitespace %s
end_comment

begin_comment
comment|// CHECK-NOT: 1{{.*}}#
end_comment

begin_comment
comment|// CHECK: {{^1$}}
end_comment

begin_comment
comment|// CHECK-NOT: 1{{.*}}#
end_comment

begin_comment
comment|// CHECK: {{^      #$}}
end_comment

begin_comment
comment|// CHECK-NOT: 1{{.*}}#
end_comment

begin_expr_stmt
literal|1
define|#
directive|define
name|EMPTY
name|EMPTY
operator|#
end_expr_stmt

end_unit

