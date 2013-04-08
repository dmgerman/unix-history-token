begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple powerpc-apple-macosx10.4.0 -verify -fsyntax-only %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_extern
extern|extern __typeof(+(_Bool
end_extern

begin_expr_stmt
unit|)
literal|0
end_expr_stmt

begin_expr_stmt
unit|)
name|should_be_int
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|int
name|should_be_int
decl_stmt|;
end_decl_stmt

end_unit

