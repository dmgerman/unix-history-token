begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XGrButton.c,v 11.9 91/01/06 11:46:22 rws Exp $ */
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
name|XGrabButton
argument_list|(
name|dpy
argument_list|,
name|button
argument_list|,
name|modifiers
argument_list|,
name|grab_window
argument_list|,
name|owner_events
argument_list|,
name|event_mask
argument_list|,
name|pointer_mode
argument_list|,
name|keyboard_mode
argument_list|,
name|confine_to
argument_list|,
name|curs
argument_list|)
specifier|register
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|unsigned
name|int
name|modifiers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CARD16 */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|button
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CARD8 */
end_comment

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
name|unsigned
name|int
name|event_mask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CARD16 */
end_comment

begin_decl_stmt
name|int
name|pointer_mode
decl_stmt|,
name|keyboard_mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Window
name|confine_to
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Cursor
name|curs
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|xGrabButtonReq
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
name|GrabButton
argument_list|,
name|req
argument_list|)
expr_stmt|;
name|req
operator|->
name|modifiers
operator|=
name|modifiers
expr_stmt|;
name|req
operator|->
name|button
operator|=
name|button
expr_stmt|;
name|req
operator|->
name|grabWindow
operator|=
name|grab_window
expr_stmt|;
name|req
operator|->
name|ownerEvents
operator|=
name|owner_events
expr_stmt|;
name|req
operator|->
name|eventMask
operator|=
name|event_mask
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
name|req
operator|->
name|confineTo
operator|=
name|confine_to
expr_stmt|;
name|req
operator|->
name|cursor
operator|=
name|curs
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

