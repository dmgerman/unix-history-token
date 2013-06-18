begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<screen.h>
end_include

begin_comment
comment|/* #include "testutil.h" */
end_comment

begin_comment
comment|/* function to keep the screen open if not launched from bash */
end_comment

begin_function
name|void
name|_NonAppStop
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|getenv
argument_list|(
literal|"_IN_NETWARE_BASH_"
argument_list|)
operator|==
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"\r\n<Press any key to close screen> "
argument_list|)
expr_stmt|;
name|getcharacter
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* static void test_not_impl(CuTest *tc) {     CuNotImpl(tc, "Test not implemented on this platform yet"); } */
end_comment

end_unit

