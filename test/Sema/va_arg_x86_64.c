begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fsyntax-only -verify -triple=x86_64-unknown-freebsd7.0 %s
end_comment

begin_comment
comment|// PR2631
end_comment

begin_function
name|char
modifier|*
name|foo
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
name|__builtin_va_list
name|ap
parameter_list|)
block|{
return|return
name|__builtin_va_arg
argument_list|(
operator|(
name|ap
operator|)
argument_list|,
name|char
operator|*
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// PR2692
end_comment

begin_typedef
typedef|typedef
name|__builtin_va_list
name|va_list
typedef|;
end_typedef

begin_function
specifier|static
name|void
name|f
parameter_list|(
name|char
modifier|*
function_decl|(
modifier|*
name|g
function_decl|)
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|char
modifier|*
modifier|*
name|p
parameter_list|,
modifier|...
parameter_list|)
block|{
name|char
modifier|*
name|s
decl_stmt|;
name|va_list
name|v
decl_stmt|;
name|s
operator|=
name|g
argument_list|(
name|p
argument_list|,
name|__builtin_va_arg
argument_list|(
name|v
argument_list|,
name|int
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

