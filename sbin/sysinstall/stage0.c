begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@login.dkuug.dk> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $Id$  *  */
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
file|<ncurses.h>
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

begin_function
name|void
name|stage0
parameter_list|()
block|{
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
name|clear
argument_list|()
expr_stmt|;
name|dialog_textbox
argument_list|(
literal|"READ ME FIRST"
argument_list|,
name|README_FILE
argument_list|,
literal|25
argument_list|,
literal|80
argument_list|)
expr_stmt|;
block|}
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
name|clear
argument_list|()
expr_stmt|;
name|dialog_textbox
argument_list|(
literal|"COPYRIGHT"
argument_list|,
name|COPYRIGHT_FILE
argument_list|,
literal|25
argument_list|,
literal|80
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

