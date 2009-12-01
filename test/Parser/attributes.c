begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fsyntax-only -verify %s -pedantic -std=c99
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
operator|)
argument_list|)
name|x
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__inline
name|void
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|foo
argument_list|(
name|void
argument_list|)
block|{ }
end_decl_stmt

begin_macro
name|__attribute__
argument_list|(
argument|()
argument_list|)
end_macro

begin_expr_stmt
name|y
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning {{defaults to 'int'}}
end_comment

begin_comment
comment|// PR2796
end_comment

begin_macro
name|int
argument_list|(
argument|__attribute__(()) *z
argument_list|)
end_macro

begin_expr_stmt
operator|(
name|long
name|y
operator|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|f1
argument_list|(
name|__attribute__
argument_list|(
argument|()
argument_list|)
name|int
name|x
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|f2
argument_list|(
name|y
argument_list|,
name|__attribute__
argument_list|(
argument|()
argument_list|)
name|x
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{expected identifier}}
end_comment

begin_comment
comment|// This is parsed as a normal argument list (with two args that are implicit
end_comment

begin_comment
comment|// int) because the __attribute__ is a declspec.
end_comment

begin_decl_stmt
name|void
name|f3
argument_list|(
name|__attribute__
argument_list|(
argument|()
argument_list|)
name|x
argument_list|,
comment|// expected-warning {{defaults to 'int'}}
name|y
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{defaults to 'int'}}
end_comment

begin_decl_stmt
name|void
name|f4
argument_list|(
name|__attribute__
argument_list|(
operator|(
operator|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{expected parameter declarator}}
end_comment

begin_comment
comment|// This is ok, the __attribute__ applies to the pointer.
end_comment

begin_decl_stmt
name|int
name|baz
argument_list|(
name|int
argument_list|(
argument|__attribute__(()) *x
argument_list|)
operator|(
name|long
name|y
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|g1
argument_list|(
name|void
argument_list|(
argument|*f1
argument_list|)
operator|(
name|__attribute__
argument_list|(
argument|()
argument_list|)
name|int
name|x
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|g2
argument_list|(
name|int
argument_list|(
operator|*
name|f2
argument_list|)
argument_list|(
name|y
argument_list|,
name|__attribute__
argument_list|(
argument|()
argument_list|)
name|x
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{expected identifier}}
end_comment

begin_decl_stmt
name|void
name|g3
argument_list|(
name|void
argument_list|(
argument|*f3
argument_list|)
operator|(
name|__attribute__
argument_list|(
argument|()
argument_list|)
name|x
operator|,
name|int
name|y
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{defaults to 'int'}}
end_comment

begin_decl_stmt
name|void
name|g4
argument_list|(
name|void
argument_list|(
operator|*
name|f4
argument_list|)
argument_list|(
name|__attribute__
argument_list|(
operator|(
operator|)
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{expected parameter declarator}}
end_comment

begin_expr_stmt
name|void
argument_list|(
operator|*
name|h1
argument_list|)
argument_list|(
name|void
argument_list|(
argument|*f1
argument_list|)
operator|(
name|__attribute__
argument_list|(
argument|()
argument_list|)
name|int
name|x
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
argument_list|(
operator|*
name|h2
argument_list|)
argument_list|(
name|int
argument_list|(
operator|*
name|f2
argument_list|)
argument_list|(
name|y
argument_list|,
name|__attribute__
argument_list|(
argument|()
argument_list|)
name|x
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{expected identifier}}
end_comment

begin_expr_stmt
name|void
argument_list|(
operator|*
name|h3
argument_list|)
argument_list|(
name|void
argument_list|(
operator|*
name|f3
argument_list|)
argument_list|(
name|__attribute__
argument_list|(
argument|()
argument_list|)
name|x
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning {{defaults to 'int'}}
end_comment

begin_expr_stmt
name|void
argument_list|(
operator|*
name|h4
argument_list|)
argument_list|(
name|void
argument_list|(
operator|*
name|f4
argument_list|)
argument_list|(
name|__attribute__
argument_list|(
operator|(
operator|)
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{expected parameter declarator}}
end_comment

begin_comment
comment|// rdar://6131260
end_comment

begin_function
name|int
name|foo42
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|x
decl_stmt|,
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
name|y
decl_stmt|,
name|z
decl_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// rdar://6096491
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
name|d0
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
name|d1
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|d2
argument_list|(
name|void
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
decl_stmt|,
name|d3
argument_list|(
name|void
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

