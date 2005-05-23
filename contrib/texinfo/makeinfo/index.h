begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* index.h -- declarations for index.c.    $Id: index.h,v 1.2 2004/04/11 17:56:47 karl Exp $     Copyright (C) 1998, 99 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INDEX_H
end_ifndef

begin_define
define|#
directive|define
name|INDEX_H
end_define

begin_include
include|#
directive|include
file|"makeinfo.h"
end_include

begin_include
include|#
directive|include
file|"cmds.h"
end_include

begin_comment
comment|/* User commands are only new indices.  (Macros are handled separately.)  */
end_comment

begin_decl_stmt
specifier|extern
name|COMMAND
modifier|*
modifier|*
name|user_command_array
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|user_command_array_len
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* An index element... */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|index_elt
block|{
name|struct
name|index_elt
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|entry
decl_stmt|;
comment|/* The index entry itself, after expansion. */
name|char
modifier|*
name|entry_text
decl_stmt|;
comment|/* The original, non-expanded entry text. */
name|char
modifier|*
name|node
decl_stmt|;
comment|/* The node from whence it came. */
name|char
modifier|*
name|section
decl_stmt|;
comment|/* Current section number we are in, */
name|char
modifier|*
name|section_name
decl_stmt|;
comment|/* ... and its title.  */
name|int
name|code
decl_stmt|;
comment|/* Nonzero means add `@code{...}' when                                    printing this element. */
name|int
name|defining_line
decl_stmt|;
comment|/* Line number where this entry was written. */
name|int
name|output_line
decl_stmt|;
comment|/* And line number where it is in the output. */
name|char
modifier|*
name|defining_file
decl_stmt|;
comment|/* Source file for defining_line. */
name|char
modifier|*
name|output_file
decl_stmt|;
comment|/* Output file for output_line. */
name|int
name|entry_number
decl_stmt|;
comment|/* Entry number.  */
block|}
name|INDEX_ELT
typedef|;
end_typedef

begin_comment
comment|/* A list of short-names for each index.    There are two indices into the the_indices array.    * read_index is the index that points to the list of index      entries that we will find if we ask for the list of entries for      this name.    * write_index is the index that points to the list of index entries      that we will add new entries to.     Initially, read_index and write_index are the same, but the    @syncodeindex and @synindex commands can change the list we add    entries to.     For example, after the commands      @cindex foo      @defindex ii      @synindex cp ii      @cindex bar     the cp index will contain the entry `foo', and the new ii    index will contain the entry `bar'.  This is consistent with the    way texinfo.tex handles the same situation.     In addition, for each index, it is remembered whether that index is    a code index or not.  Code indices have @code{} inserted around the    first word when they are printed with printindex. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|read_index
decl_stmt|;
comment|/* index entries for `name' */
name|int
name|write_index
decl_stmt|;
comment|/* store index entries here, @synindex can change it */
name|int
name|code
decl_stmt|;
block|}
name|INDEX_ALIST
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|INDEX_ALIST
modifier|*
modifier|*
name|name_index_alist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialize all indices.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_indices
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|defined_indices
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|printing_index
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|index_counter
decl_stmt|;
end_decl_stmt

begin_function_decl
name|INDEX_ELT
modifier|*
name|index_list
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !INDEX_H */
end_comment

end_unit

