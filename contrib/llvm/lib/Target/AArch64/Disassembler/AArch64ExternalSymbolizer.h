begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AArch64ExternalSymbolizer.h - Symbolizer for AArch64 -----*- C++ -*-===//
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
comment|// Symbolize AArch64 assembly code during disassembly using callbacks.
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
name|AArch64EXTERNALSYMBOLIZER_H
end_ifndef

begin_define
define|#
directive|define
name|AArch64EXTERNALSYMBOLIZER_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCExternalSymbolizer.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AArch64ExternalSymbolizer
range|:
name|public
name|MCExternalSymbolizer
block|{
name|public
operator|:
name|AArch64ExternalSymbolizer
argument_list|(
argument|MCContext&Ctx
argument_list|,
argument|std::unique_ptr<MCRelocationInfo> RelInfo
argument_list|,
argument|LLVMOpInfoCallback GetOpInfo
argument_list|,
argument|LLVMSymbolLookupCallback SymbolLookUp
argument_list|,
argument|void *DisInfo
argument_list|)
operator|:
name|MCExternalSymbolizer
argument_list|(
argument|Ctx
argument_list|,
argument|std::move(RelInfo)
argument_list|,
argument|GetOpInfo
argument_list|,
argument|SymbolLookUp
argument_list|,
argument|DisInfo
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
name|override
block|; }
decl_stmt|;
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

