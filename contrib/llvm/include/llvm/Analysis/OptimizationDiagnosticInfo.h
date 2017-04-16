begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- OptimizationDiagnosticInfo.h - Optimization Diagnostic ---*- C++ -*-===//
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
comment|// Optimization diagnostic interfaces.  It's packaged as an analysis pass so
end_comment

begin_comment
comment|// that by using this service passes become dependent on BFI as well.  BFI is
end_comment

begin_comment
comment|// used to compute the "hotness" of the diagnostic message.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_IR_OPTIMIZATIONDIAGNOSTICINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_OPTIMIZATIONDIAGNOSTICINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/BlockFrequencyInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DiagnosticInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DebugLoc
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|Loop
decl_stmt|;
name|class
name|Pass
decl_stmt|;
name|class
name|Twine
decl_stmt|;
name|class
name|Value
decl_stmt|;
comment|/// The optimization diagnostic interface.
comment|///
comment|/// It allows reporting when optimizations are performed and when they are not
comment|/// along with the reasons for it.  Hotness information of the corresponding
comment|/// code region can be included in the remark if DiagnosticHotnessRequested is
comment|/// enabled in the LLVM context.
name|class
name|OptimizationRemarkEmitter
block|{
name|public
label|:
name|OptimizationRemarkEmitter
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|,
name|BlockFrequencyInfo
operator|*
name|BFI
argument_list|)
operator|:
name|F
argument_list|(
name|F
argument_list|)
operator|,
name|BFI
argument_list|(
argument|BFI
argument_list|)
block|{}
comment|/// \brief This variant can be used to generate ORE on demand (without the
comment|/// analysis pass).
comment|///
comment|/// Note that this ctor has a very different cost depending on whether
comment|/// F->getContext().getDiagnosticHotnessRequested() is on or not.  If it's off
comment|/// the operation is free.
comment|///
comment|/// Whereas if DiagnosticHotnessRequested is on, it is fairly expensive
comment|/// operation since BFI and all its required analyses are computed.  This is
comment|/// for example useful for CGSCC passes that can't use function analyses
comment|/// passes in the old PM.
name|OptimizationRemarkEmitter
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|)
expr_stmt|;
name|OptimizationRemarkEmitter
argument_list|(
name|OptimizationRemarkEmitter
operator|&&
name|Arg
argument_list|)
operator|:
name|F
argument_list|(
name|Arg
operator|.
name|F
argument_list|)
operator|,
name|BFI
argument_list|(
argument|Arg.BFI
argument_list|)
block|{}
name|OptimizationRemarkEmitter
operator|&
name|operator
operator|=
operator|(
name|OptimizationRemarkEmitter
operator|&&
name|RHS
operator|)
block|{
name|F
operator|=
name|RHS
operator|.
name|F
block|;
name|BFI
operator|=
name|RHS
operator|.
name|BFI
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// Handle invalidation events in the new pass manager.
name|bool
name|invalidate
argument_list|(
name|Function
operator|&
name|F
argument_list|,
specifier|const
name|PreservedAnalyses
operator|&
name|PA
argument_list|,
name|FunctionAnalysisManager
operator|::
name|Invalidator
operator|&
name|Inv
argument_list|)
decl_stmt|;
comment|/// \brief Output the remark via the diagnostic handler and to the
comment|/// optimization record file.
comment|///
comment|/// This is the new interface that should be now used rather than the legacy
comment|/// emit* APIs.
name|void
name|emit
parameter_list|(
name|DiagnosticInfoOptimizationBase
modifier|&
name|OptDiag
parameter_list|)
function_decl|;
comment|/// \brief Whether we allow for extra compile-time budget to perform more
comment|/// analysis to produce fewer false positives.
comment|///
comment|/// This is useful when reporting missed optimizations.  In this case we can
comment|/// use the extra analysis (1) to filter trivial false positives or (2) to
comment|/// provide more context so that non-trivial false positives can be quickly
comment|/// detected by the user.
name|bool
name|allowExtraAnalysis
argument_list|()
specifier|const
block|{
comment|// For now, only allow this with -fsave-optimization-record since the -Rpass
comment|// options are handled in the front-end.
return|return
name|F
operator|->
name|getContext
argument_list|()
operator|.
name|getDiagnosticsOutputFile
argument_list|()
return|;
block|}
name|private
label|:
specifier|const
name|Function
modifier|*
name|F
decl_stmt|;
name|BlockFrequencyInfo
modifier|*
name|BFI
decl_stmt|;
comment|/// If we generate BFI on demand, we need to free it when ORE is freed.
name|std
operator|::
name|unique_ptr
operator|<
name|BlockFrequencyInfo
operator|>
name|OwnedBFI
expr_stmt|;
comment|/// Compute hotness from IR value (currently assumed to be a block) if PGO is
comment|/// available.
name|Optional
operator|<
name|uint64_t
operator|>
name|computeHotness
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|)
expr_stmt|;
comment|/// Similar but use value from \p OptDiag and update hotness there.
name|void
name|computeHotness
parameter_list|(
name|DiagnosticInfoIROptimization
modifier|&
name|OptDiag
parameter_list|)
function_decl|;
comment|/// \brief Only allow verbose messages if we know we're filtering by hotness
comment|/// (BFI is only set in this case).
name|bool
name|shouldEmitVerbose
parameter_list|()
block|{
return|return
name|BFI
operator|!=
name|nullptr
return|;
block|}
name|OptimizationRemarkEmitter
argument_list|(
specifier|const
name|OptimizationRemarkEmitter
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|OptimizationRemarkEmitter
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief Add a small namespace to avoid name clashes with the classes used in
comment|/// the streaming interface.  We want these to be short for better
comment|/// write/readability.
name|namespace
name|ore
block|{
name|using
name|NV
init|=
name|DiagnosticInfoOptimizationBase
operator|::
name|Argument
decl_stmt|;
name|using
name|setIsVerbose
init|=
name|DiagnosticInfoOptimizationBase
operator|::
name|setIsVerbose
decl_stmt|;
name|using
name|setExtraArgs
init|=
name|DiagnosticInfoOptimizationBase
operator|::
name|setExtraArgs
decl_stmt|;
block|}
comment|/// OptimizationRemarkEmitter legacy analysis pass
comment|///
comment|/// Note that this pass shouldn't generally be marked as preserved by other
comment|/// passes.  It's holding onto BFI, so if the pass does not preserve BFI, BFI
comment|/// could be freed.
name|class
name|OptimizationRemarkEmitterWrapperPass
range|:
name|public
name|FunctionPass
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|OptimizationRemarkEmitter
operator|>
name|ORE
block|;
name|public
operator|:
name|OptimizationRemarkEmitterWrapperPass
argument_list|()
block|;
name|bool
name|runOnFunction
argument_list|(
argument|Function&F
argument_list|)
name|override
block|;
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|;
name|OptimizationRemarkEmitter
operator|&
name|getORE
argument_list|()
block|{
name|assert
argument_list|(
name|ORE
operator|&&
literal|"pass not run yet"
argument_list|)
block|;
return|return
operator|*
name|ORE
return|;
block|}
specifier|static
name|char
name|ID
block|; }
decl_stmt|;
name|class
name|OptimizationRemarkEmitterAnalysis
range|:
name|public
name|AnalysisInfoMixin
operator|<
name|OptimizationRemarkEmitterAnalysis
operator|>
block|{
name|friend
name|AnalysisInfoMixin
operator|<
name|OptimizationRemarkEmitterAnalysis
operator|>
block|;
specifier|static
name|AnalysisKey
name|Key
block|;
name|public
operator|:
comment|/// \brief Provide the result typedef for this analysis pass.
typedef|typedef
name|OptimizationRemarkEmitter
name|Result
typedef|;
comment|/// \brief Run the analysis pass over a function and produce BFI.
name|Result
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
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|namespace
name|yaml
block|{
name|template
operator|<
operator|>
expr|struct
name|MappingTraits
operator|<
name|DiagnosticInfoOptimizationBase
operator|*
operator|>
block|{
specifier|static
name|void
name|mapping
argument_list|(
name|IO
operator|&
name|io
argument_list|,
name|DiagnosticInfoOptimizationBase
operator|*
operator|&
name|OptDiag
argument_list|)
block|; }
expr_stmt|;
block|}
end_decl_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_OPTIMIZATIONDIAGNOSTICINFO_H
end_comment

end_unit

