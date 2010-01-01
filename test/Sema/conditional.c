begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|test1
init|=
literal|1
condition|?
literal|"i"
else|:
literal|1
operator|==
literal|1
condition|?
literal|"v"
else|:
literal|"r"
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|_efree
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|_php_stream_free1
parameter_list|()
block|{
return|return
operator|(
literal|1
condition|?
name|free
argument_list|(
literal|0
argument_list|)
else|:
name|_efree
argument_list|(
literal|0
argument_list|)
operator|)
return|;
comment|// expected-error {{incompatible type returning 'void', expected 'int'}}
block|}
end_function

begin_function
name|int
name|_php_stream_free2
parameter_list|()
block|{
return|return
operator|(
literal|1
condition|?
name|_efree
argument_list|(
literal|0
argument_list|)
else|:
name|free
argument_list|(
literal|0
argument_list|)
operator|)
return|;
comment|// expected-error {{incompatible type returning 'void', expected 'int'}}
block|}
end_function

end_unit

