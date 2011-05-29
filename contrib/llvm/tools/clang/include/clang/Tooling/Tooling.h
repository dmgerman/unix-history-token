begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Tooling.h - Framework for standalone Clang tools -------*- C++ -*-===//
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
comment|//  This file implements functions to run clang tools standalone instead
end_comment

begin_comment
comment|//  of running them as a plugin.
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
name|LLVM_CLANG_TOOLING_TOOLING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLING_TOOLING_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|FrontendAction
decl_stmt|;
name|namespace
name|tooling
block|{
comment|/// \brief Runs (and deletes) the tool on 'Code' with the -fsynatx-only flag.
comment|///
comment|/// \param ToolAction The action to run over the code.
comment|/// \param Code C++ code.
comment|///
comment|/// \return - True if 'ToolAction' was successfully executed.
name|bool
name|RunSyntaxOnlyToolOnCode
argument_list|(
name|clang
operator|::
name|FrontendAction
operator|*
name|ToolAction
argument_list|,
name|llvm
operator|::
name|StringRef
name|Code
argument_list|)
decl_stmt|;
comment|/// \brief Runs (and deletes) the tool with the given Clang flags.
comment|///
comment|/// \param ToolAction The action to run over the code.
comment|/// \param Argc The number of elements in Argv.
comment|/// \param Argv The command line arguments, including the path the binary
comment|/// was started with (Argv[0]).
name|bool
name|RunToolWithFlags
argument_list|(
name|clang
operator|::
name|FrontendAction
operator|*
name|ToolAction
argument_list|,
name|int
name|Argc
argument_list|,
name|char
operator|*
name|Argv
index|[]
argument_list|)
decl_stmt|;
comment|/// \brief Converts a vector<string> into a vector<char*> suitable to pass
comment|/// to main-style functions taking (int Argc, char *Argv[]).
name|std
operator|::
name|vector
operator|<
name|char
operator|*
operator|>
name|CommandLineToArgv
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|*
name|Command
argument_list|)
expr_stmt|;
comment|/// \brief Specifies the working directory and command of a compilation.
struct|struct
name|CompileCommand
block|{
comment|/// \brief The working directory the command was executed from.
name|std
operator|::
name|string
name|Directory
expr_stmt|;
comment|/// \brief The command line that was executed.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|CommandLine
expr_stmt|;
block|}
struct|;
comment|/// \brief Looks up the compile command for 'FileName' in 'JsonDatabase'.
comment|///
comment|/// \param FileName The path to an input file for which we want the compile
comment|/// command line. If the 'JsonDatabase' was created by CMake, this must be
comment|/// an absolute path inside the CMake source directory which does not have
comment|/// symlinks resolved.
comment|///
comment|/// \param JsonDatabase A JSON formatted list of compile commands. This lookup
comment|/// command supports only a subset of the JSON standard as written by CMake.
comment|///
comment|/// \param ErrorMessage If non-empty, an error occurred and 'ErrorMessage' will
comment|/// be set to contain the error message. In this case CompileCommand will
comment|/// contain an empty directory and command line.
comment|///
comment|/// \see JsonCompileCommandLineDatabase
name|CompileCommand
name|FindCompileArgsInJsonDatabase
argument_list|(
name|llvm
operator|::
name|StringRef
name|FileName
argument_list|,
name|llvm
operator|::
name|StringRef
name|JsonDatabase
argument_list|,
name|std
operator|::
name|string
operator|&
name|ErrorMessage
argument_list|)
decl_stmt|;
block|}
comment|// end namespace tooling
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_TOOLING_TOOLING_H
end_comment

end_unit

