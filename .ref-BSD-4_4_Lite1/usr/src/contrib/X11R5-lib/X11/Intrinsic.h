begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Intrinsic.h,v 1.174 91/09/09 16:25:56 converse Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.  			All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XtIntrinsic_h
end_ifndef

begin_define
define|#
directive|define
name|_XtIntrinsic_h
end_define

begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xutil.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xresource.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|XT_BC
end_ifdef

begin_include
include|#
directive|include
file|<X11/Xos.h>
end_include

begin_comment
comment|/* for R4 compatibility */
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<X11/Xosdefs.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|X_NOT_STDC_ENV
end_ifndef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/* for XtNewString */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSV else */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !X_NOT_STDC_ENV else */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XT_BC else */
end_comment

begin_define
define|#
directive|define
name|XtSpecificationRelease
value|5
end_define

begin_typedef
typedef|typedef
name|char
modifier|*
name|String
typedef|;
end_typedef

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_comment
comment|/* We do this in order to get "const" declarations to work right.  We  * use _XtString instead of String so that C++ applications can  * #define String to something else if they choose, to avoid conflicts  * with other C++ libraries.  */
end_comment

begin_define
define|#
directive|define
name|_XtString
value|char*
end_define

begin_comment
comment|/* _Xt names are private to Xt implementation, do not use in client code */
end_comment

begin_if
if|#
directive|if
name|NeedWidePrototypes
end_if

begin_define
define|#
directive|define
name|_XtBoolean
value|int
end_define

begin_define
define|#
directive|define
name|_XtDimension
value|unsigned int
end_define

begin_define
define|#
directive|define
name|_XtKeyCode
value|unsigned int
end_define

begin_define
define|#
directive|define
name|_XtPosition
value|int
end_define

begin_define
define|#
directive|define
name|_XtXtEnum
value|unsigned int
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_XtBoolean
value|Boolean
end_define

begin_define
define|#
directive|define
name|_XtDimension
value|Dimension
end_define

begin_define
define|#
directive|define
name|_XtKeyCode
value|KeyCode
end_define

begin_define
define|#
directive|define
name|_XtPosition
value|Position
end_define

begin_define
define|#
directive|define
name|_XtXtEnum
value|XtEnum
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NeedWidePrototypes */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NeedFunctionPrototypes */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_define
define|#
directive|define
name|externalref
value|globalref
end_define

begin_define
define|#
directive|define
name|externaldef
parameter_list|(
name|psect
parameter_list|)
value|globaldef {"psect"} noshare
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|externalref
value|extern
end_define

begin_define
define|#
directive|define
name|externaldef
parameter_list|(
name|psect
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XtNumber
parameter_list|(
name|arr
parameter_list|)
value|((Cardinal) (sizeof(arr) / sizeof(arr[0])))
end_define

begin_typedef
typedef|typedef
name|struct
name|_WidgetRec
modifier|*
name|Widget
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Widget
modifier|*
name|WidgetList
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_WidgetClassRec
modifier|*
name|WidgetClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_CompositeRec
modifier|*
name|CompositeWidget
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_XtActionsRec
modifier|*
name|XtActionList
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_XtEventRec
modifier|*
name|XtEventTable
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_XtBoundAccActionRec
modifier|*
name|XtBoundAccActions
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_XtAppStruct
modifier|*
name|XtAppContext
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|XtValueMask
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|XtIntervalId
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|XtInputId
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|XtWorkProcId
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|XtGeometryMask
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|XtGCMask
typedef|;
end_typedef

begin_comment
comment|/* Mask of values that are used by widget*/
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|Pixel
typedef|;
end_typedef

begin_comment
comment|/* Index into colormap		*/
end_comment

begin_typedef
typedef|typedef
name|int
name|XtCacheType
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XtCacheNone
value|0x001
end_define

begin_define
define|#
directive|define
name|XtCacheAll
value|0x002
end_define

begin_define
define|#
directive|define
name|XtCacheByDisplay
value|0x003
end_define

begin_define
define|#
directive|define
name|XtCacheRefCount
value|0x100
end_define

begin_comment
comment|/****************************************************************  *  * System Dependent Definitions; see spec for specific range  * requirements.  Do not assume every implementation uses the  * same base types!  *  *  * XtArgVal ought to be a union of XtPointer, char *, long, int *, and proc *  * but casting to union types is not really supported.  *  * So the typedef for XtArgVal should be chosen such that  *  *	sizeof (XtArgVal)>=	sizeof(XtPointer)  *				sizeof(char *)  *				sizeof(long)  *				sizeof(int *)  *				sizeof(proc *)  *  * ArgLists rely heavily on the above typedef.  *  ****************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CRAY
end_ifdef

begin_typedef
typedef|typedef
name|long
name|Boolean
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|XtArgVal
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|XtEnum
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
name|Boolean
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|XtArgVal
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|XtEnum
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|int
name|Cardinal
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|Dimension
typedef|;
end_typedef

begin_comment
comment|/* Size in pixels			*/
end_comment

begin_typedef
typedef|typedef
name|short
name|Position
typedef|;
end_typedef

begin_comment
comment|/* Offset from 0 coordinate		*/
end_comment

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_typedef
typedef|typedef
name|void
modifier|*
name|XtPointer
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
modifier|*
name|XtPointer
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The type Opaque is NOT part of the Xt standard, do NOT use it. */
end_comment

begin_comment
comment|/* (It remains here only for backward compatibility.) */
end_comment

begin_typedef
typedef|typedef
name|XtPointer
name|Opaque
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<X11/Core.h>
end_include

begin_include
include|#
directive|include
file|<X11/Composite.h>
end_include

begin_include
include|#
directive|include
file|<X11/Constraint.h>
end_include

begin_include
include|#
directive|include
file|<X11/Object.h>
end_include

begin_include
include|#
directive|include
file|<X11/RectObj.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|_TranslationData
modifier|*
name|XtTranslations
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_TranslationData
modifier|*
name|XtAccelerators
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|Modifiers
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|XtActionProc
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
name|String
modifier|*
comment|/* params */
parameter_list|,
name|Cardinal
modifier|*
comment|/* num_params */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|XtActionProc
modifier|*
name|XtBoundActions
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_XtActionsRec
block|{
name|String
name|string
decl_stmt|;
name|XtActionProc
name|proc
decl_stmt|;
block|}
name|XtActionsRec
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* address mode		parameter representation    */
comment|/* ------------		------------------------    */
name|XtAddress
block|,
comment|/* address		    */
name|XtBaseOffset
block|,
comment|/* offset		    */
name|XtImmediate
block|,
comment|/* constant		    */
name|XtResourceString
block|,
comment|/* resource name string	    */
name|XtResourceQuark
block|,
comment|/* resource name quark	    */
name|XtWidgetBaseOffset
block|,
comment|/* offset from ancestor	    */
name|XtProcedureArg
comment|/* procedure to invoke	    */
block|}
name|XtAddressMode
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|XtAddressMode
name|address_mode
decl_stmt|;
name|XtPointer
name|address_id
decl_stmt|;
name|Cardinal
name|size
decl_stmt|;
block|}
name|XtConvertArgRec
operator|,
typedef|*
name|XtConvertArgList
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|XtConvertArgProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|Cardinal
modifier|*
comment|/* size */
parameter_list|,
name|XrmValue
modifier|*
comment|/* value */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|XtGeometryMask
name|request_mode
decl_stmt|;
name|Position
name|x
decl_stmt|,
name|y
decl_stmt|;
name|Dimension
name|width
decl_stmt|,
name|height
decl_stmt|,
name|border_width
decl_stmt|;
name|Widget
name|sibling
decl_stmt|;
name|int
name|stack_mode
decl_stmt|;
comment|/* Above, Below, TopIf, BottomIf, Opposite, DontChange */
block|}
name|XtWidgetGeometry
typedef|;
end_typedef

begin_comment
comment|/* Additions to Xlib geometry requests: ask what would happen, don't do it */
end_comment

begin_define
define|#
directive|define
name|XtCWQueryOnly
value|(1<< 7)
end_define

begin_comment
comment|/* Additions to Xlib stack modes: don't change stack order */
end_comment

begin_define
define|#
directive|define
name|XtSMDontChange
value|5
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|XtConverter
function_decl|)
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|XrmValue
modifier|*
comment|/* args */
parameter_list|,
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValue
modifier|*
comment|/* from */
parameter_list|,
name|XrmValue
modifier|*
comment|/* to */
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
name|XtTypeConverter
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValue
modifier|*
comment|/* args */
parameter_list|,
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValue
modifier|*
comment|/* from */
parameter_list|,
name|XrmValue
modifier|*
comment|/* to */
parameter_list|,
name|XtPointer
modifier|*
comment|/* converter_data */
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
name|XtDestructor
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app */
parameter_list|,
name|XrmValue
modifier|*
comment|/* to */
parameter_list|,
name|XtPointer
comment|/* converter_data */
parameter_list|,
name|XrmValue
modifier|*
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
name|Opaque
name|XtCacheRef
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Opaque
name|XtActionHookId
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|XtActionHookProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|XtPointer
comment|/* client_data */
parameter_list|,
name|String
comment|/* action_name */
parameter_list|,
name|XEvent
modifier|*
comment|/* event */
parameter_list|,
name|String
modifier|*
comment|/* params */
parameter_list|,
name|Cardinal
modifier|*
comment|/* num_params */
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
name|XtKeyProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|_XtKeyCode
comment|/* keycode */
parameter_list|,
name|Modifiers
comment|/* modifiers */
parameter_list|,
name|Modifiers
modifier|*
comment|/* modifiers_return */
parameter_list|,
name|KeySym
modifier|*
comment|/* keysym_return */
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
name|XtCaseProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|KeySym
comment|/* keysym */
parameter_list|,
name|KeySym
modifier|*
comment|/* lower_return */
parameter_list|,
name|KeySym
modifier|*
comment|/* upper_return */
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
name|XtEventHandler
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|XtPointer
comment|/* closure */
parameter_list|,
name|XEvent
modifier|*
comment|/* event */
parameter_list|,
name|Boolean
modifier|*
comment|/* continue_to_dispatch */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|EventMask
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XtListHead
block|,
name|XtListTail
block|}
name|XtListPosition
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|XtInputMask
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XtInputNoneMask
value|0L
end_define

begin_define
define|#
directive|define
name|XtInputReadMask
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|XtInputWriteMask
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|XtInputExceptMask
value|(1L<<2)
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|XtTimerCallbackProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtPointer
comment|/* closure */
parameter_list|,
name|XtIntervalId
modifier|*
comment|/* id */
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
name|XtInputCallbackProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtPointer
comment|/* closure */
parameter_list|,
name|int
modifier|*
comment|/* source */
parameter_list|,
name|XtInputId
modifier|*
comment|/* id */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|String
name|name
decl_stmt|;
name|XtArgVal
name|value
decl_stmt|;
block|}
name|Arg
operator|,
typedef|*
name|ArgList
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XtPointer
name|XtVarArgsList
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|XtCallbackProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|XtPointer
comment|/* closure */
parameter_list|,
comment|/* data the application registered */
name|XtPointer
comment|/* call_data */
comment|/* callback specific data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_XtCallbackRec
block|{
name|XtCallbackProc
name|callback
decl_stmt|;
name|XtPointer
name|closure
decl_stmt|;
block|}
name|XtCallbackRec
operator|,
typedef|*
name|XtCallbackList
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XtCallbackNoList
block|,
name|XtCallbackHasNone
block|,
name|XtCallbackHasSome
block|}
name|XtCallbackStatus
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XtGeometryYes
block|,
comment|/* Request accepted. */
name|XtGeometryNo
block|,
comment|/* Request denied. */
name|XtGeometryAlmost
block|,
comment|/* Request denied, but willing to take replyBox. */
name|XtGeometryDone
comment|/* Request accepted and done. */
block|}
name|XtGeometryResult
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XtGrabNone
block|,
name|XtGrabNonexclusive
block|,
name|XtGrabExclusive
block|}
name|XtGrabKind
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Widget
name|shell_widget
decl_stmt|;
name|Widget
name|enable_widget
decl_stmt|;
block|}
name|XtPopdownIDRec
operator|,
typedef|*
name|XtPopdownID
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_XtResource
block|{
name|String
name|resource_name
decl_stmt|;
comment|/* Resource name			    */
name|String
name|resource_class
decl_stmt|;
comment|/* Resource class			    */
name|String
name|resource_type
decl_stmt|;
comment|/* Representation type desired		    */
name|Cardinal
name|resource_size
decl_stmt|;
comment|/* Size in bytes of representation	    */
name|Cardinal
name|resource_offset
decl_stmt|;
comment|/* Offset from base to put resource value   */
name|String
name|default_type
decl_stmt|;
comment|/* representation type of specified default */
name|XtPointer
name|default_addr
decl_stmt|;
comment|/* Address of default resource		    */
block|}
name|XtResource
operator|,
typedef|*
name|XtResourceList
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|XtResourceDefaultProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|int
comment|/* offset */
parameter_list|,
name|XrmValue
modifier|*
comment|/* value */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|String
function_decl|(
modifier|*
name|XtLanguageProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|String
comment|/* xnl */
parameter_list|,
name|XtPointer
comment|/* client_data */
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
name|XtErrorMsgHandler
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|String
comment|/* name */
parameter_list|,
name|String
comment|/* type */
parameter_list|,
name|String
comment|/* class */
parameter_list|,
name|String
comment|/* default */
parameter_list|,
name|String
modifier|*
comment|/* params */
parameter_list|,
name|Cardinal
modifier|*
comment|/* num_params */
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
name|XtErrorHandler
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|String
comment|/* msg */
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
name|XtCreatePopupChildProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* shell */
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
name|XtWorkProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtPointer
comment|/* closure */
comment|/* data the application registered */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|match
decl_stmt|;
name|String
name|substitution
decl_stmt|;
block|}
name|SubstitutionRec
operator|,
typedef|*
name|Substitution
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Boolean
function_decl|(
modifier|*
name|XtFilePredicate
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|String
comment|/* filename */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|XtPointer
name|XtRequestId
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Boolean
function_decl|(
modifier|*
name|XtConvertSelectionProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|Atom
modifier|*
comment|/* selection */
parameter_list|,
name|Atom
modifier|*
comment|/* target */
parameter_list|,
name|Atom
modifier|*
comment|/* type_return */
parameter_list|,
name|XtPointer
modifier|*
comment|/* value_return */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* length_return */
parameter_list|,
name|int
modifier|*
comment|/* format_return */
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
name|XtLoseSelectionProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|Atom
modifier|*
comment|/* selection */
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
name|XtSelectionDoneProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|Atom
modifier|*
comment|/* selection */
parameter_list|,
name|Atom
modifier|*
comment|/* target */
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
name|XtSelectionCallbackProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|XtPointer
comment|/* closure */
parameter_list|,
name|Atom
modifier|*
comment|/* selection */
parameter_list|,
name|Atom
modifier|*
comment|/* type */
parameter_list|,
name|XtPointer
comment|/* value */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* length */
parameter_list|,
name|int
modifier|*
comment|/* format */
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
name|XtLoseSelectionIncrProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|Atom
modifier|*
comment|/* selection */
parameter_list|,
name|XtPointer
comment|/* client_data */
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
name|XtSelectionDoneIncrProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|Atom
modifier|*
comment|/* selection */
parameter_list|,
name|Atom
modifier|*
comment|/* target */
parameter_list|,
name|XtRequestId
modifier|*
comment|/* receiver_id */
parameter_list|,
name|XtPointer
comment|/* client_data */
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
name|XtConvertSelectionIncrProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|Atom
modifier|*
comment|/* selection */
parameter_list|,
name|Atom
modifier|*
comment|/* target */
parameter_list|,
name|Atom
modifier|*
comment|/* type */
parameter_list|,
name|XtPointer
modifier|*
comment|/* value */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* length */
parameter_list|,
name|int
modifier|*
comment|/* format */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* max_length */
parameter_list|,
name|XtPointer
comment|/* client_data */
parameter_list|,
name|XtRequestId
modifier|*
comment|/* receiver_id */
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
name|XtCancelConvertSelectionProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|Atom
modifier|*
comment|/* selection */
parameter_list|,
name|Atom
modifier|*
comment|/* target */
parameter_list|,
name|XtRequestId
modifier|*
comment|/* receiver_id */
parameter_list|,
name|XtPointer
comment|/* client_data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/***************************************************************  *  * Exported Interfaces  *  ****************************************************************/
end_comment

begin_function_decl
name|_XFUNCPROTOBEGIN
specifier|extern
name|Boolean
name|XtConvertAndStore
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* from_type */
parameter_list|,
name|XrmValue
modifier|*
comment|/* from */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* to_type */
parameter_list|,
name|XrmValue
modifier|*
comment|/* to_in_out */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtCallConverter
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XtTypeConverter
comment|/* converter */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
name|Cardinal
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* from */
parameter_list|,
name|XrmValue
modifier|*
comment|/* to_in_out */
parameter_list|,
name|XtCacheRef
modifier|*
comment|/* cache_ref_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtDispatchEvent
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XEvent
modifier|*
comment|/* event */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtCallAcceptFocus
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
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtPeekEvent
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|XEvent
modifier|*
comment|/* event_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtAppPeekEvent
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|XEvent
modifier|*
comment|/* event_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtIsSubclass
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|WidgetClass
comment|/* widgetClass */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtIsObject
parameter_list|(
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
name|Boolean
name|_XtCheckSubclassFlag
parameter_list|(
comment|/* implementation-private */
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* object */
parameter_list|,
name|_XtXtEnum
comment|/* type_flag */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|_XtIsSubclassOf
parameter_list|(
comment|/* implementation-private */
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* object */
parameter_list|,
name|WidgetClass
comment|/* widget_class */
parameter_list|,
name|WidgetClass
comment|/* flag_class */
parameter_list|,
name|_XtXtEnum
comment|/* type_flag */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtIsManaged
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* rectobj */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtIsRealized
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

begin_function_decl
specifier|extern
name|Boolean
name|XtIsSensitive
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

begin_function_decl
specifier|extern
name|Boolean
name|XtOwnSelection
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|Atom
comment|/* selection */
parameter_list|,
name|Time
comment|/* time */
parameter_list|,
name|XtConvertSelectionProc
comment|/* convert */
parameter_list|,
name|XtLoseSelectionProc
comment|/* lose */
parameter_list|,
name|XtSelectionDoneProc
comment|/* done */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtOwnSelectionIncremental
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|Atom
comment|/* selection */
parameter_list|,
name|Time
comment|/* time */
parameter_list|,
name|XtConvertSelectionIncrProc
comment|/* convert_callback */
parameter_list|,
name|XtLoseSelectionIncrProc
comment|/* lose_callback */
parameter_list|,
name|XtSelectionDoneIncrProc
comment|/* done_callback */
parameter_list|,
name|XtCancelConvertSelectionProc
comment|/* cancel_callback */
parameter_list|,
name|XtPointer
comment|/* client_data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XtGeometryResult
name|XtMakeResizeRequest
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
name|Dimension
modifier|*
comment|/* width_return */
parameter_list|,
name|Dimension
modifier|*
comment|/* height_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtTranslateCoords
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
name|Position
modifier|*
comment|/* rootx_return */
parameter_list|,
name|Position
modifier|*
comment|/* rooty_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|KeySym
modifier|*
name|XtGetKeysymTable
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|KeyCode
modifier|*
comment|/* min_keycode_return */
parameter_list|,
name|int
modifier|*
comment|/* keysyms_per_keycode_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtKeysymToKeycodeList
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|KeySym
comment|/* keysym */
parameter_list|,
name|KeyCode
modifier|*
modifier|*
comment|/* keycodes_return */
parameter_list|,
name|Cardinal
modifier|*
comment|/* keycount_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtStringConversionWarning
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|_XtString
comment|/* from_value */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* to_type */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtDisplayStringConversionWarning
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* from_value */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* to_type */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_decl_stmt
name|externalref
name|XtConvertArgRec
specifier|const
name|colorConvertArgs
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|externalref
name|XtConvertArgRec
specifier|const
name|screenConvertArg
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|externalref
name|XtConvertArgRec
name|colorConvertArgs
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|externalref
name|XtConvertArgRec
name|screenConvertArg
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|XtAppAddConverter
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* from_type */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* to_type */
parameter_list|,
name|XtConverter
comment|/* converter */
parameter_list|,
name|XtConvertArgList
comment|/* convert_args */
parameter_list|,
name|Cardinal
comment|/* num_args */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtAddConverter
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|_XtString
comment|/* from_type */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* to_type */
parameter_list|,
name|XtConverter
comment|/* converter */
parameter_list|,
name|XtConvertArgList
comment|/* convert_args */
parameter_list|,
name|Cardinal
comment|/* num_args */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtSetTypeConverter
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|_XtString
comment|/* from_type */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* to_type */
parameter_list|,
name|XtTypeConverter
comment|/* converter */
parameter_list|,
name|XtConvertArgList
comment|/* convert_args */
parameter_list|,
name|Cardinal
comment|/* num_args */
parameter_list|,
name|XtCacheType
comment|/* cache_type */
parameter_list|,
name|XtDestructor
comment|/* destructor */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtAppSetTypeConverter
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* from_type */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* to_type */
parameter_list|,
name|XtTypeConverter
comment|/* converter */
parameter_list|,
name|XtConvertArgList
comment|/* convert_args */
parameter_list|,
name|Cardinal
comment|/* num_args */
parameter_list|,
name|XtCacheType
comment|/* cache_type */
parameter_list|,
name|XtDestructor
comment|/* destructor */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtConvert
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* from_type */
parameter_list|,
name|XrmValue
modifier|*
comment|/* from */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* to_type */
parameter_list|,
name|XrmValue
modifier|*
comment|/* to_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtDirectConvert
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|XtConverter
comment|/* converter */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
name|Cardinal
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* from */
parameter_list|,
name|XrmValue
modifier|*
comment|/* to_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****************************************************************  *  * Translation Management  *  ****************************************************************/
end_comment

begin_function_decl
specifier|extern
name|XtTranslations
name|XtParseTranslationTable
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|_XtString
comment|/* table */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XtAccelerators
name|XtParseAcceleratorTable
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|_XtString
comment|/* source */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtOverrideTranslations
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|XtTranslations
comment|/* translations */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtAugmentTranslations
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|XtTranslations
comment|/* translations */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtInstallAccelerators
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* destination */
parameter_list|,
name|Widget
comment|/* source */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtInstallAllAccelerators
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* destination */
parameter_list|,
name|Widget
comment|/* source */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtUninstallTranslations
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

begin_function_decl
specifier|extern
name|void
name|XtAppAddActions
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|XtActionList
comment|/* actions */
parameter_list|,
name|Cardinal
comment|/* num_actions */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtAddActions
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|XtActionList
comment|/* actions */
parameter_list|,
name|Cardinal
comment|/* num_actions */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XtActionHookId
name|XtAppAddActionHook
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|XtActionHookProc
comment|/* proc */
parameter_list|,
name|XtPointer
comment|/* client_data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtRemoveActionHook
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtActionHookId
comment|/* id */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtGetActionList
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|WidgetClass
comment|/* widget_class */
parameter_list|,
name|XtActionList
modifier|*
comment|/* actions_return */
parameter_list|,
name|Cardinal
modifier|*
comment|/* num_actions_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtCallActionProc
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* action */
parameter_list|,
name|XEvent
modifier|*
comment|/* event */
parameter_list|,
name|String
modifier|*
comment|/* params */
parameter_list|,
name|Cardinal
comment|/* num_params */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtRegisterGrabAction
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtActionProc
comment|/* action_proc */
parameter_list|,
name|_XtBoolean
comment|/* owner_events */
parameter_list|,
name|unsigned
name|int
comment|/* event_mask */
parameter_list|,
name|int
comment|/* pointer_mode */
parameter_list|,
name|int
comment|/* keyboard_mode */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtSetMultiClickTime
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|int
comment|/* milliseconds */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XtGetMultiClickTime
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|KeySym
name|XtGetActionKeysym
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XEvent
modifier|*
comment|/* event */
parameter_list|,
name|Modifiers
modifier|*
comment|/* modifiers_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/***************************************************************  *  * Keycode and Keysym procedures for translation management  *  ****************************************************************/
end_comment

begin_function_decl
specifier|extern
name|void
name|XtTranslateKeycode
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|_XtKeyCode
comment|/* keycode */
parameter_list|,
name|Modifiers
comment|/* modifiers */
parameter_list|,
name|Modifiers
modifier|*
comment|/* modifiers_return */
parameter_list|,
name|KeySym
modifier|*
comment|/* keysym_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtTranslateKey
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|_XtKeyCode
comment|/* keycode */
parameter_list|,
name|Modifiers
comment|/* modifiers */
parameter_list|,
name|Modifiers
modifier|*
comment|/* modifiers_return */
parameter_list|,
name|KeySym
modifier|*
comment|/* keysym_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtSetKeyTranslator
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XtKeyProc
comment|/* proc */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtRegisterCaseConverter
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XtCaseProc
comment|/* proc */
parameter_list|,
name|KeySym
comment|/* start */
parameter_list|,
name|KeySym
comment|/* stop */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtConvertCase
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|KeySym
comment|/* keysym */
parameter_list|,
name|KeySym
modifier|*
comment|/* lower_return */
parameter_list|,
name|KeySym
modifier|*
comment|/* upper_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****************************************************************  *  * Event Management  *  ****************************************************************/
end_comment

begin_comment
comment|/* XtAllEvents is valid only for XtRemoveEventHandler and  * XtRemoveRawEventHandler; don't use it to select events!  */
end_comment

begin_define
define|#
directive|define
name|XtAllEvents
value|((EventMask) -1L)
end_define

begin_function_decl
specifier|extern
name|void
name|XtAddEventHandler
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|EventMask
comment|/* event_mask */
parameter_list|,
name|_XtBoolean
comment|/* nonmaskable */
parameter_list|,
name|XtEventHandler
comment|/* proc */
parameter_list|,
name|XtPointer
comment|/* closure */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtRemoveEventHandler
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|EventMask
comment|/* event_mask */
parameter_list|,
name|_XtBoolean
comment|/* nonmaskable */
parameter_list|,
name|XtEventHandler
comment|/* proc */
parameter_list|,
name|XtPointer
comment|/* closure */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtAddRawEventHandler
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|EventMask
comment|/* event_mask */
parameter_list|,
name|_XtBoolean
comment|/* nonmaskable */
parameter_list|,
name|XtEventHandler
comment|/* proc */
parameter_list|,
name|XtPointer
comment|/* closure */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtRemoveRawEventHandler
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|EventMask
comment|/* event_mask */
parameter_list|,
name|_XtBoolean
comment|/* nonmaskable */
parameter_list|,
name|XtEventHandler
comment|/* proc */
parameter_list|,
name|XtPointer
comment|/* closure */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtInsertEventHandler
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|EventMask
comment|/* event_mask */
parameter_list|,
name|_XtBoolean
comment|/* nonmaskable */
parameter_list|,
name|XtEventHandler
comment|/* proc */
parameter_list|,
name|XtPointer
comment|/* closure */
parameter_list|,
name|XtListPosition
comment|/* position */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtInsertRawEventHandler
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|EventMask
comment|/* event_mask */
parameter_list|,
name|_XtBoolean
comment|/* nonmaskable */
parameter_list|,
name|XtEventHandler
comment|/* proc */
parameter_list|,
name|XtPointer
comment|/* closure */
parameter_list|,
name|XtListPosition
comment|/* position */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|EventMask
name|XtBuildEventMask
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

begin_function_decl
specifier|extern
name|void
name|XtAddGrab
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|_XtBoolean
comment|/* exclusive */
parameter_list|,
name|_XtBoolean
comment|/* spring_loaded */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtRemoveGrab
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

begin_function_decl
specifier|extern
name|void
name|XtProcessEvent
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|XtInputMask
comment|/* mask */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtAppProcessEvent
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|XtInputMask
comment|/* mask */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtMainLoop
parameter_list|(
comment|/* obsolete */
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
name|XtAppMainLoop
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtAddExposureToRegion
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
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
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtSetKeyboardFocus
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* subtree */
parameter_list|,
name|Widget
comment|/* descendent */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Time
name|XtLastTimestampProcessed
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****************************************************************  *  * Event Gathering Routines  *  ****************************************************************/
end_comment

begin_function_decl
specifier|extern
name|XtIntervalId
name|XtAddTimeOut
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|unsigned
name|long
comment|/* interval */
parameter_list|,
name|XtTimerCallbackProc
comment|/* proc */
parameter_list|,
name|XtPointer
comment|/* closure */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XtIntervalId
name|XtAppAddTimeOut
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|unsigned
name|long
comment|/* interval */
parameter_list|,
name|XtTimerCallbackProc
comment|/* proc */
parameter_list|,
name|XtPointer
comment|/* closure */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtRemoveTimeOut
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtIntervalId
comment|/* timer */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XtInputId
name|XtAddInput
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|int
comment|/* source */
parameter_list|,
name|XtPointer
comment|/* condition */
parameter_list|,
name|XtInputCallbackProc
comment|/* proc */
parameter_list|,
name|XtPointer
comment|/* closure */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XtInputId
name|XtAppAddInput
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|int
comment|/* source */
parameter_list|,
name|XtPointer
comment|/* condition */
parameter_list|,
name|XtInputCallbackProc
comment|/* proc */
parameter_list|,
name|XtPointer
comment|/* closure */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtRemoveInput
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtInputId
comment|/* id */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtNextEvent
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|XEvent
modifier|*
comment|/* event */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtAppNextEvent
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|XEvent
modifier|*
comment|/* event_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|XtIMXEvent
value|1
end_define

begin_define
define|#
directive|define
name|XtIMTimer
value|2
end_define

begin_define
define|#
directive|define
name|XtIMAlternateInput
value|4
end_define

begin_define
define|#
directive|define
name|XtIMAll
value|(XtIMXEvent | XtIMTimer | XtIMAlternateInput)
end_define

begin_function_decl
specifier|extern
name|XtInputMask
name|XtPending
parameter_list|(
comment|/* obsolete */
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
name|XtInputMask
name|XtAppPending
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****************************************************************  *  * Random utility routines  *  ****************************************************************/
end_comment

begin_define
define|#
directive|define
name|XtIsRectObj
parameter_list|(
name|object
parameter_list|)
value|(_XtCheckSubclassFlag(object, (XtEnum)0x02))
end_define

begin_define
define|#
directive|define
name|XtIsWidget
parameter_list|(
name|object
parameter_list|)
value|(_XtCheckSubclassFlag(object, (XtEnum)0x04))
end_define

begin_define
define|#
directive|define
name|XtIsComposite
parameter_list|(
name|widget
parameter_list|)
value|(_XtCheckSubclassFlag(widget, (XtEnum)0x08))
end_define

begin_define
define|#
directive|define
name|XtIsConstraint
parameter_list|(
name|widget
parameter_list|)
value|(_XtCheckSubclassFlag(widget, (XtEnum)0x10))
end_define

begin_define
define|#
directive|define
name|XtIsShell
parameter_list|(
name|widget
parameter_list|)
value|(_XtCheckSubclassFlag(widget, (XtEnum)0x20))
end_define

begin_define
define|#
directive|define
name|XtIsOverrideShell
parameter_list|(
name|widget
parameter_list|)
define|\
value|(_XtIsSubclassOf(widget, (WidgetClass)overrideShellWidgetClass, \ 		     (WidgetClass)shellWidgetClass, (XtEnum)0x20))
end_define

begin_define
define|#
directive|define
name|XtIsWMShell
parameter_list|(
name|widget
parameter_list|)
value|(_XtCheckSubclassFlag(widget, (XtEnum)0x40))
end_define

begin_define
define|#
directive|define
name|XtIsVendorShell
parameter_list|(
name|widget
parameter_list|)
define|\
value|(_XtIsSubclassOf(widget, (WidgetClass)vendorShellWidgetClass, \ 		     (WidgetClass)wmShellWidgetClass, (XtEnum)0x40))
end_define

begin_define
define|#
directive|define
name|XtIsTransientShell
parameter_list|(
name|widget
parameter_list|)
define|\
value|(_XtIsSubclassOf(widget, (WidgetClass)transientShellWidgetClass, \ 		     (WidgetClass)wmShellWidgetClass, (XtEnum)0x40))
end_define

begin_define
define|#
directive|define
name|XtIsTopLevelShell
parameter_list|(
name|widget
parameter_list|)
value|(_XtCheckSubclassFlag(widget, (XtEnum)0x80))
end_define

begin_define
define|#
directive|define
name|XtIsApplicationShell
parameter_list|(
name|widget
parameter_list|)
define|\
value|(_XtIsSubclassOf(widget, (WidgetClass)applicationShellWidgetClass, \ 		     (WidgetClass)topLevelShellWidgetClass, (XtEnum)0x80))
end_define

begin_function_decl
specifier|extern
name|void
name|XtRealizeWidget
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

begin_function_decl
name|void
name|XtUnrealizeWidget
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

begin_function_decl
specifier|extern
name|void
name|XtDestroyWidget
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

begin_function_decl
specifier|extern
name|void
name|XtSetSensitive
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|_XtBoolean
comment|/* sensitive */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtSetMappedWhenManaged
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|_XtBoolean
comment|/* mapped_when_managed */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Widget
name|XtNameToWidget
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* reference */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* names */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Widget
name|XtWindowToWidget
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* window */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/***************************************************************  *  * Arg lists  *  ****************************************************************/
end_comment

begin_define
define|#
directive|define
name|XtSetArg
parameter_list|(
name|arg
parameter_list|,
name|n
parameter_list|,
name|d
parameter_list|)
define|\
value|((void)( (arg).name = (n), (arg).value = (XtArgVal)(d) ))
end_define

begin_function_decl
specifier|extern
name|ArgList
name|XtMergeArgLists
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|ArgList
comment|/* args1 */
parameter_list|,
name|Cardinal
comment|/* num_args1 */
parameter_list|,
name|ArgList
comment|/* args2 */
parameter_list|,
name|Cardinal
comment|/* num_args2 */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/***************************************************************  *  * Vararg lists  *  ****************************************************************/
end_comment

begin_define
define|#
directive|define
name|XtVaNestedList
value|"XtVaNestedList"
end_define

begin_define
define|#
directive|define
name|XtVaTypedArg
value|"XtVaTypedArg"
end_define

begin_function_decl
specifier|extern
name|XtVarArgsList
name|XtVaCreateArgsList
parameter_list|(
if|#
directive|if
name|NeedVarargsPrototypes
name|XtPointer
comment|/*unused*/
parameter_list|,
modifier|...
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*************************************************************  *  * Information routines  *  ************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XtIntrinsicP_h
end_ifndef

begin_comment
comment|/* We're not included from the private file, so define these */
end_comment

begin_function_decl
specifier|extern
name|Display
modifier|*
name|XtDisplay
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

begin_function_decl
specifier|extern
name|Display
modifier|*
name|XtDisplayOfObject
parameter_list|(
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
name|Screen
modifier|*
name|XtScreen
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

begin_function_decl
specifier|extern
name|Screen
modifier|*
name|XtScreenOfObject
parameter_list|(
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
name|Window
name|XtWindow
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

begin_function_decl
specifier|extern
name|Window
name|XtWindowOfObject
parameter_list|(
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
name|String
name|XtName
parameter_list|(
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
name|WidgetClass
name|XtSuperclass
parameter_list|(
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
name|WidgetClass
name|XtClass
parameter_list|(
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
name|Widget
name|XtParent
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_XtIntrinsicP_h*/
end_comment

begin_define
define|#
directive|define
name|XtMapWidget
parameter_list|(
name|widget
parameter_list|)
value|XMapWindow(XtDisplay(widget), XtWindow(widget))
end_define

begin_define
define|#
directive|define
name|XtUnmapWidget
parameter_list|(
name|widget
parameter_list|)
define|\
value|XUnmapWindow(XtDisplay(widget), XtWindow(widget))
end_define

begin_function_decl
specifier|extern
name|void
name|XtAddCallback
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* callback_name */
parameter_list|,
name|XtCallbackProc
comment|/* callback */
parameter_list|,
name|XtPointer
comment|/* closure */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtRemoveCallback
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* callback_name */
parameter_list|,
name|XtCallbackProc
comment|/* callback */
parameter_list|,
name|XtPointer
comment|/* closure */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtAddCallbacks
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* callback_name */
parameter_list|,
name|XtCallbackList
comment|/* callbacks */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtRemoveCallbacks
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* callback_name */
parameter_list|,
name|XtCallbackList
comment|/* callbacks */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtRemoveAllCallbacks
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* callback_name */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtCallCallbacks
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* callback_name */
parameter_list|,
name|XtPointer
comment|/* call_data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtCallCallbackList
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|XtCallbackList
comment|/* callbacks */
parameter_list|,
name|XtPointer
comment|/* call_data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XtCallbackStatus
name|XtHasCallbacks
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* callback_name */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****************************************************************  *  * Geometry Management  *  ****************************************************************/
end_comment

begin_function_decl
specifier|extern
name|XtGeometryResult
name|XtMakeGeometryRequest
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
comment|/* reply_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XtGeometryResult
name|XtQueryGeometry
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|XtWidgetGeometry
modifier|*
comment|/* intended */
parameter_list|,
name|XtWidgetGeometry
modifier|*
comment|/* preferred_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Widget
name|XtCreatePopupShell
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|_XtString
comment|/* name */
parameter_list|,
name|WidgetClass
comment|/* widgetClass */
parameter_list|,
name|Widget
comment|/* parent */
parameter_list|,
name|ArgList
comment|/* args */
parameter_list|,
name|Cardinal
comment|/* num_args */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Widget
name|XtVaCreatePopupShell
parameter_list|(
if|#
directive|if
name|NeedVarargsPrototypes
name|_Xconst
name|_XtString
comment|/* name */
parameter_list|,
name|WidgetClass
comment|/* widgetClass */
parameter_list|,
name|Widget
comment|/* parent */
parameter_list|,
modifier|...
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtPopup
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* popup_shell */
parameter_list|,
name|XtGrabKind
comment|/* grab_kind */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtPopupSpringLoaded
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* popup_shell */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtCallbackNone
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|XtPointer
comment|/* closure */
parameter_list|,
name|XtPointer
comment|/* call_data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtCallbackNonexclusive
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|XtPointer
comment|/* closure */
parameter_list|,
name|XtPointer
comment|/* call_data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtCallbackExclusive
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|XtPointer
comment|/* closure */
parameter_list|,
name|XtPointer
comment|/* call_data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtPopdown
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* popup_shell */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtCallbackPopdown
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|XtPointer
comment|/* closure */
parameter_list|,
name|XtPointer
comment|/* call_data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtMenuPopupAction
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
name|String
modifier|*
comment|/* params */
parameter_list|,
name|Cardinal
modifier|*
comment|/* num_params */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Widget
name|XtCreateWidget
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|_XtString
comment|/* name */
parameter_list|,
name|WidgetClass
comment|/* widget_class */
parameter_list|,
name|Widget
comment|/* parent */
parameter_list|,
name|ArgList
comment|/* args */
parameter_list|,
name|Cardinal
comment|/* num_args */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Widget
name|XtCreateManagedWidget
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|_XtString
comment|/* name */
parameter_list|,
name|WidgetClass
comment|/* widget_class */
parameter_list|,
name|Widget
comment|/* parent */
parameter_list|,
name|ArgList
comment|/* args */
parameter_list|,
name|Cardinal
comment|/* num_args */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Widget
name|XtVaCreateWidget
parameter_list|(
if|#
directive|if
name|NeedVarargsPrototypes
name|_Xconst
name|_XtString
comment|/* name */
parameter_list|,
name|WidgetClass
comment|/* widget */
parameter_list|,
name|Widget
comment|/* parent */
parameter_list|,
modifier|...
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Widget
name|XtVaCreateManagedWidget
parameter_list|(
if|#
directive|if
name|NeedVarargsPrototypes
name|_Xconst
name|_XtString
comment|/* name */
parameter_list|,
name|WidgetClass
comment|/* widget_class */
parameter_list|,
name|Widget
comment|/* parent */
parameter_list|,
modifier|...
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Widget
name|XtCreateApplicationShell
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|_XtString
comment|/* name */
parameter_list|,
name|WidgetClass
comment|/* widget_class */
parameter_list|,
name|ArgList
comment|/* args */
parameter_list|,
name|Cardinal
comment|/* num_args */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Widget
name|XtAppCreateShell
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|_XtString
comment|/* application_name */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* application_class */
parameter_list|,
name|WidgetClass
comment|/* widget_class */
parameter_list|,
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|ArgList
comment|/* args */
parameter_list|,
name|Cardinal
comment|/* num_args */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Widget
name|XtVaAppCreateShell
parameter_list|(
if|#
directive|if
name|NeedVarargsPrototypes
name|_Xconst
name|_XtString
comment|/* application_name */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* application_class */
parameter_list|,
name|WidgetClass
comment|/* widget_class */
parameter_list|,
name|Display
modifier|*
comment|/* display */
parameter_list|,
modifier|...
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****************************************************************  *  * Toolkit initialization  *  ****************************************************************/
end_comment

begin_function_decl
specifier|extern
name|void
name|XtToolkitInitialize
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
name|XtLanguageProc
name|XtSetLanguageProc
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|XtLanguageProc
comment|/* proc */
parameter_list|,
name|XtPointer
comment|/* client_data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtDisplayInitialize
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* application_name */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* application_class */
parameter_list|,
name|XrmOptionDescRec
modifier|*
comment|/* options */
parameter_list|,
name|Cardinal
comment|/* num_options */
parameter_list|,
name|int
modifier|*
comment|/* argc */
parameter_list|,
name|char
modifier|*
modifier|*
comment|/* argv */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Widget
name|XtAppInitialize
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
modifier|*
comment|/* app_context_return */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* application_class */
parameter_list|,
name|XrmOptionDescList
comment|/* options */
parameter_list|,
name|Cardinal
comment|/* num_options */
parameter_list|,
name|int
modifier|*
comment|/* argc_in_out */
parameter_list|,
name|String
modifier|*
comment|/* argv_in_out */
parameter_list|,
name|String
modifier|*
comment|/* fallback_resources */
parameter_list|,
name|ArgList
comment|/* args */
parameter_list|,
name|Cardinal
comment|/* num_args */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Widget
name|XtVaAppInitialize
parameter_list|(
if|#
directive|if
name|NeedVarargsPrototypes
name|XtAppContext
modifier|*
comment|/* app_context_return */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* application_class */
parameter_list|,
name|XrmOptionDescList
comment|/* options */
parameter_list|,
name|Cardinal
comment|/* num_options */
parameter_list|,
name|int
modifier|*
comment|/* argc_in_out */
parameter_list|,
name|String
modifier|*
comment|/* argv_in_out */
parameter_list|,
name|String
modifier|*
comment|/* fallback_resources */
parameter_list|,
modifier|...
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Widget
name|XtInitialize
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|_XtString
comment|/* shell_name */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* application_class */
parameter_list|,
name|XrmOptionDescRec
modifier|*
comment|/* options */
parameter_list|,
name|Cardinal
comment|/* num_options */
parameter_list|,
name|int
modifier|*
comment|/* argc */
parameter_list|,
name|char
modifier|*
modifier|*
comment|/* argv */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Display
modifier|*
name|XtOpenDisplay
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* display_string */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* application_name */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* application_class */
parameter_list|,
name|XrmOptionDescRec
modifier|*
comment|/* options */
parameter_list|,
name|Cardinal
comment|/* num_options */
parameter_list|,
name|int
modifier|*
comment|/* argc */
parameter_list|,
name|char
modifier|*
modifier|*
comment|/* argv */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XtAppContext
name|XtCreateApplicationContext
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
name|XtAppSetFallbackResources
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|String
modifier|*
comment|/* specification_list */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtDestroyApplicationContext
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtInitializeWidgetClass
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|WidgetClass
comment|/* widget_class */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XtAppContext
name|XtWidgetToApplicationContext
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

begin_function_decl
specifier|extern
name|XtAppContext
name|XtDisplayToApplicationContext
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XrmDatabase
name|XtDatabase
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XrmDatabase
name|XtScreenDatabase
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtCloseDisplay
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtGetApplicationResources
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|XtPointer
comment|/* base */
parameter_list|,
name|XtResourceList
comment|/* resources */
parameter_list|,
name|Cardinal
comment|/* num_resources */
parameter_list|,
name|ArgList
comment|/* args */
parameter_list|,
name|Cardinal
comment|/* num_args */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtVaGetApplicationResources
parameter_list|(
if|#
directive|if
name|NeedVarargsPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|XtPointer
comment|/* base */
parameter_list|,
name|XtResourceList
comment|/* resources */
parameter_list|,
name|Cardinal
comment|/* num_resources */
parameter_list|,
modifier|...
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtGetSubresources
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|XtPointer
comment|/* base */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* name */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* class */
parameter_list|,
name|XtResourceList
comment|/* resources */
parameter_list|,
name|Cardinal
comment|/* num_resources */
parameter_list|,
name|ArgList
comment|/* args */
parameter_list|,
name|Cardinal
comment|/* num_args */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtVaGetSubresources
parameter_list|(
if|#
directive|if
name|NeedVarargsPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|XtPointer
comment|/* base */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* name */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* class */
parameter_list|,
name|XtResourceList
comment|/* resources */
parameter_list|,
name|Cardinal
comment|/* num_resources */
parameter_list|,
modifier|...
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtSetValues
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
comment|/* num_args */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtVaSetValues
parameter_list|(
if|#
directive|if
name|NeedVarargsPrototypes
name|Widget
comment|/* widget */
parameter_list|,
modifier|...
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtGetValues
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
comment|/* num_args */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtVaGetValues
parameter_list|(
if|#
directive|if
name|NeedVarargsPrototypes
name|Widget
comment|/* widget */
parameter_list|,
modifier|...
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtSetSubvalues
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtPointer
comment|/* base */
parameter_list|,
name|XtResourceList
comment|/* resources */
parameter_list|,
name|Cardinal
comment|/* num_resources */
parameter_list|,
name|ArgList
comment|/* args */
parameter_list|,
name|Cardinal
comment|/* num_args */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtVaSetSubvalues
parameter_list|(
if|#
directive|if
name|NeedVarargsPrototypes
name|XtPointer
comment|/* base */
parameter_list|,
name|XtResourceList
comment|/* resources */
parameter_list|,
name|Cardinal
comment|/* num_resources */
parameter_list|,
modifier|...
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtGetSubvalues
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtPointer
comment|/* base */
parameter_list|,
name|XtResourceList
comment|/* resources */
parameter_list|,
name|Cardinal
comment|/* num_resources */
parameter_list|,
name|ArgList
comment|/* args */
parameter_list|,
name|Cardinal
comment|/* num_args */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtVaGetSubvalues
parameter_list|(
if|#
directive|if
name|NeedVarargsPrototypes
name|XtPointer
comment|/* base */
parameter_list|,
name|XtResourceList
comment|/* resources */
parameter_list|,
name|Cardinal
comment|/* num_resources */
parameter_list|,
modifier|...
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtGetResourceList
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|WidgetClass
comment|/* widget_class */
parameter_list|,
name|XtResourceList
modifier|*
comment|/* resources_return */
parameter_list|,
name|Cardinal
modifier|*
comment|/* num_resources_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtGetConstraintResourceList
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|WidgetClass
comment|/* widget_class */
parameter_list|,
name|XtResourceList
modifier|*
comment|/* resources_return */
parameter_list|,
name|Cardinal
modifier|*
comment|/* num_resources_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|XtUnspecifiedPixmap
value|((Pixmap)2)
end_define

begin_define
define|#
directive|define
name|XtUnspecifiedShellInt
value|(-1)
end_define

begin_define
define|#
directive|define
name|XtUnspecifiedWindow
value|((Window)2)
end_define

begin_define
define|#
directive|define
name|XtUnspecifiedWindowGroup
value|((Window)3)
end_define

begin_define
define|#
directive|define
name|XtDefaultForeground
value|"XtDefaultForeground"
end_define

begin_define
define|#
directive|define
name|XtDefaultBackground
value|"XtDefaultBackground"
end_define

begin_define
define|#
directive|define
name|XtDefaultFont
value|"XtDefaultFont"
end_define

begin_define
define|#
directive|define
name|XtDefaultFontSet
value|"XtDefaultFontSet"
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CRAY
argument_list|)
operator|||
name|defined
argument_list|(
name|__arm
argument_list|)
end_if

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_define
define|#
directive|define
name|XtOffset
parameter_list|(
name|p_type
parameter_list|,
name|field
parameter_list|)
value|_Offsetof(p_type,field)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|CRAY2
end_ifdef

begin_define
define|#
directive|define
name|XtOffset
parameter_list|(
name|p_type
parameter_list|,
name|field
parameter_list|)
define|\
value|(sizeof(int)*((unsigned int)&(((p_type)NULL)->field)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !CRAY2 */
end_comment

begin_define
define|#
directive|define
name|XtOffset
parameter_list|(
name|p_type
parameter_list|,
name|field
parameter_list|)
value|((unsigned int)&(((p_type)NULL)->field))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !CRAY2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! (CRAY || __arm) */
end_comment

begin_define
define|#
directive|define
name|XtOffset
parameter_list|(
name|p_type
parameter_list|,
name|field
parameter_list|)
define|\
value|((Cardinal) (((char *) (&(((p_type)NULL)->field))) - ((char *) NULL)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !CRAY */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|offsetof
end_ifdef

begin_define
define|#
directive|define
name|XtOffsetOf
parameter_list|(
name|s_type
parameter_list|,
name|field
parameter_list|)
value|offsetof(s_type,field)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XtOffsetOf
parameter_list|(
name|s_type
parameter_list|,
name|field
parameter_list|)
value|XtOffset(s_type*,field)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*************************************************************  *  * Error Handling  *  ************************************************************/
end_comment

begin_function_decl
specifier|extern
name|XtErrorMsgHandler
name|XtAppSetErrorMsgHandler
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|XtErrorMsgHandler
comment|/* handler */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtSetErrorMsgHandler
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|XtErrorMsgHandler
comment|/* handler */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XtErrorMsgHandler
name|XtAppSetWarningMsgHandler
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|XtErrorMsgHandler
comment|/* handler */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtSetWarningMsgHandler
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|XtErrorMsgHandler
comment|/* handler */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtAppErrorMsg
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* name */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* type */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* class */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* default */
parameter_list|,
name|String
modifier|*
comment|/* params */
parameter_list|,
name|Cardinal
modifier|*
comment|/* num_params */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtErrorMsg
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|_XtString
comment|/* name */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* type */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* class */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* default */
parameter_list|,
name|String
modifier|*
comment|/* params */
parameter_list|,
name|Cardinal
modifier|*
comment|/* num_params */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtAppWarningMsg
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* name */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* type */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* class */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* default */
parameter_list|,
name|String
modifier|*
comment|/* params */
parameter_list|,
name|Cardinal
modifier|*
comment|/* num_params */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtWarningMsg
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|_XtString
comment|/* name */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* type */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* class */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* default */
parameter_list|,
name|String
modifier|*
comment|/* params */
parameter_list|,
name|Cardinal
modifier|*
comment|/* num_params */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XtErrorHandler
name|XtAppSetErrorHandler
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|XtErrorHandler
comment|/* handler */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtSetErrorHandler
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|XtErrorHandler
comment|/* handler */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XtErrorHandler
name|XtAppSetWarningHandler
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|XtErrorHandler
comment|/* handler */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtSetWarningHandler
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|XtErrorHandler
comment|/* handler */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtAppError
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* message */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtError
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|_XtString
comment|/* message */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtAppWarning
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* message */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtWarning
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|_XtString
comment|/* message */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XrmDatabase
modifier|*
name|XtAppGetErrorDatabase
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XrmDatabase
modifier|*
name|XtGetErrorDatabase
parameter_list|(
comment|/* obsolete */
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
name|XtAppGetErrorDatabaseText
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* name */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* type */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* class */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* default */
parameter_list|,
name|String
comment|/* buffer_return */
parameter_list|,
name|int
comment|/* nbytes */
parameter_list|,
name|XrmDatabase
comment|/* database */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtGetErrorDatabaseText
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|_XtString
comment|/* name */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* type */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* class */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* default */
parameter_list|,
name|String
comment|/* buffer_return */
parameter_list|,
name|int
comment|/* nbytes */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****************************************************************  *  * Memory Management  *  ****************************************************************/
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|XtMalloc
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Cardinal
comment|/* size */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|XtCalloc
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Cardinal
comment|/* num */
parameter_list|,
name|Cardinal
comment|/* size */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|XtRealloc
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|char
modifier|*
comment|/* ptr */
parameter_list|,
name|Cardinal
comment|/* num */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtFree
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|char
modifier|*
comment|/* ptr */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|XTTRACEMEMORY
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|_XtMalloc
parameter_list|(
comment|/* implementation-private */
if|#
directive|if
name|NeedFunctionPrototypes
name|Cardinal
comment|/* size */
parameter_list|,
name|char
modifier|*
comment|/* file */
parameter_list|,
name|int
comment|/* line */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|_XtRealloc
parameter_list|(
comment|/* implementation-private */
if|#
directive|if
name|NeedFunctionPrototypes
name|char
modifier|*
comment|/* ptr */
parameter_list|,
name|Cardinal
comment|/* size */
parameter_list|,
name|char
modifier|*
comment|/* file */
parameter_list|,
name|int
comment|/* line */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|_XtCalloc
parameter_list|(
comment|/* implementation-private */
if|#
directive|if
name|NeedFunctionPrototypes
name|Cardinal
comment|/* num */
parameter_list|,
name|Cardinal
comment|/* size */
parameter_list|,
name|char
modifier|*
comment|/* file */
parameter_list|,
name|int
comment|/* line */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_XtFree
parameter_list|(
comment|/* implementation-private */
if|#
directive|if
name|NeedFunctionPrototypes
name|char
modifier|*
comment|/* ptr */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|XtMalloc
parameter_list|(
name|size
parameter_list|)
value|_XtMalloc(size, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|XtRealloc
parameter_list|(
name|ptr
parameter_list|,
name|size
parameter_list|)
value|_XtRealloc(ptr, size, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|XtCalloc
parameter_list|(
name|num
parameter_list|,
name|size
parameter_list|)
value|_XtCalloc(num, size, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|XtFree
parameter_list|(
name|ptr
parameter_list|)
value|_XtFree(ptr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifdef XTTRACEMEMORY */
end_comment

begin_define
define|#
directive|define
name|XtNew
parameter_list|(
name|type
parameter_list|)
value|((type *) XtMalloc((unsigned) sizeof(type)))
end_define

begin_define
define|#
directive|define
name|XtNewString
parameter_list|(
name|str
parameter_list|)
define|\
value|((str) != NULL ? (strcpy(XtMalloc((unsigned)strlen(str) + 1), str)) : NULL)
end_define

begin_comment
comment|/*************************************************************  *  *  Work procs  *  **************************************************************/
end_comment

begin_function_decl
specifier|extern
name|XtWorkProcId
name|XtAddWorkProc
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|XtWorkProc
comment|/* proc */
parameter_list|,
name|XtPointer
comment|/* closure */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XtWorkProcId
name|XtAppAddWorkProc
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|XtWorkProc
comment|/* proc */
parameter_list|,
name|XtPointer
comment|/* closure */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtRemoveWorkProc
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtWorkProcId
comment|/* id */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****************************************************************  *  * Graphic Context Management  *****************************************************************/
end_comment

begin_function_decl
specifier|extern
name|GC
name|XtGetGC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|XtGCMask
comment|/* valueMask */
parameter_list|,
name|XGCValues
modifier|*
comment|/* values */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|GC
name|XtAllocateGC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|Cardinal
comment|/* depth */
parameter_list|,
name|XtGCMask
comment|/* valueMask */
parameter_list|,
name|XGCValues
modifier|*
comment|/* values */
parameter_list|,
name|XtGCMask
comment|/* dynamicMask */
parameter_list|,
name|XtGCMask
comment|/* unusedMask */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This implementation of XtDestroyGC differs from the formal specification  * for historic backwards compatibility reasons.  As other implementations  * may conform to the spec, use of XtReleaseGC is strongly encouraged.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|XtDestroyGC
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|GC
comment|/* gc */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtReleaseGC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* object */
parameter_list|,
name|GC
comment|/* gc */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtAppReleaseCacheRefs
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|XtCacheRef
modifier|*
comment|/* cache_ref */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtCallbackReleaseCacheRef
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|XtPointer
comment|/* closure */
parameter_list|,
comment|/* XtCacheRef */
name|XtPointer
comment|/* call_data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtCallbackReleaseCacheRefList
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|XtPointer
comment|/* closure */
parameter_list|,
comment|/* XtCacheRef* */
name|XtPointer
comment|/* call_data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtSetWMColormapWindows
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|Widget
modifier|*
comment|/* list */
parameter_list|,
name|Cardinal
comment|/* count */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|String
name|XtFindFile
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|_XtString
comment|/* path */
parameter_list|,
name|Substitution
comment|/* substitutions */
parameter_list|,
name|Cardinal
comment|/* num_substitutions */
parameter_list|,
name|XtFilePredicate
comment|/* predicate */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|String
name|XtResolvePathname
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* type */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* filename */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* suffix */
parameter_list|,
name|_Xconst
name|_XtString
comment|/* path */
parameter_list|,
name|Substitution
comment|/* substitutions */
parameter_list|,
name|Cardinal
comment|/* num_substitutions */
parameter_list|,
name|XtFilePredicate
comment|/* predicate */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****************************************************************  *  * Selections  *  *****************************************************************/
end_comment

begin_define
define|#
directive|define
name|XT_CONVERT_FAIL
value|(Atom)0x80000001
end_define

begin_function_decl
specifier|extern
name|void
name|XtDisownSelection
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|Atom
comment|/* selection */
parameter_list|,
name|Time
comment|/* time */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtGetSelectionValue
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|Atom
comment|/* selection */
parameter_list|,
name|Atom
comment|/* target */
parameter_list|,
name|XtSelectionCallbackProc
comment|/* callback */
parameter_list|,
name|XtPointer
comment|/* closure */
parameter_list|,
name|Time
comment|/* time */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtGetSelectionValues
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|Atom
comment|/* selection */
parameter_list|,
name|Atom
modifier|*
comment|/* targets */
parameter_list|,
name|int
comment|/* count */
parameter_list|,
name|XtSelectionCallbackProc
comment|/* callback */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closures */
parameter_list|,
name|Time
comment|/* time */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtAppSetSelectionTimeout
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
parameter_list|,
name|unsigned
name|long
comment|/* timeout */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtSetSelectionTimeout
parameter_list|(
comment|/* obsolete */
if|#
directive|if
name|NeedFunctionPrototypes
name|unsigned
name|long
comment|/* timeout */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|long
name|XtAppGetSelectionTimeout
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XtAppContext
comment|/* app_context */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|long
name|XtGetSelectionTimeout
parameter_list|(
comment|/* obsolete */
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
name|XSelectionRequestEvent
modifier|*
name|XtGetSelectionRequest
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|Atom
comment|/* selection */
parameter_list|,
name|XtRequestId
comment|/* request_id */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtGetSelectionValueIncremental
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|Atom
comment|/* selection */
parameter_list|,
name|Atom
comment|/* target */
parameter_list|,
name|XtSelectionCallbackProc
comment|/* selection_callback */
parameter_list|,
name|XtPointer
comment|/* client_data */
parameter_list|,
name|Time
comment|/* time */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtGetSelectionValuesIncremental
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|Atom
comment|/* selection */
parameter_list|,
name|Atom
modifier|*
comment|/* targets */
parameter_list|,
name|int
comment|/* count */
parameter_list|,
name|XtSelectionCallbackProc
comment|/* callback */
parameter_list|,
name|XtPointer
modifier|*
comment|/* client_data */
parameter_list|,
name|Time
comment|/* time */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtGrabKey
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|_XtKeyCode
comment|/* keycode */
parameter_list|,
name|Modifiers
comment|/* modifiers */
parameter_list|,
name|_XtBoolean
comment|/* owner_events */
parameter_list|,
name|int
comment|/* pointer_mode */
parameter_list|,
name|int
comment|/* keyboard_mode */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtUngrabKey
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|_XtKeyCode
comment|/* keycode */
parameter_list|,
name|Modifiers
comment|/* modifiers */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XtGrabKeyboard
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|_XtBoolean
comment|/* owner_events */
parameter_list|,
name|int
comment|/* pointer_mode */
parameter_list|,
name|int
comment|/* keyboard_mode */
parameter_list|,
name|Time
comment|/* time */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtUngrabKeyboard
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|Time
comment|/* time */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtGrabButton
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|int
comment|/* button */
parameter_list|,
name|Modifiers
comment|/* modifiers */
parameter_list|,
name|_XtBoolean
comment|/* owner_events */
parameter_list|,
name|unsigned
name|int
comment|/* event_mask */
parameter_list|,
name|int
comment|/* pointer_mode */
parameter_list|,
name|int
comment|/* keyboard_mode */
parameter_list|,
name|Window
comment|/* confine_to */
parameter_list|,
name|Cursor
comment|/* cursor */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtUngrabButton
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|unsigned
name|int
comment|/* button */
parameter_list|,
name|Modifiers
comment|/* modifiers */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XtGrabPointer
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|_XtBoolean
comment|/* owner_events */
parameter_list|,
name|unsigned
name|int
comment|/* event_mask */
parameter_list|,
name|int
comment|/* pointer_mode */
parameter_list|,
name|int
comment|/* keyboard_mode */
parameter_list|,
name|Window
comment|/* confine_to */
parameter_list|,
name|Cursor
comment|/* cursor */
parameter_list|,
name|Time
comment|/* time */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtUngrabPointer
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* widget */
parameter_list|,
name|Time
comment|/* time */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XtGetApplicationNameAndClass
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|String
modifier|*
comment|/* name_return */
parameter_list|,
name|String
modifier|*
comment|/* class_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Predefined Resource Converters  */
end_comment

begin_comment
comment|/* String converters */
end_comment

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtStringToAcceleratorTable
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* none */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtStringToAtom
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* Display */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtStringToBoolean
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* none */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtStringToBool
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* none */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtStringToCursor
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* Display */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtStringToDimension
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* none */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtStringToDisplay
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* none */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtStringToFile
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* none */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtStringToFloat
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* none */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtStringToFont
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* Display */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtStringToFontSet
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* Display, locale */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtStringToFontStruct
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* Display */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtStringToInt
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* none */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtStringToInitialState
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* none */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtStringToPixel
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* Screen, Colormap */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|XtCvtStringToPosition
value|XtCvtStringToShort
end_define

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtStringToShort
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* none */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtStringToTranslationTable
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* none */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtStringToUnsignedChar
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* none */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtStringToVisual
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* Screen, depth */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* int converters */
end_comment

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtIntToBoolean
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* none */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtIntToBool
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* none */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtIntToColor
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* Screen, Colormap */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|XtCvtIntToDimension
value|XtCvtIntToShort
end_define

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtIntToFloat
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* none */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtIntToFont
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* none */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtIntToPixel
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* none */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtIntToPixmap
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* none */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|XtCvtIntToPosition
value|XtCvtIntToShort
end_define

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtIntToShort
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* none */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtIntToUnsignedChar
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* none */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Color converter */
end_comment

begin_function_decl
specifier|extern
name|Boolean
name|XtCvtColorToPixel
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|XrmValuePtr
comment|/* args */
parameter_list|,
comment|/* none */
name|Cardinal
modifier|*
comment|/* num_args */
parameter_list|,
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* closure_ret */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Pixel converter */
end_comment

begin_define
define|#
directive|define
name|XtCvtPixelToColor
value|XtCvtIntToColor
end_define

begin_macro
name|_XFUNCPROTOEND
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_XtIntrinsic_h*/
end_comment

begin_comment
comment|/* DON'T ADD STUFF AFTER THIS #endif */
end_comment

end_unit

