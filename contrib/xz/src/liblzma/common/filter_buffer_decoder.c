begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       filter_buffer_decoder.c
end_comment

begin_comment
comment|/// \brief      Single-call raw decoding
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
file|"filter_decoder.h"
end_include

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_raw_buffer_decode
argument_list|(
argument|const lzma_filter *filters
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
comment|// Validate what isn't validated later in filter_common.c.
if|if
condition|(
name|in
operator|==
name|NULL
operator|||
name|in_pos
operator|==
name|NULL
operator|||
operator|*
name|in_pos
operator|>
name|in_size
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
comment|// Initialize the decoer.
name|lzma_next_coder
name|next
init|=
name|LZMA_NEXT_CODER_INIT
decl_stmt|;
name|return_if_error
argument_list|(
name|lzma_raw_decoder_init
argument_list|(
operator|&
name|next
argument_list|,
name|allocator
argument_list|,
name|filters
argument_list|)
argument_list|)
expr_stmt|;
comment|// Store the positions so that we can restore them if something
comment|// goes wrong.
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
comment|// Do the actual decoding and free decoder's memory.
name|lzma_ret
name|ret
init|=
name|next
operator|.
name|code
argument_list|(
name|next
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
decl_stmt|;
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
if|if
condition|(
operator|*
name|in_pos
operator|!=
name|in_size
condition|)
block|{
comment|// Since input wasn't consumed completely,
comment|// the output buffer became full and is
comment|// too small.
name|ret
operator|=
name|LZMA_BUF_ERROR
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|*
name|out_pos
operator|!=
name|out_size
condition|)
block|{
comment|// Since output didn't became full, the input
comment|// has to be truncated.
name|ret
operator|=
name|LZMA_DATA_ERROR
expr_stmt|;
block|}
else|else
block|{
comment|// All the input was consumed and output
comment|// buffer is full. Now we don't immediately
comment|// know the reason for the error. Try
comment|// decoding one more byte. If it succeeds,
comment|// then the output buffer was too small. If
comment|// we cannot get a new output byte, the input
comment|// is truncated.
name|uint8_t
name|tmp
index|[
literal|1
index|]
decl_stmt|;
name|size_t
name|tmp_pos
init|=
literal|0
decl_stmt|;
operator|(
name|void
operator|)
name|next
operator|.
name|code
argument_list|(
name|next
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
name|tmp
argument_list|,
operator|&
name|tmp_pos
argument_list|,
literal|1
argument_list|,
name|LZMA_FINISH
argument_list|)
expr_stmt|;
if|if
condition|(
name|tmp_pos
operator|==
literal|1
condition|)
name|ret
operator|=
name|LZMA_BUF_ERROR
expr_stmt|;
else|else
name|ret
operator|=
name|LZMA_DATA_ERROR
expr_stmt|;
block|}
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
name|lzma_next_end
argument_list|(
operator|&
name|next
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

