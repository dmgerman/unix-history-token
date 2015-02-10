begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       lzma_decoder.h
end_comment

begin_comment
comment|/// \brief      LZMA decoder API
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
name|LZMA_LZMA_DECODER_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_LZMA_DECODER_H
end_define

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_comment
comment|/// Allocates and initializes LZMA decoder
end_comment

begin_function_decl
specifier|extern
name|lzma_ret
name|lzma_lzma_decoder_init
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
name|lzma_lzma_decoder_memusage
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
name|lzma_lzma_props_decode
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

begin_comment
comment|/// \brief      Decodes the LZMA Properties byte (lc/lp/pb)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return     true if error occurred, false on success
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
specifier|extern
name|bool
name|lzma_lzma_lclppb_decode
parameter_list|(
name|lzma_options_lzma
modifier|*
name|options
parameter_list|,
name|uint8_t
name|byte
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|LZMA_LZ_DECODER_H
end_ifdef

begin_comment
comment|/// Allocate and setup function pointers only. This is used by LZMA1 and
end_comment

begin_comment
comment|/// LZMA2 decoders.
end_comment

begin_function_decl
specifier|extern
name|lzma_ret
name|lzma_lzma_decoder_create
parameter_list|(
name|lzma_lz_decoder
modifier|*
name|lz
parameter_list|,
specifier|const
name|lzma_allocator
modifier|*
name|allocator
parameter_list|,
specifier|const
name|void
modifier|*
name|opt
parameter_list|,
name|lzma_lz_options
modifier|*
name|lz_options
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Gets memory usage without validating lc/lp/pb. This is used by LZMA2
end_comment

begin_comment
comment|/// decoder, because raw LZMA2 decoding doesn't need lc/lp/pb.
end_comment

begin_function_decl
specifier|extern
name|uint64_t
name|lzma_lzma_decoder_memusage_nocheck
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

