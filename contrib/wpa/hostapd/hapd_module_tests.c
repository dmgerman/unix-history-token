begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd module tests  * Copyright (c) 2014, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_include
include|#
directive|include
file|"utils/includes.h"
end_include

begin_include
include|#
directive|include
file|"utils/common.h"
end_include

begin_function
name|int
name|hapd_module_tests
parameter_list|(
name|void
parameter_list|)
block|{
name|wpa_printf
argument_list|(
name|MSG_INFO
argument_list|,
literal|"hostapd module tests"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

