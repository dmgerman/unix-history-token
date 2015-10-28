begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_symbolizer_win.h ------------------------------*- C++ -*-===//
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
comment|// Header file for the Windows symbolizer tool.
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
name|SANITIZER_SYMBOLIZER_WIN_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_SYMBOLIZER_WIN_H
end_define

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
name|WinSymbolizerTool
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
block|{
return|return
name|false
return|;
block|}
specifier|const
name|char
operator|*
name|Demangle
argument_list|(
argument|const char *name
argument_list|)
name|override
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
comment|// SANITIZER_SYMBOLIZER_WIN_H
end_comment

end_unit

