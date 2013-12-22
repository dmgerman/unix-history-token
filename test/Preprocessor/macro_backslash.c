begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s -Dfoo='bar\' | FileCheck %s
end_comment

begin_comment
comment|// CHECK: TTA bar\ TTB
end_comment

begin_expr_stmt
name|TTA
name|foo
name|TTB
end_expr_stmt

end_unit

