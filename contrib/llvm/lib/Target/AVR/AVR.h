begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AVR.h - Top-level interface for AVR representation ------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file contains the entry points for global functions defined in the LLVM
end_comment

begin_comment
comment|// AVR back-end.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_AVR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_AVR_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAGNodes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AVRTargetMachine
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|FunctionPass
modifier|*
name|createAVRISelDag
argument_list|(
name|AVRTargetMachine
operator|&
name|TM
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
argument_list|)
decl_stmt|;
name|FunctionPass
modifier|*
name|createAVRExpandPseudoPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createAVRFrameAnalyzerPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createAVRInstrumentFunctionsPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createAVRRelaxMemPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createAVRDynAllocaSRPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createAVRBranchSelectionPass
parameter_list|()
function_decl|;
name|void
name|initializeAVRExpandPseudoPass
parameter_list|(
name|PassRegistry
modifier|&
parameter_list|)
function_decl|;
name|void
name|initializeAVRInstrumentFunctionsPass
parameter_list|(
name|PassRegistry
modifier|&
parameter_list|)
function_decl|;
name|void
name|initializeAVRRelaxMemPass
parameter_list|(
name|PassRegistry
modifier|&
parameter_list|)
function_decl|;
comment|/// Contains the AVR backend.
name|namespace
name|AVR
block|{
enum|enum
name|AddressSpace
block|{
name|DataMemory
block|,
name|ProgramMemory
block|}
enum|;
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|isProgramMemoryAddress
argument_list|(
argument|T *V
argument_list|)
block|{
return|return
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|V
operator|->
name|getType
argument_list|()
operator|)
operator|->
name|getAddressSpace
argument_list|()
operator|==
name|ProgramMemory
return|;
block|}
specifier|inline
name|bool
name|isProgramMemoryAccess
parameter_list|(
name|MemSDNode
specifier|const
modifier|*
name|N
parameter_list|)
block|{
name|auto
name|V
init|=
name|N
operator|->
name|getMemOperand
argument_list|()
operator|->
name|getValue
argument_list|()
decl_stmt|;
return|return
operator|(
name|V
operator|!=
name|nullptr
operator|)
condition|?
name|isProgramMemoryAddress
argument_list|(
name|V
argument_list|)
else|:
name|false
return|;
block|}
block|}
comment|// end of namespace AVR
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_AVR_H
end_comment

end_unit

