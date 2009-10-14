begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: clang-cc -fsyntax-only -verify %s */
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|int
name|A
parameter_list|)
block|{
comment|/* expected-note {{previous definition is here}} */
name|int
name|A
decl_stmt|;
comment|/* expected-error {{redefinition of 'A'}} */
block|}
end_function

end_unit

