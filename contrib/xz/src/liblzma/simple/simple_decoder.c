begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       simple_decoder.c
end_comment

begin_comment
comment|/// \brief      Properties decoder for simple filters
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
file|"simple_decoder.h"
end_include

begin_function
specifier|extern
name|lzma_ret
name|lzma_simple_props_decode
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
block|{
if|if
condition|(
name|props_size
operator|==
literal|0
condition|)
return|return
name|LZMA_OK
return|;
if|if
condition|(
name|props_size
operator|!=
literal|4
condition|)
return|return
name|LZMA_OPTIONS_ERROR
return|;
name|lzma_options_bcj
modifier|*
name|opt
init|=
name|lzma_alloc
argument_list|(
sizeof|sizeof
argument_list|(
name|lzma_options_bcj
argument_list|)
argument_list|,
name|allocator
argument_list|)
decl_stmt|;
if|if
condition|(
name|opt
operator|==
name|NULL
condition|)
return|return
name|LZMA_MEM_ERROR
return|;
name|opt
operator|->
name|start_offset
operator|=
name|unaligned_read32le
argument_list|(
name|props
argument_list|)
expr_stmt|;
comment|// Don't leave an options structure allocated if start_offset is zero.
if|if
condition|(
name|opt
operator|->
name|start_offset
operator|==
literal|0
condition|)
name|lzma_free
argument_list|(
name|opt
argument_list|,
name|allocator
argument_list|)
expr_stmt|;
else|else
operator|*
name|options
operator|=
name|opt
expr_stmt|;
return|return
name|LZMA_OK
return|;
block|}
end_function

end_unit

