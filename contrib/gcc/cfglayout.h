begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Basic block reordering routines for the GNU compiler.    Copyright (C) 2000 Free Software Foundation, Inc.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
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
name|eff_head
decl_stmt|;
name|rtx
name|eff_end
decl_stmt|;
name|basic_block
name|next
decl_stmt|;
name|int
name|visited
decl_stmt|;
block|}
typedef|*
name|reorder_block_def
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RBI
parameter_list|(
name|BB
parameter_list|)
value|((reorder_block_def) (BB)->aux)
end_define

begin_decl_stmt
specifier|extern
name|void
name|cfg_layout_initialize
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
name|cfg_layout_finalize
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
name|scope_to_insns_initialize
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
name|scope_to_insns_finalize
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

