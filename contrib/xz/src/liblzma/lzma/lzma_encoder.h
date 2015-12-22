begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       lzma_encoder.h
end_comment

begin_comment
comment|/// \brief      LZMA encoder API
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
name|LZMA_LZMA_ENCODER_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_LZMA_ENCODER_H
end_define

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_function_decl
specifier|extern
name|lzma_ret
name|lzma_lzma_encoder_init
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
name|lzma_lzma_encoder_memusage
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
name|lzma_lzma_props_encode
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

begin_comment
comment|/// Encodes lc/lp/pb into one byte. Returns false on success and true on error.
end_comment

begin_function_decl
specifier|extern
name|bool
name|lzma_lzma_lclppb_encode
parameter_list|(
specifier|const
name|lzma_options_lzma
modifier|*
name|options
parameter_list|,
name|uint8_t
modifier|*
name|byte
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|LZMA_LZ_ENCODER_H
end_ifdef

begin_comment
comment|/// Initializes raw LZMA encoder; this is used by LZMA2.
end_comment

begin_function_decl
specifier|extern
name|lzma_ret
name|lzma_lzma_encoder_create
parameter_list|(
name|lzma_coder
modifier|*
modifier|*
name|coder_ptr
parameter_list|,
specifier|const
name|lzma_allocator
modifier|*
name|allocator
parameter_list|,
specifier|const
name|lzma_options_lzma
modifier|*
name|options
parameter_list|,
name|lzma_lz_options
modifier|*
name|lz_options
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Resets an already initialized LZMA encoder; this is used by LZMA2.
end_comment

begin_function_decl
specifier|extern
name|lzma_ret
name|lzma_lzma_encoder_reset
parameter_list|(
name|lzma_coder
modifier|*
name|coder
parameter_list|,
specifier|const
name|lzma_options_lzma
modifier|*
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|lzma_ret
name|lzma_lzma_encode
parameter_list|(
name|lzma_coder
modifier|*
specifier|restrict
name|coder
parameter_list|,
name|lzma_mf
modifier|*
specifier|restrict
name|mf
parameter_list|,
name|uint8_t
modifier|*
specifier|restrict
name|out
parameter_list|,
name|size_t
modifier|*
specifier|restrict
name|out_pos
parameter_list|,
name|size_t
name|out_size
parameter_list|,
name|uint32_t
name|read_limit
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

