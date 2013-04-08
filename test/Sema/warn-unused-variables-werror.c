begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wunused-variable -Werror -verify %s
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
comment|// expected-error{{unused}}
name|int
name|j
decl_stmt|;
comment|// expected-error{{unused}}
block|}
end_function

end_unit

