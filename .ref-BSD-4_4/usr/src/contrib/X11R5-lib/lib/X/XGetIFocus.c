begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XGetIFocus.c,v 11.10 91/01/06 11:46:05 rws Exp $ */
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

begin_include
include|#
directive|include
file|"Xlibint.h"
end_include

begin_expr_stmt
name|XGetInputFocus
argument_list|(
name|dpy
argument_list|,
name|focus
argument_list|,
name|revert_to
argument_list|)
specifier|register
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Window
modifier|*
name|focus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|revert_to
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
operator|*
name|focus
operator|=
name|rep
operator|.
name|focus
expr_stmt|;
operator|*
name|revert_to
operator|=
name|rep
operator|.
name|revertTo
expr_stmt|;
name|UnlockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|SyncHandle
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

