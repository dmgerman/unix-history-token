begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for interface to insn recognizer and insn-output.c.    Copyright (C) 1987, 1996, 1997 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"gansidecl.h"
end_include

begin_decl_stmt
specifier|extern
name|void
name|init_recog
name|PROTO
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
name|init_recog_no_volatile
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|recog_memoized
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|check_asm_operands
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|validate_change
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|*
operator|,
name|rtx
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|apply_change_group
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|num_validated_changes
name|PROTO
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
name|cancel_changes
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|constrain_operands
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|memory_address_p
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|strict_memory_address_p
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|validate_replace_rtx
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|validate_replace_src
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|reg_fits_class_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|reg_class
operator|,
name|int
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
modifier|*
name|find_single_use
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|general_operand
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|address_operand
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|register_operand
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|scratch_operand
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|immediate_operand
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|const_int_operand
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cosnt_double_operand
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nonimmediate_operand
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nonmemory_operand
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|push_operand
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|memory_operand
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|indirect_operand
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mode_independent_operand
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|comparison_operator
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|offsettable_memref_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|offsettable_nonstrict_memref_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|offsettable_address_p
name|PROTO
argument_list|(
operator|(
name|int
operator|,
expr|enum
name|machine_mode
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mode_dependent_address_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|recog
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|add_clobbers
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|insn_extract
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means volatile operands are recognized.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|volatile_ok
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The following vectors hold the results from insn_extract.  */
end_comment

begin_comment
comment|/* Indexed by N, gives value of operand N.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|recog_operand
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Indexed by N, gives location where operand N was found.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
modifier|*
name|recog_operand_loc
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Indexed by N, gives location where the Nth duplicate-appearance of    an operand was found.  This is something that matched MATCH_DUP.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
modifier|*
name|recog_dup_loc
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Indexed by N, gives the operand number that was duplicated in the    Nth duplicate-appearance of an operand.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|recog_dup_num
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Access the output function for CODE.  */
end_comment

begin_define
define|#
directive|define
name|OUT_FCN
parameter_list|(
name|CODE
parameter_list|)
value|(*insn_outfun[(int) (CODE)])
end_define

begin_comment
comment|/* Tables defined in insn-output.c that give information about    each insn-code value.  */
end_comment

begin_comment
comment|/* These are vectors indexed by insn-code.  Details in genoutput.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
specifier|const
name|insn_template
index|[]
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern char *(*const insn_outfun[]
end_extern

begin_expr_stmt
unit|)
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|insn_n_operands
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|insn_n_dups
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Indexed by insn code number, gives # of constraint alternatives.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|insn_n_alternatives
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* These are two-dimensional arrays indexed first by the insn-code    and second by the operand number.  Details in genoutput.c.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|REGISTER_CONSTRAINTS
end_ifdef

begin_comment
comment|/* Avoid undef sym in certain broken linkers.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
specifier|const
name|insn_operand_constraint
index|[]
index|[
name|MAX_RECOG_OPERANDS
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|REGISTER_CONSTRAINTS
end_ifndef

begin_comment
comment|/* Avoid undef sym in certain broken linkers.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|insn_operand_address_p
index|[]
index|[
name|MAX_RECOG_OPERANDS
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
specifier|const
name|enum
name|machine_mode
name|insn_operand_mode
index|[]
index|[
name|MAX_RECOG_OPERANDS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|insn_operand_strict_low
index|[]
index|[
name|MAX_RECOG_OPERANDS
index|]
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern int (*const insn_operand_predicate[][MAX_RECOG_OPERANDS]
end_extern

begin_expr_stmt
unit|)
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|insn_name
index|[]
decl_stmt|;
end_decl_stmt

end_unit

