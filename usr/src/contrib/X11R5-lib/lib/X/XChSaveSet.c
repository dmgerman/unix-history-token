begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XChSaveSet.c,v 11.6 91/01/06 11:44:23 rws Exp $ */
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
name|XChangeSaveSet
argument_list|(
name|dpy
argument_list|,
name|win
argument_list|,
name|mode
argument_list|)
specifier|register
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Window
name|win
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mode
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|xChangeSaveSetReq
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
name|ChangeSaveSet
argument_list|,
name|req
argument_list|)
expr_stmt|;
name|req
operator|->
name|window
operator|=
name|win
expr_stmt|;
name|req
operator|->
name|mode
operator|=
name|mode
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

begin_expr_stmt
name|XAddToSaveSet
argument_list|(
name|dpy
argument_list|,
name|win
argument_list|)
specifier|register
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Window
name|win
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|XChangeSaveSet
argument_list|(
name|dpy
argument_list|,
name|win
argument_list|,
name|SetModeInsert
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|XRemoveFromSaveSet
argument_list|(
name|dpy
argument_list|,
name|win
argument_list|)
specifier|register
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Window
name|win
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|XChangeSaveSet
argument_list|(
name|dpy
argument_list|,
name|win
argument_list|,
name|SetModeDelete
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

