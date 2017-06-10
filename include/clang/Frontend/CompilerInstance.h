begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CompilerInstance.h - Clang Compiler Instance ------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_FRONTEND_COMPILERINSTANCE_H_
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_COMPILERINSTANCE_H_
end_define

begin_include
include|#
directive|include
file|"clang/AST/ASTConsumer.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/CompilerInvocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/PCHContainerOperations.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/Utils.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/HeaderSearchOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/ModuleLoader.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
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
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
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
name|Timer
decl_stmt|;
name|class
name|TimerGroup
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|ASTReader
decl_stmt|;
name|class
name|CodeCompleteConsumer
decl_stmt|;
name|class
name|DiagnosticsEngine
decl_stmt|;
name|class
name|DiagnosticConsumer
decl_stmt|;
name|class
name|ExternalASTSource
decl_stmt|;
name|class
name|FileEntry
decl_stmt|;
name|class
name|FileManager
decl_stmt|;
name|class
name|FrontendAction
decl_stmt|;
name|class
name|MemoryBufferCache
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|class
name|Sema
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
name|class
name|TargetInfo
decl_stmt|;
comment|/// CompilerInstance - Helper class for managing a single instance of the Clang
comment|/// compiler.
comment|///
comment|/// The CompilerInstance serves two purposes:
comment|///  (1) It manages the various objects which are necessary to run the compiler,
comment|///      for example the preprocessor, the target information, and the AST
comment|///      context.
comment|///  (2) It provides utility routines for constructing and manipulating the
comment|///      common Clang objects.
comment|///
comment|/// The compiler instance generally owns the instance of all the objects that it
comment|/// manages. However, clients can still share objects by manually setting the
comment|/// object and retaking ownership prior to destroying the CompilerInstance.
comment|///
comment|/// The compiler instance is intended to simplify clients, but not to lock them
comment|/// in to the compiler instance for everything. When possible, utility functions
comment|/// come in two forms; a short form that reuses the CompilerInstance objects,
comment|/// and a long form that takes explicit instances of any required objects.
name|class
name|CompilerInstance
range|:
name|public
name|ModuleLoader
block|{
comment|/// The options used in this compiler instance.
name|std
operator|::
name|shared_ptr
operator|<
name|CompilerInvocation
operator|>
name|Invocation
block|;
comment|/// The diagnostics engine instance.
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticsEngine
operator|>
name|Diagnostics
block|;
comment|/// The target being compiled for.
name|IntrusiveRefCntPtr
operator|<
name|TargetInfo
operator|>
name|Target
block|;
comment|/// Auxiliary Target info.
name|IntrusiveRefCntPtr
operator|<
name|TargetInfo
operator|>
name|AuxTarget
block|;
comment|/// The virtual file system.
name|IntrusiveRefCntPtr
operator|<
name|vfs
operator|::
name|FileSystem
operator|>
name|VirtualFileSystem
block|;
comment|/// The file manager.
name|IntrusiveRefCntPtr
operator|<
name|FileManager
operator|>
name|FileMgr
block|;
comment|/// The source manager.
name|IntrusiveRefCntPtr
operator|<
name|SourceManager
operator|>
name|SourceMgr
block|;
comment|/// The cache of PCM files.
name|IntrusiveRefCntPtr
operator|<
name|MemoryBufferCache
operator|>
name|PCMCache
block|;
comment|/// The preprocessor.
name|std
operator|::
name|shared_ptr
operator|<
name|Preprocessor
operator|>
name|PP
block|;
comment|/// The AST context.
name|IntrusiveRefCntPtr
operator|<
name|ASTContext
operator|>
name|Context
block|;
comment|/// An optional sema source that will be attached to sema.
name|IntrusiveRefCntPtr
operator|<
name|ExternalSemaSource
operator|>
name|ExternalSemaSrc
block|;
comment|/// The AST consumer.
name|std
operator|::
name|unique_ptr
operator|<
name|ASTConsumer
operator|>
name|Consumer
block|;
comment|/// The code completion consumer.
name|std
operator|::
name|unique_ptr
operator|<
name|CodeCompleteConsumer
operator|>
name|CompletionConsumer
block|;
comment|/// \brief The semantic analysis object.
name|std
operator|::
name|unique_ptr
operator|<
name|Sema
operator|>
name|TheSema
block|;
comment|/// \brief The frontend timer group.
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|TimerGroup
operator|>
name|FrontendTimerGroup
block|;
comment|/// \brief The frontend timer.
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|Timer
operator|>
name|FrontendTimer
block|;
comment|/// \brief The ASTReader, if one exists.
name|IntrusiveRefCntPtr
operator|<
name|ASTReader
operator|>
name|ModuleManager
block|;
comment|/// \brief The module dependency collector for crashdumps
name|std
operator|::
name|shared_ptr
operator|<
name|ModuleDependencyCollector
operator|>
name|ModuleDepCollector
block|;
comment|/// \brief The module provider.
name|std
operator|::
name|shared_ptr
operator|<
name|PCHContainerOperations
operator|>
name|ThePCHContainerOperations
block|;
comment|/// \brief The dependency file generator.
name|std
operator|::
name|unique_ptr
operator|<
name|DependencyFileGenerator
operator|>
name|TheDependencyFileGenerator
block|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|shared_ptr
operator|<
name|DependencyCollector
operator|>>
name|DependencyCollectors
block|;
comment|/// \brief The set of top-level modules that has already been loaded,
comment|/// along with the module map
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|IdentifierInfo
operator|*
block|,
name|Module
operator|*
operator|>
name|KnownModules
block|;
comment|/// \brief The set of top-level modules that has already been built on the
comment|/// fly as part of this overall compilation action.
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
block|,
name|std
operator|::
name|string
operator|>
name|BuiltModules
block|;
comment|/// Should we delete the BuiltModules when we're done?
name|bool
name|DeleteBuiltModules
operator|=
name|true
block|;
comment|/// \brief The location of the module-import keyword for the last module
comment|/// import.
name|SourceLocation
name|LastModuleImportLoc
block|;
comment|/// \brief The result of the last module import.
comment|///
name|ModuleLoadResult
name|LastModuleImportResult
block|;
comment|/// \brief Whether we should (re)build the global module index once we
comment|/// have finished with this translation unit.
name|bool
name|BuildGlobalModuleIndex
operator|=
name|false
block|;
comment|/// \brief We have a full global module index, with all modules.
name|bool
name|HaveFullGlobalModuleIndex
operator|=
name|false
block|;
comment|/// \brief One or more modules failed to build.
name|bool
name|ModuleBuildFailed
operator|=
name|false
block|;
comment|/// \brief Holds information about the output file.
comment|///
comment|/// If TempFilename is not empty we must rename it to Filename at the end.
comment|/// TempFilename may be empty and Filename non-empty if creating the temporary
comment|/// failed.
block|struct
name|OutputFile
block|{
name|std
operator|::
name|string
name|Filename
block|;
name|std
operator|::
name|string
name|TempFilename
block|;
name|OutputFile
argument_list|(
argument|std::string filename
argument_list|,
argument|std::string tempFilename
argument_list|)
operator|:
name|Filename
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|filename
argument_list|)
argument_list|)
block|,
name|TempFilename
argument_list|(
argument|std::move(tempFilename)
argument_list|)
block|{     }
block|}
block|;
comment|/// If the output doesn't support seeking (terminal, pipe). we switch
comment|/// the stream to a buffer_ostream. These are the buffer and the original
comment|/// stream.
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|raw_fd_ostream
operator|>
name|NonSeekStream
block|;
comment|/// The list of active output files.
name|std
operator|::
name|list
operator|<
name|OutputFile
operator|>
name|OutputFiles
block|;
name|CompilerInstance
argument_list|(
specifier|const
name|CompilerInstance
operator|&
argument_list|)
operator|=
name|delete
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|CompilerInstance
operator|&
operator|)
operator|=
name|delete
block|;
name|public
operator|:
name|explicit
name|CompilerInstance
argument_list|(
name|std
operator|::
name|shared_ptr
operator|<
name|PCHContainerOperations
operator|>
name|PCHContainerOps
operator|=
name|std
operator|::
name|make_shared
operator|<
name|PCHContainerOperations
operator|>
operator|(
operator|)
argument_list|,
name|MemoryBufferCache
operator|*
name|SharedPCMCache
operator|=
name|nullptr
argument_list|)
block|;
operator|~
name|CompilerInstance
argument_list|()
name|override
block|;
comment|/// @name High-Level Operations
comment|/// {
comment|/// ExecuteAction - Execute the provided action against the compiler's
comment|/// CompilerInvocation object.
comment|///
comment|/// This function makes the following assumptions:
comment|///
comment|///  - The invocation options should be initialized. This function does not
comment|///    handle the '-help' or '-version' options, clients should handle those
comment|///    directly.
comment|///
comment|///  - The diagnostics engine should have already been created by the client.
comment|///
comment|///  - No other CompilerInstance state should have been initialized (this is
comment|///    an unchecked error).
comment|///
comment|///  - Clients should have initialized any LLVM target features that may be
comment|///    required.
comment|///
comment|///  - Clients should eventually call llvm_shutdown() upon the completion of
comment|///    this routine to ensure that any managed objects are properly destroyed.
comment|///
comment|/// Note that this routine may write output to 'stderr'.
comment|///
comment|/// \param Act - The action to execute.
comment|/// \return - True on success.
comment|//
comment|// FIXME: This function should take the stream to write any debugging /
comment|// verbose output to as an argument.
comment|//
comment|// FIXME: Eliminate the llvm_shutdown requirement, that should either be part
comment|// of the context or else not CompilerInstance specific.
name|bool
name|ExecuteAction
argument_list|(
name|FrontendAction
operator|&
name|Act
argument_list|)
block|;
comment|/// }
comment|/// @name Compiler Invocation and Options
comment|/// {
name|bool
name|hasInvocation
argument_list|()
specifier|const
block|{
return|return
name|Invocation
operator|!=
name|nullptr
return|;
block|}
name|CompilerInvocation
operator|&
name|getInvocation
argument_list|()
block|{
name|assert
argument_list|(
name|Invocation
operator|&&
literal|"Compiler instance has no invocation!"
argument_list|)
block|;
return|return
operator|*
name|Invocation
return|;
block|}
comment|/// setInvocation - Replace the current invocation.
name|void
name|setInvocation
argument_list|(
name|std
operator|::
name|shared_ptr
operator|<
name|CompilerInvocation
operator|>
name|Value
argument_list|)
block|;
comment|/// \brief Indicates whether we should (re)build the global module index.
name|bool
name|shouldBuildGlobalModuleIndex
argument_list|()
specifier|const
block|;
comment|/// \brief Set the flag indicating whether we should (re)build the global
comment|/// module index.
name|void
name|setBuildGlobalModuleIndex
argument_list|(
argument|bool Build
argument_list|)
block|{
name|BuildGlobalModuleIndex
operator|=
name|Build
block|;   }
comment|/// }
comment|/// @name Forwarding Methods
comment|/// {
name|AnalyzerOptionsRef
name|getAnalyzerOpts
argument_list|()
block|{
return|return
name|Invocation
operator|->
name|getAnalyzerOpts
argument_list|()
return|;
block|}
name|CodeGenOptions
operator|&
name|getCodeGenOpts
argument_list|()
block|{
return|return
name|Invocation
operator|->
name|getCodeGenOpts
argument_list|()
return|;
block|}
specifier|const
name|CodeGenOptions
operator|&
name|getCodeGenOpts
argument_list|()
specifier|const
block|{
return|return
name|Invocation
operator|->
name|getCodeGenOpts
argument_list|()
return|;
block|}
name|DependencyOutputOptions
operator|&
name|getDependencyOutputOpts
argument_list|()
block|{
return|return
name|Invocation
operator|->
name|getDependencyOutputOpts
argument_list|()
return|;
block|}
specifier|const
name|DependencyOutputOptions
operator|&
name|getDependencyOutputOpts
argument_list|()
specifier|const
block|{
return|return
name|Invocation
operator|->
name|getDependencyOutputOpts
argument_list|()
return|;
block|}
name|DiagnosticOptions
operator|&
name|getDiagnosticOpts
argument_list|()
block|{
return|return
name|Invocation
operator|->
name|getDiagnosticOpts
argument_list|()
return|;
block|}
specifier|const
name|DiagnosticOptions
operator|&
name|getDiagnosticOpts
argument_list|()
specifier|const
block|{
return|return
name|Invocation
operator|->
name|getDiagnosticOpts
argument_list|()
return|;
block|}
name|FileSystemOptions
operator|&
name|getFileSystemOpts
argument_list|()
block|{
return|return
name|Invocation
operator|->
name|getFileSystemOpts
argument_list|()
return|;
block|}
specifier|const
name|FileSystemOptions
operator|&
name|getFileSystemOpts
argument_list|()
specifier|const
block|{
return|return
name|Invocation
operator|->
name|getFileSystemOpts
argument_list|()
return|;
block|}
name|FrontendOptions
operator|&
name|getFrontendOpts
argument_list|()
block|{
return|return
name|Invocation
operator|->
name|getFrontendOpts
argument_list|()
return|;
block|}
specifier|const
name|FrontendOptions
operator|&
name|getFrontendOpts
argument_list|()
specifier|const
block|{
return|return
name|Invocation
operator|->
name|getFrontendOpts
argument_list|()
return|;
block|}
name|HeaderSearchOptions
operator|&
name|getHeaderSearchOpts
argument_list|()
block|{
return|return
name|Invocation
operator|->
name|getHeaderSearchOpts
argument_list|()
return|;
block|}
specifier|const
name|HeaderSearchOptions
operator|&
name|getHeaderSearchOpts
argument_list|()
specifier|const
block|{
return|return
name|Invocation
operator|->
name|getHeaderSearchOpts
argument_list|()
return|;
block|}
name|std
operator|::
name|shared_ptr
operator|<
name|HeaderSearchOptions
operator|>
name|getHeaderSearchOptsPtr
argument_list|()
specifier|const
block|{
return|return
name|Invocation
operator|->
name|getHeaderSearchOptsPtr
argument_list|()
return|;
block|}
name|LangOptions
operator|&
name|getLangOpts
argument_list|()
block|{
return|return
operator|*
name|Invocation
operator|->
name|getLangOpts
argument_list|()
return|;
block|}
specifier|const
name|LangOptions
operator|&
name|getLangOpts
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Invocation
operator|->
name|getLangOpts
argument_list|()
return|;
block|}
name|PreprocessorOptions
operator|&
name|getPreprocessorOpts
argument_list|()
block|{
return|return
name|Invocation
operator|->
name|getPreprocessorOpts
argument_list|()
return|;
block|}
specifier|const
name|PreprocessorOptions
operator|&
name|getPreprocessorOpts
argument_list|()
specifier|const
block|{
return|return
name|Invocation
operator|->
name|getPreprocessorOpts
argument_list|()
return|;
block|}
name|PreprocessorOutputOptions
operator|&
name|getPreprocessorOutputOpts
argument_list|()
block|{
return|return
name|Invocation
operator|->
name|getPreprocessorOutputOpts
argument_list|()
return|;
block|}
specifier|const
name|PreprocessorOutputOptions
operator|&
name|getPreprocessorOutputOpts
argument_list|()
specifier|const
block|{
return|return
name|Invocation
operator|->
name|getPreprocessorOutputOpts
argument_list|()
return|;
block|}
name|TargetOptions
operator|&
name|getTargetOpts
argument_list|()
block|{
return|return
name|Invocation
operator|->
name|getTargetOpts
argument_list|()
return|;
block|}
specifier|const
name|TargetOptions
operator|&
name|getTargetOpts
argument_list|()
specifier|const
block|{
return|return
name|Invocation
operator|->
name|getTargetOpts
argument_list|()
return|;
block|}
comment|/// }
comment|/// @name Diagnostics Engine
comment|/// {
name|bool
name|hasDiagnostics
argument_list|()
specifier|const
block|{
return|return
name|Diagnostics
operator|!=
name|nullptr
return|;
block|}
comment|/// Get the current diagnostics engine.
name|DiagnosticsEngine
operator|&
name|getDiagnostics
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Diagnostics
operator|&&
literal|"Compiler instance has no diagnostics!"
argument_list|)
block|;
return|return
operator|*
name|Diagnostics
return|;
block|}
comment|/// setDiagnostics - Replace the current diagnostics engine.
name|void
name|setDiagnostics
argument_list|(
name|DiagnosticsEngine
operator|*
name|Value
argument_list|)
block|;
name|DiagnosticConsumer
operator|&
name|getDiagnosticClient
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Diagnostics
operator|&&
name|Diagnostics
operator|->
name|getClient
argument_list|()
operator|&&
literal|"Compiler instance has no diagnostic client!"
argument_list|)
block|;
return|return
operator|*
name|Diagnostics
operator|->
name|getClient
argument_list|()
return|;
block|}
comment|/// }
comment|/// @name Target Info
comment|/// {
name|bool
name|hasTarget
argument_list|()
specifier|const
block|{
return|return
name|Target
operator|!=
name|nullptr
return|;
block|}
name|TargetInfo
operator|&
name|getTarget
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Target
operator|&&
literal|"Compiler instance has no target!"
argument_list|)
block|;
return|return
operator|*
name|Target
return|;
block|}
comment|/// Replace the current Target.
name|void
name|setTarget
argument_list|(
name|TargetInfo
operator|*
name|Value
argument_list|)
block|;
comment|/// }
comment|/// @name AuxTarget Info
comment|/// {
name|TargetInfo
operator|*
name|getAuxTarget
argument_list|()
specifier|const
block|{
return|return
name|AuxTarget
operator|.
name|get
argument_list|()
return|;
block|}
comment|/// Replace the current AuxTarget.
name|void
name|setAuxTarget
argument_list|(
name|TargetInfo
operator|*
name|Value
argument_list|)
block|;
comment|/// }
comment|/// @name Virtual File System
comment|/// {
name|bool
name|hasVirtualFileSystem
argument_list|()
specifier|const
block|{
return|return
name|VirtualFileSystem
operator|!=
name|nullptr
return|;
block|}
name|vfs
operator|::
name|FileSystem
operator|&
name|getVirtualFileSystem
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|hasVirtualFileSystem
argument_list|()
operator|&&
literal|"Compiler instance has no virtual file system"
argument_list|)
block|;
return|return
operator|*
name|VirtualFileSystem
return|;
block|}
comment|/// \brief Replace the current virtual file system.
comment|///
comment|/// \note Most clients should use setFileManager, which will implicitly reset
comment|/// the virtual file system to the one contained in the file manager.
name|void
name|setVirtualFileSystem
argument_list|(
argument|IntrusiveRefCntPtr<vfs::FileSystem> FS
argument_list|)
block|{
name|VirtualFileSystem
operator|=
name|std
operator|::
name|move
argument_list|(
name|FS
argument_list|)
block|;   }
comment|/// }
comment|/// @name File Manager
comment|/// {
name|bool
name|hasFileManager
argument_list|()
specifier|const
block|{
return|return
name|FileMgr
operator|!=
name|nullptr
return|;
block|}
comment|/// Return the current file manager to the caller.
name|FileManager
operator|&
name|getFileManager
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|FileMgr
operator|&&
literal|"Compiler instance has no file manager!"
argument_list|)
block|;
return|return
operator|*
name|FileMgr
return|;
block|}
name|void
name|resetAndLeakFileManager
argument_list|()
block|{
name|BuryPointer
argument_list|(
name|FileMgr
operator|.
name|get
argument_list|()
argument_list|)
block|;
name|FileMgr
operator|.
name|resetWithoutRelease
argument_list|()
block|;   }
comment|/// \brief Replace the current file manager and virtual file system.
name|void
name|setFileManager
argument_list|(
name|FileManager
operator|*
name|Value
argument_list|)
block|;
comment|/// }
comment|/// @name Source Manager
comment|/// {
name|bool
name|hasSourceManager
argument_list|()
specifier|const
block|{
return|return
name|SourceMgr
operator|!=
name|nullptr
return|;
block|}
comment|/// Return the current source manager.
name|SourceManager
operator|&
name|getSourceManager
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|SourceMgr
operator|&&
literal|"Compiler instance has no source manager!"
argument_list|)
block|;
return|return
operator|*
name|SourceMgr
return|;
block|}
name|void
name|resetAndLeakSourceManager
argument_list|()
block|{
name|BuryPointer
argument_list|(
name|SourceMgr
operator|.
name|get
argument_list|()
argument_list|)
block|;
name|SourceMgr
operator|.
name|resetWithoutRelease
argument_list|()
block|;   }
comment|/// setSourceManager - Replace the current source manager.
name|void
name|setSourceManager
argument_list|(
name|SourceManager
operator|*
name|Value
argument_list|)
block|;
comment|/// }
comment|/// @name Preprocessor
comment|/// {
name|bool
name|hasPreprocessor
argument_list|()
specifier|const
block|{
return|return
name|PP
operator|!=
name|nullptr
return|;
block|}
comment|/// Return the current preprocessor.
name|Preprocessor
operator|&
name|getPreprocessor
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|PP
operator|&&
literal|"Compiler instance has no preprocessor!"
argument_list|)
block|;
return|return
operator|*
name|PP
return|;
block|}
name|std
operator|::
name|shared_ptr
operator|<
name|Preprocessor
operator|>
name|getPreprocessorPtr
argument_list|()
block|{
return|return
name|PP
return|;
block|}
name|void
name|resetAndLeakPreprocessor
argument_list|()
block|{
name|BuryPointer
argument_list|(
argument|new std::shared_ptr<Preprocessor>(PP)
argument_list|)
block|;   }
comment|/// Replace the current preprocessor.
name|void
name|setPreprocessor
argument_list|(
name|std
operator|::
name|shared_ptr
operator|<
name|Preprocessor
operator|>
name|Value
argument_list|)
block|;
comment|/// }
comment|/// @name ASTContext
comment|/// {
name|bool
name|hasASTContext
argument_list|()
specifier|const
block|{
return|return
name|Context
operator|!=
name|nullptr
return|;
block|}
name|ASTContext
operator|&
name|getASTContext
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Context
operator|&&
literal|"Compiler instance has no AST context!"
argument_list|)
block|;
return|return
operator|*
name|Context
return|;
block|}
name|void
name|resetAndLeakASTContext
argument_list|()
block|{
name|BuryPointer
argument_list|(
name|Context
operator|.
name|get
argument_list|()
argument_list|)
block|;
name|Context
operator|.
name|resetWithoutRelease
argument_list|()
block|;   }
comment|/// setASTContext - Replace the current AST context.
name|void
name|setASTContext
argument_list|(
name|ASTContext
operator|*
name|Value
argument_list|)
block|;
comment|/// \brief Replace the current Sema; the compiler instance takes ownership
comment|/// of S.
name|void
name|setSema
argument_list|(
name|Sema
operator|*
name|S
argument_list|)
block|;
comment|/// }
comment|/// @name ASTConsumer
comment|/// {
name|bool
name|hasASTConsumer
argument_list|()
specifier|const
block|{
return|return
operator|(
name|bool
operator|)
name|Consumer
return|;
block|}
name|ASTConsumer
operator|&
name|getASTConsumer
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Consumer
operator|&&
literal|"Compiler instance has no AST consumer!"
argument_list|)
block|;
return|return
operator|*
name|Consumer
return|;
block|}
comment|/// takeASTConsumer - Remove the current AST consumer and give ownership to
comment|/// the caller.
name|std
operator|::
name|unique_ptr
operator|<
name|ASTConsumer
operator|>
name|takeASTConsumer
argument_list|()
block|{
return|return
name|std
operator|::
name|move
argument_list|(
name|Consumer
argument_list|)
return|;
block|}
comment|/// setASTConsumer - Replace the current AST consumer; the compiler instance
comment|/// takes ownership of \p Value.
name|void
name|setASTConsumer
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|ASTConsumer
operator|>
name|Value
argument_list|)
block|;
comment|/// }
comment|/// @name Semantic analysis
comment|/// {
name|bool
name|hasSema
argument_list|()
specifier|const
block|{
return|return
operator|(
name|bool
operator|)
name|TheSema
return|;
block|}
name|Sema
operator|&
name|getSema
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|TheSema
operator|&&
literal|"Compiler instance has no Sema object!"
argument_list|)
block|;
return|return
operator|*
name|TheSema
return|;
block|}
name|std
operator|::
name|unique_ptr
operator|<
name|Sema
operator|>
name|takeSema
argument_list|()
block|;
name|void
name|resetAndLeakSema
argument_list|()
block|;
comment|/// }
comment|/// @name Module Management
comment|/// {
name|IntrusiveRefCntPtr
operator|<
name|ASTReader
operator|>
name|getModuleManager
argument_list|()
specifier|const
block|;
name|void
name|setModuleManager
argument_list|(
name|IntrusiveRefCntPtr
operator|<
name|ASTReader
operator|>
name|Reader
argument_list|)
block|;
name|std
operator|::
name|shared_ptr
operator|<
name|ModuleDependencyCollector
operator|>
name|getModuleDepCollector
argument_list|()
specifier|const
block|;
name|void
name|setModuleDepCollector
argument_list|(
name|std
operator|::
name|shared_ptr
operator|<
name|ModuleDependencyCollector
operator|>
name|Collector
argument_list|)
block|;
name|std
operator|::
name|shared_ptr
operator|<
name|PCHContainerOperations
operator|>
name|getPCHContainerOperations
argument_list|()
specifier|const
block|{
return|return
name|ThePCHContainerOperations
return|;
block|}
comment|/// Return the appropriate PCHContainerWriter depending on the
comment|/// current CodeGenOptions.
specifier|const
name|PCHContainerWriter
operator|&
name|getPCHContainerWriter
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Invocation
operator|&&
literal|"cannot determine module format without invocation"
argument_list|)
block|;
name|StringRef
name|Format
operator|=
name|getHeaderSearchOpts
argument_list|()
operator|.
name|ModuleFormat
block|;
name|auto
operator|*
name|Writer
operator|=
name|ThePCHContainerOperations
operator|->
name|getWriterOrNull
argument_list|(
name|Format
argument_list|)
block|;
if|if
condition|(
operator|!
name|Writer
condition|)
block|{
if|if
condition|(
name|Diagnostics
condition|)
name|Diagnostics
operator|->
name|Report
argument_list|(
name|diag
operator|::
name|err_module_format_unhandled
argument_list|)
operator|<<
name|Format
expr_stmt|;
name|llvm
operator|::
name|report_fatal_error
argument_list|(
literal|"unknown module format"
argument_list|)
expr_stmt|;
block|}
return|return
operator|*
name|Writer
return|;
block|}
comment|/// Return the appropriate PCHContainerReader depending on the
comment|/// current CodeGenOptions.
specifier|const
name|PCHContainerReader
operator|&
name|getPCHContainerReader
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Invocation
operator|&&
literal|"cannot determine module format without invocation"
argument_list|)
block|;
name|StringRef
name|Format
operator|=
name|getHeaderSearchOpts
argument_list|()
operator|.
name|ModuleFormat
block|;
name|auto
operator|*
name|Reader
operator|=
name|ThePCHContainerOperations
operator|->
name|getReaderOrNull
argument_list|(
name|Format
argument_list|)
block|;
if|if
condition|(
operator|!
name|Reader
condition|)
block|{
if|if
condition|(
name|Diagnostics
condition|)
name|Diagnostics
operator|->
name|Report
argument_list|(
name|diag
operator|::
name|err_module_format_unhandled
argument_list|)
operator|<<
name|Format
expr_stmt|;
name|llvm
operator|::
name|report_fatal_error
argument_list|(
literal|"unknown module format"
argument_list|)
expr_stmt|;
block|}
return|return
operator|*
name|Reader
return|;
block|}
comment|/// }
comment|/// @name Code Completion
comment|/// {
name|bool
name|hasCodeCompletionConsumer
argument_list|()
specifier|const
block|{
return|return
operator|(
name|bool
operator|)
name|CompletionConsumer
return|;
block|}
name|CodeCompleteConsumer
operator|&
name|getCodeCompletionConsumer
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|CompletionConsumer
operator|&&
literal|"Compiler instance has no code completion consumer!"
argument_list|)
block|;
return|return
operator|*
name|CompletionConsumer
return|;
block|}
comment|/// setCodeCompletionConsumer - Replace the current code completion consumer;
comment|/// the compiler instance takes ownership of \p Value.
name|void
name|setCodeCompletionConsumer
argument_list|(
name|CodeCompleteConsumer
operator|*
name|Value
argument_list|)
block|;
comment|/// }
comment|/// @name Frontend timer
comment|/// {
name|bool
name|hasFrontendTimer
argument_list|()
specifier|const
block|{
return|return
operator|(
name|bool
operator|)
name|FrontendTimer
return|;
block|}
name|llvm
operator|::
name|Timer
operator|&
name|getFrontendTimer
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|FrontendTimer
operator|&&
literal|"Compiler instance has no frontend timer!"
argument_list|)
block|;
return|return
operator|*
name|FrontendTimer
return|;
block|}
comment|/// }
comment|/// @name Output Files
comment|/// {
comment|/// addOutputFile - Add an output file onto the list of tracked output files.
comment|///
comment|/// \param OutFile - The output file info.
name|void
name|addOutputFile
argument_list|(
name|OutputFile
operator|&&
name|OutFile
argument_list|)
block|;
comment|/// clearOutputFiles - Clear the output file list. The underlying output
comment|/// streams must have been closed beforehand.
comment|///
comment|/// \param EraseFiles - If true, attempt to erase the files from disk.
name|void
name|clearOutputFiles
argument_list|(
argument|bool EraseFiles
argument_list|)
block|;
comment|/// }
comment|/// @name Construction Utility Methods
comment|/// {
comment|/// Create the diagnostics engine using the invocation's diagnostic options
comment|/// and replace any existing one with it.
comment|///
comment|/// Note that this routine also replaces the diagnostic client,
comment|/// allocating one if one is not provided.
comment|///
comment|/// \param Client If non-NULL, a diagnostic client that will be
comment|/// attached to (and, then, owned by) the DiagnosticsEngine inside this AST
comment|/// unit.
comment|///
comment|/// \param ShouldOwnClient If Client is non-NULL, specifies whether
comment|/// the diagnostic object should take ownership of the client.
name|void
name|createDiagnostics
argument_list|(
argument|DiagnosticConsumer *Client = nullptr
argument_list|,
argument|bool ShouldOwnClient = true
argument_list|)
block|;
comment|/// Create a DiagnosticsEngine object with a the TextDiagnosticPrinter.
comment|///
comment|/// If no diagnostic client is provided, this creates a
comment|/// DiagnosticConsumer that is owned by the returned diagnostic
comment|/// object, if using directly the caller is responsible for
comment|/// releasing the returned DiagnosticsEngine's client eventually.
comment|///
comment|/// \param Opts - The diagnostic options; note that the created text
comment|/// diagnostic object contains a reference to these options.
comment|///
comment|/// \param Client If non-NULL, a diagnostic client that will be
comment|/// attached to (and, then, owned by) the returned DiagnosticsEngine
comment|/// object.
comment|///
comment|/// \param CodeGenOpts If non-NULL, the code gen options in use, which may be
comment|/// used by some diagnostics printers (for logging purposes only).
comment|///
comment|/// \return The new object on success, or null on failure.
specifier|static
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticsEngine
operator|>
name|createDiagnostics
argument_list|(
argument|DiagnosticOptions *Opts
argument_list|,
argument|DiagnosticConsumer *Client = nullptr
argument_list|,
argument|bool ShouldOwnClient = true
argument_list|,
argument|const CodeGenOptions *CodeGenOpts = nullptr
argument_list|)
block|;
comment|/// Create the file manager and replace any existing one with it.
name|void
name|createFileManager
argument_list|()
block|;
comment|/// Create the source manager and replace any existing one with it.
name|void
name|createSourceManager
argument_list|(
name|FileManager
operator|&
name|FileMgr
argument_list|)
block|;
comment|/// Create the preprocessor, using the invocation, file, and source managers,
comment|/// and replace any existing one with it.
name|void
name|createPreprocessor
argument_list|(
argument|TranslationUnitKind TUKind
argument_list|)
block|;
name|std
operator|::
name|string
name|getSpecificModuleCachePath
argument_list|()
block|;
comment|/// Create the AST context.
name|void
name|createASTContext
argument_list|()
block|;
comment|/// Create an external AST source to read a PCH file and attach it to the AST
comment|/// context.
name|void
name|createPCHExternalASTSource
argument_list|(
argument|StringRef Path
argument_list|,
argument|bool DisablePCHValidation
argument_list|,
argument|bool AllowPCHWithCompilerErrors
argument_list|,
argument|void *DeserializationListener
argument_list|,
argument|bool OwnDeserializationListener
argument_list|)
block|;
comment|/// Create an external AST source to read a PCH file.
comment|///
comment|/// \return - The new object on success, or null on failure.
specifier|static
name|IntrusiveRefCntPtr
operator|<
name|ASTReader
operator|>
name|createPCHExternalASTSource
argument_list|(
argument|StringRef Path
argument_list|,
argument|StringRef Sysroot
argument_list|,
argument|bool DisablePCHValidation
argument_list|,
argument|bool AllowPCHWithCompilerErrors
argument_list|,
argument|Preprocessor&PP
argument_list|,
argument|ASTContext&Context
argument_list|,
argument|const PCHContainerReader&PCHContainerRdr
argument_list|,
argument|ArrayRef<std::shared_ptr<ModuleFileExtension>> Extensions
argument_list|,
argument|DependencyFileGenerator *DependencyFile
argument_list|,
argument|ArrayRef<std::shared_ptr<DependencyCollector>> DependencyCollectors
argument_list|,
argument|void *DeserializationListener
argument_list|,
argument|bool OwnDeserializationListener
argument_list|,
argument|bool Preamble
argument_list|,
argument|bool UseGlobalModuleIndex
argument_list|)
block|;
comment|/// Create a code completion consumer using the invocation; note that this
comment|/// will cause the source manager to truncate the input source file at the
comment|/// completion point.
name|void
name|createCodeCompletionConsumer
argument_list|()
block|;
comment|/// Create a code completion consumer to print code completion results, at
comment|/// \p Filename, \p Line, and \p Column, to the given output stream \p OS.
specifier|static
name|CodeCompleteConsumer
operator|*
name|createCodeCompletionConsumer
argument_list|(
argument|Preprocessor&PP
argument_list|,
argument|StringRef Filename
argument_list|,
argument|unsigned Line
argument_list|,
argument|unsigned Column
argument_list|,
argument|const CodeCompleteOptions&Opts
argument_list|,
argument|raw_ostream&OS
argument_list|)
block|;
comment|/// \brief Create the Sema object to be used for parsing.
name|void
name|createSema
argument_list|(
argument|TranslationUnitKind TUKind
argument_list|,
argument|CodeCompleteConsumer *CompletionConsumer
argument_list|)
block|;
comment|/// Create the frontend timer and replace any existing one with it.
name|void
name|createFrontendTimer
argument_list|()
block|;
comment|/// Create the default output file (from the invocation's options) and add it
comment|/// to the list of tracked output files.
comment|///
comment|/// The files created by this function always use temporary files to write to
comment|/// their result (that is, the data is written to a temporary file which will
comment|/// atomically replace the target output on success).
comment|///
comment|/// \return - Null on error.
name|std
operator|::
name|unique_ptr
operator|<
name|raw_pwrite_stream
operator|>
name|createDefaultOutputFile
argument_list|(
argument|bool Binary = true
argument_list|,
argument|StringRef BaseInput =
literal|""
argument_list|,
argument|StringRef Extension =
literal|""
argument_list|)
block|;
comment|/// Create a new output file and add it to the list of tracked output files,
comment|/// optionally deriving the output path name.
comment|///
comment|/// \return - Null on error.
name|std
operator|::
name|unique_ptr
operator|<
name|raw_pwrite_stream
operator|>
name|createOutputFile
argument_list|(
argument|StringRef OutputPath
argument_list|,
argument|bool Binary
argument_list|,
argument|bool RemoveFileOnSignal
argument_list|,
argument|StringRef BaseInput
argument_list|,
argument|StringRef Extension
argument_list|,
argument|bool UseTemporary
argument_list|,
argument|bool CreateMissingDirectories = false
argument_list|)
block|;
comment|/// Create a new output file, optionally deriving the output path name.
comment|///
comment|/// If \p OutputPath is empty, then createOutputFile will derive an output
comment|/// path location as \p BaseInput, with any suffix removed, and \p Extension
comment|/// appended. If \p OutputPath is not stdout and \p UseTemporary
comment|/// is true, createOutputFile will create a new temporary file that must be
comment|/// renamed to \p OutputPath in the end.
comment|///
comment|/// \param OutputPath - If given, the path to the output file.
comment|/// \param Error [out] - On failure, the error.
comment|/// \param BaseInput - If \p OutputPath is empty, the input path name to use
comment|/// for deriving the output path.
comment|/// \param Extension - The extension to use for derived output names.
comment|/// \param Binary - The mode to open the file in.
comment|/// \param RemoveFileOnSignal - Whether the file should be registered with
comment|/// llvm::sys::RemoveFileOnSignal. Note that this is not safe for
comment|/// multithreaded use, as the underlying signal mechanism is not reentrant
comment|/// \param UseTemporary - Create a new temporary file that must be renamed to
comment|/// OutputPath in the end.
comment|/// \param CreateMissingDirectories - When \p UseTemporary is true, create
comment|/// missing directories in the output path.
comment|/// \param ResultPathName [out] - If given, the result path name will be
comment|/// stored here on success.
comment|/// \param TempPathName [out] - If given, the temporary file path name
comment|/// will be stored here on success.
name|std
operator|::
name|unique_ptr
operator|<
name|raw_pwrite_stream
operator|>
name|createOutputFile
argument_list|(
argument|StringRef OutputPath
argument_list|,
argument|std::error_code&Error
argument_list|,
argument|bool Binary
argument_list|,
argument|bool RemoveFileOnSignal
argument_list|,
argument|StringRef BaseInput
argument_list|,
argument|StringRef Extension
argument_list|,
argument|bool UseTemporary
argument_list|,
argument|bool CreateMissingDirectories
argument_list|,
argument|std::string *ResultPathName
argument_list|,
argument|std::string *TempPathName
argument_list|)
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|raw_pwrite_stream
operator|>
name|createNullOutputFile
argument_list|()
block|;
comment|/// }
comment|/// @name Initialization Utility Methods
comment|/// {
comment|/// InitializeSourceManager - Initialize the source manager to set InputFile
comment|/// as the main file.
comment|///
comment|/// \return True on success.
name|bool
name|InitializeSourceManager
argument_list|(
specifier|const
name|FrontendInputFile
operator|&
name|Input
argument_list|)
block|;
comment|/// InitializeSourceManager - Initialize the source manager to set InputFile
comment|/// as the main file.
comment|///
comment|/// \return True on success.
specifier|static
name|bool
name|InitializeSourceManager
argument_list|(
specifier|const
name|FrontendInputFile
operator|&
name|Input
argument_list|,
name|DiagnosticsEngine
operator|&
name|Diags
argument_list|,
name|FileManager
operator|&
name|FileMgr
argument_list|,
name|SourceManager
operator|&
name|SourceMgr
argument_list|,
name|HeaderSearch
operator|*
name|HS
argument_list|,
name|DependencyOutputOptions
operator|&
name|DepOpts
argument_list|,
specifier|const
name|FrontendOptions
operator|&
name|Opts
argument_list|)
block|;
comment|/// }
comment|// Create module manager.
name|void
name|createModuleManager
argument_list|()
block|;
name|bool
name|loadModuleFile
argument_list|(
argument|StringRef FileName
argument_list|)
block|;
name|ModuleLoadResult
name|loadModule
argument_list|(
argument|SourceLocation ImportLoc
argument_list|,
argument|ModuleIdPath Path
argument_list|,
argument|Module::NameVisibilityKind Visibility
argument_list|,
argument|bool IsInclusionDirective
argument_list|)
name|override
block|;
name|void
name|loadModuleFromSource
argument_list|(
argument|SourceLocation ImportLoc
argument_list|,
argument|StringRef ModuleName
argument_list|,
argument|StringRef Source
argument_list|)
name|override
block|;
name|void
name|makeModuleVisible
argument_list|(
argument|Module *Mod
argument_list|,
argument|Module::NameVisibilityKind Visibility
argument_list|,
argument|SourceLocation ImportLoc
argument_list|)
name|override
block|;
name|bool
name|hadModuleLoaderFatalFailure
argument_list|()
specifier|const
block|{
return|return
name|ModuleLoader
operator|::
name|HadFatalFailure
return|;
block|}
name|GlobalModuleIndex
operator|*
name|loadGlobalModuleIndex
argument_list|(
argument|SourceLocation TriggerLoc
argument_list|)
name|override
block|;
name|bool
name|lookupMissingImports
argument_list|(
argument|StringRef Name
argument_list|,
argument|SourceLocation TriggerLoc
argument_list|)
name|override
block|;
name|void
name|addDependencyCollector
argument_list|(
argument|std::shared_ptr<DependencyCollector> Listener
argument_list|)
block|{
name|DependencyCollectors
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Listener
argument_list|)
argument_list|)
block|;   }
name|void
name|setExternalSemaSource
argument_list|(
name|IntrusiveRefCntPtr
operator|<
name|ExternalSemaSource
operator|>
name|ESS
argument_list|)
block|;
name|MemoryBufferCache
operator|&
name|getPCMCache
argument_list|()
specifier|const
block|{
return|return
operator|*
name|PCMCache
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

