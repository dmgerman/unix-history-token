begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_macro
name|__attribute__
argument_list|(
argument|(visibility (
literal|"protected"
argument|))
argument_list|)
end_macro

begin_function
name|void
name|foo
parameter_list|()
block|{
name|printf
argument_list|(
literal|"TEST1\n"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

