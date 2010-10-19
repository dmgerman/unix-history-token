begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|void
name|bar
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|SIZE_BIG
name|printf
argument_list|(
literal|"1\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"2\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"3\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

