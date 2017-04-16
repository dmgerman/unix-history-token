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

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Prints bundles as a newline separated list of individual instructions
comment|/// Duplexes are separated by a vertical tab \v character
comment|/// A trailing line includes bundle properties such as endloop0/1
comment|///
comment|/// r0 = add(r1, r2)
comment|/// r0 = #0 \v jump 0x0
comment|/// :endloop0 :endloop1
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
name|MCAsmInfo
specifier|const
operator|&
name|MAI
argument_list|,
name|MCInstrInfo
specifier|const
operator|&
name|MII
argument_list|,
name|MCRegisterInfo
specifier|const
operator|&
name|MRI
argument_list|)
block|;
name|void
name|printInst
argument_list|(
argument|MCInst const *MI
argument_list|,
argument|raw_ostream&O
argument_list|,
argument|StringRef Annot
argument_list|,
argument|const MCSubtargetInfo&STI
argument_list|)
name|override
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
name|MCInst
specifier|const
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
name|char
specifier|const
operator|*
name|getRegisterName
argument_list|(
argument|unsigned RegNo
argument_list|)
block|;
name|void
name|printRegName
argument_list|(
argument|raw_ostream&O
argument_list|,
argument|unsigned RegNo
argument_list|)
specifier|const
name|override
block|;
name|void
name|printOperand
argument_list|(
argument|MCInst const *MI
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
argument|MCInst const *MI
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
argument|MCInst const *MI
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
argument|MCInst const *MI
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
argument|MCInst const *MI
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
argument|MCInst const *MI
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
argument|MCInst const *MI
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
argument|MCInst const *MI
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
argument|MCInst const *MI
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
argument|MCInst const *MI
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
argument|MCInst const *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|raw_ostream&O
argument_list|)
specifier|const
block|;
name|void
name|printBrtarget
argument_list|(
argument|MCInst const *MI
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
argument|MCInst const *MI
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
argument|MCInst const *MI
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
block|;   }
name|void
name|printSymbolLo
argument_list|(
argument|MCInst const *MI
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
block|;   }
name|MCAsmInfo
specifier|const
operator|&
name|getMAI
argument_list|()
specifier|const
block|{
return|return
name|MAI
return|;
block|}
name|MCInstrInfo
specifier|const
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
argument|MCInst const *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|raw_ostream&O
argument_list|,
argument|bool hi
argument_list|)
specifier|const
block|;
name|private
operator|:
name|MCInstrInfo
specifier|const
operator|&
name|MII
block|;
name|bool
name|HasExtender
block|;
name|void
name|setExtender
argument_list|(
name|MCInst
specifier|const
operator|&
name|MCI
argument_list|)
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

end_unit

