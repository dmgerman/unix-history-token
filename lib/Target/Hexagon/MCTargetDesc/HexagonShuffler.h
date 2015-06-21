begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- HexagonShuffler.h - Instruction bundle shuffling ---------------===//
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
comment|// This implements the shuffling of insns inside a bundle according to the
end_comment

begin_comment
comment|// packet formation rules of the Hexagon ISA.
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
name|HEXAGONSHUFFLER_H
end_ifndef

begin_define
define|#
directive|define
name|HEXAGONSHUFFLER_H
end_define

begin_include
include|#
directive|include
file|"Hexagon.h"
end_include

begin_include
include|#
directive|include
file|"MCTargetDesc/HexagonMCInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCInstrInfo.h"
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
comment|// Insn resources.
name|class
name|HexagonResource
block|{
comment|// Mask of the slots or units that may execute the insn and
comment|// the weight or priority that the insn requires to be assigned a slot.
name|unsigned
name|Slots
decl_stmt|,
name|Weight
decl_stmt|;
name|public
label|:
name|HexagonResource
argument_list|(
argument|unsigned s
argument_list|)
block|{
name|setUnits
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
name|void
name|setUnits
parameter_list|(
name|unsigned
name|s
parameter_list|)
block|{
name|Slots
operator|=
name|s
operator|&
operator|~
operator|(
operator|-
literal|1
operator|<<
name|HEXAGON_PACKET_SIZE
operator|)
expr_stmt|;
name|setWeight
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
name|unsigned
name|setWeight
parameter_list|(
name|unsigned
name|s
parameter_list|)
function_decl|;
name|unsigned
name|getUnits
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Slots
operator|)
return|;
block|}
empty_stmt|;
name|unsigned
name|getWeight
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Weight
operator|)
return|;
block|}
empty_stmt|;
comment|// Check if the resources are in ascending slot order.
specifier|static
name|bool
name|lessUnits
parameter_list|(
specifier|const
name|HexagonResource
modifier|&
name|A
parameter_list|,
specifier|const
name|HexagonResource
modifier|&
name|B
parameter_list|)
block|{
return|return
operator|(
name|countPopulation
argument_list|(
name|A
operator|.
name|getUnits
argument_list|()
argument_list|)
operator|<
name|countPopulation
argument_list|(
name|B
operator|.
name|getUnits
argument_list|()
argument_list|)
operator|)
return|;
block|}
empty_stmt|;
comment|// Check if the resources are in ascending weight order.
specifier|static
name|bool
name|lessWeight
parameter_list|(
specifier|const
name|HexagonResource
modifier|&
name|A
parameter_list|,
specifier|const
name|HexagonResource
modifier|&
name|B
parameter_list|)
block|{
return|return
operator|(
name|A
operator|.
name|getWeight
argument_list|()
operator|<
name|B
operator|.
name|getWeight
argument_list|()
operator|)
return|;
block|}
empty_stmt|;
block|}
empty_stmt|;
comment|// Handle to an insn used by the shuffling algorithm.
name|class
name|HexagonInstr
block|{
name|friend
name|class
name|HexagonShuffler
decl_stmt|;
name|MCInst
specifier|const
modifier|*
name|ID
decl_stmt|;
name|MCInst
specifier|const
modifier|*
name|Extender
decl_stmt|;
name|HexagonResource
name|Core
decl_stmt|;
name|bool
name|SoloException
decl_stmt|;
name|public
label|:
name|HexagonInstr
argument_list|(
argument|MCInst const *id
argument_list|,
argument|MCInst const *Extender
argument_list|,
argument|unsigned s
argument_list|,
argument|bool x = false
argument_list|)
block|:
name|ID
argument_list|(
name|id
argument_list|)
operator|,
name|Extender
argument_list|(
name|Extender
argument_list|)
operator|,
name|Core
argument_list|(
name|s
argument_list|)
operator|,
name|SoloException
argument_list|(
argument|x
argument_list|)
block|{}
expr_stmt|;
name|MCInst
specifier|const
operator|*
name|getDesc
argument_list|()
specifier|const
block|{
return|return
operator|(
name|ID
operator|)
return|;
block|}
empty_stmt|;
name|MCInst
specifier|const
operator|*
name|getExtender
argument_list|()
specifier|const
block|{
return|return
name|Extender
return|;
block|}
name|unsigned
name|isSoloException
argument_list|()
specifier|const
block|{
return|return
operator|(
name|SoloException
operator|)
return|;
block|}
empty_stmt|;
comment|// Check if the handles are in ascending order for shuffling purposes.
name|bool
name|operator
operator|<
operator|(
specifier|const
name|HexagonInstr
operator|&
name|B
operator|)
specifier|const
block|{
return|return
operator|(
name|HexagonResource
operator|::
name|lessWeight
argument_list|(
name|B
operator|.
name|Core
argument_list|,
name|Core
argument_list|)
operator|)
return|;
block|}
empty_stmt|;
comment|// Check if the handles are in ascending order by core slots.
specifier|static
name|bool
name|lessCore
parameter_list|(
specifier|const
name|HexagonInstr
modifier|&
name|A
parameter_list|,
specifier|const
name|HexagonInstr
modifier|&
name|B
parameter_list|)
block|{
return|return
operator|(
name|HexagonResource
operator|::
name|lessUnits
argument_list|(
name|A
operator|.
name|Core
argument_list|,
name|B
operator|.
name|Core
argument_list|)
operator|)
return|;
block|}
empty_stmt|;
block|}
empty_stmt|;
comment|// Bundle shuffler.
name|class
name|HexagonShuffler
block|{
typedef|typedef
name|SmallVector
operator|<
name|HexagonInstr
operator|,
name|HEXAGON_PRESHUFFLE_PACKET_SIZE
operator|>
name|HexagonPacket
expr_stmt|;
comment|// Insn handles in a bundle.
name|HexagonPacket
name|Packet
decl_stmt|;
comment|// Shuffling error code.
name|unsigned
name|Error
decl_stmt|;
name|protected
label|:
name|int64_t
name|BundleFlags
decl_stmt|;
name|MCInstrInfo
specifier|const
modifier|&
name|MCII
decl_stmt|;
name|MCSubtargetInfo
specifier|const
modifier|&
name|STI
decl_stmt|;
name|public
label|:
typedef|typedef
name|HexagonPacket
operator|::
name|iterator
name|iterator
expr_stmt|;
enum|enum
block|{
name|SHUFFLE_SUCCESS
init|=
literal|0
block|,
comment|///< Successful operation.
name|SHUFFLE_ERROR_INVALID
block|,
comment|///< Invalid bundle.
name|SHUFFLE_ERROR_STORES
block|,
comment|///< No free slots for store insns.
name|SHUFFLE_ERROR_LOADS
block|,
comment|///< No free slots for load insns.
name|SHUFFLE_ERROR_BRANCHES
block|,
comment|///< No free slots for branch insns.
name|SHUFFLE_ERROR_NOSLOTS
block|,
comment|///< No free slots for other insns.
name|SHUFFLE_ERROR_SLOTS
block|,
comment|///< Over-subscribed slots.
name|SHUFFLE_ERROR_UNKNOWN
comment|///< Unknown error.
block|}
enum|;
name|explicit
name|HexagonShuffler
parameter_list|(
name|MCInstrInfo
specifier|const
modifier|&
name|MCII
parameter_list|,
name|MCSubtargetInfo
specifier|const
modifier|&
name|STI
parameter_list|)
function_decl|;
comment|// Reset to initial state.
name|void
name|reset
parameter_list|()
function_decl|;
comment|// Check if the bundle may be validly shuffled.
name|bool
name|check
parameter_list|()
function_decl|;
comment|// Reorder the insn handles in the bundle.
name|bool
name|shuffle
parameter_list|()
function_decl|;
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Packet
operator|.
name|size
argument_list|()
operator|)
return|;
block|}
empty_stmt|;
name|iterator
name|begin
parameter_list|()
block|{
return|return
operator|(
name|Packet
operator|.
name|begin
argument_list|()
operator|)
return|;
block|}
empty_stmt|;
name|iterator
name|end
parameter_list|()
block|{
return|return
operator|(
name|Packet
operator|.
name|end
argument_list|()
operator|)
return|;
block|}
empty_stmt|;
comment|// Add insn handle to the bundle .
name|void
name|append
parameter_list|(
name|MCInst
specifier|const
modifier|*
name|ID
parameter_list|,
name|MCInst
specifier|const
modifier|*
name|Extender
parameter_list|,
name|unsigned
name|S
parameter_list|,
name|bool
name|X
init|=
name|false
parameter_list|)
function_decl|;
comment|// Return the error code for the last check or shuffling of the bundle.
name|void
name|setError
parameter_list|(
name|unsigned
name|Err
parameter_list|)
block|{
name|Error
operator|=
name|Err
expr_stmt|;
block|}
empty_stmt|;
name|unsigned
name|getError
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Error
operator|)
return|;
block|}
empty_stmt|;
block|}
empty_stmt|;
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
comment|// HEXAGONSHUFFLER_H
end_comment

end_unit

