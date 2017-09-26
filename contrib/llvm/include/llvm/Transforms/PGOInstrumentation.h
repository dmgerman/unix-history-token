begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Transforms/PGOInstrumentation.h - PGO gen/use passes  ---*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|/// This file provides the interface for IR based instrumentation passes (
end_comment

begin_comment
comment|/// (profile-gen, and profile-use).
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TRANSFORMS_PGOINSTRUMENTATION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_PGOINSTRUMENTATION_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/Instrumentation.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// The instrumentation (profile-instr-gen) pass for IR based PGO.
name|class
name|PGOInstrumentationGen
range|:
name|public
name|PassInfoMixin
operator|<
name|PGOInstrumentationGen
operator|>
block|{
name|public
operator|:
name|PreservedAnalyses
name|run
argument_list|(
name|Module
operator|&
name|M
argument_list|,
name|ModuleAnalysisManager
operator|&
name|AM
argument_list|)
block|; }
decl_stmt|;
comment|/// The profile annotation (profile-instr-use) pass for IR based PGO.
name|class
name|PGOInstrumentationUse
range|:
name|public
name|PassInfoMixin
operator|<
name|PGOInstrumentationUse
operator|>
block|{
name|public
operator|:
name|PreservedAnalyses
name|run
argument_list|(
name|Module
operator|&
name|M
argument_list|,
name|ModuleAnalysisManager
operator|&
name|AM
argument_list|)
block|;
name|PGOInstrumentationUse
argument_list|(
argument|std::string Filename =
literal|""
argument_list|)
block|;
name|private
operator|:
name|std
operator|::
name|string
name|ProfileFileName
block|; }
decl_stmt|;
comment|/// The indirect function call promotion pass.
name|class
name|PGOIndirectCallPromotion
range|:
name|public
name|PassInfoMixin
operator|<
name|PGOIndirectCallPromotion
operator|>
block|{
name|public
operator|:
name|PGOIndirectCallPromotion
argument_list|(
argument|bool IsInLTO = false
argument_list|,
argument|bool SamplePGO = false
argument_list|)
operator|:
name|InLTO
argument_list|(
name|IsInLTO
argument_list|)
block|,
name|SamplePGO
argument_list|(
argument|SamplePGO
argument_list|)
block|{}
name|PreservedAnalyses
name|run
argument_list|(
name|Module
operator|&
name|M
argument_list|,
name|ModuleAnalysisManager
operator|&
name|AM
argument_list|)
block|;
name|private
operator|:
name|bool
name|InLTO
block|;
name|bool
name|SamplePGO
block|; }
decl_stmt|;
comment|/// The profile size based optimization pass for memory intrinsics.
name|class
name|PGOMemOPSizeOpt
range|:
name|public
name|PassInfoMixin
operator|<
name|PGOMemOPSizeOpt
operator|>
block|{
name|public
operator|:
name|PGOMemOPSizeOpt
argument_list|()
block|{}
name|PreservedAnalyses
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
name|AM
argument_list|)
block|; }
decl_stmt|;
name|void
name|setProfMetadata
argument_list|(
name|Module
operator|*
name|M
argument_list|,
name|Instruction
operator|*
name|TI
argument_list|,
name|ArrayRef
operator|<
name|uint64_t
operator|>
name|EdgeCounts
argument_list|,
name|uint64_t
name|MaxCount
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

