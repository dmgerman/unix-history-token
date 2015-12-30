begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|PUBLIC_H
end_ifndef

begin_define
define|#
directive|define
name|PUBLIC_H
end_define

begin_include
include|#
directive|include
file|"private.h"
end_include

begin_function
name|void
name|pub
parameter_list|()
block|{
name|priv
argument_list|()
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

