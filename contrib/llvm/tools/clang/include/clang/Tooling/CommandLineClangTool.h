begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CommandLineClangTool.h - command-line clang tools driver -*- C++ -*-===//
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
comment|//  This file implements the CommandLineClangTool class used to run clang
end_comment

begin_comment
comment|//  tools as separate command-line applications with a consistent common
end_comment

begin_comment
comment|//  interface for handling compilation database and input files.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  It provides a common subset of command-line options, common algorithm
end_comment

begin_comment
comment|//  for locating a compilation database and source files, and help messages
end_comment

begin_comment
comment|//  for the basic command-line interface.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  It creates a CompilationDatabase, initializes a ClangTool and runs a
end_comment

begin_comment
comment|//  user-specified FrontendAction over all TUs in which the given files are
end_comment

begin_comment
comment|//  compiled.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This class uses the Clang Tooling infrastructure, see
end_comment

begin_comment
comment|//    http://clang.llvm.org/docs/HowToSetupToolingForLLVM.html
end_comment

begin_comment
comment|//  for details on setting it up with LLVM source tree.
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
name|LLVM_TOOLS_CLANG_INCLUDE_CLANG_TOOLING_COMMANDLINECLANGTOOL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_CLANG_INCLUDE_CLANG_TOOLING_COMMANDLINECLANGTOOL_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/CommandLine.h"
end_include

begin_include
include|#
directive|include
file|"clang/Tooling/CompilationDatabase.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|tooling
block|{
name|class
name|CompilationDatabase
decl_stmt|;
name|class
name|FrontendActionFactory
decl_stmt|;
comment|/// \brief A common driver for command-line Clang tools.
comment|///
comment|/// Parses a common subset of command-line arguments, locates and loads a
comment|/// compilation commands database, runs a tool with user-specified action. It
comment|/// also contains a help message for the common command-line options.
comment|/// An example of usage:
comment|/// @code
comment|/// int main(int argc, const char **argv) {
comment|///   CommandLineClangTool Tool;
comment|///   cl::extrahelp MoreHelp("\nMore help text...");
comment|///   Tool.initialize(argc, argv);
comment|///   return Tool.run(newFrontendActionFactory<clang::SyntaxOnlyAction>());
comment|/// }
comment|/// @endcode
comment|///
name|class
name|CommandLineClangTool
block|{
name|public
label|:
comment|/// Sets up command-line options and help messages.
comment|/// Add your own help messages after constructing this tool.
name|CommandLineClangTool
argument_list|()
expr_stmt|;
comment|/// Parses command-line, initializes a compilation database.
comment|/// This method exits program in case of error.
name|void
name|initialize
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
comment|/// Runs a clang tool with an action created by \c ActionFactory.
name|int
name|run
parameter_list|(
name|FrontendActionFactory
modifier|*
name|ActionFactory
parameter_list|)
function_decl|;
name|private
label|:
name|llvm
operator|::
name|OwningPtr
operator|<
name|CompilationDatabase
operator|>
name|Compilations
expr_stmt|;
name|llvm
operator|::
name|cl
operator|::
name|opt
operator|<
name|std
operator|::
name|string
operator|>
name|BuildPath
expr_stmt|;
name|llvm
operator|::
name|cl
operator|::
name|list
operator|<
name|std
operator|::
name|string
operator|>
name|SourcePaths
expr_stmt|;
name|llvm
operator|::
name|cl
operator|::
name|extrahelp
name|MoreHelp
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace tooling
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TOOLS_CLANG_INCLUDE_CLANG_TOOLING_COMMANDLINECLANGTOOL_H
end_comment

end_unit

