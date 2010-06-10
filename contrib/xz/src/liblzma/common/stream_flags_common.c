begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       stream_flags_common.c
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

begin_include
include|#
directive|include
file|"stream_flags_common.h"
end_include

begin_decl_stmt
specifier|const
name|uint8_t
name|lzma_header_magic
index|[
literal|6
index|]
init|=
block|{
literal|0xFD
block|,
literal|0x37
block|,
literal|0x7A
block|,
literal|0x58
block|,
literal|0x5A
block|,
literal|0x00
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uint8_t
name|lzma_footer_magic
index|[
literal|2
index|]
init|=
block|{
literal|0x59
block|,
literal|0x5A
block|}
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_stream_flags_compare
argument_list|(
argument|const lzma_stream_flags *a
argument_list|,
argument|const lzma_stream_flags *b
argument_list|)
end_macro

begin_block
block|{
comment|// We can compare only version 0 structures.
if|if
condition|(
name|a
operator|->
name|version
operator|!=
literal|0
operator|||
name|b
operator|->
name|version
operator|!=
literal|0
condition|)
return|return
name|LZMA_OPTIONS_ERROR
return|;
comment|// Check type
if|if
condition|(
call|(
name|unsigned
name|int
call|)
argument_list|(
name|a
operator|->
name|check
argument_list|)
operator|>
name|LZMA_CHECK_ID_MAX
operator|||
call|(
name|unsigned
name|int
call|)
argument_list|(
name|b
operator|->
name|check
argument_list|)
operator|>
name|LZMA_CHECK_ID_MAX
condition|)
return|return
name|LZMA_PROG_ERROR
return|;
if|if
condition|(
name|a
operator|->
name|check
operator|!=
name|b
operator|->
name|check
condition|)
return|return
name|LZMA_DATA_ERROR
return|;
comment|// Backward Sizes are compared only if they are known in both.
if|if
condition|(
name|a
operator|->
name|backward_size
operator|!=
name|LZMA_VLI_UNKNOWN
operator|&&
name|b
operator|->
name|backward_size
operator|!=
name|LZMA_VLI_UNKNOWN
condition|)
block|{
if|if
condition|(
operator|!
name|is_backward_size_valid
argument_list|(
name|a
argument_list|)
operator|||
operator|!
name|is_backward_size_valid
argument_list|(
name|b
argument_list|)
condition|)
return|return
name|LZMA_PROG_ERROR
return|;
if|if
condition|(
name|a
operator|->
name|backward_size
operator|!=
name|b
operator|->
name|backward_size
condition|)
return|return
name|LZMA_DATA_ERROR
return|;
block|}
return|return
name|LZMA_OK
return|;
block|}
end_block

end_unit

