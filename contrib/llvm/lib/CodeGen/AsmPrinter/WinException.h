begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- WinException.h - Windows Exception Handling ----------*- C++ -*--===//
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
comment|// This file contains support for writing windows exception info into asm files.
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
name|LLVM_LIB_CODEGEN_ASMPRINTER_WIN64EXCEPTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_ASMPRINTER_WIN64EXCEPTION_H
end_define

begin_include
include|#
directive|include
file|"EHStreamer.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MCExpr
decl_stmt|;
name|class
name|Value
decl_stmt|;
struct_decl|struct
name|WinEHFuncInfo
struct_decl|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|WinException
range|:
name|public
name|EHStreamer
block|{
comment|/// Per-function flag to indicate if personality info should be emitted.
name|bool
name|shouldEmitPersonality
operator|=
name|false
block|;
comment|/// Per-function flag to indicate if the LSDA should be emitted.
name|bool
name|shouldEmitLSDA
operator|=
name|false
block|;
comment|/// Per-function flag to indicate if frame moves info should be emitted.
name|bool
name|shouldEmitMoves
operator|=
name|false
block|;
comment|/// True if this is a 64-bit target and we should use image relative offsets.
name|bool
name|useImageRel32
operator|=
name|false
block|;
comment|/// Pointer to the current funclet entry BB.
specifier|const
name|MachineBasicBlock
operator|*
name|CurrentFuncletEntry
operator|=
name|nullptr
block|;
name|void
name|emitCSpecificHandlerTable
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|)
block|;
name|void
name|emitSEHActionsForRange
argument_list|(
argument|const WinEHFuncInfo&FuncInfo
argument_list|,
argument|const MCSymbol *BeginLabel
argument_list|,
argument|const MCSymbol *EndLabel
argument_list|,
argument|int State
argument_list|)
block|;
comment|/// Emit the EH table data for 32-bit and 64-bit functions using
comment|/// the __CxxFrameHandler3 personality.
name|void
name|emitCXXFrameHandler3Table
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|)
block|;
comment|/// Emit the EH table data for _except_handler3 and _except_handler4
comment|/// personality functions. These are only used on 32-bit and do not use CFI
comment|/// tables.
name|void
name|emitExceptHandlerTable
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|)
block|;
name|void
name|emitCLRExceptionTable
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|)
block|;
name|void
name|computeIP2StateTable
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|,
specifier|const
name|WinEHFuncInfo
operator|&
name|FuncInfo
argument_list|,
name|SmallVectorImpl
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|MCExpr
operator|*
argument_list|,
name|int
operator|>>
operator|&
name|IPToStateTable
argument_list|)
block|;
comment|/// Emits the label used with llvm.x86.seh.recoverfp, which is used by
comment|/// outlined funclets.
name|void
name|emitEHRegistrationOffsetLabel
argument_list|(
argument|const WinEHFuncInfo&FuncInfo
argument_list|,
argument|StringRef FLinkageName
argument_list|)
block|;
specifier|const
name|MCExpr
operator|*
name|create32bitRef
argument_list|(
specifier|const
name|MCSymbol
operator|*
name|Value
argument_list|)
block|;
specifier|const
name|MCExpr
operator|*
name|create32bitRef
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|)
block|;
specifier|const
name|MCExpr
operator|*
name|getLabelPlusOne
argument_list|(
specifier|const
name|MCSymbol
operator|*
name|Label
argument_list|)
block|;
specifier|const
name|MCExpr
operator|*
name|getOffset
argument_list|(
specifier|const
name|MCSymbol
operator|*
name|OffsetOf
argument_list|,
specifier|const
name|MCSymbol
operator|*
name|OffsetFrom
argument_list|)
block|;
specifier|const
name|MCExpr
operator|*
name|getOffsetPlusOne
argument_list|(
specifier|const
name|MCSymbol
operator|*
name|OffsetOf
argument_list|,
specifier|const
name|MCSymbol
operator|*
name|OffsetFrom
argument_list|)
block|;
comment|/// Gets the offset that we should use in a table for a stack object with the
comment|/// given index. For targets using CFI (Win64, etc), this is relative to the
comment|/// established SP at the end of the prologue. For targets without CFI (Win32
comment|/// only), it is relative to the frame pointer.
name|int
name|getFrameIndexOffset
argument_list|(
argument|int FrameIndex
argument_list|,
argument|const WinEHFuncInfo&FuncInfo
argument_list|)
block|;
name|public
operator|:
comment|//===--------------------------------------------------------------------===//
comment|// Main entry points.
comment|//
name|WinException
argument_list|(
name|AsmPrinter
operator|*
name|A
argument_list|)
block|;
operator|~
name|WinException
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
comment|/// \brief Emit target-specific EH funclet machinery.
name|void
name|beginFunclet
argument_list|(
argument|const MachineBasicBlock&MBB
argument_list|,
argument|MCSymbol *Sym
argument_list|)
name|override
block|;
name|void
name|endFunclet
argument_list|()
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

