begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for BSD assembler syntax for Intel 386    (actually AT&T syntax for insns and operands,    adapted to BSD conventions for symbol names and debugging.)    Copyright (C) 1988 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Use the Sequent Symmetry assembler syntax.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (80386, BSD syntax)");
end_define

begin_comment
comment|/* Define some concatenation macros to concatenate an opcode    and one, two or three operands.  In other assembler syntaxes    they may alter the order of ther operands.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

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
comment|/* Output the size-letter for an opcode.    CODE is the letter used in an operand spec (L, B, W, S or Q).    CH is the corresponding lower case letter      (except if CODE is L then CH is `l').  */
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
comment|/* Prefix for internally generated assembler labels.  */
end_comment

begin_define
define|#
directive|define
name|LPREFIX
value|"L"
end_define

begin_comment
comment|/* Output the prefix for an immediate operand, or for an offset operand.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_IMMED_PREFIX
parameter_list|(
name|FILE
parameter_list|)
value|fputs ("$", (FILE))
end_define

begin_define
define|#
directive|define
name|PRINT_OFFSET_PREFIX
parameter_list|(
name|FILE
parameter_list|)
value|fputs ("$", (FILE))
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
comment|/* Assembler pseudos to introduce constants of various size.  */
end_comment

begin_define
define|#
directive|define
name|ASM_BYTE
value|"\t.byte "
end_define

begin_define
define|#
directive|define
name|ASM_SHORT
value|"\t.word "
end_define

begin_define
define|#
directive|define
name|ASM_LONG
value|"\t.long "
end_define

begin_define
define|#
directive|define
name|ASM_DOUBLE
value|"\t.double "
end_define

begin_comment
comment|/* String containing the assembler's comment-starter.  */
end_comment

begin_define
define|#
directive|define
name|COMMENT_BEGIN
value|"/"
end_define

begin_comment
comment|/* Output at beginning of assembler file.    ??? I am skeptical of this -- RMS.  */
end_comment

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|FILE
parameter_list|)
define|\
value|fprintf (FILE, "\t.file\t\"%s\"\n", dump_base_name);
end_define

begin_comment
comment|/* This was suggested, but it shouldn't be right for DBX output. -- RMS    #define ASM_OUTPUT_SOURCE_FILENAME(FILE, NAME) */
end_comment

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

begin_escape
end_escape

begin_comment
comment|/* Define the syntax of labels and symbol definitions/declarations.  */
end_comment

begin_comment
comment|/* This is how to output an assembler line    that says to advance the location counter by SIZE bytes.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_SKIP
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|fprintf (FILE, "\t.space %u\n", (SIZE))
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
comment|/* Output before writable data.  */
end_comment

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|".data"
end_define

begin_escape
end_escape

begin_comment
comment|/* Define the syntax of labels and symbol definitions/declarations.  */
end_comment

begin_comment
comment|/* This says how to output an assembler line    to define a global common symbol.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_COMMON
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|( fputs (".comm ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%u\n", (SIZE)))
end_define

begin_comment
comment|/* This says how to output an assembler line    to define a local common symbol.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_LOCAL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|( fputs (".lcomm ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%u\n", (SIZE)))
end_define

begin_comment
comment|/* This is how to output an assembler line    that says to advance the location counter    to a multiple of 2**LOG bytes.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN
parameter_list|(
name|FILE
parameter_list|,
name|LOG
parameter_list|)
define|\
value|if ((LOG)!=0) fprintf ((FILE), "\t.align %d\n", (LOG))
end_define

begin_comment
comment|/* This is how to store into the string BUF    the symbol_ref name of an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.    This is suitable for output with `assemble_name'.  */
end_comment

begin_define
define|#
directive|define
name|ASM_GENERATE_INTERNAL_LABEL
parameter_list|(
name|BUF
parameter_list|,
name|PREFIX
parameter_list|,
name|NUMBER
parameter_list|)
define|\
value|sprintf ((BUF), "*%s%d", (PREFIX), (NUMBER))
end_define

begin_comment
comment|/* This is how to output an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_INTERNAL_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|fprintf (FILE, "%s%d:\n", PREFIX, NUM)
end_define

begin_comment
comment|/* This is how to output a reference to a user-level label named NAME.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABELREF
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|fprintf (FILE, "_%s", NAME)
end_define

begin_comment
comment|/* Sequent has some changes in the format of DBX symbols.  */
end_comment

begin_define
define|#
directive|define
name|DBX_NO_XREFS
value|1
end_define

begin_comment
comment|/* Don't split DBX symbols into continuations.  */
end_comment

begin_define
define|#
directive|define
name|DBX_CONTIN_LENGTH
value|0
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
comment|/* This is how to output an assembler line defining a `double' constant.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DOUBLE
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_DOUBLE
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|fprintf (FILE, "\t.double 0d%.20e\n", (VALUE))
end_define

end_unit

