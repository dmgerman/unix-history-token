begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 using GAS.    Copyright (C) 1988, 1993, 1994, 1996 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Note that i386/seq-gas.h is a GAS configuration that does not use this    file. */
end_comment

begin_include
include|#
directive|include
file|"i386/i386.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|YES_UNDERSCORES
end_ifndef

begin_comment
comment|/* Define this now, because i386/bsd.h tests it.  */
end_comment

begin_define
define|#
directive|define
name|NO_UNDERSCORES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Use the bsd assembler syntax.  */
end_comment

begin_comment
comment|/* we need to do this because gas is really a bsd style assembler,  * and so doesn't work well this these att-isms:  *  *  ASM_OUTPUT_SKIP is .set .,.+N, which isn't implemented in gas  *  ASM_OUTPUT_LOCAL is done with .set .,.+N, but that can't be  *   used to define bss static space  *  * Next is the question of whether to uses underscores.  RMS didn't  * like this idea at first, but since it is now obvious that we  * need this separate tm file for use with gas, at least to get  * dbx debugging info, I think we should also switch to underscores.  * We can keep i386v for real att style output, and the few  * people who want both form will have to compile twice.  */
end_comment

begin_include
include|#
directive|include
file|"i386/bsd.h"
end_include

begin_comment
comment|/* these come from i386/bsd.h, but are specific to sequent */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_NO_XREFS
end_undef

begin_undef
undef|#
directive|undef
name|DBX_CONTIN_LENGTH
end_undef

begin_comment
comment|/* Ask for COFF symbols.  */
end_comment

begin_define
define|#
directive|define
name|SDB_DEBUGGING_INFO
end_define

begin_comment
comment|/* Specify predefined symbols in preprocessor.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix"
end_define

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%(cpp_cpu) %{posix:-D_POSIX_SOURCE}"
end_define

begin_comment
comment|/* Allow #sccs in preprocessor.  */
end_comment

begin_define
define|#
directive|define
name|SCCS_DIRECTIVE
end_define

begin_comment
comment|/* Output #ident as a .ident.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_IDENT
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
value|fprintf (FILE, "\t.ident \"%s\"\n", NAME);
end_define

begin_comment
comment|/* Implicit library calls should use memcpy, not bcopy, etc.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_comment
comment|/* In the past there was confusion as to what the argument to .align was    in GAS.  For the last several years the rule has been this: for a.out    file formats that argument is LOG, and for all other file formats the    argument is 1<<LOG.     However, GAS now has .p2align and .balign pseudo-ops so to remove any    doubt or guess work, and since this file is used for both a.out and other    file formats, we use one of them.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GAS_BALIGN_AND_P2ALIGN
end_ifdef

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
value|if ((LOG)!=0) fprintf ((FILE), "\t.balign %d\n", 1<<(LOG))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A C statement to output to the stdio stream FILE an assembler    command to advance the location counter to a multiple of 1<<LOG    bytes if it is within MAX_SKIP bytes.     This is used to align code labels according to Intel recommendations.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GAS_MAX_SKIP_P2ALIGN
end_ifdef

begin_define
define|#
directive|define
name|ASM_OUTPUT_MAX_SKIP_ALIGN
parameter_list|(
name|FILE
parameter_list|,
name|LOG
parameter_list|,
name|MAX_SKIP
parameter_list|)
define|\
value|if ((LOG) != 0) {\        if ((MAX_SKIP) == 0) fprintf ((FILE), "\t.p2align %d\n", (LOG)); \        else fprintf ((FILE), "\t.p2align %d,,%d\n", (LOG), (MAX_SKIP)); \      }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* A C statement or statements which output an assembler instruction    opcode to the stdio stream STREAM.  The macro-operand PTR is a    variable of type `char *' which points to the opcode name in its    "internal" form--the form that is written in the machine description.     GAS version 1.38.1 doesn't understand the `repz' opcode mnemonic.    So use `repe' instead.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_OPCODE
parameter_list|(
name|STREAM
parameter_list|,
name|PTR
parameter_list|)
define|\
value|{									\   if ((PTR)[0] == 'r'							\&& (PTR)[1] == 'e'						\&& (PTR)[2] == 'p')						\     {									\       if ((PTR)[3] == 'z')						\ 	{								\ 	  fprintf (STREAM, "repe");					\ 	  (PTR) += 4;							\ 	}								\       else if ((PTR)[3] == 'n'&& (PTR)[4] == 'z')			\ 	{								\ 	  fprintf (STREAM, "repne");					\ 	  (PTR) += 5;							\ 	}								\     }									\ }
end_define

begin_comment
comment|/* Define macro used to output shift-double opcodes when the shift    count is in %cl.  Some assemblers require %cl as an argument;    some don't.     GAS requires the %cl argument, so override i386/unix.h. */
end_comment

begin_undef
undef|#
directive|undef
name|SHIFT_DOUBLE_OMITS_COUNT
end_undef

begin_define
define|#
directive|define
name|SHIFT_DOUBLE_OMITS_COUNT
value|0
end_define

begin_comment
comment|/* Print opcodes the way that GAS expects them. */
end_comment

begin_define
define|#
directive|define
name|GAS_MNEMONICS
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NO_UNDERSCORES
end_ifdef

begin_comment
comment|/* If user-symbols don't have underscores, 			 then it must take more than `L' to identify 			 a label that should be ignored.  */
end_comment

begin_comment
comment|/* This is how to store into the string BUF    the symbol_ref name of an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.    This is suitable for output with `assemble_name'.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_GENERATE_INTERNAL_LABEL
end_undef

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
value|sprintf ((BUF), ".%s%d", (PREFIX), (NUMBER))
end_define

begin_comment
comment|/* This is how to output an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_INTERNAL_LABEL
end_undef

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
value|fprintf (FILE, ".%s%d:\n", PREFIX, NUM)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NO_UNDERSCORES */
end_comment

end_unit

