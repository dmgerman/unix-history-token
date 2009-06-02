begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SystemUtils.h - Utilities to do low-level system stuff ---*- C++ -*-===//
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
comment|// This file contains functions used to do a variety of low-level, often
end_comment

begin_comment
comment|// system-specific, tasks.
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
name|LLVM_SUPPORT_SYSTEMUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_SYSTEMUTILS_H
end_define

begin_include
include|#
directive|include
file|"llvm/System/Program.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Determine if the ostream provided is connected to the std::cout and
comment|/// displayed or not (to a console window). If so, generate a warning message
comment|/// advising against display of bitcode and return true. Otherwise just return
comment|/// false
comment|/// @brief Check for output written to a console
name|bool
name|CheckBitcodeOutputToConsole
argument_list|(
name|std
operator|::
name|ostream
operator|*
name|stream_to_check
argument_list|,
comment|///< The stream to be checked
name|bool
name|print_warning
operator|=
name|true
comment|///< Control whether warnings are printed
argument_list|)
decl_stmt|;
comment|/// FindExecutable - Find a named executable, giving the argv[0] of program
comment|/// being executed. This allows us to find another LLVM tool if it is built into
comment|/// the same directory, but that directory is neither the current directory, nor
comment|/// in the PATH.  If the executable cannot be found, return an empty string.
comment|/// @brief Find a named executable.
name|sys
operator|::
name|Path
name|FindExecutable
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|ExeName
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|ProgramPath
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

