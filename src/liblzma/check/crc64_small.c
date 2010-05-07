begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       crc64_small.c
end_comment

begin_comment
comment|/// \brief      CRC64 calculation (size-optimized)
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
specifier|static
name|uint64_t
name|crc64_table
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|crc64_init
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
specifier|const
name|uint64_t
name|poly64
init|=
name|UINT64_C
argument_list|(
literal|0xC96C5795D7870F42
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
name|uint64_t
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
name|poly64
expr_stmt|;
else|else
name|r
operator|>>=
literal|1
expr_stmt|;
block|}
name|crc64_table
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
name|mythread_once
argument_list|(
name|crc64_init
argument_list|)
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
name|crc64_table
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

