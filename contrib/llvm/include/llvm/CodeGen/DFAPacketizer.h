begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- llvm/CodeGen/DFAPacketizer.h - DFA Packetizer for VLIW ---*- C++ -*-=====//
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
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCInstrDesc
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineLoopInfo
decl_stmt|;
name|class
name|MachineDominatorTree
decl_stmt|;
name|class
name|InstrItineraryData
decl_stmt|;
name|class
name|ScheduleDAGInstrs
decl_stmt|;
name|class
name|SUnit
decl_stmt|;
name|class
name|DFAPacketizer
block|{
name|private
label|:
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
name|UnsignPair
expr_stmt|;
specifier|const
name|InstrItineraryData
modifier|*
name|InstrItins
decl_stmt|;
name|int
name|CurrentState
decl_stmt|;
specifier|const
name|int
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
comment|// ReadTable - Read the DFA transition table and update CachedTable.
name|void
name|ReadTable
parameter_list|(
name|unsigned
name|int
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
name|int
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
comment|// canReserveResources - Check if the resources occupied by a MCInstrDesc
comment|// are available in the current state.
name|bool
name|canReserveResources
argument_list|(
specifier|const
name|llvm
operator|::
name|MCInstrDesc
operator|*
name|MID
argument_list|)
decl_stmt|;
comment|// reserveResources - Reserve the resources occupied by a MCInstrDesc and
comment|// change the current state to reflect that change.
name|void
name|reserveResources
argument_list|(
specifier|const
name|llvm
operator|::
name|MCInstrDesc
operator|*
name|MID
argument_list|)
decl_stmt|;
comment|// canReserveResources - Check if the resources occupied by a machine
comment|// instruction are available in the current state.
name|bool
name|canReserveResources
argument_list|(
name|llvm
operator|::
name|MachineInstr
operator|*
name|MI
argument_list|)
decl_stmt|;
comment|// reserveResources - Reserve the resources occupied by a machine
comment|// instruction and change the current state to reflect that change.
name|void
name|reserveResources
argument_list|(
name|llvm
operator|::
name|MachineInstr
operator|*
name|MI
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
comment|// VLIWPacketizerList - Implements a simple VLIW packetizer using DFA. The
comment|// packetizer works on machine basic blocks. For each instruction I in BB, the
comment|// packetizer consults the DFA to see if machine resources are available to
comment|// execute I. If so, the packetizer checks if I depends on any instruction J in
comment|// the current packet. If no dependency is found, I is added to current packet
comment|// and machine resource is marked as taken. If any dependency is found, a target
comment|// API call is made to prune the dependence.
name|class
name|VLIWPacketizerList
block|{
specifier|const
name|TargetMachine
modifier|&
name|TM
decl_stmt|;
specifier|const
name|MachineFunction
modifier|&
name|MF
decl_stmt|;
specifier|const
name|TargetInstrInfo
modifier|*
name|TII
decl_stmt|;
comment|// Encapsulate data types not exposed to the target interface.
name|ScheduleDAGInstrs
modifier|*
name|SchedulerImpl
decl_stmt|;
name|protected
label|:
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
comment|// Scheduling units.
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|>
name|SUnits
expr_stmt|;
name|public
label|:
name|VLIWPacketizerList
argument_list|(
argument|MachineFunction&MF
argument_list|,
argument|MachineLoopInfo&MLI
argument_list|,
argument|MachineDominatorTree&MDT
argument_list|,
argument|bool IsPostRA
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|VLIWPacketizerList
argument_list|()
expr_stmt|;
comment|// PacketizeMIs - Implement this API in the backend to bundle instructions.
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
comment|// getResourceTracker - return ResourceTracker
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
name|void
name|addToPacket
parameter_list|(
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
comment|// endPacket - End the current packet.
name|void
name|endPacket
parameter_list|(
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|,
name|MachineInstr
modifier|*
name|I
parameter_list|)
function_decl|;
comment|// ignorePseudoInstruction - Ignore bundling of pseudo instructions.
name|bool
name|ignorePseudoInstruction
parameter_list|(
name|MachineInstr
modifier|*
name|I
parameter_list|,
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
function_decl|;
comment|// isSoloInstruction - return true if instruction I must end previous
comment|// packet.
name|bool
name|isSoloInstruction
parameter_list|(
name|MachineInstr
modifier|*
name|I
parameter_list|)
function_decl|;
comment|// isLegalToPacketizeTogether - Is it legal to packetize SUI and SUJ
comment|// together.
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
comment|// isLegalToPruneDependencies - Is it legal to prune dependece between SUI
comment|// and SUJ.
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
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

