begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       chunk_size.c
end_comment

begin_comment
comment|/// \brief      Finds out the minimal reasonable chunk size for a filter chain
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

begin_comment
comment|/**  * \brief       Finds out the minimal reasonable chunk size for a filter chain  *  * This function helps determining the Uncompressed Sizes of the Blocks when  * doing multi-threaded encoding.  *  * When compressing a large file on a system having multiple CPUs or CPU  * cores, the file can be split into smaller chunks, that are compressed  * independently into separate Blocks in the same .lzma Stream.  *  * \return      Minimum reasonable Uncompressed Size of a Block. The  *              recommended minimum Uncompressed Size is between this value  *              and the value times two.   Zero if the Uncompressed Sizes of Blocks don't matter  */
end_comment

begin_extern
extern|extern LZMA_API(size_t
end_extern

begin_macro
unit|)
name|lzma_chunk_size
argument_list|(
argument|const lzma_options_filter *filters
argument_list|)
end_macro

begin_block
block|{
while|while
condition|(
name|filters
operator|->
name|id
operator|!=
name|LZMA_VLI_UNKNOWN
condition|)
block|{
switch|switch
condition|(
name|filters
operator|->
name|id
condition|)
block|{
comment|// TODO LZMA_FILTER_SPARSE
case|case
name|LZMA_FILTER_COPY
case|:
case|case
name|LZMA_FILTER_SUBBLOCK
case|:
case|case
name|LZMA_FILTER_X86
case|:
case|case
name|LZMA_FILTER_POWERPC
case|:
case|case
name|LZMA_FILTER_IA64
case|:
case|case
name|LZMA_FILTER_ARM
case|:
case|case
name|LZMA_FILTER_ARMTHUMB
case|:
case|case
name|LZMA_FILTER_SPARC
case|:
comment|// These are very fast, thus there is no point in
comment|// splitting the data into smaller blocks.
break|break;
case|case
name|LZMA_FILTER_LZMA1
case|:
comment|// The block sizes of the possible next filters in
comment|// the chain are irrelevant after the LZMA filter.
return|return
operator|(
operator|(
name|lzma_options_lzma
operator|*
operator|)
operator|(
name|filters
operator|->
name|options
operator|)
operator|)
operator|->
name|dictionary_size
return|;
default|default:
comment|// Unknown filters
return|return
literal|0
return|;
block|}
operator|++
name|filters
expr_stmt|;
block|}
comment|// Indicate that splitting would be useless.
return|return
name|SIZE_MAX
return|;
block|}
end_block

end_unit

