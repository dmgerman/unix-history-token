begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- HeaderMap.h - A file that acts like dir of symlinks ----*- C++ -*-===//
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
comment|// This file defines the HeaderMap interface.
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
name|LLVM_CLANG_LEX_HEADERMAP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEX_HEADERMAP_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
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
name|FileManager
decl_stmt|;
struct_decl|struct
name|HMapBucket
struct_decl|;
struct_decl|struct
name|HMapHeader
struct_decl|;
comment|/// This class represents an Apple concept known as a 'header map'.  To the
comment|/// \#include file resolution process, it basically acts like a directory of
comment|/// symlinks to files.  Its advantages are that it is dense and more efficient
comment|/// to create and process than a directory of symlinks.
name|class
name|HeaderMap
block|{
name|HeaderMap
argument_list|(
argument|const HeaderMap&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|HeaderMap
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
specifier|const
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|FileBuffer
expr_stmt|;
name|bool
name|NeedsBSwap
decl_stmt|;
name|HeaderMap
argument_list|(
argument|const llvm::MemoryBuffer *File
argument_list|,
argument|bool BSwap
argument_list|)
block|:
name|FileBuffer
argument_list|(
name|File
argument_list|)
operator|,
name|NeedsBSwap
argument_list|(
argument|BSwap
argument_list|)
block|{   }
name|public
operator|:
operator|~
name|HeaderMap
argument_list|()
expr_stmt|;
comment|/// HeaderMap::Create - This attempts to load the specified file as a header
comment|/// map.  If it doesn't look like a HeaderMap, it gives up and returns null.
specifier|static
specifier|const
name|HeaderMap
modifier|*
name|Create
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|FE
parameter_list|,
name|FileManager
modifier|&
name|FM
parameter_list|)
function_decl|;
comment|/// LookupFile - Check to see if the specified relative filename is located in
comment|/// this HeaderMap.  If so, open it and return its FileEntry.
comment|/// If RawPath is not NULL and the file is found, RawPath will be set to the
comment|/// raw path at which the file was found in the file system. For example,
comment|/// for a search path ".." and a filename "../file.h" this would be
comment|/// "../../file.h".
specifier|const
name|FileEntry
modifier|*
name|LookupFile
argument_list|(
name|StringRef
name|Filename
argument_list|,
name|FileManager
operator|&
name|FM
argument_list|)
decl|const
decl_stmt|;
comment|/// If the specified relative filename is located in this HeaderMap return
comment|/// the filename it is mapped to, otherwise return an empty StringRef.
name|StringRef
name|lookupFilename
argument_list|(
name|StringRef
name|Filename
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|DestPath
argument_list|)
decl|const
decl_stmt|;
comment|/// getFileName - Return the filename of the headermap.
specifier|const
name|char
operator|*
name|getFileName
argument_list|()
specifier|const
expr_stmt|;
comment|/// dump - Print the contents of this headermap to stderr.
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|unsigned
name|getEndianAdjustedWord
argument_list|(
name|unsigned
name|X
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|HMapHeader
operator|&
name|getHeader
argument_list|()
specifier|const
expr_stmt|;
name|HMapBucket
name|getBucket
argument_list|(
name|unsigned
name|BucketNo
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|char
modifier|*
name|getString
argument_list|(
name|unsigned
name|StrTabIdx
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

