begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XBdrWidth.c,v 11.8 91/01/06 11:44:11 rws Exp $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1987 */
end_comment

begin_comment
comment|/* Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty. */
end_comment

begin_include
include|#
directive|include
file|"Xlibint.h"
end_include

begin_macro
name|XSetWindowBorderWidth
argument_list|(
argument|dpy
argument_list|,
argument|w
argument_list|,
argument|width
argument_list|)
end_macro

begin_decl_stmt
name|Display
modifier|*
name|dpy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Window
name|w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|width
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|unsigned
name|long
name|lwidth
init|=
name|width
decl_stmt|;
comment|/* must be CARD32 */
specifier|register
name|xConfigureWindowReq
modifier|*
name|req
decl_stmt|;
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|GetReqExtra
argument_list|(
name|ConfigureWindow
argument_list|,
literal|4
argument_list|,
name|req
argument_list|)
expr_stmt|;
name|req
operator|->
name|window
operator|=
name|w
expr_stmt|;
name|req
operator|->
name|mask
operator|=
name|CWBorderWidth
expr_stmt|;
name|OneDataCard32
argument_list|(
name|dpy
argument_list|,
name|NEXTPTR
argument_list|(
name|req
argument_list|,
name|xConfigureWindowReq
argument_list|)
argument_list|,
name|lwidth
argument_list|)
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

