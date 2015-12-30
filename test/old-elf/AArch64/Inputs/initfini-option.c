begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|void
name|init
parameter_list|()
block|{
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|__FUNCTION__
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|fini
parameter_list|()
block|{
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|__FUNCTION__
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{ }
end_function

end_unit

