begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler for m68k targets using    assemblers derived from AT&T "SGS" releases.     Copyright (C) 1991 Free Software Foundation, Inc.     Written by Fred Fish (fnf@cygnus.com)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Control assembler-syntax conditionals in m68k.md and conditionals in    m68k.h.  Note that some systems may also require SGS_SWAP_W and/or    SGS_SWITCH_TABLES to be defined as well.  */
end_comment

begin_define
define|#
directive|define
name|MOTOROLA
end_define

begin_comment
comment|/* Use Motorola syntax rather than "MIT" */
end_comment

begin_define
define|#
directive|define
name|SGS
end_define

begin_comment
comment|/* Uses SGS assembler */
end_comment

begin_define
define|#
directive|define
name|SGS_CMP_ORDER
end_define

begin_comment
comment|/* Takes cmp operands in reverse order */
end_comment

begin_include
include|#
directive|include
file|"m68k.h"
end_include

begin_comment
comment|/* SGS specific assembler pseudo ops. */
end_comment

begin_define
define|#
directive|define
name|BYTE_ASM_OP
value|".byte"
end_define

begin_define
define|#
directive|define
name|WORD_ASM_OP
value|".short"
end_define

begin_define
define|#
directive|define
name|LONG_ASM_OP
value|".long"
end_define

begin_define
define|#
directive|define
name|SPACE_ASM_OP
value|".space"
end_define

begin_define
define|#
directive|define
name|ALIGN_ASM_OP
value|".align"
end_define

begin_undef
undef|#
directive|undef
name|GLOBAL_ASM_OP
end_undef

begin_define
define|#
directive|define
name|GLOBAL_ASM_OP
value|".global"
end_define

begin_define
define|#
directive|define
name|SWBEG_ASM_OP
value|".swbeg"
end_define

begin_define
define|#
directive|define
name|SET_ASM_OP
value|".set"
end_define

begin_define
define|#
directive|define
name|UNALIGNED_SHORT_ASM_OP
value|".short"
end_define

begin_comment
comment|/* Used in dwarfout.c */
end_comment

begin_define
define|#
directive|define
name|UNALIGNED_INT_ASM_OP
value|".long"
end_define

begin_comment
comment|/* Used in dwarfout.c */
end_comment

begin_define
define|#
directive|define
name|ASM_PN_FORMAT
value|"%s_%d"
end_define

begin_comment
comment|/* Format for private names */
end_comment

begin_comment
comment|/* Here are four prefixes that are used by asm_fprintf to    facilitate customization for alternate assembler syntaxes.    Machines with no likelihood of an alternate syntax need not    define these and need not use asm_fprintf.  */
end_comment

begin_comment
comment|/* The prefix for register names.  Note that REGISTER_NAMES    is supposed to include this prefix. Also note that this is NOT an    fprintf format string, it is a literal string */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_PREFIX
end_undef

begin_define
define|#
directive|define
name|REGISTER_PREFIX
value|"%"
end_define

begin_comment
comment|/* The prefix for local (compiler generated) labels.    These labels will not appear in the symbol table. */
end_comment

begin_undef
undef|#
directive|undef
name|LOCAL_LABEL_PREFIX
end_undef

begin_define
define|#
directive|define
name|LOCAL_LABEL_PREFIX
value|"."
end_define

begin_comment
comment|/* The prefix to add to user-visible assembler symbols. */
end_comment

begin_undef
undef|#
directive|undef
name|USER_LABEL_PREFIX
end_undef

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|""
end_define

begin_comment
comment|/* The prefix for immediate operands.  */
end_comment

begin_undef
undef|#
directive|undef
name|IMMEDIATE_PREFIX
end_undef

begin_define
define|#
directive|define
name|IMMEDIATE_PREFIX
value|"&"
end_define

begin_comment
comment|/* How to refer to registers in assembler output.    This sequence is indexed by compiler's hard-register-number.    Motorola format uses different register names than defined in m68k.h.    We also take this chance to convert 'a6' to 'fp' */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_NAMES
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|SUPPORT_SUN_FPA
end_ifndef

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{"%d0",   "%d1",   "%d2",   "%d3",   "%d4",   "%d5",   "%d6",   "%d7",	     \  "%a0",   "%a1",   "%a2",   "%a3",   "%a4",   "%a5",   "%fp",   "%sp",	     \  "%fp0",  "%fp1",  "%fp2",  "%fp3",  "%fp4",  "%fp5",  "%fp6",  "%fp7" }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SUPPORTED_SUN_FPA */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{"%d0",   "%d1",   "%d2",   "%d3",   "%d4",   "%d5",   "%d6",   "%d7",	     \  "%a0",   "%a1",   "%a2",   "%a3",   "%a4",   "%a5",   "%fp",   "%sp",	     \  "%fp0",  "%fp1",  "%fp2",  "%fp3",  "%fp4",  "%fp5",  "%fp6",  "%fp7",	     \  "%fpa0", "%fpa1", "%fpa2", "%fpa3", "%fpa4", "%fpa5", "%fpa6","%fpa7",	     \  "%fpa8", "%fpa9", "%fpa10","%fpa11","%fpa12","%fpa13","%fpa14","%fpa15",    \  "%fpa16","%fpa17","%fpa18","%fpa19","%fpa20","%fpa21","%fpa22","%fpa23",    \  "%fpa24","%fpa25","%fpa26","%fpa27","%fpa28","%fpa29","%fpa30","%fpa31" }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined SUPPORT_SUN_FPA */
end_comment

begin_comment
comment|/* When using an SGS assembler, modify the name of the artificial label which    identifies this file as having been compiled with gcc, and the macro that    emits such a label in the assembly output, to use '%' rather than '.' */
end_comment

begin_define
define|#
directive|define
name|ASM_IDENTIFY_GCC
parameter_list|(
name|FILE
parameter_list|)
define|\
value|{ fprintf ((FILE), "%s:\n", "gcc2_compiled%"); }
end_define

begin_comment
comment|/* This is how to output an assembler line defining an `int' constant.  */
end_comment

begin_comment
comment|/* The SGS assembler doesn't understand ".word". */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SHORT
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_SHORT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|( fprintf ((FILE), "\t%s ", WORD_ASM_OP),		\   output_addr_const ((FILE), (VALUE)),			\   fprintf ((FILE), "\n"))
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
value|do { union { double d; long l[2]; } tem;		\      tem.d = (VALUE);					\      fprintf((FILE), "\t%s 0x%x,0x%x\n", LONG_ASM_OP,	\ 	     tem.l[0], tem.l[1]);			\    } while (0)
end_define

begin_comment
comment|/* This is how to output an assembler line defining a `float' constant.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_FLOAT
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_FLOAT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|do { union { float f; long l;} tem;			\      tem.f = (VALUE);					\      fprintf ((FILE), "\t%s 0x%x\n", LONG_ASM_OP, tem.l); \    } while (0)
end_define

begin_comment
comment|/* This is how to output an assembler line that says to advance the    location counter to a multiple of 2**LOG bytes.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGN
end_undef

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
value|if ((LOG)> 0)						\     fprintf ((FILE), "\t%s \t%u\n", ALIGN_ASM_OP, 1<< (LOG));	\   else if ((LOG)> 31)						\     abort ();
end_define

begin_comment
comment|/* The routine used to output null terminated string literals.  We cannot    use the ".string" pseudo op, because it silently truncates strings to    1023 bytes.  There is no "partial string op" which works like ".string"    but doesn't append a null byte, so we can't chop the input string up    into small pieces and use that.  Our only remaining alternative is to    output the string one byte at a time. */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ASCII
parameter_list|(
name|FILE
parameter_list|,
name|PTR
parameter_list|,
name|LEN
parameter_list|)
define|\
value|{								\   register int sp = 0, lp = 0, ch;				\   fprintf ((FILE), "\t%s ", BYTE_ASM_OP);			\   do {								\     ch = (PTR)[sp];						\     if (ch> ' '&& ! (ch& 0x80)&& ch != '\\')		\       {								\ 	fprintf ((FILE), "'%c", ch);				\       }								\     else							\       {								\ 	fprintf ((FILE), "0x%x", ch);				\       }								\     if (++sp< (LEN))						\       {								\ 	if ((sp % 10) == 0)					\ 	  {							\ 	    fprintf ((FILE), "\n\t%s ", BYTE_ASM_OP);		\ 	  }							\ 	else							\ 	  {							\ 	    putc (',', (FILE));					\ 	  }							\       }								\   } while (sp< (LEN));						\   putc ('\n', (FILE));						\ }
end_define

begin_comment
comment|/* SGS based assemblers don't understand #NO_APP and #APP, so just don't    bother emitting them. */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_APP_ON
end_undef

begin_define
define|#
directive|define
name|ASM_APP_ON
value|""
end_define

begin_undef
undef|#
directive|undef
name|ASM_APP_OFF
end_undef

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|""
end_define

begin_comment
comment|/* When using SGS derived assemblers, change the "MIT" or "MOTOROLA"    to "SGS/AT&T"  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (68k, SGS/AT&T syntax)");
end_define

begin_comment
comment|/* Use proper assembler syntax for these macros.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_REG_PUSH
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_PUSH
parameter_list|(
name|FILE
parameter_list|,
name|REGNO
parameter_list|)
define|\
value|asm_fprintf (FILE, "\t%Omove.l %s,-(%Rsp)\n", reg_names[REGNO])
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_REG_POP
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_POP
parameter_list|(
name|FILE
parameter_list|,
name|REGNO
parameter_list|)
define|\
value|asm_fprintf (FILE, "\t%Omove.l (%Rsp)+,%s\n", reg_names[REGNO])
end_define

begin_undef
undef|#
directive|undef
name|PRINT_OPERAND_PRINT_FLOAT
end_undef

begin_define
define|#
directive|define
name|PRINT_OPERAND_PRINT_FLOAT
parameter_list|(
name|CODE
parameter_list|,
name|FILE
parameter_list|)
define|\
value|asm_fprintf ((FILE), "%I0x%x", u1.i);
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DOUBLE_OPERAND
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_DOUBLE_OPERAND
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|do {  union real_extract u;					\ 	u.d = (VALUE);						\ 	asm_fprintf ((FILE),"%I0x%x%08x", u.i[0], u.i[1]); } while (0)
end_define

begin_comment
comment|/* How to output a block of SIZE zero bytes.  Note that the `space' pseudo,    when used in the text segment, causes SGS assemblers to output nop insns    rather than 0s, so we set ASM_NO_SKIP_IN_TEXT to prevent this. */
end_comment

begin_define
define|#
directive|define
name|ASM_NO_SKIP_IN_TEXT
value|1
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SKIP
end_undef

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
value|fprintf (FILE, "\t%s %u\n", SPACE_ASM_OP, (SIZE))
end_define

begin_escape
end_escape

begin_comment
comment|/* Translate Motorola opcodes such as `jbeq' into SGS opcodes such    as `beq.w'.    Delete the `e' in `move...' and `fmove'.    Change `ftst' to `ftest'.    Change `fbne' to `fbneq'    Change `fsne' to `fsneq'    Change `divsl' to `tdivs' (32/32 -> 32r:32q)    Change `divul' to `tdivu' (32/32 -> 32r:32q)    Optionally change swap to swap.w.    */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SGS_SWAP_W
end_ifdef

begin_define
define|#
directive|define
name|ASM_OUTPUT_OPCODE
parameter_list|(
name|FILE
parameter_list|,
name|PTR
parameter_list|)
define|\
value|{							\   extern int flag_pic;					\   if (!strncmp ((PTR), "jbsr", 4))			\     { if (flag_pic)					\         fprintf ((FILE), "bsr");			\       else						\         fprintf ((FILE), "jsr");			\     (PTR) += 4; }					\   else if ((PTR)[0] == 'j'&& (PTR)[1] == 'b')		\     { ++(PTR);						\       while (*(PTR) != ' ')				\ 	{ putc (*(PTR), (FILE)); ++(PTR); }		\       fprintf ((FILE), ".w"); }				\   else if ((PTR)[0] == 's')				\     {							\       if (!strncmp ((PTR), "swap", 4))			\ 	{ fprintf ((FILE), "swap.w"); (PTR) += 4; }	\     }							\
comment|/* FMOVE ==> FMOV, (and F%& F%$ translations) */
value|\   else if ((PTR)[0] == 'f')				\     {							\       if (!strncmp ((PTR), "fmove", 5))			\ 	{ fprintf ((FILE), "fmov"); (PTR) += 5; }	\       else if (!strncmp ((PTR), "ftst", 4))		\ 	{ fprintf ((FILE), "ftest"); (PTR) += 4; }	\       else if (!strncmp ((PTR), "fbne", 4))		\ 	{ fprintf ((FILE), "fbneq"); (PTR) += 4; }	\       else if (!strncmp ((PTR), "fsne", 4))		\ 	{ fprintf ((FILE), "fsneq"); (PTR) += 4; }	\       else if (!strncmp ((PTR), "f%$move", 7))		\ 	{ (PTR) += 7;					\ 	  if (TARGET_68040_ONLY)			\ 	    fprintf ((FILE), "fsmov");			\ 	  else fprintf ((FILE), "fmov"); }		\       else if (!strncmp ((PTR), "f%&move", 7))		\ 	{ (PTR) += 7;					\ 	  if (TARGET_68040_ONLY)			\ 	    fprintf ((FILE), "fdmov");			\ 	  else fprintf ((FILE), "fmov"); }		\     }							\
comment|/* MOVE, MOVEA, MOVEQ, MOVEC ==> MOV	*/
value|\   else if ((PTR)[0] == 'm'&& (PTR)[1] == 'o'		\&& (PTR)[2] == 'v'&& (PTR)[3] == 'e')	\     { fprintf ((FILE), "mov"); (PTR) += 4;		\        if ((PTR)[0] == 'q' || (PTR)[0] == 'a'		\ 	   || (PTR)[0] == 'c') (PTR)++; }		\
comment|/* SUB, SUBQ, SUBA, SUBI ==> SUB */
value|\   else if ((PTR)[0] == 's'&& (PTR)[1] == 'u' 		\&& (PTR)[2] == 'b')				\     { fprintf ((FILE), "sub"); (PTR) += 3;		\        if ((PTR)[0] == 'q' || (PTR)[0] == 'i'	 	\ 	   || (PTR)[0] == 'a') (PTR)++; }		\
comment|/* CMP, CMPA, CMPI, CMPM ==> CMP	*/
value|\   else if ((PTR)[0] == 'c'&& (PTR)[1] == 'm'		\&& (PTR)[2] == 'p')				\     { fprintf ((FILE), "cmp"); (PTR) += 3;		\        if ((PTR)[0] == 'a' || (PTR)[0] == 'i'	 	\ 	   || (PTR)[0] == 'm') (PTR)++; }		\
comment|/* DIVSL ==> TDIVS */
value|\   else if ((PTR)[0] == 'd'&& (PTR)[1] == 'i'		\&& (PTR)[2] == 'v'&& (PTR)[3] == 's'	\&& (PTR)[4] == 'l')				\     { fprintf ((FILE), "tdivs"); (PTR) += 5; }		\
comment|/* DIVUL ==> TDIVU */
value|\   else if ((PTR)[0] == 'd'&& (PTR)[1] == 'i'		\&& (PTR)[2] == 'v'&& (PTR)[3] == 'u'	\&& (PTR)[4] == 'l')				\     { fprintf ((FILE), "tdivu"); (PTR) += 5; }		\ }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not SGS_SWAP_W */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_OPCODE
parameter_list|(
name|FILE
parameter_list|,
name|PTR
parameter_list|)
define|\
value|{							\   extern int flag_pic;					\   if (!strncmp ((PTR), "jbsr", 4))			\     { if (flag_pic)					\         fprintf ((FILE), "bsr");			\       else						\         fprintf ((FILE), "jsr");			\     (PTR) += 4; }					\   else if ((PTR)[0] == 'j'&& (PTR)[1] == 'b')		\     { ++(PTR);						\       while (*(PTR) != ' ')				\ 	{ putc (*(PTR), (FILE)); ++(PTR); }		\       fprintf ((FILE), ".w"); }				\
comment|/* FMOVE ==> FMOV, (and F%& F%$ translations) */
value|\   else if ((PTR)[0] == 'f')				\     {							\       if (!strncmp ((PTR), "fmove", 5))			\ 	{ fprintf ((FILE), "fmov"); (PTR) += 5; }	\       else if (!strncmp ((PTR), "ftst", 4))		\ 	{ fprintf ((FILE), "ftest"); (PTR) += 4; }	\       else if (!strncmp ((PTR), "fbne", 4))		\ 	{ fprintf ((FILE), "fbneq"); (PTR) += 4; }	\       else if (!strncmp ((PTR), "fsne", 4))		\ 	{ fprintf ((FILE), "fsneq"); (PTR) += 4; }	\       else if (!strncmp ((PTR), "f%$move", 7))		\ 	{ (PTR) += 7;					\ 	  if (TARGET_68040_ONLY)			\ 	    fprintf ((FILE), "fsmov");			\ 	  else fprintf ((FILE), "fmov"); }		\       else if (!strncmp ((PTR), "f%&move", 7))		\ 	{ (PTR) += 7;					\ 	  if (TARGET_68040_ONLY)			\ 	    fprintf ((FILE), "fdmov");			\ 	  else fprintf ((FILE), "fmov"); }		\     }							\
comment|/* MOVE, MOVEA, MOVEQ, MOVEC ==> MOV	*/
value|\   else if ((PTR)[0] == 'm'&& (PTR)[1] == 'o'		\&& (PTR)[2] == 'v'&& (PTR)[3] == 'e')	\     { fprintf ((FILE), "mov"); (PTR) += 4;		\        if ((PTR)[0] == 'q' || (PTR)[0] == 'a'		\ 	   || (PTR)[0] == 'c') (PTR)++; }		\
comment|/* SUB, SUBQ, SUBA, SUBI ==> SUB */
value|\   else if ((PTR)[0] == 's'&& (PTR)[1] == 'u' 		\&& (PTR)[2] == 'b')				\     { fprintf ((FILE), "sub"); (PTR) += 3;		\        if ((PTR)[0] == 'q' || (PTR)[0] == 'i'	 	\ 	   || (PTR)[0] == 'a') (PTR)++; }		\
comment|/* CMP, CMPA, CMPI, CMPM ==> CMP	*/
value|\   else if ((PTR)[0] == 'c'&& (PTR)[1] == 'm'		\&& (PTR)[2] == 'p')				\     { fprintf ((FILE), "cmp"); (PTR) += 3;		\        if ((PTR)[0] == 'a' || (PTR)[0] == 'i'	 	\ 	   || (PTR)[0] == 'm') (PTR)++; }		\
comment|/* DIVSL ==> TDIVS */
value|\   else if ((PTR)[0] == 'd'&& (PTR)[1] == 'i'		\&& (PTR)[2] == 'v'&& (PTR)[3] == 's'	\&& (PTR)[4] == 'l')				\     { fprintf ((FILE), "tdivs"); (PTR) += 5; }		\
comment|/* DIVUL ==> TDIVU */
value|\   else if ((PTR)[0] == 'd'&& (PTR)[1] == 'i'		\&& (PTR)[2] == 'v'&& (PTR)[3] == 'u'	\&& (PTR)[4] == 'l')				\     { fprintf ((FILE), "tdivu"); (PTR) += 5; }		\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not SGS_SWAP_W */
end_comment

begin_escape
end_escape

begin_comment
comment|/* This macro outputs the label at the start of a switch table.  The    ".swbeg<N>" is an assembler directive that causes the switch table    size to be inserted into the object code so that disassemblers, for    example, can identify that it is the start of a switch table. */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_BEFORE_CASE_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|,
name|TABLE
parameter_list|)
define|\
value|fprintf ((FILE), "\t%s&%d\n", SWBEG_ASM_OP, XVECLEN (PATTERN (TABLE), 1));
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_CASE_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|,
name|TABLE
parameter_list|)
define|\
value|do {									\     ASM_OUTPUT_BEFORE_CASE_LABEL((FILE),(PREFIX),(NUM),(TABLE));	\     ASM_OUTPUT_INTERNAL_LABEL((FILE),(PREFIX),(NUM));			\   } while (0)
end_define

begin_comment
comment|/* At end of a switch table, define LDnnn iff the symbol LInnn was defined.    Some SGS assemblers have a bug such that "Lnnn-LInnn-2.b(pc,d0.l*2)"    fails to assemble.  Luckily "LDnnn(pc,d0.l*2)" produces the results    we want.  This difference can be accommodated by making the assembler    define such "LDnnn" to be either "Lnnn-LInnn-2.b", "Lnnn", or any other    string, as necessary.  This is accomplished via the ASM_OUTPUT_CASE_END    macro. */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_CASE_END
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_CASE_END
parameter_list|(
name|FILE
parameter_list|,
name|NUM
parameter_list|,
name|TABLE
parameter_list|)
define|\
value|{ if (switch_table_difference_label_flag)		\     asm_fprintf (FILE, "\t%s %LLD%d,%LL%d-%LLI%d-2.b\n",\ 		 SET_ASM_OP, (NUM), (NUM), (NUM))	\   switch_table_difference_label_flag = 0; }
end_define

begin_decl_stmt
name|int
name|switch_table_difference_label_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is how to output an element of a case-vector that is relative.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ADDR_DIFF_ELT
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_DIFF_ELT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|,
name|REL
parameter_list|)
define|\
value|asm_fprintf (FILE, "\t%s %LL%d-%LL%d\n", WORD_ASM_OP, VALUE, REL)
end_define

begin_comment
comment|/* Currently, JUMP_TABLES_IN_TEXT_SECTION must be defined in order to    keep switch tables in the text section. */
end_comment

begin_define
define|#
directive|define
name|JUMP_TABLES_IN_TEXT_SECTION
value|1
end_define

begin_comment
comment|/* Store in OUTPUT a string (made with alloca) containing    an assembler-name for a local static variable named NAME.    LABELNO is an integer which is different for each call.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FORMAT_PRIVATE_NAME
end_undef

begin_define
define|#
directive|define
name|ASM_FORMAT_PRIVATE_NAME
parameter_list|(
name|OUTPUT
parameter_list|,
name|NAME
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|( (OUTPUT) = (char *) alloca (strlen ((NAME)) + 10),	\   sprintf ((OUTPUT), ASM_PN_FORMAT, (NAME), (LABELNO)))
end_define

end_unit

