begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* windmc.h -- header file for windmc program.    Copyright 2007    Free Software Foundation, Inc.    Written by Kai Tietz, Onevision.     This file is part of GNU Binutils.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_comment
comment|/* This is the header file for the windmc program.  It defines    structures and declares functions used within the program.  */
end_comment

begin_include
include|#
directive|include
file|"winduni.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|WINDMC_HXX
end_ifndef

begin_define
define|#
directive|define
name|WINDMC_HXX
end_define

begin_comment
comment|/* Global flag variables (set by windmc.c file.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mcset_custom_bit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mcset_out_values_are_decimal
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rc_uint_type
name|mcset_max_message_length
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unichar
modifier|*
name|mcset_msg_id_typedef
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lexer keyword definition and internal memory structures.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|mc_keyword
block|{
name|struct
name|mc_keyword
modifier|*
name|next
decl_stmt|;
specifier|const
name|char
modifier|*
name|group_name
decl_stmt|;
name|size_t
name|len
decl_stmt|;
name|unichar
modifier|*
name|usz
decl_stmt|;
name|int
name|rid
decl_stmt|;
name|rc_uint_type
name|nval
decl_stmt|;
name|unichar
modifier|*
name|sval
decl_stmt|;
name|wind_language_t
name|lang_info
decl_stmt|;
block|}
name|mc_keyword
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|mc_node_lang
block|{
name|struct
name|mc_node_lang
modifier|*
name|next
decl_stmt|;
name|rc_uint_type
name|vid
decl_stmt|;
specifier|const
name|mc_keyword
modifier|*
name|lang
decl_stmt|;
name|unichar
modifier|*
name|message
decl_stmt|;
block|}
name|mc_node_lang
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|mc_node
block|{
name|struct
name|mc_node
modifier|*
name|next
decl_stmt|;
name|unichar
modifier|*
name|user_text
decl_stmt|;
specifier|const
name|mc_keyword
modifier|*
name|facility
decl_stmt|;
specifier|const
name|mc_keyword
modifier|*
name|severity
decl_stmt|;
name|unichar
modifier|*
name|symbol
decl_stmt|;
name|rc_uint_type
name|id
decl_stmt|;
name|rc_uint_type
name|vid
decl_stmt|;
name|mc_node_lang
modifier|*
name|sub
decl_stmt|;
block|}
name|mc_node
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|mc_node
modifier|*
name|mc_nodes
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|mc_add_keyword
parameter_list|(
name|unichar
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|rc_uint_type
parameter_list|,
name|unichar
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|mc_keyword
modifier|*
name|enum_facility
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|mc_keyword
modifier|*
name|enum_severity
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mc_node_lang
modifier|*
name|mc_add_node_lang
parameter_list|(
name|mc_node
modifier|*
parameter_list|,
specifier|const
name|mc_keyword
modifier|*
parameter_list|,
name|rc_uint_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mc_node
modifier|*
name|mc_add_node
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Standard yacc/flex stuff.  */
end_comment

begin_function_decl
name|int
name|yyerror
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|yylex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|yyparse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* mclex.c  */
end_comment

begin_function_decl
name|void
name|mc_set_inputfile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mc_set_content
parameter_list|(
specifier|const
name|unichar
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Lexer control variables. Used by mcparser.y file.  */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|mclex_want_nl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|mclex_want_line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|mclex_want_filename
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|mc_fatal
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mc_warn
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

