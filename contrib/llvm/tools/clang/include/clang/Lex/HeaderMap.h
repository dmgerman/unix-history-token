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
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

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
comment|/// Implementation for \a HeaderMap that doesn't depend on \a FileManager.
name|class
name|HeaderMapImpl
block|{
name|std
operator|::
name|unique_ptr
operator|<
specifier|const
name|llvm
operator|::
name|MemoryBuffer
operator|>
name|FileBuffer
expr_stmt|;
name|bool
name|NeedsBSwap
decl_stmt|;
name|public
label|:
name|HeaderMapImpl
argument_list|(
argument|std::unique_ptr<const llvm::MemoryBuffer> File
argument_list|,
argument|bool NeedsBSwap
argument_list|)
block|:
name|FileBuffer
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|File
argument_list|)
argument_list|)
operator|,
name|NeedsBSwap
argument_list|(
argument|NeedsBSwap
argument_list|)
block|{}
comment|// Check for a valid header and extract the byte swap.
specifier|static
name|bool
name|checkHeader
argument_list|(
specifier|const
name|llvm
operator|::
name|MemoryBuffer
operator|&
name|File
argument_list|,
name|bool
operator|&
name|NeedsByteSwap
argument_list|)
expr_stmt|;
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
comment|/// Return the filename of the headermap.
name|StringRef
name|getFileName
argument_list|()
specifier|const
expr_stmt|;
comment|/// Print the contents of this headermap to stderr.
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
comment|/// Look up the specified string in the string table.  If the string index is
comment|/// not valid, return None.
name|Optional
operator|<
name|StringRef
operator|>
name|getString
argument_list|(
argument|unsigned StrTabIdx
argument_list|)
specifier|const
expr_stmt|;
block|}
empty_stmt|;
comment|/// This class represents an Apple concept known as a 'header map'.  To the
comment|/// \#include file resolution process, it basically acts like a directory of
comment|/// symlinks to files.  Its advantages are that it is dense and more efficient
comment|/// to create and process than a directory of symlinks.
name|class
name|HeaderMap
range|:
name|private
name|HeaderMapImpl
block|{
name|HeaderMap
argument_list|(
argument|std::unique_ptr<const llvm::MemoryBuffer> File
argument_list|,
argument|bool BSwap
argument_list|)
operator|:
name|HeaderMapImpl
argument_list|(
argument|std::move(File)
argument_list|,
argument|BSwap
argument_list|)
block|{}
name|public
operator|:
comment|/// This attempts to load the specified file as a header map.  If it doesn't
comment|/// look like a HeaderMap, it gives up and returns null.
specifier|static
specifier|const
name|HeaderMap
operator|*
name|Create
argument_list|(
specifier|const
name|FileEntry
operator|*
name|FE
argument_list|,
name|FileManager
operator|&
name|FM
argument_list|)
block|;
comment|/// Check to see if the specified relative filename is located in this
comment|/// HeaderMap.  If so, open it and return its FileEntry.  If RawPath is not
comment|/// NULL and the file is found, RawPath will be set to the raw path at which
comment|/// the file was found in the file system. For example, for a search path
comment|/// ".." and a filename "../file.h" this would be "../../file.h".
specifier|const
name|FileEntry
operator|*
name|LookupFile
argument_list|(
argument|StringRef Filename
argument_list|,
argument|FileManager&FM
argument_list|)
specifier|const
block|;
name|using
name|HeaderMapImpl
operator|::
name|lookupFilename
block|;
name|using
name|HeaderMapImpl
operator|::
name|getFileName
block|;
name|using
name|HeaderMapImpl
operator|::
name|dump
block|; }
decl_stmt|;
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

