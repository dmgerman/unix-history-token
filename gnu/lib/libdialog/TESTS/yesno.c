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
name|rval1
decl_stmt|,
name|rval2
decl_stmt|;
name|init_dialog
argument_list|()
expr_stmt|;
name|rval1
operator|=
name|dialog_yesno
argument_list|(
literal|"This is dialog_yesno() in action"
argument_list|,
literal|"Have you stopped deliberately putting bugs into your code?"
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|dialog_clear
argument_list|()
expr_stmt|;
name|rval2
operator|=
name|dialog_noyes
argument_list|(
literal|"This is dialog_noyes() in action"
argument_list|,
literal|"Have you stopped beating your wife?"
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|dialog_clear
argument_list|()
expr_stmt|;
name|end_dialog
argument_list|()
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"returned value for dialog_yesno was %d\n"
argument_list|,
name|rval1
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"returned value for dialog_noyes was %d\n"
argument_list|,
name|rval2
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

