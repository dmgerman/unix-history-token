begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-m32r.h -- Header file for tc-m32r.c.    Copyright 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005,    2007 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street - Fifth Floor,    Boston, MA 02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_M32R
end_define

begin_define
define|#
directive|define
name|LISTING_HEADER
define|\
value|(target_big_endian ? "M32R GAS" : "M32R GAS Little Endian")
end_define

begin_comment
comment|/* The target BFD architecture.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_m32r
end_define

begin_comment
comment|/* The endianness of the target format may change based on command    line arguments.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|m32r_target_format()
end_define

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|m32r_target_format
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Default to big endian.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_BYTES_BIG_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Call md_pcrel_from_section, not md_pcrel_from.  */
end_comment

begin_function_decl
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
name|MD_PCREL_FROM_SECTION
parameter_list|(
name|FIX
parameter_list|,
name|SEC
parameter_list|)
value|md_pcrel_from_section(FIX, SEC)
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
comment|/* .-foo gets turned into PC relative relocs.  */
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
comment|/* For 8 vs 16 vs 32 bit branch selection.  */
end_comment

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

begin_function_decl
specifier|extern
name|long
name|m32r_relax_frag
parameter_list|(
name|segT
parameter_list|,
name|fragS
modifier|*
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_relax_frag
parameter_list|(
name|segment
parameter_list|,
name|fragP
parameter_list|,
name|stretch
parameter_list|)
define|\
value|m32r_relax_frag (segment, fragP, stretch)
end_define

begin_comment
comment|/* Account for nop if 32 bit insn falls on odd halfword boundary.  */
end_comment

begin_define
define|#
directive|define
name|TC_CGEN_MAX_RELAX
parameter_list|(
name|insn
parameter_list|,
name|len
parameter_list|)
value|6
end_define

begin_comment
comment|/* Fill in rs_align_code fragments.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|m32r_handle_align
parameter_list|(
name|fragS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|HANDLE_ALIGN
parameter_list|(
name|f
parameter_list|)
value|m32r_handle_align (f)
end_define

begin_define
define|#
directive|define
name|MAX_MEM_FOR_RS_ALIGN_CODE
value|(1 + 2 + 4)
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
name|md_apply_fix
value|gas_cgen_md_apply_fix
end_define

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
value|m32r_fix_adjustable (FIX)
end_define

begin_function_decl
name|bfd_boolean
name|m32r_fix_adjustable
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* After creating a fixup for an instruction operand, we need to check for    HI16 relocs and queue them up for later sorting.  */
end_comment

begin_define
define|#
directive|define
name|md_cgen_record_fixup_exp
value|m32r_cgen_record_fixup_exp
end_define

begin_define
define|#
directive|define
name|TC_HANDLES_FX_DONE
end_define

begin_decl_stmt
specifier|extern
name|int
name|pic_code
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|bfd_boolean
name|m32r_fix_adjustable
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This arranges for gas/write.c to not apply a relocation if    obj_fix_adjustable() says it is not adjustable.  */
end_comment

begin_define
define|#
directive|define
name|TC_FIX_ADJUSTABLE
parameter_list|(
name|fixP
parameter_list|)
value|obj_fix_adjustable (fixP)
end_define

begin_define
define|#
directive|define
name|tc_frob_file_before_fix
parameter_list|()
value|m32r_frob_file ()
end_define

begin_function_decl
specifier|extern
name|void
name|m32r_frob_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* No shared lib support, so we don't need to ensure externally    visible symbols can be overridden. #define EXTERN_FORCE_RELOC 0 */
end_comment

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
value|m32r_force_relocation (fix)
end_define

begin_function_decl
specifier|extern
name|int
name|m32r_force_relocation
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Ensure insns at labels are aligned to 32 bit boundaries.  */
end_comment

begin_function_decl
name|int
name|m32r_fill_insn
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_after_pass_hook
parameter_list|()
value|m32r_fill_insn (1)
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
value|(ch == ':'&& m32r_fill_insn (0))
end_define

begin_define
define|#
directive|define
name|md_cleanup
value|m32r_elf_section_change_hook
end_define

begin_define
define|#
directive|define
name|md_elf_section_change_hook
value|m32r_elf_section_change_hook
end_define

begin_function_decl
specifier|extern
name|void
name|m32r_elf_section_change_hook
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
value|m32r_flush_pending_output ()
end_define

begin_function_decl
specifier|extern
name|void
name|m32r_flush_pending_output
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|elf_tc_final_processing
value|m32r_elf_final_processing
end_define

begin_function_decl
specifier|extern
name|void
name|m32r_elf_final_processing
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
value|m32r_parse_name ((name), (exprP), (mode), (nextcharP))
end_define

begin_function_decl
specifier|extern
name|int
name|m32r_parse_name
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
name|expressionS
modifier|*
parameter_list|,
name|enum
name|expr_mode
parameter_list|,
name|char
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
name|TC_CGEN_PARSE_FIX_EXP
parameter_list|(
name|opinfo
parameter_list|,
name|exp
parameter_list|)
define|\
value|m32r_cgen_parse_fix_exp(opinfo, exp)
end_define

begin_function_decl
specifier|extern
name|int
name|m32r_cgen_parse_fix_exp
parameter_list|(
name|int
parameter_list|,
name|expressionS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

