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
file|"llvm/ADT/BitVector.h"
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
file|"llvm/CodeGen/RegisterClassInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleDAG.h"
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
name|class
name|RegisterClassInfo
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
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
name|TargetInstrInfo
operator|*
name|TII
block|;
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
block|;
specifier|const
name|RegisterClassInfo
operator|&
name|RegClassInfo
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
name|std
operator|::
name|vector
operator|<
specifier|const
name|TargetRegisterClass
operator|*
operator|>
name|Classes
block|;
comment|/// RegRefs - Map registers to all their references within a live range.
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
typedef|typedef
name|std
operator|::
name|multimap
operator|<
name|unsigned
operator|,
name|MachineOperand
operator|*
operator|>
operator|::
name|const_iterator
name|RegRefIter
expr_stmt|;
comment|/// KillIndices - The index of the most recent kill (proceding bottom-up),
comment|/// or ~0u if the register is not live.
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|KillIndices
decl_stmt|;
comment|/// DefIndices - The index of the most recent complete def (proceding bottom
comment|/// up), or ~0u if the register is live.
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|DefIndices
expr_stmt|;
comment|/// KeepRegs - A set of registers which are live and cannot be changed to
comment|/// break anti-dependencies.
name|BitVector
name|KeepRegs
decl_stmt|;
name|public
label|:
name|CriticalAntiDepBreaker
argument_list|(
name|MachineFunction
operator|&
name|MFi
argument_list|,
specifier|const
name|RegisterClassInfo
operator|&
argument_list|)
expr_stmt|;
operator|~
name|CriticalAntiDepBreaker
argument_list|()
expr_stmt|;
comment|/// Start - Initialize anti-dep breaking for a new basic block.
name|void
name|StartBlock
parameter_list|(
name|MachineBasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|/// BreakAntiDependencies - Identifiy anti-dependencies along the critical
comment|/// path
comment|/// of the ScheduleDAG and break them by renaming registers.
comment|///
name|unsigned
name|BreakAntiDependencies
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|>
operator|&
name|SUnits
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|Begin
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|End
argument_list|,
name|unsigned
name|InsertPosIndex
argument_list|,
name|DbgValueVector
operator|&
name|DbgValues
argument_list|)
decl_stmt|;
comment|/// Observe - Update liveness information to account for the current
comment|/// instruction, which will not be scheduled.
comment|///
name|void
name|Observe
parameter_list|(
name|MachineInstr
modifier|*
name|MI
parameter_list|,
name|unsigned
name|Count
parameter_list|,
name|unsigned
name|InsertPosIndex
parameter_list|)
function_decl|;
comment|/// Finish - Finish anti-dep breaking for a basic block.
name|void
name|FinishBlock
parameter_list|()
function_decl|;
name|private
label|:
name|void
name|PrescanInstruction
parameter_list|(
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
name|void
name|ScanInstruction
parameter_list|(
name|MachineInstr
modifier|*
name|MI
parameter_list|,
name|unsigned
name|Count
parameter_list|)
function_decl|;
name|bool
name|isNewRegClobberedByRefs
parameter_list|(
name|RegRefIter
name|RegRefBegin
parameter_list|,
name|RegRefIter
name|RegRefEnd
parameter_list|,
name|unsigned
name|NewReg
parameter_list|)
function_decl|;
name|unsigned
name|findSuitableFreeRegister
argument_list|(
name|RegRefIter
name|RegRefBegin
argument_list|,
name|RegRefIter
name|RegRefEnd
argument_list|,
name|unsigned
name|AntiDepReg
argument_list|,
name|unsigned
name|LastNewReg
argument_list|,
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|,
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|Forbid
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

end_unit

