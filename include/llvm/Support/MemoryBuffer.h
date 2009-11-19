begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- MemoryBuffer.h - Memory Buffer Interface ---------------*- C++ -*-===//
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
comment|//  This file defines the MemoryBuffer interface.
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
name|LLVM_SUPPORT_MEMORYBUFFER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_MEMORYBUFFER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
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
comment|/// MemoryBuffer - This interface provides simple read-only access to a block
comment|/// of memory, and provides simple methods for reading files and standard input
comment|/// into a memory buffer.  In addition to basic access to the characters in the
comment|/// file, this interface guarantees you can read one character past the end of
comment|/// the file, and that this character will read as '\0'.
name|class
name|MemoryBuffer
block|{
specifier|const
name|char
modifier|*
name|BufferStart
decl_stmt|;
comment|// Start of the buffer.
specifier|const
name|char
modifier|*
name|BufferEnd
decl_stmt|;
comment|// End of the buffer.
comment|/// MustDeleteBuffer - True if we allocated this buffer.  If so, the
comment|/// destructor must know the delete[] it.
name|bool
name|MustDeleteBuffer
decl_stmt|;
name|protected
label|:
name|MemoryBuffer
argument_list|()
operator|:
name|MustDeleteBuffer
argument_list|(
argument|false
argument_list|)
block|{}
name|void
name|init
argument_list|(
specifier|const
name|char
operator|*
name|BufStart
argument_list|,
specifier|const
name|char
operator|*
name|BufEnd
argument_list|)
expr_stmt|;
name|void
name|initCopyOf
parameter_list|(
specifier|const
name|char
modifier|*
name|BufStart
parameter_list|,
specifier|const
name|char
modifier|*
name|BufEnd
parameter_list|)
function_decl|;
name|public
label|:
name|virtual
operator|~
name|MemoryBuffer
argument_list|()
expr_stmt|;
specifier|const
name|char
operator|*
name|getBufferStart
argument_list|()
specifier|const
block|{
return|return
name|BufferStart
return|;
block|}
specifier|const
name|char
operator|*
name|getBufferEnd
argument_list|()
specifier|const
block|{
return|return
name|BufferEnd
return|;
block|}
name|size_t
name|getBufferSize
argument_list|()
specifier|const
block|{
return|return
name|BufferEnd
operator|-
name|BufferStart
return|;
block|}
name|StringRef
name|getBuffer
argument_list|()
specifier|const
block|{
return|return
name|StringRef
argument_list|(
name|BufferStart
argument_list|,
name|getBufferSize
argument_list|()
argument_list|)
return|;
block|}
comment|/// getBufferIdentifier - Return an identifier for this buffer, typically the
comment|/// filename it was read from.
name|virtual
specifier|const
name|char
operator|*
name|getBufferIdentifier
argument_list|()
specifier|const
block|{
return|return
literal|"Unknown buffer"
return|;
block|}
comment|/// getFile - Open the specified file as a MemoryBuffer, returning a new
comment|/// MemoryBuffer if successful, otherwise returning null.  If FileSize is
comment|/// specified, this means that the client knows that the file exists and that
comment|/// it has the specified size.
specifier|static
name|MemoryBuffer
modifier|*
name|getFile
argument_list|(
name|StringRef
name|Filename
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrStr
operator|=
literal|0
argument_list|,
name|int64_t
name|FileSize
operator|=
operator|-
literal|1
argument_list|)
decl_stmt|;
comment|/// getMemBuffer - Open the specified memory range as a MemoryBuffer.  Note
comment|/// that EndPtr[0] must be a null byte and be accessible!
specifier|static
name|MemoryBuffer
modifier|*
name|getMemBuffer
parameter_list|(
specifier|const
name|char
modifier|*
name|StartPtr
parameter_list|,
specifier|const
name|char
modifier|*
name|EndPtr
parameter_list|,
specifier|const
name|char
modifier|*
name|BufferName
init|=
literal|""
parameter_list|)
function_decl|;
comment|/// getMemBufferCopy - Open the specified memory range as a MemoryBuffer,
comment|/// copying the contents and taking ownership of it.  This has no requirements
comment|/// on EndPtr[0].
specifier|static
name|MemoryBuffer
modifier|*
name|getMemBufferCopy
parameter_list|(
specifier|const
name|char
modifier|*
name|StartPtr
parameter_list|,
specifier|const
name|char
modifier|*
name|EndPtr
parameter_list|,
specifier|const
name|char
modifier|*
name|BufferName
init|=
literal|""
parameter_list|)
function_decl|;
comment|/// getNewMemBuffer - Allocate a new MemoryBuffer of the specified size that
comment|/// is completely initialized to zeros.  Note that the caller should
comment|/// initialize the memory allocated by this method.  The memory is owned by
comment|/// the MemoryBuffer object.
specifier|static
name|MemoryBuffer
modifier|*
name|getNewMemBuffer
parameter_list|(
name|size_t
name|Size
parameter_list|,
specifier|const
name|char
modifier|*
name|BufferName
init|=
literal|""
parameter_list|)
function_decl|;
comment|/// getNewUninitMemBuffer - Allocate a new MemoryBuffer of the specified size
comment|/// that is not initialized.  Note that the caller should initialize the
comment|/// memory allocated by this method.  The memory is owned by the MemoryBuffer
comment|/// object.
specifier|static
name|MemoryBuffer
modifier|*
name|getNewUninitMemBuffer
parameter_list|(
name|size_t
name|Size
parameter_list|,
name|StringRef
name|BufferName
init|=
literal|""
parameter_list|)
function_decl|;
comment|/// getSTDIN - Read all of stdin into a file buffer, and return it.
specifier|static
name|MemoryBuffer
modifier|*
name|getSTDIN
parameter_list|()
function_decl|;
comment|/// getFileOrSTDIN - Open the specified file as a MemoryBuffer, or open stdin
comment|/// if the Filename is "-".  If an error occurs, this returns null and fills
comment|/// in *ErrStr with a reason.
specifier|static
name|MemoryBuffer
modifier|*
name|getFileOrSTDIN
argument_list|(
name|StringRef
name|Filename
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrStr
operator|=
literal|0
argument_list|,
name|int64_t
name|FileSize
operator|=
operator|-
literal|1
argument_list|)
decl_stmt|;
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

