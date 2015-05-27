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
name|MCSubtargetInfo
specifier|const
operator|&
name|MST
block|;
name|MCContext
operator|&
name|MCT
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
name|MCSubtargetInfo
specifier|const
operator|&
name|aMST
argument_list|,
name|MCContext
operator|&
name|aMCT
argument_list|)
block|;
name|MCSubtargetInfo
specifier|const
operator|&
name|getSubtargetInfo
argument_list|()
specifier|const
block|;
name|void
name|EncodeInstruction
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
name|HexagonMCCodeEmitter
argument_list|(
argument|HexagonMCCodeEmitter const&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|void
name|operator
operator|=
operator|(
name|HexagonMCCodeEmitter
specifier|const
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
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

