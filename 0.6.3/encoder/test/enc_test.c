begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2015, Juniper Networks, Inc.  * All rights reserved.  * This SOFTWARE is licensed under the LICENSE provided in the  * ../Copyright file. By downloading, installing, copying, or otherwise  * using the SOFTWARE, you agree to be bound by the terms of that  * LICENSE.  * Phil Shafer, August 2015  */
end_comment

begin_include
include|#
directive|include
file|"xo.h"
end_include

begin_include
include|#
directive|include
file|"xo_encoder.h"
end_include

begin_function
specifier|static
name|int
name|test_handler
parameter_list|(
name|XO_ENCODER_HANDLER_ARGS
parameter_list|)
block|{
name|printf
argument_list|(
literal|"op %s: [%s] [%s]\n"
argument_list|,
name|xo_encoder_op_name
argument_list|(
name|op
argument_list|)
argument_list|,
name|name
condition|?
else|:
literal|""
argument_list|,
name|value
condition|?
else|:
literal|""
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|xo_encoder_library_init
parameter_list|(
name|XO_ENCODER_INIT_ARGS
parameter_list|)
block|{
name|arg
operator|->
name|xei_version
operator|=
name|XO_ENCODER_VERSION
expr_stmt|;
name|arg
operator|->
name|xei_handler
operator|=
name|test_handler
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

