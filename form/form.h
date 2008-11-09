begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2003,2004 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *   Author:  Juergen Pfeifer, 1995,1997                                    *  ****************************************************************************/
end_comment

begin_comment
comment|/* $Id: form.h,v 0.20 2004/12/04 22:22:10 tom Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FORM_H
end_ifndef

begin_define
define|#
directive|define
name|FORM_H
end_define

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_include
include|#
directive|include
file|<eti.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
ifndef|#
directive|ifndef
name|FORM_PRIV_H
typedef|typedef
name|void
modifier|*
name|FIELD_CELL
typedef|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NCURSES_FIELD_INTERNALS
define|#
directive|define
name|NCURSES_FIELD_INTERNALS
comment|/* nothing */
endif|#
directive|endif
typedef|typedef
name|int
name|Form_Options
typedef|;
typedef|typedef
name|int
name|Field_Options
typedef|;
comment|/********** 	*  _PAGE  * 	**********/
typedef|typedef
struct|struct
block|{
name|short
name|pmin
decl_stmt|;
comment|/* index of first field on page			*/
name|short
name|pmax
decl_stmt|;
comment|/* index of last field on page			*/
name|short
name|smin
decl_stmt|;
comment|/* index of top leftmost field on page		*/
name|short
name|smax
decl_stmt|;
comment|/* index of bottom rightmost field on page	*/
block|}
name|_PAGE
typedef|;
comment|/********** 	*  FIELD  * 	**********/
typedef|typedef
struct|struct
name|fieldnode
block|{
name|unsigned
name|short
name|status
decl_stmt|;
comment|/* flags			*/
name|short
name|rows
decl_stmt|;
comment|/* size in rows			*/
name|short
name|cols
decl_stmt|;
comment|/* size in cols			*/
name|short
name|frow
decl_stmt|;
comment|/* first row			*/
name|short
name|fcol
decl_stmt|;
comment|/* first col			*/
name|int
name|drows
decl_stmt|;
comment|/* dynamic rows			*/
name|int
name|dcols
decl_stmt|;
comment|/* dynamic cols			*/
name|int
name|maxgrow
decl_stmt|;
comment|/* maximum field growth		*/
name|int
name|nrow
decl_stmt|;
comment|/* off-screen rows		*/
name|short
name|nbuf
decl_stmt|;
comment|/* additional buffers		*/
name|short
name|just
decl_stmt|;
comment|/* justification		*/
name|short
name|page
decl_stmt|;
comment|/* page on form			*/
name|short
name|index
decl_stmt|;
comment|/* into form -> field		*/
name|int
name|pad
decl_stmt|;
comment|/* pad character		*/
name|chtype
name|fore
decl_stmt|;
comment|/* foreground attribute		*/
name|chtype
name|back
decl_stmt|;
comment|/* background attribute		*/
name|Field_Options
name|opts
decl_stmt|;
comment|/* options			*/
name|struct
name|fieldnode
modifier|*
name|snext
decl_stmt|;
comment|/* sorted order pointer		*/
name|struct
name|fieldnode
modifier|*
name|sprev
decl_stmt|;
comment|/* sorted order pointer		*/
name|struct
name|fieldnode
modifier|*
name|link
decl_stmt|;
comment|/* linked field chain		*/
name|struct
name|formnode
modifier|*
name|form
decl_stmt|;
comment|/* containing form		*/
name|struct
name|typenode
modifier|*
name|type
decl_stmt|;
comment|/* field type			*/
name|void
modifier|*
name|arg
decl_stmt|;
comment|/* argument for type		*/
name|FIELD_CELL
modifier|*
name|buf
decl_stmt|;
comment|/* field buffers		*/
name|void
modifier|*
name|usrptr
decl_stmt|;
comment|/* user pointer			*/
comment|/*    * The wide-character configuration requires extra information.  Because    * there are existing applications that manipulate the members of FIELD    * directly, we cannot make the struct opaque.  Offsets of members up to    * this point are the same in the narrow- and wide-character configuration.    * But note that the type of buf depends on the configuration, and is made    * opaque for that reason.    */
name|NCURSES_FIELD_INTERNALS
block|}
name|FIELD
typedef|;
comment|/************** 	*  FIELDTYPE  * 	**************/
typedef|typedef
struct|struct
name|typenode
block|{
name|unsigned
name|short
name|status
decl_stmt|;
comment|/* flags		*/
name|long
name|ref
decl_stmt|;
comment|/* reference count	*/
name|struct
name|typenode
modifier|*
name|left
decl_stmt|;
comment|/* ptr to operand for | */
name|struct
name|typenode
modifier|*
name|right
decl_stmt|;
comment|/* ptr to operand for | */
name|void
modifier|*
function_decl|(
modifier|*
name|makearg
function_decl|)
parameter_list|(
name|va_list
modifier|*
parameter_list|)
function_decl|;
comment|/* make fieldtype arg	*/
name|void
modifier|*
function_decl|(
modifier|*
name|copyarg
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* copy fieldtype arg	*/
name|void
function_decl|(
modifier|*
name|freearg
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* free fieldtype arg	*/
name|bool
function_decl|(
modifier|*
name|fcheck
function_decl|)
parameter_list|(
name|FIELD
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* field validation	*/
name|bool
function_decl|(
modifier|*
name|ccheck
function_decl|)
parameter_list|(
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* character validation */
name|bool
function_decl|(
modifier|*
name|next
function_decl|)
parameter_list|(
name|FIELD
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* enumerate next value */
name|bool
function_decl|(
modifier|*
name|prev
function_decl|)
parameter_list|(
name|FIELD
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* enumerate prev value */
block|}
name|FIELDTYPE
typedef|;
comment|/********* 	*  FORM  * 	*********/
typedef|typedef
struct|struct
name|formnode
block|{
name|unsigned
name|short
name|status
decl_stmt|;
comment|/* flags			*/
name|short
name|rows
decl_stmt|;
comment|/* size in rows			*/
name|short
name|cols
decl_stmt|;
comment|/* size in cols			*/
name|int
name|currow
decl_stmt|;
comment|/* current row in field window	*/
name|int
name|curcol
decl_stmt|;
comment|/* current col in field window	*/
name|int
name|toprow
decl_stmt|;
comment|/* in scrollable field window	*/
name|int
name|begincol
decl_stmt|;
comment|/* in horiz. scrollable field	*/
name|short
name|maxfield
decl_stmt|;
comment|/* number of fields		*/
name|short
name|maxpage
decl_stmt|;
comment|/* number of pages		*/
name|short
name|curpage
decl_stmt|;
comment|/* index into page		*/
name|Form_Options
name|opts
decl_stmt|;
comment|/* options			*/
name|WINDOW
modifier|*
name|win
decl_stmt|;
comment|/* window			*/
name|WINDOW
modifier|*
name|sub
decl_stmt|;
comment|/* subwindow			*/
name|WINDOW
modifier|*
name|w
decl_stmt|;
comment|/* window for current field	*/
name|FIELD
modifier|*
modifier|*
name|field
decl_stmt|;
comment|/* field [maxfield]		*/
name|FIELD
modifier|*
name|current
decl_stmt|;
comment|/* current field		*/
name|_PAGE
modifier|*
name|page
decl_stmt|;
comment|/* page [maxpage]		*/
name|void
modifier|*
name|usrptr
decl_stmt|;
comment|/* user pointer			*/
name|void
function_decl|(
modifier|*
name|forminit
function_decl|)
parameter_list|(
name|struct
name|formnode
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|formterm
function_decl|)
parameter_list|(
name|struct
name|formnode
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|fieldinit
function_decl|)
parameter_list|(
name|struct
name|formnode
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|fieldterm
function_decl|)
parameter_list|(
name|struct
name|formnode
modifier|*
parameter_list|)
function_decl|;
block|}
name|FORM
typedef|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|Form_Hook
function_decl|)
parameter_list|(
name|FORM
modifier|*
parameter_list|)
function_decl|;
comment|/*************************** 	*  miscellaneous #defines  * 	***************************/
comment|/* field justification */
define|#
directive|define
name|NO_JUSTIFICATION
value|(0)
define|#
directive|define
name|JUSTIFY_LEFT
value|(1)
define|#
directive|define
name|JUSTIFY_CENTER
value|(2)
define|#
directive|define
name|JUSTIFY_RIGHT
value|(3)
comment|/* field options */
define|#
directive|define
name|O_VISIBLE
value|(0x0001U)
define|#
directive|define
name|O_ACTIVE
value|(0x0002U)
define|#
directive|define
name|O_PUBLIC
value|(0x0004U)
define|#
directive|define
name|O_EDIT
value|(0x0008U)
define|#
directive|define
name|O_WRAP
value|(0x0010U)
define|#
directive|define
name|O_BLANK
value|(0x0020U)
define|#
directive|define
name|O_AUTOSKIP
value|(0x0040U)
define|#
directive|define
name|O_NULLOK
value|(0x0080U)
define|#
directive|define
name|O_PASSOK
value|(0x0100U)
define|#
directive|define
name|O_STATIC
value|(0x0200U)
comment|/* form options */
define|#
directive|define
name|O_NL_OVERLOAD
value|(0x0001U)
define|#
directive|define
name|O_BS_OVERLOAD
value|(0x0002U)
comment|/* form driver commands */
define|#
directive|define
name|REQ_NEXT_PAGE
value|(KEY_MAX + 1)
comment|/* move to next page		*/
define|#
directive|define
name|REQ_PREV_PAGE
value|(KEY_MAX + 2)
comment|/* move to previous page	*/
define|#
directive|define
name|REQ_FIRST_PAGE
value|(KEY_MAX + 3)
comment|/* move to first page		*/
define|#
directive|define
name|REQ_LAST_PAGE
value|(KEY_MAX + 4)
comment|/* move to last page		*/
define|#
directive|define
name|REQ_NEXT_FIELD
value|(KEY_MAX + 5)
comment|/* move to next field		*/
define|#
directive|define
name|REQ_PREV_FIELD
value|(KEY_MAX + 6)
comment|/* move to previous field	*/
define|#
directive|define
name|REQ_FIRST_FIELD
value|(KEY_MAX + 7)
comment|/* move to first field		*/
define|#
directive|define
name|REQ_LAST_FIELD
value|(KEY_MAX + 8)
comment|/* move to last field		*/
define|#
directive|define
name|REQ_SNEXT_FIELD
value|(KEY_MAX + 9)
comment|/* move to sorted next field	*/
define|#
directive|define
name|REQ_SPREV_FIELD
value|(KEY_MAX + 10)
comment|/* move to sorted prev field	*/
define|#
directive|define
name|REQ_SFIRST_FIELD
value|(KEY_MAX + 11)
comment|/* move to sorted first field	*/
define|#
directive|define
name|REQ_SLAST_FIELD
value|(KEY_MAX + 12)
comment|/* move to sorted last field	*/
define|#
directive|define
name|REQ_LEFT_FIELD
value|(KEY_MAX + 13)
comment|/* move to left to field	*/
define|#
directive|define
name|REQ_RIGHT_FIELD
value|(KEY_MAX + 14)
comment|/* move to right to field	*/
define|#
directive|define
name|REQ_UP_FIELD
value|(KEY_MAX + 15)
comment|/* move to up to field		*/
define|#
directive|define
name|REQ_DOWN_FIELD
value|(KEY_MAX + 16)
comment|/* move to down to field	*/
define|#
directive|define
name|REQ_NEXT_CHAR
value|(KEY_MAX + 17)
comment|/* move to next char in field	*/
define|#
directive|define
name|REQ_PREV_CHAR
value|(KEY_MAX + 18)
comment|/* move to prev char in field	*/
define|#
directive|define
name|REQ_NEXT_LINE
value|(KEY_MAX + 19)
comment|/* move to next line in field	*/
define|#
directive|define
name|REQ_PREV_LINE
value|(KEY_MAX + 20)
comment|/* move to prev line in field	*/
define|#
directive|define
name|REQ_NEXT_WORD
value|(KEY_MAX + 21)
comment|/* move to next word in field	*/
define|#
directive|define
name|REQ_PREV_WORD
value|(KEY_MAX + 22)
comment|/* move to prev word in field	*/
define|#
directive|define
name|REQ_BEG_FIELD
value|(KEY_MAX + 23)
comment|/* move to first char in field	*/
define|#
directive|define
name|REQ_END_FIELD
value|(KEY_MAX + 24)
comment|/* move after last char in fld	*/
define|#
directive|define
name|REQ_BEG_LINE
value|(KEY_MAX + 25)
comment|/* move to beginning of line	*/
define|#
directive|define
name|REQ_END_LINE
value|(KEY_MAX + 26)
comment|/* move after last char in line	*/
define|#
directive|define
name|REQ_LEFT_CHAR
value|(KEY_MAX + 27)
comment|/* move left in field		*/
define|#
directive|define
name|REQ_RIGHT_CHAR
value|(KEY_MAX + 28)
comment|/* move right in field		*/
define|#
directive|define
name|REQ_UP_CHAR
value|(KEY_MAX + 29)
comment|/* move up in field		*/
define|#
directive|define
name|REQ_DOWN_CHAR
value|(KEY_MAX + 30)
comment|/* move down in field		*/
define|#
directive|define
name|REQ_NEW_LINE
value|(KEY_MAX + 31)
comment|/* insert/overlay new line	*/
define|#
directive|define
name|REQ_INS_CHAR
value|(KEY_MAX + 32)
comment|/* insert blank char at cursor	*/
define|#
directive|define
name|REQ_INS_LINE
value|(KEY_MAX + 33)
comment|/* insert blank line at cursor	*/
define|#
directive|define
name|REQ_DEL_CHAR
value|(KEY_MAX + 34)
comment|/* delete char at cursor	*/
define|#
directive|define
name|REQ_DEL_PREV
value|(KEY_MAX + 35)
comment|/* delete char before cursor	*/
define|#
directive|define
name|REQ_DEL_LINE
value|(KEY_MAX + 36)
comment|/* delete line at cursor	*/
define|#
directive|define
name|REQ_DEL_WORD
value|(KEY_MAX + 37)
comment|/* delete word at cursor	*/
define|#
directive|define
name|REQ_CLR_EOL
value|(KEY_MAX + 38)
comment|/* clear to end of line		*/
define|#
directive|define
name|REQ_CLR_EOF
value|(KEY_MAX + 39)
comment|/* clear to end of field	*/
define|#
directive|define
name|REQ_CLR_FIELD
value|(KEY_MAX + 40)
comment|/* clear entire field		*/
define|#
directive|define
name|REQ_OVL_MODE
value|(KEY_MAX + 41)
comment|/* begin overlay mode		*/
define|#
directive|define
name|REQ_INS_MODE
value|(KEY_MAX + 42)
comment|/* begin insert mode		*/
define|#
directive|define
name|REQ_SCR_FLINE
value|(KEY_MAX + 43)
comment|/* scroll field forward a line	*/
define|#
directive|define
name|REQ_SCR_BLINE
value|(KEY_MAX + 44)
comment|/* scroll field backward a line	*/
define|#
directive|define
name|REQ_SCR_FPAGE
value|(KEY_MAX + 45)
comment|/* scroll field forward a page	*/
define|#
directive|define
name|REQ_SCR_BPAGE
value|(KEY_MAX + 46)
comment|/* scroll field backward a page	*/
define|#
directive|define
name|REQ_SCR_FHPAGE
value|(KEY_MAX + 47)
comment|/* scroll field forward	 half page */
define|#
directive|define
name|REQ_SCR_BHPAGE
value|(KEY_MAX + 48)
comment|/* scroll field backward half page */
define|#
directive|define
name|REQ_SCR_FCHAR
value|(KEY_MAX + 49)
comment|/* horizontal scroll char	*/
define|#
directive|define
name|REQ_SCR_BCHAR
value|(KEY_MAX + 50)
comment|/* horizontal scroll char	*/
define|#
directive|define
name|REQ_SCR_HFLINE
value|(KEY_MAX + 51)
comment|/* horizontal scroll line	*/
define|#
directive|define
name|REQ_SCR_HBLINE
value|(KEY_MAX + 52)
comment|/* horizontal scroll line	*/
define|#
directive|define
name|REQ_SCR_HFHALF
value|(KEY_MAX + 53)
comment|/* horizontal scroll half line	*/
define|#
directive|define
name|REQ_SCR_HBHALF
value|(KEY_MAX + 54)
comment|/* horizontal scroll half line	*/
define|#
directive|define
name|REQ_VALIDATION
value|(KEY_MAX + 55)
comment|/* validate field		*/
define|#
directive|define
name|REQ_NEXT_CHOICE
value|(KEY_MAX + 56)
comment|/* display next field choice	*/
define|#
directive|define
name|REQ_PREV_CHOICE
value|(KEY_MAX + 57)
comment|/* display prev field choice	*/
define|#
directive|define
name|MIN_FORM_COMMAND
value|(KEY_MAX + 1)
comment|/* used by form_driver		*/
define|#
directive|define
name|MAX_FORM_COMMAND
value|(KEY_MAX + 57)
comment|/* used by form_driver		*/
if|#
directive|if
name|defined
argument_list|(
name|MAX_COMMAND
argument_list|)
if|#
directive|if
operator|(
name|MAX_FORM_COMMAND
operator|>
name|MAX_COMMAND
operator|)
error|#
directive|error
error|Something is wrong -- MAX_FORM_COMMAND is greater than MAX_COMMAND
elif|#
directive|elif
operator|(
name|MAX_COMMAND
operator|!=
operator|(
name|KEY_MAX
operator|+
literal|128
operator|)
operator|)
error|#
directive|error
error|Something is wrong -- MAX_COMMAND is already inconsistently defined.
endif|#
directive|endif
else|#
directive|else
define|#
directive|define
name|MAX_COMMAND
value|(KEY_MAX + 128)
endif|#
directive|endif
comment|/************************* 	*  standard field types  * 	*************************/
extern|extern NCURSES_EXPORT_VAR(FIELDTYPE *
block|)
name|TYPE_ALPHA
expr_stmt|;
end_extern

begin_extern
extern|extern NCURSES_EXPORT_VAR(FIELDTYPE *
end_extern

begin_expr_stmt
unit|)
name|TYPE_ALNUM
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT_VAR(FIELDTYPE *
end_extern

begin_expr_stmt
unit|)
name|TYPE_ENUM
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT_VAR(FIELDTYPE *
end_extern

begin_expr_stmt
unit|)
name|TYPE_INTEGER
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT_VAR(FIELDTYPE *
end_extern

begin_expr_stmt
unit|)
name|TYPE_NUMERIC
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT_VAR(FIELDTYPE *
end_extern

begin_expr_stmt
unit|)
name|TYPE_REGEXP
expr_stmt|;
end_expr_stmt

begin_comment
comment|/************************************ 	*  built-in additional field types  * 	*  They are not defined in SVr4     * 	************************************/
end_comment

begin_extern
extern|extern NCURSES_EXPORT_VAR(FIELDTYPE *
end_extern

begin_expr_stmt
unit|)
name|TYPE_IPV4
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Internet IP Version 4 address */
end_comment

begin_comment
comment|/*********************** 	*   Default objects    * 	***********************/
end_comment

begin_extern
extern|extern NCURSES_EXPORT_VAR(FORM *
end_extern

begin_expr_stmt
unit|)
name|_nc_Default_Form
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT_VAR(FIELD *
end_extern

begin_expr_stmt
unit|)
name|_nc_Default_Field
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*********************** 	*  FIELDTYPE routines  * 	***********************/
end_comment

begin_extern
extern|extern NCURSES_EXPORT(FIELDTYPE *
end_extern

begin_expr_stmt
unit|)
name|new_fieldtype
argument_list|(
name|bool
argument_list|(
operator|*
specifier|const
name|field_check
argument_list|)
argument_list|(
name|FIELD
operator|*
argument_list|,
specifier|const
name|void
operator|*
argument_list|)
argument_list|,
name|bool
argument_list|(
operator|*
specifier|const
name|char_check
argument_list|)
argument_list|(
name|int
argument_list|,
specifier|const
name|void
operator|*
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(FIELDTYPE *
end_extern

begin_expr_stmt
unit|)
name|link_fieldtype
argument_list|(
name|FIELDTYPE
operator|*
argument_list|,
name|FIELDTYPE
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|free_fieldtype
argument_list|(
name|FIELDTYPE
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_fieldtype_arg
argument_list|(
name|FIELDTYPE
operator|*
argument_list|,
name|void
operator|*
operator|(
operator|*
specifier|const
name|make_arg
operator|)
operator|(
name|va_list
operator|*
operator|)
argument_list|,
name|void
operator|*
operator|(
operator|*
specifier|const
name|copy_arg
operator|)
operator|(
specifier|const
name|void
operator|*
operator|)
argument_list|,
name|void
argument_list|(
operator|*
specifier|const
name|free_arg
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_fieldtype_choice
argument_list|(
name|FIELDTYPE
operator|*
argument_list|,
name|bool
argument_list|(
operator|*
specifier|const
name|next_choice
argument_list|)
argument_list|(
name|FIELD
operator|*
argument_list|,
specifier|const
name|void
operator|*
argument_list|)
argument_list|,
name|bool
argument_list|(
operator|*
specifier|const
name|prev_choice
argument_list|)
argument_list|(
name|FIELD
operator|*
argument_list|,
specifier|const
name|void
operator|*
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/******************* 	*  FIELD routines  * 	*******************/
end_comment

begin_extern
extern|extern NCURSES_EXPORT(FIELD *
end_extern

begin_expr_stmt
unit|)
name|new_field
argument_list|(
name|int
argument_list|,
name|int
argument_list|,
name|int
argument_list|,
name|int
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(FIELD *
end_extern

begin_expr_stmt
unit|)
name|dup_field
argument_list|(
name|FIELD
operator|*
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(FIELD *
end_extern

begin_expr_stmt
unit|)
name|link_field
argument_list|(
name|FIELD
operator|*
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|free_field
argument_list|(
name|FIELD
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|field_info
argument_list|(
specifier|const
name|FIELD
operator|*
argument_list|,
name|int
operator|*
argument_list|,
name|int
operator|*
argument_list|,
name|int
operator|*
argument_list|,
name|int
operator|*
argument_list|,
name|int
operator|*
argument_list|,
name|int
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|dynamic_field_info
argument_list|(
specifier|const
name|FIELD
operator|*
argument_list|,
name|int
operator|*
argument_list|,
name|int
operator|*
argument_list|,
name|int
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_max_field
argument_list|(
name|FIELD
operator|*
argument_list|,
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|move_field
argument_list|(
name|FIELD
operator|*
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_field_type
argument_list|(
name|FIELD
operator|*
argument_list|,
name|FIELDTYPE
operator|*
argument_list|,
operator|...
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_new_page
argument_list|(
name|FIELD
operator|*
argument_list|,
name|bool
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_field_just
argument_list|(
name|FIELD
operator|*
argument_list|,
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|field_just
argument_list|(
specifier|const
name|FIELD
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_field_fore
argument_list|(
name|FIELD
operator|*
argument_list|,
name|chtype
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_field_back
argument_list|(
name|FIELD
operator|*
argument_list|,
name|chtype
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_field_pad
argument_list|(
name|FIELD
operator|*
argument_list|,
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|field_pad
argument_list|(
specifier|const
name|FIELD
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_field_buffer
argument_list|(
name|FIELD
operator|*
argument_list|,
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_field_status
argument_list|(
name|FIELD
operator|*
argument_list|,
name|bool
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_field_userptr
argument_list|(
name|FIELD
operator|*
argument_list|,
name|void
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_field_opts
argument_list|(
name|FIELD
operator|*
argument_list|,
name|Field_Options
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|field_opts_on
argument_list|(
name|FIELD
operator|*
argument_list|,
name|Field_Options
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|field_opts_off
argument_list|(
name|FIELD
operator|*
argument_list|,
name|Field_Options
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(chtype
end_extern

begin_expr_stmt
unit|)
name|field_fore
argument_list|(
specifier|const
name|FIELD
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(chtype
end_extern

begin_expr_stmt
unit|)
name|field_back
argument_list|(
specifier|const
name|FIELD
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(bool
end_extern

begin_expr_stmt
unit|)
name|new_page
argument_list|(
specifier|const
name|FIELD
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(bool
end_extern

begin_expr_stmt
unit|)
name|field_status
argument_list|(
specifier|const
name|FIELD
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void *
end_extern

begin_expr_stmt
unit|)
name|field_arg
argument_list|(
specifier|const
name|FIELD
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void *
end_extern

begin_expr_stmt
unit|)
name|field_userptr
argument_list|(
specifier|const
name|FIELD
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(FIELDTYPE *
end_extern

begin_expr_stmt
unit|)
name|field_type
argument_list|(
specifier|const
name|FIELD
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(char *
end_extern

begin_expr_stmt
unit|)
name|field_buffer
argument_list|(
specifier|const
name|FIELD
operator|*
argument_list|,
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(Field_Options
end_extern

begin_expr_stmt
unit|)
name|field_opts
argument_list|(
specifier|const
name|FIELD
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/****************** 	*  FORM routines  * 	******************/
end_comment

begin_extern
extern|extern NCURSES_EXPORT(FORM *
end_extern

begin_expr_stmt
unit|)
name|new_form
argument_list|(
name|FIELD
operator|*
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(FIELD **
end_extern

begin_expr_stmt
unit|)
name|form_fields
argument_list|(
specifier|const
name|FORM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(FIELD *
end_extern

begin_expr_stmt
unit|)
name|current_field
argument_list|(
specifier|const
name|FORM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(WINDOW *
end_extern

begin_expr_stmt
unit|)
name|form_win
argument_list|(
specifier|const
name|FORM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(WINDOW *
end_extern

begin_expr_stmt
unit|)
name|form_sub
argument_list|(
specifier|const
name|FORM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(Form_Hook
end_extern

begin_expr_stmt
unit|)
name|form_init
argument_list|(
specifier|const
name|FORM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(Form_Hook
end_extern

begin_expr_stmt
unit|)
name|form_term
argument_list|(
specifier|const
name|FORM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(Form_Hook
end_extern

begin_expr_stmt
unit|)
name|field_init
argument_list|(
specifier|const
name|FORM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(Form_Hook
end_extern

begin_expr_stmt
unit|)
name|field_term
argument_list|(
specifier|const
name|FORM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|free_form
argument_list|(
name|FORM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_form_fields
argument_list|(
name|FORM
operator|*
argument_list|,
name|FIELD
operator|*
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|field_count
argument_list|(
specifier|const
name|FORM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_form_win
argument_list|(
name|FORM
operator|*
argument_list|,
name|WINDOW
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_form_sub
argument_list|(
name|FORM
operator|*
argument_list|,
name|WINDOW
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_current_field
argument_list|(
name|FORM
operator|*
argument_list|,
name|FIELD
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|field_index
argument_list|(
specifier|const
name|FIELD
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_form_page
argument_list|(
name|FORM
operator|*
argument_list|,
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|form_page
argument_list|(
specifier|const
name|FORM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|scale_form
argument_list|(
specifier|const
name|FORM
operator|*
argument_list|,
name|int
operator|*
argument_list|,
name|int
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_form_init
argument_list|(
name|FORM
operator|*
argument_list|,
name|Form_Hook
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_form_term
argument_list|(
name|FORM
operator|*
argument_list|,
name|Form_Hook
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_field_init
argument_list|(
name|FORM
operator|*
argument_list|,
name|Form_Hook
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_field_term
argument_list|(
name|FORM
operator|*
argument_list|,
name|Form_Hook
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|post_form
argument_list|(
name|FORM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|unpost_form
argument_list|(
name|FORM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|pos_form_cursor
argument_list|(
name|FORM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|form_driver
argument_list|(
name|FORM
operator|*
argument_list|,
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_form_userptr
argument_list|(
name|FORM
operator|*
argument_list|,
name|void
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|set_form_opts
argument_list|(
name|FORM
operator|*
argument_list|,
name|Form_Options
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|form_opts_on
argument_list|(
name|FORM
operator|*
argument_list|,
name|Form_Options
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|form_opts_off
argument_list|(
name|FORM
operator|*
argument_list|,
name|Form_Options
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|form_request_by_name
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(const char *
end_extern

begin_expr_stmt
unit|)
name|form_request_name
argument_list|(
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void *
end_extern

begin_expr_stmt
unit|)
name|form_userptr
argument_list|(
specifier|const
name|FORM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(Form_Options
end_extern

begin_expr_stmt
unit|)
name|form_opts
argument_list|(
specifier|const
name|FORM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(bool
end_extern

begin_expr_stmt
unit|)
name|data_ahead
argument_list|(
specifier|const
name|FORM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(bool
end_extern

begin_expr_stmt
unit|)
name|data_behind
argument_list|(
specifier|const
name|FORM
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FORM_H */
end_comment

end_unit

