begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Utils.h - Misc utilities for the front-end -------------*- C++ -*-===//
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
comment|//  This header contains miscellaneous utilities for various front-end actions.
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
name|LLVM_CLANG_FRONTEND_UTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_UTILS_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/Diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/VirtualFileSystem.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
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
file|"llvm/Option/OptSpecifier.h"
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_fd_ostream
decl_stmt|;
name|class
name|Triple
decl_stmt|;
name|namespace
name|opt
block|{
name|class
name|ArgList
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTConsumer
decl_stmt|;
name|class
name|ASTReader
decl_stmt|;
name|class
name|CompilerInstance
decl_stmt|;
name|class
name|CompilerInvocation
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|DependencyOutputOptions
decl_stmt|;
name|class
name|DiagnosticsEngine
decl_stmt|;
name|class
name|DiagnosticOptions
decl_stmt|;
name|class
name|ExternalSemaSource
decl_stmt|;
name|class
name|FileManager
decl_stmt|;
name|class
name|HeaderSearch
decl_stmt|;
name|class
name|HeaderSearchOptions
decl_stmt|;
name|class
name|IdentifierTable
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|PCHContainerReader
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|class
name|PreprocessorOptions
decl_stmt|;
name|class
name|PreprocessorOutputOptions
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
name|class
name|TargetInfo
decl_stmt|;
name|class
name|FrontendOptions
decl_stmt|;
comment|/// Apply the header search options to get given HeaderSearch object.
name|void
name|ApplyHeaderSearchOptions
argument_list|(
name|HeaderSearch
operator|&
name|HS
argument_list|,
specifier|const
name|HeaderSearchOptions
operator|&
name|HSOpts
argument_list|,
specifier|const
name|LangOptions
operator|&
name|Lang
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|triple
argument_list|)
decl_stmt|;
comment|/// InitializePreprocessor - Initialize the preprocessor getting it and the
comment|/// environment ready to process a single file.
name|void
name|InitializePreprocessor
parameter_list|(
name|Preprocessor
modifier|&
name|PP
parameter_list|,
specifier|const
name|PreprocessorOptions
modifier|&
name|PPOpts
parameter_list|,
specifier|const
name|PCHContainerReader
modifier|&
name|PCHContainerRdr
parameter_list|,
specifier|const
name|FrontendOptions
modifier|&
name|FEOpts
parameter_list|)
function_decl|;
comment|/// DoPrintPreprocessedInput - Implement -E mode.
name|void
name|DoPrintPreprocessedInput
parameter_list|(
name|Preprocessor
modifier|&
name|PP
parameter_list|,
name|raw_ostream
modifier|*
name|OS
parameter_list|,
specifier|const
name|PreprocessorOutputOptions
modifier|&
name|Opts
parameter_list|)
function_decl|;
comment|/// An interface for collecting the dependencies of a compilation. Users should
comment|/// use \c attachToPreprocessor and \c attachToASTReader to get all of the
comment|/// dependencies.
comment|/// FIXME: Migrate DependencyFileGen and DependencyGraphGen to use this
comment|/// interface.
name|class
name|DependencyCollector
block|{
name|public
label|:
name|virtual
name|void
name|attachToPreprocessor
parameter_list|(
name|Preprocessor
modifier|&
name|PP
parameter_list|)
function_decl|;
name|virtual
name|void
name|attachToASTReader
parameter_list|(
name|ASTReader
modifier|&
name|R
parameter_list|)
function_decl|;
name|llvm
operator|::
name|ArrayRef
operator|<
name|std
operator|::
name|string
operator|>
name|getDependencies
argument_list|()
specifier|const
block|{
return|return
name|Dependencies
return|;
block|}
comment|/// Called when a new file is seen. Return true if \p Filename should be added
comment|/// to the list of dependencies.
comment|///
comment|/// The default implementation ignores<built-in> and system files.
name|virtual
name|bool
name|sawDependency
parameter_list|(
name|StringRef
name|Filename
parameter_list|,
name|bool
name|FromModule
parameter_list|,
name|bool
name|IsSystem
parameter_list|,
name|bool
name|IsModuleFile
parameter_list|,
name|bool
name|IsMissing
parameter_list|)
function_decl|;
comment|/// Called when the end of the main file is reached.
name|virtual
name|void
name|finishedMainFile
parameter_list|()
block|{ }
comment|/// Return true if system files should be passed to sawDependency().
name|virtual
name|bool
name|needSystemDependencies
parameter_list|()
block|{
return|return
name|false
return|;
block|}
name|virtual
operator|~
name|DependencyCollector
argument_list|()
expr_stmt|;
name|public
label|:
comment|// implementation detail
comment|/// Add a dependency \p Filename if it has not been seen before and
comment|/// sawDependency() returns true.
name|void
name|maybeAddDependency
parameter_list|(
name|StringRef
name|Filename
parameter_list|,
name|bool
name|FromModule
parameter_list|,
name|bool
name|IsSystem
parameter_list|,
name|bool
name|IsModuleFile
parameter_list|,
name|bool
name|IsMissing
parameter_list|)
function_decl|;
name|private
label|:
name|llvm
operator|::
name|StringSet
operator|<
operator|>
name|Seen
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Dependencies
expr_stmt|;
block|}
empty_stmt|;
comment|/// Builds a depdenency file when attached to a Preprocessor (for includes) and
comment|/// ASTReader (for module imports), and writes it out at the end of processing
comment|/// a source file.  Users should attach to the ast reader whenever a module is
comment|/// loaded.
name|class
name|DependencyFileGenerator
block|{
name|void
modifier|*
name|Impl
decl_stmt|;
comment|// Opaque implementation
name|DependencyFileGenerator
argument_list|(
name|void
operator|*
name|Impl
argument_list|)
expr_stmt|;
name|public
label|:
specifier|static
name|DependencyFileGenerator
modifier|*
name|CreateAndAttachToPreprocessor
parameter_list|(
name|Preprocessor
modifier|&
name|PP
parameter_list|,
specifier|const
name|DependencyOutputOptions
modifier|&
name|Opts
parameter_list|)
function_decl|;
name|void
name|AttachToASTReader
parameter_list|(
name|ASTReader
modifier|&
name|R
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// Collects the dependencies for imported modules into a directory.  Users
comment|/// should attach to the AST reader whenever a module is loaded.
name|class
name|ModuleDependencyCollector
range|:
name|public
name|DependencyCollector
block|{
name|std
operator|::
name|string
name|DestDir
block|;
name|bool
name|HasErrors
operator|=
name|false
block|;
name|llvm
operator|::
name|StringSet
operator|<
operator|>
name|Seen
block|;
name|vfs
operator|::
name|YAMLVFSWriter
name|VFSWriter
block|;
name|llvm
operator|::
name|StringMap
operator|<
name|std
operator|::
name|string
operator|>
name|SymLinkMap
block|;
name|bool
name|getRealPath
argument_list|(
argument|StringRef SrcPath
argument_list|,
argument|SmallVectorImpl<char>&Result
argument_list|)
block|;
name|std
operator|::
name|error_code
name|copyToRoot
argument_list|(
argument|StringRef Src
argument_list|,
argument|StringRef Dst =
literal|""
argument_list|)
block|;
name|public
operator|:
name|StringRef
name|getDest
argument_list|()
block|{
return|return
name|DestDir
return|;
block|}
name|bool
name|insertSeen
argument_list|(
argument|StringRef Filename
argument_list|)
block|{
return|return
name|Seen
operator|.
name|insert
argument_list|(
name|Filename
argument_list|)
operator|.
name|second
return|;
block|}
name|void
name|addFile
argument_list|(
argument|StringRef Filename
argument_list|,
argument|StringRef FileDst =
literal|""
argument_list|)
block|;
name|void
name|addFileMapping
argument_list|(
argument|StringRef VPath
argument_list|,
argument|StringRef RPath
argument_list|)
block|{
name|VFSWriter
operator|.
name|addFileMapping
argument_list|(
name|VPath
argument_list|,
name|RPath
argument_list|)
block|;   }
name|void
name|attachToPreprocessor
argument_list|(
argument|Preprocessor&PP
argument_list|)
name|override
block|;
name|void
name|attachToASTReader
argument_list|(
argument|ASTReader&R
argument_list|)
name|override
block|;
name|void
name|writeFileMap
argument_list|()
block|;
name|bool
name|hasErrors
argument_list|()
block|{
return|return
name|HasErrors
return|;
block|}
name|ModuleDependencyCollector
argument_list|(
argument|std::string DestDir
argument_list|)
operator|:
name|DestDir
argument_list|(
argument|std::move(DestDir)
argument_list|)
block|{}
operator|~
name|ModuleDependencyCollector
argument_list|()
block|{
name|writeFileMap
argument_list|()
block|; }
expr|}
block|;
comment|/// AttachDependencyGraphGen - Create a dependency graph generator, and attach
comment|/// it to the given preprocessor.
name|void
name|AttachDependencyGraphGen
argument_list|(
argument|Preprocessor&PP
argument_list|,
argument|StringRef OutputFile
argument_list|,
argument|StringRef SysRoot
argument_list|)
block|;
comment|/// AttachHeaderIncludeGen - Create a header include list generator, and attach
comment|/// it to the given preprocessor.
comment|///
comment|/// \param DepOpts - Options controlling the output.
comment|/// \param ShowAllHeaders - If true, show all header information instead of just
comment|/// headers following the predefines buffer. This is useful for making sure
comment|/// includes mentioned on the command line are also reported, but differs from
comment|/// the default behavior used by -H.
comment|/// \param OutputPath - If non-empty, a path to write the header include
comment|/// information to, instead of writing to stderr.
comment|/// \param ShowDepth - Whether to indent to show the nesting of the includes.
comment|/// \param MSStyle - Whether to print in cl.exe /showIncludes style.
name|void
name|AttachHeaderIncludeGen
argument_list|(
argument|Preprocessor&PP
argument_list|,
argument|const DependencyOutputOptions&DepOpts
argument_list|,
argument|bool ShowAllHeaders = false
argument_list|,
argument|StringRef OutputPath =
literal|""
argument_list|,
argument|bool ShowDepth = true
argument_list|,
argument|bool MSStyle = false
argument_list|)
block|;
comment|/// Cache tokens for use with PCH. Note that this requires a seekable stream.
name|void
name|CacheTokens
argument_list|(
name|Preprocessor
operator|&
name|PP
argument_list|,
name|raw_pwrite_stream
operator|*
name|OS
argument_list|)
block|;
comment|/// The ChainedIncludesSource class converts headers to chained PCHs in
comment|/// memory, mainly for testing.
name|IntrusiveRefCntPtr
operator|<
name|ExternalSemaSource
operator|>
name|createChainedIncludesSource
argument_list|(
name|CompilerInstance
operator|&
name|CI
argument_list|,
name|IntrusiveRefCntPtr
operator|<
name|ExternalSemaSource
operator|>
operator|&
name|Reader
argument_list|)
block|;
comment|/// createInvocationFromCommandLine - Construct a compiler invocation object for
comment|/// a command line argument vector.
comment|///
comment|/// \return A CompilerInvocation, or 0 if none was built for the given
comment|/// argument vector.
name|std
operator|::
name|unique_ptr
operator|<
name|CompilerInvocation
operator|>
name|createInvocationFromCommandLine
argument_list|(
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|Args
argument_list|,
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticsEngine
operator|>
name|Diags
operator|=
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticsEngine
operator|>
operator|(
operator|)
argument_list|,
name|IntrusiveRefCntPtr
operator|<
name|vfs
operator|::
name|FileSystem
operator|>
name|VFS
operator|=
name|nullptr
argument_list|)
block|;
comment|/// Return the value of the last argument as an integer, or a default. If Diags
comment|/// is non-null, emits an error if the argument is given, but non-integral.
name|int
name|getLastArgIntValue
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::OptSpecifier Id
argument_list|,
argument|int Default
argument_list|,
argument|DiagnosticsEngine *Diags = nullptr
argument_list|)
block|;
specifier|inline
name|int
name|getLastArgIntValue
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::OptSpecifier Id
argument_list|,
argument|int Default
argument_list|,
argument|DiagnosticsEngine&Diags
argument_list|)
block|{
return|return
name|getLastArgIntValue
argument_list|(
name|Args
argument_list|,
name|Id
argument_list|,
name|Default
argument_list|,
operator|&
name|Diags
argument_list|)
return|;
block|}
name|uint64_t
name|getLastArgUInt64Value
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::OptSpecifier Id
argument_list|,
argument|uint64_t Default
argument_list|,
argument|DiagnosticsEngine *Diags = nullptr
argument_list|)
block|;
specifier|inline
name|uint64_t
name|getLastArgUInt64Value
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::OptSpecifier Id
argument_list|,
argument|uint64_t Default
argument_list|,
argument|DiagnosticsEngine&Diags
argument_list|)
block|{
return|return
name|getLastArgUInt64Value
argument_list|(
name|Args
argument_list|,
name|Id
argument_list|,
name|Default
argument_list|,
operator|&
name|Diags
argument_list|)
return|;
block|}
comment|// When Clang->getFrontendOpts().DisableFree is set we don't delete some of the
comment|// global objects, but we don't want LeakDetectors to complain, so we bury them
comment|// in a globally visible array.
name|void
name|BuryPointer
argument_list|(
specifier|const
name|void
operator|*
name|Ptr
argument_list|)
block|;
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|BuryPointer
argument_list|(
argument|std::unique_ptr<T> Ptr
argument_list|)
block|{
name|BuryPointer
argument_list|(
name|Ptr
operator|.
name|release
argument_list|()
argument_list|)
block|; }
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

