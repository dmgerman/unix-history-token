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
literal|"@(#)ex_quit.c	10.7 (Berkeley) 4/27/96"
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
file|"../common/common.h"
end_include

begin_comment
comment|/*  * ex_quit -- :quit[!]  *	Quit.  *  * PUBLIC: int ex_quit __P((SCR *, EXCMD *));  */
end_comment

begin_function
name|int
name|ex_quit
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
name|int
name|force
decl_stmt|;
name|force
operator|=
name|FL_ISSET
argument_list|(
name|cmdp
operator|->
name|iflags
argument_list|,
name|E_C_FORCE
argument_list|)
expr_stmt|;
comment|/* Check for file modifications, or more files to edit. */
if|if
condition|(
name|file_m2
argument_list|(
name|sp
argument_list|,
name|force
argument_list|)
operator|||
name|ex_ncheck
argument_list|(
name|sp
argument_list|,
name|force
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
name|F_SET
argument_list|(
name|sp
argument_list|,
name|force
condition|?
name|SC_EXIT_FORCE
else|:
name|SC_EXIT
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

