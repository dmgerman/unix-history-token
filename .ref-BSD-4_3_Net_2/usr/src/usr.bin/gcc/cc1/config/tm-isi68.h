begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  ISI 68000/68020 version.    Intended only for use with GAS, and not ISI's assembler, which is buggy    Copyright (C) 1988 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"tm-m68k.h"
end_include

begin_comment
comment|/* See tm-m68k.h.  7 means 68020 with 68881. */
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

begin_if
if|#
directive|if
name|TARGET_DEFAULT
operator|&
literal|2
end_if

begin_comment
comment|/* Define __HAVE_68881__ in preprocessor, unless -msoft-float is specified.    This will control the use of inline 68881 insns in certain macros.  */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{!msoft-float:-D__HAVE_68881__}"
end_define

begin_comment
comment|/* If the 68881 is used, link must load libmc.a instead of libc.a */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{msoft-float:%{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p}}%{!msoft-float:%{!p:%{!pg:-lmc}}%{p:-lmc_p}%{pg:-lmc_p}}"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Define __HAVE_68881__ in preprocessor if -m68881 is specified.    This will control the use of inline 68881 insns in certain macros.  */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{m68881:-D__HAVE_68881__}"
end_define

begin_comment
comment|/* If the 68881 is used, link must load libmc.a instead of libc.a */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!m68881:%{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p}}%{m68881:%{!p:%{!pg:-lmc}}%{p:-lmc_p}%{pg:-lmc_p}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Dmc68000 -Dis68k"
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
comment|/* Override parts of tm-m68000.h to fit the ISI 68k machine.  */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_VALUE
end_undef

begin_undef
undef|#
directive|undef
name|LIBCALL_VALUE
end_undef

begin_undef
undef|#
directive|undef
name|FUNCTION_VALUE_REGNO_P
end_undef

begin_undef
undef|#
directive|undef
name|ASM_FILE_START
end_undef

begin_comment
comment|/* If TARGET_68881, return SF and DF values in f0 instead of d0.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE
parameter_list|(
name|VALTYPE
parameter_list|,
name|FUNC
parameter_list|)
value|LIBCALL_VALUE (TYPE_MODE (VALTYPE))
end_define

begin_define
define|#
directive|define
name|LIBCALL_VALUE
parameter_list|(
name|MODE
parameter_list|)
define|\
value|gen_rtx (REG, (MODE), ((TARGET_68881&& ((MODE) == SFmode || (MODE) == DFmode)) ? 16 : 0))
end_define

begin_comment
comment|/* 1 if N is a possible register number for a function value.    D0 may be used, and F0 as well if -m68881 is specified.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|N
parameter_list|)
define|\
value|((N) == 0 || (TARGET_68881&& (N) == 16))
end_define

begin_comment
comment|/* Also output something to cause the correct _doprnt to be loaded.  */
end_comment

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|FILE
parameter_list|)
value|fprintf (FILE, "#NO_APP\n%s\n", TARGET_68881 ? ".globl fltused" : "")
end_define

end_unit

