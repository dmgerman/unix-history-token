begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ASTUnit.h - ASTUnit utility ----------------------------*- C++ -*-===//
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
comment|// ASTUnit utility class.
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
name|LLVM_CLANG_FRONTEND_ASTUNIT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_ASTUNIT_H
end_define

begin_include
include|#
directive|include
file|"clang-c/Index.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ASTContext.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/FileSystemOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LangOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/TargetOptions.h"
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
file|"clang/Lex/PreprocessingRecord.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/CodeCompleteConsumer.h"
end_include

begin_include
include|#
directive|include
file|"clang/Serialization/ASTBitCodes.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/PrecompiledPreamble.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MD5.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MemoryBuffer
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Sema
decl_stmt|;
name|class
name|ASTContext
decl_stmt|;
name|class
name|ASTReader
decl_stmt|;
name|class
name|CompilerInvocation
decl_stmt|;
name|class
name|CompilerInstance
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|DiagnosticsEngine
decl_stmt|;
name|class
name|FileEntry
decl_stmt|;
name|class
name|FileManager
decl_stmt|;
name|class
name|HeaderSearch
decl_stmt|;
name|class
name|InputKind
decl_stmt|;
name|class
name|MemoryBufferCache
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|class
name|PreprocessorOptions
decl_stmt|;
name|class
name|PCHContainerOperations
decl_stmt|;
name|class
name|PCHContainerReader
decl_stmt|;
name|class
name|TargetInfo
decl_stmt|;
name|class
name|FrontendAction
decl_stmt|;
name|class
name|ASTDeserializationListener
decl_stmt|;
name|namespace
name|vfs
block|{
name|class
name|FileSystem
decl_stmt|;
block|}
comment|/// \brief Utility class for loading a ASTContext from an AST file.
comment|///
name|class
name|ASTUnit
block|{
name|public
label|:
struct|struct
name|StandaloneFixIt
block|{
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
name|RemoveRange
expr_stmt|;
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
name|InsertFromRange
expr_stmt|;
name|std
operator|::
name|string
name|CodeToInsert
expr_stmt|;
name|bool
name|BeforePreviousInsertions
decl_stmt|;
block|}
struct|;
struct|struct
name|StandaloneDiagnostic
block|{
name|unsigned
name|ID
decl_stmt|;
name|DiagnosticsEngine
operator|::
name|Level
name|Level
expr_stmt|;
name|std
operator|::
name|string
name|Message
expr_stmt|;
name|std
operator|::
name|string
name|Filename
expr_stmt|;
name|unsigned
name|LocOffset
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
expr|>
name|Ranges
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|StandaloneFixIt
operator|>
name|FixIts
expr_stmt|;
block|}
struct|;
name|private
label|:
name|std
operator|::
name|shared_ptr
operator|<
name|LangOptions
operator|>
name|LangOpts
expr_stmt|;
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticsEngine
operator|>
name|Diagnostics
expr_stmt|;
name|IntrusiveRefCntPtr
operator|<
name|FileManager
operator|>
name|FileMgr
expr_stmt|;
name|IntrusiveRefCntPtr
operator|<
name|SourceManager
operator|>
name|SourceMgr
expr_stmt|;
name|IntrusiveRefCntPtr
operator|<
name|MemoryBufferCache
operator|>
name|PCMCache
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|HeaderSearch
operator|>
name|HeaderInfo
expr_stmt|;
name|IntrusiveRefCntPtr
operator|<
name|TargetInfo
operator|>
name|Target
expr_stmt|;
name|std
operator|::
name|shared_ptr
operator|<
name|Preprocessor
operator|>
name|PP
expr_stmt|;
name|IntrusiveRefCntPtr
operator|<
name|ASTContext
operator|>
name|Ctx
expr_stmt|;
name|std
operator|::
name|shared_ptr
operator|<
name|TargetOptions
operator|>
name|TargetOpts
expr_stmt|;
name|std
operator|::
name|shared_ptr
operator|<
name|HeaderSearchOptions
operator|>
name|HSOpts
expr_stmt|;
name|std
operator|::
name|shared_ptr
operator|<
name|PreprocessorOptions
operator|>
name|PPOpts
expr_stmt|;
name|IntrusiveRefCntPtr
operator|<
name|ASTReader
operator|>
name|Reader
expr_stmt|;
name|bool
name|HadModuleLoaderFatalFailure
decl_stmt|;
struct_decl|struct
name|ASTWriterData
struct_decl|;
name|std
operator|::
name|unique_ptr
operator|<
name|ASTWriterData
operator|>
name|WriterData
expr_stmt|;
name|FileSystemOptions
name|FileSystemOpts
decl_stmt|;
comment|/// \brief The AST consumer that received information about the translation
comment|/// unit as it was parsed or loaded.
name|std
operator|::
name|unique_ptr
operator|<
name|ASTConsumer
operator|>
name|Consumer
expr_stmt|;
comment|/// \brief The semantic analysis object used to type-check the translation
comment|/// unit.
name|std
operator|::
name|unique_ptr
operator|<
name|Sema
operator|>
name|TheSema
expr_stmt|;
comment|/// Optional owned invocation, just used to make the invocation used in
comment|/// LoadFromCommandLine available.
name|std
operator|::
name|shared_ptr
operator|<
name|CompilerInvocation
operator|>
name|Invocation
expr_stmt|;
comment|/// Fake module loader: the AST unit doesn't need to load any modules.
name|TrivialModuleLoader
name|ModuleLoader
decl_stmt|;
comment|// OnlyLocalDecls - when true, walking this AST should only visit declarations
comment|// that come from the AST itself, not from included precompiled headers.
comment|// FIXME: This is temporary; eventually, CIndex will always do this.
name|bool
name|OnlyLocalDecls
decl_stmt|;
comment|/// \brief Whether to capture any diagnostics produced.
name|bool
name|CaptureDiagnostics
decl_stmt|;
comment|/// \brief Track whether the main file was loaded from an AST or not.
name|bool
name|MainFileIsAST
decl_stmt|;
comment|/// \brief What kind of translation unit this AST represents.
name|TranslationUnitKind
name|TUKind
decl_stmt|;
comment|/// \brief Whether we should time each operation.
name|bool
name|WantTiming
decl_stmt|;
comment|/// \brief Whether the ASTUnit should delete the remapped buffers.
name|bool
name|OwnsRemappedFileBuffers
decl_stmt|;
comment|/// Track the top-level decls which appeared in an ASTUnit which was loaded
comment|/// from a source file.
comment|//
comment|// FIXME: This is just an optimization hack to avoid deserializing large parts
comment|// of a PCH file when using the Index library on an ASTUnit loaded from
comment|// source. In the long term we should make the Index library use efficient and
comment|// more scalable search mechanisms.
name|std
operator|::
name|vector
operator|<
name|Decl
operator|*
operator|>
name|TopLevelDecls
expr_stmt|;
comment|/// \brief Sorted (by file offset) vector of pairs of file offset/Decl.
typedef|typedef
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|Decl
operator|*
operator|>
operator|,
literal|64
operator|>
name|LocDeclsTy
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|FileID
operator|,
name|LocDeclsTy
operator|*
operator|>
name|FileDeclsTy
expr_stmt|;
comment|/// \brief Map from FileID to the file-level declarations that it contains.
comment|/// The files and decls are only local (and non-preamble) ones.
name|FileDeclsTy
name|FileDecls
decl_stmt|;
comment|/// The name of the original source file used to generate this ASTUnit.
name|std
operator|::
name|string
name|OriginalSourceFile
expr_stmt|;
comment|/// \brief The set of diagnostics produced when creating the preamble.
name|SmallVector
operator|<
name|StandaloneDiagnostic
operator|,
literal|4
operator|>
name|PreambleDiagnostics
expr_stmt|;
comment|/// \brief The set of diagnostics produced when creating this
comment|/// translation unit.
name|SmallVector
operator|<
name|StoredDiagnostic
operator|,
literal|4
operator|>
name|StoredDiagnostics
expr_stmt|;
comment|/// \brief The set of diagnostics produced when failing to parse, e.g. due
comment|/// to failure to load the PCH.
name|SmallVector
operator|<
name|StoredDiagnostic
operator|,
literal|4
operator|>
name|FailedParseDiagnostics
expr_stmt|;
comment|/// \brief The number of stored diagnostics that come from the driver
comment|/// itself.
comment|///
comment|/// Diagnostics that come from the driver are retained from one parse to
comment|/// the next.
name|unsigned
name|NumStoredDiagnosticsFromDriver
decl_stmt|;
comment|/// \brief Counter that determines when we want to try building a
comment|/// precompiled preamble.
comment|///
comment|/// If zero, we will never build a precompiled preamble. Otherwise,
comment|/// it's treated as a counter that decrements each time we reparse
comment|/// without the benefit of a precompiled preamble. When it hits 1,
comment|/// we'll attempt to rebuild the precompiled header. This way, if
comment|/// building the precompiled preamble fails, we won't try again for
comment|/// some number of calls.
name|unsigned
name|PreambleRebuildCounter
decl_stmt|;
comment|/// \brief Cache pairs "filename - source location"
comment|///
comment|/// Cache contains only source locations from preamble so it is
comment|/// guaranteed that they stay valid when the SourceManager is recreated.
comment|/// This cache is used when loading preambule to increase performance
comment|/// of that loading. It must be cleared when preamble is recreated.
name|llvm
operator|::
name|StringMap
operator|<
name|SourceLocation
operator|>
name|PreambleSrcLocCache
expr_stmt|;
name|private
label|:
comment|/// The contents of the preamble.
name|llvm
operator|::
name|Optional
operator|<
name|PrecompiledPreamble
operator|>
name|Preamble
expr_stmt|;
comment|/// \brief When non-NULL, this is the buffer used to store the contents of
comment|/// the main file when it has been padded for use with the precompiled
comment|/// preamble.
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|>
name|SavedMainFileBuffer
expr_stmt|;
comment|/// \brief The number of warnings that occurred while parsing the preamble.
comment|///
comment|/// This value will be used to restore the state of the \c DiagnosticsEngine
comment|/// object when re-using the precompiled preamble. Note that only the
comment|/// number of warnings matters, since we will not save the preamble
comment|/// when any errors are present.
name|unsigned
name|NumWarningsInPreamble
decl_stmt|;
comment|/// \brief A list of the serialization ID numbers for each of the top-level
comment|/// declarations parsed within the precompiled preamble.
name|std
operator|::
name|vector
operator|<
name|serialization
operator|::
name|DeclID
operator|>
name|TopLevelDeclsInPreamble
expr_stmt|;
comment|/// \brief Whether we should be caching code-completion results.
name|bool
name|ShouldCacheCodeCompletionResults
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether to include brief documentation within the set of code
comment|/// completions cached.
name|bool
name|IncludeBriefCommentsInCodeCompletion
range|:
literal|1
decl_stmt|;
comment|/// \brief True if non-system source files should be treated as volatile
comment|/// (likely to change while trying to use them).
name|bool
name|UserFilesAreVolatile
range|:
literal|1
decl_stmt|;
specifier|static
name|void
name|ConfigureDiags
argument_list|(
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticsEngine
operator|>
name|Diags
argument_list|,
name|ASTUnit
operator|&
name|AST
argument_list|,
name|bool
name|CaptureDiagnostics
argument_list|)
decl_stmt|;
name|void
name|TranslateStoredDiagnostics
argument_list|(
name|FileManager
operator|&
name|FileMgr
argument_list|,
name|SourceManager
operator|&
name|SrcMan
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|StandaloneDiagnostic
operator|>
operator|&
name|Diags
argument_list|,
name|SmallVectorImpl
operator|<
name|StoredDiagnostic
operator|>
operator|&
name|Out
argument_list|)
decl_stmt|;
name|void
name|clearFileLevelDecls
parameter_list|()
function_decl|;
name|public
label|:
comment|/// \brief A cached code-completion result, which may be introduced in one of
comment|/// many different contexts.
struct|struct
name|CachedCodeCompletionResult
block|{
comment|/// \brief The code-completion string corresponding to this completion
comment|/// result.
name|CodeCompletionString
modifier|*
name|Completion
decl_stmt|;
comment|/// \brief A bitmask that indicates which code-completion contexts should
comment|/// contain this completion result.
comment|///
comment|/// The bits in the bitmask correspond to the values of
comment|/// CodeCompleteContext::Kind. To map from a completion context kind to a
comment|/// bit, shift 1 by that number of bits. Many completions can occur in
comment|/// several different contexts.
name|uint64_t
name|ShowInContexts
decl_stmt|;
comment|/// \brief The priority given to this code-completion result.
name|unsigned
name|Priority
decl_stmt|;
comment|/// \brief The libclang cursor kind corresponding to this code-completion
comment|/// result.
name|CXCursorKind
name|Kind
decl_stmt|;
comment|/// \brief The availability of this code-completion result.
name|CXAvailabilityKind
name|Availability
decl_stmt|;
comment|/// \brief The simplified type class for a non-macro completion result.
name|SimplifiedTypeClass
name|TypeClass
decl_stmt|;
comment|/// \brief The type of a non-macro completion result, stored as a unique
comment|/// integer used by the string map of cached completion types.
comment|///
comment|/// This value will be zero if the type is not known, or a unique value
comment|/// determined by the formatted type string. Se \c CachedCompletionTypes
comment|/// for more information.
name|unsigned
name|Type
decl_stmt|;
block|}
struct|;
comment|/// \brief Retrieve the mapping from formatted type names to unique type
comment|/// identifiers.
name|llvm
operator|::
name|StringMap
operator|<
name|unsigned
operator|>
operator|&
name|getCachedCompletionTypes
argument_list|()
block|{
return|return
name|CachedCompletionTypes
return|;
block|}
comment|/// \brief Retrieve the allocator used to cache global code completions.
name|std
operator|::
name|shared_ptr
operator|<
name|GlobalCodeCompletionAllocator
operator|>
name|getCachedCompletionAllocator
argument_list|()
block|{
return|return
name|CachedCompletionAllocator
return|;
block|}
name|CodeCompletionTUInfo
modifier|&
name|getCodeCompletionTUInfo
parameter_list|()
block|{
if|if
condition|(
operator|!
name|CCTUInfo
condition|)
name|CCTUInfo
operator|=
name|llvm
operator|::
name|make_unique
operator|<
name|CodeCompletionTUInfo
operator|>
operator|(
name|std
operator|::
name|make_shared
operator|<
name|GlobalCodeCompletionAllocator
operator|>
operator|(
operator|)
operator|)
expr_stmt|;
return|return
operator|*
name|CCTUInfo
return|;
block|}
name|private
label|:
comment|/// \brief Allocator used to store cached code completions.
name|std
operator|::
name|shared_ptr
operator|<
name|GlobalCodeCompletionAllocator
operator|>
name|CachedCompletionAllocator
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|CodeCompletionTUInfo
operator|>
name|CCTUInfo
expr_stmt|;
comment|/// \brief The set of cached code-completion results.
name|std
operator|::
name|vector
operator|<
name|CachedCodeCompletionResult
operator|>
name|CachedCompletionResults
expr_stmt|;
comment|/// \brief A mapping from the formatted type name to a unique number for that
comment|/// type, which is used for type equality comparisons.
name|llvm
operator|::
name|StringMap
operator|<
name|unsigned
operator|>
name|CachedCompletionTypes
expr_stmt|;
comment|/// \brief A string hash of the top-level declaration and macro definition
comment|/// names processed the last time that we reparsed the file.
comment|///
comment|/// This hash value is used to determine when we need to refresh the
comment|/// global code-completion cache.
name|unsigned
name|CompletionCacheTopLevelHashValue
decl_stmt|;
comment|/// \brief A string hash of the top-level declaration and macro definition
comment|/// names processed the last time that we reparsed the precompiled preamble.
comment|///
comment|/// This hash value is used to determine when we need to refresh the
comment|/// global code-completion cache after a rebuild of the precompiled preamble.
name|unsigned
name|PreambleTopLevelHashValue
decl_stmt|;
comment|/// \brief The current hash value for the top-level declaration and macro
comment|/// definition names
name|unsigned
name|CurrentTopLevelHashValue
decl_stmt|;
comment|/// \brief Bit used by CIndex to mark when a translation unit may be in an
comment|/// inconsistent state, and is not safe to free.
name|unsigned
name|UnsafeToFree
range|:
literal|1
decl_stmt|;
comment|/// \brief Cache any "global" code-completion results, so that we can avoid
comment|/// recomputing them with each completion.
name|void
name|CacheCodeCompletionResults
parameter_list|()
function_decl|;
comment|/// \brief Clear out and deallocate
name|void
name|ClearCachedCompletionResults
parameter_list|()
function_decl|;
name|ASTUnit
argument_list|(
specifier|const
name|ASTUnit
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|ASTUnit
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|explicit
name|ASTUnit
parameter_list|(
name|bool
name|MainFileIsAST
parameter_list|)
function_decl|;
name|bool
name|Parse
argument_list|(
name|std
operator|::
name|shared_ptr
operator|<
name|PCHContainerOperations
operator|>
name|PCHContainerOps
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|>
name|OverrideMainBuffer
argument_list|,
name|IntrusiveRefCntPtr
operator|<
name|vfs
operator|::
name|FileSystem
operator|>
name|VFS
argument_list|)
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|>
name|getMainBufferWithPrecompiledPreamble
argument_list|(
argument|std::shared_ptr<PCHContainerOperations> PCHContainerOps
argument_list|,
argument|const CompilerInvocation&PreambleInvocationIn
argument_list|,
argument|IntrusiveRefCntPtr<vfs::FileSystem> VFS
argument_list|,
argument|bool AllowRebuild = true
argument_list|,
argument|unsigned MaxLines =
literal|0
argument_list|)
expr_stmt|;
name|void
name|RealizeTopLevelDeclsFromPreamble
parameter_list|()
function_decl|;
comment|/// \brief Transfers ownership of the objects (like SourceManager) from
comment|/// \param CI to this ASTUnit.
name|void
name|transferASTDataFromCompilerInstance
parameter_list|(
name|CompilerInstance
modifier|&
name|CI
parameter_list|)
function_decl|;
comment|/// \brief Allows us to assert that ASTUnit is not being used concurrently,
comment|/// which is not supported.
comment|///
comment|/// Clients should create instances of the ConcurrencyCheck class whenever
comment|/// using the ASTUnit in a way that isn't intended to be concurrent, which is
comment|/// just about any usage.
comment|/// Becomes a noop in release mode; only useful for debug mode checking.
name|class
name|ConcurrencyState
block|{
name|void
modifier|*
name|Mutex
decl_stmt|;
comment|// a llvm::sys::MutexImpl in debug;
name|public
label|:
name|ConcurrencyState
argument_list|()
expr_stmt|;
operator|~
name|ConcurrencyState
argument_list|()
expr_stmt|;
name|void
name|start
parameter_list|()
function_decl|;
name|void
name|finish
parameter_list|()
function_decl|;
block|}
empty_stmt|;
name|ConcurrencyState
name|ConcurrencyCheckValue
decl_stmt|;
name|public
label|:
name|class
name|ConcurrencyCheck
block|{
name|ASTUnit
modifier|&
name|Self
decl_stmt|;
name|public
label|:
name|explicit
name|ConcurrencyCheck
argument_list|(
name|ASTUnit
operator|&
name|Self
argument_list|)
operator|:
name|Self
argument_list|(
argument|Self
argument_list|)
block|{
name|Self
operator|.
name|ConcurrencyCheckValue
operator|.
name|start
argument_list|()
block|;     }
operator|~
name|ConcurrencyCheck
argument_list|()
block|{
name|Self
operator|.
name|ConcurrencyCheckValue
operator|.
name|finish
argument_list|()
block|;     }
block|}
empty_stmt|;
name|friend
name|class
name|ConcurrencyCheck
decl_stmt|;
operator|~
name|ASTUnit
argument_list|()
expr_stmt|;
name|bool
name|isMainFileAST
argument_list|()
specifier|const
block|{
return|return
name|MainFileIsAST
return|;
block|}
name|bool
name|isUnsafeToFree
argument_list|()
specifier|const
block|{
return|return
name|UnsafeToFree
return|;
block|}
name|void
name|setUnsafeToFree
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|UnsafeToFree
operator|=
name|Value
expr_stmt|;
block|}
specifier|const
name|DiagnosticsEngine
operator|&
name|getDiagnostics
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Diagnostics
return|;
block|}
name|DiagnosticsEngine
modifier|&
name|getDiagnostics
parameter_list|()
block|{
return|return
operator|*
name|Diagnostics
return|;
block|}
specifier|const
name|SourceManager
operator|&
name|getSourceManager
argument_list|()
specifier|const
block|{
return|return
operator|*
name|SourceMgr
return|;
block|}
name|SourceManager
modifier|&
name|getSourceManager
parameter_list|()
block|{
return|return
operator|*
name|SourceMgr
return|;
block|}
specifier|const
name|Preprocessor
operator|&
name|getPreprocessor
argument_list|()
specifier|const
block|{
return|return
operator|*
name|PP
return|;
block|}
name|Preprocessor
modifier|&
name|getPreprocessor
parameter_list|()
block|{
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
specifier|const
block|{
return|return
name|PP
return|;
block|}
specifier|const
name|ASTContext
operator|&
name|getASTContext
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Ctx
return|;
block|}
name|ASTContext
modifier|&
name|getASTContext
parameter_list|()
block|{
return|return
operator|*
name|Ctx
return|;
block|}
name|void
name|setASTContext
parameter_list|(
name|ASTContext
modifier|*
name|ctx
parameter_list|)
block|{
name|Ctx
operator|=
name|ctx
expr_stmt|;
block|}
name|void
name|setPreprocessor
argument_list|(
name|std
operator|::
name|shared_ptr
operator|<
name|Preprocessor
operator|>
name|pp
argument_list|)
decl_stmt|;
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
literal|"ASTUnit does not have a Sema object!"
argument_list|)
block|;
return|return
operator|*
name|TheSema
return|;
block|}
specifier|const
name|LangOptions
operator|&
name|getLangOpts
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|LangOpts
operator|&&
literal|"ASTUnit does not have language options"
argument_list|)
block|;
return|return
operator|*
name|LangOpts
return|;
block|}
specifier|const
name|HeaderSearchOptions
operator|&
name|getHeaderSearchOpts
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|HSOpts
operator|&&
literal|"ASTUnit does not have header search options"
argument_list|)
block|;
return|return
operator|*
name|HSOpts
return|;
block|}
specifier|const
name|PreprocessorOptions
operator|&
name|getPreprocessorOpts
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|PPOpts
operator|&&
literal|"ASTUnit does not have preprocessor options"
argument_list|)
block|;
return|return
operator|*
name|PPOpts
return|;
block|}
specifier|const
name|FileManager
operator|&
name|getFileManager
argument_list|()
specifier|const
block|{
return|return
operator|*
name|FileMgr
return|;
block|}
name|FileManager
modifier|&
name|getFileManager
parameter_list|()
block|{
return|return
operator|*
name|FileMgr
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
name|FileSystemOpts
return|;
block|}
name|IntrusiveRefCntPtr
operator|<
name|ASTReader
operator|>
name|getASTReader
argument_list|()
specifier|const
expr_stmt|;
name|StringRef
name|getOriginalSourceFileName
parameter_list|()
block|{
return|return
name|OriginalSourceFile
return|;
block|}
name|ASTMutationListener
modifier|*
name|getASTMutationListener
parameter_list|()
function_decl|;
name|ASTDeserializationListener
modifier|*
name|getDeserializationListener
parameter_list|()
function_decl|;
name|bool
name|getOnlyLocalDecls
argument_list|()
specifier|const
block|{
return|return
name|OnlyLocalDecls
return|;
block|}
name|bool
name|getOwnsRemappedFileBuffers
argument_list|()
specifier|const
block|{
return|return
name|OwnsRemappedFileBuffers
return|;
block|}
name|void
name|setOwnsRemappedFileBuffers
parameter_list|(
name|bool
name|val
parameter_list|)
block|{
name|OwnsRemappedFileBuffers
operator|=
name|val
expr_stmt|;
block|}
name|StringRef
name|getMainFileName
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief If this ASTUnit came from an AST file, returns the filename for it.
name|StringRef
name|getASTFileName
argument_list|()
specifier|const
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Decl
operator|*
operator|>
operator|::
name|iterator
name|top_level_iterator
expr_stmt|;
name|top_level_iterator
name|top_level_begin
parameter_list|()
block|{
name|assert
argument_list|(
operator|!
name|isMainFileAST
argument_list|()
operator|&&
literal|"Invalid call for AST based ASTUnit!"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|TopLevelDeclsInPreamble
operator|.
name|empty
argument_list|()
condition|)
name|RealizeTopLevelDeclsFromPreamble
argument_list|()
expr_stmt|;
return|return
name|TopLevelDecls
operator|.
name|begin
argument_list|()
return|;
block|}
name|top_level_iterator
name|top_level_end
parameter_list|()
block|{
name|assert
argument_list|(
operator|!
name|isMainFileAST
argument_list|()
operator|&&
literal|"Invalid call for AST based ASTUnit!"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|TopLevelDeclsInPreamble
operator|.
name|empty
argument_list|()
condition|)
name|RealizeTopLevelDeclsFromPreamble
argument_list|()
expr_stmt|;
return|return
name|TopLevelDecls
operator|.
name|end
argument_list|()
return|;
block|}
name|std
operator|::
name|size_t
name|top_level_size
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isMainFileAST
argument_list|()
operator|&&
literal|"Invalid call for AST based ASTUnit!"
argument_list|)
block|;
return|return
name|TopLevelDeclsInPreamble
operator|.
name|size
argument_list|()
operator|+
name|TopLevelDecls
operator|.
name|size
argument_list|()
return|;
block|}
name|bool
name|top_level_empty
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isMainFileAST
argument_list|()
operator|&&
literal|"Invalid call for AST based ASTUnit!"
argument_list|)
block|;
return|return
name|TopLevelDeclsInPreamble
operator|.
name|empty
argument_list|()
operator|&&
name|TopLevelDecls
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// \brief Add a new top-level declaration.
name|void
name|addTopLevelDecl
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
block|{
name|TopLevelDecls
operator|.
name|push_back
argument_list|(
name|D
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Add a new local file-level declaration.
name|void
name|addFileLevelDecl
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// \brief Get the decls that are contained in a file in the Offset/Length
comment|/// range. \p Length can be 0 to indicate a point at \p Offset instead of
comment|/// a range.
name|void
name|findFileRegionDecls
argument_list|(
name|FileID
name|File
argument_list|,
name|unsigned
name|Offset
argument_list|,
name|unsigned
name|Length
argument_list|,
name|SmallVectorImpl
operator|<
name|Decl
operator|*
operator|>
operator|&
name|Decls
argument_list|)
decl_stmt|;
comment|/// \brief Retrieve a reference to the current top-level name hash value.
comment|///
comment|/// Note: This is used internally by the top-level tracking action
name|unsigned
modifier|&
name|getCurrentTopLevelHashValue
parameter_list|()
block|{
return|return
name|CurrentTopLevelHashValue
return|;
block|}
comment|/// \brief Get the source location for the given file:line:col triplet.
comment|///
comment|/// The difference with SourceManager::getLocation is that this method checks
comment|/// whether the requested location points inside the precompiled preamble
comment|/// in which case the returned source location will be a "loaded" one.
name|SourceLocation
name|getLocation
argument_list|(
specifier|const
name|FileEntry
operator|*
name|File
argument_list|,
name|unsigned
name|Line
argument_list|,
name|unsigned
name|Col
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Get the source location for the given file:offset pair.
name|SourceLocation
name|getLocation
argument_list|(
specifier|const
name|FileEntry
operator|*
name|File
argument_list|,
name|unsigned
name|Offset
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief If \p Loc is a loaded location from the preamble, returns
comment|/// the corresponding local location of the main file, otherwise it returns
comment|/// \p Loc.
name|SourceLocation
name|mapLocationFromPreamble
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
comment|/// \brief If \p Loc is a local location of the main file but inside the
comment|/// preamble chunk, returns the corresponding loaded location from the
comment|/// preamble, otherwise it returns \p Loc.
name|SourceLocation
name|mapLocationToPreamble
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
name|bool
name|isInPreambleFileID
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
name|bool
name|isInMainFileID
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
name|SourceLocation
name|getStartOfMainFileID
parameter_list|()
function_decl|;
name|SourceLocation
name|getEndOfPreambleFileID
parameter_list|()
function_decl|;
comment|/// \see mapLocationFromPreamble.
name|SourceRange
name|mapRangeFromPreamble
parameter_list|(
name|SourceRange
name|R
parameter_list|)
block|{
return|return
name|SourceRange
argument_list|(
name|mapLocationFromPreamble
argument_list|(
name|R
operator|.
name|getBegin
argument_list|()
argument_list|)
argument_list|,
name|mapLocationFromPreamble
argument_list|(
name|R
operator|.
name|getEnd
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
comment|/// \see mapLocationToPreamble.
name|SourceRange
name|mapRangeToPreamble
parameter_list|(
name|SourceRange
name|R
parameter_list|)
block|{
return|return
name|SourceRange
argument_list|(
name|mapLocationToPreamble
argument_list|(
name|R
operator|.
name|getBegin
argument_list|()
argument_list|)
argument_list|,
name|mapLocationToPreamble
argument_list|(
name|R
operator|.
name|getEnd
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
comment|// Retrieve the diagnostics associated with this AST
typedef|typedef
name|StoredDiagnostic
modifier|*
name|stored_diag_iterator
typedef|;
typedef|typedef
specifier|const
name|StoredDiagnostic
modifier|*
name|stored_diag_const_iterator
typedef|;
name|stored_diag_const_iterator
name|stored_diag_begin
argument_list|()
specifier|const
block|{
return|return
name|StoredDiagnostics
operator|.
name|begin
argument_list|()
return|;
block|}
name|stored_diag_iterator
name|stored_diag_begin
parameter_list|()
block|{
return|return
name|StoredDiagnostics
operator|.
name|begin
argument_list|()
return|;
block|}
name|stored_diag_const_iterator
name|stored_diag_end
argument_list|()
specifier|const
block|{
return|return
name|StoredDiagnostics
operator|.
name|end
argument_list|()
return|;
block|}
name|stored_diag_iterator
name|stored_diag_end
parameter_list|()
block|{
return|return
name|StoredDiagnostics
operator|.
name|end
argument_list|()
return|;
block|}
name|unsigned
name|stored_diag_size
argument_list|()
specifier|const
block|{
return|return
name|StoredDiagnostics
operator|.
name|size
argument_list|()
return|;
block|}
name|stored_diag_iterator
name|stored_diag_afterDriver_begin
parameter_list|()
block|{
if|if
condition|(
name|NumStoredDiagnosticsFromDriver
operator|>
name|StoredDiagnostics
operator|.
name|size
argument_list|()
condition|)
name|NumStoredDiagnosticsFromDriver
operator|=
literal|0
expr_stmt|;
return|return
name|StoredDiagnostics
operator|.
name|begin
argument_list|()
operator|+
name|NumStoredDiagnosticsFromDriver
return|;
block|}
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|CachedCodeCompletionResult
operator|>
operator|::
name|iterator
name|cached_completion_iterator
expr_stmt|;
name|cached_completion_iterator
name|cached_completion_begin
parameter_list|()
block|{
return|return
name|CachedCompletionResults
operator|.
name|begin
argument_list|()
return|;
block|}
name|cached_completion_iterator
name|cached_completion_end
parameter_list|()
block|{
return|return
name|CachedCompletionResults
operator|.
name|end
argument_list|()
return|;
block|}
name|unsigned
name|cached_completion_size
argument_list|()
specifier|const
block|{
return|return
name|CachedCompletionResults
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// \brief Returns an iterator range for the local preprocessing entities
comment|/// of the local Preprocessor, if this is a parsed source file, or the loaded
comment|/// preprocessing entities of the primary module if this is an AST file.
name|llvm
operator|::
name|iterator_range
operator|<
name|PreprocessingRecord
operator|::
name|iterator
operator|>
name|getLocalPreprocessingEntities
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Type for a function iterating over a number of declarations.
comment|/// \returns true to continue iteration and false to abort.
typedef|typedef
name|bool
function_decl|(
modifier|*
name|DeclVisitorFn
function_decl|)
parameter_list|(
name|void
modifier|*
name|context
parameter_list|,
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// \brief Iterate over local declarations (locally parsed if this is a parsed
comment|/// source file or the loaded declarations of the primary module if this is an
comment|/// AST file).
comment|/// \returns true if the iteration was complete or false if it was aborted.
name|bool
name|visitLocalTopLevelDecls
parameter_list|(
name|void
modifier|*
name|context
parameter_list|,
name|DeclVisitorFn
name|Fn
parameter_list|)
function_decl|;
comment|/// \brief Get the PCH file if one was included.
specifier|const
name|FileEntry
modifier|*
name|getPCHFile
parameter_list|()
function_decl|;
comment|/// \brief Returns true if the ASTUnit was constructed from a serialized
comment|/// module file.
name|bool
name|isModuleFile
parameter_list|()
function_decl|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|>
name|getBufferForFile
argument_list|(
argument|StringRef Filename
argument_list|,
argument|std::string *ErrorStr = nullptr
argument_list|)
expr_stmt|;
comment|/// \brief Determine what kind of translation unit this AST represents.
name|TranslationUnitKind
name|getTranslationUnitKind
argument_list|()
specifier|const
block|{
return|return
name|TUKind
return|;
block|}
comment|/// \brief Determine the input kind this AST unit represents.
name|InputKind
name|getInputKind
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief A mapping from a file name to the memory buffer that stores the
comment|/// remapped contents of that file.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
operator|,
name|llvm
operator|::
name|MemoryBuffer
operator|*
operator|>
name|RemappedFile
expr_stmt|;
comment|/// \brief Create a ASTUnit. Gets ownership of the passed CompilerInvocation.
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|ASTUnit
operator|>
name|create
argument_list|(
argument|std::shared_ptr<CompilerInvocation> CI
argument_list|,
argument|IntrusiveRefCntPtr<DiagnosticsEngine> Diags
argument_list|,
argument|bool CaptureDiagnostics
argument_list|,
argument|bool UserFilesAreVolatile
argument_list|)
expr_stmt|;
enum|enum
name|WhatToLoad
block|{
comment|/// Load options and the preprocessor state.
name|LoadPreprocessorOnly
block|,
comment|/// Load the AST, but do not restore Sema state.
name|LoadASTOnly
block|,
comment|/// Load everything, including Sema.
name|LoadEverything
block|}
enum|;
comment|/// \brief Create a ASTUnit from an AST file.
comment|///
comment|/// \param Filename - The AST file to load.
comment|///
comment|/// \param PCHContainerRdr - The PCHContainerOperations to use for loading and
comment|/// creating modules.
comment|/// \param Diags - The diagnostics engine to use for reporting errors; its
comment|/// lifetime is expected to extend past that of the returned ASTUnit.
comment|///
comment|/// \returns - The initialized ASTUnit or null if the AST failed to load.
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|ASTUnit
operator|>
name|LoadFromASTFile
argument_list|(
argument|const std::string&Filename
argument_list|,
argument|const PCHContainerReader&PCHContainerRdr
argument_list|,
argument|WhatToLoad ToLoad
argument_list|,
argument|IntrusiveRefCntPtr<DiagnosticsEngine> Diags
argument_list|,
argument|const FileSystemOptions&FileSystemOpts
argument_list|,
argument|bool UseDebugInfo = false
argument_list|,
argument|bool OnlyLocalDecls = false
argument_list|,
argument|ArrayRef<RemappedFile> RemappedFiles = None
argument_list|,
argument|bool CaptureDiagnostics = false
argument_list|,
argument|bool AllowPCHWithCompilerErrors = false
argument_list|,
argument|bool UserFilesAreVolatile = false
argument_list|)
expr_stmt|;
name|private
label|:
comment|/// \brief Helper function for \c LoadFromCompilerInvocation() and
comment|/// \c LoadFromCommandLine(), which loads an AST from a compiler invocation.
comment|///
comment|/// \param PrecompilePreambleAfterNParses After how many parses the preamble
comment|/// of this translation unit should be precompiled, to improve the performance
comment|/// of reparsing. Set to zero to disable preambles.
comment|///
comment|/// \param VFS - A vfs::FileSystem to be used for all file accesses. Note that
comment|/// preamble is saved to a temporary directory on a RealFileSystem, so in order
comment|/// for it to be loaded correctly, VFS should have access to it(i.e., be an
comment|/// overlay over RealFileSystem).
comment|///
comment|/// \returns \c true if a catastrophic failure occurred (which means that the
comment|/// \c ASTUnit itself is invalid), or \c false otherwise.
name|bool
name|LoadFromCompilerInvocation
argument_list|(
name|std
operator|::
name|shared_ptr
operator|<
name|PCHContainerOperations
operator|>
name|PCHContainerOps
argument_list|,
name|unsigned
name|PrecompilePreambleAfterNParses
argument_list|,
name|IntrusiveRefCntPtr
operator|<
name|vfs
operator|::
name|FileSystem
operator|>
name|VFS
argument_list|)
decl_stmt|;
name|public
label|:
comment|/// \brief Create an ASTUnit from a source file, via a CompilerInvocation
comment|/// object, by invoking the optionally provided ASTFrontendAction.
comment|///
comment|/// \param CI - The compiler invocation to use; it must have exactly one input
comment|/// source file. The ASTUnit takes ownership of the CompilerInvocation object.
comment|///
comment|/// \param PCHContainerOps - The PCHContainerOperations to use for loading and
comment|/// creating modules.
comment|///
comment|/// \param Diags - The diagnostics engine to use for reporting errors; its
comment|/// lifetime is expected to extend past that of the returned ASTUnit.
comment|///
comment|/// \param Action - The ASTFrontendAction to invoke. Its ownership is not
comment|/// transferred.
comment|///
comment|/// \param Unit - optionally an already created ASTUnit. Its ownership is not
comment|/// transferred.
comment|///
comment|/// \param Persistent - if true the returned ASTUnit will be complete.
comment|/// false means the caller is only interested in getting info through the
comment|/// provided \see Action.
comment|///
comment|/// \param ErrAST - If non-null and parsing failed without any AST to return
comment|/// (e.g. because the PCH could not be loaded), this accepts the ASTUnit
comment|/// mainly to allow the caller to see the diagnostics.
comment|/// This will only receive an ASTUnit if a new one was created. If an already
comment|/// created ASTUnit was passed in \p Unit then the caller can check that.
comment|///
specifier|static
name|ASTUnit
modifier|*
name|LoadFromCompilerInvocationAction
argument_list|(
name|std
operator|::
name|shared_ptr
operator|<
name|CompilerInvocation
operator|>
name|CI
argument_list|,
name|std
operator|::
name|shared_ptr
operator|<
name|PCHContainerOperations
operator|>
name|PCHContainerOps
argument_list|,
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticsEngine
operator|>
name|Diags
argument_list|,
name|FrontendAction
operator|*
name|Action
operator|=
name|nullptr
argument_list|,
name|ASTUnit
operator|*
name|Unit
operator|=
name|nullptr
argument_list|,
name|bool
name|Persistent
operator|=
name|true
argument_list|,
name|StringRef
name|ResourceFilesPath
operator|=
name|StringRef
argument_list|()
argument_list|,
name|bool
name|OnlyLocalDecls
operator|=
name|false
argument_list|,
name|bool
name|CaptureDiagnostics
operator|=
name|false
argument_list|,
name|unsigned
name|PrecompilePreambleAfterNParses
operator|=
literal|0
argument_list|,
name|bool
name|CacheCodeCompletionResults
operator|=
name|false
argument_list|,
name|bool
name|IncludeBriefCommentsInCodeCompletion
operator|=
name|false
argument_list|,
name|bool
name|UserFilesAreVolatile
operator|=
name|false
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|ASTUnit
operator|>
operator|*
name|ErrAST
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|/// LoadFromCompilerInvocation - Create an ASTUnit from a source file, via a
comment|/// CompilerInvocation object.
comment|///
comment|/// \param CI - The compiler invocation to use; it must have exactly one input
comment|/// source file. The ASTUnit takes ownership of the CompilerInvocation object.
comment|///
comment|/// \param PCHContainerOps - The PCHContainerOperations to use for loading and
comment|/// creating modules.
comment|///
comment|/// \param Diags - The diagnostics engine to use for reporting errors; its
comment|/// lifetime is expected to extend past that of the returned ASTUnit.
comment|//
comment|// FIXME: Move OnlyLocalDecls, UseBumpAllocator to setters on the ASTUnit, we
comment|// shouldn't need to specify them at construction time.
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|ASTUnit
operator|>
name|LoadFromCompilerInvocation
argument_list|(
argument|std::shared_ptr<CompilerInvocation> CI
argument_list|,
argument|std::shared_ptr<PCHContainerOperations> PCHContainerOps
argument_list|,
argument|IntrusiveRefCntPtr<DiagnosticsEngine> Diags
argument_list|,
argument|FileManager *FileMgr
argument_list|,
argument|bool OnlyLocalDecls = false
argument_list|,
argument|bool CaptureDiagnostics = false
argument_list|,
argument|unsigned PrecompilePreambleAfterNParses =
literal|0
argument_list|,
argument|TranslationUnitKind TUKind = TU_Complete
argument_list|,
argument|bool CacheCodeCompletionResults = false
argument_list|,
argument|bool IncludeBriefCommentsInCodeCompletion = false
argument_list|,
argument|bool UserFilesAreVolatile = false
argument_list|)
expr_stmt|;
comment|/// LoadFromCommandLine - Create an ASTUnit from a vector of command line
comment|/// arguments, which must specify exactly one source file.
comment|///
comment|/// \param ArgBegin - The beginning of the argument vector.
comment|///
comment|/// \param ArgEnd - The end of the argument vector.
comment|///
comment|/// \param PCHContainerOps - The PCHContainerOperations to use for loading and
comment|/// creating modules.
comment|///
comment|/// \param Diags - The diagnostics engine to use for reporting errors; its
comment|/// lifetime is expected to extend past that of the returned ASTUnit.
comment|///
comment|/// \param ResourceFilesPath - The path to the compiler resource files.
comment|///
comment|/// \param ModuleFormat - If provided, uses the specific module format.
comment|///
comment|/// \param ErrAST - If non-null and parsing failed without any AST to return
comment|/// (e.g. because the PCH could not be loaded), this accepts the ASTUnit
comment|/// mainly to allow the caller to see the diagnostics.
comment|///
comment|/// \param VFS - A vfs::FileSystem to be used for all file accesses. Note that
comment|/// preamble is saved to a temporary directory on a RealFileSystem, so in order
comment|/// for it to be loaded correctly, VFS should have access to it(i.e., be an
comment|/// overlay over RealFileSystem). RealFileSystem will be used if \p VFS is nullptr.
comment|///
comment|// FIXME: Move OnlyLocalDecls, UseBumpAllocator to setters on the ASTUnit, we
comment|// shouldn't need to specify them at construction time.
specifier|static
name|ASTUnit
modifier|*
name|LoadFromCommandLine
argument_list|(
specifier|const
name|char
operator|*
operator|*
name|ArgBegin
argument_list|,
specifier|const
name|char
operator|*
operator|*
name|ArgEnd
argument_list|,
name|std
operator|::
name|shared_ptr
operator|<
name|PCHContainerOperations
operator|>
name|PCHContainerOps
argument_list|,
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticsEngine
operator|>
name|Diags
argument_list|,
name|StringRef
name|ResourceFilesPath
argument_list|,
name|bool
name|OnlyLocalDecls
operator|=
name|false
argument_list|,
name|bool
name|CaptureDiagnostics
operator|=
name|false
argument_list|,
name|ArrayRef
operator|<
name|RemappedFile
operator|>
name|RemappedFiles
operator|=
name|None
argument_list|,
name|bool
name|RemappedFilesKeepOriginalName
operator|=
name|true
argument_list|,
name|unsigned
name|PrecompilePreambleAfterNParses
operator|=
literal|0
argument_list|,
name|TranslationUnitKind
name|TUKind
operator|=
name|TU_Complete
argument_list|,
name|bool
name|CacheCodeCompletionResults
operator|=
name|false
argument_list|,
name|bool
name|IncludeBriefCommentsInCodeCompletion
operator|=
name|false
argument_list|,
name|bool
name|AllowPCHWithCompilerErrors
operator|=
name|false
argument_list|,
name|bool
name|SkipFunctionBodies
operator|=
name|false
argument_list|,
name|bool
name|SingleFileParse
operator|=
name|false
argument_list|,
name|bool
name|UserFilesAreVolatile
operator|=
name|false
argument_list|,
name|bool
name|ForSerialization
operator|=
name|false
argument_list|,
name|llvm
operator|::
name|Optional
operator|<
name|StringRef
operator|>
name|ModuleFormat
operator|=
name|llvm
operator|::
name|None
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|ASTUnit
operator|>
operator|*
name|ErrAST
operator|=
name|nullptr
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
decl_stmt|;
comment|/// \brief Reparse the source files using the same command-line options that
comment|/// were originally used to produce this translation unit.
comment|///
comment|/// \param VFS - A vfs::FileSystem to be used for all file accesses. Note that
comment|/// preamble is saved to a temporary directory on a RealFileSystem, so in order
comment|/// for it to be loaded correctly, VFS should give an access to this(i.e. be an
comment|/// overlay over RealFileSystem). FileMgr->getVirtualFileSystem() will be used if
comment|/// \p VFS is nullptr.
comment|///
comment|/// \returns True if a failure occurred that causes the ASTUnit not to
comment|/// contain any translation-unit information, false otherwise.
name|bool
name|Reparse
argument_list|(
name|std
operator|::
name|shared_ptr
operator|<
name|PCHContainerOperations
operator|>
name|PCHContainerOps
argument_list|,
name|ArrayRef
operator|<
name|RemappedFile
operator|>
name|RemappedFiles
operator|=
name|None
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
decl_stmt|;
comment|/// \brief Free data that will be re-generated on the next parse.
comment|///
comment|/// Preamble-related data is not affected.
name|void
name|ResetForParse
parameter_list|()
function_decl|;
comment|/// \brief Perform code completion at the given file, line, and
comment|/// column within this translation unit.
comment|///
comment|/// \param File The file in which code completion will occur.
comment|///
comment|/// \param Line The line at which code completion will occur.
comment|///
comment|/// \param Column The column at which code completion will occur.
comment|///
comment|/// \param IncludeMacros Whether to include macros in the code-completion
comment|/// results.
comment|///
comment|/// \param IncludeCodePatterns Whether to include code patterns (such as a
comment|/// for loop) in the code-completion results.
comment|///
comment|/// \param IncludeBriefComments Whether to include brief documentation within
comment|/// the set of code completions returned.
comment|///
comment|/// FIXME: The Diag, LangOpts, SourceMgr, FileMgr, StoredDiagnostics, and
comment|/// OwnedBuffers parameters are all disgusting hacks. They will go away.
name|void
name|CodeComplete
argument_list|(
name|StringRef
name|File
argument_list|,
name|unsigned
name|Line
argument_list|,
name|unsigned
name|Column
argument_list|,
name|ArrayRef
operator|<
name|RemappedFile
operator|>
name|RemappedFiles
argument_list|,
name|bool
name|IncludeMacros
argument_list|,
name|bool
name|IncludeCodePatterns
argument_list|,
name|bool
name|IncludeBriefComments
argument_list|,
name|CodeCompleteConsumer
operator|&
name|Consumer
argument_list|,
name|std
operator|::
name|shared_ptr
operator|<
name|PCHContainerOperations
operator|>
name|PCHContainerOps
argument_list|,
name|DiagnosticsEngine
operator|&
name|Diag
argument_list|,
name|LangOptions
operator|&
name|LangOpts
argument_list|,
name|SourceManager
operator|&
name|SourceMgr
argument_list|,
name|FileManager
operator|&
name|FileMgr
argument_list|,
name|SmallVectorImpl
operator|<
name|StoredDiagnostic
operator|>
operator|&
name|StoredDiagnostics
argument_list|,
name|SmallVectorImpl
operator|<
specifier|const
name|llvm
operator|::
name|MemoryBuffer
operator|*
operator|>
operator|&
name|OwnedBuffers
argument_list|)
decl_stmt|;
comment|/// \brief Save this translation unit to a file with the given name.
comment|///
comment|/// \returns true if there was a file error or false if the save was
comment|/// successful.
name|bool
name|Save
parameter_list|(
name|StringRef
name|File
parameter_list|)
function_decl|;
comment|/// \brief Serialize this translation unit with the given output stream.
comment|///
comment|/// \returns True if an error occurred, false otherwise.
name|bool
name|serialize
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

