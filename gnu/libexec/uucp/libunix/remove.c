begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* remove.c    Remove a file (Unix specific implementation).  */
end_comment

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_function
name|int
name|remove
parameter_list|(
name|z
parameter_list|)
specifier|const
name|char
modifier|*
name|z
decl_stmt|;
block|{
return|return
name|unlink
argument_list|(
name|z
argument_list|)
return|;
block|}
end_function

end_unit

