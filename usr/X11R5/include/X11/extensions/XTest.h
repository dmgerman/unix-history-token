begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XTest.h,v 1.4 92/04/20 13:13:54 rws Exp $ */
end_comment

begin_comment
comment|/*  Copyright 1992 by the Massachusetts Institute of Technology  Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XTEST_H_
end_ifndef

begin_define
define|#
directive|define
name|_XTEST_H_
end_define

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_define
define|#
directive|define
name|X_XTestGetVersion
value|0
end_define

begin_define
define|#
directive|define
name|X_XTestCompareCursor
value|1
end_define

begin_define
define|#
directive|define
name|X_XTestFakeInput
value|2
end_define

begin_define
define|#
directive|define
name|XTestNumberEvents
value|0
end_define

begin_define
define|#
directive|define
name|XTestNumberErrors
value|0
end_define

begin_define
define|#
directive|define
name|XTestMajorVersion
value|2
end_define

begin_define
define|#
directive|define
name|XTestMinorVersion
value|1
end_define

begin_define
define|#
directive|define
name|XTestExtensionName
value|"XTEST"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_XTEST_SERVER_
end_ifndef

begin_function_decl
name|_XFUNCPROTOBEGIN
name|Bool
name|XTestQueryExtension
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|int
modifier|*
comment|/* event_basep */
parameter_list|,
name|int
modifier|*
comment|/* error_basep */
parameter_list|,
name|int
modifier|*
comment|/* majorp */
parameter_list|,
name|int
modifier|*
comment|/* minorp */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Bool
name|XTestCompareCursorWithWindow
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Window
comment|/* window */
parameter_list|,
name|Cursor
comment|/* cursor */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Bool
name|XTestCompareCurrentCursorWithWindow
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Window
comment|/* window */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XTestFakeKeyEvent(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* dpy */
operator|,
extern|unsigned int
comment|/* keycode */
operator|,
extern|Bool
comment|/* is_press */
operator|,
extern|unsigned long
end_extern

begin_comment
comment|/* delay */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern XTestFakeButtonEvent(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* dpy */
operator|,
extern|unsigned int
comment|/* button */
operator|,
extern|Bool
comment|/* is_press */
operator|,
extern|unsigned long
end_extern

begin_comment
comment|/* delay */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern XTestFakeMotionEvent(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* dpy */
operator|,
extern|int
comment|/* screen */
operator|,
extern|int
comment|/* x */
operator|,
extern|int
comment|/* y */
operator|,
extern|unsigned long
end_extern

begin_comment
comment|/* delay */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern XTestFakeRelativeMotionEvent(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* dpy */
operator|,
extern|int
comment|/* x */
operator|,
extern|int
comment|/* y */
operator|,
extern|unsigned long
end_extern

begin_comment
comment|/* delay */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|XTestSetGContextOfGC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|GC
comment|/* gc */
parameter_list|,
name|GContext
comment|/* gid */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|XTestSetVisualIDOfVisual
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Visual
modifier|*
comment|/* visual */
parameter_list|,
name|VisualID
comment|/* visualid */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Status
name|XTestDiscard
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

begin_macro
name|_XFUNCPROTOEND
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XTEST_SERVER_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

