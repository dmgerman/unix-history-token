begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Sequent Intel 386.    Copyright (C) 1988, 1994, 1999, 2000 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"i386/i386.h"
end_include

begin_comment
comment|/* Use the BSD assembler syntax.  */
end_comment

begin_include
include|#
directive|include
file|"i386/bsd.h"
end_include

begin_comment
comment|/* By default, don't use IEEE compatible arithmetic comparisons    because the assembler can't handle the fucom insn.    Return float values in the 387.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_SUBTARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_SUBTARGET_DEFAULT
value|(MASK_80387 | MASK_FLOAT_RETURNS)
end_define

begin_comment
comment|/* Specify predefined symbols in preprocessor.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Dsequent -Asystem=unix"
end_define

begin_comment
comment|/* Pass -Z and -ZO options to the linker.  */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{Z*}"
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Dynix 3.1 is said to accept -L.  */
end_comment

begin_comment
comment|/* Dynix V3.0.12 doesn't accept -L at all.  */
end_comment

begin_define
define|#
directive|define
name|LINK_LIBGCC_SPECIAL
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* Sequent Symmetry has size_t defined as int in /usr/include/sys/types.h */
end_comment

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"int"
end_define

begin_comment
comment|/* gcc order is ax, dx, cx, bx, si, di, bp, sp, st, st.  * dbx order is ax, dx, cx, st(0), st(1), bx, si, di, st(2), st(3),  * 		st(4), st(5), st(6), st(7), sp, bp  */
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
value|((n)< 3 ? (n) : (n)< 6 ? (n) + 2	\  : (n) == 6 ? 15 : (n) == 7 ? 14 : 3)
end_define

begin_comment
comment|/* malcolmp@hydra.maths.unsw.EDU.AU says these two definitions    fix trouble in dbx.  */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_OUTPUT_LBRAC
end_undef

begin_define
define|#
directive|define
name|DBX_OUTPUT_LBRAC
parameter_list|(
name|file
parameter_list|,
name|name
parameter_list|)
define|\
value|fprintf (asmfile, "%s%d,0,%d,", ASM_STABN_OP, N_LBRAC, depth); \ 	      assemble_name (asmfile, buf); \ 	      fprintf (asmfile, "\n");
end_define

begin_undef
undef|#
directive|undef
name|DBX_OUTPUT_RBRAC
end_undef

begin_define
define|#
directive|define
name|DBX_OUTPUT_RBRAC
parameter_list|(
name|file
parameter_list|,
name|name
parameter_list|)
define|\
value|fprintf (asmfile, "%s%d,0,%d,", ASM_STABN_OP, N_RBRAC, depth); \ 	      assemble_name (asmfile, buf); \ 	      fprintf (asmfile, "\n");
end_define

begin_comment
comment|/* Prevent anything from being allocated in the register pair cx/bx,    since that would confuse GDB.  */
end_comment

begin_undef
undef|#
directive|undef
name|HARD_REGNO_MODE_OK
end_undef

begin_define
define|#
directive|define
name|HARD_REGNO_MODE_OK
parameter_list|(
name|REGNO
parameter_list|,
name|MODE
parameter_list|)
define|\
value|(((REGNO)< 2 ? 1							\     : (REGNO)< 4 ? 1							\     : FP_REGNO_P (REGNO) ? (GET_MODE_CLASS (MODE) == MODE_FLOAT         \ 			    || GET_MODE_CLASS (MODE) == MODE_COMPLEX_FLOAT) \     : (MODE) != QImode)							\&& ! (REGNO == 2&& GET_MODE_UNIT_SIZE (MODE)> 4))
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
value|fprintf (FILE, "\tmovl $.LP%d,%%eax\n\tcall mcount\n", (LABELNO));
end_define

begin_comment
comment|/* Assembler pseudo-op for shared data segment.  */
end_comment

begin_define
define|#
directive|define
name|SHARED_SECTION_ASM_OP
value|"\t.shdata"
end_define

begin_comment
comment|/* A C statement or statements which output an assembler instruction    opcode to the stdio stream STREAM.  The macro-operand PTR is a    variable of type `char *' which points to the opcode name in its    "internal" form--the form that is written in the machine description.     The Sequent assembler (identified as "Balance 8000 Assembler    07/17/85 3.90" by "as -v") does not understand the `movs[bwl]' string    move mnemonics - it uses `smov[bwl]' instead.  Change "movs" into    "smov", carefully avoiding the sign-extend opcodes.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_OPCODE
parameter_list|(
name|STREAM
parameter_list|,
name|PTR
parameter_list|)
define|\
value|{									\   if ((PTR)[0] == 'm'							\&& (PTR)[1] == 'o'						\&& (PTR)[2] == 'v'						\&& (PTR)[3] == 's'						\&& ((PTR)[4] == 'b' || (PTR)[4] == 'w' || (PTR)[4] == 'l')	\&& ((PTR)[5] == ' ' || (PTR)[5] == '\t'|| (PTR)[5] == '\0'))	\     {									\       fprintf (STREAM, "smov");						\       (PTR) += 4;							\     }									\ }
end_define

begin_comment
comment|/* 10-Aug-92 pes  Local labels are prefixed with ".L" */
end_comment

begin_undef
undef|#
directive|undef
name|LPREFIX
end_undef

begin_define
define|#
directive|define
name|LPREFIX
value|".L"
end_define

begin_undef
undef|#
directive|undef
name|ASM_GENERATE_INTERNAL_LABEL
end_undef

begin_define
define|#
directive|define
name|ASM_GENERATE_INTERNAL_LABEL
parameter_list|(
name|BUF
parameter_list|,
name|PREFIX
parameter_list|,
name|NUMBER
parameter_list|)
define|\
value|sprintf ((BUF), "*.%s%ld", (PREFIX), (long)(NUMBER))
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_INTERNAL_LABEL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_INTERNAL_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|fprintf (FILE, ".%s%d:\n", PREFIX, NUM)
end_define

begin_comment
comment|/* The native compiler passes the address of the returned structure in eax.  */
end_comment

begin_undef
undef|#
directive|undef
name|STRUCT_VALUE
end_undef

begin_undef
undef|#
directive|undef
name|STRUCT_VALUE_INCOMING
end_undef

begin_define
define|#
directive|define
name|STRUCT_VALUE_REGNUM
value|0
end_define

end_unit

