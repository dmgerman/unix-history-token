begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       delta_decoder.h
end_comment

begin_comment
comment|/// \brief      Delta filter decoder
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
name|LZMA_DELTA_DECODER_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_DELTA_DECODER_H
end_define

begin_include
include|#
directive|include
file|"delta_common.h"
end_include

begin_function_decl
specifier|extern
name|lzma_ret
name|lzma_delta_decoder_init
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|lzma_ret
name|lzma_delta_props_decode
parameter_list|(
name|void
modifier|*
modifier|*
name|options
parameter_list|,
specifier|const
name|lzma_allocator
modifier|*
name|allocator
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|props
parameter_list|,
name|size_t
name|props_size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

