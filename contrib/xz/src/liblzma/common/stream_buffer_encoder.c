begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       stream_buffer_encoder.c
end_comment

begin_comment
comment|/// \brief      Single-call .xz Stream encoder
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
file|"index.h"
end_include

begin_comment
comment|/// Maximum size of Index that has exactly one Record.
end_comment

begin_comment
comment|/// Index Indicator + Number of Records + Record + CRC32 rounded up to
end_comment

begin_comment
comment|/// the next multiple of four.
end_comment

begin_define
define|#
directive|define
name|INDEX_BOUND
value|((1 + 1 + 2 * LZMA_VLI_BYTES_MAX + 4 + 3)& ~3)
end_define

begin_comment
comment|/// Stream Header, Stream Footer, and Index
end_comment

begin_define
define|#
directive|define
name|HEADERS_BOUND
value|(2 * LZMA_STREAM_HEADER_SIZE + INDEX_BOUND)
end_define

begin_extern
extern|extern LZMA_API(size_t
end_extern

begin_macro
unit|)
name|lzma_stream_buffer_bound
argument_list|(
argument|size_t uncompressed_size
argument_list|)
end_macro

begin_block
block|{
comment|// Get the maximum possible size of a Block.
specifier|const
name|size_t
name|block_bound
init|=
name|lzma_block_buffer_bound
argument_list|(
name|uncompressed_size
argument_list|)
decl_stmt|;
if|if
condition|(
name|block_bound
operator|==
literal|0
condition|)
return|return
literal|0
return|;
comment|// Catch the possible integer overflow and also prevent the size of
comment|// the Stream exceeding LZMA_VLI_MAX (theoretically possible on
comment|// 64-bit systems).
if|if
condition|(
name|my_min
argument_list|(
name|SIZE_MAX
argument_list|,
name|LZMA_VLI_MAX
argument_list|)
operator|-
name|block_bound
operator|<
name|HEADERS_BOUND
condition|)
return|return
literal|0
return|;
return|return
name|block_bound
operator|+
name|HEADERS_BOUND
return|;
block|}
end_block

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_stream_buffer_encode
argument_list|(
argument|lzma_filter *filters
argument_list|,
argument|lzma_check check
argument_list|,
argument|const lzma_allocator *allocator
argument_list|,
argument|const uint8_t *in
argument_list|,
argument|size_t in_size
argument_list|,
argument|uint8_t *out
argument_list|,
argument|size_t *out_pos_ptr
argument_list|,
argument|size_t out_size
argument_list|)
end_macro

begin_block
block|{
comment|// Sanity checks
if|if
condition|(
name|filters
operator|==
name|NULL
operator|||
call|(
name|unsigned
name|int
call|)
argument_list|(
name|check
argument_list|)
operator|>
name|LZMA_CHECK_ID_MAX
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
name|out_pos_ptr
operator|==
name|NULL
operator|||
operator|*
name|out_pos_ptr
operator|>
name|out_size
condition|)
return|return
name|LZMA_PROG_ERROR
return|;
if|if
condition|(
operator|!
name|lzma_check_is_supported
argument_list|(
name|check
argument_list|)
condition|)
return|return
name|LZMA_UNSUPPORTED_CHECK
return|;
comment|// Note for the paranoids: Index encoder prevents the Stream from
comment|// getting too big and still being accepted with LZMA_OK, and Block
comment|// encoder catches if the input is too big. So we don't need to
comment|// separately check if the buffers are too big.
comment|// Use a local copy. We update *out_pos_ptr only if everything
comment|// succeeds.
name|size_t
name|out_pos
init|=
operator|*
name|out_pos_ptr
decl_stmt|;
comment|// Check that there's enough space for both Stream Header and
comment|// Stream Footer.
if|if
condition|(
name|out_size
operator|-
name|out_pos
operator|<=
literal|2
operator|*
name|LZMA_STREAM_HEADER_SIZE
condition|)
return|return
name|LZMA_BUF_ERROR
return|;
comment|// Reserve space for Stream Footer so we don't need to check for
comment|// available space again before encoding Stream Footer.
name|out_size
operator|-=
name|LZMA_STREAM_HEADER_SIZE
expr_stmt|;
comment|// Encode the Stream Header.
name|lzma_stream_flags
name|stream_flags
init|=
block|{
operator|.
name|version
operator|=
literal|0
block|,
operator|.
name|check
operator|=
name|check
block|, 	}
decl_stmt|;
if|if
condition|(
name|lzma_stream_header_encode
argument_list|(
operator|&
name|stream_flags
argument_list|,
name|out
operator|+
name|out_pos
argument_list|)
operator|!=
name|LZMA_OK
condition|)
return|return
name|LZMA_PROG_ERROR
return|;
name|out_pos
operator|+=
name|LZMA_STREAM_HEADER_SIZE
expr_stmt|;
comment|// Encode a Block but only if there is at least one byte of input.
name|lzma_block
name|block
init|=
block|{
operator|.
name|version
operator|=
literal|0
block|,
operator|.
name|check
operator|=
name|check
block|,
operator|.
name|filters
operator|=
name|filters
block|, 	}
decl_stmt|;
if|if
condition|(
name|in_size
operator|>
literal|0
condition|)
name|return_if_error
argument_list|(
name|lzma_block_buffer_encode
argument_list|(
operator|&
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
operator|&
name|out_pos
argument_list|,
name|out_size
argument_list|)
argument_list|)
expr_stmt|;
comment|// Index
block|{
comment|// Create an Index. It will have one Record if there was
comment|// at least one byte of input to encode. Otherwise the
comment|// Index will be empty.
name|lzma_index
modifier|*
name|i
init|=
name|lzma_index_init
argument_list|(
name|allocator
argument_list|)
decl_stmt|;
if|if
condition|(
name|i
operator|==
name|NULL
condition|)
return|return
name|LZMA_MEM_ERROR
return|;
name|lzma_ret
name|ret
init|=
name|LZMA_OK
decl_stmt|;
if|if
condition|(
name|in_size
operator|>
literal|0
condition|)
name|ret
operator|=
name|lzma_index_append
argument_list|(
name|i
argument_list|,
name|allocator
argument_list|,
name|lzma_block_unpadded_size
argument_list|(
operator|&
name|block
argument_list|)
argument_list|,
name|block
operator|.
name|uncompressed_size
argument_list|)
expr_stmt|;
comment|// If adding the Record was successful, encode the Index
comment|// and get its size which will be stored into Stream Footer.
if|if
condition|(
name|ret
operator|==
name|LZMA_OK
condition|)
block|{
name|ret
operator|=
name|lzma_index_buffer_encode
argument_list|(
name|i
argument_list|,
name|out
argument_list|,
operator|&
name|out_pos
argument_list|,
name|out_size
argument_list|)
expr_stmt|;
name|stream_flags
operator|.
name|backward_size
operator|=
name|lzma_index_size
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
name|lzma_index_end
argument_list|(
name|i
argument_list|,
name|allocator
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|!=
name|LZMA_OK
condition|)
return|return
name|ret
return|;
block|}
comment|// Stream Footer. We have already reserved space for this.
if|if
condition|(
name|lzma_stream_footer_encode
argument_list|(
operator|&
name|stream_flags
argument_list|,
name|out
operator|+
name|out_pos
argument_list|)
operator|!=
name|LZMA_OK
condition|)
return|return
name|LZMA_PROG_ERROR
return|;
name|out_pos
operator|+=
name|LZMA_STREAM_HEADER_SIZE
expr_stmt|;
comment|// Everything went fine, make the new output position available
comment|// to the application.
operator|*
name|out_pos_ptr
operator|=
name|out_pos
expr_stmt|;
return|return
name|LZMA_OK
return|;
block|}
end_block

end_unit

