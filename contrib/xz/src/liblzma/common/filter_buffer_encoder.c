begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       filter_buffer_encoder.c
end_comment

begin_comment
comment|/// \brief      Single-call raw encoding
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
file|"filter_encoder.h"
end_include

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_raw_buffer_encode
argument_list|(
argument|const lzma_filter *filters
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
comment|// Validate what isn't validated later in filter_common.c.
if|if
condition|(
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
comment|// Initialize the encoder
name|lzma_next_coder
name|next
init|=
name|LZMA_NEXT_CODER_INIT
decl_stmt|;
name|return_if_error
argument_list|(
name|lzma_raw_encoder_init
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
comment|// Store the output position so that we can restore it if
comment|// something goes wrong.
specifier|const
name|size_t
name|out_start
init|=
operator|*
name|out_pos
decl_stmt|;
comment|// Do the actual encoding and free coder's memory.
name|size_t
name|in_pos
init|=
literal|0
decl_stmt|;
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
decl_stmt|;
name|lzma_next_end
argument_list|(
operator|&
name|next
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
comment|// Output buffer was too small.
name|assert
argument_list|(
operator|*
name|out_pos
operator|==
name|out_size
argument_list|)
expr_stmt|;
name|ret
operator|=
name|LZMA_BUF_ERROR
expr_stmt|;
block|}
comment|// Restore the output position.
operator|*
name|out_pos
operator|=
name|out_start
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_block

end_unit

