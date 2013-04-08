begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- PreprocessorOptions.h ----------------------------------*- C++ -*-===//
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
name|LLVM_CLANG_LEX_PREPROCESSOROPTIONS_H_
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEX_PREPROCESSOROPTIONS_H_
end_define

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
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
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<set>
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
name|Preprocessor
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
comment|/// \brief Enumerate the kinds of standard library that
enum|enum
name|ObjCXXARCStandardLibraryKind
block|{
name|ARCXX_nolib
block|,
comment|/// \brief libc++
name|ARCXX_libcxx
block|,
comment|/// \brief libstdc++
name|ARCXX_libstdcxx
block|}
enum|;
comment|/// PreprocessorOptions - This class is used for passing the various options
comment|/// used in preprocessor initialization to InitializePreprocessor().
name|class
name|PreprocessorOptions
range|:
name|public
name|RefCountedBase
operator|<
name|PreprocessorOptions
operator|>
block|{
name|public
operator|:
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
block|,
name|bool
comment|/*isUndef*/
operator|>
expr|>
name|Macros
block|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Includes
block|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|MacroIncludes
block|;
comment|/// \brief Initialize the preprocessor with the compiler and target specific
comment|/// predefines.
name|unsigned
name|UsePredefines
operator|:
literal|1
block|;
comment|/// \brief Whether we should maintain a detailed record of all macro
comment|/// definitions and expansions.
name|unsigned
name|DetailedRecord
operator|:
literal|1
block|;
comment|/// The implicit PCH included at the start of the translation unit, or empty.
name|std
operator|::
name|string
name|ImplicitPCHInclude
block|;
comment|/// \brief Headers that will be converted to chained PCHs in memory.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|ChainedIncludes
block|;
comment|/// \brief When true, disables most of the normal validation performed on
comment|/// precompiled headers.
name|bool
name|DisablePCHValidation
block|;
comment|/// \brief When true, a PCH with compiler errors will not be rejected.
name|bool
name|AllowPCHWithCompilerErrors
block|;
comment|/// \brief Dump declarations that are deserialized from PCH, for testing.
name|bool
name|DumpDeserializedPCHDecls
block|;
comment|/// \brief This is a set of names for decls that we do not want to be
comment|/// deserialized, and we emit an error if they are; for testing purposes.
name|std
operator|::
name|set
operator|<
name|std
operator|::
name|string
operator|>
name|DeserializedPCHDeclsToErrorOn
block|;
comment|/// \brief If non-zero, the implicit PCH include is actually a precompiled
comment|/// preamble that covers this number of bytes in the main source file.
comment|///
comment|/// The boolean indicates whether the preamble ends at the start of a new
comment|/// line.
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|bool
operator|>
name|PrecompiledPreambleBytes
block|;
comment|/// The implicit PTH input included at the start of the translation unit, or
comment|/// empty.
name|std
operator|::
name|string
name|ImplicitPTHInclude
block|;
comment|/// If given, a PTH cache file to use for speeding up header parsing.
name|std
operator|::
name|string
name|TokenCache
block|;
comment|/// \brief True if the SourceManager should report the original file name for
comment|/// contents of files that were remapped to other files. Defaults to true.
name|bool
name|RemappedFilesKeepOriginalName
block|;
comment|/// \brief The set of file remappings, which take existing files on
comment|/// the system (the first part of each pair) and gives them the
comment|/// contents of other files on the system (the second part of each
comment|/// pair).
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
block|,
name|std
operator|::
name|string
operator|>
expr|>
name|RemappedFiles
block|;
comment|/// \brief The set of file-to-buffer remappings, which take existing files
comment|/// on the system (the first part of each pair) and gives them the contents
comment|/// of the specified memory buffer (the second part of each pair).
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
block|,
specifier|const
name|llvm
operator|::
name|MemoryBuffer
operator|*
operator|>
expr|>
name|RemappedFileBuffers
block|;
comment|/// \brief Whether the compiler instance should retain (i.e., not free)
comment|/// the buffers associated with remapped files.
comment|///
comment|/// This flag defaults to false; it can be set true only through direct
comment|/// manipulation of the compiler invocation object, in cases where the
comment|/// compiler invocation and its buffers will be reused.
name|bool
name|RetainRemappedFileBuffers
block|;
comment|/// \brief The Objective-C++ ARC standard library that we should support,
comment|/// by providing appropriate definitions to retrofit the standard library
comment|/// with support for lifetime-qualified pointers.
name|ObjCXXARCStandardLibraryKind
name|ObjCXXARCStandardLibrary
block|;
comment|/// \brief Records the set of modules
name|class
name|FailedModulesSet
operator|:
name|public
name|RefCountedBase
operator|<
name|FailedModulesSet
operator|>
block|{
name|llvm
operator|::
name|StringSet
operator|<
operator|>
name|Failed
block|;
name|public
operator|:
name|bool
name|hasAlreadyFailed
argument_list|(
argument|StringRef module
argument_list|)
block|{
return|return
name|Failed
operator|.
name|count
argument_list|(
name|module
argument_list|)
operator|>
literal|0
return|;
block|}
name|void
name|addFailed
argument_list|(
argument|StringRef module
argument_list|)
block|{
name|Failed
operator|.
name|insert
argument_list|(
name|module
argument_list|)
block|;     }
expr|}
block|;
comment|/// \brief The set of modules that failed to build.
comment|///
comment|/// This pointer will be shared among all of the compiler instances created
comment|/// to (re)build modules, so that once a module fails to build anywhere,
comment|/// other instances will see that the module has failed and won't try to
comment|/// build it again.
name|IntrusiveRefCntPtr
operator|<
name|FailedModulesSet
operator|>
name|FailedModules
block|;
typedef|typedef
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
name|std
operator|::
name|string
operator|>
expr|>
operator|::
name|iterator
name|remapped_file_iterator
expr_stmt|;
typedef|typedef
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
name|std
operator|::
name|string
operator|>
expr|>
operator|::
name|const_iterator
name|const_remapped_file_iterator
expr_stmt|;
name|remapped_file_iterator
name|remapped_file_begin
argument_list|()
block|{
return|return
name|RemappedFiles
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_remapped_file_iterator
name|remapped_file_begin
argument_list|()
specifier|const
block|{
return|return
name|RemappedFiles
operator|.
name|begin
argument_list|()
return|;
block|}
name|remapped_file_iterator
name|remapped_file_end
argument_list|()
block|{
return|return
name|RemappedFiles
operator|.
name|end
argument_list|()
return|;
block|}
name|const_remapped_file_iterator
name|remapped_file_end
argument_list|()
specifier|const
block|{
return|return
name|RemappedFiles
operator|.
name|end
argument_list|()
return|;
block|}
typedef|typedef
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
specifier|const
name|llvm
operator|::
name|MemoryBuffer
operator|*
operator|>
expr|>
operator|::
name|iterator
name|remapped_file_buffer_iterator
expr_stmt|;
typedef|typedef
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
specifier|const
name|llvm
operator|::
name|MemoryBuffer
operator|*
operator|>
expr|>
operator|::
name|const_iterator
name|const_remapped_file_buffer_iterator
expr_stmt|;
name|remapped_file_buffer_iterator
name|remapped_file_buffer_begin
parameter_list|()
block|{
return|return
name|RemappedFileBuffers
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_remapped_file_buffer_iterator
name|remapped_file_buffer_begin
argument_list|()
specifier|const
block|{
return|return
name|RemappedFileBuffers
operator|.
name|begin
argument_list|()
return|;
block|}
name|remapped_file_buffer_iterator
name|remapped_file_buffer_end
parameter_list|()
block|{
return|return
name|RemappedFileBuffers
operator|.
name|end
argument_list|()
return|;
block|}
name|const_remapped_file_buffer_iterator
name|remapped_file_buffer_end
argument_list|()
specifier|const
block|{
return|return
name|RemappedFileBuffers
operator|.
name|end
argument_list|()
return|;
block|}
name|public
label|:
name|PreprocessorOptions
argument_list|()
operator|:
name|UsePredefines
argument_list|(
name|true
argument_list|)
operator|,
name|DetailedRecord
argument_list|(
name|false
argument_list|)
operator|,
name|DisablePCHValidation
argument_list|(
name|false
argument_list|)
operator|,
name|AllowPCHWithCompilerErrors
argument_list|(
name|false
argument_list|)
operator|,
name|DumpDeserializedPCHDecls
argument_list|(
name|false
argument_list|)
operator|,
name|PrecompiledPreambleBytes
argument_list|(
literal|0
argument_list|,
name|true
argument_list|)
operator|,
name|RemappedFilesKeepOriginalName
argument_list|(
name|true
argument_list|)
operator|,
name|RetainRemappedFileBuffers
argument_list|(
name|false
argument_list|)
operator|,
name|ObjCXXARCStandardLibrary
argument_list|(
argument|ARCXX_nolib
argument_list|)
block|{ }
name|void
name|addMacroDef
argument_list|(
argument|StringRef Name
argument_list|)
block|{
name|Macros
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|Name
argument_list|,
name|false
argument_list|)
argument_list|)
block|;   }
name|void
name|addMacroUndef
argument_list|(
argument|StringRef Name
argument_list|)
block|{
name|Macros
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|Name
argument_list|,
name|true
argument_list|)
argument_list|)
block|;   }
name|void
name|addRemappedFile
argument_list|(
argument|StringRef From
argument_list|,
argument|StringRef To
argument_list|)
block|{
name|RemappedFiles
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|From
argument_list|,
name|To
argument_list|)
argument_list|)
block|;   }
name|remapped_file_iterator
name|eraseRemappedFile
argument_list|(
argument|remapped_file_iterator Remapped
argument_list|)
block|{
return|return
name|RemappedFiles
operator|.
name|erase
argument_list|(
name|Remapped
argument_list|)
return|;
block|}
name|void
name|addRemappedFile
argument_list|(
name|StringRef
name|From
argument_list|,
specifier|const
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|To
argument_list|)
block|{
name|RemappedFileBuffers
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|From
argument_list|,
name|To
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|remapped_file_buffer_iterator
name|eraseRemappedFile
parameter_list|(
name|remapped_file_buffer_iterator
name|Remapped
parameter_list|)
block|{
return|return
name|RemappedFileBuffers
operator|.
name|erase
argument_list|(
name|Remapped
argument_list|)
return|;
block|}
name|void
name|clearRemappedFiles
parameter_list|()
block|{
name|RemappedFiles
operator|.
name|clear
argument_list|()
expr_stmt|;
name|RemappedFileBuffers
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
comment|/// \brief Reset any options that are not considered when building a
comment|/// module.
name|void
name|resetNonModularOptions
parameter_list|()
block|{
name|Includes
operator|.
name|clear
argument_list|()
expr_stmt|;
name|MacroIncludes
operator|.
name|clear
argument_list|()
expr_stmt|;
name|ChainedIncludes
operator|.
name|clear
argument_list|()
expr_stmt|;
name|DumpDeserializedPCHDecls
operator|=
name|false
expr_stmt|;
name|ImplicitPCHInclude
operator|.
name|clear
argument_list|()
expr_stmt|;
name|ImplicitPTHInclude
operator|.
name|clear
argument_list|()
expr_stmt|;
name|TokenCache
operator|.
name|clear
argument_list|()
expr_stmt|;
name|RetainRemappedFileBuffers
operator|=
name|true
expr_stmt|;
name|PrecompiledPreambleBytes
operator|.
name|first
operator|=
literal|0
expr_stmt|;
name|PrecompiledPreambleBytes
operator|.
name|second
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

