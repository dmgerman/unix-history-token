begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* corefile.h     Copyright 2000, 2001, 2002, 2004 Free Software Foundation, Inc.  This file is part of GNU Binutils.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|corefile_h
end_ifndef

begin_define
define|#
directive|define
name|corefile_h
end_define

begin_struct
struct|struct
name|function_map
block|{
name|char
modifier|*
name|function_name
decl_stmt|;
name|char
modifier|*
name|file_name
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|function_map
modifier|*
name|symbol_map
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|symbol_map_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bfd
modifier|*
name|core_bfd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* BFD for core-file.  */
end_comment

begin_decl_stmt
specifier|extern
name|asection
modifier|*
name|core_text_sect
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Core text section.  */
end_comment

begin_decl_stmt
specifier|extern
name|PTR
name|core_text_space
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Text space of a.out in core.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|offset_to_code
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Offset (in bytes) of code from entry 				   address of routine.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|core_init
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|core_get_text_space
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|core_create_function_syms
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|core_create_line_syms
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* corefile_h */
end_comment

end_unit

