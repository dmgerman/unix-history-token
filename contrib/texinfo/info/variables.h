begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* variables.h -- Description of user visible variables in Info.    $Id: variables.h,v 1.3 1997/07/15 18:44:23 karl Exp $     This file is part of GNU Info, a program for reading online documentation    stored in Info format.     Copyright (C) 1993, 97 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INFO_VARIABLES_H
end_ifndef

begin_define
define|#
directive|define
name|INFO_VARIABLES_H
end_define

begin_comment
comment|/* A variable (in the Info sense) is an integer value with a user-visible    name.  You may supply an array of strings to complete over when the    variable is set; in that case, the variable is set to the index of the    string that the user chose.  If you supply a null list, the user can    set the variable to a numeric value. */
end_comment

begin_comment
comment|/* Structure describing a user visible variable. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Polite name. */
name|char
modifier|*
name|doc
decl_stmt|;
comment|/* Documentation string. */
name|int
modifier|*
name|value
decl_stmt|;
comment|/* Address of value. */
name|char
modifier|*
modifier|*
name|choices
decl_stmt|;
comment|/* Array of strings or NULL if numeric only. */
block|}
name|VARIABLE_ALIST
typedef|;
end_typedef

begin_comment
comment|/* Read the name of an Info variable in the echo area and return the    address of a VARIABLE_ALIST member.  A return value of NULL indicates    that no variable could be read. */
end_comment

begin_function_decl
specifier|extern
name|VARIABLE_ALIST
modifier|*
name|read_variable_name
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Make an array of REFERENCE which actually contains the names of the    variables available in Info. */
end_comment

begin_function_decl
specifier|extern
name|REFERENCE
modifier|*
modifier|*
name|make_variable_completions_array
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Set the value of an info variable. */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_variable
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* The list of user-visible variables. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|auto_footnotes_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|auto_tiling_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|terminal_use_visible_bell_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|info_error_rings_bell_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|gc_compressed_files
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|show_index_match
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|info_scroll_behaviour
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|window_scroll_step
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ISO_Latin_p
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not INFO_VARIABLES_H */
end_comment

end_unit

