begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* macro.h -- declarations for macro.c.    $Id: macro.h,v 1.5 1999/07/15 00:00:46 karl Exp $     Copyright (C) 1998, 99 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.    */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MACRO_H
end_ifndef

begin_define
define|#
directive|define
name|MACRO_H
end_define

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|macro_expansion_output_stream
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|macro_expansion_filename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|me_executing_string
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|only_macro_expansion
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Here is a structure used to remember input text strings and offsets    within them. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|pointer
decl_stmt|;
comment|/* Pointer to the input text. */
name|int
name|offset
decl_stmt|;
comment|/* Offset of the last character output. */
block|}
name|ITEXT
typedef|;
end_typedef

begin_comment
comment|/* Macro definitions for user-defined commands. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of the macro. */
name|char
modifier|*
modifier|*
name|arglist
decl_stmt|;
comment|/* Args to replace when executing. */
name|char
modifier|*
name|body
decl_stmt|;
comment|/* Macro body. */
name|char
modifier|*
name|source_file
decl_stmt|;
comment|/* File where this macro is defined. */
name|int
name|source_lineno
decl_stmt|;
comment|/* Line number within FILENAME. */
name|int
name|inhibited
decl_stmt|;
comment|/* Nonzero means make find_macro () fail. */
name|int
name|flags
decl_stmt|;
comment|/* ME_RECURSE, ME_QUOTE_ARG, etc. */
block|}
name|MACRO_DEF
typedef|;
end_typedef

begin_comment
comment|/* flags for MACRO_DEF */
end_comment

begin_define
define|#
directive|define
name|ME_RECURSE
value|0x01
end_define

begin_define
define|#
directive|define
name|ME_QUOTE_ARG
value|0x02
end_define

begin_function_decl
specifier|extern
name|void
name|execute_macro
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|MACRO_DEF
modifier|*
name|find_macro
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|expand_macro
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ITEXT
modifier|*
name|remember_itext
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|forget_itext
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|maybe_write_itext
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_region_to_macro_output
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|append_to_expansion_output
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|me_append_before_this_command
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|me_execute_string
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|alias_expand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|enclosure_command
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|enclosure_expand
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* The @commands.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|cm_macro
argument_list|()
decl_stmt|,
name|cm_rmacro
argument_list|()
decl_stmt|,
name|cm_unmacro
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cm_alias
argument_list|()
decl_stmt|,
name|cm_definfoenclose
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MACRO_H */
end_comment

end_unit

