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

begin_decl_stmt
specifier|static
name|char
name|bachelor
index|[
literal|10
index|]
decl_stmt|,
name|bachelette
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|getBachelor
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
return|return
operator|!
name|strcmp
argument_list|(
name|bachelor
argument_list|,
name|self
operator|->
name|prompt
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|setBachelor
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
name|strcpy
argument_list|(
name|bachelor
argument_list|,
name|self
operator|->
name|prompt
argument_list|)
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
name|getBachelette
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
return|return
operator|!
name|strcmp
argument_list|(
name|bachelette
argument_list|,
name|self
operator|->
name|prompt
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|setBachelette
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
name|strcpy
argument_list|(
name|bachelette
argument_list|,
name|self
operator|->
name|prompt
argument_list|)
expr_stmt|;
return|return
name|DITEM_SUCCESS
operator||
name|DITEM_REDRAW
return|;
block|}
end_function

begin_comment
comment|/* menu6- More complex radiolist menu that creates two groups in a single menu */
end_comment

begin_comment
comment|/* prompt	title								checked		fire */
end_comment

begin_decl_stmt
specifier|static
name|dialogMenuItem
name|menu6
index|[]
init|=
block|{
block|{
literal|"Tom"
block|,
literal|"Tom's a dynamic shoe salesman from Tulsa, OK!"
block|,
name|getBachelor
block|,
name|setBachelor
block|}
block|,
block|{
literal|"Dick"
block|,
literal|"Dick's a retired engine inspector from McDonnell-Douglas!"
block|,
name|getBachelor
block|,
name|setBachelor
block|}
block|,
block|{
literal|"Harry"
block|,
literal|"Harry's a professional female impersonator from Las Vegas!"
block|,
name|getBachelor
block|,
name|setBachelor
block|}
block|,
block|{
literal|"-----"
block|,
literal|"----------------------------------"
block|,
name|NULL
block|,
name|NULL
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
block|,
block|{
literal|"Jane"
block|,
literal|"Jane's a twice-divorced housewife from Moose, Oregon!"
block|,
name|getBachelette
block|,
name|setBachelette
block|}
block|,
block|{
literal|"Sally"
block|,
literal|"Sally's a shy Human Resources Manager for IBM!"
block|,
name|getBachelette
block|,
name|setBachelette
block|}
block|,
block|{
literal|"Mary"
block|,
literal|"Mary's an energetic serial killer on the lam!"
block|,
name|getBachelette
block|,
name|setBachelette
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
name|dialog_radiolist
argument_list|(
literal|"this is dialog_radiolist() in action, test #2"
argument_list|,
literal|"Welcome to \"The Love Blender!\" - America's favorite game show\n"
literal|"where YOU, the contestant, get to choose which of these two\n"
literal|"fine specimens of humanity will go home together, whether they\n"
literal|"like it or not!"
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
literal|7
argument_list|,
operator|-
literal|7
argument_list|,
name|menu6
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
literal|"I'm sure that %s and %s will be very happy together!\n"
argument_list|,
name|bachelor
argument_list|,
name|bachelette
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

