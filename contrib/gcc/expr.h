begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for code generation pass of GNU compiler.    Copyright (C) 1987, 91-98, 1999 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
comment|/* This is the 4th arg to `expand_expr'.    EXPAND_SUM means it is ok to return a PLUS rtx or MULT rtx.    EXPAND_INITIALIZER is similar but also record any labels on forced_labels.    EXPAND_CONST_ADDRESS means it is ok to return a MEM whose address     is a constant that is not a legitimate address.    EXPAND_MEMORY_USE_* are explained below.  */
end_comment

begin_enum
enum|enum
name|expand_modifier
block|{
name|EXPAND_NORMAL
block|,
name|EXPAND_SUM
block|,
name|EXPAND_CONST_ADDRESS
block|,
name|EXPAND_INITIALIZER
block|,
name|EXPAND_MEMORY_USE_WO
block|,
name|EXPAND_MEMORY_USE_RW
block|,
name|EXPAND_MEMORY_USE_BAD
block|,
name|EXPAND_MEMORY_USE_DONT
block|}
enum|;
end_enum

begin_comment
comment|/* Argument for chkr_* functions.    MEMORY_USE_RO: the pointer reads memory.    MEMORY_USE_WO: the pointer writes to memory.    MEMORY_USE_RW: the pointer modifies memory (ie it reads and writes). An                   example is (*ptr)++    MEMORY_USE_BAD: use this if you don't know the behavior of the pointer, or                    if you know there are no pointers.  Using an INDIRECT_REF                    with MEMORY_USE_BAD will abort.    MEMORY_USE_TW: just test for writing, without update.  Special.    MEMORY_USE_DONT: the memory is neither read nor written.  This is used by    		   '->' and '.'.  */
end_comment

begin_enum
enum|enum
name|memory_use_mode
block|{
name|MEMORY_USE_BAD
init|=
literal|0
block|,
name|MEMORY_USE_RO
init|=
literal|1
block|,
name|MEMORY_USE_WO
init|=
literal|2
block|,
name|MEMORY_USE_RW
init|=
literal|3
block|,
name|MEMORY_USE_TW
init|=
literal|6
block|,
name|MEMORY_USE_DONT
init|=
literal|99
block|}
enum|;
end_enum

begin_comment
comment|/* List of labels that must never be deleted.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|forced_labels
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List (chain of EXPR_LISTs) of pseudo-regs of SAVE_EXPRs.    So we can mark them all live at the end of the function, if stupid.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|save_expr_regs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_function_calls_alloca
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_function_outgoing_args_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is the offset from the arg pointer to the place where the first    anonymous arg can be found, if there is one.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|current_function_arg_offset_rtx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is nonzero if the current function uses the constant pool.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_uses_const_pool
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is nonzero if the current function uses pic_offset_table_rtx.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_uses_pic_offset_table
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The arg pointer hard register, or the pseudo into which it was copied.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|current_function_internal_arg_pointer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is nonzero if memory access checking be enabled in the current    function.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_check_memory_usage
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Under some ABIs, it is the caller's responsibility to pop arguments    pushed for function calls.  A naive implementation would simply pop    the arguments immediately after each call.  However, if several    function calls are made in a row, it is typically cheaper to pop    all the arguments after all of the calls are complete since a    single pop instruction can be used.  Therefore, GCC attempts to    defer popping the arguments until absolutely necessary.  (For    example, at the end of a conditional, the arguments must be popped,    since code outside the conditional won't know whether or not the    arguments need to be popped.)     When INHIBIT_DEFER_POP is non-zero, however, the compiler does not    attempt to defer pops.  Instead, the stack is popped immediately    after each call.  Rather then setting this variable directly, use    NO_DEFER_POP and OK_DEFER_POP.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inhibit_defer_pop
decl_stmt|;
end_decl_stmt

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

begin_comment
comment|/* Number of function calls seen so far in current function.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|function_call_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List (chain of EXPR_LIST) of stack slots that hold the current handlers    for nonlocal gotos.  There is one for every nonlocal label in the function;    this list matches the one in nonlocal_labels.    Zero when function does not have nonlocal labels.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|nonlocal_goto_handler_slots
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* RTX for stack slot that holds the stack pointer value to restore    for a nonlocal goto.    Zero when function does not have nonlocal labels.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|nonlocal_goto_stack_level
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List (chain of TREE_LIST) of LABEL_DECLs for all nonlocal labels    (labels to which there can be nonlocal gotos from nested functions)    in this function.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TREE_CODE
end_ifdef

begin_comment
comment|/* Don't lose if tree.h not included.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|nonlocal_labels
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of units that we should eventually pop off the stack.    These are the arguments to function calls that have already returned.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pending_stack_adjust
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* When temporaries are created by TARGET_EXPRs, they are created at    this level of temp_slot_level, so that they can remain allocated    until no longer needed.  CLEANUP_POINT_EXPRs define the lifetime    of TARGET_EXPRs.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|target_temp_slot_level
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current level for normal temporaries.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|temp_slot_level
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|TREE_CODE
end_ifdef

begin_comment
comment|/* Don't lose if tree.h not included.  */
end_comment

begin_comment
comment|/* Structure to record the size of a sequence of arguments    as the sum of a tree-expression and a constant.  */
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

begin_endif
endif|#
directive|endif
end_endif

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
value|{ tree inc = (INC);				\   if (TREE_CODE (inc) == INTEGER_CST)		\     (TO).constant += TREE_INT_CST_LOW (inc);	\   else if ((TO).var == 0)			\     (TO).var = inc;				\   else						\     (TO).var = size_binop (PLUS_EXPR, (TO).var, inc); }
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
value|{ tree dec = (DEC);				\   if (TREE_CODE (dec) == INTEGER_CST)		\     (TO).constant -= TREE_INT_CST_LOW (dec);	\   else if ((TO).var == 0)			\     (TO).var = size_binop (MINUS_EXPR, integer_zero_node, dec); \   else						\     (TO).var = size_binop (MINUS_EXPR, (TO).var, dec); }
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
value|((SIZE).var == 0 ? GEN_INT ((SIZE).constant)	\  : expand_expr (size_binop (PLUS_EXPR, (SIZE).var,			\ 			    size_int ((SIZE).constant)),		\ 		NULL_RTX, VOIDmode, EXPAND_MEMORY_USE_BAD))
end_define

begin_comment
comment|/* Convert the implicit sum in a `struct args_size' into a tree.  */
end_comment

begin_define
define|#
directive|define
name|ARGS_SIZE_TREE
parameter_list|(
name|SIZE
parameter_list|)
define|\
value|((SIZE).var == 0 ? size_int ((SIZE).constant)				\  : size_binop (PLUS_EXPR, (SIZE).var, size_int ((SIZE).constant)))
end_define

begin_comment
comment|/* Supply a default definition for FUNCTION_ARG_PADDING:    usually pad upward, but pad short args downward on    big-endian machines.  */
end_comment

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
comment|/* Value has this type.  */
end_comment

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
value|(! BYTES_BIG_ENDIAN							\    ? upward								\    : (((MODE) == BLKmode						\        ? ((TYPE)&& TREE_CODE (TYPE_SIZE (TYPE)) == INTEGER_CST		\&& int_size_in_bytes (TYPE)< (PARM_BOUNDARY / BITS_PER_UNIT)) \        : GET_MODE_BITSIZE (MODE)< PARM_BOUNDARY)			\       ? downward : upward))
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

begin_comment
comment|/* Provide a default value for STRICT_ARGUMENT_NAMING.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STRICT_ARGUMENT_NAMING
end_ifndef

begin_define
define|#
directive|define
name|STRICT_ARGUMENT_NAMING
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Provide a default value for PRETEND_OUTGOING_VARARGS_NAMED.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SETUP_INCOMING_VARARGS
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|PRETEND_OUTGOING_VARARGS_NAMED
end_ifndef

begin_define
define|#
directive|define
name|PRETEND_OUTGOING_VARARGS_NAMED
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* It is an error to define PRETEND_OUTGOING_VARARGS_NAMED without    defining SETUP_INCOMING_VARARGS.  */
end_comment

begin_define
define|#
directive|define
name|PRETEND_OUTGOING_VARARGS_NAMED
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Nonzero if we do not know how to pass TYPE solely in registers.    We cannot do so in the following cases:     - if the type has variable size    - if the type is marked as addressable (it is required to be constructed      into the stack)    - if the padding and mode of the type is such that a copy into a register      would put it into the wrong part of the register.     Which padding can't be supported depends on the byte endianness.     A value in a register is implicitly padded at the most significant end.    On a big-endian machine, that is the lower end in memory.    So a value padded in memory at the upper end can't go in a register.    For a little-endian machine, the reverse is true.  */
end_comment

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
define|\
value|((TYPE) != 0						\&& (TREE_CODE (TYPE_SIZE (TYPE)) != INTEGER_CST	\        || TREE_ADDRESSABLE (TYPE)			\        || ((MODE) == BLKmode 				\&& ! ((TYPE) != 0&& TREE_CODE (TYPE_SIZE (TYPE)) == INTEGER_CST \&& 0 == (int_size_in_bytes (TYPE)	\ 			  % (PARM_BOUNDARY / BITS_PER_UNIT))) \&& (FUNCTION_ARG_PADDING (MODE, TYPE)	\ 	       == (BYTES_BIG_ENDIAN ? upward : downward)))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Nonzero if type TYPE should be returned in memory.    Most machines can use the following default definition.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RETURN_IN_MEMORY
end_ifndef

begin_define
define|#
directive|define
name|RETURN_IN_MEMORY
parameter_list|(
name|TYPE
parameter_list|)
value|(TYPE_MODE (TYPE) == BLKmode)
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
comment|/* Optabs are tables saying how to generate insn bodies    for various machine modes and numbers of operands.    Each optab applies to one operation.    For example, add_optab applies to addition.     The insn_code slot is the enum insn_code that says how to    generate an insn for this operation on a particular machine mode.    It is CODE_FOR_nothing if there is no such insn on the target machine.     The `lib_call' slot is the name of the library function that    can be used to perform the operation.     A few optabs, such as move_optab and cmp_optab, are used    by special code.  */
end_comment

begin_comment
comment|/* Everything that uses expr.h needs to define enum insn_code    but we don't list it in the Makefile dependencies just for that.  */
end_comment

begin_include
include|#
directive|include
file|"insn-codes.h"
end_include

begin_typedef
typedef|typedef
struct|struct
name|optab
block|{
name|enum
name|rtx_code
name|code
decl_stmt|;
struct|struct
block|{
name|enum
name|insn_code
name|insn_code
decl_stmt|;
name|rtx
name|libfunc
decl_stmt|;
block|}
name|handlers
index|[
name|NUM_MACHINE_MODES
index|]
struct|;
block|}
typedef|*
name|optab
typedef|;
end_typedef

begin_comment
comment|/* Given an enum insn_code, access the function to construct    the body of that kind of insn.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FUNCTION_CONVERSION_BUG
end_ifdef

begin_comment
comment|/* Some compilers fail to convert a function properly to a    pointer-to-function when used as an argument.    So produce the pointer-to-function directly.    Luckily, these compilers seem to work properly when you    call the pointer-to-function.  */
end_comment

begin_define
define|#
directive|define
name|GEN_FCN
parameter_list|(
name|CODE
parameter_list|)
value|(insn_gen_function[(int) (CODE)])
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GEN_FCN
parameter_list|(
name|CODE
parameter_list|)
value|(*insn_gen_function[(int) (CODE)])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_extern
extern|extern rtx (*const insn_gen_function[]
end_extern

begin_expr_stmt
unit|)
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
operator|...
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|optab
name|add_optab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|optab
name|sub_optab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|optab
name|smul_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Signed and floating-point multiply */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|smul_highpart_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Signed multiply, return high word */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|umul_highpart_optab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|optab
name|smul_widen_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Signed multiply with result  				   one machine mode wider than args */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|umul_widen_optab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|optab
name|sdiv_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Signed divide */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|sdivmod_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Signed divide-and-remainder in one */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|udiv_optab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|optab
name|udivmod_optab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|optab
name|smod_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Signed remainder */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|umod_optab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|optab
name|flodiv_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Optab for floating divide. */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|ftrunc_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Convert float to integer in float fmt */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|and_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Logical and */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|ior_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Logical or */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|xor_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Logical xor */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|ashl_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Arithmetic shift left */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|ashr_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Arithmetic shift right */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|lshr_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Logical shift right */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|rotl_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Rotate left */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|rotr_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Rotate right */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|smin_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Signed and floating-point minimum value */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|smax_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Signed and floating-point maximum value */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|umin_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Unsigned minimum value */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|umax_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Unsigned maximum value */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|mov_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Move instruction.  */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|movstrict_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Move, preserving high part of register.  */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|cmp_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Compare insn; two operands.  */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|tst_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tst insn; compare one operand against 0 */
end_comment

begin_comment
comment|/* Unary operations */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|neg_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Negation */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|abs_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Abs value */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|one_cmpl_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Bitwise not */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|ffs_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Find first bit set */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|sqrt_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Square root */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|sin_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Sine */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|cos_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Cosine */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|strlen_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* String length */
end_comment

begin_comment
comment|/* Tables of patterns for extending one integer mode to another.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|insn_code
name|extendtab
index|[
name|MAX_MACHINE_MODE
index|]
index|[
name|MAX_MACHINE_MODE
index|]
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tables of patterns for converting between fixed and floating point. */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|insn_code
name|fixtab
index|[
name|NUM_MACHINE_MODES
index|]
index|[
name|NUM_MACHINE_MODES
index|]
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|insn_code
name|fixtrunctab
index|[
name|NUM_MACHINE_MODES
index|]
index|[
name|NUM_MACHINE_MODES
index|]
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|insn_code
name|floattab
index|[
name|NUM_MACHINE_MODES
index|]
index|[
name|NUM_MACHINE_MODES
index|]
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Contains the optab used for each rtx code.  */
end_comment

begin_decl_stmt
specifier|extern
name|optab
name|code_to_optab
index|[
name|NUM_RTX_CODE
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Passed to expand_binop and expand_unop to say which options to try to use    if the requested operation can't be open-coded on the requisite mode.    Either OPTAB_LIB or OPTAB_LIB_WIDEN says try using a library call.    Either OPTAB_WIDEN or OPTAB_LIB_WIDEN says try using a wider mode.    OPTAB_MUST_WIDEN says try widening and don't try anything else.  */
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
comment|/* SYMBOL_REF rtx's for the library functions that are called    implicitly and not via optabs.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|extendsfdf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|extendsfxf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|extendsftf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|extenddfxf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|extenddftf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|truncdfsf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|truncxfsf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|trunctfsf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|truncxfdf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|trunctfdf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|memcpy_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|bcopy_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|memcmp_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|bcmp_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|memset_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|bzero_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|throw_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|rethrow_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|sjthrow_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|sjpopnthrow_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|terminate_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|setjmp_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|longjmp_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|eh_rtime_match_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|eqhf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|nehf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gthf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gehf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|lthf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|lehf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|eqsf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|nesf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gtsf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gesf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|ltsf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|lesf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|eqdf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|nedf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gtdf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gedf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|ltdf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|ledf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|eqxf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|nexf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gtxf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gexf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|ltxf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|lexf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|eqtf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|netf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|gttf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|getf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|lttf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|letf2_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|floatsisf_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|floatdisf_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|floattisf_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|floatsidf_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|floatdidf_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|floattidf_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|floatsixf_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|floatdixf_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|floattixf_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|floatsitf_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|floatditf_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|floattitf_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|fixsfsi_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|fixsfdi_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|fixsfti_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|fixdfsi_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|fixdfdi_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|fixdfti_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|fixxfsi_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|fixxfdi_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|fixxfti_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|fixtfsi_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|fixtfdi_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|fixtfti_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|fixunssfsi_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|fixunssfdi_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|fixunssfti_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|fixunsdfsi_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|fixunsdfdi_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|fixunsdfti_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|fixunsxfsi_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|fixunsxfdi_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|fixunsxfti_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|fixunstfsi_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|fixunstfdi_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|fixunstfti_libfunc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For check-memory-usage.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|chkr_check_addr_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|chkr_set_right_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|chkr_copy_bitmap_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|chkr_check_exec_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|chkr_check_str_libfunc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For instrument-functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|profile_function_entry_libfunc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|profile_function_exit_libfunc
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_typedef
typedef|typedef
name|rtx
argument_list|(
argument|*rtxfun
argument_list|)
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_comment
comment|/* Indexed by the rtx-code for a conditional (eg. EQ, LT,...)    gives the gen_function to make a branch to test that condition.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtxfun
name|bcc_gen_fctn
index|[
name|NUM_RTX_CODE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Indexed by the rtx-code for a conditional (eg. EQ, LT,...)    gives the insn code to make a store-condition insn    to test that condition.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|insn_code
name|setcc_gen_code
index|[
name|NUM_RTX_CODE
index|]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_conditional_move
end_ifdef

begin_comment
comment|/* Indexed by the machine mode, gives the insn code to make a conditional    move insn.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|insn_code
name|movcc_gen_code
index|[
name|NUM_MACHINE_MODES
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This array records the insn_code of insns to perform block moves.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|insn_code
name|movstr_optab
index|[
name|NUM_MACHINE_MODES
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This array records the insn_code of insns to perform block clears.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|insn_code
name|clrstr_optab
index|[
name|NUM_MACHINE_MODES
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define functions given in optabs.c.  */
end_comment

begin_comment
comment|/* Expand a binary operation given optab and rtx operands.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|expand_binop
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|optab
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|int
operator|,
expr|enum
name|optab_methods
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Expand a binary operation with both signed and unsigned forms.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|sign_expand_binop
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|optab
operator|,
name|optab
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|int
operator|,
expr|enum
name|optab_methods
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate code to perform an operation on two operands with two results.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|expand_twoval_binop
name|PROTO
argument_list|(
operator|(
name|optab
operator|,
name|rtx
operator|,
name|rtx
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

begin_comment
comment|/* Expand a unary arithmetic operation given optab rtx operand.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|expand_unop
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|optab
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

begin_comment
comment|/* Expand the absolute value operation.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|expand_abs
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

begin_comment
comment|/* Expand the complex absolute value operation.  */
end_comment

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

begin_comment
comment|/* Generate an instruction with a given INSN_CODE with an output and    an input.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|emit_unop_insn
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|rtx
operator|,
name|rtx
operator|,
expr|enum
name|rtx_code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Emit code to perform a series of operations on a multi-word quantity, one    word at a time.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|emit_no_conflict_block
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
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Emit code to make a call to a constant function or a library call. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|emit_libcall_block
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
comment|/* Emit one rtl instruction to store zero in specified rtx.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|emit_clr_insn
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Emit one rtl insn to store 1 in specified rtx assuming it contains 0.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|emit_0_to_1_insn
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Emit one rtl insn to compare two rtx's.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|emit_cmp_insn
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
expr|enum
name|rtx_code
operator|,
name|rtx
operator|,
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

begin_comment
comment|/* Emit a pair of rtl insns to compare two rtx's and to jump     to a label if the comparison is true.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|emit_cmp_and_jump_insns
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
expr|enum
name|rtx_code
operator|,
name|rtx
operator|,
expr|enum
name|machine_mode
operator|,
name|int
operator|,
name|int
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if a compare of mode MODE can be done straightforwardly    (without splitting it into pieces).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|can_compare_p
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Emit a library call comparison between floating point X and Y.    COMPARISON is the rtl operator to compare with (EQ, NE, GT, etc.).  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|emit_float_lib_cmp
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
expr|enum
name|rtx_code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate code to indirectly jump to a location given in the rtx LOC.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|emit_indirect_jump
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_conditional_move
end_ifdef

begin_comment
comment|/* Emit a conditional move operation.  */
end_comment

begin_decl_stmt
name|rtx
name|emit_conditional_move
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|rtx_code
operator|,
name|rtx
operator|,
name|rtx
operator|,
expr|enum
name|machine_mode
operator|,
name|rtx
operator|,
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

begin_comment
comment|/* Return non-zero if the conditional move is supported.  */
end_comment

begin_decl_stmt
name|int
name|can_conditionally_move_p
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
name|mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Create but don't emit one rtl instruction to add one rtx into another.    Modes must match; operands must meet the operation's predicates.    Likewise for subtraction and for just copying.    These do not call protect_from_queue; caller must do so.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|gen_add2_insn
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
name|gen_sub2_insn
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
name|int
name|have_add2_insn
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
name|int
name|have_sub2_insn
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the INSN_CODE to use for an extend operation.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|insn_code
name|can_extend_p
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
expr|enum
name|machine_mode
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate the body of an insn to extend Y (with mode MFROM)    into X (with mode MTO).  Do zero-extension if UNSIGNEDP is nonzero.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|gen_extend_insn
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
expr|enum
name|machine_mode
operator|,
expr|enum
name|machine_mode
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialize the tables that control conversion between fixed and    floating values.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_fixtab
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
name|init_floattab
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate code for a FLOAT_EXPR.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|expand_float
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

begin_comment
comment|/* Generate code for a FIX_EXPR.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|expand_fix
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

begin_comment
comment|/* Call this once to initialize the contents of the optabs    appropriately for the current target machine.  */
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

begin_escape
end_escape

begin_comment
comment|/* Functions from expmed.c:  */
end_comment

begin_comment
comment|/* Arguments MODE, RTX: return an rtx for the negation of that value.    May emit insns.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|negate_rtx
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
comment|/* Expand a logical AND operation.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|expand_and
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

begin_comment
comment|/* Emit a store-flag operation.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|emit_store_flag
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|rtx_code
operator|,
name|rtx
operator|,
name|rtx
operator|,
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

begin_comment
comment|/* Like emit_store_flag, but always succeeds.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|emit_store_flag_force
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|rtx_code
operator|,
name|rtx
operator|,
name|rtx
operator|,
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

begin_comment
comment|/* Functions from loop.c:  */
end_comment

begin_comment
comment|/* Given a JUMP_INSN, return a description of the test being made.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|get_condition
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

begin_comment
comment|/* Generate a conditional trap instruction.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|gen_cond_trap
name|PROTO
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

begin_escape
end_escape

begin_comment
comment|/* Functions from expr.c:  */
end_comment

begin_comment
comment|/* This is run once per compilation to set up which modes can be used    directly in memory and to initialize the block move optab.  */
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

begin_comment
comment|/* This is run at the start of compiling a function.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_expr
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use protect_from_queue to convert a QUEUED expression    into something that you can put immediately into an instruction.  */
end_comment

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

begin_comment
comment|/* Perform all the pending incrementations.  */
end_comment

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

begin_comment
comment|/* Tell if something has a queued subexpression.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|queued_subexp_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Emit some rtl insns to move data between rtx's, converting machine modes.    Both modes must be floating or both fixed.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|convert_move
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

begin_comment
comment|/* Convert an rtx to specified machine mode and return the result.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|convert_to_mode
name|PROTO
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

begin_comment
comment|/* Convert an rtx to MODE from OLDMODE and return the result.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|convert_modes
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
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

begin_comment
comment|/* Emit code to move a block Y to a block X.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|emit_block_move
name|PROTO
argument_list|(
operator|(
name|rtx
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

begin_comment
comment|/* Copy all or part of a value X into registers starting at REGNO.    The number of registers to be filled is NREGS.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|move_block_to_reg
name|PROTO
argument_list|(
operator|(
name|int
operator|,
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
comment|/* Copy all or part of a BLKmode value X out of registers starting at REGNO.    The number of registers to be filled is NREGS.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|move_block_from_reg
name|PROTO
argument_list|(
operator|(
name|int
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
comment|/* Load a BLKmode value into non-consecutive registers represented by a    PARALLEL.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|emit_group_load
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
comment|/* Store a BLKmode value from non-consecutive registers represented by a    PARALLEL.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|emit_group_store
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

begin_ifdef
ifdef|#
directive|ifdef
name|TREE_CODE
end_ifdef

begin_comment
comment|/* Copy BLKmode object from a set of registers. */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|copy_blkmode_from_reg
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Mark REG as holding a parameter for the next CALL_INSN.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|use_reg
name|PROTO
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

begin_comment
comment|/* Mark NREGS consecutive regs, starting at REGNO, as holding parameters    for the next CALL_INSN.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|use_regs
name|PROTO
argument_list|(
operator|(
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

begin_comment
comment|/* Mark a PARALLEL as holding a parameter for the next CALL_INSN.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|use_group_regs
name|PROTO
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

begin_comment
comment|/* Write zeros through the storage of OBJECT.    If OBJECT has BLKmode, SIZE is its length in bytes and ALIGN is its    alignment.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|clear_storage
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

begin_comment
comment|/* Emit insns to set X from Y.  */
end_comment

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

begin_comment
comment|/* Emit insns to set X from Y, with no frills.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|emit_move_insn_1
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
comment|/* Push a block of length SIZE (perhaps variable)    and return an rtx to address the beginning of the block.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|push_block
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

begin_comment
comment|/* Make an operand to push something on the stack.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|gen_push_operand
name|PROTO
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
name|TREE_CODE
end_ifdef

begin_comment
comment|/* Generate code to push something onto the stack, given its mode and type.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|emit_push_insn
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|machine_mode
operator|,
name|tree
operator|,
name|rtx
operator|,
name|int
operator|,
name|int
operator|,
name|rtx
operator|,
name|int
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
name|orgfun
operator|,
name|int
name|no_queue
operator|,
expr|enum
name|machine_mode
name|outmode
operator|,
name|int
name|nargs
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
name|orgfun
operator|,
name|rtx
name|value
operator|,
name|int
name|no_queue
operator|,
expr|enum
name|machine_mode
name|outmode
operator|,
name|int
name|nargs
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Expand an assignment that stores the value of FROM into TO. */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|expand_assignment
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate code for computing expression EXP,    and storing the value into TARGET.    If SUGGEST_REG is nonzero, copy the value through a register    and return that register, if that is possible.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|store_expr
name|PROTO
argument_list|(
operator|(
name|tree
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
comment|/* Given an rtx that may include add and multiply operations,    generate them as insns and return a pseudo-reg containing the value.    Useful after calling expand_expr with 1 as sum_ok.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|force_operand
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
name|expand_builtin_setjmp_setup
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
name|expand_builtin_setjmp_receiver
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|TREE_CODE
end_ifdef

begin_comment
comment|/* Generate code for computing expression EXP.    An rtx for the computed value is returned.  The value is never null.    In the case of a void EXP, const0_rtx is returned.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|expand_expr
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|rtx
operator|,
expr|enum
name|machine_mode
operator|,
expr|enum
name|expand_modifier
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* At the start of a function, record that we have no previously-pushed    arguments waiting to be popped.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_pending_stack_adjust
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* When exiting from function, if safe, clear out any pending stack adjust    so the adjustment won't get done.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|clear_pending_stack_adjust
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pop any previously-pushed arguments that have not been popped yet.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|do_pending_stack_adjust
name|PROTO
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
name|TREE_CODE
end_ifdef

begin_comment
comment|/* Generate code to evaluate EXP and jump to LABEL if the value is zero.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|jumpifnot
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate code to evaluate EXP and jump to LABEL if the value is nonzero.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|jumpif
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate code to evaluate EXP and jump to IF_FALSE_LABEL if    the result is zero, or IF_TRUE_LABEL if the result is one.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|do_jump
name|PROTO
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Generate rtl to compare two rtx's, will call emit_cmp_insn.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|compare_from_rtx
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
expr|enum
name|rtx_code
operator|,
name|int
operator|,
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

begin_comment
comment|/* Generate a tablejump instruction (used for switch statements).  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|do_tablejump
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
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|TREE_CODE
end_ifdef

begin_comment
comment|/* rtl.h and tree.h were included.  */
end_comment

begin_comment
comment|/* Return an rtx for the size in bytes of the value of an expr.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|expr_size
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|lookup_static_chain
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Convert a stack slot address ADDR valid in function FNDECL    into an address valid in this function (using a static chain).  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|fix_lexical_addr
name|PROTO
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
comment|/* Return the address of the trampoline for entering nested fn FUNCTION.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|trampoline_address
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return an rtx that refers to the value returned by a function    in its original home.  This becomes invalid if any more code is emitted.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|hard_function_value
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|prepare_call_address
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|tree
operator|,
name|rtx
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
name|expand_call
name|PROTO
argument_list|(
operator|(
name|tree
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
name|expand_shift
name|PROTO
argument_list|(
operator|(
expr|enum
name|tree_code
operator|,
expr|enum
name|machine_mode
operator|,
name|rtx
operator|,
name|tree
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
name|expand_divmod
name|PROTO
argument_list|(
operator|(
name|int
operator|,
expr|enum
name|tree_code
operator|,
expr|enum
name|machine_mode
operator|,
name|rtx
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
name|void
name|locate_and_pad_parm
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|tree
operator|,
name|int
operator|,
name|tree
operator|,
expr|struct
name|args_size
operator|*
operator|,
expr|struct
name|args_size
operator|*
operator|,
expr|struct
name|args_size
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|expand_inline_function
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|,
name|rtx
operator|,
name|int
operator|,
name|tree
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the CODE_LABEL rtx for a LABEL_DECL, creating it if necessary.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|label_rtx
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Indicate how an input argument register was promoted.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|promoted_input_arg
name|PROTO
argument_list|(
operator|(
name|int
operator|,
expr|enum
name|machine_mode
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return an rtx like arg but sans any constant terms.    Returns the original rtx if it has no constant terms.    The constant terms are added and stored via a second arg.  */
end_comment

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

begin_comment
comment|/* Convert arg to a valid memory address for specified machine mode,    by emitting insns to perform arithmetic if nec.  */
end_comment

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

begin_comment
comment|/* Like `memory_address' but pretent `flag_force_addr' is 0.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|memory_address_noforce
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
comment|/* Return a memory reference like MEMREF, but with its mode changed    to MODE and its address changed to ADDR.    (VOIDmode means don't change the mode.    NULL for ADDR means don't change the address.)  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|change_address
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|machine_mode
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return a memory reference like MEMREF, but which is known to have a    valid address.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|validize_mem
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Assemble the static constant template for function entry trampolines.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|assemble_trampoline_template
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return 1 if two rtx's are equivalent in structure and elements.  */
end_comment

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

begin_comment
comment|/* Given rtx, return new rtx whose address won't be affected by    any side effects.  It has been copied to a new temporary reg.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|stabilize
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given an rtx, copy all regs it refers to into new temps    and return a modified copy that refers to the new temps.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|copy_all_regs
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Copy given rtx to a new temp reg and return that.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|copy_to_reg
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Like copy_to_reg but always make the reg Pmode.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|copy_addr_to_reg
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Like copy_to_reg but always make the reg the specified mode MODE.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|copy_to_mode_reg
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
comment|/* Copy given rtx to given temp reg and return that.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|copy_to_suggested_reg
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Copy a value to a register if it isn't already a register.    Args are mode (in case value is a constant) and the value.  */
end_comment

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

begin_comment
comment|/* Return given rtx, copied into a new temp reg if it was in memory.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|force_not_mem
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|TREE_CODE
end_ifdef

begin_comment
comment|/* Return mode and signedness to use when object is promoted.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|machine_mode
name|promote_mode
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
expr|enum
name|machine_mode
operator|,
name|int
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

begin_comment
comment|/* Remove some bytes from the stack.  An rtx says how many.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|adjust_stack
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add some bytes to the stack.  An rtx says how many.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|anti_adjust_stack
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|void
name|emit_stack_save
name|PROTO
argument_list|(
operator|(
expr|enum
name|save_level
operator|,
name|rtx
operator|*
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Restore the stack pointer from a save area of the specified level.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|emit_stack_restore
name|PROTO
argument_list|(
operator|(
expr|enum
name|save_level
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allocate some space on the stack dynamically and return its address.  An rtx    says how many bytes.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|allocate_dynamic_stack_space
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

begin_comment
comment|/* Probe a range of stack addresses from FIRST to FIRST+SIZE, inclusive.     FIRST is a constant and size is a Pmode RTX.  These are offsets from the    current stack pointer.  STACK_GROWS_DOWNWARD says whether to add or    subtract from the stack.  If SIZE is constant, this is done    with a fixed number of probes.  Otherwise, we must make a loop.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|probe_stack_range
name|PROTO
argument_list|(
operator|(
name|HOST_WIDE_INT
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return an rtx that refers to the value returned by a library call    in its original home.  This becomes invalid if any more code is emitted.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|hard_libcall_value
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given an rtx, return an rtx for a value rounded up to a multiple    of STACK_BOUNDARY / BITS_PER_UNIT.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|round_push
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
name|store_bit_field
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

begin_decl_stmt
specifier|extern
name|rtx
name|extract_bit_field
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
operator|,
name|rtx
operator|,
expr|enum
name|machine_mode
operator|,
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
name|expand_mult
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
name|expand_mult_add
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
name|expand_mult_highpart_adjust
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
name|assemble_static_space
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hook called by expand_expr for language-specific tree codes.    It is up to the language front end to install a hook    if it has any such codes that expand_expr needs to know about.  */
end_comment

begin_extern
extern|extern rtx (*lang_expand_expr
end_extern

begin_expr_stmt
unit|)
name|PROTO
argument_list|(
operator|(
expr|union
name|tree_node
operator|*
operator|,
name|rtx
operator|,
expr|enum
name|machine_mode
operator|,
expr|enum
name|expand_modifier
name|modifier
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|TREE_CODE
end_ifdef

begin_comment
comment|/* Hook called by output_constant for language-specific tree codes.    It is up to the language front-end to install a hook if it has any    such codes that output_constant needs to know about.  Returns a    language-independent constant equivalent to its input.  */
end_comment

begin_extern
extern|extern tree (*lang_expand_constant
end_extern

begin_expr_stmt
unit|)
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|init_all_optabs
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
name|init_mov_optab
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
name|do_jump_by_parts_equality_rtx
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
name|do_jump_by_parts_greater_rtx
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|int
operator|,
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

begin_ifdef
ifdef|#
directive|ifdef
name|TREE_CODE
end_ifdef

begin_comment
comment|/* Don't lose if tree.h not included.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|mark_seen_cases
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|unsigned
name|char
operator|*
operator|,
name|long
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

end_unit

