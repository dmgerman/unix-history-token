begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Unix assembler syntax for the Intel 80386.    Copyright (C) 1988, 1994 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* This file defines the aspects of assembler syntax    that are the same for all the i386 Unix systems    (though they may differ in non-Unix systems).  */
end_comment

begin_comment
comment|/* Define some concatenation macros to concatenate an opcode    and one, two or three operands.  In other assembler syntaxes    they may alter the order of ther operands.  */
end_comment

begin_comment
comment|/* Note that the other files fail to use these    in some of the places where they should.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|ALMOST_STDC
argument_list|)
end_if

begin_define
define|#
directive|define
name|AS2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|#a " " #b "," #c
end_define

begin_define
define|#
directive|define
name|AS2C
parameter_list|(
name|b
parameter_list|,
name|c
parameter_list|)
value|" " #b "," #c
end_define

begin_define
define|#
directive|define
name|AS3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|#a " " #b "," #c "," #d
end_define

begin_define
define|#
directive|define
name|AS1
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|#a " " #b
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AS1
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|"a b"
end_define

begin_define
define|#
directive|define
name|AS2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|"a b,c"
end_define

begin_define
define|#
directive|define
name|AS2C
parameter_list|(
name|b
parameter_list|,
name|c
parameter_list|)
value|" b,c"
end_define

begin_define
define|#
directive|define
name|AS3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|"a b,c,d"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define macro used to output shift-double opcodes when the shift    count is in %cl.  Some assemblers require %cl as an argument;    some don't.  This macro controls what to do: by default, don't    print %cl.  */
end_comment

begin_define
define|#
directive|define
name|AS3_SHIFT_DOUBLE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|AS2 (a,c,d)
end_define

begin_comment
comment|/* Output the size-letter for an opcode.    CODE is the letter used in an operand spec (L, B, W, S or Q).    CH is the corresponding lower case letter      (except if CODE is `Q' then CH is `l', unless GAS_MNEMONICS).  */
end_comment

begin_define
define|#
directive|define
name|PUT_OP_SIZE
parameter_list|(
name|CODE
parameter_list|,
name|CH
parameter_list|,
name|FILE
parameter_list|)
value|putc (CH,(FILE))
end_define

begin_comment
comment|/* Opcode suffix for fullword insn.  */
end_comment

begin_define
define|#
directive|define
name|L_SIZE
value|"l"
end_define

begin_comment
comment|/* Prefix for register names in this syntax.  */
end_comment

begin_define
define|#
directive|define
name|RP
value|"%"
end_define

begin_comment
comment|/* Prefix for immediate operands in this syntax.  */
end_comment

begin_define
define|#
directive|define
name|IP
value|"$"
end_define

begin_comment
comment|/* Indirect call instructions should use `*'.  */
end_comment

begin_define
define|#
directive|define
name|USE_STAR
value|1
end_define

begin_comment
comment|/* Prefix for a memory-operand X.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_PTR
parameter_list|(
name|X
parameter_list|,
name|FILE
parameter_list|)
end_define

begin_comment
comment|/* Delimiters that surround base reg and index reg.  */
end_comment

begin_define
define|#
directive|define
name|ADDR_BEG
parameter_list|(
name|FILE
parameter_list|)
value|putc('(', (FILE))
end_define

begin_define
define|#
directive|define
name|ADDR_END
parameter_list|(
name|FILE
parameter_list|)
value|putc(')', (FILE))
end_define

begin_comment
comment|/* Print an index register (whose rtx is IREG).  */
end_comment

begin_define
define|#
directive|define
name|PRINT_IREG
parameter_list|(
name|FILE
parameter_list|,
name|IREG
parameter_list|)
define|\
value|do								\   { fputs (",", (FILE)); PRINT_REG ((IREG), 0, (FILE)); }	\   while (0)
end_define

begin_comment
comment|/* Print an index scale factor SCALE.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_SCALE
parameter_list|(
name|FILE
parameter_list|,
name|SCALE
parameter_list|)
define|\
value|if ((SCALE) != 1) fprintf ((FILE), ",%d", (SCALE))
end_define

begin_comment
comment|/* Print a base/index combination.    BREG is the base reg rtx, IREG is the index reg rtx,    and SCALE is the index scale factor (an integer).  */
end_comment

begin_define
define|#
directive|define
name|PRINT_B_I_S
parameter_list|(
name|BREG
parameter_list|,
name|IREG
parameter_list|,
name|SCALE
parameter_list|,
name|FILE
parameter_list|)
define|\
value|{ ADDR_BEG (FILE); 				\     if (BREG) PRINT_REG ((BREG), 0, (FILE));	\     if ((IREG) != 0)				\       { PRINT_IREG ((FILE), (IREG));		\         PRINT_SCALE ((FILE), (SCALE)); }	\     ADDR_END (FILE); }
end_define

begin_escape
end_escape

begin_comment
comment|/* Define the syntax of pseudo-ops, labels and comments.  */
end_comment

begin_comment
comment|/* String containing the assembler's comment-starter.  */
end_comment

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|"/"
end_define

begin_comment
comment|/* Output to assembler file text saying following lines    may contain character constants, extra white space, comments, etc.  */
end_comment

begin_define
define|#
directive|define
name|ASM_APP_ON
value|"/APP\n"
end_define

begin_comment
comment|/* Output to assembler file text saying following lines    no longer contain unusual constructs.  */
end_comment

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|"/NO_APP\n"
end_define

begin_comment
comment|/* Output before read-only data.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|".text"
end_define

begin_comment
comment|/* Output before writable (initialized) data.  */
end_comment

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|".data"
end_define

begin_comment
comment|/* Output before writable (uninitialized) data.  */
end_comment

begin_define
define|#
directive|define
name|BSS_SECTION_ASM_OP
value|".bss"
end_define

begin_comment
comment|/* This is how to output a command to make the user-level label named NAME    defined for reference from other files.  */
end_comment

begin_define
define|#
directive|define
name|ASM_GLOBALIZE_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|(fputs (".globl ", FILE), assemble_name (FILE, NAME), fputs ("\n", FILE))
end_define

begin_comment
comment|/* By default, target has a 80387, uses IEEE compatible arithmetic,    and returns float values in the 387, ie,    (TARGET_80387 | TARGET_IEEE_FP | TARGET_FLOAT_RETURNS_IN_80387) */
end_comment

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|0301
end_define

begin_comment
comment|/* Floating-point return values come in the FP register.  */
end_comment

begin_define
define|#
directive|define
name|VALUE_REGNO
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(GET_MODE_CLASS (MODE) == MODE_FLOAT				\&& TARGET_FLOAT_RETURNS_IN_80387 ? FIRST_FLOAT_REG : 0)
end_define

begin_comment
comment|/* 1 if N is a possible register number for a function value. */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|N
parameter_list|)
define|\
value|((N) == 0 || ((N)== FIRST_FLOAT_REG&& TARGET_FLOAT_RETURNS_IN_80387))
end_define

end_unit

