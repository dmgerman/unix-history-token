begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=-- Hexagon.h - Top-level interface for Hexagon representation --*- C++ -*-=//
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
comment|// This file contains the entry points for global functions defined in the LLVM
end_comment

begin_comment
comment|// Hexagon back-end.
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
name|LLVM_LIB_TARGET_HEXAGON_HEXAGON_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_HEXAGON_HEXAGON_H
end_define

begin_define
define|#
directive|define
name|Hexagon_POINTER_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|Hexagon_PointerSize
value|(Hexagon_POINTER_SIZE)
end_define

begin_define
define|#
directive|define
name|Hexagon_PointerSize_Bits
value|(Hexagon_POINTER_SIZE * 8)
end_define

begin_define
define|#
directive|define
name|Hexagon_WordSize
value|Hexagon_PointerSize
end_define

begin_define
define|#
directive|define
name|Hexagon_WordSize_Bits
value|Hexagon_PointerSize_Bits
end_define

begin_comment
comment|// allocframe saves LR and FP on stack before allocating
end_comment

begin_comment
comment|// a new stack frame. This takes 8 bytes.
end_comment

begin_define
define|#
directive|define
name|HEXAGON_LRFP_SIZE
value|8
end_define

begin_comment
comment|// Normal instruction size (in bytes).
end_comment

begin_define
define|#
directive|define
name|HEXAGON_INSTR_SIZE
value|4
end_define

begin_comment
comment|// Maximum number of words and instructions in a packet.
end_comment

begin_define
define|#
directive|define
name|HEXAGON_PACKET_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|HEXAGON_MAX_PACKET_SIZE
value|(HEXAGON_PACKET_SIZE * HEXAGON_INSTR_SIZE)
end_define

begin_comment
comment|// Minimum number of instructions in an end-loop packet.
end_comment

begin_define
define|#
directive|define
name|HEXAGON_PACKET_INNER_SIZE
value|2
end_define

begin_define
define|#
directive|define
name|HEXAGON_PACKET_OUTER_SIZE
value|3
end_define

begin_comment
comment|// Maximum number of instructions in a packet before shuffling,
end_comment

begin_comment
comment|// including a compound one or a duplex or an extender.
end_comment

begin_define
define|#
directive|define
name|HEXAGON_PRESHUFFLE_PACKET_SIZE
value|(HEXAGON_PACKET_SIZE + 3)
end_define

begin_comment
comment|// Name of the global offset table as defined by the Hexagon ABI
end_comment

begin_define
define|#
directive|define
name|HEXAGON_GOT_SYM_NAME
value|"_GLOBAL_OFFSET_TABLE_"
end_define

begin_include
include|#
directive|include
file|"MCTargetDesc/HexagonMCTargetDesc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetLowering.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|HexagonTargetMachine
decl_stmt|;
comment|/// \brief Creates a Hexagon-specific Target Transformation Info pass.
name|ImmutablePass
modifier|*
name|createHexagonTargetTransformInfoPass
parameter_list|(
specifier|const
name|HexagonTargetMachine
modifier|*
name|TM
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm;
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

