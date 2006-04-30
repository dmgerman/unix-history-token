begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for condition code handling in final.c and output routines.    Copyright (C) 1987 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* None of the things in the files exist if we don't use CC0.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_cc0
end_ifdef

begin_comment
comment|/* The variable cc_status says how to interpret the condition code.    It is set by output routines for an instruction that sets the cc's    and examined by output routines for jump instructions.     cc_status contains two components named `value1' and `value2'    that record two equivalent expressions for the values that the    condition codes were set from.  (Either or both may be null if    there is no useful expression to record.)  These fields are    used for eliminating redundant test and compare instructions    in the cases where the condition codes were already set by the    previous instruction.     cc_status.flags contains flags which say that the condition codes    were set in a nonstandard manner.  The output of jump instructions    uses these flags to compensate and produce the standard result    with the nonstandard condition codes.  Standard flags are defined here.    The tm.h file can also define other machine-dependent flags.     cc_status also contains a machine-dependent component `mdep'    whose type, `CC_STATUS_MDEP', may be defined as a macro in the    tm.h file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CC_STATUS_MDEP
end_ifndef

begin_define
define|#
directive|define
name|CC_STATUS_MDEP
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CC_STATUS_MDEP_INIT
end_ifndef

begin_define
define|#
directive|define
name|CC_STATUS_MDEP_INIT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|flags
decl_stmt|;
name|rtx
name|value1
decl_stmt|,
name|value2
decl_stmt|;
name|CC_STATUS_MDEP
name|mdep
decl_stmt|;
block|}
name|CC_STATUS
typedef|;
end_typedef

begin_comment
comment|/* While outputting an insn as assembler code,    this is the status BEFORE that insn.  */
end_comment

begin_decl_stmt
specifier|extern
name|CC_STATUS
name|cc_prev_status
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* While outputting an insn as assembler code,    this is being altered to the status AFTER that insn.  */
end_comment

begin_decl_stmt
specifier|extern
name|CC_STATUS
name|cc_status
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* These are the machine-independent flags:  */
end_comment

begin_comment
comment|/* Set if the sign of the cc value is inverted:    output a following jump-if-less as a jump-if-greater, etc.  */
end_comment

begin_define
define|#
directive|define
name|CC_REVERSED
value|1
end_define

begin_comment
comment|/* This bit means that the current setting of the N bit is bogus    and conditional jumps should use the Z bit in its place.    This state obtains when an extraction of a signed single-bit field    or an arithmetic shift right of a byte by 7 bits    is turned into a btst, because btst does not set the N bit.  */
end_comment

begin_define
define|#
directive|define
name|CC_NOT_POSITIVE
value|2
end_define

begin_comment
comment|/* This bit means that the current setting of the N bit is bogus    and conditional jumps should pretend that the N bit is clear.    Used after extraction of an unsigned bit    or logical shift right of a byte by 7 bits is turned into a btst.    The btst does not alter the N bit, but the result of that shift    or extract is never negative.  */
end_comment

begin_define
define|#
directive|define
name|CC_NOT_NEGATIVE
value|4
end_define

begin_comment
comment|/* This bit means that the current setting of the overflow flag    is bogus and conditional jumps should pretend there is no overflow.  */
end_comment

begin_comment
comment|/* ??? Note that for most targets this macro is misnamed as it applies    to the carry flag, not the overflow flag.  */
end_comment

begin_define
define|#
directive|define
name|CC_NO_OVERFLOW
value|010
end_define

begin_comment
comment|/* This bit means that what ought to be in the Z bit    should be tested as the complement of the N bit.  */
end_comment

begin_define
define|#
directive|define
name|CC_Z_IN_NOT_N
value|020
end_define

begin_comment
comment|/* This bit means that what ought to be in the Z bit    should be tested as the N bit.  */
end_comment

begin_define
define|#
directive|define
name|CC_Z_IN_N
value|040
end_define

begin_comment
comment|/* Nonzero if we must invert the sense of the following branch, i.e.    change EQ to NE.  This is not safe for IEEE floating point operations!    It is intended for use only when a combination of arithmetic    or logical insns can leave the condition codes set in a fortuitous    (though inverted) state.  */
end_comment

begin_define
define|#
directive|define
name|CC_INVERTED
value|0100
end_define

begin_comment
comment|/* Nonzero if we must convert signed condition operators to unsigned.    This is only used by machine description files.  */
end_comment

begin_define
define|#
directive|define
name|CC_NOT_SIGNED
value|0200
end_define

begin_comment
comment|/* This is how to initialize the variable cc_status.    final does this at appropriate moments.  */
end_comment

begin_define
define|#
directive|define
name|CC_STATUS_INIT
define|\
value|(cc_status.flags = 0, cc_status.value1 = 0, cc_status.value2 = 0,  \   CC_STATUS_MDEP_INIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

