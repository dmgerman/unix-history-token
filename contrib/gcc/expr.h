begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for code generation pass of GNU compiler.    Copyright (C) 1987, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998,    1999, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* The default branch cost is 1.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BRANCH_COST
end_ifndef

begin_define
define|#
directive|define
name|BRANCH_COST
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Macros to access the slots of a QUEUED rtx.    Here rather than in rtl.h because only the expansion pass    should ever encounter a QUEUED.  */
end_comment

begin_comment
comment|/* The variable for which an increment is queued.  */
end_comment

begin_define
define|#
directive|define
name|QUEUED_VAR
parameter_list|(
name|P
parameter_list|)
value|XEXP (P, 0)
end_define

begin_comment
comment|/* If the increment has been emitted, this is the insn    that does the increment.  It is zero before the increment is emitted.    If more than one insn is emitted, this is the first insn.  */
end_comment

begin_define
define|#
directive|define
name|QUEUED_INSN
parameter_list|(
name|P
parameter_list|)
value|XEXP (P, 1)
end_define

begin_comment
comment|/* If a pre-increment copy has been generated, this is the copy    (it is a temporary reg).  Zero if no copy made yet.  */
end_comment

begin_define
define|#
directive|define
name|QUEUED_COPY
parameter_list|(
name|P
parameter_list|)
value|XEXP (P, 2)
end_define

begin_comment
comment|/* This is the body to use for the insn to do the increment.    It is used to emit the increment.  */
end_comment

begin_define
define|#
directive|define
name|QUEUED_BODY
parameter_list|(
name|P
parameter_list|)
value|XEXP (P, 3)
end_define

begin_comment
comment|/* Next QUEUED in the queue.  */
end_comment

begin_define
define|#
directive|define
name|QUEUED_NEXT
parameter_list|(
name|P
parameter_list|)
value|XEXP (P, 4)
end_define

begin_comment
comment|/* This is the 4th arg to `expand_expr'.    EXPAND_STACK_PARM means we are possibly expanding a call param onto    the stack.  Choosing a value of 2 isn't special;  It just allows    some code optimization in store_expr.    EXPAND_SUM means it is ok to return a PLUS rtx or MULT rtx.    EXPAND_INITIALIZER is similar but also record any labels on forced_labels.    EXPAND_CONST_ADDRESS means it is ok to return a MEM whose address     is a constant that is not a legitimate address.    EXPAND_WRITE means we are only going to write to the resulting rtx.    EXPAND_MEMORY means we are interested in a memory result, even if     the memory is constant and we could have propagated a constant value.  */
end_comment

begin_enum
enum|enum
name|expand_modifier
block|{
name|EXPAND_NORMAL
init|=
literal|0
block|,
name|EXPAND_STACK_PARM
init|=
literal|2
block|,
name|EXPAND_SUM
block|,
name|EXPAND_CONST_ADDRESS
block|,
name|EXPAND_INITIALIZER
block|,
name|EXPAND_WRITE
block|,
name|EXPAND_MEMORY
block|}
enum|;
end_enum

begin_comment
comment|/* Prevent the compiler from deferring stack pops.  See    inhibit_defer_pop for more information.  */
end_comment

begin_define
define|#
directive|define
name|NO_DEFER_POP
value|(inhibit_defer_pop += 1)
end_define

begin_comment
comment|/* Allow the compiler to defer stack pops.  See inhibit_defer_pop for    more information.  */
end_comment

begin_define
define|#
directive|define
name|OK_DEFER_POP
value|(inhibit_defer_pop -= 1)
end_define

begin_escape
end_escape

begin_comment
comment|/* If a memory-to-memory move would take MOVE_RATIO or more simple    move-instruction sequences, we will do a movstr or libcall instead.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MOVE_RATIO
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_movstrqi
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_movstrhi
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_movstrsi
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_movstrdi
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_movstrti
argument_list|)
end_if

begin_define
define|#
directive|define
name|MOVE_RATIO
value|2
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* If we are optimizing for space (-Os), cut down the default move ratio.  */
end_comment

begin_define
define|#
directive|define
name|MOVE_RATIO
value|(optimize_size ? 3 : 15)
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
comment|/* If a clear memory operation would take CLEAR_RATIO or more simple    move-instruction sequences, we will do a clrstr or libcall instead.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CLEAR_RATIO
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_clrstrqi
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_clrstrhi
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_clrstrsi
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_clrstrdi
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_clrstrti
argument_list|)
end_if

begin_define
define|#
directive|define
name|CLEAR_RATIO
value|2
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* If we are optimizing for space, cut down the default clear ratio.  */
end_comment

begin_define
define|#
directive|define
name|CLEAR_RATIO
value|(optimize_size ? 3 : 15)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_enum
enum|enum
name|direction
block|{
name|none
block|,
name|upward
block|,
name|downward
block|}
enum|;
end_enum

begin_comment
comment|/* Structure to record the size of a sequence of arguments    as the sum of a tree-expression and a constant.  This structure is    also used to store offsets from the stack, which might be negative,    so the variable part must be ssizetype, not sizetype.  */
end_comment

begin_struct
struct|struct
name|args_size
block|{
name|HOST_WIDE_INT
name|constant
decl_stmt|;
name|tree
name|var
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Package up various arg related fields of struct args for    locate_and_pad_parm.  */
end_comment

begin_struct
struct|struct
name|locate_and_pad_arg_data
block|{
comment|/* Size of this argument on the stack, rounded up for any padding it      gets.  If REG_PARM_STACK_SPACE is defined, then register parms are      counted here, otherwise they aren't.  */
name|struct
name|args_size
name|size
decl_stmt|;
comment|/* Offset of this argument from beginning of stack-args.  */
name|struct
name|args_size
name|offset
decl_stmt|;
comment|/* Offset to the start of the stack slot.  Different from OFFSET      if this arg pads downward.  */
name|struct
name|args_size
name|slot_offset
decl_stmt|;
comment|/* The amount that the stack pointer needs to be adjusted to      force alignment for the next argument.  */
name|struct
name|args_size
name|alignment_pad
decl_stmt|;
comment|/* Which way we should pad this arg.  */
name|enum
name|direction
name|where_pad
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Add the value of the tree INC to the `struct args_size' TO.  */
end_comment

begin_define
define|#
directive|define
name|ADD_PARM_SIZE
parameter_list|(
name|TO
parameter_list|,
name|INC
parameter_list|)
define|\
value|do {							\   tree inc = (INC);					\   if (host_integerp (inc, 0))				\     (TO).constant += tree_low_cst (inc, 0);		\   else if ((TO).var == 0)				\     (TO).var = convert (ssizetype, inc);		\   else							\     (TO).var = size_binop (PLUS_EXPR, (TO).var,		\ 			   convert (ssizetype, inc));	\ } while (0)
end_define

begin_define
define|#
directive|define
name|SUB_PARM_SIZE
parameter_list|(
name|TO
parameter_list|,
name|DEC
parameter_list|)
define|\
value|do {							\   tree dec = (DEC);					\   if (host_integerp (dec, 0))				\     (TO).constant -= tree_low_cst (dec, 0);		\   else if ((TO).var == 0)				\     (TO).var = size_binop (MINUS_EXPR, ssize_int (0),	\ 			   convert (ssizetype, dec));	\   else							\     (TO).var = size_binop (MINUS_EXPR, (TO).var,	\ 			   convert (ssizetype, dec));	\ } while (0)
end_define

begin_comment
comment|/* Convert the implicit sum in a `struct args_size' into a tree    of type ssizetype.  */
end_comment

begin_define
define|#
directive|define
name|ARGS_SIZE_TREE
parameter_list|(
name|SIZE
parameter_list|)
define|\
value|((SIZE).var == 0 ? ssize_int ((SIZE).constant)			\  : size_binop (PLUS_EXPR, convert (ssizetype, (SIZE).var),	\ 	       ssize_int ((SIZE).constant)))
end_define

begin_comment
comment|/* Convert the implicit sum in a `struct args_size' into an rtx.  */
end_comment

begin_define
define|#
directive|define
name|ARGS_SIZE_RTX
parameter_list|(
name|SIZE
parameter_list|)
define|\
value|((SIZE).var == 0 ? GEN_INT ((SIZE).constant)			\  : expand_expr (ARGS_SIZE_TREE (SIZE), NULL_RTX, VOIDmode, 0))
end_define

begin_comment
comment|/* Supply a default definition for FUNCTION_ARG_PADDING:    usually pad upward, but pad short args downward on    big-endian machines.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_FUNCTION_ARG_PADDING
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|(! BYTES_BIG_ENDIAN							\    ? upward								\    : (((MODE) == BLKmode						\        ? ((TYPE)&& TREE_CODE (TYPE_SIZE (TYPE)) == INTEGER_CST		\&& int_size_in_bytes (TYPE)< (PARM_BOUNDARY / BITS_PER_UNIT)) \        : GET_MODE_BITSIZE (MODE)< PARM_BOUNDARY)			\       ? downward : upward))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|FUNCTION_ARG_PADDING
end_ifndef

begin_define
define|#
directive|define
name|FUNCTION_ARG_PADDING
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|DEFAULT_FUNCTION_ARG_PADDING ((MODE), (TYPE))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Supply a default definition for FUNCTION_ARG_BOUNDARY.  Normally, we let    FUNCTION_ARG_PADDING, which also pads the length, handle any needed    alignment.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FUNCTION_ARG_BOUNDARY
end_ifndef

begin_define
define|#
directive|define
name|FUNCTION_ARG_BOUNDARY
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|)
value|PARM_BOUNDARY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|tree
name|split_complex_types
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|split_complex_values
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Nonzero if we do not know how to pass TYPE solely in registers.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|default_must_pass_in_stack
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|MUST_PASS_IN_STACK
end_ifndef

begin_define
define|#
directive|define
name|MUST_PASS_IN_STACK
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|)
value|default_must_pass_in_stack(MODE, TYPE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Supply a default definition of STACK_SAVEAREA_MODE for emit_stack_save.    Normally move_insn, so Pmode stack pointer.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STACK_SAVEAREA_MODE
end_ifndef

begin_define
define|#
directive|define
name|STACK_SAVEAREA_MODE
parameter_list|(
name|LEVEL
parameter_list|)
value|Pmode
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Supply a default definition of STACK_SIZE_MODE for    allocate_dynamic_stack_space.  Normally PLUS/MINUS, so word_mode.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STACK_SIZE_MODE
end_ifndef

begin_define
define|#
directive|define
name|STACK_SIZE_MODE
value|word_mode
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Provide default values for the macros controlling stack checking.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STACK_CHECK_BUILTIN
end_ifndef

begin_define
define|#
directive|define
name|STACK_CHECK_BUILTIN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The default interval is one page.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STACK_CHECK_PROBE_INTERVAL
end_ifndef

begin_define
define|#
directive|define
name|STACK_CHECK_PROBE_INTERVAL
value|4096
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The default is to do a store into the stack.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STACK_CHECK_PROBE_LOAD
end_ifndef

begin_define
define|#
directive|define
name|STACK_CHECK_PROBE_LOAD
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This value is arbitrary, but should be sufficient for most machines.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STACK_CHECK_PROTECT
end_ifndef

begin_define
define|#
directive|define
name|STACK_CHECK_PROTECT
value|(75 * UNITS_PER_WORD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Make the maximum frame size be the largest we can and still only need    one probe per function.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STACK_CHECK_MAX_FRAME_SIZE
end_ifndef

begin_define
define|#
directive|define
name|STACK_CHECK_MAX_FRAME_SIZE
define|\
value|(STACK_CHECK_PROBE_INTERVAL - UNITS_PER_WORD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is arbitrary, but should be large enough everywhere.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STACK_CHECK_FIXED_FRAME_SIZE
end_ifndef

begin_define
define|#
directive|define
name|STACK_CHECK_FIXED_FRAME_SIZE
value|(4 * UNITS_PER_WORD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Provide a reasonable default for the maximum size of an object to    allocate in the fixed frame.  We may need to be able to make this    controllable by the user at some point.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STACK_CHECK_MAX_VAR_SIZE
end_ifndef

begin_define
define|#
directive|define
name|STACK_CHECK_MAX_VAR_SIZE
value|(STACK_CHECK_MAX_FRAME_SIZE / 100)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Functions from optabs.c, commonly used, and without need for the optabs    tables:  */
end_comment

begin_comment
comment|/* Passed to expand_simple_binop and expand_binop to say which options    to try to use if the requested operation can't be open-coded on the    requisite mode.  Either OPTAB_LIB or OPTAB_LIB_WIDEN says try using    a library call.  Either OPTAB_WIDEN or OPTAB_LIB_WIDEN says try    using a wider mode.  OPTAB_MUST_WIDEN says try widening and don't    try anything else.  */
end_comment

begin_enum
enum|enum
name|optab_methods
block|{
name|OPTAB_DIRECT
block|,
name|OPTAB_LIB
block|,
name|OPTAB_WIDEN
block|,
name|OPTAB_LIB_WIDEN
block|,
name|OPTAB_MUST_WIDEN
block|}
enum|;
end_enum

begin_comment
comment|/* Generate code for a simple binary or unary operation.  "Simple" in    this case means "can be unambiguously described by a (mode, code)    pair and mapped to a single optab."  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|expand_simple_binop
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|enum
name|rtx_code
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|,
name|enum
name|optab_methods
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|expand_simple_unop
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|enum
name|rtx_code
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Report whether the machine description contains an insn which can    perform the operation described by CODE and MODE.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|have_insn_for
parameter_list|(
name|enum
name|rtx_code
parameter_list|,
name|enum
name|machine_mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Emit code to make a call to a constant function or a library call.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|emit_libcall_block
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create but don't emit one rtl instruction to perform certain operations.    Modes must match; operands must meet the operation's predicates.    Likewise for subtraction and for just copying.    These do not call protect_from_queue; caller must do so.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|gen_add2_insn
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_add3_insn
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_sub2_insn
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_sub3_insn
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_move_insn
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|have_add2_insn
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|have_sub2_insn
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Emit a pair of rtl insns to compare two rtx's and to jump    to a label if the comparison is true.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|emit_cmp_and_jump_insns
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|rtx_code
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|int
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Generate code to indirectly jump to a location given in the rtx LOC.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|emit_indirect_jump
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_conditional_move
end_ifdef

begin_comment
comment|/* Emit a conditional move operation.  */
end_comment

begin_function_decl
name|rtx
name|emit_conditional_move
parameter_list|(
name|rtx
parameter_list|,
name|enum
name|rtx_code
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return nonzero if the conditional move is supported.  */
end_comment

begin_function_decl
name|int
name|can_conditionally_move_p
parameter_list|(
name|enum
name|machine_mode
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|rtx
name|emit_conditional_add
parameter_list|(
name|rtx
parameter_list|,
name|enum
name|rtx_code
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Functions from expmed.c:  */
end_comment

begin_comment
comment|/* Arguments MODE, RTX: return an rtx for the negation of that value.    May emit insns.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|negate_rtx
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Expand a logical AND operation.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|expand_and
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Emit a store-flag operation.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|emit_store_flag
parameter_list|(
name|rtx
parameter_list|,
name|enum
name|rtx_code
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Like emit_store_flag, but always succeeds.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|emit_store_flag_force
parameter_list|(
name|rtx
parameter_list|,
name|enum
name|rtx_code
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions from loop.c:  */
end_comment

begin_comment
comment|/* Given an insn and condition, return a canonical description of    the test being made.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|canonicalize_condition
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|,
name|rtx
modifier|*
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given a JUMP_INSN, return a canonical description of the test    being made.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|get_condition
parameter_list|(
name|rtx
parameter_list|,
name|rtx
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Generate a conditional trap instruction.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|gen_cond_trap
parameter_list|(
name|enum
name|rtx_code
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Functions from builtins.c:  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|expand_builtin
parameter_list|(
name|tree
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|std_build_builtin_va_list
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|std_expand_builtin_va_start
parameter_list|(
name|tree
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|std_expand_builtin_va_arg
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|expand_builtin_va_arg
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|default_expand_builtin
parameter_list|(
name|tree
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_builtin_setjmp_setup
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_builtin_setjmp_receiver
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_builtin_longjmp
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|expand_builtin_saveregs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expand_builtin_trap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HOST_WIDE_INT
name|get_varargs_alias_set
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HOST_WIDE_INT
name|get_frame_alias_set
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|record_base_value
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|record_alias_subset
parameter_list|(
name|HOST_WIDE_INT
parameter_list|,
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HOST_WIDE_INT
name|new_alias_set
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|can_address_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Functions from expr.c:  */
end_comment

begin_comment
comment|/* This is run once per compilation to set up which modes can be used    directly in memory and to initialize the block move optab.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_expr_once
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This is run at the start of compiling a function.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_expr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This is run at the end of compiling a function.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|finish_expr_for_function
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Use protect_from_queue to convert a QUEUED expression    into something that you can put immediately into an instruction.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|protect_from_queue
parameter_list|(
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Perform all the pending incrementations.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|emit_queue
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Tell if something has a queued subexpression.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|queued_subexp_p
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Emit some rtl insns to move data between rtx's, converting machine modes.    Both modes must be floating or both fixed.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|convert_move
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert an rtx to specified machine mode and return the result.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|convert_to_mode
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert an rtx to MODE from OLDMODE and return the result.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|convert_modes
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Emit code to move a block Y to a block X.  */
end_comment

begin_enum
enum|enum
name|block_op_methods
block|{
name|BLOCK_OP_NORMAL
block|,
name|BLOCK_OP_NO_LIBCALL
block|,
name|BLOCK_OP_CALL_PARM
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|void
name|init_block_move_fn
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_block_clear_fn
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|emit_block_move
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|block_op_methods
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Copy all or part of a value X into registers starting at REGNO.    The number of registers to be filled is NREGS.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|move_block_to_reg
parameter_list|(
name|int
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|,
name|enum
name|machine_mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Copy all or part of a BLKmode value X out of registers starting at REGNO.    The number of registers to be filled is NREGS.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|move_block_from_reg
parameter_list|(
name|int
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Generate a non-consecutive group of registers represented by a PARALLEL.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|gen_group_rtx
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Load a BLKmode value into non-consecutive registers represented by a    PARALLEL.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|emit_group_load
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Move a non-consecutive group of registers represented by a PARALLEL into    a non-consecutive group of registers represented by a PARALLEL.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|emit_group_move
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Store a BLKmode value from non-consecutive registers represented by a    PARALLEL.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|emit_group_store
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Copy BLKmode object from a set of registers.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|copy_blkmode_from_reg
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Mark REG as holding a parameter for the next CALL_INSN.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|use_reg
parameter_list|(
name|rtx
modifier|*
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Mark NREGS consecutive regs, starting at REGNO, as holding parameters    for the next CALL_INSN.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|use_regs
parameter_list|(
name|rtx
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Mark a PARALLEL as holding a parameter for the next CALL_INSN.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|use_group_regs
parameter_list|(
name|rtx
modifier|*
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write zeros through the storage of OBJECT.    If OBJECT has BLKmode, SIZE is its length in bytes.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|clear_storage
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Determine whether the LEN bytes can be moved by using several move    instructions.  Return nonzero if a call to move_by_pieces should    succeed.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|can_move_by_pieces
parameter_list|(
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return nonzero if it is desirable to store LEN bytes generated by    CONSTFUN with several move instructions by store_by_pieces    function.  CONSTFUNDATA is a pointer which will be passed as argument    in every CONSTFUN call.    ALIGN is maximum alignment we can assume.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|can_store_by_pieces
parameter_list|(
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|rtx
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|HOST_WIDE_INT
parameter_list|,
name|enum
name|machine_mode
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Generate several move instructions to store LEN bytes generated by    CONSTFUN to block TO.  (A MEM rtx with BLKmode).  CONSTFUNDATA is a    pointer which will be passed as argument in every CONSTFUN call.    ALIGN is maximum alignment we can assume.    Returns TO + LEN.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|store_by_pieces
parameter_list|(
name|rtx
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|rtx
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|HOST_WIDE_INT
parameter_list|,
name|enum
name|machine_mode
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Emit insns to set X from Y.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|emit_move_insn
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Emit insns to set X from Y, with no frills.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|emit_move_insn_1
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Push a block of length SIZE (perhaps variable)    and return an rtx to address the beginning of the block.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|push_block
parameter_list|(
name|rtx
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Generate code to push something onto the stack, given its mode and type.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|emit_push_insn
parameter_list|(
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|tree
parameter_list|,
name|rtx
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Expand an assignment that stores the value of FROM into TO.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|expand_assignment
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Generate code for computing expression EXP,    and storing the value into TARGET.    If SUGGEST_REG is nonzero, copy the value through a register    and return that register, if that is possible.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|store_expr
parameter_list|(
name|tree
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given an rtx that may include add and multiply operations,    generate them as insns and return a pseudo-reg containing the value.    Useful after calling expand_expr with 1 as sum_ok.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|force_operand
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return an object on the placeholder list that matches EXP, a    PLACEHOLDER_EXPR.  An object "matches" if it is of the type of the    PLACEHOLDER_EXPR or a pointer type to it.  For further information, see    tree.def.  If no such object is found, abort.  If PLIST is nonzero, it is    a location which initially points to a starting location in the    placeholder list (zero means start of the list) and where a pointer into    the placeholder list at which the object is found is placed.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|find_placeholder
parameter_list|(
name|tree
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Generate code for computing expression EXP.    An rtx for the computed value is returned.  The value is never null.    In the case of a void EXP, const0_rtx is returned.  */
end_comment

begin_define
define|#
directive|define
name|expand_expr
parameter_list|(
name|EXP
parameter_list|,
name|TARGET
parameter_list|,
name|MODE
parameter_list|,
name|MODIFIER
parameter_list|)
define|\
value|expand_expr_real((EXP), (TARGET), (MODE), (MODIFIER), NULL)
end_define

begin_function_decl
specifier|extern
name|rtx
name|expand_expr_real
parameter_list|(
name|tree
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|enum
name|expand_modifier
parameter_list|,
name|rtx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* At the start of a function, record that we have no previously-pushed    arguments waiting to be popped.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_pending_stack_adjust
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* When exiting from function, if safe, clear out any pending stack adjust    so the adjustment won't get done.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|clear_pending_stack_adjust
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Pop any previously-pushed arguments that have not been popped yet.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|do_pending_stack_adjust
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the tree node and offset if a given argument corresponds to    a string constant.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|string_constant
parameter_list|(
name|tree
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Generate code to evaluate EXP and jump to LABEL if the value is zero.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|jumpifnot
parameter_list|(
name|tree
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Generate code to evaluate EXP and jump to LABEL if the value is nonzero.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|jumpif
parameter_list|(
name|tree
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Generate code to evaluate EXP and jump to IF_FALSE_LABEL if    the result is zero, or IF_TRUE_LABEL if the result is one.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|do_jump
parameter_list|(
name|tree
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Generate rtl to compare two rtx's, will call emit_cmp_insn.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|compare_from_rtx
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|rtx_code
parameter_list|,
name|int
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|do_compare_rtx_and_jump
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|rtx_code
parameter_list|,
name|int
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Two different ways of generating switch statements.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|try_casesi
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|try_tablejump
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Smallest number of adjacent cases before we use a jump table.    XXX Should be a target hook.  */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|int
name|case_values_threshold
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* rtl.h and tree.h were included.  */
end_comment

begin_comment
comment|/* Return an rtx for the size in bytes of the value of an expr.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|expr_size
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a wide integer for the size in bytes of the value of EXP, or -1    if the size can vary or is larger than an integer.  */
end_comment

begin_function_decl
specifier|extern
name|HOST_WIDE_INT
name|int_expr_size
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|lookup_static_chain
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert a stack slot address ADDR valid in function FNDECL    into an address valid in this function (using a static chain).  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|fix_lexical_addr
parameter_list|(
name|rtx
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the address of the trampoline for entering nested fn FUNCTION.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|trampoline_address
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return an rtx that refers to the value returned by a function    in its original home.  This becomes invalid if any more code is emitted.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|hard_function_value
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|prepare_call_address
parameter_list|(
name|rtx
parameter_list|,
name|tree
parameter_list|,
name|rtx
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|expand_call
parameter_list|(
name|tree
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|TREE_CODE
end_ifdef

begin_function_decl
specifier|extern
name|rtx
name|expand_shift
parameter_list|(
name|enum
name|tree_code
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|,
name|tree
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|expand_divmod
parameter_list|(
name|int
parameter_list|,
name|enum
name|tree_code
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|locate_and_pad_parm
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|tree
parameter_list|,
name|struct
name|args_size
modifier|*
parameter_list|,
name|struct
name|locate_and_pad_arg_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|expand_inline_function
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|,
name|tree
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the CODE_LABEL rtx for a LABEL_DECL, creating it if necessary.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|label_rtx
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* As label_rtx, but additionally the label is placed on the forced label    list of its containing function (i.e. it is treated as reachable even    if how is not obvious).  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|force_label_rtx
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Indicate how an input argument register was promoted.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|promoted_input_arg
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|enum
name|machine_mode
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return an rtx like arg but sans any constant terms.    Returns the original rtx if it has no constant terms.    The constant terms are added and stored via a second arg.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|eliminate_constant_term
parameter_list|(
name|rtx
parameter_list|,
name|rtx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert arg to a valid memory address for specified machine mode,    by emitting insns to perform arithmetic if nec.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|memory_address
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Like `memory_address' but pretent `flag_force_addr' is 0.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|memory_address_noforce
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the alias set of MEM to SET.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_mem_alias_set
parameter_list|(
name|rtx
parameter_list|,
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the alignment of MEM to ALIGN bits.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_mem_align
parameter_list|(
name|rtx
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the expr for MEM to EXPR.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_mem_expr
parameter_list|(
name|rtx
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the offset for MEM to OFFSET.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_mem_offset
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the size for MEM to SIZE.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_mem_size
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a memory reference like MEMREF, but with its mode changed    to MODE and its address changed to ADDR.    (VOIDmode means don't change the mode.    NULL for ADDR means don't change the address.)  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|change_address
parameter_list|(
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a memory reference like MEMREF, but with its mode changed    to MODE and its address offset by OFFSET bytes.  */
end_comment

begin_define
define|#
directive|define
name|adjust_address
parameter_list|(
name|MEMREF
parameter_list|,
name|MODE
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|adjust_address_1 (MEMREF, MODE, OFFSET, 1, 1)
end_define

begin_comment
comment|/* Likewise, but the reference is not required to be valid.  */
end_comment

begin_define
define|#
directive|define
name|adjust_address_nv
parameter_list|(
name|MEMREF
parameter_list|,
name|MODE
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|adjust_address_1 (MEMREF, MODE, OFFSET, 0, 1)
end_define

begin_comment
comment|/* Return a memory reference like MEMREF, but with its mode changed    to MODE and its address changed to ADDR, which is assumed to be    increased by OFFSET bytes from MEMREF.  */
end_comment

begin_define
define|#
directive|define
name|adjust_automodify_address
parameter_list|(
name|MEMREF
parameter_list|,
name|MODE
parameter_list|,
name|ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|adjust_automodify_address_1 (MEMREF, MODE, ADDR, OFFSET, 1)
end_define

begin_comment
comment|/* Likewise, but the reference is not required to be valid.  */
end_comment

begin_define
define|#
directive|define
name|adjust_automodify_address_nv
parameter_list|(
name|MEMREF
parameter_list|,
name|MODE
parameter_list|,
name|ADDR
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|adjust_automodify_address_1 (MEMREF, MODE, ADDR, OFFSET, 0)
end_define

begin_function_decl
specifier|extern
name|rtx
name|adjust_address_1
parameter_list|(
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|HOST_WIDE_INT
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|adjust_automodify_address_1
parameter_list|(
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|,
name|HOST_WIDE_INT
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a memory reference like MEMREF, but whose address is changed by    adding OFFSET, an RTX, to it.  POW2 is the highest power of two factor    known to be in OFFSET (possibly 1).  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|offset_address
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a memory reference like MEMREF, but with its address changed to    ADDR.  The caller is asserting that the actual piece of memory pointed    to is the same, just the form of the address is being changed, such as    by putting something into a register.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|replace_equiv_address
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Likewise, but the reference is not required to be valid.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|replace_equiv_address_nv
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a memory reference like MEMREF, but with its mode widened to    MODE and adjusted by OFFSET.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|widen_memory_access
parameter_list|(
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a memory reference like MEMREF, but which is known to have a    valid address.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|validize_mem
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given REF, either a MEM or a REG, and T, either the type of X or    the expression corresponding to REF, set RTX_UNCHANGING_P if    appropriate.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|maybe_set_unchanging
parameter_list|(
name|rtx
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given REF, a MEM, and T, either the type of X or the expression    corresponding to REF, set the memory attributes.  OBJECTP is nonzero    if we are making a new object of this type.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_mem_attributes
parameter_list|(
name|rtx
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Similar, except that BITPOS has not yet been applied to REF, so if    we alter MEM_OFFSET according to T then we should subtract BITPOS    expecting that it'll be added back in later.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_mem_attributes_minus_bitpos
parameter_list|(
name|rtx
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|,
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Assemble the static constant template for function entry trampolines.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|assemble_trampoline_template
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given rtx, return new rtx whose address won't be affected by    any side effects.  It has been copied to a new temporary reg.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|stabilize
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given an rtx, copy all regs it refers to into new temps    and return a modified copy that refers to the new temps.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|copy_all_regs
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Copy given rtx to a new temp reg and return that.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|copy_to_reg
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Like copy_to_reg but always make the reg Pmode.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|copy_addr_to_reg
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Like copy_to_reg but always make the reg the specified mode MODE.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|copy_to_mode_reg
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Copy given rtx to given temp reg and return that.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|copy_to_suggested_reg
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Copy a value to a register if it isn't already a register.    Args are mode (in case value is a constant) and the value.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|force_reg
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return given rtx, copied into a new temp reg if it was in memory.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|force_not_mem
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return mode and signedness to use when object is promoted.  */
end_comment

begin_function_decl
specifier|extern
name|enum
name|machine_mode
name|promote_mode
parameter_list|(
name|tree
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Remove some bytes from the stack.  An rtx says how many.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|adjust_stack
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Add some bytes to the stack.  An rtx says how many.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|anti_adjust_stack
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This enum is used for the following two functions.  */
end_comment

begin_enum
enum|enum
name|save_level
block|{
name|SAVE_BLOCK
block|,
name|SAVE_FUNCTION
block|,
name|SAVE_NONLOCAL
block|}
enum|;
end_enum

begin_comment
comment|/* Save the stack pointer at the specified level.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|emit_stack_save
parameter_list|(
name|enum
name|save_level
parameter_list|,
name|rtx
modifier|*
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Restore the stack pointer from a save area of the specified level.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|emit_stack_restore
parameter_list|(
name|enum
name|save_level
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Allocate some space on the stack dynamically and return its address.  An rtx    says how many bytes.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|allocate_dynamic_stack_space
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Probe a range of stack addresses from FIRST to FIRST+SIZE, inclusive.    FIRST is a constant and size is a Pmode RTX.  These are offsets from the    current stack pointer.  STACK_GROWS_DOWNWARD says whether to add or    subtract from the stack.  If SIZE is constant, this is done    with a fixed number of probes.  Otherwise, we must make a loop.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|probe_stack_range
parameter_list|(
name|HOST_WIDE_INT
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return an rtx that refers to the value returned by a library call    in its original home.  This becomes invalid if any more code is emitted.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|hard_libcall_value
parameter_list|(
name|enum
name|machine_mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given an rtx, return an rtx for a value rounded up to a multiple    of STACK_BOUNDARY / BITS_PER_UNIT.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|round_push
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the mode desired by operand N of a particular bitfield    insert/extract insn, or MAX_MACHINE_MODE if no such insn is    available.  */
end_comment

begin_enum
enum|enum
name|extraction_pattern
block|{
name|EP_insv
block|,
name|EP_extv
block|,
name|EP_extzv
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|enum
name|machine_mode
name|mode_for_extraction
parameter_list|(
name|enum
name|extraction_pattern
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|store_bit_field
parameter_list|(
name|rtx
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|,
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|extract_bit_field
parameter_list|(
name|rtx
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|int
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|expand_mult
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|const_mult_add_overflow_p
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|expand_mult_add
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|expand_mult_highpart_adjust
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|assemble_static_space
parameter_list|(
name|unsigned
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|safe_from_p
parameter_list|(
name|rtx
parameter_list|,
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Call this once to initialize the contents of the optabs    appropriately for the current target machine.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_optabs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_all_optabs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Call this to initialize an optab function entry.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|init_one_libfunc
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|do_jump_by_parts_equality_rtx
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|do_jump_by_parts_greater_rtx
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|int
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mark_seen_cases
parameter_list|(
name|tree
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|HOST_WIDE_INT
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vector_mode_valid_p
parameter_list|(
name|enum
name|machine_mode
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tree
name|placeholder_list
decl_stmt|;
end_decl_stmt

end_unit

