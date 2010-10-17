begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-cris.h -- Header file for tc-cris.c, the CRIS GAS port.    Copyright 2000, 2001, 2002 Free Software Foundation, Inc.     Contributed by Axis Communications AB, Lund, Sweden.    Originally written for GAS 1.38.1 by Mikael Asker.    Updates, BFDizing, GNUifying and ELF by Hans-Peter Nilsson.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the    Free Software Foundation, 59 Temple Place - Suite 330, Boston,    MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* See the GAS "internal" document for general documentation on this.    It is called internals.texi (internals.info when makeinfo:d), but is    not installed or makeinfo:d by "make info".  */
end_comment

begin_comment
comment|/* Functions and variables that aren't declared in tc.h are declared here,    with the type/prototype that is used in the local extern-declaration of    their usage.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TC_CRIS
end_ifndef

begin_define
define|#
directive|define
name|TC_CRIS
end_define

begin_comment
comment|/* Multi-target support is always on.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|cris_target_format
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
name|TARGET_FORMAT
value|cris_target_format ()
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_cris
end_define

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|0
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|md_shortopts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|option
name|md_longopts
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|md_longopts_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|pseudo_typeS
name|md_pseudo_table
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tc_comment_chars
value|cris_comment_chars
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|cris_comment_chars
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|line_comment_chars
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|line_separator_chars
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|EXP_CHARS
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|FLT_CHARS
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This should be optional, since it is ignored as an escape (assumed to    be itself) if it is not recognized.  */
end_comment

begin_define
define|#
directive|define
name|ONLY_STANDARD_ESCAPES
end_define

begin_comment
comment|/* Note that we do not define TC_EQUAL_IN_INSN, since its current use is    in the instruction rather than the operand, and thus does not come to    use for side-effect assignments such as "and.d [r0 = r1 + 42], r3".  */
end_comment

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
name|md_number_to_chars
value|number_to_chars_littleendian
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|md_short_jump_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|md_long_jump_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* There's no use having different functions for this; the sizes are the    same.  Note that we can't #define md_short_jump_size here.  */
end_comment

begin_define
define|#
directive|define
name|md_create_short_jump
value|md_create_long_jump
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|relax_type
name|md_cris_relax_table
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_GENERIC_RELAX_TABLE
value|md_cris_relax_table
end_define

begin_decl_stmt
name|long
name|cris_relax_frag
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
value|((FRAGP)->fr_symbol != NULL				\&& S_GET_SEGMENT ((FRAGP)->fr_symbol) == (SEG)	\   ? relax_frag (SEG, FRAGP, STRETCH)			\   : cris_relax_frag (SEG, FRAGP, STRETCH))
end_define

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION
parameter_list|(
name|FIX
parameter_list|)
value|md_cris_force_relocation (FIX)
end_define

begin_decl_stmt
specifier|extern
name|int
name|md_cris_force_relocation
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
name|IS_CRIS_PIC_RELOC
parameter_list|(
name|RTYPE
parameter_list|)
define|\
value|((RTYPE) == BFD_RELOC_CRIS_16_GOT			\    || (RTYPE) == BFD_RELOC_CRIS_32_GOT			\    || (RTYPE) == BFD_RELOC_CRIS_16_GOTPLT		\    || (RTYPE) == BFD_RELOC_CRIS_32_GOTPLT		\    || (RTYPE) == BFD_RELOC_CRIS_32_GOTREL		\    || (RTYPE) == BFD_RELOC_CRIS_32_PLT_GOTREL		\    || (RTYPE) == BFD_RELOC_CRIS_32_PLT_PCREL)
end_define

begin_comment
comment|/* Make sure we don't resolve fixups for which we want to emit dynamic    relocations.  FIXME: Set fx_plt instead of using IS_CRIS_PIC_RELOC.  */
end_comment

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION_LOCAL
parameter_list|(
name|FIX
parameter_list|)
define|\
value|(!(FIX)->fx_pcrel					\    || (FIX)->fx_plt					\    || IS_CRIS_PIC_RELOC ((FIX)->fx_r_type)		\    || TC_FORCE_RELOCATION (FIX))
end_define

begin_comment
comment|/* For some reloc types, don't adjust fixups by reducing to a section    symbol.  */
end_comment

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
define|\
value|((FIX)->fx_r_type != BFD_RELOC_VTABLE_INHERIT		\&& (FIX)->fx_r_type != BFD_RELOC_VTABLE_ENTRY		\&& (! IS_CRIS_PIC_RELOC ((FIX)->fx_r_type)		\       || (FIX)->fx_r_type == BFD_RELOC_CRIS_32_GOTREL))
end_define

begin_comment
comment|/* When we have fixups against constant expressions, we get a GAS-specific    section symbol at no extra charge for obscure reasons in    adjust_reloc_syms.  Since ELF outputs section symbols, it gladly    outputs this "*ABS*" symbol in every object.  Avoid that.    Also, don't emit undefined symbols (that aren't used in relocations).    They pop up when tentatively parsing register names as symbols.  */
end_comment

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
value|do {							\   if ((OUTPUT_FLAVOR == bfd_target_elf_flavour		\&& (symp) == section_symbol (absolute_section))	\       || ! S_IS_DEFINED (symp))				\     (punt) = 1;						\  } while (0)
end_define

begin_define
define|#
directive|define
name|LISTING_HEADER
value|"GAS for CRIS"
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* The testsuite does not let me define these, although they IMHO should    be preferred over the default.  */
end_comment

begin_define
define|#
directive|define
name|LISTING_WORD_SIZE
value|2
end_define

begin_define
define|#
directive|define
name|LISTING_LHS_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|LISTING_LHS_WIDTH_SECOND
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* END of declaration and definitions described in the "internals"    document.  */
end_comment

begin_comment
comment|/* Do this, or we will never know what hit us when the    broken-word-fixes break.  Do _not_ use WARN_SIGNED_OVERFLOW_WORD,    it is only for use with WORKING_DOT_WORD and warns about most stuff.    (still in 2.9.1).  */
end_comment

begin_struct_decl
struct_decl|struct
name|broken_word
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|void
name|tc_cris_check_adjusted_broken_word
name|PARAMS
argument_list|(
operator|(
name|offsetT
operator|,
expr|struct
name|broken_word
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_CHECK_ADJUSTED_BROKEN_DOT_WORD
parameter_list|(
name|new_offset
parameter_list|,
name|brokw
parameter_list|)
define|\
value|tc_cris_check_adjusted_broken_word ((offsetT) (new_offset), brokw)
end_define

begin_comment
comment|/* We don't want any implicit alignment, so we do nothing.  */
end_comment

begin_define
define|#
directive|define
name|TC_IMPLICIT_LCOMM_ALIGNMENT
parameter_list|(
name|SIZE
parameter_list|,
name|P2VAR
parameter_list|)
end_define

begin_comment
comment|/* CRIS instructions, with operands and prefixes included, are a multiple    of two bytes long.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_LINE_MIN_INSN_LENGTH
value|2
end_define

begin_comment
comment|/* Make port immune to unwanted difference in te-generic.h vs. te-linux.h.  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_LABELS_DOLLAR
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_CRIS */
end_comment

begin_comment
comment|/*  * Local variables:  * eval: (c-set-style "gnu")  * indent-tabs-mode: t  * End:  */
end_comment

end_unit

