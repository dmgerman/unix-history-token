begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  Altos 3068 68020 version.    Copyright (C) 1988,1989 Free Software Foundation, Inc.  Written by Jyrki Kuoppala<jkp@cs.hut.fi> Last modified: Mon Mar  6 22:47:58 1989  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"tm-m68k.h"
end_include

begin_comment
comment|/* See tm-m68k.h.  7 means 68020 with 68881.  */
end_comment

begin_comment
comment|/* 5 is without 68881.  Change to 7 if you have 68881 */
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
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define __HAVE_68881__ in preprocessor,    according to the -m flags.    This will control the use of inline 68881 insns in certain macros.    Also inform the program which CPU this is for.  */
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
value|"%{!msoft-float:-D__HAVE_68881__ }\ %{!ansi:%{m68000:-Dmc68010}%{mc68000:-Dmc68010}%{!mc68000:%{!m68000:-Dmc68020}}}"
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
value|"%{m68881:-D__HAVE_68881__ }\ %{!ansi:%{m68000:-Dmc68010}%{mc68000:-Dmc68010}%{!mc68000:%{!m68000:-Dmc68020}}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* -m68000 requires special flags to the assembler.  */
end_comment

begin_define
define|#
directive|define
name|ASM_SPEC
define|\
value|"%{m68000:-mc68010}%{mc68000:-mc68010}%{!mc68000:%{!m68000:-mc68020}}"
end_define

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dmc68000 -DPORTAR -Dmc68k32 -Uvax -Dm68k -Dunix"
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
comment|/* Generate calls to memcpy, memcmp and memset.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_comment
comment|/* We use gnu assembler, linker and gdb, so we want DBX format.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_comment
comment|/* Tell some conditionals we will use GAS.  Is this really used?  */
end_comment

begin_define
define|#
directive|define
name|USE_GAS
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
value|fprintf (FILE, "\t.double 0r%.20e\n", (VALUE))
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
value|fprintf (FILE, "\t.single 0r%.20e\n", (VALUE))
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
value|fprintf (FILE, "#0r%.9g", (VALUE))
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
value|fprintf (FILE, "#0r%.20g", (VALUE))
end_define

begin_comment
comment|/* Return pointer values in both d0 and a0.  */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_EXTRA_EPILOGUE
end_undef

begin_define
define|#
directive|define
name|FUNCTION_EXTRA_EPILOGUE
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|{								\   extern int current_function_returns_pointer;			\   if ((current_function_returns_pointer)&& 			\       ! find_equiv_reg (0, get_last_insn (), 0, 0, 0, 8, Pmode))\     fprintf (FILE, "\tmovel d0,a0\n");				\ }
end_define

end_unit

