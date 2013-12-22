begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-linux-gnu -verify -fsyntax-only %s
end_comment

begin_if
if|#
directive|if
operator|!
name|__has_attribute
argument_list|(
name|tls_model
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Should support tls_model attribute"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|f
parameter_list|()
function_decl|__attribute
parameter_list|(
function_decl|(tls_model
parameter_list|(
function_decl|"global-dynamic"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'tls_model' attribute only applies to thread-local variables}}
end_comment

begin_decl_stmt
name|int
name|x
name|__attribute
argument_list|(
operator|(
name|tls_model
argument_list|(
literal|"global-dynamic"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'tls_model' attribute only applies to thread-local variables}}
end_comment

begin_decl_stmt
specifier|static
name|__thread
name|int
name|y
name|__attribute
argument_list|(
operator|(
name|tls_model
argument_list|(
literal|"global-dynamic"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// no-warning
end_comment

begin_decl_stmt
specifier|static
name|__thread
name|int
name|y
name|__attribute
argument_list|(
operator|(
name|tls_model
argument_list|(
literal|"local"
argument_list|,
literal|"dynamic"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'tls_model' attribute takes one argument}}
end_comment

begin_decl_stmt
specifier|static
name|__thread
name|int
name|y
name|__attribute
argument_list|(
operator|(
name|tls_model
argument_list|(
literal|123
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'tls_model' attribute requires a string}}
end_comment

begin_decl_stmt
specifier|static
name|__thread
name|int
name|y
name|__attribute
argument_list|(
operator|(
name|tls_model
argument_list|(
literal|"foobar"
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{tls_model must be "global-dynamic", "local-dynamic", "initial-exec" or "local-exec"}}
end_comment

end_unit

