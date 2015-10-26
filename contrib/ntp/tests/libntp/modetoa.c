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
file|"unity.h"
end_include

begin_function_decl
name|void
name|test_KnownMode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|test_UnknownMode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
literal|"mode#100"
argument_list|,
name|modetoa
argument_list|(
name|MODE
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

