begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* isdir.c    See whether a file exists and is a directory.  */
end_comment

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_function
name|boolean
name|fsysdep_directory
parameter_list|(
name|z
parameter_list|)
specifier|const
name|char
modifier|*
name|z
decl_stmt|;
block|{
name|struct
name|stat
name|s
decl_stmt|;
if|if
condition|(
name|stat
argument_list|(
operator|(
name|char
operator|*
operator|)
name|z
argument_list|,
operator|&
name|s
argument_list|)
operator|<
literal|0
condition|)
return|return
name|FALSE
return|;
return|return
name|S_ISDIR
argument_list|(
name|s
operator|.
name|st_mode
argument_list|)
return|;
block|}
end_function

end_unit

