begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This is part of libio/iostream, providing -*- C++ -*- input/output. Copyright (C) 1993 Free Software Foundation  This file is part of the GNU IO Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  As a special exception, if you link this library with files compiled with a GNU compiler to produce an executable, this does not cause the resulting executable to be covered by the GNU General Public License. This exception does not however invalidate any other reasons why the executable file might be covered by the GNU General Public License.  Written by Per Bothner (bothner@cygnus.com). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EDITBUF_H
end_ifndef

begin_define
define|#
directive|define
name|_EDITBUF_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|interface
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<fstream.h>
end_include

begin_typedef
typedef|typedef
name|unsigned
name|long
name|mark_pointer
typedef|;
end_typedef

begin_comment
comment|// At some point, it might be nice to parameterize this code
end_comment

begin_comment
comment|// in terms of buf_char.
end_comment

begin_typedef
typedef|typedef
comment|/*unsigned*/
name|char
name|buf_char
typedef|;
end_typedef

begin_comment
comment|// Logical pos from start of buffer (does not count gap).
end_comment

begin_typedef
typedef|typedef
name|long
name|buf_index
typedef|;
end_typedef

begin_comment
comment|// Pos from start of buffer, possibly including gap_size.
end_comment

begin_typedef
typedef|typedef
name|long
name|buf_offset
typedef|;
end_typedef

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|struct buf_cookie {     FILE *file;     struct edit_string *str;     struct buf_cookie *next;     buf_index tell(); };
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|edit_buffer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|edit_mark
struct_decl|;
end_struct_decl

begin_comment
comment|// A edit_string is defined as the region between the 'start' and 'end' marks.
end_comment

begin_comment
comment|// Normally (always?) 'start->insert_before()' should be false,
end_comment

begin_comment
comment|// and 'end->insert_before()' should be true.
end_comment

begin_struct
struct|struct
name|edit_string
block|{
name|struct
name|edit_buffer
modifier|*
name|buffer
decl_stmt|;
comment|// buffer that 'start' and 'end' belong to
name|struct
name|edit_mark
modifier|*
name|start
decl_stmt|,
modifier|*
name|end
decl_stmt|;
name|int
name|length
parameter_list|()
function|const;
comment|// count of buf_chars currently in string
name|edit_string
argument_list|(
argument|struct edit_buffer *b
argument_list|,
argument|struct edit_mark *ms
argument_list|,
argument|struct edit_mark *me
argument_list|)
block|{
name|buffer
operator|=
name|b
expr_stmt|;
name|start
operator|=
name|ms
expr_stmt|;
name|end
operator|=
name|me
expr_stmt|;
block|}
comment|/* Make a fresh, contiguous copy of the data in STR.    Assign length of STR to *LENP.    (Output has extra NUL at out[*LENP].) */
name|buf_char
modifier|*
name|copy_bytes
argument_list|(
name|int
operator|*
name|lenp
argument_list|)
decl|const
decl_stmt|;
comment|//    FILE *open_file(char *mode);
name|void
name|assign
parameter_list|(
name|struct
name|edit_string
modifier|*
name|src
parameter_list|)
function_decl|;
comment|// copy bytes from src to this
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|edit_streambuf
range|:
name|public
name|streambuf
block|{
name|friend
name|edit_buffer
block|;
name|edit_string
operator|*
name|str
block|;
name|edit_streambuf
operator|*
name|next
block|;
comment|// Chain of edit_streambuf's for a edit_buffer.
name|short
name|_mode
block|;
name|edit_streambuf
argument_list|(
argument|edit_string* bstr
argument_list|,
argument|int mode
argument_list|)
block|;
operator|~
name|edit_streambuf
argument_list|()
block|;
name|virtual
name|int
name|underflow
argument_list|()
block|;
name|virtual
name|int
name|overflow
argument_list|(
argument|int c = EOF
argument_list|)
block|;
name|virtual
name|streampos
name|seekoff
argument_list|(
argument|streamoff
argument_list|,
argument|_seek_dir
argument_list|,
argument|int mode=ios::in|ios::out
argument_list|)
block|;
name|void
name|flush_to_buffer
argument_list|()
block|;
name|void
name|flush_to_buffer
argument_list|(
name|edit_buffer
operator|*
name|buffer
argument_list|)
block|;
name|int
name|_inserting
block|;
name|int
name|inserting
argument_list|()
block|{
return|return
name|_inserting
return|;
block|}
name|void
name|inserting
argument_list|(
argument|int i
argument_list|)
block|{
name|_inserting
operator|=
name|i
block|; }
comment|//    int delete_chars(int count, char* cut_buf); Not implemented.
name|int
name|truncate
argument_list|()
block|;
name|int
name|is_reading
argument_list|()
block|{
return|return
name|gptr
argument_list|()
operator|!=
name|NULL
return|;
block|}
name|buf_char
operator|*
name|current
argument_list|()
block|{
return|return
name|is_reading
argument_list|()
operator|?
name|gptr
argument_list|()
operator|:
name|pptr
argument_list|()
return|;
block|}
name|void
name|set_current
argument_list|(
argument|char *p
argument_list|,
argument|int is_reading
argument_list|)
block|;
name|protected
operator|:
name|void
name|disconnect_gap_from_file
argument_list|(
name|edit_buffer
operator|*
name|buffer
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|// A 'edit_mark' indicates a position in a buffer.
end_comment

begin_comment
comment|// It is "attached" the text (rather than the offset).
end_comment

begin_comment
comment|// There are two kinds of mark, which have different behavior
end_comment

begin_comment
comment|// when text is inserted at the mark:
end_comment

begin_comment
comment|// If 'insert_before()' is true the mark will be adjusted to be
end_comment

begin_comment
comment|// *after* the new text.
end_comment

begin_struct
struct|struct
name|edit_mark
block|{
name|struct
name|edit_mark
modifier|*
name|chain
decl_stmt|;
name|mark_pointer
name|_pos
decl_stmt|;
specifier|inline
name|int
name|insert_before
parameter_list|()
block|{
return|return
name|_pos
operator|&
literal|1
return|;
block|}
specifier|inline
name|unsigned
name|long
name|index_in_buffer
parameter_list|(
name|struct
name|edit_buffer
modifier|*
name|buffer
parameter_list|)
block|{
return|return
name|_pos
operator|>>
literal|1
return|;
block|}
specifier|inline
name|buf_char
modifier|*
name|ptr
parameter_list|(
name|struct
name|edit_buffer
modifier|*
name|buf
parameter_list|)
function_decl|;
name|buf_index
name|tell
parameter_list|()
function_decl|;
name|edit_mark
argument_list|()
block|{ }
name|edit_mark
argument_list|(
argument|struct edit_string *str
argument_list|,
argument|long delta
argument_list|)
empty_stmt|;
name|edit_buffer
modifier|*
name|buffer
parameter_list|()
function_decl|;
operator|~
name|edit_mark
argument_list|()
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// A 'edit_buffer' consists of a sequence of buf_chars (the data),
end_comment

begin_comment
comment|// a list of edit_marks pointing into the data, and a list of FILEs
end_comment

begin_comment
comment|// also pointing into the data.
end_comment

begin_comment
comment|// A 'edit_buffer' coerced to a edit_string is the string of
end_comment

begin_comment
comment|// all the buf_chars in the buffer.
end_comment

begin_comment
comment|// This implementation uses a conventional buffer gap (as in Emacs).
end_comment

begin_comment
comment|// The gap start is defined by de-referencing a (buf_char**).
end_comment

begin_comment
comment|// This is because sometimes a FILE is inserting into the buffer,
end_comment

begin_comment
comment|// so rather than having each putc adjust the gap, we use indirection
end_comment

begin_comment
comment|// to have the gap be defined as the write pointer of the FILE.
end_comment

begin_comment
comment|// (This assumes that putc adjusts a pointer (as in GNU's libc), not an index.)
end_comment

begin_struct
struct|struct
name|edit_buffer
block|{
name|buf_char
modifier|*
name|data
decl_stmt|;
comment|/* == emacs buffer_text.p1+1 */
name|buf_char
modifier|*
name|_gap_start
decl_stmt|;
name|edit_streambuf
modifier|*
name|_writer
decl_stmt|;
comment|// If non-NULL, currently writing stream
specifier|inline
name|buf_char
modifier|*
name|gap_start
parameter_list|()
block|{
return|return
name|_writer
condition|?
name|_writer
operator|->
name|pptr
argument_list|()
else|:
name|_gap_start
return|;
block|}
name|buf_offset
name|__gap_end_pos
decl_stmt|;
comment|// size of part 1 + size of gap
comment|/* int gap; implicit: buf_size - size1 - size2 */
name|int
name|buf_size
decl_stmt|;
name|struct
name|edit_streambuf
modifier|*
name|files
decl_stmt|;
name|struct
name|edit_mark
name|start_mark
decl_stmt|;
name|struct
name|edit_mark
name|end_mark
decl_stmt|;
name|edit_buffer
argument_list|()
expr_stmt|;
specifier|inline
name|buf_offset
name|gap_end_pos
parameter_list|()
block|{
return|return
name|__gap_end_pos
return|;
block|}
specifier|inline
name|struct
name|edit_mark
modifier|*
name|start_marker
parameter_list|()
block|{
return|return
operator|&
name|start_mark
return|;
block|}
specifier|inline
name|struct
name|edit_mark
modifier|*
name|end_marker
parameter_list|()
block|{
return|return
operator|&
name|end_mark
return|;
block|}
comment|/* these should be protected, ultimately */
name|buf_index
name|tell
parameter_list|(
name|edit_mark
modifier|*
parameter_list|)
function_decl|;
name|buf_index
name|tell
parameter_list|(
name|buf_char
modifier|*
parameter_list|)
function_decl|;
specifier|inline
name|buf_char
modifier|*
name|gap_end
parameter_list|()
block|{
return|return
name|data
operator|+
name|gap_end_pos
argument_list|()
return|;
block|}
specifier|inline
name|int
name|gap_size
parameter_list|()
block|{
return|return
name|gap_end
argument_list|()
operator|-
name|gap_start
argument_list|()
return|;
block|}
specifier|inline
name|int
name|size1
parameter_list|()
block|{
return|return
name|gap_start
argument_list|()
operator|-
name|data
return|;
block|}
specifier|inline
name|int
name|size2
parameter_list|()
block|{
return|return
name|buf_size
operator|-
name|gap_end_pos
argument_list|()
return|;
block|}
specifier|inline
name|struct
name|edit_mark
modifier|*
name|mark_list
parameter_list|()
block|{
return|return
operator|&
name|start_mark
return|;
block|}
name|void
name|make_gap
parameter_list|(
name|buf_offset
parameter_list|)
function_decl|;
name|void
name|move_gap
parameter_list|(
name|buf_offset
name|pos
parameter_list|)
function_decl|;
name|void
name|move_gap
parameter_list|(
name|buf_char
modifier|*
name|pos
parameter_list|)
block|{
name|move_gap
argument_list|(
name|pos
operator|-
name|data
argument_list|)
expr_stmt|;
block|}
name|void
name|gap_left
parameter_list|(
name|int
name|pos
parameter_list|)
function_decl|;
name|void
name|gap_right
parameter_list|(
name|int
name|pos
parameter_list|)
function_decl|;
name|void
name|adjust_markers
parameter_list|(
name|mark_pointer
name|low
parameter_list|,
name|mark_pointer
name|high
parameter_list|,
name|int
name|amount
parameter_list|,
name|buf_char
modifier|*
name|old_data
parameter_list|)
function_decl|;
name|void
name|delete_range
parameter_list|(
name|buf_index
name|from
parameter_list|,
name|buf_index
name|to
parameter_list|)
function_decl|;
name|void
name|delete_range
parameter_list|(
name|struct
name|edit_mark
modifier|*
name|start
parameter_list|,
name|struct
name|edit_mark
modifier|*
name|end
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|buf_char
modifier|*
name|bstr_copy
parameter_list|(
name|struct
name|edit_string
modifier|*
name|str
parameter_list|,
name|int
modifier|*
name|lenp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Convert a edit_mark to a (buf_char*)
end_comment

begin_expr_stmt
specifier|inline
name|buf_char
operator|*
name|edit_mark
operator|::
name|ptr
argument_list|(
argument|struct edit_buffer *buf
argument_list|)
block|{
return|return
name|buf
operator|->
name|data
operator|+
name|index_in_buffer
argument_list|(
name|buf
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|void
name|edit_streambuf
operator|::
name|flush_to_buffer
argument_list|()
block|{
name|edit_buffer
operator|*
name|buffer
operator|=
name|str
operator|->
name|buffer
block|;
if|if
condition|(
name|buffer
operator|->
name|_writer
operator|==
name|this
condition|)
name|flush_to_buffer
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_EDITBUF_H*/
end_comment

end_unit

