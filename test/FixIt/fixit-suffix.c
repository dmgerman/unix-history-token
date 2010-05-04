begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: cp %s %t.extrasuffix
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fixit=fixed -x c %t.extrasuffix
end_comment

begin_comment
comment|// RUN: %clang_cc1 -Werror -pedantic -x c %t.fixed.extrasuffix
end_comment

begin_expr_stmt
specifier|_Complex
name|cd
expr_stmt|;
end_expr_stmt

end_unit

