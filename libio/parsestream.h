begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This is part of libio/iostream, providing -*- C++ -*- input/output. Copyright (C) 1993 Free Software Foundation  This file is part of the GNU IO Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this library; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.  As a special exception, if you link this library with files compiled with a GNU compiler to produce an executable, this does not cause the resulting executable to be covered by the GNU General Public License. This exception does not however invalidate any other reasons why the executable file might be covered by the GNU General Public License.  Written by Per Bothner (bothner@cygnus.com). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PARSESTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|PARSESTREAM_H
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
file|"streambuf.h"
end_include

begin_extern
extern|extern
literal|"C++"
block|{
comment|// A parsebuf is a streambuf optimized for scanning text files.
comment|// It keeps track of line and column numbers.
comment|// It is guaranteed to remember the entire current line,
comment|// as well the '\n'-s on either side of it (if they exist).
comment|// You can arbitrarily seek (or unget) within this extended line.
comment|// Other backward seeks are not supported.
comment|// Normal read semantics are supported (and hence istream operators like>>).
name|class
name|parsebuf
range|:
name|public
name|streambuf
block|{
name|protected
operator|:
name|_IO_off_t
name|pos_at_line_start
block|;
name|long
name|_line_length
block|;
name|unsigned
name|long
name|__line_number
block|;
name|char
operator|*
name|buf_start
block|;
name|char
operator|*
name|buf_end
block|;
name|public
operator|:
name|parsebuf
operator|*
name|chain
block|;
comment|// Return column number (raw - don't handle tabs etc).
comment|// Retult can be -1, meaning: at '\n' before current line.
name|virtual
name|int
name|tell_in_line
argument_list|()
block|;
comment|// seek to (raw) column I in current line.
comment|// Result is new (raw) column position - differs from I if unable to seek.
comment|// Seek to -1 tries to seek to before previous LF.
name|virtual
name|int
name|seek_in_line
argument_list|(
argument|int i
argument_list|)
block|;
comment|// Note: there is no "current line" initially, until something is read.
comment|// Current line number, starting with 0.
comment|// If tell_in_line()==-1, then line number of next line.
name|int
name|line_number
argument_list|()
block|{
return|return
name|__line_number
return|;
block|}
comment|// Length of current line, not counting either '\n'.
name|int
name|line_length
argument_list|()
block|{
return|return
name|_line_length
return|;
block|}
comment|// Current line - not a copy, so file ops may trash it.
name|virtual
name|char
operator|*
name|current_line
argument_list|()
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
name|virtual
name|streambuf
operator|*
name|setbuf
argument_list|(
argument|char* p
argument_list|,
argument|int len
argument_list|)
block|;
name|protected
operator|:
name|parsebuf
argument_list|()
block|{
name|chain
operator|=
name|NULL
block|;
name|__line_number
operator|=
literal|0
block|;
name|pos_at_line_start
operator|=
literal|0
block|;
name|_line_length
operator|=
operator|-
literal|1
block|; }
name|virtual
name|int
name|pbackfail
argument_list|(
argument|int c
argument_list|)
block|; }
decl_stmt|;
comment|// A string_parsebuf is a parsebuf whose source is a fixed string.
name|class
name|string_parsebuf
range|:
name|public
name|parsebuf
block|{
name|public
operator|:
name|int
name|do_delete
block|;
name|string_parsebuf
argument_list|(
argument|char *str
argument_list|,
argument|int len
argument_list|,
argument|int delete_at_close=
literal|0
argument_list|)
block|;
name|virtual
name|int
name|underflow
argument_list|()
block|;
name|virtual
name|char
operator|*
name|current_line
argument_list|()
block|;
name|virtual
name|int
name|seek_in_line
argument_list|(
argument|int i
argument_list|)
block|;
name|virtual
name|int
name|tell_in_line
argument_list|()
block|;
name|char
operator|*
name|left
argument_list|()
specifier|const
block|{
return|return
name|base
argument_list|()
return|;
block|}
name|char
operator|*
name|right
argument_list|()
specifier|const
block|{
return|return
name|ebuf
argument_list|()
return|;
block|}
comment|//    streampos seekoff(streamoff, _seek_dir, int);
expr|}
block|;
comment|// A func_parsebuf calls a given function to get new input.
comment|// Each call returns an entire NUL-terminated line (without the '\n').
comment|// That line has been allocated with malloc(), not new.
comment|// The interface is tailored to the GNU readline library.
comment|// Example:
comment|// char* DoReadLine(void* arg)
comment|// {
comment|//   char *line = readline((char*)arg); /* 'arg' is used as prompt. */
comment|//   if line == NULL) { putc('\n', stderr); return NULL; }
comment|//   if (line[0] != '\0') add_history(line);
comment|//    return line;
comment|// }
comment|// char PromptBuffer[100] = "> ";
comment|// func_parsebuf my_stream(DoReadLine, PromptBuffer);
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|CharReader
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|class
name|istream
decl_stmt|;
name|class
name|func_parsebuf
range|:
name|public
name|parsebuf
block|{
name|public
operator|:
name|void
operator|*
name|arg
block|;
name|CharReader
name|read_func
block|;
name|int
name|backed_up_to_newline
block|;
name|func_parsebuf
argument_list|(
argument|CharReader func
argument_list|,
argument|void *argm = NULL
argument_list|)
block|;
name|int
name|underflow
argument_list|()
block|;
name|virtual
name|int
name|tell_in_line
argument_list|()
block|;
name|virtual
name|int
name|seek_in_line
argument_list|(
argument|int i
argument_list|)
block|;
name|virtual
name|char
operator|*
name|current_line
argument_list|()
block|; }
decl_stmt|;
comment|// A general_parsebuf is a parsebuf which gets its input from some
comment|// other streambuf. It explicitly buffers up an entire line.
name|class
name|general_parsebuf
range|:
name|public
name|parsebuf
block|{
name|public
operator|:
name|streambuf
operator|*
name|sbuf
block|;
name|int
name|delete_buf
block|;
comment|// Delete sbuf when destroying this.
name|general_parsebuf
argument_list|(
argument|streambuf *buf
argument_list|,
argument|int delete_arg_buf =
literal|0
argument_list|)
block|;
name|int
name|underflow
argument_list|()
block|;
name|virtual
name|int
name|tell_in_line
argument_list|()
block|;
name|virtual
name|int
name|seek_in_line
argument_list|(
argument|int i
argument_list|)
block|;
operator|~
name|general_parsebuf
argument_list|()
block|;
name|virtual
name|char
operator|*
name|current_line
argument_list|()
block|; }
decl_stmt|;
if|#
directive|if
literal|0
block|class parsestream : public istream {     streammarker marks[2];     short _first;
comment|// of the two marks; either 0 or 1
block|int _lineno;     int first() { return _first; }     int second() { return 1-_first; }     int line_length() { marks[second].delta(marks[first]); }     int line_length() { marks[second].delta(marks[first]); }     int seek_in_line(int i);     int tell_in_line();     int line_number(); };
endif|#
directive|endif
block|}
end_extern

begin_comment
comment|// extern "C++"
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!defined(PARSESTREAM_H)*/
end_comment

end_unit

