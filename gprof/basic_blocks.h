begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* basic_blocks.h    Copyright 2000, 2002 Free Software Foundation, Inc.  This file is part of GNU Binutils.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_decl_stmt
specifier|extern
name|void
name|bb_read_rec
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|bb_write_blocks
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|bb_create_syms
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_annotated_source
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_exec_counts
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* basic_blocks_h */
end_comment

end_unit

