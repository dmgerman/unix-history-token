begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* linebuffer.h -- declarations for reading arbitrarily long lines    Copyright (C) 1986, 1991 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_escape
end_escape

begin_comment
comment|/* A `struct linebuffer' holds a line of text. */
end_comment

begin_struct
struct|struct
name|linebuffer
block|{
name|long
name|size
decl_stmt|;
comment|/* Allocated. */
name|long
name|length
decl_stmt|;
comment|/* Used. */
name|char
modifier|*
name|buffer
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_comment
comment|/* Initialize linebuffer LINEBUFFER for use. */
end_comment

begin_function_decl
name|void
name|initbuffer
parameter_list|(
name|struct
name|linebuffer
modifier|*
name|linebuffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read an arbitrarily long line of text from STREAM into LINEBUFFER.    Remove any newline.  Does not null terminate.    Return LINEBUFFER, except at end of file return 0.  */
end_comment

begin_function_decl
name|struct
name|linebuffer
modifier|*
name|readline
parameter_list|(
name|struct
name|linebuffer
modifier|*
name|linebuffer
parameter_list|,
name|FILE
modifier|*
name|stream
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free linebuffer LINEBUFFER and its data, all allocated with malloc. */
end_comment

begin_function_decl
name|void
name|freebuffer
parameter_list|(
name|struct
name|linebuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|initbuffer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|linebuffer
modifier|*
name|readline
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freebuffer
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

