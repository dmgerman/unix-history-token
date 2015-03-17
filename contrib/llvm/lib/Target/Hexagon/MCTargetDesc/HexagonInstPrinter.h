begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HexagonInstPrinter.h - Convert Hexagon MCInst to assembly syntax --===//
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
comment|// This class prints an Hexagon MCInst to a .s file.
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
name|LLVM_LIB_TARGET_HEXAGON_INSTPRINTER_HEXAGONINSTPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_HEXAGON_INSTPRINTER_HEXAGONINSTPRINTER_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCInstPrinter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCInstrInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|HexagonMCInst
decl_stmt|;
name|class
name|HexagonInstPrinter
range|:
name|public
name|MCInstPrinter
block|{
name|public
operator|:
name|explicit
name|HexagonInstPrinter
argument_list|(
specifier|const
name|MCAsmInfo
operator|&
name|MAI
argument_list|,
specifier|const
name|MCInstrInfo
operator|&
name|MII
argument_list|,
specifier|const
name|MCRegisterInfo
operator|&
name|MRI
argument_list|)
operator|:
name|MCInstPrinter
argument_list|(
name|MAI
argument_list|,
name|MII
argument_list|,
name|MRI
argument_list|)
block|,
name|MII
argument_list|(
argument|MII
argument_list|)
block|{}
name|void
name|printInst
argument_list|(
argument|const MCInst *MI
argument_list|,
argument|raw_ostream&O
argument_list|,
argument|StringRef Annot
argument_list|)
name|override
block|;
name|void
name|printInst
argument_list|(
argument|const HexagonMCInst *MI
argument_list|,
argument|raw_ostream&O
argument_list|,
argument|StringRef Annot
argument_list|)
block|;
name|virtual
name|StringRef
name|getOpcodeName
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|void
name|printInstruction
argument_list|(
specifier|const
name|MCInst
operator|*
name|MI
argument_list|,
name|raw_ostream
operator|&
name|O
argument_list|)
block|;
name|StringRef
name|getRegName
argument_list|(
argument|unsigned RegNo
argument_list|)
specifier|const
block|;
specifier|static
specifier|const
name|char
operator|*
name|getRegisterName
argument_list|(
argument|unsigned RegNo
argument_list|)
block|;
name|void
name|printOperand
argument_list|(
argument|const MCInst *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|raw_ostream&O
argument_list|)
specifier|const
block|;
name|void
name|printImmOperand
argument_list|(
argument|const MCInst *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|raw_ostream&O
argument_list|)
specifier|const
block|;
name|void
name|printExtOperand
argument_list|(
argument|const MCInst *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|raw_ostream&O
argument_list|)
specifier|const
block|;
name|void
name|printUnsignedImmOperand
argument_list|(
argument|const MCInst *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|raw_ostream&O
argument_list|)
specifier|const
block|;
name|void
name|printNegImmOperand
argument_list|(
argument|const MCInst *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|raw_ostream&O
argument_list|)
specifier|const
block|;
name|void
name|printNOneImmOperand
argument_list|(
argument|const MCInst *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|raw_ostream&O
argument_list|)
specifier|const
block|;
name|void
name|printMEMriOperand
argument_list|(
argument|const MCInst *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|raw_ostream&O
argument_list|)
specifier|const
block|;
name|void
name|printFrameIndexOperand
argument_list|(
argument|const MCInst *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|raw_ostream&O
argument_list|)
specifier|const
block|;
name|void
name|printBranchOperand
argument_list|(
argument|const MCInst *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|raw_ostream&O
argument_list|)
specifier|const
block|;
name|void
name|printCallOperand
argument_list|(
argument|const MCInst *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|raw_ostream&O
argument_list|)
specifier|const
block|;
name|void
name|printAbsAddrOperand
argument_list|(
argument|const MCInst *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|raw_ostream&O
argument_list|)
specifier|const
block|;
name|void
name|printPredicateOperand
argument_list|(
argument|const MCInst *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|raw_ostream&O
argument_list|)
specifier|const
block|;
name|void
name|printGlobalOperand
argument_list|(
argument|const MCInst *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|raw_ostream&O
argument_list|)
specifier|const
block|;
name|void
name|printJumpTable
argument_list|(
argument|const MCInst *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|raw_ostream&O
argument_list|)
specifier|const
block|;
name|void
name|printConstantPool
argument_list|(
argument|const MCInst *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|raw_ostream&O
argument_list|)
specifier|const
block|;
name|void
name|printSymbolHi
argument_list|(
argument|const MCInst *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|raw_ostream&O
argument_list|)
specifier|const
block|{
name|printSymbol
argument_list|(
name|MI
argument_list|,
name|OpNo
argument_list|,
name|O
argument_list|,
name|true
argument_list|)
block|; }
name|void
name|printSymbolLo
argument_list|(
argument|const MCInst *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|raw_ostream&O
argument_list|)
specifier|const
block|{
name|printSymbol
argument_list|(
name|MI
argument_list|,
name|OpNo
argument_list|,
name|O
argument_list|,
name|false
argument_list|)
block|; }
specifier|const
name|MCInstrInfo
operator|&
name|getMII
argument_list|()
specifier|const
block|{
return|return
name|MII
return|;
block|}
name|protected
operator|:
name|void
name|printSymbol
argument_list|(
argument|const MCInst *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|raw_ostream&O
argument_list|,
argument|bool hi
argument_list|)
specifier|const
block|;
specifier|static
specifier|const
name|char
name|PacketPadding
block|;
name|private
operator|:
specifier|const
name|MCInstrInfo
operator|&
name|MII
block|;    }
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

end_unit

