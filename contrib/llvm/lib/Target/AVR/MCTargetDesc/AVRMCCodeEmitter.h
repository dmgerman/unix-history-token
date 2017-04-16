begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AVRMCCodeEmitter.h - Convert AVR Code to Machine Code -------------===//
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
comment|// This file defines the AVRMCCodeEmitter class.
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_AVR_CODE_EMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_AVR_CODE_EMITTER_H
end_define

begin_include
include|#
directive|include
file|"AVRFixupKinds.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCCodeEmitter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_define
define|#
directive|define
name|GET_INSTRINFO_OPERAND_TYPES_ENUM
end_define

begin_include
include|#
directive|include
file|"AVRGenInstrInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCContext
decl_stmt|;
name|class
name|MCExpr
decl_stmt|;
name|class
name|MCFixup
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|class
name|MCInstrInfo
decl_stmt|;
name|class
name|MCOperand
decl_stmt|;
name|class
name|MCSubtargetInfo
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// Writes AVR machine code to a stream.
name|class
name|AVRMCCodeEmitter
range|:
name|public
name|MCCodeEmitter
block|{
name|public
operator|:
name|AVRMCCodeEmitter
argument_list|(
specifier|const
name|MCInstrInfo
operator|&
name|MCII
argument_list|,
name|MCContext
operator|&
name|Ctx
argument_list|)
operator|:
name|MCII
argument_list|(
name|MCII
argument_list|)
block|,
name|Ctx
argument_list|(
argument|Ctx
argument_list|)
block|{}
name|private
operator|:
comment|/// Finishes up encoding an LD/ST instruction.
comment|/// The purpose of this function is to set an bit in the instruction
comment|/// which follows no logical pattern. See the implementation for details.
name|unsigned
name|loadStorePostEncoder
argument_list|(
argument|const MCInst&MI
argument_list|,
argument|unsigned EncodedValue
argument_list|,
argument|const MCSubtargetInfo&STI
argument_list|)
specifier|const
block|;
comment|/// Gets the encoding for a conditional branch target.
name|template
operator|<
name|AVR
operator|::
name|Fixups
name|Fixup
operator|>
name|unsigned
name|encodeRelCondBrTarget
argument_list|(
argument|const MCInst&MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|SmallVectorImpl<MCFixup>&Fixups
argument_list|,
argument|const MCSubtargetInfo&STI
argument_list|)
specifier|const
block|;
comment|/// Encodes the `PTRREGS` operand to a load or store instruction.
name|unsigned
name|encodeLDSTPtrReg
argument_list|(
argument|const MCInst&MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|SmallVectorImpl<MCFixup>&Fixups
argument_list|,
argument|const MCSubtargetInfo&STI
argument_list|)
specifier|const
block|;
comment|/// Encodes a `register+immediate` operand for `LDD`/`STD`.
name|unsigned
name|encodeMemri
argument_list|(
argument|const MCInst&MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|SmallVectorImpl<MCFixup>&Fixups
argument_list|,
argument|const MCSubtargetInfo&STI
argument_list|)
specifier|const
block|;
comment|/// Takes the complement of a number (~0 - val).
name|unsigned
name|encodeComplement
argument_list|(
argument|const MCInst&MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|SmallVectorImpl<MCFixup>&Fixups
argument_list|,
argument|const MCSubtargetInfo&STI
argument_list|)
specifier|const
block|;
comment|/// Encodes an immediate value with a given fixup.
name|template
operator|<
name|AVR
operator|::
name|Fixups
name|Fixup
operator|>
name|unsigned
name|encodeImm
argument_list|(
argument|const MCInst&MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|SmallVectorImpl<MCFixup>&Fixups
argument_list|,
argument|const MCSubtargetInfo&STI
argument_list|)
specifier|const
block|;
comment|/// Gets the encoding of the target for the `CALL k` instruction.
name|unsigned
name|encodeCallTarget
argument_list|(
argument|const MCInst&MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|SmallVectorImpl<MCFixup>&Fixups
argument_list|,
argument|const MCSubtargetInfo&STI
argument_list|)
specifier|const
block|;
comment|/// TableGen'ed function to get the binary encoding for an instruction.
name|uint64_t
name|getBinaryCodeForInstr
argument_list|(
argument|const MCInst&MI
argument_list|,
argument|SmallVectorImpl<MCFixup>&Fixups
argument_list|,
argument|const MCSubtargetInfo&STI
argument_list|)
specifier|const
block|;
name|unsigned
name|getExprOpValue
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|SmallVectorImpl<MCFixup>&Fixups
argument_list|,
argument|const MCSubtargetInfo&STI
argument_list|)
specifier|const
block|;
comment|/// Returns the binary encoding of operand.
comment|///
comment|/// If the machine operand requires relocation, the relocation is recorded
comment|/// and zero is returned.
name|unsigned
name|getMachineOpValue
argument_list|(
argument|const MCInst&MI
argument_list|,
argument|const MCOperand&MO
argument_list|,
argument|SmallVectorImpl<MCFixup>&Fixups
argument_list|,
argument|const MCSubtargetInfo&STI
argument_list|)
specifier|const
block|;
name|void
name|emitInstruction
argument_list|(
argument|uint64_t Val
argument_list|,
argument|unsigned Size
argument_list|,
argument|const MCSubtargetInfo&STI
argument_list|,
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;
name|void
name|encodeInstruction
argument_list|(
argument|const MCInst&MI
argument_list|,
argument|raw_ostream&OS
argument_list|,
argument|SmallVectorImpl<MCFixup>&Fixups
argument_list|,
argument|const MCSubtargetInfo&STI
argument_list|)
specifier|const
name|override
block|;
name|AVRMCCodeEmitter
argument_list|(
specifier|const
name|AVRMCCodeEmitter
operator|&
argument_list|)
operator|=
name|delete
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|AVRMCCodeEmitter
operator|&
operator|)
operator|=
name|delete
block|;
specifier|const
name|MCInstrInfo
operator|&
name|MCII
block|;
name|MCContext
operator|&
name|Ctx
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace of llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_AVR_CODE_EMITTER_H
end_comment

end_unit

