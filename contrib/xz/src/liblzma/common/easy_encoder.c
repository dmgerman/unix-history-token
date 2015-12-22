begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       easy_encoder.c
end_comment

begin_comment
comment|/// \brief      Easy .xz Stream encoder initialization
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
file|"easy_preset.h"
end_include

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_easy_encoder
argument_list|(
argument|lzma_stream *strm
argument_list|,
argument|uint32_t preset
argument_list|,
argument|lzma_check check
argument_list|)
end_macro

begin_block
block|{
name|lzma_options_easy
name|opt_easy
decl_stmt|;
if|if
condition|(
name|lzma_easy_preset
argument_list|(
operator|&
name|opt_easy
argument_list|,
name|preset
argument_list|)
condition|)
return|return
name|LZMA_OPTIONS_ERROR
return|;
return|return
name|lzma_stream_encoder
argument_list|(
name|strm
argument_list|,
name|opt_easy
operator|.
name|filters
argument_list|,
name|check
argument_list|)
return|;
block|}
end_block

end_unit

