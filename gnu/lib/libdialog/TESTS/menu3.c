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
name|stop
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
name|dialog_mesgbox
argument_list|(
literal|"!"
argument_list|,
literal|"I'm no idiot!"
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

begin_function
specifier|static
name|int
name|maybe
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
name|dialog_mesgbox
argument_list|(
literal|"!"
argument_list|,
literal|"I said don't rush me!  I'm THINKING!"
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
operator||
name|DITEM_RESTORE
operator||
name|DITEM_CONTINUE
return|;
block|}
end_function

begin_comment
comment|/* Dummy menu just to show of the ability */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|insurance
index|[]
init|=
block|{
literal|"1,000,000"
block|,
literal|"Mondo insurance policy"
block|,
literal|"Off"
block|,
literal|"5,000,000"
block|,
literal|"Mega insurance policy"
block|,
literal|"Off"
block|,
literal|"10,000,000"
block|,
literal|"Friend!  Most Favored customer!"
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|preinsure
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|,
name|int
name|is_selected
parameter_list|)
block|{
if|if
condition|(
name|is_selected
condition|)
block|{
specifier|static
name|WINDOW
modifier|*
name|w
decl_stmt|;
comment|/* This has to be here first if you want to see selection traverse properly in the invoking menu */
name|refresh
argument_list|()
expr_stmt|;
name|w
operator|=
name|dupwin
argument_list|(
name|newscr
argument_list|)
expr_stmt|;
name|DialogX
operator|=
literal|1
expr_stmt|;
name|DialogY
operator|=
literal|13
expr_stmt|;
name|dialog_radiolist
argument_list|(
literal|"How much insurance would you like to take out?"
argument_list|,
literal|"If you're really going to do this, we recommend some insurance\n"
literal|"first!  What kind of life insurance policy would you like?"
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
literal|3
argument_list|,
literal|3
argument_list|,
name|insurance
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|touchwin
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|wrefresh
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|delwin
argument_list|(
name|w
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * Show a simple menu that puts up a sub menu when a certain item is traversed to  */
end_comment

begin_comment
comment|/* prompt	title						checked		fire		sel  */
end_comment

begin_decl_stmt
specifier|static
name|dialogMenuItem
name|doit
index|[]
init|=
block|{
block|{
literal|"Rah!"
block|}
block|,
block|{
literal|"No way!"
block|}
block|,
block|{
literal|"Stop"
block|,
literal|"No, I'm not going to do that!"
block|,
name|NULL
block|,
name|stop
block|,
name|NULL
block|}
block|,
block|{
literal|"Maybe"
block|,
literal|"I'm still thinking about it, don't rush me!"
block|,
name|NULL
block|,
name|maybe
block|,
name|NULL
block|,	}
block|,
block|{
literal|"Go"
block|,
literal|"Yes!  Yes!  I want to do it!"
block|,
name|NULL
block|,
name|NULL
block|,
name|preinsure
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
name|DialogX
operator|=
literal|5
expr_stmt|;
name|DialogY
operator|=
literal|1
expr_stmt|;
name|retval
operator|=
name|dialog_menu
argument_list|(
literal|"Do you have the GUTS?"
argument_list|,
literal|"C'mon, macho man!  Do you have what it takes to do something REALLY\n"
literal|"dangerous and stupid?  WHAT ARE YOU WAITING FOR?!"
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
literal|3
argument_list|,
operator|-
literal|3
argument_list|,
name|doit
operator|+
literal|2
argument_list|,
operator|(
name|char
operator|*
operator|)
name|TRUE
argument_list|,
name|NULL
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
literal|"returned value for dialog_menu was %d\n"
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

