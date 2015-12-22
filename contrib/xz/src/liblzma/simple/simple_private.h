begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       simple_private.h
end_comment

begin_comment
comment|/// \brief      Private definitions for so called simple filters
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

begin_ifndef
ifndef|#
directive|ifndef
name|LZMA_SIMPLE_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_SIMPLE_PRIVATE_H
end_define

begin_include
include|#
directive|include
file|"simple_coder.h"
end_include

begin_typedef
typedef|typedef
name|struct
name|lzma_simple_s
name|lzma_simple
typedef|;
end_typedef

begin_struct
struct|struct
name|lzma_coder_s
block|{
comment|/// Next filter in the chain
name|lzma_next_coder
name|next
decl_stmt|;
comment|/// True if the next coder in the chain has returned LZMA_STREAM_END.
name|bool
name|end_was_reached
decl_stmt|;
comment|/// True if filter() should encode the data; false to decode.
comment|/// Currently all simple filters use the same function for encoding
comment|/// and decoding, because the difference between encoders and decoders
comment|/// is very small.
name|bool
name|is_encoder
decl_stmt|;
comment|/// Pointer to filter-specific function, which does
comment|/// the actual filtering.
name|size_t
function_decl|(
modifier|*
name|filter
function_decl|)
parameter_list|(
name|lzma_simple
modifier|*
name|simple
parameter_list|,
name|uint32_t
name|now_pos
parameter_list|,
name|bool
name|is_encoder
parameter_list|,
name|uint8_t
modifier|*
name|buffer
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
comment|/// Pointer to filter-specific data, or NULL if filter doesn't need
comment|/// any extra data.
name|lzma_simple
modifier|*
name|simple
decl_stmt|;
comment|/// The lowest 32 bits of the current position in the data. Most
comment|/// filters need this to do conversions between absolute and relative
comment|/// addresses.
name|uint32_t
name|now_pos
decl_stmt|;
comment|/// Size of the memory allocated for the buffer.
name|size_t
name|allocated
decl_stmt|;
comment|/// Flushing position in the temporary buffer. buffer[pos] is the
comment|/// next byte to be copied to out[].
name|size_t
name|pos
decl_stmt|;
comment|/// buffer[filtered] is the first unfiltered byte. When pos is smaller
comment|/// than filtered, there is unflushed filtered data in the buffer.
name|size_t
name|filtered
decl_stmt|;
comment|/// Total number of bytes (both filtered and unfiltered) currently
comment|/// in the temporary buffer.
name|size_t
name|size
decl_stmt|;
comment|/// Temporary buffer
name|uint8_t
name|buffer
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|lzma_ret
name|lzma_simple_coder_init
parameter_list|(
name|lzma_next_coder
modifier|*
name|next
parameter_list|,
specifier|const
name|lzma_allocator
modifier|*
name|allocator
parameter_list|,
specifier|const
name|lzma_filter_info
modifier|*
name|filters
parameter_list|,
name|size_t
function_decl|(
modifier|*
name|filter
function_decl|)
parameter_list|(
name|lzma_simple
modifier|*
name|simple
parameter_list|,
name|uint32_t
name|now_pos
parameter_list|,
name|bool
name|is_encoder
parameter_list|,
name|uint8_t
modifier|*
name|buffer
parameter_list|,
name|size_t
name|size
parameter_list|)
parameter_list|,
name|size_t
name|simple_size
parameter_list|,
name|size_t
name|unfiltered_max
parameter_list|,
name|uint32_t
name|alignment
parameter_list|,
name|bool
name|is_encoder
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

