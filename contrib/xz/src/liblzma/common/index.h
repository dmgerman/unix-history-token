begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       index.h
end_comment

begin_comment
comment|/// \brief      Handling of Index
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
name|LZMA_INDEX_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_INDEX_H
end_define

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_comment
comment|/// Minimum Unpadded Size
end_comment

begin_define
define|#
directive|define
name|UNPADDED_SIZE_MIN
value|LZMA_VLI_C(5)
end_define

begin_comment
comment|/// Maximum Unpadded Size
end_comment

begin_define
define|#
directive|define
name|UNPADDED_SIZE_MAX
value|(LZMA_VLI_MAX& ~LZMA_VLI_C(3))
end_define

begin_comment
comment|/// Get the size of the Index Padding field. This is needed by Index encoder
end_comment

begin_comment
comment|/// and decoder, but applications should have no use for this.
end_comment

begin_function_decl
specifier|extern
name|uint32_t
name|lzma_index_padding_size
parameter_list|(
specifier|const
name|lzma_index
modifier|*
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Set for how many Records to allocate memory the next time
end_comment

begin_comment
comment|/// lzma_index_append() needs to allocate space for a new Record.
end_comment

begin_comment
comment|/// This is used only by the Index decoder.
end_comment

begin_function_decl
specifier|extern
name|void
name|lzma_index_prealloc
parameter_list|(
name|lzma_index
modifier|*
name|i
parameter_list|,
name|lzma_vli
name|records
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Round the variable-length integer to the next multiple of four.
end_comment

begin_function
specifier|static
specifier|inline
name|lzma_vli
name|vli_ceil4
parameter_list|(
name|lzma_vli
name|vli
parameter_list|)
block|{
name|assert
argument_list|(
name|vli
operator|<=
name|LZMA_VLI_MAX
argument_list|)
expr_stmt|;
return|return
operator|(
name|vli
operator|+
literal|3
operator|)
operator|&
operator|~
name|LZMA_VLI_C
argument_list|(
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Calculate the size of the Index field excluding Index Padding
end_comment

begin_function
specifier|static
specifier|inline
name|lzma_vli
name|index_size_unpadded
parameter_list|(
name|lzma_vli
name|count
parameter_list|,
name|lzma_vli
name|index_list_size
parameter_list|)
block|{
comment|// Index Indicator + Number of Records + List of Records + CRC32
return|return
literal|1
operator|+
name|lzma_vli_size
argument_list|(
name|count
argument_list|)
operator|+
name|index_list_size
operator|+
literal|4
return|;
block|}
end_function

begin_comment
comment|/// Calculate the size of the Index field including Index Padding
end_comment

begin_function
specifier|static
specifier|inline
name|lzma_vli
name|index_size
parameter_list|(
name|lzma_vli
name|count
parameter_list|,
name|lzma_vli
name|index_list_size
parameter_list|)
block|{
return|return
name|vli_ceil4
argument_list|(
name|index_size_unpadded
argument_list|(
name|count
argument_list|,
name|index_list_size
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Calculate the total size of the Stream
end_comment

begin_function
specifier|static
specifier|inline
name|lzma_vli
name|index_stream_size
parameter_list|(
name|lzma_vli
name|blocks_size
parameter_list|,
name|lzma_vli
name|count
parameter_list|,
name|lzma_vli
name|index_list_size
parameter_list|)
block|{
return|return
name|LZMA_STREAM_HEADER_SIZE
operator|+
name|blocks_size
operator|+
name|index_size
argument_list|(
name|count
argument_list|,
name|index_list_size
argument_list|)
operator|+
name|LZMA_STREAM_HEADER_SIZE
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

