begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* nlmconv.h -- header file for NLM conversion program    Copyright 1993, 2002, 2003 Free Software Foundation, Inc.  This file is part of GNU Binutils.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Written by Ian Lance Taylor<ian@cygnus.com>.     bfd.h, nlm/common.h and nlm/internal.h must be included before this    file.  */
end_comment

begin_comment
comment|/* A linked list of strings.  */
end_comment

begin_struct
struct|struct
name|string_list
block|{
name|struct
name|string_list
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|string
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The NLM header parser in nlmheader.y stores information in the    following variables.  */
end_comment

begin_decl_stmt
specifier|extern
name|Nlm_Internal_Fixed_Header
modifier|*
name|fixed_hdr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Nlm_Internal_Variable_Header
modifier|*
name|var_hdr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Nlm_Internal_Version_Header
modifier|*
name|version_hdr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Nlm_Internal_Copyright_Header
modifier|*
name|copyright_hdr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Nlm_Internal_Extended_Header
modifier|*
name|extended_hdr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Procedure named by CHECK.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|check_procedure
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File named by CUSTOM.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|custom_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Whether to generate debugging information (DEBUG).  */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|debug_info
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Procedure named by EXIT.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|exit_procedure
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Exported symbols (EXPORT).  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|string_list
modifier|*
name|export_symbols
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of files from INPUT.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|string_list
modifier|*
name|input_files
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Map file name (MAP, FULLMAP).  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|map_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Whether a full map has been requested (FULLMAP).  */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|full_map
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File named by HELP.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|help_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Imported symbols (IMPORT).  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|string_list
modifier|*
name|import_symbols
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File named by MESSAGES.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|message_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Autoload module list (MODULE).  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|string_list
modifier|*
name|modules
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File named by OUTPUT.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|output_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File named by SHARELIB.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sharelib_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Start procedure name (START).  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|start_procedure
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* VERBOSE.  */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|verbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* RPC description file (XDCDATA).  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rpc_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The number of serious parse errors.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|parse_errors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The parser.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|yyparse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Tell the lexer what file to read.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|nlmlex_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

