begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XSync.c,v 11.15 91/01/06 11:48:24 rws Exp $ */
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
name|NEED_REPLIES
end_define

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
comment|/* Synchronize with errors and events, optionally discarding pending events */
end_comment

begin_expr_stmt
name|XSync
argument_list|(
name|dpy
argument_list|,
name|discard
argument_list|)
specifier|register
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Bool
name|discard
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|xGetInputFocusReply
name|rep
decl_stmt|;
specifier|register
name|xReq
modifier|*
name|req
decl_stmt|;
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|GetEmptyReq
argument_list|(
name|GetInputFocus
argument_list|,
name|req
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|_XReply
argument_list|(
name|dpy
argument_list|,
operator|(
name|xReply
operator|*
operator|)
operator|&
name|rep
argument_list|,
literal|0
argument_list|,
name|xTrue
argument_list|)
expr_stmt|;
if|if
condition|(
name|discard
operator|&&
name|dpy
operator|->
name|head
condition|)
block|{
operator|(
operator|(
name|_XQEvent
operator|*
operator|)
name|dpy
operator|->
name|tail
operator|)
operator|->
name|next
operator|=
name|_qfree
expr_stmt|;
name|_qfree
operator|=
operator|(
name|_XQEvent
operator|*
operator|)
name|dpy
operator|->
name|head
expr_stmt|;
name|dpy
operator|->
name|head
operator|=
name|dpy
operator|->
name|tail
operator|=
name|NULL
expr_stmt|;
name|dpy
operator|->
name|qlen
operator|=
literal|0
expr_stmt|;
block|}
name|UnlockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

