begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * small test-driver for new dialog functionality  *  * Copyright (c) 1995, Jordan Hubbard  *  * All rights reserved.  *  * This source code may be used, modified, copied, distributed, and  * sold, in both source and binary form provided that the above  * copyright and these terms are retained, verbatim, as the first  * lines of this file.  Under no circumstances is the author  * responsible for the proper functioning of the software nor does  * the author assume any responsibility for damages incurred with  * its use.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<dialog.h>
end_include

begin_comment
comment|/* Hook functions */
end_comment

begin_function
specifier|static
name|int
name|getBool
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
if|if
condition|(
name|self
operator|->
name|data
operator|&&
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|self
operator|->
name|data
operator|)
condition|)
return|return
name|TRUE
return|;
return|return
name|FALSE
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|setBool
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
if|if
condition|(
name|self
operator|->
name|data
condition|)
block|{
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|self
operator|->
name|data
operator|)
operator|=
operator|!
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|self
operator|->
name|data
operator|)
expr_stmt|;
return|return
name|DITEM_SUCCESS
return|;
block|}
return|return
name|DITEM_FAILURE
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|int
name|german_book
decl_stmt|,
name|italian_book
decl_stmt|,
name|slang_book
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|clearBooks
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
name|german_book
operator|=
name|italian_book
operator|=
name|slang_book
operator|=
name|FALSE
expr_stmt|;
return|return
name|DITEM_SUCCESS
operator||
name|DITEM_REDRAW
return|;
block|}
end_function

begin_comment
comment|/* menu2 - A more advanced way of using checked and fire hooks to manipulate the backing-variables directly */
end_comment

begin_comment
comment|/* prompt	title					checked		fire		sel   data */
end_comment

begin_decl_stmt
specifier|static
name|dialogMenuItem
name|menu2
index|[]
init|=
block|{
block|{
literal|"German"
block|,
literal|"Buy book on learning German"
block|,
name|getBool
block|,
name|setBool
block|,
name|NULL
block|,
operator|&
name|german_book
block|}
block|,
block|{
literal|"Italian"
block|,
literal|"Buy book on learning Italian"
block|,
name|getBool
block|,
name|setBool
block|,
name|NULL
block|,
operator|&
name|italian_book
block|}
block|,
block|{
literal|"Slang"
block|,
literal|"Buy book on commonly used insults"
block|,
name|getBool
block|,
name|setBool
block|,
name|NULL
block|,
operator|&
name|slang_book
block|}
block|,
block|{
literal|"Clear"
block|,
literal|"Clear book list"
block|,
name|NULL
block|,
name|clearBooks
block|,
name|NULL
block|,
name|NULL
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* End of hook functions */
end_comment

begin_comment
comment|/* Kick it off, James! */
end_comment

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|int
name|retval
decl_stmt|;
name|init_dialog
argument_list|()
expr_stmt|;
name|retval
operator|=
name|dialog_checklist
argument_list|(
literal|"this is a dialog_checklist() in action, test #1"
argument_list|,
literal|"this checklist menu shows off some of the straight-forward features\n"
literal|"of the new menu system's check& fire dispatch hooks"
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
literal|4
argument_list|,
operator|-
literal|4
argument_list|,
name|menu2
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|dialog_clear
argument_list|()
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"returned value for dialog_checklist was %d (%d %d %d)\n"
argument_list|,
name|retval
argument_list|,
name|german_book
argument_list|,
name|italian_book
argument_list|,
name|slang_book
argument_list|)
expr_stmt|;
name|end_dialog
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

