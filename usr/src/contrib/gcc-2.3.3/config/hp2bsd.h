begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  HP 9000/200 68000 version.    Copyright (C) 1987, 1991 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"m68k.h"
end_include

begin_comment
comment|/* See m68k.h.  0 means 68000 with no 68881.  */
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
value|"-Dmc68000 -Dmc68010 -Dhp200 -Dunix"
end_define

begin_comment
comment|/* Link with libg.a when debugging, for dbx's sake.  */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{g:-lg} %{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p} "
end_define

begin_comment
comment|/* Alignment of field after `int : 0' in a structure.  */
end_comment

begin_undef
undef|#
directive|undef
name|EMPTY_FIELD_BOUNDARY
end_undef

begin_define
define|#
directive|define
name|EMPTY_FIELD_BOUNDARY
value|16
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
comment|/* Define subroutines to call to handle multiply, divide, and remainder.    These routines are built into the c-library on the hp200.    XXX What other routines from the c-library could we use?    The `*' prevents an underscore from being prepended by the compiler.  */
end_comment

begin_define
define|#
directive|define
name|DIVSI3_LIBCALL
value|"*ldiv"
end_define

begin_define
define|#
directive|define
name|UDIVSI3_LIBCALL
value|"*uldiv"
end_define

begin_define
define|#
directive|define
name|MODSI3_LIBCALL
value|"*lrem"
end_define

begin_define
define|#
directive|define
name|UMODSI3_LIBCALL
value|"*ulrem"
end_define

begin_define
define|#
directive|define
name|MULSI3_LIBCALL
value|"*lmul"
end_define

begin_define
define|#
directive|define
name|UMULSI3_LIBCALL
value|"*ulmul"
end_define

end_unit

