begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.    AT&T UNIX PC version (pc7300, 3b1)     Written by Alex Crain    bug reports to alex@umbc3.umd.edu     Copyright (C) 1987 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|SGS_SWITCH_TABLES
end_define

begin_comment
comment|/* Different switch table handling */
end_comment

begin_include
include|#
directive|include
file|"hp320.h"
end_include

begin_comment
comment|/* See m68k.h.  0 means 680[01]0 with no 68881.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|0
end_define

begin_comment
comment|/* -m68020 requires special flags to the assembler.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{m68020:-68020}%{!m68020:-68010} %{m68881:-68881}"
end_define

begin_comment
comment|/* we use /lib/libp/lib*  when profiling */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!shlib:%{p:-L/lib/libp} %{pg:-L/lib/libp} -lc}"
end_define

begin_comment
comment|/* shared libraries need to use crt0s.o  */
end_comment

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{!shlib:%{pg:mcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}}\    %{shlib:crt0s.o%s shlib.ifile%s} "
end_define

begin_comment
comment|/* cpp has to support a #sccs directive for the /usr/include files */
end_comment

begin_define
define|#
directive|define
name|SCCS_DIRECTIVE
end_define

begin_comment
comment|/* Make output for SDB.  */
end_comment

begin_define
define|#
directive|define
name|SDB_DEBUGGING_INFO
end_define

begin_comment
comment|/* The .file command should always begin the output.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FILE_START
end_undef

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|FILE
parameter_list|)
define|\
value|output_file_directive ((FILE), main_input_filename)
end_define

begin_comment
comment|/* Don't try to define `gcc_compiled.' since the assembler might not    accept symbols with periods and GDB doesn't run on this machine anyway.  */
end_comment

begin_define
define|#
directive|define
name|ASM_IDENTIFY_GCC
parameter_list|(
name|FILE
parameter_list|)
end_define

begin_comment
comment|/* Define __HAVE_68881__ in preprocessor if -m68881 is specified.    This will control the use of inline 68881 insns in certain macros.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{m68881:-D__HAVE_68881__}"
end_define

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_comment
comment|/* ihnp4!lmayk!lgm@eddie.mit.edu says mc68000 and m68k should not be here.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dmc68k -Dunix -Dunixpc"
end_define

begin_undef
undef|#
directive|undef
name|REGISTER_NAMES
end_undef

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{"%d0", "%d1", "%d2", "%d3", "%d4", "%d5", "%d6", "%d7",	\  "%a0", "%a1", "%a2", "%a3", "%a4", "%a5", "%fp", "%sp",	\  "%f0", "%f1", "%f2", "%f3", "%f4", "%f5", "%f6", "%f7"}
end_define

begin_comment
comment|/* Specify how to pad function arguments.    Value should be `upward', `downward' or `none'.    Same as the default, except no padding for large or variable-size args.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_PADDING
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|(((MODE) == BLKmode							\     ? ((TYPE)&& TREE_CODE (TYPE_SIZE (TYPE)) == INTEGER_CST		\&& int_size_in_bytes (TYPE)< PARM_BOUNDARY / BITS_PER_UNIT)	\     : GET_MODE_BITSIZE (MODE)< PARM_BOUNDARY)				\    ? downward : none)
end_define

begin_comment
comment|/* Override part of the obstack macros.  */
end_comment

begin_define
define|#
directive|define
name|__PTR_TO_INT
parameter_list|(
name|P
parameter_list|)
value|((int)(P))
end_define

begin_define
define|#
directive|define
name|__INT_TO_PTR
parameter_list|(
name|P
parameter_list|)
value|((char *)(P))
end_define

begin_comment
comment|/* The 3b1 does not have `atexit'.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_ATEXIT
end_undef

begin_comment
comment|/* Override parts of m68k.h to fit the SGS-3b1 assembler.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_undef
undef|#
directive|undef
name|ASM_FORMAT_PRIVATE_NAME
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DOUBLE
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_FLOAT
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGN
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SOURCE_FILENAME
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SOURCE_LINE
end_undef

begin_undef
undef|#
directive|undef
name|PRINT_OPERAND_ADDRESS
end_undef

begin_undef
undef|#
directive|undef
name|ASM_GENERATE_INTERNAL_LABEL
end_undef

begin_undef
undef|#
directive|undef
name|FUNCTION_PROFILER
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ADDR_VEC_ELT
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ADDR_DIFF_ELT
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_INTERNAL_LABEL
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_OPCODE
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LOCAL
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LABELREF
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ASCII
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (68k, SGS/AT&T unixpc syntax)");
end_define

begin_comment
comment|/* Store in OUTPUT a string (made with alloca) containing    an assembler-name for a local static variable named NAME.    LABELNO is an integer which is different for each call.  */
end_comment

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
value|( (OUTPUT) = (char *) alloca (strlen ((NAME)) + 12),	\   sprintf ((OUTPUT), "%s_%%%d", (NAME), (LABELNO)))
end_define

begin_comment
comment|/* The unixpc doesn't know about double's and float's */
end_comment

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
value|do { union { double d; long l[2]; } tem;		\      tem.d = (VALUE);					\      fprintf(FILE, "\tlong 0x%x,0x%x\n", tem.l[0], tem.l[1]); \    } while (0)
end_define

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
value|do { union { float f; long l;} tem;			\      tem.f = (VALUE);					\      fprintf (FILE, "\tlong 0x%x\n", tem.l);	\    } while (0)
end_define

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
value|if ((LOG) == 1)			\     fprintf (FILE, "\teven\n");	\   else if ((LOG) != 0)			\     abort ();
end_define

begin_comment
comment|/* This is how to output an assembler line    that says to advance the location counter by SIZE bytes.  */
end_comment

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
value|fprintf (FILE, "\tspace %d\n", (SIZE))
end_define

begin_comment
comment|/* Can't use ASM_OUTPUT_SKIP in text section; it doesn't leave 0s.  */
end_comment

begin_define
define|#
directive|define
name|ASM_NO_SKIP_IN_TEXT
value|1
end_define

begin_comment
comment|/* The beginnings of sdb support... */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_SOURCE_FILENAME
parameter_list|(
name|FILE
parameter_list|,
name|FILENAME
parameter_list|)
define|\
value|fprintf (FILE, "\tfile\t\"%s\"\n", FILENAME)
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_SOURCE_LINE
parameter_list|(
name|FILE
parameter_list|,
name|LINENO
parameter_list|)
define|\
value|fprintf (FILE, "\tln\t%d\n",			\ 	   (sdb_begin_function_line		\ 	    ? last_linenum - sdb_begin_function_line : 1))
end_define

begin_comment
comment|/* Yet another null terminated string format. */
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
value|{ register int sp = 0, lp = 0; \     fprintf ((FILE), "\tbyte\t"); \   loop: \     if ((PTR)[sp]> ' '&& ! ((PTR)[sp]& 0x80)&& (PTR)[sp] != '\\') \       { lp += 3; \ 	fprintf ((FILE), "'%c", (PTR)[sp]); } \     else \       { lp += 5; \ 	fprintf ((FILE), "0x%x", (PTR)[sp]); } \     if (++sp< (LEN)) \       {	if (lp> 60) \ 	  { lp = 0; \ 	    fprintf ((FILE), "\n\t%s ", ASCII_DATA_ASM_OP); }	\ 	else \ 	  putc (',', (FILE)); \ 	goto loop; } \     putc ('\n', (FILE)); }
end_define

begin_comment
comment|/* Note that in the case of the movhi which fetches an element of    an ADDR_DIFF_VEC the offset output is too large by 2.    This is because the 3b1 assembler refuses to subtract 2.    ASM_OUTPUT_CASE_LABEL, below, compensates for this.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND_ADDRESS
parameter_list|(
name|FILE
parameter_list|,
name|ADDR
parameter_list|)
define|\
value|{ register rtx reg1, reg2, breg, ireg;					\   register rtx addr = ADDR;						\   rtx offset;								\   switch (GET_CODE (addr))						\     {									\     case REG:								\       fprintf (FILE, "(%s)", reg_names[REGNO (addr)]);			\       break;								\     case PRE_DEC:							\       fprintf (FILE, "-(%s)", reg_names[REGNO (XEXP (addr, 0))]);	\       break;								\     case POST_INC:							\       fprintf (FILE, "(%s)+", reg_names[REGNO (XEXP (addr, 0))]);	\       break;								\     case PLUS:								\       reg1 = 0;	reg2 = 0;						\       ireg = 0;	breg = 0;						\       offset = 0;							\       if (CONSTANT_ADDRESS_P (XEXP (addr, 0)))				\ 	{								\ 	  offset = XEXP (addr, 0);					\ 	  addr = XEXP (addr, 1);					\ 	}								\       else if (CONSTANT_ADDRESS_P (XEXP (addr, 1)))			\ 	{								\ 	  offset = XEXP (addr, 1);					\ 	  addr = XEXP (addr, 0);					\ 	}								\       if (GET_CODE (addr) != PLUS) ;					\       else if (GET_CODE (XEXP (addr, 0)) == SIGN_EXTEND)		\ 	{								\ 	  reg1 = XEXP (addr, 0);					\ 	  addr = XEXP (addr, 1);					\ 	}								\       else if (GET_CODE (XEXP (addr, 1)) == SIGN_EXTEND)		\ 	{								\ 	  reg1 = XEXP (addr, 1);					\ 	  addr = XEXP (addr, 0);					\ 	}								\       else if (GET_CODE (XEXP (addr, 0)) == MULT)			\ 	{								\ 	  reg1 = XEXP (addr, 0);					\ 	  addr = XEXP (addr, 1);					\ 	}								\       else if (GET_CODE (XEXP (addr, 1)) == MULT)			\ 	{								\ 	  reg1 = XEXP (addr, 1);					\ 	  addr = XEXP (addr, 0);					\ 	}								\       else if (GET_CODE (XEXP (addr, 0)) == REG)			\ 	{								\ 	  reg1 = XEXP (addr, 0);					\ 	  addr = XEXP (addr, 1);					\ 	}								\       else if (GET_CODE (XEXP (addr, 1)) == REG)			\ 	{								\ 	  reg1 = XEXP (addr, 1);					\ 	  addr = XEXP (addr, 0);					\ 	}								\       if (GET_CODE (addr) == REG || GET_CODE (addr) == MULT		\ 	  || GET_CODE (addr) == SIGN_EXTEND)				\ 	{ if (reg1 == 0) reg1 = addr; else reg2 = addr; addr = 0; }	\
comment|/*  for OLD_INDEXING							\       else if (GET_CODE (addr) == PLUS)					\ 	{								\ 	  if (GET_CODE (XEXP (addr, 0)) == REG)				\ 	    {								\ 	      reg2 = XEXP (addr, 0);					\ 	      addr = XEXP (addr, 1);					\ 	    }								\ 	  else if (GET_CODE (XEXP (addr, 1)) == REG)			\ 	    {								\ 	      reg2 = XEXP (addr, 1);					\ 	      addr = XEXP (addr, 0);					\ 	    }								\ 	}								\   */
value|\       if (offset != 0) { if (addr != 0) abort (); addr = offset; }	\       if ((reg1&& (GET_CODE (reg1) == SIGN_EXTEND			\ 		    || GET_CODE (reg1) == MULT))			\ 	  || (reg2 != 0&& REGNO_OK_FOR_BASE_P (REGNO (reg2))))		\ 	{ breg = reg2; ireg = reg1; }					\       else if (reg1 != 0&& REGNO_OK_FOR_BASE_P (REGNO (reg1)))		\ 	{ breg = reg1; ireg = reg2; }					\       if (ireg != 0&& breg == 0&& GET_CODE (addr) == LABEL_REF)	\         { int scale = 1;						\ 	  if (GET_CODE (ireg) == MULT)					\ 	    { scale = INTVAL (XEXP (ireg, 1));				\ 	      ireg = XEXP (ireg, 0); }					\ 	  if (GET_CODE (ireg) == SIGN_EXTEND)				\ 	    fprintf (FILE, "LD%%%d(%%pc,%s.w",				\ 		     CODE_LABEL_NUMBER (XEXP (addr, 0)),		\ 		     reg_names[REGNO (XEXP (ireg, 0))]); 		\ 	  else								\ 	    fprintf (FILE, "LD%%%d(%%pc,%s.l",				\ 		     CODE_LABEL_NUMBER (XEXP (addr, 0)),		\ 		     reg_names[REGNO (ireg)]);				\ 	  if (scale != 1) fprintf (FILE, "*%d", scale);			\ 	  fprintf (FILE, ")");						\ 	  break; }							\       if (breg != 0&& ireg == 0&& GET_CODE (addr) == LABEL_REF)	\         { fprintf (FILE, "LD%%%d(%%pc,%s.l",				\ 		   CODE_LABEL_NUMBER (XEXP (addr, 0)),			\ 		   reg_names[REGNO (breg)]);				\ 	  putc (')', FILE);						\ 	  break; }							\       if (ireg != 0 || breg != 0)					\ 	{ int scale = 1;						\ 	  if (breg == 0)						\ 	    abort ();							\ 	  if (addr != 0)						\ 	    output_addr_const (FILE, addr);				\ 	  fprintf (FILE, "(%s", reg_names[REGNO (breg)]);		\ 	  if (ireg != 0)					        \ 	    putc (',', FILE);						\ 	  if (ireg != 0&& GET_CODE (ireg) == MULT)			\ 	    { scale = INTVAL (XEXP (ireg, 1));				\ 	      ireg = XEXP (ireg, 0); }					\ 	  if (ireg != 0&& GET_CODE (ireg) == SIGN_EXTEND)		\ 	    fprintf (FILE, "%s.w", reg_names[REGNO (XEXP (ireg, 0))]);	\ 	  else if (ireg != 0)						\ 	    fprintf (FILE, "%s.l", reg_names[REGNO (ireg)]);		\ 	  if (scale != 1) fprintf (FILE, "*%d", scale);			\ 	  putc (')', FILE);						\ 	  break;							\ 	}								\       else if (reg1 != 0&& GET_CODE (addr) == LABEL_REF)		\ 	{ fprintf (FILE, "LD%%%d(%%pc,%s.w)",				\ 		   CODE_LABEL_NUMBER (XEXP (addr, 0)),			\ 		   reg_names[REGNO (reg1)]);				\ 	  break; }							\     default:								\       if (GET_CODE (addr) == CONST_INT					\&& INTVAL (addr)< 0x8000					\&& INTVAL (addr)>= -0x8000)					\ 	fprintf (FILE, "%d", INTVAL (addr));				\       else								\         output_addr_const (FILE, addr);					\     }}
end_define

begin_define
define|#
directive|define
name|ASM_GENERATE_INTERNAL_LABEL
parameter_list|(
name|LABEL
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|sprintf ((LABEL), "%s%%%d", (PREFIX), (NUM))
end_define

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
value|fprintf (FILE, "%s%%%d:\n", PREFIX, NUM)
end_define

begin_comment
comment|/* Must put address in  %a0 , not  %d0 . -- LGM, 7/15/88 */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABEL_NO
parameter_list|)
define|\
value|fprintf (FILE, "\tmov.l&LP%%%d,%%a0\n\tjsr mcount\n", (LABEL_NO))
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_VEC_ELT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|fprintf (FILE, "\tlong L%%%d\n", (VALUE))
end_define

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
value|fprintf (FILE, "\tshort L%%%d-L%%%d\n", (VALUE), (REL))
end_define

begin_comment
comment|/* ihnp4!lmayk!lgm says that `short 0' triggers assembler bug;    `short L%nn-L%nn' supposedly works.  */
end_comment

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
value|if (! RTX_INTEGRATED_P (TABLE))					\     fprintf (FILE, "\tswbeg&%d\n%s%%%d:\n",				\ 	     XVECLEN (PATTERN (TABLE), 1), (PREFIX), (NUM));		\   else									\     fprintf (FILE, "\tswbeg&%d\n%s%%%d:\n\tshort %s%%%d-%s%%%d\n",	\ 	     XVECLEN (PATTERN (TABLE), 1) + 1, (PREFIX), (NUM),		\ 	     (PREFIX), (NUM), (PREFIX), (NUM))
end_define

begin_comment
comment|/* At end of a switch table, define LDnnn iff the symbol LInnn was defined.    Some SGS assemblers have a bug such that "Lnnn-LInnn-2.b(pc,d0.l*2)"    fails to assemble.  Luckily "LDnnn(pc,d0.l*2)" produces the results    we want.  This difference can be accommodated by making the assembler    define such "LDnnn" to be either "Lnnn-LInnn-2.b", "Lnnn", or any other    string, as necessary.  This is accomplished via the ASM_OUTPUT_CASE_END    macro. */
end_comment

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
value|{ if (switch_table_difference_label_flag)				\     fprintf (FILE, "\tset LD%%%d,L%%%d-LI%%%d\n", (NUM), (NUM), (NUM))	\   switch_table_difference_label_flag = 0; }
end_define

begin_decl_stmt
name|int
name|switch_table_difference_label_flag
decl_stmt|;
end_decl_stmt

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
value|{ if ((PTR)[0] == 'j'&& (PTR)[1] == 'b')		\     { ++(PTR);						\       while (*(PTR) != ' ')				\ 	{ putc (*(PTR), (FILE)); ++(PTR); }		\       fprintf ((FILE), ".w"); }				\   else if ((PTR)[0] == 's')				\     {							\       if (!strncmp ((PTR), "swap", 4))			\ 	{ fprintf ((FILE), "swap.w"); (PTR) += 4; }	\     }							\   else if ((PTR)[0] == 'f')				\     {							\       if (!strncmp ((PTR), "fmove", 5))			\ 	{ fprintf ((FILE), "fmov"); (PTR) += 5; }	\       else if (!strncmp ((PTR), "fbne", 4))		\ 	{ fprintf ((FILE), "fbneq"); (PTR) += 4; }	\     }							\
comment|/* MOVE, MOVEA, MOVEQ, MOVEC ==> MOV	*/
value|\   else if ((PTR)[0] == 'm'&& (PTR)[1] == 'o'		\&& (PTR)[2] == 'v'&& (PTR)[3] == 'e')	\     { fprintf ((FILE), "mov"); (PTR) += 4;		\        if ((PTR)[0] == 'q' || (PTR)[0] == 'a'		\ 	   || (PTR)[0] == 'c') (PTR)++; }		\
comment|/* SUB, SUBQ, SUBA, SUBI ==> SUB */
value|\   else if ((PTR)[0] == 's'&& (PTR)[1] == 'u' 		\&& (PTR)[2] == 'b')				\     { fprintf ((FILE), "sub"); (PTR) += 3;		\        if ((PTR)[0] == 'q' || (PTR)[0] == 'i'	 	\ 	   || (PTR)[0] == 'a') (PTR)++; }		\
comment|/* CMP, CMPA, CMPI, CMPM ==> CMP	*/
value|\   else if ((PTR)[0] == 'c'&& (PTR)[1] == 'm'		\&& (PTR)[2] == 'p')				\     { fprintf ((FILE), "cmp"); (PTR) += 3;		\        if ((PTR)[0] == 'a' || (PTR)[0] == 'i'	 	\ 	   || (PTR)[0] == 'm') (PTR)++; }		\ }
end_define

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
value|( fputs ("\tlcomm ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%u\n", (ROUNDED)))
end_define

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
value|fprintf (FILE, "%s", NAME)
end_define

begin_escape
end_escape

begin_comment
comment|/* Override usual definitions of SDB output macros.    These definitions differ only in the absence of the period    at the beginning of the name of the directive    and in the use of `~' as the symbol for the current location.  */
end_comment

begin_define
define|#
directive|define
name|PUT_SDB_SCL
parameter_list|(
name|a
parameter_list|)
value|fprintf(asm_out_file, "\tscl\t%d;", (a))
end_define

begin_define
define|#
directive|define
name|PUT_SDB_INT_VAL
parameter_list|(
name|a
parameter_list|)
value|fprintf (asm_out_file, "\tval\t%d;", (a))
end_define

begin_define
define|#
directive|define
name|PUT_SDB_VAL
parameter_list|(
name|a
parameter_list|)
define|\
value|( fputs ("\tval\t", asm_out_file),		\   output_addr_const (asm_out_file, (a)),	\   fputc (';', asm_out_file))
end_define

begin_define
define|#
directive|define
name|PUT_SDB_DEF
parameter_list|(
name|a
parameter_list|)
define|\
value|do { fprintf (asm_out_file, "\tdef\t");	\      ASM_OUTPUT_LABELREF (asm_out_file, a); 	\      fprintf (asm_out_file, ";"); } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_PLAIN_DEF
parameter_list|(
name|a
parameter_list|)
value|fprintf(asm_out_file,"\tdef\t~%s;",a)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_ENDEF
value|fputs("\tendef\n", asm_out_file)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_TYPE
parameter_list|(
name|a
parameter_list|)
value|fprintf(asm_out_file, "\ttype\t0%o;", a)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_SIZE
parameter_list|(
name|a
parameter_list|)
value|fprintf(asm_out_file, "\tsize\t%d;", a)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_START_DIM
value|fprintf(asm_out_file, "\tdim\t")
end_define

begin_define
define|#
directive|define
name|PUT_SDB_TAG
parameter_list|(
name|a
parameter_list|)
define|\
value|do { fprintf (asm_out_file, "\ttag\t");	\      ASM_OUTPUT_LABELREF (asm_out_file, a);	\      fprintf (asm_out_file, ";"); } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_BLOCK_START
parameter_list|(
name|LINE
parameter_list|)
define|\
value|fprintf (asm_out_file,			\ 	   "\tdef\t~bb;\tval\t~;\tscl\t100;\tline\t%d;\tendef\n",	\ 	   (LINE))
end_define

begin_define
define|#
directive|define
name|PUT_SDB_BLOCK_END
parameter_list|(
name|LINE
parameter_list|)
define|\
value|fprintf (asm_out_file,			\ 	   "\tdef\t~eb;\tval\t~;\tscl\t100;\tline\t%d;\tendef\n",	\ 	   (LINE))
end_define

begin_define
define|#
directive|define
name|PUT_SDB_FUNCTION_START
parameter_list|(
name|LINE
parameter_list|)
define|\
value|fprintf (asm_out_file,			\ 	   "\tdef\t~bf;\tval\t~;\tscl\t101;\tline\t%d;\tendef\n",	\ 	   (LINE))
end_define

begin_define
define|#
directive|define
name|PUT_SDB_FUNCTION_END
parameter_list|(
name|LINE
parameter_list|)
define|\
value|fprintf (asm_out_file,			\ 	   "\tdef\t~ef;\tval\t~;\tscl\t101;\tline\t%d;\tendef\n",	\ 	   (LINE))
end_define

begin_define
define|#
directive|define
name|PUT_SDB_EPILOGUE_END
parameter_list|(
name|NAME
parameter_list|)
define|\
value|fprintf (asm_out_file,			\ 	   "\tdef\t%s;\tval\t~;\tscl\t-1;\tendef\n",	\ 	   (NAME))
end_define

begin_define
define|#
directive|define
name|SDB_GENERATE_FAKE
parameter_list|(
name|BUFFER
parameter_list|,
name|NUMBER
parameter_list|)
define|\
value|sprintf ((BUFFER), "~%dfake", (NUMBER));
end_define

begin_comment
comment|/* Define subroutines to call to handle multiply, divide, and remainder.    Use the subroutines that the 3b1's library provides.    The `*' prevents an underscore from being prepended by the compiler.  */
end_comment

begin_define
define|#
directive|define
name|DIVSI3_LIBCALL
value|"*ldiv"
end_define

begin_define
define|#
directive|define
name|UDIVSI3_LIBCALL
value|"*uldiv"
end_define

begin_define
define|#
directive|define
name|MODSI3_LIBCALL
value|"*lrem"
end_define

begin_define
define|#
directive|define
name|UMODSI3_LIBCALL
value|"*ulrem"
end_define

begin_define
define|#
directive|define
name|MULSI3_LIBCALL
value|"*lmul"
end_define

begin_define
define|#
directive|define
name|UMULSI3_LIBCALL
value|"*ulmul"
end_define

end_unit

