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
comment|//  A ClangTool is initialized with a CompilationDatabase and a set of files
end_comment

begin_comment
comment|//  to run over. The tool will then run a user-specified FrontendAction over
end_comment

begin_comment
comment|//  all TUs in which the given files are compiled.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  It is also possible to run a FrontendAction over a snippet of code by
end_comment

begin_comment
comment|//  calling runSyntaxOnlyToolOnCode, which is useful for unit testing.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Applications that need more fine grained control over how to run
end_comment

begin_comment
comment|//  multiple FrontendActions over code can use ToolInvocation.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Example tools:
end_comment

begin_comment
comment|//  - running clang -fsyntax-only over source code from an editor to get
end_comment

begin_comment
comment|//    fast syntax checks
end_comment

begin_comment
comment|//  - running match/replace tools over C++ code
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
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/FileManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/Util.h"
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
name|namespace
name|driver
block|{
name|class
name|Compilation
decl_stmt|;
block|}
comment|// end namespace driver
name|class
name|CompilerInvocation
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
name|class
name|FrontendAction
decl_stmt|;
name|namespace
name|tooling
block|{
name|class
name|CompilationDatabase
decl_stmt|;
comment|/// \brief Interface to generate clang::FrontendActions.
name|class
name|FrontendActionFactory
block|{
name|public
label|:
name|virtual
operator|~
name|FrontendActionFactory
argument_list|()
expr_stmt|;
comment|/// \brief Returns a new clang::FrontendAction.
comment|///
comment|/// The caller takes ownership of the returned action.
name|virtual
name|clang
operator|::
name|FrontendAction
operator|*
name|create
argument_list|()
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
comment|/// \brief Returns a new FrontendActionFactory for a given type.
comment|///
comment|/// T must extend clang::FrontendAction.
comment|///
comment|/// Example:
comment|/// FrontendActionFactory *Factory =
comment|///   newFrontendActionFactory<clang::SyntaxOnlyAction>();
name|template
operator|<
name|typename
name|T
operator|>
name|FrontendActionFactory
operator|*
name|newFrontendActionFactory
argument_list|()
expr_stmt|;
comment|/// \brief Returns a new FrontendActionFactory for any type that provides an
comment|/// implementation of newFrontendAction().
comment|///
comment|/// FactoryT must implement: FrontendAction *newFrontendAction().
comment|///
comment|/// Example:
comment|/// struct ProvidesFrontendActions {
comment|///   FrontendAction *newFrontendAction();
comment|/// } Factory;
comment|/// FrontendActionFactory *FactoryAdapter =
comment|///   newFrontendActionFactory(&Factory);
name|template
operator|<
name|typename
name|FactoryT
operator|>
name|FrontendActionFactory
operator|*
name|newFrontendActionFactory
argument_list|(
name|FactoryT
operator|*
name|ActionFactory
argument_list|)
expr_stmt|;
comment|/// \brief Runs (and deletes) the tool on 'Code' with the -fsyntax-only flag.
comment|///
comment|/// \param ToolAction The action to run over the code.
comment|/// \param Code C++ code.
comment|/// \param FileName The file name which 'Code' will be mapped as.
comment|///
comment|/// \return - True if 'ToolAction' was successfully executed.
name|bool
name|runToolOnCode
argument_list|(
name|clang
operator|::
name|FrontendAction
operator|*
name|ToolAction
argument_list|,
specifier|const
name|Twine
operator|&
name|Code
argument_list|,
specifier|const
name|Twine
operator|&
name|FileName
operator|=
literal|"input.cc"
argument_list|)
decl_stmt|;
comment|/// \brief Utility to run a FrontendAction in a single clang invocation.
name|class
name|ToolInvocation
block|{
name|public
label|:
comment|/// \brief Create a tool invocation.
comment|///
comment|/// \param CommandLine The command line arguments to clang.
comment|/// \param ToolAction The action to be executed. Class takes ownership.
comment|/// \param Files The FileManager used for the execution. Class does not take
comment|/// ownership.
name|ToolInvocation
argument_list|(
name|ArrayRef
operator|<
name|std
operator|::
name|string
operator|>
name|CommandLine
argument_list|,
name|FrontendAction
operator|*
name|ToolAction
argument_list|,
name|FileManager
operator|*
name|Files
argument_list|)
expr_stmt|;
comment|/// \brief Map a virtual file to be used while running the tool.
comment|///
comment|/// \param FilePath The path at which the content will be mapped.
comment|/// \param Content A null terminated buffer of the file's content.
name|void
name|mapVirtualFile
parameter_list|(
name|StringRef
name|FilePath
parameter_list|,
name|StringRef
name|Content
parameter_list|)
function_decl|;
comment|/// \brief Run the clang invocation.
comment|///
comment|/// \returns True if there were no errors during execution.
name|bool
name|run
parameter_list|()
function_decl|;
name|private
label|:
name|void
name|addFileMappingsTo
parameter_list|(
name|SourceManager
modifier|&
name|SourceManager
parameter_list|)
function_decl|;
name|bool
name|runInvocation
argument_list|(
specifier|const
name|char
operator|*
name|BinaryName
argument_list|,
name|clang
operator|::
name|driver
operator|::
name|Compilation
operator|*
name|Compilation
argument_list|,
name|clang
operator|::
name|CompilerInvocation
operator|*
name|Invocation
argument_list|,
specifier|const
name|clang
operator|::
name|driver
operator|::
name|ArgStringList
operator|&
name|CC1Args
argument_list|,
name|clang
operator|::
name|FrontendAction
operator|*
name|ToolAction
argument_list|)
decl_stmt|;
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
name|llvm
operator|::
name|OwningPtr
operator|<
name|FrontendAction
operator|>
name|ToolAction
expr_stmt|;
name|FileManager
modifier|*
name|Files
decl_stmt|;
comment|// Maps<file name> -><file content>.
name|llvm
operator|::
name|StringMap
operator|<
name|StringRef
operator|>
name|MappedFileContents
expr_stmt|;
block|}
empty_stmt|;
comment|/// \brief Utility to run a FrontendAction over a set of files.
comment|///
comment|/// This class is written to be usable for command line utilities.
name|class
name|ClangTool
block|{
name|public
label|:
comment|/// \brief Constructs a clang tool to run over a list of files.
comment|///
comment|/// \param Compilations The CompilationDatabase which contains the compile
comment|///        command lines for the given source paths.
comment|/// \param SourcePaths The source files to run over. If a source files is
comment|///        not found in Compilations, it is skipped.
name|ClangTool
argument_list|(
specifier|const
name|CompilationDatabase
operator|&
name|Compilations
argument_list|,
name|ArrayRef
operator|<
name|std
operator|::
name|string
operator|>
name|SourcePaths
argument_list|)
expr_stmt|;
comment|/// \brief Map a virtual file to be used while running the tool.
comment|///
comment|/// \param FilePath The path at which the content will be mapped.
comment|/// \param Content A null terminated buffer of the file's content.
name|void
name|mapVirtualFile
parameter_list|(
name|StringRef
name|FilePath
parameter_list|,
name|StringRef
name|Content
parameter_list|)
function_decl|;
comment|/// Runs a frontend action over all files specified in the command line.
comment|///
comment|/// \param ActionFactory Factory generating the frontend actions. The function
comment|/// takes ownership of this parameter. A new action is generated for every
comment|/// processed translation unit.
name|int
name|run
parameter_list|(
name|FrontendActionFactory
modifier|*
name|ActionFactory
parameter_list|)
function_decl|;
comment|/// \brief Returns the file manager used in the tool.
comment|///
comment|/// The file manager is shared between all translation units.
name|FileManager
modifier|&
name|getFiles
parameter_list|()
block|{
return|return
name|Files
return|;
block|}
name|private
label|:
comment|// We store command lines as pair (file name, command line).
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
operator|,
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
expr|>
name|CommandLine
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|CommandLine
operator|>
name|CommandLines
expr_stmt|;
name|FileManager
name|Files
decl_stmt|;
comment|// Contains a list of pairs (<file name>,<file content>).
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|StringRef
operator|,
name|StringRef
operator|>
expr|>
name|MappedFileContents
expr_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|FrontendActionFactory
operator|*
name|newFrontendActionFactory
argument_list|()
block|{
name|class
name|SimpleFrontendActionFactory
operator|:
name|public
name|FrontendActionFactory
block|{
name|public
operator|:
name|virtual
name|clang
operator|::
name|FrontendAction
operator|*
name|create
argument_list|()
block|{
return|return
name|new
name|T
return|;
block|}
expr|}
block|;
return|return
name|new
name|SimpleFrontendActionFactory
return|;
block|}
name|template
operator|<
name|typename
name|FactoryT
operator|>
name|FrontendActionFactory
operator|*
name|newFrontendActionFactory
argument_list|(
argument|FactoryT *ActionFactory
argument_list|)
block|{
name|class
name|FrontendActionFactoryAdapter
operator|:
name|public
name|FrontendActionFactory
block|{
name|public
operator|:
name|explicit
name|FrontendActionFactoryAdapter
argument_list|(
name|FactoryT
operator|*
name|ActionFactory
argument_list|)
operator|:
name|ActionFactory
argument_list|(
argument|ActionFactory
argument_list|)
block|{}
name|virtual
name|clang
operator|::
name|FrontendAction
operator|*
name|create
argument_list|()
block|{
return|return
name|ActionFactory
operator|->
name|newFrontendAction
argument_list|()
return|;
block|}
name|private
operator|:
name|FactoryT
operator|*
name|ActionFactory
block|;   }
block|;
return|return
name|new
name|FrontendActionFactoryAdapter
argument_list|(
name|ActionFactory
argument_list|)
return|;
block|}
expr|}
comment|// end namespace tooling
expr|}
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

