begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|"ficl.h"
end_include

begin_function
name|unsigned
name|long
name|ficlNtohl
parameter_list|(
name|unsigned
name|long
name|number
parameter_list|)
block|{
return|return
name|ntohl
argument_list|(
name|number
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|ficlCompilePlatform
parameter_list|(
name|FICL_DICT
modifier|*
name|dp
parameter_list|)
block|{
return|return;
block|}
end_function

end_unit

