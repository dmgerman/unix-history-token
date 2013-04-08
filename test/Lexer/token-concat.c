begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s | FileCheck --strict-whitespace %s
end_comment

begin_expr_stmt
name|IDENT
literal|.2
comment|// CHECK: {{^}}IDENT.2{{$}}
comment|// PR4395
define|#
directive|define
name|X
value|.*
name|X
end_expr_stmt

begin_comment
comment|// CHECK: {{^}}.*{{$}}
end_comment

end_unit

