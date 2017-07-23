begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///===- MachineOptimizationRemarkEmitter.h - Opt Diagnostics -*- C++ -*----===//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|/// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///===---------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// Optimization diagnostic interfaces for machine passes.  It's packaged as an
end_comment

begin_comment
comment|/// analysis pass so that by using this service passes become dependent on MBFI
end_comment

begin_comment
comment|/// as well.  MBFI is used to compute the "hotness" of the diagnostic message.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///===---------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CODEGEN_MACHINEOPTIMIZATIONREMARKEMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINEOPTIMIZATIONREMARKEMITTER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/OptimizationDiagnosticInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineBlockFrequencyInfo
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
comment|/// \brief Common features for diagnostics dealing with optimization remarks
comment|/// that are used by machine passes.
name|class
name|DiagnosticInfoMIROptimization
range|:
name|public
name|DiagnosticInfoOptimizationBase
block|{
name|public
operator|:
name|DiagnosticInfoMIROptimization
argument_list|(
argument|enum DiagnosticKind Kind
argument_list|,
argument|const char *PassName
argument_list|,
argument|StringRef RemarkName
argument_list|,
argument|const DiagnosticLocation&Loc
argument_list|,
argument|const MachineBasicBlock *MBB
argument_list|)
operator|:
name|DiagnosticInfoOptimizationBase
argument_list|(
name|Kind
argument_list|,
name|DS_Remark
argument_list|,
name|PassName
argument_list|,
name|RemarkName
argument_list|,
operator|*
name|MBB
operator|->
name|getParent
argument_list|()
operator|->
name|getFunction
argument_list|()
argument_list|,
name|Loc
argument_list|)
block|,
name|MBB
argument_list|(
argument|MBB
argument_list|)
block|{}
comment|/// MI-specific kinds of diagnostic Arguments.
expr|struct
name|MachineArgument
operator|:
name|public
name|DiagnosticInfoOptimizationBase
operator|::
name|Argument
block|{
comment|/// Print an entire MachineInstr.
name|MachineArgument
argument_list|(
argument|StringRef Key
argument_list|,
argument|const MachineInstr&MI
argument_list|)
block|;   }
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const DiagnosticInfo *DI
argument_list|)
block|{
return|return
name|DI
operator|->
name|getKind
argument_list|()
operator|>=
name|DK_FirstMachineRemark
operator|&&
name|DI
operator|->
name|getKind
argument_list|()
operator|<=
name|DK_LastMachineRemark
return|;
block|}
specifier|const
name|MachineBasicBlock
operator|*
name|getBlock
argument_list|()
specifier|const
block|{
return|return
name|MBB
return|;
block|}
name|private
operator|:
specifier|const
name|MachineBasicBlock
operator|*
name|MBB
block|; }
decl_stmt|;
comment|/// Diagnostic information for applied optimization remarks.
name|class
name|MachineOptimizationRemark
range|:
name|public
name|DiagnosticInfoMIROptimization
block|{
name|public
operator|:
comment|/// \p PassName is the name of the pass emitting this diagnostic. If this name
comment|/// matches the regular expression given in -Rpass=, then the diagnostic will
comment|/// be emitted.  \p RemarkName is a textual identifier for the remark.  \p
comment|/// Loc is the debug location and \p MBB is the block that the optimization
comment|/// operates in.
name|MachineOptimizationRemark
argument_list|(
argument|const char *PassName
argument_list|,
argument|StringRef RemarkName
argument_list|,
argument|const DiagnosticLocation&Loc
argument_list|,
argument|const MachineBasicBlock *MBB
argument_list|)
operator|:
name|DiagnosticInfoMIROptimization
argument_list|(
argument|DK_MachineOptimizationRemark
argument_list|,
argument|PassName
argument_list|,
argument|RemarkName
argument_list|,
argument|Loc
argument_list|,
argument|MBB
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const DiagnosticInfo *DI
argument_list|)
block|{
return|return
name|DI
operator|->
name|getKind
argument_list|()
operator|==
name|DK_MachineOptimizationRemark
return|;
block|}
comment|/// \see DiagnosticInfoOptimizationBase::isEnabled.
name|bool
name|isEnabled
argument_list|()
specifier|const
name|override
block|{
return|return
name|OptimizationRemark
operator|::
name|isEnabled
argument_list|(
name|getPassName
argument_list|()
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// Diagnostic information for missed-optimization remarks.
name|class
name|MachineOptimizationRemarkMissed
operator|:
name|public
name|DiagnosticInfoMIROptimization
block|{
name|public
operator|:
comment|/// \p PassName is the name of the pass emitting this diagnostic. If this name
comment|/// matches the regular expression given in -Rpass-missed=, then the
comment|/// diagnostic will be emitted.  \p RemarkName is a textual identifier for the
comment|/// remark.  \p Loc is the debug location and \p MBB is the block that the
comment|/// optimization operates in.
name|MachineOptimizationRemarkMissed
argument_list|(
argument|const char *PassName
argument_list|,
argument|StringRef RemarkName
argument_list|,
argument|const DiagnosticLocation&Loc
argument_list|,
argument|const MachineBasicBlock *MBB
argument_list|)
operator|:
name|DiagnosticInfoMIROptimization
argument_list|(
argument|DK_MachineOptimizationRemarkMissed
argument_list|,
argument|PassName
argument_list|,
argument|RemarkName
argument_list|,
argument|Loc
argument_list|,
argument|MBB
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const DiagnosticInfo *DI
argument_list|)
block|{
return|return
name|DI
operator|->
name|getKind
argument_list|()
operator|==
name|DK_MachineOptimizationRemarkMissed
return|;
block|}
comment|/// \see DiagnosticInfoOptimizationBase::isEnabled.
name|bool
name|isEnabled
argument_list|()
specifier|const
name|override
block|{
return|return
name|OptimizationRemarkMissed
operator|::
name|isEnabled
argument_list|(
name|getPassName
argument_list|()
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// Diagnostic information for optimization analysis remarks.
name|class
name|MachineOptimizationRemarkAnalysis
operator|:
name|public
name|DiagnosticInfoMIROptimization
block|{
name|public
operator|:
comment|/// \p PassName is the name of the pass emitting this diagnostic. If this name
comment|/// matches the regular expression given in -Rpass-analysis=, then the
comment|/// diagnostic will be emitted.  \p RemarkName is a textual identifier for the
comment|/// remark.  \p Loc is the debug location and \p MBB is the block that the
comment|/// optimization operates in.
name|MachineOptimizationRemarkAnalysis
argument_list|(
argument|const char *PassName
argument_list|,
argument|StringRef RemarkName
argument_list|,
argument|const DiagnosticLocation&Loc
argument_list|,
argument|const MachineBasicBlock *MBB
argument_list|)
operator|:
name|DiagnosticInfoMIROptimization
argument_list|(
argument|DK_MachineOptimizationRemarkAnalysis
argument_list|,
argument|PassName
argument_list|,
argument|RemarkName
argument_list|,
argument|Loc
argument_list|,
argument|MBB
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const DiagnosticInfo *DI
argument_list|)
block|{
return|return
name|DI
operator|->
name|getKind
argument_list|()
operator|==
name|DK_MachineOptimizationRemarkAnalysis
return|;
block|}
comment|/// \see DiagnosticInfoOptimizationBase::isEnabled.
name|bool
name|isEnabled
argument_list|()
specifier|const
name|override
block|{
return|return
name|OptimizationRemarkAnalysis
operator|::
name|isEnabled
argument_list|(
name|getPassName
argument_list|()
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// Extend llvm::ore:: with MI-specific helper names.
name|namespace
name|ore
block|{
name|using
name|MNV
operator|=
name|DiagnosticInfoMIROptimization
operator|::
name|MachineArgument
block|; }
comment|/// The optimization diagnostic interface.
comment|///
comment|/// It allows reporting when optimizations are performed and when they are not
comment|/// along with the reasons for it.  Hotness information of the corresponding
comment|/// code region can be included in the remark if DiagnosticsHotnessRequested is
comment|/// enabled in the LLVM context.
name|class
name|MachineOptimizationRemarkEmitter
block|{
name|public
operator|:
name|MachineOptimizationRemarkEmitter
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|,
name|MachineBlockFrequencyInfo
operator|*
name|MBFI
argument_list|)
operator|:
name|MF
argument_list|(
name|MF
argument_list|)
block|,
name|MBFI
argument_list|(
argument|MBFI
argument_list|)
block|{}
comment|/// Emit an optimization remark.
name|void
name|emit
argument_list|(
name|DiagnosticInfoOptimizationBase
operator|&
name|OptDiag
argument_list|)
block|;
comment|/// \brief Whether we allow for extra compile-time budget to perform more
comment|/// analysis to be more informative.
comment|///
comment|/// This is useful to enable additional missed optimizations to be reported
comment|/// that are normally too noisy.  In this mode, we can use the extra analysis
comment|/// (1) to filter trivial false positives or (2) to provide more context so
comment|/// that non-trivial false positives can be quickly detected by the user.
name|bool
name|allowExtraAnalysis
argument_list|()
specifier|const
block|{
comment|// For now, only allow this with -fsave-optimization-record since the -Rpass
comment|// options are handled in the front-end.
return|return
name|MF
operator|.
name|getFunction
argument_list|()
operator|->
name|getContext
argument_list|()
operator|.
name|getDiagnosticsOutputFile
argument_list|()
return|;
block|}
name|private
operator|:
name|MachineFunction
operator|&
name|MF
block|;
comment|/// MBFI is only set if hotness is requested.
name|MachineBlockFrequencyInfo
operator|*
name|MBFI
block|;
comment|/// Compute hotness from IR value (currently assumed to be a block) if PGO is
comment|/// available.
name|Optional
operator|<
name|uint64_t
operator|>
name|computeHotness
argument_list|(
specifier|const
name|MachineBasicBlock
operator|&
name|MBB
argument_list|)
block|;
comment|/// Similar but use value from \p OptDiag and update hotness there.
name|void
name|computeHotness
argument_list|(
name|DiagnosticInfoMIROptimization
operator|&
name|Remark
argument_list|)
block|;
comment|/// \brief Only allow verbose messages if we know we're filtering by hotness
comment|/// (BFI is only set in this case).
name|bool
name|shouldEmitVerbose
argument_list|()
block|{
return|return
name|MBFI
operator|!=
name|nullptr
return|;
block|}
expr|}
block|;
comment|/// The analysis pass
comment|///
comment|/// Note that this pass shouldn't generally be marked as preserved by other
comment|/// passes.  It's holding onto BFI, so if the pass does not preserve BFI, BFI
comment|/// could be freed.
name|class
name|MachineOptimizationRemarkEmitterPass
operator|:
name|public
name|MachineFunctionPass
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|MachineOptimizationRemarkEmitter
operator|>
name|ORE
block|;
name|public
operator|:
name|MachineOptimizationRemarkEmitterPass
argument_list|()
block|;
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&MF
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
name|MachineOptimizationRemarkEmitter
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
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

