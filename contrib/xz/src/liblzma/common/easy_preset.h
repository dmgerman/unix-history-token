begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       easy_preset.h
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
file|"common.h"
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/// We need to keep the filters array available in case
comment|/// LZMA_FULL_FLUSH is used.
name|lzma_filter
name|filters
index|[
name|LZMA_FILTERS_MAX
operator|+
literal|1
index|]
decl_stmt|;
comment|/// Options for LZMA2
name|lzma_options_lzma
name|opt_lzma
decl_stmt|;
comment|// Options for more filters can be added later, so this struct
comment|// is not ready to be put into the public API.
block|}
name|lzma_options_easy
typedef|;
end_typedef

begin_comment
comment|/// Set *easy to the settings given by the preset. Returns true on error,
end_comment

begin_comment
comment|/// false on success.
end_comment

begin_function_decl
specifier|extern
name|bool
name|lzma_easy_preset
parameter_list|(
name|lzma_options_easy
modifier|*
name|easy
parameter_list|,
name|uint32_t
name|preset
parameter_list|)
function_decl|;
end_function_decl

end_unit

