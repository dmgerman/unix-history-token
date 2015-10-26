begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|"main.h"
end_include

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
return|return
name|sntp_main
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|Version
argument_list|)
return|;
block|}
end_function

end_unit

