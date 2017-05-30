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
name|MemoryBufferCache
decl_stmt|;
name|class
name|Preprocessor
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
range|:
name|public
name|ModuleLoader
block|{
name|public
operator|:
expr|struct
name|StandaloneFixIt
block|{
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|unsigned
operator|>
name|RemoveRange
block|;
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|unsigned
operator|>
name|InsertFromRange
block|;
name|std
operator|::
name|string
name|CodeToInsert
block|;
name|bool
name|BeforePreviousInsertions
block|;   }
block|;    struct
name|StandaloneDiagnostic
block|{
name|unsigned
name|ID
block|;
name|DiagnosticsEngine
operator|::
name|Level
name|Level
block|;
name|std
operator|::
name|string
name|Message
block|;
name|std
operator|::
name|string
name|Filename
block|;
name|unsigned
name|LocOffset
block|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|unsigned
operator|>
expr|>
name|Ranges
block|;
name|std
operator|::
name|vector
operator|<
name|StandaloneFixIt
operator|>
name|FixIts
block|;   }
block|;
name|private
operator|:
name|std
operator|::
name|shared_ptr
operator|<
name|LangOptions
operator|>
name|LangOpts
block|;
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticsEngine
operator|>
name|Diagnostics
block|;
name|IntrusiveRefCntPtr
operator|<
name|FileManager
operator|>
name|FileMgr
block|;
name|IntrusiveRefCntPtr
operator|<
name|SourceManager
operator|>
name|SourceMgr
block|;
name|IntrusiveRefCntPtr
operator|<
name|MemoryBufferCache
operator|>
name|PCMCache
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|HeaderSearch
operator|>
name|HeaderInfo
block|;
name|IntrusiveRefCntPtr
operator|<
name|TargetInfo
operator|>
name|Target
block|;
name|std
operator|::
name|shared_ptr
operator|<
name|Preprocessor
operator|>
name|PP
block|;
name|IntrusiveRefCntPtr
operator|<
name|ASTContext
operator|>
name|Ctx
block|;
name|std
operator|::
name|shared_ptr
operator|<
name|TargetOptions
operator|>
name|TargetOpts
block|;
name|std
operator|::
name|shared_ptr
operator|<
name|HeaderSearchOptions
operator|>
name|HSOpts
block|;
name|IntrusiveRefCntPtr
operator|<
name|ASTReader
operator|>
name|Reader
block|;
name|bool
name|HadModuleLoaderFatalFailure
block|;    struct
name|ASTWriterData
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|ASTWriterData
operator|>
name|WriterData
block|;
name|FileSystemOptions
name|FileSystemOpts
block|;
comment|/// \brief The AST consumer that received information about the translation
comment|/// unit as it was parsed or loaded.
name|std
operator|::
name|unique_ptr
operator|<
name|ASTConsumer
operator|>
name|Consumer
block|;
comment|/// \brief The semantic analysis object used to type-check the translation
comment|/// unit.
name|std
operator|::
name|unique_ptr
operator|<
name|Sema
operator|>
name|TheSema
block|;
comment|/// Optional owned invocation, just used to make the invocation used in
comment|/// LoadFromCommandLine available.
name|std
operator|::
name|shared_ptr
operator|<
name|CompilerInvocation
operator|>
name|Invocation
block|;
comment|// OnlyLocalDecls - when true, walking this AST should only visit declarations
comment|// that come from the AST itself, not from included precompiled headers.
comment|// FIXME: This is temporary; eventually, CIndex will always do this.
name|bool
name|OnlyLocalDecls
block|;
comment|/// \brief Whether to capture any diagnostics produced.
name|bool
name|CaptureDiagnostics
block|;
comment|/// \brief Track whether the main file was loaded from an AST or not.
name|bool
name|MainFileIsAST
block|;
comment|/// \brief What kind of translation unit this AST represents.
name|TranslationUnitKind
name|TUKind
block|;
comment|/// \brief Whether we should time each operation.
name|bool
name|WantTiming
block|;
comment|/// \brief Whether the ASTUnit should delete the remapped buffers.
name|bool
name|OwnsRemappedFileBuffers
block|;
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
block|;
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
name|public
label|:
name|class
name|PreambleData
block|{
specifier|const
name|FileEntry
modifier|*
name|File
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|char
operator|>
name|Buffer
expr_stmt|;
name|mutable
name|unsigned
name|NumLines
decl_stmt|;
name|public
label|:
name|PreambleData
argument_list|()
operator|:
name|File
argument_list|(
name|nullptr
argument_list|)
operator|,
name|NumLines
argument_list|(
literal|0
argument_list|)
block|{ }
name|void
name|assign
argument_list|(
argument|const FileEntry *F
argument_list|,
argument|const char *begin
argument_list|,
argument|const char *end
argument_list|)
block|{
name|File
operator|=
name|F
block|;
name|Buffer
operator|.
name|assign
argument_list|(
name|begin
argument_list|,
name|end
argument_list|)
block|;
name|NumLines
operator|=
literal|0
block|;     }
name|void
name|clear
argument_list|()
block|{
name|Buffer
operator|.
name|clear
argument_list|()
block|;
name|File
operator|=
name|nullptr
block|;
name|NumLines
operator|=
literal|0
block|; }
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|Buffer
operator|.
name|size
argument_list|()
return|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Buffer
operator|.
name|empty
argument_list|()
return|;
block|}
specifier|const
name|char
operator|*
name|getBufferStart
argument_list|()
specifier|const
block|{
return|return
operator|&
name|Buffer
index|[
literal|0
index|]
return|;
block|}
name|unsigned
name|getNumLines
argument_list|()
specifier|const
block|{
if|if
condition|(
name|NumLines
condition|)
return|return
name|NumLines
return|;
name|countLines
argument_list|()
expr_stmt|;
return|return
name|NumLines
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|(
specifier|const
name|SourceManager
operator|&
name|SM
argument_list|)
decl|const
block|{
name|SourceLocation
name|FileLoc
init|=
name|SM
operator|.
name|getLocForStartOfFile
argument_list|(
name|SM
operator|.
name|getPreambleFileID
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|SourceRange
argument_list|(
name|FileLoc
argument_list|,
name|FileLoc
operator|.
name|getLocWithOffset
argument_list|(
name|size
argument_list|()
operator|-
literal|1
argument_list|)
argument_list|)
return|;
block|}
name|private
label|:
name|void
name|countLines
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
specifier|const
name|PreambleData
operator|&
name|getPreambleData
argument_list|()
specifier|const
block|{
return|return
name|Preamble
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Data used to determine if a file used in the preamble has been changed.
end_comment

begin_struct
struct|struct
name|PreambleFileHash
block|{
comment|/// All files have size set.
name|off_t
name|Size
decl_stmt|;
comment|/// Modification time is set for files that are on disk.  For memory
comment|/// buffers it is zero.
name|time_t
name|ModTime
decl_stmt|;
comment|/// Memory buffers have MD5 instead of modification time.  We don't
comment|/// compute MD5 for on-disk files because we hope that modification time is
comment|/// enough to tell if the file was changed.
name|llvm
operator|::
name|MD5
operator|::
name|MD5Result
name|MD5
expr_stmt|;
specifier|static
name|PreambleFileHash
name|createForFile
parameter_list|(
name|off_t
name|Size
parameter_list|,
name|time_t
name|ModTime
parameter_list|)
function_decl|;
specifier|static
name|PreambleFileHash
name|createForMemoryBuffer
argument_list|(
specifier|const
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|Buffer
argument_list|)
decl_stmt|;
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|PreambleFileHash
operator|&
name|LHS
operator|,
specifier|const
name|PreambleFileHash
operator|&
name|RHS
operator|)
expr_stmt|;
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|PreambleFileHash
operator|&
name|LHS
operator|,
specifier|const
name|PreambleFileHash
operator|&
name|RHS
operator|)
block|{
return|return
operator|!
operator|(
name|LHS
operator|==
name|RHS
operator|)
return|;
block|}
block|}
struct|;
end_struct

begin_label
name|private
label|:
end_label

begin_comment
comment|/// \brief The contents of the preamble that has been precompiled to
end_comment

begin_comment
comment|/// \c PreambleFile.
end_comment

begin_decl_stmt
name|PreambleData
name|Preamble
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Whether the preamble ends at the start of a new line.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Used to inform the lexer as to whether it's starting at the beginning of
end_comment

begin_comment
comment|/// a line after skipping the preamble.
end_comment

begin_decl_stmt
name|bool
name|PreambleEndsAtStartOfLine
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Keeps track of the files that were used when computing the
end_comment

begin_comment
comment|/// preamble, with both their buffer size and their modification time.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If any of the files have changed from one compile to the next,
end_comment

begin_comment
comment|/// the preamble must be thrown away.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|StringMap
operator|<
name|PreambleFileHash
operator|>
name|FilesInPreamble
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief When non-NULL, this is the buffer used to store the contents of
end_comment

begin_comment
comment|/// the main file when it has been padded for use with the precompiled
end_comment

begin_comment
comment|/// preamble.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief When non-NULL, this is the buffer used to store the
end_comment

begin_comment
comment|/// contents of the preamble when it has been padded to build the
end_comment

begin_comment
comment|/// precompiled preamble.
end_comment

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|>
name|PreambleBuffer
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief The number of warnings that occurred while parsing the preamble.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This value will be used to restore the state of the \c DiagnosticsEngine
end_comment

begin_comment
comment|/// object when re-using the precompiled preamble. Note that only the
end_comment

begin_comment
comment|/// number of warnings matters, since we will not save the preamble
end_comment

begin_comment
comment|/// when any errors are present.
end_comment

begin_decl_stmt
name|unsigned
name|NumWarningsInPreamble
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief A list of the serialization ID numbers for each of the top-level
end_comment

begin_comment
comment|/// declarations parsed within the precompiled preamble.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Whether we should be caching code-completion results.
end_comment

begin_decl_stmt
name|bool
name|ShouldCacheCodeCompletionResults
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Whether to include brief documentation within the set of code
end_comment

begin_comment
comment|/// completions cached.
end_comment

begin_decl_stmt
name|bool
name|IncludeBriefCommentsInCodeCompletion
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief True if non-system source files should be treated as volatile
end_comment

begin_comment
comment|/// (likely to change while trying to use them).
end_comment

begin_decl_stmt
name|bool
name|UserFilesAreVolatile
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The language options used when we load an AST file.
end_comment

begin_decl_stmt
name|LangOptions
name|ASTFileLangOpts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_function_decl
name|void
name|clearFileLevelDecls
parameter_list|()
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_comment
comment|/// \brief A cached code-completion result, which may be introduced in one of
end_comment

begin_comment
comment|/// many different contexts.
end_comment

begin_struct
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
end_struct

begin_comment
comment|/// \brief Retrieve the mapping from formatted type names to unique type
end_comment

begin_comment
comment|/// identifiers.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the allocator used to cache global code completions.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_function
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
end_function

begin_label
name|private
label|:
end_label

begin_comment
comment|/// \brief Allocator used to store cached code completions.
end_comment

begin_expr_stmt
name|std
operator|::
name|shared_ptr
operator|<
name|GlobalCodeCompletionAllocator
operator|>
name|CachedCompletionAllocator
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|CodeCompletionTUInfo
operator|>
name|CCTUInfo
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief The set of cached code-completion results.
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|CachedCodeCompletionResult
operator|>
name|CachedCompletionResults
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief A mapping from the formatted type name to a unique number for that
end_comment

begin_comment
comment|/// type, which is used for type equality comparisons.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|StringMap
operator|<
name|unsigned
operator|>
name|CachedCompletionTypes
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief A string hash of the top-level declaration and macro definition
end_comment

begin_comment
comment|/// names processed the last time that we reparsed the file.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This hash value is used to determine when we need to refresh the
end_comment

begin_comment
comment|/// global code-completion cache.
end_comment

begin_decl_stmt
name|unsigned
name|CompletionCacheTopLevelHashValue
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief A string hash of the top-level declaration and macro definition
end_comment

begin_comment
comment|/// names processed the last time that we reparsed the precompiled preamble.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This hash value is used to determine when we need to refresh the
end_comment

begin_comment
comment|/// global code-completion cache after a rebuild of the precompiled preamble.
end_comment

begin_decl_stmt
name|unsigned
name|PreambleTopLevelHashValue
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The current hash value for the top-level declaration and macro
end_comment

begin_comment
comment|/// definition names
end_comment

begin_decl_stmt
name|unsigned
name|CurrentTopLevelHashValue
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Bit used by CIndex to mark when a translation unit may be in an
end_comment

begin_comment
comment|/// inconsistent state, and is not safe to free.
end_comment

begin_decl_stmt
name|unsigned
name|UnsafeToFree
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Cache any "global" code-completion results, so that we can avoid
end_comment

begin_comment
comment|/// recomputing them with each completion.
end_comment

begin_function_decl
name|void
name|CacheCodeCompletionResults
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Clear out and deallocate
end_comment

begin_function_decl
name|void
name|ClearCachedCompletionResults
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|ASTUnit
argument_list|(
specifier|const
name|ASTUnit
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
end_expr_stmt

begin_decl_stmt
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
end_decl_stmt

begin_function_decl
name|explicit
name|ASTUnit
parameter_list|(
name|bool
name|MainFileIsAST
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
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
end_decl_stmt

begin_struct
struct|struct
name|ComputedPreamble
block|{
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|Buffer
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|>
name|Owner
expr_stmt|;
name|unsigned
name|Size
decl_stmt|;
name|bool
name|PreambleEndsAtStartOfLine
decl_stmt|;
name|ComputedPreamble
argument_list|(
argument|llvm::MemoryBuffer *Buffer
argument_list|,
argument|std::unique_ptr<llvm::MemoryBuffer> Owner
argument_list|,
argument|unsigned Size
argument_list|,
argument|bool PreambleEndsAtStartOfLine
argument_list|)
block|:
name|Buffer
argument_list|(
name|Buffer
argument_list|)
operator|,
name|Owner
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Owner
argument_list|)
argument_list|)
operator|,
name|Size
argument_list|(
name|Size
argument_list|)
operator|,
name|PreambleEndsAtStartOfLine
argument_list|(
argument|PreambleEndsAtStartOfLine
argument_list|)
block|{}
block|}
struct|;
end_struct

begin_decl_stmt
name|ComputedPreamble
name|ComputePreamble
argument_list|(
name|CompilerInvocation
operator|&
name|Invocation
argument_list|,
name|unsigned
name|MaxLines
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
end_decl_stmt

begin_expr_stmt
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
end_expr_stmt

begin_function_decl
name|void
name|RealizeTopLevelDeclsFromPreamble
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Transfers ownership of the objects (like SourceManager) from
end_comment

begin_comment
comment|/// \param CI to this ASTUnit.
end_comment

begin_function_decl
name|void
name|transferASTDataFromCompilerInstance
parameter_list|(
name|CompilerInstance
modifier|&
name|CI
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Allows us to assert that ASTUnit is not being used concurrently,
end_comment

begin_comment
comment|/// which is not supported.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clients should create instances of the ConcurrencyCheck class whenever
end_comment

begin_comment
comment|/// using the ASTUnit in a way that isn't intended to be concurrent, which is
end_comment

begin_comment
comment|/// just about any usage.
end_comment

begin_comment
comment|/// Becomes a noop in release mode; only useful for debug mode checking.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|ConcurrencyState
name|ConcurrencyCheckValue
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_decl_stmt
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|friend
name|class
name|ConcurrencyCheck
decl_stmt|;
end_decl_stmt

begin_expr_stmt
operator|~
name|ASTUnit
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|isMainFileAST
argument_list|()
specifier|const
block|{
return|return
name|MainFileIsAST
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isUnsafeToFree
argument_list|()
specifier|const
block|{
return|return
name|UnsafeToFree
return|;
block|}
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
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
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
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
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
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
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_function
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
end_function

begin_function
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
end_function

begin_decl_stmt
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
end_decl_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
literal|" ASTUnit does not have language options"
argument_list|)
block|;
return|return
operator|*
name|LangOpts
return|;
block|}
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
name|IntrusiveRefCntPtr
operator|<
name|ASTReader
operator|>
name|getASTReader
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function
name|StringRef
name|getOriginalSourceFileName
parameter_list|()
block|{
return|return
name|OriginalSourceFile
return|;
block|}
end_function

begin_function_decl
name|ASTMutationListener
modifier|*
name|getASTMutationListener
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ASTDeserializationListener
modifier|*
name|getDeserializationListener
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|bool
name|getOnlyLocalDecls
argument_list|()
specifier|const
block|{
return|return
name|OnlyLocalDecls
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|getOwnsRemappedFileBuffers
argument_list|()
specifier|const
block|{
return|return
name|OwnsRemappedFileBuffers
return|;
block|}
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
name|StringRef
name|getMainFileName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief If this ASTUnit came from an AST file, returns the filename for it.
end_comment

begin_expr_stmt
name|StringRef
name|getASTFileName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_typedef
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
end_typedef

begin_function
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
end_function

begin_function
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
end_function

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Add a new top-level declaration.
end_comment

begin_function
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
end_function

begin_comment
comment|/// \brief Add a new local file-level declaration.
end_comment

begin_function_decl
name|void
name|addFileLevelDecl
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Get the decls that are contained in a file in the Offset/Length
end_comment

begin_comment
comment|/// range. \p Length can be 0 to indicate a point at \p Offset instead of
end_comment

begin_comment
comment|/// a range.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Add a new top-level declaration, identified by its ID in
end_comment

begin_comment
comment|/// the precompiled preamble.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Retrieve a reference to the current top-level name hash value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note: This is used internally by the top-level tracking action
end_comment

begin_function
name|unsigned
modifier|&
name|getCurrentTopLevelHashValue
parameter_list|()
block|{
return|return
name|CurrentTopLevelHashValue
return|;
block|}
end_function

begin_comment
comment|/// \brief Get the source location for the given file:line:col triplet.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The difference with SourceManager::getLocation is that this method checks
end_comment

begin_comment
comment|/// whether the requested location points inside the precompiled preamble
end_comment

begin_comment
comment|/// in which case the returned source location will be a "loaded" one.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Get the source location for the given file:offset pair.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief If \p Loc is a loaded location from the preamble, returns
end_comment

begin_comment
comment|/// the corresponding local location of the main file, otherwise it returns
end_comment

begin_comment
comment|/// \p Loc.
end_comment

begin_function_decl
name|SourceLocation
name|mapLocationFromPreamble
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief If \p Loc is a local location of the main file but inside the
end_comment

begin_comment
comment|/// preamble chunk, returns the corresponding loaded location from the
end_comment

begin_comment
comment|/// preamble, otherwise it returns \p Loc.
end_comment

begin_function_decl
name|SourceLocation
name|mapLocationToPreamble
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|isInPreambleFileID
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|isInMainFileID
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SourceLocation
name|getStartOfMainFileID
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|SourceLocation
name|getEndOfPreambleFileID
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \see mapLocationFromPreamble.
end_comment

begin_function
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
end_function

begin_comment
comment|/// \see mapLocationToPreamble.
end_comment

begin_function
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
end_function

begin_comment
comment|// Retrieve the diagnostics associated with this AST
end_comment

begin_typedef
typedef|typedef
name|StoredDiagnostic
modifier|*
name|stored_diag_iterator
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|StoredDiagnostic
modifier|*
name|stored_diag_const_iterator
typedef|;
end_typedef

begin_expr_stmt
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
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
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
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
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
end_expr_stmt

begin_function
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
end_function

begin_typedef
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
end_typedef

begin_function
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
end_function

begin_function
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
end_function

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Returns an iterator range for the local preprocessing entities
end_comment

begin_comment
comment|/// of the local Preprocessor, if this is a parsed source file, or the loaded
end_comment

begin_comment
comment|/// preprocessing entities of the primary module if this is an AST file.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Type for a function iterating over a number of declarations.
end_comment

begin_comment
comment|/// \returns true to continue iteration and false to abort.
end_comment

begin_typedef
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
end_typedef

begin_comment
comment|/// \brief Iterate over local declarations (locally parsed if this is a parsed
end_comment

begin_comment
comment|/// source file or the loaded declarations of the primary module if this is an
end_comment

begin_comment
comment|/// AST file).
end_comment

begin_comment
comment|/// \returns true if the iteration was complete or false if it was aborted.
end_comment

begin_function_decl
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
end_function_decl

begin_comment
comment|/// \brief Get the PCH file if one was included.
end_comment

begin_function_decl
specifier|const
name|FileEntry
modifier|*
name|getPCHFile
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Returns true if the ASTUnit was constructed from a serialized
end_comment

begin_comment
comment|/// module file.
end_comment

begin_function_decl
name|bool
name|isModuleFile
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Determine what kind of translation unit this AST represents.
end_comment

begin_expr_stmt
name|TranslationUnitKind
name|getTranslationUnitKind
argument_list|()
specifier|const
block|{
return|return
name|TUKind
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief A mapping from a file name to the memory buffer that stores the
end_comment

begin_comment
comment|/// remapped contents of that file.
end_comment

begin_typedef
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
end_typedef

begin_comment
comment|/// \brief Create a ASTUnit. Gets ownership of the passed CompilerInvocation.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Create a ASTUnit from an AST file.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Filename - The AST file to load.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param PCHContainerRdr - The PCHContainerOperations to use for loading and
end_comment

begin_comment
comment|/// creating modules.
end_comment

begin_comment
comment|/// \param Diags - The diagnostics engine to use for reporting errors; its
end_comment

begin_comment
comment|/// lifetime is expected to extend past that of the returned ASTUnit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns - The initialized ASTUnit or null if the AST failed to load.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|/// \brief Helper function for \c LoadFromCompilerInvocation() and
end_comment

begin_comment
comment|/// \c LoadFromCommandLine(), which loads an AST from a compiler invocation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param PrecompilePreambleAfterNParses After how many parses the preamble
end_comment

begin_comment
comment|/// of this translation unit should be precompiled, to improve the performance
end_comment

begin_comment
comment|/// of reparsing. Set to zero to disable preambles.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param VFS - A vfs::FileSystem to be used for all file accesses. Note that
end_comment

begin_comment
comment|/// preamble is saved to a temporary directory on a RealFileSystem, so in order
end_comment

begin_comment
comment|/// for it to be loaded correctly, VFS should have access to it(i.e., be an
end_comment

begin_comment
comment|/// overlay over RealFileSystem).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns \c true if a catastrophic failure occurred (which means that the
end_comment

begin_comment
comment|/// \c ASTUnit itself is invalid), or \c false otherwise.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// \brief Create an ASTUnit from a source file, via a CompilerInvocation
end_comment

begin_comment
comment|/// object, by invoking the optionally provided ASTFrontendAction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param CI - The compiler invocation to use; it must have exactly one input
end_comment

begin_comment
comment|/// source file. The ASTUnit takes ownership of the CompilerInvocation object.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param PCHContainerOps - The PCHContainerOperations to use for loading and
end_comment

begin_comment
comment|/// creating modules.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Diags - The diagnostics engine to use for reporting errors; its
end_comment

begin_comment
comment|/// lifetime is expected to extend past that of the returned ASTUnit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Action - The ASTFrontendAction to invoke. Its ownership is not
end_comment

begin_comment
comment|/// transferred.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Unit - optionally an already created ASTUnit. Its ownership is not
end_comment

begin_comment
comment|/// transferred.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Persistent - if true the returned ASTUnit will be complete.
end_comment

begin_comment
comment|/// false means the caller is only interested in getting info through the
end_comment

begin_comment
comment|/// provided \see Action.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ErrAST - If non-null and parsing failed without any AST to return
end_comment

begin_comment
comment|/// (e.g. because the PCH could not be loaded), this accepts the ASTUnit
end_comment

begin_comment
comment|/// mainly to allow the caller to see the diagnostics.
end_comment

begin_comment
comment|/// This will only receive an ASTUnit if a new one was created. If an already
end_comment

begin_comment
comment|/// created ASTUnit was passed in \p Unit then the caller can check that.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// LoadFromCompilerInvocation - Create an ASTUnit from a source file, via a
end_comment

begin_comment
comment|/// CompilerInvocation object.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param CI - The compiler invocation to use; it must have exactly one input
end_comment

begin_comment
comment|/// source file. The ASTUnit takes ownership of the CompilerInvocation object.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param PCHContainerOps - The PCHContainerOperations to use for loading and
end_comment

begin_comment
comment|/// creating modules.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Diags - The diagnostics engine to use for reporting errors; its
end_comment

begin_comment
comment|/// lifetime is expected to extend past that of the returned ASTUnit.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FIXME: Move OnlyLocalDecls, UseBumpAllocator to setters on the ASTUnit, we
end_comment

begin_comment
comment|// shouldn't need to specify them at construction time.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// LoadFromCommandLine - Create an ASTUnit from a vector of command line
end_comment

begin_comment
comment|/// arguments, which must specify exactly one source file.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ArgBegin - The beginning of the argument vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ArgEnd - The end of the argument vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param PCHContainerOps - The PCHContainerOperations to use for loading and
end_comment

begin_comment
comment|/// creating modules.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Diags - The diagnostics engine to use for reporting errors; its
end_comment

begin_comment
comment|/// lifetime is expected to extend past that of the returned ASTUnit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ResourceFilesPath - The path to the compiler resource files.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ModuleFormat - If provided, uses the specific module format.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ErrAST - If non-null and parsing failed without any AST to return
end_comment

begin_comment
comment|/// (e.g. because the PCH could not be loaded), this accepts the ASTUnit
end_comment

begin_comment
comment|/// mainly to allow the caller to see the diagnostics.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param VFS - A vfs::FileSystem to be used for all file accesses. Note that
end_comment

begin_comment
comment|/// preamble is saved to a temporary directory on a RealFileSystem, so in order
end_comment

begin_comment
comment|/// for it to be loaded correctly, VFS should have access to it(i.e., be an
end_comment

begin_comment
comment|/// overlay over RealFileSystem). RealFileSystem will be used if \p VFS is nullptr.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|// FIXME: Move OnlyLocalDecls, UseBumpAllocator to setters on the ASTUnit, we
end_comment

begin_comment
comment|// shouldn't need to specify them at construction time.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Reparse the source files using the same command-line options that
end_comment

begin_comment
comment|/// were originally used to produce this translation unit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param VFS - A vfs::FileSystem to be used for all file accesses. Note that
end_comment

begin_comment
comment|/// preamble is saved to a temporary directory on a RealFileSystem, so in order
end_comment

begin_comment
comment|/// for it to be loaded correctly, VFS should give an access to this(i.e. be an
end_comment

begin_comment
comment|/// overlay over RealFileSystem). FileMgr->getVirtualFileSystem() will be used if
end_comment

begin_comment
comment|/// \p VFS is nullptr.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns True if a failure occurred that causes the ASTUnit not to
end_comment

begin_comment
comment|/// contain any translation-unit information, false otherwise.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Free data that will be re-generated on the next parse.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Preamble-related data is not affected.
end_comment

begin_function_decl
name|void
name|ResetForParse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Perform code completion at the given file, line, and
end_comment

begin_comment
comment|/// column within this translation unit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param File The file in which code completion will occur.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Line The line at which code completion will occur.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Column The column at which code completion will occur.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param IncludeMacros Whether to include macros in the code-completion
end_comment

begin_comment
comment|/// results.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param IncludeCodePatterns Whether to include code patterns (such as a
end_comment

begin_comment
comment|/// for loop) in the code-completion results.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param IncludeBriefComments Whether to include brief documentation within
end_comment

begin_comment
comment|/// the set of code completions returned.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// FIXME: The Diag, LangOpts, SourceMgr, FileMgr, StoredDiagnostics, and
end_comment

begin_comment
comment|/// OwnedBuffers parameters are all disgusting hacks. They will go away.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/// \brief Save this translation unit to a file with the given name.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if there was a file error or false if the save was
end_comment

begin_comment
comment|/// successful.
end_comment

begin_function_decl
name|bool
name|Save
parameter_list|(
name|StringRef
name|File
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Serialize this translation unit with the given output stream.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns True if an error occurred, false otherwise.
end_comment

begin_function_decl
name|bool
name|serialize
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ModuleLoadResult
name|loadModule
argument_list|(
name|SourceLocation
name|ImportLoc
argument_list|,
name|ModuleIdPath
name|Path
argument_list|,
name|Module
operator|::
name|NameVisibilityKind
name|Visibility
argument_list|,
name|bool
name|IsInclusionDirective
argument_list|)
name|override
block|{
comment|// ASTUnit doesn't know how to load modules (not that this matters).
return|return
name|ModuleLoadResult
argument_list|()
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|makeModuleVisible
argument_list|(
name|Module
operator|*
name|Mod
argument_list|,
name|Module
operator|::
name|NameVisibilityKind
name|Visibility
argument_list|,
name|SourceLocation
name|ImportLoc
argument_list|)
name|override
block|{}
end_decl_stmt

begin_function
name|GlobalModuleIndex
modifier|*
name|loadGlobalModuleIndex
parameter_list|(
name|SourceLocation
name|TriggerLoc
parameter_list|)
function|override
block|{
return|return
name|nullptr
return|;
block|}
end_function

begin_function
name|bool
name|lookupMissingImports
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|SourceLocation
name|TriggerLoc
parameter_list|)
function|override
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
unit|};  }
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

