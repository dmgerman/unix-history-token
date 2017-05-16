begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-linux -target-feature -sse -target-feature -sse2 -S -o /dev/null -verify %s
end_comment

begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_function
name|double
name|f1
parameter_list|(
name|void
parameter_list|)
block|{
comment|// expected-error {{SSE register return with SSE disabled}}
return|return
literal|1.4
return|;
block|}
end_function

begin_decl_stmt
specifier|extern
name|double
name|g
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f2
parameter_list|(
name|void
parameter_list|)
block|{
comment|// expected-error {{SSE register return with SSE disabled}}
name|g
operator|=
name|f1
argument_list|()
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|take_double
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|pass_double
parameter_list|(
name|void
parameter_list|)
block|{
comment|// FIXME: Still asserts.
comment|//take_double(1.5);
block|}
end_function

end_unit

