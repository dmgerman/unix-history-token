begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-bfin.h - header file for tc-bfin.c    Copyright 2005    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_BFIN
value|1
end_define

begin_define
define|#
directive|define
name|TC_ADI_BFIN
value|1
end_define

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_bfin
end_define

begin_comment
comment|/*  * Define the target format macro here.   The value for this should be  * "elf32-bfin", not "elf32-little-bfin".  Since the BFD source file   * elf32-bfin.c defines TARGET_LITTLE_NAME to be "elf32-little-bfin",  * we must use this value, until this is corrected and BFD is rebuilt.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"elf32-bfin"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LISTING_HEADER
value|"BFIN GAS "
end_define

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_decl_stmt
specifier|extern
name|void
name|bfin_start_line_hook
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
name|bfd_boolean
name|bfin_start_label
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|md_start_line_hook
parameter_list|()
value|bfin_start_line_hook()
end_define

begin_define
define|#
directive|define
name|md_number_to_chars
value|number_to_chars_littleendian
end_define

begin_define
define|#
directive|define
name|md_convert_frag
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|,
name|f
parameter_list|)
value|as_fatal ("bfin convert_frag\n");
end_define

begin_comment
comment|/* Allow for [, ], etc.  */
end_comment

begin_define
define|#
directive|define
name|LEX_BR
value|6
end_define

begin_define
define|#
directive|define
name|TC_EOL_IN_INSN
parameter_list|(
name|PTR
parameter_list|)
value|(bfin_eol_in_insn(PTR) ? 1 : 0)
end_define

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|bfin_eol_in_insn
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The instruction is permitted to contain an = character.  */
end_comment

begin_define
define|#
directive|define
name|TC_EQUAL_IN_INSN
parameter_list|(
name|C
parameter_list|,
name|NAME
parameter_list|)
value|(bfin_name_is_register (NAME) ? 1 : 0)
end_define

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|bfin_name_is_register
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NOP_OPCODE
value|0x0000
end_define

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
value|1
end_define

begin_define
define|#
directive|define
name|DOUBLESLASH_LINE_COMMENTS
end_define

begin_define
define|#
directive|define
name|TC_START_LABEL
parameter_list|(
name|ch
parameter_list|,
name|ptr
parameter_list|)
value|(ch == ':'&& bfin_start_label (ptr))
end_define

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
value|bfin_fix_adjustable (FIX)
end_define

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|bfin_fix_adjustable
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
name|TC_FORCE_RELOCATION
parameter_list|(
name|FIX
parameter_list|)
value|bfin_force_relocation (FIX)
end_define

begin_decl_stmt
specifier|extern
name|int
name|bfin_force_relocation
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
comment|/* Values passed to md_apply_fix3 don't include symbol values.  */
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
comment|/* end of tc-bfin.h */
end_comment

end_unit

