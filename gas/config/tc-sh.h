begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is tc-sh.h    Copyright 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002,    2003, 2004, 2005 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street - Fifth Floor,    Boston, MA 02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_SH
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_sh
end_define

begin_comment
comment|/* The type fixS is defined (to struct fix) in write.h, but write.h uses    definitions from this file.  To avoid problems with including write.h    after the "right" definitions, don't; just forward-declare struct fix    here.  */
end_comment

begin_struct_decl
struct_decl|struct
name|fix
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|segment_info_struct
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|internal_reloc
struct_decl|;
end_struct_decl

begin_comment
comment|/* Whether -relax was used.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sh_relax
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Whether -small was used.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sh_small
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Don't try to break words.  */
end_comment

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_comment
comment|/* We require .long, et. al., to be aligned correctly.  */
end_comment

begin_define
define|#
directive|define
name|md_cons_align
parameter_list|(
name|nbytes
parameter_list|)
value|sh_cons_align (nbytes)
end_define

begin_function_decl
specifier|extern
name|void
name|sh_cons_align
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* When relaxing, we need to generate relocations for alignment    directives.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_ALIGN
parameter_list|(
name|frag
parameter_list|)
value|sh_handle_align (frag)
end_define

begin_function_decl
specifier|extern
name|void
name|sh_handle_align
parameter_list|(
name|fragS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MAX_MEM_FOR_RS_ALIGN_CODE
value|(1 + 2)
end_define

begin_comment
comment|/* We need to force out some relocations when relaxing.  */
end_comment

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION
parameter_list|(
name|fix
parameter_list|)
value|sh_force_relocation (fix)
end_define

begin_function_decl
specifier|extern
name|int
name|sh_force_relocation
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This macro decides whether a particular reloc is an entry in a    switch table.  It is used when relaxing, because the linker needs    to know about all such entries so that it can adjust them if    necessary.  */
end_comment

begin_define
define|#
directive|define
name|SWITCH_TABLE
parameter_list|(
name|FIX
parameter_list|)
define|\
value|((FIX)->fx_addsy != NULL				\&& (FIX)->fx_subsy != NULL				\&& S_GET_SEGMENT ((FIX)->fx_addsy) == text_section	\&& S_GET_SEGMENT ((FIX)->fx_subsy) == text_section	\&& ((FIX)->fx_r_type == BFD_RELOC_32			\        || (FIX)->fx_r_type == BFD_RELOC_16		\        || (FIX)->fx_r_type == BFD_RELOC_8))
end_define

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
value|(! SEG_NORMAL (SEC)					\    || TC_FORCE_RELOCATION (FIX)				\    || (sh_relax&& SWITCH_TABLE (FIX)))
end_define

begin_comment
comment|/* Don't complain when we leave fx_subsy around.  */
end_comment

begin_define
define|#
directive|define
name|TC_VALIDATE_FIX_SUB
parameter_list|(
name|FIX
parameter_list|)
define|\
value|(sh_relax&& SWITCH_TABLE (FIX))
end_define

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
name|IGNORE_NONSTANDARD_ESCAPES
end_define

begin_define
define|#
directive|define
name|LISTING_HEADER
define|\
value|(!target_big_endian \    ? "Renesas / SuperH SH GAS Little Endian" \    : "Renesas / SuperH SH GAS Big Endian")
end_define

begin_define
define|#
directive|define
name|md_operand
parameter_list|(
name|x
parameter_list|)
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

begin_define
define|#
directive|define
name|TC_GENERIC_RELAX_TABLE
value|md_relax_table
end_define

begin_comment
comment|/* We record, for each section, whether we have most recently output a    CODE reloc or a DATA reloc.  */
end_comment

begin_struct
struct|struct
name|sh_segment_info_type
block|{
name|int
name|in_code
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TC_SEGMENT_INFO_TYPE
value|struct sh_segment_info_type
end_define

begin_comment
comment|/* We call a routine to emit a reloc for a label, so that the linker    can align loads and stores without crossing a label.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|sh_frob_label
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tc_frob_label
parameter_list|(
name|sym
parameter_list|)
value|sh_frob_label (sym)
end_define

begin_comment
comment|/* We call a routine to flush pending output in order to output a DATA    reloc when required.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|sh_flush_pending_output
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_flush_pending_output
parameter_list|()
value|sh_flush_pending_output ()
end_define

begin_define
define|#
directive|define
name|tc_frob_file_before_adjust
value|sh_frob_file
end_define

begin_function_decl
specifier|extern
name|void
name|sh_frob_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_COFF
end_ifdef

begin_comment
comment|/* COFF specific definitions.  */
end_comment

begin_define
define|#
directive|define
name|COFF_MAGIC
value|(!target_big_endian ? SH_ARCH_MAGIC_LITTLE : SH_ARCH_MAGIC_BIG)
end_define

begin_define
define|#
directive|define
name|tc_coff_symbol_emit_hook
parameter_list|(
name|a
parameter_list|)
value|;
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|TC_KEEP_FX_OFFSET
value|1
end_define

begin_define
define|#
directive|define
name|SEG_NAME
parameter_list|(
name|SEG
parameter_list|)
value|segment_name (SEG)
end_define

begin_comment
comment|/* We align most sections to a 16 byte boundary.  */
end_comment

begin_define
define|#
directive|define
name|SUB_SEGMENT_ALIGN
parameter_list|(
name|SEG
parameter_list|,
name|FRCHAIN
parameter_list|)
define|\
value|(strncmp (SEG_NAME (SEG), ".stabstr", 8) == 0		\    ? 0							\    : ((strncmp (SEG_NAME (SEG), ".stab", 5) == 0	\        || strcmp (SEG_NAME (SEG), ".ctors") == 0	\        || strcmp (SEG_NAME (SEG), ".dtors") == 0)	\       ? 2						\       : (sh_small ? 2 : 4)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OBJ_COFF */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_comment
comment|/* ELF specific definitions.  */
end_comment

begin_comment
comment|/* Whether or not the target is big endian */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|target_big_endian
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|TE_LINUX
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|(!target_big_endian ? "elf32-sh-linux" : "elf32-shbig-linux")
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|TE_NetBSD
argument_list|)
end_elif

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|(!target_big_endian ? "elf32-shl-nbsd" : "elf32-sh-nbsd")
end_define

begin_elif
elif|#
directive|elif
name|defined
name|TARGET_SYMBIAN
end_elif

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|(!target_big_endian ? "elf32-shl-symbian" : "elf32-sh-symbian")
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|(!target_big_endian ? "elf32-shl" : "elf32-sh")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|elf_tc_final_processing
value|sh_elf_final_processing
end_define

begin_function_decl
specifier|extern
name|void
name|sh_elf_final_processing
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DIFF_EXPR_OK
end_define

begin_comment
comment|/* foo-. gets turned into PC relative relocs */
end_comment

begin_define
define|#
directive|define
name|GLOBAL_OFFSET_TABLE_NAME
value|"_GLOBAL_OFFSET_TABLE_"
end_define

begin_comment
comment|/* This is the relocation type for direct references to    GLOBAL_OFFSET_TABLE.  It comes up in complicated expressions such    as _GLOBAL_OFFSET_TABLE_+[.-.L284], which cannot be expressed    normally with the regular expressions.  The fixup specified here    when used at runtime implies that we should add the address of the    GOT to the specified location, and as a result we have simplified    the expression into something we can use.  */
end_comment

begin_define
define|#
directive|define
name|TC_RELOC_GLOBAL_OFFSET_TABLE
value|BFD_RELOC_SH_GOTPC
end_define

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
value|sh_fix_adjustable(FIX)
end_define

begin_function_decl
specifier|extern
name|bfd_boolean
name|sh_fix_adjustable
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* This expression evaluates to true if the relocation is for a local object    for which we still want to do the relocation at runtime.  False if we    are willing to perform this relocation while building the .o file.     We can't resolve references to the GOT or the PLT when creating the    object file, since these tables are only created by the linker.    Also, if the symbol is global, weak, common or not defined, the    assembler can't compute the appropriate reloc, since its location    can only be determined at link time.  */
end_comment

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION_LOCAL
parameter_list|(
name|FIX
parameter_list|)
define|\
value|(!(FIX)->fx_pcrel					\    || (FIX)->fx_plt					\    || (FIX)->fx_r_type == BFD_RELOC_32_PLT_PCREL	\    || (FIX)->fx_r_type == BFD_RELOC_32_GOT_PCREL	\    || (FIX)->fx_r_type == BFD_RELOC_SH_GOTPC		\    || TC_FORCE_RELOCATION (FIX))
end_define

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION_SUB_LOCAL
parameter_list|(
name|FIX
parameter_list|)
value|(sh_relax&& SWITCH_TABLE (FIX))
end_define

begin_comment
comment|/* This keeps the subtracted symbol around, for use by PLT_PCREL    relocs.  */
end_comment

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION_SUB_ABS
parameter_list|(
name|FIX
parameter_list|)
define|\
value|((FIX)->fx_r_type == BFD_RELOC_32_PLT_PCREL)
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
value|((FIX)->fx_r_type == BFD_RELOC_32_PLT_PCREL		\    || (sh_relax&& SWITCH_TABLE (FIX)))
end_define

begin_define
define|#
directive|define
name|md_parse_name
parameter_list|(
name|name
parameter_list|,
name|exprP
parameter_list|,
name|mode
parameter_list|,
name|nextcharP
parameter_list|)
define|\
value|sh_parse_name ((name), (exprP), (mode), (nextcharP))
end_define

begin_function_decl
name|int
name|sh_parse_name
parameter_list|(
name|char
specifier|const
modifier|*
name|name
parameter_list|,
name|expressionS
modifier|*
name|exprP
parameter_list|,
name|enum
name|expr_mode
name|mode
parameter_list|,
name|char
modifier|*
name|nextchar
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TC_CONS_FIX_NEW
parameter_list|(
name|FRAG
parameter_list|,
name|OFF
parameter_list|,
name|LEN
parameter_list|,
name|EXP
parameter_list|)
define|\
value|sh_cons_fix_new ((FRAG), (OFF), (LEN), (EXP))
end_define

begin_function_decl
name|void
name|sh_cons_fix_new
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

begin_comment
comment|/* This is used to construct expressions out of @GOTOFF, @PLT and @GOT    symbols.  The relocation type is stored in X_md.  */
end_comment

begin_define
define|#
directive|define
name|O_PIC_reloc
value|O_md1
end_define

begin_define
define|#
directive|define
name|TARGET_USE_CFIPOP
value|1
end_define

begin_define
define|#
directive|define
name|tc_cfi_frame_initial_instructions
value|sh_cfi_frame_initial_instructions
end_define

begin_function_decl
specifier|extern
name|void
name|sh_cfi_frame_initial_instructions
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tc_regname_to_dw2regnum
value|sh_regname_to_dw2regnum
end_define

begin_function_decl
specifier|extern
name|int
name|sh_regname_to_dw2regnum
parameter_list|(
specifier|const
name|char
modifier|*
name|regname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* All SH instructions are multiples of 16 bits.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_LINE_MIN_INSN_LENGTH
value|2
end_define

begin_define
define|#
directive|define
name|DWARF2_DEFAULT_RETURN_COLUMN
value|17
end_define

begin_define
define|#
directive|define
name|DWARF2_CIE_DATA_ALIGNMENT
value|-4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OBJ_ELF */
end_comment

end_unit

