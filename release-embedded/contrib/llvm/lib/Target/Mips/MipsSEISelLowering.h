begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsSEISelLowering.h - MipsSE DAG Lowering Interface ----*- C++ -*-===//
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
comment|// Subclass of MipsTargetLowering specialized for mips32/64.
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
name|MipsSEISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|MipsSEISELLOWERING_H
end_define

begin_include
include|#
directive|include
file|"MipsISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"MipsRegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MipsSETargetLowering
range|:
name|public
name|MipsTargetLowering
block|{
name|public
operator|:
name|explicit
name|MipsSETargetLowering
argument_list|(
name|MipsTargetMachine
operator|&
name|TM
argument_list|)
block|;
name|virtual
name|bool
name|allowsUnalignedMemoryAccesses
argument_list|(
argument|EVT VT
argument_list|,
argument|bool *Fast
argument_list|)
specifier|const
block|;
name|virtual
name|SDValue
name|LowerOperation
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|virtual
name|SDValue
name|PerformDAGCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|virtual
name|MachineBasicBlock
operator|*
name|EmitInstrWithCustomInserter
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *MBB
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isShuffleMaskLegal
argument_list|(
argument|const SmallVectorImpl<int>&Mask
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
specifier|const
name|TargetRegisterClass
operator|*
name|getRepRegClassFor
argument_list|(
argument|MVT VT
argument_list|)
specifier|const
block|{
if|if
condition|(
name|VT
operator|==
name|MVT
operator|::
name|Untyped
condition|)
return|return
name|Subtarget
operator|->
name|hasDSP
argument_list|()
operator|?
operator|&
name|Mips
operator|::
name|ACRegsDSPRegClass
operator|:
operator|&
name|Mips
operator|::
name|ACRegsRegClass
return|;
return|return
name|TargetLowering
operator|::
name|getRepRegClassFor
argument_list|(
name|VT
argument_list|)
return|;
block|}
name|private
label|:
name|virtual
name|bool
name|isEligibleForTailCallOptimization
argument_list|(
specifier|const
name|MipsCC
operator|&
name|MipsCCInfo
argument_list|,
name|unsigned
name|NextStackOffset
argument_list|,
specifier|const
name|MipsFunctionInfo
operator|&
name|FI
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|void
name|getOpndList
argument_list|(
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|Ops
argument_list|,
name|std
operator|::
name|deque
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
argument_list|,
name|SDValue
operator|>
expr|>
operator|&
name|RegsToPass
argument_list|,
name|bool
name|IsPICCall
argument_list|,
name|bool
name|GlobalOrExternal
argument_list|,
name|bool
name|InternalLinkage
argument_list|,
name|CallLoweringInfo
operator|&
name|CLI
argument_list|,
name|SDValue
name|Callee
argument_list|,
name|SDValue
name|Chain
argument_list|)
decl|const
decl_stmt|;
name|SDValue
name|lowerMulDiv
argument_list|(
name|SDValue
name|Op
argument_list|,
name|unsigned
name|NewOpc
argument_list|,
name|bool
name|HasLo
argument_list|,
name|bool
name|HasHi
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
name|SDValue
name|lowerINTRINSIC_WO_CHAIN
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
name|SDValue
name|lowerINTRINSIC_W_CHAIN
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
name|MachineBasicBlock
modifier|*
name|emitBPOSGE32
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|,
name|MachineBasicBlock
operator|*
name|BB
argument_list|)
decl|const
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
comment|// MipsSEISELLOWERING_H
end_comment

end_unit

