begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1992, 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  */
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
literal|"@(#)v_screen.c	10.10 (Berkeley) 4/27/96"
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
comment|/*  * v_screen -- ^W  *	Switch screens.  *  * PUBLIC: int v_screen __P((SCR *, VICMD *));  */
end_comment

begin_function
name|int
name|v_screen
parameter_list|(
name|sp
parameter_list|,
name|vp
parameter_list|)
name|SCR
modifier|*
name|sp
decl_stmt|;
name|VICMD
modifier|*
name|vp
decl_stmt|;
block|{
comment|/* 	 * You can't leave a colon command-line edit window -- it's not that 	 * it won't work, but it gets real weird, real fast when you execute 	 * a colon command out of a window that was forked from a window that's 	 * now backgrounded...  You get the idea. 	 */
if|if
condition|(
name|F_ISSET
argument_list|(
name|sp
argument_list|,
name|SC_COMEDIT
argument_list|)
condition|)
block|{
name|msgq
argument_list|(
name|sp
argument_list|,
name|M_ERR
argument_list|,
literal|"308|Enter<CR> to execute a command, :q to exit"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
comment|/* 	 * Try for the next lower screen, or, go back to the first 	 * screen on the stack. 	 */
if|if
condition|(
name|sp
operator|->
name|q
operator|.
name|cqe_next
operator|!=
operator|(
name|void
operator|*
operator|)
operator|&
name|sp
operator|->
name|gp
operator|->
name|dq
condition|)
name|sp
operator|->
name|nextdisp
operator|=
name|sp
operator|->
name|q
operator|.
name|cqe_next
expr_stmt|;
elseif|else
if|if
condition|(
name|sp
operator|->
name|gp
operator|->
name|dq
operator|.
name|cqh_first
operator|==
name|sp
condition|)
block|{
name|msgq
argument_list|(
name|sp
argument_list|,
name|M_ERR
argument_list|,
literal|"187|No other screen to switch to"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
else|else
name|sp
operator|->
name|nextdisp
operator|=
name|sp
operator|->
name|gp
operator|->
name|dq
operator|.
name|cqh_first
expr_stmt|;
name|F_SET
argument_list|(
name|sp
operator|->
name|nextdisp
argument_list|,
name|SC_STATUS
argument_list|)
expr_stmt|;
name|F_SET
argument_list|(
name|sp
argument_list|,
name|SC_SSWITCH
operator||
name|SC_STATUS
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

