begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Register Transfer Language (RTL) definitions for GNU C-Compiler    Copyright (C) 1987, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998,    1999, 2000, 2001, 2002 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_RTL_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_RTL_H
end_define

begin_struct_decl
struct_decl|struct
name|function
struct_decl|;
end_struct_decl

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

begin_comment
comment|/* Value used by some passes to "recognize" noop moves as valid  instructions.  */
end_comment

begin_define
define|#
directive|define
name|NOOP_MOVE_INSN_CODE
value|INT_MAX
end_define

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
value|((int) LAST_AND_UNUSED_RTX_CODE)
end_define

begin_comment
comment|/* The cast here, saves many elsewhere.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|rtx_length
index|[
name|NUM_RTX_CODE
index|]
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
specifier|const
name|char
modifier|*
specifier|const
name|rtx_name
index|[
name|NUM_RTX_CODE
index|]
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
specifier|const
name|char
modifier|*
specifier|const
name|rtx_format
index|[
name|NUM_RTX_CODE
index|]
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
specifier|const
name|char
name|rtx_class
index|[
name|NUM_RTX_CODE
index|]
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
comment|/* minimum address target label is 				 after the ADDR_DIFF_VEC.  */
name|unsigned
name|max_after_vec
range|:
literal|1
decl_stmt|;
comment|/* maximum address target label is 				 after the ADDR_DIFF_VEC.  */
name|unsigned
name|min_after_base
range|:
literal|1
decl_stmt|;
comment|/* minimum address target label is 				 after BASE.  */
name|unsigned
name|max_after_base
range|:
literal|1
decl_stmt|;
comment|/* maximum address target label is 				 after BASE.  */
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
comment|/* Structure used to describe the attributes of a MEM.  These are hashed    so MEMs that the same attributes share a data structure.  This means    they cannot be modified in place.  If any element is nonzero, it means    the value of the corresponding attribute is unknown.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|HOST_WIDE_INT
name|alias
decl_stmt|;
comment|/* Memory alias set.  */
name|tree
name|expr
decl_stmt|;
comment|/* expr corresponding to MEM.  */
name|rtx
name|offset
decl_stmt|;
comment|/* Offset from start of DECL, as CONST_INT.  */
name|rtx
name|size
decl_stmt|;
comment|/* Size in bytes, as a CONST_INT.  */
name|unsigned
name|int
name|align
decl_stmt|;
comment|/* Alignment of MEM in bits.  */
block|}
name|mem_attrs
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
name|unsigned
name|int
name|rtuint
decl_stmt|;
specifier|const
name|char
modifier|*
name|rtstr
decl_stmt|;
name|rtx
name|rtx
decl_stmt|;
name|rtvec
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
name|cselib_val_struct
modifier|*
name|rt_cselib
decl_stmt|;
name|struct
name|bitmap_head_def
modifier|*
name|rtbit
decl_stmt|;
name|tree
name|rttree
decl_stmt|;
name|struct
name|basic_block_def
modifier|*
name|bb
decl_stmt|;
name|mem_attrs
modifier|*
name|rtmem
decl_stmt|;
block|}
name|rtunion
typedef|;
end_typedef

begin_comment
comment|/* RTL expression ("rtx").  */
end_comment

begin_struct
struct|struct
name|rtx_def
block|{
comment|/* The kind of expression this is.  */
name|ENUM_BITFIELD
argument_list|(
argument|rtx_code
argument_list|)
name|code
label|:
literal|16
expr_stmt|;
comment|/* The kind of value the expression has.  */
name|ENUM_BITFIELD
argument_list|(
argument|machine_mode
argument_list|)
name|mode
label|:
literal|8
expr_stmt|;
comment|/* 1 in an INSN if it can alter flow of control      within this function.      MEM_KEEP_ALIAS_SET_P in a MEM.      LINK_COST_ZERO in an INSN_LIST.      SET_IS_RETURN_P in a SET.  */
name|unsigned
name|int
name|jump
range|:
literal|1
decl_stmt|;
comment|/* 1 in an INSN if it can call another function.      LINK_COST_FREE in an INSN_LIST.  */
name|unsigned
name|int
name|call
range|:
literal|1
decl_stmt|;
comment|/* 1 in a REG if value of this expression will never change during      the current function, even though it is not manifestly constant.      1 in a MEM if contents of memory are constant.  This does not      necessarily mean that the value of this expression is constant.      1 in a SUBREG if it is from a promoted variable that is unsigned.      1 in a SYMBOL_REF if it addresses something in the per-function      constants pool.      1 in a CALL_INSN if it is a const call.      1 in a JUMP_INSN if it is a branch that should be annulled.  Valid from      reorg until end of compilation; cleared before used.  */
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
comment|/* 1 in a MEM referring to a field of an aggregate.      0 if the MEM was a variable or the result of a * operator in C;      1 if it was the result of a . or -> operator (on a struct) in C.      1 in a REG if the register is used only in exit code a loop.      1 in a SUBREG expression if was generated from a variable with a      promoted mode.      1 in a CODE_LABEL if the label is used for nonlocal gotos      and must not be deleted even if its count is zero.      1 in a LABEL_REF if this is a reference to a label outside the      current loop.      1 in an INSN, JUMP_INSN, or CALL_INSN if this insn must be scheduled      together with the preceding insn.  Valid only within sched.      1 in an INSN, JUMP_INSN, or CALL_INSN if insn is in a delay slot and      from the target of a branch.  Valid from reorg until end of compilation;      cleared before used.      1 in an INSN if this insn is dead code.  Valid only during      dead-code elimination phase; cleared before use.  */
name|unsigned
name|int
name|in_struct
range|:
literal|1
decl_stmt|;
comment|/* 1 if this rtx is used.  This is used for copying shared structure.      See `unshare_all_rtl'.      In a REG, this is not needed for that purpose, and used instead      in `leaf_renumber_regs_insn'.      In a SYMBOL_REF, means that emit_library_call      has used it as the function.  */
name|unsigned
name|int
name|used
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if this rtx came from procedure integration.      In a REG, nonzero means this reg refers to the return value      of the current function.      1 in a SYMBOL_REF if the symbol is weak.  */
name|unsigned
name|integrated
range|:
literal|1
decl_stmt|;
comment|/* 1 in an INSN or a SET if this rtx is related to the call frame,      either changing how we compute the frame address or saving and      restoring registers in the prologue and epilogue.      1 in a MEM if the MEM refers to a scalar, rather than a member of      an aggregate.      1 in a REG if the register is a pointer.      1 in a SYMBOL_REF if it addresses something in the per-function      constant string pool.  */
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
struct|;
end_struct

begin_define
define|#
directive|define
name|NULL_RTX
value|(rtx) 0
end_define

begin_comment
comment|/* Define macros to access the `code' field of the rtx.  */
end_comment

begin_define
define|#
directive|define
name|GET_CODE
parameter_list|(
name|RTX
parameter_list|)
value|((enum rtx_code) (RTX)->code)
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
value|((RTX)->code = (ENUM_BITFIELD(rtx_code)) (CODE))
end_define

begin_define
define|#
directive|define
name|GET_MODE
parameter_list|(
name|RTX
parameter_list|)
value|((enum machine_mode) (RTX)->mode)
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
value|((RTX)->mode = (ENUM_BITFIELD(machine_mode)) (MODE))
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

begin_struct
struct|struct
name|rtvec_def
block|{
name|int
name|num_elem
decl_stmt|;
comment|/* number of elements */
name|rtx
name|elem
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

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

begin_comment
comment|/* Predicate yielding nonzero iff X is an rtl for a register.  */
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
comment|/* Predicate yielding nonzero iff X is a label insn.  */
end_comment

begin_define
define|#
directive|define
name|LABEL_P
parameter_list|(
name|X
parameter_list|)
value|(GET_CODE (X) == CODE_LABEL)
end_define

begin_comment
comment|/* Predicate yielding nonzero iff X is a jump insn.  */
end_comment

begin_define
define|#
directive|define
name|JUMP_P
parameter_list|(
name|X
parameter_list|)
value|(GET_CODE (X) == JUMP_INSN)
end_define

begin_comment
comment|/* Predicate yielding nonzero iff X is a note insn.  */
end_comment

begin_define
define|#
directive|define
name|NOTE_P
parameter_list|(
name|X
parameter_list|)
value|(GET_CODE (X) == NOTE)
end_define

begin_comment
comment|/* Predicate yielding nonzero iff X is a barrier insn.  */
end_comment

begin_define
define|#
directive|define
name|BARRIER_P
parameter_list|(
name|X
parameter_list|)
value|(GET_CODE (X) == BARRIER)
end_define

begin_comment
comment|/* Predicate yielding nonzero iff X is a data for a jump table.  */
end_comment

begin_define
define|#
directive|define
name|JUMP_TABLE_DATA_P
parameter_list|(
name|INSN
parameter_list|)
define|\
value|(JUMP_P (INSN)&& (GET_CODE (PATTERN (INSN)) == ADDR_VEC || \ 		     GET_CODE (PATTERN (INSN)) == ADDR_DIFF_VEC))
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

begin_if
if|#
directive|if
name|defined
name|ENABLE_RTL_CHECKING
operator|&&
operator|(
name|GCC_VERSION
operator|>=
literal|2007
operator|)
end_if

begin_comment
comment|/* The bit with a star outside the statement expr and an& inside is    so that N can be evaluated only once.  */
end_comment

begin_define
define|#
directive|define
name|RTL_CHECK1
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|,
name|C1
parameter_list|)
value|__extension__				\ (*({ rtx _rtx = (RTX); int _n = (N);					\      enum rtx_code _code = GET_CODE (_rtx);				\      if (_n< 0 || _n>= GET_RTX_LENGTH (_code))			\        rtl_check_failed_bounds (_rtx, _n, __FILE__, __LINE__,		\ 				__FUNCTION__);				\      if (GET_RTX_FORMAT(_code)[_n] != C1)				\        rtl_check_failed_type1 (_rtx, _n, C1, __FILE__, __LINE__,	\ 			       __FUNCTION__);				\&_rtx->fld[_n]; }))
end_define

begin_define
define|#
directive|define
name|RTL_CHECK2
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|,
name|C1
parameter_list|,
name|C2
parameter_list|)
value|__extension__			\ (*({ rtx _rtx = (RTX); int _n = (N);					\      enum rtx_code _code = GET_CODE (_rtx);				\      if (_n< 0 || _n>= GET_RTX_LENGTH (_code))			\        rtl_check_failed_bounds (_rtx, _n, __FILE__, __LINE__,		\ 				__FUNCTION__);				\      if (GET_RTX_FORMAT(_code)[_n] != C1				\&& GET_RTX_FORMAT(_code)[_n] != C2)				\        rtl_check_failed_type2 (_rtx, _n, C1, C2, __FILE__, __LINE__,	\ 			       __FUNCTION__);				\&_rtx->fld[_n]; }))
end_define

begin_define
define|#
directive|define
name|RTL_CHECKC1
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|,
name|C
parameter_list|)
value|__extension__				\ (*({ rtx _rtx = (RTX); int _n = (N);					\      if (GET_CODE (_rtx) != (C))					\        rtl_check_failed_code1 (_rtx, (C), __FILE__, __LINE__,		\ 			       __FUNCTION__);				\&_rtx->fld[_n]; }))
end_define

begin_define
define|#
directive|define
name|RTL_CHECKC2
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|,
name|C1
parameter_list|,
name|C2
parameter_list|)
value|__extension__			\ (*({ rtx _rtx = (RTX); int _n = (N);					\      enum rtx_code _code = GET_CODE (_rtx);				\      if (_code != (C1)&& _code != (C2))				\        rtl_check_failed_code2 (_rtx, (C1), (C2), __FILE__, __LINE__,	\ 			       __FUNCTION__); \&_rtx->fld[_n]; }))
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
value|__extension__				\ (*({ rtvec _rtvec = (RTVEC); int _i = (I);				\      if (_i< 0 || _i>= GET_NUM_ELEM (_rtvec))				\        rtvec_check_failed_bounds (_rtvec, _i, __FILE__, __LINE__,	\ 				  __FUNCTION__);			\&_rtvec->elem[_i]; }))
end_define

begin_decl_stmt
specifier|extern
name|void
name|rtl_check_failed_bounds
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rtl_check_failed_type1
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rtl_check_failed_type2
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rtl_check_failed_code1
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|rtx_code
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rtl_check_failed_code2
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|rtx_code
operator|,
expr|enum
name|rtx_code
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rtvec_check_failed_bounds
name|PARAMS
argument_list|(
operator|(
name|rtvec
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not ENABLE_RTL_CHECKING */
end_comment

begin_define
define|#
directive|define
name|RTL_CHECK1
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|,
name|C1
parameter_list|)
value|((RTX)->fld[N])
end_define

begin_define
define|#
directive|define
name|RTL_CHECK2
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|,
name|C1
parameter_list|,
name|C2
parameter_list|)
value|((RTX)->fld[N])
end_define

begin_define
define|#
directive|define
name|RTL_CHECKC1
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|,
name|C
parameter_list|)
value|((RTX)->fld[N])
end_define

begin_define
define|#
directive|define
name|RTL_CHECKC2
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|,
name|C1
parameter_list|,
name|C2
parameter_list|)
value|((RTX)->fld[N])
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
value|((RTVEC)->elem[I])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XWINT
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|(RTL_CHECK1 (RTX, N, 'w').rtwint)
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
value|(RTL_CHECK2 (RTX, N, 'i', 'n').rtint)
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
value|(RTL_CHECK2 (RTX, N, 's', 'S').rtstr)
end_define

begin_define
define|#
directive|define
name|XEXP
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|(RTL_CHECK2 (RTX, N, 'e', 'u').rtx)
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
value|(RTL_CHECK2 (RTX, N, 'E', 'V').rtvec)
end_define

begin_define
define|#
directive|define
name|XMODE
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|(RTL_CHECK1 (RTX, N, 'M').rttype)
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
value|(RTL_CHECK1 (RTX, N, 'b').rtbit)
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
value|(RTL_CHECK1 (RTX, N, 't').rttree)
end_define

begin_define
define|#
directive|define
name|XBBDEF
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|(RTL_CHECK1 (RTX, N, 'B').bb)
end_define

begin_define
define|#
directive|define
name|XTMPL
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|(RTL_CHECK1 (RTX, N, 'T').rtstr)
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
value|RTVEC_ELT (XVEC (RTX, N), M)
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
value|GET_NUM_ELEM (XVEC (RTX, N))
end_define

begin_comment
comment|/* These are like XWINT, etc. except that they expect a '0' field instead    of the normal type code.  */
end_comment

begin_define
define|#
directive|define
name|X0WINT
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|(RTL_CHECK1 (RTX, N, '0').rtwint)
end_define

begin_define
define|#
directive|define
name|X0INT
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|(RTL_CHECK1 (RTX, N, '0').rtint)
end_define

begin_define
define|#
directive|define
name|X0UINT
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|(RTL_CHECK1 (RTX, N, '0').rtuint)
end_define

begin_define
define|#
directive|define
name|X0STR
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|(RTL_CHECK1 (RTX, N, '0').rtstr)
end_define

begin_define
define|#
directive|define
name|X0EXP
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|(RTL_CHECK1 (RTX, N, '0').rtx)
end_define

begin_define
define|#
directive|define
name|X0VEC
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|(RTL_CHECK1 (RTX, N, '0').rtvec)
end_define

begin_define
define|#
directive|define
name|X0MODE
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|(RTL_CHECK1 (RTX, N, '0').rttype)
end_define

begin_define
define|#
directive|define
name|X0BITMAP
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|(RTL_CHECK1 (RTX, N, '0').rtbit)
end_define

begin_define
define|#
directive|define
name|X0TREE
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|(RTL_CHECK1 (RTX, N, '0').rttree)
end_define

begin_define
define|#
directive|define
name|X0BBDEF
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|(RTL_CHECK1 (RTX, N, '0').bb)
end_define

begin_define
define|#
directive|define
name|X0ADVFLAGS
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|(RTL_CHECK1 (RTX, N, '0').rt_addr_diff_vec_flags)
end_define

begin_define
define|#
directive|define
name|X0CSELIB
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|(RTL_CHECK1 (RTX, N, '0').rt_cselib)
end_define

begin_define
define|#
directive|define
name|X0MEMATTR
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
value|(RTL_CHECK1 (RTX, N, '0').rtmem)
end_define

begin_define
define|#
directive|define
name|XCWINT
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|,
name|C
parameter_list|)
value|(RTL_CHECKC1 (RTX, N, C).rtwint)
end_define

begin_define
define|#
directive|define
name|XCINT
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|,
name|C
parameter_list|)
value|(RTL_CHECKC1 (RTX, N, C).rtint)
end_define

begin_define
define|#
directive|define
name|XCUINT
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|,
name|C
parameter_list|)
value|(RTL_CHECKC1 (RTX, N, C).rtuint)
end_define

begin_define
define|#
directive|define
name|XCSTR
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|,
name|C
parameter_list|)
value|(RTL_CHECKC1 (RTX, N, C).rtstr)
end_define

begin_define
define|#
directive|define
name|XCEXP
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|,
name|C
parameter_list|)
value|(RTL_CHECKC1 (RTX, N, C).rtx)
end_define

begin_define
define|#
directive|define
name|XCVEC
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|,
name|C
parameter_list|)
value|(RTL_CHECKC1 (RTX, N, C).rtvec)
end_define

begin_define
define|#
directive|define
name|XCMODE
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|,
name|C
parameter_list|)
value|(RTL_CHECKC1 (RTX, N, C).rttype)
end_define

begin_define
define|#
directive|define
name|XCBITMAP
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|,
name|C
parameter_list|)
value|(RTL_CHECKC1 (RTX, N, C).rtbit)
end_define

begin_define
define|#
directive|define
name|XCTREE
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|,
name|C
parameter_list|)
value|(RTL_CHECKC1 (RTX, N, C).rttree)
end_define

begin_define
define|#
directive|define
name|XCBBDEF
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|,
name|C
parameter_list|)
value|(RTL_CHECKC1 (RTX, N, C).bb)
end_define

begin_define
define|#
directive|define
name|XCADVFLAGS
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|,
name|C
parameter_list|)
value|(RTL_CHECKC1 (RTX, N, C).rt_addr_diff_vec_flags)
end_define

begin_define
define|#
directive|define
name|XCCSELIB
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|,
name|C
parameter_list|)
value|(RTL_CHECKC1 (RTX, N, C).rt_cselib)
end_define

begin_define
define|#
directive|define
name|XCVECEXP
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|,
name|M
parameter_list|,
name|C
parameter_list|)
value|RTVEC_ELT (XCVEC (RTX, N, C), M)
end_define

begin_define
define|#
directive|define
name|XCVECLEN
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|,
name|C
parameter_list|)
value|GET_NUM_ELEM (XCVEC (RTX, N, C))
end_define

begin_define
define|#
directive|define
name|XC2EXP
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|,
name|C1
parameter_list|,
name|C2
parameter_list|)
value|(RTL_CHECKC2 (RTX, N, C1, C2).rtx)
end_define

begin_escape
end_escape

begin_comment
comment|/* ACCESS MACROS for particular fields of insns.  */
end_comment

begin_comment
comment|/* Determines whether X is an insn.  */
end_comment

begin_define
define|#
directive|define
name|INSN_P
parameter_list|(
name|X
parameter_list|)
value|(GET_RTX_CLASS (GET_CODE(X)) == 'i')
end_define

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
value|XINT (INSN, 0)
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
value|XEXP (INSN, 1)
end_define

begin_define
define|#
directive|define
name|NEXT_INSN
parameter_list|(
name|INSN
parameter_list|)
value|XEXP (INSN, 2)
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
value|XEXP (INSN, 3)
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
value|XINT (INSN, 4)
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
value|XEXP(INSN, 5)
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
comment|/* 1 if insn is a call to a const or pure function.  */
end_comment

begin_define
define|#
directive|define
name|CONST_OR_PURE_CALL_P
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->unchanging)
end_define

begin_comment
comment|/* 1 if insn (assumed to be a CALL_INSN) is a sibling call.  */
end_comment

begin_define
define|#
directive|define
name|SIBLING_CALL_P
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->jump)
end_define

begin_comment
comment|/* 1 if insn is a branch that should not unconditionally execute its    delay slots, i.e., it is an annulled branch.  */
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
comment|/* 1 if insn is a dead code.  Valid only for dead-code elimination phase.  */
end_comment

begin_define
define|#
directive|define
name|INSN_DEAD_CODE_P
parameter_list|(
name|INSN
parameter_list|)
value|((INSN)->in_struct)
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

begin_define
define|#
directive|define
name|ADDR_DIFF_VEC_FLAGS
parameter_list|(
name|RTX
parameter_list|)
value|X0ADVFLAGS(RTX, 4)
end_define

begin_define
define|#
directive|define
name|CSELIB_VAL_PTR
parameter_list|(
name|RTX
parameter_list|)
value|X0CSELIB(RTX, 0)
end_define

begin_comment
comment|/* Holds a list of notes on what this insn does to various REGs.    It is a chain of EXPR_LIST rtx's, where the second operand is the    chain pointer and the first operand is the REG being described.    The mode field of the EXPR_LIST contains not a real machine mode    but a value from enum reg_note.  */
end_comment

begin_define
define|#
directive|define
name|REG_NOTES
parameter_list|(
name|INSN
parameter_list|)
value|XEXP(INSN, 6)
end_define

begin_comment
comment|/* Don't forget to change reg_note_name in rtl.c.  */
end_comment

begin_enum
enum|enum
name|reg_note
block|{
comment|/* The value in REG dies in this insn (i.e., it is not needed past      this insn).  If REG is set in this insn, the REG_DEAD note may,      but need not, be omitted.  */
name|REG_DEAD
init|=
literal|1
block|,
comment|/* The REG is autoincremented or autodecremented.  */
name|REG_INC
block|,
comment|/* Describes the insn as a whole; it says that the insn sets a register      to a constant value or to be equivalent to a memory address.  If the      register is spilled to the stack then the constant value should be      substituted for it.  The contents of the REG_EQUIV is the constant      value or memory address, which may be different from the source of      the SET although it has the same value.  A REG_EQUIV note may also      appear on an insn which copies a register parameter to a pseudo-register,      if there is a memory address which could be used to hold that      pseudo-register throughout the function.  */
name|REG_EQUIV
block|,
comment|/* Like REG_EQUIV except that the destination is only momentarily equal      to the specified rtx.  Therefore, it cannot be used for substitution;      but it can be used for cse.  */
name|REG_EQUAL
block|,
comment|/* The register set in this insn held 0 before the insn.  The contents of      the note is the insn that stored the 0.  If that insn is deleted or      patched to a NOTE, the REG_WAS_0 is inoperative.  The REG_WAS_0 note      is actually an INSN_LIST, not an EXPR_LIST.  */
name|REG_WAS_0
block|,
comment|/* This insn copies the return-value of a library call out of the hard reg      for return values.  This note is actually an INSN_LIST and it points to      the first insn involved in setting up arguments for the call.  flow.c      uses this to delete the entire library call when its result is dead.  */
name|REG_RETVAL
block|,
comment|/* The inverse of REG_RETVAL: it goes on the first insn of the library call      and points at the one that has the REG_RETVAL.  This note is also an      INSN_LIST.  */
name|REG_LIBCALL
block|,
comment|/* The register is always nonnegative during the containing loop.  This is      used in branches so that decrement and branch instructions terminating      on zero can be matched.  There must be an insn pattern in the md file      named `decrement_and_branch_until_zero' or else this will never be added      to any instructions.  */
name|REG_NONNEG
block|,
comment|/* There is no conflict *after this insn* between the register in the note      and the destination of this insn.  */
name|REG_NO_CONFLICT
block|,
comment|/* Identifies a register set in this insn and never used.  */
name|REG_UNUSED
block|,
comment|/* REG_CC_SETTER and REG_CC_USER link a pair of insns that set and use CC0,      respectively.  Normally, these are required to be consecutive insns, but      we permit putting a cc0-setting insn in the delay slot of a branch as      long as only one copy of the insn exists.  In that case, these notes      point from one to the other to allow code generation to determine what      any require information and to properly update CC_STATUS.  These notes      are INSN_LISTs.  */
name|REG_CC_SETTER
block|,
name|REG_CC_USER
block|,
comment|/* Points to a CODE_LABEL.  Used by non-JUMP_INSNs to say that the      CODE_LABEL contained in the REG_LABEL note is used by the insn.       This note is an INSN_LIST.  */
name|REG_LABEL
block|,
comment|/* REG_DEP_ANTI and REG_DEP_OUTPUT are used in LOG_LINKS to represent      write-after-read and write-after-write dependencies respectively.      Data dependencies, which are the only type of LOG_LINK created by      flow, are represented by a 0 reg note kind.  */
name|REG_DEP_ANTI
block|,
name|REG_DEP_OUTPUT
block|,
comment|/* REG_BR_PROB is attached to JUMP_INSNs and CALL_INSNs.      It has an integer value.  For jumps, it is the probability that this is a      taken branch.  For calls, it is the probability that this call won't      return.  */
name|REG_BR_PROB
block|,
comment|/* REG_EXEC_COUNT is attached to the first insn of each basic block, and      the first insn after each CALL_INSN.  It indicates how many times this      block was executed.  */
name|REG_EXEC_COUNT
block|,
comment|/* Attached to a call insn; indicates that the call is malloc-like and      that the pointer returned cannot alias anything else.  */
name|REG_NOALIAS
block|,
comment|/* Used to optimize rtl generated by dynamic stack allocations for targets      where SETJMP_VIA_SAVE_AREA is true.  */
name|REG_SAVE_AREA
block|,
comment|/* REG_BR_PRED is attached to JUMP_INSNs and CALL_INSNSs.  It contains      CONCAT of two integer value.  First specifies the branch predictor      that added the note, second specifies the predicted hitrate of branch      in the same format as REG_BR_PROB note uses.  */
name|REG_BR_PRED
block|,
comment|/* Attached to insns that are RTX_FRAME_RELATED_P, but are too complex      for DWARF to interpret what they imply.  The attached rtx is used      instead of intuition.  */
name|REG_FRAME_RELATED_EXPR
block|,
comment|/* Indicates that REG holds the exception context for the function.      This context is shared by inline functions, so the code to acquire      the real exception context is delayed until after inlining.  */
name|REG_EH_CONTEXT
block|,
comment|/* Indicates what exception region an INSN belongs in.  This is used to      indicate what region to which a call may throw.  REGION 0 indicates      that a call cannot throw at all.  REGION -1 indicates that it cannot      throw, nor will it execute a non-local goto.  */
name|REG_EH_REGION
block|,
comment|/* Used by haifa-sched to save NOTE_INSN notes across scheduling.  */
name|REG_SAVE_NOTE
block|,
comment|/* Indicates that this insn (which is part of the prologue) computes      a value which might not be used later, and if so it's OK to delete      the insn.  Normally, deleting any insn in the prologue is an error.       At present the parameter is unused and set to (const_int 0).  */
name|REG_MAYBE_DEAD
block|,
comment|/* Indicates that a call does not return.  */
name|REG_NORETURN
block|,
comment|/* Indicates that an indirect jump is a non-local goto instead of a       computed goto.  */
name|REG_NON_LOCAL_GOTO
block|,
comment|/* This kind of note is generated at each to `setjmp',      and similar functions that can return twice.  */
name|REG_SETJMP
block|,
comment|/* Indicate calls that always returns.  */
name|REG_ALWAYS_RETURN
block|,
comment|/* Indicate that the memory load references a vtable.  The expression      is of the form (plus (symbol_ref vtable_sym) (const_int offset)).  */
name|REG_VTABLE_REF
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
define|\
value|PUT_MODE (LINK, (enum machine_mode) (KIND))
end_define

begin_comment
comment|/* Names for REG_NOTE's in EXPR_LIST insn's.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
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
value|XEXP(INSN, 7)
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
value|XINT (INSN, 5)
end_define

begin_define
define|#
directive|define
name|LINE_NUMBER
value|NOTE
end_define

begin_comment
comment|/* In a NOTE that is a line number, this is a string for the file name that the    line is in.  We use the same field to record block numbers temporarily in    NOTE_INSN_BLOCK_BEG and NOTE_INSN_BLOCK_END notes.  (We avoid lots of casts    between ints and pointers if we use a different macro for the block number.)    The NOTE_INSN_RANGE_{START,END} and NOTE_INSN_LIVE notes record their    information as an rtx in the field.  */
end_comment

begin_define
define|#
directive|define
name|NOTE_SOURCE_FILE
parameter_list|(
name|INSN
parameter_list|)
value|XCSTR (INSN, 3, NOTE)
end_define

begin_define
define|#
directive|define
name|NOTE_BLOCK
parameter_list|(
name|INSN
parameter_list|)
value|XCTREE (INSN, 3, NOTE)
end_define

begin_define
define|#
directive|define
name|NOTE_EH_HANDLER
parameter_list|(
name|INSN
parameter_list|)
value|XCINT (INSN, 3, NOTE)
end_define

begin_define
define|#
directive|define
name|NOTE_RANGE_INFO
parameter_list|(
name|INSN
parameter_list|)
value|XCEXP (INSN, 3, NOTE)
end_define

begin_define
define|#
directive|define
name|NOTE_LIVE_INFO
parameter_list|(
name|INSN
parameter_list|)
value|XCEXP (INSN, 3, NOTE)
end_define

begin_define
define|#
directive|define
name|NOTE_BASIC_BLOCK
parameter_list|(
name|INSN
parameter_list|)
value|XCBBDEF (INSN, 3, NOTE)
end_define

begin_define
define|#
directive|define
name|NOTE_EXPECTED_VALUE
parameter_list|(
name|INSN
parameter_list|)
value|XCEXP (INSN, 3, NOTE)
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
value|XCINT (INSN, 4, NOTE)
end_define

begin_comment
comment|/* Nonzero if INSN is a note marking the beginning of a basic block.  */
end_comment

begin_define
define|#
directive|define
name|NOTE_INSN_BASIC_BLOCK_P
parameter_list|(
name|INSN
parameter_list|)
define|\
value|(GET_CODE (INSN) == NOTE				\&& NOTE_LINE_NUMBER (INSN) == NOTE_INSN_BASIC_BLOCK)
end_define

begin_comment
comment|/* Codes that appear in the NOTE_LINE_NUMBER field    for kinds of notes that are not line numbers.     Notice that we do not try to use zero here for any of    the special note codes because sometimes the source line    actually can be zero!  This happens (for example) when we    are generating code for the per-translation-unit constructor    and destructor routines for some C++ translation unit.     If you should change any of the following values, or if you    should add a new value here, don't forget to change the    note_insn_name array in rtl.c.  */
end_comment

begin_enum
enum|enum
name|insn_note
block|{
comment|/* Keep all of these numbers negative.  Adjust as needed.  */
name|NOTE_INSN_BIAS
init|=
operator|-
literal|100
block|,
comment|/* This note is used to get rid of an insn      when it isn't safe to patch the insn out of the chain.  */
name|NOTE_INSN_DELETED
block|,
comment|/* These are used to mark the beginning and end of a lexical block.      See NOTE_BLOCK, identify_blocks and reorder_blocks.  */
name|NOTE_INSN_BLOCK_BEG
block|,
name|NOTE_INSN_BLOCK_END
block|,
comment|/* These mark the extremes of a loop.  */
name|NOTE_INSN_LOOP_BEG
block|,
name|NOTE_INSN_LOOP_END
block|,
comment|/* Generated at the place in a loop that `continue' jumps to.  */
name|NOTE_INSN_LOOP_CONT
block|,
comment|/* Generated at the start of a duplicated exit test.  */
name|NOTE_INSN_LOOP_VTOP
block|,
comment|/* Generated at the end of a conditional at the top of the loop.      This is used to perform a lame form of loop rotation in lieu      of actually understanding the loop structure.  The note is      discarded after rotation is complete.  */
name|NOTE_INSN_LOOP_END_TOP_COND
block|,
comment|/* This kind of note is generated at the end of the function body,      just before the return insn or return label.  In an optimizing      compilation it is deleted by the first jump optimization, after      enabling that optimizer to determine whether control can fall      off the end of the function body without a return statement.  */
name|NOTE_INSN_FUNCTION_END
block|,
comment|/* This marks the point immediately after the last prologue insn.  */
name|NOTE_INSN_PROLOGUE_END
block|,
comment|/* This marks the point immediately prior to the first epilogue insn.  */
name|NOTE_INSN_EPILOGUE_BEG
block|,
comment|/* Generated in place of user-declared labels when they are deleted.  */
name|NOTE_INSN_DELETED_LABEL
block|,
comment|/* This note indicates the start of the real body of the function,      i.e. the point just after all of the parms have been moved into      their homes, etc.  */
name|NOTE_INSN_FUNCTION_BEG
block|,
comment|/* These note where exception handling regions begin and end.       Uses NOTE_EH_HANDLER to identify the region in question.  */
name|NOTE_INSN_EH_REGION_BEG
block|,
name|NOTE_INSN_EH_REGION_END
block|,
comment|/* Generated whenever a duplicate line number note is output.  For example,      one is output after the end of an inline function, in order to prevent      the line containing the inline call from being counted twice in gcov.  */
name|NOTE_INSN_REPEATED_LINE_NUMBER
block|,
comment|/* Start/end of a live range region, where pseudos allocated on the stack      can be allocated to temporary registers.  Uses NOTE_RANGE_INFO.  */
name|NOTE_INSN_RANGE_BEG
block|,
name|NOTE_INSN_RANGE_END
block|,
comment|/* Record which registers are currently live.  Uses NOTE_LIVE_INFO.  */
name|NOTE_INSN_LIVE
block|,
comment|/* Record the struct for the following basic block.  Uses NOTE_BASIC_BLOCK.  */
name|NOTE_INSN_BASIC_BLOCK
block|,
comment|/* Record the expected value of a register at a location.  Uses      NOTE_EXPECTED_VALUE; stored as (eq (reg) (const_int)).  */
name|NOTE_INSN_EXPECTED_VALUE
block|,
name|NOTE_INSN_MAX
block|}
enum|;
end_enum

begin_comment
comment|/* Names for NOTE insn's other than line numbers.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|note_insn_name
index|[
name|NOTE_INSN_MAX
operator|-
name|NOTE_INSN_BIAS
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_NOTE_INSN_NAME
parameter_list|(
name|NOTE_CODE
parameter_list|)
define|\
value|(note_insn_name[(NOTE_CODE) - (int) NOTE_INSN_BIAS])
end_define

begin_comment
comment|/* The name of a label, in case it corresponds to an explicit label    in the input source code.  */
end_comment

begin_define
define|#
directive|define
name|LABEL_NAME
parameter_list|(
name|RTX
parameter_list|)
value|XCSTR (RTX, 6, CODE_LABEL)
end_define

begin_comment
comment|/* In jump.c, each label contains a count of the number    of LABEL_REFs that point at it, so unused labels can be deleted.  */
end_comment

begin_define
define|#
directive|define
name|LABEL_NUSES
parameter_list|(
name|RTX
parameter_list|)
value|XCINT (RTX, 3, CODE_LABEL)
end_define

begin_comment
comment|/* Associate a name with a CODE_LABEL.  */
end_comment

begin_define
define|#
directive|define
name|LABEL_ALTERNATE_NAME
parameter_list|(
name|RTX
parameter_list|)
value|XCSTR (RTX, 7, CODE_LABEL)
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
value|XCUINT (RTX, 1, ADDRESSOF)
end_define

begin_comment
comment|/* The variable in the register we took the address of.  */
end_comment

begin_define
define|#
directive|define
name|ADDRESSOF_DECL
parameter_list|(
name|RTX
parameter_list|)
value|XCTREE (RTX, 2, ADDRESSOF)
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
value|XCEXP (INSN, 7, JUMP_INSN)
end_define

begin_comment
comment|/* Once basic blocks are found in flow.c,    each CODE_LABEL starts a chain that goes through    all the LABEL_REFs that jump to that label.    The chain eventually winds up at the CODE_LABEL: it is circular.  */
end_comment

begin_define
define|#
directive|define
name|LABEL_REFS
parameter_list|(
name|LABEL
parameter_list|)
value|XCEXP (LABEL, 4, CODE_LABEL)
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
value|XCEXP (REF, 1, LABEL_REF)
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
value|XCEXP (RTX, 2, LABEL_REF)
end_define

begin_comment
comment|/* For a REG rtx, REGNO extracts the register number.  ORIGINAL_REGNO holds    the number the register originally had; for a pseudo register turned into    a hard reg this will hold the old pseudo register number.  */
end_comment

begin_define
define|#
directive|define
name|REGNO
parameter_list|(
name|RTX
parameter_list|)
value|XCUINT (RTX, 0, REG)
end_define

begin_define
define|#
directive|define
name|ORIGINAL_REGNO
parameter_list|(
name|RTX
parameter_list|)
value|X0UINT (RTX, 1)
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
comment|/* 1 in a REG rtx if the register is a pointer.  */
end_comment

begin_define
define|#
directive|define
name|REG_POINTER
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->frame_related)
end_define

begin_comment
comment|/* 1 if the given register REG corresponds to a hard register.  */
end_comment

begin_define
define|#
directive|define
name|HARD_REGISTER_P
parameter_list|(
name|REG
parameter_list|)
value|(HARD_REGISTER_NUM_P (REGNO (REG)))
end_define

begin_comment
comment|/* 1 if the given register number REG_NO corresponds to a hard register.  */
end_comment

begin_define
define|#
directive|define
name|HARD_REGISTER_NUM_P
parameter_list|(
name|REG_NO
parameter_list|)
value|((REG_NO)< FIRST_PSEUDO_REGISTER)
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
value|XCWINT(RTX, 0, CONST_INT)
end_define

begin_comment
comment|/* For a CONST_DOUBLE:    The usual two ints that hold the value.    For a DImode, that is all there are;     and CONST_DOUBLE_LOW is the low-order word and ..._HIGH the high-order.    For a float, the number of ints varies,     and CONST_DOUBLE_LOW is the one that should come first *in memory*.     So use&CONST_DOUBLE_LOW(r) as the address of an array of ints.  */
end_comment

begin_define
define|#
directive|define
name|CONST_DOUBLE_LOW
parameter_list|(
name|r
parameter_list|)
value|XCWINT (r, 1, CONST_DOUBLE)
end_define

begin_define
define|#
directive|define
name|CONST_DOUBLE_HIGH
parameter_list|(
name|r
parameter_list|)
value|XCWINT (r, 2, CONST_DOUBLE)
end_define

begin_comment
comment|/* Link for chain of all CONST_DOUBLEs in use in current function.  */
end_comment

begin_define
define|#
directive|define
name|CONST_DOUBLE_CHAIN
parameter_list|(
name|r
parameter_list|)
value|XCEXP (r, 0, CONST_DOUBLE)
end_define

begin_comment
comment|/* For a SUBREG rtx, SUBREG_REG extracts the value we want a subreg of.    SUBREG_BYTE extracts the byte-number.  */
end_comment

begin_define
define|#
directive|define
name|SUBREG_REG
parameter_list|(
name|RTX
parameter_list|)
value|XCEXP (RTX, 0, SUBREG)
end_define

begin_define
define|#
directive|define
name|SUBREG_BYTE
parameter_list|(
name|RTX
parameter_list|)
value|XCUINT (RTX, 1, SUBREG)
end_define

begin_comment
comment|/* in rtlanal.c */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|subreg_lsb
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|subreg_regno_offset
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
operator|,
expr|enum
name|machine_mode
operator|,
name|unsigned
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
name|unsigned
name|int
name|subreg_regno
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 if the REG contained in SUBREG_REG is already known to be    sign- or zero-extended from the mode of the SUBREG to the mode of    the reg.  SUBREG_PROMOTED_UNSIGNED_P gives the signedness of the    extension.     When used as a LHS, is means that this extension must be done    when assigning to SUBREG_REG.  */
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
value|XCSTR (RTX, 0, ASM_OPERANDS)
end_define

begin_define
define|#
directive|define
name|ASM_OPERANDS_OUTPUT_CONSTRAINT
parameter_list|(
name|RTX
parameter_list|)
value|XCSTR (RTX, 1, ASM_OPERANDS)
end_define

begin_define
define|#
directive|define
name|ASM_OPERANDS_OUTPUT_IDX
parameter_list|(
name|RTX
parameter_list|)
value|XCINT (RTX, 2, ASM_OPERANDS)
end_define

begin_define
define|#
directive|define
name|ASM_OPERANDS_INPUT_VEC
parameter_list|(
name|RTX
parameter_list|)
value|XCVEC (RTX, 3, ASM_OPERANDS)
end_define

begin_define
define|#
directive|define
name|ASM_OPERANDS_INPUT_CONSTRAINT_VEC
parameter_list|(
name|RTX
parameter_list|)
value|XCVEC (RTX, 4, ASM_OPERANDS)
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
value|XCVECEXP (RTX, 3, N, ASM_OPERANDS)
end_define

begin_define
define|#
directive|define
name|ASM_OPERANDS_INPUT_LENGTH
parameter_list|(
name|RTX
parameter_list|)
value|XCVECLEN (RTX, 3, ASM_OPERANDS)
end_define

begin_define
define|#
directive|define
name|ASM_OPERANDS_INPUT_CONSTRAINT_EXP
parameter_list|(
name|RTX
parameter_list|,
name|N
parameter_list|)
define|\
value|XCVECEXP (RTX, 4, N, ASM_OPERANDS)
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
define|\
value|XSTR (XCVECEXP (RTX, 4, N, ASM_OPERANDS), 0)
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
define|\
value|GET_MODE (XCVECEXP (RTX, 4, N, ASM_OPERANDS))
end_define

begin_define
define|#
directive|define
name|ASM_OPERANDS_SOURCE_FILE
parameter_list|(
name|RTX
parameter_list|)
value|XCSTR (RTX, 5, ASM_OPERANDS)
end_define

begin_define
define|#
directive|define
name|ASM_OPERANDS_SOURCE_LINE
parameter_list|(
name|RTX
parameter_list|)
value|XCINT (RTX, 6, ASM_OPERANDS)
end_define

begin_comment
comment|/* For a MEM RTX, 1 if we should keep the alias set for this mem    unchanged when we access a component.  Set to 1, or example, when we    are already in a non-addressable component of an aggregate.  */
end_comment

begin_define
define|#
directive|define
name|MEM_KEEP_ALIAS_SET_P
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->jump)
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
comment|/* For a MEM rtx, 1 if it refers to an aggregate, either to the    aggregate itself of to a field of the aggregate.  If zero, RTX may    or may not be such a reference.  */
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
comment|/* For a MEM rtx, 1 if it refers to a scalar.  If zero, RTX may or may    not refer to a scalar.  */
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
value|do {						\   if (VAL)					\     {						\       MEM_IN_STRUCT_P (RTX) = 1;		\       MEM_SCALAR_P (RTX) = 0;			\     }						\   else						\     {						\       MEM_IN_STRUCT_P (RTX) = 0;		\       MEM_SCALAR_P (RTX) = 1;			\     }						\ } while (0)
end_define

begin_comment
comment|/* The memory attribute block.  We provide access macros for each value    in the block and provide defaults if none specified.  */
end_comment

begin_define
define|#
directive|define
name|MEM_ATTRS
parameter_list|(
name|RTX
parameter_list|)
value|X0MEMATTR (RTX, 1)
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
value|(MEM_ATTRS (RTX) == 0 ? 0 : MEM_ATTRS (RTX)->alias)
end_define

begin_comment
comment|/* For a MEM rtx, the decl it is known to refer to, if it is known to    refer to part of a DECL.  It may also be a COMPONENT_REF.  */
end_comment

begin_define
define|#
directive|define
name|MEM_EXPR
parameter_list|(
name|RTX
parameter_list|)
value|(MEM_ATTRS (RTX) == 0 ? 0 : MEM_ATTRS (RTX)->expr)
end_define

begin_comment
comment|/* For a MEM rtx, the offset from the start of MEM_EXPR, if known, as a    RTX that is always a CONST_INT.  */
end_comment

begin_define
define|#
directive|define
name|MEM_OFFSET
parameter_list|(
name|RTX
parameter_list|)
value|(MEM_ATTRS (RTX) == 0 ? 0 : MEM_ATTRS (RTX)->offset)
end_define

begin_comment
comment|/* For a MEM rtx, the size in bytes of the MEM, if known, as an RTX that    is always a CONST_INT.  */
end_comment

begin_define
define|#
directive|define
name|MEM_SIZE
parameter_list|(
name|RTX
parameter_list|)
define|\
value|(MEM_ATTRS (RTX) != 0 ? MEM_ATTRS (RTX)->size				\  : GET_MODE (RTX) != BLKmode ? GEN_INT (GET_MODE_SIZE (GET_MODE (RTX)))	\  : 0)
end_define

begin_comment
comment|/* For a MEM rtx, the alignment in bits.  We can use the alignment of the    mode as a default when STRICT_ALIGNMENT, but not if not.  */
end_comment

begin_define
define|#
directive|define
name|MEM_ALIGN
parameter_list|(
name|RTX
parameter_list|)
define|\
value|(MEM_ATTRS (RTX) != 0 ? MEM_ATTRS (RTX)->align				\  : (STRICT_ALIGNMENT&& GET_MODE (RTX) != BLKmode			\     ? GET_MODE_ALIGNMENT (GET_MODE (RTX)) : BITS_PER_UNIT))
end_define

begin_comment
comment|/* Copy the attributes that apply to memory locations from RHS to LHS.  */
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
value|(MEM_VOLATILE_P (LHS) = MEM_VOLATILE_P (RHS),			\    MEM_IN_STRUCT_P (LHS) = MEM_IN_STRUCT_P (RHS),		\    MEM_SCALAR_P (LHS) = MEM_SCALAR_P (RHS),			\    RTX_UNCHANGING_P (LHS) = RTX_UNCHANGING_P (RHS),		\    MEM_KEEP_ALIAS_SET_P (LHS) = MEM_KEEP_ALIAS_SET_P (RHS),	\    MEM_ATTRS (LHS) = MEM_ATTRS (RHS))
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
value|XC2EXP(RTX, 0, SET, CLOBBER)
end_define

begin_define
define|#
directive|define
name|SET_SRC
parameter_list|(
name|RTX
parameter_list|)
value|XCEXP(RTX, 1, SET)
end_define

begin_define
define|#
directive|define
name|SET_IS_RETURN_P
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->jump)
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
value|XCEXP (RTX, 0, TRAP_IF)
end_define

begin_define
define|#
directive|define
name|TRAP_CODE
parameter_list|(
name|RTX
parameter_list|)
value|XCEXP (RTX, 1, TRAP_IF)
end_define

begin_comment
comment|/* For a COND_EXEC rtx, COND_EXEC_TEST is the condition to base    conditionally executing the code on, COND_EXEC_CODE is the code    to execute if the condition is true.  */
end_comment

begin_define
define|#
directive|define
name|COND_EXEC_TEST
parameter_list|(
name|RTX
parameter_list|)
value|XCEXP (RTX, 0, COND_EXEC)
end_define

begin_define
define|#
directive|define
name|COND_EXEC_CODE
parameter_list|(
name|RTX
parameter_list|)
value|XCEXP (RTX, 1, COND_EXEC)
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
comment|/* 1 in a SYMBOL_REF if it addresses this function's string constant pool.  */
end_comment

begin_define
define|#
directive|define
name|STRING_POOL_ADDRESS_P
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->frame_related)
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
comment|/* 1 means a SYMBOL_REF is weak.  */
end_comment

begin_define
define|#
directive|define
name|SYMBOL_REF_WEAK
parameter_list|(
name|RTX
parameter_list|)
value|((RTX)->integrated)
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
name|INSN
parameter_list|,
name|REG
parameter_list|)
define|\
value|((REG) != NULL_RTX&& REG_P ((REG))			\    ? find_regno_note ((INSN), REG_INC, REGNO (REG))	\    : find_reg_note ((INSN), REG_INC, (REG)))
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
name|INSN
parameter_list|,
name|REG
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

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_POST_MODIFY_DISP
end_ifndef

begin_define
define|#
directive|define
name|HAVE_POST_MODIFY_DISP
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_POST_MODIFY_REG
end_ifndef

begin_define
define|#
directive|define
name|HAVE_POST_MODIFY_REG
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_PRE_MODIFY_DISP
end_ifndef

begin_define
define|#
directive|define
name|HAVE_PRE_MODIFY_DISP
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_PRE_MODIFY_REG
end_ifndef

begin_define
define|#
directive|define
name|HAVE_PRE_MODIFY_REG
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
value|XCEXP (INSN, 0, RANGE_INFO)
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
value|XCEXP (INSN, 1, RANGE_INFO)
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
value|XCVEC (INSN, 2, RANGE_INFO)
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
value|XCVECEXP (INSN, 2, N, RANGE_INFO)
end_define

begin_define
define|#
directive|define
name|RANGE_INFO_NUM_REGS
parameter_list|(
name|INSN
parameter_list|)
value|XCVECLEN (INSN, 2, RANGE_INFO)
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
value|XCINT (INSN, 3, RANGE_INFO)
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
value|XCINT (INSN, 4, RANGE_INFO)
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
value|XCINT (INSN, 5, RANGE_INFO)
end_define

begin_comment
comment|/* For RANGE_{START,END} notes, the basic block # the range starts with.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_INFO_BB_START
parameter_list|(
name|INSN
parameter_list|)
value|XCINT (INSN, 6, RANGE_INFO)
end_define

begin_comment
comment|/* For RANGE_{START,END} notes, the basic block # the range ends with.  */
end_comment

begin_define
define|#
directive|define
name|RANGE_INFO_BB_END
parameter_list|(
name|INSN
parameter_list|)
value|XCINT (INSN, 7, RANGE_INFO)
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
value|XCINT (INSN, 8, RANGE_INFO)
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
value|XCBITMAP (INSN, 9, RANGE_INFO)
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
value|XCBITMAP (INSN, 10, RANGE_INFO)
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
value|XCINT (INSN, 11, RANGE_INFO)
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
value|XCINT (INSN, 12, RANGE_INFO)
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
value|XCINT (XCVECEXP (INSN, 2, N, RANGE_INFO), 0, REG)
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
value|XCINT (XCVECEXP (INSN, 2, N, RANGE_INFO), 1, REG)
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
value|XINT (XCVECEXP (INSN, 2, N, RANGE_INFO), 2)
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
value|XINT (XCVECEXP (INSN, 2, N, RANGE_INFO), 3)
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
value|XINT (XCVECEXP (INSN, 2, N, RANGE_INFO), 4)
end_define

begin_comment
comment|/* Whether the original value is needed to be copied into the range register at    the start of the range.  */
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
value|XINT (XCVECEXP (INSN, 2, N, RANGE_INFO), 5)
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
value|XINT (XCVECEXP (INSN, 2, N, RANGE_INFO), 6)
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
value|XINT (XCVECEXP (INSN, 2, N, RANGE_INFO), 7)
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
value|XTREE (XCVECEXP (INSN, 2, N, RANGE_INFO), 8)
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
value|XTREE (XCVECEXP (INSN, 2, N, RANGE_INFO), 9)
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

begin_comment
comment|/* Determine if the insn is a PHI node.  */
end_comment

begin_define
define|#
directive|define
name|PHI_NODE_P
parameter_list|(
name|X
parameter_list|)
define|\
value|((X)&& GET_CODE (X) == INSN			\&& GET_CODE (PATTERN (X)) == SET		\&& GET_CODE (SET_SRC (PATTERN (X))) == PHI)
end_define

begin_escape
end_escape

begin_comment
comment|/* Nonzero if we need to distinguish between the return value of this function    and the return value of a function called by this function.  This helps    integrate.c.    This is 1 until after the rtl generation pass.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rtx_equal_function_value_matters
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero when we are generating CONCATs.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|generating_concat_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generally useful functions.  */
end_comment

begin_comment
comment|/* In expmed.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ceil_log2
name|PARAMS
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
value|plus_constant_wide ((X), (HOST_WIDE_INT) (C))
end_define

begin_comment
comment|/* In builtins.c */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|expand_builtin_expect_jump
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In explow.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|set_stack_check_libfunc
name|PARAMS
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
name|trunc_int_for_mode
name|PARAMS
argument_list|(
operator|(
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
name|plus_constant_wide
name|PARAMS
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
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In emit-rtl.c */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|gen_rtx
name|PARAMS
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
name|PARAMS
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
name|copy_insn_1
name|PARAMS
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
name|copy_insn
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In rtl.c */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|rtx_alloc
name|PARAMS
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
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In emit-rtl.c */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|copy_rtx_if_shared
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In rtl.c */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|copy_most_rtx
name|PARAMS
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
name|PARAMS
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
name|rtx_equal_p
name|PARAMS
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
comment|/* In emit-rtl.c */
end_comment

begin_decl_stmt
specifier|extern
name|rtvec
name|gen_rtvec_v
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|subreg_hard_regno
name|PARAMS
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
name|gen_lowpart_common
name|PARAMS
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
name|PARAMS
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
comment|/* In cse.c */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|gen_lowpart_if_possible
name|PARAMS
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
comment|/* In emit-rtl.c */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|gen_highpart
name|PARAMS
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
name|gen_highpart_mode
name|PARAMS
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|unsigned
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
name|constant_subword
name|PARAMS
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

begin_comment
comment|/* In emit-rtl.c */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|operand_subword_force
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|unsigned
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
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|subreg_lowpart_offset
name|PARAMS
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|subreg_highpart_offset
name|PARAMS
argument_list|(
operator|(
expr|enum
name|machine_mode
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
name|make_safe_from
name|PARAMS
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
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|get_insn_name
name|PARAMS
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
name|get_last_insn
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|push_to_full_sequence
name|PARAMS
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
name|end_full_sequence
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|*
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
name|gen_sequence
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In varasm.c  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|immed_double_const
name|PARAMS
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
name|mem_for_const_double
name|PARAMS
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
name|force_const_mem
name|PARAMS
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
comment|/* In varasm.c  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|get_pool_constant
name|PARAMS
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
name|PARAMS
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
name|get_pool_constant_for_function
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
operator|*
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|machine_mode
name|get_pool_mode_for_function
name|PARAMS
argument_list|(
operator|(
expr|struct
name|function
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
name|get_pool_offset
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In function.c  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|assign_stack_local
name|PARAMS
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
name|PARAMS
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
name|assign_stack_temp_for_type
name|PARAMS
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|HOST_WIDE_INT
operator|,
name|int
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|assign_temp
name|PARAMS
argument_list|(
operator|(
name|tree
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
comment|/* In emit-rtl.c */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|emit_insn_before
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
specifier|const
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
specifier|const
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
name|PARAMS
argument_list|(
operator|(
specifier|const
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
name|PARAMS
argument_list|(
operator|(
specifier|const
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|active_insn_p
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In jump.c */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|next_nondeleted_insn
name|PARAMS
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
name|PARAMS
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
name|reverse_condition_maybe_unordered
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|void
name|mark_jump_label
name|PARAMS
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
name|cleanup_barriers
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In jump.c */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|squeeze_notes
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|*
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
name|delete_related_insns
name|PARAMS
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
name|PARAMS
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
name|delete_barrier
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In recog.c  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
modifier|*
name|find_constant_term_loc
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In emit-rtl.c  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|try_split
name|PARAMS
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
name|int
name|split_branch_probability
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In unknown file  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|split_insns
name|PARAMS
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
comment|/* In simplify-rtx.c  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|simplify_unary_operation
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|simplify_gen_binary
name|PARAMS
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
name|simplify_gen_unary
name|PARAMS
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
name|simplify_gen_ternary
name|PARAMS
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
name|simplify_gen_relational
name|PARAMS
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|simplify_subreg
name|PARAMS
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|rtx
operator|,
expr|enum
name|machine_mode
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|simplify_gen_subreg
name|PARAMS
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|rtx
operator|,
expr|enum
name|machine_mode
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|simplify_replace_rtx
name|PARAMS
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
name|simplify_rtx
name|PARAMS
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
name|avoid_constant_pool_reference
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In function.c  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|gen_mem_addressof
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In regclass.c  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|machine_mode
name|choose_hard_reg_mode
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In emit-rtl.c  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|set_unique_reg_note
name|PARAMS
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

begin_comment
comment|/* Single set is implemented as macro for performance reasons.  */
end_comment

begin_define
define|#
directive|define
name|single_set
parameter_list|(
name|I
parameter_list|)
value|(INSN_P (I) \ 		       ? (GET_CODE (PATTERN (I)) == SET \ 			  ? PATTERN (I) : single_set_1 (I)) \ 		       : NULL_RTX)
end_define

begin_define
define|#
directive|define
name|single_set_1
parameter_list|(
name|I
parameter_list|)
value|single_set_2 (I, PATTERN (I))
end_define

begin_decl_stmt
specifier|extern
name|int
name|rtx_addr_can_trap_p
name|PARAMS
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
name|rtx_unstable_p
name|PARAMS
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
name|PARAMS
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
name|rtx_addr_varies_p
name|PARAMS
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
name|HOST_WIDE_INT
name|get_integer_term
name|PARAMS
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
name|PARAMS
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
name|get_jump_table_offset
name|PARAMS
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
name|reg_mentioned_p
name|PARAMS
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
name|count_occurrences
name|PARAMS
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
name|int
name|reg_referenced_p
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|commutative_operand_precedence
name|PARAMS
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
name|swap_commutative_operands_p
name|PARAMS
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
name|modified_between_p
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|insn_dependent_p
name|PARAMS
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
name|PARAMS
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
name|single_set_2
name|PARAMS
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
name|multiple_sets
name|PARAMS
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
name|set_noop_p
name|PARAMS
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
name|noop_move_p
name|PARAMS
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
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
operator|,
name|unsigned
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
name|PARAMS
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
name|set_of
name|PARAMS
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
name|PARAMS
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
argument_list|,
name|void
operator|*
argument_list|)
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|note_uses
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|*
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|rtx
operator|*
argument_list|,
name|void
operator|*
argument_list|)
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
name|reg_set_last
name|PARAMS
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
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|find_reg_note
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|reg_note
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|find_reg_equal_equiv_note
name|PARAMS
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
name|find_reg_fusage
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|rtx_code
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|remove_note
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|*
operator|,
name|unsigned
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
name|unsigned
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
name|PARAMS
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
name|in_expr_list_p
name|PARAMS
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
name|remove_node_from_expr_list
name|PARAMS
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
name|PARAMS
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
name|int
name|loc_mentioned_in_p
name|PARAMS
argument_list|(
operator|(
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
name|find_first_parameter_load
name|PARAMS
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
comment|/* flow.c */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|find_use_as_address
name|PARAMS
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

begin_decl_stmt
name|void
name|init_EXPR_INSN_LIST_cache
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|free_EXPR_LIST_list
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|free_INSN_LIST_list
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|free_EXPR_LIST_node
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|free_INSN_LIST_node
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|rtx
name|alloc_INSN_LIST
name|PARAMS
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
name|rtx
name|alloc_EXPR_LIST
name|PARAMS
argument_list|(
operator|(
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
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|decode_asm_operands
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|split_all_insns
name|PARAMS
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
name|split_all_insns_noflow
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MAX_SAVED_CONST_INT
value|64
end_define

begin_decl_stmt
specifier|extern
name|rtx
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
value|(const_int_rtx[MAX_SAVED_CONST_INT])
end_define

begin_define
define|#
directive|define
name|const1_rtx
value|(const_int_rtx[MAX_SAVED_CONST_INT+1])
end_define

begin_define
define|#
directive|define
name|const2_rtx
value|(const_int_rtx[MAX_SAVED_CONST_INT+2])
end_define

begin_define
define|#
directive|define
name|constm1_rtx
value|(const_int_rtx[MAX_SAVED_CONST_INT-1])
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
comment|/* Returns a constant 0 rtx in mode MODE.  Integer modes are treated the    same as VOIDmode.  */
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
comment|/* If HARD_FRAME_POINTER_REGNUM is defined, then a special dummy reg    is used to represent the frame pointer.  This is because the    hard frame pointer and the automatic variables are separated by an amount    that cannot be determined until after register allocation.  We can assume    that in this case ELIMINABLE_REGS will be defined, one action of which    will be to eliminate FRAME_POINTER_REGNUM into HARD_FRAME_POINTER_REGNUM.  */
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
comment|/* Index labels for global_rtl.  */
end_comment

begin_enum
enum|enum
name|global_rtl_index
block|{
name|GR_PC
block|,
name|GR_CC0
block|,
name|GR_STACK_POINTER
block|,
name|GR_FRAME_POINTER
block|,
comment|/* For register elimination to work properly these hard_frame_pointer_rtx,    frame_pointer_rtx, and arg_pointer_rtx must be the same if they refer to    the same register.  */
if|#
directive|if
name|FRAME_POINTER_REGNUM
operator|==
name|ARG_POINTER_REGNUM
name|GR_ARG_POINTER
init|=
name|GR_FRAME_POINTER
block|,
endif|#
directive|endif
if|#
directive|if
name|HARD_FRAME_POINTER_REGNUM
operator|==
name|FRAME_POINTER_REGNUM
name|GR_HARD_FRAME_POINTER
init|=
name|GR_FRAME_POINTER
block|,
else|#
directive|else
name|GR_HARD_FRAME_POINTER
block|,
endif|#
directive|endif
if|#
directive|if
name|FRAME_POINTER_REGNUM
operator|!=
name|ARG_POINTER_REGNUM
if|#
directive|if
name|HARD_FRAME_POINTER_REGNUM
operator|==
name|ARG_POINTER_REGNUM
name|GR_ARG_POINTER
init|=
name|GR_HARD_FRAME_POINTER
block|,
else|#
directive|else
name|GR_ARG_POINTER
block|,
endif|#
directive|endif
endif|#
directive|endif
name|GR_VIRTUAL_INCOMING_ARGS
block|,
name|GR_VIRTUAL_STACK_ARGS
block|,
name|GR_VIRTUAL_STACK_DYNAMIC
block|,
name|GR_VIRTUAL_OUTGOING_ARGS
block|,
name|GR_VIRTUAL_CFA
block|,
name|GR_MAX
block|}
enum|;
end_enum

begin_comment
comment|/* Pointers to standard pieces of rtx are stored here.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|global_rtl
index|[
name|GR_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Standard pieces of rtx, to be substituted directly into things.  */
end_comment

begin_define
define|#
directive|define
name|pc_rtx
value|(global_rtl[GR_PC])
end_define

begin_define
define|#
directive|define
name|cc0_rtx
value|(global_rtl[GR_CC0])
end_define

begin_comment
comment|/* All references to certain hard regs, except those created    by allocating pseudo regs into them (when that's possible),    go through these unique rtx objects.  */
end_comment

begin_define
define|#
directive|define
name|stack_pointer_rtx
value|(global_rtl[GR_STACK_POINTER])
end_define

begin_define
define|#
directive|define
name|frame_pointer_rtx
value|(global_rtl[GR_FRAME_POINTER])
end_define

begin_define
define|#
directive|define
name|hard_frame_pointer_rtx
value|(global_rtl[GR_HARD_FRAME_POINTER])
end_define

begin_define
define|#
directive|define
name|arg_pointer_rtx
value|(global_rtl[GR_ARG_POINTER])
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
name|PARAMS
argument_list|(
operator|(
expr|enum
name|machine_mode
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
name|PARAMS
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
name|gen_raw_REG
name|PARAMS
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
name|gen_rtx_REG
name|PARAMS
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
name|gen_rtx_SUBREG
name|PARAMS
argument_list|(
operator|(
expr|enum
name|machine_mode
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
name|gen_rtx_MEM
name|PARAMS
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
name|gen_lowpart_SUBREG
name|PARAMS
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
value|(global_rtl[GR_VIRTUAL_INCOMING_ARGS])
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
value|(global_rtl[GR_VIRTUAL_STACK_ARGS])
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
value|(global_rtl[GR_VIRTUAL_STACK_DYNAMIC])
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
value|(global_rtl[GR_VIRTUAL_OUTGOING_ARGS])
end_define

begin_define
define|#
directive|define
name|VIRTUAL_OUTGOING_ARGS_REGNUM
value|((FIRST_VIRTUAL_REGISTER) + 3)
end_define

begin_comment
comment|/* This points to the Canonical Frame Address of the function.  This    should corrospond to the CFA produced by INCOMING_FRAME_SP_OFFSET,    but is calculated relative to the arg pointer for simplicity; the    frame pointer nor stack pointer are necessarily fixed relative to    the CFA until after reload.  */
end_comment

begin_define
define|#
directive|define
name|virtual_cfa_rtx
value|(global_rtl[GR_VIRTUAL_CFA])
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

begin_comment
comment|/* Nonzero if REGNUM is a pointer into the stack frame.  */
end_comment

begin_define
define|#
directive|define
name|REGNO_PTR_FRAME_P
parameter_list|(
name|REGNUM
parameter_list|)
define|\
value|((REGNUM) == STACK_POINTER_REGNUM		\    || (REGNUM) == FRAME_POINTER_REGNUM		\    || (REGNUM) == HARD_FRAME_POINTER_REGNUM	\    || (REGNUM) == ARG_POINTER_REGNUM		\    || ((REGNUM)>= FIRST_VIRTUAL_REGISTER	\&& (REGNUM)<= LAST_VIRTUAL_REGISTER))
end_define

begin_comment
comment|/* REGNUM never really appearing in the INSN stream.  */
end_comment

begin_define
define|#
directive|define
name|INVALID_REGNUM
value|(~(unsigned int) 0)
end_define

begin_decl_stmt
specifier|extern
name|rtx
name|find_next_ref
name|PARAMS
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
name|output_constant_def
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|immed_real_const
name|PARAMS
argument_list|(
operator|(
name|tree
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
comment|/* Translates rtx code to tree code, for those codes needed by    REAL_ARITHMETIC.  The function returns an int because the caller may not    know what `enum tree_code' means.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rtx_to_tree_code
name|PARAMS
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

begin_struct_decl
struct_decl|struct
name|obstack
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|void
name|gcc_obstack_init
name|PARAMS
argument_list|(
operator|(
expr|struct
name|obstack
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In cse.c */
end_comment

begin_struct_decl
struct_decl|struct
name|cse_basic_block_data
struct_decl|;
end_struct_decl

begin_comment
comment|/* Return the right cost to give to an operation    to make the cost of the corresponding register-to-register instruction    N times that of a fast register-to-register instruction.  */
end_comment

begin_define
define|#
directive|define
name|COSTS_N_INSNS
parameter_list|(
name|N
parameter_list|)
value|((N) * 4)
end_define

begin_comment
comment|/* Maximum cost of a rtl expression.  This value has the special meaning    not to use an rtx with this cost under any circumstances.  */
end_comment

begin_define
define|#
directive|define
name|MAX_COST
value|INT_MAX
end_define

begin_decl_stmt
specifier|extern
name|int
name|rtx_cost
name|PARAMS
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
name|int
name|address_cost
name|PARAMS
argument_list|(
operator|(
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
name|void
name|delete_trivially_dead_insns
name|PARAMS
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
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|cse_main
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|any_condjump_p
name|PARAMS
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
name|any_uncondjump_p
name|PARAMS
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
name|safe_to_remove_jump_p
name|PARAMS
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
name|pc_set
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|onlyjump_p
name|PARAMS
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
name|only_sets_cc0_p
name|PARAMS
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
name|PARAMS
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
name|invert_jump_1
name|PARAMS
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
name|invert_jump
name|PARAMS
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
name|int
name|rtx_renumbered_equal_p
name|PARAMS
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
name|PARAMS
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
name|redirect_jump_1
name|PARAMS
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
name|redirect_jump
name|PARAMS
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
name|rebuild_jump_labels
name|PARAMS
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
name|reversed_comparison_code
name|PARAMS
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
name|enum
name|rtx_code
name|reversed_comparison_code_parts
name|PARAMS
argument_list|(
operator|(
expr|enum
name|rtx_code
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
name|void
name|delete_for_peephole
name|PARAMS
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
name|PARAMS
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
name|never_reached_warning
name|PARAMS
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
name|purge_line_number_notes
name|PARAMS
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
name|copy_loop_headers
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In emit-rtl.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|max_reg_num
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|reorder_insns_nobb
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|clear_emit_caches
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|set_new_last_label_num
name|PARAMS
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
name|unshare_all_rtl_again
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|emit
name|PARAMS
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
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
name|int
name|old_value
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|renumber_insns
name|PARAMS
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
name|remove_unnecessary_notes
name|PARAMS
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
name|delete_insn
name|PARAMS
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
name|delete_insn_chain
name|PARAMS
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
comment|/* In combine.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|combine_instructions
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|extended_count
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
name|unsigned
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
name|PARAMS
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
name|PARAMS
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
comment|/* In sched.c.  */
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
name|PARAMS
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
name|schedule_ebbs
name|PARAMS
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
name|fix_sched_param
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In print-rtl.c */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|print_rtx_head
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|debug_rtx
name|PARAMS
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
name|PARAMS
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
name|debug_rtx_range
name|PARAMS
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
name|debug_rtx_find
name|PARAMS
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
name|print_mem_expr
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_rtl
name|PARAMS
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
name|print_simple_rtl
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|FILE
operator|*
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|prologue_epilogue_contains
name|PARAMS
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
name|sibcall_epilogue_contains
name|PARAMS
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
name|preserve_rtl_expr_result
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|purge_hard_subreg_sets
name|PARAMS
argument_list|(
operator|(
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
name|set_file_and_line_for_stmt
name|PARAMS
argument_list|(
operator|(
specifier|const
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
name|void
name|expand_null_return
name|PARAMS
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
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In expr.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|move_by_pieces
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|unsigned
name|HOST_WIDE_INT
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In flow.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|recompute_reg_usage
name|PARAMS
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
name|initialize_uninitialized_subregs
name|PARAMS
argument_list|(
operator|(
name|void
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
name|print_rtl_with_bb
name|PARAMS
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
name|dump_flow_info
name|PARAMS
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
comment|/* In expmed.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_expmed
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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

begin_decl_stmt
specifier|extern
name|void
name|build_insn_chain
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In regclass.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|reg_classes_intersect_p
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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

begin_decl_stmt
specifier|extern
name|void
name|reg_scan
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|unsigned
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
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fix_register
name|PARAMS
argument_list|(
operator|(
specifier|const
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

begin_decl_stmt
specifier|extern
name|void
name|delete_null_pointer_checks
name|PARAMS
argument_list|(
operator|(
name|rtx
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
name|PARAMS
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

begin_decl_stmt
specifier|extern
name|void
name|combine_stack_adjustments
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
name|rtx
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
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|branch_prob
name|PARAMS
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
name|end_branch_prob
name|PARAMS
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
name|output_func_start_profiler
name|PARAMS
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
name|PARAMS
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
comment|/* In fold-const.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|add_double
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|unsigned
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|unsigned
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
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|unsigned
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
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|unsigned
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|unsigned
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
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|unsigned
name|int
operator|,
name|unsigned
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
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|unsigned
name|int
operator|,
name|unsigned
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
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|unsigned
name|int
operator|,
name|unsigned
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
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|HOST_WIDE_INT
operator|,
name|unsigned
name|int
operator|,
name|unsigned
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

begin_enum
enum|enum
name|libcall_type
block|{
name|LCT_NORMAL
init|=
literal|0
block|,
name|LCT_CONST
init|=
literal|1
block|,
name|LCT_PURE
init|=
literal|2
block|,
name|LCT_CONST_MAKE_BLOCK
init|=
literal|3
block|,
name|LCT_PURE_MAKE_BLOCK
init|=
literal|4
block|,
name|LCT_NORETURN
init|=
literal|5
block|,
name|LCT_THROW
init|=
literal|6
block|,
name|LCT_ALWAYS_RETURN
init|=
literal|7
block|,
name|LCT_RETURNS_TWICE
init|=
literal|8
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|void
name|emit_library_call
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|libcall_type
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
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
expr|enum
name|libcall_type
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
name|PARAMS
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
name|int
name|in_data_section
name|PARAMS
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
name|init_varasm_once
name|PARAMS
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
name|PARAMS
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
name|traverse_md_constants
name|PARAMS
argument_list|(
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
operator|*
argument_list|,
name|void
operator|*
argument_list|)
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|md_constant
block|{
name|char
modifier|*
name|name
decl_stmt|,
modifier|*
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|read_skip_spaces
name|PARAMS
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
name|rtx
name|read_rtx
name|PARAMS
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
specifier|const
name|char
modifier|*
name|read_rtx_filename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|read_rtx_lineno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Redefine abort to report an internal error w/o coredump, and    reporting the location of the error in the source file.  This logic    is duplicated in rtl.h and tree.h because every file that needs the    special abort includes one or both.  toplev.h gets too few files,    system.h gets too many.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|fancy_abort
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|abort
parameter_list|()
value|fancy_abort (__FILE__, __LINE__, __FUNCTION__)
end_define

begin_comment
comment|/* In alias.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|clear_reg_alias_info
name|PARAMS
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
name|canon_rtx
name|PARAMS
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
name|true_dependence
name|PARAMS
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
argument_list|,
name|int
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|get_addr
name|PARAMS
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
name|canon_true_dependence
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|machine_mode
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|rtx
argument_list|,
name|int
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|read_dependence
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|mark_constant_function
name|PARAMS
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
name|init_alias_once
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|addr_side_effect_eval
name|PARAMS
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

begin_comment
comment|/* In sibcall.c */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|sibcall_use_normal
init|=
literal|1
block|,
name|sibcall_use_tail_recursion
block|,
name|sibcall_use_sibcall
block|}
name|sibcall_use_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|void
name|optimize_sibling_and_tail_recursive_calls
name|PARAMS
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
name|replace_call_placeholder
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|sibcall_use_t
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
name|PARAMS
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

begin_comment
comment|/* In toplev.c */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|stack_limit_rtx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In regrename.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|regrename_optimize
name|PARAMS
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
name|copyprop_hardreg_forward
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In ifcvt.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|if_convert
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In predict.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|invert_br_probabilities
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|expensive_function_p
name|PARAMS
argument_list|(
operator|(
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
comment|/* ! GCC_RTL_H */
end_comment

end_unit

