begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"macro.h"
end_include

begin_include
include|#
directive|include
file|"yesno.h"
end_include

begin_comment
comment|/*  * ch_dir changes current working directory. Returns integer YES if  * successful, otherwise NO.  */
end_comment

begin_macro
name|ch_dir
argument_list|(
argument|pathname
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|pathname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pathname of destination directory */
end_comment

begin_block
block|{
specifier|extern
name|int
name|IGNORE_BAD_EXIT
decl_stmt|;
comment|/* exit if command doesn't return 0 */
if|if
condition|(
operator|!
name|CHDIR
argument_list|(
name|pathname
argument_list|)
condition|)
block|{
name|pperror
argument_list|(
name|pathname
argument_list|)
expr_stmt|;
if|if
condition|(
name|IGNORE_BAD_EXIT
operator|==
name|NO
condition|)
name|pxexit
argument_list|()
expr_stmt|;
return|return
operator|(
name|NO
operator|)
return|;
block|}
return|return
operator|(
name|YES
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * getpvindex() returns the location of the PROJECT environment  * variable in the global cell environ.  */
end_comment

begin_macro
name|getpvindex
argument_list|()
end_macro

begin_block
block|{
specifier|extern
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
comment|/* global environment cell */
specifier|register
name|int
name|i
decl_stmt|;
comment|/* location of PROJECT env. variable */
name|int
name|strncmp
parameter_list|()
function_decl|;
comment|/* compare n characters */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|environ
index|[
name|i
index|]
operator|!=
name|NULL
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|strncmp
argument_list|(
name|environ
index|[
name|i
index|]
argument_list|,
literal|"PROJECT="
argument_list|,
literal|8
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|i
operator|)
return|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * nomorecore() prints a warning error message and then exits.  */
end_comment

begin_macro
name|nomorecore
argument_list|()
end_macro

begin_block
block|{
name|warn
argument_list|(
literal|"out of memory"
argument_list|)
expr_stmt|;
name|pxexit
argument_list|()
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * print_title prints a project directory title.  */
end_comment

begin_function
name|void
name|print_title
parameter_list|(
name|ppathname
parameter_list|)
name|char
modifier|*
name|ppathname
decl_stmt|;
comment|/* project directory pathname */
block|{
specifier|static
name|int
name|done_command
decl_stmt|;
comment|/* has a command been done? */
name|printf
argument_list|(
operator|(
name|done_command
operator|)
condition|?
literal|"\n==> %s<==\n"
else|:
literal|"==> %s<==\n"
argument_list|,
name|ppathname
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|done_command
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * pxexit() calls exit(ERRSTATUS).  */
end_comment

begin_macro
name|pxexit
argument_list|()
end_macro

begin_block
block|{
specifier|extern
name|int
name|ERRSTATUS
decl_stmt|;
comment|/* pexec error status */
name|exit
argument_list|(
name|ERRSTATUS
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

