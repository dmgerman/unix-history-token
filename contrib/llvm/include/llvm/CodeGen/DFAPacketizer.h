begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/CodeGen/DFAPacketizer.h - DFA Packetizer for VLIW ---*- C++ -*-===//
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
comment|// This class implements a deterministic finite automaton (DFA) based
end_comment

begin_comment
comment|// packetizing mechanism for VLIW architectures. It provides APIs to
end_comment

begin_comment
comment|// determine whether there exists a legal mapping of instructions to
end_comment

begin_comment
comment|// functional unit assignments in a packet. The DFA is auto-generated from
end_comment

begin_comment
comment|// the target's Schedule.td file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A DFA consists of 3 major elements: states, inputs, and transitions. For
end_comment

begin_comment
comment|// the packetizing mechanism, the input is the set of instruction classes for
end_comment

begin_comment
comment|// a target. The state models all possible combinations of functional unit
end_comment

begin_comment
comment|// consumption for a given set of instructions in a packet. A transition
end_comment

begin_comment
comment|// models the addition of an instruction to a packet. In the DFA constructed
end_comment

begin_comment
comment|// by this class, if an instruction can be added to a packet, then a valid
end_comment

begin_comment
comment|// transition exists from the corresponding state. Invalid transitions
end_comment

begin_comment
comment|// indicate that the instruction cannot be added to the current packet.
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
name|LLVM_CODEGEN_DFAPACKETIZER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_DFAPACKETIZER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleDAGMutation.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DefaultVLIWScheduler
decl_stmt|;
name|class
name|InstrItineraryData
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineLoopInfo
decl_stmt|;
name|class
name|MCInstrDesc
decl_stmt|;
name|class
name|SUnit
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
comment|// --------------------------------------------------------------------
comment|// Definitions shared between DFAPacketizer.cpp and DFAPacketizerEmitter.cpp
comment|// DFA_MAX_RESTERMS * DFA_MAX_RESOURCES must fit within sizeof DFAInput.
comment|// This is verified in DFAPacketizer.cpp:DFAPacketizer::DFAPacketizer.
comment|//
comment|// e.g. terms x resource bit combinations that fit in uint32_t:
comment|//      4 terms x 8  bits = 32 bits
comment|//      3 terms x 10 bits = 30 bits
comment|//      2 terms x 16 bits = 32 bits
comment|//
comment|// e.g. terms x resource bit combinations that fit in uint64_t:
comment|//      8 terms x 8  bits = 64 bits
comment|//      7 terms x 9  bits = 63 bits
comment|//      6 terms x 10 bits = 60 bits
comment|//      5 terms x 12 bits = 60 bits
comment|//      4 terms x 16 bits = 64 bits<--- current
comment|//      3 terms x 21 bits = 63 bits
comment|//      2 terms x 32 bits = 64 bits
comment|//
define|#
directive|define
name|DFA_MAX_RESTERMS
value|4
comment|// The max # of AND'ed resource terms.
define|#
directive|define
name|DFA_MAX_RESOURCES
value|16
comment|// The max # of resource bits in one term.
name|using
name|DFAInput
init|=
name|uint64_t
decl_stmt|;
name|using
name|DFAStateInput
init|=
name|int64_t
decl_stmt|;
define|#
directive|define
name|DFA_TBLTYPE
value|"int64_t"
comment|// For generating DFAStateInputTable.
comment|// --------------------------------------------------------------------
name|class
name|DFAPacketizer
block|{
name|private
label|:
name|using
name|UnsignPair
init|=
name|std
operator|::
name|pair
operator|<
name|unsigned
decl_stmt|,
name|DFAInput
decl|>
decl_stmt|;
specifier|const
name|InstrItineraryData
modifier|*
name|InstrItins
decl_stmt|;
name|int
name|CurrentState
init|=
literal|0
decl_stmt|;
specifier|const
name|DFAStateInput
argument_list|(
operator|*
name|DFAStateInputTable
argument_list|)
index|[
literal|2
index|]
expr_stmt|;
specifier|const
name|unsigned
modifier|*
name|DFAStateEntryTable
decl_stmt|;
comment|// CachedTable is a map from<FromState, Input> to ToState.
name|DenseMap
operator|<
name|UnsignPair
operator|,
name|unsigned
operator|>
name|CachedTable
expr_stmt|;
comment|// Read the DFA transition table and update CachedTable.
name|void
name|ReadTable
parameter_list|(
name|unsigned
name|state
parameter_list|)
function_decl|;
name|public
label|:
name|DFAPacketizer
argument_list|(
specifier|const
name|InstrItineraryData
operator|*
name|I
argument_list|,
specifier|const
name|DFAStateInput
argument_list|(
operator|*
name|SIT
argument_list|)
index|[
literal|2
index|]
argument_list|,
specifier|const
name|unsigned
operator|*
name|SET
argument_list|)
expr_stmt|;
comment|// Reset the current state to make all resources available.
name|void
name|clearResources
parameter_list|()
block|{
name|CurrentState
operator|=
literal|0
expr_stmt|;
block|}
comment|// Return the DFAInput for an instruction class.
name|DFAInput
name|getInsnInput
parameter_list|(
name|unsigned
name|InsnClass
parameter_list|)
function_decl|;
comment|// Return the DFAInput for an instruction class input vector.
specifier|static
name|DFAInput
name|getInsnInput
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
operator|&
name|InsnClass
argument_list|)
decl_stmt|;
comment|// Check if the resources occupied by a MCInstrDesc are available in
comment|// the current state.
name|bool
name|canReserveResources
parameter_list|(
specifier|const
name|MCInstrDesc
modifier|*
name|MID
parameter_list|)
function_decl|;
comment|// Reserve the resources occupied by a MCInstrDesc and change the current
comment|// state to reflect that change.
name|void
name|reserveResources
parameter_list|(
specifier|const
name|MCInstrDesc
modifier|*
name|MID
parameter_list|)
function_decl|;
comment|// Check if the resources occupied by a machine instruction are available
comment|// in the current state.
name|bool
name|canReserveResources
parameter_list|(
name|MachineInstr
modifier|&
name|MI
parameter_list|)
function_decl|;
comment|// Reserve the resources occupied by a machine instruction and change the
comment|// current state to reflect that change.
name|void
name|reserveResources
parameter_list|(
name|MachineInstr
modifier|&
name|MI
parameter_list|)
function_decl|;
specifier|const
name|InstrItineraryData
operator|*
name|getInstrItins
argument_list|()
specifier|const
block|{
return|return
name|InstrItins
return|;
block|}
block|}
empty_stmt|;
comment|// VLIWPacketizerList implements a simple VLIW packetizer using DFA. The
comment|// packetizer works on machine basic blocks. For each instruction I in BB,
comment|// the packetizer consults the DFA to see if machine resources are available
comment|// to execute I. If so, the packetizer checks if I depends on any instruction
comment|// in the current packet. If no dependency is found, I is added to current
comment|// packet and the machine resource is marked as taken. If any dependency is
comment|// found, a target API call is made to prune the dependence.
name|class
name|VLIWPacketizerList
block|{
name|protected
label|:
name|MachineFunction
modifier|&
name|MF
decl_stmt|;
specifier|const
name|TargetInstrInfo
modifier|*
name|TII
decl_stmt|;
name|AliasAnalysis
modifier|*
name|AA
decl_stmt|;
comment|// The VLIW Scheduler.
name|DefaultVLIWScheduler
modifier|*
name|VLIWScheduler
decl_stmt|;
comment|// Vector of instructions assigned to the current packet.
name|std
operator|::
name|vector
operator|<
name|MachineInstr
operator|*
operator|>
name|CurrentPacketMIs
expr_stmt|;
comment|// DFA resource tracker.
name|DFAPacketizer
modifier|*
name|ResourceTracker
decl_stmt|;
comment|// Map: MI -> SU.
name|std
operator|::
name|map
operator|<
name|MachineInstr
operator|*
operator|,
name|SUnit
operator|*
operator|>
name|MIToSUnit
expr_stmt|;
name|public
label|:
comment|// The AliasAnalysis parameter can be nullptr.
name|VLIWPacketizerList
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|,
name|MachineLoopInfo
operator|&
name|MLI
argument_list|,
name|AliasAnalysis
operator|*
name|AA
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|VLIWPacketizerList
argument_list|()
expr_stmt|;
comment|// Implement this API in the backend to bundle instructions.
name|void
name|PacketizeMIs
argument_list|(
name|MachineBasicBlock
operator|*
name|MBB
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|BeginItr
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|EndItr
argument_list|)
decl_stmt|;
comment|// Return the ResourceTracker.
name|DFAPacketizer
modifier|*
name|getResourceTracker
parameter_list|()
block|{
return|return
name|ResourceTracker
return|;
block|}
comment|// addToPacket - Add MI to the current packet.
name|virtual
name|MachineBasicBlock
operator|::
name|iterator
name|addToPacket
argument_list|(
argument|MachineInstr&MI
argument_list|)
block|{
name|CurrentPacketMIs
operator|.
name|push_back
argument_list|(
operator|&
name|MI
argument_list|)
block|;
name|ResourceTracker
operator|->
name|reserveResources
argument_list|(
name|MI
argument_list|)
block|;
return|return
name|MI
return|;
block|}
comment|// End the current packet and reset the state of the packetizer.
comment|// Overriding this function allows the target-specific packetizer
comment|// to perform custom finalization.
name|virtual
name|void
name|endPacket
argument_list|(
name|MachineBasicBlock
operator|*
name|MBB
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|MI
argument_list|)
decl_stmt|;
comment|// Perform initialization before packetizing an instruction. This
comment|// function is supposed to be overrided by the target dependent packetizer.
name|virtual
name|void
name|initPacketizerState
parameter_list|()
block|{}
comment|// Check if the given instruction I should be ignored by the packetizer.
name|virtual
name|bool
name|ignorePseudoInstruction
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|I
parameter_list|,
specifier|const
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
block|{
return|return
name|false
return|;
block|}
comment|// Return true if instruction MI can not be packetized with any other
comment|// instruction, which means that MI itself is a packet.
name|virtual
name|bool
name|isSoloInstruction
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Check if the packetizer should try to add the given instruction to
comment|// the current packet. One reasons for which it may not be desirable
comment|// to include an instruction in the current packet could be that it
comment|// would cause a stall.
comment|// If this function returns "false", the current packet will be ended,
comment|// and the instruction will be added to the next packet.
name|virtual
name|bool
name|shouldAddToPacket
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Check if it is legal to packetize SUI and SUJ together.
name|virtual
name|bool
name|isLegalToPacketizeTogether
parameter_list|(
name|SUnit
modifier|*
name|SUI
parameter_list|,
name|SUnit
modifier|*
name|SUJ
parameter_list|)
block|{
return|return
name|false
return|;
block|}
comment|// Check if it is legal to prune dependece between SUI and SUJ.
name|virtual
name|bool
name|isLegalToPruneDependencies
parameter_list|(
name|SUnit
modifier|*
name|SUI
parameter_list|,
name|SUnit
modifier|*
name|SUJ
parameter_list|)
block|{
return|return
name|false
return|;
block|}
comment|// Add a DAG mutation to be done before the packetization begins.
name|void
name|addMutation
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|ScheduleDAGMutation
operator|>
name|Mutation
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_DFAPACKETIZER_H
end_comment

end_unit

