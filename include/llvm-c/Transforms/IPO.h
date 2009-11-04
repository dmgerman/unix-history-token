begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- IPO.h - Interprocedural Transformations C Interface -----*- C++ -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This header declares the C interface to libLLVMIPO.a, which implements     *| |* various interprocedural transformations of the LLVM IR.                    *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_C_TRANSFORMS_IPO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_C_TRANSFORMS_IPO_H
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
comment|/** See llvm::createArgumentPromotionPass function. */
name|void
name|LLVMAddArgumentPromotionPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createConstantMergePass function. */
name|void
name|LLVMAddConstantMergePass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createDeadArgEliminationPass function. */
name|void
name|LLVMAddDeadArgEliminationPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createDeadTypeEliminationPass function. */
name|void
name|LLVMAddDeadTypeEliminationPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createFunctionAttrsPass function. */
name|void
name|LLVMAddFunctionAttrsPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createFunctionInliningPass function. */
name|void
name|LLVMAddFunctionInliningPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createGlobalDCEPass function. */
name|void
name|LLVMAddGlobalDCEPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createGlobalOptimizerPass function. */
name|void
name|LLVMAddGlobalOptimizerPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createIPConstantPropagationPass function. */
name|void
name|LLVMAddIPConstantPropagationPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createLowerSetJmpPass function. */
name|void
name|LLVMAddLowerSetJmpPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createPruneEHPass function. */
name|void
name|LLVMAddPruneEHPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|// FIXME: Remove in LLVM 3.0.
name|void
name|LLVMAddRaiseAllocationsPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createStripDeadPrototypesPass function. */
name|void
name|LLVMAddStripDeadPrototypesPass
parameter_list|(
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::createStripSymbolsPass function. */
name|void
name|LLVMAddStripSymbolsPass
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

