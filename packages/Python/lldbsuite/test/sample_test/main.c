begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|test_var
init|=
literal|10
decl_stmt|;
name|printf
argument_list|(
literal|"Set a breakpoint here: %d.\n"
argument_list|,
name|test_var
argument_list|)
expr_stmt|;
comment|//% test_var = self.frame().FindVariable("test_var")
comment|//% test_value = test_var.GetValueAsUnsigned()
comment|//% self.assertTrue(test_var.GetError().Success(), "Failed to fetch test_var")
comment|//% self.assertEqual(test_value, 10, "Failed to get the right value for test_var")
return|return
literal|0
return|;
block|}
end_function

end_unit

