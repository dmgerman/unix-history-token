begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* exists.c    Check whether a file exists.  */
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

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_function
name|boolean
name|fsysdep_file_exists
parameter_list|(
name|zfile
parameter_list|)
specifier|const
name|char
modifier|*
name|zfile
decl_stmt|;
block|{
name|struct
name|stat
name|s
decl_stmt|;
return|return
name|stat
argument_list|(
operator|(
name|char
operator|*
operator|)
name|zfile
argument_list|,
operator|&
name|s
argument_list|)
operator|==
literal|0
return|;
block|}
end_function

end_unit

