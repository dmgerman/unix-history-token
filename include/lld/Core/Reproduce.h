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
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSet.h"
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
name|class
name|raw_fd_ostream
decl_stmt|;
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
comment|// This class creates a .cpio file for --reproduce (ELF) or /linkrepro (COFF).
comment|//
comment|// If "--reproduce foo" is given, we create a file "foo.cpio" and
comment|// copy all input files to the archive, along with a response file
comment|// to re-run the same command with the same inputs.
comment|// It is useful for reporting issues to LLD developers.
comment|//
comment|// Cpio as a file format is a deliberate choice. It's standardized in
comment|// POSIX and very easy to create. cpio command is available virtually
comment|// on all Unix systems. See
comment|// http://pubs.opengroup.org/onlinepubs/9699919799/utilities/pax.html#tag_20_92_13_07
comment|// for the format details.
name|class
name|CpioFile
block|{
name|public
label|:
specifier|static
name|ErrorOr
operator|<
name|CpioFile
operator|*
operator|>
name|create
argument_list|(
argument|StringRef OutputPath
argument_list|)
expr_stmt|;
name|void
name|append
parameter_list|(
name|StringRef
name|Path
parameter_list|,
name|StringRef
name|Data
parameter_list|)
function_decl|;
name|private
label|:
name|CpioFile
argument_list|(
argument|std::unique_ptr<llvm::raw_fd_ostream> OS
argument_list|,
argument|StringRef Basename
argument_list|)
empty_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|raw_fd_ostream
operator|>
name|OS
expr_stmt|;
name|llvm
operator|::
name|StringSet
operator|<
operator|>
name|Seen
expr_stmt|;
name|std
operator|::
name|string
name|Basename
expr_stmt|;
block|}
empty_stmt|;
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
name|stringize
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
comment|// Replaces backslashes with slashes if Windows.
name|std
operator|::
name|string
name|convertToUnixPathSeparator
argument_list|(
argument|StringRef S
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

