begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Sequent Intel 386.    Copyright (C) 1988 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"tm-i386.h"
end_include

begin_comment
comment|/* Use the BSD assembler syntax.  */
end_comment

begin_include
include|#
directive|include
file|"tm-bsd386.h"
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
comment|/* Specify predefined symbols in preprocessor.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Di386 -Dsequent"
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
value|(hard_regno_mode_ok (REGNO, MODE)	\&& ! (REGNO == 2&& GET_MODE_SIZE (MODE)> 4))
end_define

begin_comment
comment|/* Floating-point return values come in the FP register.  */
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
comment|/* Output assembler code to FILE to increment profiler label # LABELNO    for profiling a function entry. */
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
value|fprintf (FILE, "\tmovl $LP%d,%%eax\n\tcall mcount\n", (LABELNO));
end_define

begin_comment
comment|/* Assember pseudo-op for shared data segment. */
end_comment

begin_define
define|#
directive|define
name|SHARED_SECTION_ASM_OP
value|".shdata"
end_define

end_unit

