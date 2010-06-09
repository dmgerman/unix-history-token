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
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|namespace
name|sys
block|{
name|class
name|Path
decl_stmt|;
block|}
comment|/// Determine if the raw_ostream provided is connected to the outs() and
comment|/// displayed or not (to a console window). If so, generate a warning message
comment|/// advising against display of bitcode and return true. Otherwise just return
comment|/// false
comment|/// @brief Check for output written to a console
name|bool
name|CheckBitcodeOutputToConsole
parameter_list|(
name|raw_ostream
modifier|&
name|stream_to_check
parameter_list|,
comment|///< The stream to be checked
name|bool
name|print_warning
init|=
name|true
comment|///< Control whether warnings are printed
parameter_list|)
function_decl|;
comment|/// FindExecutable - Find a named executable, giving the argv[0] of program
comment|/// being executed. This allows us to find another LLVM tool if it is built in
comment|/// the same directory.  If the executable cannot be found, return an
comment|/// empty string.
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
name|char
operator|*
name|Argv0
argument_list|,
name|void
operator|*
name|MainAddr
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

