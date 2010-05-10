begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       filter_flags_encoder.c
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
file|"filter_encoder.h"
end_include

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_filter_flags_size
argument_list|(
argument|uint32_t *size
argument_list|,
argument|const lzma_filter *filter
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|filter
operator|->
name|id
operator|>=
name|LZMA_FILTER_RESERVED_START
condition|)
return|return
name|LZMA_PROG_ERROR
return|;
name|return_if_error
argument_list|(
name|lzma_properties_size
argument_list|(
name|size
argument_list|,
name|filter
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|size
operator|+=
name|lzma_vli_size
argument_list|(
name|filter
operator|->
name|id
argument_list|)
operator|+
name|lzma_vli_size
argument_list|(
operator|*
name|size
argument_list|)
expr_stmt|;
return|return
name|LZMA_OK
return|;
block|}
end_block

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_filter_flags_encode
argument_list|(
argument|const lzma_filter *filter
argument_list|,
argument|uint8_t *out
argument_list|,
argument|size_t *out_pos
argument_list|,
argument|size_t out_size
argument_list|)
end_macro

begin_block
block|{
comment|// Filter ID
if|if
condition|(
name|filter
operator|->
name|id
operator|>=
name|LZMA_FILTER_RESERVED_START
condition|)
return|return
name|LZMA_PROG_ERROR
return|;
name|return_if_error
argument_list|(
name|lzma_vli_encode
argument_list|(
name|filter
operator|->
name|id
argument_list|,
name|NULL
argument_list|,
name|out
argument_list|,
name|out_pos
argument_list|,
name|out_size
argument_list|)
argument_list|)
expr_stmt|;
comment|// Size of Properties
name|uint32_t
name|props_size
decl_stmt|;
name|return_if_error
argument_list|(
name|lzma_properties_size
argument_list|(
operator|&
name|props_size
argument_list|,
name|filter
argument_list|)
argument_list|)
expr_stmt|;
name|return_if_error
argument_list|(
name|lzma_vli_encode
argument_list|(
name|props_size
argument_list|,
name|NULL
argument_list|,
name|out
argument_list|,
name|out_pos
argument_list|,
name|out_size
argument_list|)
argument_list|)
expr_stmt|;
comment|// Filter Properties
if|if
condition|(
name|out_size
operator|-
operator|*
name|out_pos
operator|<
name|props_size
condition|)
return|return
name|LZMA_PROG_ERROR
return|;
name|return_if_error
argument_list|(
name|lzma_properties_encode
argument_list|(
name|filter
argument_list|,
name|out
operator|+
operator|*
name|out_pos
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|out_pos
operator|+=
name|props_size
expr_stmt|;
return|return
name|LZMA_OK
return|;
block|}
end_block

end_unit

