begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * $XConsortium: BoxP.h,v 1.16 89/11/06 10:51:28 swick Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*   * BoxP.h - Private definitions for Box widget  *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawBoxP_h
end_ifndef

begin_define
define|#
directive|define
name|_XawBoxP_h
end_define

begin_comment
comment|/***********************************************************************  *  * Box Widget Private Data  *  ***********************************************************************/
end_comment

begin_include
include|#
directive|include
file|<X11/Xaw/Box.h>
end_include

begin_include
include|#
directive|include
file|<X11/CompositeP.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xmu/Converters.h>
end_include

begin_comment
comment|/* New fields for the Box widget class record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|empty
decl_stmt|;
block|}
name|BoxClassPart
typedef|;
end_typedef

begin_comment
comment|/* Full class record declaration */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_BoxClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|CompositeClassPart
name|composite_class
decl_stmt|;
name|BoxClassPart
name|box_class
decl_stmt|;
block|}
name|BoxClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|BoxClassRec
name|boxClassRec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* New fields for the Box widget record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* resources */
name|Dimension
name|h_space
decl_stmt|,
name|v_space
decl_stmt|;
name|XtOrientation
name|orientation
decl_stmt|;
comment|/* private state */
name|Dimension
name|preferred_width
decl_stmt|,
name|preferred_height
decl_stmt|;
name|Dimension
name|last_query_width
decl_stmt|,
name|last_query_height
decl_stmt|;
name|XtGeometryMask
name|last_query_mode
decl_stmt|;
block|}
name|BoxPart
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *  * Full instance record declaration  *  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_BoxRec
block|{
name|CorePart
name|core
decl_stmt|;
name|CompositePart
name|composite
decl_stmt|;
name|BoxPart
name|box
decl_stmt|;
block|}
name|BoxRec
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawBoxP_h */
end_comment

end_unit

