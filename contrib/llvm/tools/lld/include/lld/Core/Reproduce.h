begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Reproduce.h - Utilities for creating reproducers ---------*- C++ -*-===//
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
name|LLD_CORE_REPRODUCE_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_CORE_REPRODUCE_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|opt
block|{
name|class
name|Arg
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lld
block|{
comment|// Makes a given pathname an absolute path first, and then remove
comment|// beginning /. For example, "../foo.o" is converted to "home/john/foo.o",
comment|// assuming that the current directory is "/home/john/bar".
name|std
operator|::
name|string
name|relativeToRoot
argument_list|(
argument|StringRef Path
argument_list|)
expr_stmt|;
comment|// Quote a given string if it contains a space character.
name|std
operator|::
name|string
name|quote
argument_list|(
argument|StringRef S
argument_list|)
expr_stmt|;
comment|// Rewrite the given path if a file exists with that pathname, otherwise
comment|// returns the original path.
name|std
operator|::
name|string
name|rewritePath
argument_list|(
argument|StringRef S
argument_list|)
expr_stmt|;
comment|// Returns the string form of the given argument.
name|std
operator|::
name|string
name|toString
argument_list|(
name|llvm
operator|::
name|opt
operator|::
name|Arg
operator|*
name|Arg
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

