begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* basnam.c    Get the base name of a file.  */
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

begin_comment
comment|/* Get the base name of a file name.  */
end_comment

begin_function
name|char
modifier|*
name|zsysdep_base_name
parameter_list|(
name|zfile
parameter_list|)
specifier|const
name|char
modifier|*
name|zfile
decl_stmt|;
block|{
specifier|const
name|char
modifier|*
name|z
decl_stmt|;
name|z
operator|=
name|strrchr
argument_list|(
name|zfile
argument_list|,
literal|'/'
argument_list|)
expr_stmt|;
if|if
condition|(
name|z
operator|!=
name|NULL
condition|)
return|return
name|zbufcpy
argument_list|(
name|z
operator|+
literal|1
argument_list|)
return|;
return|return
name|zbufcpy
argument_list|(
name|zfile
argument_list|)
return|;
block|}
end_function

end_unit

