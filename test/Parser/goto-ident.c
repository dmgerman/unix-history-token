begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: %clang_cc1 -fsyntax-only -verify %s */
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
goto|goto ;
comment|/* expected-error {{expected identifier}} */
block|}
end_function

end_unit

