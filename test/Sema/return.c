begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -fsyntax-only -verify
end_comment

begin_comment
comment|// clang emits the following warning by default.
end_comment

begin_comment
comment|// With GCC, -pedantic, -Wreturn-type or -Wall are required to produce the
end_comment

begin_comment
comment|// following warning.
end_comment

begin_function
name|int
name|t14
parameter_list|()
block|{
return|return;
comment|// expected-warning {{non-void function 't14' should return a value}}
block|}
end_function

begin_function
name|void
name|t15
parameter_list|()
block|{
return|return
literal|1
return|;
comment|// expected-warning {{void function 't15' should not return a value}}
block|}
end_function

end_unit

