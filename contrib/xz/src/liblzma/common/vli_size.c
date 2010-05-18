begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       vli_size.c
end_comment

begin_comment
comment|/// \brief      Calculates the encoded size of a variable-length integer
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
extern|extern LZMA_API(uint32_t
end_extern

begin_macro
unit|)
name|lzma_vli_size
argument_list|(
argument|lzma_vli vli
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|vli
operator|>
name|LZMA_VLI_MAX
condition|)
return|return
literal|0
return|;
name|uint32_t
name|i
init|=
literal|0
decl_stmt|;
do|do
block|{
name|vli
operator|>>=
literal|7
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
do|while
condition|(
name|vli
operator|!=
literal|0
condition|)
do|;
name|assert
argument_list|(
name|i
operator|<=
name|LZMA_VLI_BYTES_MAX
argument_list|)
expr_stmt|;
return|return
name|i
return|;
block|}
end_block

end_unit

