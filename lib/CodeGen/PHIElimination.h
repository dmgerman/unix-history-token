begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lib/CodeGen/PHIElimination.h ----------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CODEGEN_PHIELIMINATION_HPP
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_PHIELIMINATION_HPP
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Lower PHI instructions to copies.
name|class
name|PHIElimination
range|:
name|public
name|MachineFunctionPass
block|{
name|MachineRegisterInfo
operator|*
name|MRI
block|;
comment|// Machine register information
name|private
operator|:
typedef|typedef
name|SmallSet
operator|<
name|MachineBasicBlock
operator|*
operator|,
literal|4
operator|>
name|PHIKillList
expr_stmt|;
typedef|typedef
name|DenseMap
operator|<
name|unsigned
operator|,
name|PHIKillList
operator|>
name|PHIKillMap
expr_stmt|;
typedef|typedef
name|DenseMap
operator|<
name|unsigned
operator|,
name|MachineBasicBlock
operator|*
operator|>
name|PHIDefMap
expr_stmt|;
name|public
label|:
typedef|typedef
name|PHIKillList
operator|::
name|iterator
name|phi_kill_iterator
expr_stmt|;
typedef|typedef
name|PHIKillList
operator|::
name|const_iterator
name|const_phi_kill_iterator
expr_stmt|;
specifier|static
name|char
name|ID
decl_stmt|;
comment|// Pass identification, replacement for typeid
name|PHIElimination
argument_list|()
operator|:
name|MachineFunctionPass
argument_list|(
argument|&ID
argument_list|)
block|{}
name|virtual
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
name|Fn
argument_list|)
expr_stmt|;
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
name|AU
argument_list|)
decl|const
decl_stmt|;
comment|/// Return true if the given vreg was defined by a PHI intsr prior to
comment|/// lowering.
name|bool
name|hasPHIDef
argument_list|(
name|unsigned
name|vreg
argument_list|)
decl|const
block|{
return|return
name|PHIDefs
operator|.
name|count
argument_list|(
name|vreg
argument_list|)
return|;
block|}
comment|/// Returns the block in which the PHI instruction which defined the
comment|/// given vreg used to reside.
name|MachineBasicBlock
modifier|*
name|getPHIDefBlock
parameter_list|(
name|unsigned
name|vreg
parameter_list|)
block|{
name|PHIDefMap
operator|::
name|iterator
name|phiDefItr
operator|=
name|PHIDefs
operator|.
name|find
argument_list|(
name|vreg
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|phiDefItr
operator|!=
name|PHIDefs
operator|.
name|end
argument_list|()
operator|&&
literal|"vreg has no phi-def."
argument_list|)
expr_stmt|;
return|return
name|phiDefItr
operator|->
name|second
return|;
block|}
comment|/// Returns true if the given vreg was killed by a PHI instr.
name|bool
name|hasPHIKills
argument_list|(
name|unsigned
name|vreg
argument_list|)
decl|const
block|{
return|return
name|PHIKills
operator|.
name|count
argument_list|(
name|vreg
argument_list|)
return|;
block|}
comment|/// Returns an iterator over the BasicBlocks which contained PHI
comment|/// kills of this register prior to lowering.
name|phi_kill_iterator
name|phiKillsBegin
parameter_list|(
name|unsigned
name|vreg
parameter_list|)
block|{
name|PHIKillMap
operator|::
name|iterator
name|phiKillItr
operator|=
name|PHIKills
operator|.
name|find
argument_list|(
name|vreg
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|phiKillItr
operator|!=
name|PHIKills
operator|.
name|end
argument_list|()
operator|&&
literal|"vreg has no phi-kills."
argument_list|)
expr_stmt|;
return|return
name|phiKillItr
operator|->
name|second
operator|.
name|begin
argument_list|()
return|;
block|}
name|phi_kill_iterator
name|phiKillsEnd
parameter_list|(
name|unsigned
name|vreg
parameter_list|)
block|{
name|PHIKillMap
operator|::
name|iterator
name|phiKillItr
operator|=
name|PHIKills
operator|.
name|find
argument_list|(
name|vreg
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|phiKillItr
operator|!=
name|PHIKills
operator|.
name|end
argument_list|()
operator|&&
literal|"vreg has no phi-kills."
argument_list|)
expr_stmt|;
return|return
name|phiKillItr
operator|->
name|second
operator|.
name|end
argument_list|()
return|;
block|}
name|private
label|:
comment|/// EliminatePHINodes - Eliminate phi nodes by inserting copy instructions
comment|/// in predecessor basic blocks.
comment|///
name|bool
name|EliminatePHINodes
parameter_list|(
name|MachineFunction
modifier|&
name|MF
parameter_list|,
name|MachineBasicBlock
modifier|&
name|MBB
parameter_list|)
function_decl|;
name|void
name|LowerAtomicPHINode
argument_list|(
name|MachineBasicBlock
operator|&
name|MBB
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|AfterPHIsIt
argument_list|)
decl_stmt|;
comment|/// analyzePHINodes - Gather information about the PHI nodes in
comment|/// here. In particular, we want to map the number of uses of a virtual
comment|/// register which is used in a PHI node. We map that to the BB the
comment|/// vreg is coming from. This is used later to determine when the vreg
comment|/// is killed in the BB.
comment|///
name|void
name|analyzePHINodes
parameter_list|(
specifier|const
name|MachineFunction
modifier|&
name|Fn
parameter_list|)
function_decl|;
comment|/// Split critical edges where necessary for good coalescer performance.
name|bool
name|SplitPHIEdges
parameter_list|(
name|MachineFunction
modifier|&
name|MF
parameter_list|,
name|MachineBasicBlock
modifier|&
name|MBB
parameter_list|,
name|LiveVariables
modifier|&
name|LV
parameter_list|)
function_decl|;
comment|/// isLiveOut - Determine if Reg is live out from MBB, when not
comment|/// considering PHI nodes. This means that Reg is either killed by
comment|/// a successor block or passed through one.
name|bool
name|isLiveOut
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
specifier|const
name|MachineBasicBlock
modifier|&
name|MBB
parameter_list|,
name|LiveVariables
modifier|&
name|LV
parameter_list|)
function_decl|;
comment|/// SplitCriticalEdge - Split a critical edge from A to B by
comment|/// inserting a new MBB. Update branches in A and PHI instructions
comment|/// in B. Return the new block.
name|MachineBasicBlock
modifier|*
name|SplitCriticalEdge
parameter_list|(
name|MachineBasicBlock
modifier|*
name|A
parameter_list|,
name|MachineBasicBlock
modifier|*
name|B
parameter_list|)
function_decl|;
comment|/// FindCopyInsertPoint - Find a safe place in MBB to insert a copy from
comment|/// SrcReg when following the CFG edge to SuccMBB. This needs to be after
comment|/// any def of SrcReg, but before any subsequent point where control flow
comment|/// might jump out of the basic block.
name|MachineBasicBlock
operator|::
name|iterator
name|FindCopyInsertPoint
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock&SuccMBB
argument_list|,
argument|unsigned SrcReg
argument_list|)
expr_stmt|;
comment|// SkipPHIsAndLabels - Copies need to be inserted after phi nodes and
comment|// also after any exception handling labels: in landing pads execution
comment|// starts at the label, so any copies placed before it won't be executed!
name|MachineBasicBlock
operator|::
name|iterator
name|SkipPHIsAndLabels
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator I
argument_list|)
block|{
comment|// Rather than assuming that EH labels come before other kinds of labels,
comment|// just skip all labels.
while|while
condition|(
name|I
operator|!=
name|MBB
operator|.
name|end
argument_list|()
operator|&&
operator|(
name|I
operator|->
name|getOpcode
argument_list|()
operator|==
name|TargetInstrInfo
operator|::
name|PHI
operator|||
name|I
operator|->
name|isLabel
argument_list|()
operator|)
condition|)
operator|++
name|I
expr_stmt|;
return|return
name|I
return|;
block|}
end_decl_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|pair
operator|<
specifier|const
name|MachineBasicBlock
operator|*
operator|,
name|unsigned
operator|>
name|BBVRegPair
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|map
operator|<
name|BBVRegPair
operator|,
name|unsigned
operator|>
name|VRegPHIUse
expr_stmt|;
end_typedef

begin_decl_stmt
name|VRegPHIUse
name|VRegPHIUseCount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PHIDefMap
name|PHIDefs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PHIKillMap
name|PHIKills
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Defs of PHI sources which are implicit_def.
end_comment

begin_expr_stmt
name|SmallPtrSet
operator|<
name|MachineInstr
operator|*
operator|,
literal|4
operator|>
name|ImpDefs
expr_stmt|;
end_expr_stmt

begin_endif
unit|};  }
endif|#
directive|endif
end_endif

begin_comment
comment|/* LLVM_CODEGEN_PHIELIMINATION_HPP */
end_comment

end_unit

