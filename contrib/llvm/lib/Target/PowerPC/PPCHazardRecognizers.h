begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PPCHazardRecognizers.h - PowerPC Hazard Recognizers -----*- C++ -*-===//
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
comment|// This file defines hazard recognizers for scheduling on PowerPC processors.
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
name|PPCHAZRECS_H
end_ifndef

begin_define
define|#
directive|define
name|PPCHAZRECS_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleHazardRecognizer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAGNodes.h"
end_include

begin_include
include|#
directive|include
file|"PPCInstrInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// PPCHazardRecognizer970 - This class defines a finite state automata that
comment|/// models the dispatch logic on the PowerPC 970 (aka G5) processor.  This
comment|/// promotes good dispatch group formation and implements noop insertion to
comment|/// avoid structural hazards that cause significant performance penalties (e.g.
comment|/// setting the CTR register then branching through it within a dispatch group),
comment|/// or storing then loading from the same address within a dispatch group.
name|class
name|PPCHazardRecognizer970
range|:
name|public
name|ScheduleHazardRecognizer
block|{
specifier|const
name|TargetInstrInfo
operator|&
name|TII
block|;
name|unsigned
name|NumIssued
block|;
comment|// Number of insts issued, including advanced cycles.
comment|// Various things that can cause a structural hazard.
comment|// HasCTRSet - If the CTR register is set in this group, disallow BCTRL.
name|bool
name|HasCTRSet
block|;
comment|// StoredPtr - Keep track of the address of any store.  If we see a load from
comment|// the same address (or one that aliases it), disallow the store.  We can have
comment|// up to four stores in one dispatch group, hence we track up to 4.
comment|//
comment|// This is null if we haven't seen a store yet.  We keep track of both
comment|// operands of the store here, since we support [r+r] and [r+i] addressing.
name|SDValue
name|StorePtr1
index|[
literal|4
index|]
block|,
name|StorePtr2
index|[
literal|4
index|]
block|;
name|unsigned
name|StoreSize
index|[
literal|4
index|]
block|;
name|unsigned
name|NumStores
block|;
name|public
operator|:
name|PPCHazardRecognizer970
argument_list|(
specifier|const
name|TargetInstrInfo
operator|&
name|TII
argument_list|)
block|;
name|virtual
name|HazardType
name|getHazardType
argument_list|(
argument|SUnit *SU
argument_list|,
argument|int Stalls
argument_list|)
block|;
name|virtual
name|void
name|EmitInstruction
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
block|;
name|virtual
name|void
name|AdvanceCycle
argument_list|()
block|;
name|private
operator|:
comment|/// EndDispatchGroup - Called when we are finishing a new dispatch group.
comment|///
name|void
name|EndDispatchGroup
argument_list|()
block|;
comment|/// GetInstrType - Classify the specified powerpc opcode according to its
comment|/// pipeline.
name|PPCII
operator|::
name|PPC970_Unit
name|GetInstrType
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|bool&isFirst
argument_list|,
argument|bool&isSingle
argument_list|,
argument|bool&isCracked
argument_list|,
argument|bool&isLoad
argument_list|,
argument|bool&isStore
argument_list|)
block|;
name|bool
name|isLoadOfStoredAddress
argument_list|(
argument|unsigned LoadSize
argument_list|,
argument|SDValue Ptr1
argument_list|,
argument|SDValue Ptr2
argument_list|)
specifier|const
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

