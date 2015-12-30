begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple=x86_64-linux-gnu -S -verify -o -
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|target
argument_list|(
literal|"avx"
argument_list|)
operator|,
name|always_inline
operator|)
argument_list|)
name|foo
argument_list|(
name|int
name|a
argument_list|)
block|{
return|return
name|a
operator|+
literal|4
return|;
block|}
end_decl_stmt

begin_function
name|int
name|bar
parameter_list|()
block|{
return|return
name|foo
argument_list|(
literal|4
argument_list|)
return|;
comment|// expected-error {{always_inline function 'foo' requires target feature 'sse4.2', but would be inlined into function 'bar' that is compiled without support for 'sse4.2'}}
block|}
end_function

end_unit

