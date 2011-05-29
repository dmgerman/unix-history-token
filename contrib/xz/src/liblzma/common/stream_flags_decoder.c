begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       stream_flags_decoder.c
end_comment

begin_comment
comment|/// \brief      Decodes Stream Header and Stream Footer from .xz files
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
name|stream_flags_decode
parameter_list|(
name|lzma_stream_flags
modifier|*
name|options
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|in
parameter_list|)
block|{
comment|// Reserved bits must be unset.
if|if
condition|(
name|in
index|[
literal|0
index|]
operator|!=
literal|0x00
operator|||
operator|(
name|in
index|[
literal|1
index|]
operator|&
literal|0xF0
operator|)
condition|)
return|return
name|true
return|;
name|options
operator|->
name|version
operator|=
literal|0
expr_stmt|;
name|options
operator|->
name|check
operator|=
name|in
index|[
literal|1
index|]
operator|&
literal|0x0F
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
name|lzma_stream_header_decode
argument_list|(
argument|lzma_stream_flags *options
argument_list|,
argument|const uint8_t *in
argument_list|)
end_macro

begin_block
block|{
comment|// Magic
if|if
condition|(
name|memcmp
argument_list|(
name|in
argument_list|,
name|lzma_header_magic
argument_list|,
sizeof|sizeof
argument_list|(
name|lzma_header_magic
argument_list|)
argument_list|)
operator|!=
literal|0
condition|)
return|return
name|LZMA_FORMAT_ERROR
return|;
comment|// Verify the CRC32 so we can distinguish between corrupt
comment|// and unsupported files.
specifier|const
name|uint32_t
name|crc
init|=
name|lzma_crc32
argument_list|(
name|in
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
if|if
condition|(
name|crc
operator|!=
name|unaligned_read32le
argument_list|(
name|in
operator|+
sizeof|sizeof
argument_list|(
name|lzma_header_magic
argument_list|)
operator|+
name|LZMA_STREAM_FLAGS_SIZE
argument_list|)
condition|)
return|return
name|LZMA_DATA_ERROR
return|;
comment|// Stream Flags
if|if
condition|(
name|stream_flags_decode
argument_list|(
name|options
argument_list|,
name|in
operator|+
sizeof|sizeof
argument_list|(
name|lzma_header_magic
argument_list|)
argument_list|)
condition|)
return|return
name|LZMA_OPTIONS_ERROR
return|;
comment|// Set Backward Size to indicate unknown value. That way
comment|// lzma_stream_flags_compare() can be used to compare Stream Header
comment|// and Stream Footer while keeping it useful also for comparing
comment|// two Stream Footers.
name|options
operator|->
name|backward_size
operator|=
name|LZMA_VLI_UNKNOWN
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
name|lzma_stream_footer_decode
argument_list|(
argument|lzma_stream_flags *options
argument_list|,
argument|const uint8_t *in
argument_list|)
end_macro

begin_block
block|{
comment|// Magic
if|if
condition|(
name|memcmp
argument_list|(
name|in
operator|+
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
operator|*
literal|2
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
operator|!=
literal|0
condition|)
return|return
name|LZMA_FORMAT_ERROR
return|;
comment|// CRC32
specifier|const
name|uint32_t
name|crc
init|=
name|lzma_crc32
argument_list|(
name|in
operator|+
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
operator|+
name|LZMA_STREAM_FLAGS_SIZE
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|crc
operator|!=
name|unaligned_read32le
argument_list|(
name|in
argument_list|)
condition|)
return|return
name|LZMA_DATA_ERROR
return|;
comment|// Stream Flags
if|if
condition|(
name|stream_flags_decode
argument_list|(
name|options
argument_list|,
name|in
operator|+
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
operator|*
literal|2
argument_list|)
condition|)
return|return
name|LZMA_OPTIONS_ERROR
return|;
comment|// Backward Size
name|options
operator|->
name|backward_size
operator|=
name|unaligned_read32le
argument_list|(
name|in
operator|+
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
argument_list|)
expr_stmt|;
name|options
operator|->
name|backward_size
operator|=
operator|(
name|options
operator|->
name|backward_size
operator|+
literal|1
operator|)
operator|*
literal|4
expr_stmt|;
return|return
name|LZMA_OK
return|;
block|}
end_block

end_unit

