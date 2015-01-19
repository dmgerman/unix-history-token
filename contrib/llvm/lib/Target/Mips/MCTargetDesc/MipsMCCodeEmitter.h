begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsMCCodeEmitter.h - Convert Mips Code to Machine Code -----------===//
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

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIPS_MC_CODE_EMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|MIPS_MC_CODE_EMITTER_H
end_define

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
name|class
name|MCContext
decl_stmt|;
name|class
name|MCExpr
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|class
name|MCInstrInfo
decl_stmt|;
name|class
name|MCFixup
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
name|MipsMCCodeEmitter
argument_list|(
argument|const MipsMCCodeEmitter&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|MipsMCCodeEmitter
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
block|;
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
operator|~
name|MipsMCCodeEmitter
argument_list|()
block|{}
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
name|EncodeInstruction
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
comment|// getBranchJumpOpValue - Return binary encoding of the jump
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
name|getSizeExtEncoding
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
comment|// getLSAImmEncoding - Return binary encoding of LSA immediate.
name|unsigned
name|getLSAImmEncoding
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
name|getExprOpValue
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|SmallVectorImpl<MCFixup>&Fixups
argument_list|,
argument|const MCSubtargetInfo&STI
argument_list|)
specifier|const
block|;  }
decl_stmt|;
comment|// class MipsMCCodeEmitter
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

