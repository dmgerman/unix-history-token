begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Copyright (C) 1995, 2000-2002 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GETLINE_H_
end_ifndef

begin_define
define|#
directive|define
name|GETLINE_H_
value|1
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* Like the glibc functions get_line and get_delim, except that the result    must be freed using delete[], not free().  */
end_comment

begin_comment
comment|/* Reads up to (and including) a newline from STREAM into *LINEPTR    (and null-terminate it). *LINEPTR is a pointer returned from new [] (or    NULL), pointing to *N characters of space.  It is realloc'd as    necessary.  Returns the number of characters read (not including the    null terminator), or -1 on error or immediate EOF.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|get_line
parameter_list|(
name|char
modifier|*
modifier|*
name|lineptr
parameter_list|,
name|size_t
modifier|*
name|n
parameter_list|,
name|FILE
modifier|*
name|stream
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Reads up to (and including) a DELIMITER from STREAM into *LINEPTR    (and null-terminate it). *LINEPTR is a pointer returned from new [] (or    NULL), pointing to *N characters of space.  It is realloc'd as    necessary.  Returns the number of characters read (not including the    null terminator), or -1 on error or immediate EOF.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|get_delim
parameter_list|(
name|char
modifier|*
modifier|*
name|lineptr
parameter_list|,
name|size_t
modifier|*
name|n
parameter_list|,
name|int
name|delimiter
parameter_list|,
name|FILE
modifier|*
name|stream
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not GETLINE_H_ */
end_comment

end_unit

