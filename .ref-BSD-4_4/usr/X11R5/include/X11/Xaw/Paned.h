begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * $XConsortium: Paned.h,v 1.13 91/02/17 13:16:15 rws Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * Paned.h - Paned Composite Widget's public header file.  *  * Updated and significantly modifided from the Athena VPaned Widget.  *  * Date:    March 1, 1989  *  * By:      Chris D. Peterson  *          MIT X Consortium  *          kit@expo.lcs.mit.edu  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawPaned_h
end_ifndef

begin_define
define|#
directive|define
name|_XawPaned_h
end_define

begin_include
include|#
directive|include
file|<X11/Constraint.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xmu/Converters.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_comment
comment|/****************************************************************  *  * Vertical Paned Widget (SubClass of CompositeClass)  *  ****************************************************************/
end_comment

begin_comment
comment|/* RESOURCES:   Name		         Class		   RepType	    Default Value  ----		         -----		   -------	    -------------  background	         Background	   Pixel	    XtDefaultBackground  betweenCursor	         Cursor	           Cursor	    **  border		         BorderColor       Pixel	    XtDefaultForeground  borderWidth	         BorderWidth       Dimension	    1  cursor		         Cursor	           Cursor	    None  destroyCallback         Callback	   Pointer	    NULL  height		         Height	           Dimension	    0  gripIndent	         GripIndent	   Position	    16  gripCursor	         Cursor	           Cursor	    **  horizontalGripCursol    Cursor	           Cursor	    sb_h_double_arrow  horizontalBetweencursor Cursor	           Cursor	    sb_up_arrow  internalBorderColor     BorderColor	   Pixel	    XtDefaultForeground  internalBorderWidth     BorderWidth	   Position	    1  leftCursor	         Cursor	           Cursor	    sb_left_arrow  lowerCursor	         Cursor	           Cursor	    sb_down_arrow  mappedWhenManaged       MappedWhenManaged Boolean	    True  orientation             Orientation       XtOrientation    XtorientVertical  refigureMode	         Boolean	   Boolean	    On  rightCursor	         Cursor	           Cursor           sb_right_arrow  sensitive	         Sensitive	   Boolean	    True  upperCursor	         Cursor	           Cursor	    sb_up_arrow  verticalBetweenCursor   Cursor	           Cursor           sb_left_arrow  verticalGripCursor      Cursor	           Cursor           sb_v_double_arrow  width		         Width	           Dimension	    0  x		         Position	   Position	    0  y		         Position	   Position    	    0  ** These resources now are set to the vertical or horizontal cursor    depending upon orientation, by default.  If a value is specified here    then that cursor will be used reguardless of orientation.   CONSTRAINT RESOURCES:   Name		      Class		RepType		Default Value  ----		      -----		-------		-------------  allowResize	      Boolean	        Boolean         False  max		      Max	        Dimension	unlimited  min		      Min		Dimension	Grip Size  preferredPaneSize    PerferredPaneSize Dimension	PANED_ASK_CHILD  resizeToPreferred    Boolean		Boolean	 	False  showGrip	      ShowGrip		Boolean		True  skipAdjust	      Boolean	        Boolean         False  */
end_comment

begin_define
define|#
directive|define
name|PANED_ASK_CHILD
value|0
end_define

begin_define
define|#
directive|define
name|PANED_GRIP_SIZE
value|0
end_define

begin_comment
comment|/* New Fields */
end_comment

begin_define
define|#
directive|define
name|XtNallowResize
value|"allowResize"
end_define

begin_define
define|#
directive|define
name|XtNbetweenCursor
value|"betweenCursor"
end_define

begin_define
define|#
directive|define
name|XtNverticalBetweenCursor
value|"verticalBetweenCursor"
end_define

begin_define
define|#
directive|define
name|XtNhorizontalBetweenCursor
value|"horizontalBetweenCursor"
end_define

begin_define
define|#
directive|define
name|XtNgripCursor
value|"gripCursor"
end_define

begin_define
define|#
directive|define
name|XtNgripIndent
value|"gripIndent"
end_define

begin_define
define|#
directive|define
name|XtNhorizontalGripCursor
value|"horizontalGripCursor"
end_define

begin_define
define|#
directive|define
name|XtNinternalBorderColor
value|"internalBorderColor"
end_define

begin_define
define|#
directive|define
name|XtNinternalBorderWidth
value|"internalBorderWidth"
end_define

begin_define
define|#
directive|define
name|XtNleftCursor
value|"leftCursor"
end_define

begin_define
define|#
directive|define
name|XtNlowerCursor
value|"lowerCursor"
end_define

begin_define
define|#
directive|define
name|XtNrefigureMode
value|"refigureMode"
end_define

begin_define
define|#
directive|define
name|XtNposition
value|"position"
end_define

begin_define
define|#
directive|define
name|XtNmin
value|"min"
end_define

begin_define
define|#
directive|define
name|XtNmax
value|"max"
end_define

begin_define
define|#
directive|define
name|XtNpreferredPaneSize
value|"preferredPaneSize"
end_define

begin_define
define|#
directive|define
name|XtNresizeToPreferred
value|"resizeToPreferred"
end_define

begin_define
define|#
directive|define
name|XtNrightCursor
value|"rightCursor"
end_define

begin_define
define|#
directive|define
name|XtNshowGrip
value|"showGrip"
end_define

begin_define
define|#
directive|define
name|XtNskipAdjust
value|"skipAdjust"
end_define

begin_define
define|#
directive|define
name|XtNupperCursor
value|"upperCursor"
end_define

begin_define
define|#
directive|define
name|XtNverticalGripCursor
value|"verticalGripCursor"
end_define

begin_define
define|#
directive|define
name|XtCGripIndent
value|"GripIndent"
end_define

begin_define
define|#
directive|define
name|XtCMin
value|"Min"
end_define

begin_define
define|#
directive|define
name|XtCMax
value|"Max"
end_define

begin_define
define|#
directive|define
name|XtCPreferredPaneSize
value|"PreferredPaneSize"
end_define

begin_define
define|#
directive|define
name|XtCShowGrip
value|"ShowGrip"
end_define

begin_comment
comment|/* Class record constant */
end_comment

begin_decl_stmt
specifier|extern
name|WidgetClass
name|panedWidgetClass
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|struct
name|_PanedClassRec
modifier|*
name|PanedWidgetClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_PanedRec
modifier|*
name|PanedWidget
typedef|;
end_typedef

begin_comment
comment|/************************************************************  *  *  Public Procedures   *  ************************************************************/
end_comment

begin_function_decl
name|_XFUNCPROTOBEGIN
comment|/*	Function Name: XawPanedSetMinMax  *	Description: Sets the min and max size for a pane.  *	Arguments: widget - the widget that is a child of the Paned widget.  *                 min, max - the new min and max size for the pane.  *	Returns: none.  */
specifier|extern
name|void
name|XawPanedSetMinMax
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|int
comment|/* min */
parameter_list|,
name|int
comment|/* max */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawPanedGetMinMax  *	Description: Gets the min and max size for a pane.  *	Arguments: widget - the widget that is a child of the Paned widget.  ** RETURNED **    min, max - the current min and max size for the pane.  *	Returns: none.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|XawPanedGetMinMax
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|int
modifier|*
comment|/* min_return */
parameter_list|,
name|int
modifier|*
comment|/* max_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawPanedSetRefigureMode  *	Description: Allows a flag to be set the will inhibit   *                   the paned widgets relayout routine.  *	Arguments: w - the paned widget.  *                 mode - if FALSE then inhibit refigure.  *	Returns: none.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|XawPanedSetRefigureMode
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
if|#
directive|if
name|NeedWidePrototypes
comment|/* Boolean */
name|int
comment|/* mode */
else|#
directive|else
name|Boolean
comment|/* mode */
endif|#
directive|endif
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawPanedGetNumSub  *	Description: Returns the number of panes in the paned widget.  *	Arguments: w - the paned widget.  *	Returns: the number of panes in the paned widget.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|XawPanedGetNumSub
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawPanedAllowResize  *	Description: Allows a flag to be set that determines if the paned  *                   widget will allow geometry requests from this child  *	Arguments: widget - a child of the paned widget.  *	Returns: none.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|XawPanedAllowResize
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
if|#
directive|if
name|NeedWidePrototypes
comment|/* Boolean */
name|int
comment|/* allow_resize */
else|#
directive|else
name|Boolean
comment|/* allow_resize */
endif|#
directive|endif
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
comment|/* _XawPaned_h */
end_comment

begin_comment
comment|/* DON'T ADD STUFF AFTER THIS #endif */
end_comment

end_unit

