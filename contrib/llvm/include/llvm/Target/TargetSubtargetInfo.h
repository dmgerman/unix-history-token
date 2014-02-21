begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- llvm/Target/TargetSubtargetInfo.h - Target Information ----*- C++ -*-==//
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
comment|// This file describes the subtarget options of a Target machine.
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
name|LLVM_TARGET_TARGETSUBTARGETINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETSUBTARGETINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCSubtargetInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CodeGen.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|SDep
decl_stmt|;
name|class
name|SUnit
decl_stmt|;
name|class
name|TargetRegisterClass
decl_stmt|;
name|class
name|TargetSchedModel
decl_stmt|;
struct_decl|struct
name|MachineSchedPolicy
struct_decl|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|///
comment|/// TargetSubtargetInfo - Generic base class for all target subtargets.  All
comment|/// Target-specific options that control code generation and printing should
comment|/// be exposed through a TargetSubtargetInfo-derived class.
comment|///
name|class
name|TargetSubtargetInfo
range|:
name|public
name|MCSubtargetInfo
block|{
name|TargetSubtargetInfo
argument_list|(
argument|const TargetSubtargetInfo&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|TargetSubtargetInfo
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
block|;
name|protected
operator|:
comment|// Can only create subclasses...
name|TargetSubtargetInfo
argument_list|()
block|;
name|public
operator|:
comment|// AntiDepBreakMode - Type of anti-dependence breaking that should
comment|// be performed before post-RA scheduling.
typedef|typedef
enum|enum
block|{
name|ANTIDEP_NONE
block|,
name|ANTIDEP_CRITICAL
block|,
name|ANTIDEP_ALL
decl|}
name|AntiDepBreakMode
empty_stmt|;
typedef|typedef
name|SmallVectorImpl
operator|<
specifier|const
name|TargetRegisterClass
operator|*
operator|>
name|RegClassVector
expr_stmt|;
name|virtual
decl|~
name|TargetSubtargetInfo
argument_list|()
empty_stmt|;
comment|/// Resolve a SchedClass at runtime, where SchedClass identifies an
comment|/// MCSchedClassDesc with the isVariant property. This may return the ID of
comment|/// another variant SchedClass, but repeated invocation must quickly terminate
comment|/// in a nonvariant SchedClass.
name|virtual
name|unsigned
name|resolveSchedClass
block|(
name|unsigned
name|SchedClass
block|, const
name|MachineInstr
modifier|*
name|MI
block|,
specifier|const
name|TargetSchedModel
operator|*
name|SchedModel
block|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// \brief Temporary API to test migration to MI scheduler.
name|bool
name|useMachineScheduler
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief True if the subtarget should run MachineScheduler after aggressive
comment|/// coalescing.
comment|///
comment|/// This currently replaces the SelectionDAG scheduler with the "source" order
comment|/// scheduler. It does not yet disable the postRA scheduler.
name|virtual
name|bool
name|enableMachineScheduler
argument_list|()
specifier|const
decl_stmt|;
comment|/// \brief Override generic scheduling policy within a region.
comment|///
comment|/// This is a convenient way for targets that don't provide any custom
comment|/// scheduling heuristics (no custom MachineSchedStrategy) to make
comment|/// changes to the generic scheduling policy.
name|virtual
name|void
name|overrideSchedPolicy
argument_list|(
name|MachineSchedPolicy
operator|&
name|Policy
argument_list|,
name|MachineInstr
operator|*
name|begin
argument_list|,
name|MachineInstr
operator|*
name|end
argument_list|,
name|unsigned
name|NumRegionInstrs
argument_list|)
decl|const
block|{}
comment|// enablePostRAScheduler - If the target can benefit from post-regalloc
comment|// scheduling and the specified optimization level meets the requirement
comment|// return true to enable post-register-allocation scheduling. In
comment|// CriticalPathRCs return any register classes that should only be broken
comment|// if on the critical path.
name|virtual
name|bool
name|enablePostRAScheduler
argument_list|(
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
argument_list|,
name|AntiDepBreakMode
operator|&
name|Mode
argument_list|,
name|RegClassVector
operator|&
name|CriticalPathRCs
argument_list|)
decl|const
decl_stmt|;
comment|// adjustSchedDependency - Perform target specific adjustments to
comment|// the latency of a schedule dependency.
name|virtual
name|void
name|adjustSchedDependency
argument_list|(
name|SUnit
operator|*
name|def
argument_list|,
name|SUnit
operator|*
name|use
argument_list|,
name|SDep
operator|&
name|dep
argument_list|)
decl|const
block|{ }
comment|/// \brief Enable use of alias analysis during code generation (during MI
comment|/// scheduling, DAGCombine, etc.).
name|virtual
name|bool
name|useAA
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Reset the features for the subtarget.
name|virtual
name|void
name|resetSubtargetFeatures
parameter_list|(
specifier|const
name|MachineFunction
modifier|*
name|MF
parameter_list|)
block|{ }
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

