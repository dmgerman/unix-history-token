begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994, Jordan Hubbard, Paul Richards and Poul-Henning Kamp.  *  * All rights reserved.  *  * This software may be used, modified, copied, distributed, and  * sold, in both source and binary form provided that the above  * copyright and these terms are retained, verbatim, as the first  * lines of this file.  Under no circumstances is the author  * responsible for the proper functioning of this software, nor does  * the author assume any responsibility for damages incurred with  * its use.  *  * [Note: This file bears almost no resemblance to what was here in an  * earlier incarnation].  */
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
file|<dialog.h>
end_include

begin_include
include|#
directive|include
file|"sysinstall.h"
end_include

begin_decl_stmt
specifier|static
name|unsigned
name|char
modifier|*
name|welcome
index|[]
init|=
block|{
literal|"1. README"
block|,
literal|"View `READ ME FIRST' File."
block|,
literal|"2. COPYRIGHT"
block|,
literal|"View FreeBSD Copyright Information."
block|,
literal|"3. Proceed"
block|,
literal|"Proceed with installation."
block|,
literal|"4. Fixit"
block|,
literal|"Repair existing installation (`fixit' mode)."
block|,
literal|"5. Quit"
block|,
literal|"Don't do anything, just reboot."
block|, }
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|stage0
parameter_list|()
block|{
name|evil_goto
label|:
if|if
condition|(
name|dialog_menu
argument_list|(
literal|"Welcome to FreeBSD!"
argument_list|,
literal|"Please select one of the following options:"
argument_list|,
literal|15
argument_list|,
literal|75
argument_list|,
literal|6
argument_list|,
literal|5
argument_list|,
name|welcome
argument_list|,
name|selection
argument_list|)
condition|)
block|{
name|dialog_clear
argument_list|()
expr_stmt|;
name|end_dialog
argument_list|()
expr_stmt|;
name|reboot
argument_list|(
name|RB_AUTOBOOT
argument_list|)
expr_stmt|;
block|}
switch|switch
condition|(
name|atoi
argument_list|(
name|selection
argument_list|)
condition|)
block|{
case|case
literal|1
case|:
comment|/* View readme */
if|if
condition|(
operator|!
name|access
argument_list|(
name|README_FILE
argument_list|,
name|R_OK
argument_list|)
condition|)
block|{
name|dialog_clear
argument_list|()
expr_stmt|;
name|dialog_textbox
argument_list|(
literal|"READ ME FIRST"
argument_list|,
name|README_FILE
argument_list|,
name|LINES
operator|-
literal|1
argument_list|,
name|COLS
argument_list|)
expr_stmt|;
name|dialog_clear
argument_list|()
expr_stmt|;
block|}
goto|goto
name|evil_goto
goto|;
break|break;
case|case
literal|2
case|:
comment|/* View copyrights */
if|if
condition|(
operator|!
name|access
argument_list|(
name|COPYRIGHT_FILE
argument_list|,
name|R_OK
argument_list|)
condition|)
block|{
name|dialog_clear
argument_list|()
expr_stmt|;
name|dialog_textbox
argument_list|(
literal|"COPYRIGHT"
argument_list|,
name|COPYRIGHT_FILE
argument_list|,
name|LINES
operator|-
literal|1
argument_list|,
name|COLS
argument_list|)
expr_stmt|;
name|dialog_clear
argument_list|()
expr_stmt|;
block|}
goto|goto
name|evil_goto
goto|;
break|break;
case|case
literal|3
case|:
comment|/* Proceed (do nothing special, really) */
break|break;
case|case
literal|4
case|:
name|dialog_msgbox
argument_list|(
literal|"Sorry!"
argument_list|,
literal|"This feature not currently implemented."
argument_list|,
literal|6
argument_list|,
literal|75
argument_list|,
literal|1
argument_list|)
expr_stmt|;
goto|goto
name|evil_goto
goto|;
break|break;
case|case
literal|5
case|:
comment|/* Be neat.. */
name|dialog_clear
argument_list|()
expr_stmt|;
name|end_dialog
argument_list|()
expr_stmt|;
name|reboot
argument_list|(
name|RB_AUTOBOOT
argument_list|)
expr_stmt|;
break|break;
comment|/* hope not! :) */
block|}
block|}
end_function

end_unit

