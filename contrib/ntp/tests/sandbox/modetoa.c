begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//#include "config.h"
end_comment

begin_comment
comment|//#include "libntptest.h"
end_comment

begin_include
include|#
directive|include
file|"unity.h"
end_include

begin_comment
comment|//#include "ntp_stdlib.h"
end_comment

begin_function
name|void
name|test_KnownMode
parameter_list|(
name|void
parameter_list|)
block|{
specifier|const
name|int
name|MODE
init|=
literal|3
decl_stmt|;
comment|// Should be "client"
name|TEST_ASSERT_EQUAL_STRING
argument_list|(
literal|"client"
argument_list|,
name|modetoa
argument_list|(
name|MODE
argument_list|)
argument_list|)
expr_stmt|;
comment|//	EXPECT_STREQ("client", modetoa(MODE));
block|}
end_function

begin_function
name|void
name|test_UnknownMode
parameter_list|(
name|void
parameter_list|)
block|{
specifier|const
name|int
name|MODE
init|=
literal|100
decl_stmt|;
name|TEST_ASSERT_EQUAL_STRING
argument_list|(
literal|"mode#1001"
argument_list|,
name|modetoa
argument_list|(
name|MODE
argument_list|)
argument_list|)
expr_stmt|;
comment|//	EXPECT_STREQ("mode#100", modetoa(MODE));
block|}
end_function

end_unit

