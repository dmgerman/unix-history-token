begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * getpwdir() searchs from the beginning of the passwd file until a  * matching home directory is found. If found, a pointer is returned  * to a passwd struct, otherwise NULL.  */
end_comment

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|"macro.h"
end_include

begin_include
include|#
directive|include
file|"null.h"
end_include

begin_function
name|struct
name|passwd
modifier|*
name|getpwdir
parameter_list|(
name|dir
parameter_list|)
name|char
modifier|*
name|dir
decl_stmt|;
comment|/* directory to be matched */
block|{
specifier|register
name|struct
name|passwd
modifier|*
name|pw
decl_stmt|;
comment|/* pointer to current passwd entry */
name|int
name|endpwent
parameter_list|()
function_decl|;
comment|/* close passwd file */
name|struct
name|passwd
modifier|*
name|getpwent
parameter_list|()
function_decl|;
comment|/* get next passwd entry */
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
operator|(
name|pw
operator|=
name|getpwent
argument_list|()
operator|)
operator|==
name|NULL
condition|)
break|break;
if|if
condition|(
name|EQUAL
argument_list|(
name|dir
argument_list|,
name|pw
operator|->
name|pw_dir
argument_list|)
condition|)
break|break;
block|}
name|endpwent
argument_list|()
expr_stmt|;
return|return
operator|(
name|pw
operator|)
return|;
block|}
end_function

end_unit

