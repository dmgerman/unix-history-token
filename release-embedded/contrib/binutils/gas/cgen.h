begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GAS cgen support.    Copyright 1998, 1999, 2000, 2001, 2002, 2003    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|GAS_CGEN_MAX_FIXUPS
end_ifndef

begin_define
define|#
directive|define
name|GAS_CGEN_MAX_FIXUPS
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|gas_cgen_parse_operand
parameter_list|(
name|CGEN_CPU_DESC
parameter_list|,
name|enum
name|cgen_parse_operand_type
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|enum
name|cgen_parse_operand_result
modifier|*
parameter_list|,
name|bfd_vma
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Call this from md_assemble to initialize the assembler callback.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|gas_cgen_init_parse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Routines and macros for saving fixup chains.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|gas_cgen_save_fixups
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gas_cgen_restore_fixups
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gas_cgen_swap_fixups
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gas_cgen_initialize_saved_fixups_array
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MAX_SAVED_FIXUP_CHAINS
value|50
end_define

begin_comment
comment|/* Add a register to the assembler's hash table.    This makes lets GAS parse registers for us.    ??? This isn't currently used, but it could be in the future.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|cgen_asm_record_register
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* After CGEN_SYM (assemble_insn) is done, this is called to    output the insn and record any fixups.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|gas_cgen_finish_insn
parameter_list|(
specifier|const
name|CGEN_INSN
modifier|*
parameter_list|,
name|CGEN_INSN_BYTES_PTR
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|,
name|finished_insnS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Record a fixup.  */
end_comment

begin_function_decl
specifier|extern
name|fixS
modifier|*
name|gas_cgen_record_fixup
parameter_list|(
name|fragS
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|CGEN_INSN
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|CGEN_OPERAND
modifier|*
parameter_list|,
name|int
parameter_list|,
name|symbolS
modifier|*
parameter_list|,
name|offsetT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|fixS
modifier|*
name|gas_cgen_record_fixup_exp
parameter_list|(
name|fragS
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|CGEN_INSN
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|CGEN_OPERAND
modifier|*
parameter_list|,
name|int
parameter_list|,
name|expressionS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* md_apply_fix handler */
end_comment

begin_function_decl
specifier|extern
name|void
name|gas_cgen_md_apply_fix
parameter_list|(
name|fixS
modifier|*
parameter_list|,
name|valueT
modifier|*
parameter_list|,
name|segT
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* tc_gen_reloc handler */
end_comment

begin_function_decl
specifier|extern
name|arelent
modifier|*
name|gas_cgen_tc_gen_reloc
parameter_list|(
name|asection
modifier|*
parameter_list|,
name|fixS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Target supplied routine to lookup a reloc.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_reloc_code_real_type
name|md_cgen_lookup_reloc
parameter_list|(
specifier|const
name|CGEN_INSN
modifier|*
parameter_list|,
specifier|const
name|CGEN_OPERAND
modifier|*
parameter_list|,
name|fixS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Optional target supplied routine to record a fixup for an expression.  */
end_comment

begin_function_decl
specifier|extern
name|fixS
modifier|*
name|md_cgen_record_fixup_exp
parameter_list|(
name|fragS
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|CGEN_INSN
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|CGEN_OPERAND
modifier|*
parameter_list|,
name|int
parameter_list|,
name|expressionS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gas_cgen_md_operand
parameter_list|(
name|expressionS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Perform any cgen specific initialisation for gas.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|gas_cgen_begin
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
comment|/* GAS_CGEN_H */
end_comment

end_unit

