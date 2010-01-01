begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: %clang_cc1 -fsyntax-only %s -std=c89  * RUN: not %clang_cc1 -fsyntax-only %s -std=c99 -pedantic-errors  */
end_comment

begin_function
name|int
name|A
parameter_list|()
block|{
return|return
name|X
argument_list|()
return|;
block|}
end_function

end_unit

