begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       delta_private.h
end_comment

begin_comment
comment|/// \brief      Private common stuff for Delta encoder and decoder
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
name|LZMA_DELTA_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_DELTA_PRIVATE_H
end_define

begin_include
include|#
directive|include
file|"delta_common.h"
end_include

begin_struct
struct|struct
name|lzma_coder_s
block|{
comment|/// Next coder in the chain
name|lzma_next_coder
name|next
decl_stmt|;
comment|/// Delta distance
name|size_t
name|distance
decl_stmt|;
comment|/// Position in history[]
name|uint8_t
name|pos
decl_stmt|;
comment|/// Buffer to hold history of the original data
name|uint8_t
name|history
index|[
name|LZMA_DELTA_DIST_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|lzma_ret
name|lzma_delta_coder_init
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

