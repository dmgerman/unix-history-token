begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DataBufferHeap.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_DataBufferHeap_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_DataBufferHeap_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Utility/DataBuffer.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_comment
comment|// for offset_t
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_comment
comment|// for StringRef
end_comment

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_comment
comment|// for uint8_t, uint64_t
end_comment

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class DataBufferHeap DataBufferHeap.h "lldb/Core/DataBufferHeap.h"
comment|/// @brief A subclass of DataBuffer that stores a data buffer on the heap.
comment|///
comment|/// This class keeps its data in a heap based buffer that is owned by
comment|/// the object. This class is best used to store chunks of data that
comment|/// are created or read from sources that can't intelligently and lazily
comment|/// fault new data pages in. Large amounts of data that comes from files
comment|/// should probably use DataBufferLLVM, which can intelligently determine
comment|/// when memory mapping is optimal.
comment|//----------------------------------------------------------------------
name|class
name|DataBufferHeap
range|:
name|public
name|DataBuffer
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|/// Default constructor
comment|///
comment|/// Initializes the heap based buffer with no bytes.
comment|//------------------------------------------------------------------
name|DataBufferHeap
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Construct with size \a n and fill with \a ch.
comment|///
comment|/// Initialize this class with \a n bytes and fills the buffer with
comment|/// \a ch.
comment|///
comment|/// @param[in] n
comment|///     The number of bytes that heap based buffer should contain.
comment|///
comment|/// @param[in] ch
comment|///     The character to use when filling the buffer initially.
comment|//------------------------------------------------------------------
name|DataBufferHeap
argument_list|(
argument|lldb::offset_t n
argument_list|,
argument|uint8_t ch
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Construct by making a copy of \a src_len bytes from \a src.
comment|///
comment|/// @param[in] src
comment|///     A pointer to the data to copy.
comment|///
comment|/// @param[in] src_len
comment|///     The number of bytes in \a src to copy.
comment|//------------------------------------------------------------------
name|DataBufferHeap
argument_list|(
argument|const void *src
argument_list|,
argument|lldb::offset_t src_len
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|///
comment|/// Virtual destructor since this class inherits from a pure virtual
comment|/// base class #DataBuffer.
comment|//------------------------------------------------------------------
operator|~
name|DataBufferHeap
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|/// @copydoc DataBuffer::GetBytes()
comment|//------------------------------------------------------------------
name|uint8_t
operator|*
name|GetBytes
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|/// @copydoc DataBuffer::GetBytes() const
comment|//------------------------------------------------------------------
specifier|const
name|uint8_t
operator|*
name|GetBytes
argument_list|()
specifier|const
name|override
block|;
comment|//------------------------------------------------------------------
comment|/// @copydoc DataBuffer::GetByteSize() const
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|offset_t
name|GetByteSize
argument_list|()
specifier|const
name|override
block|;
comment|//------------------------------------------------------------------
comment|/// Set the number of bytes in the data buffer.
comment|///
comment|/// Sets the number of bytes that this object should be able to
comment|/// contain. This can be used prior to copying data into the buffer.
comment|///
comment|/// @param[in] byte_size
comment|///     The new size in bytes that this data buffer should attempt
comment|///     to resize itself to.
comment|///
comment|/// @return
comment|///     The size in bytes after that this heap buffer was
comment|///     successfully resized to.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|offset_t
name|SetByteSize
argument_list|(
argument|lldb::offset_t byte_size
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Makes a copy of the \a src_len bytes in \a src.
comment|///
comment|/// Copies the data in \a src into an internal buffer.
comment|///
comment|/// @param[in] src
comment|///     A pointer to the data to copy.
comment|///
comment|/// @param[in] src_len
comment|///     The number of bytes in \a src to copy.
comment|//------------------------------------------------------------------
name|void
name|CopyData
argument_list|(
argument|const void *src
argument_list|,
argument|lldb::offset_t src_len
argument_list|)
block|;
name|void
name|CopyData
argument_list|(
argument|llvm::StringRef src
argument_list|)
block|{
name|CopyData
argument_list|(
name|src
operator|.
name|data
argument_list|()
argument_list|,
name|src
operator|.
name|size
argument_list|()
argument_list|)
block|; }
name|void
name|AppendData
argument_list|(
argument|const void *src
argument_list|,
argument|uint64_t src_len
argument_list|)
block|;
name|void
name|Clear
argument_list|()
block|;
name|private
operator|:
comment|//------------------------------------------------------------------
comment|// This object uses a std::vector<uint8_t> to store its data. This
comment|// takes care of free the data when the object is deleted.
comment|//------------------------------------------------------------------
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>
name|buffer_t
expr_stmt|;
comment|///< Buffer type
name|buffer_t
name|m_data
decl_stmt|;
comment|///< The heap based buffer where data is stored
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_DataBufferHeap_h_
end_comment

end_unit

