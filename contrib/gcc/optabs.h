begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for code generation pass of GNU compiler.    Copyright (C) 2001 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_OPTABS_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_OPTABS_H
end_define

begin_include
include|#
directive|include
file|"insn-codes.h"
end_include

begin_comment
comment|/* Optabs are tables saying how to generate insn bodies    for various machine modes and numbers of operands.    Each optab applies to one operation.    For example, add_optab applies to addition.     The insn_code slot is the enum insn_code that says how to    generate an insn for this operation on a particular machine mode.    It is CODE_FOR_nothing if there is no such insn on the target machine.     The `lib_call' slot is the name of the library function that    can be used to perform the operation.     A few optabs, such as move_optab and cmp_optab, are used    by special code.  */
end_comment

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

begin_define
define|#
directive|define
name|GEN_FCN
parameter_list|(
name|CODE
parameter_list|)
value|(*insn_data[(int) (CODE)].genfun)
end_define

begin_comment
comment|/* Enumeration of valid indexes into optab_table.  */
end_comment

begin_enum
enum|enum
name|optab_index
block|{
name|OTI_add
block|,
name|OTI_addv
block|,
name|OTI_sub
block|,
name|OTI_subv
block|,
comment|/* Signed and fp multiply */
name|OTI_smul
block|,
name|OTI_smulv
block|,
comment|/* Signed multiply, return high word */
name|OTI_smul_highpart
block|,
name|OTI_umul_highpart
block|,
comment|/* Signed multiply with result one machine mode wider than args */
name|OTI_smul_widen
block|,
name|OTI_umul_widen
block|,
comment|/* Signed divide */
name|OTI_sdiv
block|,
name|OTI_sdivv
block|,
comment|/* Signed divide-and-remainder in one */
name|OTI_sdivmod
block|,
name|OTI_udiv
block|,
name|OTI_udivmod
block|,
comment|/* Signed remainder */
name|OTI_smod
block|,
name|OTI_umod
block|,
comment|/* Convert float to integer in float fmt */
name|OTI_ftrunc
block|,
comment|/* Logical and */
name|OTI_and
block|,
comment|/* Logical or */
name|OTI_ior
block|,
comment|/* Logical xor */
name|OTI_xor
block|,
comment|/* Arithmetic shift left */
name|OTI_ashl
block|,
comment|/* Logical shift right */
name|OTI_lshr
block|,
comment|/* Arithmetic shift right */
name|OTI_ashr
block|,
comment|/* Rotate left */
name|OTI_rotl
block|,
comment|/* Rotate right */
name|OTI_rotr
block|,
comment|/* Signed and floating-point minimum value */
name|OTI_smin
block|,
comment|/* Signed and floating-point maximum value */
name|OTI_smax
block|,
comment|/* Unsigned minimum value */
name|OTI_umin
block|,
comment|/* Unsigned maximum value */
name|OTI_umax
block|,
comment|/* Move instruction.  */
name|OTI_mov
block|,
comment|/* Move, preserving high part of register.  */
name|OTI_movstrict
block|,
comment|/* Unary operations */
comment|/* Negation */
name|OTI_neg
block|,
name|OTI_negv
block|,
comment|/* Abs value */
name|OTI_abs
block|,
name|OTI_absv
block|,
comment|/* Bitwise not */
name|OTI_one_cmpl
block|,
comment|/* Find first bit set */
name|OTI_ffs
block|,
comment|/* Square root */
name|OTI_sqrt
block|,
comment|/* Sine */
name|OTI_sin
block|,
comment|/* Cosine */
name|OTI_cos
block|,
comment|/* Compare insn; two operands.  */
name|OTI_cmp
block|,
comment|/* Used only for libcalls for unsigned comparisons.  */
name|OTI_ucmp
block|,
comment|/* tst insn; compare one operand against 0 */
name|OTI_tst
block|,
comment|/* String length */
name|OTI_strlen
block|,
comment|/* Combined compare& jump/store flags/move operations.  */
name|OTI_cbranch
block|,
name|OTI_cmov
block|,
name|OTI_cstore
block|,
comment|/* Push instruction.  */
name|OTI_push
block|,
name|OTI_MAX
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|optab
name|optab_table
index|[
name|OTI_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|add_optab
value|(optab_table[OTI_add])
end_define

begin_define
define|#
directive|define
name|sub_optab
value|(optab_table[OTI_sub])
end_define

begin_define
define|#
directive|define
name|smul_optab
value|(optab_table[OTI_smul])
end_define

begin_define
define|#
directive|define
name|addv_optab
value|(optab_table[OTI_addv])
end_define

begin_define
define|#
directive|define
name|subv_optab
value|(optab_table[OTI_subv])
end_define

begin_define
define|#
directive|define
name|smul_highpart_optab
value|(optab_table[OTI_smul_highpart])
end_define

begin_define
define|#
directive|define
name|umul_highpart_optab
value|(optab_table[OTI_umul_highpart])
end_define

begin_define
define|#
directive|define
name|smul_widen_optab
value|(optab_table[OTI_smul_widen])
end_define

begin_define
define|#
directive|define
name|umul_widen_optab
value|(optab_table[OTI_umul_widen])
end_define

begin_define
define|#
directive|define
name|sdiv_optab
value|(optab_table[OTI_sdiv])
end_define

begin_define
define|#
directive|define
name|smulv_optab
value|(optab_table[OTI_smulv])
end_define

begin_define
define|#
directive|define
name|sdivv_optab
value|(optab_table[OTI_sdivv])
end_define

begin_define
define|#
directive|define
name|sdivmod_optab
value|(optab_table[OTI_sdivmod])
end_define

begin_define
define|#
directive|define
name|udiv_optab
value|(optab_table[OTI_udiv])
end_define

begin_define
define|#
directive|define
name|udivmod_optab
value|(optab_table[OTI_udivmod])
end_define

begin_define
define|#
directive|define
name|smod_optab
value|(optab_table[OTI_smod])
end_define

begin_define
define|#
directive|define
name|umod_optab
value|(optab_table[OTI_umod])
end_define

begin_define
define|#
directive|define
name|ftrunc_optab
value|(optab_table[OTI_ftrunc])
end_define

begin_define
define|#
directive|define
name|and_optab
value|(optab_table[OTI_and])
end_define

begin_define
define|#
directive|define
name|ior_optab
value|(optab_table[OTI_ior])
end_define

begin_define
define|#
directive|define
name|xor_optab
value|(optab_table[OTI_xor])
end_define

begin_define
define|#
directive|define
name|ashl_optab
value|(optab_table[OTI_ashl])
end_define

begin_define
define|#
directive|define
name|lshr_optab
value|(optab_table[OTI_lshr])
end_define

begin_define
define|#
directive|define
name|ashr_optab
value|(optab_table[OTI_ashr])
end_define

begin_define
define|#
directive|define
name|rotl_optab
value|(optab_table[OTI_rotl])
end_define

begin_define
define|#
directive|define
name|rotr_optab
value|(optab_table[OTI_rotr])
end_define

begin_define
define|#
directive|define
name|smin_optab
value|(optab_table[OTI_smin])
end_define

begin_define
define|#
directive|define
name|smax_optab
value|(optab_table[OTI_smax])
end_define

begin_define
define|#
directive|define
name|umin_optab
value|(optab_table[OTI_umin])
end_define

begin_define
define|#
directive|define
name|umax_optab
value|(optab_table[OTI_umax])
end_define

begin_define
define|#
directive|define
name|mov_optab
value|(optab_table[OTI_mov])
end_define

begin_define
define|#
directive|define
name|movstrict_optab
value|(optab_table[OTI_movstrict])
end_define

begin_define
define|#
directive|define
name|neg_optab
value|(optab_table[OTI_neg])
end_define

begin_define
define|#
directive|define
name|negv_optab
value|(optab_table[OTI_negv])
end_define

begin_define
define|#
directive|define
name|abs_optab
value|(optab_table[OTI_abs])
end_define

begin_define
define|#
directive|define
name|absv_optab
value|(optab_table[OTI_absv])
end_define

begin_define
define|#
directive|define
name|one_cmpl_optab
value|(optab_table[OTI_one_cmpl])
end_define

begin_define
define|#
directive|define
name|ffs_optab
value|(optab_table[OTI_ffs])
end_define

begin_define
define|#
directive|define
name|sqrt_optab
value|(optab_table[OTI_sqrt])
end_define

begin_define
define|#
directive|define
name|sin_optab
value|(optab_table[OTI_sin])
end_define

begin_define
define|#
directive|define
name|cos_optab
value|(optab_table[OTI_cos])
end_define

begin_define
define|#
directive|define
name|cmp_optab
value|(optab_table[OTI_cmp])
end_define

begin_define
define|#
directive|define
name|ucmp_optab
value|(optab_table[OTI_ucmp])
end_define

begin_define
define|#
directive|define
name|tst_optab
value|(optab_table[OTI_tst])
end_define

begin_define
define|#
directive|define
name|strlen_optab
value|(optab_table[OTI_strlen])
end_define

begin_define
define|#
directive|define
name|cbranch_optab
value|(optab_table[OTI_cbranch])
end_define

begin_define
define|#
directive|define
name|cmov_optab
value|(optab_table[OTI_cmov])
end_define

begin_define
define|#
directive|define
name|cstore_optab
value|(optab_table[OTI_cstore])
end_define

begin_define
define|#
directive|define
name|push_optab
value|(optab_table[OTI_push])
end_define

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
comment|/* Tables of patterns for converting between fixed and floating point.  */
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
comment|/* These arrays record the insn_code of insns that may be needed to    perform input and output reloads of special objects.  They provide a    place to pass a scratch register.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|insn_code
name|reload_in_optab
index|[
name|NUM_MACHINE_MODES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|insn_code
name|reload_out_optab
index|[
name|NUM_MACHINE_MODES
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

begin_escape
end_escape

begin_typedef
typedef|typedef
name|rtx
argument_list|(
argument|*rtxfun
argument_list|)
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
comment|/* Emit one rtl instruction to store zero in specified rtx.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|emit_clr_insn
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The various uses that a comparison can have; used by can_compare_p:    jumps, conditional moves, store flag operations.  */
end_comment

begin_enum
enum|enum
name|can_compare_purpose
block|{
name|ccp_jump
block|,
name|ccp_cmov
block|,
name|ccp_store_flag
block|}
enum|;
end_enum

begin_comment
comment|/* Nonzero if a compare of mode MODE can be done straightforwardly    (without splitting it into pieces).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|can_compare_p
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
name|can_compare_purpose
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|prepare_operand
name|PARAMS
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
comment|/* Return the INSN_CODE to use for an extend operation.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|insn_code
name|can_extend_p
name|PARAMS
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
name|PARAMS
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
name|init_floattab
name|PARAMS
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

begin_comment
comment|/* Generate code for a FIX_EXPR.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|expand_fix
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_OPTABS_H */
end_comment

end_unit

