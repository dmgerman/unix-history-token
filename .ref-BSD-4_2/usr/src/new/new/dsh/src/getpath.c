begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*(@(#)getpath.c	1.2		/ra/csr/presotto/hacks/src/worm/sccs/s.getpath.c)*/
end_comment

begin_define
define|#
directive|define
name|MAXPATHS
value|20
end_define

begin_define
define|#
directive|define
name|MAXPATHSIZE
value|100
end_define

begin_decl_stmt
name|int
name|npaths
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of paths to search */
end_comment

begin_decl_stmt
name|char
modifier|*
name|paths
index|[
name|MAXPATHS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointers to the paths */
end_comment

begin_decl_stmt
name|char
name|thepath
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where to copy path */
end_comment

begin_comment
comment|/*  *	input the execution search path  */
end_comment

begin_macro
name|getpath
argument_list|()
end_macro

begin_block
block|{
name|char
modifier|*
name|path
decl_stmt|;
name|path
operator|=
operator|(
name|char
operator|*
operator|)
name|getenv
argument_list|(
literal|"PATH"
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|thepath
argument_list|,
name|path
argument_list|)
expr_stmt|;
name|path
operator|=
name|thepath
expr_stmt|;
for|for
control|(
name|npaths
operator|=
literal|0
init|;
name|npaths
operator|<
name|MAXPATHS
condition|;
name|npaths
operator|++
control|)
block|{
name|paths
index|[
name|npaths
index|]
operator|=
name|path
expr_stmt|;
while|while
condition|(
operator|*
name|path
operator|!=
literal|':'
operator|&&
operator|*
name|path
operator|!=
literal|0
condition|)
name|path
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|path
operator|==
literal|0
condition|)
block|{
name|npaths
operator|++
expr_stmt|;
break|break;
block|}
else|else
block|{
operator|*
name|path
operator|++
operator|=
literal|0
expr_stmt|;
block|}
block|}
block|}
end_block

begin_comment
comment|/*  *	see if we can execute a command  */
end_comment

begin_macro
name|findcmd
argument_list|(
argument|path
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|path
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* path to the command */
end_comment

begin_block
block|{
name|char
name|abspath
index|[
name|MAXPATHSIZE
index|]
decl_stmt|;
name|int
name|rv
decl_stmt|;
comment|/* return value */
name|int
name|indp
decl_stmt|;
comment|/* path index */
if|if
condition|(
operator|*
name|path
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
operator|*
name|path
operator|==
literal|'/'
condition|)
block|{
comment|/* absolute path,  don't fool around */
name|rv
operator|=
name|access
argument_list|(
name|path
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* relative path,  do some work */
for|for
control|(
name|indp
operator|=
literal|0
init|;
name|indp
operator|<
name|npaths
condition|;
name|indp
operator|++
control|)
block|{
name|strcpy
argument_list|(
name|abspath
argument_list|,
name|paths
index|[
name|indp
index|]
argument_list|)
expr_stmt|;
name|strcat
argument_list|(
name|abspath
argument_list|,
literal|"/"
argument_list|)
expr_stmt|;
name|strcat
argument_list|(
name|abspath
argument_list|,
name|path
argument_list|)
expr_stmt|;
name|rv
operator|=
name|access
argument_list|(
name|abspath
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|rv
operator|==
literal|0
condition|)
break|break;
block|}
block|}
return|return
operator|(
name|rv
operator|)
return|;
block|}
end_block

end_unit

