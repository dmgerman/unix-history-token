begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       filter_flags_decoder.c
end_comment

begin_comment
comment|/// \brief      Decodes a Filter Flags field
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
file|"filter_decoder.h"
end_include

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_filter_flags_decode
argument_list|(
argument|lzma_filter *filter
argument_list|,
argument|const lzma_allocator *allocator
argument_list|,
argument|const uint8_t *in
argument_list|,
argument|size_t *in_pos
argument_list|,
argument|size_t in_size
argument_list|)
end_macro

begin_block
block|{
comment|// Set the pointer to NULL so the caller can always safely free it.
name|filter
operator|->
name|options
operator|=
name|NULL
expr_stmt|;
comment|// Filter ID
name|return_if_error
argument_list|(
name|lzma_vli_decode
argument_list|(
operator|&
name|filter
operator|->
name|id
argument_list|,
name|NULL
argument_list|,
name|in
argument_list|,
name|in_pos
argument_list|,
name|in_size
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|filter
operator|->
name|id
operator|>=
name|LZMA_FILTER_RESERVED_START
condition|)
return|return
name|LZMA_DATA_ERROR
return|;
comment|// Size of Properties
name|lzma_vli
name|props_size
decl_stmt|;
name|return_if_error
argument_list|(
name|lzma_vli_decode
argument_list|(
operator|&
name|props_size
argument_list|,
name|NULL
argument_list|,
name|in
argument_list|,
name|in_pos
argument_list|,
name|in_size
argument_list|)
argument_list|)
expr_stmt|;
comment|// Filter Properties
if|if
condition|(
name|in_size
operator|-
operator|*
name|in_pos
operator|<
name|props_size
condition|)
return|return
name|LZMA_DATA_ERROR
return|;
specifier|const
name|lzma_ret
name|ret
init|=
name|lzma_properties_decode
argument_list|(
name|filter
argument_list|,
name|allocator
argument_list|,
name|in
operator|+
operator|*
name|in_pos
argument_list|,
name|props_size
argument_list|)
decl_stmt|;
operator|*
name|in_pos
operator|+=
name|props_size
expr_stmt|;
return|return
name|ret
return|;
block|}
end_block

end_unit

