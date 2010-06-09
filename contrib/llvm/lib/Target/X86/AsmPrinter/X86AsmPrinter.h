begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- X86AsmPrinter.h - Convert X86 LLVM code to assembly -----*- C++ -*-===//
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
comment|// AT&T assembly code printer class.
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
name|X86ASMPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|X86ASMPRINTER_H
end_define

begin_include
include|#
directive|include
file|"../X86.h"
end_include

begin_include
include|#
directive|include
file|"../X86MachineFunctionInfo.h"
end_include

begin_include
include|#
directive|include
file|"../X86TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/AsmPrinter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineModuleInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ValueTypes.h"
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
name|MachineJumpTableInfo
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|class
name|MCStreamer
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|X86AsmPrinter
range|:
name|public
name|AsmPrinter
block|{
specifier|const
name|X86Subtarget
operator|*
name|Subtarget
block|;
name|public
operator|:
name|explicit
name|X86AsmPrinter
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
name|X86Subtarget
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
literal|"X86 AT&T-Style Assembly Printer"
return|;
block|}
specifier|const
name|X86Subtarget
operator|&
name|getSubtarget
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Subtarget
return|;
block|}
name|virtual
name|void
name|EmitStartOfAsmFile
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|virtual
name|void
name|EmitEndOfAsmFile
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|virtual
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
name|printSymbolOperand
argument_list|(
specifier|const
name|MachineOperand
operator|&
name|MO
argument_list|,
name|raw_ostream
operator|&
name|O
argument_list|)
block|;
comment|// These methods are used by the tablegen'erated instruction printer.
name|void
name|printOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|raw_ostream&O
argument_list|,
argument|const char *Modifier =
literal|0
argument_list|)
block|;
name|void
name|print_pcrel_imm
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|raw_ostream&O
argument_list|)
block|;
name|bool
name|printAsmMRegister
argument_list|(
argument|const MachineOperand&MO
argument_list|,
argument|char Mode
argument_list|,
argument|raw_ostream&O
argument_list|)
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
argument|raw_ostream&OS
argument_list|)
block|;
name|bool
name|PrintAsmMemoryOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|unsigned AsmVariant
argument_list|,
argument|const char *ExtraCode
argument_list|,
argument|raw_ostream&OS
argument_list|)
block|;
name|void
name|printMachineInstruction
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
block|;
name|void
name|printSSECC
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned Op
argument_list|,
argument|raw_ostream&O
argument_list|)
block|;
name|void
name|printMemReference
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned Op
argument_list|,
argument|raw_ostream&O
argument_list|,
argument|const char *Modifier=NULL
argument_list|)
block|;
name|void
name|printLeaMemReference
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned Op
argument_list|,
argument|raw_ostream&O
argument_list|,
argument|const char *Modifier=NULL
argument_list|)
block|;
name|void
name|printPICLabel
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned Op
argument_list|,
argument|raw_ostream&O
argument_list|)
block|;
name|void
name|PrintPICBaseSymbol
argument_list|(
argument|raw_ostream&O
argument_list|)
specifier|const
block|;
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
name|F
argument_list|)
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
block|;
name|MachineLocation
name|getDebugValueLocation
argument_list|(
argument|const MachineInstr *MI
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

end_unit

