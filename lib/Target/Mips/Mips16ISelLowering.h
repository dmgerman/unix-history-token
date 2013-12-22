begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Mips16ISelLowering.h - Mips16 DAG Lowering Interface ----*- C++ -*-===//
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
comment|// Subclass of MipsTargetLowering specialized for mips16.
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
name|Mips16ISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|Mips16ISELLOWERING_H
end_define

begin_include
include|#
directive|include
file|"MipsISelLowering.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Mips16TargetLowering
range|:
name|public
name|MipsTargetLowering
block|{
name|public
operator|:
name|explicit
name|Mips16TargetLowering
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
name|private
operator|:
name|virtual
name|bool
name|isEligibleForTailCallOptimization
argument_list|(
argument|const MipsCC&MipsCCInfo
argument_list|,
argument|unsigned NextStackOffset
argument_list|,
argument|const MipsFunctionInfo& FI
argument_list|)
specifier|const
block|;
name|void
name|setMips16HardFloatLibCalls
argument_list|()
block|;
name|unsigned
name|int
name|getMips16HelperFunctionStubNumber
argument_list|(
argument|ArgListTy&Args
argument_list|)
specifier|const
block|;
specifier|const
name|char
operator|*
name|getMips16HelperFunction
argument_list|(
argument|Type* RetTy
argument_list|,
argument|ArgListTy&Args
argument_list|,
argument|bool&needHelper
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|getOpndList
argument_list|(
argument|SmallVectorImpl<SDValue>&Ops
argument_list|,
argument|std::deque< std::pair<unsigned
argument_list|,
argument|SDValue>>&RegsToPass
argument_list|,
argument|bool IsPICCall
argument_list|,
argument|bool GlobalOrExternal
argument_list|,
argument|bool InternalLinkage
argument_list|,
argument|CallLoweringInfo&CLI
argument_list|,
argument|SDValue Callee
argument_list|,
argument|SDValue Chain
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitSel16
argument_list|(
argument|unsigned Opc
argument_list|,
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitSeliT16
argument_list|(
argument|unsigned Opc1
argument_list|,
argument|unsigned Opc2
argument_list|,
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitSelT16
argument_list|(
argument|unsigned Opc1
argument_list|,
argument|unsigned Opc2
argument_list|,
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitFEXT_T8I816_ins
argument_list|(
argument|unsigned BtOpc
argument_list|,
argument|unsigned CmpOpc
argument_list|,
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitFEXT_T8I8I16_ins
argument_list|(
argument|unsigned BtOpc
argument_list|,
argument|unsigned CmpiOpc
argument_list|,
argument|unsigned CmpiXOpc
argument_list|,
argument|bool ImmSigned
argument_list|,
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitFEXT_CCRX16_ins
argument_list|(
argument|unsigned SltOpc
argument_list|,
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitFEXT_CCRXI16_ins
argument_list|(
argument|unsigned SltiOpc
argument_list|,
argument|unsigned SltiXOpc
argument_list|,
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Mips16ISELLOWERING_H
end_comment

end_unit

