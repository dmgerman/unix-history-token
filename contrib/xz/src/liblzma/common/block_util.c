begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       block_header.c
end_comment

begin_comment
comment|/// \brief      Utility functions to handle lzma_block
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

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_include
include|#
directive|include
file|"index.h"
end_include

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_block_compressed_size
argument_list|(
argument|lzma_block *block
argument_list|,
argument|lzma_vli unpadded_size
argument_list|)
end_macro

begin_block
block|{
comment|// Validate everything but Uncompressed Size and filters.
if|if
condition|(
name|lzma_block_unpadded_size
argument_list|(
name|block
argument_list|)
operator|==
literal|0
condition|)
return|return
name|LZMA_PROG_ERROR
return|;
specifier|const
name|uint32_t
name|container_size
init|=
name|block
operator|->
name|header_size
operator|+
name|lzma_check_size
argument_list|(
name|block
operator|->
name|check
argument_list|)
decl_stmt|;
comment|// Validate that Compressed Size will be greater than zero.
if|if
condition|(
name|unpadded_size
operator|<=
name|container_size
condition|)
return|return
name|LZMA_DATA_ERROR
return|;
comment|// Calculate what Compressed Size is supposed to be.
comment|// If Compressed Size was present in Block Header,
comment|// compare that the new value matches it.
specifier|const
name|lzma_vli
name|compressed_size
init|=
name|unpadded_size
operator|-
name|container_size
decl_stmt|;
if|if
condition|(
name|block
operator|->
name|compressed_size
operator|!=
name|LZMA_VLI_UNKNOWN
operator|&&
name|block
operator|->
name|compressed_size
operator|!=
name|compressed_size
condition|)
return|return
name|LZMA_DATA_ERROR
return|;
name|block
operator|->
name|compressed_size
operator|=
name|compressed_size
expr_stmt|;
return|return
name|LZMA_OK
return|;
block|}
end_block

begin_extern
extern|extern LZMA_API(lzma_vli
end_extern

begin_macro
unit|)
name|lzma_block_unpadded_size
argument_list|(
argument|const lzma_block *block
argument_list|)
end_macro

begin_block
block|{
comment|// Validate the values that we are interested in i.e. all but
comment|// Uncompressed Size and the filters.
comment|//
comment|// NOTE: This function is used for validation too, so it is
comment|// essential that these checks are always done even if
comment|// Compressed Size is unknown.
if|if
condition|(
name|block
operator|==
name|NULL
operator|||
name|block
operator|->
name|version
operator|>
literal|1
operator|||
name|block
operator|->
name|header_size
operator|<
name|LZMA_BLOCK_HEADER_SIZE_MIN
operator|||
name|block
operator|->
name|header_size
operator|>
name|LZMA_BLOCK_HEADER_SIZE_MAX
operator|||
operator|(
name|block
operator|->
name|header_size
operator|&
literal|3
operator|)
operator|||
operator|!
name|lzma_vli_is_valid
argument_list|(
name|block
operator|->
name|compressed_size
argument_list|)
operator|||
name|block
operator|->
name|compressed_size
operator|==
literal|0
operator|||
call|(
name|unsigned
name|int
call|)
argument_list|(
name|block
operator|->
name|check
argument_list|)
operator|>
name|LZMA_CHECK_ID_MAX
condition|)
return|return
literal|0
return|;
comment|// If Compressed Size is unknown, return that we cannot know
comment|// size of the Block either.
if|if
condition|(
name|block
operator|->
name|compressed_size
operator|==
name|LZMA_VLI_UNKNOWN
condition|)
return|return
name|LZMA_VLI_UNKNOWN
return|;
comment|// Calculate Unpadded Size and validate it.
specifier|const
name|lzma_vli
name|unpadded_size
init|=
name|block
operator|->
name|compressed_size
operator|+
name|block
operator|->
name|header_size
operator|+
name|lzma_check_size
argument_list|(
name|block
operator|->
name|check
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|unpadded_size
operator|>=
name|UNPADDED_SIZE_MIN
argument_list|)
expr_stmt|;
if|if
condition|(
name|unpadded_size
operator|>
name|UNPADDED_SIZE_MAX
condition|)
return|return
literal|0
return|;
return|return
name|unpadded_size
return|;
block|}
end_block

begin_extern
extern|extern LZMA_API(lzma_vli
end_extern

begin_macro
unit|)
name|lzma_block_total_size
argument_list|(
argument|const lzma_block *block
argument_list|)
end_macro

begin_block
block|{
name|lzma_vli
name|unpadded_size
init|=
name|lzma_block_unpadded_size
argument_list|(
name|block
argument_list|)
decl_stmt|;
if|if
condition|(
name|unpadded_size
operator|!=
name|LZMA_VLI_UNKNOWN
condition|)
name|unpadded_size
operator|=
name|vli_ceil4
argument_list|(
name|unpadded_size
argument_list|)
expr_stmt|;
return|return
name|unpadded_size
return|;
block|}
end_block

end_unit

