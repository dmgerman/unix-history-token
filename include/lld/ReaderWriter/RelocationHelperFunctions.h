begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lld/ReaderWriter/RelocationHelperFunctions.h------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_READER_WRITER_RELOCATION_HELPER_FUNCTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_RELOCATION_HELPER_FUNCTIONS_H
end_define

begin_decl_stmt
name|namespace
name|lld
block|{
comment|/// Gather val's bits as specified by the mask. Example:
comment|///
comment|///  Val:    0bABCDEFGHIJKLMN
comment|///  Mask:   0b10111100001011
comment|///  Output: 0b000000ACDEFKMN
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|gatherBits
argument_list|(
argument|T val
argument_list|,
argument|T mask
argument_list|)
block|{
name|T
name|result
operator|=
literal|0
block|;
name|size_t
name|off
operator|=
literal|0
block|;
for|for
control|(
name|size_t
name|bit
init|=
literal|0
init|;
name|bit
operator|<
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|*
literal|8
condition|;
operator|++
name|bit
control|)
block|{
name|bool
name|maskBit
init|=
operator|(
name|mask
operator|>>
name|bit
operator|)
operator|&
literal|1
decl_stmt|;
if|if
condition|(
name|maskBit
condition|)
block|{
name|bool
name|valBit
init|=
operator|(
name|val
operator|>>
name|bit
operator|)
operator|&
literal|1
decl_stmt|;
name|result
operator||=
name|static_cast
operator|<
name|T
operator|>
operator|(
name|valBit
operator|)
operator|<<
name|off
expr_stmt|;
operator|++
name|off
expr_stmt|;
block|}
block|}
return|return
name|result
return|;
block|}
comment|/// Scatter val's bits as specified by the mask. Example:
comment|///
comment|///  Val:    0bABCDEFG
comment|///  Mask:   0b10111100001011
comment|///  Output: 0b00ABCD0000E0FG
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|scatterBits
argument_list|(
argument|T val
argument_list|,
argument|T mask
argument_list|)
block|{
name|T
name|result
operator|=
literal|0
block|;
name|size_t
name|off
operator|=
literal|0
block|;
for|for
control|(
name|size_t
name|bit
init|=
literal|0
init|;
name|bit
operator|<
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|*
literal|8
condition|;
operator|++
name|bit
control|)
block|{
name|bool
name|maskBit
init|=
operator|(
name|mask
operator|>>
name|bit
operator|)
operator|&
literal|1
decl_stmt|;
if|if
condition|(
name|maskBit
condition|)
block|{
name|bool
name|valBit
init|=
operator|(
name|val
operator|>>
name|off
operator|)
operator|&
literal|1
decl_stmt|;
name|result
operator||=
name|static_cast
operator|<
name|T
operator|>
operator|(
name|valBit
operator|)
operator|<<
name|bit
expr_stmt|;
operator|++
name|off
expr_stmt|;
block|}
block|}
return|return
name|result
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_READER_WRITER_RELOCATION_HELPER_FUNCTIONS_H
end_comment

end_unit

