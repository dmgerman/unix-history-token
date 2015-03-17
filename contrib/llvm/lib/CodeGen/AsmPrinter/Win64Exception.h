begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Win64Exception.h - Windows Exception Handling ----------*- C++ -*--===//
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
name|MachineFunction
decl_stmt|;
name|class
name|Win64Exception
range|:
name|public
name|EHStreamer
block|{
comment|/// Per-function flag to indicate if personality info should be emitted.
name|bool
name|shouldEmitPersonality
block|;
comment|/// Per-function flag to indicate if the LSDA should be emitted.
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

