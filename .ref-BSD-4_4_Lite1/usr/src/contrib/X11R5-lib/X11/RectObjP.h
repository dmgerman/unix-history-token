begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: RectObjP.h,v 1.11 90/03/19 12:52:48 swick Exp $ */
end_comment

begin_comment
comment|/* $oHeader: RectObjP.h,v 1.2 88/08/18 15:55:52 asente Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_Xt_RectObjP_h_
end_ifndef

begin_define
define|#
directive|define
name|_Xt_RectObjP_h_
end_define

begin_include
include|#
directive|include
file|<X11/RectObj.h>
end_include

begin_include
include|#
directive|include
file|<X11/ObjectP.h>
end_include

begin_comment
comment|/**********************************************************  * Rectangle Object Instance Data Structures  *  **********************************************************/
end_comment

begin_comment
comment|/* these fields match CorePart and can not be changed */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_RectObjPart
block|{
name|Position
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* rectangle position               */
name|Dimension
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|/* rectangle dimensions             */
name|Dimension
name|border_width
decl_stmt|;
comment|/* rectangle border width           */
name|Boolean
name|managed
decl_stmt|;
comment|/* is widget geometry managed?       */
name|Boolean
name|sensitive
decl_stmt|;
comment|/* is widget sensitive to user events*/
name|Boolean
name|ancestor_sensitive
decl_stmt|;
comment|/* are all ancestors sensitive?      */
block|}
name|RectObjPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_RectObjRec
block|{
name|ObjectPart
name|object
decl_stmt|;
name|RectObjPart
name|rectangle
decl_stmt|;
block|}
name|RectObjRec
typedef|;
end_typedef

begin_comment
comment|/********************************************************  * Rectangle Object Class Data Structures  *  ********************************************************/
end_comment

begin_comment
comment|/* these fields match CoreClassPart and can not be changed */
end_comment

begin_comment
comment|/* ideally these structures would only contain the fields required;    but because the CoreClassPart cannot be changed at this late date    extraneous fields are necessary to make the field offsets match */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_RectObjClassPart
block|{
name|WidgetClass
name|superclass
decl_stmt|;
comment|/* pointer to superclass ClassRec   */
name|String
name|class_name
decl_stmt|;
comment|/* widget resource class name       */
name|Cardinal
name|widget_size
decl_stmt|;
comment|/* size in bytes of widget record   */
name|XtProc
name|class_initialize
decl_stmt|;
comment|/* class initialization proc        */
name|XtWidgetClassProc
name|class_part_initialize
decl_stmt|;
comment|/* dynamic initialization      */
name|XtEnum
name|class_inited
decl_stmt|;
comment|/* has class been initialized?      */
name|XtInitProc
name|initialize
decl_stmt|;
comment|/* initialize subclass fields       */
name|XtArgsProc
name|initialize_hook
decl_stmt|;
comment|/* notify that initialize called    */
name|XtProc
name|rect1
decl_stmt|;
comment|/* NULL                             */
name|XtPointer
name|rect2
decl_stmt|;
comment|/* NULL                             */
name|Cardinal
name|rect3
decl_stmt|;
comment|/* NULL                             */
name|XtResourceList
name|resources
decl_stmt|;
comment|/* resources for subclass fields    */
name|Cardinal
name|num_resources
decl_stmt|;
comment|/* number of entries in resources   */
name|XrmClass
name|xrm_class
decl_stmt|;
comment|/* resource class quarkified        */
name|Boolean
name|rect4
decl_stmt|;
comment|/* NULL                             */
name|Boolean
name|rect5
decl_stmt|;
comment|/* NULL                             */
name|Boolean
name|rect6
decl_stmt|;
comment|/* NULL				    */
name|Boolean
name|rect7
decl_stmt|;
comment|/* NULL                             */
name|XtWidgetProc
name|destroy
decl_stmt|;
comment|/* free data for subclass pointers  */
name|XtWidgetProc
name|resize
decl_stmt|;
comment|/* geom manager changed widget size */
name|XtExposeProc
name|expose
decl_stmt|;
comment|/* rediplay rectangle               */
name|XtSetValuesFunc
name|set_values
decl_stmt|;
comment|/* set subclass resource values     */
name|XtArgsFunc
name|set_values_hook
decl_stmt|;
comment|/* notify that set_values called    */
name|XtAlmostProc
name|set_values_almost
decl_stmt|;
comment|/* set values almost for geometry   */
name|XtArgsProc
name|get_values_hook
decl_stmt|;
comment|/* notify that get_values called    */
name|XtProc
name|rect9
decl_stmt|;
comment|/* NULL                             */
name|XtVersionType
name|version
decl_stmt|;
comment|/* version of intrinsics used       */
name|XtPointer
name|callback_private
decl_stmt|;
comment|/* list of callback offsets         */
name|String
name|rect10
decl_stmt|;
comment|/* NULL                             */
name|XtGeometryHandler
name|query_geometry
decl_stmt|;
comment|/* return preferred geometry        */
name|XtProc
name|rect11
decl_stmt|;
comment|/* NULL                             */
name|XtPointer
name|extension
decl_stmt|;
comment|/* pointer to extension record      */
block|}
name|RectObjClassPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_RectObjClassRec
block|{
name|RectObjClassPart
name|rect_class
decl_stmt|;
block|}
name|RectObjClassRec
typedef|;
end_typedef

begin_decl_stmt
name|externalref
name|RectObjClassRec
name|rectObjClassRec
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_Xt_RectObjP_h_*/
end_comment

end_unit

