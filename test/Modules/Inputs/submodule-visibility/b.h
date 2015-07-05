begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|int
name|m
init|=
name|n
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"other.h"
end_include

begin_include
include|#
directive|include
file|"c.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|A
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ALLOW_NAME_LEAKAGE
argument_list|)
end_if

begin_error
error|#
directive|error
error|A is defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|B
end_define

end_unit

