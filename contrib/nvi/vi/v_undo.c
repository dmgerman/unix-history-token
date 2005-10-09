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
literal|"@(#)v_undo.c	10.5 (Berkeley) 3/6/96"
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

begin_include
include|#
directive|include
file|"vi.h"
end_include

begin_comment
comment|/*  * v_Undo -- U  *	Undo changes to this line.  *  * PUBLIC: int v_Undo __P((SCR *, VICMD *));  */
end_comment

begin_function
name|int
name|v_Undo
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
comment|/* 	 * Historically, U reset the cursor to the first column in the line 	 * (not the first non-blank).  This seems a bit non-intuitive, but, 	 * considering that we may have undone multiple changes, anything 	 * else (including the cursor position stored in the logging records) 	 * is going to appear random. 	 */
name|vp
operator|->
name|m_final
operator|.
name|cno
operator|=
literal|0
expr_stmt|;
comment|/* 	 * !!! 	 * Set up the flags so that an immediately subsequent 'u' will roll 	 * forward, instead of backward.  In historic vi, a 'u' following a 	 * 'U' redid all of the changes to the line.  Given that the user has 	 * explicitly discarded those changes by entering 'U', it seems likely 	 * that the user wants something between the original and end forms of 	 * the line, so starting to replay the changes seems the best way to 	 * get to there. 	 */
name|F_SET
argument_list|(
name|sp
operator|->
name|ep
argument_list|,
name|F_UNDO
argument_list|)
expr_stmt|;
name|sp
operator|->
name|ep
operator|->
name|lundo
operator|=
name|BACKWARD
expr_stmt|;
return|return
operator|(
name|log_setline
argument_list|(
name|sp
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * v_undo -- u  *	Undo the last change.  *  * PUBLIC: int v_undo __P((SCR *, VICMD *));  */
end_comment

begin_function
name|int
name|v_undo
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
name|EXF
modifier|*
name|ep
decl_stmt|;
comment|/* Set the command count. */
name|VIP
argument_list|(
name|sp
argument_list|)
operator|->
name|u_ccnt
operator|=
name|sp
operator|->
name|ccnt
expr_stmt|;
comment|/* 	 * !!! 	 * In historic vi, 'u' toggled between "undo" and "redo", i.e. 'u' 	 * undid the last undo.  However, if there has been a change since 	 * the last undo/redo, we always do an undo.  To make this work when 	 * the user can undo multiple operations, we leave the old semantic 	 * unchanged, but make '.' after a 'u' do another undo/redo operation. 	 * This has two problems. 	 * 	 * The first is that 'u' didn't set '.' in historic vi.  So, if a 	 * user made a change, realized it was in the wrong place, does a 	 * 'u' to undo it, moves to the right place and then does '.', the 	 * change was reapplied.  To make this work, we only apply the '.' 	 * to the undo command if it's the command immediately following an 	 * undo command.  See vi/vi.c:getcmd() for the details. 	 * 	 * The second is that the traditional way to view the numbered cut 	 * buffers in vi was to enter the commands "1pu.u.u.u. which will 	 * no longer work because the '.' immediately follows the 'u' command. 	 * Since we provide a much better method of viewing buffers, and 	 * nobody can think of a better way of adding in multiple undo, this 	 * remains broken. 	 * 	 * !!! 	 * There is change to historic practice for the final cursor position 	 * in this implementation.  In historic vi, if an undo was isolated to 	 * a single line, the cursor moved to the start of the change, and 	 * then, subsequent 'u' commands would not move it again. (It has been 	 * pointed out that users used multiple undo commands to get the cursor 	 * to the start of the changed text.)  Nvi toggles between the cursor 	 * position before and after the change was made.  One final issue is 	 * that historic vi only did this if the user had not moved off of the 	 * line before entering the undo command; otherwise, vi would move the 	 * cursor to the most attractive position on the changed line. 	 * 	 * It would be difficult to match historic practice in this area. You 	 * not only have to know that the changes were isolated to one line, 	 * but whether it was the first or second undo command as well.  And, 	 * to completely match historic practice, we'd have to track users line 	 * changes, too.  This isn't worth the effort. 	 */
name|ep
operator|=
name|sp
operator|->
name|ep
expr_stmt|;
if|if
condition|(
operator|!
name|F_ISSET
argument_list|(
name|ep
argument_list|,
name|F_UNDO
argument_list|)
condition|)
block|{
name|F_SET
argument_list|(
name|ep
argument_list|,
name|F_UNDO
argument_list|)
expr_stmt|;
name|ep
operator|->
name|lundo
operator|=
name|BACKWARD
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|F_ISSET
argument_list|(
name|vp
argument_list|,
name|VC_ISDOT
argument_list|)
condition|)
name|ep
operator|->
name|lundo
operator|=
name|ep
operator|->
name|lundo
operator|==
name|BACKWARD
condition|?
name|FORWARD
else|:
name|BACKWARD
expr_stmt|;
switch|switch
condition|(
name|ep
operator|->
name|lundo
condition|)
block|{
case|case
name|BACKWARD
case|:
return|return
operator|(
name|log_backward
argument_list|(
name|sp
argument_list|,
operator|&
name|vp
operator|->
name|m_final
argument_list|)
operator|)
return|;
case|case
name|FORWARD
case|:
return|return
operator|(
name|log_forward
argument_list|(
name|sp
argument_list|,
operator|&
name|vp
operator|->
name|m_final
argument_list|)
operator|)
return|;
default|default:
name|abort
argument_list|()
expr_stmt|;
block|}
comment|/* NOTREACHED */
block|}
end_function

end_unit

