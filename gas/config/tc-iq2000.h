begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-iq2000.h -- Header file for tc-iq2000.c.    Copyright (C) 2003, 2004, 2005 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street - Fifth Floor,    Boston, MA 02110-1301, USA. */
end_comment

begin_define
define|#
directive|define
name|TC_IQ2000
end_define

begin_define
define|#
directive|define
name|LISTING_HEADER
value|"IQ2000 GAS "
end_define

begin_comment
comment|/* The target BFD architecture.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_iq2000
end_define

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"elf32-iq2000"
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

begin_define
define|#
directive|define
name|md_apply_fix
value|gas_cgen_md_apply_fix
end_define

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

begin_define
define|#
directive|define
name|tc_frob_file
parameter_list|()
value|iq2000_frob_file ()
end_define

begin_define
define|#
directive|define
name|obj_fix_adjustable
parameter_list|(
name|fixP
parameter_list|)
value|iq2000_fix_adjustable (fixP)
end_define

begin_comment
comment|/* After creating a fixup for an instruction operand, we need to check    for HI16 relocs and queue them up for later sorting.  */
end_comment

begin_define
define|#
directive|define
name|md_cgen_record_fixup_exp
value|iq2000_cgen_record_fixup_exp
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
value|iq2000_force_relocation (fix)
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
name|tc_gen_reloc
value|gas_cgen_tc_gen_reloc
end_define

begin_function_decl
specifier|extern
name|void
name|iq2000_frob_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|iq2000_fix_adjustable
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|iq2000_force_relocation
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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

end_unit

