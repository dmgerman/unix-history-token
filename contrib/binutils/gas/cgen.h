begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GAS cgen support.    Copyright (C) 1998, 1999 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GAS_CGEN_H
end_ifndef

begin_define
define|#
directive|define
name|GAS_CGEN_H
end_define

begin_comment
comment|/* Opcode table handle.  */
end_comment

begin_decl_stmt
specifier|extern
name|CGEN_CPU_DESC
name|gas_cgen_cpu_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Maximum number of fixups in an insn.    If you need to change this, allow target to override and do so there.  */
end_comment

begin_define
define|#
directive|define
name|GAS_CGEN_MAX_FIXUPS
value|3
end_define

begin_comment
comment|/* Struct defining result of gas_cgen_finish_insn.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* frag containing the insn */
name|fragS
modifier|*
name|frag
decl_stmt|;
comment|/* Address of insn in frag.  */
name|char
modifier|*
name|addr
decl_stmt|;
comment|/* Number of fixups this insn has.  */
name|int
name|num_fixups
decl_stmt|;
comment|/* Array of fixups.  */
name|fixS
modifier|*
name|fixups
index|[
name|GAS_CGEN_MAX_FIXUPS
index|]
decl_stmt|;
block|}
name|finished_insnS
typedef|;
end_typedef

begin_comment
comment|/* Callback for operand parsing.    The result is an error message or NULL for success.    The parsed value is stored in the bfd_vma *.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|gas_cgen_parse_operand
name|PARAMS
argument_list|(
operator|(
name|CGEN_CPU_DESC
operator|,
expr|enum
name|cgen_parse_operand_type
operator|,
specifier|const
name|char
operator|*
operator|*
operator|,
name|int
operator|,
name|int
operator|,
expr|enum
name|cgen_parse_operand_result
operator|*
operator|,
name|bfd_vma
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Call this from md_assemble to initialize the assembler callback.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gas_cgen_init_parse
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
name|gas_cgen_save_fixups
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
name|gas_cgen_restore_fixups
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
name|gas_cgen_swap_fixups
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add a register to the assembler's hash table.    This makes lets GAS parse registers for us.    ??? This isn't currently used, but it could be in the future.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|cgen_asm_record_register
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* After CGEN_SYM (assemble_insn) is done, this is called to    output the insn and record any fixups.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gas_cgen_finish_insn
name|PARAMS
argument_list|(
operator|(
specifier|const
name|CGEN_INSN
operator|*
operator|,
name|CGEN_INSN_BYTES_PTR
operator|,
name|unsigned
name|int
operator|,
name|int
operator|,
name|finished_insnS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Record a fixup.  */
end_comment

begin_decl_stmt
specifier|extern
name|fixS
modifier|*
name|gas_cgen_record_fixup
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
operator|,
name|int
operator|,
specifier|const
name|CGEN_INSN
operator|*
operator|,
name|int
operator|,
specifier|const
name|CGEN_OPERAND
operator|*
operator|,
name|int
operator|,
name|symbolS
operator|*
operator|,
name|offsetT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|fixS
modifier|*
name|gas_cgen_record_fixup_exp
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
operator|,
name|int
operator|,
specifier|const
name|CGEN_INSN
operator|*
operator|,
name|int
operator|,
specifier|const
name|CGEN_OPERAND
operator|*
operator|,
name|int
operator|,
name|expressionS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* md_apply_fix3 handler */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gas_cgen_md_apply_fix3
name|PARAMS
argument_list|(
operator|(
name|fixS
operator|*
operator|,
name|valueT
operator|*
operator|,
name|segT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tc_gen_reloc handler */
end_comment

begin_decl_stmt
specifier|extern
name|arelent
modifier|*
name|gas_cgen_tc_gen_reloc
name|PARAMS
argument_list|(
operator|(
name|asection
operator|*
operator|,
name|fixS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Target supplied routine to lookup a reloc.  */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_reloc_code_real_type
name|md_cgen_lookup_reloc
name|PARAMS
argument_list|(
operator|(
specifier|const
name|CGEN_INSN
operator|*
operator|,
specifier|const
name|CGEN_OPERAND
operator|*
operator|,
name|fixS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Optional target supplied routine to record a fixup for an expression.  */
end_comment

begin_decl_stmt
specifier|extern
name|fixS
modifier|*
name|md_cgen_record_fixup_exp
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
operator|,
name|int
operator|,
specifier|const
name|CGEN_INSN
operator|*
operator|,
name|int
operator|,
specifier|const
name|CGEN_OPERAND
operator|*
operator|,
name|int
operator|,
name|expressionS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GAS_CGEN_H */
end_comment

end_unit

