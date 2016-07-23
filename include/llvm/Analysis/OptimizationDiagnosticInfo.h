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
name|BlockFrequencyInfo
decl_stmt|;
name|class
name|DebugLoc
decl_stmt|;
name|class
name|Function
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
name|class
name|OptimizationRemarkEmitter
block|{
name|public
label|:
name|OptimizationRemarkEmitter
argument_list|(
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
comment|/// Emit an optimization-missed message.
comment|///
comment|/// \p PassName is the name of the pass emitting the message. If
comment|/// -Rpass-missed= is given and the name matches the regular expression in
comment|/// -Rpass, then the remark will be emitted. \p Fn is the function triggering
comment|/// the remark, \p DLoc is the debug location where the diagnostic is
comment|/// generated. \p V is the IR Value that identifies the code region. \p Msg is
comment|/// the message string to use.
name|void
name|emitOptimizationRemarkMissed
parameter_list|(
specifier|const
name|char
modifier|*
name|PassName
parameter_list|,
specifier|const
name|DebugLoc
modifier|&
name|DLoc
parameter_list|,
name|Value
modifier|*
name|V
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Msg
parameter_list|)
function_decl|;
comment|/// \brief Same as above but derives the IR Value for the code region and the
comment|/// debug location from the Loop parameter \p L.
name|void
name|emitOptimizationRemarkMissed
parameter_list|(
specifier|const
name|char
modifier|*
name|PassName
parameter_list|,
name|Loop
modifier|*
name|L
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Msg
parameter_list|)
function_decl|;
name|private
label|:
name|Function
modifier|*
name|F
decl_stmt|;
name|BlockFrequencyInfo
modifier|*
name|BFI
decl_stmt|;
name|Optional
operator|<
name|uint64_t
operator|>
name|computeHotness
argument_list|(
name|Value
operator|*
name|V
argument_list|)
expr_stmt|;
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
name|char
name|PassID
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
name|AnalysisManager
operator|<
name|Function
operator|>
operator|&
name|AM
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_OPTIMIZATIONDIAGNOSTICINFO_H
end_comment

end_unit

