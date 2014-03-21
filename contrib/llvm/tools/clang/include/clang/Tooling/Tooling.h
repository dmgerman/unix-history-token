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
comment|//  calling runToolOnCode, which is useful for unit testing.
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
file|"clang/Basic/Diagnostic.h"
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
file|"clang/Frontend/FrontendAction.h"
end_include

begin_include
include|#
directive|include
file|"clang/Tooling/ArgumentsAdjusters.h"
end_include

begin_include
include|#
directive|include
file|"clang/Tooling/CompilationDatabase.h"
end_include

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
comment|/// \brief Interface to process a clang::CompilerInvocation.
comment|///
comment|/// If your tool is based on FrontendAction, you should be deriving from
comment|/// FrontendActionFactory instead.
name|class
name|ToolAction
block|{
name|public
label|:
name|virtual
operator|~
name|ToolAction
argument_list|()
expr_stmt|;
comment|/// \brief Perform an action for an invocation.
name|virtual
name|bool
name|runInvocation
argument_list|(
name|clang
operator|::
name|CompilerInvocation
operator|*
name|Invocation
argument_list|,
name|FileManager
operator|*
name|Files
argument_list|,
name|DiagnosticConsumer
operator|*
name|DiagConsumer
argument_list|)
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief Interface to generate clang::FrontendActions.
comment|///
comment|/// Having a factory interface allows, for example, a new FrontendAction to be
comment|/// created for each translation unit processed by ClangTool.  This class is
comment|/// also a ToolAction which uses the FrontendActions created by create() to
comment|/// process each translation unit.
name|class
name|FrontendActionFactory
range|:
name|public
name|ToolAction
block|{
name|public
operator|:
name|virtual
operator|~
name|FrontendActionFactory
argument_list|()
block|;
comment|/// \brief Invokes the compiler with a FrontendAction created by create().
name|bool
name|runInvocation
argument_list|(
name|clang
operator|::
name|CompilerInvocation
operator|*
name|Invocation
argument_list|,
name|FileManager
operator|*
name|Files
argument_list|,
name|DiagnosticConsumer
operator|*
name|DiagConsumer
argument_list|)
block|;
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
block|; }
decl_stmt|;
comment|/// \brief Returns a new FrontendActionFactory for a given type.
comment|///
comment|/// T must derive from clang::FrontendAction.
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
comment|/// \brief Callbacks called before and after each source file processed by a
comment|/// FrontendAction created by the FrontedActionFactory returned by \c
comment|/// newFrontendActionFactory.
name|class
name|SourceFileCallbacks
block|{
name|public
label|:
name|virtual
operator|~
name|SourceFileCallbacks
argument_list|()
block|{}
comment|/// \brief Called before a source file is processed by a FrontEndAction.
comment|/// \see clang::FrontendAction::BeginSourceFileAction
name|virtual
name|bool
name|handleBeginSource
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|StringRef Filename
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|/// \brief Called after a source file is processed by a FrontendAction.
comment|/// \see clang::FrontendAction::EndSourceFileAction
name|virtual
name|void
name|handleEndSource
parameter_list|()
block|{}
block|}
empty_stmt|;
comment|/// \brief Returns a new FrontendActionFactory for any type that provides an
comment|/// implementation of newASTConsumer().
comment|///
comment|/// FactoryT must implement: ASTConsumer *newASTConsumer().
comment|///
comment|/// Example:
comment|/// struct ProvidesASTConsumers {
comment|///   clang::ASTConsumer *newASTConsumer();
comment|/// } Factory;
comment|/// FrontendActionFactory *FactoryAdapter =
comment|///   newFrontendActionFactory(&Factory);
name|template
operator|<
name|typename
name|FactoryT
operator|>
specifier|inline
name|FrontendActionFactory
operator|*
name|newFrontendActionFactory
argument_list|(
name|FactoryT
operator|*
name|ConsumerFactory
argument_list|,
name|SourceFileCallbacks
operator|*
name|Callbacks
operator|=
name|NULL
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
comment|/// \brief Runs (and deletes) the tool on 'Code' with the -fsyntax-only flag and
comment|///        with additional other flags.
comment|///
comment|/// \param ToolAction The action to run over the code.
comment|/// \param Code C++ code.
comment|/// \param Args Additional flags to pass on.
comment|/// \param FileName The file name which 'Code' will be mapped as.
comment|///
comment|/// \return - True if 'ToolAction' was successfully executed.
name|bool
name|runToolOnCodeWithArgs
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
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|Args
argument_list|,
specifier|const
name|Twine
operator|&
name|FileName
operator|=
literal|"input.cc"
argument_list|)
decl_stmt|;
comment|/// \brief Builds an AST for 'Code'.
comment|///
comment|/// \param Code C++ code.
comment|/// \param FileName The file name which 'Code' will be mapped as.
comment|///
comment|/// \return The resulting AST or null if an error occurred.
name|ASTUnit
modifier|*
name|buildASTFromCode
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Code
parameter_list|,
specifier|const
name|Twine
modifier|&
name|FileName
init|=
literal|"input.cc"
parameter_list|)
function_decl|;
comment|/// \brief Builds an AST for 'Code' with additional flags.
comment|///
comment|/// \param Code C++ code.
comment|/// \param Args Additional flags to pass on.
comment|/// \param FileName The file name which 'Code' will be mapped as.
comment|///
comment|/// \return The resulting AST or null if an error occurred.
name|ASTUnit
modifier|*
name|buildASTFromCodeWithArgs
argument_list|(
specifier|const
name|Twine
operator|&
name|Code
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|Args
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
comment|/// \param CommandLine The command line arguments to clang. Note that clang
comment|/// uses its binary name (CommandLine[0]) to locate its builtin headers.
comment|/// Callers have to ensure that they are installed in a compatible location
comment|/// (see clang driver implementation) or mapped in via mapVirtualFile.
comment|/// \param FAction The action to be executed. Class takes ownership.
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
name|FAction
argument_list|,
name|FileManager
operator|*
name|Files
argument_list|)
expr_stmt|;
comment|/// \brief Create a tool invocation.
comment|///
comment|/// \param CommandLine The command line arguments to clang.
comment|/// \param Action The action to be executed.
comment|/// \param Files The FileManager used for the execution.
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
name|ToolAction
operator|*
name|Action
argument_list|,
name|FileManager
operator|*
name|Files
argument_list|)
expr_stmt|;
operator|~
name|ToolInvocation
argument_list|()
expr_stmt|;
comment|/// \brief Set a \c DiagnosticConsumer to use during parsing.
name|void
name|setDiagnosticConsumer
parameter_list|(
name|DiagnosticConsumer
modifier|*
name|DiagConsumer
parameter_list|)
function_decl|;
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
name|ToolAction
modifier|*
name|Action
decl_stmt|;
name|bool
name|OwnsAction
decl_stmt|;
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
name|DiagnosticConsumer
modifier|*
name|DiagConsumer
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief Utility to run a FrontendAction over a set of files.
comment|///
comment|/// This class is written to be usable for command line utilities.
comment|/// By default the class uses ClangSyntaxOnlyAdjuster to modify
comment|/// command line arguments before the arguments are used to run
comment|/// a frontend action. One could install an additional command line
comment|/// arguments adjuster by calling the appendArgumentsAdjuster() method.
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
name|virtual
operator|~
name|ClangTool
argument_list|()
block|{
name|clearArgumentsAdjusters
argument_list|()
block|; }
comment|/// \brief Set a \c DiagnosticConsumer to use during parsing.
name|void
name|setDiagnosticConsumer
argument_list|(
name|DiagnosticConsumer
operator|*
name|DiagConsumer
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
comment|/// \brief Install command line arguments adjuster.
comment|///
comment|/// \param Adjuster Command line arguments adjuster.
comment|//
comment|/// FIXME: Function is deprecated. Use (clear/append)ArgumentsAdjuster instead.
comment|/// Remove it once all callers are gone.
name|void
name|setArgumentsAdjuster
parameter_list|(
name|ArgumentsAdjuster
modifier|*
name|Adjuster
parameter_list|)
function_decl|;
comment|/// \brief Append a command line arguments adjuster to the adjuster chain.
comment|///
comment|/// \param Adjuster An argument adjuster, which will be run on the output of
comment|///        previous argument adjusters.
name|void
name|appendArgumentsAdjuster
parameter_list|(
name|ArgumentsAdjuster
modifier|*
name|Adjuster
parameter_list|)
function_decl|;
comment|/// \brief Clear the command line arguments adjuster chain.
name|void
name|clearArgumentsAdjusters
parameter_list|()
function_decl|;
comment|/// Runs an action over all files specified in the command line.
comment|///
comment|/// \param Action Tool action.
name|int
name|run
parameter_list|(
name|ToolAction
modifier|*
name|Action
parameter_list|)
function_decl|;
comment|/// \brief Create an AST for each file specified in the command line and
comment|/// append them to ASTs.
name|int
name|buildASTs
argument_list|(
name|std
operator|::
name|vector
operator|<
name|ASTUnit
operator|*
operator|>
operator|&
name|ASTs
argument_list|)
decl_stmt|;
comment|/// \brief Returns the file manager used in the tool.
comment|///
comment|/// The file manager is shared between all translation units.
name|FileManager
modifier|&
name|getFiles
parameter_list|()
block|{
return|return
operator|*
name|Files
return|;
block|}
name|private
label|:
comment|// We store compile commands as pair (file name, compile command).
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
operator|,
name|CompileCommand
operator|>
expr|>
name|CompileCommands
expr_stmt|;
name|llvm
operator|::
name|IntrusiveRefCntPtr
operator|<
name|FileManager
operator|>
name|Files
expr_stmt|;
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
name|SmallVector
operator|<
name|ArgumentsAdjuster
operator|*
operator|,
literal|2
operator|>
name|ArgsAdjusters
expr_stmt|;
name|DiagnosticConsumer
modifier|*
name|DiagConsumer
decl_stmt|;
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
specifier|inline
name|FrontendActionFactory
operator|*
name|newFrontendActionFactory
argument_list|(
argument|FactoryT *ConsumerFactory
argument_list|,
argument|SourceFileCallbacks *Callbacks
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
name|ConsumerFactory
argument_list|,
name|SourceFileCallbacks
operator|*
name|Callbacks
argument_list|)
operator|:
name|ConsumerFactory
argument_list|(
name|ConsumerFactory
argument_list|)
block|,
name|Callbacks
argument_list|(
argument|Callbacks
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
name|new
name|ConsumerFactoryAdaptor
argument_list|(
name|ConsumerFactory
argument_list|,
name|Callbacks
argument_list|)
return|;
block|}
name|private
operator|:
name|class
name|ConsumerFactoryAdaptor
operator|:
name|public
name|clang
operator|::
name|ASTFrontendAction
block|{
name|public
operator|:
name|ConsumerFactoryAdaptor
argument_list|(
name|FactoryT
operator|*
name|ConsumerFactory
argument_list|,
name|SourceFileCallbacks
operator|*
name|Callbacks
argument_list|)
operator|:
name|ConsumerFactory
argument_list|(
name|ConsumerFactory
argument_list|)
block|,
name|Callbacks
argument_list|(
argument|Callbacks
argument_list|)
block|{}
name|clang
operator|::
name|ASTConsumer
operator|*
name|CreateASTConsumer
argument_list|(
argument|clang::CompilerInstance&
argument_list|,
argument|StringRef
argument_list|)
block|{
return|return
name|ConsumerFactory
operator|->
name|newASTConsumer
argument_list|()
return|;
block|}
name|protected
operator|:
name|virtual
name|bool
name|BeginSourceFileAction
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|StringRef Filename
argument_list|)
name|LLVM_OVERRIDE
block|{
if|if
condition|(
operator|!
name|clang
operator|::
name|ASTFrontendAction
operator|::
name|BeginSourceFileAction
argument_list|(
name|CI
argument_list|,
name|Filename
argument_list|)
condition|)
return|return
name|false
return|;
if|if
condition|(
name|Callbacks
operator|!=
name|NULL
condition|)
return|return
name|Callbacks
operator|->
name|handleBeginSource
argument_list|(
name|CI
argument_list|,
name|Filename
argument_list|)
return|;
return|return
name|true
return|;
block|}
name|virtual
name|void
name|EndSourceFileAction
argument_list|()
name|LLVM_OVERRIDE
block|{
if|if
condition|(
name|Callbacks
operator|!=
name|NULL
condition|)
name|Callbacks
operator|->
name|handleEndSource
argument_list|()
expr_stmt|;
name|clang
operator|::
name|ASTFrontendAction
operator|::
name|EndSourceFileAction
argument_list|()
block|;       }
name|private
operator|:
name|FactoryT
operator|*
name|ConsumerFactory
block|;
name|SourceFileCallbacks
operator|*
name|Callbacks
block|;     }
expr_stmt|;
name|FactoryT
modifier|*
name|ConsumerFactory
decl_stmt|;
name|SourceFileCallbacks
modifier|*
name|Callbacks
decl_stmt|;
block|}
empty_stmt|;
return|return
name|new
name|FrontendActionFactoryAdapter
argument_list|(
name|ConsumerFactory
argument_list|,
name|Callbacks
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Returns the absolute path of \c File, by prepending it with
end_comment

begin_comment
comment|/// the current directory if \c File is not absolute.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Otherwise returns \c File.
end_comment

begin_comment
comment|/// If 'File' starts with "./", the returned path will not contain the "./".
end_comment

begin_comment
comment|/// Otherwise, the returned path will contain the literal path-concatenation of
end_comment

begin_comment
comment|/// the current directory and \c File.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The difference to llvm::sys::fs::make_absolute is the canonicalization this
end_comment

begin_comment
comment|/// does by removing "./" and computing native paths.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param File Either an absolute or relative path.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|getAbsolutePath
argument_list|(
argument|StringRef File
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// end namespace tooling
end_comment

begin_comment
unit|}
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

