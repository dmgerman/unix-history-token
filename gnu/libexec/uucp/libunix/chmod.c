begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* chmod.c    Change the mode of a file.  */
end_comment

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_include
include|#
directive|include
file|"uudefs.h"
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

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/* Change the mode of a file.  */
end_comment

begin_function
name|boolean
name|fsysdep_change_mode
parameter_list|(
name|zfile
parameter_list|,
name|imode
parameter_list|)
specifier|const
name|char
modifier|*
name|zfile
decl_stmt|;
name|unsigned
name|int
name|imode
decl_stmt|;
block|{
if|if
condition|(
name|chmod
argument_list|(
operator|(
name|char
operator|*
operator|)
name|zfile
argument_list|,
name|imode
argument_list|)
operator|<
literal|0
condition|)
block|{
name|ulog
argument_list|(
name|LOG_ERROR
argument_list|,
literal|"chmod (%s): %s"
argument_list|,
name|zfile
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|FALSE
return|;
block|}
return|return
name|TRUE
return|;
block|}
end_function

end_unit

