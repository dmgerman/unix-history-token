begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"port_before.h"
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"port_after.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NEED_STRDUP
end_ifndef

begin_decl_stmt
name|int
name|__bind_strdup_unneeded
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function
name|char
modifier|*
name|strdup
parameter_list|(
specifier|const
name|char
modifier|*
name|src
parameter_list|)
block|{
name|char
modifier|*
name|dst
init|=
name|malloc
argument_list|(
name|strlen
argument_list|(
name|src
argument_list|)
operator|+
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|dst
condition|)
name|strcpy
argument_list|(
name|dst
argument_list|,
name|src
argument_list|)
expr_stmt|;
return|return
operator|(
name|dst
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

