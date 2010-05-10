begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       subblock_decoder_helper.h
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

begin_ifndef
ifndef|#
directive|ifndef
name|LZMA_SUBBLOCK_DECODER_HELPER_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_SUBBLOCK_DECODER_HELPER_H
end_define

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|bool
name|end_was_reached
decl_stmt|;
block|}
name|lzma_options_subblock_helper
typedef|;
end_typedef

begin_function_decl
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
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

