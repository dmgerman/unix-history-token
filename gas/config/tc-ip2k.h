begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-ip2k.h -- Header file for tc-ip2k.c.    Copyright (C) 2000, 2002 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_IP2K
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_ASSEMBLER
end_ifndef

begin_comment
comment|/* Leading space so will compile with cc.  */
end_comment

begin_error
error|#
directive|error
error|IP2K support requires BFD_ASSEMBLER
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LISTING_HEADER
value|"IP2xxx GAS "
end_define

begin_comment
comment|/* The target BFD architecture.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_ip2k
end_define

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"elf32-ip2k"
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
name|DOUBLESLASH_LINE_COMMENTS
end_define

begin_comment
comment|/* Values passed to md_apply_fix3 don't include the symbol value.  */
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
name|md_apply_fix3
value|ip2k_apply_fix3
end_define

begin_define
define|#
directive|define
name|TC_HANDLES_FX_DONE
end_define

begin_comment
comment|/* No shared lib support, so we don't need to ensure externally    visible symbols can be overridden.  */
end_comment

begin_define
define|#
directive|define
name|EXTERN_FORCE_RELOC
value|0
end_define

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION
parameter_list|(
name|FIX
parameter_list|)
value|ip2k_force_relocation (FIX)
end_define

begin_decl_stmt
specifier|extern
name|int
name|ip2k_force_relocation
name|PARAMS
argument_list|(
operator|(
expr|struct
name|fix
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tc_gen_reloc
value|gas_cgen_tc_gen_reloc
end_define

begin_define
define|#
directive|define
name|md_elf_section_flags
value|ip2k_elf_section_flags
end_define

begin_decl_stmt
specifier|extern
name|int
name|ip2k_elf_section_flags
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|md_operand
parameter_list|(
name|x
parameter_list|)
value|gas_cgen_md_operand (x)
end_define

begin_decl_stmt
specifier|extern
name|void
name|gas_cgen_md_operand
name|PARAMS
argument_list|(
operator|(
name|expressionS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

