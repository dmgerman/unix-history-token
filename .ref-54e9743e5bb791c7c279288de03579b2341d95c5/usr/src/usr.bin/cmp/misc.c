begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)misc.c	8.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

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
file|"extern.h"
end_include

begin_function
name|void
name|eofmsg
parameter_list|(
name|file
parameter_list|)
name|char
modifier|*
name|file
decl_stmt|;
block|{
if|if
condition|(
operator|!
name|sflag
condition|)
name|warnx
argument_list|(
literal|"EOF on %s"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|DIFF_EXIT
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|void
name|diffmsg
argument_list|(
name|file1
argument_list|,
name|file2
argument_list|,
name|byte
argument_list|,
name|line
argument_list|)
name|char
modifier|*
name|file1
decl_stmt|,
modifier|*
name|file2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|off_t
name|byte
decl_stmt|,
name|line
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
operator|!
name|sflag
condition|)
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s %s differ: char %qd, line %qd\n"
argument_list|,
name|file1
argument_list|,
name|file2
argument_list|,
name|byte
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|DIFF_EXIT
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

