begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -std=c99 -fsyntax-only -verify -Wvla %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -std=c89 -fsyntax-only -verify -Wvla %s
end_comment

begin_function
name|void
name|test1
parameter_list|(
name|int
name|n
parameter_list|)
block|{
name|int
name|v
index|[
name|n
index|]
decl_stmt|;
comment|// expected-warning {{variable length array used}}
block|}
end_function

begin_function
name|void
name|test2
parameter_list|(
name|int
name|n
parameter_list|,
name|int
name|v
index|[
name|n
index|]
parameter_list|)
block|{
comment|// expected-warning {{variable length array used}}
block|}
end_function

begin_function_decl
name|void
name|test3
parameter_list|(
name|int
name|n
parameter_list|,
name|int
name|v
index|[
name|n
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning {{variable length array used}}
end_comment

end_unit

