begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-fr30.h -- Header file for tc-fr30.c.    Copyright 1998, 1999, 2000, 2001, 2002, 2003    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_FR30
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_ASSEMBLER
end_ifndef

begin_comment
comment|/* leading space so will compile with cc */
end_comment

begin_error
error|#
directive|error
error|FR30 support requires BFD_ASSEMBLER
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LISTING_HEADER
value|"FR30 GAS "
end_define

begin_comment
comment|/* The target BFD architecture.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_fr30
end_define

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"elf32-fr30"
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

begin_define
define|#
directive|define
name|DIFF_EXPR_OK
end_define

begin_comment
comment|/* .-foo gets turned into PC relative relocs */
end_comment

begin_comment
comment|/* We don't need to handle .word strangely.  */
end_comment

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
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
value|gas_cgen_md_apply_fix3
end_define

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
value|fr30_fix_adjustable (FIX)
end_define

begin_struct_decl
struct_decl|struct
name|fix
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|fr30_fix_adjustable
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

begin_comment
comment|/* Call md_pcrel_from_section(), not md_pcrel_from().  */
end_comment

begin_define
define|#
directive|define
name|MD_PCREL_FROM_SECTION
parameter_list|(
name|FIX
parameter_list|,
name|SEC
parameter_list|)
value|md_pcrel_from_section (FIX, SEC)
end_define

begin_decl_stmt
specifier|extern
name|long
name|md_pcrel_from_section
name|PARAMS
argument_list|(
operator|(
expr|struct
name|fix
operator|*
operator|,
name|segT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For 8 vs 16 vs 32 bit branch selection.  */
end_comment

begin_define
define|#
directive|define
name|TC_GENERIC_RELAX_TABLE
value|md_relax_table
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|relax_type
name|md_relax_table
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* We need a special version of the TC_START_LABEL macro so that we    allow the LDI:8, LDI:20, LDI:32 and delay slot instructions to be    parsed as such.  Note - in a HORRIBLE HACK, we make use of the    knowledge that this marco is only ever evaluated in one place    (read_a_source_file in read.c) where we can access the local    variable 's' - the start of the symbol that was terminated by    'character'.  Also we need to be able to change the contents of    the local variable 'c' which is passed to this macro as 'character'.  */
end_comment

begin_define
define|#
directive|define
name|TC_START_LABEL
parameter_list|(
name|character
parameter_list|,
name|i_l_p
parameter_list|)
define|\
value|((character) != ':' ? 0 : (character = fr30_is_colon_insn (s)) ? 0 : ((character = ':'), 1))
end_define

begin_decl_stmt
specifier|extern
name|char
name|fr30_is_colon_insn
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

