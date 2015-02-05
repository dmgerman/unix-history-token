begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//
end_comment

begin_comment
comment|// serialpps-ppsapi-provider.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For this tiny project the single header serves as a precompiled header
end_comment

begin_comment
comment|// as well, meaning all the bulky headers are included before or within it.
end_comment

begin_comment
comment|// Within, in this case.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|_CRT_SECURE_NO_WARNINGS
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* Prevent inclusion of winsock.h in windows.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WINSOCKAPI_
end_ifndef

begin_define
define|#
directive|define
name|_WINSOCKAPI_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_typedef
typedef|typedef
name|DWORD
name|u_int32
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"sys/time.h"
end_include

begin_include
include|#
directive|include
file|"../../include/timepps.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|UNUSED
end_ifndef

begin_define
define|#
directive|define
name|UNUSED
parameter_list|(
name|item
parameter_list|)
value|((void)(item))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

