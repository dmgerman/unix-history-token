begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HexagonMCCodeEmitter.h - Hexagon Target Descriptions ----*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Definition for classes that emit Hexagon machine code from MCInsts
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEXAGONMCCODEEMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|HEXAGONMCCODEEMITTER_H
end_define

begin_include
include|#
directive|include
file|"MCTargetDesc/HexagonFixupKinds.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCCodeEmitter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCExpr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCInst.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSubtargetInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|HexagonMCCodeEmitter
range|:
name|public
name|MCCodeEmitter
block|{
name|MCContext
operator|&
name|MCT
block|;
name|MCInstrInfo
specifier|const
operator|&
name|MCII
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|unsigned
operator|>
name|Addend
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|bool
operator|>
name|Extended
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|MCInst
specifier|const
operator|*
operator|>
name|CurrentBundle
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|size_t
operator|>
name|CurrentIndex
block|;
comment|// helper routine for getMachineOpValue()
name|unsigned
name|getExprOpValue
argument_list|(
argument|const MCInst&MI
argument_list|,
argument|const MCOperand&MO
argument_list|,
argument|const MCExpr *ME
argument_list|,
argument|SmallVectorImpl<MCFixup>&Fixups
argument_list|,
argument|const MCSubtargetInfo&STI
argument_list|)
specifier|const
block|;
name|Hexagon
operator|::
name|Fixups
name|getFixupNoBits
argument_list|(
argument|MCInstrInfo const&MCII
argument_list|,
argument|const MCInst&MI
argument_list|,
argument|const MCOperand&MO
argument_list|,
argument|const MCSymbolRefExpr::VariantKind kind
argument_list|)
specifier|const
block|;
name|public
operator|:
name|HexagonMCCodeEmitter
argument_list|(
name|MCInstrInfo
specifier|const
operator|&
name|aMII
argument_list|,
name|MCContext
operator|&
name|aMCT
argument_list|)
block|;
comment|// Return parse bits for instruction `MCI' inside bundle `MCB'
name|uint32_t
name|parseBits
argument_list|(
argument|size_t Last
argument_list|,
argument|MCInst const&MCB
argument_list|,
argument|MCInst const&MCI
argument_list|)
specifier|const
block|;
name|void
name|encodeInstruction
argument_list|(
argument|MCInst const&MI
argument_list|,
argument|raw_ostream&OS
argument_list|,
argument|SmallVectorImpl<MCFixup>&Fixups
argument_list|,
argument|MCSubtargetInfo const&STI
argument_list|)
specifier|const
name|override
block|;
name|void
name|EncodeSingleInstruction
argument_list|(
argument|const MCInst&MI
argument_list|,
argument|raw_ostream&OS
argument_list|,
argument|SmallVectorImpl<MCFixup>&Fixups
argument_list|,
argument|const MCSubtargetInfo&STI
argument_list|,
argument|uint32_t Parse
argument_list|)
specifier|const
block|;
comment|// \brief TableGen'erated function for getting the
comment|// binary encoding for an instruction.
name|uint64_t
name|getBinaryCodeForInstr
argument_list|(
argument|MCInst const&MI
argument_list|,
argument|SmallVectorImpl<MCFixup>&Fixups
argument_list|,
argument|MCSubtargetInfo const&STI
argument_list|)
specifier|const
block|;
comment|/// \brief Return binary encoding of operand.
name|unsigned
name|getMachineOpValue
argument_list|(
argument|MCInst const&MI
argument_list|,
argument|MCOperand const&MO
argument_list|,
argument|SmallVectorImpl<MCFixup>&Fixups
argument_list|,
argument|MCSubtargetInfo const&STI
argument_list|)
specifier|const
block|;
name|private
operator|:
name|uint64_t
name|computeAvailableFeatures
argument_list|(
argument|const FeatureBitset&FB
argument_list|)
specifier|const
block|;
name|void
name|verifyInstructionPredicates
argument_list|(
argument|const MCInst&MI
argument_list|,
argument|uint64_t AvailableFeatures
argument_list|)
specifier|const
block|; }
decl_stmt|;
comment|// class HexagonMCCodeEmitter
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
comment|/* HEXAGONMCCODEEMITTER_H */
end_comment

end_unit

