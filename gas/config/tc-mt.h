begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-mt.h -- Header file for tc-mt.c.    Copyright (C) 2005 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA. */
end_comment

begin_define
define|#
directive|define
name|TC_MT
end_define

begin_define
define|#
directive|define
name|LISTING_HEADER
value|"MT GAS "
end_define

begin_comment
comment|/* The target BFD architecture.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_mt
end_define

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"elf32-mt"
end_define

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* Permit temporary numeric labels.  */
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
comment|/* All mt instructions are multiples of 32 bits.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_LINE_MIN_INSN_LENGTH
value|4
end_define

begin_define
define|#
directive|define
name|LITERAL_PREFIXDOLLAR_HEX
end_define

begin_define
define|#
directive|define
name|LITERAL_PREFIXPERCENT_BIN
end_define

begin_define
define|#
directive|define
name|md_apply_fix
value|mt_apply_fix
end_define

begin_function_decl
specifier|extern
name|void
name|mt_apply_fix
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
name|obj_fix_adjustable
parameter_list|(
name|fixP
parameter_list|)
value|iq2000_fix_adjustable (fixP)
end_define

begin_function_decl
specifier|extern
name|bfd_boolean
name|mt_fix_adjustable
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
name|tc_gen_reloc
value|gas_cgen_tc_gen_reloc
end_define

begin_define
define|#
directive|define
name|md_operand
parameter_list|(
name|x
parameter_list|)
value|gas_cgen_md_operand (x)
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
name|TC_FORCE_RELOCATION
parameter_list|(
name|fixp
parameter_list|)
value|mt_force_relocation (fixp)
end_define

begin_function_decl
specifier|extern
name|int
name|mt_force_relocation
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
name|tc_fix_adjustable
parameter_list|(
name|fixP
parameter_list|)
value|mt_fix_adjustable (fixP)
end_define

begin_function_decl
specifier|extern
name|bfd_boolean
name|mt_fix_adjustable
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

