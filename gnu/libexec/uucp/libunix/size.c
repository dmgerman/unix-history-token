begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* size.c    Get the size in bytes of a file.  */
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

begin_function
name|long
name|csysdep_size
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
if|if
condition|(
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
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|errno
operator|==
name|ENOENT
condition|)
return|return
operator|-
literal|1
return|;
name|ulog
argument_list|(
name|LOG_ERROR
argument_list|,
literal|"stat (%s): %s"
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
operator|-
literal|2
return|;
block|}
return|return
name|s
operator|.
name|st_size
return|;
block|}
end_function

end_unit

