begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  SEQUENT NS32000 version.    Copyright (C) 1987 Free Software Foundation, Inc.    Contributed by Michael Tiemann (tiemann@mcc.com)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"ns32k.h"
end_include

begin_comment
comment|/* This is BSD, so it wants DBX format.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_comment
comment|/* Sequent has some changes in the format of DBX symbols.  */
end_comment

begin_define
define|#
directive|define
name|DBX_NO_XREFS
value|1
end_define

begin_comment
comment|/* Don't split DBX symbols into continuations.  */
end_comment

begin_define
define|#
directive|define
name|DBX_CONTIN_LENGTH
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|9
end_define

begin_comment
comment|/* 32332 with 32081 (guessing).  */
end_comment

begin_comment
comment|/* Print subsidiary information on the compiler version in use.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (32000, Sequent syntax)");
end_define

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dns32000 -Dsequent -Dunix"
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
comment|/* gcc should find libgcc.a itself, not ask linker to do so.  */
end_comment

begin_define
define|#
directive|define
name|LINK_LIBGCC_SPECIAL
end_define

begin_comment
comment|/* GCC must match what sys/types.h uses for size_t.  */
end_comment

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"int"
end_define

begin_comment
comment|/* This is how to align the code that follows an unconditional branch.    Don't define it, since it confuses the assembler (we hear).  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGN_CODE
end_undef

begin_comment
comment|/* Assembler pseudo-op for shared data segment. */
end_comment

begin_define
define|#
directive|define
name|SHARED_SECTION_ASM_OP
value|".shdata"
end_define

begin_comment
comment|/* Control how stack adjust insns are output.  */
end_comment

begin_define
define|#
directive|define
name|SEQUENT_ADJUST_STACK
end_define

begin_define
define|#
directive|define
name|NO_ABSOLUTE_PREFIX_IF_SYMBOLIC
end_define

begin_define
define|#
directive|define
name|IMMEDIATE_PREFIX
value|0
end_define

begin_define
define|#
directive|define
name|SEQUENT_ASM
end_define

begin_comment
comment|/* Operand of bsr or jsr should be just the address.  */
end_comment

begin_define
define|#
directive|define
name|CALL_MEMREF_IMPLICIT
end_define

begin_comment
comment|/* Output a reg as an index rather than a base if we have the choice.  */
end_comment

begin_define
define|#
directive|define
name|INDEX_RATHER_THAN_BASE
end_define

end_unit

