begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -fsyntax-only -verify
end_comment

begin_comment
comment|// rdar://6587766
end_comment

begin_function_decl
name|int
name|fn1
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(warn_unused_result
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|fn2
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(pure
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|fn3
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(const
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|int
name|foo
parameter_list|()
block|{
if|if
condition|(
name|fn1
argument_list|()
operator|<
literal|0
operator|||
name|fn2
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
operator|<
literal|0
operator|||
name|fn3
argument_list|(
literal|2
argument_list|)
operator|<
literal|0
condition|)
comment|// no warnings
return|return
operator|-
literal|1
return|;
name|fn1
argument_list|()
expr_stmt|;
comment|// expected-warning {{expression result unused}}
name|fn2
argument_list|(
literal|92
argument_list|,
literal|21
argument_list|)
expr_stmt|;
comment|// expected-warning {{expression result unused}}
name|fn3
argument_list|(
literal|42
argument_list|)
expr_stmt|;
comment|// expected-warning {{expression result unused}}
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|int
name|bar
name|__attribute__
argument_list|(
operator|(
name|warn_unused_result
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{warning: 'warn_unused_result' attribute only applies to function types}}
end_comment

end_unit

