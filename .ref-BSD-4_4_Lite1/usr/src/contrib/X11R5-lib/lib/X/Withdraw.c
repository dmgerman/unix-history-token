begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Withdraw.c,v 1.5 91/02/01 16:33:33 gildea Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1988 by Wyse Technology, Inc., San Jose, Ca., and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Wyse or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    WYSE DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_define
define|#
directive|define
name|NEED_EVENTS
end_define

begin_include
include|#
directive|include
file|<X11/Xlibint.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xatom.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xos.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xutil.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/*  * This function instructs the window manager to change this window from  * NormalState or IconicState to Withdrawn.  */
end_comment

begin_function
name|Status
name|XWithdrawWindow
parameter_list|(
name|dpy
parameter_list|,
name|w
parameter_list|,
name|screen
parameter_list|)
name|Display
modifier|*
name|dpy
decl_stmt|;
name|Window
name|w
decl_stmt|;
name|int
name|screen
decl_stmt|;
block|{
name|XUnmapEvent
name|ev
decl_stmt|;
name|Window
name|root
init|=
name|RootWindow
argument_list|(
name|dpy
argument_list|,
name|screen
argument_list|)
decl_stmt|;
name|XUnmapWindow
argument_list|(
name|dpy
argument_list|,
name|w
argument_list|)
expr_stmt|;
name|ev
operator|.
name|type
operator|=
name|UnmapNotify
expr_stmt|;
name|ev
operator|.
name|event
operator|=
name|root
expr_stmt|;
name|ev
operator|.
name|window
operator|=
name|w
expr_stmt|;
name|ev
operator|.
name|from_configure
operator|=
name|False
expr_stmt|;
return|return
operator|(
name|XSendEvent
argument_list|(
name|dpy
argument_list|,
name|root
argument_list|,
name|False
argument_list|,
name|SubstructureRedirectMask
operator||
name|SubstructureNotifyMask
argument_list|,
operator|(
name|XEvent
operator|*
operator|)
operator|&
name|ev
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

