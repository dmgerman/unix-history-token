begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -triple x86_64-pc-linux-gnu -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -triple powerpc64le-linux-gnu -verify %s
end_comment

begin_function_decl
specifier|extern
name|void
name|a
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|str
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|__x86_64__
if|if
condition|(
name|__builtin_cpu_supports
argument_list|(
literal|"ss"
argument_list|)
condition|)
comment|// expected-error {{invalid cpu feature string}}
name|a
argument_list|(
literal|"sse4.2"
argument_list|)
expr_stmt|;
if|if
condition|(
name|__builtin_cpu_supports
argument_list|(
name|str
argument_list|)
condition|)
comment|// expected-error {{expression is not a string literal}}
name|a
argument_list|(
name|str
argument_list|)
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|__builtin_cpu_supports
argument_list|(
literal|"vsx"
argument_list|)
condition|)
comment|// expected-error {{use of unknown builtin}}
name|a
argument_list|(
literal|"vsx"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|0
return|;
block|}
end_function

end_unit

