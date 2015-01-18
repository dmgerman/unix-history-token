begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"a.h"
end_include

begin_if
if|#
directive|if
operator|!
name|__building_module
argument_list|(
name|b
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"should only get here when building module b"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|const
name|int
name|b
init|=
literal|2
decl_stmt|;
end_decl_stmt

end_unit

