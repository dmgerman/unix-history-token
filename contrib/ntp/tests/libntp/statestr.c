begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_include
include|#
directive|include
file|"ntp_calendar.h"
end_include

begin_include
include|#
directive|include
file|"ntp.h"
end_include

begin_comment
comment|// Needed for MAX_MAC_LEN used in ntp_control.h
end_comment

begin_include
include|#
directive|include
file|"ntp_control.h"
end_include

begin_include
include|#
directive|include
file|"unity.h"
end_include

begin_function
name|void
name|setUp
parameter_list|(
name|void
parameter_list|)
block|{  }
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
comment|// eventstr()
end_comment

begin_function
name|void
name|test_PeerRestart
parameter_list|(
name|void
parameter_list|)
block|{
name|TEST_ASSERT_EQUAL_STRING
argument_list|(
literal|"restart"
argument_list|,
name|eventstr
argument_list|(
name|PEVNT_RESTART
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_SysUnspecified
parameter_list|(
name|void
parameter_list|)
block|{
name|TEST_ASSERT_EQUAL_STRING
argument_list|(
literal|"unspecified"
argument_list|,
name|eventstr
argument_list|(
name|EVNT_UNSPEC
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// ceventstr()
end_comment

begin_function
name|void
name|test_ClockCodeExists
parameter_list|(
name|void
parameter_list|)
block|{
name|TEST_ASSERT_EQUAL_STRING
argument_list|(
literal|"clk_unspec"
argument_list|,
name|ceventstr
argument_list|(
name|CTL_CLK_OKAY
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_ClockCodeUnknown
parameter_list|(
name|void
parameter_list|)
block|{
name|TEST_ASSERT_EQUAL_STRING
argument_list|(
literal|"clk_-1"
argument_list|,
name|ceventstr
argument_list|(
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

