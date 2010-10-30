begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* spu.h -- Assembler for spu     Copyright 2006, 2007 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TC_SPU
end_ifndef

begin_define
define|#
directive|define
name|TC_SPU
value|1
end_define

begin_include
include|#
directive|include
file|"opcode/spu.h"
end_include

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"elf32-spu"
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_spu
end_define

begin_define
define|#
directive|define
name|TARGET_NAME
value|"elf32-spu"
end_define

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|1
end_define

begin_struct
struct|struct
name|tc_fix_info
block|{
name|unsigned
name|short
name|arg_format
decl_stmt|;
name|unsigned
name|short
name|insn_tag
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* fixS will have a member named tc_fix_data of this type.  */
end_comment

begin_define
define|#
directive|define
name|TC_FIX_TYPE
value|struct tc_fix_info
end_define

begin_define
define|#
directive|define
name|TC_INIT_FIX_DATA
parameter_list|(
name|FIXP
parameter_list|)
define|\
value|do						\     {						\       (FIXP)->tc_fix_data.arg_format = 0;	\       (FIXP)->tc_fix_data.insn_tag = 0;		\     }						\   while (0)
end_define

begin_comment
comment|/* Don't reduce function symbols to section symbols, and don't adjust    references to PPU symbols.  */
end_comment

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIXP
parameter_list|)
define|\
value|(!(S_IS_FUNCTION ((FIXP)->fx_addsy)			\      || (FIXP)->fx_r_type == BFD_RELOC_SPU_PPU32	\      || (FIXP)->fx_r_type == BFD_RELOC_SPU_PPU64))
end_define

begin_comment
comment|/* Keep relocs on calls.  Branches to function symbols are tail or    sibling calls.  */
end_comment

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION
parameter_list|(
name|FIXP
parameter_list|)
define|\
value|((FIXP)->tc_fix_data.insn_tag == M_BRSL		\    || (FIXP)->tc_fix_data.insn_tag == M_BRASL		\    || (((FIXP)->tc_fix_data.insn_tag == M_BR		\ 	|| (FIXP)->tc_fix_data.insn_tag == M_BRA)	\&& (FIXP)->fx_addsy != NULL			\&& S_IS_FUNCTION ((FIXP)->fx_addsy))		\    || (FIXP)->fx_r_type == BFD_RELOC_SPU_PPU32		\    || (FIXP)->fx_r_type == BFD_RELOC_SPU_PPU64		\    || generic_force_reloc (FIXP))
end_define

begin_comment
comment|/* Values passed to md_apply_fix don't include symbol values.  */
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
comment|/* The spu uses pseudo-ops with no leading period.  */
end_comment

begin_define
define|#
directive|define
name|NO_PSEUDO_DOT
value|1
end_define

begin_comment
comment|/* Don't warn on word overflow; it happens on %hi relocs.  */
end_comment

begin_undef
undef|#
directive|undef
name|WARN_SIGNED_OVERFLOW_WORD
end_undef

begin_define
define|#
directive|define
name|DIFF_EXPR_OK
end_define

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_define
define|#
directive|define
name|md_number_to_chars
value|number_to_chars_bigendian
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
value|{as_fatal (_("spu convert_frag\n"));}
end_define

begin_comment
comment|/* We don't need to do anything special for undefined symbols.  */
end_comment

begin_define
define|#
directive|define
name|md_undefined_symbol
parameter_list|(
name|s
parameter_list|)
value|0
end_define

begin_function_decl
specifier|extern
name|symbolS
modifier|*
name|section_symbol
parameter_list|(
name|asection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_operand
parameter_list|(
name|e
parameter_list|)
define|\
value|do {								\     if (strncasecmp (input_line_pointer, "@ppu", 4) == 0)	\       {								\ 	e->X_op = O_symbol;					\ 	if (abs_section_sym == NULL)				\ 	  abs_section_sym = section_symbol (absolute_section);	\ 	e->X_add_symbol = abs_section_sym;			\ 	e->X_add_number = 0;					\       }								\   } while (0)
end_define

begin_comment
comment|/* Fill in rs_align_code fragments.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|spu_handle_align
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|HANDLE_ALIGN
parameter_list|(
name|frag
parameter_list|)
value|spu_handle_align (frag)
end_define

begin_define
define|#
directive|define
name|MAX_MEM_FOR_RS_ALIGN_CODE
value|(7 + 8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_SPU */
end_comment

end_unit

