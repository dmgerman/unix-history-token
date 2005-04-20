begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntpdc-layout - print layout of NTP mode 7 request/response packets  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|"ntpdc.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|IMPL_XNTPD_OLD
argument_list|)
operator|&&
name|IMPL_XNTPD
operator|!=
literal|3
end_if

begin_error
error|#
directive|error
error|Unexpected IMPL_XNTPD
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
include|#
directive|include
file|"nl.c"
return|return
operator|(
name|EXIT_SUCCESS
operator|)
return|;
block|}
end_function

end_unit

