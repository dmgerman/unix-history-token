begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for a 3b1 using GAS.    Copyright (C) 1987, 1988 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"tm-m68k.h"
end_include

begin_comment
comment|/* See tm-m68k.h.  0 means 68000 with no 68881.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|0
end_define

begin_comment
comment|/* Define __HAVE_68881 in preprocessor only if -m68881 is specified.    This will control the use of inline 68881 insns in certain macros.    Also inform the program which CPU this is for.  */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{m68881:-D__HAVE_68881__} \ %{!ansi:%{m68020:-Dmc68020}%{mc68020:-Dmc68020}%{!mc68020:%{!m68020:-Dmc68010}}}"
end_define

begin_comment
comment|/* -m68020 requires special flags to the assembler.  */
end_comment

begin_define
define|#
directive|define
name|ASM_SPEC
define|\
value|"%{m68020:-mc68020}%{mc68020:-mc68020}%{!mc68020:%{!m68020:-mc68010}}"
end_define

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dmc68000 -Dmc68k -Dunix -Dunixpc"
end_define

begin_comment
comment|/* This is (not really) BSD, so (but) it wants DBX format.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_comment
comment|/* Brain damage. */
end_comment

begin_define
define|#
directive|define
name|SCCS_DIRECTIVE
end_define

begin_comment
comment|/* Specify how to pad function arguments.    Value should be `upward', `downward' or `none'.    Same as the default, except no padding for large or variable-size args.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_PADDING
parameter_list|(
name|mode
parameter_list|,
name|size
parameter_list|)
define|\
value|(((mode) == BLKmode							\     ? (GET_CODE (size) == CONST_INT					\&& INTVAL (size)< PARM_BOUNDARY / BITS_PER_UNIT)		\     : GET_MODE_BITSIZE (mode)< PARM_BOUNDARY)				\    ? downward : none)
end_define

begin_comment
comment|/* Override part of the obstack macros.  */
end_comment

begin_define
define|#
directive|define
name|__PTR_TO_INT
parameter_list|(
name|P
parameter_list|)
value|((int)(P))
end_define

begin_define
define|#
directive|define
name|__INT_TO_PTR
parameter_list|(
name|P
parameter_list|)
value|((char *)(P))
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

end_unit

