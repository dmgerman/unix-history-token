begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XChWAttrs.c,v 11.9 91/01/06 11:44:25 rws Exp $ */
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

begin_define
define|#
directive|define
name|AllMaskBits
value|(CWBackPixmap|CWBackPixel|CWBorderPixmap|\ 		     CWBorderPixel|CWBitGravity|CWWinGravity|\ 		     CWBackingStore|CWBackingPlanes|CWBackingPixel|\ 		     CWOverrideRedirect|CWSaveUnder|CWEventMask|\ 		     CWDontPropagate|CWColormap|CWCursor)
end_define

begin_expr_stmt
name|XChangeWindowAttributes
argument_list|(
name|dpy
argument_list|,
name|w
argument_list|,
name|valuemask
argument_list|,
name|attributes
argument_list|)
specifier|register
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Window
name|w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|valuemask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XSetWindowAttributes
modifier|*
name|attributes
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|xChangeWindowAttributesReq
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
name|ChangeWindowAttributes
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
name|valuemask
operator|&=
name|AllMaskBits
expr_stmt|;
if|if
condition|(
name|req
operator|->
name|valueMask
operator|=
name|valuemask
condition|)
name|_XProcessWindowAttributes
argument_list|(
name|dpy
argument_list|,
name|req
argument_list|,
name|valuemask
argument_list|,
name|attributes
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

