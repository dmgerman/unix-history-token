begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: TextSink.h,v 1.8 91/02/17 13:20:18 rws Exp $  */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawTextSink_h
end_ifndef

begin_define
define|#
directive|define
name|_XawTextSink_h
end_define

begin_comment
comment|/***********************************************************************  *  * TextSink Object  *  ***********************************************************************/
end_comment

begin_include
include|#
directive|include
file|<X11/Object.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_comment
comment|/* Resources:   Name		     Class		RepType		Default Value  ----		     -----		-------		-------------  font                Font            XFontStruct *      XtDefaultFont  foreground          Foreground      Pixel              XtDefaultForeground  background          Background      Pixel              XtDefaultBackground  */
end_comment

begin_comment
comment|/* Class record constants */
end_comment

begin_decl_stmt
specifier|extern
name|WidgetClass
name|textSinkObjectClass
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|struct
name|_TextSinkClassRec
modifier|*
name|TextSinkObjectClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_TextSinkRec
modifier|*
name|TextSinkObject
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XawisOn
block|,
name|XawisOff
block|}
name|XawTextInsertState
typedef|;
end_typedef

begin_comment
comment|/************************************************************  *  * Public Functions.  *  ************************************************************/
end_comment

begin_function_decl
name|_XFUNCPROTOBEGIN
comment|/*	Function Name: XawTextSinkDisplayText  *	Description: Stub function that in subclasses will display text.   *	Arguments: w - the TextSink Object.  *                 x, y - location to start drawing text.  *                 pos1, pos2 - location of starting and ending points  *                              in the text buffer.  *                 highlight - hightlight this text?  *	Returns: none.  *  * This function doesn't actually display anything, it is only a place  * holder.  */
specifier|extern
name|void
name|XawTextSinkDisplayText
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
comment|/* Position */
name|int
comment|/* x */
parameter_list|,
comment|/* Position	*/
name|int
comment|/* y */
parameter_list|,
else|#
directive|else
name|Position
comment|/* x */
parameter_list|,
name|Position
comment|/* y */
parameter_list|,
endif|#
directive|endif
name|XawTextPosition
comment|/* pos1 */
parameter_list|,
name|XawTextPosition
comment|/* pos2 */
parameter_list|,
if|#
directive|if
name|NeedWidePrototypes
comment|/* Boolean */
name|int
comment|/* highlight */
else|#
directive|else
name|Boolean
comment|/* highlight */
endif|#
directive|endif
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawTextSinkInsertCursor  *	Description: Places the InsertCursor.  *	Arguments: w - the TextSink Object.  *                 x, y - location for the cursor.  *                 staye - whether to turn the cursor on, or off.  *	Returns: none.  *  * This function doesn't actually display anything, it is only a place  * holder.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|XawTextSinkInsertCursor
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
comment|/* Position */
name|int
comment|/* x */
parameter_list|,
comment|/* Position	*/
name|int
comment|/* y */
parameter_list|,
comment|/* XawTextInsertState */
name|int
comment|/* state */
else|#
directive|else
name|Position
comment|/* x */
parameter_list|,
name|Position
comment|/* y */
parameter_list|,
name|XawTextInsertState
comment|/* state */
endif|#
directive|endif
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawTextSinkClearToBackground  *	Description: Clears a region of the sink to the background color.  *	Arguments: w - the TextSink Object.  *                 x, y  - location of area to clear.  *                 width, height - size of area to clear  *	Returns: void.  *  * This function doesn't actually display anything, it is only a place  * holder.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|XawTextSinkClearToBackground
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
comment|/* Position */
name|int
comment|/* x */
parameter_list|,
comment|/* Position */
name|int
comment|/* y */
parameter_list|,
comment|/* Dimension */
name|int
comment|/* width */
parameter_list|,
comment|/* Dimension */
name|int
comment|/* height */
else|#
directive|else
name|Position
comment|/* x */
parameter_list|,
name|Position
comment|/* y */
parameter_list|,
name|Dimension
comment|/* width */
parameter_list|,
name|Dimension
comment|/* height */
endif|#
directive|endif
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawTextSinkFindPosition  *	Description: Finds a position in the text.  *	Arguments: w - the TextSink Object.  *                 fromPos - reference position.  *                 fromX   - reference location.  *                 width,  - width of section to paint text.  *                 stopAtWordBreak - returned position is a word break?  *                 resPos - Position to return.      *** RETURNED ***  *                 resWidth - Width actually used.   *** RETURNED ***  *                 resHeight - Height actually used. *** RETURNED ***  *	Returns: none (see above).  */
end_comment

begin_function_decl
specifier|extern
name|void
name|XawTextSinkFindPosition
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|XawTextPosition
comment|/* fromPos */
parameter_list|,
name|int
comment|/* fromX */
parameter_list|,
name|int
comment|/* width */
parameter_list|,
if|#
directive|if
name|NeedWidePrototypes
comment|/* Boolean */
name|int
comment|/* stopAtWordBreak */
parameter_list|,
else|#
directive|else
name|Boolean
comment|/* stopAtWordBreak */
parameter_list|,
endif|#
directive|endif
name|XawTextPosition
modifier|*
comment|/* pos_return */
parameter_list|,
name|int
modifier|*
comment|/* width_return */
parameter_list|,
name|int
modifier|*
comment|/* height_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawTextSinkFindDistance  *	Description: Find the Pixel Distance between two text Positions.  *	Arguments: w - the TextSink Object.  *                 fromPos - starting Position.  *                 fromX   - x location of starting Position.  *                 toPos   - end Position.  *                 resWidth - Distance between fromPos and toPos.  *                 resPos   - Acutal toPos used.  *                 resHeight - Height required by this text.  *	Returns: none.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|XawTextSinkFindDistance
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|XawTextPosition
comment|/* fromPos */
parameter_list|,
name|int
comment|/* fromX */
parameter_list|,
name|XawTextPosition
comment|/* toPos */
parameter_list|,
name|int
modifier|*
comment|/* width_return */
parameter_list|,
name|XawTextPosition
modifier|*
comment|/* pos_return */
parameter_list|,
name|int
modifier|*
comment|/* height_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawTextSinkResolve  *	Description: Resloves a location to a position.  *	Arguments: w - the TextSink Object.  *                 pos - a reference Position.  *                 fromx - a reference Location.  *                 width - width to move.  *                 resPos - the resulting position.  *	Returns: none  */
end_comment

begin_function_decl
specifier|extern
name|void
name|XawTextSinkResolve
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|XawTextPosition
comment|/* fromPos */
parameter_list|,
name|int
comment|/* fromX */
parameter_list|,
name|int
comment|/* width */
parameter_list|,
name|XawTextPosition
modifier|*
comment|/* pos_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawTextSinkMaxLines  *	Description: Finds the Maximum number of lines that will fit in  *                   a given height.  *	Arguments: w - the TextSink Object.  *                 height - height to fit lines into.  *	Returns: the number of lines that will fit.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|XawTextSinkMaxLines
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
comment|/* Dimension */
name|int
comment|/* height */
else|#
directive|else
name|Dimension
comment|/* height */
endif|#
directive|endif
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawTextSinkMaxHeight  *	Description: Finds the Minium height that will contain a given number   *                   lines.  *	Arguments: w - the TextSink Object.  *                 lines - the number of lines.  *	Returns: the height.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|XawTextSinkMaxHeight
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|int
comment|/* lines */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawTextSinkSetTabs  *	Description: Sets the Tab stops.  *	Arguments: w - the TextSink Object.  *                 tab_count - the number of tabs in the list.  *                 tabs - the text positions of the tabs.  *	Returns: none  */
end_comment

begin_function_decl
specifier|extern
name|void
name|XawTextSinkSetTabs
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|int
comment|/* tab_count */
parameter_list|,
name|int
modifier|*
comment|/* tabs */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawTextSinkGetCursorBounds  *	Description: Finds the bounding box for the insert curor (caret).  *	Arguments: w - the TextSinkObject.  *                 rect - an X rectance containing the cursor bounds.  *	Returns: none (fills in rect).  */
end_comment

begin_function_decl
specifier|extern
name|void
name|XawTextSinkGetCursorBounds
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|XRectangle
modifier|*
comment|/* rect_return */
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
comment|/* _XawTextSrc_h -- DON'T ADD STUFF AFTER THIS #endif */
end_comment

end_unit

