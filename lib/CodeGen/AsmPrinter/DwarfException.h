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
name|LLVM_CODEGEN_ASMPRINTER_DWARFEXCEPTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_ASMPRINTER_DWARFEXCEPTION_H
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
name|DwarfCFIException
range|:
name|public
name|EHStreamer
block|{
comment|/// shouldEmitPersonality - Per-function flag to indicate if .cfi_personality
comment|/// should be emitted.
name|bool
name|shouldEmitPersonality
block|;
comment|/// shouldEmitLSDA - Per-function flag to indicate if .cfi_lsda
comment|/// should be emitted.
name|bool
name|shouldEmitLSDA
block|;
comment|/// shouldEmitMoves - Per-function flag to indicate if frame moves info
comment|/// should be emitted.
name|bool
name|shouldEmitMoves
block|;
name|AsmPrinter
operator|::
name|CFIMoveType
name|moveTypeModule
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
name|virtual
operator|~
name|DwarfCFIException
argument_list|()
block|;
comment|/// endModule - Emit all exception information that should come after the
comment|/// content.
name|void
name|endModule
argument_list|()
name|override
block|;
comment|/// beginFunction - Gather pre-function exception information.  Assumes being
comment|/// emitted immediately after the function entry point.
name|void
name|beginFunction
argument_list|(
argument|const MachineFunction *MF
argument_list|)
name|override
block|;
comment|/// endFunction - Gather and emit post-function exception information.
name|void
name|endFunction
argument_list|(
argument|const MachineFunction *
argument_list|)
name|override
block|; }
decl_stmt|;
name|class
name|ARMException
range|:
name|public
name|EHStreamer
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
comment|/// shouldEmitCFI - Per-function flag to indicate if frame CFI info
comment|/// should be emitted.
name|bool
name|shouldEmitCFI
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
name|virtual
operator|~
name|ARMException
argument_list|()
block|;
comment|/// endModule - Emit all exception information that should come after the
comment|/// content.
name|void
name|endModule
argument_list|()
name|override
block|;
comment|/// beginFunction - Gather pre-function exception information.  Assumes being
comment|/// emitted immediately after the function entry point.
name|void
name|beginFunction
argument_list|(
argument|const MachineFunction *MF
argument_list|)
name|override
block|;
comment|/// endFunction - Gather and emit post-function exception information.
name|void
name|endFunction
argument_list|(
argument|const MachineFunction *
argument_list|)
name|override
block|; }
decl_stmt|;
name|class
name|Win64Exception
range|:
name|public
name|EHStreamer
block|{
comment|/// shouldEmitPersonality - Per-function flag to indicate if personality
comment|/// info should be emitted.
name|bool
name|shouldEmitPersonality
block|;
comment|/// shouldEmitLSDA - Per-function flag to indicate if the LSDA
comment|/// should be emitted.
name|bool
name|shouldEmitLSDA
block|;
comment|/// shouldEmitMoves - Per-function flag to indicate if frame moves info
comment|/// should be emitted.
name|bool
name|shouldEmitMoves
block|;
name|public
operator|:
comment|//===--------------------------------------------------------------------===//
comment|// Main entry points.
comment|//
name|Win64Exception
argument_list|(
name|AsmPrinter
operator|*
name|A
argument_list|)
block|;
name|virtual
operator|~
name|Win64Exception
argument_list|()
block|;
comment|/// endModule - Emit all exception information that should come after the
comment|/// content.
name|void
name|endModule
argument_list|()
name|override
block|;
comment|/// beginFunction - Gather pre-function exception information.  Assumes being
comment|/// emitted immediately after the function entry point.
name|void
name|beginFunction
argument_list|(
argument|const MachineFunction *MF
argument_list|)
name|override
block|;
comment|/// endFunction - Gather and emit post-function exception information.
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

