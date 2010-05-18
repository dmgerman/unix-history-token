begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       stream_flags_encoder.c
end_comment

begin_comment
comment|/// \brief      Encodes Stream Header and Stream Footer for .xz files
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
file|"stream_flags_common.h"
end_include

begin_function
specifier|static
name|bool
name|stream_flags_encode
parameter_list|(
specifier|const
name|lzma_stream_flags
modifier|*
name|options
parameter_list|,
name|uint8_t
modifier|*
name|out
parameter_list|)
block|{
if|if
condition|(
call|(
name|unsigned
name|int
call|)
argument_list|(
name|options
operator|->
name|check
argument_list|)
operator|>
name|LZMA_CHECK_ID_MAX
condition|)
return|return
name|true
return|;
name|out
index|[
literal|0
index|]
operator|=
literal|0x00
expr_stmt|;
name|out
index|[
literal|1
index|]
operator|=
name|options
operator|->
name|check
expr_stmt|;
return|return
name|false
return|;
block|}
end_function

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_stream_header_encode
argument_list|(
argument|const lzma_stream_flags *options
argument_list|,
argument|uint8_t *out
argument_list|)
end_macro

begin_block
block|{
name|assert
argument_list|(
sizeof|sizeof
argument_list|(
name|lzma_header_magic
argument_list|)
operator|+
name|LZMA_STREAM_FLAGS_SIZE
operator|+
literal|4
operator|==
name|LZMA_STREAM_HEADER_SIZE
argument_list|)
expr_stmt|;
if|if
condition|(
name|options
operator|->
name|version
operator|!=
literal|0
condition|)
return|return
name|LZMA_OPTIONS_ERROR
return|;
comment|// Magic
name|memcpy
argument_list|(
name|out
argument_list|,
name|lzma_header_magic
argument_list|,
sizeof|sizeof
argument_list|(
name|lzma_header_magic
argument_list|)
argument_list|)
expr_stmt|;
comment|// Stream Flags
if|if
condition|(
name|stream_flags_encode
argument_list|(
name|options
argument_list|,
name|out
operator|+
sizeof|sizeof
argument_list|(
name|lzma_header_magic
argument_list|)
argument_list|)
condition|)
return|return
name|LZMA_PROG_ERROR
return|;
comment|// CRC32 of the Stream Header
specifier|const
name|uint32_t
name|crc
init|=
name|lzma_crc32
argument_list|(
name|out
operator|+
sizeof|sizeof
argument_list|(
name|lzma_header_magic
argument_list|)
argument_list|,
name|LZMA_STREAM_FLAGS_SIZE
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|unaligned_write32le
argument_list|(
name|out
operator|+
sizeof|sizeof
argument_list|(
name|lzma_header_magic
argument_list|)
operator|+
name|LZMA_STREAM_FLAGS_SIZE
argument_list|,
name|crc
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
name|lzma_stream_footer_encode
argument_list|(
argument|const lzma_stream_flags *options
argument_list|,
argument|uint8_t *out
argument_list|)
end_macro

begin_block
block|{
name|assert
argument_list|(
literal|2
operator|*
literal|4
operator|+
name|LZMA_STREAM_FLAGS_SIZE
operator|+
sizeof|sizeof
argument_list|(
name|lzma_footer_magic
argument_list|)
operator|==
name|LZMA_STREAM_HEADER_SIZE
argument_list|)
expr_stmt|;
if|if
condition|(
name|options
operator|->
name|version
operator|!=
literal|0
condition|)
return|return
name|LZMA_OPTIONS_ERROR
return|;
comment|// Backward Size
if|if
condition|(
operator|!
name|is_backward_size_valid
argument_list|(
name|options
argument_list|)
condition|)
return|return
name|LZMA_PROG_ERROR
return|;
name|unaligned_write32le
argument_list|(
name|out
operator|+
literal|4
argument_list|,
name|options
operator|->
name|backward_size
operator|/
literal|4
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// Stream Flags
if|if
condition|(
name|stream_flags_encode
argument_list|(
name|options
argument_list|,
name|out
operator|+
literal|2
operator|*
literal|4
argument_list|)
condition|)
return|return
name|LZMA_PROG_ERROR
return|;
comment|// CRC32
specifier|const
name|uint32_t
name|crc
init|=
name|lzma_crc32
argument_list|(
name|out
operator|+
literal|4
argument_list|,
literal|4
operator|+
name|LZMA_STREAM_FLAGS_SIZE
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|unaligned_write32le
argument_list|(
name|out
argument_list|,
name|crc
argument_list|)
expr_stmt|;
comment|// Magic
name|memcpy
argument_list|(
name|out
operator|+
literal|2
operator|*
literal|4
operator|+
name|LZMA_STREAM_FLAGS_SIZE
argument_list|,
name|lzma_footer_magic
argument_list|,
sizeof|sizeof
argument_list|(
name|lzma_footer_magic
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|LZMA_OK
return|;
block|}
end_block

end_unit

