begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  Sun 68000/68020 version.    Copyright (C) 1987, 1988 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* This comment is here to see if it will keep Sun's cpp from dying.  */
end_comment

begin_comment
comment|/* If you do not need to generate floating point code for the optional    Sun FPA board, you can safely comment out the SUPPORT_SUN_FPA define    to gain a little speed and code size.  */
end_comment

begin_define
define|#
directive|define
name|SUPPORT_SUN_FPA
end_define

begin_include
include|#
directive|include
file|"m68k.h"
end_include

begin_comment
comment|/* See m68k.h.  7 means 68020 with 68881.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define __HAVE_FPA__ or __HAVE_68881__ in preprocessor,    according to the -m flags.    This will control the use of inline 68881 insns in certain macros.    Also inform the program which CPU this is for.  */
end_comment

begin_if
if|#
directive|if
name|TARGET_DEFAULT
operator|&
literal|02
end_if

begin_comment
comment|/* -m68881 is the default */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
define|\
value|"%{!msoft-float:%{mfpa:-D__HAVE_FPA__ }%{!mfpa:-D__HAVE_68881__ }}\ %{m68000:-D__mc68010__}%{mc68000:-D__mc68010__}%{!mc68000:%{!m68000:-D__mc68020__}} \ %{!ansi:%{m68000:-Dmc68010}%{mc68000:-Dmc68010}%{!mc68000:%{!m68000:-Dmc68020}}}"
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
value|"%{m68881:-D__HAVE_68881__ }%{mfpa:-D__HAVE_FPA__ }\ %{m68000:-D__mc68010__}%{mc68000:-D__mc68010__}%{!mc68000:%{!m68000:-D__mc68020__}} \ %{!ansi:%{m68000:-Dmc68010}%{mc68000:-Dmc68010}%{!mc68000:%{!m68000:-Dmc68020}}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Prevent error on `-sun3' and `-target sun3' options.  */
end_comment

begin_define
define|#
directive|define
name|CC1_SPEC
value|"%{sun3:} %{target:}"
end_define

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"int"
end_define

begin_comment
comment|/* We must override m68k.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"short unsigned int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|16
end_define

begin_comment
comment|/* These compiler options take an argument.  We ignore -target for now.  */
end_comment

begin_define
define|#
directive|define
name|WORD_SWITCH_TAKES_ARG
parameter_list|(
name|STR
parameter_list|)
define|\
value|(!strcmp (STR, "Tdata") || !strcmp (STR, "Ttext")		\   || !strcmp (STR, "Tbss") || !strcmp (STR, "include")		\   || !strcmp (STR, "imacros") || !strcmp (STR, "target")	\   || !strcmp (STR, "assert") || !strcmp (STR, "aux-info"))
end_define

begin_comment
comment|/* -m68000 requires special flags to the assembler.  */
end_comment

begin_define
define|#
directive|define
name|ASM_SPEC
define|\
value|"%{m68000:-mc68010}%{mc68000:-mc68010}%{!mc68000:%{!m68000:-mc68020}} \   %{fpic:-k} %{fPIC:-k}"
end_define

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dmc68000 -Dsun -Dunix"
end_define

begin_comment
comment|/* STARTFILE_SPEC to include sun floating point initialization    This is necessary (tr: Sun does it) for both the m68881 and the fpa    routines.    Note that includes knowledge of the default specs for gcc, ie. no    args translates to the same effect as -m68881    I'm not sure what would happen below if people gave contradictory    arguments (eg. -msoft-float -mfpa) */
end_comment

begin_if
if|#
directive|if
name|TARGET_DEFAULT
operator|&
literal|0100
end_if

begin_comment
comment|/* -mfpa is the default */
end_comment

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}	\    %{m68881:Mcrt1.o%s}					\    %{msoft-float:Fcrt1.o%s}				\    %{!m68881:%{!msoft-float:Wcrt1.o%s}}"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|TARGET_DEFAULT
operator|&
literal|2
end_if

begin_comment
comment|/* -m68881 is the default */
end_comment

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}	\    %{mfpa:Wcrt1.o%s}					\    %{msoft-float:Fcrt1.o%s}				\    %{!mfpa:%{!msoft-float:Mcrt1.o%s}}"
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
value|"%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}	\    %{m68881:Mcrt1.o%s}					\    %{mfpa:Wcrt1.o%s}					\    %{!m68881:%{!mfpa:Fcrt1.o%s}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Specify library to handle `-a' basic block profiling.    Control choice of libm.a (if user says -lm)    based on fp arith default and options.  */
end_comment

begin_if
if|#
directive|if
name|TARGET_DEFAULT
operator|&
literal|0100
end_if

begin_comment
comment|/* -mfpa is the default */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{g:-lg} %{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p} \ %{a:/usr/lib/bb_link.o} %{g:-lg} \ %{msoft-float:-L/usr/lib/fsoft}%{m68881:-L/usr/lib/f68881}\ %{!msoft_float:%{!m68881:-L/usr/lib/ffpa}}"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|TARGET_DEFAULT
operator|&
literal|2
end_if

begin_comment
comment|/* -m68881 is the default */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{g:-lg} %{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p} \ %{a:/usr/lib/bb_link.o} %{g:-lg} \ %{msoft-float:-L/usr/lib/fsoft}%{!msoft-float:%{!mfpa:-L/usr/lib/f68881}}\ %{mfpa:-L/usr/lib/ffpa}"
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
value|"%{g:-lg} %{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p} \ %{a:/usr/lib/bb_link.o} %{g:-lg} \ %{!m68881:%{!mfpa:-L/usr/lib/fsoft}}%{m68881:-L/usr/lib/f68881}\ %{mfpa:-L/usr/lib/ffpa}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Provide required defaults for linker -e and -d switches.  */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
define|\
value|"%{!nostdlib:%{!r*:%{!e*:-e start}}} -dc -dp %{static:-Bstatic} %{assert*}"
end_define

begin_comment
comment|/* Every structure or union's size must be a multiple of 2 bytes.  */
end_comment

begin_define
define|#
directive|define
name|STRUCTURE_SIZE_BOUNDARY
value|16
end_define

begin_comment
comment|/* This is BSD, so it wants DBX format.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_comment
comment|/* Allow folding division by zero.  */
end_comment

begin_define
define|#
directive|define
name|REAL_INFINITY
end_define

begin_comment
comment|/* Generate calls to memcpy, memcmp and memset.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
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
value|{									\     if (REAL_VALUE_ISINF (VALUE))					\       fprintf (FILE, "\t.double 0r%s99e999\n", (VALUE)> 0 ? "" : "-");	\     else if (REAL_VALUE_ISNAN (VALUE))					\       {									\ 	union { double d; long l[2];} t;				\ 	t.d = (VALUE);							\ 	fprintf (FILE, "\t.long 0x%lx\n\t.long 0x%lx\n", t.l[0], t.l[1]); \       }									\     else								\       fprintf (FILE, "\t.double 0r%.17g\n", VALUE);			\   }
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
value|{									\     if (REAL_VALUE_ISINF (VALUE))					\       fprintf (FILE, "\t.single 0r%s99e999\n", (VALUE)> 0 ? "" : "-");	\     else if (REAL_VALUE_ISNAN (VALUE))					\       {									\ 	union { float f; long l;} t;					\ 	t.f = (VALUE);							\ 	fprintf (FILE, "\t.long 0x%lx\n", t.l);				\       }									\     else								\       fprintf (FILE, "\t.single 0r%.9g\n", VALUE);			\   }
end_define

begin_comment
comment|/* This is how to output an assembler lines defining floating operands.    There's no way to output a NaN's fraction, so we lose it.  */
end_comment

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
value|(REAL_VALUE_ISINF ((VALUE))						\    ? (asm_fprintf (FILE, "%I0r%s99e999", ((VALUE)> 0 ? "" : "-")), 0)	\    : REAL_VALUE_MINUS_ZERO (VALUE)					\    ? (asm_fprintf (FILE, "%I0r-0.0"), 0)				\    : (asm_fprintf (FILE, "%I0r%.9g", (VALUE)), 0))
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
value|(REAL_VALUE_ISINF ((VALUE))						\    ? (asm_fprintf (FILE, "%I0r%s99e999", ((VALUE)> 0 ? "" : "-")), 0)	\    : REAL_VALUE_MINUS_ZERO (VALUE)					\    ? (asm_fprintf (FILE, "%I0r-0.0"), 0)				\    : (asm_fprintf (FILE, "%I0r%.17g", (VALUE)), 0))
end_define

end_unit

