begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * small test-driver for new dialog functionality  *  * Copyright (c) 1995, Jordan Hubbard  *  * All rights reserved.  *  * This source code may be used, modified, copied, distributed, and  * sold, in both source and binary form provided that the above  * copyright and these terms are retained, verbatim, as the first  * lines of this file.  Under no circumstances is the author  * responsible for the proper functioning of the software nor does  * the author assume any responsibility for damages incurred with  * its use.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

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
name|unsigned
name|char
name|result
index|[
literal|128
index|]
decl_stmt|;
name|init_dialog
argument_list|()
expr_stmt|;
name|result
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
name|DialogInputAttrs
operator||=
name|DITEM_NO_ECHO
expr_stmt|;
name|retval
operator|=
name|dialog_inputbox
argument_list|(
literal|"this is dialog_inputbox() in action, test #2 (no echo)"
argument_list|,
literal|"Enter something really secret below, please."
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
name|result
argument_list|)
expr_stmt|;
name|DialogInputAttrs
operator|&=
name|DITEM_NO_ECHO
expr_stmt|;
name|dialog_clear
argument_list|()
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"returned value for dialog_inputbox was %d (%s)\n"
argument_list|,
name|retval
argument_list|,
name|result
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

