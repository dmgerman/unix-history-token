begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* An interface to write() that retries after interrupts.    Copyright (C) 2002 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_define
define|#
directive|define
name|SAFE_WRITE_ERROR
value|((size_t) -1)
end_define

begin_comment
comment|/* Write up to COUNT bytes at BUF to descriptor FD, retrying if interrupted.    Return the actual number of bytes written, zero for EOF, or SAFE_WRITE_ERROR    upon error.  */
end_comment

begin_function_decl
specifier|extern
name|size_t
name|safe_write
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

end_unit

