begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- R600MachineScheduler.h - R600 Scheduler Interface -*- C++ -*-------===//
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
comment|/// \file
end_comment

begin_comment
comment|/// \brief R600 Machine Scheduler interface
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
name|R600MACHINESCHEDULER_H_
end_ifndef

begin_define
define|#
directive|define
name|R600MACHINESCHEDULER_H_
end_define

begin_include
include|#
directive|include
file|"R600InstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PriorityQueue.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineScheduler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_decl_stmt
name|using
name|namespace
name|llvm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|R600SchedStrategy
range|:
name|public
name|MachineSchedStrategy
block|{
specifier|const
name|ScheduleDAGMI
operator|*
name|DAG
block|;
specifier|const
name|R600InstrInfo
operator|*
name|TII
block|;
specifier|const
name|R600RegisterInfo
operator|*
name|TRI
block|;
name|MachineRegisterInfo
operator|*
name|MRI
block|;    enum
name|InstKind
block|{
name|IDAlu
block|,
name|IDFetch
block|,
name|IDOther
block|,
name|IDLast
block|}
block|;    enum
name|AluKind
block|{
name|AluAny
block|,
name|AluT_X
block|,
name|AluT_Y
block|,
name|AluT_Z
block|,
name|AluT_W
block|,
name|AluT_XYZW
block|,
name|AluPredX
block|,
name|AluTrans
block|,
name|AluDiscarded
block|,
comment|// LLVM Instructions that are going to be eliminated
name|AluLast
block|}
block|;
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|*
operator|>
name|Available
index|[
name|IDLast
index|]
block|,
name|Pending
index|[
name|IDLast
index|]
block|;
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|*
operator|>
name|AvailableAlus
index|[
name|AluLast
index|]
block|;
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|*
operator|>
name|PhysicalRegCopy
block|;
name|InstKind
name|CurInstKind
block|;
name|int
name|CurEmitted
block|;
name|InstKind
name|NextInstKind
block|;
name|unsigned
name|AluInstCount
block|;
name|unsigned
name|FetchInstCount
block|;
name|int
name|InstKindLimit
index|[
name|IDLast
index|]
block|;
name|int
name|OccupedSlotsMask
block|;
name|public
operator|:
name|R600SchedStrategy
argument_list|()
operator|:
name|DAG
argument_list|(
literal|0
argument_list|)
block|,
name|TII
argument_list|(
literal|0
argument_list|)
block|,
name|TRI
argument_list|(
literal|0
argument_list|)
block|,
name|MRI
argument_list|(
literal|0
argument_list|)
block|{   }
name|virtual
operator|~
name|R600SchedStrategy
argument_list|()
block|{   }
name|virtual
name|void
name|initialize
argument_list|(
name|ScheduleDAGMI
operator|*
name|dag
argument_list|)
block|;
name|virtual
name|SUnit
operator|*
name|pickNode
argument_list|(
name|bool
operator|&
name|IsTopNode
argument_list|)
block|;
name|virtual
name|void
name|schedNode
argument_list|(
argument|SUnit *SU
argument_list|,
argument|bool IsTopNode
argument_list|)
block|;
name|virtual
name|void
name|releaseTopNode
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
block|;
name|virtual
name|void
name|releaseBottomNode
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
block|;
name|private
operator|:
name|std
operator|::
name|vector
operator|<
name|MachineInstr
operator|*
operator|>
name|InstructionsGroupCandidate
block|;
name|bool
name|VLIW5
block|;
name|int
name|getInstKind
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
block|;
name|bool
name|regBelongsToClass
argument_list|(
argument|unsigned Reg
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|)
specifier|const
block|;
name|AluKind
name|getAluKind
argument_list|(
argument|SUnit *SU
argument_list|)
specifier|const
block|;
name|void
name|LoadAlu
argument_list|()
block|;
name|unsigned
name|AvailablesAluCount
argument_list|()
specifier|const
block|;
name|SUnit
operator|*
name|AttemptFillSlot
argument_list|(
argument|unsigned Slot
argument_list|,
argument|bool AnyAlu
argument_list|)
block|;
name|void
name|PrepareNextSlot
argument_list|()
block|;
name|SUnit
operator|*
name|PopInst
argument_list|(
argument|std::vector<SUnit*>&Q
argument_list|,
argument|bool AnyALU
argument_list|)
block|;
name|void
name|AssignSlot
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|unsigned Slot
argument_list|)
block|;
name|SUnit
operator|*
name|pickAlu
argument_list|()
block|;
name|SUnit
operator|*
name|pickOther
argument_list|(
argument|int QID
argument_list|)
block|;
name|void
name|MoveUnits
argument_list|(
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|*
operator|>
operator|&
name|QSrc
argument_list|,
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|*
operator|>
operator|&
name|QDst
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* R600MACHINESCHEDULER_H_ */
end_comment

end_unit

