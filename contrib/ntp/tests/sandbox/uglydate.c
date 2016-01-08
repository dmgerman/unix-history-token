begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"config.h"
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

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_comment
comment|//#include "libntptest.h"
end_comment

begin_function_decl
name|void
name|setUp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|test_ConstantDateTime
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|setUp
parameter_list|(
name|void
parameter_list|)
block|{
name|init_lib
argument_list|()
expr_stmt|;
return|return;
block|}
end_function

begin_function
name|void
name|test_ConstantDateTime
parameter_list|(
name|void
parameter_list|)
block|{
specifier|const
name|u_int32
name|HALF
init|=
literal|2147483648UL
decl_stmt|;
name|l_fp
name|e_time
init|=
block|{
block|{
literal|3485080800UL
block|}
block|,
name|HALF
block|}
decl_stmt|;
comment|// 2010-06-09 14:00:00.5
name|TEST_ASSERT_EQUAL_STRING
argument_list|(
literal|"3485080800.500000 10:159:14:00:00.500"
argument_list|,
name|uglydate
argument_list|(
operator|&
name|e_time
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

