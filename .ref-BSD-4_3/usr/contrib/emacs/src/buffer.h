begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Header file for the buffer manipulation primitives.    Copyright (C) 1985 Richard M. Stallman.  This file is part of GNU Emacs.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU Emacs General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU Emacs, but only under the conditions described in the GNU Emacs General Public License.   A copy of this license is supposed to have been given to you along with GNU Emacs so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_include
include|#
directive|include
file|"undo.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_define
define|#
directive|define
name|SetPoint
value|point =
end_define

begin_define
define|#
directive|define
name|PointRight
value|point +=
end_define

begin_define
define|#
directive|define
name|PointLeft
value|point -=
end_define

begin_escape
end_escape

begin_struct
struct|struct
name|buffer_text
block|{
name|unsigned
name|char
modifier|*
name|p1
decl_stmt|;
comment|/* Address of first data char, minus 1 */
name|unsigned
name|char
modifier|*
name|p2
decl_stmt|;
comment|/* p1 plus gap size */
name|int
name|size1
decl_stmt|;
comment|/* # characters before gap */
name|int
name|size2
decl_stmt|;
comment|/* # characters after gap */
name|int
name|gap
decl_stmt|;
comment|/* gap size in chars */
name|int
name|modified
decl_stmt|;
comment|/* tick at which contents last modified */
name|int
name|head_clip
decl_stmt|;
comment|/* # of first char that's visible (origin 1) */
name|int
name|tail_clip
decl_stmt|;
comment|/* # chars not visible at end of buffer */
name|int
name|pointloc
decl_stmt|;
comment|/* # of char point is at (origin 1) */
block|}
struct|;
end_struct

begin_comment
comment|/* structure that defines a buffer */
end_comment

begin_struct
struct|struct
name|buffer
block|{
name|struct
name|buffer_text
name|text
decl_stmt|;
comment|/* This describes the buffer's text */
name|Lisp_Object
name|number
decl_stmt|;
comment|/* buffer number, assigned when buffer made */
name|Lisp_Object
name|name
decl_stmt|;
comment|/* the name of this buffer */
name|Lisp_Object
name|filename
decl_stmt|;
comment|/* the name of the file associated 				   with this buffer */
name|Lisp_Object
name|directory
decl_stmt|;
comment|/* Dir for expanding relative pathnames */
name|int
name|save_modified
decl_stmt|;
comment|/* Value of text.modified when buffer last saved */
name|Lisp_Object
name|save_length
decl_stmt|;
comment|/* Length of file when last read or saved. */
name|int
name|modtime
decl_stmt|;
comment|/* Set to the modtime of the file when read */
comment|/* Really should be time_t */
name|int
name|backed_up
decl_stmt|;
comment|/* true iff this buffer has been been backed 				   up (if you write to its associated file 				   and it hasn't been backed up, then a 				   backup will be made) */
name|Lisp_Object
name|auto_save_file_name
decl_stmt|;
comment|/* file name used for auto-saving this 				   buffer */
name|int
name|auto_save_modified
decl_stmt|;
comment|/* the value of text.modified at the last auto-save. */
name|Lisp_Object
name|read_only
decl_stmt|;
comment|/* Non-nil if buffer read-only */
name|Lisp_Object
name|markers
decl_stmt|;
comment|/* the markers that refer to this buffer. 				   This is actually a single marker --- 				   successive elements in its marker `chain' 				   are the other markers referring to this 				   buffer */
name|Lisp_Object
name|mark
decl_stmt|;
comment|/* "The mark"; may be nil */
name|Lisp_Object
name|major_mode
decl_stmt|;
comment|/* Symbol naming major mode (eg lisp-mode) */
name|Lisp_Object
name|mode_name
decl_stmt|;
comment|/* Pretty name of major mode (eg "Lisp") */
name|Lisp_Object
name|mode_line_format
decl_stmt|;
comment|/* Format string for mode line */
name|Lisp_Object
name|keymap
decl_stmt|;
comment|/* Keys that are bound local to this buffer 				   (stuff like $J) */
name|struct
name|Lisp_Vector
modifier|*
name|syntax_table_v
decl_stmt|;
comment|/* the syntax table in use */
name|Lisp_Object
name|abbrev_table
decl_stmt|;
comment|/* This buffer's local abbrev table */
comment|/* Values of several buffer-local variables */
comment|/* tab-width is buffer-local so that redisplay can find it        in buffers that are not current */
name|Lisp_Object
name|case_fold_search
decl_stmt|;
name|Lisp_Object
name|tab_width
decl_stmt|;
name|Lisp_Object
name|fill_column
decl_stmt|;
name|Lisp_Object
name|left_margin
decl_stmt|;
name|Lisp_Object
name|auto_fill_hook
decl_stmt|;
comment|/* Function to call when insert space past fiull column */
comment|/* Alist of elements (SYMBOL . VALUE-IN-THIS-BUFFER)      for all per-buffer variables of this buffer.  */
name|Lisp_Object
name|local_var_alist
decl_stmt|;
comment|/* Position in buffer at which display started        the last time this buffer was displayed */
name|int
name|last_window_start
decl_stmt|;
comment|/* Non-nil means do not display continuation lines */
name|Lisp_Object
name|truncate_lines
decl_stmt|;
comment|/* Non-nil means display ctl chars with uparrow */
name|Lisp_Object
name|ctl_arrow
decl_stmt|;
comment|/* Non-nil means do selective display;        See doc string in syms_of_buffer (buffer.c) for details.  */
name|Lisp_Object
name|selective_display
decl_stmt|;
comment|/* Alist of (FUNCTION . STRING) for each minor mode enabled in buffer. */
name|Lisp_Object
name|minor_modes
decl_stmt|;
comment|/* Undo records for changes in this buffer. */
name|struct
name|UndoData
modifier|*
name|undodata
decl_stmt|;
comment|/* t if "self-insertion" should overwrite */
name|Lisp_Object
name|overwrite_mode
decl_stmt|;
comment|/* non-nil means abbrev mode is on.  Expand abbrevs automatically. */
name|Lisp_Object
name|abbrev_mode
decl_stmt|;
comment|/* Next buffer, in chain of all buffers that exist.  */
name|struct
name|buffer
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|buffer
modifier|*
name|bf_cur
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the current buffer */
end_comment

begin_comment
comment|/* This structure contains data describing the text of the current buffer.  Switching buffers swaps their text data in and out of here */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|buffer_text
name|bf_text
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|bf_p1
value|bf_text.p1
end_define

begin_define
define|#
directive|define
name|bf_p2
value|bf_text.p2
end_define

begin_define
define|#
directive|define
name|bf_s1
value|bf_text.size1
end_define

begin_define
define|#
directive|define
name|bf_s2
value|bf_text.size2
end_define

begin_define
define|#
directive|define
name|bf_gap
value|bf_text.gap
end_define

begin_define
define|#
directive|define
name|bf_modified
value|bf_text.modified
end_define

begin_define
define|#
directive|define
name|bf_head_clip
value|bf_text.head_clip
end_define

begin_define
define|#
directive|define
name|bf_tail_clip
value|bf_text.tail_clip
end_define

begin_define
define|#
directive|define
name|point
value|bf_text.pointloc
end_define

begin_comment
comment|/* Lowest legal value of point for current buffer */
end_comment

begin_define
define|#
directive|define
name|FirstCharacter
value|bf_text.head_clip
end_define

begin_comment
comment|/* Number of last visible character in current buffer */
end_comment

begin_comment
comment|/* The highest legal value for point is one greater than this */
end_comment

begin_define
define|#
directive|define
name|NumCharacters
value|(bf_text.size1+bf_text.size2-bf_text.tail_clip)
end_define

begin_comment
comment|/* Return character at position n.  No range checking */
end_comment

begin_define
define|#
directive|define
name|CharAt
parameter_list|(
name|n
parameter_list|)
value|*(((n)>bf_s1 ? bf_p2 : bf_p1) + (n))
end_define

begin_function_decl
specifier|extern
name|void
name|reset_buffer
parameter_list|()
function_decl|;
end_function_decl

end_unit

