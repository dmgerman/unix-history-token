begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 running SunOS 4.0.    Copyright (C) 1988 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"tm-i386.h"
end_include

begin_comment
comment|/* Use the Sun assembler syntax.  */
end_comment

begin_include
include|#
directive|include
file|"tm-sun386.h"
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
comment|/* Use crt0.o as a startup file.  */
end_comment

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}"
end_define

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p}\ %{sun386:}"
end_define

begin_comment
comment|/* That last item is just to prevent a spurious error.  */
end_comment

begin_comment
comment|/* It is hard to debug with shared libraries,    so don't use them if going to debug.  */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{g:-Bstatic} %{static:-Bstatic} %{Bstatic}"
end_define

begin_comment
comment|/* Extra switches to give the assembler.  */
end_comment

begin_define
define|#
directive|define
name|ASM_SPEC
value|"-i386"
end_define

begin_comment
comment|/* Specify predefined symbols in preprocessor.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Di386 -Dsun386 -Dsun"
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
comment|/* We don't want to output SDB debugging information.  */
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

begin_comment
comment|/* Force structure alignment to the type used for a bitfield.  */
end_comment

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
end_define

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
comment|/* This is partly guess.  */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_REGISTER_NUMBER
end_undef

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|n
parameter_list|)
define|\
value|((n) == 0 ? 11 : (n)  == 1 ? 9 : (n) == 2 ? 10 : (n) == 3 ? 8	\    : (n) == 4 ? 5 : (n) == 5 ? 4 : (n) == 6 ? 6 : (n))
end_define

begin_comment
comment|/* Every debugger symbol must be in the text section.    Otherwise the assembler or the linker screws up.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_SYMS_TEXT
end_define

begin_comment
comment|/* This NOP insn makes profiling not fail.  */
end_comment

begin_define
define|#
directive|define
name|ASM_IDENTIFY_GCC
parameter_list|(
name|FILE
parameter_list|)
define|\
value|fprintf (FILE, (profile_flag ? "gcc_compiled.:\n\tnop\n" : "gcc_compiled.:\n"))
end_define

end_unit

