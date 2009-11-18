begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- Scalar.h - Scalar Transformation Library C Interface ----*- C++ -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This header declares the C interface to libLLVMScalarOpts.a, which         *| |* implements various scalar transformations of the LLVM IR.                  *| |*                                                                            *| |* Many exotic languages can interoperate with C code but have a harder time  *| |* with C++ due to name mangling. So in addition to C, this interface enables *| |* tools written in such languages.                                           *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_C_TRANSFORMS_SCALAR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_C_TRANSFORMS_SCALAR_H
end_define

begin_include
include|#
directive|include
file|"llvm-c/Core.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/** See llvm::createAggressiveDCEPass function. */
name|void
name|LLVMAddAggressiveDCEPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createCFGSimplificationPass function. */
name|void
name|LLVMAddCFGSimplificationPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createDeadStoreEliminationPass function. */
name|void
name|LLVMAddDeadStoreEliminationPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createGVNPass function. */
name|void
name|LLVMAddGVNPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createIndVarSimplifyPass function. */
name|void
name|LLVMAddIndVarSimplifyPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createInstructionCombiningPass function. */
name|void
name|LLVMAddInstructionCombiningPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createJumpThreadingPass function. */
name|void
name|LLVMAddJumpThreadingPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createLICMPass function. */
name|void
name|LLVMAddLICMPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createLoopDeletionPass function. */
name|void
name|LLVMAddLoopDeletionPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createLoopIndexSplitPass function. */
name|void
name|LLVMAddLoopIndexSplitPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createLoopRotatePass function. */
name|void
name|LLVMAddLoopRotatePass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createLoopUnrollPass function. */
name|void
name|LLVMAddLoopUnrollPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createLoopUnswitchPass function. */
name|void
name|LLVMAddLoopUnswitchPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createMemCpyOptPass function. */
name|void
name|LLVMAddMemCpyOptPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createPromoteMemoryToRegisterPass function. */
name|void
name|LLVMAddPromoteMemoryToRegisterPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createReassociatePass function. */
name|void
name|LLVMAddReassociatePass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createSCCPPass function. */
name|void
name|LLVMAddSCCPPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createScalarReplAggregatesPass function. */
name|void
name|LLVMAddScalarReplAggregatesPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createSimplifyLibCallsPass function. */
name|void
name|LLVMAddSimplifyLibCallsPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createTailCallEliminationPass function. */
name|void
name|LLVMAddTailCallEliminationPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createConstantPropagationPass function. */
name|void
name|LLVMAddConstantPropagationPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::demotePromoteMemoryToRegisterPass function. */
name|void
name|LLVMAddDemoteMemoryToRegisterPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__cplusplus) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

