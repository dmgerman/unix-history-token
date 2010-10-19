begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is tc-msp430.h    Copyright (C) 2002, 2004, 2005 Free Software Foundation, Inc.     Contributed by Dmitry Diky<diwil@mail.ru>     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_MSP430
end_define

begin_comment
comment|/*   By convention, you should define this macro in the `.h' file.  For      example, `tc-m68k.h' defines `TC_M68K'.  You might have to use this      if it is necessary to add CPU specific code to the object format      file.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"elf32-msp430"
end_define

begin_comment
comment|/*   This macro is the BFD target name to use when creating the output      file.  This will normally depend upon the `OBJ_FMT' macro.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_msp430
end_define

begin_comment
comment|/*   This macro is the BFD architecture to pass to `bfd_set_arch_mach'.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MACH
value|0
end_define

begin_comment
comment|/*   This macro is the BFD machine number to pass to      `bfd_set_arch_mach'.  If it is not defined, GAS will use 0.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|0
end_define

begin_comment
comment|/*   You should define this macro to be non-zero if the target is big      endian, and zero if the target is little endian.  */
end_comment

begin_define
define|#
directive|define
name|ONLY_STANDARD_ESCAPES
end_define

begin_comment
comment|/*   If you define this macro, GAS will warn about the use of      nonstandard escape sequences in a string.  */
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
comment|/*   GAS will call this function for any expression that can not be      recognized.  When the function is called, `input_line_pointer'      will point to the start of the expression.  */
end_comment

begin_define
define|#
directive|define
name|md_number_to_chars
value|number_to_chars_littleendian
end_define

begin_comment
comment|/*   This should just call either `number_to_chars_bigendian' or      `number_to_chars_littleendian', whichever is appropriate.  On      targets like the MIPS which support options to change the      endianness, which function to call is a runtime decision.  On      other targets, `md_number_to_chars' can be a simple macro.  */
end_comment

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_comment
comment|/* `md_short_jump_size' `md_long_jump_size' `md_create_short_jump' `md_create_long_jump'      If `WORKING_DOT_WORD' is defined, GAS will not do broken word      processing (*note Broken words::.).  Otherwise, you should set      `md_short_jump_size' to the size of a short jump (a jump that is      just long enough to jump around a long jmp) and      `md_long_jump_size' to the size of a long jump (a jump that can go      anywhere in the function), You should define      `md_create_short_jump' to create a short jump around a long jump,      and define `md_create_long_jump' to create a long jump.  */
end_comment

begin_define
define|#
directive|define
name|MD_APPLY_FIX3
end_define

begin_define
define|#
directive|define
name|TC_HANDLES_FX_DONE
end_define

begin_undef
undef|#
directive|undef
name|RELOC_EXPANSION_POSSIBLE
end_undef

begin_comment
comment|/*   If you define this macro, it means that `tc_gen_reloc' may return      multiple relocation entries for a single fixup.  In this case, the      return value of `tc_gen_reloc' is a pointer to a null terminated      array.  */
end_comment

begin_define
define|#
directive|define
name|MD_PCREL_FROM_SECTION
parameter_list|(
name|FIXP
parameter_list|,
name|SEC
parameter_list|)
value|md_pcrel_from_section(FIXP, SEC)
end_define

begin_comment
comment|/*   If you define this macro, it should return the offset between the      address of a PC relative fixup and the position from which the PC      relative adjustment should be made.  On many processors, the base      of a PC relative instruction is the next instruction, so this      macro would return the length of an instruction.  */
end_comment

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
name|LISTING_WORD_SIZE
value|2
end_define

begin_comment
comment|/*   The number of bytes to put into a word in a listing.  This affects      the way the bytes are clumped together in the listing.  For      example, a value of 2 might print `1234 5678' where a value of 1      would print `12 34 56 78'.  The default value is 4.  */
end_comment

begin_define
define|#
directive|define
name|LEX_DOLLAR
value|0
end_define

begin_comment
comment|/* MSP430 port does not use `$' as a logical line separator */
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

begin_comment
comment|/*   An `.lcomm' directive with no explicit alignment parameter will      use this macro to set P2VAR to the alignment that a request for      SIZE bytes will have.  The alignment is expressed as a power of      two.  If no alignment should take place, the macro definition      should do nothing.  Some targets define a `.bss' directive that is      also affected by this macro.  The default definition will set      P2VAR to the truncated power of two of sizes up to eight bytes.  */
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
value|msp430_relax_frag (SEG, FRAGP, STRETCH)
end_define

begin_function_decl
specifier|extern
name|long
name|msp430_relax_frag
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
name|TC_FORCE_RELOCATION_LOCAL
parameter_list|(
name|FIX
parameter_list|)
define|\
value|msp430_force_relocation_local(FIX)
end_define

begin_function_decl
specifier|extern
name|int
name|msp430_force_relocation_local
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|msp430_enable_relax
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|msp430_enable_polys
decl_stmt|;
end_decl_stmt

end_unit

