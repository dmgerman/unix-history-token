begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * $XConsortium: GripP.h,v 1.14 89/05/11 01:05:27 kit Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  *  GripP.h - Private definitions for Grip widget (Used by VPane Widget)  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawGripP_h
end_ifndef

begin_define
define|#
directive|define
name|_XawGripP_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/Grip.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/SimpleP.h>
end_include

begin_comment
comment|/*****************************************************************************  *  * Grip Widget Private Data  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DEFAULT_GRIP_SIZE
value|8
end_define

begin_comment
comment|/* New fields for the Grip widget class record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|empty
decl_stmt|;
block|}
name|GripClassPart
typedef|;
end_typedef

begin_comment
comment|/* Full Class record declaration */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_GripClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|SimpleClassPart
name|simple_class
decl_stmt|;
name|GripClassPart
name|grip_class
decl_stmt|;
block|}
name|GripClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|GripClassRec
name|gripClassRec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* New fields for the Grip widget record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XtCallbackList
name|grip_action
decl_stmt|;
block|}
name|GripPart
typedef|;
end_typedef

begin_comment
comment|/*****************************************************************************  *  * Full instance record declaration  *  ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_GripRec
block|{
name|CorePart
name|core
decl_stmt|;
name|SimplePart
name|simple
decl_stmt|;
name|GripPart
name|grip
decl_stmt|;
block|}
name|GripRec
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawGripP_h */
end_comment

end_unit

