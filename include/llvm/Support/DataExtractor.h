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
name|LLVM_SUPPORT_DATAEXTRACTOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_DATAEXTRACTOR_H
end_define

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

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// An auxiliary type to facilitate extraction of 3-byte entities.
struct|struct
name|Uint24
block|{
name|uint8_t
name|Bytes
index|[
literal|3
index|]
decl_stmt|;
name|Uint24
argument_list|(
argument|uint8_t U
argument_list|)
block|{
name|Bytes
index|[
literal|0
index|]
operator|=
name|Bytes
index|[
literal|1
index|]
operator|=
name|Bytes
index|[
literal|2
index|]
operator|=
name|U
expr_stmt|;
block|}
name|Uint24
argument_list|(
argument|uint8_t U0
argument_list|,
argument|uint8_t U1
argument_list|,
argument|uint8_t U2
argument_list|)
block|{
name|Bytes
index|[
literal|0
index|]
operator|=
name|U0
expr_stmt|;
name|Bytes
index|[
literal|1
index|]
operator|=
name|U1
expr_stmt|;
name|Bytes
index|[
literal|2
index|]
operator|=
name|U2
expr_stmt|;
block|}
name|uint32_t
name|getAsUint32
argument_list|(
name|bool
name|IsLittleEndian
argument_list|)
decl|const
block|{
name|int
name|LoIx
init|=
name|IsLittleEndian
condition|?
literal|0
else|:
literal|2
decl_stmt|;
return|return
name|Bytes
index|[
name|LoIx
index|]
operator|+
operator|(
name|Bytes
index|[
literal|1
index|]
operator|<<
literal|8
operator|)
operator|+
operator|(
name|Bytes
index|[
literal|2
operator|-
name|LoIx
index|]
operator|<<
literal|16
operator|)
return|;
block|}
block|}
struct|;
name|using
name|uint24_t
init|=
name|Uint24
decl_stmt|;
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|uint24_t
argument_list|)
operator|==
literal|3
argument_list|,
literal|"sizeof(uint24_t) != 3"
argument_list|)
expr_stmt|;
comment|/// Needed by swapByteOrder().
specifier|inline
name|uint24_t
name|getSwappedBytes
parameter_list|(
name|uint24_t
name|C
parameter_list|)
block|{
return|return
name|uint24_t
argument_list|(
name|C
operator|.
name|Bytes
index|[
literal|2
index|]
argument_list|,
name|C
operator|.
name|Bytes
index|[
literal|1
index|]
argument_list|,
name|C
operator|.
name|Bytes
index|[
literal|0
index|]
argument_list|)
return|;
block|}
name|class
name|DataExtractor
block|{
name|StringRef
name|Data
decl_stmt|;
name|uint8_t
name|IsLittleEndian
decl_stmt|;
name|uint8_t
name|AddressSize
decl_stmt|;
name|public
label|:
comment|/// Construct with a buffer that is owned by the caller.
comment|///
comment|/// This constructor allows us to use data that is owned by the
comment|/// caller. The data must stay around as long as this object is
comment|/// valid.
name|DataExtractor
argument_list|(
argument|StringRef Data
argument_list|,
argument|bool IsLittleEndian
argument_list|,
argument|uint8_t AddressSize
argument_list|)
block|:
name|Data
argument_list|(
name|Data
argument_list|)
operator|,
name|IsLittleEndian
argument_list|(
name|IsLittleEndian
argument_list|)
operator|,
name|AddressSize
argument_list|(
argument|AddressSize
argument_list|)
block|{}
comment|/// \brief Get the data pointed to by this extractor.
name|StringRef
name|getData
argument_list|()
specifier|const
block|{
return|return
name|Data
return|;
block|}
comment|/// \brief Get the endianness for this extractor.
name|bool
name|isLittleEndian
argument_list|()
specifier|const
block|{
return|return
name|IsLittleEndian
return|;
block|}
comment|/// \brief Get the address size for this extractor.
name|uint8_t
name|getAddressSize
argument_list|()
specifier|const
block|{
return|return
name|AddressSize
return|;
block|}
comment|/// \brief Set the address size for this extractor.
name|void
name|setAddressSize
parameter_list|(
name|uint8_t
name|Size
parameter_list|)
block|{
name|AddressSize
operator|=
name|Size
expr_stmt|;
block|}
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
comment|///     NULL will be returned.
specifier|const
name|char
modifier|*
name|getCStr
argument_list|(
name|uint32_t
operator|*
name|offset_ptr
argument_list|)
decl|const
decl_stmt|;
comment|/// Extract a C string from \a *OffsetPtr.
comment|///
comment|/// Returns a StringRef for the C String from the data at the offset
comment|/// pointed to by \a OffsetPtr. A variable length NULL terminated C
comment|/// string will be extracted and the \a OffsetPtr will be
comment|/// updated with the offset of the byte that follows the NULL
comment|/// terminator byte.
comment|///
comment|/// \param[in,out] OffsetPtr
comment|///     A pointer to an offset within the data that will be advanced
comment|///     by the appropriate number of bytes if the value is extracted
comment|///     correctly. If the offset is out of bounds or there are not
comment|///     enough bytes to extract this value, the offset will be left
comment|///     unmodified.
comment|///
comment|/// \return
comment|///     A StringRef for the C string value in the data. If the offset
comment|///     pointed to by \a OffsetPtr is out of bounds, or if the
comment|///     offset plus the length of the C string is out of bounds,
comment|///     a default-initialized StringRef will be returned.
name|StringRef
name|getCStrRef
argument_list|(
name|uint32_t
operator|*
name|OffsetPtr
argument_list|)
decl|const
decl_stmt|;
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
name|uint64_t
name|getUnsigned
argument_list|(
name|uint32_t
operator|*
name|offset_ptr
argument_list|,
name|uint32_t
name|byte_size
argument_list|)
decl|const
decl_stmt|;
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
comment|/// @param[in] size
comment|///     The size in bytes of the integer to extract.
comment|///
comment|/// @return
comment|///     The sign extended signed integer value that was extracted,
comment|///     or zero on failure.
name|int64_t
name|getSigned
argument_list|(
name|uint32_t
operator|*
name|offset_ptr
argument_list|,
name|uint32_t
name|size
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Extract an pointer from \a *offset_ptr.
comment|///
comment|/// Extract a single pointer from the data and update the offset
comment|/// pointed to by \a offset_ptr. The size of the extracted pointer
comment|/// is \a getAddressSize(), so the address size has to be
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
name|uint64_t
name|getAddress
argument_list|(
name|uint32_t
operator|*
name|offset_ptr
argument_list|)
decl|const
block|{
return|return
name|getUnsigned
argument_list|(
name|offset_ptr
argument_list|,
name|AddressSize
argument_list|)
return|;
block|}
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
name|uint8_t
name|getU8
argument_list|(
name|uint32_t
operator|*
name|offset_ptr
argument_list|)
decl|const
decl_stmt|;
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
comment|///     NULL otherise.
name|uint8_t
modifier|*
name|getU8
argument_list|(
name|uint32_t
operator|*
name|offset_ptr
argument_list|,
name|uint8_t
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
name|getU16
argument_list|(
name|uint32_t
operator|*
name|offset_ptr
argument_list|)
decl|const
decl_stmt|;
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
comment|///     NULL otherise.
name|uint16_t
modifier|*
name|getU16
argument_list|(
name|uint32_t
operator|*
name|offset_ptr
argument_list|,
name|uint16_t
operator|*
name|dst
argument_list|,
name|uint32_t
name|count
argument_list|)
decl|const
decl_stmt|;
comment|/// Extract a 24-bit unsigned value from \a *offset_ptr and return it
comment|/// in a uint32_t.
comment|///
comment|/// Extract 3 bytes from the binary data at the offset pointed to by
comment|/// \a offset_ptr, construct a uint32_t from them and update the offset
comment|/// on success.
comment|///
comment|/// @param[in,out] offset_ptr
comment|///     A pointer to an offset within the data that will be advanced
comment|///     by the 3 bytes if the value is extracted correctly. If the offset
comment|///     is out of bounds or there are not enough bytes to extract this value,
comment|///     the offset will be left unmodified.
comment|///
comment|/// @return
comment|///     The extracted 24-bit value represented in a uint32_t.
name|uint32_t
name|getU24
argument_list|(
name|uint32_t
operator|*
name|offset_ptr
argument_list|)
decl|const
decl_stmt|;
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
name|uint32_t
name|getU32
argument_list|(
name|uint32_t
operator|*
name|offset_ptr
argument_list|)
decl|const
decl_stmt|;
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
comment|///     NULL otherise.
name|uint32_t
modifier|*
name|getU32
argument_list|(
name|uint32_t
operator|*
name|offset_ptr
argument_list|,
name|uint32_t
operator|*
name|dst
argument_list|,
name|uint32_t
name|count
argument_list|)
decl|const
decl_stmt|;
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
name|uint64_t
name|getU64
argument_list|(
name|uint32_t
operator|*
name|offset_ptr
argument_list|)
decl|const
decl_stmt|;
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
comment|///     NULL otherise.
name|uint64_t
modifier|*
name|getU64
argument_list|(
name|uint32_t
operator|*
name|offset_ptr
argument_list|,
name|uint64_t
operator|*
name|dst
argument_list|,
name|uint32_t
name|count
argument_list|)
decl|const
decl_stmt|;
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
name|int64_t
name|getSLEB128
argument_list|(
name|uint32_t
operator|*
name|offset_ptr
argument_list|)
decl|const
decl_stmt|;
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
name|uint64_t
name|getULEB128
argument_list|(
name|uint32_t
operator|*
name|offset_ptr
argument_list|)
decl|const
decl_stmt|;
comment|/// Test the validity of \a offset.
comment|///
comment|/// @return
comment|///     \b true if \a offset is a valid offset into the data in this
comment|///     object, \b false otherwise.
name|bool
name|isValidOffset
argument_list|(
name|uint32_t
name|offset
argument_list|)
decl|const
block|{
return|return
name|Data
operator|.
name|size
argument_list|()
operator|>
name|offset
return|;
block|}
comment|/// Test the availability of \a length bytes of data from \a offset.
comment|///
comment|/// @return
comment|///     \b true if \a offset is a valid offset and there are \a
comment|///     length bytes available at that offset, \b false otherwise.
name|bool
name|isValidOffsetForDataOfSize
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
name|offset
operator|+
name|length
operator|>=
name|offset
operator|&&
name|isValidOffset
argument_list|(
name|offset
operator|+
name|length
operator|-
literal|1
argument_list|)
return|;
block|}
comment|/// Test the availability of enough bytes of data for a pointer from
comment|/// \a offset. The size of a pointer is \a getAddressSize().
comment|///
comment|/// @return
comment|///     \b true if \a offset is a valid offset and there are enough
comment|///     bytes for a pointer available at that offset, \b false
comment|///     otherwise.
name|bool
name|isValidOffsetForAddress
argument_list|(
name|uint32_t
name|offset
argument_list|)
decl|const
block|{
return|return
name|isValidOffsetForDataOfSize
argument_list|(
name|offset
argument_list|,
name|AddressSize
argument_list|)
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

