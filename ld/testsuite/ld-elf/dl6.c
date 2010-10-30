begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|int
name|bar
init|=
literal|10
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|bar
operator|==
literal|10
condition|)
name|printf
argument_list|(
literal|"bar is in DSO.\n"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|bar
operator|==
operator|-
literal|20
condition|)
name|printf
argument_list|(
literal|"bar is in main.\n"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"FAIL\n"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

