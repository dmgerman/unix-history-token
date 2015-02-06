begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       block_buffer_encoder.h
end_comment

begin_comment
comment|/// \brief      Single-call .xz Block encoder
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
name|LZMA_BLOCK_BUFFER_ENCODER_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_BLOCK_BUFFER_ENCODER_H
end_define

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_comment
comment|/// uint64_t version of lzma_block_buffer_bound(). It is used by
end_comment

begin_comment
comment|/// stream_encoder_mt.c. Probably the original lzma_block_buffer_bound()
end_comment

begin_comment
comment|/// should have been 64-bit, but fixing it would break the ABI.
end_comment

begin_function_decl
specifier|extern
name|uint64_t
name|lzma_block_buffer_bound64
parameter_list|(
name|uint64_t
name|uncompressed_size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

