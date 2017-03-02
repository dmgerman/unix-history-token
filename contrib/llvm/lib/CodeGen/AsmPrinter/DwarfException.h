begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DwarfException.h - Dwarf Exception Framework -----------*- C++ -*--===//
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
comment|// This file contains support for writing dwarf exception info into asm files.
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
name|LLVM_LIB_CODEGEN_ASMPRINTER_DWARFEXCEPTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_ASMPRINTER_DWARFEXCEPTION_H
end_define

begin_include
include|#
directive|include
file|"EHStreamer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/AsmPrinter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCDwarf.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineFunction
decl_stmt|;
name|class
name|ARMTargetStreamer
decl_stmt|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|DwarfCFIExceptionBase
range|:
name|public
name|EHStreamer
block|{
name|protected
operator|:
name|DwarfCFIExceptionBase
argument_list|(
name|AsmPrinter
operator|*
name|A
argument_list|)
block|;
comment|/// Per-function flag to indicate if frame CFI info should be emitted.
name|bool
name|shouldEmitCFI
block|;
comment|/// Per-module flag to indicate if .cfi_section has beeen emitted.
name|bool
name|hasEmittedCFISections
block|;
name|void
name|markFunctionEnd
argument_list|()
name|override
block|;
name|void
name|endFragment
argument_list|()
name|override
block|; }
decl_stmt|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|DwarfCFIException
range|:
name|public
name|DwarfCFIExceptionBase
block|{
comment|/// Per-function flag to indicate if .cfi_personality should be emitted.
name|bool
name|shouldEmitPersonality
block|;
comment|/// Per-function flag to indicate if .cfi_personality must be emitted.
name|bool
name|forceEmitPersonality
block|;
comment|/// Per-function flag to indicate if .cfi_lsda should be emitted.
name|bool
name|shouldEmitLSDA
block|;
comment|/// Per-function flag to indicate if frame moves info should be emitted.
name|bool
name|shouldEmitMoves
block|;
name|public
operator|:
comment|//===--------------------------------------------------------------------===//
comment|// Main entry points.
comment|//
name|DwarfCFIException
argument_list|(
name|AsmPrinter
operator|*
name|A
argument_list|)
block|;
operator|~
name|DwarfCFIException
argument_list|()
name|override
block|;
comment|/// Emit all exception information that should come after the content.
name|void
name|endModule
argument_list|()
name|override
block|;
comment|/// Gather pre-function exception information.  Assumes being emitted
comment|/// immediately after the function entry point.
name|void
name|beginFunction
argument_list|(
argument|const MachineFunction *MF
argument_list|)
name|override
block|;
comment|/// Gather and emit post-function exception information.
name|void
name|endFunction
argument_list|(
argument|const MachineFunction *
argument_list|)
name|override
block|;
name|void
name|beginFragment
argument_list|(
argument|const MachineBasicBlock *MBB
argument_list|,
argument|ExceptionSymbolProvider ESP
argument_list|)
name|override
block|; }
decl_stmt|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|ARMException
range|:
name|public
name|DwarfCFIExceptionBase
block|{
name|void
name|emitTypeInfos
argument_list|(
argument|unsigned TTypeEncoding
argument_list|)
name|override
block|;
name|ARMTargetStreamer
operator|&
name|getTargetStreamer
argument_list|()
block|;
name|public
operator|:
comment|//===--------------------------------------------------------------------===//
comment|// Main entry points.
comment|//
name|ARMException
argument_list|(
name|AsmPrinter
operator|*
name|A
argument_list|)
block|;
operator|~
name|ARMException
argument_list|()
name|override
block|;
comment|/// Emit all exception information that should come after the content.
name|void
name|endModule
argument_list|()
name|override
block|{}
comment|/// Gather pre-function exception information.  Assumes being emitted
comment|/// immediately after the function entry point.
name|void
name|beginFunction
argument_list|(
argument|const MachineFunction *MF
argument_list|)
name|override
block|;
comment|/// Gather and emit post-function exception information.
name|void
name|endFunction
argument_list|(
argument|const MachineFunction *
argument_list|)
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End of namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

