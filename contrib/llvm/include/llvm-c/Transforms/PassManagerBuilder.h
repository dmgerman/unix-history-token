begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- llvm-c/Transform/PassManagerBuilder.h - PMB C Interface ---*- C -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This header declares the C interface to the PassManagerBuilder class.      *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_C_PASSMANAGERBUILDER
end_ifndef

begin_define
define|#
directive|define
name|LLVM_C_PASSMANAGERBUILDER
end_define

begin_include
include|#
directive|include
file|"llvm-c/Core.h"
end_include

begin_typedef
typedef|typedef
name|struct
name|LLVMOpaquePassManagerBuilder
modifier|*
name|LLVMPassManagerBuilderRef
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_include
include|#
directive|include
file|"llvm/Transforms/IPO/PassManagerBuilder.h"
end_include

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/** See llvm::PassManagerBuilder. */
name|LLVMPassManagerBuilderRef
name|LLVMPassManagerBuilderCreate
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|LLVMPassManagerBuilderDispose
parameter_list|(
name|LLVMPassManagerBuilderRef
name|PMB
parameter_list|)
function_decl|;
comment|/** See llvm::PassManagerBuilder::OptLevel. */
name|void
name|LLVMPassManagerBuilderSetOptLevel
parameter_list|(
name|LLVMPassManagerBuilderRef
name|PMB
parameter_list|,
name|unsigned
name|OptLevel
parameter_list|)
function_decl|;
comment|/** See llvm::PassManagerBuilder::SizeLevel. */
name|void
name|LLVMPassManagerBuilderSetSizeLevel
parameter_list|(
name|LLVMPassManagerBuilderRef
name|PMB
parameter_list|,
name|unsigned
name|SizeLevel
parameter_list|)
function_decl|;
comment|/** See llvm::PassManagerBuilder::DisableUnitAtATime. */
name|void
name|LLVMPassManagerBuilderSetDisableUnitAtATime
parameter_list|(
name|LLVMPassManagerBuilderRef
name|PMB
parameter_list|,
name|LLVMBool
name|Value
parameter_list|)
function_decl|;
comment|/** See llvm::PassManagerBuilder::DisableUnrollLoops. */
name|void
name|LLVMPassManagerBuilderSetDisableUnrollLoops
parameter_list|(
name|LLVMPassManagerBuilderRef
name|PMB
parameter_list|,
name|LLVMBool
name|Value
parameter_list|)
function_decl|;
comment|/** See llvm::PassManagerBuilder::DisableSimplifyLibCalls */
name|void
name|LLVMPassManagerBuilderSetDisableSimplifyLibCalls
parameter_list|(
name|LLVMPassManagerBuilderRef
name|PMB
parameter_list|,
name|LLVMBool
name|Value
parameter_list|)
function_decl|;
comment|/** See llvm::PassManagerBuilder::Inliner. */
name|void
name|LLVMPassManagerBuilderUseInlinerWithThreshold
parameter_list|(
name|LLVMPassManagerBuilderRef
name|PMB
parameter_list|,
name|unsigned
name|Threshold
parameter_list|)
function_decl|;
comment|/** See llvm::PassManagerBuilder::populateFunctionPassManager. */
name|void
name|LLVMPassManagerBuilderPopulateFunctionPassManager
parameter_list|(
name|LLVMPassManagerBuilderRef
name|PMB
parameter_list|,
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::PassManagerBuilder::populateModulePassManager. */
name|void
name|LLVMPassManagerBuilderPopulateModulePassManager
parameter_list|(
name|LLVMPassManagerBuilderRef
name|PMB
parameter_list|,
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** See llvm::PassManagerBuilder::populateLTOPassManager. */
name|void
name|LLVMPassManagerBuilderPopulateLTOPassManager
parameter_list|(
name|LLVMPassManagerBuilderRef
name|PMB
parameter_list|,
name|LLVMPassManagerRef
name|PM
parameter_list|,
name|bool
name|Internalize
parameter_list|,
name|bool
name|RunInliner
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_decl_stmt
name|namespace
name|llvm
block|{
specifier|inline
name|PassManagerBuilder
modifier|*
name|unwrap
parameter_list|(
name|LLVMPassManagerBuilderRef
name|P
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|PassManagerBuilder
operator|*
operator|>
operator|(
name|P
operator|)
return|;
block|}
specifier|inline
name|LLVMPassManagerBuilderRef
name|wrap
parameter_list|(
name|PassManagerBuilder
modifier|*
name|P
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|LLVMPassManagerBuilderRef
operator|>
operator|(
name|P
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

