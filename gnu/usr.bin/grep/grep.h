begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* grep.h - interface to grep driver for searching subroutines.    Copyright (C) 1992 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_function_decl
specifier|extern
name|void
name|fatal
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Grep.c expects the matchers vector to be terminated    by an entry with a NULL name, and to contain at least    an entry named "default". */
end_comment

begin_struct
specifier|extern
struct|struct
name|matcher
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|void
function_decl|(
modifier|*
name|compile
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|char
modifier|*
function_decl|(
modifier|*
name|execute
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
block|}
name|matchers
index|[]
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|fatal
parameter_list|()
function_decl|;
end_function_decl

begin_struct
specifier|extern
struct|struct
name|matcher
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|void
function_decl|(
modifier|*
name|compile
function_decl|)
parameter_list|()
function_decl|;
name|char
modifier|*
function_decl|(
modifier|*
name|execute
function_decl|)
parameter_list|()
function_decl|;
block|}
name|matchers
index|[]
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Exported from grep.c. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|matcher
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The following flags are exported from grep for the matchers    to look at. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|match_icase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -i */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|match_words
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -w */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|match_lines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -x */
end_comment

end_unit

