begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * chproject() changes the name of the project root directory pathname.  * Returns integer YES if successful, otherwise NO.  */
end_comment

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

begin_include
include|#
directive|include
file|"yesno.h"
end_include

begin_macro
name|chproject
argument_list|(
argument|ppathname
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|ppathname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* new project pathname */
end_comment

begin_block
block|{
specifier|extern
name|char
modifier|*
name|_PROJECT
decl_stmt|;
comment|/* project root directory pathname */
name|char
modifier|*
name|strsav
parameter_list|()
function_decl|;
comment|/* save a string somewhere */
name|PATH
name|pathbuf
decl_stmt|;
comment|/* pathname buffer */
if|if
condition|(
name|xppath
argument_list|(
name|ppathname
argument_list|,
operator|&
name|pathbuf
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|patherr
argument_list|(
name|ppathname
argument_list|)
expr_stmt|;
return|return
operator|(
name|NO
operator|)
return|;
block|}
else|else
block|{
switch|switch
condition|(
name|pathbuf
operator|.
name|p_mode
operator|&
name|P_IFMT
condition|)
block|{
case|case
name|P_IFNEW
case|:
case|case
name|P_IFREG
case|:
case|case
name|P_IFPDIR
case|:
name|warn
argument_list|(
literal|"%s: no such project"
argument_list|,
name|ppathname
argument_list|)
expr_stmt|;
return|return
operator|(
name|NO
operator|)
return|;
case|case
name|P_IFHOME
case|:
case|case
name|P_IFPROOT
case|:
if|if
condition|(
name|_PROJECT
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|_PROJECT
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|_PROJECT
operator|=
name|strsav
argument_list|(
name|pathbuf
operator|.
name|p_path
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|warn
argument_list|(
literal|"out of memory"
argument_list|)
expr_stmt|;
return|return
operator|(
name|NO
operator|)
return|;
block|}
break|break;
block|}
block|}
return|return
operator|(
name|YES
operator|)
return|;
block|}
end_block

end_unit

