begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       block_encoder.h
end_comment

begin_comment
comment|/// \brief      Encodes .xz Blocks
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
name|LZMA_BLOCK_ENCODER_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_BLOCK_ENCODER_H
end_define

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_comment
comment|/// \brief      Biggest Compressed Size value that the Block encoder supports
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The maximum size of a single Block is limited by the maximum size of
end_comment

begin_comment
comment|/// a Stream, which in theory is 2^63 - 3 bytes (i.e. LZMA_VLI_MAX - 3).
end_comment

begin_comment
comment|/// While the size is really big and no one should hit it in practice, we
end_comment

begin_comment
comment|/// take it into account in some places anyway to catch some errors e.g. if
end_comment

begin_comment
comment|/// application passes insanely big value to some function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// We could take into account the headers etc. to determine the exact
end_comment

begin_comment
comment|/// maximum size of the Compressed Data field, but the complexity would give
end_comment

begin_comment
comment|/// us nothing useful. Instead, limit the size of Compressed Data so that
end_comment

begin_comment
comment|/// even with biggest possible Block Header and Check fields the total
end_comment

begin_comment
comment|/// encoded size of the Block stays as a valid VLI. This doesn't guarantee
end_comment

begin_comment
comment|/// that the size of the Stream doesn't grow too big, but that problem is
end_comment

begin_comment
comment|/// taken care outside the Block handling code.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// ~LZMA_VLI_C(3) is to guarantee that if we need padding at the end of
end_comment

begin_comment
comment|/// the Compressed Data field, it will still stay in the proper limit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This constant is in this file because it is needed in both
end_comment

begin_comment
comment|/// block_encoder.c and block_buffer_encoder.c.
end_comment

begin_define
define|#
directive|define
name|COMPRESSED_SIZE_MAX
value|((LZMA_VLI_MAX - LZMA_BLOCK_HEADER_SIZE_MAX \ 		- LZMA_CHECK_SIZE_MAX)& ~LZMA_VLI_C(3))
end_define

begin_function_decl
specifier|extern
name|lzma_ret
name|lzma_block_encoder_init
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
name|lzma_block
modifier|*
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

