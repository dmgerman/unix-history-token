begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       filter_common.c
end_comment

begin_comment
comment|/// \brief      Filter-specific stuff common for both encoder and decoder
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
name|LZMA_FILTER_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_FILTER_COMMON_H
end_define

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_comment
comment|/// Both lzma_filter_encoder and lzma_filter_decoder begin with these members.
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/// Filter ID
name|lzma_vli
name|id
decl_stmt|;
comment|/// Initializes the filter encoder and calls lzma_next_filter_init()
comment|/// for filters + 1.
name|lzma_init_function
name|init
decl_stmt|;
comment|/// Calculates memory usage of the encoder. If the options are
comment|/// invalid, UINT64_MAX is returned.
name|uint64_t
function_decl|(
modifier|*
name|memusage
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
name|options
parameter_list|)
function_decl|;
block|}
name|lzma_filter_coder
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|lzma_filter_coder
modifier|*
function_decl|(
modifier|*
name|lzma_filter_find
function_decl|)
parameter_list|(
name|lzma_vli
name|id
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|lzma_ret
name|lzma_raw_coder_init
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
parameter_list|,
name|lzma_filter_find
name|coder_find
parameter_list|,
name|bool
name|is_encoder
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|lzma_raw_coder_memusage
parameter_list|(
name|lzma_filter_find
name|coder_find
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

