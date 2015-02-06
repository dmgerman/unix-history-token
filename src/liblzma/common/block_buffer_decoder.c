begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       block_buffer_decoder.c
end_comment

begin_comment
comment|/// \brief      Single-call .xz Block decoder
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
file|"block_decoder.h"
end_include

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_block_buffer_decode
argument_list|(
argument|lzma_block *block
argument_list|,
argument|const lzma_allocator *allocator
argument_list|,
argument|const uint8_t *in
argument_list|,
argument|size_t *in_pos
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
if|if
condition|(
name|in_pos
operator|==
name|NULL
operator|||
operator|(
name|in
operator|==
name|NULL
operator|&&
operator|*
name|in_pos
operator|!=
name|in_size
operator|)
operator|||
operator|*
name|in_pos
operator|>
name|in_size
operator|||
name|out_pos
operator|==
name|NULL
operator|||
operator|(
name|out
operator|==
name|NULL
operator|&&
operator|*
name|out_pos
operator|!=
name|out_size
operator|)
operator|||
operator|*
name|out_pos
operator|>
name|out_size
condition|)
return|return
name|LZMA_PROG_ERROR
return|;
comment|// Initialize the Block decoder.
name|lzma_next_coder
name|block_decoder
init|=
name|LZMA_NEXT_CODER_INIT
decl_stmt|;
name|lzma_ret
name|ret
init|=
name|lzma_block_decoder_init
argument_list|(
operator|&
name|block_decoder
argument_list|,
name|allocator
argument_list|,
name|block
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
operator|==
name|LZMA_OK
condition|)
block|{
comment|// Save the positions so that we can restore them in case
comment|// an error occurs.
specifier|const
name|size_t
name|in_start
init|=
operator|*
name|in_pos
decl_stmt|;
specifier|const
name|size_t
name|out_start
init|=
operator|*
name|out_pos
decl_stmt|;
comment|// Do the actual decoding.
name|ret
operator|=
name|block_decoder
operator|.
name|code
argument_list|(
name|block_decoder
operator|.
name|coder
argument_list|,
name|allocator
argument_list|,
name|in
argument_list|,
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
if|if
condition|(
name|ret
operator|==
name|LZMA_STREAM_END
condition|)
block|{
name|ret
operator|=
name|LZMA_OK
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|ret
operator|==
name|LZMA_OK
condition|)
block|{
comment|// Either the input was truncated or the
comment|// output buffer was too small.
name|assert
argument_list|(
operator|*
name|in_pos
operator|==
name|in_size
operator|||
operator|*
name|out_pos
operator|==
name|out_size
argument_list|)
expr_stmt|;
comment|// If all the input was consumed, then the
comment|// input is truncated, even if the output
comment|// buffer is also full. This is because
comment|// processing the last byte of the Block
comment|// never produces output.
comment|//
comment|// NOTE: This assumption may break when new
comment|// filters are added, if the end marker of
comment|// the filter doesn't consume at least one
comment|// complete byte.
if|if
condition|(
operator|*
name|in_pos
operator|==
name|in_size
condition|)
name|ret
operator|=
name|LZMA_DATA_ERROR
expr_stmt|;
else|else
name|ret
operator|=
name|LZMA_BUF_ERROR
expr_stmt|;
block|}
comment|// Restore the positions.
operator|*
name|in_pos
operator|=
name|in_start
expr_stmt|;
operator|*
name|out_pos
operator|=
name|out_start
expr_stmt|;
block|}
block|}
comment|// Free the decoder memory. This needs to be done even if
comment|// initialization fails, because the internal API doesn't
comment|// require the initialization function to free its memory on error.
name|lzma_next_end
argument_list|(
operator|&
name|block_decoder
argument_list|,
name|allocator
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_block

end_unit

