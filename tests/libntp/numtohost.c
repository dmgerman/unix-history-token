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
file|"ntp_fp.h"
end_include

begin_include
include|#
directive|include
file|"unity.h"
end_include

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
name|test_LoopbackNetNonResolve
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
name|test_LoopbackNetNonResolve
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* A loopback address in 127.0.0.0/8 is chosen, and 	 * numtohost() should not try to resolve it unless 	 * it is 127.0.0.1 	 */
specifier|const
name|u_int32
name|input
init|=
literal|127
operator|*
literal|256
operator|*
literal|256
operator|*
literal|256
operator|+
literal|1
operator|*
literal|256
operator|+
literal|1
decl_stmt|;
comment|// 127.0.1.1
name|TEST_ASSERT_EQUAL_STRING
argument_list|(
literal|"127.0.1.1"
argument_list|,
name|numtohost
argument_list|(
name|htonl
argument_list|(
name|input
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

