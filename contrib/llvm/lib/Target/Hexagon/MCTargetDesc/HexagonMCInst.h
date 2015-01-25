begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- HexagonMCInst.h - Hexagon sub-class of MCInst ----------------------===//
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
comment|// This class extends MCInst to allow some VLIW annotations.
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
name|LLVM_LIB_TARGET_HEXAGON_MCTARGETDESC_HEXAGONMCINST_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_HEXAGON_MCTARGETDESC_HEXAGONMCINST_H
end_define

begin_include
include|#
directive|include
file|"HexagonTargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCInst.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_extern
extern|extern
literal|"C"
name|void
name|LLVMInitializeHexagonTargetMC
parameter_list|()
function_decl|;
end_extern

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCOperand
decl_stmt|;
name|class
name|HexagonMCInst
range|:
name|public
name|MCInst
block|{
name|friend
name|void
operator|::
name|LLVMInitializeHexagonTargetMC
argument_list|()
block|;
comment|// Used to access TSFlags
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|MCInstrInfo
specifier|const
operator|>
name|MCII
block|;
name|public
operator|:
name|explicit
name|HexagonMCInst
argument_list|()
block|;
name|HexagonMCInst
argument_list|(
specifier|const
name|MCInstrDesc
operator|&
name|mcid
argument_list|)
block|;
specifier|static
name|void
name|AppendImplicitOperands
argument_list|(
name|MCInst
operator|&
name|MCI
argument_list|)
block|;
specifier|static
name|std
operator|::
name|bitset
operator|<
literal|16
operator|>
name|GetImplicitBits
argument_list|(
name|MCInst
specifier|const
operator|&
name|MCI
argument_list|)
block|;
specifier|static
name|void
name|SetImplicitBits
argument_list|(
name|MCInst
operator|&
name|MCI
argument_list|,
name|std
operator|::
name|bitset
operator|<
literal|16
operator|>
name|Bits
argument_list|)
block|;
specifier|static
name|void
name|SanityCheckImplicitOperands
argument_list|(
argument|MCInst const&MCI
argument_list|)
block|{
name|assert
argument_list|(
name|MCI
operator|.
name|getNumOperands
argument_list|()
operator|>=
literal|2
operator|&&
literal|"At least the two implicit operands"
argument_list|)
block|;
name|assert
argument_list|(
name|MCI
operator|.
name|getOperand
argument_list|(
name|MCI
operator|.
name|getNumOperands
argument_list|()
operator|-
literal|1
argument_list|)
operator|.
name|isInst
argument_list|()
operator|&&
literal|"Implicit bits and flags"
argument_list|)
block|;
name|assert
argument_list|(
name|MCI
operator|.
name|getOperand
argument_list|(
name|MCI
operator|.
name|getNumOperands
argument_list|()
operator|-
literal|2
argument_list|)
operator|.
name|isImm
argument_list|()
operator|&&
literal|"Parent pointer"
argument_list|)
block|;   }
name|void
name|setPacketBegin
argument_list|(
argument|bool Y
argument_list|)
block|;
name|bool
name|isPacketBegin
argument_list|()
specifier|const
block|;
specifier|static
specifier|const
name|size_t
name|packetBeginIndex
operator|=
literal|0
block|;
name|void
name|setPacketEnd
argument_list|(
argument|bool Y
argument_list|)
block|;
name|bool
name|isPacketEnd
argument_list|()
specifier|const
block|;
specifier|static
specifier|const
name|size_t
name|packetEndIndex
operator|=
literal|1
block|;
name|void
name|resetPacket
argument_list|()
block|;
comment|// Return the slots used by the insn.
name|unsigned
name|getUnits
argument_list|(
argument|const HexagonTargetMachine *TM
argument_list|)
specifier|const
block|;
comment|// Return the Hexagon ISA class for the insn.
name|unsigned
name|getType
argument_list|()
specifier|const
block|;
name|MCInstrDesc
specifier|const
operator|&
name|getDesc
argument_list|()
specifier|const
block|;
comment|// Return whether the insn is an actual insn.
name|bool
name|isCanon
argument_list|()
specifier|const
block|;
comment|// Return whether the insn is a prefix.
name|bool
name|isPrefix
argument_list|()
specifier|const
block|;
comment|// Return whether the insn is solo, i.e., cannot be in a packet.
name|bool
name|isSolo
argument_list|()
specifier|const
block|;
comment|// Return whether the instruction needs to be constant extended.
name|bool
name|isConstExtended
argument_list|()
specifier|const
block|;
comment|// Return constant extended operand number.
name|unsigned
name|short
name|getCExtOpNum
argument_list|(
argument|void
argument_list|)
specifier|const
block|;
comment|// Return whether the insn is a new-value consumer.
name|bool
name|isNewValue
argument_list|()
specifier|const
block|;
comment|// Return whether the instruction is a legal new-value producer.
name|bool
name|hasNewValue
argument_list|()
specifier|const
block|;
comment|// Return the operand that consumes or produces a new value.
specifier|const
name|MCOperand
operator|&
name|getNewValue
argument_list|()
specifier|const
block|;
comment|// Return number of bits in the constant extended operand.
name|unsigned
name|getBitCount
argument_list|(
argument|void
argument_list|)
specifier|const
block|;
name|private
operator|:
comment|// Return whether the instruction must be always extended.
name|bool
name|isExtended
argument_list|()
specifier|const
block|;
comment|// Return true if the insn may be extended based on the operand value.
name|bool
name|isExtendable
argument_list|()
specifier|const
block|;
comment|// Return true if the operand can be constant extended.
name|bool
name|isOperandExtended
argument_list|(
argument|const unsigned short OperandNum
argument_list|)
specifier|const
block|;
comment|// Return the min value that a constant extendable operand can have
comment|// without being extended.
name|int
name|getMinValue
argument_list|()
specifier|const
block|;
comment|// Return the max value that a constant extendable operand can have
comment|// without being extended.
name|int
name|getMaxValue
argument_list|()
specifier|const
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

