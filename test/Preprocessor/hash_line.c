begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// The 1 and # should not go on the same line.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E %s | FileCheck --strict-whitespace %s
end_comment

begin_comment
comment|// CHECK: {{^1$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^      #$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^2$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^           #$}}
end_comment

begin_define
define|#
directive|define
name|EMPTY
end_define

begin_define
define|#
directive|define
name|IDENTITY
parameter_list|(
name|X
parameter_list|)
value|X
end_define

begin_expr_stmt
literal|1
name|EMPTY
operator|#
literal|2
name|IDENTITY
argument_list|()
operator|#
end_expr_stmt

end_unit

