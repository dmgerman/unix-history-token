begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       easy_preset.c
end_comment

begin_comment
comment|/// \brief      Preset handling for easy encoder and decoder
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

begin_function
specifier|extern
name|bool
name|lzma_easy_preset
parameter_list|(
name|lzma_options_easy
modifier|*
name|opt_easy
parameter_list|,
name|uint32_t
name|preset
parameter_list|)
block|{
if|if
condition|(
name|lzma_lzma_preset
argument_list|(
operator|&
name|opt_easy
operator|->
name|opt_lzma
argument_list|,
name|preset
argument_list|)
condition|)
return|return
name|true
return|;
name|opt_easy
operator|->
name|filters
index|[
literal|0
index|]
operator|.
name|id
operator|=
name|LZMA_FILTER_LZMA2
expr_stmt|;
name|opt_easy
operator|->
name|filters
index|[
literal|0
index|]
operator|.
name|options
operator|=
operator|&
name|opt_easy
operator|->
name|opt_lzma
expr_stmt|;
name|opt_easy
operator|->
name|filters
index|[
literal|1
index|]
operator|.
name|id
operator|=
name|LZMA_VLI_UNKNOWN
expr_stmt|;
return|return
name|false
return|;
block|}
end_function

end_unit

