begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- ipo_ocaml.c - LLVM OCaml Glue ---------------------------*- C++ -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This file glues LLVM's OCaml interface to its C interface. These functions *| |* are by and large transparent wrappers to the corresponding C functions.    *| |*                                                                            *| |* Note that these functions intentionally take liberties with the CAMLparamX *| |* macros, since most of the parameters are not GC heap objects.              *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_include
include|#
directive|include
file|"llvm-c/Transforms/IPO.h"
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
comment|/* [`Module] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_argument_promotion
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddArgumentPromotionPass
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
comment|/* [`Module] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_constant_merge
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddConstantMergePass
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
comment|/* [`Module] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_dead_arg_elimination
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddDeadArgEliminationPass
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
comment|/* [`Module] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_function_attrs
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddFunctionAttrsPass
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
comment|/* [`Module] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_function_inlining
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddFunctionInliningPass
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
comment|/* [`Module] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_always_inliner
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddAlwaysInlinerPass
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
comment|/* [`Module] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_global_dce
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddGlobalDCEPass
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
comment|/* [`Module] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_global_optimizer
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddGlobalOptimizerPass
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
comment|/* [`Module] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_ip_constant_propagation
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddIPConstantPropagationPass
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
comment|/* [`Module] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_prune_eh
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddPruneEHPass
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
comment|/* [`Module] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_ipsccp
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddIPSCCPPass
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
comment|/* [`Module] Llvm.PassManager.t -> all_but_main:bool -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_internalize
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|,
name|value
name|AllButMain
parameter_list|)
block|{
name|LLVMAddInternalizePass
argument_list|(
name|PM
argument_list|,
name|Bool_val
argument_list|(
name|AllButMain
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|Val_unit
return|;
block|}
end_function

begin_comment
comment|/* [`Module] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_strip_dead_prototypes
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddStripDeadPrototypesPass
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
comment|/* [`Module] Llvm.PassManager.t -> unit */
end_comment

begin_function
name|CAMLprim
name|value
name|llvm_add_strip_symbols
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
block|{
name|LLVMAddStripSymbolsPass
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

