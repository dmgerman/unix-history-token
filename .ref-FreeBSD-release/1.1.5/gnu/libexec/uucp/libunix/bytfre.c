begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bytfre.c    Get the number of bytes free on a file system.  */
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

begin_include
include|#
directive|include
file|"fsusg.h"
end_include

begin_function
name|long
name|csysdep_bytes_free
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
name|fs_usage
name|s
decl_stmt|;
if|if
condition|(
name|get_fs_usage
argument_list|(
operator|(
name|char
operator|*
operator|)
name|zfile
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|,
operator|&
name|s
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
return|return
name|s
operator|.
name|fsu_bavail
operator|*
operator|(
name|long
operator|)
literal|512
return|;
block|}
end_function

end_unit

