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
name|char
modifier|*
name|welcome
index|[]
init|=
block|{
literal|"View 'READ ME FIRST' File."
block|,
literal|"View FreeBSD Copyright Information."
block|,
literal|"Proceed with installation."
block|,
literal|"Repair existing installation ('fixit' mode)."
block|,
literal|"Exit to shell."
block|, }
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|stage0
parameter_list|()
block|{
name|int
name|valid
init|=
literal|0
decl_stmt|;
do|do
block|{
if|if
condition|(
operator|!
name|dialog_menu
argument_list|(
literal|"Welcome to FreeBSD!"
argument_list|,
literal|"Please select one of the following options.\n"
argument_list|,
literal|10
argument_list|,
literal|75
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|,
name|welcome
argument_list|,
name|selection
argument_list|)
condition|)
name|valid
operator|=
literal|1
expr_stmt|;
name|dialog_clear
argument_list|()
expr_stmt|;
block|}
do|while
condition|(
operator|!
name|valid
condition|)
do|;
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
literal|24
argument_list|,
literal|80
argument_list|)
expr_stmt|;
block|}
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
literal|24
argument_list|,
literal|80
argument_list|)
expr_stmt|;
block|}
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
break|break;
case|case
literal|5
case|:
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
break|break;
comment|/* hope not! :) */
block|}
block|}
end_function

end_unit

