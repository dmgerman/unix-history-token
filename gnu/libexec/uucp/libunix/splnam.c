begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* splnam.c    Get the full name of a file in the spool directory.  */
end_comment

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_include
include|#
directive|include
file|"uuconf.h"
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
comment|/* Get the real name of a spool file.  */
end_comment

begin_function
name|char
modifier|*
name|zsysdep_spool_file_name
parameter_list|(
name|qsys
parameter_list|,
name|zfile
parameter_list|,
name|pseq
parameter_list|)
specifier|const
name|struct
name|uuconf_system
modifier|*
name|qsys
decl_stmt|;
specifier|const
name|char
modifier|*
name|zfile
decl_stmt|;
name|pointer
name|pseq
decl_stmt|;
block|{
return|return
name|zsfind_file
argument_list|(
name|zfile
argument_list|,
name|qsys
operator|->
name|uuconf_zname
argument_list|,
name|bsgrade
argument_list|(
name|pseq
argument_list|)
argument_list|)
return|;
block|}
end_function

end_unit

