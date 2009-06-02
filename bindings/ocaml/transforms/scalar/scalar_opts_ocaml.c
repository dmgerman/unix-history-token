begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- scalar_opts_ocaml.c - LLVM Ocaml Glue -------------------*- C++ -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This file glues LLVM's ocaml interface to its C interface. These functions *| |* are by and large transparent wrappers to the corresponding C functions.    *| |*                                                                            *| |* Note that these functions intentionally take liberties with the CAMLparamX *| |* macros, since most of the parameters are not GC heap objects.              *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
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
name|llvm_add_instruction_combining
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

end_unit

