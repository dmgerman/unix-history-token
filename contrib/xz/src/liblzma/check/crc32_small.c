begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       crc32_small.c
end_comment

begin_comment
comment|/// \brief      CRC32 calculation (size-optimized)
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
file|"check.h"
end_include

begin_decl_stmt
name|uint32_t
name|lzma_crc32_table
index|[
literal|1
index|]
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|crc32_init
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
specifier|const
name|uint32_t
name|poly32
init|=
name|UINT32_C
argument_list|(
literal|0xEDB88320
argument_list|)
decl_stmt|;
for|for
control|(
name|size_t
name|b
init|=
literal|0
init|;
name|b
operator|<
literal|256
condition|;
operator|++
name|b
control|)
block|{
name|uint32_t
name|r
init|=
name|b
decl_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|8
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|r
operator|&
literal|1
condition|)
name|r
operator|=
operator|(
name|r
operator|>>
literal|1
operator|)
operator|^
name|poly32
expr_stmt|;
else|else
name|r
operator|>>=
literal|1
expr_stmt|;
block|}
name|lzma_crc32_table
index|[
literal|0
index|]
index|[
name|b
index|]
operator|=
name|r
expr_stmt|;
block|}
return|return;
block|}
end_function

begin_function
specifier|extern
name|void
name|lzma_crc32_init
parameter_list|(
name|void
parameter_list|)
block|{
name|mythread_once
argument_list|(
name|crc32_init
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_extern
extern|extern LZMA_API(uint32_t
end_extern

begin_macro
unit|)
name|lzma_crc32
argument_list|(
argument|const uint8_t *buf
argument_list|,
argument|size_t size
argument_list|,
argument|uint32_t crc
argument_list|)
end_macro

begin_block
block|{
name|lzma_crc32_init
argument_list|()
expr_stmt|;
name|crc
operator|=
operator|~
name|crc
expr_stmt|;
while|while
condition|(
name|size
operator|!=
literal|0
condition|)
block|{
name|crc
operator|=
name|lzma_crc32_table
index|[
literal|0
index|]
index|[
operator|*
name|buf
operator|++
operator|^
operator|(
name|crc
operator|&
literal|0xFF
operator|)
index|]
operator|^
operator|(
name|crc
operator|>>
literal|8
operator|)
expr_stmt|;
operator|--
name|size
expr_stmt|;
block|}
return|return
operator|~
name|crc
return|;
block|}
end_block

end_unit

