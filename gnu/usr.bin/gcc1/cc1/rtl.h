begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Register Transfer Language (RTL) definitions for GNU C-Compiler    Copyright (C) 1987 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|FFS
end_undef

begin_comment
comment|/* Some systems predefine this symbol; don't let it interfere.  */
end_comment

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
comment|/* A convienent way to get a value for 				   NUM_RTX_CODE. 				   Assumes default enum value assignement.  */
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

begin_comment
comment|/* Get the definition of `enum machine_mode' */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_MACHINE_MODES
end_ifndef

begin_define
define|#
directive|define
name|DEF_MACHMODE
parameter_list|(
name|SYM
parameter_list|,
name|NAME
parameter_list|,
name|TYPE
parameter_list|,
name|SIZE
parameter_list|,
name|UNIT
parameter_list|,
name|WIDER
parameter_list|)
value|SYM,
end_define

begin_enum
enum|enum
name|machine_mode
block|{
include|#
directive|include
file|"machmode.def"
name|MAX_MACHINE_MODE
block|}
enum|;
end_enum

begin_undef
undef|#
directive|undef
name|DEF_MACHMODE
end_undef

begin_define
define|#
directive|define
name|HAVE_MACHINE_MODES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_MACHINE_MODES */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NUM_MACHINE_MODES
end_ifndef

begin_define
define|#
directive|define
name|NUM_MACHINE_MODES
value|(int) MAX_MACHINE_MODE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get the name of mode MODE as a string.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mode_name
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_MODE_NAME
parameter_list|(
name|MODE
parameter_list|)
value|(mode_name[(int)(MODE)])
end_define

begin_enum
enum|enum
name|mode_class
block|{
name|MODE_RANDOM
block|,
name|MODE_INT
block|,
name|MODE_FLOAT
block|,
name|MODE_COMPLEX_INT
block|,
name|MODE_COMPLEX_FLOAT
block|,
name|MODE_FUNCTION
block|}
enum|;
end_enum

begin_comment
comment|/* Get the general kind of object that mode MODE represents    (integer, floating, complex, etc.)  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|mode_class
name|mode_class
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_MODE_CLASS
parameter_list|(
name|MODE
parameter_list|)
value|(mode_class[(int)(MODE)])
end_define

begin_comment
comment|/* Get the size in bytes of an object of mode MODE.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mode_size
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_MODE_SIZE
parameter_list|(
name|MODE
parameter_list|)
value|(mode_size[(int)(MODE)])
end_define

begin_comment
comment|/* Get the size in bytes of the basic parts of an object of mode MODE.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mode_unit_size
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_MODE_UNIT_SIZE
parameter_list|(
name|MODE
parameter_list|)
value|(mode_unit_size[(int)(MODE)])
end_define

begin_comment
comment|/* Get the size in bits of an object of mode MODE.  */
end_comment

begin_define
define|#
directive|define
name|GET_MODE_BITSIZE
parameter_list|(
name|MODE
parameter_list|)
value|(BITS_PER_UNIT * mode_size[(int)(MODE)])
end_define

begin_comment
comment|/* Get a bitmask containing 1 for all bits in a word    that fit within mode MODE.  */
end_comment

begin_define
define|#
directive|define
name|GET_MODE_MASK
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((GET_MODE_BITSIZE (MODE)>= HOST_BITS_PER_INT)  \     ? -1 : ((1<< GET_MODE_BITSIZE (MODE)) - 1))
end_define

begin_comment
comment|/* Get the next wider natural mode (eg, QI -> HI -> SI -> DI -> TI).  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|machine_mode
name|mode_wider_mode
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_MODE_WIDER_MODE
parameter_list|(
name|MODE
parameter_list|)
value|(mode_wider_mode[(int)(MODE)])
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
name|SHORT_ENUM_BUG
name|unsigned
name|short
name|code
decl_stmt|;
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
name|enum
name|machine_mode
name|mode
range|:
literal|8
decl_stmt|;
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
comment|/* 1 in a MEM or REG if value of this expression will never change      during the current function, even though it is not      manifestly constant.      1 in a SYMBOL_REF if it addresses something in the per-function      constants pool.  */
name|unsigned
name|int
name|unchanging
range|:
literal|1
decl_stmt|;
comment|/* 1 in a MEM expression if contents of memory are volatile.  */
comment|/* 1 in an INSN, CALL_INSN, JUMP_INSN, CODE_LABEL or BARRIER      if it is deleted.  */
comment|/* 1 in a REG expression if corresponds to a variable declared by the user.      0 for an internally generated temporary.  */
name|unsigned
name|int
name|volatil
range|:
literal|1
decl_stmt|;
comment|/* 1 in a MEM referring to a field of a structure (not a union!).      0 if the MEM was a variable or the result of a * operator in C;      1 if it was the result of a . or -> operator (on a struct) in C.  */
name|unsigned
name|int
name|in_struct
range|:
literal|1
decl_stmt|;
comment|/* 1 if this rtx is used.  This is used for copying shared structure.      See `unshare_all_rtl'.      This bit is used to detect that event.  */
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
value|(GET_CODE (X) == LABEL_REF || GET_CODE (X) == SYMBOL_REF		\    || GET_CODE (X) == CONST_INT						\    || GET_CODE (X) == CONST)
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
comment|/* Holds a list of notes on what this insn does to various REGs.    It is a chain of EXPR_LIST rtx's, where the second operand    is the chain pointer and the first operand is the REG being described.    The mode field of the EXPR_LIST contains not a real machine mode    but a value that says what this note says about the REG:      REG_DEAD means that the REG dies in this insn.      REG_INC means that the REG is autoincremented or autodecremented.    Note that one insn can have both REG_DEAD and REG_INC for the same register    if the register is preincremented or predecremented in the insn    and not needed afterward.  This can probably happen.      REG_EQUIV describes the insn as a whole; it says that the    insn sets a register to a constant value or to be equivalent to    a memory address.  If the    register is spilled to the stack then the constant value    should be substituted for it.  The contents of the REG_EQUIV    is the constant value or memory address, which may be different    from the source of the SET although it has the same value.       REG_EQUAL is like REG_EQUIV except that the destination    is only momentarily equal to the specified rtx.  Therefore, it    cannot be used for substitution; but it can be used for cse.      REG_RETVAL means that this insn copies the return-value of    a library call out of the hard reg for return values.  This note    is actually an INSN_LIST and it points to the first insn involved    in setting up arguments for the call.  flow.c uses this to delete    the entire library call when its result is dead.      REG_LIBCALL is the inverse of REG_RETVAL: it goes on the first insn    of the library call and points at the one that has the REG_RETVAL.      REG_WAS_0 says that the register set in this insn held 0 before the insn.    The contents of the note is the insn that stored the 0.    If that insn is deleted or patched to a NOTE, the REG_WAS_0 is inoperative.    The REG_WAS_0 note is actually an INSN_LIST, not an EXPR_LIST.      REG_NONNEG means that the register is always nonnegative during    the containing loop.  This is used in branches so that decrement and    branch instructions terminating on zero can be matched.      REG_UNSET identifies a pseudo-reg used in this insn and never set.  */
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
name|REG_UNSET
init|=
literal|9
block|}
enum|;
end_enum

begin_comment
comment|/* Extract the reg-note kind from an EXPR_LIST.  */
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
comment|/* In a NOTE that is a line number, this is a string for the file name    that the line is in.  */
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
comment|/* Codes that appear in the NOTE_LINE_NUMBER field    for kinds of notes that are not line numbers.  */
end_comment

begin_comment
comment|/* This note indicates the end of the real body of the function,    after moving the parms into their homes, etc.  */
end_comment

begin_define
define|#
directive|define
name|NOTE_INSN_FUNCTION_BEG
value|0
end_define

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
comment|/* Don't forget to change note_insn_name in rtl.c.  */
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
comment|/* In jump.c, each label contains a count of the number    of LABEL_REFs that point at it, so unused labels can be deleted.  */
end_comment

begin_define
define|#
directive|define
name|LABEL_NUSES
parameter_list|(
name|LABEL
parameter_list|)
value|((LABEL)->fld[4].rtint)
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
value|((LABEL)->fld[4].rtx)
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
value|((RTX)->fld[0].rtint)
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
comment|/* 1 in a SYMBOL_REF if it is the name of an external symbol.  */
end_comment

begin_define
define|#
directive|define
name|EXTERNAL_SYMBOL_P
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->volatil)
end_define

begin_comment
comment|/* For an INLINE_HEADER rtx, FIRST_FUNCTION_INSN is the first insn    of the function that is not involved in copying parameters to    pseudo-registers.  FIRST_PARM_INSN is the very first insn of    the function, including the parameter copying.    We keep this around in case we must splice    this function into the assembly code at the end of the file.    FIRST_LABELNO is the first label number used by the function (inclusive).    LAST_LABELNO is the last label used by the function (exclusive).    MAX_REGNUM is the largest pseudo-register used by that function.     We want this to lay down like an INSN.  The PREV_INSN field    is always NULL.  The NEXT_INSN field always points to the    first function insn of the function being squirreled away.  */
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

begin_escape
end_escape

begin_comment
comment|/* Generally useful functions.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|rtx_alloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtvec
name|rtvec_alloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|find_reg_note
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_rtx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|copy_rtx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtvec
name|gen_rtvec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtvec
name|gen_rtvec_v
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_reg_rtx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_label_rtx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_inline_header_rtx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_lowpart
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_highpart
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|subreg_lowpart_p
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|make_safe_from
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|memory_address
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|get_insns
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|get_last_insn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|start_sequence
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_sequence
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|expand_expr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|output_constant_def
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|immed_real_const
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|immed_real_const_1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|immed_double_const
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|force_const_double_mem
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|force_const_mem
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|get_parm_real_loc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|assign_stack_local
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|protect_from_queue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|emit_queue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|emit_move_insn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|emit_insn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|emit_jump_insn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|emit_call_insn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|emit_call_insn_before
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|emit_insn_before
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|emit_insn_after
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|emit_label
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|emit_barrier
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|emit_barrier_after
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|emit_note
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|emit_line_note
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|emit_line_note_force
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|prev_real_insn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|next_real_insn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|next_nondeleted_insn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|plus_constant
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|find_equiv_reg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|delete_insn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|adj_offsettable_operand
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Maximum number of parallel sets and clobbers in any insn in this fn.    Always at least 3, since the combiner could put that many togetherm    and we want this to remain correct for all the remaining passes.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|max_parallel
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|asm_noperands
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|decode_asm_operands
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|BITS_PER_WORD
end_ifdef

begin_comment
comment|/* Conditional is to detect when config.h has been included.  */
end_comment

begin_function_decl
specifier|extern
name|enum
name|reg_class
name|reg_preferred_class
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|rtx
name|get_first_nonparm_insn
parameter_list|()
function_decl|;
end_function_decl

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
name|fconst0_rtx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|dconst0_rtx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Returns a constant 0 rtx in mode MODE.  */
end_comment

begin_define
define|#
directive|define
name|CONST0_RTX
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((MODE == SFmode) ? fconst0_rtx			\   : ((MODE == DFmode) ? dconst0_rtx			\      : ((GET_MODE_CLASS (MODE) == MODE_INT) ? const0_rtx	\         : (abort (), NULL_RTX))))
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
name|arg_pointer_rtx
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

end_unit

