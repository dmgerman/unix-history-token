begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"libioP.h"
end_include

begin_function
name|_IO_FILE
modifier|*
name|fdopen
parameter_list|(
name|fd
parameter_list|,
name|mode
parameter_list|)
name|int
name|fd
decl_stmt|;
specifier|const
name|char
modifier|*
name|mode
decl_stmt|;
block|{
return|return
name|_IO_fdopen
argument_list|(
name|fd
argument_list|,
name|mode
argument_list|)
return|;
block|}
end_function

end_unit

