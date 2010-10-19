begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* this is tc-z80.h    Copyright 2005 Free Software Foundation, Inc.     Contributed by Arnold Metselaar<arnold_m@operamail.com>     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of .the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TC_Z80
end_ifndef

begin_define
define|#
directive|define
name|TC_Z80
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_z80
end_define

begin_define
define|#
directive|define
name|BFD_ARCH
value|TARGET_ARCH
end_define

begin_define
define|#
directive|define
name|COFF_MAGIC
value|0x5A80
end_define

begin_define
define|#
directive|define
name|TARGET_MACH
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|0
end_define

begin_comment
comment|/* If you define this macro, GAS will warn about the    use of nonstandard escape sequences in a string.  */
end_comment

begin_define
define|#
directive|define
name|ONLY_STANDARD_ESCAPES
end_define

begin_comment
comment|/* GAS will call this function for any expression that can not be    recognized.  When the function is called, `input_line_pointer'    will point to the start of the expression.  */
end_comment

begin_define
define|#
directive|define
name|md_operand
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/* This should just call either `number_to_chars_bigendian' or    `number_to_chars_littleendian', whichever is appropriate.  On    targets like the MIPS which support options to change the    endianness, which function to call is a runtime decision.  On    other targets, `md_number_to_chars' can be a simple macro.  */
end_comment

begin_define
define|#
directive|define
name|md_number_to_chars
value|number_to_chars_littleendian
end_define

begin_define
define|#
directive|define
name|TC_COUNT_RELOC
parameter_list|(
name|x
parameter_list|)
value|1
end_define

begin_define
define|#
directive|define
name|TC_COFF_FIX2RTYPE
parameter_list|(
name|fixP
parameter_list|)
value|tc_coff_fix2rtype (fixP)
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
value|as_fatal ("convert_frag called\n")
end_define

begin_define
define|#
directive|define
name|md_estimate_size_before_relax
parameter_list|(
name|f
parameter_list|,
name|s
parameter_list|)
define|\
value|(as_fatal (_("estimate_size_before_relax called")), 1)
end_define

begin_comment
comment|/* Define some functions to be called by generic code.  */
end_comment

begin_define
define|#
directive|define
name|md_end
value|z80_md_end
end_define

begin_define
define|#
directive|define
name|md_start_line_hook
parameter_list|()
value|{ if (z80_start_line_hook ()) continue; }
end_define

begin_define
define|#
directive|define
name|TC_CONS_FIX_NEW
value|z80_cons_fix_new
end_define

begin_function_decl
specifier|extern
name|void
name|z80_md_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|z80_start_line_hook
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|z80_cons_fix_new
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

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_comment
comment|/* If you define this macro, it means that `tc_gen_reloc' may return    multiple relocation entries for a single fixup.  In this case, the    return value of `tc_gen_reloc' is a pointer to a null terminated    array.  */
end_comment

begin_undef
undef|#
directive|undef
name|RELOC_EXPANSION_POSSIBLE
end_undef

begin_comment
comment|/* No shared lib support, so we don't need to ensure    externally visible symbols can be overridden.  */
end_comment

begin_define
define|#
directive|define
name|EXTERN_FORCE_RELOC
value|0
end_define

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

begin_define
define|#
directive|define
name|LISTING_WORD_SIZE
value|2
end_define

begin_comment
comment|/* A single '=' is accepted as a comparison operator.  */
end_comment

begin_define
define|#
directive|define
name|O_SINGLE_EQ
value|O_eq
end_define

begin_comment
comment|/* A '$' is used to refer to the current location or as a hex. prefix.  */
end_comment

begin_define
define|#
directive|define
name|DOLLAR_DOT
end_define

begin_define
define|#
directive|define
name|DOLLAR_AMBIGU
value|1
end_define

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
value|1
end_define

begin_define
define|#
directive|define
name|LITERAL_PREFIXPERCENT_BIN
end_define

begin_define
define|#
directive|define
name|NUMBERS_WITH_SUFFIX
value|1
end_define

begin_define
define|#
directive|define
name|NO_PSEUDO_DOT
value|1
end_define

begin_comment
comment|/* We allow single quotes to delimit character constants as    well, but it is cleaner to handle that in tc-z80.c.  */
end_comment

begin_define
define|#
directive|define
name|SINGLE_QUOTE_STRINGS
end_define

begin_define
define|#
directive|define
name|NO_STRING_ESCAPES
end_define

begin_comment
comment|/* An `.lcomm' directive with no explicit alignment parameter will    use this macro to set P2VAR to the alignment that a request for    SIZE bytes will have.  The alignment is expressed as a power of    two.  If no alignment should take place, the macro definition    should do nothing.  Some targets define a `.bss' directive that is    also affected by this macro.  The default definition will set    P2VAR to the truncated power of two of sizes up to eight bytes.  */
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
value|(P2VAR) = 0
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

