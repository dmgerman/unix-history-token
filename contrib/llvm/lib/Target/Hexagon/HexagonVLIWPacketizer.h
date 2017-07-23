begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|HEXAGONVLIWPACKETIZER_H
end_ifndef

begin_define
define|#
directive|define
name|HEXAGONVLIWPACKETIZER_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/DFAPacketizer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBranchProbabilityInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleDAGInstrs.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|HexagonInstrInfo
decl_stmt|;
name|class
name|HexagonRegisterInfo
decl_stmt|;
name|class
name|HexagonPacketizerList
range|:
name|public
name|VLIWPacketizerList
block|{
comment|// Vector of instructions assigned to the packet that has just been created.
name|std
operator|::
name|vector
operator|<
name|MachineInstr
operator|*
operator|>
name|OldPacketMIs
block|;
comment|// Has the instruction been promoted to a dot-new instruction.
name|bool
name|PromotedToDotNew
block|;
comment|// Has the instruction been glued to allocframe.
name|bool
name|GlueAllocframeStore
block|;
comment|// Has the feeder instruction been glued to new value jump.
name|bool
name|GlueToNewValueJump
block|;
comment|// Check if there is a dependence between some instruction already in this
comment|// packet and this instruction.
name|bool
name|Dependence
block|;
comment|// Only check for dependence if there are resources available to
comment|// schedule this instruction.
name|bool
name|FoundSequentialDependence
block|;
comment|// Track MIs with ignored dependence.
name|std
operator|::
name|vector
operator|<
name|MachineInstr
operator|*
operator|>
name|IgnoreDepMIs
block|;
comment|// Set to true if the packet contains an instruction that stalls with an
comment|// instruction from the previous packet.
name|bool
name|PacketStalls
operator|=
name|false
block|;
name|protected
operator|:
comment|/// \brief A handle to the branch probability pass.
specifier|const
name|MachineBranchProbabilityInfo
operator|*
name|MBPI
block|;
specifier|const
name|MachineLoopInfo
operator|*
name|MLI
block|;
name|private
operator|:
specifier|const
name|HexagonInstrInfo
operator|*
name|HII
block|;
specifier|const
name|HexagonRegisterInfo
operator|*
name|HRI
block|;
name|public
operator|:
comment|// Ctor.
name|HexagonPacketizerList
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
argument_list|,
specifier|const
name|MachineBranchProbabilityInfo
operator|*
name|MBPI
argument_list|)
block|;
comment|// initPacketizerState - initialize some internal flags.
name|void
name|initPacketizerState
argument_list|()
name|override
block|;
comment|// ignorePseudoInstruction - Ignore bundling of pseudo instructions.
name|bool
name|ignorePseudoInstruction
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|const MachineBasicBlock *MBB
argument_list|)
name|override
block|;
comment|// isSoloInstruction - return true if instruction MI can not be packetized
comment|// with any other instruction, which means that MI itself is a packet.
name|bool
name|isSoloInstruction
argument_list|(
argument|const MachineInstr&MI
argument_list|)
name|override
block|;
comment|// isLegalToPacketizeTogether - Is it legal to packetize SUI and SUJ
comment|// together.
name|bool
name|isLegalToPacketizeTogether
argument_list|(
argument|SUnit *SUI
argument_list|,
argument|SUnit *SUJ
argument_list|)
name|override
block|;
comment|// isLegalToPruneDependencies - Is it legal to prune dependece between SUI
comment|// and SUJ.
name|bool
name|isLegalToPruneDependencies
argument_list|(
argument|SUnit *SUI
argument_list|,
argument|SUnit *SUJ
argument_list|)
name|override
block|;
name|MachineBasicBlock
operator|::
name|iterator
name|addToPacket
argument_list|(
argument|MachineInstr&MI
argument_list|)
name|override
block|;
name|void
name|endPacket
argument_list|(
argument|MachineBasicBlock *MBB
argument_list|,
argument|MachineBasicBlock::iterator MI
argument_list|)
name|override
block|;
name|bool
name|shouldAddToPacket
argument_list|(
argument|const MachineInstr&MI
argument_list|)
name|override
block|;
name|void
name|unpacketizeSoloInstrs
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
name|protected
operator|:
name|bool
name|isCallDependent
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|SDep::Kind DepType
argument_list|,
argument|unsigned DepReg
argument_list|)
block|;
name|bool
name|promoteToDotCur
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|SDep::Kind DepType
argument_list|,
argument|MachineBasicBlock::iterator&MII
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|)
block|;
name|bool
name|canPromoteToDotCur
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|const SUnit *PacketSU
argument_list|,
argument|unsigned DepReg
argument_list|,
argument|MachineBasicBlock::iterator&MII
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|)
block|;
name|void
name|cleanUpDotCur
argument_list|()
block|;
name|bool
name|promoteToDotNew
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|SDep::Kind DepType
argument_list|,
argument|MachineBasicBlock::iterator&MII
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|)
block|;
name|bool
name|canPromoteToDotNew
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|const SUnit *PacketSU
argument_list|,
argument|unsigned DepReg
argument_list|,
argument|MachineBasicBlock::iterator&MII
argument_list|,
argument|const TargetRegisterClass *RC
argument_list|)
block|;
name|bool
name|canPromoteToNewValue
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|const SUnit *PacketSU
argument_list|,
argument|unsigned DepReg
argument_list|,
argument|MachineBasicBlock::iterator&MII
argument_list|)
block|;
name|bool
name|canPromoteToNewValueStore
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|const MachineInstr&PacketMI
argument_list|,
argument|unsigned DepReg
argument_list|)
block|;
name|bool
name|demoteToDotOld
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|)
block|;
name|bool
name|useCallersSP
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|)
block|;
name|void
name|useCalleesSP
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|)
block|;
name|bool
name|arePredicatesComplements
argument_list|(
name|MachineInstr
operator|&
name|MI1
argument_list|,
name|MachineInstr
operator|&
name|MI2
argument_list|)
block|;
name|bool
name|restrictingDepExistInPacket
argument_list|(
name|MachineInstr
operator|&
argument_list|,
name|unsigned
argument_list|)
block|;
name|bool
name|isNewifiable
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|,
specifier|const
name|TargetRegisterClass
operator|*
name|NewRC
argument_list|)
block|;
name|bool
name|isCurifiable
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|)
block|;
name|bool
name|cannotCoexist
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|,
specifier|const
name|MachineInstr
operator|&
name|MJ
argument_list|)
block|;
specifier|inline
name|bool
name|isPromotedToDotNew
argument_list|()
specifier|const
block|{
return|return
name|PromotedToDotNew
return|;
block|}
name|bool
name|tryAllocateResourcesForConstExt
argument_list|(
argument|bool Reserve
argument_list|)
block|;
name|bool
name|canReserveResourcesForConstExt
argument_list|()
block|;
name|void
name|reserveResourcesForConstExt
argument_list|()
block|;
name|bool
name|hasDeadDependence
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|I
argument_list|,
specifier|const
name|MachineInstr
operator|&
name|J
argument_list|)
block|;
name|bool
name|hasControlDependence
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|I
argument_list|,
specifier|const
name|MachineInstr
operator|&
name|J
argument_list|)
block|;
name|bool
name|hasRegMaskDependence
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|I
argument_list|,
specifier|const
name|MachineInstr
operator|&
name|J
argument_list|)
block|;
name|bool
name|hasV4SpecificDependence
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|I
argument_list|,
specifier|const
name|MachineInstr
operator|&
name|J
argument_list|)
block|;
name|bool
name|producesStall
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
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
comment|// HEXAGONVLIWPACKETIZER_H
end_comment

end_unit

