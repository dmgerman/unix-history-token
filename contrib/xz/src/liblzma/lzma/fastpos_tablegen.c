begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       fastpos_tablegen.c
end_comment

begin_comment
comment|/// \brief      Generates the lzma_fastpos[] lookup table
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//  Authors:    Igor Pavlov
end_comment

begin_comment
comment|//              Lasse Collin
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"fastpos.h"
end_include

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|uint8_t
name|fastpos
index|[
literal|1
operator|<<
name|FASTPOS_BITS
index|]
decl_stmt|;
specifier|const
name|uint8_t
name|fast_slots
init|=
literal|2
operator|*
name|FASTPOS_BITS
decl_stmt|;
name|uint32_t
name|c
init|=
literal|2
decl_stmt|;
name|fastpos
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
name|fastpos
index|[
literal|1
index|]
operator|=
literal|1
expr_stmt|;
for|for
control|(
name|uint8_t
name|slot_fast
init|=
literal|2
init|;
name|slot_fast
operator|<
name|fast_slots
condition|;
operator|++
name|slot_fast
control|)
block|{
specifier|const
name|uint32_t
name|k
init|=
literal|1
operator|<<
operator|(
operator|(
name|slot_fast
operator|>>
literal|1
operator|)
operator|-
literal|1
operator|)
decl_stmt|;
for|for
control|(
name|uint32_t
name|j
init|=
literal|0
init|;
name|j
operator|<
name|k
condition|;
operator|++
name|j
operator|,
operator|++
name|c
control|)
name|fastpos
index|[
name|c
index|]
operator|=
name|slot_fast
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"/* This file has been automatically generated "
literal|"by fastpos_tablegen.c. */\n\n"
literal|"#include \"common.h\"\n"
literal|"#include \"fastpos.h\"\n\n"
literal|"const uint8_t lzma_fastpos[1<< FASTPOS_BITS] = {"
argument_list|)
expr_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
operator|(
literal|1
operator|<<
name|FASTPOS_BITS
operator|)
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|i
operator|%
literal|16
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"\n\t"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%3u"
argument_list|,
call|(
name|unsigned
name|int
call|)
argument_list|(
name|fastpos
index|[
name|i
index|]
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|!=
operator|(
literal|1
operator|<<
name|FASTPOS_BITS
operator|)
operator|-
literal|1
condition|)
name|printf
argument_list|(
literal|","
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n};\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

