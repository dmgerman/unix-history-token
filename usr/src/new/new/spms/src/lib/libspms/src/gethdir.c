begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * gethdir() returns a pointer to a string containing the pathname of the  * root project directory belonging to username. If username is null or a  * zero length string, the root project directory belonging to the current  * user returned. A null pointer is returned on error.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|"null.h"
end_include

begin_include
include|#
directive|include
file|"path.h"
end_include

begin_function
name|char
modifier|*
name|gethdir
parameter_list|(
name|username
parameter_list|)
name|char
modifier|*
name|username
decl_stmt|;
comment|/* user's login name */
block|{
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
comment|/* get environment variable */
name|char
modifier|*
name|hdir
decl_stmt|;
comment|/* pointer to home directory pathname */
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
comment|/* string copy */
name|struct
name|passwd
modifier|*
name|getpwnam
parameter_list|()
function_decl|;
comment|/* get password file entry by name */
name|struct
name|passwd
modifier|*
name|getpwuid
parameter_list|()
function_decl|;
comment|/* get password file entry by uid */
name|struct
name|passwd
modifier|*
name|pw
decl_stmt|;
comment|/* passwd struct pointer */
if|if
condition|(
name|username
operator|==
name|NULL
operator|||
operator|*
name|username
operator|==
literal|'\0'
condition|)
block|{
if|if
condition|(
operator|(
name|hdir
operator|=
name|getenv
argument_list|(
literal|"ROOTPROJECT"
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
return|return
operator|(
name|hdir
operator|)
return|;
if|if
condition|(
operator|(
name|hdir
operator|=
name|getenv
argument_list|(
literal|"HOME"
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
return|return
operator|(
name|hdir
operator|)
return|;
name|pw
operator|=
name|getpwuid
argument_list|(
name|getuid
argument_list|()
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|pw
operator|=
name|getpwnam
argument_list|(
name|username
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|warn
argument_list|(
literal|"unknown user %s"
argument_list|,
name|username
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
return|return
operator|(
name|pw
operator|->
name|pw_dir
operator|)
return|;
block|}
end_function

end_unit

