begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -triple x86_64-apple-darwin9 -verify %s
end_comment

begin_decl_stmt
name|int
name|a
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|f0
parameter_list|()
block|{
return|return
name|__builtin_object_size
argument_list|(
operator|&
name|a
argument_list|)
return|;
comment|// expected-error {{too few arguments to function}}
block|}
end_function

begin_function
name|int
name|f1
parameter_list|()
block|{
return|return
operator|(
name|__builtin_object_size
argument_list|(
operator|&
name|a
argument_list|,
literal|0
argument_list|)
operator|+
name|__builtin_object_size
argument_list|(
operator|&
name|a
argument_list|,
literal|1
argument_list|)
operator|+
name|__builtin_object_size
argument_list|(
operator|&
name|a
argument_list|,
literal|2
argument_list|)
operator|+
name|__builtin_object_size
argument_list|(
operator|&
name|a
argument_list|,
literal|3
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|int
name|f2
parameter_list|()
block|{
return|return
name|__builtin_object_size
argument_list|(
operator|&
name|a
argument_list|,
operator|-
literal|1
argument_list|)
return|;
comment|// expected-error {{argument should be a value from 0 to 3}}
block|}
end_function

begin_function
name|int
name|f3
parameter_list|()
block|{
return|return
name|__builtin_object_size
argument_list|(
operator|&
name|a
argument_list|,
literal|4
argument_list|)
return|;
comment|// expected-error {{argument should be a value from 0 to 3}}
block|}
end_function

begin_comment
comment|// rdar://6252231 - cannot call vsnprintf with va_list on x86_64
end_comment

begin_function
name|void
name|f4
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|__builtin_va_list
name|args
decl_stmt|;
name|__builtin___vsnprintf_chk
argument_list|(
literal|0
argument_list|,
literal|42
argument_list|,
literal|0
argument_list|,
literal|11
argument_list|,
name|fmt
argument_list|,
name|args
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

