begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       block_buffer_encoder.c
end_comment

begin_comment
comment|/// \brief      Single-call .xz Block encoder
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
file|"block_buffer_encoder.h"
end_include

begin_include
include|#
directive|include
file|"block_encoder.h"
end_include

begin_include
include|#
directive|include
file|"filter_encoder.h"
end_include

begin_include
include|#
directive|include
file|"lzma2_encoder.h"
end_include

begin_include
include|#
directive|include
file|"check.h"
end_include

begin_comment
comment|/// Estimate the maximum size of the Block Header and Check fields for
end_comment

begin_comment
comment|/// a Block that uses LZMA2 uncompressed chunks. We could use
end_comment

begin_comment
comment|/// lzma_block_header_size() but this is simpler.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Block Header Size + Block Flags + Compressed Size
end_comment

begin_comment
comment|/// + Uncompressed Size + Filter Flags for LZMA2 + CRC32 + Check
end_comment

begin_comment
comment|/// and round up to the next multiple of four to take Header Padding
end_comment

begin_comment
comment|/// into account.
end_comment

begin_define
define|#
directive|define
name|HEADERS_BOUND
value|((1 + 1 + 2 * LZMA_VLI_BYTES_MAX + 3 + 4 \ 		+ LZMA_CHECK_SIZE_MAX + 3)& ~3)
end_define

begin_function
specifier|static
name|uint64_t
name|lzma2_bound
parameter_list|(
name|uint64_t
name|uncompressed_size
parameter_list|)
block|{
comment|// Prevent integer overflow in overhead calculation.
if|if
condition|(
name|uncompressed_size
operator|>
name|COMPRESSED_SIZE_MAX
condition|)
return|return
literal|0
return|;
comment|// Calculate the exact overhead of the LZMA2 headers: Round
comment|// uncompressed_size up to the next multiple of LZMA2_CHUNK_MAX,
comment|// multiply by the size of per-chunk header, and add one byte for
comment|// the end marker.
specifier|const
name|uint64_t
name|overhead
init|=
operator|(
operator|(
name|uncompressed_size
operator|+
name|LZMA2_CHUNK_MAX
operator|-
literal|1
operator|)
operator|/
name|LZMA2_CHUNK_MAX
operator|)
operator|*
name|LZMA2_HEADER_UNCOMPRESSED
operator|+
literal|1
decl_stmt|;
comment|// Catch the possible integer overflow.
if|if
condition|(
name|COMPRESSED_SIZE_MAX
operator|-
name|overhead
operator|<
name|uncompressed_size
condition|)
return|return
literal|0
return|;
return|return
name|uncompressed_size
operator|+
name|overhead
return|;
block|}
end_function

begin_function
specifier|extern
name|uint64_t
name|lzma_block_buffer_bound64
parameter_list|(
name|uint64_t
name|uncompressed_size
parameter_list|)
block|{
comment|// If the data doesn't compress, we always use uncompressed
comment|// LZMA2 chunks.
name|uint64_t
name|lzma2_size
init|=
name|lzma2_bound
argument_list|(
name|uncompressed_size
argument_list|)
decl_stmt|;
if|if
condition|(
name|lzma2_size
operator|==
literal|0
condition|)
return|return
literal|0
return|;
comment|// Take Block Padding into account.
name|lzma2_size
operator|=
operator|(
name|lzma2_size
operator|+
literal|3
operator|)
operator|&
operator|~
name|UINT64_C
argument_list|(
literal|3
argument_list|)
expr_stmt|;
comment|// No risk of integer overflow because lzma2_bound() already takes
comment|// into account the size of the headers in the Block.
return|return
name|HEADERS_BOUND
operator|+
name|lzma2_size
return|;
block|}
end_function

begin_extern
extern|extern LZMA_API(size_t
end_extern

begin_macro
unit|)
name|lzma_block_buffer_bound
argument_list|(
argument|size_t uncompressed_size
argument_list|)
end_macro

begin_block
block|{
name|uint64_t
name|ret
init|=
name|lzma_block_buffer_bound64
argument_list|(
name|uncompressed_size
argument_list|)
decl_stmt|;
if|#
directive|if
name|SIZE_MAX
operator|<
name|UINT64_MAX
comment|// Catch the possible integer overflow on 32-bit systems.
if|if
condition|(
name|ret
operator|>
name|SIZE_MAX
condition|)
return|return
literal|0
return|;
endif|#
directive|endif
return|return
name|ret
return|;
block|}
end_block

begin_function
specifier|static
name|lzma_ret
name|block_encode_uncompressed
parameter_list|(
name|lzma_block
modifier|*
name|block
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|in
parameter_list|,
name|size_t
name|in_size
parameter_list|,
name|uint8_t
modifier|*
name|out
parameter_list|,
name|size_t
modifier|*
name|out_pos
parameter_list|,
name|size_t
name|out_size
parameter_list|)
block|{
comment|// Use LZMA2 uncompressed chunks. We wouldn't need a dictionary at
comment|// all, but LZMA2 always requires a dictionary, so use the minimum
comment|// value to minimize memory usage of the decoder.
name|lzma_options_lzma
name|lzma2
init|=
block|{
operator|.
name|dict_size
operator|=
name|LZMA_DICT_SIZE_MIN
block|, 	}
decl_stmt|;
name|lzma_filter
name|filters
index|[
literal|2
index|]
decl_stmt|;
name|filters
index|[
literal|0
index|]
operator|.
name|id
operator|=
name|LZMA_FILTER_LZMA2
expr_stmt|;
name|filters
index|[
literal|0
index|]
operator|.
name|options
operator|=
operator|&
name|lzma2
expr_stmt|;
name|filters
index|[
literal|1
index|]
operator|.
name|id
operator|=
name|LZMA_VLI_UNKNOWN
expr_stmt|;
comment|// Set the above filter options to *block temporarily so that we can
comment|// encode the Block Header.
name|lzma_filter
modifier|*
name|filters_orig
init|=
name|block
operator|->
name|filters
decl_stmt|;
name|block
operator|->
name|filters
operator|=
name|filters
expr_stmt|;
if|if
condition|(
name|lzma_block_header_size
argument_list|(
name|block
argument_list|)
operator|!=
name|LZMA_OK
condition|)
block|{
name|block
operator|->
name|filters
operator|=
name|filters_orig
expr_stmt|;
return|return
name|LZMA_PROG_ERROR
return|;
block|}
comment|// Check that there's enough output space. The caller has already
comment|// set block->compressed_size to what lzma2_bound() has returned,
comment|// so we can reuse that value. We know that compressed_size is a
comment|// known valid VLI and header_size is a small value so their sum
comment|// will never overflow.
name|assert
argument_list|(
name|block
operator|->
name|compressed_size
operator|==
name|lzma2_bound
argument_list|(
name|in_size
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|out_size
operator|-
operator|*
name|out_pos
operator|<
name|block
operator|->
name|header_size
operator|+
name|block
operator|->
name|compressed_size
condition|)
block|{
name|block
operator|->
name|filters
operator|=
name|filters_orig
expr_stmt|;
return|return
name|LZMA_BUF_ERROR
return|;
block|}
if|if
condition|(
name|lzma_block_header_encode
argument_list|(
name|block
argument_list|,
name|out
operator|+
operator|*
name|out_pos
argument_list|)
operator|!=
name|LZMA_OK
condition|)
block|{
name|block
operator|->
name|filters
operator|=
name|filters_orig
expr_stmt|;
return|return
name|LZMA_PROG_ERROR
return|;
block|}
name|block
operator|->
name|filters
operator|=
name|filters_orig
expr_stmt|;
operator|*
name|out_pos
operator|+=
name|block
operator|->
name|header_size
expr_stmt|;
comment|// Encode the data using LZMA2 uncompressed chunks.
name|size_t
name|in_pos
init|=
literal|0
decl_stmt|;
name|uint8_t
name|control
init|=
literal|0x01
decl_stmt|;
comment|// Dictionary reset
while|while
condition|(
name|in_pos
operator|<
name|in_size
condition|)
block|{
comment|// Control byte: Indicate uncompressed chunk, of which
comment|// the first resets the dictionary.
name|out
index|[
operator|(
operator|*
name|out_pos
operator|)
operator|++
index|]
operator|=
name|control
expr_stmt|;
name|control
operator|=
literal|0x02
expr_stmt|;
comment|// No dictionary reset
comment|// Size of the uncompressed chunk
specifier|const
name|size_t
name|copy_size
init|=
name|my_min
argument_list|(
name|in_size
operator|-
name|in_pos
argument_list|,
name|LZMA2_CHUNK_MAX
argument_list|)
decl_stmt|;
name|out
index|[
operator|(
operator|*
name|out_pos
operator|)
operator|++
index|]
operator|=
operator|(
name|copy_size
operator|-
literal|1
operator|)
operator|>>
literal|8
expr_stmt|;
name|out
index|[
operator|(
operator|*
name|out_pos
operator|)
operator|++
index|]
operator|=
operator|(
name|copy_size
operator|-
literal|1
operator|)
operator|&
literal|0xFF
expr_stmt|;
comment|// The actual data
name|assert
argument_list|(
operator|*
name|out_pos
operator|+
name|copy_size
operator|<=
name|out_size
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|out
operator|+
operator|*
name|out_pos
argument_list|,
name|in
operator|+
name|in_pos
argument_list|,
name|copy_size
argument_list|)
expr_stmt|;
name|in_pos
operator|+=
name|copy_size
expr_stmt|;
operator|*
name|out_pos
operator|+=
name|copy_size
expr_stmt|;
block|}
comment|// End marker
name|out
index|[
operator|(
operator|*
name|out_pos
operator|)
operator|++
index|]
operator|=
literal|0x00
expr_stmt|;
name|assert
argument_list|(
operator|*
name|out_pos
operator|<=
name|out_size
argument_list|)
expr_stmt|;
return|return
name|LZMA_OK
return|;
block|}
end_function

begin_function
specifier|static
name|lzma_ret
name|block_encode_normal
parameter_list|(
name|lzma_block
modifier|*
name|block
parameter_list|,
specifier|const
name|lzma_allocator
modifier|*
name|allocator
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|in
parameter_list|,
name|size_t
name|in_size
parameter_list|,
name|uint8_t
modifier|*
name|out
parameter_list|,
name|size_t
modifier|*
name|out_pos
parameter_list|,
name|size_t
name|out_size
parameter_list|)
block|{
comment|// Find out the size of the Block Header.
name|return_if_error
argument_list|(
name|lzma_block_header_size
argument_list|(
name|block
argument_list|)
argument_list|)
expr_stmt|;
comment|// Reserve space for the Block Header and skip it for now.
if|if
condition|(
name|out_size
operator|-
operator|*
name|out_pos
operator|<=
name|block
operator|->
name|header_size
condition|)
return|return
name|LZMA_BUF_ERROR
return|;
specifier|const
name|size_t
name|out_start
init|=
operator|*
name|out_pos
decl_stmt|;
operator|*
name|out_pos
operator|+=
name|block
operator|->
name|header_size
expr_stmt|;
comment|// Limit out_size so that we stop encoding if the output would grow
comment|// bigger than what uncompressed Block would be.
if|if
condition|(
name|out_size
operator|-
operator|*
name|out_pos
operator|>
name|block
operator|->
name|compressed_size
condition|)
name|out_size
operator|=
operator|*
name|out_pos
operator|+
name|block
operator|->
name|compressed_size
expr_stmt|;
comment|// TODO: In many common cases this could be optimized to use
comment|// significantly less memory.
name|lzma_next_coder
name|raw_encoder
init|=
name|LZMA_NEXT_CODER_INIT
decl_stmt|;
name|lzma_ret
name|ret
init|=
name|lzma_raw_encoder_init
argument_list|(
operator|&
name|raw_encoder
argument_list|,
name|allocator
argument_list|,
name|block
operator|->
name|filters
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
operator|==
name|LZMA_OK
condition|)
block|{
name|size_t
name|in_pos
init|=
literal|0
decl_stmt|;
name|ret
operator|=
name|raw_encoder
operator|.
name|code
argument_list|(
name|raw_encoder
operator|.
name|coder
argument_list|,
name|allocator
argument_list|,
name|in
argument_list|,
operator|&
name|in_pos
argument_list|,
name|in_size
argument_list|,
name|out
argument_list|,
name|out_pos
argument_list|,
name|out_size
argument_list|,
name|LZMA_FINISH
argument_list|)
expr_stmt|;
block|}
comment|// NOTE: This needs to be run even if lzma_raw_encoder_init() failed.
name|lzma_next_end
argument_list|(
operator|&
name|raw_encoder
argument_list|,
name|allocator
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|==
name|LZMA_STREAM_END
condition|)
block|{
comment|// Compression was successful. Write the Block Header.
name|block
operator|->
name|compressed_size
operator|=
operator|*
name|out_pos
operator|-
operator|(
name|out_start
operator|+
name|block
operator|->
name|header_size
operator|)
expr_stmt|;
name|ret
operator|=
name|lzma_block_header_encode
argument_list|(
name|block
argument_list|,
name|out
operator|+
name|out_start
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|!=
name|LZMA_OK
condition|)
name|ret
operator|=
name|LZMA_PROG_ERROR
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ret
operator|==
name|LZMA_OK
condition|)
block|{
comment|// Output buffer became full.
name|ret
operator|=
name|LZMA_BUF_ERROR
expr_stmt|;
block|}
comment|// Reset *out_pos if something went wrong.
if|if
condition|(
name|ret
operator|!=
name|LZMA_OK
condition|)
operator|*
name|out_pos
operator|=
name|out_start
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_function
specifier|static
name|lzma_ret
name|block_buffer_encode
parameter_list|(
name|lzma_block
modifier|*
name|block
parameter_list|,
specifier|const
name|lzma_allocator
modifier|*
name|allocator
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|in
parameter_list|,
name|size_t
name|in_size
parameter_list|,
name|uint8_t
modifier|*
name|out
parameter_list|,
name|size_t
modifier|*
name|out_pos
parameter_list|,
name|size_t
name|out_size
parameter_list|,
name|bool
name|try_to_compress
parameter_list|)
block|{
comment|// Validate the arguments.
if|if
condition|(
name|block
operator|==
name|NULL
operator|||
operator|(
name|in
operator|==
name|NULL
operator|&&
name|in_size
operator|!=
literal|0
operator|)
operator|||
name|out
operator|==
name|NULL
operator|||
name|out_pos
operator|==
name|NULL
operator|||
operator|*
name|out_pos
operator|>
name|out_size
condition|)
return|return
name|LZMA_PROG_ERROR
return|;
comment|// The contents of the structure may depend on the version so
comment|// check the version before validating the contents of *block.
if|if
condition|(
name|block
operator|->
name|version
operator|>
literal|1
condition|)
return|return
name|LZMA_OPTIONS_ERROR
return|;
if|if
condition|(
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
operator|||
operator|(
name|try_to_compress
operator|&&
name|block
operator|->
name|filters
operator|==
name|NULL
operator|)
condition|)
return|return
name|LZMA_PROG_ERROR
return|;
if|if
condition|(
operator|!
name|lzma_check_is_supported
argument_list|(
name|block
operator|->
name|check
argument_list|)
condition|)
return|return
name|LZMA_UNSUPPORTED_CHECK
return|;
comment|// Size of a Block has to be a multiple of four, so limit the size
comment|// here already. This way we don't need to check it again when adding
comment|// Block Padding.
name|out_size
operator|-=
operator|(
name|out_size
operator|-
operator|*
name|out_pos
operator|)
operator|&
literal|3
expr_stmt|;
comment|// Get the size of the Check field.
specifier|const
name|size_t
name|check_size
init|=
name|lzma_check_size
argument_list|(
name|block
operator|->
name|check
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|check_size
operator|!=
name|UINT32_MAX
argument_list|)
expr_stmt|;
comment|// Reserve space for the Check field.
if|if
condition|(
name|out_size
operator|-
operator|*
name|out_pos
operator|<=
name|check_size
condition|)
return|return
name|LZMA_BUF_ERROR
return|;
name|out_size
operator|-=
name|check_size
expr_stmt|;
comment|// Initialize block->uncompressed_size and calculate the worst-case
comment|// value for block->compressed_size.
name|block
operator|->
name|uncompressed_size
operator|=
name|in_size
expr_stmt|;
name|block
operator|->
name|compressed_size
operator|=
name|lzma2_bound
argument_list|(
name|in_size
argument_list|)
expr_stmt|;
if|if
condition|(
name|block
operator|->
name|compressed_size
operator|==
literal|0
condition|)
return|return
name|LZMA_DATA_ERROR
return|;
comment|// Do the actual compression.
name|lzma_ret
name|ret
init|=
name|LZMA_BUF_ERROR
decl_stmt|;
if|if
condition|(
name|try_to_compress
condition|)
name|ret
operator|=
name|block_encode_normal
argument_list|(
name|block
argument_list|,
name|allocator
argument_list|,
name|in
argument_list|,
name|in_size
argument_list|,
name|out
argument_list|,
name|out_pos
argument_list|,
name|out_size
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|!=
name|LZMA_OK
condition|)
block|{
comment|// If the error was something else than output buffer
comment|// becoming full, return the error now.
if|if
condition|(
name|ret
operator|!=
name|LZMA_BUF_ERROR
condition|)
return|return
name|ret
return|;
comment|// The data was uncompressible (at least with the options
comment|// given to us) or the output buffer was too small. Use the
comment|// uncompressed chunks of LZMA2 to wrap the data into a valid
comment|// Block. If we haven't been given enough output space, even
comment|// this may fail.
name|return_if_error
argument_list|(
name|block_encode_uncompressed
argument_list|(
name|block
argument_list|,
name|in
argument_list|,
name|in_size
argument_list|,
name|out
argument_list|,
name|out_pos
argument_list|,
name|out_size
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|assert
argument_list|(
operator|*
name|out_pos
operator|<=
name|out_size
argument_list|)
expr_stmt|;
comment|// Block Padding. No buffer overflow here, because we already adjusted
comment|// out_size so that (out_size - out_start) is a multiple of four.
comment|// Thus, if the buffer is full, the loop body can never run.
for|for
control|(
name|size_t
name|i
init|=
call|(
name|size_t
call|)
argument_list|(
name|block
operator|->
name|compressed_size
argument_list|)
init|;
name|i
operator|&
literal|3
condition|;
operator|++
name|i
control|)
block|{
name|assert
argument_list|(
operator|*
name|out_pos
operator|<
name|out_size
argument_list|)
expr_stmt|;
name|out
index|[
operator|(
operator|*
name|out_pos
operator|)
operator|++
index|]
operator|=
literal|0x00
expr_stmt|;
block|}
comment|// If there's no Check field, we are done now.
if|if
condition|(
name|check_size
operator|>
literal|0
condition|)
block|{
comment|// Calculate the integrity check. We reserved space for
comment|// the Check field earlier so we don't need to check for
comment|// available output space here.
name|lzma_check_state
name|check
decl_stmt|;
name|lzma_check_init
argument_list|(
operator|&
name|check
argument_list|,
name|block
operator|->
name|check
argument_list|)
expr_stmt|;
name|lzma_check_update
argument_list|(
operator|&
name|check
argument_list|,
name|block
operator|->
name|check
argument_list|,
name|in
argument_list|,
name|in_size
argument_list|)
expr_stmt|;
name|lzma_check_finish
argument_list|(
operator|&
name|check
argument_list|,
name|block
operator|->
name|check
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|block
operator|->
name|raw_check
argument_list|,
name|check
operator|.
name|buffer
operator|.
name|u8
argument_list|,
name|check_size
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|out
operator|+
operator|*
name|out_pos
argument_list|,
name|check
operator|.
name|buffer
operator|.
name|u8
argument_list|,
name|check_size
argument_list|)
expr_stmt|;
operator|*
name|out_pos
operator|+=
name|check_size
expr_stmt|;
block|}
return|return
name|LZMA_OK
return|;
block|}
end_function

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_block_buffer_encode
argument_list|(
argument|lzma_block *block
argument_list|,
argument|const lzma_allocator *allocator
argument_list|,
argument|const uint8_t *in
argument_list|,
argument|size_t in_size
argument_list|,
argument|uint8_t *out
argument_list|,
argument|size_t *out_pos
argument_list|,
argument|size_t out_size
argument_list|)
end_macro

begin_block
block|{
return|return
name|block_buffer_encode
argument_list|(
name|block
argument_list|,
name|allocator
argument_list|,
name|in
argument_list|,
name|in_size
argument_list|,
name|out
argument_list|,
name|out_pos
argument_list|,
name|out_size
argument_list|,
name|true
argument_list|)
return|;
block|}
end_block

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_block_uncomp_encode
argument_list|(
argument|lzma_block *block
argument_list|,
argument|const uint8_t *in
argument_list|,
argument|size_t in_size
argument_list|,
argument|uint8_t *out
argument_list|,
argument|size_t *out_pos
argument_list|,
argument|size_t out_size
argument_list|)
end_macro

begin_block
block|{
comment|// It won't allocate any memory from heap so no need
comment|// for lzma_allocator.
return|return
name|block_buffer_encode
argument_list|(
name|block
argument_list|,
name|NULL
argument_list|,
name|in
argument_list|,
name|in_size
argument_list|,
name|out
argument_list|,
name|out_pos
argument_list|,
name|out_size
argument_list|,
name|false
argument_list|)
return|;
block|}
end_block

end_unit

