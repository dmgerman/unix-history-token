begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Converters.h,v 1.14 91/07/22 23:51:43 converse Exp $  *  * Copyright 1988 by the Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided   * that the above copyright notice appear in all copies and that both that   * copyright notice and this permission notice appear in supporting   * documentation, and that the name of M.I.T. not be used in advertising  * or publicity pertaining to distribution of the software without specific,   * written prior permission. M.I.T. makes no representations about the   * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * The X Window System is a Trademark of MIT.  *  * The interfaces described by this header file are for miscellaneous utilities  * and are not part of the Xlib standard.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XMU_STRCONVERT_H_
end_ifndef

begin_define
define|#
directive|define
name|_XMU_STRCONVERT_H_
end_define

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_function_decl
name|_XFUNCPROTOBEGIN
comment|/*  * Converters - insert in alphabetical order  */
comment|/******************************************************************************  * XmuCvtFunctionToCallback  */
specifier|extern
name|void
name|XmuCvtFunctionToCallback
parameter_list|(
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
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/******************************************************************************  * XmuCvtStringToBackingStore  */
end_comment

begin_define
define|#
directive|define
name|XtNbackingStore
value|"backingStore"
end_define

begin_define
define|#
directive|define
name|XtCBackingStore
value|"BackingStore"
end_define

begin_define
define|#
directive|define
name|XtRBackingStore
value|"BackingStore"
end_define

begin_define
define|#
directive|define
name|XtEnotUseful
value|"notUseful"
end_define

begin_define
define|#
directive|define
name|XtEwhenMapped
value|"whenMapped"
end_define

begin_define
define|#
directive|define
name|XtEalways
value|"always"
end_define

begin_define
define|#
directive|define
name|XtEdefault
value|"default"
end_define

begin_function_decl
specifier|extern
name|void
name|XmuCvtStringToBackingStore
parameter_list|(
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
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/******************************************************************************  * XmuCvtStringToCursor  */
end_comment

begin_function_decl
specifier|extern
name|void
name|XmuCvtStringToCursor
parameter_list|(
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
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XmuCvtStringToColorCursor
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
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* converter_data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|XtRColorCursor
value|"ColorCursor"
end_define

begin_define
define|#
directive|define
name|XtNpointerColor
value|"pointerColor"
end_define

begin_define
define|#
directive|define
name|XtNpointerColorBackground
value|"pointerColorBackground"
end_define

begin_comment
comment|/******************************************************************************  * XmuCvtStringToGravity  */
end_comment

begin_typedef
typedef|typedef
name|int
name|XtGravity
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XtRGravity
value|"Gravity"
end_define

begin_define
define|#
directive|define
name|XtEForget
value|"forget"
end_define

begin_define
define|#
directive|define
name|XtENorthWest
value|"northwest"
end_define

begin_define
define|#
directive|define
name|XtENorth
value|"north"
end_define

begin_define
define|#
directive|define
name|XtENorthEast
value|"northeast"
end_define

begin_define
define|#
directive|define
name|XtEWest
value|"west"
end_define

begin_define
define|#
directive|define
name|XtECenter
value|"center"
end_define

begin_define
define|#
directive|define
name|XtEEast
value|"east"
end_define

begin_define
define|#
directive|define
name|XtESouthWest
value|"southwest"
end_define

begin_define
define|#
directive|define
name|XtESouth
value|"south"
end_define

begin_define
define|#
directive|define
name|XtESouthEast
value|"southeast"
end_define

begin_define
define|#
directive|define
name|XtEStatic
value|"static"
end_define

begin_define
define|#
directive|define
name|XtEUnmap
value|"unmap"
end_define

begin_function_decl
specifier|extern
name|void
name|XmuCvtStringToGravity
parameter_list|(
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
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/******************************************************************************  * XmuCvtStringToJustify  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|XtJustifyLeft
block|,
comment|/* justify text to left side of button   */
name|XtJustifyCenter
block|,
comment|/* justify text in center of button      */
name|XtJustifyRight
comment|/* justify text to right side of button  */
block|}
name|XtJustify
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XtEleft
value|"left"
end_define

begin_define
define|#
directive|define
name|XtEcenter
value|"center"
end_define

begin_define
define|#
directive|define
name|XtEright
value|"right"
end_define

begin_define
define|#
directive|define
name|XtEtop
value|"top"
end_define

begin_define
define|#
directive|define
name|XtEbottom
value|"bottom"
end_define

begin_function_decl
specifier|extern
name|void
name|XmuCvtStringToJustify
parameter_list|(
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
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/******************************************************************************  * XmuCvtStringToLong  */
end_comment

begin_define
define|#
directive|define
name|XtRLong
value|"Long"
end_define

begin_function_decl
specifier|extern
name|void
name|XmuCvtStringToLong
parameter_list|(
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
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/******************************************************************************  * XmuCvtStringToOrientation  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|XtorientHorizontal
block|,
name|XtorientVertical
block|}
name|XtOrientation
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|XmuCvtStringToOrientation
parameter_list|(
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
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/******************************************************************************  * XmuCvtStringToBitmap  */
end_comment

begin_function_decl
specifier|extern
name|void
name|XmuCvtStringToBitmap
parameter_list|(
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
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/******************************************************************************  * XmuCvtStringToShapeStyle; is XtTypeConverter (i.e. new style)  * no conversion arguments, not particularly useful to cache the results.  */
end_comment

begin_define
define|#
directive|define
name|XtRShapeStyle
value|"ShapeStyle"
end_define

begin_define
define|#
directive|define
name|XtERectangle
value|"Rectangle"
end_define

begin_define
define|#
directive|define
name|XtEOval
value|"Oval"
end_define

begin_define
define|#
directive|define
name|XtEEllipse
value|"Ellipse"
end_define

begin_define
define|#
directive|define
name|XtERoundedRectangle
value|"RoundedRectangle"
end_define

begin_define
define|#
directive|define
name|XmuShapeRectangle
value|1
end_define

begin_define
define|#
directive|define
name|XmuShapeOval
value|2
end_define

begin_define
define|#
directive|define
name|XmuShapeEllipse
value|3
end_define

begin_define
define|#
directive|define
name|XmuShapeRoundedRectangle
value|4
end_define

begin_function_decl
specifier|extern
name|Boolean
name|XmuCvtStringToShapeStyle
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
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* converter_data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|XmuReshapeWidget
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|int
comment|/* shape_style */
parameter_list|,
name|int
comment|/* corner_width */
parameter_list|,
name|int
comment|/* corner_height */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/******************************************************************************  * XmuCvtStringToWidget  */
end_comment

begin_function_decl
specifier|extern
name|void
name|XmuCvtStringToWidget
parameter_list|(
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
name|XrmValuePtr
comment|/* fromVal */
parameter_list|,
name|XrmValuePtr
comment|/* toVal */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/******************************************************************************  * XmuNewCvtStringToWidget  */
end_comment

begin_function_decl
specifier|extern
name|Boolean
name|XmuNewCvtStringToWidget
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
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
comment|/* fromVal */
parameter_list|,
name|XrmValue
modifier|*
comment|/* toVal */
parameter_list|,
name|XtPointer
modifier|*
comment|/* converter_data */
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
comment|/* _XMU_STRCONVERT_H_ */
end_comment

end_unit

