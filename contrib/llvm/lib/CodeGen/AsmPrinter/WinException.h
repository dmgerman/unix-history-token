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
struct_decl|struct
name|WinEHFuncInfo
struct_decl|;
name|class
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
name|void
name|emitCSpecificHandlerTable
argument_list|()
block|;
name|void
name|emitCXXFrameHandler3Table
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|)
block|;
name|void
name|extendIP2StateTable
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|,
specifier|const
name|Function
operator|*
name|ParentF
argument_list|,
name|WinEHFuncInfo
operator|&
name|FuncInfo
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
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

