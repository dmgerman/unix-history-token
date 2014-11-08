begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       crc32.c
end_comment

begin_comment
comment|/// \brief      CRC32 calculation
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Calculate the CRC32 using the slice-by-eight algorithm.
end_comment

begin_comment
comment|/// It is explained in this document:
end_comment

begin_comment
comment|/// http://www.intel.com/technology/comms/perfnet/download/CRC_generators.pdf
end_comment

begin_comment
comment|/// The code in this file is not the same as in Intel's paper, but
end_comment

begin_comment
comment|/// the basic principle is identical.
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

begin_include
include|#
directive|include
file|"crc_macros.h"
end_include

begin_comment
comment|// If you make any changes, do some benchmarking! Seemingly unrelated
end_comment

begin_comment
comment|// changes can very easily ruin the performance (and very probably is
end_comment

begin_comment
comment|// very compiler dependent).
end_comment

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
name|crc
operator|=
operator|~
name|crc
expr_stmt|;
ifdef|#
directive|ifdef
name|WORDS_BIGENDIAN
name|crc
operator|=
name|bswap32
argument_list|(
name|crc
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|size
operator|>
literal|8
condition|)
block|{
comment|// Fix the alignment, if needed. The if statement above
comment|// ensures that this won't read past the end of buf[].
while|while
condition|(
call|(
name|uintptr_t
call|)
argument_list|(
name|buf
argument_list|)
operator|&
literal|7
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
name|A
argument_list|(
name|crc
argument_list|)
index|]
operator|^
name|S8
argument_list|(
name|crc
argument_list|)
expr_stmt|;
operator|--
name|size
expr_stmt|;
block|}
comment|// Calculate the position where to stop.
specifier|const
name|uint8_t
modifier|*
specifier|const
name|limit
init|=
name|buf
operator|+
operator|(
name|size
operator|&
operator|~
call|(
name|size_t
call|)
argument_list|(
literal|7
argument_list|)
operator|)
decl_stmt|;
comment|// Calculate how many bytes must be calculated separately
comment|// before returning the result.
name|size
operator|&=
call|(
name|size_t
call|)
argument_list|(
literal|7
argument_list|)
expr_stmt|;
comment|// Calculate the CRC32 using the slice-by-eight algorithm.
while|while
condition|(
name|buf
operator|<
name|limit
condition|)
block|{
name|crc
operator|^=
operator|*
operator|(
specifier|const
name|uint32_t
operator|*
operator|)
operator|(
name|buf
operator|)
expr_stmt|;
name|buf
operator|+=
literal|4
expr_stmt|;
name|crc
operator|=
name|lzma_crc32_table
index|[
literal|7
index|]
index|[
name|A
argument_list|(
name|crc
argument_list|)
index|]
operator|^
name|lzma_crc32_table
index|[
literal|6
index|]
index|[
name|B
argument_list|(
name|crc
argument_list|)
index|]
operator|^
name|lzma_crc32_table
index|[
literal|5
index|]
index|[
name|C
argument_list|(
name|crc
argument_list|)
index|]
operator|^
name|lzma_crc32_table
index|[
literal|4
index|]
index|[
name|D
argument_list|(
name|crc
argument_list|)
index|]
expr_stmt|;
specifier|const
name|uint32_t
name|tmp
init|=
operator|*
operator|(
specifier|const
name|uint32_t
operator|*
operator|)
operator|(
name|buf
operator|)
decl_stmt|;
name|buf
operator|+=
literal|4
expr_stmt|;
comment|// At least with some compilers, it is critical for
comment|// performance, that the crc variable is XORed
comment|// between the two table-lookup pairs.
name|crc
operator|=
name|lzma_crc32_table
index|[
literal|3
index|]
index|[
name|A
argument_list|(
name|tmp
argument_list|)
index|]
operator|^
name|lzma_crc32_table
index|[
literal|2
index|]
index|[
name|B
argument_list|(
name|tmp
argument_list|)
index|]
operator|^
name|crc
operator|^
name|lzma_crc32_table
index|[
literal|1
index|]
index|[
name|C
argument_list|(
name|tmp
argument_list|)
index|]
operator|^
name|lzma_crc32_table
index|[
literal|0
index|]
index|[
name|D
argument_list|(
name|tmp
argument_list|)
index|]
expr_stmt|;
block|}
block|}
while|while
condition|(
name|size
operator|--
operator|!=
literal|0
condition|)
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
name|A
argument_list|(
name|crc
argument_list|)
index|]
operator|^
name|S8
argument_list|(
name|crc
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|WORDS_BIGENDIAN
name|crc
operator|=
name|bswap32
argument_list|(
name|crc
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|~
name|crc
return|;
block|}
end_block

end_unit

