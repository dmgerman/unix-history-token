begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Xprotostr.h,v 1.4 91/03/13 20:09:34 rws Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XPROTOSTRUCTS_H
end_ifndef

begin_define
define|#
directive|define
name|XPROTOSTRUCTS_H
end_define

begin_comment
comment|/*********************************************************** Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_include
include|#
directive|include
file|<X11/Xmd.h>
end_include

begin_comment
comment|/* Used by PolySegment */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_xSegment
block|{
name|INT16
name|x1
name|B16
decl_stmt|,
name|y1
name|B16
decl_stmt|,
name|x2
name|B16
decl_stmt|,
name|y2
name|B16
decl_stmt|;
block|}
name|xSegment
typedef|;
end_typedef

begin_comment
comment|/* POINT */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_xPoint
block|{
name|INT16
name|x
name|B16
decl_stmt|,
name|y
name|B16
decl_stmt|;
block|}
name|xPoint
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_xRectangle
block|{
name|INT16
name|x
name|B16
decl_stmt|,
name|y
name|B16
decl_stmt|;
name|CARD16
name|width
name|B16
decl_stmt|,
name|height
name|B16
decl_stmt|;
block|}
name|xRectangle
typedef|;
end_typedef

begin_comment
comment|/*  ARC  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_xArc
block|{
name|INT16
name|x
name|B16
decl_stmt|,
name|y
name|B16
decl_stmt|;
name|CARD16
name|width
name|B16
decl_stmt|,
name|height
name|B16
decl_stmt|;
name|INT16
name|angle1
name|B16
decl_stmt|,
name|angle2
name|B16
decl_stmt|;
block|}
name|xArc
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XPROTOSTRUCTS_H */
end_comment

end_unit

