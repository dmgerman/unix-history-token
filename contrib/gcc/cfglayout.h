begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Basic block reordering routines for the GNU compiler.    Copyright (C) 2000, 2003 Free Software Foundation, Inc.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_comment
comment|/* Structure to hold information about the blocks during reordering.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|reorder_block_def
block|{
name|rtx
name|header
decl_stmt|;
name|rtx
name|footer
decl_stmt|;
name|basic_block
name|next
decl_stmt|;
name|basic_block
name|original
decl_stmt|;
comment|/* Used by loop copying.  */
name|basic_block
name|copy
decl_stmt|;
name|int
name|duplicated
decl_stmt|;
comment|/* These fields are used by bb-reorder pass.  */
name|int
name|visited
decl_stmt|;
block|}
typedef|*
name|reorder_block_def
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|rtx
name|cfg_layout_function_footer
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|cfg_layout_initialize
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfg_layout_finalize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|cfg_layout_can_duplicate_bb_p
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|basic_block
name|cfg_layout_duplicate_bb
parameter_list|(
name|basic_block
parameter_list|,
name|edge
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|insn_locators_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reemit_insn_block_notes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|can_copy_bbs_p
parameter_list|(
name|basic_block
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|copy_bbs
parameter_list|(
name|basic_block
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|basic_block
modifier|*
parameter_list|,
name|edge
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|edge
modifier|*
parameter_list|,
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfg_layout_initialize_rbi
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

end_unit

