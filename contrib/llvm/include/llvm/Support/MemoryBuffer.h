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
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/Core.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|error_code
decl_stmt|;
name|template
operator|<
name|class
name|T
operator|>
name|class
name|OwningPtr
expr_stmt|;
comment|/// MemoryBuffer - This interface provides simple read-only access to a block
comment|/// of memory, and provides simple methods for reading files and standard input
comment|/// into a memory buffer.  In addition to basic access to the characters in the
comment|/// file, this interface guarantees you can read one character past the end of
comment|/// the file, and that this character will read as '\0'.
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
name|MemoryBuffer
argument_list|(
argument|const MemoryBuffer&
argument_list|)
name|LLVM_DELETED_FUNCTION
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
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|protected
label|:
name|MemoryBuffer
argument_list|()
block|{}
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
name|error_code
name|getFile
argument_list|(
name|Twine
name|Filename
argument_list|,
name|OwningPtr
operator|<
name|MemoryBuffer
operator|>
operator|&
name|result
argument_list|,
name|int64_t
name|FileSize
operator|=
operator|-
literal|1
argument_list|,
name|bool
name|RequiresNullTerminator
operator|=
name|true
argument_list|)
decl_stmt|;
comment|/// Given an already-open file descriptor, map some slice of it into a
comment|/// MemoryBuffer. The slice is specified by an \p Offset and \p MapSize.
comment|/// Since this is in the middle of a file, the buffer is not null terminated.
specifier|static
name|error_code
name|getOpenFileSlice
argument_list|(
name|int
name|FD
argument_list|,
specifier|const
name|char
operator|*
name|Filename
argument_list|,
name|OwningPtr
operator|<
name|MemoryBuffer
operator|>
operator|&
name|Result
argument_list|,
name|uint64_t
name|MapSize
argument_list|,
name|int64_t
name|Offset
argument_list|)
decl_stmt|;
comment|/// Given an already-open file descriptor, read the file and return a
comment|/// MemoryBuffer.
specifier|static
name|error_code
name|getOpenFile
argument_list|(
name|int
name|FD
argument_list|,
specifier|const
name|char
operator|*
name|Filename
argument_list|,
name|OwningPtr
operator|<
name|MemoryBuffer
operator|>
operator|&
name|Result
argument_list|,
name|uint64_t
name|FileSize
argument_list|,
name|bool
name|RequiresNullTerminator
operator|=
name|true
argument_list|)
decl_stmt|;
comment|/// getMemBuffer - Open the specified memory range as a MemoryBuffer.  Note
comment|/// that InputData must be null terminated if RequiresNullTerminator is true.
specifier|static
name|MemoryBuffer
modifier|*
name|getMemBuffer
parameter_list|(
name|StringRef
name|InputData
parameter_list|,
name|StringRef
name|BufferName
init|=
literal|""
parameter_list|,
name|bool
name|RequiresNullTerminator
init|=
name|true
parameter_list|)
function_decl|;
comment|/// getMemBufferCopy - Open the specified memory range as a MemoryBuffer,
comment|/// copying the contents and taking ownership of it.  InputData does not
comment|/// have to be null terminated.
specifier|static
name|MemoryBuffer
modifier|*
name|getMemBufferCopy
parameter_list|(
name|StringRef
name|InputData
parameter_list|,
name|StringRef
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
name|StringRef
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
comment|/// If an error occurs, this returns null and sets ec.
specifier|static
name|error_code
name|getSTDIN
argument_list|(
name|OwningPtr
operator|<
name|MemoryBuffer
operator|>
operator|&
name|result
argument_list|)
decl_stmt|;
comment|/// getFileOrSTDIN - Open the specified file as a MemoryBuffer, or open stdin
comment|/// if the Filename is "-".  If an error occurs, this returns null and sets
comment|/// ec.
specifier|static
name|error_code
name|getFileOrSTDIN
argument_list|(
name|StringRef
name|Filename
argument_list|,
name|OwningPtr
operator|<
name|MemoryBuffer
operator|>
operator|&
name|result
argument_list|,
name|int64_t
name|FileSize
operator|=
operator|-
literal|1
argument_list|)
decl_stmt|;
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

end_unit

