begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       stream_flags_common.h
end_comment

begin_comment
comment|/// \brief      Common stuff for Stream flags coders
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
name|LZMA_STREAM_FLAGS_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|LZMA_STREAM_FLAGS_COMMON_H
end_define

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_comment
comment|/// Size of the Stream Flags field
end_comment

begin_define
define|#
directive|define
name|LZMA_STREAM_FLAGS_SIZE
value|2
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|uint8_t
name|lzma_header_magic
index|[
literal|6
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint8_t
name|lzma_footer_magic
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|bool
name|is_backward_size_valid
parameter_list|(
specifier|const
name|lzma_stream_flags
modifier|*
name|options
parameter_list|)
block|{
return|return
name|options
operator|->
name|backward_size
operator|>=
name|LZMA_BACKWARD_SIZE_MIN
operator|&&
name|options
operator|->
name|backward_size
operator|<=
name|LZMA_BACKWARD_SIZE_MAX
operator|&&
operator|(
name|options
operator|->
name|backward_size
operator|&
literal|3
operator|)
operator|==
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

