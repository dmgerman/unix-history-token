begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-m68hc11.h -- Header file for tc-m68hc11.c.    Copyright 1999, 2000, 2001, 2002 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_M68HC11
end_define

begin_define
define|#
directive|define
name|TC_M68HC12
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ANSI_PROTOTYPES
end_ifdef

begin_struct_decl
struct_decl|struct
name|fix
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define TC_M68K so that we can use the MRI mode.  */
end_comment

begin_define
define|#
directive|define
name|TC_M68K
end_define

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* Motorola assembler specs does not require '.' before pseudo-ops.  */
end_comment

begin_define
define|#
directive|define
name|NO_PSEUDO_DOT
value|1
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Treat the single quote as a string delimiter.    ??? This does not work at all.  */
end_comment

begin_define
define|#
directive|define
name|SINGLE_QUOTE_STRINGS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_ASSEMBLER
end_ifndef

begin_error
error|#
directive|error
error|M68HC11 support requires BFD_ASSEMBLER
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The target BFD architecture.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ARCH
value|(m68hc11_arch ())
end_define

begin_function_decl
specifier|extern
name|enum
name|bfd_architecture
name|m68hc11_arch
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TARGET_MACH
value|(m68hc11_mach ())
end_define

begin_function_decl
specifier|extern
name|int
name|m68hc11_mach
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|(m68hc11_arch_format ())
end_define

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|m68hc11_arch_format
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LISTING_WORD_SIZE
value|1
end_define

begin_comment
comment|/* A word is 1 bytes */
end_comment

begin_define
define|#
directive|define
name|LISTING_LHS_WIDTH
value|4
end_define

begin_comment
comment|/* One word on the first line */
end_comment

begin_define
define|#
directive|define
name|LISTING_LHS_WIDTH_SECOND
value|4
end_define

begin_comment
comment|/* One word on the second line */
end_comment

begin_define
define|#
directive|define
name|LISTING_LHS_CONT_LINES
value|4
end_define

begin_comment
comment|/* And 4 lines max */
end_comment

begin_define
define|#
directive|define
name|LISTING_HEADER
value|m68hc11_listing_header ()
end_define

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|m68hc11_listing_header
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
name|tc_init_after_args
value|m68hc11_init_after_args
end_define

begin_function_decl
specifier|extern
name|void
name|m68hc11_init_after_args
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|md_parse_long_option
value|m68hc11_parse_long_option
end_define

begin_function_decl
specifier|extern
name|int
name|m68hc11_parse_long_option
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DWARF2_LINE_MIN_INSN_LENGTH
value|1
end_define

begin_comment
comment|/* Use 32-bit address to represent a symbol address so that we can    represent them with their page number.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_ADDR_SIZE
parameter_list|(
name|bfd
parameter_list|)
value|4
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
name|md_number_to_chars
value|number_to_chars_bigendian
end_define

begin_comment
comment|/* Relax table to translate short relative branches (-128..127) into    absolute branches.  */
end_comment

begin_define
define|#
directive|define
name|TC_GENERIC_RELAX_TABLE
value|md_relax_table
end_define

begin_decl_stmt
specifier|extern
name|struct
name|relax_type
name|md_relax_table
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* GAS only handles relaxations for pc-relative data targeting addresses    in the same segment, so we have to handle the rest on our own.  */
end_comment

begin_define
define|#
directive|define
name|md_relax_frag
parameter_list|(
name|SEG
parameter_list|,
name|FRAGP
parameter_list|,
name|STRETCH
parameter_list|)
define|\
value|((FRAGP)->fr_symbol != NULL				\&& S_GET_SEGMENT ((FRAGP)->fr_symbol) == (SEG)	\   ? relax_frag (SEG, FRAGP, STRETCH)			\   : m68hc11_relax_frag (SEG, FRAGP, STRETCH))
end_define

begin_function_decl
specifier|extern
name|long
name|m68hc11_relax_frag
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
name|TC_HANDLES_FX_DONE
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
name|fix
parameter_list|)
value|tc_m68hc11_force_relocation (fix)
end_define

begin_function_decl
specifier|extern
name|int
name|tc_m68hc11_force_relocation
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
name|X
parameter_list|)
value|tc_m68hc11_fix_adjustable(X)
end_define

begin_function_decl
specifier|extern
name|int
name|tc_m68hc11_fix_adjustable
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
name|md_operand
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|tc_frob_label
parameter_list|(
name|sym
parameter_list|)
value|do {\   S_SET_VALUE (sym, (valueT) frag_now_fix ()); \ } while (0)
end_define

begin_define
define|#
directive|define
name|elf_tc_final_processing
value|m68hc11_elf_final_processing
end_define

begin_function_decl
specifier|extern
name|void
name|m68hc11_elf_final_processing
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tc_print_statistics
parameter_list|(
name|FILE
parameter_list|)
value|m68hc11_print_statistics (FILE)
end_define

begin_function_decl
specifier|extern
name|void
name|m68hc11_print_statistics
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

