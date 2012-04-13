begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PTXAsmPrinter.h - Print machine code to a PTX file ----------------===//
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
comment|// PTX Assembly printer class.
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
name|PTXASMPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|PTXASMPRINTER_H
end_define

begin_include
include|#
directive|include
file|"PTX.h"
end_include

begin_include
include|#
directive|include
file|"PTXTargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCOperand
decl_stmt|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|PTXAsmPrinter
range|:
name|public
name|AsmPrinter
block|{
name|public
operator|:
name|explicit
name|PTXAsmPrinter
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
block|{}
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
block|{
return|return
literal|"PTX Assembly Printer"
return|;
block|}
name|bool
name|doFinalization
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
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
name|EmitFunctionBodyStart
argument_list|()
block|;
name|virtual
name|void
name|EmitFunctionBodyEnd
argument_list|()
block|;
name|virtual
name|void
name|EmitFunctionEntryLabel
argument_list|()
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
name|unsigned
name|GetOrCreateSourceID
argument_list|(
argument|StringRef FileName
argument_list|,
argument|StringRef DirName
argument_list|)
block|;
name|MCOperand
name|GetSymbolRef
argument_list|(
specifier|const
name|MachineOperand
operator|&
name|MO
argument_list|,
specifier|const
name|MCSymbol
operator|*
name|Symbol
argument_list|)
block|;
name|MCOperand
name|lowerOperand
argument_list|(
specifier|const
name|MachineOperand
operator|&
name|MO
argument_list|)
block|;
name|private
operator|:
name|void
name|EmitVariableDeclaration
argument_list|(
specifier|const
name|GlobalVariable
operator|*
name|gv
argument_list|)
block|;
name|void
name|EmitFunctionDeclaration
argument_list|()
block|;
name|StringMap
operator|<
name|unsigned
operator|>
name|SourceIdMap
block|; }
decl_stmt|;
comment|// class PTXAsmPrinter
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

