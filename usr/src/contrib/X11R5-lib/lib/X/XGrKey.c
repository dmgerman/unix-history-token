begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XGrKey.c,v 11.8 91/01/06 11:46:23 rws Exp $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1986	*/
end_comment

begin_comment
comment|/* Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty. */
end_comment

begin_include
include|#
directive|include
file|"Xlibint.h"
end_include

begin_expr_stmt
name|XGrabKey
argument_list|(
name|dpy
argument_list|,
name|key
argument_list|,
name|modifiers
argument_list|,
name|grab_window
argument_list|,
name|owner_events
argument_list|,
name|pointer_mode
argument_list|,
name|keyboard_mode
argument_list|)
specifier|register
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|key
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|modifiers
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Window
name|grab_window
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Bool
name|owner_events
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pointer_mode
decl_stmt|,
name|keyboard_mode
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|xGrabKeyReq
modifier|*
name|req
decl_stmt|;
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|GetReq
argument_list|(
name|GrabKey
argument_list|,
name|req
argument_list|)
expr_stmt|;
name|req
operator|->
name|ownerEvents
operator|=
name|owner_events
expr_stmt|;
name|req
operator|->
name|grabWindow
operator|=
name|grab_window
expr_stmt|;
name|req
operator|->
name|modifiers
operator|=
name|modifiers
expr_stmt|;
name|req
operator|->
name|key
operator|=
name|key
expr_stmt|;
name|req
operator|->
name|pointerMode
operator|=
name|pointer_mode
expr_stmt|;
name|req
operator|->
name|keyboardMode
operator|=
name|keyboard_mode
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

