begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MipsMCCodeEmitter.h - Convert Mips Code to Machine Code --*- C++ -*-===//
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
comment|// This file defines the MipsMCCodeEmitter class.
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
name|LLVM_LIB_TARGET_MIPS_MCTARGETDESC_MIPSMCCODEEMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_MIPS_MCTARGETDESC_MIPSMCCODEEMITTER_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCCodeEmitter.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
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
name|class
name|MipsMCCodeEmitter
range|:
name|public
name|MCCodeEmitter
block|{
specifier|const
name|MCInstrInfo
operator|&
name|MCII
block|;
name|MCContext
operator|&
name|Ctx
block|;
name|bool
name|IsLittleEndian
block|;
name|bool
name|isMicroMips
argument_list|(
argument|const MCSubtargetInfo&STI
argument_list|)
specifier|const
block|;
name|bool
name|isMips32r6
argument_list|(
argument|const MCSubtargetInfo&STI
argument_list|)
specifier|const
block|;
name|public
operator|:
name|MipsMCCodeEmitter
argument_list|(
argument|const MCInstrInfo&mcii
argument_list|,
argument|MCContext&Ctx_
argument_list|,
argument|bool IsLittle
argument_list|)
operator|:
name|MCII
argument_list|(
name|mcii
argument_list|)
block|,
name|Ctx
argument_list|(
name|Ctx_
argument_list|)
block|,
name|IsLittleEndian
argument_list|(
argument|IsLittle
argument_list|)
block|{}
name|MipsMCCodeEmitter
argument_list|(
specifier|const
name|MipsMCCodeEmitter
operator|&
argument_list|)
operator|=
name|delete
block|;
name|MipsMCCodeEmitter
operator|&
name|operator
operator|=
operator|(
specifier|const
name|MipsMCCodeEmitter
operator|&
operator|)
operator|=
name|delete
block|;
operator|~
name|MipsMCCodeEmitter
argument_list|()
name|override
operator|=
expr|default
block|;
name|void
name|EmitByte
argument_list|(
argument|unsigned char C
argument_list|,
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;
name|void
name|EmitInstruction
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
comment|// getBinaryCodeForInstr - TableGen'erated function for getting the
comment|// binary encoding for an instruction.
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
comment|// getJumpTargetOpValue - Return binary encoding of the jump
comment|// target operand. If the machine operand requires relocation,
comment|// record the relocation and return zero.
name|unsigned
name|getJumpTargetOpValue
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
comment|// getBranchJumpOpValueMM - Return binary encoding of the microMIPS jump
comment|// target operand. If the machine operand requires relocation,
comment|// record the relocation and return zero.
name|unsigned
name|getJumpTargetOpValueMM
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
comment|// getUImm5Lsl2Encoding - Return binary encoding of the microMIPS jump
comment|// target operand.
name|unsigned
name|getUImm5Lsl2Encoding
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
name|unsigned
name|getSImm3Lsa2Value
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
name|unsigned
name|getUImm6Lsl2Encoding
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
comment|// getSImm9AddiuspValue - Return binary encoding of the microMIPS addiusp
comment|// instruction immediate operand.
name|unsigned
name|getSImm9AddiuspValue
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
comment|// getBranchTargetOpValue - Return binary encoding of the branch
comment|// target operand. If the machine operand requires relocation,
comment|// record the relocation and return zero.
name|unsigned
name|getBranchTargetOpValue
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
comment|// getBranchTargetOpValue1SImm16 - Return binary encoding of the branch
comment|// target operand. If the machine operand requires relocation,
comment|// record the relocation and return zero.
name|unsigned
name|getBranchTargetOpValue1SImm16
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
comment|// getBranchTargetOpValueMMR6 - Return binary encoding of the branch
comment|// target operand. If the machine operand requires relocation,
comment|// record the relocation and return zero.
name|unsigned
name|getBranchTargetOpValueMMR6
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
comment|// getBranchTargetOpValueLsl2MMR6 - Return binary encoding of the branch
comment|// target operand. If the machine operand requires relocation,
comment|// record the relocation and return zero.
name|unsigned
name|getBranchTargetOpValueLsl2MMR6
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
comment|// getBranchTarget7OpValue - Return binary encoding of the microMIPS branch
comment|// target operand. If the machine operand requires relocation,
comment|// record the relocation and return zero.
name|unsigned
name|getBranchTarget7OpValueMM
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
comment|// getBranchTargetOpValueMMPC10 - Return binary encoding of the microMIPS
comment|// 10-bit branch target operand. If the machine operand requires relocation,
comment|// record the relocation and return zero.
name|unsigned
name|getBranchTargetOpValueMMPC10
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
comment|// getBranchTargetOpValue - Return binary encoding of the microMIPS branch
comment|// target operand. If the machine operand requires relocation,
comment|// record the relocation and return zero.
name|unsigned
name|getBranchTargetOpValueMM
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
comment|// getBranchTarget21OpValue - Return binary encoding of the branch
comment|// offset operand. If the machine operand requires relocation,
comment|// record the relocation and return zero.
name|unsigned
name|getBranchTarget21OpValue
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
comment|// getBranchTarget21OpValueMM - Return binary encoding of the branch
comment|// offset operand for microMIPS. If the machine operand requires
comment|// relocation,record the relocation and return zero.
name|unsigned
name|getBranchTarget21OpValueMM
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
comment|// getBranchTarget26OpValue - Return binary encoding of the branch
comment|// offset operand. If the machine operand requires relocation,
comment|// record the relocation and return zero.
name|unsigned
name|getBranchTarget26OpValue
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
comment|// getBranchTarget26OpValueMM - Return binary encoding of the branch
comment|// offset operand. If the machine operand requires relocation,
comment|// record the relocation and return zero.
name|unsigned
name|getBranchTarget26OpValueMM
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
comment|// getJumpOffset16OpValue - Return binary encoding of the jump
comment|// offset operand. If the machine operand requires relocation,
comment|// record the relocation and return zero.
name|unsigned
name|getJumpOffset16OpValue
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
comment|// getMachineOpValue - Return binary encoding of operand. If the machin
comment|// operand requires relocation, record the relocation and return zero.
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
name|unsigned
name|getMSAMemEncoding
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
name|template
operator|<
name|unsigned
name|ShiftAmount
operator|=
literal|0
operator|>
name|unsigned
name|getMemEncoding
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
name|unsigned
name|getMemEncodingMMImm4
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
name|unsigned
name|getMemEncodingMMImm4Lsl1
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
name|unsigned
name|getMemEncodingMMImm4Lsl2
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
name|unsigned
name|getMemEncodingMMSPImm5Lsl2
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
name|unsigned
name|getMemEncodingMMGPImm7Lsl2
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
name|unsigned
name|getMemEncodingMMImm9
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
name|unsigned
name|getMemEncodingMMImm11
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
name|unsigned
name|getMemEncodingMMImm12
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
name|unsigned
name|getMemEncodingMMImm16
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
name|unsigned
name|getMemEncodingMMImm4sp
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
name|unsigned
name|getSizeInsEncoding
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
comment|/// Subtract Offset then encode as a N-bit unsigned integer.
name|template
operator|<
name|unsigned
name|Bits
block|,
name|int
name|Offset
operator|>
name|unsigned
name|getUImmWithOffsetEncoding
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
name|unsigned
name|getSimm19Lsl2Encoding
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
name|unsigned
name|getSimm18Lsl3Encoding
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
name|unsigned
name|getUImm3Mod8Encoding
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
name|unsigned
name|getUImm4AndValue
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
name|unsigned
name|getRegisterPairOpValue
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
name|unsigned
name|getMovePRegPairOpValue
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
name|unsigned
name|getSimm23Lsl2Encoding
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
name|unsigned
name|getRegisterListOpValue
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
name|unsigned
name|getRegisterListOpValue16
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
name|private
operator|:
name|void
name|LowerCompactBranch
argument_list|(
argument|MCInst& Inst
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

begin_comment
comment|// LLVM_LIB_TARGET_MIPS_MCTARGETDESC_MIPSMCCODEEMITTER_H
end_comment

end_unit

