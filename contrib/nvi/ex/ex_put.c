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
literal|"@(#)ex_put.c	10.7 (Berkeley) 3/6/96"
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
file|<ctype.h>
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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"../common/common.h"
end_include

begin_comment
comment|/*  * ex_put -- [line] pu[t] [buffer]  *	Append a cut buffer into the file.  *  * PUBLIC: int ex_put __P((SCR *, EXCMD *));  */
end_comment

begin_function
name|int
name|ex_put
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
name|MARK
name|m
decl_stmt|;
name|NEEDFILE
argument_list|(
name|sp
argument_list|,
name|cmdp
argument_list|)
expr_stmt|;
name|m
operator|.
name|lno
operator|=
name|sp
operator|->
name|lno
expr_stmt|;
name|m
operator|.
name|cno
operator|=
name|sp
operator|->
name|cno
expr_stmt|;
if|if
condition|(
name|put
argument_list|(
name|sp
argument_list|,
name|NULL
argument_list|,
name|FL_ISSET
argument_list|(
name|cmdp
operator|->
name|iflags
argument_list|,
name|E_C_BUFFER
argument_list|)
condition|?
operator|&
name|cmdp
operator|->
name|buffer
else|:
name|NULL
argument_list|,
operator|&
name|cmdp
operator|->
name|addr1
argument_list|,
operator|&
name|m
argument_list|,
literal|1
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
name|sp
operator|->
name|lno
operator|=
name|m
operator|.
name|lno
expr_stmt|;
name|sp
operator|->
name|cno
operator|=
name|m
operator|.
name|cno
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

