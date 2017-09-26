begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DataEncoder.h -------------------------------------------*- C++ -*-===//
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
name|liblldb_DataEncoder_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_DataEncoder_h_
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
file|"lldb/lldb-defines.h"
end_include

begin_comment
comment|// for DISALLOW_COPY_AND_ASSIGN
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_comment
comment|// for ByteOrder
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_comment
comment|// for DataBufferSP
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_comment
comment|// for addr_t
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// for size_t
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class DataEncoder DataEncoder.h "lldb/Core/DataEncoder.h"
comment|/// @brief An binary data encoding class.
comment|///
comment|/// DataEncoder is a class that can encode binary data (swapping if needed)
comment|/// to a data buffer. The data buffer can be caller owned, or can be
comment|/// shared data that can be shared between multiple DataEncoder or
comment|/// DataEncoder instances.
comment|///
comment|/// @see DataBuffer
comment|//----------------------------------------------------------------------
name|class
name|DataEncoder
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Default constructor.
comment|///
comment|/// Initialize all members to a default empty state.
comment|//------------------------------------------------------------------
name|DataEncoder
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Construct with a buffer that is owned by the caller.
comment|///
comment|/// This constructor allows us to use data that is owned by the
comment|/// caller. The data must stay around as long as this object is
comment|/// valid.
comment|///
comment|/// @param[in] data
comment|///     A pointer to caller owned data.
comment|///
comment|/// @param[in] data_length
comment|///     The length in bytes of \a data.
comment|///
comment|/// @param[in] byte_order
comment|///     A byte order of the data that we are extracting from.
comment|///
comment|/// @param[in] addr_size
comment|///     A new address byte size value.
comment|//------------------------------------------------------------------
name|DataEncoder
argument_list|(
argument|void *data
argument_list|,
argument|uint32_t data_length
argument_list|,
argument|lldb::ByteOrder byte_order
argument_list|,
argument|uint8_t addr_size
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Construct with shared data.
comment|///
comment|/// Copies the data shared pointer which adds a reference to the
comment|/// contained in \a data_sp. The shared data reference is reference
comment|/// counted to ensure the data lives as long as anyone still has a
comment|/// valid shared pointer to the data in \a data_sp.
comment|///
comment|/// @param[in] data_sp
comment|///     A shared pointer to data.
comment|///
comment|/// @param[in] byte_order
comment|///     A byte order of the data that we are extracting from.
comment|///
comment|/// @param[in] addr_size
comment|///     A new address byte size value.
comment|//------------------------------------------------------------------
name|DataEncoder
argument_list|(
argument|const lldb::DataBufferSP&data_sp
argument_list|,
argument|lldb::ByteOrder byte_order
argument_list|,
argument|uint8_t addr_size
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|///
comment|/// If this object contains a valid shared data reference, the
comment|/// reference count on the data will be decremented, and if zero,
comment|/// the data will be freed.
comment|//------------------------------------------------------------------
operator|~
name|DataEncoder
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Clears the object state.
comment|///
comment|/// Clears the object contents back to a default invalid state, and
comment|/// release any references to shared data that this object may
comment|/// contain.
comment|//------------------------------------------------------------------
name|void
name|Clear
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get the current address size.
comment|///
comment|/// Return the size in bytes of any address values this object will
comment|/// extract.
comment|///
comment|/// @return
comment|///     The size in bytes of address values that will be extracted.
comment|//------------------------------------------------------------------
name|uint8_t
name|GetAddressByteSize
argument_list|()
specifier|const
block|{
return|return
name|m_addr_size
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the number of bytes contained in this object.
comment|///
comment|/// @return
comment|///     The total number of bytes of data this object refers to.
comment|//------------------------------------------------------------------
name|size_t
name|GetByteSize
argument_list|()
specifier|const
block|{
return|return
name|m_end
operator|-
name|m_start
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the data end pointer.
comment|///
comment|/// @return
comment|///     Returns a pointer to the next byte contained in this
comment|///     object's data, or NULL of there is no data in this object.
comment|//------------------------------------------------------------------
name|uint8_t
modifier|*
name|GetDataEnd
parameter_list|()
block|{
return|return
name|m_end
return|;
block|}
specifier|const
name|uint8_t
operator|*
name|GetDataEnd
argument_list|()
specifier|const
block|{
return|return
name|m_end
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the shared data offset.
comment|///
comment|/// Get the offset of the first byte of data in the shared data (if
comment|/// any).
comment|///
comment|/// @return
comment|///     If this object contains shared data, this function returns
comment|///     the offset in bytes into that shared data, zero otherwise.
comment|//------------------------------------------------------------------
name|size_t
name|GetSharedDataOffset
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the current byte order value.
comment|///
comment|/// @return
comment|///     The current byte order value from this object's internal
comment|///     state.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
specifier|const
block|{
return|return
name|m_byte_order
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the data start pointer.
comment|///
comment|/// @return
comment|///     Returns a pointer to the first byte contained in this
comment|///     object's data, or NULL of there is no data in this object.
comment|//------------------------------------------------------------------
name|uint8_t
modifier|*
name|GetDataStart
parameter_list|()
block|{
return|return
name|m_start
return|;
block|}
specifier|const
name|uint8_t
operator|*
name|GetDataStart
argument_list|()
specifier|const
block|{
return|return
name|m_start
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Encode unsigned integer values into the data at \a offset.
comment|///
comment|/// @param[in] offset
comment|///     The offset within the contained data at which to put the
comment|///     data.
comment|///
comment|/// @param[in] value
comment|///     The value to encode into the data.
comment|///
comment|/// @return
comment|///     The next offset in the bytes of this data if the data
comment|///     was successfully encoded, UINT32_MAX if the encoding failed.
comment|//------------------------------------------------------------------
name|uint32_t
name|PutU8
parameter_list|(
name|uint32_t
name|offset
parameter_list|,
name|uint8_t
name|value
parameter_list|)
function_decl|;
name|uint32_t
name|PutU16
parameter_list|(
name|uint32_t
name|offset
parameter_list|,
name|uint16_t
name|value
parameter_list|)
function_decl|;
name|uint32_t
name|PutU32
parameter_list|(
name|uint32_t
name|offset
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
name|uint32_t
name|PutU64
parameter_list|(
name|uint32_t
name|offset
parameter_list|,
name|uint64_t
name|value
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Encode an unsigned integer of size \a byte_size to \a offset.
comment|///
comment|/// Encode a single integer value at \a offset and return the offset
comment|/// that follows the newly encoded integer when the data is successfully
comment|/// encoded into the existing data. There must be enough room in the
comment|/// data, else UINT32_MAX will be returned to indicate that encoding
comment|/// failed.
comment|///
comment|/// @param[in] offset
comment|///     The offset within the contained data at which to put the
comment|///     encoded integer.
comment|///
comment|/// @param[in] byte_size
comment|///     The size in byte of the integer to encode.
comment|///
comment|/// @param[in] value
comment|///     The integer value to write. The least significant bytes of
comment|///     the integer value will be written if the size is less than
comment|///     8 bytes.
comment|///
comment|/// @return
comment|///     The next offset in the bytes of this data if the integer
comment|///     was successfully encoded, UINT32_MAX if the encoding failed.
comment|//------------------------------------------------------------------
name|uint32_t
name|PutMaxU64
parameter_list|(
name|uint32_t
name|offset
parameter_list|,
name|uint32_t
name|byte_size
parameter_list|,
name|uint64_t
name|value
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Encode an arbitrary number of bytes.
comment|///
comment|/// @param[in] offset
comment|///     The offset in bytes into the contained data at which to
comment|///     start encoding.
comment|///
comment|/// @param[in] src
comment|///     The buffer that contains the bytes to encode.
comment|///
comment|/// @param[in] src_len
comment|///     The number of bytes to encode.
comment|///
comment|/// @return
comment|///     The next valid offset within data if the put operation
comment|///     was successful, else UINT32_MAX to indicate the put failed.
comment|//------------------------------------------------------------------
name|uint32_t
name|PutData
parameter_list|(
name|uint32_t
name|offset
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|uint32_t
name|src_len
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Encode an address in the existing buffer at \a offset bytes into
comment|/// the buffer.
comment|///
comment|/// Encode a single address (honoring the m_addr_size member) to
comment|/// the data and return the next offset where subsequent data would
comment|/// go.
comment|/// pointed to by \a offset_ptr. The size of the extracted address
comment|/// comes from the \a m_addr_size member variable and should be
comment|/// set correctly prior to extracting any address values.
comment|///
comment|/// @param[in,out] offset_ptr
comment|///     A pointer to an offset within the data that will be advanced
comment|///     by the appropriate number of bytes if the value is extracted
comment|///     correctly. If the offset is out of bounds or there are not
comment|///     enough bytes to extract this value, the offset will be left
comment|///     unmodified.
comment|///
comment|/// @return
comment|///     The next valid offset within data if the put operation
comment|///     was successful, else UINT32_MAX to indicate the put failed.
comment|//------------------------------------------------------------------
name|uint32_t
name|PutAddress
argument_list|(
name|uint32_t
name|offset
argument_list|,
name|lldb
operator|::
name|addr_t
name|addr
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Put a C string to \a offset.
comment|///
comment|/// Encodes a C string into the existing data including the
comment|/// terminating
comment|///
comment|/// @param[in,out] offset_ptr
comment|///     A pointer to an offset within the data that will be advanced
comment|///     by the appropriate number of bytes if the value is extracted
comment|///     correctly. If the offset is out of bounds or there are not
comment|///     enough bytes to extract this value, the offset will be left
comment|///     unmodified.
comment|///
comment|/// @return
comment|///     A pointer to the C string value in the data. If the offset
comment|///     pointed to by \a offset_ptr is out of bounds, or if the
comment|///     offset plus the length of the C string is out of bounds,
comment|///     NULL will be returned.
comment|//------------------------------------------------------------------
name|uint32_t
name|PutCString
parameter_list|(
name|uint32_t
name|offset_ptr
parameter_list|,
specifier|const
name|char
modifier|*
name|cstr
parameter_list|)
function_decl|;
name|lldb
operator|::
name|DataBufferSP
operator|&
name|GetSharedDataBuffer
argument_list|()
block|{
return|return
name|m_data_sp
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Set the address byte size.
comment|///
comment|/// Set the size in bytes that will be used when extracting any
comment|/// address and pointer values from data contained in this object.
comment|///
comment|/// @param[in] addr_size
comment|///     The size in bytes to use when extracting addresses.
comment|//------------------------------------------------------------------
name|void
name|SetAddressByteSize
parameter_list|(
name|uint8_t
name|addr_size
parameter_list|)
block|{
name|m_addr_size
operator|=
name|addr_size
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// Set data with a buffer that is caller owned.
comment|///
comment|/// Use data that is owned by the caller when extracting values.
comment|/// The data must stay around as long as this object, or any object
comment|/// that copies a subset of this object's data, is valid. If \a
comment|/// bytes is NULL, or \a length is zero, this object will contain
comment|/// no data.
comment|///
comment|/// @param[in] bytes
comment|///     A pointer to caller owned data.
comment|///
comment|/// @param[in] length
comment|///     The length in bytes of \a bytes.
comment|///
comment|/// @param[in] byte_order
comment|///     A byte order of the data that we are extracting from.
comment|///
comment|/// @return
comment|///     The number of bytes that this object now contains.
comment|//------------------------------------------------------------------
name|uint32_t
name|SetData
argument_list|(
name|void
operator|*
name|bytes
argument_list|,
name|uint32_t
name|length
argument_list|,
name|lldb
operator|::
name|ByteOrder
name|byte_order
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Adopt a subset of shared data in \a data_sp.
comment|///
comment|/// Copies the data shared pointer which adds a reference to the
comment|/// contained in \a data_sp. The shared data reference is reference
comment|/// counted to ensure the data lives as long as anyone still has a
comment|/// valid shared pointer to the data in \a data_sp. The byte order
comment|/// and address byte size settings remain the same. If
comment|/// \a offset is not a valid offset in \a data_sp, then no reference
comment|/// to the shared data will be added. If there are not \a length
comment|/// bytes available in \a data starting at \a offset, the length
comment|/// will be truncated to contains as many bytes as possible.
comment|///
comment|/// @param[in] data_sp
comment|///     A shared pointer to data.
comment|///
comment|/// @param[in] offset
comment|///     The offset into \a data_sp at which the subset starts.
comment|///
comment|/// @param[in] length
comment|///     The length in bytes of the subset of \a data_sp.
comment|///
comment|/// @return
comment|///     The number of bytes that this object now contains.
comment|//------------------------------------------------------------------
name|uint32_t
name|SetData
argument_list|(
specifier|const
name|lldb
operator|::
name|DataBufferSP
operator|&
name|data_sp
argument_list|,
name|uint32_t
name|offset
operator|=
literal|0
argument_list|,
name|uint32_t
name|length
operator|=
name|UINT32_MAX
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Set the byte_order value.
comment|///
comment|/// Sets the byte order of the data to extract. Extracted values
comment|/// will be swapped if necessary when decoding.
comment|///
comment|/// @param[in] byte_order
comment|///     The byte order value to use when extracting data.
comment|//------------------------------------------------------------------
name|void
name|SetByteOrder
argument_list|(
name|lldb
operator|::
name|ByteOrder
name|byte_order
argument_list|)
block|{
name|m_byte_order
operator|=
name|byte_order
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// Test the validity of \a offset.
comment|///
comment|/// @return
comment|///     \b true if \a offset is a valid offset into the data in this
comment|///     object, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|ValidOffset
argument_list|(
name|uint32_t
name|offset
argument_list|)
decl|const
block|{
return|return
name|offset
operator|<
name|GetByteSize
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Test the availability of \a length bytes of data from \a offset.
comment|///
comment|/// @return
comment|///     \b true if \a offset is a valid offset and there are \a
comment|///     length bytes available at that offset, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|ValidOffsetForDataOfSize
argument_list|(
name|uint32_t
name|offset
argument_list|,
name|uint32_t
name|length
argument_list|)
decl|const
block|{
return|return
name|length
operator|<=
name|BytesLeft
argument_list|(
name|offset
argument_list|)
return|;
block|}
name|uint32_t
name|BytesLeft
argument_list|(
name|uint32_t
name|offset
argument_list|)
decl|const
block|{
specifier|const
name|uint32_t
name|size
init|=
name|GetByteSize
argument_list|()
decl_stmt|;
if|if
condition|(
name|size
operator|>
name|offset
condition|)
return|return
name|size
operator|-
name|offset
return|;
return|return
literal|0
return|;
block|}
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Member variables
comment|//------------------------------------------------------------------
name|uint8_t
modifier|*
name|m_start
decl_stmt|;
comment|///< A pointer to the first byte of data.
name|uint8_t
modifier|*
name|m_end
decl_stmt|;
comment|///< A pointer to the byte that is past the end of the data.
name|lldb
operator|::
name|ByteOrder
name|m_byte_order
expr_stmt|;
comment|///< The byte order of the data we are extracting from.
name|uint8_t
name|m_addr_size
decl_stmt|;
comment|///< The address size to use when extracting pointers or
comment|/// addresses
name|mutable
name|lldb
operator|::
name|DataBufferSP
name|m_data_sp
expr_stmt|;
comment|///< The shared pointer to data that can
comment|/// be shared among multiple instances
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|DataEncoder
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
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
comment|// #if defined (__cplusplus)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_DataEncoder_h_
end_comment

end_unit

