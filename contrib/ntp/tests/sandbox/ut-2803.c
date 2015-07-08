begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//#include "bug-2803.h"
end_comment

begin_include
include|#
directive|include
file|"unity.h"
end_include

begin_comment
comment|//#include "code-2803.h"
end_comment

begin_define
define|#
directive|define
name|VERSION
value|5
end_define

begin_comment
comment|//change this to 5 and the test wont fail.
end_comment

begin_function
name|void
name|setUp
parameter_list|(
name|void
parameter_list|)
block|{    }
end_function

begin_function
name|void
name|tearDown
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* int main( void ) {  	// loop from {0.0} to {1.1000000} stepping by tv_sec by 1 and tv_usec by 100000 	test_loop( 0, 0,   1,  MICROSECONDS,   1,  MICROSECONDS / 10 );  	// test_loop( 0, 0,   5,  MICROSECONDS,   1,  MICROSECONDS / 1000 ); 	// test_loop( 0, 0,  -5, -MICROSECONDS,  -1, -MICROSECONDS / 1000 );  	return 0; } */
end_comment

begin_function
name|void
name|test_main
parameter_list|(
name|void
parameter_list|)
block|{
name|TEST_ASSERT_EQUAL
argument_list|(
literal|0
argument_list|,
name|main2
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|//VERSION defined at the top of the file
end_comment

begin_function
name|void
name|test_XPASS
parameter_list|(
name|void
parameter_list|)
comment|//expecting fail but passes, should we get an alert about that?
block|{
comment|//TEST_ABORT
name|TEST_EXPECT_FAIL
argument_list|()
expr_stmt|;
if|if
condition|(
name|VERSION
operator|<
literal|4
condition|)
block|{
name|TEST_FAIL_MESSAGE
argument_list|(
literal|"expected to fail"
argument_list|)
expr_stmt|;
block|}
else|else
name|TEST_ASSERT_EQUAL
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_XFAIL
parameter_list|(
name|void
parameter_list|)
comment|//expecting fail, and XFAILs
block|{
name|TEST_EXPECT_FAIL
argument_list|()
expr_stmt|;
if|if
condition|(
name|VERSION
operator|<
literal|4
condition|)
block|{
name|TEST_FAIL_MESSAGE
argument_list|(
literal|"Expected to fail"
argument_list|)
expr_stmt|;
block|}
else|else
name|TEST_ASSERT_EQUAL
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_XFAIL_WITH_MESSAGE
parameter_list|(
name|void
parameter_list|)
comment|//expecting fail, and XFAILs
block|{
comment|//TEST_ABORT
name|TEST_EXPECT_FAIL_MESSAGE
argument_list|(
literal|"Doesn't work on this OS"
argument_list|)
expr_stmt|;
if|if
condition|(
name|VERSION
operator|<
literal|4
condition|)
block|{
name|TEST_FAIL_MESSAGE
argument_list|(
literal|"Expected to fail"
argument_list|)
expr_stmt|;
block|}
else|else
name|TEST_ASSERT_EQUAL
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_main_incorrect
parameter_list|(
name|void
parameter_list|)
block|{
name|TEST_ASSERT_EQUAL
argument_list|(
literal|3
argument_list|,
name|main2
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_ignored
parameter_list|(
name|void
parameter_list|)
block|{
comment|//TEST_IGNORE();
name|TEST_IGNORE_MESSAGE
argument_list|(
literal|"This test is being ignored!"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

