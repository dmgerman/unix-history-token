begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * $XConsortium: TextP.h,v 1.49 91/05/14 15:20:55 gildea Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawTextP_h
end_ifndef

begin_define
define|#
directive|define
name|_XawTextP_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/Text.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/SimpleP.h>
end_include

begin_comment
comment|/****************************************************************  *  * Text widget private  *  ****************************************************************/
end_comment

begin_define
define|#
directive|define
name|MAXCUT
value|30000
end_define

begin_comment
comment|/* Maximum number of characters that can be cut. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|abs
end_ifndef

begin_define
define|#
directive|define
name|abs
parameter_list|(
name|x
parameter_list|)
value|(((x)< 0) ? (-(x)) : (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GETLASTPOS
value|XawTextSourceScan(ctx->text.source, 0, \ 				      XawstAll, XawsdRight, 1, TRUE)
end_define

begin_define
define|#
directive|define
name|zeroPosition
value|((XawTextPosition) 0)
end_define

begin_decl_stmt
specifier|extern
name|XtActionsRec
name|_XawTextActionsTable
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Cardinal
name|_XawTextActionsTableCount
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|XawLF
value|0x0a
end_define

begin_define
define|#
directive|define
name|XawCR
value|0x0d
end_define

begin_define
define|#
directive|define
name|XawTAB
value|0x09
end_define

begin_define
define|#
directive|define
name|XawBS
value|0x08
end_define

begin_define
define|#
directive|define
name|XawSP
value|0x20
end_define

begin_define
define|#
directive|define
name|XawDEL
value|0x7f
end_define

begin_define
define|#
directive|define
name|XawBSLASH
value|'\\'
end_define

begin_comment
comment|/* constants that subclasses may want to know */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_TEXT_HEIGHT
value|((Dimension)~0)
end_define

begin_comment
comment|/* displayable text management data structures */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XawTextPosition
name|position
decl_stmt|;
name|Position
name|y
decl_stmt|;
name|Dimension
name|textWidth
decl_stmt|;
block|}
name|XawTextLineTableEntry
operator|,
typedef|*
name|XawTextLineTableEntryPtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|XawTextPosition
name|left
decl_stmt|,
name|right
decl_stmt|;
name|XawTextSelectType
name|type
decl_stmt|;
name|Atom
modifier|*
name|selections
decl_stmt|;
name|int
name|atom_count
decl_stmt|;
name|int
name|array_size
decl_stmt|;
block|}
name|XawTextSelection
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_XawTextSelectionSalt
block|{
name|struct
name|_XawTextSelectionSalt
modifier|*
name|next
decl_stmt|;
name|XawTextSelection
name|s
decl_stmt|;
name|char
modifier|*
name|contents
decl_stmt|;
name|int
name|length
decl_stmt|;
block|}
name|XawTextSelectionSalt
typedef|;
end_typedef

begin_comment
comment|/* Line Tables are n+1 long - last position displayed is in last lt entry */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XawTextPosition
name|top
decl_stmt|;
comment|/* Top of the displayed text.		*/
name|int
name|lines
decl_stmt|;
comment|/* How many lines in this table.	*/
name|XawTextLineTableEntry
modifier|*
name|info
decl_stmt|;
comment|/* A dynamic array, one entry per line  */
block|}
name|XawTextLineTable
operator|,
typedef|*
name|XawTextLineTablePtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_XawTextMargin
block|{
name|Position
name|left
decl_stmt|,
name|right
decl_stmt|,
name|top
decl_stmt|,
name|bottom
decl_stmt|;
block|}
name|XawTextMargin
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VMargins
parameter_list|(
name|ctx
parameter_list|)
value|( (ctx)->text.margin.top + (ctx)->text.margin.bottom )
end_define

begin_define
define|#
directive|define
name|HMargins
parameter_list|(
name|ctx
parameter_list|)
value|( (ctx)->text.margin.left + (ctx)->text.margin.right )
end_define

begin_define
define|#
directive|define
name|IsPositionVisible
parameter_list|(
name|ctx
parameter_list|,
name|pos
parameter_list|)
define|\
value|(pos>= ctx->text.lt.info[0].position&& \ 		 pos< ctx->text.lt.info[ctx->text.lt.lines].position)
end_define

begin_comment
comment|/*  * Search& Replace data structure.  */
end_comment

begin_struct
struct|struct
name|SearchAndReplace
block|{
name|Boolean
name|selection_changed
decl_stmt|;
comment|/* flag so that the selection cannot be 				   changed out from underneath query-replace.*/
name|Widget
name|search_popup
decl_stmt|;
comment|/* The poppup widget that allows searches.*/
name|Widget
name|label1
decl_stmt|;
comment|/* The label widgets for the search window. */
name|Widget
name|label2
decl_stmt|;
name|Widget
name|left_toggle
decl_stmt|;
comment|/* The left search toggle radioGroup. */
name|Widget
name|right_toggle
decl_stmt|;
comment|/* The right search toggle radioGroup. */
name|Widget
name|rep_label
decl_stmt|;
comment|/* The Replace label string. */
name|Widget
name|rep_text
decl_stmt|;
comment|/* The Replace text field. */
name|Widget
name|search_text
decl_stmt|;
comment|/* The Search text field. */
name|Widget
name|rep_one
decl_stmt|;
comment|/* The Replace one button. */
name|Widget
name|rep_all
decl_stmt|;
comment|/* The Replace all button. */
block|}
struct|;
end_struct

begin_comment
comment|/* Private Text Definitions */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|ActionProc
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_comment
comment|/* New fields for the Text widget class record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|empty
decl_stmt|;
block|}
name|TextClassPart
typedef|;
end_typedef

begin_struct
struct|struct
name|text_move
block|{
name|int
name|h
decl_stmt|,
name|v
decl_stmt|;
name|struct
name|text_move
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Full class record declaration */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_TextClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|SimpleClassPart
name|simple_class
decl_stmt|;
name|TextClassPart
name|text_class
decl_stmt|;
block|}
name|TextClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|TextClassRec
name|textClassRec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* New fields for the Text widget record */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_TextPart
block|{
comment|/* resources */
name|Widget
name|source
decl_stmt|,
name|sink
decl_stmt|;
name|XawTextPosition
name|insertPos
decl_stmt|;
name|XawTextSelection
name|s
decl_stmt|;
name|XawTextSelectType
modifier|*
name|sarray
decl_stmt|;
comment|/* Array to cycle for selections. */
name|XawTextSelectionSalt
modifier|*
name|salt
decl_stmt|;
comment|/* salted away selections */
name|int
name|options
decl_stmt|;
comment|/* wordbreak, scroll, etc. */
name|int
name|dialog_horiz_offset
decl_stmt|;
comment|/* position for popup dialog */
name|int
name|dialog_vert_offset
decl_stmt|;
comment|/* position for popup dialog */
name|Boolean
name|display_caret
decl_stmt|;
comment|/* insertion pt visible iff T */
name|Boolean
name|auto_fill
decl_stmt|;
comment|/* Auto fill mode? */
name|XawTextScrollMode
name|scroll_vert
decl_stmt|,
name|scroll_horiz
decl_stmt|;
comment|/*what type of scrollbars.*/
name|XawTextWrapMode
name|wrap
decl_stmt|;
comment|/* The type of wrapping. */
name|XawTextResizeMode
name|resize
decl_stmt|;
comment|/* what to resize */
name|XawTextMargin
name|r_margin
decl_stmt|;
comment|/* The real margins. */
name|XtCallbackList
name|unrealize_callbacks
decl_stmt|;
comment|/* used for scrollbars */
comment|/* private state */
name|XawTextMargin
name|margin
decl_stmt|;
comment|/* The current margins. */
name|XawTextLineTable
name|lt
decl_stmt|;
name|XawTextScanDirection
name|extendDir
decl_stmt|;
name|XawTextSelection
name|origSel
decl_stmt|;
comment|/* the selection being modified */
name|Time
name|lasttime
decl_stmt|;
comment|/* timestamp of last processed action */
name|Time
name|time
decl_stmt|;
comment|/* time of last key or button action */
name|Position
name|ev_x
decl_stmt|,
name|ev_y
decl_stmt|;
comment|/* x, y coords for key or button action */
name|Widget
name|vbar
decl_stmt|,
name|hbar
decl_stmt|;
comment|/* The scroll bars (none = NULL). */
name|struct
name|SearchAndReplace
modifier|*
name|search
decl_stmt|;
comment|/* Search and replace structure. */
name|Widget
name|file_insert
decl_stmt|;
comment|/* The file insert popup widget. */
name|XawTextPosition
modifier|*
name|updateFrom
decl_stmt|;
comment|/* Array of start positions for update. */
name|XawTextPosition
modifier|*
name|updateTo
decl_stmt|;
comment|/* Array of end positions for update. */
name|int
name|numranges
decl_stmt|;
comment|/* How many update ranges there are. */
name|int
name|maxranges
decl_stmt|;
comment|/* How many ranges we have space for */
name|XawTextPosition
name|lastPos
decl_stmt|;
comment|/* Last position of source. */
name|GC
name|gc
decl_stmt|;
name|Boolean
name|showposition
decl_stmt|;
comment|/* True if we need to show the position. */
name|Boolean
name|hasfocus
decl_stmt|;
comment|/* TRUE if we currently have input focus.*/
name|Boolean
name|update_disabled
decl_stmt|;
comment|/* TRUE if display updating turned off */
name|Boolean
name|single_char
decl_stmt|;
comment|/* Single character replaced. */
name|XawTextPosition
name|old_insert
decl_stmt|;
comment|/* Last insertPos for batched updates */
name|short
name|mult
decl_stmt|;
comment|/* Multiplier. */
name|struct
name|text_move
modifier|*
name|copy_area_offsets
decl_stmt|;
comment|/* Text offset area (linked list) */
comment|/* private state, shared w/Source and Sink */
name|Boolean
name|redisplay_needed
decl_stmt|;
comment|/* in SetValues */
block|}
name|TextPart
typedef|;
end_typedef

begin_comment
comment|/*************************************************************  *  * Resource types private to Text widget.  *  *************************************************************/
end_comment

begin_define
define|#
directive|define
name|XtRScrollMode
value|"ScrollMode"
end_define

begin_define
define|#
directive|define
name|XtRWrapMode
value|"WrapMode"
end_define

begin_define
define|#
directive|define
name|XtRResizeMode
value|"ResizeMode"
end_define

begin_comment
comment|/****************************************************************  *  * Full instance record declaration  *  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_TextRec
block|{
name|CorePart
name|core
decl_stmt|;
name|SimplePart
name|simple
decl_stmt|;
name|TextPart
name|text
decl_stmt|;
block|}
name|TextRec
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawTextP_h */
end_comment

end_unit

