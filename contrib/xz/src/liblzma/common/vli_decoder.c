begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       vli_decoder.c
end_comment

begin_comment
comment|/// \brief      Decodes variable-length integers
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

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_vli_decode
argument_list|(
argument|lzma_vli *restrict vli
argument_list|,
argument|size_t *vli_pos
argument_list|,
argument|const uint8_t *restrict in
argument_list|,
argument|size_t *restrict in_pos
argument_list|,
argument|size_t in_size
argument_list|)
end_macro

begin_block
block|{
comment|// If we haven't been given vli_pos, work in single-call mode.
name|size_t
name|vli_pos_internal
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|vli_pos
operator|==
name|NULL
condition|)
block|{
name|vli_pos
operator|=
operator|&
name|vli_pos_internal
expr_stmt|;
operator|*
name|vli
operator|=
literal|0
expr_stmt|;
comment|// If there's no input, use LZMA_DATA_ERROR. This way it is
comment|// easy to decode VLIs from buffers that have known size,
comment|// and get the correct error code in case the buffer is
comment|// too short.
if|if
condition|(
operator|*
name|in_pos
operator|>=
name|in_size
condition|)
return|return
name|LZMA_DATA_ERROR
return|;
block|}
else|else
block|{
comment|// Initialize *vli when starting to decode a new integer.
if|if
condition|(
operator|*
name|vli_pos
operator|==
literal|0
condition|)
operator|*
name|vli
operator|=
literal|0
expr_stmt|;
comment|// Validate the arguments.
if|if
condition|(
operator|*
name|vli_pos
operator|>=
name|LZMA_VLI_BYTES_MAX
operator|||
operator|(
operator|*
name|vli
operator|>>
operator|(
operator|*
name|vli_pos
operator|*
literal|7
operator|)
operator|)
operator|!=
literal|0
condition|)
return|return
name|LZMA_PROG_ERROR
return|;
empty_stmt|;
if|if
condition|(
operator|*
name|in_pos
operator|>=
name|in_size
condition|)
return|return
name|LZMA_BUF_ERROR
return|;
block|}
do|do
block|{
comment|// Read the next byte. Use a temporary variable so that we
comment|// can update *in_pos immediately.
specifier|const
name|uint8_t
name|byte
init|=
name|in
index|[
operator|*
name|in_pos
index|]
decl_stmt|;
operator|++
operator|*
name|in_pos
expr_stmt|;
comment|// Add the newly read byte to *vli.
operator|*
name|vli
operator|+=
call|(
name|lzma_vli
call|)
argument_list|(
name|byte
operator|&
literal|0x7F
argument_list|)
operator|<<
operator|(
operator|*
name|vli_pos
operator|*
literal|7
operator|)
expr_stmt|;
operator|++
operator|*
name|vli_pos
expr_stmt|;
comment|// Check if this is the last byte of a multibyte integer.
if|if
condition|(
operator|(
name|byte
operator|&
literal|0x80
operator|)
operator|==
literal|0
condition|)
block|{
comment|// We don't allow using variable-length integers as
comment|// padding i.e. the encoding must use the most the
comment|// compact form.
if|if
condition|(
name|byte
operator|==
literal|0x00
operator|&&
operator|*
name|vli_pos
operator|>
literal|1
condition|)
return|return
name|LZMA_DATA_ERROR
return|;
return|return
name|vli_pos
operator|==
operator|&
name|vli_pos_internal
condition|?
name|LZMA_OK
else|:
name|LZMA_STREAM_END
return|;
block|}
comment|// There is at least one more byte coming. If we have already
comment|// read maximum number of bytes, the integer is considered
comment|// corrupt.
comment|//
comment|// If we need bigger integers in future, old versions liblzma
comment|// will confusingly indicate the file being corrupt istead of
comment|// unsupported. I suppose it's still better this way, because
comment|// in the foreseeable future (writing this in 2008) the only
comment|// reason why files would appear having over 63-bit integers
comment|// is that the files are simply corrupt.
if|if
condition|(
operator|*
name|vli_pos
operator|==
name|LZMA_VLI_BYTES_MAX
condition|)
return|return
name|LZMA_DATA_ERROR
return|;
block|}
do|while
condition|(
operator|*
name|in_pos
operator|<
name|in_size
condition|)
do|;
return|return
name|vli_pos
operator|==
operator|&
name|vli_pos_internal
condition|?
name|LZMA_DATA_ERROR
else|:
name|LZMA_OK
return|;
block|}
end_block

end_unit

