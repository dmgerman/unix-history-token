begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|main
parameter_list|()
block|{
name|char
name|token
index|[
literal|80
index|]
decl_stmt|;
name|printf
argument_list|(
literal|"about to sleep"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|sleep
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|endnot
argument_list|()
expr_stmt|;
block|}
end_function

begin_macro
name|endnot
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"done\n"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

