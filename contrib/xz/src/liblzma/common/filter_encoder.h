begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       filter_encoder.c
end_comment

begin_comment
comment|/// \brief      Filter ID mapping to filter-specific functions
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
name|LZMA_FILTER_ENCODER_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_FILTER_ENCODER_H
end_define

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_comment
comment|// FIXME: Might become a part of the public API.
end_comment

begin_function_decl
specifier|extern
name|uint64_t
name|lzma_mt_block_size
parameter_list|(
specifier|const
name|lzma_filter
modifier|*
name|filters
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|lzma_ret
name|lzma_raw_encoder_init
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
name|lzma_filter
modifier|*
name|filters
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

