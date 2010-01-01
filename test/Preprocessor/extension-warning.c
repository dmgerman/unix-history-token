begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -pedantic %s
end_comment

begin_comment
comment|// The preprocessor shouldn't warn about extensions within macro bodies that
end_comment

begin_comment
comment|// aren't expanded.
end_comment

begin_define
define|#
directive|define
name|TY
value|typeof
end_define

begin_define
define|#
directive|define
name|TY1
value|typeof(1)
end_define

begin_comment
comment|// But we should warn here
end_comment

begin_decl_stmt
name|TY1
name|x
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{extension}}
end_comment

begin_macro
name|TY
argument_list|(
literal|1
argument_list|)
end_macro

begin_expr_stmt
name|x
expr_stmt|;
end_expr_stmt

begin_comment
comment|// FIXME: And we should warn here
end_comment

begin_comment
comment|// Note: this warning intentionally doesn't trigger on keywords like
end_comment

begin_comment
comment|// __attribute; the standard allows implementation-defined extensions
end_comment

begin_comment
comment|// prefixed with "__".
end_comment

begin_comment
comment|// Current list of keywords this can trigger on:
end_comment

begin_comment
comment|// inline, restrict, asm, typeof, _asm
end_comment

begin_function
name|void
name|whatever
parameter_list|()
block|{}
end_function

end_unit

