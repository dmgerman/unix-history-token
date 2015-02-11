begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       lzma2_encoder.h
end_comment

begin_comment
comment|/// \brief      LZMA2 encoder
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//  Authors:    Igor Pavlov
end_comment

begin_comment
comment|//              Lasse Collin
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
name|LZMA_LZMA2_ENCODER_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_LZMA2_ENCODER_H
end_define

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_comment
comment|/// Maximum number of bytes of actual data per chunk (no headers)
end_comment

begin_define
define|#
directive|define
name|LZMA2_CHUNK_MAX
value|(UINT32_C(1)<< 16)
end_define

begin_comment
comment|/// Maximum uncompressed size of LZMA chunk (no headers)
end_comment

begin_define
define|#
directive|define
name|LZMA2_UNCOMPRESSED_MAX
value|(UINT32_C(1)<< 21)
end_define

begin_comment
comment|/// Maximum size of LZMA2 headers
end_comment

begin_define
define|#
directive|define
name|LZMA2_HEADER_MAX
value|6
end_define

begin_comment
comment|/// Size of a header for uncompressed chunk
end_comment

begin_define
define|#
directive|define
name|LZMA2_HEADER_UNCOMPRESSED
value|3
end_define

begin_function_decl
specifier|extern
name|lzma_ret
name|lzma_lzma2_encoder_init
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
name|uint64_t
name|lzma_lzma2_encoder_memusage
parameter_list|(
specifier|const
name|void
modifier|*
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|lzma_ret
name|lzma_lzma2_props_encode
parameter_list|(
specifier|const
name|void
modifier|*
name|options
parameter_list|,
name|uint8_t
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|lzma_lzma2_block_size
parameter_list|(
specifier|const
name|void
modifier|*
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

