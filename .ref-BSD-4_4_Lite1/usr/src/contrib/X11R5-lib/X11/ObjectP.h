begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: ObjectP.h,v 1.10 89/10/04 12:22:44 swick Exp $ */
end_comment

begin_comment
comment|/* $oHeader: ObjectP.h,v 1.2 88/08/18 15:55:35 asente Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_Xt_ObjectP_h_
end_ifndef

begin_define
define|#
directive|define
name|_Xt_ObjectP_h_
end_define

begin_include
include|#
directive|include
file|<X11/Object.h>
end_include

begin_comment
comment|/**********************************************************  * Object Instance Data Structures  *  **********************************************************/
end_comment

begin_comment
comment|/* these fields match CorePart and can not be changed */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ObjectPart
block|{
name|Widget
name|self
decl_stmt|;
comment|/* pointer to widget itself          */
name|WidgetClass
name|widget_class
decl_stmt|;
comment|/* pointer to Widget's ClassRec      */
name|Widget
name|parent
decl_stmt|;
comment|/* parent widget                     */
name|XrmName
name|xrm_name
decl_stmt|;
comment|/* widget resource name quarkified   */
name|Boolean
name|being_destroyed
decl_stmt|;
comment|/* marked for destroy                */
name|XtCallbackList
name|destroy_callbacks
decl_stmt|;
comment|/* who to call when widget destroyed */
name|XtPointer
name|constraints
decl_stmt|;
comment|/* constraint record                 */
block|}
name|ObjectPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ObjectRec
block|{
name|ObjectPart
name|object
decl_stmt|;
block|}
name|ObjectRec
typedef|;
end_typedef

begin_comment
comment|/********************************************************  * Object Class Data Structures  *  ********************************************************/
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
name|_ObjectClassPart
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
name|obj1
decl_stmt|;
comment|/* NULL                             */
name|XtProc
name|obj2
decl_stmt|;
comment|/* NULL                             */
name|Cardinal
name|obj3
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
name|obj4
decl_stmt|;
comment|/* NULL                             */
name|Boolean
name|obj5
decl_stmt|;
comment|/* NULL                             */
name|Boolean
name|obj6
decl_stmt|;
comment|/* NULL				    */
name|Boolean
name|obj7
decl_stmt|;
comment|/* NULL                             */
name|XtWidgetProc
name|destroy
decl_stmt|;
comment|/* free data for subclass pointers  */
name|XtProc
name|obj8
decl_stmt|;
comment|/* NULL                             */
name|XtProc
name|obj9
decl_stmt|;
comment|/* NULL			            */
name|XtSetValuesFunc
name|set_values
decl_stmt|;
comment|/* set subclass resource values     */
name|XtArgsFunc
name|set_values_hook
decl_stmt|;
comment|/* notify that set_values called    */
name|XtProc
name|obj10
decl_stmt|;
comment|/* NULL                             */
name|XtArgsProc
name|get_values_hook
decl_stmt|;
comment|/* notify that get_values called    */
name|XtProc
name|obj11
decl_stmt|;
comment|/* NULL                             */
name|XtVersionType
name|version
decl_stmt|;
comment|/* version of intrinsics used       */
name|XtPointer
name|callback_private
decl_stmt|;
comment|/* list of callback offsets       */
name|String
name|obj12
decl_stmt|;
comment|/* NULL                             */
name|XtProc
name|obj13
decl_stmt|;
comment|/* NULL                             */
name|XtProc
name|obj14
decl_stmt|;
comment|/* NULL                             */
name|XtPointer
name|extension
decl_stmt|;
comment|/* pointer to extension record      */
block|}
name|ObjectClassPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ObjectClassRec
block|{
name|ObjectClassPart
name|object_class
decl_stmt|;
block|}
name|ObjectClassRec
typedef|;
end_typedef

begin_decl_stmt
name|externalref
name|ObjectClassRec
name|objectClassRec
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_Xt_ObjectP_h_*/
end_comment

end_unit

