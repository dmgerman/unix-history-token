begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SymbolListFile.h -----------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_ELF_SYMBOL_LIST_FILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_ELF_SYMBOL_LIST_FILE_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
name|size_t
name|defineSymbolVersion
parameter_list|(
name|StringRef
name|Version
parameter_list|)
function_decl|;
name|void
name|parseDynamicList
parameter_list|(
name|MemoryBufferRef
name|MB
parameter_list|)
function_decl|;
name|void
name|parseVersionScript
parameter_list|(
name|MemoryBufferRef
name|MB
parameter_list|)
function_decl|;
block|}
comment|// namespace elf
block|}
end_decl_stmt

begin_comment
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

