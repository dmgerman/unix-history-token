begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Register Transfer Language (RTL) definitions for GNU C-Compiler    Copyright (C) 1987, 91, 92, 93, 94, 1995 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

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
value|(rtx_length[(int)(CODE)])
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
value|(rtx_name[(int)(CODE)])
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
value|(rtx_format[(int)(CODE)])
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
value|(rtx_class[(int)(CODE)])
end_define

begin_escape
end_escape

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
comment|/* 1 in an INSN if it can alter flow of control      within this function.  Not yet used!  */
name|unsigned
name|int
name|jump
range|:
literal|1
decl_stmt|;
comment|/* 1 in an INSN if it can call another function.  Not yet used!  */
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
comment|/* 1 in a MEM referring to a field of a structure (not a union!).      0 if the MEM was a variable or the result of a * operator in C;      1 if it was the result of a . or -> operator (on a struct) in C.      1 in a REG if the register is used only in exit code a loop.      1 in a SUBREG expression if was generated from a variable with a       promoted mode.      1 in a CODE_LABEL if the label is used for nonlocal gotos      and must not be deleted even if its count is zero.      1 in a LABEL_REF if this is a reference to a label outside the      current loop.      1 in an INSN, JUMP_INSN, or CALL_INSN if this insn must be scheduled      together with the preceding insn.  Valid only within sched.      1 in an INSN, JUMP_INSN, or CALL_INSN if insn is in a delay slot and      from the target of a branch.  Valid from reorg until end of compilation;      cleared before used.  */
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

begin_comment
comment|/* Add prototype support.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PROTO
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_PROTOTYPES
argument_list|)
condition|?
name|USE_PROTOTYPES
expr|:
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|PROTO
parameter_list|(
name|ARGS
parameter_list|)
value|ARGS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PROTO
parameter_list|(
name|ARGS
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VPROTO
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|PVPROTO
parameter_list|(
name|ARGS
parameter_list|)
value|ARGS
end_define

begin_define
define|#
directive|define
name|VPROTO
parameter_list|(
name|ARGS
parameter_list|)
value|ARGS
end_define

begin_define
define|#
directive|define
name|VA_START
parameter_list|(
name|va_list
parameter_list|,
name|var
parameter_list|)
value|va_start(va_list,var)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PVPROTO
parameter_list|(
name|ARGS
parameter_list|)
value|()
end_define

begin_define
define|#
directive|define
name|VPROTO
parameter_list|(
name|ARGS
parameter_list|)
value|(va_alist) va_dcl
end_define

begin_define
define|#
directive|define
name|VA_START
parameter_list|(
name|va_list
parameter_list|,
name|var
parameter_list|)
value|va_start(va_list)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDIO_PROTO
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_define
define|#
directive|define
name|STDIO_PROTO
parameter_list|(
name|ARGS
parameter_list|)
value|PROTO(ARGS)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STDIO_PROTO
parameter_list|(
name|ARGS
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NULL_RTX
value|(rtx) 0
end_define

begin_comment
comment|/* Define a generic NULL if one hasn't already been defined.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GENERIC_PTR
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_PROTOTYPES
argument_list|)
condition|?
name|USE_PROTOTYPES
expr|:
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|GENERIC_PTR
value|void *
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GENERIC_PTR
value|char *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NULL_PTR
end_ifndef

begin_define
define|#
directive|define
name|NULL_PTR
value|((GENERIC_PTR)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* RTL vector.  These appear inside RTX's when there is a need    for a variable number of things.  The principle use is inside    PARALLEL expressions.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rtvec_def
block|{
name|unsigned
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
value|((RTVEC)->num_elem = (unsigned) NUM)
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
value|(GET_CODE (X) == LABEL_REF || GET_CODE (X) == SYMBOL_REF		\    || GET_CODE (X) == CONST_INT || GET_CODE (X) == CONST_DOUBLE		\    || GET_CODE (X) == CONST || GET_CODE (X) == HIGH)
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
comment|/* Holds a list of notes on what this insn does to various REGs.    It is a chain of EXPR_LIST rtx's, where the second operand    is the chain pointer and the first operand is the REG being described.    The mode field of the EXPR_LIST contains not a real machine mode    but a value that says what this note says about the REG:      REG_DEAD means that the value in REG dies in this insn (i.e., it is    not needed past this insn).  If REG is set in this insn, the REG_DEAD    note may, but need not, be omitted.      REG_INC means that the REG is autoincremented or autodecremented.      REG_EQUIV describes the insn as a whole; it says that the    insn sets a register to a constant value or to be equivalent to    a memory address.  If the    register is spilled to the stack then the constant value    should be substituted for it.  The contents of the REG_EQUIV    is the constant value or memory address, which may be different    from the source of the SET although it has the same value.       REG_EQUAL is like REG_EQUIV except that the destination    is only momentarily equal to the specified rtx.  Therefore, it    cannot be used for substitution; but it can be used for cse.      REG_RETVAL means that this insn copies the return-value of    a library call out of the hard reg for return values.  This note    is actually an INSN_LIST and it points to the first insn involved    in setting up arguments for the call.  flow.c uses this to delete    the entire library call when its result is dead.      REG_LIBCALL is the inverse of REG_RETVAL: it goes on the first insn    of the library call and points at the one that has the REG_RETVAL.      REG_WAS_0 says that the register set in this insn held 0 before the insn.    The contents of the note is the insn that stored the 0.    If that insn is deleted or patched to a NOTE, the REG_WAS_0 is inoperative.    The REG_WAS_0 note is actually an INSN_LIST, not an EXPR_LIST.      REG_NONNEG means that the register is always nonnegative during    the containing loop.  This is used in branches so that decrement and    branch instructions terminating on zero can be matched.  There must be    an insn pattern in the md file named `decrement_and_branch_until_zero'    or else this will never be added to any instructions.      REG_NO_CONFLICT means there is no conflict *after this insn*    between the register in the note and the destination of this insn.      REG_UNUSED identifies a register set in this insn and never used.      REG_CC_SETTER and REG_CC_USER link a pair of insns that set and use    CC0, respectively.  Normally, these are required to be consecutive insns,    but we permit putting a cc0-setting insn in the delay slot of a branch    as long as only one copy of the insn exists.  In that case, these notes    point from one to the other to allow code generation to determine what    any require information and to properly update CC_STATUS.      REG_LABEL points to a CODE_LABEL.  Used by non-JUMP_INSNs to    say that the CODE_LABEL contained in the REG_LABEL note is used    by the insn.      REG_DEP_ANTI is used in LOG_LINKS which represent anti (write after read)    dependencies.  REG_DEP_OUTPUT is used in LOG_LINKS which represent output    (write after write) dependencies.  Data dependencies, which are the only    type of LOG_LINK created by flow, are represented by a 0 reg note kind.  */
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
block|}
enum|;
end_enum

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
value|(reg_note_name[(int)(MODE)])
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
comment|/* In a NOTE that is a line number, this is a string for the file name    that the line is in.  We use the same field to record block numbers    temporarily in NOTE_INSN_BLOCK_BEG and NOTE_INSN_BLOCK_END notes.    (We avoid lots of casts between ints and pointers if we use a    different macro for the bock number.)  */
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
comment|/* The rest is used instead of the above, in a CODE_LABEL,    if bytecode is being output.    We make the slightly kludgy assumption that a LABEL has enough slots    to hold these things.  That happens to be true.  */
end_comment

begin_comment
comment|/* For static or external objects.  */
end_comment

begin_define
define|#
directive|define
name|BYTECODE_LABEL
parameter_list|(
name|X
parameter_list|)
value|(XEXP ((X), 0))
end_define

begin_comment
comment|/* For goto labels inside bytecode functions.  */
end_comment

begin_define
define|#
directive|define
name|BYTECODE_BC_LABEL
parameter_list|(
name|X
parameter_list|)
value|(*(struct bc_label **)&XEXP ((X), 1))
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
value|((LABEL)->fld[5].rtx)
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
comment|/* For a MEM rtx, 1 if it refers to a structure or union component.  */
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
comment|/* For an INLINE_HEADER rtx, FIRST_FUNCTION_INSN is the first insn    of the function that is not involved in copying parameters to    pseudo-registers.  FIRST_PARM_INSN is the very first insn of    the function, including the parameter copying.    We keep this around in case we must splice    this function into the assembly code at the end of the file.    FIRST_LABELNO is the first label number used by the function (inclusive).    LAST_LABELNO is the last label used by the function (exclusive).    MAX_REGNUM is the largest pseudo-register used by that function.    FUNCTION_ARGS_SIZE is the size of the argument block in the stack.    POPS_ARGS is the number of bytes of input arguments popped by the function    STACK_SLOT_LIST is the list of stack slots.    FORCED_LABELS is the list of labels whose address was taken.    FUNCTION_FLAGS are where single-bit flags are saved.    OUTGOING_ARGS_SIZE is the size of the largest outgoing stack parameter list.    ORIGINAL_ARG_VECTOR is a vector of the original DECL_RTX values     for the function arguments.    ORIGINAL_DECL_INITIAL is a pointer to the original DECL_INITIAL for the     function.     We want this to lay down like an INSN.  The PREV_INSN field    is always NULL.  The NEXT_INSN field always points to the    first function insn of the function being squirreled away.  */
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
value|exact_log2_wide ((HOST_WIDE_INT) (N))
end_define

begin_define
define|#
directive|define
name|floor_log2
parameter_list|(
name|N
parameter_list|)
value|floor_log2_wide ((HOST_WIDE_INT) (N))
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|GEN_INT
parameter_list|(
name|N
parameter_list|)
value|gen_rtx (CONST_INT, VOIDmode, (HOST_WIDE_INT) (N))
end_define

begin_function_decl
specifier|extern
name|rtx
name|bc_gen_rtx
parameter_list|()
function_decl|;
end_function_decl

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

begin_decl_stmt
specifier|extern
name|rtx
name|read_rtx
name|STDIO_PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* At present, don't prototype xrealloc, since all of the callers don't    cast their pointers to char *, and all of the xrealloc's don't use    void * yet.  */
end_comment

begin_else
unit|extern char *xmalloc			PROTO((size_t)); extern char *xrealloc			PROTO((void *, size_t));
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|char
modifier|*
name|xmalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|xrealloc
parameter_list|()
function_decl|;
end_function_decl

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
name|void
name|free
name|PROTO
argument_list|(
operator|(
name|void
operator|*
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
name|assign_stack_temp
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
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
name|nonlocal_label_rtx_list
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

begin_comment
comment|/* Maximum number of parallel sets and clobbers in any insn in this fn.    Always at least 3, since the combiner could put that many togetherm    and we want this to remain correct for all the remaining passes.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|max_parallel
decl_stmt|;
end_decl_stmt

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

begin_comment
comment|/* Standard pieces of rtx, to be substituted directly into things.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|pc_rtx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|cc0_rtx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|const0_rtx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|const1_rtx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|const2_rtx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|constm1_rtx
decl_stmt|;
end_decl_stmt

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

begin_comment
comment|/* All references to certain hard regs, except those created    by allocating pseudo regs into them (when that's possible),    go through these unique rtx objects.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|stack_pointer_rtx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|frame_pointer_rtx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|hard_frame_pointer_rtx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|arg_pointer_rtx
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|rtx
name|virtual_incoming_args_rtx
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VIRTUAL_INCOMING_ARGS_REGNUM
value|(FIRST_VIRTUAL_REGISTER)
end_define

begin_comment
comment|/* If FRAME_GROWS_DOWNWARD, this points to immediately above the first    variable on the stack.  Otherwise, it points to the first variable on    the stack.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|virtual_stack_vars_rtx
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VIRTUAL_STACK_VARS_REGNUM
value|((FIRST_VIRTUAL_REGISTER) + 1)
end_define

begin_comment
comment|/* This points to the location of dynamically-allocated memory on the stack    immediately after the stack pointer has been adjusted by the amount    desired.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|virtual_stack_dynamic_rtx
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VIRTUAL_STACK_DYNAMIC_REGNUM
value|((FIRST_VIRTUAL_REGISTER) + 2)
end_define

begin_comment
comment|/* This points to the location in the stack at which outgoing arguments should    be written when the stack is pre-pushed (arguments pushed using push    insns always use sp).  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|virtual_outgoing_args_rtx
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VIRTUAL_OUTGOING_ARGS_REGNUM
value|((FIRST_VIRTUAL_REGISTER) + 3)
end_define

begin_define
define|#
directive|define
name|LAST_VIRTUAL_REGISTER
value|((FIRST_VIRTUAL_REGISTER) + 3)
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

begin_comment
comment|/* It is hard to write the prototype for expand_expr, since it needs    expr.h to be included for the enumeration.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|expand_expr
parameter_list|()
function_decl|;
end_function_decl

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
comment|/* Abort routines */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|fatal_insn_not_found
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
name|fatal_insn
name|PROTO
argument_list|(
operator|(
name|char
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
comment|/* Nonzero after end of reload pass.    Set to 1 or 0 by toplev.c.  */
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

end_unit

