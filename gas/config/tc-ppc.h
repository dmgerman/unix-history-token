begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-ppc.h -- Header file for tc-ppc.c.    Copyright 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003,    2004, 2005, 2006, 2007 Free Software Foundation, Inc.    Written by Ian Lance Taylor, Cygnus Support.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_PPC
end_define

begin_struct_decl
struct_decl|struct
name|fix
struct_decl|;
end_struct_decl

begin_comment
comment|/* Set the endianness we are using.  Default to big endian.  */
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
comment|/* If OBJ_COFF is defined, and TE_PE is not defined, we are assembling    XCOFF for AIX or PowerMac.  If TE_PE is defined, we are assembling    COFF for Windows NT.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_COFF
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|TE_PE
end_ifndef

begin_define
define|#
directive|define
name|OBJ_XCOFF
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|(ppc_arch ())
end_define

begin_define
define|#
directive|define
name|TARGET_MACH
value|(ppc_mach ())
end_define

begin_function_decl
specifier|extern
name|enum
name|bfd_architecture
name|ppc_arch
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|long
name|ppc_mach
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Whether or not the target is big endian */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|target_big_endian
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The target BFD format.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|(ppc_target_format ())
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|ppc_target_format
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

begin_comment
comment|/* $ is used to refer to the current location.  */
end_comment

begin_define
define|#
directive|define
name|DOLLAR_DOT
end_define

begin_comment
comment|/* Strings do not use backslash escapes under COFF.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_COFF
end_ifdef

begin_define
define|#
directive|define
name|NO_STRING_ESCAPES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_define
define|#
directive|define
name|DIFF_EXPR_OK
end_define

begin_comment
comment|/* foo-. gets turned into PC relative relocs */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TARGET_BYTES_BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|PPC_BIG_ENDIAN
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PPC_BIG_ENDIAN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|MAX_MEM_FOR_RS_ALIGN_CODE
value|4
end_define

begin_define
define|#
directive|define
name|HANDLE_ALIGN
parameter_list|(
name|FRAGP
parameter_list|)
define|\
value|if ((FRAGP)->fr_type == rs_align_code)				\     ppc_handle_align (FRAGP);
end_define

begin_function_decl
specifier|extern
name|void
name|ppc_handle_align
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
name|SUB_SEGMENT_ALIGN
parameter_list|(
name|SEG
parameter_list|,
name|FRCHAIN
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|md_frag_check
parameter_list|(
name|FRAGP
parameter_list|)
define|\
value|if ((FRAGP)->has_code							\&& (((FRAGP)->fr_address + (FRAGP)->insn_addr)& 3) != 0)		\     as_bad_where ((FRAGP)->fr_file, (FRAGP)->fr_line,			\ 		  _("instruction address is not a multiple of 4"));
end_define

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|TE_PE
end_ifdef

begin_comment
comment|/* Question marks are permitted in symbol names.  */
end_comment

begin_define
define|#
directive|define
name|LEX_QM
value|1
end_define

begin_comment
comment|/* Don't adjust TOC relocs.  */
end_comment

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
value|ppc_pe_fix_adjustable (FIX)
end_define

begin_function_decl
specifier|extern
name|int
name|ppc_pe_fix_adjustable
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_XCOFF
end_ifdef

begin_comment
comment|/* Declarations needed when generating XCOFF code.  XCOFF is an    extension of COFF, used only on the RS/6000.  Rather than create an    obj-xcoff, we just use obj-coff, and handle the extensions here in    tc-ppc.  */
end_comment

begin_comment
comment|/* We need to keep some information for symbols.  */
end_comment

begin_struct
struct|struct
name|ppc_tc_sy
block|{
comment|/* We keep a few linked lists of symbols.  */
name|symbolS
modifier|*
name|next
decl_stmt|;
comment|/* Non-zero if the symbol should be output.  The RS/6000 assembler      only outputs symbols that are external or are mentioned in a      .globl or .lglobl statement.  */
name|int
name|output
decl_stmt|;
comment|/* The symbol class.  */
name|int
name|class
decl_stmt|;
comment|/* The real name, if the symbol was renamed.  */
name|char
modifier|*
name|real_name
decl_stmt|;
comment|/* For a csect symbol, the subsegment we are using.  This is zero      for symbols that are not csects.  */
name|subsegT
name|subseg
decl_stmt|;
comment|/* For a csect or common symbol, the alignment to use.  */
name|int
name|align
decl_stmt|;
comment|/* For a function symbol, a symbol whose value is the size.  The      field is NULL if there is no size.  */
name|symbolS
modifier|*
name|size
decl_stmt|;
comment|/* For a csect symbol, the last symbol which has been defined in      this csect, or NULL if none have been defined so far.  For a .bs      symbol, the referenced csect symbol.  */
name|symbolS
modifier|*
name|within
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TC_SYMFIELD_TYPE
value|struct ppc_tc_sy
end_define

begin_comment
comment|/* We need an additional auxent for function symbols.  */
end_comment

begin_define
define|#
directive|define
name|OBJ_COFF_MAX_AUXENTRIES
value|2
end_define

begin_comment
comment|/* Square and curly brackets are permitted in symbol names.  */
end_comment

begin_define
define|#
directive|define
name|LEX_BR
value|3
end_define

begin_comment
comment|/* Canonicalize the symbol name.  */
end_comment

begin_define
define|#
directive|define
name|tc_canonicalize_symbol_name
parameter_list|(
name|name
parameter_list|)
value|ppc_canonicalize_symbol_name (name)
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|ppc_canonicalize_symbol_name
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the symbol class from the name.  */
end_comment

begin_define
define|#
directive|define
name|tc_symbol_new_hook
parameter_list|(
name|sym
parameter_list|)
value|ppc_symbol_new_hook (sym)
end_define

begin_function_decl
specifier|extern
name|void
name|ppc_symbol_new_hook
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the symbol class of a label based on the csect.  */
end_comment

begin_define
define|#
directive|define
name|tc_frob_label
parameter_list|(
name|sym
parameter_list|)
value|ppc_frob_label (sym)
end_define

begin_function_decl
specifier|extern
name|void
name|ppc_frob_label
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* TOC relocs requires special handling.  */
end_comment

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
value|ppc_fix_adjustable (FIX)
end_define

begin_function_decl
specifier|extern
name|int
name|ppc_fix_adjustable
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* We need to set the section VMA.  */
end_comment

begin_define
define|#
directive|define
name|tc_frob_section
parameter_list|(
name|sec
parameter_list|)
value|ppc_frob_section (sec)
end_define

begin_function_decl
specifier|extern
name|void
name|ppc_frob_section
parameter_list|(
name|asection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Finish up the symbol.  */
end_comment

begin_define
define|#
directive|define
name|tc_frob_symbol
parameter_list|(
name|sym
parameter_list|,
name|punt
parameter_list|)
value|punt = ppc_frob_symbol (sym)
end_define

begin_function_decl
specifier|extern
name|int
name|ppc_frob_symbol
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Finish up the entire symtab.  */
end_comment

begin_define
define|#
directive|define
name|tc_adjust_symtab
parameter_list|()
value|ppc_adjust_symtab ()
end_define

begin_function_decl
specifier|extern
name|void
name|ppc_adjust_symtab
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* We also need to copy, in particular, the class of the symbol,    over what obj-coff would otherwise have copied.  */
end_comment

begin_define
define|#
directive|define
name|OBJ_COPY_SYMBOL_ATTRIBUTES
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
define|\
value|do {								\   if (SF_GET_GET_SEGMENT (dest))				\     S_SET_SEGMENT (dest, S_GET_SEGMENT (src));			\   symbol_get_tc (dest)->size = symbol_get_tc (src)->size;	\   symbol_get_tc (dest)->align = symbol_get_tc (src)->align;	\   symbol_get_tc (dest)->class = symbol_get_tc (src)->class;	\   symbol_get_tc (dest)->within = symbol_get_tc (src)->within;	\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OBJ_XCOFF */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|ppc_symbol_chars
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tc_symbol_chars
value|ppc_symbol_chars
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_comment
comment|/* Support for SHF_EXCLUDE and SHT_ORDERED */
end_comment

begin_function_decl
specifier|extern
name|int
name|ppc_section_letter
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppc_section_type
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppc_section_word
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ppc_section_flags
parameter_list|(
name|int
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
name|md_elf_section_letter
parameter_list|(
name|LETTER
parameter_list|,
name|PTR_MSG
parameter_list|)
value|ppc_section_letter (LETTER, PTR_MSG)
end_define

begin_define
define|#
directive|define
name|md_elf_section_type
parameter_list|(
name|STR
parameter_list|,
name|LEN
parameter_list|)
value|ppc_section_type (STR, LEN)
end_define

begin_define
define|#
directive|define
name|md_elf_section_word
parameter_list|(
name|STR
parameter_list|,
name|LEN
parameter_list|)
value|ppc_section_word (STR, LEN)
end_define

begin_define
define|#
directive|define
name|md_elf_section_flags
parameter_list|(
name|FLAGS
parameter_list|,
name|ATTR
parameter_list|,
name|TYPE
parameter_list|)
value|ppc_section_flags (FLAGS, ATTR, TYPE)
end_define

begin_define
define|#
directive|define
name|tc_comment_chars
value|ppc_comment_chars
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ppc_comment_chars
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Keep relocations relative to the GOT, or non-PC relative.  */
end_comment

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
value|ppc_fix_adjustable (FIX)
end_define

begin_function_decl
specifier|extern
name|int
name|ppc_fix_adjustable
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

begin_define
define|#
directive|define
name|tc_frob_file_before_adjust
value|ppc_frob_file_before_adjust
end_define

begin_function_decl
specifier|extern
name|void
name|ppc_frob_file_before_adjust
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OBJ_ELF */
end_comment

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
name|OBJ_XCOFF
argument_list|)
end_if

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION
parameter_list|(
name|FIX
parameter_list|)
value|ppc_force_relocation (FIX)
end_define

begin_function_decl
specifier|extern
name|int
name|ppc_force_relocation
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* call md_pcrel_from_section, not md_pcrel_from */
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
value|md_pcrel_from_section(FIX, SEC)
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
name|md_parse_name
parameter_list|(
name|name
parameter_list|,
name|exp
parameter_list|,
name|mode
parameter_list|,
name|c
parameter_list|)
value|ppc_parse_name (name, exp)
end_define

begin_function_decl
specifier|extern
name|int
name|ppc_parse_name
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|expressionS
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
name|md_cleanup
parameter_list|()
value|ppc_cleanup ()
end_define

begin_function_decl
specifier|extern
name|void
name|ppc_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
value|ppc_cfi_frame_initial_instructions
end_define

begin_function_decl
specifier|extern
name|void
name|ppc_cfi_frame_initial_instructions
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tc_regname_to_dw2regnum
value|tc_ppc_regname_to_dw2regnum
end_define

begin_function_decl
specifier|extern
name|int
name|tc_ppc_regname_to_dw2regnum
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|ppc_cie_data_alignment
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DWARF2_LINE_MIN_INSN_LENGTH
value|4
end_define

begin_define
define|#
directive|define
name|DWARF2_DEFAULT_RETURN_COLUMN
value|0x41
end_define

begin_define
define|#
directive|define
name|DWARF2_CIE_DATA_ALIGNMENT
value|ppc_cie_data_alignment
end_define

end_unit

