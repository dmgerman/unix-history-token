begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       easy_decoder_memusage.c
end_comment

begin_comment
comment|/// \brief      Decoder memory usage calculation to match easy encoder presets
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
extern|extern LZMA_API(uint64_t
end_extern

begin_macro
unit|)
name|lzma_easy_decoder_memusage
argument_list|(
argument|uint32_t preset
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
name|UINT32_MAX
return|;
return|return
name|lzma_raw_decoder_memusage
argument_list|(
name|opt_easy
operator|.
name|filters
argument_list|)
return|;
block|}
end_block

end_unit

