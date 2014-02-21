begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-mips.h -- header file for tc-mips.c.    Copyright 1993, 1994, 1995, 1996, 1997, 2000, 2001, 2002, 2003, 2004,    2005, 2006 Free Software Foundation, Inc.    Contributed by the OSF and Ralph Campbell.    Written by Keith Knowles and Ralph Campbell, working independently.    Modified for ECOFF support by Ian Lance Taylor of Cygnus Support.     This file is part of GAS.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TC_MIPS
end_ifndef

begin_define
define|#
directive|define
name|TC_MIPS
end_define

begin_struct_decl
struct_decl|struct
name|frag
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|expressionS
struct_decl|;
end_struct_decl

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

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_mips
end_define

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
value|1
end_define

begin_define
define|#
directive|define
name|OLD_FLOAT_READS
end_define

begin_define
define|#
directive|define
name|REPEAT_CONS_EXPRESSIONS
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
value|3
end_define

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
value|1
end_define

begin_comment
comment|/* Maximum symbol offset that can be encoded in a BFD_RELOC_GPREL16    relocation.  */
end_comment

begin_define
define|#
directive|define
name|MAX_GPREL_OFFSET
value|(0x7FF0)
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
define|\
value|mips_relax_frag(segment, fragp, stretch)
end_define

begin_function_decl
specifier|extern
name|int
name|mips_relax_frag
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
name|md_undefined_symbol
parameter_list|(
name|name
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|md_operand
parameter_list|(
name|x
parameter_list|)
end_define

begin_function_decl
specifier|extern
name|void
name|mips_handle_align
parameter_list|(
name|struct
name|frag
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|HANDLE_ALIGN
parameter_list|(
name|fragp
parameter_list|)
value|mips_handle_align (fragp)
end_define

begin_define
define|#
directive|define
name|MAX_MEM_FOR_RS_ALIGN_CODE
value|(1 + 2)
end_define

begin_struct_decl
struct_decl|struct
name|insn_label_list
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|TC_SEGMENT_INFO_TYPE
value|struct insn_label_list *
end_define

begin_comment
comment|/* This field is nonzero if the symbol is the target of a MIPS16 jump.  */
end_comment

begin_define
define|#
directive|define
name|TC_SYMFIELD_TYPE
value|int
end_define

begin_comment
comment|/* Tell assembler that we have an itbl_mips.h header file to include.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ITBL_CPU
end_define

begin_comment
comment|/* The endianness of the target format may change based on command    line arguments.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|mips_target_format()
end_define

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|mips_target_format
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MIPS PIC level.  */
end_comment

begin_enum
enum|enum
name|mips_pic_level
block|{
comment|/* Do not generate PIC code.  */
name|NO_PIC
block|,
comment|/* Generate PIC code as in the SVR4 MIPS ABI.  */
name|SVR4_PIC
block|,
comment|/* VxWorks's PIC model.  */
name|VXWORKS_PIC
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|mips_pic_level
name|mips_pic
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|tc_get_register
parameter_list|(
name|int
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_after_parse_args
parameter_list|()
value|mips_after_parse_args()
end_define

begin_function_decl
specifier|extern
name|void
name|mips_after_parse_args
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tc_init_after_args
parameter_list|()
value|mips_init_after_args()
end_define

begin_function_decl
specifier|extern
name|void
name|mips_init_after_args
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_parse_long_option
parameter_list|(
name|arg
parameter_list|)
value|mips_parse_long_option (arg)
end_define

begin_function_decl
specifier|extern
name|int
name|mips_parse_long_option
parameter_list|(
specifier|const
name|char
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
value|mips_define_label (sym)
end_define

begin_function_decl
specifier|extern
name|void
name|mips_define_label
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tc_frob_file_before_adjust
parameter_list|()
value|mips_frob_file_before_adjust ()
end_define

begin_function_decl
specifier|extern
name|void
name|mips_frob_file_before_adjust
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tc_frob_file_before_fix
parameter_list|()
value|mips_frob_file ()
end_define

begin_function_decl
specifier|extern
name|void
name|mips_frob_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OBJ_ELF
argument_list|)
operator|||
name|defined
argument_list|(
name|OBJ_MAYBE_ELF
argument_list|)
end_if

begin_define
define|#
directive|define
name|tc_frob_file_after_relocs
value|mips_frob_file_after_relocs
end_define

begin_function_decl
specifier|extern
name|void
name|mips_frob_file_after_relocs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|fixp
parameter_list|)
value|mips_fix_adjustable (fixp)
end_define

begin_function_decl
specifier|extern
name|int
name|mips_fix_adjustable
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
comment|/* Global syms must not be resolved, to support ELF shared libraries.  */
end_comment

begin_define
define|#
directive|define
name|EXTERN_FORCE_RELOC
define|\
value|(OUTPUT_FLAVOR == bfd_target_elf_flavour)
end_define

begin_comment
comment|/* When generating NEWABI code, we may need to have to keep combined    relocations which don't have symbols.  */
end_comment

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION
parameter_list|(
name|FIX
parameter_list|)
value|mips_force_relocation (FIX)
end_define

begin_function_decl
specifier|extern
name|int
name|mips_force_relocation
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
name|TC_FORCE_RELOCATION_SUB_SAME
parameter_list|(
name|FIX
parameter_list|,
name|SEG
parameter_list|)
define|\
value|(! SEG_NORMAL (SEG) || mips_force_relocation (FIX))
end_define

begin_comment
comment|/* Register mask variables.  These are set by the MIPS assembly code    and used by ECOFF and possibly other object file formats.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|mips_gprmask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|mips_cprmask
index|[
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OBJ_ELF
argument_list|)
operator|||
name|defined
argument_list|(
name|OBJ_MAYBE_ELF
argument_list|)
end_if

begin_define
define|#
directive|define
name|elf_tc_final_processing
value|mips_elf_final_processing
end_define

begin_function_decl
specifier|extern
name|void
name|mips_elf_final_processing
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|md_mips_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_end
parameter_list|()
value|md_mips_end()
end_define

begin_function_decl
specifier|extern
name|void
name|mips_pop_insert
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_pop_insert
parameter_list|()
value|mips_pop_insert()
end_define

begin_function_decl
specifier|extern
name|void
name|mips_emit_delays
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_flush_pending_output
value|mips_emit_delays
end_define

begin_function_decl
specifier|extern
name|void
name|mips_enable_auto_align
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_elf_section_change_hook
parameter_list|()
value|mips_enable_auto_align()
end_define

begin_function_decl
specifier|extern
name|int
name|mips_dwarf2_addr_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DWARF2_ADDR_SIZE
parameter_list|(
name|bfd
parameter_list|)
value|mips_dwarf2_addr_size ()
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
value|mips_cfi_frame_initial_instructions
end_define

begin_function_decl
specifier|extern
name|void
name|mips_cfi_frame_initial_instructions
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tc_regname_to_dw2regnum
value|tc_mips_regname_to_dw2regnum
end_define

begin_function_decl
specifier|extern
name|int
name|tc_mips_regname_to_dw2regnum
parameter_list|(
name|char
modifier|*
name|regname
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DWARF2_DEFAULT_RETURN_COLUMN
value|31
end_define

begin_define
define|#
directive|define
name|DWARF2_CIE_DATA_ALIGNMENT
value|(-4)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_MIPS */
end_comment

end_unit

