begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Strings.h ------------------------------------------------*- C++ -*-===//
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
name|LLD_COFF_STRINGS_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_COFF_STRINGS_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
name|bool
name|globMatch
parameter_list|(
name|StringRef
name|S
parameter_list|,
name|StringRef
name|T
parameter_list|)
function_decl|;
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>
name|parseHex
argument_list|(
argument|StringRef S
argument_list|)
expr_stmt|;
name|bool
name|isValidCIdentifier
parameter_list|(
name|StringRef
name|S
parameter_list|)
function_decl|;
comment|// Returns a demangled C++ symbol name. If Name is not a mangled
comment|// name or the system does not provide __cxa_demangle function,
comment|// it returns an unmodified string.
name|std
operator|::
name|string
name|demangle
argument_list|(
argument|StringRef Name
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

