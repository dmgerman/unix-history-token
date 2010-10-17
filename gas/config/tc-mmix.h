begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-mmix.h -- Header file for tc-mmix.c.    Copyright (C) 2001, 2002, 2003 Free Software Foundation, Inc.    Written by Hans-Peter Nilsson (hp@bitrange.com).     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_MMIX
end_define

begin_comment
comment|/* See gas/doc/internals.texi for explanation of these macros.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"elf64-mmix"
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_mmix
end_define

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|1
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|mmix_comment_chars
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tc_comment_chars
value|mmix_comment_chars
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|mmix_symbol_chars
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tc_symbol_chars
value|mmix_symbol_chars
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|mmix_exp_chars
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|EXP_CHARS
value|mmix_exp_chars
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|mmix_flt_chars
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FLT_CHARS
value|mmix_flt_chars
end_define

begin_comment
comment|/* "@" is a synonym for ".".  */
end_comment

begin_define
define|#
directive|define
name|LEX_AT
value|(LEX_BEGIN_NAME)
end_define

begin_decl_stmt
specifier|extern
name|int
name|mmix_label_without_colon_this_line
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LABELS_WITHOUT_COLONS
value|mmix_label_without_colon_this_line ()
end_define

begin_decl_stmt
specifier|extern
name|int
name|mmix_next_semicolon_is_eoln
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_EOL_IN_INSN
parameter_list|(
name|p
parameter_list|)
value|(*(p) == ';'&& ! mmix_next_semicolon_is_eoln)
end_define

begin_comment
comment|/* This is one direction we can get mmixal compatibility.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|mmix_handle_mmixal
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|md_start_line_hook
value|mmix_handle_mmixal
end_define

begin_decl_stmt
specifier|extern
name|void
name|mmix_md_begin
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|md_begin
value|mmix_md_begin
end_define

begin_decl_stmt
specifier|extern
name|void
name|mmix_md_end
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|md_end
value|mmix_md_end
end_define

begin_decl_stmt
specifier|extern
name|int
name|mmix_current_location
decl|\
name|PARAMS
argument_list|(
operator|(
name|void
argument_list|(
operator|*
name|fn
argument_list|)
argument_list|(
name|expressionS
operator|*
argument_list|)
operator|,
name|expressionS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mmix_parse_predefined_name
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|expressionS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mmix_current_prefix
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A bit ugly, since we "know" that there's a static function    current_location that does what we want.  We also strip off a leading    ':' in another ugly way.     The [DVWIOUZX]_Handler symbols are provided when-used.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mmix_gnu_syntax
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|md_parse_name
parameter_list|(
name|name
parameter_list|,
name|exp
parameter_list|,
name|cpos
parameter_list|)
define|\
value|(! mmix_gnu_syntax						\&& (name[0] == '@'						\       ? (! is_part_of_name (name[1])				\&& mmix_current_location (current_location, exp))	\       : ((name[0] == ':' || ISUPPER (name[0]))			\&& mmix_parse_predefined_name (name, exp))))
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mmix_prefix_name
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
comment|/* We implement when *creating* a symbol, we also need to strip a ':' or    prepend a prefix.  */
end_comment

begin_define
define|#
directive|define
name|tc_canonicalize_symbol_name
parameter_list|(
name|x
parameter_list|)
define|\
value|(mmix_current_prefix == NULL&& (x)[0] != ':' ? (x) : mmix_prefix_name (x))
end_define

begin_define
define|#
directive|define
name|md_undefined_symbol
parameter_list|(
name|x
parameter_list|)
value|NULL
end_define

begin_decl_stmt
specifier|extern
name|void
name|mmix_fb_label
name|PARAMS
argument_list|(
operator|(
name|expressionS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Since integer_constant is local to expr.c, we have to make this a    macro.  FIXME: Do it cleaner.  */
end_comment

begin_define
define|#
directive|define
name|md_operand
parameter_list|(
name|exp
parameter_list|)
define|\
value|do									\     {									\       if (input_line_pointer[0] == '#')					\ 	{								\ 	  input_line_pointer++;						\ 	  integer_constant (16, (exp));					\ 	}								\       else if (input_line_pointer[0] == '&'				\&& input_line_pointer[1] != '&')				\ 	as_bad (_("`&' serial number operator is not supported"));	\       else								\ 	mmix_fb_label (exp);						\     }									\   while (0)
end_define

begin_comment
comment|/* Gas dislikes the 2ADD, 8ADD etc. insns, so we have to assemble them in    the error-recovery loop.  Hopefully there are no significant    differences.  Also, space on a line isn't gracefully handled.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mmix_assemble_return_nonzero
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
name|tc_unrecognized_line
parameter_list|(
name|c
parameter_list|)
define|\
value|((c) == ' '								\   || (((c) == '1' || (c) == '2' || (c) == '4' || (c) == '8')		\&& mmix_assemble_return_nonzero (input_line_pointer - 1)))
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
name|WORKING_DOT_WORD
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|relax_type
name|mmix_relax_table
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_GENERIC_RELAX_TABLE
value|mmix_relax_table
end_define

begin_comment
comment|/* We use the relax table for everything except the GREG frags and PUSHJ.  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|mmix_md_relax_frag
name|PARAMS
argument_list|(
operator|(
name|segT
operator|,
name|fragS
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|md_relax_frag
value|mmix_md_relax_frag
end_define

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
define|\
value|(((FIX)->fx_addsy == NULL					\    || S_GET_SEGMENT ((FIX)->fx_addsy) != reg_section)		\&& (FIX)->fx_r_type != BFD_RELOC_VTABLE_INHERIT		\&& (FIX)->fx_r_type != BFD_RELOC_VTABLE_ENTRY			\&& (FIX)->fx_r_type != BFD_RELOC_MMIX_LOCAL)
end_define

begin_comment
comment|/* Adjust symbols which are registers.  */
end_comment

begin_define
define|#
directive|define
name|tc_adjust_symtab
parameter_list|()
value|mmix_adjust_symtab ()
end_define

begin_decl_stmt
specifier|extern
name|void
name|mmix_adjust_symtab
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Here's where we make all symbols global, when so requested.    We must avoid doing that for expression symbols or section symbols,    though.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mmix_globalize_symbols
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tc_frob_symbol
parameter_list|(
name|sym
parameter_list|,
name|punt
parameter_list|)
define|\
value|do								\     {								\       if (S_GET_SEGMENT (sym) == reg_section)			\ 	{							\ 	  if (S_GET_NAME (sym)[0] != '$'			\&& S_GET_VALUE (sym)< 256)			\ 	    {							\ 	      if (mmix_globalize_symbols)			\ 		S_SET_EXTERNAL (sym);				\ 	      else						\ 		symbol_mark_used_in_reloc (sym);		\ 	    }							\ 	}							\       else if (mmix_globalize_symbols				\&& ! symbol_section_p (sym)			\&& sym != section_symbol (absolute_section)	\&& ! S_IS_LOCAL (sym))				\ 	S_SET_EXTERNAL (sym);					\     }								\   while (0)
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
value|mmix_force_relocation (fix)
end_define

begin_decl_stmt
specifier|extern
name|int
name|mmix_force_relocation
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

begin_define
define|#
directive|define
name|md_section_align
parameter_list|(
name|seg
parameter_list|,
name|size
parameter_list|)
value|(size)
end_define

begin_define
define|#
directive|define
name|LISTING_HEADER
value|"GAS for MMIX"
end_define

begin_comment
comment|/* The default of 4 means Bcc expansion looks like it's missing a line.  */
end_comment

begin_define
define|#
directive|define
name|LISTING_LHS_CONT_LINES
value|5
end_define

begin_decl_stmt
specifier|extern
name|fragS
modifier|*
name|mmix_opcode_frag
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_FRAG_TYPE
value|fragS *
end_define

begin_define
define|#
directive|define
name|TC_FRAG_INIT
parameter_list|(
name|frag
parameter_list|)
value|(frag)->tc_frag_data = mmix_opcode_frag
end_define

begin_comment
comment|/* We need to associate each section symbol with a list of GREGs defined    for that section/segment and sorted on offset, between the point where    all symbols have been evaluated and all frags mapped, and when the    fixups are done and relocs are output.  Similarly for each unknown    symbol.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|mmix_frob_file
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tc_frob_file_before_fix
value|mmix_frob_file
end_define

begin_comment
comment|/* Used by mmix_frob_file.  Hangs on section symbols and unknown symbols.  */
end_comment

begin_struct_decl
struct_decl|struct
name|mmix_symbol_gregs
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|TC_SYMFIELD_TYPE
value|struct mmix_symbol_gregs *
end_define

begin_comment
comment|/* Used by relaxation, counting maximum needed PUSHJ stubs for a section.  */
end_comment

begin_struct
struct|struct
name|mmix_segment_info_type
block|{
comment|/* We only need to keep track of the last stubbable frag because       there's no less hackish way to keep track of different relaxation       rounds.  */
name|fragS
modifier|*
name|last_stubfrag
decl_stmt|;
name|bfd_size_type
name|nstubs
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TC_SEGMENT_INFO_TYPE
value|struct mmix_segment_info_type
end_define

begin_decl_stmt
specifier|extern
name|void
name|mmix_md_elf_section_change_hook
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|md_elf_section_change_hook
value|mmix_md_elf_section_change_hook
end_define

begin_decl_stmt
specifier|extern
name|void
name|mmix_md_do_align
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|label
parameter_list|)
define|\
value|mmix_md_do_align (n, fill, len, max)
end_define

begin_comment
comment|/* Each insn is a tetrabyte (4 bytes) long, but if there are BYTE    sequences sprinkled in, we can get unaligned DWARF2 offsets, so let's    explicitly say one byte.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_LINE_MIN_INSN_LENGTH
value|1
end_define

end_unit

