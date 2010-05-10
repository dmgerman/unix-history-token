begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       crc64.c
end_comment

begin_comment
comment|/// \brief      CRC64 calculation
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Calculate the CRC64 using the slice-by-four algorithm. This is the same
end_comment

begin_comment
comment|/// idea that is used in crc32_fast.c, but for CRC64 we use only four tables
end_comment

begin_comment
comment|/// instead of eight to avoid increasing CPU cache usage.
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

begin_ifdef
ifdef|#
directive|ifdef
name|WORDS_BIGENDIAN
end_ifdef

begin_define
define|#
directive|define
name|A1
parameter_list|(
name|x
parameter_list|)
value|((x)>> 56)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|A1
value|A
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// See the comments in crc32_fast.c. They aren't duplicated here.
end_comment

begin_extern
extern|extern LZMA_API(uint64_t
end_extern

begin_macro
unit|)
name|lzma_crc64
argument_list|(
argument|const uint8_t *buf
argument_list|,
argument|size_t size
argument_list|,
argument|uint64_t crc
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
name|bswap64
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
literal|4
condition|)
block|{
while|while
condition|(
call|(
name|uintptr_t
call|)
argument_list|(
name|buf
argument_list|)
operator|&
literal|3
condition|)
block|{
name|crc
operator|=
name|lzma_crc64_table
index|[
literal|0
index|]
index|[
operator|*
name|buf
operator|++
operator|^
name|A1
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
literal|3
argument_list|)
operator|)
decl_stmt|;
name|size
operator|&=
call|(
name|size_t
call|)
argument_list|(
literal|3
argument_list|)
expr_stmt|;
while|while
condition|(
name|buf
operator|<
name|limit
condition|)
block|{
ifdef|#
directive|ifdef
name|WORDS_BIGENDIAN
specifier|const
name|uint32_t
name|tmp
init|=
operator|(
name|crc
operator|>>
literal|32
operator|)
operator|^
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
else|#
directive|else
specifier|const
name|uint32_t
name|tmp
init|=
name|crc
operator|^
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
endif|#
directive|endif
name|buf
operator|+=
literal|4
expr_stmt|;
name|crc
operator|=
name|lzma_crc64_table
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
name|lzma_crc64_table
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
name|S32
argument_list|(
name|crc
argument_list|)
operator|^
name|lzma_crc64_table
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
name|lzma_crc64_table
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
name|lzma_crc64_table
index|[
literal|0
index|]
index|[
operator|*
name|buf
operator|++
operator|^
name|A1
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
name|bswap64
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

