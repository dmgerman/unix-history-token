begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -DTEST -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-unknown-linux-gnu -fsyntax-only -verify %s
end_comment

begin_if
if|#
directive|if
name|TEST
end_if

begin_expr_stmt
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|regparm
argument_list|(
literal|3
argument_list|)
operator|,
name|stdcall
operator|)
argument_list|)
operator|*
name|pf
argument_list|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|//expected-warning {{calling convention 'stdcall' ignored for this target}}
end_comment

begin_macro
name|void
argument_list|(
argument|__attribute__((regparm(
literal|2
argument|), stdcall)) foo
argument_list|)
end_macro

begin_expr_stmt
operator|(
name|int
name|a
operator|)
block|{
comment|//expected-warning {{calling convention 'stdcall' ignored for this target}}
block|}
else|#
directive|else
comment|//expected-no-diagnostics
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|regparm
argument_list|(
literal|3
argument_list|)
operator|,
name|stdcall
operator|)
argument_list|)
operator|*
name|pf
argument_list|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_macro
name|void
argument_list|(
argument|__attribute__((regparm(
literal|2
argument|), stdcall)) foo
argument_list|)
end_macro

begin_expr_stmt
operator|(
name|int
name|a
operator|)
block|{}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

