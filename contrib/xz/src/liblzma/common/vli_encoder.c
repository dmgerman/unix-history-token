begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       vli_encoder.c
end_comment

begin_comment
comment|/// \brief      Encodes variable-length integers
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
name|lzma_vli_encode
argument_list|(
argument|lzma_vli vli
argument_list|,
argument|size_t *vli_pos
argument_list|,
argument|uint8_t *restrict out
argument_list|,
argument|size_t *restrict out_pos
argument_list|,
argument|size_t out_size
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
comment|// In single-call mode, we expect that the caller has
comment|// reserved enough output space.
if|if
condition|(
operator|*
name|out_pos
operator|>=
name|out_size
condition|)
return|return
name|LZMA_PROG_ERROR
return|;
block|}
else|else
block|{
comment|// This never happens when we are called by liblzma, but
comment|// may happen if called directly from an application.
if|if
condition|(
operator|*
name|out_pos
operator|>=
name|out_size
condition|)
return|return
name|LZMA_BUF_ERROR
return|;
block|}
comment|// Validate the arguments.
if|if
condition|(
operator|*
name|vli_pos
operator|>=
name|LZMA_VLI_BYTES_MAX
operator|||
name|vli
operator|>
name|LZMA_VLI_MAX
condition|)
return|return
name|LZMA_PROG_ERROR
return|;
comment|// Shift vli so that the next bits to encode are the lowest. In
comment|// single-call mode this never changes vli since *vli_pos is zero.
name|vli
operator|>>=
operator|*
name|vli_pos
operator|*
literal|7
expr_stmt|;
comment|// Write the non-last bytes in a loop.
while|while
condition|(
name|vli
operator|>=
literal|0x80
condition|)
block|{
comment|// We don't need *vli_pos during this function call anymore,
comment|// but update it here so that it is ready if we need to
comment|// return before the whole integer has been decoded.
operator|++
operator|*
name|vli_pos
expr_stmt|;
name|assert
argument_list|(
operator|*
name|vli_pos
operator|<
name|LZMA_VLI_BYTES_MAX
argument_list|)
expr_stmt|;
comment|// Write the next byte.
name|out
index|[
operator|*
name|out_pos
index|]
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|vli
argument_list|)
operator||
literal|0x80
expr_stmt|;
name|vli
operator|>>=
literal|7
expr_stmt|;
if|if
condition|(
operator|++
operator|*
name|out_pos
operator|==
name|out_size
condition|)
return|return
name|vli_pos
operator|==
operator|&
name|vli_pos_internal
condition|?
name|LZMA_PROG_ERROR
else|:
name|LZMA_OK
return|;
block|}
comment|// Write the last byte.
name|out
index|[
operator|*
name|out_pos
index|]
operator|=
call|(
name|uint8_t
call|)
argument_list|(
name|vli
argument_list|)
expr_stmt|;
operator|++
operator|*
name|out_pos
expr_stmt|;
operator|++
operator|*
name|vli_pos
expr_stmt|;
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
end_block

end_unit

