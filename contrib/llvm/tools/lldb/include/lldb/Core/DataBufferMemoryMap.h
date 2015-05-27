begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DataBufferMemoryMap.h -----------------------------------*- C++ -*-===//
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
name|liblldb_DataBufferMemoryMap_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_DataBufferMemoryMap_h_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/DataBuffer.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Error.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class DataBufferMemoryMap DataBufferMemoryMap.h "lldb/Core/DataBufferMemoryMap.h"
comment|/// @brief A subclass of DataBuffer that memory maps data.
comment|///
comment|/// This class memory maps data and stores any needed data for the
comment|/// memory mapping in its internal state. Memory map requests are not
comment|/// required to have any alignment or size constraints, this class will
comment|/// work around any host OS issues regarding such things.
comment|///
comment|/// This class is designed to allow pages to be faulted in as needed and
comment|/// works well data from large files that won't be accessed all at once.
comment|//----------------------------------------------------------------------
name|class
name|DataBufferMemoryMap
range|:
name|public
name|DataBuffer
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|/// Default Constructor
comment|//------------------------------------------------------------------
name|DataBufferMemoryMap
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|///
comment|/// Virtual destructor since this class inherits from a pure virtual
comment|/// base class #DataBuffer.
comment|//------------------------------------------------------------------
name|virtual
operator|~
name|DataBufferMemoryMap
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Reverts this object to an empty state by unmapping any memory
comment|/// that is currently owned.
comment|//------------------------------------------------------------------
name|void
name|Clear
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// @copydoc DataBuffer::GetBytes()
comment|//------------------------------------------------------------------
name|virtual
name|uint8_t
operator|*
name|GetBytes
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// @copydoc DataBuffer::GetBytes() const
comment|//------------------------------------------------------------------
name|virtual
specifier|const
name|uint8_t
operator|*
name|GetBytes
argument_list|()
specifier|const
block|;
comment|//------------------------------------------------------------------
comment|/// @copydoc DataBuffer::GetByteSize() const
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|offset_t
name|GetByteSize
argument_list|()
specifier|const
block|;
comment|//------------------------------------------------------------------
comment|/// Error get accessor.
comment|///
comment|/// @return
comment|///     A const reference to Error object in case memory mapping
comment|///     fails.
comment|//------------------------------------------------------------------
specifier|const
name|Error
operator|&
name|GetError
argument_list|()
specifier|const
block|;
comment|//------------------------------------------------------------------
comment|/// Memory map all or part of a file.
comment|///
comment|/// Memory map \a length bytes from \a file starting \a offset
comment|/// bytes into the file. If \a length is set to \c SIZE_MAX,
comment|/// then map as many bytes as possible.
comment|///
comment|/// @param[in] file
comment|///     The file specification from which to map data.
comment|///
comment|/// @param[in] offset
comment|///     The offset in bytes from the beginning of the file where
comment|///     memory mapping should begin.
comment|///
comment|/// @param[in] length
comment|///     The size in bytes that should be mapped starting \a offset
comment|///     bytes into the file. If \a length is \c SIZE_MAX, map
comment|///     as many bytes as possible.  Even though it may be possible
comment|///     for a 32-bit host debugger to debug a 64-bit target, size_t
comment|///     still dictates the maximum possible size that can be mapped
comment|///     into this process.  For this kind of cross-arch debugging
comment|///     scenario, mappings and views should be managed at a higher
comment|///     level.
comment|///
comment|/// @return
comment|///     The number of bytes mapped starting from the \a offset.
comment|//------------------------------------------------------------------
name|size_t
name|MemoryMapFromFileSpec
argument_list|(
argument|const FileSpec* file
argument_list|,
argument|lldb::offset_t offset =
literal|0
argument_list|,
argument|size_t length = SIZE_MAX
argument_list|,
argument|bool writeable = false
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Memory map all or part of a file.
comment|///
comment|/// Memory map \a length bytes from an opened file descriptor \a fd
comment|/// starting \a offset bytes into the file. If \a length is set to
comment|/// \c SIZE_MAX, then map as many bytes as possible.
comment|///
comment|/// @param[in] fd
comment|///     The posix file descriptor for an already opened file
comment|///     from which to map data.
comment|///
comment|/// @param[in] offset
comment|///     The offset in bytes from the beginning of the file where
comment|///     memory mapping should begin.
comment|///
comment|/// @param[in] length
comment|///     The size in bytes that should be mapped starting \a offset
comment|///     bytes into the file. If \a length is \c SIZE_MAX, map
comment|///     as many bytes as possible.
comment|///
comment|/// @return
comment|///     The number of bytes mapped starting from the \a offset.
comment|//------------------------------------------------------------------
name|size_t
name|MemoryMapFromFileDescriptor
argument_list|(
argument|int fd
argument_list|,
argument|lldb::offset_t offset
argument_list|,
argument|size_t length
argument_list|,
argument|bool write
argument_list|,
argument|bool fd_is_file
argument_list|)
block|;
name|protected
operator|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from DataBufferMemoryMap can see and modify these
comment|//------------------------------------------------------------------
name|uint8_t
operator|*
name|m_mmap_addr
block|;
comment|///< The actual pointer that was returned from \c mmap()
name|size_t
name|m_mmap_size
block|;
comment|///< The actual number of bytes that were mapped when \c mmap() was called
name|uint8_t
operator|*
name|m_data
block|;
comment|///< The data the user requested somewhere within the memory mapped data.
name|lldb
operator|::
name|offset_t
name|m_size
block|;
comment|///< The size of the data the user got when data was requested
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|DataBufferMemoryMap
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #if defined(__cplusplus)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_DataBufferMemoryMap_h_
end_comment

end_unit

