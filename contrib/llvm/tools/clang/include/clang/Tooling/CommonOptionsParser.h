begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CommonOptionsParser.h - common options for clang tools -*- C++ -*-=====//
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
comment|//  This file implements the CommonOptionsParser class used to parse common
end_comment

begin_comment
comment|//  command-line options for clang tools, so that they can be run as separate
end_comment

begin_comment
comment|//  command-line applications with a consistent common interface for handling
end_comment

begin_comment
comment|//  compilation database and input files.
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
comment|//  It creates a CompilationDatabase and reads common command-line options.
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
name|LLVM_TOOLS_CLANG_INCLUDE_CLANG_TOOLING_COMMONOPTIONSPARSER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_CLANG_INCLUDE_CLANG_TOOLING_COMMONOPTIONSPARSER_H
end_define

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
comment|/// \brief A parser for options common to all command-line Clang tools.
comment|///
comment|/// Parses a common subset of command-line arguments, locates and loads a
comment|/// compilation commands database and runs a tool with user-specified action. It
comment|/// also contains a help message for the common command-line options.
comment|///
comment|/// An example of usage:
comment|/// \code
comment|/// #include "clang/Frontend/FrontendActions.h"
comment|/// #include "clang/Tooling/CommonOptionsParser.h"
comment|/// #include "llvm/Support/CommandLine.h"
comment|///
comment|/// using namespace clang::tooling;
comment|/// using namespace llvm;
comment|///
comment|/// static cl::extrahelp CommonHelp(CommonOptionsParser::HelpMessage);
comment|/// static cl::extrahelp MoreHelp("\nMore help text...");
comment|/// static cl:opt<bool> YourOwnOption(...);
comment|/// ...
comment|///
comment|/// int main(int argc, const char **argv) {
comment|///   CommonOptionsParser OptionsParser(argc, argv);
comment|///   ClangTool Tool(OptionsParser.getCompilations(),
comment|///                  OptionsParser.getSourcePathListi());
comment|///   return Tool.run(newFrontendActionFactory<clang::SyntaxOnlyAction>());
comment|/// }
comment|/// \endcode
name|class
name|CommonOptionsParser
block|{
name|public
label|:
comment|/// \brief Parses command-line, initializes a compilation database.
comment|/// This constructor can change argc and argv contents, e.g. consume
comment|/// command-line options used for creating FixedCompilationDatabase.
comment|/// This constructor exits program in case of error.
name|CommonOptionsParser
argument_list|(
name|int
operator|&
name|argc
argument_list|,
specifier|const
name|char
operator|*
operator|*
name|argv
argument_list|,
specifier|const
name|char
operator|*
name|Overview
operator|=
literal|0
argument_list|)
expr_stmt|;
comment|/// Returns a reference to the loaded compilations database.
name|CompilationDatabase
modifier|&
name|getCompilations
parameter_list|()
block|{
return|return
operator|*
name|Compilations
return|;
block|}
comment|/// Returns a list of source file paths to process.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|getSourcePathList
argument_list|()
block|{
return|return
name|SourcePathList
return|;
block|}
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|HelpMessage
decl_stmt|;
name|private
label|:
name|OwningPtr
operator|<
name|CompilationDatabase
operator|>
name|Compilations
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|SourcePathList
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
comment|// LLVM_TOOLS_CLANG_INCLUDE_CLANG_TOOLING_COMMONOPTIONSPARSER_H
end_comment

end_unit

