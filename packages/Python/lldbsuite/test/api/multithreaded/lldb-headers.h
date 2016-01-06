begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|LLDB_HEADERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_HEADERS_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_include
include|#
directive|include
file|<LLDB/LLDB.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"lldb/API/LLDB.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_HEADERS_H
end_comment

end_unit

