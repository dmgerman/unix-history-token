begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-score.h -- Score specific file for assembler    Copyright 2006 Free Software Foundation, Inc.    Contributed by:     Mei Ligang (ligang@sunnorth.com.cn)    Pei-Lin Tsai (pltsai@sunplus.com)      This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TC_SCORE
end_ifndef

begin_define
define|#
directive|define
name|TC_SCORE
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_score
end_define

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_define
define|#
directive|define
name|DIFF_EXPR_OK
end_define

begin_define
define|#
directive|define
name|RELOC_EXPANSION_POSSIBLE
end_define

begin_define
define|#
directive|define
name|MAX_RELOC_EXPANSION
value|2
end_define

begin_define
define|#
directive|define
name|MAX_MEM_FOR_RS_ALIGN_CODE
value|(3 + 4)
end_define

begin_define
define|#
directive|define
name|md_undefined_symbol
parameter_list|(
name|name
parameter_list|)
value|NULL
end_define

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|(target_big_endian ? "elf32-bigscore" : "elf32-littlescore")
end_define

begin_define
define|#
directive|define
name|md_relax_frag
parameter_list|(
name|segment
parameter_list|,
name|fragp
parameter_list|,
name|stretch
parameter_list|)
value|score_relax_frag (segment, fragp, stretch)
end_define

begin_function_decl
specifier|extern
name|int
name|score_relax_frag
parameter_list|(
name|asection
modifier|*
parameter_list|,
name|struct
name|frag
modifier|*
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_frag_check
parameter_list|(
name|fragp
parameter_list|)
value|score_frag_check (fragp)
end_define

begin_function_decl
specifier|extern
name|void
name|score_frag_check
parameter_list|(
name|fragS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TC_VALIDATE_FIX
parameter_list|(
name|FIXP
parameter_list|,
name|SEGTYPE
parameter_list|,
name|SKIP
parameter_list|)
value|score_validate_fix (FIXP)
end_define

begin_function_decl
specifier|extern
name|void
name|score_validate_fix
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
name|TC_FORCE_RELOCATION
parameter_list|(
name|FIXP
parameter_list|)
value|score_force_relocation (FIXP)
end_define

begin_function_decl
specifier|extern
name|int
name|score_force_relocation
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
name|fixp
parameter_list|)
value|score_fix_adjustable (fixp)
end_define

begin_function_decl
specifier|extern
name|bfd_boolean
name|score_fix_adjustable
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
name|elf_tc_final_processing
value|score_elf_final_processing
end_define

begin_function_decl
specifier|extern
name|void
name|score_elf_final_processing
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|score_tc_frag_data
block|{
name|unsigned
name|int
name|is_insn
decl_stmt|;
name|struct
name|fix
modifier|*
name|fixp
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TC_FRAG_TYPE
value|struct score_tc_frag_data
end_define

begin_define
define|#
directive|define
name|TC_FRAG_INIT
parameter_list|(
name|FRAGP
parameter_list|)
define|\
value|do \     { \       (FRAGP)->tc_frag_data.is_insn = (((FRAGP)->fr_type == rs_machine_dependent) ? 1 : 0); \     } \   while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_define
define|#
directive|define
name|GLOBAL_OFFSET_TABLE_NAME
value|"_GLOBAL_OFFSET_TABLE_"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GLOBAL_OFFSET_TABLE_NAME
value|"__GLOBAL_OFFSET_TABLE_"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
name|score_pic_level
block|{
name|NO_PIC
block|,
name|PIC
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*TC_SCORE */
end_comment

end_unit

