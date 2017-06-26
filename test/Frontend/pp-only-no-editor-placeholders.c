begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -verify -o - %s | FileCheck %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_expr_stmt
operator|<
operator|#
name|placeholder
operator|#
operator|>
expr_stmt|;
end_expr_stmt

begin_comment
comment|// CHECK:<#placeholder#>;
end_comment

end_unit

