begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Static Single Assignment (SSA) definitions for GNU C-Compiler    Copyright (C) 2000, 2001 Free Software Foundation, Inc.    Written by Jeffrey D. Oldham<oldham@codesourcery.com>.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Main SSA routines.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|convert_to_ssa
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
name|convert_from_ssa
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*successor_phi_fn
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|,
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|for_each_successor_phi
name|PARAMS
argument_list|(
operator|(
name|basic_block
name|bb
operator|,
name|successor_phi_fn
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|compute_dominance_frontiers
name|PARAMS
argument_list|(
operator|(
name|sbitmap
operator|*
name|frontiers
operator|,
name|int
operator|*
name|idom
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|remove_phi_alternative
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|basic_block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Optimizations.  */
end_comment

begin_comment
comment|/* In ssa-dce.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ssa_eliminate_dead_code
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In ssa-ccp.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ssa_const_prop
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SSA definitions and uses.  */
end_comment

begin_comment
comment|/* This flag is set when the CFG is in SSA form.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|in_ssa_form
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Element I is the single instruction that sets register I.  */
end_comment

begin_decl_stmt
specifier|extern
name|varray_type
name|ssa_definition
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Element I is an INSN_LIST of instructions that use register I.  */
end_comment

begin_decl_stmt
specifier|extern
name|varray_type
name|ssa_uses
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Specify which hard registers should be converted.  */
end_comment

begin_comment
comment|/* All pseudo-registers (having register number>=    FIRST_PSEUDO_REGISTER) and hard registers satisfying    CONVERT_HARD_REGISTER_TO_SSA_P are converted to SSA form.  */
end_comment

begin_comment
comment|/* Given a hard register number REG_NO, return nonzero if and only if    the register should be converted to SSA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONVERT_HARD_REGISTER_TO_SSA_P
end_ifndef

begin_define
define|#
directive|define
name|CONVERT_HARD_REGISTER_TO_SSA_P
parameter_list|(
name|REG_NO
parameter_list|)
value|(0)
end_define

begin_comment
comment|/* default of no hard registers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONVERT_HARD_REGISTER_TO_SSA_P  */
end_comment

begin_comment
comment|/* Given a register number REG_NO, return nonzero if and only if the    register should be converted to SSA.  */
end_comment

begin_define
define|#
directive|define
name|CONVERT_REGISTER_TO_SSA_P
parameter_list|(
name|REG_NO
parameter_list|)
define|\
value|((!HARD_REGISTER_NUM_P (REG_NO)) || \ 	 (CONVERT_HARD_REGISTER_TO_SSA_P (REG_NO)))
end_define

end_unit

