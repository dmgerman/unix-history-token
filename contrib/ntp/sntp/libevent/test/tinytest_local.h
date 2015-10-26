begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"util-internal.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_include
include|#
directive|include
file|<winsock2.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"event2/util.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|snprintf
end_ifdef

begin_undef
undef|#
directive|undef
name|snprintf
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|snprintf
value|evutil_snprintf
end_define

end_unit

