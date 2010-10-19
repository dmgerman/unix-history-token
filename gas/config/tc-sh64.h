begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is tc-sh64.h    Copyright 2000, 2001, 2002, 2003 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street - Fifth Floor,    Boston, MA 02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_SH64
end_define

begin_include
include|#
directive|include
file|"config/tc-sh.h"
end_include

begin_include
include|#
directive|include
file|"elf/sh.h"
end_include

begin_include
include|#
directive|include
file|"elf32-sh64.h"
end_include

begin_comment
comment|/* We need to override the tc-sh.h settings of HANDLE_ALIGN and    MAX_MEM_FOR_RS_ALIGN_CODE; we might need to put in SHmedia NOP:s, not    SHcompact NOP:s.  */
end_comment

begin_undef
undef|#
directive|undef
name|HANDLE_ALIGN
end_undef

begin_define
define|#
directive|define
name|HANDLE_ALIGN
parameter_list|(
name|frag
parameter_list|)
value|sh64_handle_align (frag)
end_define

begin_function_decl
specifier|extern
name|void
name|sh64_handle_align
parameter_list|(
name|fragS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|MAX_MEM_FOR_RS_ALIGN_CODE
end_undef

begin_define
define|#
directive|define
name|MAX_MEM_FOR_RS_ALIGN_CODE
value|sh64_max_mem_for_rs_align_code ()
end_define

begin_function_decl
specifier|extern
name|int
name|sh64_max_mem_for_rs_align_code
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|LISTING_HEADER
end_undef

begin_define
define|#
directive|define
name|LISTING_HEADER
define|\
value|(target_big_endian ?					\      "SuperH SHcompact/SHmedia Big Endian GAS"		\    : "SuperH SHcompact/SHmedia Little Endian GAS")
end_define

begin_comment
comment|/* We need to record the new frag position after an .align.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|sh64_do_align
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
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
name|md_do_align
parameter_list|(
name|n
parameter_list|,
name|fill
parameter_list|,
name|len
parameter_list|,
name|max
parameter_list|,
name|l
parameter_list|)
define|\
value|do { sh64_do_align (n, fill, len, max); goto l; } while (0)
end_define

begin_struct
struct|struct
name|sh64_segment_info_type
block|{
comment|/* The type of the section is initialized when the range_start_symbol      member is non-NULL.  */
name|symbolS
modifier|*
name|mode_start_symbol
decl_stmt|;
name|subsegT
name|mode_start_subseg
decl_stmt|;
comment|/* A stored symbol indicating location of last call of      "md_flush_pending_output".  It is NULLed when we actually use it;      otherwise the contents is just filled in with segment, frag and      offset within frag.  */
name|symbolS
modifier|*
name|last_contents_mark
decl_stmt|;
name|unsigned
name|int
name|emitted_ranges
decl_stmt|;
name|enum
name|sh64_elf_cr_type
name|contents_type
decl_stmt|;
comment|/* This is used by the SH1-4 parts; we set it to 0 for SHmedia code and      data.  */
name|unsigned
name|int
name|in_code
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_undef
undef|#
directive|undef
name|TC_SEGMENT_INFO_TYPE
end_undef

begin_define
define|#
directive|define
name|TC_SEGMENT_INFO_TYPE
value|struct sh64_segment_info_type
end_define

begin_undef
undef|#
directive|undef
name|TARGET_FORMAT
end_undef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|sh64_target_format ()
end_define

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|sh64_target_format
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TARGET_MACH
value|sh64_target_mach ()
end_define

begin_function_decl
specifier|extern
name|int
name|sh64_target_mach
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|TC_FORCE_RELOCATION_LOCAL
end_undef

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION_LOCAL
parameter_list|(
name|FIX
parameter_list|)
define|\
value|(!(FIX)->fx_pcrel					\    || (FIX)->fx_plt					\    || (FIX)->fx_r_type == BFD_RELOC_32_PLT_PCREL	\    || (FIX)->fx_r_type == BFD_RELOC_SH_PLT_LOW16	\    || (FIX)->fx_r_type == BFD_RELOC_SH_PLT_MEDLOW16	\    || (FIX)->fx_r_type == BFD_RELOC_SH_PLT_MEDHI16	\    || (FIX)->fx_r_type == BFD_RELOC_SH_PLT_HI16		\    || (FIX)->fx_r_type == BFD_RELOC_32_GOT_PCREL	\    || (FIX)->fx_r_type == BFD_RELOC_SH_GOT_LOW16	\    || (FIX)->fx_r_type == BFD_RELOC_SH_GOT_MEDLOW16	\    || (FIX)->fx_r_type == BFD_RELOC_SH_GOT_MEDHI16	\    || (FIX)->fx_r_type == BFD_RELOC_SH_GOT_HI16		\    || (FIX)->fx_r_type == BFD_RELOC_SH_GOT10BY4		\    || (FIX)->fx_r_type == BFD_RELOC_SH_GOT10BY8		\    || (FIX)->fx_r_type == BFD_RELOC_SH_GOTPLT32		\    || (FIX)->fx_r_type == BFD_RELOC_SH_GOTPLT_LOW16	\    || (FIX)->fx_r_type == BFD_RELOC_SH_GOTPLT_MEDLOW16	\    || (FIX)->fx_r_type == BFD_RELOC_SH_GOTPLT_MEDHI16	\    || (FIX)->fx_r_type == BFD_RELOC_SH_GOTPLT_HI16	\    || (FIX)->fx_r_type == BFD_RELOC_SH_GOTPLT10BY4	\    || (FIX)->fx_r_type == BFD_RELOC_SH_GOTPLT10BY8	\    || (FIX)->fx_r_type == BFD_RELOC_SH_GOTPC		\    || (FIX)->fx_r_type == BFD_RELOC_SH_GOTPC_LOW16	\    || (FIX)->fx_r_type == BFD_RELOC_SH_GOTPC_MEDLOW16	\    || (FIX)->fx_r_type == BFD_RELOC_SH_GOTPC_MEDHI16	\    || (FIX)->fx_r_type == BFD_RELOC_SH_GOTPC_HI16	\    || TC_FORCE_RELOCATION (FIX))
end_define

begin_undef
undef|#
directive|undef
name|TC_FORCE_RELOCATION_SUB_SAME
end_undef

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION_SUB_SAME
parameter_list|(
name|FIX
parameter_list|,
name|SEC
parameter_list|)
define|\
value|(! SEG_NORMAL (SEC)					\    || TC_FORCE_RELOCATION (FIX)				\    || (sh_relax&& SWITCH_TABLE (FIX))			\    || *symbol_get_tc ((FIX)->fx_addsy) != NULL)
end_define

begin_comment
comment|/* Don't complain when we leave fx_subsy around.  */
end_comment

begin_undef
undef|#
directive|undef
name|TC_VALIDATE_FIX_SUB
end_undef

begin_define
define|#
directive|define
name|TC_VALIDATE_FIX_SUB
parameter_list|(
name|FIX
parameter_list|)
define|\
value|((FIX)->fx_r_type == BFD_RELOC_32_PLT_PCREL		\    || (sh_relax&& SWITCH_TABLE (FIX))			\    || *symbol_get_tc ((FIX)->fx_addsy) != NULL)
end_define

begin_comment
comment|/* Note the kludge: we want to put back C, and we also want to consume the    expression, since we have handled it ourselves.  FIXME: What we really    need is a new GAS infrastructure feature: md_qualifier.  */
end_comment

begin_undef
undef|#
directive|undef
name|md_parse_name
end_undef

begin_define
define|#
directive|define
name|md_parse_name
parameter_list|(
name|NAME
parameter_list|,
name|EXP
parameter_list|,
name|MODE
parameter_list|,
name|CP
parameter_list|)
define|\
value|sh64_consume_datalabel (NAME, EXP, MODE, CP, operand)
end_define

begin_decl_stmt
specifier|extern
name|int
name|sh64_consume_datalabel
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|expressionS
operator|*
argument_list|,
expr|enum
name|expr_mode
argument_list|,
name|char
operator|*
argument_list|,
name|segT
argument_list|(
operator|*
argument_list|)
argument_list|(
name|expressionS
operator|*
argument_list|,
expr|enum
name|expr_mode
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Saying "$" is the same as saying ".".  */
end_comment

begin_define
define|#
directive|define
name|DOLLAR_DOT
end_define

begin_undef
undef|#
directive|undef
name|MD_PCREL_FROM_SECTION
end_undef

begin_define
define|#
directive|define
name|MD_PCREL_FROM_SECTION
parameter_list|(
name|FIX
parameter_list|,
name|SEC
parameter_list|)
define|\
value|shmedia_md_pcrel_from_section (FIX, SEC)
end_define

begin_function_decl
specifier|extern
name|valueT
name|shmedia_md_pcrel_from_section
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|,
name|segT
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* We need to mark this symbol as a BranchTarget; setting st_other for it    and adding 1 to its value (temporarily).  */
end_comment

begin_function_decl
specifier|extern
name|void
name|sh64_frob_label
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|tc_frob_label
end_undef

begin_define
define|#
directive|define
name|tc_frob_label
parameter_list|(
name|sym
parameter_list|)
define|\
value|do { sh_frob_label (sym); sh64_frob_label (sym); } while (0)
end_define

begin_define
define|#
directive|define
name|tc_symbol_new_hook
parameter_list|(
name|s
parameter_list|)
value|sh64_frob_label (s)
end_define

begin_comment
comment|/* We use this to mark our "datalabel" symbol copies.  The "mark" is NULL    for an ordinary symbol, and the pointer to the "ordinary" symbol for a    datalabel symbol.  */
end_comment

begin_define
define|#
directive|define
name|TC_SYMFIELD_TYPE
value|symbolS *
end_define

begin_define
define|#
directive|define
name|tc_frob_symbol
parameter_list|(
name|symp
parameter_list|,
name|punt
parameter_list|)
define|\
value|do						\    {						\      punt = sh64_exclude_symbol (symp);		\    }						\  while (0)
end_define

begin_function_decl
specifier|extern
name|int
name|sh64_exclude_symbol
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sh64_adjust_symtab
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tc_adjust_symtab
value|sh64_adjust_symtab
end_define

begin_undef
undef|#
directive|undef
name|md_flush_pending_output
end_undef

begin_define
define|#
directive|define
name|md_flush_pending_output
parameter_list|()
value|sh64_flush_pending_output ()
end_define

begin_function_decl
specifier|extern
name|void
name|sh64_flush_pending_output
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Note that tc-sh.c has a sh_frob_section, but it's called from    tc_frob_file_before_adjust.  */
end_comment

begin_define
define|#
directive|define
name|tc_frob_section
parameter_list|(
name|sec
parameter_list|)
value|shmedia_frob_section_type (sec)
end_define

begin_function_decl
specifier|extern
name|void
name|shmedia_frob_section_type
parameter_list|(
name|asection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* We need to emit fixups relative to the frag in which the instruction    resides.  Safest way without calculating max fragment growth or making    it a fixed number is to provide a pointer to the opcode frag.     We also need to emit the right NOP pattern in .align frags.  This is    done after the text-to-bits assembly pass, so we need to mark it with    the ISA setting at the time the .align was assembled.  */
end_comment

begin_define
define|#
directive|define
name|TC_FRAG_TYPE
value|struct sh64_tc_frag_data
end_define

begin_enum
enum|enum
name|sh64_isa_values
block|{
name|sh64_isa_unspecified
block|,
name|sh64_isa_shcompact
block|,
name|sh64_isa_shmedia
block|,
comment|/* Special guard value used in contexts when we don't know which ISA it       is, just that it's specified (not sh64_isa_unspecified).  */
name|sh64_isa_sh5_guard
block|}
enum|;
end_enum

begin_struct
struct|struct
name|sh64_tc_frag_data
block|{
name|fragS
modifier|*
name|opc_frag
decl_stmt|;
name|enum
name|sh64_isa_values
name|isa
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|enum
name|sh64_isa_values
name|sh64_isa_mode
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_FRAG_INIT
parameter_list|(
name|FRAGP
parameter_list|)
define|\
value|do								\    {								\      (FRAGP)->tc_frag_data.opc_frag = sh64_last_insn_frag;	\      (FRAGP)->tc_frag_data.isa = sh64_isa_mode;			\    }								\  while (0)
end_define

begin_comment
comment|/* This variable is set whenever we generate (or grow) a new opcode frag    in shmedia_build_Mytes.  */
end_comment

begin_decl_stmt
specifier|extern
name|fragS
modifier|*
name|sh64_last_insn_frag
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|md_end
parameter_list|()
value|shmedia_md_end ()
end_define

begin_function_decl
name|void
name|shmedia_md_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Because we make .debug_line hold the SHmedia instruction address | 1,    we have to say we only have minimum byte-size insns.  */
end_comment

begin_undef
undef|#
directive|undef
name|DWARF2_LINE_MIN_INSN_LENGTH
end_undef

begin_define
define|#
directive|define
name|DWARF2_LINE_MIN_INSN_LENGTH
value|1
end_define

begin_define
define|#
directive|define
name|TC_FAKE_LABEL
parameter_list|(
name|NAME
parameter_list|)
value|sh64_fake_label(NAME)
end_define

begin_function_decl
specifier|extern
name|int
name|sh64_fake_label
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

