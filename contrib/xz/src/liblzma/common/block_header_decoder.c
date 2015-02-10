begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       block_header_decoder.c
end_comment

begin_comment
comment|/// \brief      Decodes Block Header from .xz files
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_include
include|#
directive|include
file|"check.h"
end_include

begin_function
specifier|static
name|void
name|free_properties
parameter_list|(
name|lzma_block
modifier|*
name|block
parameter_list|,
specifier|const
name|lzma_allocator
modifier|*
name|allocator
parameter_list|)
block|{
comment|// Free allocated filter options. The last array member is not
comment|// touched after the initialization in the beginning of
comment|// lzma_block_header_decode(), so we don't need to touch that here.
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|LZMA_FILTERS_MAX
condition|;
operator|++
name|i
control|)
block|{
name|lzma_free
argument_list|(
name|block
operator|->
name|filters
index|[
name|i
index|]
operator|.
name|options
argument_list|,
name|allocator
argument_list|)
expr_stmt|;
name|block
operator|->
name|filters
index|[
name|i
index|]
operator|.
name|id
operator|=
name|LZMA_VLI_UNKNOWN
expr_stmt|;
name|block
operator|->
name|filters
index|[
name|i
index|]
operator|.
name|options
operator|=
name|NULL
expr_stmt|;
block|}
return|return;
block|}
end_function

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_block_header_decode
argument_list|(
argument|lzma_block *block
argument_list|,
argument|const lzma_allocator *allocator
argument_list|,
argument|const uint8_t *in
argument_list|)
end_macro

begin_block
block|{
comment|// NOTE: We consider the header to be corrupt not only when the
comment|// CRC32 doesn't match, but also when variable-length integers
comment|// are invalid or over 63 bits, or if the header is too small
comment|// to contain the claimed information.
comment|// Initialize the filter options array. This way the caller can
comment|// safely free() the options even if an error occurs in this function.
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<=
name|LZMA_FILTERS_MAX
condition|;
operator|++
name|i
control|)
block|{
name|block
operator|->
name|filters
index|[
name|i
index|]
operator|.
name|id
operator|=
name|LZMA_VLI_UNKNOWN
expr_stmt|;
name|block
operator|->
name|filters
index|[
name|i
index|]
operator|.
name|options
operator|=
name|NULL
expr_stmt|;
block|}
comment|// Versions 0 and 1 are supported. If a newer version was specified,
comment|// we need to downgrade it.
if|if
condition|(
name|block
operator|->
name|version
operator|>
literal|1
condition|)
name|block
operator|->
name|version
operator|=
literal|1
expr_stmt|;
comment|// This isn't a Block Header option, but since the decompressor will
comment|// read it if version>= 1, it's better to initialize it here than
comment|// to expect the caller to do it since in almost all cases this
comment|// should be false.
name|block
operator|->
name|ignore_check
operator|=
name|false
expr_stmt|;
comment|// Validate Block Header Size and Check type. The caller must have
comment|// already set these, so it is a programming error if this test fails.
if|if
condition|(
name|lzma_block_header_size_decode
argument_list|(
name|in
index|[
literal|0
index|]
argument_list|)
operator|!=
name|block
operator|->
name|header_size
operator|||
call|(
name|unsigned
name|int
call|)
argument_list|(
name|block
operator|->
name|check
argument_list|)
operator|>
name|LZMA_CHECK_ID_MAX
condition|)
return|return
name|LZMA_PROG_ERROR
return|;
comment|// Exclude the CRC32 field.
specifier|const
name|size_t
name|in_size
init|=
name|block
operator|->
name|header_size
operator|-
literal|4
decl_stmt|;
comment|// Verify CRC32
if|if
condition|(
name|lzma_crc32
argument_list|(
name|in
argument_list|,
name|in_size
argument_list|,
literal|0
argument_list|)
operator|!=
name|unaligned_read32le
argument_list|(
name|in
operator|+
name|in_size
argument_list|)
condition|)
return|return
name|LZMA_DATA_ERROR
return|;
comment|// Check for unsupported flags.
if|if
condition|(
name|in
index|[
literal|1
index|]
operator|&
literal|0x3C
condition|)
return|return
name|LZMA_OPTIONS_ERROR
return|;
comment|// Start after the Block Header Size and Block Flags fields.
name|size_t
name|in_pos
init|=
literal|2
decl_stmt|;
comment|// Compressed Size
if|if
condition|(
name|in
index|[
literal|1
index|]
operator|&
literal|0x40
condition|)
block|{
name|return_if_error
argument_list|(
name|lzma_vli_decode
argument_list|(
operator|&
name|block
operator|->
name|compressed_size
argument_list|,
name|NULL
argument_list|,
name|in
argument_list|,
operator|&
name|in_pos
argument_list|,
name|in_size
argument_list|)
argument_list|)
expr_stmt|;
comment|// Validate Compressed Size. This checks that it isn't zero
comment|// and that the total size of the Block is a valid VLI.
if|if
condition|(
name|lzma_block_unpadded_size
argument_list|(
name|block
argument_list|)
operator|==
literal|0
condition|)
return|return
name|LZMA_DATA_ERROR
return|;
block|}
else|else
block|{
name|block
operator|->
name|compressed_size
operator|=
name|LZMA_VLI_UNKNOWN
expr_stmt|;
block|}
comment|// Uncompressed Size
if|if
condition|(
name|in
index|[
literal|1
index|]
operator|&
literal|0x80
condition|)
name|return_if_error
argument_list|(
name|lzma_vli_decode
argument_list|(
operator|&
name|block
operator|->
name|uncompressed_size
argument_list|,
name|NULL
argument_list|,
name|in
argument_list|,
operator|&
name|in_pos
argument_list|,
name|in_size
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|block
operator|->
name|uncompressed_size
operator|=
name|LZMA_VLI_UNKNOWN
expr_stmt|;
comment|// Filter Flags
specifier|const
name|size_t
name|filter_count
init|=
operator|(
name|in
index|[
literal|1
index|]
operator|&
literal|3
operator|)
operator|+
literal|1
decl_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|filter_count
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|lzma_ret
name|ret
init|=
name|lzma_filter_flags_decode
argument_list|(
operator|&
name|block
operator|->
name|filters
index|[
name|i
index|]
argument_list|,
name|allocator
argument_list|,
name|in
argument_list|,
operator|&
name|in_pos
argument_list|,
name|in_size
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
operator|!=
name|LZMA_OK
condition|)
block|{
name|free_properties
argument_list|(
name|block
argument_list|,
name|allocator
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
block|}
comment|// Padding
while|while
condition|(
name|in_pos
operator|<
name|in_size
condition|)
block|{
if|if
condition|(
name|in
index|[
name|in_pos
operator|++
index|]
operator|!=
literal|0x00
condition|)
block|{
name|free_properties
argument_list|(
name|block
argument_list|,
name|allocator
argument_list|)
expr_stmt|;
comment|// Possibly some new field present so use
comment|// LZMA_OPTIONS_ERROR instead of LZMA_DATA_ERROR.
return|return
name|LZMA_OPTIONS_ERROR
return|;
block|}
block|}
return|return
name|LZMA_OK
return|;
block|}
end_block

end_unit

