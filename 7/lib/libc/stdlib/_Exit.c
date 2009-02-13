begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This file is in the public domain.  Written by Garrett A. Wollman,  * 2002-09-07.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|/*  * ISO C99 added this function to provide for Standard C applications  * which needed something like POSIX _exit().  A new interface was created  * in case it turned out that _exit() was insufficient to meet the  * requirements of ISO C.  (That's probably not the case, but here  * is where you would put the extra code if it were.)  */
end_comment

begin_function
name|void
name|_Exit
parameter_list|(
name|int
name|code
parameter_list|)
block|{
name|_exit
argument_list|(
name|code
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

