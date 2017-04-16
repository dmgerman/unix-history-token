begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DataExtractor.h -----------------------------------------*- C++ -*-===//
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
name|LLDB_UTILITY_DATAEXTRACTOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_UTILITY_DATAEXTRACTOR_H
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

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

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Log
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Stream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// C++ Includes
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class DataExtractor DataExtractor.h "lldb/Core/DataExtractor.h"
comment|/// @brief An data extractor class.
comment|///
comment|/// DataExtractor is a class that can extract data (swapping if needed)
comment|/// from a data buffer. The data buffer can be caller owned, or can be
comment|/// shared data that can be shared between multiple DataExtractor
comment|/// instances. Multiple DataExtractor objects can share the same data,
comment|/// yet extract values in different address sizes and byte order modes.
comment|/// Each object can have a unique position in the shared data and extract
comment|/// data from different offsets.
comment|///
comment|/// @see DataBuffer
comment|//----------------------------------------------------------------------
name|class
name|DataExtractor
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// @typedef DataExtractor::Type
comment|/// @brief Type enumerations used in the dump routines.
comment|//------------------------------------------------------------------
typedef|typedef
enum|enum
block|{
name|TypeUInt8
block|,
comment|///< Format output as unsigned 8 bit integers
name|TypeChar
block|,
comment|///< Format output as characters
name|TypeUInt16
block|,
comment|///< Format output as unsigned 16 bit integers
name|TypeUInt32
block|,
comment|///< Format output as unsigned 32 bit integers
name|TypeUInt64
block|,
comment|///< Format output as unsigned 64 bit integers
name|TypePointer
block|,
comment|///< Format output as pointers
name|TypeULEB128
block|,
comment|///< Format output as ULEB128 numbers
name|TypeSLEB128
comment|///< Format output as SLEB128 numbers
block|}
name|Type
typedef|;
comment|//------------------------------------------------------------------
comment|/// Default constructor.
comment|///
comment|/// Initialize all members to a default empty state.
comment|//------------------------------------------------------------------
name|DataExtractor
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
comment|///
comment|/// @param[in] target_byte_size
comment|///     A size of a target byte in 8-bit host bytes
comment|//------------------------------------------------------------------
name|DataExtractor
argument_list|(
argument|const void *data
argument_list|,
argument|lldb::offset_t data_length
argument_list|,
argument|lldb::ByteOrder byte_order
argument_list|,
argument|uint32_t addr_size
argument_list|,
argument|uint32_t target_byte_size =
literal|1
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
comment|///
comment|/// @param[in] target_byte_size
comment|///     A size of a target byte in 8-bit host bytes
comment|//------------------------------------------------------------------
name|DataExtractor
argument_list|(
argument|const lldb::DataBufferSP&data_sp
argument_list|,
argument|lldb::ByteOrder byte_order
argument_list|,
argument|uint32_t addr_size
argument_list|,
argument|uint32_t target_byte_size =
literal|1
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Construct with a subset of \a data.
comment|///
comment|/// Initialize this object with a subset of the data bytes in \a
comment|/// data. If \a data contains shared data, then a reference to the
comment|/// shared data will be added to ensure the shared data stays around
comment|/// as long as any objects have references to the shared data. The
comment|/// byte order value and the address size settings are copied from \a
comment|/// data. If \a offset is not a valid offset in \a data, then no
comment|/// reference to the shared data will be added. If there are not
comment|/// \a length bytes available in \a data starting at \a offset,
comment|/// the length will be truncated to contain as many bytes as
comment|/// possible.
comment|///
comment|/// @param[in] data
comment|///     Another DataExtractor object that contains data.
comment|///
comment|/// @param[in] offset
comment|///     The offset into \a data at which the subset starts.
comment|///
comment|/// @param[in] length
comment|///     The length in bytes of the subset of data.
comment|///
comment|/// @param[in] target_byte_size
comment|///     A size of a target byte in 8-bit host bytes
comment|//------------------------------------------------------------------
name|DataExtractor
argument_list|(
argument|const DataExtractor&data
argument_list|,
argument|lldb::offset_t offset
argument_list|,
argument|lldb::offset_t length
argument_list|,
argument|uint32_t target_byte_size =
literal|1
argument_list|)
empty_stmt|;
name|DataExtractor
argument_list|(
specifier|const
name|DataExtractor
operator|&
name|rhs
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Assignment operator.
comment|///
comment|/// Copies all data, byte order and address size settings from \a rhs into
comment|/// this object. If \a rhs contains shared data, a reference to that
comment|/// shared data will be added.
comment|///
comment|/// @param[in] rhs
comment|///     Another DataExtractor object to copy.
comment|///
comment|/// @return
comment|///     A const reference to this object.
comment|//------------------------------------------------------------------
specifier|const
name|DataExtractor
modifier|&
name|operator
init|=
operator|(
specifier|const
name|DataExtractor
operator|&
name|rhs
operator|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|///
comment|/// If this object contains a valid shared data reference, the
comment|/// reference count on the data will be decremented, and if zero,
comment|/// the data will be freed.
comment|//------------------------------------------------------------------
name|virtual
operator|~
name|DataExtractor
argument_list|()
expr_stmt|;
name|uint32_t
name|getTargetByteSize
argument_list|()
specifier|const
block|{
return|return
name|m_target_byte_size
return|;
block|}
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
comment|/// Dumps the binary data as \a type objects to stream \a s (or to
comment|/// Log() if \a s is nullptr) starting \a offset bytes into the data
comment|/// and stopping after dumping \a length bytes. The offset into the
comment|/// data is displayed at the beginning of each line and can be
comment|/// offset by base address \a base_addr. \a num_per_line objects
comment|/// will be displayed on each line.
comment|///
comment|/// @param[in] s
comment|///     The stream to dump the output to. If nullptr the output will
comment|///     be dumped to Log().
comment|///
comment|/// @param[in] offset
comment|///     The offset into the data at which to start dumping.
comment|///
comment|/// @param[in] length
comment|///     The number of bytes to dump.
comment|///
comment|/// @param[in] base_addr
comment|///     The base address that gets added to the offset displayed on
comment|///     each line.
comment|///
comment|/// @param[in] num_per_line
comment|///     The number of \a type objects to display on each line.
comment|///
comment|/// @param[in] type
comment|///     The type of objects to use when dumping data from this
comment|///     object. See DataExtractor::Type.
comment|///
comment|/// @param[in] type_format
comment|///     The optional format to use for the \a type objects. If this
comment|///     is nullptr, the default format for the \a type will be used.
comment|///
comment|/// @return
comment|///     The offset at which dumping ended.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|offset_t
name|PutToLog
argument_list|(
argument|Log *log
argument_list|,
argument|lldb::offset_t offset
argument_list|,
argument|lldb::offset_t length
argument_list|,
argument|uint64_t base_addr
argument_list|,
argument|uint32_t num_per_line
argument_list|,
argument|Type type
argument_list|,
argument|const char *type_format = nullptr
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Dump a UUID value at \a offset.
comment|///
comment|/// Dump a UUID starting at \a offset bytes into this object's data.
comment|/// If the stream \a s is nullptr, the output will be sent to Log().
comment|///
comment|/// @param[in] s
comment|///     The stream to dump the output to. If nullptr the output will
comment|///     be dumped to Log().
comment|///
comment|/// @param[in] offset
comment|///     The offset into the data at which to extract and dump a
comment|///     UUID value.
comment|//------------------------------------------------------------------
name|void
name|DumpUUID
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|lldb
operator|::
name|offset_t
name|offset
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Extract an arbitrary number of bytes in the specified byte
comment|/// order.
comment|///
comment|/// Attemps to extract \a length bytes starting at \a offset bytes
comment|/// into this data in the requested byte order (\a dst_byte_order)
comment|/// and place the results in \a dst. \a dst must be at least \a
comment|/// length bytes long.
comment|///
comment|/// @param[in] offset
comment|///     The offset in bytes into the contained data at which to
comment|///     start extracting.
comment|///
comment|/// @param[in] length
comment|///     The number of bytes to extract.
comment|///
comment|/// @param[in] dst_byte_order
comment|///     A byte order of the data that we want when the value in
comment|///     copied to \a dst.
comment|///
comment|/// @param[out] dst
comment|///     The buffer that will receive the extracted value if there
comment|///     are enough bytes available in the current data.
comment|///
comment|/// @return
comment|///     The number of bytes that were extracted which will be \a
comment|///     length when the value is successfully extracted, or zero
comment|///     if there aren't enough bytes at the specified offset.
comment|//------------------------------------------------------------------
name|size_t
name|ExtractBytes
argument_list|(
name|lldb
operator|::
name|offset_t
name|offset
argument_list|,
name|lldb
operator|::
name|offset_t
name|length
argument_list|,
name|lldb
operator|::
name|ByteOrder
name|dst_byte_order
argument_list|,
name|void
operator|*
name|dst
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Extract an address from \a *offset_ptr.
comment|///
comment|/// Extract a single address from the data and update the offset
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
comment|///     The extracted address value.
comment|//------------------------------------------------------------------
name|uint64_t
name|GetAddress
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|)
decl|const
decl_stmt|;
name|uint64_t
name|GetAddress_unchecked
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the current address size.
comment|///
comment|/// Return the size in bytes of any address values this object will
comment|/// extract.
comment|///
comment|/// @return
comment|///     The size in bytes of address values that will be extracted.
comment|//------------------------------------------------------------------
name|uint32_t
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
name|uint64_t
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
comment|/// Extract a C string from \a *offset_ptr.
comment|///
comment|/// Returns a pointer to a C String from the data at the offset
comment|/// pointed to by \a offset_ptr. A variable length NULL terminated C
comment|/// string will be extracted and the \a offset_ptr will be
comment|/// updated with the offset of the byte that follows the NULL
comment|/// terminator byte.
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
comment|///     nullptr will be returned.
comment|//------------------------------------------------------------------
specifier|const
name|char
modifier|*
name|GetCStr
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Extract a C string from \a *offset_ptr with field size \a len.
comment|///
comment|/// Returns a pointer to a C String from the data at the offset
comment|/// pointed to by \a offset_ptr, with a field length of \a len.
comment|/// A NULL terminated C string will be extracted and the \a offset_ptr
comment|/// will be updated with the offset of the byte that follows the fixed
comment|/// length field.
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
comment|///     offset plus the length of the field is out of bounds, or if
comment|///     the field does not contain a NULL terminator byte, nullptr will
comment|///     be returned.
specifier|const
name|char
modifier|*
name|GetCStr
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|,
name|lldb
operator|::
name|offset_t
name|len
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Extract \a length bytes from \a *offset_ptr.
comment|///
comment|/// Returns a pointer to a bytes in this object's data at the offset
comment|/// pointed to by \a offset_ptr. If \a length is zero or too large,
comment|/// then the offset pointed to by \a offset_ptr will not be updated
comment|/// and nullptr will be returned.
comment|///
comment|/// @param[in,out] offset_ptr
comment|///     A pointer to an offset within the data that will be advanced
comment|///     by the appropriate number of bytes if the value is extracted
comment|///     correctly. If the offset is out of bounds or there are not
comment|///     enough bytes to extract this value, the offset will be left
comment|///     unmodified.
comment|///
comment|/// @param[in] length
comment|///     The optional length of a string to extract. If the value is
comment|///     zero, a NULL terminated C string will be extracted.
comment|///
comment|/// @return
comment|///     A pointer to the bytes in this object's data if the offset
comment|///     and length are valid, or nullptr otherwise.
comment|//------------------------------------------------------------------
specifier|const
name|void
modifier|*
name|GetData
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|,
name|lldb
operator|::
name|offset_t
name|length
argument_list|)
decl|const
block|{
specifier|const
name|uint8_t
modifier|*
name|ptr
init|=
name|PeekData
argument_list|(
operator|*
name|offset_ptr
argument_list|,
name|length
argument_list|)
decl_stmt|;
if|if
condition|(
name|ptr
condition|)
operator|*
name|offset_ptr
operator|+=
name|length
expr_stmt|;
return|return
name|ptr
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Copy \a length bytes from \a *offset, without swapping bytes.
comment|///
comment|/// @param[in] offset
comment|///     The offset into this data from which to start copying
comment|///
comment|/// @param[in] length
comment|///     The length of the data to copy from this object
comment|///
comment|/// @param[out] dst
comment|///     The buffer to place the output data.
comment|///
comment|/// @return
comment|///     Returns the number of bytes that were copied, or zero if
comment|///     anything goes wrong.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|offset_t
name|CopyData
argument_list|(
argument|lldb::offset_t offset
argument_list|,
argument|lldb::offset_t length
argument_list|,
argument|void *dst
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Copy \a dst_len bytes from \a *offset_ptr and ensure the copied
comment|/// data is treated as a value that can be swapped to match the
comment|/// specified byte order.
comment|///
comment|/// For values that are larger than the supported integer sizes,
comment|/// this function can be used to extract data in a specified byte
comment|/// order. It can also be used to copy a smaller integer value from
comment|/// to a larger value. The extra bytes left over will be padded
comment|/// correctly according to the byte order of this object and the
comment|/// \a dst_byte_order. This can be very handy when say copying a
comment|/// partial data value into a register.
comment|///
comment|/// @param[in] src_offset
comment|///     The offset into this data from which to start copying an
comment|///     endian entity
comment|///
comment|/// @param[in] src_len
comment|///     The length of the endian data to copy from this object
comment|///     into the \a dst object
comment|///
comment|/// @param[out] dst
comment|///     The buffer where to place the endian data. The data might
comment|///     need to be byte swapped (and appropriately padded with
comment|///     zeroes if \a src_len != \a dst_len) if \a dst_byte_order
comment|///     does not match the byte order in this object.
comment|///
comment|/// @param[in] dst_len
comment|///     The length number of bytes that the endian value will
comment|///     occupy is \a dst.
comment|///
comment|/// @param[in] byte_order
comment|///     The byte order that the endian value should be in the \a dst
comment|///     buffer.
comment|///
comment|/// @return
comment|///     Returns the number of bytes that were copied, or zero if
comment|///     anything goes wrong.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|offset_t
name|CopyByteOrderedData
argument_list|(
argument|lldb::offset_t src_offset
argument_list|,
argument|lldb::offset_t src_len
argument_list|,
argument|void *dst
argument_list|,
argument|lldb::offset_t dst_len
argument_list|,
argument|lldb::ByteOrder dst_byte_order
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the data end pointer.
comment|///
comment|/// @return
comment|///     Returns a pointer to the next byte contained in this
comment|///     object's data, or nullptr of there is no data in this object.
comment|//------------------------------------------------------------------
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
comment|/// Get the data start pointer.
comment|///
comment|/// @return
comment|///     Returns a pointer to the first byte contained in this
comment|///     object's data, or nullptr of there is no data in this object.
comment|//------------------------------------------------------------------
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
comment|/// Extract a float from \a *offset_ptr.
comment|///
comment|/// Extract a single float value.
comment|///
comment|/// @param[in,out] offset_ptr
comment|///     A pointer to an offset within the data that will be advanced
comment|///     by the appropriate number of bytes if the value is extracted
comment|///     correctly. If the offset is out of bounds or there are not
comment|///     enough bytes to extract this value, the offset will be left
comment|///     unmodified.
comment|///
comment|/// @return
comment|///     The floating value that was extracted, or zero on failure.
comment|//------------------------------------------------------------------
name|float
name|GetFloat
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|)
decl|const
decl_stmt|;
name|double
name|GetDouble
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|)
decl|const
decl_stmt|;
name|long
name|double
name|GetLongDouble
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Extract an integer of size \a byte_size from \a *offset_ptr.
comment|///
comment|/// Extract a single integer value and update the offset pointed to
comment|/// by \a offset_ptr. The size of the extracted integer is specified
comment|/// by the \a byte_size argument. \a byte_size should have a value
comment|///>= 1 and<= 4 since the return value is only 32 bits wide. Any
comment|/// \a byte_size values less than 1 or greater than 4 will result in
comment|/// nothing being extracted, and zero being returned.
comment|///
comment|/// @param[in,out] offset_ptr
comment|///     A pointer to an offset within the data that will be advanced
comment|///     by the appropriate number of bytes if the value is extracted
comment|///     correctly. If the offset is out of bounds or there are not
comment|///     enough bytes to extract this value, the offset will be left
comment|///     unmodified.
comment|///
comment|/// @param[in] byte_size
comment|///     The size in byte of the integer to extract.
comment|///
comment|/// @return
comment|///     The integer value that was extracted, or zero on failure.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetMaxU32
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|,
name|size_t
name|byte_size
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Extract an unsigned integer of size \a byte_size from \a
comment|/// *offset_ptr.
comment|///
comment|/// Extract a single unsigned integer value and update the offset
comment|/// pointed to by \a offset_ptr. The size of the extracted integer
comment|/// is specified by the \a byte_size argument. \a byte_size should
comment|/// have a value greater than or equal to one and less than or equal
comment|/// to eight since the return value is 64 bits wide. Any
comment|/// \a byte_size values less than 1 or greater than 8 will result in
comment|/// nothing being extracted, and zero being returned.
comment|///
comment|/// @param[in,out] offset_ptr
comment|///     A pointer to an offset within the data that will be advanced
comment|///     by the appropriate number of bytes if the value is extracted
comment|///     correctly. If the offset is out of bounds or there are not
comment|///     enough bytes to extract this value, the offset will be left
comment|///     unmodified.
comment|///
comment|/// @param[in] byte_size
comment|///     The size in byte of the integer to extract.
comment|///
comment|/// @return
comment|///     The unsigned integer value that was extracted, or zero on
comment|///     failure.
comment|//------------------------------------------------------------------
name|uint64_t
name|GetMaxU64
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|,
name|size_t
name|byte_size
argument_list|)
decl|const
decl_stmt|;
name|uint64_t
name|GetMaxU64_unchecked
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|,
name|size_t
name|byte_size
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Extract an signed integer of size \a byte_size from \a *offset_ptr.
comment|///
comment|/// Extract a single signed integer value (sign extending if required)
comment|/// and update the offset pointed to by \a offset_ptr. The size of
comment|/// the extracted integer is specified by the \a byte_size argument.
comment|/// \a byte_size should have a value greater than or equal to one
comment|/// and less than or equal to eight since the return value is 64
comment|/// bits wide. Any \a byte_size values less than 1 or greater than
comment|/// 8 will result in nothing being extracted, and zero being returned.
comment|///
comment|/// @param[in,out] offset_ptr
comment|///     A pointer to an offset within the data that will be advanced
comment|///     by the appropriate number of bytes if the value is extracted
comment|///     correctly. If the offset is out of bounds or there are not
comment|///     enough bytes to extract this value, the offset will be left
comment|///     unmodified.
comment|///
comment|/// @param[in] byte_size
comment|///     The size in byte of the integer to extract.
comment|///
comment|/// @return
comment|///     The sign extended signed integer value that was extracted,
comment|///     or zero on failure.
comment|//------------------------------------------------------------------
name|int64_t
name|GetMaxS64
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|,
name|size_t
name|size
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Extract an unsigned integer of size \a byte_size from \a
comment|/// *offset_ptr, then extract the bitfield from this value if
comment|/// \a bitfield_bit_size is non-zero.
comment|///
comment|/// Extract a single unsigned integer value and update the offset
comment|/// pointed to by \a offset_ptr. The size of the extracted integer
comment|/// is specified by the \a byte_size argument. \a byte_size should
comment|/// have a value greater than or equal to one and less than or equal
comment|/// to 8 since the return value is 64 bits wide. Any
comment|/// \a byte_size values less than 1 or greater than 8 will result in
comment|/// nothing being extracted, and zero being returned.
comment|///
comment|/// @param[in,out] offset_ptr
comment|///     A pointer to an offset within the data that will be advanced
comment|///     by the appropriate number of bytes if the value is extracted
comment|///     correctly. If the offset is out of bounds or there are not
comment|///     enough bytes to extract this value, the offset will be left
comment|///     unmodified.
comment|///
comment|/// @param[in] byte_size
comment|///     The size in byte of the integer to extract.
comment|///
comment|/// @param[in] bitfield_bit_size
comment|///     The size in bits of the bitfield value to extract, or zero
comment|///     to just extract the entire integer value.
comment|///
comment|/// @param[in] bitfield_bit_offset
comment|///     The bit offset of the bitfield value in the extracted
comment|///     integer.  For little-endian data, this is the offset of
comment|///     the LSB of the bitfield from the LSB of the integer.
comment|///     For big-endian data, this is the offset of the MSB of the
comment|///     bitfield from the MSB of the integer.
comment|///
comment|/// @return
comment|///     The unsigned bitfield integer value that was extracted, or
comment|///     zero on failure.
comment|//------------------------------------------------------------------
name|uint64_t
name|GetMaxU64Bitfield
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|,
name|size_t
name|size
argument_list|,
name|uint32_t
name|bitfield_bit_size
argument_list|,
name|uint32_t
name|bitfield_bit_offset
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Extract an signed integer of size \a byte_size from \a
comment|/// *offset_ptr, then extract and signe extend the bitfield from
comment|/// this value if \a bitfield_bit_size is non-zero.
comment|///
comment|/// Extract a single signed integer value (sign extending if required)
comment|/// and update the offset pointed to by \a offset_ptr. The size of
comment|/// the extracted integer is specified by the \a byte_size argument.
comment|/// \a byte_size should have a value greater than or equal to one
comment|/// and less than or equal to eight since the return value is 64
comment|/// bits wide. Any \a byte_size values less than 1 or greater than
comment|/// 8 will result in nothing being extracted, and zero being returned.
comment|///
comment|/// @param[in,out] offset_ptr
comment|///     A pointer to an offset within the data that will be advanced
comment|///     by the appropriate number of bytes if the value is extracted
comment|///     correctly. If the offset is out of bounds or there are not
comment|///     enough bytes to extract this value, the offset will be left
comment|///     unmodified.
comment|///
comment|/// @param[in] byte_size
comment|///     The size in bytes of the integer to extract.
comment|///
comment|/// @param[in] bitfield_bit_size
comment|///     The size in bits of the bitfield value to extract, or zero
comment|///     to just extract the entire integer value.
comment|///
comment|/// @param[in] bitfield_bit_offset
comment|///     The bit offset of the bitfield value in the extracted
comment|///     integer.  For little-endian data, this is the offset of
comment|///     the LSB of the bitfield from the LSB of the integer.
comment|///     For big-endian data, this is the offset of the MSB of the
comment|///     bitfield from the MSB of the integer.
comment|///
comment|/// @return
comment|///     The signed bitfield integer value that was extracted, or
comment|///     zero on failure.
comment|//------------------------------------------------------------------
name|int64_t
name|GetMaxS64Bitfield
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|,
name|size_t
name|size
argument_list|,
name|uint32_t
name|bitfield_bit_size
argument_list|,
name|uint32_t
name|bitfield_bit_offset
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Extract an pointer from \a *offset_ptr.
comment|///
comment|/// Extract a single pointer from the data and update the offset
comment|/// pointed to by \a offset_ptr. The size of the extracted pointer
comment|/// comes from the \a m_addr_size member variable and should be
comment|/// set correctly prior to extracting any pointer values.
comment|///
comment|/// @param[in,out] offset_ptr
comment|///     A pointer to an offset within the data that will be advanced
comment|///     by the appropriate number of bytes if the value is extracted
comment|///     correctly. If the offset is out of bounds or there are not
comment|///     enough bytes to extract this value, the offset will be left
comment|///     unmodified.
comment|///
comment|/// @return
comment|///     The extracted pointer value as a 64 integer.
comment|//------------------------------------------------------------------
name|uint64_t
name|GetPointer
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|)
decl|const
decl_stmt|;
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
comment|/// Extract a uint8_t value from \a *offset_ptr.
comment|///
comment|/// Extract a single uint8_t from the binary data at the offset
comment|/// pointed to by \a offset_ptr, and advance the offset on success.
comment|///
comment|/// @param[in,out] offset_ptr
comment|///     A pointer to an offset within the data that will be advanced
comment|///     by the appropriate number of bytes if the value is extracted
comment|///     correctly. If the offset is out of bounds or there are not
comment|///     enough bytes to extract this value, the offset will be left
comment|///     unmodified.
comment|///
comment|/// @return
comment|///     The extracted uint8_t value.
comment|//------------------------------------------------------------------
name|uint8_t
name|GetU8
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|)
decl|const
decl_stmt|;
name|uint8_t
name|GetU8_unchecked
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|)
decl|const
block|{
name|uint8_t
name|val
init|=
name|m_start
index|[
operator|*
name|offset_ptr
index|]
decl_stmt|;
operator|*
name|offset_ptr
operator|+=
literal|1
expr_stmt|;
return|return
name|val
return|;
block|}
name|uint16_t
name|GetU16_unchecked
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|)
decl|const
decl_stmt|;
name|uint32_t
name|GetU32_unchecked
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|)
decl|const
decl_stmt|;
name|uint64_t
name|GetU64_unchecked
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Extract \a count uint8_t values from \a *offset_ptr.
comment|///
comment|/// Extract \a count uint8_t values from the binary data at the
comment|/// offset pointed to by \a offset_ptr, and advance the offset on
comment|/// success. The extracted values are copied into \a dst.
comment|///
comment|/// @param[in,out] offset_ptr
comment|///     A pointer to an offset within the data that will be advanced
comment|///     by the appropriate number of bytes if the value is extracted
comment|///     correctly. If the offset is out of bounds or there are not
comment|///     enough bytes to extract this value, the offset will be left
comment|///     unmodified.
comment|///
comment|/// @param[out] dst
comment|///     A buffer to copy \a count uint8_t values into. \a dst must
comment|///     be large enough to hold all requested data.
comment|///
comment|/// @param[in] count
comment|///     The number of uint8_t values to extract.
comment|///
comment|/// @return
comment|///     \a dst if all values were properly extracted and copied,
comment|///     nullptr otherwise.
comment|//------------------------------------------------------------------
name|void
modifier|*
name|GetU8
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|,
name|void
operator|*
name|dst
argument_list|,
name|uint32_t
name|count
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Extract a uint16_t value from \a *offset_ptr.
comment|///
comment|/// Extract a single uint16_t from the binary data at the offset
comment|/// pointed to by \a offset_ptr, and update the offset on success.
comment|///
comment|/// @param[in,out] offset_ptr
comment|///     A pointer to an offset within the data that will be advanced
comment|///     by the appropriate number of bytes if the value is extracted
comment|///     correctly. If the offset is out of bounds or there are not
comment|///     enough bytes to extract this value, the offset will be left
comment|///     unmodified.
comment|///
comment|/// @return
comment|///     The extracted uint16_t value.
comment|//------------------------------------------------------------------
name|uint16_t
name|GetU16
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Extract \a count uint16_t values from \a *offset_ptr.
comment|///
comment|/// Extract \a count uint16_t values from the binary data at the
comment|/// offset pointed to by \a offset_ptr, and advance the offset on
comment|/// success. The extracted values are copied into \a dst.
comment|///
comment|/// @param[in,out] offset_ptr
comment|///     A pointer to an offset within the data that will be advanced
comment|///     by the appropriate number of bytes if the value is extracted
comment|///     correctly. If the offset is out of bounds or there are not
comment|///     enough bytes to extract this value, the offset will be left
comment|///     unmodified.
comment|///
comment|/// @param[out] dst
comment|///     A buffer to copy \a count uint16_t values into. \a dst must
comment|///     be large enough to hold all requested data.
comment|///
comment|/// @param[in] count
comment|///     The number of uint16_t values to extract.
comment|///
comment|/// @return
comment|///     \a dst if all values were properly extracted and copied,
comment|///     nullptr otherwise.
comment|//------------------------------------------------------------------
name|void
modifier|*
name|GetU16
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|,
name|void
operator|*
name|dst
argument_list|,
name|uint32_t
name|count
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Extract a uint32_t value from \a *offset_ptr.
comment|///
comment|/// Extract a single uint32_t from the binary data at the offset
comment|/// pointed to by \a offset_ptr, and update the offset on success.
comment|///
comment|/// @param[in,out] offset_ptr
comment|///     A pointer to an offset within the data that will be advanced
comment|///     by the appropriate number of bytes if the value is extracted
comment|///     correctly. If the offset is out of bounds or there are not
comment|///     enough bytes to extract this value, the offset will be left
comment|///     unmodified.
comment|///
comment|/// @return
comment|///     The extracted uint32_t value.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetU32
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Extract \a count uint32_t values from \a *offset_ptr.
comment|///
comment|/// Extract \a count uint32_t values from the binary data at the
comment|/// offset pointed to by \a offset_ptr, and advance the offset on
comment|/// success. The extracted values are copied into \a dst.
comment|///
comment|/// @param[in,out] offset_ptr
comment|///     A pointer to an offset within the data that will be advanced
comment|///     by the appropriate number of bytes if the value is extracted
comment|///     correctly. If the offset is out of bounds or there are not
comment|///     enough bytes to extract this value, the offset will be left
comment|///     unmodified.
comment|///
comment|/// @param[out] dst
comment|///     A buffer to copy \a count uint32_t values into. \a dst must
comment|///     be large enough to hold all requested data.
comment|///
comment|/// @param[in] count
comment|///     The number of uint32_t values to extract.
comment|///
comment|/// @return
comment|///     \a dst if all values were properly extracted and copied,
comment|///     nullptr otherwise.
comment|//------------------------------------------------------------------
name|void
modifier|*
name|GetU32
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|,
name|void
operator|*
name|dst
argument_list|,
name|uint32_t
name|count
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Extract a uint64_t value from \a *offset_ptr.
comment|///
comment|/// Extract a single uint64_t from the binary data at the offset
comment|/// pointed to by \a offset_ptr, and update the offset on success.
comment|///
comment|/// @param[in,out] offset_ptr
comment|///     A pointer to an offset within the data that will be advanced
comment|///     by the appropriate number of bytes if the value is extracted
comment|///     correctly. If the offset is out of bounds or there are not
comment|///     enough bytes to extract this value, the offset will be left
comment|///     unmodified.
comment|///
comment|/// @return
comment|///     The extracted uint64_t value.
comment|//------------------------------------------------------------------
name|uint64_t
name|GetU64
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Extract \a count uint64_t values from \a *offset_ptr.
comment|///
comment|/// Extract \a count uint64_t values from the binary data at the
comment|/// offset pointed to by \a offset_ptr, and advance the offset on
comment|/// success. The extracted values are copied into \a dst.
comment|///
comment|/// @param[in,out] offset_ptr
comment|///     A pointer to an offset within the data that will be advanced
comment|///     by the appropriate number of bytes if the value is extracted
comment|///     correctly. If the offset is out of bounds or there are not
comment|///     enough bytes to extract this value, the offset will be left
comment|///     unmodified.
comment|///
comment|/// @param[out] dst
comment|///     A buffer to copy \a count uint64_t values into. \a dst must
comment|///     be large enough to hold all requested data.
comment|///
comment|/// @param[in] count
comment|///     The number of uint64_t values to extract.
comment|///
comment|/// @return
comment|///     \a dst if all values were properly extracted and copied,
comment|///     nullptr otherwise.
comment|//------------------------------------------------------------------
name|void
modifier|*
name|GetU64
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|,
name|void
operator|*
name|dst
argument_list|,
name|uint32_t
name|count
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Extract a signed LEB128 value from \a *offset_ptr.
comment|///
comment|/// Extracts an signed LEB128 number from this object's data
comment|/// starting at the offset pointed to by \a offset_ptr. The offset
comment|/// pointed to by \a offset_ptr will be updated with the offset of
comment|/// the byte following the last extracted byte.
comment|///
comment|/// @param[in,out] offset_ptr
comment|///     A pointer to an offset within the data that will be advanced
comment|///     by the appropriate number of bytes if the value is extracted
comment|///     correctly. If the offset is out of bounds or there are not
comment|///     enough bytes to extract this value, the offset will be left
comment|///     unmodified.
comment|///
comment|/// @return
comment|///     The extracted signed integer value.
comment|//------------------------------------------------------------------
name|int64_t
name|GetSLEB128
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Extract a unsigned LEB128 value from \a *offset_ptr.
comment|///
comment|/// Extracts an unsigned LEB128 number from this object's data
comment|/// starting at the offset pointed to by \a offset_ptr. The offset
comment|/// pointed to by \a offset_ptr will be updated with the offset of
comment|/// the byte following the last extracted byte.
comment|///
comment|/// @param[in,out] offset_ptr
comment|///     A pointer to an offset within the data that will be advanced
comment|///     by the appropriate number of bytes if the value is extracted
comment|///     correctly. If the offset is out of bounds or there are not
comment|///     enough bytes to extract this value, the offset will be left
comment|///     unmodified.
comment|///
comment|/// @return
comment|///     The extracted unsigned integer value.
comment|//------------------------------------------------------------------
name|uint64_t
name|GetULEB128
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|)
decl|const
decl_stmt|;
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
comment|/// Peek at a C string at \a offset.
comment|///
comment|/// Peeks at a string in the contained data. No verification is done
comment|/// to make sure the entire string lies within the bounds of this
comment|/// object's data, only \a offset is verified to be a valid offset.
comment|///
comment|/// @param[in] offset
comment|///     An offset into the data.
comment|///
comment|/// @return
comment|///     A non-nullptr C string pointer if \a offset is a valid offset,
comment|///     nullptr otherwise.
comment|//------------------------------------------------------------------
specifier|const
name|char
modifier|*
name|PeekCStr
argument_list|(
name|lldb
operator|::
name|offset_t
name|offset
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Peek at a bytes at \a offset.
comment|///
comment|/// Returns a pointer to \a length bytes at \a offset as long as
comment|/// there are \a length bytes available starting at \a offset.
comment|///
comment|/// @return
comment|///     A non-nullptr data pointer if \a offset is a valid offset and
comment|///     there are \a length bytes available at that offset, nullptr
comment|///     otherwise.
comment|//------------------------------------------------------------------
specifier|const
name|uint8_t
modifier|*
name|PeekData
argument_list|(
name|lldb
operator|::
name|offset_t
name|offset
argument_list|,
name|lldb
operator|::
name|offset_t
name|length
argument_list|)
decl|const
block|{
if|if
condition|(
name|ValidOffsetForDataOfSize
argument_list|(
name|offset
argument_list|,
name|length
argument_list|)
condition|)
return|return
name|m_start
operator|+
name|offset
return|;
return|return
name|nullptr
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
name|uint32_t
name|addr_size
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|LLDB_CONFIGURATION_DEBUG
name|assert
argument_list|(
name|addr_size
operator|==
literal|4
operator|||
name|addr_size
operator|==
literal|8
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
comment|/// bytes is nullptr, or \a length is zero, this object will contain
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
name|lldb
operator|::
name|offset_t
name|SetData
argument_list|(
argument|const void *bytes
argument_list|,
argument|lldb::offset_t length
argument_list|,
argument|lldb::ByteOrder byte_order
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Adopt a subset of \a data.
comment|///
comment|/// Set this object's data to be a subset of the data bytes in \a
comment|/// data. If \a data contains shared data, then a reference to the
comment|/// shared data will be added to ensure the shared data stays around
comment|/// as long as any objects have references to the shared data. The
comment|/// byte order and the address size settings are copied from \a
comment|/// data. If \a offset is not a valid offset in \a data, then no
comment|/// reference to the shared data will be added. If there are not
comment|/// \a length bytes available in \a data starting at \a offset,
comment|/// the length will be truncated to contains as many bytes as
comment|/// possible.
comment|///
comment|/// @param[in] data
comment|///     Another DataExtractor object that contains data.
comment|///
comment|/// @param[in] offset
comment|///     The offset into \a data at which the subset starts.
comment|///
comment|/// @param[in] length
comment|///     The length in bytes of the subset of \a data.
comment|///
comment|/// @return
comment|///     The number of bytes that this object now contains.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|offset_t
name|SetData
argument_list|(
argument|const DataExtractor&data
argument_list|,
argument|lldb::offset_t offset
argument_list|,
argument|lldb::offset_t length
argument_list|)
expr_stmt|;
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
name|lldb
operator|::
name|offset_t
name|SetData
argument_list|(
argument|const lldb::DataBufferSP&data_sp
argument_list|,
argument|lldb::offset_t offset =
literal|0
argument_list|,
argument|lldb::offset_t length = LLDB_INVALID_OFFSET
argument_list|)
expr_stmt|;
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
comment|/// Skip an LEB128 number at \a *offset_ptr.
comment|///
comment|/// Skips a LEB128 number (signed or unsigned) from this object's
comment|/// data starting at the offset pointed to by \a offset_ptr. The
comment|/// offset pointed to by \a offset_ptr will be updated with the
comment|/// offset of the byte following the last extracted byte.
comment|///
comment|/// @param[in,out] offset_ptr
comment|///     A pointer to an offset within the data that will be advanced
comment|///     by the appropriate number of bytes if the value is extracted
comment|///     correctly. If the offset is out of bounds or there are not
comment|///     enough bytes to extract this value, the offset will be left
comment|///     unmodified.
comment|///
comment|/// @return
comment|//      The number of bytes consumed during the extraction.
comment|//------------------------------------------------------------------
name|uint32_t
name|Skip_LEB128
argument_list|(
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|)
decl|const
decl_stmt|;
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
name|lldb
operator|::
name|offset_t
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
name|lldb
operator|::
name|offset_t
name|offset
argument_list|,
name|lldb
operator|::
name|offset_t
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
name|size_t
name|Copy
argument_list|(
name|DataExtractor
operator|&
name|dest_data
argument_list|)
decl|const
decl_stmt|;
name|bool
name|Append
parameter_list|(
name|DataExtractor
modifier|&
name|rhs
parameter_list|)
function_decl|;
name|bool
name|Append
argument_list|(
name|void
operator|*
name|bytes
argument_list|,
name|lldb
operator|::
name|offset_t
name|length
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|offset_t
name|BytesLeft
argument_list|(
argument|lldb::offset_t offset
argument_list|)
specifier|const
block|{
specifier|const
name|lldb
operator|::
name|offset_t
name|size
operator|=
name|GetByteSize
argument_list|()
block|;
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
name|void
name|Checksum
argument_list|(
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|uint8_t
operator|>
operator|&
name|dest
argument_list|,
name|uint64_t
name|max_data
operator|=
literal|0
argument_list|)
decl_stmt|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Member variables
comment|//------------------------------------------------------------------
specifier|const
name|uint8_t
modifier|*
name|m_start
decl_stmt|;
comment|///< A pointer to the first byte of data.
specifier|const
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
name|uint32_t
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
specifier|const
name|uint32_t
name|m_target_byte_size
decl_stmt|;
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
comment|// liblldb_DataExtractor_h_
end_comment

end_unit

