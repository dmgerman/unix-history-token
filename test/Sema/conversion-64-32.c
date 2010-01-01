begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Wshorten-64-to-32 -triple x86_64-apple-darwin %s
end_comment

begin_function
name|int
name|test0
parameter_list|(
name|long
name|v
parameter_list|)
block|{
return|return
name|v
return|;
comment|// expected-warning {{implicit cast loses integer precision}}
block|}
end_function

end_unit

