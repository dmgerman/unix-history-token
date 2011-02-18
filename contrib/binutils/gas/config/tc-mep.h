begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-mep.h -- Header file for tc-mep.c.    Copyright (C) 2001, 2002, 2005 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street, Fifth Floor,    Boston, MA 02110-1301, USA. */
end_comment

begin_define
define|#
directive|define
name|TC_MEP
end_define

begin_comment
comment|/* Support computed relocations.  */
end_comment

begin_define
define|#
directive|define
name|OBJ_COMPLEX_RELC
end_define

begin_comment
comment|/* Support many operands per instruction.  */
end_comment

begin_define
define|#
directive|define
name|GAS_CGEN_MAX_FIXUPS
value|10
end_define

begin_define
define|#
directive|define
name|LISTING_HEADER
value|"MEP GAS "
end_define

begin_comment
comment|/* The target BFD architecture.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_mep
end_define

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|(target_big_endian ? "elf32-mep" : "elf32-mep-little")
end_define

begin_comment
comment|/* This is the default.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* Permit temporary numeric labels. */
end_comment

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
value|1
end_define

begin_comment
comment|/* .-foo gets turned into PC relative relocs.  */
end_comment

begin_define
define|#
directive|define
name|DIFF_EXPR_OK
end_define

begin_comment
comment|/* We don't need to handle .word strangely.  */
end_comment

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_comment
comment|/* Values passed to md_apply_fix don't include the symbol value.  */
end_comment

begin_define
define|#
directive|define
name|MD_APPLY_SYM_VALUE
parameter_list|(
name|FIX
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|MD_APPLY_FIX
end_define

begin_define
define|#
directive|define
name|md_apply_fix
value|mep_apply_fix
end_define

begin_function_decl
specifier|extern
name|void
name|mep_apply_fix
parameter_list|(
name|struct
name|fix
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
comment|/* Call md_pcrel_from_section(), not md_pcrel_from().  */
end_comment

begin_define
define|#
directive|define
name|MD_PCREL_FROM_SECTION
parameter_list|(
name|FIXP
parameter_list|,
name|SEC
parameter_list|)
value|md_pcrel_from_section (FIXP, SEC)
end_define

begin_function_decl
specifier|extern
name|long
name|md_pcrel_from_section
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|,
name|segT
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tc_frob_file
parameter_list|()
value|mep_frob_file ()
end_define

begin_function_decl
specifier|extern
name|void
name|mep_frob_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|fixP
parameter_list|)
value|mep_fix_adjustable (fixP)
end_define

begin_function_decl
specifier|extern
name|bfd_boolean
name|mep_fix_adjustable
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* After creating a fixup for an instruction operand, we need    to check for HI16 relocs and queue them up for later sorting.  */
end_comment

begin_define
define|#
directive|define
name|md_cgen_record_fixup_exp
value|mep_cgen_record_fixup_exp
end_define

begin_comment
comment|/* When relaxing, we need to emit various relocs we otherwise wouldn't.  */
end_comment

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION
parameter_list|(
name|fix
parameter_list|)
value|mep_force_relocation (fix)
end_define

begin_function_decl
specifier|extern
name|int
name|mep_force_relocation
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tc_gen_reloc
value|gas_cgen_tc_gen_reloc
end_define

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

begin_define
define|#
directive|define
name|md_operand
parameter_list|(
name|x
parameter_list|)
value|gas_cgen_md_operand (x)
end_define

begin_define
define|#
directive|define
name|md_flush_pending_output
parameter_list|()
value|mep_flush_pending_output()
end_define

begin_function_decl
specifier|extern
name|int
name|mep_flush_pending_output
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|relax_type
name|md_relax_table
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_GENERIC_RELAX_TABLE
value|md_relax_table
end_define

begin_comment
comment|/* Account for inserting a jmp after the insn.  */
end_comment

begin_define
define|#
directive|define
name|TC_CGEN_MAX_RELAX
parameter_list|(
name|insn
parameter_list|,
name|len
parameter_list|)
value|((len) + 4)
end_define

begin_function_decl
specifier|extern
name|void
name|mep_prepare_relax_scan
parameter_list|(
name|fragS
modifier|*
parameter_list|,
name|offsetT
modifier|*
parameter_list|,
name|relax_substateT
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_prepare_relax_scan
parameter_list|(
name|FRAGP
parameter_list|,
name|ADDR
parameter_list|,
name|AIM
parameter_list|,
name|STATE
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|mep_prepare_relax_scan (FRAGP,&AIM, STATE)
end_define

begin_define
define|#
directive|define
name|skip_whitespace
parameter_list|(
name|str
parameter_list|)
value|while (*(str) == ' ') ++(str)
end_define

begin_comment
comment|/* Support for core/vliw mode switching.  */
end_comment

begin_define
define|#
directive|define
name|CORE
value|0
end_define

begin_define
define|#
directive|define
name|VLIW
value|1
end_define

begin_define
define|#
directive|define
name|MAX_PARALLEL_INSNS
value|56
end_define

begin_comment
comment|/* From email from Toshiba.  */
end_comment

begin_define
define|#
directive|define
name|VTEXT_SECTION_NAME
value|".vtext"
end_define

begin_comment
comment|/* Needed to process pending instructions when a label is encountered.  */
end_comment

begin_define
define|#
directive|define
name|TC_START_LABEL
parameter_list|(
name|ch
parameter_list|,
name|ptr
parameter_list|)
value|((ch == ':')&& mep_flush_pending_output ())
end_define

begin_define
define|#
directive|define
name|tc_unrecognized_line
parameter_list|(
name|c
parameter_list|)
value|mep_unrecognized_line (c)
end_define

begin_function_decl
specifier|extern
name|int
name|mep_unrecognized_line
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_cleanup
value|mep_cleanup
end_define

begin_function_decl
specifier|extern
name|void
name|mep_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_elf_section_letter
value|mep_elf_section_letter
end_define

begin_function_decl
specifier|extern
name|int
name|mep_elf_section_letter
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_elf_section_flags
value|mep_elf_section_flags
end_define

begin_function_decl
specifier|extern
name|flagword
name|mep_elf_section_flags
parameter_list|(
name|flagword
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ELF_TC_SPECIAL_SECTIONS
define|\
value|{ VTEXT_SECTION_NAME, SHT_PROGBITS, SHF_ALLOC|SHF_EXECINSTR|SHF_MEP_VLIW },
end_define

begin_comment
comment|/* The values of the following enum are for use with parinsnum, which     is a variable in md_assemble that keeps track of whether or not the    next instruction is expected to be the first or second instrucion in    a parallelization group.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|exp_par_insn_
block|{
name|FIRST
block|,
name|SECOND
block|}
name|EXP_PAR_INSN
typedef|;
end_typedef

end_unit

