begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: keysym.h,v 1.13 91/03/13 20:09:49 rws Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/* default keysyms */
end_comment

begin_define
define|#
directive|define
name|XK_MISCELLANY
end_define

begin_define
define|#
directive|define
name|XK_LATIN1
end_define

begin_define
define|#
directive|define
name|XK_LATIN2
end_define

begin_define
define|#
directive|define
name|XK_LATIN3
end_define

begin_define
define|#
directive|define
name|XK_LATIN4
end_define

begin_define
define|#
directive|define
name|XK_GREEK
end_define

begin_include
include|#
directive|include
file|<X11/keysymdef.h>
end_include

end_unit

