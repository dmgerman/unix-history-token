begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMMachineFunctionInfo.h - ARM machine function info ----*- C++ -*-===//
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
comment|// This file declares ARM-specific per-machine-function information.
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
name|LLVM_LIB_TARGET_ARM_ARMMACHINEFUNCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_ARM_ARMMACHINEFUNCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// ARMFunctionInfo - This class is derived from MachineFunctionInfo and
comment|/// contains private ARM-specific information for each MachineFunction.
name|class
name|ARMFunctionInfo
range|:
name|public
name|MachineFunctionInfo
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// isThumb - True if this function is compiled under Thumb mode.
comment|/// Used to initialized Align, so must precede it.
name|bool
name|isThumb
operator|=
name|false
block|;
comment|/// hasThumb2 - True if the target architecture supports Thumb2. Do not use
comment|/// to determine if function is compiled under Thumb mode, for that use
comment|/// 'isThumb'.
name|bool
name|hasThumb2
operator|=
name|false
block|;
comment|/// StByValParamsPadding - For parameter that is split between
comment|/// GPRs and memory; while recovering GPRs part, when
comment|/// StackAlignment> 4, and GPRs-part-size mod StackAlignment != 0,
comment|/// we need to insert gap before parameter start address. It allows to
comment|/// "attach" GPR-part to the part that was passed via stack.
name|unsigned
name|StByValParamsPadding
operator|=
literal|0
block|;
comment|/// VarArgsRegSaveSize - Size of the register save area for vararg functions.
comment|///
name|unsigned
name|ArgRegsSaveSize
operator|=
literal|0
block|;
comment|/// ReturnRegsCount - Number of registers used up in the return.
name|unsigned
name|ReturnRegsCount
operator|=
literal|0
block|;
comment|/// HasStackFrame - True if this function has a stack frame. Set by
comment|/// determineCalleeSaves().
name|bool
name|HasStackFrame
operator|=
name|false
block|;
comment|/// RestoreSPFromFP - True if epilogue should restore SP from FP. Set by
comment|/// emitPrologue.
name|bool
name|RestoreSPFromFP
operator|=
name|false
block|;
comment|/// LRSpilledForFarJump - True if the LR register has been for spilled to
comment|/// enable far jump.
name|bool
name|LRSpilledForFarJump
operator|=
name|false
block|;
comment|/// FramePtrSpillOffset - If HasStackFrame, this records the frame pointer
comment|/// spill stack offset.
name|unsigned
name|FramePtrSpillOffset
operator|=
literal|0
block|;
comment|/// GPRCS1Offset, GPRCS2Offset, DPRCSOffset - Starting offset of callee saved
comment|/// register spills areas. For Mac OS X:
comment|///
comment|/// GPR callee-saved (1) : r4, r5, r6, r7, lr
comment|/// --------------------------------------------
comment|/// GPR callee-saved (2) : r8, r10, r11
comment|/// --------------------------------------------
comment|/// DPR callee-saved : d8 - d15
comment|///
comment|/// Also see AlignedDPRCSRegs below. Not all D-regs need to go in area 3.
comment|/// Some may be spilled after the stack has been realigned.
name|unsigned
name|GPRCS1Offset
operator|=
literal|0
block|;
name|unsigned
name|GPRCS2Offset
operator|=
literal|0
block|;
name|unsigned
name|DPRCSOffset
operator|=
literal|0
block|;
comment|/// GPRCS1Size, GPRCS2Size, DPRCSSize - Sizes of callee saved register spills
comment|/// areas.
name|unsigned
name|GPRCS1Size
operator|=
literal|0
block|;
name|unsigned
name|GPRCS2Size
operator|=
literal|0
block|;
name|unsigned
name|DPRCSAlignGapSize
operator|=
literal|0
block|;
name|unsigned
name|DPRCSSize
operator|=
literal|0
block|;
comment|/// NumAlignedDPRCS2Regs - The number of callee-saved DPRs that are saved in
comment|/// the aligned portion of the stack frame.  This is always a contiguous
comment|/// sequence of D-registers starting from d8.
comment|///
comment|/// We do not keep track of the frame indices used for these registers - they
comment|/// behave like any other frame index in the aligned stack frame.  These
comment|/// registers also aren't included in DPRCSSize above.
name|unsigned
name|NumAlignedDPRCS2Regs
operator|=
literal|0
block|;
name|unsigned
name|PICLabelUId
operator|=
literal|0
block|;
comment|/// VarArgsFrameIndex - FrameIndex for start of varargs area.
name|int
name|VarArgsFrameIndex
operator|=
literal|0
block|;
comment|/// HasITBlocks - True if IT blocks have been inserted.
name|bool
name|HasITBlocks
operator|=
name|false
block|;
comment|/// CPEClones - Track constant pool entries clones created by Constant Island
comment|/// pass.
name|DenseMap
operator|<
name|unsigned
block|,
name|unsigned
operator|>
name|CPEClones
block|;
comment|/// ArgumentStackSize - amount of bytes on stack consumed by the arguments
comment|/// being passed on the stack
name|unsigned
name|ArgumentStackSize
operator|=
literal|0
block|;
comment|/// CoalescedWeights - mapping of basic blocks to the rolling counter of
comment|/// coalesced weights.
name|DenseMap
operator|<
specifier|const
name|MachineBasicBlock
operator|*
block|,
name|unsigned
operator|>
name|CoalescedWeights
block|;
comment|/// True if this function has a subset of CSRs that is handled explicitly via
comment|/// copies.
name|bool
name|IsSplitCSR
operator|=
name|false
block|;
comment|/// Globals that have had their storage promoted into the constant pool.
name|SmallPtrSet
operator|<
specifier|const
name|GlobalVariable
operator|*
block|,
literal|2
operator|>
name|PromotedGlobals
block|;
comment|/// The amount the literal pool has been increasedby due to promoted globals.
name|int
name|PromotedGlobalsIncrease
operator|=
literal|0
block|;
name|public
operator|:
name|ARMFunctionInfo
argument_list|()
operator|=
expr|default
block|;
name|explicit
name|ARMFunctionInfo
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
name|bool
name|isThumbFunction
argument_list|()
specifier|const
block|{
return|return
name|isThumb
return|;
block|}
name|bool
name|isThumb1OnlyFunction
argument_list|()
specifier|const
block|{
return|return
name|isThumb
operator|&&
operator|!
name|hasThumb2
return|;
block|}
name|bool
name|isThumb2Function
argument_list|()
specifier|const
block|{
return|return
name|isThumb
operator|&&
name|hasThumb2
return|;
block|}
name|unsigned
name|getStoredByValParamsPadding
argument_list|()
specifier|const
block|{
return|return
name|StByValParamsPadding
return|;
block|}
name|void
name|setStoredByValParamsPadding
argument_list|(
argument|unsigned p
argument_list|)
block|{
name|StByValParamsPadding
operator|=
name|p
block|; }
name|unsigned
name|getArgRegsSaveSize
argument_list|()
specifier|const
block|{
return|return
name|ArgRegsSaveSize
return|;
block|}
name|void
name|setArgRegsSaveSize
argument_list|(
argument|unsigned s
argument_list|)
block|{
name|ArgRegsSaveSize
operator|=
name|s
block|; }
name|unsigned
name|getReturnRegsCount
argument_list|()
specifier|const
block|{
return|return
name|ReturnRegsCount
return|;
block|}
name|void
name|setReturnRegsCount
argument_list|(
argument|unsigned s
argument_list|)
block|{
name|ReturnRegsCount
operator|=
name|s
block|; }
name|bool
name|hasStackFrame
argument_list|()
specifier|const
block|{
return|return
name|HasStackFrame
return|;
block|}
name|void
name|setHasStackFrame
argument_list|(
argument|bool s
argument_list|)
block|{
name|HasStackFrame
operator|=
name|s
block|; }
name|bool
name|shouldRestoreSPFromFP
argument_list|()
specifier|const
block|{
return|return
name|RestoreSPFromFP
return|;
block|}
name|void
name|setShouldRestoreSPFromFP
argument_list|(
argument|bool s
argument_list|)
block|{
name|RestoreSPFromFP
operator|=
name|s
block|; }
name|bool
name|isLRSpilledForFarJump
argument_list|()
specifier|const
block|{
return|return
name|LRSpilledForFarJump
return|;
block|}
name|void
name|setLRIsSpilledForFarJump
argument_list|(
argument|bool s
argument_list|)
block|{
name|LRSpilledForFarJump
operator|=
name|s
block|; }
name|unsigned
name|getFramePtrSpillOffset
argument_list|()
specifier|const
block|{
return|return
name|FramePtrSpillOffset
return|;
block|}
name|void
name|setFramePtrSpillOffset
argument_list|(
argument|unsigned o
argument_list|)
block|{
name|FramePtrSpillOffset
operator|=
name|o
block|; }
name|unsigned
name|getNumAlignedDPRCS2Regs
argument_list|()
specifier|const
block|{
return|return
name|NumAlignedDPRCS2Regs
return|;
block|}
name|void
name|setNumAlignedDPRCS2Regs
argument_list|(
argument|unsigned n
argument_list|)
block|{
name|NumAlignedDPRCS2Regs
operator|=
name|n
block|; }
name|unsigned
name|getGPRCalleeSavedArea1Offset
argument_list|()
specifier|const
block|{
return|return
name|GPRCS1Offset
return|;
block|}
name|unsigned
name|getGPRCalleeSavedArea2Offset
argument_list|()
specifier|const
block|{
return|return
name|GPRCS2Offset
return|;
block|}
name|unsigned
name|getDPRCalleeSavedAreaOffset
argument_list|()
specifier|const
block|{
return|return
name|DPRCSOffset
return|;
block|}
name|void
name|setGPRCalleeSavedArea1Offset
argument_list|(
argument|unsigned o
argument_list|)
block|{
name|GPRCS1Offset
operator|=
name|o
block|; }
name|void
name|setGPRCalleeSavedArea2Offset
argument_list|(
argument|unsigned o
argument_list|)
block|{
name|GPRCS2Offset
operator|=
name|o
block|; }
name|void
name|setDPRCalleeSavedAreaOffset
argument_list|(
argument|unsigned o
argument_list|)
block|{
name|DPRCSOffset
operator|=
name|o
block|; }
name|unsigned
name|getGPRCalleeSavedArea1Size
argument_list|()
specifier|const
block|{
return|return
name|GPRCS1Size
return|;
block|}
name|unsigned
name|getGPRCalleeSavedArea2Size
argument_list|()
specifier|const
block|{
return|return
name|GPRCS2Size
return|;
block|}
name|unsigned
name|getDPRCalleeSavedGapSize
argument_list|()
specifier|const
block|{
return|return
name|DPRCSAlignGapSize
return|;
block|}
name|unsigned
name|getDPRCalleeSavedAreaSize
argument_list|()
specifier|const
block|{
return|return
name|DPRCSSize
return|;
block|}
name|void
name|setGPRCalleeSavedArea1Size
argument_list|(
argument|unsigned s
argument_list|)
block|{
name|GPRCS1Size
operator|=
name|s
block|; }
name|void
name|setGPRCalleeSavedArea2Size
argument_list|(
argument|unsigned s
argument_list|)
block|{
name|GPRCS2Size
operator|=
name|s
block|; }
name|void
name|setDPRCalleeSavedGapSize
argument_list|(
argument|unsigned s
argument_list|)
block|{
name|DPRCSAlignGapSize
operator|=
name|s
block|; }
name|void
name|setDPRCalleeSavedAreaSize
argument_list|(
argument|unsigned s
argument_list|)
block|{
name|DPRCSSize
operator|=
name|s
block|; }
name|unsigned
name|getArgumentStackSize
argument_list|()
specifier|const
block|{
return|return
name|ArgumentStackSize
return|;
block|}
name|void
name|setArgumentStackSize
argument_list|(
argument|unsigned size
argument_list|)
block|{
name|ArgumentStackSize
operator|=
name|size
block|; }
name|void
name|initPICLabelUId
argument_list|(
argument|unsigned UId
argument_list|)
block|{
name|PICLabelUId
operator|=
name|UId
block|;   }
name|unsigned
name|getNumPICLabels
argument_list|()
specifier|const
block|{
return|return
name|PICLabelUId
return|;
block|}
name|unsigned
name|createPICLabelUId
argument_list|()
block|{
return|return
name|PICLabelUId
operator|++
return|;
block|}
name|int
name|getVarArgsFrameIndex
argument_list|()
specifier|const
block|{
return|return
name|VarArgsFrameIndex
return|;
block|}
name|void
name|setVarArgsFrameIndex
argument_list|(
argument|int Index
argument_list|)
block|{
name|VarArgsFrameIndex
operator|=
name|Index
block|; }
name|bool
name|hasITBlocks
argument_list|()
specifier|const
block|{
return|return
name|HasITBlocks
return|;
block|}
name|void
name|setHasITBlocks
argument_list|(
argument|bool h
argument_list|)
block|{
name|HasITBlocks
operator|=
name|h
block|; }
name|bool
name|isSplitCSR
argument_list|()
specifier|const
block|{
return|return
name|IsSplitCSR
return|;
block|}
name|void
name|setIsSplitCSR
argument_list|(
argument|bool s
argument_list|)
block|{
name|IsSplitCSR
operator|=
name|s
block|; }
name|void
name|recordCPEClone
argument_list|(
argument|unsigned CPIdx
argument_list|,
argument|unsigned CPCloneIdx
argument_list|)
block|{
if|if
condition|(
operator|!
name|CPEClones
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|CPCloneIdx
argument_list|,
name|CPIdx
argument_list|)
argument_list|)
operator|.
name|second
condition|)
name|llvm_unreachable
argument_list|(
literal|"Duplicate entries!"
argument_list|)
expr_stmt|;
block|}
name|unsigned
name|getOriginalCPIdx
argument_list|(
argument|unsigned CloneIdx
argument_list|)
specifier|const
block|{
name|DenseMap
operator|<
name|unsigned
block|,
name|unsigned
operator|>
operator|::
name|const_iterator
name|I
operator|=
name|CPEClones
operator|.
name|find
argument_list|(
name|CloneIdx
argument_list|)
block|;
if|if
condition|(
name|I
operator|!=
name|CPEClones
operator|.
name|end
argument_list|()
condition|)
return|return
name|I
operator|->
name|second
return|;
else|else
return|return
operator|-
literal|1U
return|;
block|}
name|DenseMap
operator|<
specifier|const
name|MachineBasicBlock
operator|*
block|,
name|unsigned
operator|>
operator|::
name|iterator
name|getCoalescedWeight
argument_list|(
argument|MachineBasicBlock* MBB
argument_list|)
block|{
name|auto
name|It
operator|=
name|CoalescedWeights
operator|.
name|find
argument_list|(
name|MBB
argument_list|)
block|;
if|if
condition|(
name|It
operator|==
name|CoalescedWeights
operator|.
name|end
argument_list|()
condition|)
block|{
name|It
operator|=
name|CoalescedWeights
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|MBB
argument_list|,
literal|0
argument_list|)
argument_list|)
operator|.
name|first
expr_stmt|;
block|}
return|return
name|It
return|;
block|}
comment|/// Indicate to the backend that \c GV has had its storage changed to inside
comment|/// a constant pool. This means it no longer needs to be emitted as a
comment|/// global variable.
name|void
name|markGlobalAsPromotedToConstantPool
argument_list|(
argument|const GlobalVariable *GV
argument_list|)
block|{
name|PromotedGlobals
operator|.
name|insert
argument_list|(
name|GV
argument_list|)
block|;   }
name|SmallPtrSet
operator|<
specifier|const
name|GlobalVariable
operator|*
block|,
literal|2
operator|>
operator|&
name|getGlobalsPromotedToConstantPool
argument_list|()
block|{
return|return
name|PromotedGlobals
return|;
block|}
name|int
name|getPromotedConstpoolIncrease
argument_list|()
specifier|const
block|{
return|return
name|PromotedGlobalsIncrease
return|;
block|}
name|void
name|setPromotedConstpoolIncrease
argument_list|(
argument|int Sz
argument_list|)
block|{
name|PromotedGlobalsIncrease
operator|=
name|Sz
block|;   }
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_ARM_ARMMACHINEFUNCTIONINFO_H
end_comment

end_unit

