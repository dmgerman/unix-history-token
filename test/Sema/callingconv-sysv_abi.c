begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple x86_64-pc-linux-gnu %s
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|ms_abi
operator|)
argument_list|)
name|foo
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
function_decl|(
modifier|*
name|pfoo
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|foo
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{incompatible pointer types}}
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|sysv_abi
operator|)
argument_list|)
name|bar
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
function_decl|(
modifier|*
name|pbar
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|bar
function_decl|;
end_function_decl

begin_expr_stmt
name|void
argument_list|(
name|__attribute__
argument_list|(
operator|(
name|ms_abi
operator|)
argument_list|)
operator|*
name|pbar2
argument_list|)
argument_list|(
name|void
argument_list|)
operator|=
name|bar
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning{{incompatible pointer types}}
end_comment

end_unit

