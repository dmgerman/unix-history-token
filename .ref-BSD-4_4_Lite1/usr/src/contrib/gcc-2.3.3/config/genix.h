begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  Genix ns32000 version.    Copyright (C) 1987, 1988 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"encore.h"
end_include

begin_comment
comment|/* We don't want the one Encore needs.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_comment
comment|/* The following defines override ones in ns32k.h and prevent any attempts    to explicitly or implicitly make references to the SB register in the GCC    generated code.  It is necessary to avoid such references under Genix V.3.1    because this OS doesn't even save/restore the SB on context switches!  */
end_comment

begin_define
define|#
directive|define
name|IS_OK_REG_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
define|\
value|( (GET_CODE (X) == REG)&& REG_OK_FOR_BASE_P (X) )
end_define

begin_undef
undef|#
directive|undef
name|INDIRECTABLE_1_ADDRESS_P
end_undef

begin_define
define|#
directive|define
name|INDIRECTABLE_1_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(CONSTANT_ADDRESS_NO_LABEL_P (X)					\    || IS_OK_REG_FOR_BASE_P (X)						\    || (GET_CODE (X) == PLUS						\&& IS_OK_REG_FOR_BASE_P (XEXP (X, 0))				\&& CONSTANT_ADDRESS_P (XEXP (X, 1))  )  )
end_define

begin_comment
comment|/* Note that for double indirects, only FP, SP, and SB are allowed    as the inner-most base register.  But we are avoiding use of SB.  */
end_comment

begin_undef
undef|#
directive|undef
name|MEM_REG
end_undef

begin_define
define|#
directive|define
name|MEM_REG
parameter_list|(
name|X
parameter_list|)
define|\
value|( (GET_CODE (X) == REG)						\&& ( (REGNO (X) == FRAME_POINTER_REGNUM)				\     || (REGNO (X) == STACK_POINTER_REGNUM) ) )
end_define

begin_undef
undef|#
directive|undef
name|INDIRECTABLE_2_ADDRESS_P
end_undef

begin_define
define|#
directive|define
name|INDIRECTABLE_2_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == MEM							\&& (((xfoo0 = XEXP (X, 0), MEM_REG (xfoo0))				\        || (GET_CODE (xfoo0) == PLUS					\&& MEM_REG (XEXP (xfoo0, 0))					\&& CONSTANT_ADDRESS_NO_LABEL_P (XEXP (xfoo0, 1))))		\        || CONSTANT_ADDRESS_NO_LABEL_P (xfoo0)))
end_define

begin_comment
comment|/* Go to ADDR if X is a valid address not using indexing.    (This much is the easy part.)  */
end_comment

begin_undef
undef|#
directive|undef
name|GO_IF_NONINDEXED_ADDRESS
end_undef

begin_define
define|#
directive|define
name|GO_IF_NONINDEXED_ADDRESS
parameter_list|(
name|X
parameter_list|,
name|ADDR
parameter_list|)
define|\
value|{ register rtx xfoob = (X);						\   if (GET_CODE (xfoob) == REG) goto ADDR;				\   if (INDIRECTABLE_1_ADDRESS_P(X)) goto ADDR;				\   if (CONSTANT_P(X)) goto ADDR;						\   if (INDIRECTABLE_2_ADDRESS_P (X)) goto ADDR;				\   if (GET_CODE (X) == PLUS)						\     if (CONSTANT_ADDRESS_NO_LABEL_P (XEXP (X, 1)))			\       if (INDIRECTABLE_2_ADDRESS_P (XEXP (X, 0)))			\ 	goto ADDR;							\ }
end_define

begin_comment
comment|/* A bug in the GNX 3.X assembler causes references to external symbols to    be mishandled if the symbol is also used as the name of a function-local    variable or as the name of a struct or union field.  The problem only    appears when you are also using the -g option so that SDB debugging    directives are also being produced by GCC.  In such cases, the assembler    gets the external entity confused with the local entity and addressing    havoc ensues.  The solution is to get GCC to produce .global directives    for all external entities which are actually referenced within the current    source file.  The following macro does this.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_EXTERNAL
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|)
define|\
value|ASM_GLOBALIZE_LABEL(FILE,NAME);
end_define

begin_comment
comment|/* Genix wants 0l instead of 0f.  */
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
value|fprintf (FILE, "\t.long 0l%.20e\n", (VALUE))
end_define

begin_comment
comment|/*  A bug in the GNX 3.X linker prevents symbol-table entries with a storage-     class field of C_EFCN (-1) from being accepted. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PUT_SDB_EPILOGUE_END
end_ifdef

begin_undef
undef|#
directive|undef
name|PUT_SDB_EPILOGUE_END
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PUT_SDB_EPILOGUE_END
parameter_list|(
name|NAME
parameter_list|)
end_define

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (32000, National syntax)");
end_define

begin_comment
comment|/* Same as the encore definition except    * Different syntax for double constants.    * Don't output `?' before external regs.    * Output `(sb)' in certain indirect refs.  */
end_comment

begin_error
error|#
directive|error
error|this has not been updated since version 1.
end_error

begin_error
error|#
directive|error
error|it is certainly wrong.
end_error

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
value|{ if (CODE == '$') putc ('$', FILE);					\   else if (CODE == '?');						\   else if (GET_CODE (X) == REG)						\     fprintf (FILE, "%s", reg_names[REGNO (X)]);				\   else if (GET_CODE (X) == MEM)						\     {									\       rtx xfoo;								\       xfoo = XEXP (X, 0);						\       switch (GET_CODE (xfoo))						\ 	{								\ 	case MEM:							\ 	  if (GET_CODE (XEXP (xfoo, 0)) == REG)				\ 	    if (REGNO (XEXP (xfoo, 0)) == STACK_POINTER_REGNUM)		\ 	      fprintf (FILE, "0(0(sp))");				\ 	    else fprintf (FILE, "0(0(%s))",				\ 			  reg_names[REGNO (XEXP (xfoo, 0))]);		\ 	  else								\ 	    {								\ 	      extern int paren_base_reg_printed;			\ 	      fprintf (FILE, "0(");					\ 	      paren_base_reg_printed = 0;				\ 	      output_address (xfoo);					\ 	      if (!paren_base_reg_printed)				\ 		fprintf (FILE, "(sb)");					\ 	      putc (')', FILE);						\ 	    }								\ 	  break;							\ 	case REG:							\ 	  fprintf (FILE, "0(%s)", reg_names[REGNO (xfoo)]);		\ 	  break;							\ 	case PRE_DEC:							\ 	case POST_INC:							\ 	  fprintf (FILE, "tos");					\ 	  break;							\ 	case CONST_INT:							\ 	  fprintf (FILE, "@%d", INTVAL (xfoo));				\ 	  break;							\ 	default:							\ 	  output_address (xfoo);					\ 	  break;							\ 	}								\     }									\   else if (GET_CODE (X) == CONST_DOUBLE&& GET_MODE (X) != DImode)	\     if (GET_MODE (X) == DFmode)						\       { union { double d; int i[2]; } u;				\         u.i[0] = CONST_DOUBLE_LOW (X); u.i[1] = CONST_DOUBLE_HIGH (X);	\ 	fprintf (FILE, "$0l%.20e", u.d); }				\     else { union { double d; int i[2]; } u;				\ 	   u.i[0] = CONST_DOUBLE_LOW (X); u.i[1] = CONST_DOUBLE_HIGH (X); \ 	   fprintf (FILE, "$0f%.20e", u.d); }				\   else if (GET_CODE (X) == CONST)					\     output_addr_const (FILE, X);					\   else { putc ('$', FILE); output_addr_const (FILE, X); }}
end_define

end_unit

