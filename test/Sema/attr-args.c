begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -Wunused -Wused-but-marked-unused -Wunused-parameter -fsyntax-only %s
end_comment

begin_decl_stmt
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|inline
name|__attribute__
argument_list|(
argument|(noreturn(a))
argument_list|)
name|void
operator|*
name|f1
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{'noreturn' attribute takes no arguments}}
end_comment

begin_expr_stmt
specifier|inline
name|__attribute__
argument_list|(
argument|(always_inline(a))
argument_list|)
name|void
operator|*
name|f2
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{'always_inline' attribute takes no arguments}}
end_comment

begin_expr_stmt
specifier|inline
name|__attribute__
argument_list|(
argument|(cdecl(a))
argument_list|)
name|void
operator|*
name|f3
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{'cdecl' attribute takes no arguments}}
end_comment

begin_expr_stmt
specifier|inline
name|__attribute__
argument_list|(
argument|(const(a))
argument_list|)
name|void
operator|*
name|f4
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{'const' attribute takes no arguments}}
end_comment

begin_expr_stmt
specifier|inline
name|__attribute__
argument_list|(
argument|(fastcall(a))
argument_list|)
name|void
operator|*
name|f5
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{'fastcall' attribute takes no arguments}}
end_comment

begin_expr_stmt
specifier|inline
name|__attribute__
argument_list|(
argument|(malloc(a))
argument_list|)
name|void
operator|*
name|f5
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{'malloc' attribute takes no arguments}}
end_comment

begin_expr_stmt
specifier|inline
name|__attribute__
argument_list|(
argument|(nothrow(a))
argument_list|)
name|void
operator|*
name|f7
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{'nothrow' attribute takes no arguments}}
end_comment

begin_expr_stmt
specifier|inline
name|__attribute__
argument_list|(
argument|(stdcall(a))
argument_list|)
name|void
operator|*
name|f8
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{'stdcall' attribute takes no arguments}}
end_comment

begin_expr_stmt
specifier|inline
name|__attribute__
argument_list|(
argument|(used(a))
argument_list|)
name|void
operator|*
name|f9
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{'used' attribute takes no arguments}}
end_comment

begin_expr_stmt
specifier|inline
name|__attribute__
argument_list|(
argument|(unused(a))
argument_list|)
name|void
operator|*
name|f10
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{'unused' attribute takes no arguments}}
end_comment

begin_expr_stmt
specifier|inline
name|__attribute__
argument_list|(
argument|(weak(a))
argument_list|)
name|void
operator|*
name|f11
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{'weak' attribute takes no arguments}}
end_comment

end_unit

