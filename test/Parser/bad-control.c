begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: clang-cc -fsyntax-only -verify %s */
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
break|break;
comment|/* expected-error {{'break' statement not in loop or switch statement}} */
block|}
end_function

begin_function
name|void
name|foo2
parameter_list|()
block|{
continue|continue;
comment|/* expected-error {{'continue' statement not in loop statement}} */
block|}
end_function

end_unit

