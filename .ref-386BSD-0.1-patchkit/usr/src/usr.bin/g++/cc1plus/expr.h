begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for code generation pass of GNU compiler.    Copyright (C) 1987 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|const
end_ifndef

begin_define
define|#
directive|define
name|const
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
comment|/* If the increment has been emitted, this is the insn    that does the increment.  It is zero before the increment is emitted.  */
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
comment|/* This is the 4th arg to `expand_expr'.    EXPAND_SUM means it is ok to return a PLUS rtx or MULT rtx.    EXPAND_CONST_ADDRESS means it is ok to return a MEM whose address     is a constant that is not a legitimate address.    EXPAND_INTO_STACK means that if a temporary value needs to be     created, it should be done so that it lasts the life of     the call.  This can be implemented either by returning     a pointer to a slot which is actually allocated on the stack,     or by returning a temporary in the callers frame.  */
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
name|EXPAND_INTO_STACK
block|}
enum|;
end_enum

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

begin_comment
comment|/* Nonzero means stack pops must not be deferred, and deferred stack    pops must not be output.  It is nonzero inside a function call,    inside a conditional expression, inside a statement expression,    and in other cases as well.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inhibit_defer_pop
decl_stmt|;
end_decl_stmt

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
comment|/* RTX for stack slot that holds the current handler for nonlocal gotos.    Zero when function does not have nonlocal labels.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|nonlocal_goto_handler_slot
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

begin_define
define|#
directive|define
name|NO_DEFER_POP
value|(inhibit_defer_pop += 1)
end_define

begin_define
define|#
directive|define
name|OK_DEFER_POP
value|(inhibit_defer_pop -= 1)
end_define

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
comment|/* A list of all cleanups which belong to the arguments of    function calls being expanded by expand_call.  */
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
name|cleanups_this_call
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Sequence of insns which must be emitted *prior* to calling    __builtin_saveregs.  */
end_comment

begin_decl_stmt
name|rtx
name|save_from_saveregs
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
name|int
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
value|{ tree inc = (INC);				\   if (TREE_CODE (inc) == INTEGER_CST)		\     (TO).constant += TREE_INT_CST_LOW (inc);	\   else if ((TO).var == 0)			\     (TO).var = inc;				\   else						\     (TO).var = genop (PLUS_EXPR, (TO).var, inc); }
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
value|{ tree dec = (DEC);				\   if (TREE_CODE (dec) == INTEGER_CST)		\     (TO).constant -= TREE_INT_CST_LOW (dec);	\   else if ((TO).var == 0)			\     (TO).var = genop (MINUS_EXPR, integer_zero_node, dec); \   else						\     (TO).var = genop (MINUS_EXPR, (TO).var, dec); }
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
value|((SIZE).var == 0 ? gen_rtx (CONST_INT, VOIDmode, (SIZE).constant)	\  : plus_constant (expand_expr ((SIZE).var, 0, VOIDmode, 0),		\ 		  (SIZE).constant))
end_define

begin_comment
comment|/* Supply a default definition for FUNCTION_ARG_PADDING:    usually pad upward, but pad short args downward on big-endian machines.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|BYTES_BIG_ENDIAN
end_ifdef

begin_define
define|#
directive|define
name|FUNCTION_ARG_PADDING
parameter_list|(
name|mode
parameter_list|,
name|size
parameter_list|)
define|\
value|(((mode) == BLKmode							\     ? (GET_CODE (size) == CONST_INT					\&& INTVAL (size)< PARM_BOUNDARY / BITS_PER_UNIT)		\     : GET_MODE_BITSIZE (mode)< PARM_BOUNDARY)				\    ? downward : upward)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FUNCTION_ARG_PADDING
parameter_list|(
name|mode
parameter_list|,
name|size
parameter_list|)
value|upward
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
comment|/* Nonzero if type TYPE should be returned in memory    (even though its mode is not BLKmode).    Most machines can use the following default definition.  */
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
name|type
parameter_list|)
value|0
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
name|char
modifier|*
name|lib_call
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

begin_define
define|#
directive|define
name|GEN_FCN
parameter_list|(
name|CODE
parameter_list|)
value|(*insn_gen_function[(int) (CODE)])
end_define

begin_extern
extern|extern rtx (*const insn_gen_function[]
end_extern

begin_expr_stmt
unit|)
operator|(
operator|)
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
comment|/* Signed multiply */
end_comment

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
name|lshl_optab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Logical shift left */
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
block|, }
enum|;
end_enum

begin_escape
end_escape

begin_typedef
typedef|typedef
name|rtx
function_decl|(
modifier|*
name|rtxfun
function_decl|)
parameter_list|()
function_decl|;
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
comment|/* Indexed by the rtx-code for a conditional (eg. EQ, LT,...)    gives the gen_function to make a store-condition insn    to test that condition.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtxfun
name|setcc_gen_fctn
index|[
name|NUM_RTX_CODE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Expand a binary operation given optab and rtx operands.  */
end_comment

begin_function_decl
name|rtx
name|expand_binop
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Expand a binary operation with both signed and unsigned forms.  */
end_comment

begin_function_decl
name|rtx
name|sign_expand_binop
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Expand a unary arithmetic operation given optab rtx operand.  */
end_comment

begin_function_decl
name|rtx
name|expand_unop
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Arguments MODE, RTX: return an rtx for the negation of that value.    May emit insns.  */
end_comment

begin_function_decl
name|rtx
name|negate_rtx
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Initialize the tables that control conversion between fixed and    floating values.  */
end_comment

begin_function_decl
name|void
name|init_fixtab
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_floattab
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Generate code for a FIX_EXPR.  */
end_comment

begin_function_decl
name|void
name|expand_fix
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Generate code for a FLOAT_EXPR.  */
end_comment

begin_function_decl
name|void
name|expand_float
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Create but don't emit one rtl instruction to add one rtx into another.    Modes must match.    Likewise for subtraction and for just copying.    These do not call protect_from_queue; caller must do so.  */
end_comment

begin_function_decl
name|rtx
name|gen_add2_insn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|rtx
name|gen_sub2_insn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|rtx
name|gen_move_insn
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Emit one rtl instruction to store zero in specified rtx.  */
end_comment

begin_function_decl
name|void
name|emit_clr_insn
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Emit one rtl insn to store 1 in specified rtx assuming it contains 0.  */
end_comment

begin_function_decl
name|void
name|emit_0_to_1_insn
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Emit one rtl insn to compare two rtx's.  */
end_comment

begin_function_decl
name|void
name|emit_cmp_insn
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Emit some rtl insns to move data between rtx's, converting machine modes.    Both modes must be floating or both fixed.  */
end_comment

begin_function_decl
name|void
name|convert_move
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Convert an rtx to specified machine mode and return the result.  */
end_comment

begin_function_decl
name|rtx
name|convert_to_mode
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Emit code to push some arguments and call a library routine,    storing the value in a specified place.  Calling sequence is    complicated.  */
end_comment

begin_function_decl
name|void
name|emit_library_call
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Given an rtx that may include add and multiply operations,    generate them as insns and return a pseudo-reg containing the value.    Useful after calling expand_expr with 1 as sum_ok.  */
end_comment

begin_function_decl
name|rtx
name|force_operand
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return an rtx for the size in bytes of the value of an expr.  */
end_comment

begin_function_decl
name|rtx
name|expr_size
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return an rtx for the sum of an rtx and an integer.  */
end_comment

begin_function_decl
name|rtx
name|plus_constant
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|rtx
name|lookup_static_chain
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return an rtx like arg but sans any constant terms.    Returns the original rtx if it has no constant terms.    The constant terms are added and stored via a second arg.  */
end_comment

begin_function_decl
name|rtx
name|eliminate_constant_term
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Convert arg to a valid memory address for specified machine mode,    by emitting insns to perform arithmetic if nec.  */
end_comment

begin_function_decl
name|rtx
name|memory_address
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Like `memory_address' but pretent `flag_force_addr' is 0.  */
end_comment

begin_function_decl
name|rtx
name|memory_address_noforce
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return a memory reference like MEMREF, but with its mode changed    to MODE and its address changed to ADDR.    (VOIDmode means don't change the mode.    NULL for ADDR means don't change the address.)  */
end_comment

begin_function_decl
name|rtx
name|change_address
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Convert a stack slot address ADDR valid in function FNDECL    into an address valid in this function (using a static chain).  */
end_comment

begin_comment
unit|rtx fix_lexical_addr ();
comment|/* Return the address of the trampoline for entering nested fn FUNCTION.  */
end_comment

begin_comment
unit|rtx trampoline_address ();
comment|/* Assemble the static constant template for function entry trampolines.  */
end_comment

begin_endif
unit|rtx assemble_trampoline_template ();
endif|#
directive|endif
end_endif

begin_comment
comment|/* Return 1 if two rtx's are equivalent in structure and elements.  */
end_comment

begin_function_decl
name|int
name|rtx_equal_p
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Given rtx, return new rtx whose address won't be affected by    any side effects.  It has been copied to a new temporary reg.  */
end_comment

begin_function_decl
name|rtx
name|stabilize
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Given an rtx, copy all regs it refers to into new temps    and return a modified copy that refers to the new temps.  */
end_comment

begin_function_decl
name|rtx
name|copy_all_regs
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Copy given rtx to a new temp reg and return that.  */
end_comment

begin_function_decl
name|rtx
name|copy_to_reg
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Like copy_to_reg but always make the reg Pmode.  */
end_comment

begin_function_decl
name|rtx
name|copy_addr_to_reg
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Like copy_to_reg but always make the reg the specified mode MODE.  */
end_comment

begin_function_decl
name|rtx
name|copy_to_mode_reg
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Copy given rtx to given temp reg and return that.  */
end_comment

begin_function_decl
name|rtx
name|copy_to_suggested_reg
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Copy a value to a register if it isn't already a register.    Args are mode (in case value is a constant) and the value.  */
end_comment

begin_function_decl
name|rtx
name|force_reg
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return given rtx, copied into a new temp reg if it was in memory.  */
end_comment

begin_function_decl
name|rtx
name|force_not_mem
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Remove some bytes from the stack.  An rtx says how many.  */
end_comment

begin_function_decl
name|void
name|adjust_stack
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Add some bytes to the stack.  An rtx says how many.  */
end_comment

begin_function_decl
name|void
name|anti_adjust_stack
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Emit code to copy function value to a new temp reg and return that reg.  */
end_comment

begin_function_decl
name|rtx
name|function_value
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return an rtx that refers to the value returned by a function    in its original home.  This becomes invalid if any more code is emitted.  */
end_comment

begin_function_decl
name|rtx
name|hard_function_value
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return an rtx that refers to the value returned by a library call    in its original home.  This becomes invalid if any more code is emitted.  */
end_comment

begin_function_decl
name|rtx
name|hard_libcall_value
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Emit code to copy function value to a specified place.  */
end_comment

begin_function_decl
name|void
name|copy_function_value
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Given an rtx, return an rtx for a value rounded up to a multiple    of STACK_BOUNDARY / BITS_PER_UNIT.  */
end_comment

begin_function_decl
name|rtx
name|round_push
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Push a block of length SIZE (perhaps variable)    and return an rtx to address the beginning of the block.  */
end_comment

begin_function_decl
name|rtx
name|push_block
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Generate code for computing expression EXP,    and storing the value into TARGET.    If SUGGEST_REG is nonzero, copy the value through a register    and return that register, if that is possible.  */
end_comment

begin_function_decl
name|rtx
name|store_expr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|rtx
name|prepare_call_address
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|rtx
name|expand_call
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|emit_call_1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|emit_block_move
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|emit_push_insn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|use_regs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|move_block_to_reg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|rtx
name|store_bit_field
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|rtx
name|extract_bit_field
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|rtx
name|expand_shift
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|rtx
name|expand_mult
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|rtx
name|expand_divmod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|rtx
name|expand_mult_add
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|rtx
name|get_structure_value_addr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|rtx
name|expand_stmt_expr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|rtx
name|emit_no_conflict_block
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|jumpifnot
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|jumpif
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_jump
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|rtx
name|assemble_static_space
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Needed for old compiler.  */
end_comment

begin_function_decl
name|rtx
name|expand_bit_and
parameter_list|()
function_decl|;
end_function_decl

end_unit

