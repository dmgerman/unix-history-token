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
literal|"$Id: v_redraw.c,v 10.7 2001/06/25 15:19:34 skimo Exp $"
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
file|<sys/time.h>
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

begin_include
include|#
directive|include
file|"vi.h"
end_include

begin_comment
comment|/*  * v_redraw -- ^L, ^R  *	Redraw the screen.  *  * PUBLIC: int v_redraw __P((SCR *, VICMD *));  */
end_comment

begin_function
name|int
name|v_redraw
parameter_list|(
name|SCR
modifier|*
name|sp
parameter_list|,
name|VICMD
modifier|*
name|vp
parameter_list|)
block|{
return|return
operator|(
name|sp
operator|->
name|gp
operator|->
name|scr_refresh
argument_list|(
name|sp
argument_list|,
literal|1
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

