begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsAsmPrinter.h - Mips LLVM assembly writer ----------------------===//
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
comment|// Mips Assembly printer class.
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
name|MIPSASMPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|MIPSASMPRINTER_H
end_define

begin_include
include|#
directive|include
file|"MipsSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/AsmPrinter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
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
name|MCStreamer
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|MipsAsmPrinter
range|:
name|public
name|AsmPrinter
block|{
specifier|const
name|MipsSubtarget
operator|*
name|Subtarget
block|;
name|public
operator|:
name|explicit
name|MipsAsmPrinter
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
name|MipsSubtarget
operator|>
operator|(
operator|)
block|;   }
name|virtual
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
block|{
return|return
literal|"Mips Assembly Printer"
return|;
block|}
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
name|printSavedRegsBitmask
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|)
block|;
name|void
name|printHex32
argument_list|(
argument|unsigned int Value
argument_list|,
argument|raw_ostream&O
argument_list|)
block|;
name|void
name|emitFrameDirective
argument_list|()
block|;
specifier|const
name|char
operator|*
name|getCurrentABIString
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|EmitFunctionEntryLabel
argument_list|()
block|;
name|virtual
name|void
name|EmitFunctionBodyStart
argument_list|()
block|;
name|virtual
name|void
name|EmitFunctionBodyEnd
argument_list|()
block|;
name|virtual
name|bool
name|isBlockOnlyReachableByFallthrough
argument_list|(
argument|const MachineBasicBlock*                                                  MBB
argument_list|)
specifier|const
block|;
name|bool
name|PrintAsmOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned OpNo
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
name|void
name|printOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int opNum
argument_list|,
argument|raw_ostream&O
argument_list|)
block|;
name|void
name|printUnsignedImm
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int opNum
argument_list|,
argument|raw_ostream&O
argument_list|)
block|;
name|void
name|printMemOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int opNum
argument_list|,
argument|raw_ostream&O
argument_list|)
block|;
name|void
name|printMemOperandEA
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int opNum
argument_list|,
argument|raw_ostream&O
argument_list|)
block|;
name|void
name|printFCCOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|int opNum
argument_list|,
argument|raw_ostream&O
argument_list|,
argument|const char *Modifier =
literal|0
argument_list|)
block|;
name|void
name|EmitStartOfAsmFile
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|virtual
name|MachineLocation
name|getDebugValueLocation
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
name|void
name|PrintDebugValueComment
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

