begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- llvm/CodeGen/CriticalAntiDepBreaker.h - Anti-Dep Support -*- C++ -*-=//
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
comment|// This file implements the CriticalAntiDepBreaker class, which
end_comment

begin_comment
comment|// implements register anti-dependence breaking along a blocks
end_comment

begin_comment
comment|// critical path during post-RA scheduler.
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
name|LLVM_CODEGEN_CRITICALANTIDEPBREAKER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_CRITICALANTIDEPBREAKER_H
end_define

begin_include
include|#
directive|include
file|"AntiDepBreaker.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFrameInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|CriticalAntiDepBreaker
range|:
name|public
name|AntiDepBreaker
block|{
name|MachineFunction
operator|&
name|MF
block|;
name|MachineRegisterInfo
operator|&
name|MRI
block|;
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
block|;
comment|/// AllocatableSet - The set of allocatable registers.
comment|/// We'll be ignoring anti-dependencies on non-allocatable registers,
comment|/// because they may not be safe to break.
specifier|const
name|BitVector
name|AllocatableSet
block|;
comment|/// Classes - For live regs that are only used in one register class in a
comment|/// live range, the register class. If the register is not live, the
comment|/// corresponding value is null. If the register is live but used in
comment|/// multiple register classes, the corresponding value is -1 casted to a
comment|/// pointer.
specifier|const
name|TargetRegisterClass
operator|*
name|Classes
index|[
name|TargetRegisterInfo
operator|::
name|FirstVirtualRegister
index|]
block|;
comment|/// RegRegs - Map registers to all their references within a live range.
name|std
operator|::
name|multimap
operator|<
name|unsigned
block|,
name|MachineOperand
operator|*
operator|>
name|RegRefs
block|;
comment|/// KillIndices - The index of the most recent kill (proceding bottom-up),
comment|/// or ~0u if the register is not live.
name|unsigned
name|KillIndices
index|[
name|TargetRegisterInfo
operator|::
name|FirstVirtualRegister
index|]
block|;
comment|/// DefIndices - The index of the most recent complete def (proceding bottom
comment|/// up), or ~0u if the register is live.
name|unsigned
name|DefIndices
index|[
name|TargetRegisterInfo
operator|::
name|FirstVirtualRegister
index|]
block|;
comment|/// KeepRegs - A set of registers which are live and cannot be changed to
comment|/// break anti-dependencies.
name|SmallSet
operator|<
name|unsigned
block|,
literal|4
operator|>
name|KeepRegs
block|;
name|public
operator|:
name|CriticalAntiDepBreaker
argument_list|(
name|MachineFunction
operator|&
name|MFi
argument_list|)
block|;
operator|~
name|CriticalAntiDepBreaker
argument_list|()
block|;
comment|/// GetMaxTrials - Critical path anti-dependence breaking requires
comment|/// only a single pass
name|unsigned
name|GetMaxTrials
argument_list|()
block|{
return|return
literal|1
return|;
block|}
comment|/// NeedCandidates - Candidates not needed.
name|bool
name|NeedCandidates
argument_list|()
block|{
return|return
name|false
return|;
block|}
comment|/// Start - Initialize anti-dep breaking for a new basic block.
name|void
name|StartBlock
argument_list|(
name|MachineBasicBlock
operator|*
name|BB
argument_list|)
block|;
comment|/// BreakAntiDependencies - Identifiy anti-dependencies along the critical path
comment|/// of the ScheduleDAG and break them by renaming registers.
comment|///
name|unsigned
name|BreakAntiDependencies
argument_list|(
argument|std::vector<SUnit>& SUnits
argument_list|,
argument|CandidateMap& Candidates
argument_list|,
argument|MachineBasicBlock::iterator& Begin
argument_list|,
argument|MachineBasicBlock::iterator& End
argument_list|,
argument|unsigned InsertPosIndex
argument_list|)
block|;
comment|/// Observe - Update liveness information to account for the current
comment|/// instruction, which will not be scheduled.
comment|///
name|void
name|Observe
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|unsigned Count
argument_list|,
argument|unsigned InsertPosIndex
argument_list|)
block|;
comment|/// Finish - Finish anti-dep breaking for a basic block.
name|void
name|FinishBlock
argument_list|()
block|;
name|private
operator|:
name|void
name|PrescanInstruction
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|)
block|;
name|void
name|ScanInstruction
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|unsigned Count
argument_list|)
block|;
name|unsigned
name|findSuitableFreeRegister
argument_list|(
argument|unsigned AntiDepReg
argument_list|,
argument|unsigned LastNewReg
argument_list|,
argument|const TargetRegisterClass *
argument_list|)
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

