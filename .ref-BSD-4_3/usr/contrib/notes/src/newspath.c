begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"newsgate.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|RCSIDENT
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Header: newspath.c,v 1.7 85/01/18 15:40:17 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_comment
comment|/*  *	char *getpath(dest) char *dest;  *  *	look in the routing tables for a path from here to that  *	specified host.  Return the path.  *	Return NULL if there is no such path.  *  *	The returned path is of the form:  *		a!b!c!d!dest!		(note trailing !)  *  *	The path is saved in a static buffer so you have to save   *	it or it is destroyed in the next call.  *  *	A re-write of what Jeff Donnelly did a while back.  *	Ray Essick  *  *	The routing table contains lines of the form:  *	site<space>path  *		site = destination site  *		path = a!b!c!d!site!	(not trailing !)  *  *	Must be in alphabetical order since the search gives up  *	after finding a site "after" the one we want!  */
end_comment

begin_function_decl
name|FILE
modifier|*
name|fopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|fgets
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  *	This entire routine is only called when EXPANDPATH is defined  *	so we surround it with an ifdef to keep down the binary sizes  *	when EXPANDPATH is not defined.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EXPANDPATH
end_ifdef

begin_function
name|char
modifier|*
name|getpath
parameter_list|(
name|dest
parameter_list|)
name|char
modifier|*
name|dest
decl_stmt|;
block|{
specifier|static
name|char
name|line
index|[
name|BUFSIZ
index|]
decl_stmt|;
name|FILE
modifier|*
name|mapfile
decl_stmt|;
specifier|register
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|path
decl_stmt|;
if|if
condition|(
operator|(
name|mapfile
operator|=
name|fopen
argument_list|(
name|PATHMAP
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
comment|/* no file */
while|while
condition|(
name|fgets
argument_list|(
name|line
argument_list|,
name|BUFSIZ
argument_list|,
name|mapfile
argument_list|)
operator|!=
name|NULL
condition|)
block|{
name|p
operator|=
name|line
expr_stmt|;
name|path
operator|=
name|NULL
expr_stmt|;
do|do
block|{
switch|switch
condition|(
operator|*
name|p
condition|)
block|{
case|case
literal|' '
case|:
case|case
literal|'\t'
case|:
comment|/* zap and mark path */
if|if
condition|(
name|path
operator|==
name|NULL
condition|)
comment|/* only once */
block|{
operator|*
name|p
operator|++
operator|=
literal|'\0'
expr_stmt|;
name|path
operator|=
name|p
expr_stmt|;
block|}
else|else
name|p
operator|++
expr_stmt|;
comment|/* gotta move over it */
break|break;
case|case
literal|'\n'
case|:
operator|*
name|p
operator|=
literal|'\0'
expr_stmt|;
comment|/* end of it all */
break|break;
default|default:
name|p
operator|++
expr_stmt|;
break|break;
block|}
block|}
do|while
condition|(
operator|*
name|p
condition|)
do|;
comment|/* terminates after newline */
if|if
condition|(
name|strcmp
argument_list|(
name|line
argument_list|,
name|dest
argument_list|)
operator|==
literal|0
condition|)
comment|/* matches */
block|{
break|break;
comment|/* jump and return */
block|}
if|if
condition|(
name|strcmp
argument_list|(
name|line
argument_list|,
name|dest
argument_list|)
operator|>
literal|0
condition|)
comment|/* past it */
block|{
name|path
operator|=
name|NULL
expr_stmt|;
break|break;
block|}
block|}
name|fclose
argument_list|(
name|mapfile
argument_list|)
expr_stmt|;
comment|/* don't litter */
return|return
operator|(
name|path
operator|)
return|;
comment|/* and our answer */
block|}
end_function

begin_endif
endif|#
directive|endif
endif|EXPANDPATH
end_endif

end_unit

