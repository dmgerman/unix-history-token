begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=== FileOutputBuffer.h - File Output Buffer -------------------*- C++ -*-===//
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
comment|// Utility for creating a in-memory buffer that will be written to a file.
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
name|LLVM_SUPPORT_FILEOUTPUTBUFFER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_FILEOUTPUTBUFFER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FileSystem.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// FileOutputBuffer - This interface provides simple way to create an in-memory
comment|/// buffer which will be written to a file. During the lifetime of these
comment|/// objects, the content or existence of the specified file is undefined. That
comment|/// is, creating an OutputBuffer for a file may immediately remove the file.
comment|/// If the FileOutputBuffer is committed, the target file's content will become
comment|/// the buffer content at the time of the commit.  If the FileOutputBuffer is
comment|/// not committed, the file will be deleted in the FileOutputBuffer destructor.
name|class
name|FileOutputBuffer
block|{
name|public
label|:
enum|enum
block|{
name|F_executable
init|=
literal|1
comment|/// set the 'x' bit on the resulting file
block|}
enum|;
comment|/// Factory method to create an OutputBuffer object which manages a read/write
comment|/// buffer of the specified size. When committed, the buffer will be written
comment|/// to the file at the specified path.
specifier|static
name|std
operator|::
name|error_code
name|create
argument_list|(
argument|StringRef FilePath
argument_list|,
argument|size_t Size
argument_list|,
argument|std::unique_ptr<FileOutputBuffer>&Result
argument_list|,
argument|unsigned Flags =
literal|0
argument_list|)
expr_stmt|;
comment|/// Returns a pointer to the start of the buffer.
name|uint8_t
modifier|*
name|getBufferStart
parameter_list|()
block|{
return|return
operator|(
name|uint8_t
operator|*
operator|)
name|Region
operator|->
name|data
argument_list|()
return|;
block|}
comment|/// Returns a pointer to the end of the buffer.
name|uint8_t
modifier|*
name|getBufferEnd
parameter_list|()
block|{
return|return
operator|(
name|uint8_t
operator|*
operator|)
name|Region
operator|->
name|data
argument_list|()
operator|+
name|Region
operator|->
name|size
argument_list|()
return|;
block|}
comment|/// Returns size of the buffer.
name|size_t
name|getBufferSize
argument_list|()
specifier|const
block|{
return|return
name|Region
operator|->
name|size
argument_list|()
return|;
block|}
comment|/// Returns path where file will show up if buffer is committed.
name|StringRef
name|getPath
argument_list|()
specifier|const
block|{
return|return
name|FinalPath
return|;
block|}
comment|/// Flushes the content of the buffer to its file and deallocates the
comment|/// buffer.  If commit() is not called before this object's destructor
comment|/// is called, the file is deleted in the destructor. The optional parameter
comment|/// is used if it turns out you want the file size to be smaller than
comment|/// initially requested.
name|std
operator|::
name|error_code
name|commit
argument_list|(
argument|int64_t NewSmallerSize = -
literal|1
argument_list|)
expr_stmt|;
comment|/// If this object was previously committed, the destructor just deletes
comment|/// this object.  If this object was not committed, the destructor
comment|/// deallocates the buffer and the target file is never written.
operator|~
name|FileOutputBuffer
argument_list|()
expr_stmt|;
name|private
label|:
name|FileOutputBuffer
argument_list|(
argument|const FileOutputBuffer&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|FileOutputBuffer
modifier|&
name|operator
init|=
operator|(
specifier|const
name|FileOutputBuffer
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|FileOutputBuffer
argument_list|(
argument|llvm::sys::fs::mapped_file_region *R
argument_list|,
argument|StringRef Path
argument_list|,
argument|StringRef TempPath
argument_list|)
empty_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|sys
operator|::
name|fs
operator|::
name|mapped_file_region
operator|>
name|Region
expr_stmt|;
name|SmallString
operator|<
literal|128
operator|>
name|FinalPath
expr_stmt|;
name|SmallString
operator|<
literal|128
operator|>
name|TempPath
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

