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
name|i
decl_stmt|;
name|init_dialog
argument_list|()
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<=
literal|100
condition|;
name|i
operator|++
control|)
block|{
name|dialog_gauge
argument_list|(
literal|"Gas tank"
argument_list|,
literal|"When this gets 100% full, you'd better yank out the nozzle!"
argument_list|,
literal|10
argument_list|,
literal|1
argument_list|,
literal|7
argument_list|,
literal|70
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|usleep
argument_list|(
literal|30000
argument_list|)
expr_stmt|;
block|}
name|end_dialog
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

