begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_symbolizer_mac.h ------------------------------*- C++ -*-===//
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
comment|// This file is shared between various sanitizers' runtime libraries.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Header for Mac-specific "atos" symbolizer.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_SYMBOLIZER_MAC_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_SYMBOLIZER_MAC_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_platform.h"
end_include

begin_if
if|#
directive|if
name|SANITIZER_MAC
end_if

begin_include
include|#
directive|include
file|"sanitizer_symbolizer_internal.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
name|class
name|DlAddrSymbolizer
range|:
name|public
name|SymbolizerTool
block|{
name|public
operator|:
name|bool
name|SymbolizePC
argument_list|(
argument|uptr addr
argument_list|,
argument|SymbolizedStack *stack
argument_list|)
name|override
block|;
name|bool
name|SymbolizeData
argument_list|(
argument|uptr addr
argument_list|,
argument|DataInfo *info
argument_list|)
name|override
block|; }
decl_stmt|;
name|class
name|AtosSymbolizerProcess
decl_stmt|;
name|class
name|AtosSymbolizer
range|:
name|public
name|SymbolizerTool
block|{
name|public
operator|:
name|explicit
name|AtosSymbolizer
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|,
name|LowLevelAllocator
operator|*
name|allocator
argument_list|)
block|;
name|bool
name|SymbolizePC
argument_list|(
argument|uptr addr
argument_list|,
argument|SymbolizedStack *stack
argument_list|)
name|override
block|;
name|bool
name|SymbolizeData
argument_list|(
argument|uptr addr
argument_list|,
argument|DataInfo *info
argument_list|)
name|override
block|;
name|private
operator|:
name|AtosSymbolizerProcess
operator|*
name|process_
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_MAC
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_SYMBOLIZER_MAC_H
end_comment

end_unit

