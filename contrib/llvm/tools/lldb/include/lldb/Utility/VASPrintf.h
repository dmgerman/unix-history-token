begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- VASPrintf.h ---------------------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLDB_UTILITY_VASPRINTF_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_UTILITY_VASPRINTF_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|<cstdarg>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|bool
name|VASprintf
argument_list|(
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|buf
argument_list|,
specifier|const
name|char
operator|*
name|fmt
argument_list|,
name|va_list
name|args
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifdef LLDB_UTILITY_VASPRINTF_H
end_comment

end_unit

