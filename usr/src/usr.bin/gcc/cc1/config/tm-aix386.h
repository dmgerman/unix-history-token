begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for IBM PS2 running AIX/386.    From: Minh Tran-Le<TRANLE@intellicorp.com>    Copyright (C) 1988 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"tm-i386.h"
end_include

begin_comment
comment|/* Use the ATT assembler syntax.  */
end_comment

begin_include
include|#
directive|include
file|"tm-att386.h"
end_include

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
comment|/* Use crt1.o as a startup file and crtn.o as a closing file.  */
end_comment

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{pg:gcrt1.o%s}%{!pg:%{p:mcrt1.o%s}%{!p:crt1.o%s}}"
end_define

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{p:-L/usr/lib/libp}%{pg:-L/usr/lib/libp} -lc crtn.o%s"
end_define

begin_comment
comment|/* Special flags for the linker.  I don't know what they do.  */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{!K:-K} %{!T*:-T0x00400000} %{z:-lm}"
end_define

begin_comment
comment|/* Specify predefined symbols in preprocessor.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-D_I386 -Di386 -DAIX -D_AIX"
end_define

begin_comment
comment|/* special flags for the aix assembler to generate the short form for all    qualifying forward reference */
end_comment

begin_define
define|#
directive|define
name|ASM_SPEC
value|"-s2"
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
value|do { fprintf (FILE, "\t.file\t\"%s\"\n", dump_base_name);	\      } while (0)
end_define

begin_comment
comment|/* This used to output .noopt if nonoptimizing and run ASM_FILE_START_1    if optimizing, but that loses with the AIX assembler.  */
end_comment

begin_comment
comment|/* This was suggested, but it shouldn't be right for DBX output. -- RMS    #define ASM_OUTPUT_SOURCE_FILENAME(FILE, NAME) */
end_comment

begin_comment
comment|/* We want to output SDB debugging information. */
end_comment

begin_define
define|#
directive|define
name|SDB_DEBUGGING_INFO
end_define

begin_comment
comment|/* We don't want to output DBX debugging information. Becaus IBM AIX dbx    use COFF format */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_DEBUGGING_INFO
end_undef

begin_comment
comment|/* Implicit library calls should use memcpy, not bcopy, etc.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_comment
comment|/* Writing `int' for a bitfield forces int alignment for the structure.  */
end_comment

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
value|1
end_define

begin_comment
comment|/* Don't write a `.optim' pseudo; this assembler    is said to have a bug when .optim is used.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_undef
undef|#
directive|undef
name|ASM_FILE_START_1
end_undef

begin_define
define|#
directive|define
name|ASM_FILE_START_1
parameter_list|(
name|FILE
parameter_list|)
value|fprintf (FILE, "\t.noopt\n");
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

begin_comment
comment|/* Output assembler code to FILE to increment profiler label # LABELNO    for profiling a function entry.  */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_PROFILER
end_undef

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|fprintf (FILE, "\tleal %sP%d,%%eax\n\tcall mcount\n", LPREFIX, (LABELNO));
end_define

end_unit

