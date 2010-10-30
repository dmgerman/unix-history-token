begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-m32c.h -- Header file for tc-m32c.c.    Copyright (C) 2004, 2005 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA. */
end_comment

begin_define
define|#
directive|define
name|TC_M32C
end_define

begin_define
define|#
directive|define
name|LISTING_HEADER
value|"M16C/M32C GAS "
end_define

begin_comment
comment|/* The target BFD architecture.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_m32c
end_define

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"elf32-m32c"
end_define

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|1
end_define

begin_define
define|#
directive|define
name|md_end
value|m32c_md_end
end_define

begin_function_decl
specifier|extern
name|void
name|m32c_md_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_start_line_hook
value|m32c_start_line_hook
end_define

begin_function_decl
specifier|extern
name|void
name|m32c_start_line_hook
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* call md_pcrel_from_section, not md_pcrel_from */
end_comment

begin_decl_stmt
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

begin_define
define|#
directive|define
name|md_apply_fix
value|m32c_apply_fix
end_define

begin_decl_stmt
specifier|extern
name|void
name|m32c_apply_fix
name|PARAMS
argument_list|(
operator|(
expr|struct
name|fix
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

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|fixP
parameter_list|)
value|m32c_fix_adjustable (fixP)
end_define

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|m32c_fix_adjustable
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
value|m32c_force_relocation (fix)
end_define

begin_decl_stmt
specifier|extern
name|int
name|m32c_force_relocation
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
name|TC_CONS_FIX_NEW
parameter_list|(
name|FRAG
parameter_list|,
name|WHERE
parameter_list|,
name|NBYTES
parameter_list|,
name|EXP
parameter_list|)
define|\
value|m32c_cons_fix_new (FRAG, WHERE, NBYTES, EXP)
end_define

begin_function_decl
specifier|extern
name|void
name|m32c_cons_fix_new
parameter_list|(
name|fragS
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|expressionS
modifier|*
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

begin_decl_stmt
specifier|extern
name|void
name|m32c_prepare_relax_scan
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
operator|,
name|offsetT
operator|*
operator|,
name|relax_substateT
name|state
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
value|m32c_prepare_relax_scan(FRAGP,&AIM, STATE)
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
comment|/* We need a special version of the TC_START_LABEL macro so that we    allow the :Z, :S, :Q and :G suffixes to be    parsed as such.  Note - in a HORRIBLE HACK, we make use of the    knowledge that this marco is only ever evaluated in one place    (read_a_source_file in read.c) where we can access the local    variable 's' - the start of the symbol that was terminated by    'character'.  Also we need to be able to change the contents of    the local variable 'c' which is passed to this macro as 'character'.  */
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
value|((character) != ':' ? 0 : (character = m32c_is_colon_insn (s)) ? 0 : ((character = ':'), 1))
end_define

begin_decl_stmt
specifier|extern
name|char
name|m32c_is_colon_insn
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

