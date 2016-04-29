begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: common.c,v 1.4 2006/05/25 03:20:32 ray Exp $	*/
end_comment

begin_comment
comment|/*  * Written by Raymond Lai<ray@cyth.net>.  * Public domain.  */
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
file|<err.h>
end_include

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

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_function
name|void
name|cleanup
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
block|{
if|if
condition|(
name|unlink
argument_list|(
name|filename
argument_list|)
condition|)
name|err
argument_list|(
literal|2
argument_list|,
literal|"could not delete: %s"
argument_list|,
name|filename
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

