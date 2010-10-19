begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-maxq.h -- Header file for the asssembler(MAXQ)     Copyright 2004, 2005  Free Software Foundation, Inc.     Contributed by HCL Technologies Pvt. Ltd.     Written by Vineet Sharma(vineets@noida.hcltech.com) Inderpreet    S.(inderpreetb@noida.hcltech.com)     This file is part of GAS.     GAS is free software; you can redistribute it and/or modify it under the    terms of the GNU General Public License as published by the Free Software    Foundation; either version 2, or (at your option) any later version.     GAS is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS    FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more    details.     You should have received a copy of the GNU General Public License along    with GAS; see the file COPYING.  If not, write to the Free Software    Foundation, 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TC_MAXQ_H_
end_ifndef

begin_define
define|#
directive|define
name|_TC_MAXQ_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_RELOC
end_ifndef

begin_define
define|#
directive|define
name|NO_RELOC
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* `md_short_jump_size' `md_long_jump_size' `md_create_short_jump'    `md_create_long_jump' If `WORKING_DOT_WORD' is defined, GAS will not do    broken word processing (*note Broken words::.).  Otherwise, you should set    `md_short_jump_size' to the size of a short jump (a jump that is just long    enough to jump around a long jmp) and `md_long_jump_size' to the size of a    long jump (a jump that can go anywhere in the function), You should define    `md_create_short_jump' to create a short jump around a long jump, and    define `md_create_long_jump' to create a long jump.  */
end_comment

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_typedef
typedef|typedef
enum|enum
name|_RELOC_ENUM
block|{
name|MAXQ_WORDDATA
init|=
literal|5
block|,
comment|/* Word+n.  */
name|MAXQ_LONGDATA
init|=
literal|2
block|,
comment|/* Long+n.  */
name|MAXQ_INTERSEGMENT
init|=
literal|4
block|,
comment|/* Text to any other segment.  */
name|MAXQ_SHORTJUMP
init|=
name|BFD_RELOC_16_PCREL_S2
block|,
comment|/* PC Relative.  */
name|MAXQ_LONGJUMP
init|=
literal|6
block|,
comment|/* Absolute Jump.  */
name|EXTERNAL_RELOC
init|=
literal|8
block|,
name|INTERSEGMENT_RELOC
block|}
name|RELOC_ENUM
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|MAX_STACK
end_ifndef

begin_define
define|#
directive|define
name|MAX_STACK
value|0xf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TC_MAXQ20
end_ifndef

begin_define
define|#
directive|define
name|TC_MAXQ20
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAX_OPERAND_SIZE
end_ifndef

begin_define
define|#
directive|define
name|MAX_OPERAND_SIZE
value|255
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXQ_INSTRUCTION_SIZE
end_ifndef

begin_define
define|#
directive|define
name|MAXQ_INSTRUCTION_SIZE
value|2
end_define

begin_comment
comment|/* 16 - BITS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|MAXQ_INSTRUCTION_SIZE
end_if

begin_define
define|#
directive|define
name|MAXQ_OCTETS_PER_BYTE
value|MAXQ_INSTRUCTION_SIZE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXQ_OCTETS_PER_BYTE
value|OCTETS_PER_BYTE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* if this macro is defined gas will use this instead of comment_chars.  */
end_comment

begin_define
define|#
directive|define
name|tc_comments_chars
value|maxq20_comment_chars
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
name|md_section_align
parameter_list|(
name|SEGMENT
parameter_list|,
name|SIZE
parameter_list|)
value|(SIZE)
end_define

begin_comment
comment|/* Locally defined symbol shoudnot be adjusted to section symbol.  */
end_comment

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
value|0
end_define

begin_comment
comment|/* This specifies that the target has been defined as little endian -    default.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|0
end_define

begin_define
define|#
directive|define
name|MAX_MEM_NAME_SIZE
value|12
end_define

begin_define
define|#
directive|define
name|MAX_REG_NAME_SIZE
value|7
end_define

begin_define
define|#
directive|define
name|MAX_MNEM_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|END_OF_INSN
value|'\0'
end_define

begin_comment
comment|/* This macro is the BFD archetectureto pass to 'bfd_set_arch_mach'.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_maxq
end_define

begin_comment
comment|/* This macro is the BFD machine number to pass to 'bfd_set_arch_mach'.    If not defines GAS will use 0.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MACH
value|maxq20_mach ()
end_define

begin_function_decl
specifier|extern
name|unsigned
name|long
name|maxq20_mach
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|LEX_AT
end_ifndef

begin_comment
comment|/* We define this macro to generate a fixup for a data allocation pseudo-op.  */
end_comment

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
value|maxq20_cons_fix_new (FRAG,OFF,LEN,EXP)
end_define

begin_function_decl
specifier|extern
name|void
name|maxq20_cons_fix_new
parameter_list|(
name|fragS
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|expressionS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define md_number_to_chars as the appropriate standard big endian or This    should just call either `number_to_chars_bigendian' or    `number_to_chars_littleendian', whichever is appropriate.  On targets like     the MIPS which support options to change the endianness, which function to     call is a runtime decision.  On other targets, `md_number_to_chars' can be     a simple macro.  */
end_comment

begin_define
define|#
directive|define
name|md_number_to_chars
value|maxq_number_to_chars
end_define

begin_function_decl
specifier|extern
name|void
name|maxq_number_to_chars
parameter_list|(
name|char
modifier|*
parameter_list|,
name|valueT
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* If this macro is defined, it is a pointer to a NULL terminated list of    chracters which may appear in an operand. GAS already assumes that all    alphanumeric chracters, and '$', '.', and '_' may appear in an    operand("symbol_char"in app.c). This macro may be defined to treat    additional chracters as appearing in an operand. This affects the way in    which GAS removes whitespaces before passing the string to md_assemble.  */
end_comment

begin_define
define|#
directive|define
name|tc_symbol_chars_extra_symbol_chars
end_define

begin_comment
comment|/* Define away the call to md_operand in the expression parsing code. This is     called whenever the expression parser can't parse the input and gives the    assembler backend a chance to deal with it instead.  */
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
name|MAX_OPERANDS
value|2
end_define

begin_comment
comment|/* Max operands per instruction.  */
end_comment

begin_define
define|#
directive|define
name|MAX_IMMEDIATE_OPERANDS
value|1
end_define

begin_comment
comment|/* Max immediate operands per instruction.  */
end_comment

begin_define
define|#
directive|define
name|MAX_MEMORY_OPERANDS
value|1
end_define

begin_comment
comment|/* Max memory operands per instruction.  */
end_comment

begin_comment
comment|/* Define the prefix we are using while trying to use an immediate value in    an instruction. e.g move A[0], #03h.  */
end_comment

begin_define
define|#
directive|define
name|IMMEDIATE_PREFIX
value|'#'
end_define

begin_define
define|#
directive|define
name|ABSOLUTE_PREFIX
value|'@'
end_define

begin_comment
comment|/* This here defines the opcode of the nop operation on the MAXQ. We did    declare it here when we tried to fill the align bites with nop's but GAS    only expects nop's to be single byte instruction.  */
end_comment

begin_define
define|#
directive|define
name|NOP_OPCODE
value|(char)0xDA3A
end_define

begin_define
define|#
directive|define
name|SIZE_OF_PM
value|sizeof(pmodule)
end_define

begin_comment
comment|/* Size of the structure.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_MAXQ_H */
end_comment

end_unit

