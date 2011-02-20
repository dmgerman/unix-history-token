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
file|"clang/Index/ASTLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Serialization/ASTBitCodes.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/Sema.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/CodeCompleteConsumer.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/PreprocessingRecord.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/FileManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/FileSystemOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang-c/Index.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
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
file|"llvm/Support/Path.h"
end_include

begin_include
include|#
directive|include
file|<map>
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

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
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
name|ASTContext
decl_stmt|;
name|class
name|CodeCompleteConsumer
decl_stmt|;
name|class
name|CompilerInvocation
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|Diagnostic
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
name|Preprocessor
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
name|class
name|TargetInfo
decl_stmt|;
name|using
name|namespace
name|idx
decl_stmt|;
comment|/// \brief Allocator for a cached set of global code completions.
name|class
name|GlobalCodeCompletionAllocator
range|:
name|public
name|CodeCompletionAllocator
decl_stmt|,
name|public
name|llvm
decl|::
name|RefCountedBase
decl|<
name|GlobalCodeCompletionAllocator
decl|>
block|{  }
empty_stmt|;
comment|/// \brief Utility class for loading a ASTContext from an AST file.
comment|///
name|class
name|ASTUnit
block|{
name|public
label|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|FileID
operator|,
name|std
operator|::
name|vector
operator|<
name|PreprocessedEntity
operator|*
operator|>
expr|>
name|PreprocessedEntitiesByFileMap
expr_stmt|;
name|private
label|:
name|llvm
operator|::
name|IntrusiveRefCntPtr
operator|<
name|Diagnostic
operator|>
name|Diagnostics
expr_stmt|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|FileManager
operator|>
name|FileMgr
expr_stmt|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|SourceManager
operator|>
name|SourceMgr
expr_stmt|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|HeaderSearch
operator|>
name|HeaderInfo
expr_stmt|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|TargetInfo
operator|>
name|Target
expr_stmt|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|Preprocessor
operator|>
name|PP
expr_stmt|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|ASTContext
operator|>
name|Ctx
expr_stmt|;
name|FileSystemOptions
name|FileSystemOpts
decl_stmt|;
comment|/// \brief The AST consumer that received information about the translation
comment|/// unit as it was parsed or loaded.
name|llvm
operator|::
name|OwningPtr
operator|<
name|ASTConsumer
operator|>
name|Consumer
expr_stmt|;
comment|/// \brief The semantic analysis object used to type-check the translation
comment|/// unit.
name|llvm
operator|::
name|OwningPtr
operator|<
name|Sema
operator|>
name|TheSema
expr_stmt|;
comment|/// Optional owned invocation, just used to make the invocation used in
comment|/// LoadFromCommandLine available.
name|llvm
operator|::
name|OwningPtr
operator|<
name|CompilerInvocation
operator|>
name|Invocation
expr_stmt|;
comment|/// \brief The set of target features.
comment|///
comment|/// FIXME: each time we reparse, we need to restore the set of target
comment|/// features from this vector, because TargetInfo::CreateTargetInfo()
comment|/// mangles the target options in place. Yuck!
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|TargetFeatures
expr_stmt|;
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
comment|/// \brief Whether this AST represents a complete translation unit.
name|bool
name|CompleteTranslationUnit
decl_stmt|;
comment|/// \brief Whether we should time each operation.
name|bool
name|WantTiming
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
comment|/// \brief The list of preprocessed entities which appeared when the ASTUnit
comment|/// was loaded.
comment|///
comment|/// FIXME: This is just an optimization hack to avoid deserializing large
comment|/// parts of a PCH file while performing a walk or search. In the long term,
comment|/// we should provide more scalable search mechanisms.
name|std
operator|::
name|vector
operator|<
name|PreprocessedEntity
operator|*
operator|>
name|PreprocessedEntities
expr_stmt|;
comment|/// The name of the original source file used to generate this ASTUnit.
name|std
operator|::
name|string
name|OriginalSourceFile
expr_stmt|;
comment|// Critical optimization when using clang_getCursor().
name|ASTLocation
name|LastLoc
decl_stmt|;
comment|/// \brief The set of diagnostics produced when creating this
comment|/// translation unit.
name|llvm
operator|::
name|SmallVector
operator|<
name|StoredDiagnostic
operator|,
literal|4
operator|>
name|StoredDiagnostics
expr_stmt|;
comment|/// \brief The number of stored diagnostics that come from the driver
comment|/// itself.
comment|///
comment|/// Diagnostics that come from the driver are retained from one parse to
comment|/// the next.
name|unsigned
name|NumStoredDiagnosticsFromDriver
decl_stmt|;
comment|/// \brief Temporary files that should be removed when the ASTUnit is
comment|/// destroyed.
name|llvm
operator|::
name|SmallVector
operator|<
name|llvm
operator|::
name|sys
operator|::
name|Path
operator|,
literal|4
operator|>
name|TemporaryFiles
expr_stmt|;
comment|/// \brief A mapping from file IDs to the set of preprocessed entities
comment|/// stored in that file.
comment|///
comment|/// FIXME: This is just an optimization hack to avoid searching through
comment|/// many preprocessed entities during cursor traversal in the CIndex library.
comment|/// Ideally, we would just be able to perform a binary search within the
comment|/// list of preprocessed entities.
name|PreprocessedEntitiesByFileMap
name|PreprocessedEntitiesByFile
decl_stmt|;
comment|/// \brief Simple hack to allow us to assert that ASTUnit is not being
comment|/// used concurrently, which is not supported.
comment|///
comment|/// Clients should create instances of the ConcurrencyCheck class whenever
comment|/// using the ASTUnit in a way that isn't intended to be concurrent, which is
comment|/// just about any usage.
name|unsigned
name|int
name|ConcurrencyCheckValue
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|int
name|CheckLocked
init|=
literal|28573289
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|int
name|CheckUnlocked
init|=
literal|9803453
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
comment|/// \brief The file in which the precompiled preamble is stored.
name|std
operator|::
name|string
name|PreambleFile
expr_stmt|;
comment|/// \brief The contents of the preamble that has been precompiled to
comment|/// \c PreambleFile.
name|std
operator|::
name|vector
operator|<
name|char
operator|>
name|Preamble
expr_stmt|;
comment|/// \brief Whether the preamble ends at the start of a new line.
comment|///
comment|/// Used to inform the lexer as to whether it's starting at the beginning of
comment|/// a line after skipping the preamble.
name|bool
name|PreambleEndsAtStartOfLine
decl_stmt|;
comment|/// \brief The size of the source buffer that we've reserved for the main
comment|/// file within the precompiled preamble.
name|unsigned
name|PreambleReservedSize
decl_stmt|;
comment|/// \brief Keeps track of the files that were used when computing the
comment|/// preamble, with both their buffer size and their modification time.
comment|///
comment|/// If any of the files have changed from one compile to the next,
comment|/// the preamble must be thrown away.
name|llvm
operator|::
name|StringMap
operator|<
name|std
operator|::
name|pair
operator|<
name|off_t
operator|,
name|time_t
operator|>
expr|>
name|FilesInPreamble
expr_stmt|;
comment|/// \brief When non-NULL, this is the buffer used to store the contents of
comment|/// the main file when it has been padded for use with the precompiled
comment|/// preamble.
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|SavedMainFileBuffer
expr_stmt|;
comment|/// \brief When non-NULL, this is the buffer used to store the
comment|/// contents of the preamble when it has been padded to build the
comment|/// precompiled preamble.
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|PreambleBuffer
expr_stmt|;
comment|/// \brief The number of warnings that occurred while parsing the preamble.
comment|///
comment|/// This value will be used to restore the state of the \c Diagnostic object
comment|/// when re-using the precompiled preamble. Note that only the
comment|/// number of warnings matters, since we will not save the preamble
comment|/// when any errors are present.
name|unsigned
name|NumWarningsInPreamble
decl_stmt|;
comment|/// \brief The number of diagnostics that were stored when parsing
comment|/// the precompiled preamble.
comment|///
comment|/// This value is used to determine how many of the stored
comment|/// diagnostics should be retained when reparsing in the presence of
comment|/// a precompiled preamble.
name|unsigned
name|NumStoredDiagnosticsInPreamble
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
comment|/// \brief A list of the offsets into the precompiled preamble which
comment|/// correspond to preprocessed entities.
name|std
operator|::
name|vector
operator|<
name|uint64_t
operator|>
name|PreprocessedEntitiesInPreamble
expr_stmt|;
comment|/// \brief Whether we should be caching code-completion results.
name|bool
name|ShouldCacheCodeCompletionResults
decl_stmt|;
specifier|static
name|void
name|ConfigureDiags
argument_list|(
name|llvm
operator|::
name|IntrusiveRefCntPtr
operator|<
name|Diagnostic
operator|>
operator|&
name|Diags
argument_list|,
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
name|ASTUnit
operator|&
name|AST
argument_list|,
name|bool
name|CaptureDiagnostics
argument_list|)
decl_stmt|;
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
comment|/// bit, subtract one from the completion context kind and shift 1 by that
comment|/// number of bits. Many completions can occur in several different
comment|/// contexts.
name|unsigned
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
name|llvm
operator|::
name|IntrusiveRefCntPtr
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
name|private
label|:
comment|/// \brief Allocator used to store cached code completions.
name|llvm
operator|::
name|IntrusiveRefCntPtr
operator|<
name|GlobalCodeCompletionAllocator
operator|>
name|CachedCompletionAllocator
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
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|ASTUnit
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ASTUnit
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|explicit
name|ASTUnit
parameter_list|(
name|bool
name|MainFileIsAST
parameter_list|)
function_decl|;
name|void
name|CleanTemporaryFiles
parameter_list|()
function_decl|;
name|bool
name|Parse
argument_list|(
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|OverrideMainBuffer
argument_list|)
decl_stmt|;
name|std
operator|::
name|pair
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|*
operator|,
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|bool
operator|>
expr|>
name|ComputePreamble
argument_list|(
argument|CompilerInvocation&Invocation
argument_list|,
argument|unsigned MaxLines
argument_list|,
argument|bool&CreatedBuffer
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|getMainBufferWithPrecompiledPreamble
argument_list|(
argument|CompilerInvocation PreambleInvocation
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
name|void
name|RealizePreprocessedEntitiesFromPreamble
parameter_list|()
function_decl|;
name|public
label|:
name|class
name|ConcurrencyCheck
block|{
specifier|volatile
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
name|assert
argument_list|(
name|Self
operator|.
name|ConcurrencyCheckValue
operator|==
name|CheckUnlocked
operator|&&
literal|"Concurrent access to ASTUnit!"
argument_list|)
block|;
name|Self
operator|.
name|ConcurrencyCheckValue
operator|=
name|CheckLocked
block|;     }
operator|~
name|ConcurrencyCheck
argument_list|()
block|{
name|Self
operator|.
name|ConcurrencyCheckValue
operator|=
name|CheckUnlocked
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
name|Diagnostic
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
name|Diagnostic
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
operator|.
name|get
argument_list|()
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
operator|.
name|get
argument_list|()
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
operator|.
name|get
argument_list|()
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
operator|.
name|get
argument_list|()
return|;
block|}
name|bool
name|hasSema
argument_list|()
specifier|const
block|{
return|return
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
specifier|const
name|std
operator|::
name|string
operator|&
name|getOriginalSourceFileName
argument_list|()
expr_stmt|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getASTFileName
argument_list|()
expr_stmt|;
comment|/// \brief Add a temporary file that the ASTUnit depends on.
comment|///
comment|/// This file will be erased when the ASTUnit is destroyed.
name|void
name|addTemporaryFile
argument_list|(
specifier|const
name|llvm
operator|::
name|sys
operator|::
name|Path
operator|&
name|TempFile
argument_list|)
block|{
name|TemporaryFiles
operator|.
name|push_back
argument_list|(
name|TempFile
argument_list|)
expr_stmt|;
block|}
name|bool
name|getOnlyLocalDecls
argument_list|()
specifier|const
block|{
return|return
name|OnlyLocalDecls
return|;
block|}
comment|/// \brief Retrieve the maximum PCH level of declarations that a
comment|/// traversal of the translation unit should consider.
name|unsigned
name|getMaxPCHLevel
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setLastASTLocation
parameter_list|(
name|ASTLocation
name|ALoc
parameter_list|)
block|{
name|LastLoc
operator|=
name|ALoc
expr_stmt|;
block|}
name|ASTLocation
name|getLastASTLocation
argument_list|()
specifier|const
block|{
return|return
name|LastLoc
return|;
block|}
name|llvm
operator|::
name|StringRef
name|getMainFileName
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
comment|/// \brief Add a new top-level declaration, identified by its ID in
comment|/// the precompiled preamble.
name|void
name|addTopLevelDeclFromPreamble
argument_list|(
name|serialization
operator|::
name|DeclID
name|D
argument_list|)
block|{
name|TopLevelDeclsInPreamble
operator|.
name|push_back
argument_list|(
name|D
argument_list|)
expr_stmt|;
block|}
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
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|PreprocessedEntity
operator|*
operator|>
operator|::
name|iterator
name|pp_entity_iterator
expr_stmt|;
name|pp_entity_iterator
name|pp_entity_begin
parameter_list|()
function_decl|;
name|pp_entity_iterator
name|pp_entity_end
parameter_list|()
function_decl|;
comment|/// \brief Add a new preprocessed entity that's stored at the given offset
comment|/// in the precompiled preamble.
name|void
name|addPreprocessedEntityFromPreamble
parameter_list|(
name|uint64_t
name|Offset
parameter_list|)
block|{
name|PreprocessedEntitiesInPreamble
operator|.
name|push_back
argument_list|(
name|Offset
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Retrieve the mapping from File IDs to the preprocessed entities
comment|/// within that file.
name|PreprocessedEntitiesByFileMap
modifier|&
name|getPreprocessedEntitiesByFile
parameter_list|()
block|{
return|return
name|PreprocessedEntitiesByFile
return|;
block|}
comment|// Retrieve the diagnostics associated with this AST
typedef|typedef
specifier|const
name|StoredDiagnostic
modifier|*
name|stored_diag_iterator
typedef|;
name|stored_diag_iterator
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
name|llvm
operator|::
name|SmallVector
operator|<
name|StoredDiagnostic
operator|,
literal|4
operator|>
operator|&
name|getStoredDiagnostics
argument_list|()
block|{
return|return
name|StoredDiagnostics
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
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|getBufferForFile
argument_list|(
argument|llvm::StringRef Filename
argument_list|,
argument|std::string *ErrorStr =
literal|0
argument_list|)
expr_stmt|;
comment|/// \brief Whether this AST represents a complete translation unit.
comment|///
comment|/// If false, this AST is only a partial translation unit, e.g., one
comment|/// that might still be used as a precompiled header or preamble.
name|bool
name|isCompleteTranslationUnit
argument_list|()
specifier|const
block|{
return|return
name|CompleteTranslationUnit
return|;
block|}
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
specifier|const
name|llvm
operator|::
name|MemoryBuffer
operator|*
operator|>
name|RemappedFile
expr_stmt|;
comment|/// \brief Create a ASTUnit from an AST file.
comment|///
comment|/// \param Filename - The AST file to load.
comment|///
comment|/// \param Diags - The diagnostics engine to use for reporting errors; its
comment|/// lifetime is expected to extend past that of the returned ASTUnit.
comment|///
comment|/// \returns - The initialized ASTUnit or null if the AST failed to load.
specifier|static
name|ASTUnit
modifier|*
name|LoadFromASTFile
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Filename
argument_list|,
name|llvm
operator|::
name|IntrusiveRefCntPtr
operator|<
name|Diagnostic
operator|>
name|Diags
argument_list|,
specifier|const
name|FileSystemOptions
operator|&
name|FileSystemOpts
argument_list|,
name|bool
name|OnlyLocalDecls
operator|=
name|false
argument_list|,
name|RemappedFile
operator|*
name|RemappedFiles
operator|=
literal|0
argument_list|,
name|unsigned
name|NumRemappedFiles
operator|=
literal|0
argument_list|,
name|bool
name|CaptureDiagnostics
operator|=
name|false
argument_list|)
decl_stmt|;
name|private
label|:
comment|/// \brief Helper function for \c LoadFromCompilerInvocation() and
comment|/// \c LoadFromCommandLine(), which loads an AST from a compiler invocation.
comment|///
comment|/// \param PrecompilePreamble Whether to precompile the preamble of this
comment|/// translation unit, to improve the performance of reparsing.
comment|///
comment|/// \returns \c true if a catastrophic failure occurred (which means that the
comment|/// \c ASTUnit itself is invalid), or \c false otherwise.
name|bool
name|LoadFromCompilerInvocation
parameter_list|(
name|bool
name|PrecompilePreamble
parameter_list|)
function_decl|;
name|public
label|:
comment|/// LoadFromCompilerInvocation - Create an ASTUnit from a source file, via a
comment|/// CompilerInvocation object.
comment|///
comment|/// \param CI - The compiler invocation to use; it must have exactly one input
comment|/// source file. The ASTUnit takes ownership of the CompilerInvocation object.
comment|///
comment|/// \param Diags - The diagnostics engine to use for reporting errors; its
comment|/// lifetime is expected to extend past that of the returned ASTUnit.
comment|//
comment|// FIXME: Move OnlyLocalDecls, UseBumpAllocator to setters on the ASTUnit, we
comment|// shouldn't need to specify them at construction time.
specifier|static
name|ASTUnit
modifier|*
name|LoadFromCompilerInvocation
argument_list|(
name|CompilerInvocation
operator|*
name|CI
argument_list|,
name|llvm
operator|::
name|IntrusiveRefCntPtr
operator|<
name|Diagnostic
operator|>
name|Diags
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
name|bool
name|PrecompilePreamble
operator|=
name|false
argument_list|,
name|bool
name|CompleteTranslationUnit
operator|=
name|true
argument_list|,
name|bool
name|CacheCodeCompletionResults
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// LoadFromCommandLine - Create an ASTUnit from a vector of command line
comment|/// arguments, which must specify exactly one source file.
comment|///
comment|/// \param ArgBegin - The beginning of the argument vector.
comment|///
comment|/// \param ArgEnd - The end of the argument vector.
comment|///
comment|/// \param Diags - The diagnostics engine to use for reporting errors; its
comment|/// lifetime is expected to extend past that of the returned ASTUnit.
comment|///
comment|/// \param ResourceFilesPath - The path to the compiler resource files.
comment|//
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
name|llvm
operator|::
name|IntrusiveRefCntPtr
operator|<
name|Diagnostic
operator|>
name|Diags
argument_list|,
name|llvm
operator|::
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
name|RemappedFile
operator|*
name|RemappedFiles
operator|=
literal|0
argument_list|,
name|unsigned
name|NumRemappedFiles
operator|=
literal|0
argument_list|,
name|bool
name|PrecompilePreamble
operator|=
name|false
argument_list|,
name|bool
name|CompleteTranslationUnit
operator|=
name|true
argument_list|,
name|bool
name|CacheCodeCompletionResults
operator|=
name|false
argument_list|,
name|bool
name|CXXPrecompilePreamble
operator|=
name|false
argument_list|,
name|bool
name|CXXChainedPCH
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// \brief Reparse the source files using the same command-line options that
comment|/// were originally used to produce this translation unit.
comment|///
comment|/// \returns True if a failure occurred that causes the ASTUnit not to
comment|/// contain any translation-unit information, false otherwise.
name|bool
name|Reparse
parameter_list|(
name|RemappedFile
modifier|*
name|RemappedFiles
init|=
literal|0
parameter_list|,
name|unsigned
name|NumRemappedFiles
init|=
literal|0
parameter_list|)
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
comment|/// FIXME: The Diag, LangOpts, SourceMgr, FileMgr, StoredDiagnostics, and
comment|/// OwnedBuffers parameters are all disgusting hacks. They will go away.
name|void
name|CodeComplete
argument_list|(
name|llvm
operator|::
name|StringRef
name|File
argument_list|,
name|unsigned
name|Line
argument_list|,
name|unsigned
name|Column
argument_list|,
name|RemappedFile
operator|*
name|RemappedFiles
argument_list|,
name|unsigned
name|NumRemappedFiles
argument_list|,
name|bool
name|IncludeMacros
argument_list|,
name|bool
name|IncludeCodePatterns
argument_list|,
name|CodeCompleteConsumer
operator|&
name|Consumer
argument_list|,
name|Diagnostic
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
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|StoredDiagnostic
operator|>
operator|&
name|StoredDiagnostics
argument_list|,
name|llvm
operator|::
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
comment|/// \returns True if an error occurred, false otherwise.
name|bool
name|Save
argument_list|(
name|llvm
operator|::
name|StringRef
name|File
argument_list|)
decl_stmt|;
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

