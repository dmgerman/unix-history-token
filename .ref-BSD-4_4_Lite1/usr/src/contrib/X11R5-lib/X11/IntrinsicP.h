begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: IntrinsicP.h,v 1.57 91/06/26 19:33:20 converse Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XtintrinsicP_h
end_ifndef

begin_define
define|#
directive|define
name|_XtintrinsicP_h
end_define

begin_include
include|#
directive|include
file|<X11/Intrinsic.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|XrmQuark
name|xrm_name
decl_stmt|;
comment|/* Resource name quark		*/
name|XrmQuark
name|xrm_class
decl_stmt|;
comment|/* Resource class quark		*/
name|XrmQuark
name|xrm_type
decl_stmt|;
comment|/* Resource representation type quark */
name|Cardinal
name|xrm_size
decl_stmt|;
comment|/* Size in bytes of representation	*/
name|long
name|int
name|xrm_offset
decl_stmt|;
comment|/* -offset-1				*/
name|XrmQuark
name|xrm_default_type
decl_stmt|;
comment|/* Default representation type quark	*/
name|XtPointer
name|xrm_default_addr
decl_stmt|;
comment|/* Default resource address		*/
block|}
name|XrmResource
operator|,
typedef|*
name|XrmResourceList
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|XtVersionType
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XT_VERSION
value|11
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|XT_REVISION
end_ifndef

begin_define
define|#
directive|define
name|XT_REVISION
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XtVersion
value|(XT_VERSION * 1000 + XT_REVISION)
end_define

begin_define
define|#
directive|define
name|XtVersionDontCheck
value|0
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|XtProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|void
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|XtWidgetClassProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|WidgetClass
comment|/* class */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|XtWidgetProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|Boolean
function_decl|(
modifier|*
name|XtAcceptFocusProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|Time
modifier|*
comment|/* time */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|XtArgsProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|ArgList
comment|/* args */
parameter_list|,
name|Cardinal
modifier|*
comment|/* num_args */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|XtInitProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* request */
parameter_list|,
name|Widget
comment|/* new */
parameter_list|,
name|ArgList
comment|/* args */
parameter_list|,
name|Cardinal
modifier|*
comment|/* num_args */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|Boolean
function_decl|(
modifier|*
name|XtSetValuesFunc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* old */
parameter_list|,
name|Widget
comment|/* request */
parameter_list|,
name|Widget
comment|/* new */
parameter_list|,
name|ArgList
comment|/* args */
parameter_list|,
name|Cardinal
modifier|*
comment|/* num_args */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|Boolean
function_decl|(
modifier|*
name|XtArgsFunc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|ArgList
comment|/* args */
parameter_list|,
name|Cardinal
modifier|*
comment|/* num_args */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|XtAlmostProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* old */
parameter_list|,
name|Widget
comment|/* new */
parameter_list|,
name|XtWidgetGeometry
modifier|*
comment|/* request */
parameter_list|,
name|XtWidgetGeometry
modifier|*
comment|/* reply */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|XtExposeProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|XEvent
modifier|*
comment|/* event */
parameter_list|,
name|Region
comment|/* region */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* compress_exposure options*/
end_comment

begin_define
define|#
directive|define
name|XtExposeNoCompress
value|((XtEnum)False)
end_define

begin_define
define|#
directive|define
name|XtExposeCompressSeries
value|((XtEnum)True)
end_define

begin_define
define|#
directive|define
name|XtExposeCompressMultiple
value|2
end_define

begin_define
define|#
directive|define
name|XtExposeCompressMaximal
value|3
end_define

begin_comment
comment|/* modifiers */
end_comment

begin_define
define|#
directive|define
name|XtExposeGraphicsExpose
value|0x10
end_define

begin_define
define|#
directive|define
name|XtExposeGraphicsExposeMerged
value|0x20
end_define

begin_define
define|#
directive|define
name|XtExposeNoExpose
value|0x40
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|XtRealizeProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|XtValueMask
modifier|*
comment|/* mask */
parameter_list|,
name|XSetWindowAttributes
modifier|*
comment|/* attributes */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|XtGeometryResult
function_decl|(
modifier|*
name|XtGeometryHandler
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|XtWidgetGeometry
modifier|*
comment|/* request */
parameter_list|,
name|XtWidgetGeometry
modifier|*
comment|/* reply */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|XtStringProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|String
comment|/* str */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_XtTMRec
block|{
name|XtTranslations
name|translations
decl_stmt|;
comment|/* private to Translation Manager    */
name|XtBoundActions
name|proc_table
decl_stmt|;
comment|/* procedure bindings for actions    */
name|struct
name|_XtStateRec
modifier|*
name|current_state
decl_stmt|;
comment|/* Translation Manager state ptr     */
name|unsigned
name|long
name|lastEventTime
decl_stmt|;
block|}
name|XtTMRec
operator|,
typedef|*
name|XtTM
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<X11/CoreP.h>
end_include

begin_include
include|#
directive|include
file|<X11/CompositeP.h>
end_include

begin_include
include|#
directive|include
file|<X11/ConstrainP.h>
end_include

begin_include
include|#
directive|include
file|<X11/ObjectP.h>
end_include

begin_include
include|#
directive|include
file|<X11/RectObjP.h>
end_include

begin_define
define|#
directive|define
name|XtDisplay
parameter_list|(
name|widget
parameter_list|)
value|DisplayOfScreen((widget)->core.screen)
end_define

begin_define
define|#
directive|define
name|XtScreen
parameter_list|(
name|widget
parameter_list|)
value|((widget)->core.screen)
end_define

begin_define
define|#
directive|define
name|XtWindow
parameter_list|(
name|widget
parameter_list|)
value|((widget)->core.window)
end_define

begin_define
define|#
directive|define
name|XtClass
parameter_list|(
name|widget
parameter_list|)
value|((widget)->core.widget_class)
end_define

begin_define
define|#
directive|define
name|XtSuperclass
parameter_list|(
name|widget
parameter_list|)
value|(XtClass(widget)->core_class.superclass)
end_define

begin_define
define|#
directive|define
name|XtIsRealized
parameter_list|(
name|object
parameter_list|)
value|(XtWindowOfObject(object) != None)
end_define

begin_define
define|#
directive|define
name|XtParent
parameter_list|(
name|widget
parameter_list|)
value|((widget)->core.parent)
end_define

begin_undef
undef|#
directive|undef
name|XtIsRectObj
end_undef

begin_define
define|#
directive|define
name|XtIsRectObj
parameter_list|(
name|obj
parameter_list|)
define|\
value|(((Object)(obj))->object.widget_class->core_class.class_inited& 0x02)
end_define

begin_undef
undef|#
directive|undef
name|XtIsWidget
end_undef

begin_define
define|#
directive|define
name|XtIsWidget
parameter_list|(
name|obj
parameter_list|)
define|\
value|(((Object)(obj))->object.widget_class->core_class.class_inited& 0x04)
end_define

begin_undef
undef|#
directive|undef
name|XtIsComposite
end_undef

begin_define
define|#
directive|define
name|XtIsComposite
parameter_list|(
name|obj
parameter_list|)
define|\
value|(((Object)(obj))->object.widget_class->core_class.class_inited& 0x08)
end_define

begin_undef
undef|#
directive|undef
name|XtIsConstraint
end_undef

begin_define
define|#
directive|define
name|XtIsConstraint
parameter_list|(
name|obj
parameter_list|)
define|\
value|(((Object)(obj))->object.widget_class->core_class.class_inited& 0x10)
end_define

begin_undef
undef|#
directive|undef
name|XtIsShell
end_undef

begin_define
define|#
directive|define
name|XtIsShell
parameter_list|(
name|obj
parameter_list|)
define|\
value|(((Object)(obj))->object.widget_class->core_class.class_inited& 0x20)
end_define

begin_undef
undef|#
directive|undef
name|XtIsWMShell
end_undef

begin_define
define|#
directive|define
name|XtIsWMShell
parameter_list|(
name|obj
parameter_list|)
define|\
value|(((Object)(obj))->object.widget_class->core_class.class_inited& 0x40)
end_define

begin_undef
undef|#
directive|undef
name|XtIsTopLevelShell
end_undef

begin_define
define|#
directive|define
name|XtIsTopLevelShell
parameter_list|(
name|obj
parameter_list|)
define|\
value|(((Object)(obj))->object.widget_class->core_class.class_inited& 0x80)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|XtCheckSubclass
parameter_list|(
name|w
parameter_list|,
name|widget_class_ptr
parameter_list|,
name|message
parameter_list|)
define|\
value|if (!XtIsSubclass(((Widget)(w)), (widget_class_ptr))) {	\ 	    String params[3];				\ 	    Cardinal num_params = 3;			\ 	    params[0] = ((Widget)(w))->core.widget_class->core_class.class_name;\ 	    params[1] = (widget_class_ptr)->core_class.class_name;	     \ 	    params[2] = (message);					     \ 	    XtAppErrorMsg(XtWidgetToApplicationContext((Widget)(w)),	     \ 		    "subclassMismatch", "xtCheckSubclass", "XtToolkitError", \ 		    "Widget class %s found when subclass of %s expected: %s",\ 		    params,&num_params);		\ 	}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XtCheckSubclass
parameter_list|(
name|w
parameter_list|,
name|widget_class
parameter_list|,
name|message
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|_XFUNCPROTOBEGIN
specifier|extern
name|Widget
name|_XtWindowedAncestor
parameter_list|(
comment|/* internal; implementation-dependent */
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* object */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_XtInherit
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|void
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtCreateWindow
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|unsigned
name|int
comment|/* window_class */
parameter_list|,
name|Visual
modifier|*
comment|/* visual */
parameter_list|,
name|XtValueMask
comment|/* value_mask */
parameter_list|,
name|XSetWindowAttributes
modifier|*
comment|/* attributes */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtResizeWidget
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|_XtDimension
comment|/* width */
parameter_list|,
name|_XtDimension
comment|/* height */
parameter_list|,
name|_XtDimension
comment|/* border_width */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtMoveWidget
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|_XtPosition
comment|/* x */
parameter_list|,
name|_XtPosition
comment|/* y */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtConfigureWidget
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|_XtPosition
comment|/* x */
parameter_list|,
name|_XtPosition
comment|/* y */
parameter_list|,
name|_XtDimension
comment|/* width */
parameter_list|,
name|_XtDimension
comment|/* height */
parameter_list|,
name|_XtDimension
comment|/* border_width */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtResizeWindow
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|_XFUNCPROTOEND
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XtIntrinsicP_h */
end_comment

begin_comment
comment|/* DON'T ADD STUFF AFTER THIS #endif */
end_comment

end_unit

