begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- PTHManager.h - Manager object for PTH processing -------*- C++ -*-===//
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
comment|//  This file defines the PTHManager interface.
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
name|LLVM_CLANG_PTHMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_PTHMANAGER_H
end_define

begin_include
include|#
directive|include
file|"clang/Lex/PTHLexer.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LangOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/IdentifierTable.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|<string>
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
name|FileEntry
decl_stmt|;
name|class
name|PTHLexer
decl_stmt|;
name|class
name|Diagnostic
decl_stmt|;
name|class
name|StatSysCallCache
decl_stmt|;
name|class
name|PTHManager
range|:
name|public
name|IdentifierInfoLookup
block|{
name|friend
name|class
name|PTHLexer
block|;
comment|/// The memory mapped PTH file.
specifier|const
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|Buf
block|;
comment|/// Alloc - Allocator used for IdentifierInfo objects.
name|llvm
operator|::
name|BumpPtrAllocator
name|Alloc
block|;
comment|/// IdMap - A lazily generated cache mapping from persistent identifiers to
comment|///  IdentifierInfo*.
name|IdentifierInfo
operator|*
operator|*
name|PerIDCache
block|;
comment|/// FileLookup - Abstract data structure used for mapping between files
comment|///  and token data in the PTH file.
name|void
operator|*
name|FileLookup
block|;
comment|/// IdDataTable - Array representing the mapping from persistent IDs to the
comment|///  data offset within the PTH file containing the information to
comment|///  reconsitute an IdentifierInfo.
specifier|const
name|unsigned
name|char
operator|*
specifier|const
name|IdDataTable
block|;
comment|/// SortedIdTable - Abstract data structure mapping from strings to
comment|///  persistent IDs.  This is used by get().
name|void
operator|*
name|StringIdLookup
block|;
comment|/// NumIds - The number of identifiers in the PTH file.
specifier|const
name|unsigned
name|NumIds
block|;
comment|/// PP - The Preprocessor object that will use this PTHManager to create
comment|///  PTHLexer objects.
name|Preprocessor
operator|*
name|PP
block|;
comment|/// SpellingBase - The base offset within the PTH memory buffer that
comment|///  contains the cached spellings for literals.
specifier|const
name|unsigned
name|char
operator|*
specifier|const
name|SpellingBase
block|;
comment|/// OriginalSourceFile - A null-terminated C-string that specifies the name
comment|///  if the file (if any) that was to used to generate the PTH cache.
specifier|const
name|char
operator|*
name|OriginalSourceFile
block|;
comment|/// This constructor is intended to only be called by the static 'Create'
comment|/// method.
name|PTHManager
argument_list|(
argument|const llvm::MemoryBuffer* buf
argument_list|,
argument|void* fileLookup
argument_list|,
argument|const unsigned char* idDataTable
argument_list|,
argument|IdentifierInfo** perIDCache
argument_list|,
argument|void* stringIdLookup
argument_list|,
argument|unsigned numIds
argument_list|,
argument|const unsigned char* spellingBase
argument_list|,
argument|const char *originalSourceFile
argument_list|)
block|;
comment|// Do not implement.
name|PTHManager
argument_list|()
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|PTHManager
operator|&
operator|)
block|;
comment|/// getSpellingAtPTHOffset - Used by PTHLexer classes to get the cached
comment|///  spelling for a token.
name|unsigned
name|getSpellingAtPTHOffset
argument_list|(
argument|unsigned PTHOffset
argument_list|,
argument|const char*& Buffer
argument_list|)
block|;
comment|/// GetIdentifierInfo - Used to reconstruct IdentifierInfo objects from the
comment|///  PTH file.
specifier|inline
name|IdentifierInfo
operator|*
name|GetIdentifierInfo
argument_list|(
argument|unsigned PersistentID
argument_list|)
block|{
comment|// Check if the IdentifierInfo has already been resolved.
if|if
condition|(
name|IdentifierInfo
modifier|*
name|II
init|=
name|PerIDCache
index|[
name|PersistentID
index|]
condition|)
return|return
name|II
return|;
return|return
name|LazilyCreateIdentifierInfo
argument_list|(
name|PersistentID
argument_list|)
return|;
block|}
name|IdentifierInfo
modifier|*
name|LazilyCreateIdentifierInfo
parameter_list|(
name|unsigned
name|PersistentID
parameter_list|)
function_decl|;
name|public
label|:
comment|// The current PTH version.
enum|enum
block|{
name|Version
init|=
literal|9
block|}
enum|;
operator|~
name|PTHManager
argument_list|()
expr_stmt|;
comment|/// getOriginalSourceFile - Return the full path to the original header
comment|///  file name that was used to generate the PTH cache.
specifier|const
name|char
operator|*
name|getOriginalSourceFile
argument_list|()
specifier|const
block|{
return|return
name|OriginalSourceFile
return|;
block|}
comment|/// get - Return the identifier token info for the specified named identifier.
comment|///  Unlike the version in IdentifierTable, this returns a pointer instead
comment|///  of a reference.  If the pointer is NULL then the IdentifierInfo cannot
comment|///  be found.
name|IdentifierInfo
modifier|*
name|get
parameter_list|(
specifier|const
name|char
modifier|*
name|NameStart
parameter_list|,
specifier|const
name|char
modifier|*
name|NameEnd
parameter_list|)
function_decl|;
comment|/// Create - This method creates PTHManager objects.  The 'file' argument
comment|///  is the name of the PTH file.  This method returns NULL upon failure.
specifier|static
name|PTHManager
modifier|*
name|Create
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|file
argument_list|,
name|Diagnostic
operator|&
name|Diags
argument_list|)
decl_stmt|;
name|void
name|setPreprocessor
parameter_list|(
name|Preprocessor
modifier|*
name|pp
parameter_list|)
block|{
name|PP
operator|=
name|pp
expr_stmt|;
block|}
comment|/// CreateLexer - Return a PTHLexer that "lexes" the cached tokens for the
comment|///  specified file.  This method returns NULL if no cached tokens exist.
comment|///  It is the responsibility of the caller to 'delete' the returned object.
name|PTHLexer
modifier|*
name|CreateLexer
parameter_list|(
name|FileID
name|FID
parameter_list|)
function_decl|;
comment|/// createStatCache - Returns a StatSysCallCache object for use with
comment|///  FileManager objects.  These objects use the PTH data to speed up
comment|///  calls to stat by memoizing their results from when the PTH file
comment|///  was generated.
name|StatSysCallCache
modifier|*
name|createStatCache
parameter_list|()
function_decl|;
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

