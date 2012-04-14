begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only -Werror
end_comment

begin_typedef
typedef|typedef
name|int
name|int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|Boolean
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|printf
parameter_list|(
name|__const
name|char
modifier|*
name|__restrict
name|__format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note{{'printf' declared here}}
end_comment

begin_function
name|void
name|func
parameter_list|()
block|{
name|int32_t
modifier|*
name|vector
index|[
literal|16
index|]
decl_stmt|;
specifier|const
name|char
name|compDesc
index|[
literal|16
operator|+
literal|1
index|]
decl_stmt|;
name|int32_t
name|compCount
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|_CFCalendarDecomposeAbsoluteTimeV
argument_list|(
name|compDesc
argument_list|,
name|vector
argument_list|,
name|compCount
argument_list|)
condition|)
block|{
comment|// expected-note {{previous implicit declaration is here}} \
name|expected
operator|-
name|error
block|{
block|{
name|implicit
name|declaration
name|of
name|function
literal|'_CFCalendarDecomposeAbsoluteTimeV'
name|is
name|invalid
name|in
name|C99
block|}
block|}
block|}
name|printg
argument_list|(
literal|"Hello, World!\n"
argument_list|)
expr_stmt|;
comment|// expected-error{{implicit declaration of function 'printg' is invalid in C99}} \
comment|// expected-note{{did you mean 'printf'?}}
name|__builtin_is_les
argument_list|(
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// expected-error{{use of unknown builtin '__builtin_is_les'}}
block|}
end_function

begin_function
name|Boolean
name|_CFCalendarDecomposeAbsoluteTimeV
parameter_list|(
specifier|const
name|char
modifier|*
name|componentDesc
parameter_list|,
name|int32_t
modifier|*
modifier|*
name|vector
parameter_list|,
name|int32_t
name|count
parameter_list|)
block|{
comment|// expected-error{{conflicting types for '_CFCalendarDecomposeAbsoluteTimeV'}}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// Test the typo-correction callback in Sema::ImplicitlyDefineFunction
end_comment

begin_function_decl
specifier|extern
name|int
name|sformatf
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|__const
name|char
modifier|*
name|__restrict
name|__format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note{{'sformatf' declared here}}
end_comment

begin_function
name|void
name|test_implicit
parameter_list|()
block|{
name|int
name|formats
init|=
literal|0
decl_stmt|;
name|formatd
argument_list|(
literal|"Hello, World!\n"
argument_list|)
expr_stmt|;
comment|// expected-error{{implicit declaration of function 'formatd' is invalid in C99}} \
comment|// expected-note{{did you mean 'sformatf'?}}
block|}
end_function

end_unit

