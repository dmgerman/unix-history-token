begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -fsyntax-only %s
end_comment

begin_function_decl
specifier|static
name|void
function_decl|(
modifier|*
name|fp0
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(unused
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|static
name|void
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
name|f0
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// On K&R
end_comment

begin_function_decl
name|int
name|f1
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(unused
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|int
name|g0
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|f2
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(unused
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{attribute requires 0 argument(s)}}
end_comment

end_unit

