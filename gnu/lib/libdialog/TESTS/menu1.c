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
comment|/* Start of hook functions */
end_comment

begin_enum
specifier|static
enum|enum
block|{
name|nowhere
block|,
name|berlin
block|,
name|rome
block|,
name|ny
block|}
name|where
enum|;
end_enum

begin_function
specifier|static
name|int
name|_menu1_berlin_action
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
if|if
condition|(
name|where
operator|==
name|berlin
condition|)
block|{
name|dialog_mesgbox
argument_list|(
literal|"excuse me?"
argument_list|,
literal|"But you're already *in* Berlin!"
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|where
operator|=
name|berlin
expr_stmt|;
name|dialog_mesgbox
argument_list|(
literal|"whoosh!"
argument_list|,
literal|"Welcome to Berlin!  Have a beer!"
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
name|DITEM_SUCCESS
operator||
name|DITEM_RESTORE
operator||
name|DITEM_CONTINUE
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|_menu1_rome_action
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
if|if
condition|(
name|where
operator|==
name|rome
condition|)
block|{
name|dialog_mesgbox
argument_list|(
literal|"The wine must be getting to you.."
argument_list|,
literal|"You're already in Rome!"
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|where
operator|=
name|rome
expr_stmt|;
name|dialog_mesgbox
argument_list|(
literal|"whoosh!"
argument_list|,
literal|"Welcome to Rome!  Have a coffee!"
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
name|DITEM_SUCCESS
operator||
name|DITEM_RESTORE
operator||
name|DITEM_CONTINUE
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|_menu1_ny_action
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
if|if
condition|(
name|where
operator|==
name|ny
condition|)
block|{
name|dialog_mesgbox
argument_list|(
literal|"Say what?"
argument_list|,
literal|"You're already there!"
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|where
operator|=
name|ny
expr_stmt|;
name|dialog_mesgbox
argument_list|(
literal|"whoosh!"
argument_list|,
literal|"Welcome to New York!  Now go someplace else!"
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
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
comment|/* menu1 - show off the "fire" action hook */
end_comment

begin_comment
comment|/* prompt	title					checked		fire */
end_comment

begin_decl_stmt
specifier|static
name|dialogMenuItem
name|menu1
index|[]
init|=
block|{
block|{
literal|"Berlin"
block|,
literal|"Go visit Germany's new capitol"
block|,
name|NULL
block|,
name|_menu1_berlin_action
block|}
block|,
block|{
literal|"Rome"
block|,
literal|"Go visit the Roman ruins"
block|,
name|NULL
block|,
name|_menu1_rome_action
block|}
block|,
block|{
literal|"New York"
block|,
literal|"Go visit the streets of New York"
block|,
name|NULL
block|,
name|_menu1_ny_action
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
name|dialog_menu
argument_list|(
literal|"this is dialog_menu() in action, test #1"
argument_list|,
literal|"this simple menu shows off some of the straight-forward features\n"
literal|"of the new menu system's action dispatch hooks.  Select Cancel to leave"
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
name|menu1
argument_list|,
name|NULL
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

