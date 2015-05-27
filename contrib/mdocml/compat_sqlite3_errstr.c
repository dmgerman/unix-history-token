begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"config.h"
end_include

begin_if
if|#
directive|if
name|HAVE_SQLITE3_ERRSTR
end_if

begin_decl_stmt
name|int
name|dummy
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function
specifier|const
name|char
modifier|*
name|sqlite3_errstr
parameter_list|(
name|int
name|rc
parameter_list|)
block|{
return|return
operator|(
name|rc
condition|?
literal|"unknown error"
else|:
literal|"not an error"
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

