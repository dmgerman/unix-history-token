begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mode.c    Get the Unix file mode of a file.  */
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
name|unsigned
name|int
name|ixsysdep_file_mode
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
operator|!=
literal|0
condition|)
block|{
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
literal|0
return|;
block|}
if|#
directive|if
name|S_IRWXU
operator|!=
literal|0700
error|#
directive|error
error|Files modes need to be translated
endif|#
directive|endif
comment|/* We can't return 0, since that indicate an error.  */
if|if
condition|(
operator|(
name|s
operator|.
name|st_mode
operator|&
literal|0777
operator|)
operator|==
literal|0
condition|)
return|return
literal|0400
return|;
return|return
name|s
operator|.
name|st_mode
operator|&
literal|0777
return|;
block|}
end_function

end_unit

