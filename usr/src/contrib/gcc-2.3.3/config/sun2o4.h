begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  Sun 2 running Sunos 4.    Copyright (C) 1987, 1988 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"sun2.h"
end_include

begin_comment
comment|/* Define __HAVE_SKY__ in preprocessor, according to the -m flags.    Also inform the program which CPU this is for.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"int"
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"short unsigned int"
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|16
end_define

begin_if
if|#
directive|if
name|TARGET_DEFAULT
operator|&
literal|0200
end_if

begin_comment
comment|/* -msky is the default */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
define|\
value|"%{!msoft-float:-D__HAVE_SKY__}\ %{!ansi:%{m68020:-Dmc68020}%{mc68020:-Dmc68020}%{!mc68020:%{!m68020:-Dmc68010}}}"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* -msoft-float is the default */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
define|\
value|"%{msky:-D__HAVE_SKY__ }\ %{!ansi:%{m68020:-Dmc68020}%{mc68020:-Dmc68020}%{!mc68020:%{!m68020:-Dmc68010}}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STARTFILE_SPEC to include sun floating point initialization    This is necessary (tr: Sun does it) for the sky routines.    I'm not sure what would happen below if people gave contradictory    arguments (eg. -msoft-float -mfpa) */
end_comment

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_if
if|#
directive|if
name|TARGET_DEFAULT
operator|&
literal|0200
end_if

begin_comment
comment|/* -msky is the default */
end_comment

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}	\    %{msoft-float:Fcrt1.o%s}				\    %{!msoft-float:Scrt1.o%s}"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* -msoft-float is the default */
end_comment

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}	\    %{msky:Scrt1.o%s}					\    %{!msky:Fcrt1.o%s}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Specify library to handle `-a' basic block profiling.    Control choice of libm.a (if user says -lm)    based on fp arith default and options.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_if
if|#
directive|if
name|TARGET_DEFAULT
operator|&
literal|0200
end_if

begin_comment
comment|/* -msky is the default */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p} \ %{a:/usr/lib/bb_link.o -lc} %{g:-lg} \ %{msoft-float:-L/usr/lib/fsoft} \ %{!msoft_float:-L/usr/lib/fsky}"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* -msoft-float is the default */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p} \ %{a:/usr/lib/bb_link.o -lc} %{g:-lg} \ %{!msky:-L/usr/lib/fsoft} \ %{msky:-L/usr/lib/ffpa}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
define|\
value|"%{!nostdlib:%{!r*:%{!e*:-e start}}} -dc -dp %{static:-Bstatic}"
end_define

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
value|(REAL_VALUE_ISINF ((VALUE))						\    ? fprintf (FILE, "\t.double 0r%s99e999\n", ((VALUE)> 0 ? "" : "-")) \    : REAL_VALUE_MINUS_ZERO ((VALUE))					\    ? fprintf (FILE, "\t.long 0x80000000,0\n")				\    : fprintf (FILE, "\t.double 0r%.20e\n", (VALUE)))
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
value|(REAL_VALUE_ISINF ((VALUE))						\    ? fprintf (FILE, "\t.single 0r%s99e999\n", ((VALUE)> 0 ? "" : "-")) \    : REAL_VALUE_MINUS_ZERO ((VALUE))					\    ? fprintf (FILE, "\t.long 0x80000000\n")				\    : fprintf (FILE, "\t.single 0r%.20e\n", (VALUE)))
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_FLOAT_OPERAND
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_FLOAT_OPERAND
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|(REAL_VALUE_ISINF ((VALUE))						\    ? fprintf (FILE, "#0r%s99e999", ((VALUE)> 0 ? "" : "-")) 		\    : REAL_VALUE_MINUS_ZERO ((VALUE))					\    ? fprintf (FILE, "#0r-0.0")						\    : fprintf (FILE, "#0r%.9g", (VALUE)))
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
value|(REAL_VALUE_ISINF ((VALUE))						\    ? fprintf (FILE, "#0r%s99e999", ((VALUE)> 0 ? "" : "-"))		\    : REAL_VALUE_MINUS_ZERO ((VALUE))					\    ? fprintf (FILE, "#0r-0.0")						\    : fprintf (FILE, "#0r%.20g", (VALUE)))
end_define

end_unit

