begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 running system V with gnu tools    Copyright (C) 1988 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"tm-i386.h"
end_include

begin_comment
comment|/* Use the bsd assembler syntax.  */
end_comment

begin_comment
comment|/* we need to do this because gas is really a bsd style assembler,  * and so doesn't work well this these att-isms:  *  *  ASM_OUTPUT_SKIP is .set .,.+N, which isn't implemented in gas  *  ASM_OUTPUT_LOCAL is done with .set .,.+N, but that can't be  *   used to define bss static space  *  * Next is the question of whether to uses underscores.  RMS didn't  * like this idea at first, but since it is now obvious that we  * need this separate tm file for use with gas, at least to get  * dbx debugging info, I think we should also switch to underscores.  * We can keep tm-i386v for real att style output, and the few  * people who want both form will have to compile twice.  */
end_comment

begin_include
include|#
directive|include
file|"tm-bsd386.h"
end_include

begin_comment
comment|/* these come from tm-bsd386.h, but are specific to sequent */
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
comment|/* By default, target has a 80387.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|1
end_define

begin_comment
comment|/* Specify predefined symbols in preprocessor.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Di386"
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
comment|/* We do not want to output SDB debugging information.  */
end_comment

begin_undef
undef|#
directive|undef
name|SDB_DEBUGGING_INFO
end_undef

begin_comment
comment|/* We want to output DBX debugging information.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_comment
comment|/* Implicit library calls should use memcpy, not bcopy, etc.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* People say gas uses the log as the arg to .align.  */
end_comment

begin_comment
comment|/* When using gas, .align N aligns to an N-byte boundary.  */
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
value|if ((LOG)!=0) fprintf ((FILE), "\t.align %d\n", 1<<(LOG))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Align labels, etc. at 4-byte boundaries.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN_CODE
parameter_list|(
name|FILE
parameter_list|)
define|\
value|fprintf ((FILE), "\t.align 2\n");
end_define

begin_comment
comment|/* Use log of 4 as arg.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN_CODE
parameter_list|(
name|FILE
parameter_list|)
define|\
value|fprintf ((FILE), "\t.align 4\n");
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Machines that use the AT&T assembler syntax    also return floating point values in an FP register.  */
end_comment

begin_comment
comment|/* Define how to find the value returned by a function.    VALTYPE is the data type of the value (as a tree).    If the precise function being called is known, FUNC is its FUNCTION_DECL;    otherwise, FUNC is 0.  */
end_comment

begin_define
define|#
directive|define
name|VALUE_REGNO
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(((MODE)==SFmode || (MODE)==DFmode) ? FIRST_FLOAT_REG : 0)
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
value|((N) == 0 || (N)== FIRST_FLOAT_REG)
end_define

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
value|fprintf (FILE, "\t.file\t\"%s\"\n", dump_base_name);
end_define

end_unit

