begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* basic_blocks.h    Copyright 2000, 2002, 2004 Free Software Foundation, Inc.  This file is part of GNU Binutils.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|basic_blocks_h
end_ifndef

begin_define
define|#
directive|define
name|basic_blocks_h
end_define

begin_comment
comment|/* Options:  */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|bb_annotate_all_lines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Force annotation of all lines?  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bb_table_length
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Length of most-used bb table.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|bb_min_calls
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Minimum execution count.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|bb_read_rec
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bb_write_blocks
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bb_create_syms
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_annotated_source
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_exec_counts
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
comment|/* basic_blocks_h */
end_comment

end_unit

