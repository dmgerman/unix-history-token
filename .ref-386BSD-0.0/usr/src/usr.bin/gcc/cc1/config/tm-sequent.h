begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  SEQUENT NS32000 version.    Copyright (C) 1987 Free Software Foundation, Inc.    Contributed by Michael Tiemann (tiemann@mcc.com)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Two flags to control how addresses are printed in assembler insns.  */
end_comment

begin_define
define|#
directive|define
name|SEQUENT_ADDRESS_BUG
value|1
end_define

begin_define
define|#
directive|define
name|SEQUENT_BASE_REGS
end_define

begin_include
include|#
directive|include
file|"tm-ns32k.h"
end_include

begin_comment
comment|/* This is BSD, so it wants DBX format.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
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

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|1
end_define

begin_comment
comment|/* Print subsidiary information on the compiler version in use.  */
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
value|fprintf (stderr, " (32000, Sequent syntax)");
end_define

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dns32000 -Dsequent -Dunix"
end_define

begin_comment
comment|/* This is how to align the code that follows an unconditional branch.    Don't define it, since it confuses the assembler (we hear).  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGN_CODE
end_undef

begin_comment
comment|/* Assember pseudo-op for shared data segment. */
end_comment

begin_define
define|#
directive|define
name|SHARED_SECTION_ASM_OP
value|".shdata"
end_define

begin_comment
comment|/* Control how stack adjust insns are output.  */
end_comment

begin_define
define|#
directive|define
name|SEQUENT_ADJUST_STACK
end_define

begin_comment
comment|/* %$ means print the prefix for an immediate operand.    On the sequent, no prefix is used for such.  */
end_comment

begin_undef
undef|#
directive|undef
name|PRINT_OPERAND
end_undef

begin_define
define|#
directive|define
name|PRINT_OPERAND
parameter_list|(
name|FILE
parameter_list|,
name|X
parameter_list|,
name|CODE
parameter_list|)
define|\
value|{ if (CODE == '$') ;							\   else if (CODE == '?');						\   else if (GET_CODE (X) == REG)						\     fprintf (FILE, "%s", reg_names[REGNO (X)]);				\   else if (GET_CODE (X) == MEM)						\     {									\       rtx xfoo;								\       xfoo = XEXP (X, 0);						\       switch (GET_CODE (xfoo))						\ 	{								\ 	case MEM:							\ 	  if (GET_CODE (XEXP (xfoo, 0)) == REG)				\ 	    if (REGNO (XEXP (xfoo, 0)) == STACK_POINTER_REGNUM)		\ 	      fprintf (FILE, "0(0(sp))");				\ 	    else fprintf (FILE, "0(0(%s))",				\ 			  reg_names[REGNO (XEXP (xfoo, 0))]);		\ 	  else								\ 	    {								\ 	      fprintf (FILE, "0(");					\ 	      output_address (xfoo);					\ 	      putc (')', FILE);						\ 	    }								\ 	  break;							\ 	case REG:							\ 	  fprintf (FILE, "0(%s)", reg_names[REGNO (xfoo)]);		\ 	  break;							\ 	case PRE_DEC:							\ 	case POST_INC:							\ 	  fprintf (FILE, "tos");					\ 	  break;							\ 	case CONST_INT:							\ 	  fprintf (FILE, "@%d", INTVAL (xfoo));				\ 	  break;							\ 	default:							\ 	  output_address (xfoo);					\ 	  break;							\ 	}								\     }									\   else if (GET_CODE (X) == CONST_DOUBLE&& GET_MODE (X) != DImode)	\     if (GET_MODE (X) == DFmode)						\       { union { double d; int i[2]; } u;				\ 	u.i[0] = CONST_DOUBLE_LOW (X); u.i[1] = CONST_DOUBLE_HIGH (X);	\ 	fprintf (FILE, "0d%.20e", u.d); }				\     else { union { double d; int i[2]; } u;				\ 	   u.i[0] = CONST_DOUBLE_LOW (X); u.i[1] = CONST_DOUBLE_HIGH (X); \ 	   fprintf (FILE, "0f%.20e", u.d); }				\   else output_addr_const (FILE, X); }
end_define

begin_undef
undef|#
directive|undef
name|PRINT_OPERAND_ADDRESS
end_undef

begin_define
define|#
directive|define
name|PRINT_OPERAND_ADDRESS
parameter_list|(
name|FILE
parameter_list|,
name|ADDR
parameter_list|)
value|print_operand_address(FILE, ADDR)
end_define

end_unit

