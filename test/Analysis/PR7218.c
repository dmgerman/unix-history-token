begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core -analyzer-store region -verify %s
end_comment

begin_function
name|char
name|PR7218
parameter_list|(
name|char
name|a
parameter_list|)
block|{
name|char
name|buf
index|[
literal|2
index|]
decl_stmt|;
name|buf
index|[
literal|0
index|]
operator|=
name|a
expr_stmt|;
return|return
name|buf
index|[
literal|1
index|]
return|;
comment|// expected-warning {{Undefined or garbage value returned to caller}}
block|}
end_function

end_unit

