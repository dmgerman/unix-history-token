begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * $XConsortium: CoreP.h,v 1.16 89/10/04 12:22:50 swick Exp $ * $oHeader: CoreP.h,v 1.2 88/08/18 15:54:37 asente Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XtCoreP_h
end_ifndef

begin_define
define|#
directive|define
name|XtCoreP_h
end_define

begin_include
include|#
directive|include
file|<X11/Core.h>
end_include

begin_decl_stmt
name|externalref
name|int
name|_XtInheritTranslations
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|XtInheritTranslations
value|((String)&_XtInheritTranslations)
end_define

begin_define
define|#
directive|define
name|XtInheritRealize
value|((XtRealizeProc) _XtInherit)
end_define

begin_define
define|#
directive|define
name|XtInheritResize
value|((XtWidgetProc) _XtInherit)
end_define

begin_define
define|#
directive|define
name|XtInheritExpose
value|((XtExposeProc) _XtInherit)
end_define

begin_define
define|#
directive|define
name|XtInheritSetValuesAlmost
value|((XtAlmostProc) _XtInherit)
end_define

begin_define
define|#
directive|define
name|XtInheritAcceptFocus
value|((XtAcceptFocusProc) _XtInherit)
end_define

begin_define
define|#
directive|define
name|XtInheritQueryGeometry
value|((XtGeometryHandler) _XtInherit)
end_define

begin_define
define|#
directive|define
name|XtInheritDisplayAccelerator
value|((XtStringProc) _XtInherit)
end_define

begin_comment
comment|/***************************************************************  * Widget Core Data Structures  *  *  **************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CorePart
block|{
name|Widget
name|self
decl_stmt|;
comment|/* pointer to widget itself	     */
name|WidgetClass
name|widget_class
decl_stmt|;
comment|/* pointer to Widget's ClassRec	     */
name|Widget
name|parent
decl_stmt|;
comment|/* parent widget	  	     */
name|XrmName
name|xrm_name
decl_stmt|;
comment|/* widget resource name quarkified   */
name|Boolean
name|being_destroyed
decl_stmt|;
comment|/* marked for destroy		     */
name|XtCallbackList
name|destroy_callbacks
decl_stmt|;
comment|/* who to call when widget destroyed */
name|XtPointer
name|constraints
decl_stmt|;
comment|/* constraint record                 */
name|Position
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* window position		     */
name|Dimension
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|/* window dimensions		     */
name|Dimension
name|border_width
decl_stmt|;
comment|/* window border width		     */
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
name|XtEventTable
name|event_table
decl_stmt|;
comment|/* private to event dispatcher       */
name|XtTMRec
name|tm
decl_stmt|;
comment|/* translation management            */
name|XtTranslations
name|accelerators
decl_stmt|;
comment|/* accelerator translations          */
name|Pixel
name|border_pixel
decl_stmt|;
comment|/* window border pixel		     */
name|Pixmap
name|border_pixmap
decl_stmt|;
comment|/* window border pixmap or NULL      */
name|WidgetList
name|popup_list
decl_stmt|;
comment|/* list of popups                    */
name|Cardinal
name|num_popups
decl_stmt|;
comment|/* how many popups                   */
name|String
name|name
decl_stmt|;
comment|/* widget resource name		     */
name|Screen
modifier|*
name|screen
decl_stmt|;
comment|/* window's screen		     */
name|Colormap
name|colormap
decl_stmt|;
comment|/* colormap                          */
name|Window
name|window
decl_stmt|;
comment|/* window ID			     */
name|Cardinal
name|depth
decl_stmt|;
comment|/* number of planes in window        */
name|Pixel
name|background_pixel
decl_stmt|;
comment|/* window background pixel	     */
name|Pixmap
name|background_pixmap
decl_stmt|;
comment|/* window background pixmap or NULL  */
name|Boolean
name|visible
decl_stmt|;
comment|/* is window mapped and not occluded?*/
name|Boolean
name|mapped_when_managed
decl_stmt|;
comment|/* map window if it's managed?       */
block|}
name|CorePart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_WidgetRec
block|{
name|CorePart
name|core
decl_stmt|;
block|}
name|WidgetRec
operator|,
name|CoreRec
typedef|;
end_typedef

begin_comment
comment|/******************************************************************  *  * Core Class Structure. Widgets, regardless of their class, will have  * these fields.  All widgets of a given class will have the same values  * for these fields.  Widgets of a given class may also have additional  * common fields.  These additional fields are included in incremental  * class structures, such as CommandClass.  *  * The fields that are specific to this subclass, as opposed to fields that  * are part of the superclass, are called "subclass fields" below.  Many  * procedures are responsible only for the subclass fields, and not for  * any superclass fields.  *  ********************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CoreClassPart
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
comment|/* class initialization proc	    */
name|XtWidgetClassProc
name|class_part_initialize
decl_stmt|;
comment|/* dynamic initialization	    */
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
name|XtRealizeProc
name|realize
decl_stmt|;
comment|/* XCreateWindow for widget	    */
name|XtActionList
name|actions
decl_stmt|;
comment|/* widget semantics name to proc map */
name|Cardinal
name|num_actions
decl_stmt|;
comment|/* number of entries in actions     */
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
comment|/* resource class quarkified	    */
name|Boolean
name|compress_motion
decl_stmt|;
comment|/* compress MotionNotify for widget */
name|XtEnum
name|compress_exposure
decl_stmt|;
comment|/* compress Expose events for widget*/
name|Boolean
name|compress_enterleave
decl_stmt|;
comment|/* compress enter and leave events  */
name|Boolean
name|visible_interest
decl_stmt|;
comment|/* select for VisibilityNotify      */
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
comment|/* rediplay window		    */
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
comment|/* set_values got "Almost" geo reply */
name|XtArgsProc
name|get_values_hook
decl_stmt|;
comment|/* notify that get_values called    */
name|XtAcceptFocusProc
name|accept_focus
decl_stmt|;
comment|/* assign input focus to widget     */
name|XtVersionType
name|version
decl_stmt|;
comment|/* version of intrinsics used	    */
name|XtPointer
name|callback_private
decl_stmt|;
comment|/* list of callback offsets       */
name|String
name|tm_table
decl_stmt|;
comment|/* state machine                    */
name|XtGeometryHandler
name|query_geometry
decl_stmt|;
comment|/* return preferred geometry        */
name|XtStringProc
name|display_accelerator
decl_stmt|;
comment|/* display your accelerator	    */
name|XtPointer
name|extension
decl_stmt|;
comment|/* pointer to extension record      */
block|}
name|CoreClassPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_WidgetClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
block|}
name|WidgetClassRec
operator|,
name|CoreClassRec
typedef|;
end_typedef

begin_decl_stmt
name|externalref
name|WidgetClassRec
name|widgetClassRec
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|coreClassRec
value|widgetClassRec
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XtCoreP_h */
end_comment

begin_comment
comment|/* DON'T ADD STUFF AFTER THIS #endif */
end_comment

end_unit

