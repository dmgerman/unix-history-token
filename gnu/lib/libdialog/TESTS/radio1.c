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
name|int
name|spending
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|check
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
return|return
operator|(
operator|(
name|int
operator|)
name|self
operator|->
name|data
operator|==
name|spending
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|spend
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
name|spending
operator|=
operator|(
name|int
operator|)
name|self
operator|->
name|data
expr_stmt|;
return|return
name|DITEM_SUCCESS
operator||
name|DITEM_REDRAW
return|;
block|}
end_function

begin_comment
comment|/* menu5 - Show a simple radiolist menu that inherits the radio appearance by default */
end_comment

begin_comment
comment|/* prompt	title			checked		fire		sel   data */
end_comment

begin_decl_stmt
specifier|static
name|dialogMenuItem
name|menu5
index|[]
init|=
block|{
block|{
literal|"1000"
block|,
literal|"Spend $1,000"
block|,
name|check
block|,
name|spend
block|,
name|NULL
block|,
operator|(
name|void
operator|*
operator|)
literal|1000
block|}
block|,
block|{
literal|"500"
block|,
literal|"Spend $500"
block|,
name|check
block|,
name|spend
block|,
name|NULL
block|,
operator|(
name|void
operator|*
operator|)
literal|500
block|}
block|,
block|{
literal|"100"
block|,
literal|"Spend $100"
block|,
name|check
block|,
name|spend
block|,
name|NULL
block|,
operator|(
name|void
operator|*
operator|)
literal|100
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
literal|"this is dialog_radiolist() in action, test #1"
argument_list|,
literal|"this radio menu shows off some of the straight-forward features\n"
literal|"of the new menu system's check& fire dispatch hooks"
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
name|menu5
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
literal|"returned value for dialog_radiolist was %d (money set to %d)\n"
argument_list|,
name|retval
argument_list|,
name|spending
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

