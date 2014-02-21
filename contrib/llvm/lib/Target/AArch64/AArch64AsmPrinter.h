begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// AArch64AsmPrinter.h - Print machine code to an AArch64 .s file -*- C++ -*-=//
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
comment|// This file defines the AArch64 assembly printer class.
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
name|LLVM_AARCH64ASMPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_AARCH64ASMPRINTER_H
end_define

begin_include
include|#
directive|include
file|"AArch64.h"
end_include

begin_include
include|#
directive|include
file|"AArch64TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/AsmPrinter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCStreamer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCOperand
decl_stmt|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|AArch64AsmPrinter
range|:
name|public
name|AsmPrinter
block|{
comment|/// Subtarget - Keep a pointer to the AArch64Subtarget around so that we can
comment|/// make the right decision when printing asm code for different targets.
specifier|const
name|AArch64Subtarget
operator|*
name|Subtarget
block|;
comment|// emitPseudoExpansionLowering - tblgen'erated.
name|bool
name|emitPseudoExpansionLowering
argument_list|(
name|MCStreamer
operator|&
name|OutStreamer
argument_list|,
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
block|;
name|public
operator|:
name|explicit
name|AArch64AsmPrinter
argument_list|(
name|TargetMachine
operator|&
name|TM
argument_list|,
name|MCStreamer
operator|&
name|Streamer
argument_list|)
operator|:
name|AsmPrinter
argument_list|(
argument|TM
argument_list|,
argument|Streamer
argument_list|)
block|{
name|Subtarget
operator|=
operator|&
name|TM
operator|.
name|getSubtarget
operator|<
name|AArch64Subtarget
operator|>
operator|(
operator|)
block|;   }
name|bool
name|lowerOperand
argument_list|(
argument|const MachineOperand&MO
argument_list|,
argument|MCOperand&MCOp
argument_list|)
specifier|const
block|;
name|MCOperand
name|lowerSymbolOperand
argument_list|(
argument|const MachineOperand&MO
argument_list|,
argument|const MCSymbol *Sym
argument_list|)
specifier|const
block|;
name|void
name|EmitInstruction
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
block|;
name|void
name|EmitEndOfAsmFile
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|bool
name|PrintAsmOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned OpNum
argument_list|,
argument|unsigned AsmVariant
argument_list|,
argument|const char *ExtraCode
argument_list|,
argument|raw_ostream&O
argument_list|)
block|;
name|bool
name|PrintAsmMemoryOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned OpNum
argument_list|,
argument|unsigned AsmVariant
argument_list|,
argument|const char *ExtraCode
argument_list|,
argument|raw_ostream&O
argument_list|)
block|;
comment|/// printSymbolicAddress - Given some kind of reasonably bare symbolic
comment|/// reference, print out the appropriate asm string to represent it. If
comment|/// appropriate, a relocation-specifier will be produced, composed of a
comment|/// general class derived from the MO parameter and an instruction-specific
comment|/// suffix, provided in Suffix. E.g. ":got_lo12:" if a Suffix of "lo12" is
comment|/// given.
name|bool
name|printSymbolicAddress
argument_list|(
argument|const MachineOperand&MO
argument_list|,
argument|bool PrintImmediatePrefix
argument_list|,
argument|StringRef Suffix
argument_list|,
argument|raw_ostream&O
argument_list|)
block|;
name|virtual
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
block|{
return|return
literal|"AArch64 Assembly Printer"
return|;
block|}
name|virtual
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
name|MF
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

