begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************  * Dummy Header for Unix to Windows NT portability  * Created for NTP package  **************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IOCTL_H
end_ifndef

begin_define
define|#
directive|define
name|_IOCTL_H
end_define

begin_include
include|#
directive|include
file|"win32_io.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

