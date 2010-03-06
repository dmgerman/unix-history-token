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
file|"llvm/CodeGen/MachineRegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LiveVariables
decl_stmt|;
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
name|public
operator|:
specifier|static
name|char
name|ID
block|;
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
block|;
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
block|;
name|private
operator|:
comment|/// EliminatePHINodes - Eliminate phi nodes by inserting copy instructions
comment|/// in predecessor basic blocks.
comment|///
name|bool
name|EliminatePHINodes
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|,
name|MachineBasicBlock
operator|&
name|MBB
argument_list|)
block|;
name|void
name|LowerAtomicPHINode
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|MachineBasicBlock::iterator AfterPHIsIt
argument_list|)
block|;
comment|/// analyzePHINodes - Gather information about the PHI nodes in
comment|/// here. In particular, we want to map the number of uses of a virtual
comment|/// register which is used in a PHI node. We map that to the BB the
comment|/// vreg is coming from. This is used later to determine when the vreg
comment|/// is killed in the BB.
comment|///
name|void
name|analyzePHINodes
argument_list|(
specifier|const
name|MachineFunction
operator|&
name|Fn
argument_list|)
block|;
comment|/// Split critical edges where necessary for good coalescer performance.
name|bool
name|SplitPHIEdges
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|,
name|MachineBasicBlock
operator|&
name|MBB
argument_list|,
name|LiveVariables
operator|&
name|LV
argument_list|)
block|;
comment|/// SplitCriticalEdge - Split a critical edge from A to B by
comment|/// inserting a new MBB. Update branches in A and PHI instructions
comment|/// in B. Return the new block.
name|MachineBasicBlock
operator|*
name|SplitCriticalEdge
argument_list|(
name|MachineBasicBlock
operator|*
name|A
argument_list|,
name|MachineBasicBlock
operator|*
name|B
argument_list|)
block|;
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
block|;
comment|// SkipPHIsAndLabels - Copies need to be inserted after phi nodes and
comment|// also after any exception handling labels: in landing pads execution
comment|// starts at the label, so any copies placed before it won't be executed!
comment|// We also deal with DBG_VALUEs, which are a bit tricky:
comment|//  PHI
comment|//  DBG_VALUE
comment|//  LABEL
comment|// Here the DBG_VALUE needs to be skipped, and if it refers to a PHI it
comment|// needs to be annulled or, better, moved to follow the label, as well.
comment|//  PHI
comment|//  DBG_VALUE
comment|//  no label
comment|// Here it is not a good idea to skip the DBG_VALUE.
comment|// FIXME: For now we skip and annul all DBG_VALUEs, maximally simple and
comment|// maximally stupid.
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
name|isPHI
argument_list|()
operator|||
name|I
operator|->
name|isLabel
argument_list|()
operator|||
name|I
operator|->
name|isDebugValue
argument_list|()
operator|)
condition|)
block|{
if|if
condition|(
name|I
operator|->
name|isDebugValue
argument_list|()
operator|&&
name|I
operator|->
name|getNumOperands
argument_list|()
operator|==
literal|3
operator|&&
name|I
operator|->
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|.
name|isReg
argument_list|()
condition|)
name|I
operator|->
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|.
name|setReg
argument_list|(
literal|0U
argument_list|)
expr_stmt|;
operator|++
name|I
expr_stmt|;
block|}
return|return
name|I
return|;
block|}
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
name|BBVRegPair
expr_stmt|;
typedef|typedef
name|DenseMap
operator|<
name|BBVRegPair
operator|,
name|unsigned
operator|>
name|VRegPHIUse
expr_stmt|;
name|VRegPHIUse
name|VRegPHIUseCount
decl_stmt|;
comment|// Defs of PHI sources which are implicit_def.
name|SmallPtrSet
operator|<
name|MachineInstr
operator|*
operator|,
literal|4
operator|>
name|ImpDefs
expr_stmt|;
comment|// Map reusable lowered PHI node -> incoming join register.
typedef|typedef
name|DenseMap
operator|<
name|MachineInstr
operator|*
operator|,
name|unsigned
operator|,
name|MachineInstrExpressionTrait
operator|>
name|LoweredPHIMap
expr_stmt|;
name|LoweredPHIMap
name|LoweredPHIs
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
comment|/* LLVM_CODEGEN_PHIELIMINATION_HPP */
end_comment

end_unit

