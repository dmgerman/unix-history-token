begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       easy_buffer_encoder.c
end_comment

begin_comment
comment|/// \brief      Easy single-call .xz Stream encoder
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
file|"easy_preset.h"
end_include

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_easy_buffer_encode
argument_list|(
argument|uint32_t preset
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
argument|size_t *out_pos
argument_list|,
argument|size_t out_size
argument_list|)
end_macro

begin_block
block|{
name|lzma_options_easy
name|opt_easy
decl_stmt|;
if|if
condition|(
name|lzma_easy_preset
argument_list|(
operator|&
name|opt_easy
argument_list|,
name|preset
argument_list|)
condition|)
return|return
name|LZMA_OPTIONS_ERROR
return|;
return|return
name|lzma_stream_buffer_encode
argument_list|(
name|opt_easy
operator|.
name|filters
argument_list|,
name|check
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
return|;
block|}
end_block

end_unit

