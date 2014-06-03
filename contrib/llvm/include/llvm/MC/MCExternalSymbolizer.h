begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCExternalSymbolizer.h - ------------------------*- C++ -*-===//
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
comment|// This file contains the declaration of the MCExternalSymbolizer class, which
end_comment

begin_comment
comment|// enables library users to provide callbacks (through the C API) to do the
end_comment

begin_comment
comment|// symbolization externally.
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
name|LLVM_MC_MCEXTERNALSYMBOLIZER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCEXTERNALSYMBOLIZER_H
end_define

begin_include
include|#
directive|include
file|"llvm-c/Disassembler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSymbolizer.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief Symbolize using user-provided, C API, callbacks.
comment|///
comment|/// See llvm-c/Disassembler.h.
name|class
name|MCExternalSymbolizer
range|:
name|public
name|MCSymbolizer
block|{
comment|/// \name Hooks for symbolic disassembly via the public 'C' interface.
comment|/// @{
comment|/// The function to get the symbolic information for operands.
name|LLVMOpInfoCallback
name|GetOpInfo
block|;
comment|/// The function to lookup a symbol name.
name|LLVMSymbolLookupCallback
name|SymbolLookUp
block|;
comment|/// The pointer to the block of symbolic information for above call back.
name|void
operator|*
name|DisInfo
block|;
comment|/// @}
name|public
operator|:
name|MCExternalSymbolizer
argument_list|(
argument|MCContext&Ctx
argument_list|,
argument|OwningPtr<MCRelocationInfo>&RelInfo
argument_list|,
argument|LLVMOpInfoCallback getOpInfo
argument_list|,
argument|LLVMSymbolLookupCallback symbolLookUp
argument_list|,
argument|void *disInfo
argument_list|)
operator|:
name|MCSymbolizer
argument_list|(
name|Ctx
argument_list|,
name|RelInfo
argument_list|)
block|,
name|GetOpInfo
argument_list|(
name|getOpInfo
argument_list|)
block|,
name|SymbolLookUp
argument_list|(
name|symbolLookUp
argument_list|)
block|,
name|DisInfo
argument_list|(
argument|disInfo
argument_list|)
block|{}
name|bool
name|tryAddingSymbolicOperand
argument_list|(
argument|MCInst&MI
argument_list|,
argument|raw_ostream&CommentStream
argument_list|,
argument|int64_t Value
argument_list|,
argument|uint64_t Address
argument_list|,
argument|bool IsBranch
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|uint64_t InstSize
argument_list|)
block|;
name|void
name|tryAddingPcLoadReferenceComment
argument_list|(
argument|raw_ostream&CommentStream
argument_list|,
argument|int64_t Value
argument_list|,
argument|uint64_t Address
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

