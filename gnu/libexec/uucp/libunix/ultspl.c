begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ultspl.c    See whether there is an Ultrix spool directory for a system.  */
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

begin_function
name|boolean
name|fsultrix_has_spool
parameter_list|(
name|zsystem
parameter_list|)
specifier|const
name|char
modifier|*
name|zsystem
decl_stmt|;
block|{
name|char
modifier|*
name|z
decl_stmt|;
name|boolean
name|fret
decl_stmt|;
name|z
operator|=
name|zsysdep_in_dir
argument_list|(
literal|"sys"
argument_list|,
name|zsystem
argument_list|)
expr_stmt|;
name|fret
operator|=
name|fsysdep_directory
argument_list|(
name|z
argument_list|)
expr_stmt|;
name|ubuffree
argument_list|(
name|z
argument_list|)
expr_stmt|;
return|return
name|fret
return|;
block|}
end_function

end_unit

