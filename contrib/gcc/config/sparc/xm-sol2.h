begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* If not compiled with GNU C, include the system's<alloca.h> header.  */
end_comment

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

end_unit

