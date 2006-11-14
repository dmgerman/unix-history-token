begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1992, 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|sccsid
index|[]
init|=
literal|"@(#)ex_file.c	10.12 (Berkeley) 7/12/96"
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
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<bitstring.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"../common/common.h"
end_include

begin_comment
comment|/*  * ex_file -- :f[ile] [name]  *	Change the file's name and display the status line.  *  * PUBLIC: int ex_file __P((SCR *, EXCMD *));  */
end_comment

begin_function
name|int
name|ex_file
parameter_list|(
name|sp
parameter_list|,
name|cmdp
parameter_list|)
name|SCR
modifier|*
name|sp
decl_stmt|;
name|EXCMD
modifier|*
name|cmdp
decl_stmt|;
block|{
name|CHAR_T
modifier|*
name|p
decl_stmt|;
name|FREF
modifier|*
name|frp
decl_stmt|;
name|NEEDFILE
argument_list|(
name|sp
argument_list|,
name|cmdp
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|cmdp
operator|->
name|argc
condition|)
block|{
case|case
literal|0
case|:
break|break;
case|case
literal|1
case|:
name|frp
operator|=
name|sp
operator|->
name|frp
expr_stmt|;
comment|/* Make sure can allocate enough space. */
if|if
condition|(
operator|(
name|p
operator|=
name|v_strdup
argument_list|(
name|sp
argument_list|,
name|cmdp
operator|->
name|argv
index|[
literal|0
index|]
operator|->
name|bp
argument_list|,
name|cmdp
operator|->
name|argv
index|[
literal|0
index|]
operator|->
name|len
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* If already have a file name, it becomes the alternate. */
if|if
condition|(
operator|!
name|F_ISSET
argument_list|(
name|frp
argument_list|,
name|FR_TMPFILE
argument_list|)
condition|)
name|set_alt_name
argument_list|(
name|sp
argument_list|,
name|frp
operator|->
name|name
argument_list|)
expr_stmt|;
comment|/* Free the previous name. */
name|free
argument_list|(
name|frp
operator|->
name|name
argument_list|)
expr_stmt|;
name|frp
operator|->
name|name
operator|=
name|p
expr_stmt|;
comment|/* 		 * The file has a real name, it's no longer a temporary, 		 * clear the temporary file flags. 		 */
name|F_CLR
argument_list|(
name|frp
argument_list|,
name|FR_TMPEXIT
operator||
name|FR_TMPFILE
argument_list|)
expr_stmt|;
comment|/* Have to force a write if the file exists, next time. */
name|F_SET
argument_list|(
name|frp
argument_list|,
name|FR_NAMECHANGE
argument_list|)
expr_stmt|;
comment|/* Notify the screen. */
operator|(
name|void
operator|)
name|sp
operator|->
name|gp
operator|->
name|scr_rename
argument_list|(
name|sp
argument_list|,
name|sp
operator|->
name|frp
operator|->
name|name
argument_list|,
literal|1
argument_list|)
expr_stmt|;
break|break;
default|default:
name|abort
argument_list|()
expr_stmt|;
block|}
name|msgq_status
argument_list|(
name|sp
argument_list|,
name|sp
operator|->
name|lno
argument_list|,
name|MSTAT_SHOWLAST
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

