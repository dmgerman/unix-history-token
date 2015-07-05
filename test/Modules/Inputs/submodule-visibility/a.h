begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|B
end_ifdef

begin_error
error|#
directive|error
error|B is defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|A
end_define

begin_include
include|#
directive|include
file|"c.h"
end_include

end_unit

