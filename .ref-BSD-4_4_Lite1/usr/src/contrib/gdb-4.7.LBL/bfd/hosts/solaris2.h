begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Solaris-2 host system */
end_comment

begin_include
include|#
directive|include
file|"hosts/sysv4.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* That's all... */
end_comment

end_unit

