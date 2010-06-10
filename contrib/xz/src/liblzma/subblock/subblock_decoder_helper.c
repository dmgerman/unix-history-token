begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       subblock_decoder_helper.c
end_comment

begin_comment
comment|/// \brief      Helper filter for the Subblock decoder
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This filter is used to indicate End of Input for subfilters needing it.
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
file|"subblock_decoder_helper.h"
end_include

begin_struct
struct|struct
name|lzma_coder_s
block|{
specifier|const
name|lzma_options_subblock_helper
modifier|*
name|options
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|lzma_ret
name|helper_decode
argument_list|(
name|lzma_coder
operator|*
name|coder
argument_list|,
name|lzma_allocator
operator|*
name|allocator
name|lzma_attribute
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
argument_list|,
specifier|const
name|uint8_t
operator|*
specifier|restrict
name|in
argument_list|,
name|size_t
operator|*
specifier|restrict
name|in_pos
argument_list|,
name|size_t
name|in_size
argument_list|,
name|uint8_t
operator|*
specifier|restrict
name|out
argument_list|,
name|size_t
operator|*
specifier|restrict
name|out_pos
argument_list|,
name|size_t
name|out_size
argument_list|,
name|lzma_action
name|action
name|lzma_attribute
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
argument_list|)
block|{
comment|// If end_was_reached is true, we cannot have any input.
name|assert
argument_list|(
operator|!
name|coder
operator|->
name|options
operator|->
name|end_was_reached
operator|||
operator|*
name|in_pos
operator|==
name|in_size
argument_list|)
expr_stmt|;
comment|// We can safely copy as much as possible, because we are never
comment|// given more data than a single Subblock Data field.
name|lzma_bufcpy
argument_list|(
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
argument_list|)
expr_stmt|;
comment|// Return LZMA_STREAM_END when instructed so by the Subblock decoder.
return|return
name|coder
operator|->
name|options
operator|->
name|end_was_reached
condition|?
name|LZMA_STREAM_END
else|:
name|LZMA_OK
return|;
block|}
end_decl_stmt

begin_function
specifier|static
name|void
name|helper_end
parameter_list|(
name|lzma_coder
modifier|*
name|coder
parameter_list|,
name|lzma_allocator
modifier|*
name|allocator
parameter_list|)
block|{
name|lzma_free
argument_list|(
name|coder
argument_list|,
name|allocator
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|extern
name|lzma_ret
name|lzma_subblock_decoder_helper_init
parameter_list|(
name|lzma_next_coder
modifier|*
name|next
parameter_list|,
name|lzma_allocator
modifier|*
name|allocator
parameter_list|,
specifier|const
name|lzma_filter_info
modifier|*
name|filters
parameter_list|)
block|{
comment|// This is always the last filter in the chain.
name|assert
argument_list|(
name|filters
index|[
literal|1
index|]
operator|.
name|init
operator|==
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|next
operator|->
name|coder
operator|==
name|NULL
condition|)
block|{
name|next
operator|->
name|coder
operator|=
name|lzma_alloc
argument_list|(
sizeof|sizeof
argument_list|(
name|lzma_coder
argument_list|)
argument_list|,
name|allocator
argument_list|)
expr_stmt|;
if|if
condition|(
name|next
operator|->
name|coder
operator|==
name|NULL
condition|)
return|return
name|LZMA_MEM_ERROR
return|;
name|next
operator|->
name|code
operator|=
operator|&
name|helper_decode
expr_stmt|;
name|next
operator|->
name|end
operator|=
operator|&
name|helper_end
expr_stmt|;
block|}
name|next
operator|->
name|coder
operator|->
name|options
operator|=
name|filters
index|[
literal|0
index|]
operator|.
name|options
expr_stmt|;
return|return
name|LZMA_OK
return|;
block|}
end_function

end_unit

