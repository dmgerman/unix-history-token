begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Register Transfer Language (RTL) definitions for GNU C-Compiler    Copyright (C) 1987, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999,    2000, 2001 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RTL_H
end_ifndef

begin_define
define|#
directive|define
name|_RTL_H
end_define

begin_include
include|#
directive|include
file|"machmode.h"
end_include

begin_undef
undef|#
directive|undef
name|FFS
end_undef

begin_comment
comment|/* Some systems predefine this symbol; don't let it interfere.  */
end_comment

begin_undef
undef|#
directive|undef
name|FLOAT
end_undef

begin_comment
comment|/* Likewise.  */
end_comment

begin_undef
undef|#
directive|undef
name|ABS
end_undef

begin_comment
comment|/* Likewise.  */
end_comment

begin_undef
undef|#
directive|undef
name|PC
end_undef

begin_comment
comment|/* Likewise.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TREE_CODE
end_ifndef

begin_union_decl
union_decl|union
name|tree_node
union_decl|;
end_union_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Register Transfer Language EXPRESSIONS CODES */
end_comment

begin_define
define|#
directive|define
name|RTX_CODE
value|enum rtx_code
end_define

begin_enum
enum|enum
name|rtx_code
block|{
define|#
directive|define
name|DEF_RTL_EXPR
parameter_list|(
name|ENUM
parameter_list|,
name|NAME
parameter_list|,
name|FORMAT
parameter_list|,
name|CLASS
parameter_list|)
value|ENUM ,
include|#
directive|include
file|"rtl.def"
comment|/* rtl expressions are documented here */
undef|#
directive|undef
name|DEF_RTL_EXPR
name|LAST_AND_UNUSED_RTX_CODE
block|}
enum|;
end_enum

begin_comment
comment|/* A convenient way to get a value for 				   NUM_RTX_CODE. 				   Assumes default enum value assignment.  */
end_comment

begin_define
define|#
directive|define
name|NUM_RTX_CODE
value|((int)LAST_AND_UNUSED_RTX_CODE)
end_define

begin_comment
comment|/* The cast here, saves many elsewhere.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rtx_length
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_RTX_LENGTH
parameter_list|(
name|CODE
parameter_list|)
value|(rtx_length[(int) (CODE)])
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rtx_name
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_RTX_NAME
parameter_list|(
name|CODE
parameter_list|)
value|(rtx_name[(int) (CODE)])
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rtx_format
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_RTX_FORMAT
parameter_list|(
name|CODE
parameter_list|)
value|(rtx_format[(int) (CODE)])
end_define

begin_decl_stmt
specifier|extern
name|char
name|rtx_class
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_RTX_CLASS
parameter_list|(
name|CODE
parameter_list|)
value|(rtx_class[(int) (CODE)])
end_define

begin_escape
end_escape

begin_comment
comment|/* The flags and bitfields of an ADDR_DIFF_VEC.  BASE is the base label    relative to which the offsets are calculated, as explained in rtl.def.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Set at the start of shorten_branches - ONLY WHEN OPTIMIZING - : */
name|unsigned
name|min_align
range|:
literal|8
decl_stmt|;
comment|/* Flags: */
name|unsigned
name|base_after_vec
range|:
literal|1
decl_stmt|;
comment|/* BASE is after the ADDR_DIFF_VEC.  */
name|unsigned
name|min_after_vec
range|:
literal|1
decl_stmt|;
comment|/* minimum address target label is after the ADDR_DIFF_VEC.  */
name|unsigned
name|max_after_vec
range|:
literal|1
decl_stmt|;
comment|/* maximum address target label is after the ADDR_DIFF_VEC.  */
name|unsigned
name|min_after_base
range|:
literal|1
decl_stmt|;
comment|/* minimum address target label is after BASE.  */
name|unsigned
name|max_after_base
range|:
literal|1
decl_stmt|;
comment|/* maximum address target label is after BASE.  */
comment|/* Set by the actual branch shortening process - ONLY WHEN OPTIMIZING - : */
name|unsigned
name|offset_unsigned
range|:
literal|1
decl_stmt|;
comment|/* offsets have to be treated as unsigned.  */
name|unsigned
label|:
literal|2
expr_stmt|;
name|unsigned
name|scale
range|:
literal|8
decl_stmt|;
block|}
name|addr_diff_vec_flags
typedef|;
end_typedef

begin_comment
comment|/* Common union for an element of an rtx.  */
end_comment

begin_typedef
typedef|typedef
union|union
name|rtunion_def
block|{
name|HOST_WIDE_INT
name|rtwint
decl_stmt|;
name|int
name|rtint
decl_stmt|;
name|char
modifier|*
name|rtstr
decl_stmt|;
name|struct
name|rtx_def
modifier|*
name|rtx
decl_stmt|;
name|struct
name|rtvec_def
modifier|*
name|rtvec
decl_stmt|;
name|enum
name|machine_mode
name|rttype
decl_stmt|;
name|addr_diff_vec_flags
name|rt_addr_diff_vec_flags
decl_stmt|;
name|struct
name|bitmap_head_def
modifier|*
name|rtbit
decl_stmt|;
name|union
name|tree_node
modifier|*
name|rttree
decl_stmt|;
name|struct
name|basic_block_def
modifier|*
name|bb
decl_stmt|;
block|}
name|rtunion
typedef|;
end_typedef

begin_comment
comment|/* RTL expression ("rtx").  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rtx_def
block|{
ifdef|#
directive|ifdef
name|ONLY_INT_FIELDS
ifdef|#
directive|ifdef
name|CODE_FIELD_BUG
name|unsigned
name|int
name|code
range|:
literal|16
decl_stmt|;
else|#
directive|else
name|unsigned
name|short
name|code
decl_stmt|;
endif|#
directive|endif
else|#
directive|else
comment|/* The kind of expression this is.  */
name|enum
name|rtx_code
name|code
range|:
literal|16
decl_stmt|;
endif|#
directive|endif
comment|/* The kind of value the expression has.  */
ifdef|#
directive|ifdef
name|ONLY_INT_FIELDS
name|int
name|mode
range|:
literal|8
decl_stmt|;
else|#
directive|else
name|enum
name|machine_mode
name|mode
range|:
literal|8
decl_stmt|;
endif|#
directive|endif
comment|/* LINK_COST_ZERO in an INSN_LIST.  */
name|unsigned
name|int
name|jump
range|:
literal|1
decl_stmt|;
comment|/* LINK_COST_FREE in an INSN_LIST.  */
name|unsigned
name|int
name|call
range|:
literal|1
decl_stmt|;
comment|/* 1 in a MEM or REG if value of this expression will never change      during the current function, even though it is not      manifestly constant.      1 in a SUBREG if it is from a promoted variable that is unsigned.      1 in a SYMBOL_REF if it addresses something in the per-function      constants pool.      1 in a CALL_INSN if it is a const call.      1 in a JUMP_INSN if it is a branch that should be annulled.  Valid from      reorg until end of compilation; cleared before used.  */
name|unsigned
name|int
name|unchanging
range|:
literal|1
decl_stmt|;
comment|/* 1 in a MEM expression if contents of memory are volatile.      1 in an INSN, CALL_INSN, JUMP_INSN, CODE_LABEL or BARRIER      if it is deleted.      1 in a REG expression if corresponds to a variable declared by the user.      0 for an internally generated temporary.      In a SYMBOL_REF, this flag is used for machine-specific purposes.      In a LABEL_REF or in a REG_LABEL note, this is LABEL_REF_NONLOCAL_P.  */
name|unsigned
name|int
name|volatil
range|:
literal|1
decl_stmt|;
comment|/* 1 in a MEM referring to a field of an aggregate.      0 if the MEM was a variable or the result of a * operator in C;      1 if it was the result of a . or -> operator (on a struct) in C.      1 in a REG if the register is used only in exit code a loop.      1 in a SUBREG expression if was generated from a variable with a       promoted mode.      1 in a CODE_LABEL if the label is used for nonlocal gotos      and must not be deleted even if its count is zero.      1 in a LABEL_REF if this is a reference to a label outside the      current loop.      1 in an INSN, JUMP_INSN, or CALL_INSN if this insn must be scheduled      together with the preceding insn.  Valid only within sched.      1 in an INSN, JUMP_INSN, or CALL_INSN if insn is in a delay slot and      from the target of a branch.  Valid from reorg until end of compilation;      cleared before used.  */
name|unsigned
name|int
name|in_struct
range|:
literal|1
decl_stmt|;
comment|/* 1 if this rtx is used.  This is used for copying shared structure.      See `unshare_all_rtl'.      In a REG, this is not needed for that purpose, and used instead       in `leaf_renumber_regs_insn'.      In a SYMBOL_REF, means that emit_library_call      has used it as the function.  */
name|unsigned
name|int
name|used
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if this rtx came from procedure integration.      In a REG, nonzero means this reg refers to the return value      of the current function.  */
name|unsigned
name|integrated
range|:
literal|1
decl_stmt|;
comment|/* 1 in an INSN or a SET if this rtx is related to the call frame,      either changing how we compute the frame address or saving and      restoring registers in the prologue and epilogue.        1 in a MEM if the MEM refers to a scalar, rather than a member of      an aggregate.  */
name|unsigned
name|frame_related
range|:
literal|1
decl_stmt|;
comment|/* The first element of the operands of this rtx.      The number of operands and their types are controlled      by the `code' field, according to rtl.def.  */
name|rtunion
name|fld
index|[
literal|1
index|]
decl_stmt|;
block|}
typedef|*
name|rtx
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULL_RTX
value|(rtx) 0
end_define

begin_comment
comment|/* Define macros to access the `code' field of the rtx.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SHORT_ENUM_BUG
end_ifdef

begin_define
define|#
directive|define
name|GET_CODE
parameter_list|(
name|RTX
parameter_list|)
value|((enum rtx_code) ((RTX)->code))
end_define

begin_define
define|#
directive|define
name|PUT_CODE
parameter_list|(
name|RTX
parameter_list|,
name|CODE
parameter_list|)
value|((RTX)->code = ((short) (CODE)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GET_CODE
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->code)
end_define

begin_define
define|#
directive|define
name|PUT_CODE
parameter_list|(
name|RTX
parameter_list|,
name|CODE
parameter_list|)
value|((RTX)->code = (CODE))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GET_MODE
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->mode)
end_define

begin_define
define|#
directive|define
name|PUT_MODE
parameter_list|(
name|RTX
parameter_list|,
name|MODE
parameter_list|)
value|((RTX)->mode = (MODE))
end_define

begin_define
define|#
directive|define
name|RTX_INTEGRATED_P
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->integrated)
end_define

begin_define
define|#
directive|define
name|RTX_UNCHANGING_P
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->unchanging)
end_define

begin_define
define|#
directive|define
name|RTX_FRAME_RELATED_P
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->frame_related)
end_define

begin_comment
comment|/* RTL vector.  These appear inside RTX's when there is a need    for a variable number of things.  The principle use is inside    PARALLEL expressions.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rtvec_def
block|{
name|int
name|num_elem
decl_stmt|;
comment|/* number of elements */
name|rtunion
name|elem
index|[
literal|1
index|]
decl_stmt|;
block|}
typedef|*
name|rtvec
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULL_RTVEC
value|(rtvec) 0
end_define

begin_define
define|#
directive|define
name|GET_NUM_ELEM
parameter_list|(
name|RTVEC
parameter_list|)
value|((RTVEC)->num_elem)
end_define

begin_define
define|#
directive|define
name|PUT_NUM_ELEM
parameter_list|(
name|RTVEC
parameter_list|,
name|NUM
parameter_list|)
value|((RTVEC)->num_elem = (NUM))
end_define

begin_define
define|#
directive|define
name|RTVEC_ELT
parameter_list|(
name|RTVEC
parameter_list|,
name|I
parameter_list|)
value|((RTVEC)->elem[(I)].rtx)
end_define

begin_comment
comment|/* 1 if X is a REG.  */
end_comment

begin_define
define|#
directive|define
name|REG_P
parameter_list|(
name|X
parameter_list|)
value|(GET_CODE (X) == REG)
end_define

begin_comment
comment|/* 1 if X is a constant value that is an integer.  */
end_comment

begin_define
define|#
directive|define
name|CONSTANT_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == LABEL_REF || GET_CODE (X) == SYMBOL_REF		\    || GET_CODE (X) == CONST_INT || GET_CODE (X) == CONST_DOUBLE		\    || GET_CODE (X) == CONST || GET_CODE (X) == HIGH			\    || GET_CODE (X) == CONSTANT_P_RTX)
end_define

begin_comment
comment|/* General accessor macros for accessing the fields of an rtx.  */
end_comment

begin_define
define|#
directive|define
name|XEXP
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|((RTX)->fld[N].rtx)
end_define

begin_define
define|#
directive|define
name|XINT
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|((RTX)->fld[N].rtint)
end_define

begin_define
define|#
directive|define
name|XWINT
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|((RTX)->fld[N].rtwint)
end_define

begin_define
define|#
directive|define
name|XSTR
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|((RTX)->fld[N].rtstr)
end_define

begin_define
define|#
directive|define
name|XVEC
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|((RTX)->fld[N].rtvec)
end_define

begin_define
define|#
directive|define
name|XVECLEN
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|((RTX)->fld[N].rtvec->num_elem)
end_define

begin_define
define|#
directive|define
name|XVECEXP
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|,
name|M
parameter_list|)
value|((RTX)->fld[N].rtvec->elem[M].rtx)
end_define

begin_define
define|#
directive|define
name|XBITMAP
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|((RTX)->fld[N].rtbit)
end_define

begin_define
define|#
directive|define
name|XTREE
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|((RTX)->fld[N].rttree)
end_define

begin_escape
end_escape

begin_comment
comment|/* ACCESS MACROS for particular fields of insns.  */
end_comment

begin_comment
comment|/* Holds a unique number for each insn.    These are not necessarily sequentially increasing.  */
end_comment

begin_define
define|#
directive|define
name|INSN_UID
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->fld[0].rtint)
end_define

begin_comment
comment|/* Chain insns together in sequence.  */
end_comment

begin_define
define|#
directive|define
name|PREV_INSN
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->fld[1].rtx)
end_define

begin_define
define|#
directive|define
name|NEXT_INSN
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->fld[2].rtx)
end_define

begin_comment
comment|/* The body of an insn.  */
end_comment

begin_define
define|#
directive|define
name|PATTERN
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->fld[3].rtx)
end_define

begin_comment
comment|/* Code number of instruction, from when it was recognized.    -1 means this instruction has not been recognized yet.  */
end_comment

begin_define
define|#
directive|define
name|INSN_CODE
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->fld[4].rtint)
end_define

begin_comment
comment|/* Set up in flow.c; empty before then.    Holds a chain of INSN_LIST rtx's whose first operands point at    previous insns with direct data-flow connections to this one.    That means that those insns set variables whose next use is in this insn.    They are always in the same basic block as this insn.  */
end_comment

begin_define
define|#
directive|define
name|LOG_LINKS
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->fld[5].rtx)
end_define

begin_comment
comment|/* 1 if insn has been deleted.  */
end_comment

begin_define
define|#
directive|define
name|INSN_DELETED_P
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->volatil)
end_define

begin_comment
comment|/* 1 if insn is a call to a const function.  */
end_comment

begin_define
define|#
directive|define
name|CONST_CALL_P
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->unchanging)
end_define

begin_comment
comment|/* 1 if insn is a branch that should not unconditionally execute its    delay slots, i.e., it is an annulled branch.   */
end_comment

begin_define
define|#
directive|define
name|INSN_ANNULLED_BRANCH_P
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->unchanging)
end_define

begin_comment
comment|/* 1 if insn is in a delay slot and is from the target of the branch.  If    the branch insn has INSN_ANNULLED_BRANCH_P set, this insn should only be    executed if the branch is taken.  For annulled branches with this bit    clear, the insn should be executed only if the branch is not taken.  */
end_comment

begin_define
define|#
directive|define
name|INSN_FROM_TARGET_P
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->in_struct)
end_define

begin_comment
comment|/* Holds a list of notes on what this insn does to various REGs.    It is a chain of EXPR_LIST rtx's, where the second operand    is the chain pointer and the first operand is the REG being described.    The mode field of the EXPR_LIST contains not a real machine mode    but a value that says what this note says about the REG:      REG_DEAD means that the value in REG dies in this insn (i.e., it is    not needed past this insn).  If REG is set in this insn, the REG_DEAD    note may, but need not, be omitted.      REG_INC means that the REG is autoincremented or autodecremented.      REG_EQUIV describes the insn as a whole; it says that the insn    sets a register to a constant value or to be equivalent to a memory    address.  If the register is spilled to the stack then the constant    value should be substituted for it.  The contents of the REG_EQUIV    is the constant value or memory address, which may be different    from the source of the SET although it has the same value.  A    REG_EQUIV note may also appear on an insn which copies a register    parameter to a pseudo-register, if there is a memory address which    could be used to hold that pseudo-register throughout the function.      REG_EQUAL is like REG_EQUIV except that the destination    is only momentarily equal to the specified rtx.  Therefore, it    cannot be used for substitution; but it can be used for cse.      REG_RETVAL means that this insn copies the return-value of    a library call out of the hard reg for return values.  This note    is actually an INSN_LIST and it points to the first insn involved    in setting up arguments for the call.  flow.c uses this to delete    the entire library call when its result is dead.      REG_LIBCALL is the inverse of REG_RETVAL: it goes on the first insn    of the library call and points at the one that has the REG_RETVAL.      REG_WAS_0 says that the register set in this insn held 0 before the insn.    The contents of the note is the insn that stored the 0.    If that insn is deleted or patched to a NOTE, the REG_WAS_0 is inoperative.    The REG_WAS_0 note is actually an INSN_LIST, not an EXPR_LIST.      REG_NONNEG means that the register is always nonnegative during    the containing loop.  This is used in branches so that decrement and    branch instructions terminating on zero can be matched.  There must be    an insn pattern in the md file named `decrement_and_branch_until_zero'    or else this will never be added to any instructions.      REG_NO_CONFLICT means there is no conflict *after this insn*    between the register in the note and the destination of this insn.      REG_UNUSED identifies a register set in this insn and never used.      REG_CC_SETTER and REG_CC_USER link a pair of insns that set and use    CC0, respectively.  Normally, these are required to be consecutive insns,    but we permit putting a cc0-setting insn in the delay slot of a branch    as long as only one copy of the insn exists.  In that case, these notes    point from one to the other to allow code generation to determine what    any require information and to properly update CC_STATUS.      REG_LABEL points to a CODE_LABEL.  Used by non-JUMP_INSNs to    say that the CODE_LABEL contained in the REG_LABEL note is used    by the insn.      REG_DEP_ANTI is used in LOG_LINKS which represent anti (write after read)    dependencies.  REG_DEP_OUTPUT is used in LOG_LINKS which represent output    (write after write) dependencies.  Data dependencies, which are the only    type of LOG_LINK created by flow, are represented by a 0 reg note kind.  */
end_comment

begin_comment
comment|/*   REG_BR_PROB is attached to JUMP_INSNs and CALL_INSNs when the flag    -fbranch-probabilities is given.  It has an integer value.  For jumps,    it is the probability that this is a taken branch.  For calls, it is the    probability that this call won't return.      REG_EXEC_COUNT is attached to the first insn of each basic block, and    the first insn after each CALL_INSN.  It indicates how many times this    block was executed.      REG_SAVE_AREA is used to optimize rtl generated by dynamic stack    allocations for targets where SETJMP_VIA_SAVE_AREA is true.      REG_BR_PRED is attached to JUMP_INSNs only, it holds the branch prediction    flags computed by get_jump_flags() after dbr scheduling is complete.      REG_FRAME_RELATED_EXPR is attached to insns that are RTX_FRAME_RELATED_P,    but are too complex for DWARF to interpret what they imply.  The attached    rtx is used instead of intuition.  */
end_comment

begin_comment
comment|/*   REG_EH_REGION is used to indicate what exception region an INSN    belongs in.  This can be used to indicate what region a call may throw    to.  A REGION of 0 indicates that a call cannot throw at all.    A REGION  of -1 indicates that it cannot throw, nor will it execute    a non-local goto.      REG_EH_RETHROW is used to indicate what that a call is actually a    call to rethrow, and specifies which region the rethrow is targetting.    This provides a way to generate the non standard flow edges required     for a rethrow.  */
end_comment

begin_define
define|#
directive|define
name|REG_NOTES
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->fld[6].rtx)
end_define

begin_define
define|#
directive|define
name|ADDR_DIFF_VEC_FLAGS
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[4].rt_addr_diff_vec_flags)
end_define

begin_comment
comment|/* Don't forget to change reg_note_name in rtl.c.  */
end_comment

begin_enum
enum|enum
name|reg_note
block|{
name|REG_DEAD
init|=
literal|1
block|,
name|REG_INC
init|=
literal|2
block|,
name|REG_EQUIV
init|=
literal|3
block|,
name|REG_WAS_0
init|=
literal|4
block|,
name|REG_EQUAL
init|=
literal|5
block|,
name|REG_RETVAL
init|=
literal|6
block|,
name|REG_LIBCALL
init|=
literal|7
block|,
name|REG_NONNEG
init|=
literal|8
block|,
name|REG_NO_CONFLICT
init|=
literal|9
block|,
name|REG_UNUSED
init|=
literal|10
block|,
name|REG_CC_SETTER
init|=
literal|11
block|,
name|REG_CC_USER
init|=
literal|12
block|,
name|REG_LABEL
init|=
literal|13
block|,
name|REG_DEP_ANTI
init|=
literal|14
block|,
name|REG_DEP_OUTPUT
init|=
literal|15
block|,
name|REG_BR_PROB
init|=
literal|16
block|,
name|REG_EXEC_COUNT
init|=
literal|17
block|,
name|REG_NOALIAS
init|=
literal|18
block|,
name|REG_SAVE_AREA
init|=
literal|19
block|,
name|REG_BR_PRED
init|=
literal|20
block|,
name|REG_EH_CONTEXT
init|=
literal|21
block|,
name|REG_FRAME_RELATED_EXPR
init|=
literal|22
block|,
name|REG_EH_REGION
init|=
literal|23
block|,
name|REG_EH_RETHROW
init|=
literal|24
block|}
enum|;
end_enum

begin_comment
comment|/* The base value for branch probability notes.  */
end_comment

begin_define
define|#
directive|define
name|REG_BR_PROB_BASE
value|10000
end_define

begin_comment
comment|/* Define macros to extract and insert the reg-note kind in an EXPR_LIST.  */
end_comment

begin_define
define|#
directive|define
name|REG_NOTE_KIND
parameter_list|(
name|LINK
parameter_list|)
value|((enum reg_note) GET_MODE (LINK))
end_define

begin_define
define|#
directive|define
name|PUT_REG_NOTE_KIND
parameter_list|(
name|LINK
parameter_list|,
name|KIND
parameter_list|)
value|PUT_MODE(LINK, (enum machine_mode) (KIND))
end_define

begin_comment
comment|/* Names for REG_NOTE's in EXPR_LIST insn's.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|reg_note_name
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_REG_NOTE_NAME
parameter_list|(
name|MODE
parameter_list|)
value|(reg_note_name[(int) (MODE)])
end_define

begin_comment
comment|/* This field is only present on CALL_INSNs.  It holds a chain of EXPR_LIST of    USE and CLOBBER expressions.      USE expressions list the registers filled with arguments that    are passed to the function.      CLOBBER expressions document the registers explicitly clobbered    by this CALL_INSN.      Pseudo registers can not be mentioned in this list.  */
end_comment

begin_define
define|#
directive|define
name|CALL_INSN_FUNCTION_USAGE
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->fld[7].rtx)
end_define

begin_comment
comment|/* The label-number of a code-label.  The assembler label    is made from `L' and the label-number printed in decimal.    Label numbers are unique in a compilation.  */
end_comment

begin_define
define|#
directive|define
name|CODE_LABEL_NUMBER
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->fld[3].rtint)
end_define

begin_define
define|#
directive|define
name|LINE_NUMBER
value|NOTE
end_define

begin_comment
comment|/* In a NOTE that is a line number, this is a string for the file name that the    line is in.  We use the same field to record block numbers temporarily in    NOTE_INSN_BLOCK_BEG and NOTE_INSN_BLOCK_END notes.  (We avoid lots of casts    between ints and pointers if we use a different macro for the block number.)    The NOTE_INSN_RANGE_{START,END} and NOTE_INSN_LIVE notes record their    information as a rtx in the field.  */
end_comment

begin_define
define|#
directive|define
name|NOTE_SOURCE_FILE
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->fld[3].rtstr)
end_define

begin_define
define|#
directive|define
name|NOTE_BLOCK_NUMBER
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->fld[3].rtint)
end_define

begin_define
define|#
directive|define
name|NOTE_RANGE_INFO
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->fld[3].rtx)
end_define

begin_define
define|#
directive|define
name|NOTE_LIVE_INFO
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->fld[3].rtx)
end_define

begin_define
define|#
directive|define
name|NOTE_BASIC_BLOCK
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->fld[3].bb)
end_define

begin_comment
comment|/* If the NOTE_BLOCK_NUMBER field gets a -1, it means create a new    block node for a live range block.  */
end_comment

begin_define
define|#
directive|define
name|NOTE_BLOCK_LIVE_RANGE_BLOCK
value|-1
end_define

begin_comment
comment|/* In a NOTE that is a line number, this is the line number.    Other kinds of NOTEs are identified by negative numbers here.  */
end_comment

begin_define
define|#
directive|define
name|NOTE_LINE_NUMBER
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->fld[4].rtint)
end_define

begin_comment
comment|/* Codes that appear in the NOTE_LINE_NUMBER field    for kinds of notes that are not line numbers.     Notice that we do not try to use zero here for any of    the special note codes because sometimes the source line    actually can be zero!  This happens (for example) when we    are generating code for the per-translation-unit constructor    and destructor routines for some C++ translation unit.     If you should change any of the following values, or if you    should add a new value here, don't forget to change the    note_insn_name array in rtl.c.  */
end_comment

begin_comment
comment|/* This note is used to get rid of an insn    when it isn't safe to patch the insn out of the chain.  */
end_comment

begin_define
define|#
directive|define
name|NOTE_INSN_DELETED
value|-1
end_define

begin_define
define|#
directive|define
name|NOTE_INSN_BLOCK_BEG
value|-2
end_define

begin_define
define|#
directive|define
name|NOTE_INSN_BLOCK_END
value|-3
end_define

begin_define
define|#
directive|define
name|NOTE_INSN_LOOP_BEG
value|-4
end_define

begin_define
define|#
directive|define
name|NOTE_INSN_LOOP_END
value|-5
end_define

begin_comment
comment|/* This kind of note is generated at the end of the function body,    just before the return insn or return label.    In an optimizing compilation it is deleted by the first jump optimization,    after enabling that optimizer to determine whether control can fall    off the end of the function body without a return statement.  */
end_comment

begin_define
define|#
directive|define
name|NOTE_INSN_FUNCTION_END
value|-6
end_define

begin_comment
comment|/* This kind of note is generated just after each call to `setjmp', et al.  */
end_comment

begin_define
define|#
directive|define
name|NOTE_INSN_SETJMP
value|-7
end_define

begin_comment
comment|/* Generated at the place in a loop that `continue' jumps to.  */
end_comment

begin_define
define|#
directive|define
name|NOTE_INSN_LOOP_CONT
value|-8
end_define

begin_comment
comment|/* Generated at the start of a duplicated exit test.  */
end_comment

begin_define
define|#
directive|define
name|NOTE_INSN_LOOP_VTOP
value|-9
end_define

begin_comment
comment|/* This marks the point immediately after the last prologue insn.  */
end_comment

begin_define
define|#
directive|define
name|NOTE_INSN_PROLOGUE_END
value|-10
end_define

begin_comment
comment|/* This marks the point immediately prior to the first epilogue insn.  */
end_comment

begin_define
define|#
directive|define
name|NOTE_INSN_EPILOGUE_BEG
value|-11
end_define

begin_comment
comment|/* Generated in place of user-declared labels when they are deleted.  */
end_comment

begin_define
define|#
directive|define
name|NOTE_INSN_DELETED_LABEL
value|-12
end_define

begin_comment
comment|/* This note indicates the start of the real body of the function,    i.e. the point just after all of the parms have been moved into    their homes, etc.  */
end_comment

begin_define
define|#
directive|define
name|NOTE_INSN_FUNCTION_BEG
value|-13
end_define

begin_comment
comment|/* These note where exception handling regions begin and end.  */
end_comment

begin_define
define|#
directive|define
name|NOTE_INSN_EH_REGION_BEG
value|-14
end_define

begin_define
define|#
directive|define
name|NOTE_INSN_EH_REGION_END
value|-15
end_define

begin_comment
comment|/* Generated whenever a duplicate line number note is output.  For example,    one is output after the end of an inline function, in order to prevent    the line containing the inline call from being counted twice in gcov. */
end_comment

begin_define
define|#
directive|define
name|NOTE_REPEATED_LINE_NUMBER
value|-16
end_define

begin_comment
comment|/* Start/end of a live range region, where pseudos allocated on the stack can    be allocated to temporary registers.  */
end_comment

begin_define
define|#
directive|define
name|NOTE_INSN_RANGE_START
value|-17
end_define

begin_define
define|#
directive|define
name|NOTE_INSN_RANGE_END
value|-18
end_define

begin_comment
comment|/* Record which registers are currently live.  */
end_comment

begin_define
define|#
directive|define
name|NOTE_INSN_LIVE
value|-19
end_define

begin_comment
comment|/* Record the struct for the following basic block.  */
end_comment

begin_define
define|#
directive|define
name|NOTE_INSN_BASIC_BLOCK
value|-20
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* These are not used, and I don't know what they were for. --rms.  */
end_comment

begin_define
define|#
directive|define
name|NOTE_DECL_NAME
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->fld[3].rtstr)
end_define

begin_define
define|#
directive|define
name|NOTE_DECL_CODE
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->fld[4].rtint)
end_define

begin_define
define|#
directive|define
name|NOTE_DECL_RTL
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->fld[5].rtx)
end_define

begin_define
define|#
directive|define
name|NOTE_DECL_IDENTIFIER
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->fld[6].rtint)
end_define

begin_define
define|#
directive|define
name|NOTE_DECL_TYPE
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->fld[7].rtint)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_comment
comment|/* Names for NOTE insn's other than line numbers.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|note_insn_name
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_NOTE_INSN_NAME
parameter_list|(
name|NOTE_CODE
parameter_list|)
value|(note_insn_name[-(NOTE_CODE)])
end_define

begin_comment
comment|/* The name of a label, in case it corresponds to an explicit label    in the input source code.  */
end_comment

begin_define
define|#
directive|define
name|LABEL_NAME
parameter_list|(
name|LABEL
parameter_list|)
value|((LABEL)->fld[4].rtstr)
end_define

begin_comment
comment|/* In jump.c, each label contains a count of the number    of LABEL_REFs that point at it, so unused labels can be deleted.  */
end_comment

begin_define
define|#
directive|define
name|LABEL_NUSES
parameter_list|(
name|LABEL
parameter_list|)
value|((LABEL)->fld[5].rtint)
end_define

begin_comment
comment|/* The original regno this ADDRESSOF was built for.  */
end_comment

begin_define
define|#
directive|define
name|ADDRESSOF_REGNO
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[1].rtint)
end_define

begin_comment
comment|/* The variable in the register we took the address of.  */
end_comment

begin_define
define|#
directive|define
name|ADDRESSOF_DECL
parameter_list|(
name|X
parameter_list|)
value|((tree) XEXP ((X), 2))
end_define

begin_define
define|#
directive|define
name|SET_ADDRESSOF_DECL
parameter_list|(
name|X
parameter_list|,
name|T
parameter_list|)
value|(XEXP ((X), 2) = (rtx) (T))
end_define

begin_comment
comment|/* In jump.c, each JUMP_INSN can point to a label that it can jump to,    so that if the JUMP_INSN is deleted, the label's LABEL_NUSES can    be decremented and possibly the label can be deleted.  */
end_comment

begin_define
define|#
directive|define
name|JUMP_LABEL
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->fld[7].rtx)
end_define

begin_comment
comment|/* Once basic blocks are found in flow.c,    each CODE_LABEL starts a chain that goes through    all the LABEL_REFs that jump to that label.    The chain eventually winds up at the CODE_LABEL; it is circular.  */
end_comment

begin_define
define|#
directive|define
name|LABEL_REFS
parameter_list|(
name|LABEL
parameter_list|)
value|((LABEL)->fld[6].rtx)
end_define

begin_escape
end_escape

begin_comment
comment|/* This is the field in the LABEL_REF through which the circular chain    of references to a particular label is linked.    This chain is set up in flow.c.  */
end_comment

begin_define
define|#
directive|define
name|LABEL_NEXTREF
parameter_list|(
name|REF
parameter_list|)
value|((REF)->fld[1].rtx)
end_define

begin_comment
comment|/* Once basic blocks are found in flow.c,    Each LABEL_REF points to its containing instruction with this field.  */
end_comment

begin_define
define|#
directive|define
name|CONTAINING_INSN
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[2].rtx)
end_define

begin_comment
comment|/* For a REG rtx, REGNO extracts the register number.  */
end_comment

begin_define
define|#
directive|define
name|REGNO
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[0].rtint)
end_define

begin_comment
comment|/* For a REG rtx, REG_FUNCTION_VALUE_P is nonzero if the reg    is the current function's return value.  */
end_comment

begin_define
define|#
directive|define
name|REG_FUNCTION_VALUE_P
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->integrated)
end_define

begin_comment
comment|/* 1 in a REG rtx if it corresponds to a variable declared by the user.  */
end_comment

begin_define
define|#
directive|define
name|REG_USERVAR_P
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->volatil)
end_define

begin_comment
comment|/* For a CONST_INT rtx, INTVAL extracts the integer.  */
end_comment

begin_define
define|#
directive|define
name|INTVAL
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[0].rtwint)
end_define

begin_comment
comment|/* For a SUBREG rtx, SUBREG_REG extracts the value we want a subreg of.    SUBREG_WORD extracts the word-number.  */
end_comment

begin_define
define|#
directive|define
name|SUBREG_REG
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[0].rtx)
end_define

begin_define
define|#
directive|define
name|SUBREG_WORD
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[1].rtint)
end_define

begin_comment
comment|/* 1 if the REG contained in SUBREG_REG is already known to be    sign- or zero-extended from the mode of the SUBREG to the mode of    the reg.  SUBREG_PROMOTED_UNSIGNED_P gives the signedness of the    extension.       When used as a LHS, is means that this extension must be done    when assigning to SUBREG_REG.  */
end_comment

begin_define
define|#
directive|define
name|SUBREG_PROMOTED_VAR_P
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->in_struct)
end_define

begin_define
define|#
directive|define
name|SUBREG_PROMOTED_UNSIGNED_P
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->unchanging)
end_define

begin_comment
comment|/* Access various components of an ASM_OPERANDS rtx.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OPERANDS_TEMPLATE
parameter_list|(
name|RTX
parameter_list|)
value|XSTR ((RTX), 0)
end_define

begin_define
define|#
directive|define
name|ASM_OPERANDS_OUTPUT_CONSTRAINT
parameter_list|(
name|RTX
parameter_list|)
value|XSTR ((RTX), 1)
end_define

begin_define
define|#
directive|define
name|ASM_OPERANDS_OUTPUT_IDX
parameter_list|(
name|RTX
parameter_list|)
value|XINT ((RTX), 2)
end_define

begin_define
define|#
directive|define
name|ASM_OPERANDS_INPUT_VEC
parameter_list|(
name|RTX
parameter_list|)
value|XVEC ((RTX), 3)
end_define

begin_define
define|#
directive|define
name|ASM_OPERANDS_INPUT_CONSTRAINT_VEC
parameter_list|(
name|RTX
parameter_list|)
value|XVEC ((RTX), 4)
end_define

begin_define
define|#
directive|define
name|ASM_OPERANDS_INPUT
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|XVECEXP ((RTX), 3, (N))
end_define

begin_define
define|#
directive|define
name|ASM_OPERANDS_INPUT_LENGTH
parameter_list|(
name|RTX
parameter_list|)
value|XVECLEN ((RTX), 3)
end_define

begin_define
define|#
directive|define
name|ASM_OPERANDS_INPUT_CONSTRAINT
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|XSTR (XVECEXP ((RTX), 4, (N)), 0)
end_define

begin_define
define|#
directive|define
name|ASM_OPERANDS_INPUT_MODE
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|GET_MODE (XVECEXP ((RTX), 4, (N)))
end_define

begin_define
define|#
directive|define
name|ASM_OPERANDS_SOURCE_FILE
parameter_list|(
name|RTX
parameter_list|)
value|XSTR ((RTX), 5)
end_define

begin_define
define|#
directive|define
name|ASM_OPERANDS_SOURCE_LINE
parameter_list|(
name|RTX
parameter_list|)
value|XINT ((RTX), 6)
end_define

begin_comment
comment|/* For a MEM rtx, 1 if it's a volatile reference.    Also in an ASM_OPERANDS rtx.  */
end_comment

begin_define
define|#
directive|define
name|MEM_VOLATILE_P
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->volatil)
end_define

begin_comment
comment|/* For a MEM rtx, 1 if it refers to a field of an aggregate.  If zero,    RTX may or may not refer to a field of an aggregate.  */
end_comment

begin_define
define|#
directive|define
name|MEM_IN_STRUCT_P
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->in_struct)
end_define

begin_comment
comment|/* For a MEM rtx, 1 if it refers to a scalar.  If zero, RTX may or may    not refer to a scalar.*/
end_comment

begin_define
define|#
directive|define
name|MEM_SCALAR_P
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->frame_related)
end_define

begin_comment
comment|/* Copy the MEM_VOLATILE_P, MEM_IN_STRUCT_P, and MEM_SCALAR_P    attributes from RHS to LHS.  */
end_comment

begin_define
define|#
directive|define
name|MEM_COPY_ATTRIBUTES
parameter_list|(
name|LHS
parameter_list|,
name|RHS
parameter_list|)
define|\
value|(MEM_VOLATILE_P (LHS) = MEM_VOLATILE_P (RHS),		\    MEM_IN_STRUCT_P (LHS) = MEM_IN_STRUCT_P (RHS),	\    MEM_SCALAR_P (LHS) = MEM_SCALAR_P (RHS))
end_define

begin_comment
comment|/* If VAL is non-zero, set MEM_IN_STRUCT_P and clear MEM_SCALAR_P in    RTX.  Otherwise, vice versa.  Use this macro only when you are    *sure* that you know that the MEM is in a structure, or is a    scalar.  VAL is evaluated only once.  */
end_comment

begin_define
define|#
directive|define
name|MEM_SET_IN_STRUCT_P
parameter_list|(
name|RTX
parameter_list|,
name|VAL
parameter_list|)
define|\
value|((VAL) ? (MEM_IN_STRUCT_P (RTX) = 1, MEM_SCALAR_P (RTX) = 0)	\    : (MEM_IN_STRUCT_P (RTX) = 0, MEM_SCALAR_P (RTX) = 1))
end_define

begin_comment
comment|/* For a MEM rtx, the alias set.  If 0, this MEM is not in any alias    set, and may alias anything.  Otherwise, the MEM can only alias    MEMs in the same alias set.  This value is set in a    language-dependent manner in the front-end, and should not be    altered in the back-end.  These set numbers are tested for zero,    and compared for equality; they have no other significance.  In    some front-ends, these numbers may correspond in some way to types,    or other language-level entities, but they need not, and the    back-end makes no such assumptions.  */
end_comment

begin_define
define|#
directive|define
name|MEM_ALIAS_SET
parameter_list|(
name|RTX
parameter_list|)
value|(XINT (RTX, 1))
end_define

begin_comment
comment|/* For a LABEL_REF, 1 means that this reference is to a label outside the    loop containing the reference.  */
end_comment

begin_define
define|#
directive|define
name|LABEL_OUTSIDE_LOOP_P
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->in_struct)
end_define

begin_comment
comment|/* For a LABEL_REF, 1 means it is for a nonlocal label.  */
end_comment

begin_comment
comment|/* Likewise in an EXPR_LIST for a REG_LABEL note.  */
end_comment

begin_define
define|#
directive|define
name|LABEL_REF_NONLOCAL_P
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->volatil)
end_define

begin_comment
comment|/* For a CODE_LABEL, 1 means always consider this label to be needed.  */
end_comment

begin_define
define|#
directive|define
name|LABEL_PRESERVE_P
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->in_struct)
end_define

begin_comment
comment|/* For a REG, 1 means the register is used only in an exit test of a loop.  */
end_comment

begin_define
define|#
directive|define
name|REG_LOOP_TEST_P
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->in_struct)
end_define

begin_comment
comment|/* During sched, for an insn, 1 means that the insn must be scheduled together    with the preceding insn.  */
end_comment

begin_define
define|#
directive|define
name|SCHED_GROUP_P
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->in_struct)
end_define

begin_comment
comment|/* During sched, for the LOG_LINKS of an insn, these cache the adjusted    cost of the dependence link.  The cost of executing an instruction    may vary based on how the results are used.  LINK_COST_ZERO is 1 when    the cost through the link varies and is unchanged (i.e., the link has    zero additional cost).  LINK_COST_FREE is 1 when the cost through the    link is zero (i.e., the link makes the cost free).  In other cases,    the adjustment to the cost is recomputed each time it is needed.  */
end_comment

begin_define
define|#
directive|define
name|LINK_COST_ZERO
parameter_list|(
name|X
parameter_list|)
value|((X)->jump)
end_define

begin_define
define|#
directive|define
name|LINK_COST_FREE
parameter_list|(
name|X
parameter_list|)
value|((X)->call)
end_define

begin_comment
comment|/* For a SET rtx, SET_DEST is the place that is set    and SET_SRC is the value it is set to.  */
end_comment

begin_define
define|#
directive|define
name|SET_DEST
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[0].rtx)
end_define

begin_define
define|#
directive|define
name|SET_SRC
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[1].rtx)
end_define

begin_comment
comment|/* For a TRAP_IF rtx, TRAP_CONDITION is an expression.  */
end_comment

begin_define
define|#
directive|define
name|TRAP_CONDITION
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[0].rtx)
end_define

begin_define
define|#
directive|define
name|TRAP_CODE
parameter_list|(
name|RTX
parameter_list|)
value|(RTX)->fld[1].rtx
end_define

begin_comment
comment|/* 1 in a SYMBOL_REF if it addresses this function's constants pool.  */
end_comment

begin_define
define|#
directive|define
name|CONSTANT_POOL_ADDRESS_P
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->unchanging)
end_define

begin_comment
comment|/* Flag in a SYMBOL_REF for machine-specific purposes.  */
end_comment

begin_define
define|#
directive|define
name|SYMBOL_REF_FLAG
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->volatil)
end_define

begin_comment
comment|/* 1 in a SYMBOL_REF if it represents a symbol which might have to change    if its inlined or unrolled. */
end_comment

begin_define
define|#
directive|define
name|SYMBOL_REF_NEED_ADJUST
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->in_struct)
end_define

begin_comment
comment|/* 1 means a SYMBOL_REF has been the library function in emit_library_call.  */
end_comment

begin_define
define|#
directive|define
name|SYMBOL_REF_USED
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->used)
end_define

begin_comment
comment|/* For an INLINE_HEADER rtx, FIRST_FUNCTION_INSN is the first insn    of the function that is not involved in copying parameters to    pseudo-registers.  FIRST_PARM_INSN is the very first insn of    the function, including the parameter copying.    We keep this around in case we must splice    this function into the assembly code at the end of the file.    FIRST_LABELNO is the first label number used by the function (inclusive).    LAST_LABELNO is the last label used by the function (exclusive).    MAX_REGNUM is the largest pseudo-register used by that function.    FUNCTION_ARGS_SIZE is the size of the argument block in the stack.    POPS_ARGS is the number of bytes of input arguments popped by the function    STACK_SLOT_LIST is the list of stack slots.    FORCED_LABELS is the list of labels whose address was taken.    FUNCTION_FLAGS are where single-bit flags are saved.    OUTGOING_ARGS_SIZE is the size of the largest outgoing stack parameter list.    ORIGINAL_ARG_VECTOR is a vector of the original DECL_RTX values     for the function arguments.    ORIGINAL_DECL_INITIAL is a pointer to the original DECL_INITIAL for the     function.    INLINE_REGNO_REG_RTX, INLINE_REGNO_POINTER_FLAG, and     INLINE_REGNO_POINTER_ALIGN are pointers to the corresponding arrays.     We want this to lay down like an INSN.  The PREV_INSN field    is always NULL.  The NEXT_INSN field always points to the    first function insn of the function being squirreled away.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_FUNCTION_INSN
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[2].rtx)
end_define

begin_define
define|#
directive|define
name|FIRST_PARM_INSN
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[3].rtx)
end_define

begin_define
define|#
directive|define
name|FIRST_LABELNO
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[4].rtint)
end_define

begin_define
define|#
directive|define
name|LAST_LABELNO
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[5].rtint)
end_define

begin_define
define|#
directive|define
name|MAX_PARMREG
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[6].rtint)
end_define

begin_define
define|#
directive|define
name|MAX_REGNUM
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[7].rtint)
end_define

begin_define
define|#
directive|define
name|FUNCTION_ARGS_SIZE
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[8].rtint)
end_define

begin_define
define|#
directive|define
name|POPS_ARGS
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[9].rtint)
end_define

begin_define
define|#
directive|define
name|STACK_SLOT_LIST
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[10].rtx)
end_define

begin_define
define|#
directive|define
name|FORCED_LABELS
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[11].rtx)
end_define

begin_define
define|#
directive|define
name|FUNCTION_FLAGS
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[12].rtint)
end_define

begin_define
define|#
directive|define
name|OUTGOING_ARGS_SIZE
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[13].rtint)
end_define

begin_define
define|#
directive|define
name|ORIGINAL_ARG_VECTOR
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[14].rtvec)
end_define

begin_define
define|#
directive|define
name|ORIGINAL_DECL_INITIAL
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[15].rtx)
end_define

begin_define
define|#
directive|define
name|INLINE_REGNO_REG_RTX
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[16].rtvec)
end_define

begin_define
define|#
directive|define
name|INLINE_REGNO_POINTER_FLAG
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[17].rtstr)
end_define

begin_define
define|#
directive|define
name|INLINE_REGNO_POINTER_ALIGN
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[18].rtstr)
end_define

begin_define
define|#
directive|define
name|PARMREG_STACK_LOC
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->fld[19].rtvec)
end_define

begin_comment
comment|/* In FUNCTION_FLAGS we save some variables computed when emitting the code    for the function and which must be `or'ed into the current flag values when    insns from that function are being inlined.  */
end_comment

begin_comment
comment|/* These ought to be an enum, but non-ANSI compilers don't like that.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_FLAGS_CALLS_ALLOCA
value|01
end_define

begin_define
define|#
directive|define
name|FUNCTION_FLAGS_CALLS_SETJMP
value|02
end_define

begin_define
define|#
directive|define
name|FUNCTION_FLAGS_RETURNS_STRUCT
value|04
end_define

begin_define
define|#
directive|define
name|FUNCTION_FLAGS_RETURNS_PCC_STRUCT
value|010
end_define

begin_define
define|#
directive|define
name|FUNCTION_FLAGS_NEEDS_CONTEXT
value|020
end_define

begin_define
define|#
directive|define
name|FUNCTION_FLAGS_HAS_NONLOCAL_LABEL
value|040
end_define

begin_define
define|#
directive|define
name|FUNCTION_FLAGS_RETURNS_POINTER
value|0100
end_define

begin_define
define|#
directive|define
name|FUNCTION_FLAGS_USES_CONST_POOL
value|0200
end_define

begin_define
define|#
directive|define
name|FUNCTION_FLAGS_CALLS_LONGJMP
value|0400
end_define

begin_define
define|#
directive|define
name|FUNCTION_FLAGS_USES_PIC_OFFSET_TABLE
value|01000
end_define

begin_define
define|#
directive|define
name|FUNCTION_FLAGS_HAS_COMPUTED_JUMP
value|02000
end_define

begin_comment
comment|/* Define a macro to look for REG_INC notes,    but save time on machines where they never exist.  */
end_comment

begin_comment
comment|/* Don't continue this line--convex cc version 4.1 would lose.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|HAVE_PRE_INCREMENT
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_PRE_DECREMENT
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_POST_INCREMENT
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_POST_DECREMENT
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|FIND_REG_INC_NOTE
parameter_list|(
name|insn
parameter_list|,
name|reg
parameter_list|)
value|(find_reg_note ((insn), REG_INC, (reg)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FIND_REG_INC_NOTE
parameter_list|(
name|insn
parameter_list|,
name|reg
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Indicate whether the machine has any sort of auto increment addressing.    If not, we can avoid checking for REG_INC notes.  */
end_comment

begin_comment
comment|/* Don't continue this line--convex cc version 4.1 would lose.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|HAVE_PRE_INCREMENT
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_PRE_DECREMENT
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_POST_INCREMENT
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_POST_DECREMENT
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|AUTO_INC_DEC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_PRE_INCREMENT
end_ifndef

begin_define
define|#
directive|define
name|HAVE_PRE_INCREMENT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_PRE_DECREMENT
end_ifndef

begin_define
define|#
directive|define
name|HAVE_PRE_DECREMENT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_POST_INCREMENT
end_ifndef

begin_define
define|#
directive|define
name|HAVE_POST_INCREMENT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_POST_DECREMENT
end_ifndef

begin_define
define|#
directive|define
name|HAVE_POST_DECREMENT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some architectures do not have complete pre/post increment/decrement    instruction sets, or only move some modes efficiently.  These macros    allow us to tune autoincrement generation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_LOAD_POST_INCREMENT
end_ifndef

begin_define
define|#
directive|define
name|USE_LOAD_POST_INCREMENT
parameter_list|(
name|MODE
parameter_list|)
value|HAVE_POST_INCREMENT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USE_LOAD_POST_DECREMENT
end_ifndef

begin_define
define|#
directive|define
name|USE_LOAD_POST_DECREMENT
parameter_list|(
name|MODE
parameter_list|)
value|HAVE_POST_DECREMENT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USE_LOAD_PRE_INCREMENT
end_ifndef

begin_define
define|#
directive|define
name|USE_LOAD_PRE_INCREMENT
parameter_list|(
name|MODE
parameter_list|)
value|HAVE_PRE_INCREMENT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USE_LOAD_PRE_DECREMENT
end_ifndef

begin_define
define|#
directive|define
name|USE_LOAD_PRE_DECREMENT
parameter_list|(
name|MODE
parameter_list|)
value|HAVE_PRE_DECREMENT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USE_STORE_POST_INCREMENT
end_ifndef

begin_define
define|#
directive|define
name|USE_STORE_POST_INCREMENT
parameter_list|(
name|MODE
parameter_list|)
value|HAVE_POST_INCREMENT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USE_STORE_POST_DECREMENT
end_ifndef

begin_define
define|#
directive|define
name|USE_STORE_POST_DECREMENT
parameter_list|(
name|MODE
parameter_list|)
value|HAVE_POST_DECREMENT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USE_STORE_PRE_INCREMENT
end_ifndef

begin_define
define|#
directive|define
name|USE_STORE_PRE_INCREMENT
parameter_list|(
name|MODE
parameter_list|)
value|HAVE_PRE_INCREMENT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USE_STORE_PRE_DECREMENT
end_ifndef

begin_define
define|#
directive|define
name|USE_STORE_PRE_DECREMENT
parameter_list|(
name|MODE
parameter_list|)
value|HAVE_PRE_DECREMENT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Accessors for RANGE_INFO.  */
end_comment

begin_comment
comment|/* For RANGE_{START,END} notes return the RANGE_START note.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_INFO_NOTE_START
parameter_list|(
name|INSN
parameter_list|)
value|(XEXP (INSN, 0))
end_define

begin_comment
comment|/* For RANGE_{START,END} notes return the RANGE_START note.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_INFO_NOTE_END
parameter_list|(
name|INSN
parameter_list|)
value|(XEXP (INSN, 1))
end_define

begin_comment
comment|/* For RANGE_{START,END} notes, return the vector containing the registers used    in the range.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_INFO_REGS
parameter_list|(
name|INSN
parameter_list|)
value|(XVEC (INSN, 2))
end_define

begin_define
define|#
directive|define
name|RANGE_INFO_REGS_REG
parameter_list|(
name|INSN
parameter_list|,
name|N
parameter_list|)
value|(XVECEXP (INSN, 2, N))
end_define

begin_define
define|#
directive|define
name|RANGE_INFO_NUM_REGS
parameter_list|(
name|INSN
parameter_list|)
value|(XVECLEN (INSN, 2))
end_define

begin_comment
comment|/* For RANGE_{START,END} notes, the number of calls within the range.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_INFO_NCALLS
parameter_list|(
name|INSN
parameter_list|)
value|(XINT (INSN, 3))
end_define

begin_comment
comment|/* For RANGE_{START,END} notes, the number of insns within the range.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_INFO_NINSNS
parameter_list|(
name|INSN
parameter_list|)
value|(XINT (INSN, 4))
end_define

begin_comment
comment|/* For RANGE_{START,END} notes, a unique # to identify this range.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_INFO_UNIQUE
parameter_list|(
name|INSN
parameter_list|)
value|(XINT (INSN, 5))
end_define

begin_comment
comment|/* For RANGE_{START,END} notes, the basic block # the range starts with. */
end_comment

begin_define
define|#
directive|define
name|RANGE_INFO_BB_START
parameter_list|(
name|INSN
parameter_list|)
value|(XINT (INSN, 6))
end_define

begin_comment
comment|/* For RANGE_{START,END} notes, the basic block # the range ends with. */
end_comment

begin_define
define|#
directive|define
name|RANGE_INFO_BB_END
parameter_list|(
name|INSN
parameter_list|)
value|(XINT (INSN, 7))
end_define

begin_comment
comment|/* For RANGE_{START,END} notes, the loop depth the range is in.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_INFO_LOOP_DEPTH
parameter_list|(
name|INSN
parameter_list|)
value|(XINT (INSN, 8))
end_define

begin_comment
comment|/* For RANGE_{START,END} notes, the bitmap of live registers at the start    of the range.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_INFO_LIVE_START
parameter_list|(
name|INSN
parameter_list|)
value|(XBITMAP (INSN, 9))
end_define

begin_comment
comment|/* For RANGE_{START,END} notes, the bitmap of live registers at the end    of the range.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_INFO_LIVE_END
parameter_list|(
name|INSN
parameter_list|)
value|(XBITMAP (INSN, 10))
end_define

begin_comment
comment|/* For RANGE_START notes, the marker # of the start of the range.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_INFO_MARKER_START
parameter_list|(
name|INSN
parameter_list|)
value|(XINT (INSN, 11))
end_define

begin_comment
comment|/* For RANGE_START notes, the marker # of the end of the range.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_INFO_MARKER_END
parameter_list|(
name|INSN
parameter_list|)
value|(XINT (INSN, 12))
end_define

begin_comment
comment|/* Original pseudo register # for a live range note.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_REG_PSEUDO
parameter_list|(
name|INSN
parameter_list|,
name|N
parameter_list|)
value|(XINT (XVECEXP (INSN, 2, N), 0))
end_define

begin_comment
comment|/* Pseudo register # original register is copied into or -1.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_REG_COPY
parameter_list|(
name|INSN
parameter_list|,
name|N
parameter_list|)
value|(XINT (XVECEXP (INSN, 2, N), 1))
end_define

begin_comment
comment|/* How many times a register in a live range note was referenced.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_REG_REFS
parameter_list|(
name|INSN
parameter_list|,
name|N
parameter_list|)
value|(XINT (XVECEXP (INSN, 2, N), 2))
end_define

begin_comment
comment|/* How many times a register in a live range note was set.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_REG_SETS
parameter_list|(
name|INSN
parameter_list|,
name|N
parameter_list|)
value|(XINT (XVECEXP (INSN, 2, N), 3))
end_define

begin_comment
comment|/* How many times a register in a live range note died.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_REG_DEATHS
parameter_list|(
name|INSN
parameter_list|,
name|N
parameter_list|)
value|(XINT (XVECEXP (INSN, 2, N), 4))
end_define

begin_comment
comment|/* Whether the original value is needed to be copied into the range register at    the start of the range. */
end_comment

begin_define
define|#
directive|define
name|RANGE_REG_COPY_FLAGS
parameter_list|(
name|INSN
parameter_list|,
name|N
parameter_list|)
value|(XINT (XVECEXP (INSN, 2, N), 5))
end_define

begin_comment
comment|/* # of insns the register copy is live over.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_REG_LIVE_LENGTH
parameter_list|(
name|INSN
parameter_list|,
name|N
parameter_list|)
value|(XINT (XVECEXP (INSN, 2, N), 6))
end_define

begin_comment
comment|/* # of calls the register copy is live over.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_REG_N_CALLS
parameter_list|(
name|INSN
parameter_list|,
name|N
parameter_list|)
value|(XINT (XVECEXP (INSN, 2, N), 7))
end_define

begin_comment
comment|/* DECL_NODE pointer of the declaration if the register is a user defined    variable.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_REG_SYMBOL_NODE
parameter_list|(
name|INSN
parameter_list|,
name|N
parameter_list|)
value|(XTREE (XVECEXP (INSN, 2, N), 8))
end_define

begin_comment
comment|/* BLOCK_NODE pointer to the block the variable is declared in if the    register is a user defined variable.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_REG_BLOCK_NODE
parameter_list|(
name|INSN
parameter_list|,
name|N
parameter_list|)
value|(XTREE (XVECEXP (INSN, 2, N), 9))
end_define

begin_comment
comment|/* EXPR_LIST of the distinct ranges a variable is in.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_VAR_LIST
parameter_list|(
name|INSN
parameter_list|)
value|(XEXP (INSN, 0))
end_define

begin_comment
comment|/* Block a variable is declared in.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_VAR_BLOCK
parameter_list|(
name|INSN
parameter_list|)
value|(XTREE (INSN, 1))
end_define

begin_comment
comment|/* # of distinct ranges a variable is in.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_VAR_NUM
parameter_list|(
name|INSN
parameter_list|)
value|(XINT (INSN, 2))
end_define

begin_comment
comment|/* For a NOTE_INSN_LIVE note, the registers which are currently live.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_LIVE_BITMAP
parameter_list|(
name|INSN
parameter_list|)
value|(XBITMAP (INSN, 0))
end_define

begin_comment
comment|/* For a NOTE_INSN_LIVE note, the original basic block number.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_LIVE_ORIG_BLOCK
parameter_list|(
name|INSN
parameter_list|)
value|(XINT (INSN, 1))
end_define

begin_escape
end_escape

begin_comment
comment|/* Generally useful functions.  */
end_comment

begin_comment
comment|/* The following functions accept a wide integer argument.  Rather than    having to cast on every function call, we use a macro instead, that is    defined here and in tree.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|exact_log2
end_ifndef

begin_define
define|#
directive|define
name|exact_log2
parameter_list|(
name|N
parameter_list|)
value|exact_log2_wide ((unsigned HOST_WIDE_INT) (N))
end_define

begin_define
define|#
directive|define
name|floor_log2
parameter_list|(
name|N
parameter_list|)
value|floor_log2_wide ((unsigned HOST_WIDE_INT) (N))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|exact_log2_wide
name|PROTO
argument_list|(
operator|(
name|unsigned
name|HOST_WIDE_INT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|floor_log2_wide
name|PROTO
argument_list|(
operator|(
name|unsigned
name|HOST_WIDE_INT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In expmed.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ceil_log2
name|PROTO
argument_list|(
operator|(
name|unsigned
name|HOST_WIDE_INT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|plus_constant
parameter_list|(
name|X
parameter_list|,
name|C
parameter_list|)
value|plus_constant_wide (X, (HOST_WIDE_INT) (C))
end_define

begin_define
define|#
directive|define
name|plus_constant_for_output
parameter_list|(
name|X
parameter_list|,
name|C
parameter_list|)
define|\
value|plus_constant_for_output_wide (X, (HOST_WIDE_INT) (C))
end_define

begin_comment
comment|/* In explow.c */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|plus_constant_wide
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|HOST_WIDE_INT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|plus_constant_for_output_wide
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|HOST_WIDE_INT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|optimize_save_area_alloca
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_rtx
name|PVPROTO
argument_list|(
operator|(
expr|enum
name|rtx_code
operator|,
expr|enum
name|machine_mode
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtvec
name|gen_rtvec
name|PVPROTO
argument_list|(
operator|(
name|int
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|rtx
name|read_rtx
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|oballoc
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|permalloc
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|rtx_alloc
name|PROTO
argument_list|(
operator|(
name|RTX_CODE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtvec
name|rtvec_alloc
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|copy_rtx
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|copy_rtx_if_shared
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|copy_most_rtx
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|shallow_copy_rtx
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtvec
name|gen_rtvec_v
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|rtx
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtvec
name|gen_rtvec_vv
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|rtunion
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_reg_rtx
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_label_rtx
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_inline_header_rtx
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|int
operator|,
name|int
operator|,
name|rtvec
operator|,
name|rtx
operator|,
name|rtvec
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|rtvec
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_lowpart_common
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_lowpart
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_lowpart_if_possible
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_highpart
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_realpart
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_imagpart
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|operand_subword
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|,
name|int
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|operand_subword_force
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|subreg_lowpart_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|make_safe_from
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|convert_memory_address
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|memory_address
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|get_insns
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|get_last_insn
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|get_last_insn_anywhere
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|start_sequence
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|push_to_sequence
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|end_sequence
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_sequence
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|immed_double_const
name|PROTO
argument_list|(
operator|(
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|force_const_mem
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|force_reg
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|get_pool_constant
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|machine_mode
name|get_pool_mode
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|get_pool_offset
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|simplify_subtraction
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|assign_stack_local
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|HOST_WIDE_INT
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|assign_stack_temp
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|HOST_WIDE_INT
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|assign_temp
name|PROTO
argument_list|(
operator|(
expr|union
name|tree_node
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|protect_from_queue
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|emit_queue
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_move_insn
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_insn_before
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_jump_insn_before
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_call_insn_before
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_barrier_before
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_label_before
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_note_before
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_insn_after
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_jump_insn_after
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_barrier_after
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_label_after
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_note_after
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_line_note_after
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_insn
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_insns
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_insns_before
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_insns_after
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_jump_insn
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_call_insn
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_label
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_barrier
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_line_note
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_note
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_line_note_force
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|make_insn_raw
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|previous_insn
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|next_insn
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|prev_nonnote_insn
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|next_nonnote_insn
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|prev_real_insn
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|next_real_insn
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|prev_active_insn
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|next_active_insn
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|prev_label
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|next_label
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|next_cc0_user
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|prev_cc0_setter
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|next_nondeleted_insn
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|rtx_code
name|reverse_condition
name|PROTO
argument_list|(
operator|(
expr|enum
name|rtx_code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|rtx_code
name|swap_condition
name|PROTO
argument_list|(
operator|(
expr|enum
name|rtx_code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|rtx_code
name|unsigned_condition
name|PROTO
argument_list|(
operator|(
expr|enum
name|rtx_code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|rtx_code
name|signed_condition
name|PROTO
argument_list|(
operator|(
expr|enum
name|rtx_code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|find_equiv_reg
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
expr|enum
name|reg_class
operator|,
name|int
operator|,
name|short
operator|*
operator|,
name|int
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|squeeze_notes
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|delete_insn
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|delete_jump
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|get_label_before
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|get_label_after
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|follow_jumps
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|adj_offsettable_operand
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|try_split
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|split_insns
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|simplify_unary_operation
name|PROTO
argument_list|(
operator|(
expr|enum
name|rtx_code
operator|,
expr|enum
name|machine_mode
operator|,
name|rtx
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|simplify_binary_operation
name|PROTO
argument_list|(
operator|(
expr|enum
name|rtx_code
operator|,
expr|enum
name|machine_mode
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|simplify_ternary_operation
name|PROTO
argument_list|(
operator|(
expr|enum
name|rtx_code
operator|,
expr|enum
name|machine_mode
operator|,
expr|enum
name|machine_mode
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|simplify_relational_operation
name|PROTO
argument_list|(
operator|(
expr|enum
name|rtx_code
operator|,
expr|enum
name|machine_mode
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_move_insn
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_jump
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_beq
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_bge
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_ble
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_mem_addressof
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|union
name|tree_node
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|eliminate_constant_term
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|expand_complex_abs
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|machine_mode
name|choose_hard_reg_mode
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_unique_reg_note
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|reg_note
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Functions in rtlanal.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rtx_unstable_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rtx_varies_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rtx_addr_varies_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|HOST_WIDE_INT
name|get_integer_term
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|get_related_value
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|reg_mentioned_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|reg_referenced_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|reg_used_between_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|reg_referenced_between_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|reg_set_between_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|regs_set_between_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|modified_between_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|no_labels_between_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|no_jumps_between_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|modified_in_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|reg_set_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|single_set
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|multiple_sets
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|find_last_value
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|*
operator|,
name|rtx
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|refers_to_regno_p
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|rtx
operator|,
name|rtx
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|reg_overlap_mentioned_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|note_stores
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|rtx
argument_list|,
name|rtx
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|reg_set_last
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rtx_equal_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dead_or_set_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dead_or_set_regno_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|find_reg_note
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|reg_note
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|find_regno_note
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|reg_note
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|find_reg_fusage
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|rtx_code
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|find_regno_fusage
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|rtx_code
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|remove_note
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|side_effects_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|volatile_refs_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|volatile_insn_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|may_trap_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inequality_comparisons_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|replace_rtx
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|replace_regs
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|computed_jump_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*rtx_function
argument_list|)
name|PROTO
argument_list|(
operator|(
name|rtx
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|for_each_rtx
name|PROTO
argument_list|(
operator|(
name|rtx
operator|*
operator|,
name|rtx_function
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|regno_use_in
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|auto_inc_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|remove_node_from_expr_list
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|insns_safe_to_move_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flow.c */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|find_use_as_address
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|HOST_WIDE_INT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* regclass.c */
end_comment

begin_comment
comment|/* Maximum number of parallel sets and clobbers in any insn in this fn.    Always at least 3, since the combiner could put that many togetherm    and we want this to remain correct for all the remaining passes.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|max_parallel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Free up register info memory.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|free_reg_info
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* recog.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|asm_noperands
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|decode_asm_operands
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|*
operator|,
name|rtx
operator|*
operator|*
operator|,
specifier|const
name|char
operator|*
operator|*
operator|,
expr|enum
name|machine_mode
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|reg_class
name|reg_preferred_class
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|reg_class
name|reg_alternate_class
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|get_first_nonparm_insn
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|split_block_insns
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|update_flow_info
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Standard pieces of rtx, to be substituted directly into things.  */
end_comment

begin_define
define|#
directive|define
name|pc_rtx
value|(&global_rtl.pc_val)
end_define

begin_define
define|#
directive|define
name|cc0_rtx
value|(&global_rtl.cc0_val)
end_define

begin_define
define|#
directive|define
name|MAX_SAVED_CONST_INT
value|64
end_define

begin_decl_stmt
specifier|extern
name|struct
name|rtx_def
name|const_int_rtx
index|[
name|MAX_SAVED_CONST_INT
operator|*
literal|2
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|const0_rtx
value|(&const_int_rtx[MAX_SAVED_CONST_INT])
end_define

begin_define
define|#
directive|define
name|const1_rtx
value|(&const_int_rtx[MAX_SAVED_CONST_INT+1])
end_define

begin_define
define|#
directive|define
name|const2_rtx
value|(&const_int_rtx[MAX_SAVED_CONST_INT+2])
end_define

begin_define
define|#
directive|define
name|constm1_rtx
value|(&const_int_rtx[MAX_SAVED_CONST_INT-1])
end_define

begin_decl_stmt
specifier|extern
name|rtx
name|const_true_rtx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|const_tiny_rtx
index|[
literal|3
index|]
index|[
operator|(
name|int
operator|)
name|MAX_MACHINE_MODE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Returns a constant 0 rtx in mode MODE.  Integer modes are treated the     same as VOIDmode.  */
end_comment

begin_define
define|#
directive|define
name|CONST0_RTX
parameter_list|(
name|MODE
parameter_list|)
value|(const_tiny_rtx[0][(int) (MODE)])
end_define

begin_comment
comment|/* Likewise, for the constants 1 and 2.  */
end_comment

begin_define
define|#
directive|define
name|CONST1_RTX
parameter_list|(
name|MODE
parameter_list|)
value|(const_tiny_rtx[1][(int) (MODE)])
end_define

begin_define
define|#
directive|define
name|CONST2_RTX
parameter_list|(
name|MODE
parameter_list|)
value|(const_tiny_rtx[2][(int) (MODE)])
end_define

begin_struct
specifier|extern
struct|struct
name|_global_rtl
block|{
name|struct
name|rtx_def
name|pc_val
decl_stmt|,
name|cc0_val
decl_stmt|;
name|struct
name|rtx_def
name|stack_pointer_val
decl_stmt|,
name|frame_pointer_val
decl_stmt|;
name|struct
name|rtx_def
name|hard_frame_pointer_val
decl_stmt|;
name|struct
name|rtx_def
name|arg_pointer_val
decl_stmt|;
name|struct
name|rtx_def
name|virtual_incoming_args_val
decl_stmt|;
name|struct
name|rtx_def
name|virtual_stack_vars_val
decl_stmt|;
name|struct
name|rtx_def
name|virtual_stack_dynamic_val
decl_stmt|;
name|struct
name|rtx_def
name|virtual_outgoing_args_val
decl_stmt|;
name|struct
name|rtx_def
name|virtual_cfa_val
decl_stmt|;
block|}
name|global_rtl
struct|;
end_struct

begin_comment
comment|/* All references to certain hard regs, except those created    by allocating pseudo regs into them (when that's possible),    go through these unique rtx objects.  */
end_comment

begin_define
define|#
directive|define
name|stack_pointer_rtx
value|(&global_rtl.stack_pointer_val)
end_define

begin_define
define|#
directive|define
name|frame_pointer_rtx
value|(&global_rtl.frame_pointer_val)
end_define

begin_decl_stmt
specifier|extern
name|rtx
name|pic_offset_table_rtx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|struct_value_rtx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|struct_value_incoming_rtx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|static_chain_rtx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|static_chain_incoming_rtx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|return_address_pointer_rtx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Include the RTL generation functions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_GENRTL_H
end_ifndef

begin_include
include|#
directive|include
file|"genrtl.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* There are some RTL codes that require special attention; the    generation functions included above do the raw handling.  If you    add to this list, modify special_rtx in gengenrtl.c as well.  You    should also modify gen_rtx to use the special function.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|gen_rtx_CONST_DOUBLE
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|rtx
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_rtx_CONST_INT
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|HOST_WIDE_INT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_rtx_REG
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gen_rtx_MEM
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* We need the cast here to ensure that we get the same result both with    and without prototypes.  */
end_comment

begin_define
define|#
directive|define
name|GEN_INT
parameter_list|(
name|N
parameter_list|)
value|gen_rtx_CONST_INT (VOIDmode, (HOST_WIDE_INT) (N))
end_define

begin_comment
comment|/* If HARD_FRAME_POINTER_REGNUM is defined, then a special dummy reg    is used to represent the frame pointer.  This is because the    hard frame pointer and the automatic variables are separated by an amount    that cannot be determined until after register allocation.  We can assume    that in this case ELIMINABLE_REGS will be defined, one action of which    will be to eliminate FRAME_POINTER_REGNUM into HARD_FRAME_POINTER_REGNUM. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HARD_FRAME_POINTER_REGNUM
end_ifndef

begin_define
define|#
directive|define
name|HARD_FRAME_POINTER_REGNUM
value|FRAME_POINTER_REGNUM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For register elimination to work properly these hard_frame_pointer_rtx,    frame_pointer_rtx, and arg_pointer_rtx must be the same if they refer to    the same register.  */
end_comment

begin_if
if|#
directive|if
name|HARD_FRAME_POINTER_REGNUM
operator|==
name|FRAME_POINTER_REGNUM
end_if

begin_define
define|#
directive|define
name|hard_frame_pointer_rtx
value|(&global_rtl.frame_pointer_val)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|hard_frame_pointer_rtx
value|(&global_rtl.hard_frame_pointer_val)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FRAME_POINTER_REGNUM
operator|==
name|ARG_POINTER_REGNUM
end_if

begin_define
define|#
directive|define
name|arg_pointer_rtx
value|(&global_rtl.frame_pointer_val)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HARD_FRAME_POINTER_REGNUM
operator|==
name|ARG_POINTER_REGNUM
end_if

begin_define
define|#
directive|define
name|arg_pointer_rtx
value|(&global_rtl.hard_frame_pointer_val)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|arg_pointer_rtx
value|(&global_rtl.arg_pointer_val)
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
comment|/* Virtual registers are used during RTL generation to refer to locations into    the stack frame when the actual location isn't known until RTL generation    is complete.  The routine instantiate_virtual_regs replaces these with    the proper value, which is normally {frame,arg,stack}_pointer_rtx plus    a constant.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_VIRTUAL_REGISTER
value|(FIRST_PSEUDO_REGISTER)
end_define

begin_comment
comment|/* This points to the first word of the incoming arguments passed on the stack,    either by the caller or by the callee when pretending it was passed by the    caller.  */
end_comment

begin_define
define|#
directive|define
name|virtual_incoming_args_rtx
value|(&global_rtl.virtual_incoming_args_val)
end_define

begin_define
define|#
directive|define
name|VIRTUAL_INCOMING_ARGS_REGNUM
value|(FIRST_VIRTUAL_REGISTER)
end_define

begin_comment
comment|/* If FRAME_GROWS_DOWNWARD, this points to immediately above the first    variable on the stack.  Otherwise, it points to the first variable on    the stack.  */
end_comment

begin_define
define|#
directive|define
name|virtual_stack_vars_rtx
value|(&global_rtl.virtual_stack_vars_val)
end_define

begin_define
define|#
directive|define
name|VIRTUAL_STACK_VARS_REGNUM
value|((FIRST_VIRTUAL_REGISTER) + 1)
end_define

begin_comment
comment|/* This points to the location of dynamically-allocated memory on the stack    immediately after the stack pointer has been adjusted by the amount    desired.  */
end_comment

begin_define
define|#
directive|define
name|virtual_stack_dynamic_rtx
value|(&global_rtl.virtual_stack_dynamic_val)
end_define

begin_define
define|#
directive|define
name|VIRTUAL_STACK_DYNAMIC_REGNUM
value|((FIRST_VIRTUAL_REGISTER) + 2)
end_define

begin_comment
comment|/* This points to the location in the stack at which outgoing arguments should    be written when the stack is pre-pushed (arguments pushed using push    insns always use sp).  */
end_comment

begin_define
define|#
directive|define
name|virtual_outgoing_args_rtx
value|(&global_rtl.virtual_outgoing_args_val)
end_define

begin_define
define|#
directive|define
name|VIRTUAL_OUTGOING_ARGS_REGNUM
value|((FIRST_VIRTUAL_REGISTER) + 3)
end_define

begin_comment
comment|/* This points to the Canonical Frame Address of the function.  This    should corrospond to the CFA produced by INCOMING_FRAME_SP_OFFSET,    but is calculated relative to the arg pointer for simplicity; the    frame pointer nor stack pointer are necessarily fixed relative to     the CFA until after reload.  */
end_comment

begin_define
define|#
directive|define
name|virtual_cfa_rtx
value|(&global_rtl.virtual_cfa_val)
end_define

begin_define
define|#
directive|define
name|VIRTUAL_CFA_REGNUM
value|((FIRST_VIRTUAL_REGISTER) + 4)
end_define

begin_define
define|#
directive|define
name|LAST_VIRTUAL_REGISTER
value|((FIRST_VIRTUAL_REGISTER) + 4)
end_define

begin_decl_stmt
specifier|extern
name|rtx
name|find_next_ref
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
modifier|*
name|find_single_use
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|output_constant_def
name|PROTO
argument_list|(
operator|(
expr|union
name|tree_node
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|immed_real_const
name|PROTO
argument_list|(
operator|(
expr|union
name|tree_node
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|union
name|tree_node
modifier|*
name|make_tree
name|PROTO
argument_list|(
operator|(
expr|union
name|tree_node
operator|*
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define a default value for STORE_FLAG_VALUE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STORE_FLAG_VALUE
end_ifndef

begin_define
define|#
directive|define
name|STORE_FLAG_VALUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Nonzero after the second flow pass has completed.    Set to 1 or 0 by toplev.c  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flow2_completed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero after end of reload pass.    Set to 1 or 0 by reload1.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|reload_completed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set to 1 while reload_as_needed is operating.    Required by some machines to handle any generated moves differently.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|reload_in_progress
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If this is nonzero, we do not bother generating VOLATILE    around volatile memory references, and we are willing to    output indirect addresses.  If cse is to follow, we reject    indirect addresses so a useful potential cse is generated;    if it is used only once, instruction combination will produce    the same indirect address eventually.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cse_not_expected
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set to nonzero before life analysis to indicate that it is unsafe to    generate any new pseudo registers.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|no_new_pseudos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Indexed by pseudo register number, gives the rtx for that pseudo.    Allocated in parallel with regno_pointer_flag.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
modifier|*
name|regno_reg_rtx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Vector indexed by regno; contain the alignment in bytes and type    pointed to for a register that contains a pointer, if known.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|regno_pointer_align
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|REGNO_POINTER_ALIGN
parameter_list|(
name|REGNO
parameter_list|)
value|regno_pointer_align[REGNO]
end_define

begin_comment
comment|/* Translates rtx code to tree code, for those codes needed by    REAL_ARITHMETIC.  The function returns an int because the caller may not    know what `enum tree_code' means.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rtx_to_tree_code
name|PROTO
argument_list|(
operator|(
expr|enum
name|rtx_code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In tree.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|obfree
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|obstack
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|void
name|gcc_obstack_init
name|PROTO
argument_list|(
operator|(
expr|struct
name|obstack
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pop_obstacks
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|push_obstacks
name|PROTO
argument_list|(
operator|(
expr|struct
name|obstack
operator|*
operator|,
expr|struct
name|obstack
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|read_skip_spaces
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In cse.c */
end_comment

begin_struct_decl
struct_decl|struct
name|cse_basic_block_data
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|int
name|rtx_cost
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|rtx_code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|delete_trivially_dead_insns
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|cse_main
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|,
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|cse_end_of_basic_block
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|struct
name|cse_basic_block_data
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In jump.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|comparison_dominates_p
name|PROTO
argument_list|(
operator|(
expr|enum
name|rtx_code
operator|,
expr|enum
name|rtx_code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|condjump_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|condjump_label
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|simplejump_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|returnjump_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sets_cc0_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|invert_jump
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rtx_renumbered_equal_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|true_regnum
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|redirect_jump
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|jump_optimize
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rebuild_jump_labels
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|thread_jumps
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|redirect_exp
name|PROTO
argument_list|(
operator|(
name|rtx
operator|*
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rtx_equal_for_thread_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|invert_exp
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|can_reverse_comparison_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|delete_for_peephole
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|condjump_in_parallel_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flags for jump_optimize() */
end_comment

begin_define
define|#
directive|define
name|JUMP_CROSS_JUMP
value|1
end_define

begin_define
define|#
directive|define
name|JUMP_NOOP_MOVES
value|1
end_define

begin_define
define|#
directive|define
name|JUMP_AFTER_REGSCAN
value|1
end_define

begin_comment
comment|/* In emit-rtl.c. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|max_reg_num
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|max_label_num
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|get_first_label_num
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|delete_insns_since
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mark_reg_pointer
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mark_user_reg
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|reset_used_flags
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|reorder_insns
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|get_max_uid
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|in_sequence_p
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|force_next_line_note
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_emit
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_emit_once
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|push_topmost_sequence
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pop_topmost_sequence
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|subreg_realpart_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|reverse_comparison
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_new_first_and_last_insn
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_new_first_and_last_label_num
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|unshare_all_rtl_again
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_last_insn
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|link_cc0_insns
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|add_insn
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|add_insn_before
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|add_insn_after
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|remove_insn
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|reorder_insns_with_line_notes
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|emit_insn_after_with_line_notes
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|rtx_code
name|classify_insn
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_virtual_regs
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Query and clear/ restore no_line_numbers.  This is used by the    switch / case handling in stmt.c to give proper line numbers in    warnings about unreachable code.  */
end_comment

begin_decl_stmt
name|int
name|force_line_numbers
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|restore_line_number_status
name|PROTO
argument_list|(
operator|(
name|int
name|old_value
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In insn-emit.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|add_clobbers
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In combine.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|combine_instructions
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|extended_count
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|machine_mode
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|remove_death
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|dump_combine_stats
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_combine_total_stats
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In sched.c. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|schedule_insns
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAIFA
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|fix_sched_param
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In print-rtl.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|debug_rtx
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|debug_rtx_list
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|debug_rtx_find
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|print_rtl
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|print_rtl_single
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_inline_rtx
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|rtx
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In loop.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_loop
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|libcall_other_reg
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|loop_optimize
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|FILE
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|record_excess_regs
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In function.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|reposition_prologue_and_epilogue_notes
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|thread_prologue_and_epilogue_insns
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|use_variable
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|HOST_WIDE_INT
name|get_frame_size
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|preserve_rtl_expr_result
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mark_temp_addr_taken
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|update_temp_slot_address
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|use_variable_after
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|purge_addressof
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In reload.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|operands_match_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|safe_from_earlyclobber
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In stmt.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|expand_null_return
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|emit_jump
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|preserve_subexpressions_p
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List (chain of EXPR_LIST) of labels heading the current handlers for    nonlocal gotos.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|nonlocal_goto_handler_labels
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In expr.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_expr_once
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|move_by_pieces
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In stupid.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|stupid_life_analysis
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In flow.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|allocate_bb_life_data
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|allocate_reg_life_data
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|recompute_reg_usage
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|dump_flow_info
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|free_bb_mem
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In expmed.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_expmed
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|expand_inc
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|expand_dec
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|expand_mult_highpart
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|rtx
operator|,
name|unsigned
name|HOST_WIDE_INT
operator|,
name|rtx
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In gcse.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|gcse_main
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In global.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|mark_elimination
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|global_alloc
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_global_regs
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HARD_CONST
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|retry_global_alloc
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|HARD_REG_SET
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In regclass.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|reg_classes_intersect_p
name|PROTO
argument_list|(
operator|(
expr|enum
name|reg_class
operator|,
expr|enum
name|reg_class
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|reg_class_subset_p
name|PROTO
argument_list|(
operator|(
expr|enum
name|reg_class
operator|,
expr|enum
name|reg_class
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|globalize_reg
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_regs
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_reg_sets
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|regset_release_memory
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|regclass_init
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|regclass
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|reg_scan
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|reg_scan_update
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fix_register
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In regmove.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|regmove_optimize
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In reorg.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|dbr_schedule
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In optabs.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_optabs
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In local-alloc.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|dump_local_alloc
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|local_alloc
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|function_invariant_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In reload1.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|reload_cse_regs
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_reload
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mark_home_live
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|reload
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In caller-save.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_caller_save
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In profile.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_branch_prob
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|branch_prob
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|end_branch_prob
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|output_func_start_profiler
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In reg-stack.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|reg_to_stack
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|stack_regs_mentioned_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In fold-const.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|add_double
name|PROTO
argument_list|(
operator|(
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|*
operator|,
name|HOST_WIDE_INT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|neg_double
name|PROTO
argument_list|(
operator|(
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|*
operator|,
name|HOST_WIDE_INT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mul_double
name|PROTO
argument_list|(
operator|(
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|*
operator|,
name|HOST_WIDE_INT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|lshift_double
name|PROTO
argument_list|(
operator|(
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|int
operator|,
name|HOST_WIDE_INT
operator|*
operator|,
name|HOST_WIDE_INT
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rshift_double
name|PROTO
argument_list|(
operator|(
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|int
operator|,
name|HOST_WIDE_INT
operator|*
operator|,
name|HOST_WIDE_INT
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|lrotate_double
name|PROTO
argument_list|(
operator|(
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|int
operator|,
name|HOST_WIDE_INT
operator|*
operator|,
name|HOST_WIDE_INT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rrotate_double
name|PROTO
argument_list|(
operator|(
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|int
operator|,
name|HOST_WIDE_INT
operator|*
operator|,
name|HOST_WIDE_INT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In calls.c */
end_comment

begin_comment
comment|/* Emit library call.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|emit_library_call
name|PVPROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|,
expr|enum
name|machine_mode
operator|,
name|int
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_library_call_value
name|PVPROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|int
operator|,
expr|enum
name|machine_mode
operator|,
name|int
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In unroll.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|set_dominates_use
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In varasm.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|bss_section
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|in_data_section
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|supports_one_only
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In rtl.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_rtl
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rtx_free
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In alias.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|true_dependence
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|machine_mode
operator|,
name|rtx
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|rtx
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|read_dependence
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|anti_dependence
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|output_dependence
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_alias_once
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_alias_analysis
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|end_alias_analysis
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|record_base_value
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|rtx
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|record_alias_subset
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|addr_side_effect_eval
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|STACK_REGS
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|stack_regs_mentioned
name|PROTO
argument_list|(
operator|(
name|rtx
name|insn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RTL_H */
end_comment

end_unit

