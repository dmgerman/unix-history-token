begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: CompositeP.h,v 1.15 91/10/24 13:20:18 converse Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XtCompositeP_h
end_ifndef

begin_define
define|#
directive|define
name|_XtCompositeP_h
end_define

begin_include
include|#
directive|include
file|<X11/Composite.h>
end_include

begin_comment
comment|/************************************************************************  *  * Additional instance fields for widgets of (sub)class 'Composite'   *  ************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CompositePart
block|{
name|WidgetList
name|children
decl_stmt|;
comment|/* array of ALL widget children	     */
name|Cardinal
name|num_children
decl_stmt|;
comment|/* total number of widget children	     */
name|Cardinal
name|num_slots
decl_stmt|;
comment|/* number of slots in children array    */
name|XtOrderProc
name|insert_position
decl_stmt|;
comment|/* compute position of new child	     */
block|}
name|CompositePart
operator|,
typedef|*
name|CompositePtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_CompositeRec
block|{
name|CorePart
name|core
decl_stmt|;
name|CompositePart
name|composite
decl_stmt|;
block|}
name|CompositeRec
typedef|;
end_typedef

begin_comment
comment|/*********************************************************************  *  *  Additional class fields for widgets of (sub)class 'Composite'  *  ********************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CompositeClassPart
block|{
name|XtGeometryHandler
name|geometry_manager
decl_stmt|;
comment|/* geometry manager for children   */
name|XtWidgetProc
name|change_managed
decl_stmt|;
comment|/* change managed state of child   */
name|XtWidgetProc
name|insert_child
decl_stmt|;
comment|/* physically add child to parent  */
name|XtWidgetProc
name|delete_child
decl_stmt|;
comment|/* physically remove child	     */
name|XtPointer
name|extension
decl_stmt|;
comment|/* pointer to extension record     */
block|}
name|CompositeClassPart
operator|,
typedef|*
name|CompositePartPtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|XtPointer
name|next_extension
decl_stmt|;
comment|/* 1st 4 mandated for all extension records */
name|XrmQuark
name|record_type
decl_stmt|;
comment|/* NULLQUARK; on CompositeClassPart */
name|long
name|version
decl_stmt|;
comment|/* must be XtCompositeExtensionVersion */
name|Cardinal
name|record_size
decl_stmt|;
comment|/* sizeof(CompositeClassExtensionRec) */
name|Boolean
name|accepts_objects
decl_stmt|;
block|}
name|CompositeClassExtensionRec
operator|,
typedef|*
name|CompositeClassExtension
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_CompositeClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|CompositeClassPart
name|composite_class
decl_stmt|;
block|}
name|CompositeClassRec
typedef|;
end_typedef

begin_decl_stmt
name|externalref
name|CompositeClassRec
name|compositeClassRec
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|XtCompositeExtensionVersion
value|1L
end_define

begin_define
define|#
directive|define
name|XtInheritGeometryManager
value|((XtGeometryHandler) _XtInherit)
end_define

begin_define
define|#
directive|define
name|XtInheritChangeManaged
value|((XtWidgetProc) _XtInherit)
end_define

begin_define
define|#
directive|define
name|XtInheritInsertChild
value|((XtWidgetProc) _XtInherit)
end_define

begin_define
define|#
directive|define
name|XtInheritDeleteChild
value|((XtWidgetProc) _XtInherit)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XtCompositeP_h */
end_comment

begin_comment
comment|/* DON'T ADD STUFF AFTER THIS #endif */
end_comment

end_unit

