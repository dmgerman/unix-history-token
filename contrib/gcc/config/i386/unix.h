begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Unix assembler syntax for the Intel 80386.    Copyright (C) 1988, 1994, 1999, 2000, 2001 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file defines the aspects of assembler syntax    that are the same for all the i386 Unix systems    (though they may differ in non-Unix systems).  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_ASSEMBLER_DIALECT
value|0
end_define

begin_comment
comment|/* Define macro used to output shift-double opcodes when the shift    count is in %cl.  Some assemblers require %cl as an argument;    some don't.  This macro controls what to do: by default, don't    print %cl.  */
end_comment

begin_define
define|#
directive|define
name|SHIFT_DOUBLE_OMITS_COUNT
value|1
end_define

begin_escape
end_escape

begin_comment
comment|/* Define the syntax of pseudo-ops, labels and comments.  */
end_comment

begin_comment
comment|/* String containing the assembler's comment-starter.  */
end_comment

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|"/"
end_define

begin_comment
comment|/* Output to assembler file text saying following lines    may contain character constants, extra white space, comments, etc.  */
end_comment

begin_define
define|#
directive|define
name|ASM_APP_ON
value|"/APP\n"
end_define

begin_comment
comment|/* Output to assembler file text saying following lines    no longer contain unusual constructs.  */
end_comment

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|"/NO_APP\n"
end_define

begin_comment
comment|/* Output before read-only data.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|"\t.text"
end_define

begin_comment
comment|/* Output before writable (initialized) data.  */
end_comment

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|"\t.data"
end_define

begin_comment
comment|/* Output before writable (uninitialized) data.  */
end_comment

begin_define
define|#
directive|define
name|BSS_SECTION_ASM_OP
value|"\t.bss"
end_define

begin_comment
comment|/* This is how to output a command to make the user-level label named NAME    defined for reference from other files.  */
end_comment

begin_define
define|#
directive|define
name|ASM_GLOBALIZE_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|(fputs (".globl ", FILE), assemble_name (FILE, NAME), fputs ("\n", FILE))
end_define

begin_comment
comment|/* By default, target has a 80387, uses IEEE compatible arithmetic,    and returns float values in the 387.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SUBTARGET_DEFAULT
value|(MASK_80387 | MASK_IEEE_FP | MASK_FLOAT_RETURNS)
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
value|(GET_MODE_CLASS (MODE) == MODE_FLOAT				\&& TARGET_FLOAT_RETURNS_IN_80387 ? FIRST_FLOAT_REG		\    : (MODE) == TImode || VECTOR_MODE_P (MODE) ? FIRST_SSE_REG	\    : 0)
end_define

begin_comment
comment|/* Output code to add DELTA to the first argument, and then jump to FUNCTION.    Used for C++ multiple inheritance.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_MI_THUNK
parameter_list|(
name|FILE
parameter_list|,
name|THUNK_FNDECL
parameter_list|,
name|DELTA
parameter_list|,
name|FUNCTION
parameter_list|)
define|\
value|x86_output_mi_thunk (FILE, DELTA, FUNCTION);
end_define

end_unit

