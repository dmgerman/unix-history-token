begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       alone_decoder.h
end_comment

begin_comment
comment|/// \brief      Decoder for LZMA_Alone files
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
name|LZMA_ALONE_DECODER_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_ALONE_DECODER_H
end_define

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_function_decl
specifier|extern
name|lzma_ret
name|lzma_alone_decoder_init
parameter_list|(
name|lzma_next_coder
modifier|*
name|next
parameter_list|,
name|lzma_allocator
modifier|*
name|allocator
parameter_list|,
name|uint64_t
name|memlimit
parameter_list|,
name|bool
name|picky
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

