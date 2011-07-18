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
name|LLVM_CLANG_FRONTEND_PREPROCESSOROPTIONS_H_
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_PREPROCESSOROPTIONS_H_
end_define

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

begin_include
include|#
directive|include
file|<set>
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
block|{
name|public
label|:
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
name|bool
comment|/*isUndef*/
operator|>
expr|>
name|Macros
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Includes
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|MacroIncludes
expr_stmt|;
name|unsigned
name|UsePredefines
range|:
literal|1
decl_stmt|;
comment|/// Initialize the preprocessor with the compiler
comment|/// and target specific predefines.
name|unsigned
name|DetailedRecord
range|:
literal|1
decl_stmt|;
comment|/// Whether we should maintain a detailed
comment|/// record of all macro definitions and
comment|/// expansions.
comment|/// \brief Whether the detailed preprocessing record includes nested macro
comment|/// expansions.
name|unsigned
name|DetailedRecordIncludesNestedMacroExpansions
range|:
literal|1
decl_stmt|;
comment|/// The implicit PCH included at the start of the translation unit, or empty.
name|std
operator|::
name|string
name|ImplicitPCHInclude
expr_stmt|;
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
expr_stmt|;
comment|/// \brief When true, disables most of the normal validation performed on
comment|/// precompiled headers.
name|bool
name|DisablePCHValidation
decl_stmt|;
comment|/// \brief When true, disables the use of the stat cache within a
comment|/// precompiled header or AST file.
name|bool
name|DisableStatCache
decl_stmt|;
comment|/// \brief Dump declarations that are deserialized from PCH, for testing.
name|bool
name|DumpDeserializedPCHDecls
decl_stmt|;
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
expr_stmt|;
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
operator|,
name|bool
operator|>
name|PrecompiledPreambleBytes
expr_stmt|;
comment|/// The implicit PTH input included at the start of the translation unit, or
comment|/// empty.
name|std
operator|::
name|string
name|ImplicitPTHInclude
expr_stmt|;
comment|/// If given, a PTH cache file to use for speeding up header parsing.
name|std
operator|::
name|string
name|TokenCache
expr_stmt|;
comment|/// \brief True if the SourceManager should report the original file name for
comment|/// contents of files that were remapped to other files. Defaults to true.
name|bool
name|RemappedFilesKeepOriginalName
decl_stmt|;
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
operator|,
name|std
operator|::
name|string
operator|>
expr|>
name|RemappedFiles
expr_stmt|;
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
operator|,
specifier|const
name|llvm
operator|::
name|MemoryBuffer
operator|*
operator|>
expr|>
name|RemappedFileBuffers
expr_stmt|;
comment|/// \brief Whether the compiler instance should retain (i.e., not free)
comment|/// the buffers associated with remapped files.
comment|///
comment|/// This flag defaults to false; it can be set true only through direct
comment|/// manipulation of the compiler invocation object, in cases where the
comment|/// compiler invocation and its buffers will be reused.
name|bool
name|RetainRemappedFileBuffers
decl_stmt|;
comment|/// \brief The Objective-C++ ARC standard library that we should support,
comment|/// by providing appropriate definitions to retrofit the standard library
comment|/// with support for lifetime-qualified pointers.
name|ObjCXXARCStandardLibraryKind
name|ObjCXXARCStandardLibrary
decl_stmt|;
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
parameter_list|()
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
parameter_list|()
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
name|DetailedRecordIncludesNestedMacroExpansions
argument_list|(
name|true
argument_list|)
operator|,
name|DisablePCHValidation
argument_list|(
name|false
argument_list|)
operator|,
name|DisableStatCache
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
argument|llvm::StringRef Name
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
argument|llvm::StringRef Name
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
argument|llvm::StringRef From
argument_list|,
argument|llvm::StringRef To
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
name|llvm
operator|::
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
block|}
empty_stmt|;
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

