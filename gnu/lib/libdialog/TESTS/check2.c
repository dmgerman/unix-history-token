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

begin_function
specifier|static
name|int
name|buyBooks
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
name|char
name|foo
index|[
literal|256
index|]
decl_stmt|;
if|if
condition|(
name|german_book
operator|||
name|italian_book
operator|||
name|slang_book
condition|)
block|{
name|strcpy
argument_list|(
name|foo
argument_list|,
literal|"Ok, you're buying books on"
argument_list|)
expr_stmt|;
if|if
condition|(
name|german_book
condition|)
name|strcat
argument_list|(
name|foo
argument_list|,
literal|" german"
argument_list|)
expr_stmt|;
if|if
condition|(
name|italian_book
condition|)
name|strcat
argument_list|(
name|foo
argument_list|,
literal|" italian"
argument_list|)
expr_stmt|;
if|if
condition|(
name|slang_book
condition|)
name|strcat
argument_list|(
name|foo
argument_list|,
literal|" slang"
argument_list|)
expr_stmt|;
block|}
else|else
name|strcpy
argument_list|(
name|foo
argument_list|,
literal|"You're not buying any books?"
argument_list|)
expr_stmt|;
name|dialog_mesgbox
argument_list|(
literal|"This is a direct callback for the `Buy' button"
argument_list|,
name|foo
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
return|return
name|DITEM_SUCCESS
return|;
block|}
end_function

begin_comment
comment|/* menu3 - Look mom!  We can finally use our own OK and Cancel buttons! */
end_comment

begin_comment
comment|/* prompt	title					checked		fire		sel   data */
end_comment

begin_decl_stmt
specifier|static
name|dialogMenuItem
name|menu3
index|[]
init|=
block|{
block|{
literal|"Buy!"
block|,
name|NULL
block|,
name|NULL
block|,
name|buyBooks
block|}
block|,
comment|/* New "OK" button */
block|{
literal|"No Way!"
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
comment|/* New "Cancel" button */
block|{
literal|"German"
block|,
literal|"Buy books on learning German"
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
literal|"Buy books on learning Italian"
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
literal|"Buy books on commonly used insults"
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
literal|"this is dialog_checklist() in action, test #2"
argument_list|,
literal|"Same as before, but now we relabel the buttons and override the OK action."
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
name|menu3
operator|+
literal|2
argument_list|,
operator|(
name|char
operator|*
operator|)
name|TRUE
argument_list|)
expr_stmt|;
name|dialog_clear
argument_list|()
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"returned value for dialog_checklist was %d\n"
argument_list|,
name|retval
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

