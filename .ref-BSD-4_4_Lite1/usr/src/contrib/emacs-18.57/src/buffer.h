begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Header file for the buffer manipulation primitives.    Copyright (C) 1985, 1986, 1990 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|SET_PT
value|PT =
end_define

begin_comment
comment|/* Just for laughs, use the same names as in ITS TECO, around 1973.  */
end_comment

begin_comment
comment|/* Character position of beginning of buffer.  */
end_comment

begin_define
define|#
directive|define
name|BEG
value|(1)
end_define

begin_comment
comment|/* Character position of beginning of accessible range of buffer.  */
end_comment

begin_define
define|#
directive|define
name|BEGV
value|(current_buffer->text.begv)
end_define

begin_comment
comment|/* Character position of point in buffer.  */
end_comment

begin_define
define|#
directive|define
name|PT
value|(current_buffer->text.pt)
end_define

begin_comment
comment|/* Character position of gap in buffer.  */
end_comment

begin_define
define|#
directive|define
name|GPT
value|(current_buffer->text.gpt)
end_define

begin_comment
comment|/* Character position of end of accessible range of buffer.  */
end_comment

begin_define
define|#
directive|define
name|ZV
value|(current_buffer->text.zv)
end_define

begin_comment
comment|/* Character position of end of buffer.  */
end_comment

begin_define
define|#
directive|define
name|Z
value|(current_buffer->text.z)
end_define

begin_comment
comment|/* Modification count.  */
end_comment

begin_define
define|#
directive|define
name|MODIFF
value|(current_buffer->text.modiff)
end_define

begin_comment
comment|/* Address of beginning of buffer.  */
end_comment

begin_define
define|#
directive|define
name|BEG_ADDR
value|(current_buffer->text.beg)
end_define

begin_comment
comment|/* Address of beginning of accessible range of buffer.  */
end_comment

begin_define
define|#
directive|define
name|BEGV_ADDR
value|(&FETCH_CHAR (current_buffer->text.begv))
end_define

begin_comment
comment|/* Address of point in buffer.  */
end_comment

begin_define
define|#
directive|define
name|PT_ADDR
value|(&FETCH_CHAR (current_buffer->text.pt))
end_define

begin_comment
comment|/* Address of beginning of gap in buffer.  */
end_comment

begin_define
define|#
directive|define
name|GPT_ADDR
value|(current_buffer->text.beg + current_buffer->text.gpt - 1)
end_define

begin_comment
comment|/* Address of end of gap in buffer.  */
end_comment

begin_define
define|#
directive|define
name|GAP_END_ADDR
value|(current_buffer->text.beg + current_buffer->text.gpt + current_buffer->text.gap_size - 1)
end_define

begin_comment
comment|/* Address of end of accessible range of buffer.  */
end_comment

begin_define
define|#
directive|define
name|ZV_ADDR
value|(&FETCH_CHAR (current_buffer->text.zv))
end_define

begin_comment
comment|/* Size of gap.  */
end_comment

begin_define
define|#
directive|define
name|GAP_SIZE
value|(current_buffer->text.gap_size)
end_define

begin_comment
comment|/* Now similar macros for a specified buffer.    Note that many of these evaluate the buffer argument more than once.  */
end_comment

begin_comment
comment|/* Character position of beginning of buffer.  */
end_comment

begin_define
define|#
directive|define
name|BUF_BEG
parameter_list|(
name|buf
parameter_list|)
value|(1)
end_define

begin_comment
comment|/* Character position of beginning of accessible range of buffer.  */
end_comment

begin_define
define|#
directive|define
name|BUF_BEGV
parameter_list|(
name|buf
parameter_list|)
value|((buf)->text.begv)
end_define

begin_comment
comment|/* Character position of point in buffer.  */
end_comment

begin_define
define|#
directive|define
name|BUF_PT
parameter_list|(
name|buf
parameter_list|)
value|((buf)->text.pt)
end_define

begin_comment
comment|/* Character position of gap in buffer.  */
end_comment

begin_define
define|#
directive|define
name|BUF_GPT
parameter_list|(
name|buf
parameter_list|)
value|((buf)->text.gpt)
end_define

begin_comment
comment|/* Character position of end of accessible range of buffer.  */
end_comment

begin_define
define|#
directive|define
name|BUF_ZV
parameter_list|(
name|buf
parameter_list|)
value|((buf)->text.zv)
end_define

begin_comment
comment|/* Character position of end of buffer.  */
end_comment

begin_define
define|#
directive|define
name|BUF_Z
parameter_list|(
name|buf
parameter_list|)
value|((buf)->text.z)
end_define

begin_comment
comment|/* Modification count.  */
end_comment

begin_define
define|#
directive|define
name|BUF_MODIFF
parameter_list|(
name|buf
parameter_list|)
value|((buf)->text.modiff)
end_define

begin_comment
comment|/* Address of beginning of buffer.  */
end_comment

begin_define
define|#
directive|define
name|BUF_BEG_ADDR
parameter_list|(
name|buf
parameter_list|)
value|((buf)->text.beg)
end_define

begin_comment
comment|/* Macro for setting the value of BUF_ZV (BUF) to VALUE,    by varying the end of the accessible region.  */
end_comment

begin_define
define|#
directive|define
name|SET_BUF_ZV
parameter_list|(
name|buf
parameter_list|,
name|value
parameter_list|)
value|((buf)->text.zv = (value))
end_define

begin_define
define|#
directive|define
name|SET_BUF_PT
parameter_list|(
name|buf
parameter_list|,
name|value
parameter_list|)
value|((buf)->text.pt = (value))
end_define

begin_comment
comment|/* Size of gap.  */
end_comment

begin_define
define|#
directive|define
name|BUF_GAP_SIZE
parameter_list|(
name|buf
parameter_list|)
value|((buf)->text.gap_size)
end_define

begin_comment
comment|/* Return the address of character at position POS in buffer BUF.     Note that both arguments can be computed more than once.  */
end_comment

begin_define
define|#
directive|define
name|BUF_CHAR_ADDRESS
parameter_list|(
name|buf
parameter_list|,
name|pos
parameter_list|)
define|\
value|((buf)->text.beg + (pos) - 1		\  + ((pos)>= (buf)->text.gpt ? (buf)->text.gap_size : 0))
end_define

begin_comment
comment|/* Convert the address of a char in the buffer into a character position.  */
end_comment

begin_define
define|#
directive|define
name|PTR_CHAR_POS
parameter_list|(
name|ptr
parameter_list|)
define|\
value|((ptr) - (current_buffer)->text.beg		\  - (ptr - (current_buffer)->text.beg< (unsigned) GPT ? 0 : GAP_SIZE))
end_define

begin_escape
end_escape

begin_struct
struct|struct
name|buffer_text
block|{
comment|/* Actual address of buffer contents.  */
name|unsigned
name|char
modifier|*
name|beg
decl_stmt|;
comment|/* Values of BEGV ... Z in this buffer.  */
name|int
name|begv
decl_stmt|;
name|int
name|pt
decl_stmt|;
name|int
name|gpt
decl_stmt|;
name|int
name|zv
decl_stmt|;
name|int
name|z
decl_stmt|;
comment|/* Value of GAP_SIZE in this buffer.  */
name|int
name|gap_size
decl_stmt|;
comment|/* This counts buffer-modification events for this buffer.        It is incremented for each such event, and never otherwise changed.  */
name|int
name|modiff
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|buffer
block|{
comment|/* Everything before the `name' slot must be of a non-Lisp_Object type,        and every slot after `name' must be a Lisp_Object        This is known about by both mark_buffer (alloc.c) and        Flist_buffer_local_variables (buffer.c)      */
comment|/* This structure holds the coordinates of the buffer contents.  */
name|struct
name|buffer_text
name|text
decl_stmt|;
comment|/* Next buffer, in chain of all buffers including killed buffers.        This chain is used only for garbage collection, in order to        collect killed buffers properly.  */
name|struct
name|buffer
modifier|*
name|next
decl_stmt|;
comment|/* Flags saying which DEFVAR_PER_BUFFER variables        are local to this buffer.  */
name|int
name|local_var_flags
decl_stmt|;
comment|/* Value of text.modified as of when visited file was read or written.  */
name|int
name|save_modified
decl_stmt|;
comment|/* the value of text.modified at the last auto-save. */
name|int
name|auto_save_modified
decl_stmt|;
comment|/* Set to the modtime of the visited file when read or written.        -1 means visited file was nonexistent.        0 means visited file modtime unknown; in no case complain        about any mismatch on next save attempt.  */
name|int
name|modtime
decl_stmt|;
comment|/* Position in buffer at which display started        the last time this buffer was displayed */
name|int
name|last_window_start
decl_stmt|;
comment|/* This is a special exception -- as this slot should not be        marked by gc_sweep, and as it is not lisp-accessible as        a local variable -- so re regard it as not really being of type        Lisp_Object */
comment|/* the markers that refer to this buffer.        This is actually a single marker ---        successive elements in its marker `chain'        are the other markers referring to this        buffer */
name|Lisp_Object
name|markers
decl_stmt|;
comment|/* Everything from here down must be a Lisp_Object */
comment|/* the name of this buffer */
name|Lisp_Object
name|name
decl_stmt|;
comment|/* the name of the file associated with this buffer */
name|Lisp_Object
name|filename
decl_stmt|;
comment|/* Dir for expanding relative pathnames */
name|Lisp_Object
name|directory
decl_stmt|;
comment|/* True iff this buffer has been been backed        up (if you write to its associated file        and it hasn't been backed up, then a        backup will be made) */
comment|/* This isn't really used by the C code, so could be deleted.  */
name|Lisp_Object
name|backed_up
decl_stmt|;
comment|/* Length of file when last read or saved. */
name|Lisp_Object
name|save_length
decl_stmt|;
comment|/* file name used for auto-saving this buffer */
name|Lisp_Object
name|auto_save_file_name
decl_stmt|;
comment|/* Non-nil if buffer read-only */
name|Lisp_Object
name|read_only
decl_stmt|;
comment|/* "The mark"; no longer allowed to be nil */
name|Lisp_Object
name|mark
decl_stmt|;
comment|/* Alist of elements (SYMBOL . VALUE-IN-THIS-BUFFER)        for all per-buffer variables of this buffer.  */
name|Lisp_Object
name|local_var_alist
decl_stmt|;
comment|/* Symbol naming major mode (eg lisp-mode) */
name|Lisp_Object
name|major_mode
decl_stmt|;
comment|/* Pretty name of major mode (eg "Lisp") */
name|Lisp_Object
name|mode_name
decl_stmt|;
comment|/* Format description for mode line */
name|Lisp_Object
name|mode_line_format
decl_stmt|;
comment|/* Keys that are bound local to this buffer */
name|Lisp_Object
name|keymap
decl_stmt|;
comment|/* This buffer's local abbrev table */
name|Lisp_Object
name|abbrev_table
decl_stmt|;
comment|/* This buffer's syntax table.  */
name|Lisp_Object
name|syntax_table
decl_stmt|;
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
comment|/* Function to call when insert space past fiull column */
name|Lisp_Object
name|auto_fill_hook
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
comment|/* Non-nil means show ... at end of line followed by invisible lines.  */
name|Lisp_Object
name|selective_display_ellipses
decl_stmt|;
comment|/* t if "self-insertion" should overwrite */
name|Lisp_Object
name|overwrite_mode
decl_stmt|;
comment|/* non-nil means abbrev mode is on.  Expand abbrevs automatically. */
name|Lisp_Object
name|abbrev_mode
decl_stmt|;
comment|/* Changes in the buffer are recorded here for undo.        t means don't record anything.  */
name|Lisp_Object
name|undo_list
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|buffer
modifier|*
name|current_buffer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* points to the current buffer */
end_comment

begin_comment
comment|/* This structure holds the default values of the buffer-local variables    defined with DefBufferLispVar, that have special slots in each buffer.    The default value occupies the same slot in this structure    as an individual buffer's value occupies in that buffer.    Setting the default value also goes through the alist of buffers    and stores into each buffer that does not say it has a local value.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|buffer
name|buffer_defaults
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This structure marks which slots in a buffer have corresponding    default values in buffer_defaults.    Each such slot has a nonzero value in this structure.    The value has only one nonzero bit.     When a buffer has its own local value for a slot,    the bit for that slot (found in the same slot in this structure)    is turned on in the buffer's local_var_flags slot.     If a slot in this structure is zero, then even though there may    be a DefBufferLispVar for the slot, there is no default valuefeor it;    and the corresponding slot in buffer_defaults is not used.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|buffer
name|buffer_local_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For each buffer slot, this points to the Lisp symbol name    for that slot in the current buffer.  It is 0 for slots    that don't have such names.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|buffer
name|buffer_local_symbols
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Some aliases for info about the current buffer.  */
end_comment

begin_define
define|#
directive|define
name|point
value|current_buffer->text.pt
end_define

begin_comment
comment|/* Return character at position n.  No range checking */
end_comment

begin_define
define|#
directive|define
name|FETCH_CHAR
parameter_list|(
name|n
parameter_list|)
value|*(((n)>= GPT ? GAP_SIZE : 0) + (n) + BEG_ADDR - 1)
end_define

begin_comment
comment|/* BufferSafeCeiling (resp. BufferSafeFloor), when applied to n, return */
end_comment

begin_comment
comment|/* the max (resp. min) p such that&FETCH_CHAR (p) -&FETCH_CHAR (n) == p - n   */
end_comment

begin_define
define|#
directive|define
name|BufferSafeCeiling
parameter_list|(
name|n
parameter_list|)
value|(((n)< GPT&& GPT< ZV ? GPT : ZV) - 1)
end_define

begin_define
define|#
directive|define
name|BufferSafeFloor
parameter_list|(
name|n
parameter_list|)
value|(BEGV<= GPT&& GPT<= (n) ? GPT : BEGV)
end_define

begin_function_decl
specifier|extern
name|void
name|reset_buffer
parameter_list|()
function_decl|;
end_function_decl

end_unit

