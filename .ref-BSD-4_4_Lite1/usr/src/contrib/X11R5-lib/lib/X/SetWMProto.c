begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: SetWMProto.c,v 1.4 91/01/06 11:43:54 rws Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_include
include|#
directive|include
file|"Xlibint.h"
end_include

begin_include
include|#
directive|include
file|<X11/Xatom.h>
end_include

begin_comment
comment|/*   * XSetWMProtocols sets the property   *	WM_PROTOCOLS 	type: ATOM	format: 32  */
end_comment

begin_function
name|Status
name|XSetWMProtocols
parameter_list|(
name|dpy
parameter_list|,
name|w
parameter_list|,
name|protocols
parameter_list|,
name|count
parameter_list|)
name|Display
modifier|*
name|dpy
decl_stmt|;
name|Window
name|w
decl_stmt|;
name|Atom
modifier|*
name|protocols
decl_stmt|;
name|int
name|count
decl_stmt|;
block|{
name|Atom
name|prop
decl_stmt|;
name|prop
operator|=
name|XInternAtom
argument_list|(
name|dpy
argument_list|,
literal|"WM_PROTOCOLS"
argument_list|,
name|False
argument_list|)
expr_stmt|;
if|if
condition|(
name|prop
operator|==
name|None
condition|)
return|return
name|False
return|;
name|XChangeProperty
argument_list|(
name|dpy
argument_list|,
name|w
argument_list|,
name|prop
argument_list|,
name|XA_ATOM
argument_list|,
literal|32
argument_list|,
name|PropModeReplace
argument_list|,
operator|(
name|unsigned
name|char
operator|*
operator|)
name|protocols
argument_list|,
name|count
argument_list|)
expr_stmt|;
return|return
name|True
return|;
block|}
end_function

end_unit

