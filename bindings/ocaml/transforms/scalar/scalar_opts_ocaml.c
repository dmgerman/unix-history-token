begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- scalar_opts_ocaml.c - LLVM OCaml Glue -------------------*- C++ -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This file glues LLVM's OCaml interface to its C interface. These functions *| |* are by and large transparent wrappers to the corresponding C functions.    *| |*                                                                            *| |* Note that these functions intentionally take liberties with the CAMLparamX *| |* macros, since most of the parameters are not GC heap objects.              *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_include
include|#
directive|include
file|"llvm-c/Transforms/Scalar.h"
end_include

begin_include
include|#
directive|include
file|"caml/mlvalues.h"
end_include

begin_include
include|#
directive|include
file|"caml/misc.h"
end_include

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_constant_propagation
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddConstantPropagationPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_sccp
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddSCCPPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_dead_store_elimination
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddDeadStoreEliminationPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_aggressive_dce
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddAggressiveDCEPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_scalar_repl_aggregation
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddScalarReplAggregatesPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_scalar_repl_aggregation_ssa
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddScalarReplAggregatesPassSSA
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> int -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_scalar_repl_aggregation_with_threshold
parameter_list|(
name|value
name|threshold
parameter_list|,
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddScalarReplAggregatesPassWithThreshold
argument_list|(
name|PM
argument_list|,
name|Int_val
argument_list|(
name|threshold
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_ind_var_simplification
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddIndVarSimplifyPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_instruction_combination
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddInstructionCombiningPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_licm
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddLICMPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_loop_unswitch
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddLoopUnswitchPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_loop_unroll
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddLoopUnrollPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_loop_rotation
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddLoopRotatePass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_memory_to_register_promotion
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddPromoteMemoryToRegisterPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_memory_to_register_demotion
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddDemoteMemoryToRegisterPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_reassociation
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddReassociatePass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_jump_threading
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddJumpThreadingPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_cfg_simplification
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddCFGSimplificationPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_tail_call_elimination
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddTailCallEliminationPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_merged_load_store_motion
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddMergedLoadStoreMotionPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_gvn
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddGVNPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_memcpy_opt
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddMemCpyOptPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_loop_deletion
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddLoopDeletionPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_loop_idiom
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddLoopIdiomPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_lib_call_simplification
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddSimplifyLibCallsPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_verifier
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddVerifierPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_correlated_value_propagation
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddCorrelatedValuePropagationPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_early_cse
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddEarlyCSEPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_lower_expect_intrinsic
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddLowerExpectIntrinsicPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_type_based_alias_analysis
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddTypeBasedAliasAnalysisPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_basic_alias_analysis
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddBasicAliasAnalysisPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [<Llvm.PassManager.any] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_partially_inline_lib_calls
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddPartiallyInlineLibCallsPass
argument_list|(
name|PM
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

end_unit

