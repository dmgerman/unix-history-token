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
file|"ntp_fp.h"
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

begin_function
name|void
name|test_Address
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int32
name|input
init|=
name|htonl
argument_list|(
literal|3221225472UL
operator|+
literal|512UL
operator|+
literal|1UL
argument_list|)
decl_stmt|;
comment|// 192.0.2.1
name|TEST_ASSERT_EQUAL_STRING
argument_list|(
literal|"192.0.2.1"
argument_list|,
name|numtoa
argument_list|(
name|input
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_Netmask
parameter_list|(
name|void
parameter_list|)
block|{
comment|// 255.255.255.0
name|u_int32
name|hostOrder
init|=
literal|255UL
operator|*
literal|256UL
operator|*
literal|256UL
operator|*
literal|256UL
operator|+
literal|255UL
operator|*
literal|256UL
operator|*
literal|256UL
operator|+
literal|255UL
operator|*
literal|256UL
decl_stmt|;
name|u_int32
name|input
init|=
name|htonl
argument_list|(
name|hostOrder
argument_list|)
decl_stmt|;
name|TEST_ASSERT_EQUAL_STRING
argument_list|(
literal|"255.255.255.0"
argument_list|,
name|numtoa
argument_list|(
name|input
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

