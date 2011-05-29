begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       simple_encoder.c
end_comment

begin_comment
comment|/// \brief      Properties encoder for simple filters
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
file|"simple_encoder.h"
end_include

begin_function
specifier|extern
name|lzma_ret
name|lzma_simple_props_size
parameter_list|(
name|uint32_t
modifier|*
name|size
parameter_list|,
specifier|const
name|void
modifier|*
name|options
parameter_list|)
block|{
specifier|const
name|lzma_options_bcj
modifier|*
specifier|const
name|opt
init|=
name|options
decl_stmt|;
operator|*
name|size
operator|=
operator|(
name|opt
operator|==
name|NULL
operator|||
name|opt
operator|->
name|start_offset
operator|==
literal|0
operator|)
condition|?
literal|0
else|:
literal|4
expr_stmt|;
return|return
name|LZMA_OK
return|;
block|}
end_function

begin_function
specifier|extern
name|lzma_ret
name|lzma_simple_props_encode
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
block|{
specifier|const
name|lzma_options_bcj
modifier|*
specifier|const
name|opt
init|=
name|options
decl_stmt|;
comment|// The default start offset is zero, so we don't need to store any
comment|// options unless the start offset is non-zero.
if|if
condition|(
name|opt
operator|==
name|NULL
operator|||
name|opt
operator|->
name|start_offset
operator|==
literal|0
condition|)
return|return
name|LZMA_OK
return|;
name|unaligned_write32le
argument_list|(
name|out
argument_list|,
name|opt
operator|->
name|start_offset
argument_list|)
expr_stmt|;
return|return
name|LZMA_OK
return|;
block|}
end_function

end_unit

