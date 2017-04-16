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
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CBindingWrapping.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorOr.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/Types.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MemoryBufferRef
decl_stmt|;
comment|/// This interface provides simple read-only access to a block of memory, and
comment|/// provides simple methods for reading files and standard input into a memory
comment|/// buffer.  In addition to basic access to the characters in the file, this
comment|/// interface guarantees you can read one character past the end of the file,
comment|/// and that this character will read as '\0'.
comment|///
comment|/// The '\0' guarantee is needed to support an optimization -- it's intended to
comment|/// be more efficient for clients which are reading all the data to stop
comment|/// reading when they encounter a '\0' than to continually check the file
comment|/// position to see if it has reached the end of the file.
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
name|protected
label|:
name|MemoryBuffer
argument_list|()
operator|=
expr|default
expr_stmt|;
name|void
name|init
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
parameter_list|,
name|bool
name|RequiresNullTerminator
parameter_list|)
function_decl|;
name|public
label|:
name|MemoryBuffer
argument_list|(
specifier|const
name|MemoryBuffer
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|MemoryBuffer
modifier|&
name|operator
init|=
operator|(
specifier|const
name|MemoryBuffer
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
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
comment|/// Return an identifier for this buffer, typically the filename it was read
comment|/// from.
name|virtual
name|StringRef
name|getBufferIdentifier
argument_list|()
specifier|const
block|{
return|return
literal|"Unknown buffer"
return|;
block|}
comment|/// Open the specified file as a MemoryBuffer, returning a new MemoryBuffer
comment|/// if successful, otherwise returning null. If FileSize is specified, this
comment|/// means that the client knows that the file exists and that it has the
comment|/// specified size.
comment|///
comment|/// \param IsVolatile Set to true to indicate that the contents of the file
comment|/// can change outside the user's control, e.g. when libclang tries to parse
comment|/// while the user is editing/updating the file or if the file is on an NFS.
specifier|static
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>>
name|getFile
argument_list|(
argument|const Twine&Filename
argument_list|,
argument|int64_t FileSize = -
literal|1
argument_list|,
argument|bool RequiresNullTerminator = true
argument_list|,
argument|bool IsVolatile = false
argument_list|)
expr_stmt|;
comment|/// Read all of the specified file into a MemoryBuffer as a stream
comment|/// (i.e. until EOF reached). This is useful for special files that
comment|/// look like a regular file but have 0 size (e.g. /proc/cpuinfo on Linux).
specifier|static
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>>
name|getFileAsStream
argument_list|(
specifier|const
name|Twine
operator|&
name|Filename
argument_list|)
expr_stmt|;
comment|/// Given an already-open file descriptor, map some slice of it into a
comment|/// MemoryBuffer. The slice is specified by an \p Offset and \p MapSize.
comment|/// Since this is in the middle of a file, the buffer is not null terminated.
specifier|static
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>>
name|getOpenFileSlice
argument_list|(
argument|int FD
argument_list|,
argument|const Twine&Filename
argument_list|,
argument|uint64_t MapSize
argument_list|,
argument|int64_t Offset
argument_list|,
argument|bool IsVolatile = false
argument_list|)
expr_stmt|;
comment|/// Given an already-open file descriptor, read the file and return a
comment|/// MemoryBuffer.
comment|///
comment|/// \param IsVolatile Set to true to indicate that the contents of the file
comment|/// can change outside the user's control, e.g. when libclang tries to parse
comment|/// while the user is editing/updating the file or if the file is on an NFS.
specifier|static
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>>
name|getOpenFile
argument_list|(
argument|int FD
argument_list|,
argument|const Twine&Filename
argument_list|,
argument|uint64_t FileSize
argument_list|,
argument|bool RequiresNullTerminator = true
argument_list|,
argument|bool IsVolatile = false
argument_list|)
expr_stmt|;
comment|/// Open the specified memory range as a MemoryBuffer. Note that InputData
comment|/// must be null terminated if RequiresNullTerminator is true.
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|getMemBuffer
argument_list|(
argument|StringRef InputData
argument_list|,
argument|StringRef BufferName =
literal|""
argument_list|,
argument|bool RequiresNullTerminator = true
argument_list|)
expr_stmt|;
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|getMemBuffer
argument_list|(
argument|MemoryBufferRef Ref
argument_list|,
argument|bool RequiresNullTerminator = true
argument_list|)
expr_stmt|;
comment|/// Open the specified memory range as a MemoryBuffer, copying the contents
comment|/// and taking ownership of it. InputData does not have to be null terminated.
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|getMemBufferCopy
argument_list|(
argument|StringRef InputData
argument_list|,
argument|const Twine&BufferName =
literal|""
argument_list|)
expr_stmt|;
comment|/// Allocate a new zero-initialized MemoryBuffer of the specified size. Note
comment|/// that the caller need not initialize the memory allocated by this method.
comment|/// The memory is owned by the MemoryBuffer object.
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|getNewMemBuffer
argument_list|(
argument|size_t Size
argument_list|,
argument|StringRef BufferName =
literal|""
argument_list|)
expr_stmt|;
comment|/// Allocate a new MemoryBuffer of the specified size that is not initialized.
comment|/// Note that the caller should initialize the memory allocated by this
comment|/// method. The memory is owned by the MemoryBuffer object.
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|getNewUninitMemBuffer
argument_list|(
argument|size_t Size
argument_list|,
argument|const Twine&BufferName =
literal|""
argument_list|)
expr_stmt|;
comment|/// Read all of stdin into a file buffer, and return it.
specifier|static
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>>
name|getSTDIN
argument_list|()
expr_stmt|;
comment|/// Open the specified file as a MemoryBuffer, or open stdin if the Filename
comment|/// is "-".
specifier|static
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>>
name|getFileOrSTDIN
argument_list|(
argument|const Twine&Filename
argument_list|,
argument|int64_t FileSize = -
literal|1
argument_list|,
argument|bool RequiresNullTerminator = true
argument_list|)
expr_stmt|;
comment|/// Map a subrange of the specified file as a MemoryBuffer.
specifier|static
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>>
name|getFileSlice
argument_list|(
argument|const Twine&Filename
argument_list|,
argument|uint64_t MapSize
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|bool IsVolatile = false
argument_list|)
expr_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|// Provided for performance analysis.
comment|//===--------------------------------------------------------------------===//
comment|/// The kind of memory backing used to support the MemoryBuffer.
enum|enum
name|BufferKind
block|{
name|MemoryBuffer_Malloc
block|,
name|MemoryBuffer_MMap
block|}
enum|;
comment|/// Return information on the memory mechanism used to support the
comment|/// MemoryBuffer.
name|virtual
name|BufferKind
name|getBufferKind
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|MemoryBufferRef
name|getMemBufferRef
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
name|class
name|MemoryBufferRef
block|{
name|StringRef
name|Buffer
decl_stmt|;
name|StringRef
name|Identifier
decl_stmt|;
name|public
label|:
name|MemoryBufferRef
argument_list|()
operator|=
expr|default
expr_stmt|;
name|MemoryBufferRef
argument_list|(
name|MemoryBuffer
operator|&
name|Buffer
argument_list|)
operator|:
name|Buffer
argument_list|(
name|Buffer
operator|.
name|getBuffer
argument_list|()
argument_list|)
operator|,
name|Identifier
argument_list|(
argument|Buffer.getBufferIdentifier()
argument_list|)
block|{}
name|MemoryBufferRef
argument_list|(
argument|StringRef Buffer
argument_list|,
argument|StringRef Identifier
argument_list|)
operator|:
name|Buffer
argument_list|(
name|Buffer
argument_list|)
operator|,
name|Identifier
argument_list|(
argument|Identifier
argument_list|)
block|{}
name|StringRef
name|getBuffer
argument_list|()
specifier|const
block|{
return|return
name|Buffer
return|;
block|}
name|StringRef
name|getBufferIdentifier
argument_list|()
specifier|const
block|{
return|return
name|Identifier
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
name|Buffer
operator|.
name|begin
argument_list|()
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
name|Buffer
operator|.
name|end
argument_list|()
return|;
block|}
name|size_t
name|getBufferSize
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
block|}
empty_stmt|;
comment|// Create wrappers for C Binding types (see CBindingWrapping.h).
name|DEFINE_SIMPLE_CONVERSION_FUNCTIONS
argument_list|(
argument|MemoryBuffer
argument_list|,
argument|LLVMMemoryBufferRef
argument_list|)
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_MEMORYBUFFER_H
end_comment

end_unit

