begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XNextEvent.c,v 11.16 91/01/06 11:47:06 rws Exp $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1986	*/
end_comment

begin_comment
comment|/* Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty. */
end_comment

begin_define
define|#
directive|define
name|NEED_EVENTS
end_define

begin_include
include|#
directive|include
file|"Xlibint.h"
end_include

begin_decl_stmt
specifier|extern
name|_XQEvent
modifier|*
name|_qfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * Return next event in queue, or if none, flush output and wait for  * events.  */
end_comment

begin_expr_stmt
name|XNextEvent
argument_list|(
name|dpy
argument_list|,
name|event
argument_list|)
specifier|register
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|XEvent
modifier|*
name|event
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|_XQEvent
modifier|*
name|qelt
decl_stmt|;
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
if|if
condition|(
name|dpy
operator|->
name|head
operator|==
name|NULL
condition|)
name|_XReadEvents
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|qelt
operator|=
name|dpy
operator|->
name|head
expr_stmt|;
operator|*
name|event
operator|=
name|qelt
operator|->
name|event
expr_stmt|;
comment|/* move the head of the queue to the free list */
if|if
condition|(
operator|(
name|dpy
operator|->
name|head
operator|=
name|qelt
operator|->
name|next
operator|)
operator|==
name|NULL
condition|)
name|dpy
operator|->
name|tail
operator|=
name|NULL
expr_stmt|;
name|qelt
operator|->
name|next
operator|=
name|_qfree
expr_stmt|;
name|_qfree
operator|=
name|qelt
expr_stmt|;
name|dpy
operator|->
name|qlen
operator|--
expr_stmt|;
name|UnlockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

end_unit

