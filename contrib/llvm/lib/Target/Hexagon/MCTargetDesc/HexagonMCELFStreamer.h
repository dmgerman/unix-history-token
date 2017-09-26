begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- HexagonMCELFStreamer.h - Hexagon subclass of MCElfStreamer ---------===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_HEXAGON_MCTARGETDESC_HEXAGONMCELFSTREAMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_HEXAGON_MCTARGETDESC_HEXAGONMCELFSTREAMER_H
end_define

begin_include
include|#
directive|include
file|"MCTargetDesc/HexagonMCTargetDesc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCELFStreamer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|HexagonMCELFStreamer
range|:
name|public
name|MCELFStreamer
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|MCInstrInfo
operator|>
name|MCII
block|;
name|public
operator|:
name|HexagonMCELFStreamer
argument_list|(
name|MCContext
operator|&
name|Context
argument_list|,
name|MCAsmBackend
operator|&
name|TAB
argument_list|,
name|raw_pwrite_stream
operator|&
name|OS
argument_list|,
name|MCCodeEmitter
operator|*
name|Emitter
argument_list|)
operator|:
name|MCELFStreamer
argument_list|(
name|Context
argument_list|,
name|TAB
argument_list|,
name|OS
argument_list|,
name|Emitter
argument_list|)
block|,
name|MCII
argument_list|(
argument|createHexagonMCInstrInfo()
argument_list|)
block|{}
name|HexagonMCELFStreamer
argument_list|(
name|MCContext
operator|&
name|Context
argument_list|,
name|MCAsmBackend
operator|&
name|TAB
argument_list|,
name|raw_pwrite_stream
operator|&
name|OS
argument_list|,
name|MCCodeEmitter
operator|*
name|Emitter
argument_list|,
name|MCAssembler
operator|*
name|Assembler
argument_list|)
operator|:
name|MCELFStreamer
argument_list|(
name|Context
argument_list|,
name|TAB
argument_list|,
name|OS
argument_list|,
name|Emitter
argument_list|)
block|,
name|MCII
argument_list|(
argument|createHexagonMCInstrInfo()
argument_list|)
block|{}
name|void
name|EmitInstruction
argument_list|(
argument|const MCInst&Inst
argument_list|,
argument|const MCSubtargetInfo&STI
argument_list|,
argument|bool
argument_list|)
name|override
block|;
name|void
name|EmitSymbol
argument_list|(
specifier|const
name|MCInst
operator|&
name|Inst
argument_list|)
block|;
name|void
name|HexagonMCEmitLocalCommonSymbol
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|uint64_t Size
argument_list|,
argument|unsigned ByteAlignment
argument_list|,
argument|unsigned AccessSize
argument_list|)
block|;
name|void
name|HexagonMCEmitCommonSymbol
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|uint64_t Size
argument_list|,
argument|unsigned ByteAlignment
argument_list|,
argument|unsigned AccessSize
argument_list|)
block|; }
decl_stmt|;
name|MCStreamer
modifier|*
name|createHexagonELFStreamer
parameter_list|(
name|Triple
specifier|const
modifier|&
name|TT
parameter_list|,
name|MCContext
modifier|&
name|Context
parameter_list|,
name|MCAsmBackend
modifier|&
name|MAB
parameter_list|,
name|raw_pwrite_stream
modifier|&
name|OS
parameter_list|,
name|MCCodeEmitter
modifier|*
name|CE
parameter_list|)
function_decl|;
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
comment|// LLVM_LIB_TARGET_HEXAGON_MCTARGETDESC_HEXAGONMCELFSTREAMER_H
end_comment

end_unit

