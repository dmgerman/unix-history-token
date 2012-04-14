begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Werror -pedantic %s -fixit-recompile -fixit-to-temporary -E -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -Werror -pedantic %s -fixit-recompile -fixit-to-temporary -fix-only-warnings
end_comment

begin_expr_stmt
specifier|_Complex
name|cd
expr_stmt|;
end_expr_stmt

begin_comment
comment|// CHECK: _Complex double cd;
end_comment

end_unit

