begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* search.h -- Structure used to search large bodies of text, with bounds.    $Id: search.h,v 1.4 1998/04/19 20:50:23 karl Exp $     Copyright (C) 1993, 97, 98 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_comment
comment|/* The search functions take two arguments:       1) a string to search for, and       2) a pointer to a SEARCH_BINDING which contains the buffer, start,         and end of the search.     They return a long, which is the offset from the start of the buffer    at which the match was found.  An offset of -1 indicates failure. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INFO_SEARCH_H
end_ifndef

begin_define
define|#
directive|define
name|INFO_SEARCH_H
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|buffer
decl_stmt|;
comment|/* The buffer of text to search. */
name|long
name|start
decl_stmt|;
comment|/* Offset of the start of the search. */
name|long
name|end
decl_stmt|;
comment|/* Offset of the end of the searh. */
name|int
name|flags
decl_stmt|;
comment|/* Flags controlling the type of search. */
block|}
name|SEARCH_BINDING
typedef|;
end_typedef

begin_define
define|#
directive|define
name|S_FoldCase
value|0x01
end_define

begin_comment
comment|/* Set means fold case in searches. */
end_comment

begin_define
define|#
directive|define
name|S_SkipDest
value|0x02
end_define

begin_comment
comment|/* Set means return pointing after the dest. */
end_comment

begin_decl_stmt
name|SEARCH_BINDING
modifier|*
name|make_binding
argument_list|()
decl_stmt|,
modifier|*
name|copy_binding
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|search_forward
argument_list|()
decl_stmt|,
name|search_backward
argument_list|()
decl_stmt|,
name|search
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|looking_at
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Note that STRING_IN_LINE () always returns the offset of the 1st character    after the string. */
end_comment

begin_function_decl
specifier|extern
name|int
name|string_in_line
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Function names that start with "skip" are passed a string, and return    an offset from the start of that string.  Function names that start    with "find" are passed a SEARCH_BINDING, and return an absolute position    marker of the item being searched for.  "Find" functions return a value    of -1 if the item being looked for couldn't be found. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|skip_whitespace
argument_list|()
decl_stmt|,
name|skip_non_whitespace
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|skip_whitespace_and_newlines
argument_list|()
decl_stmt|,
name|skip_line
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|skip_node_characters
argument_list|()
decl_stmt|,
name|skip_node_separator
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DONT_SKIP_NEWLINES
value|0
end_define

begin_define
define|#
directive|define
name|SKIP_NEWLINES
value|1
end_define

begin_decl_stmt
specifier|extern
name|long
name|find_node_separator
argument_list|()
decl_stmt|,
name|find_tags_table
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|long
name|find_node_in_binding
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not INFO_SEARCH_H */
end_comment

end_unit

