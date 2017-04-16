begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- FuzzerRandom.h - Internal header for the Fuzzer ----------*- C++ -* ===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
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

begin_comment
comment|// fuzzer::Random
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_FUZZER_RANDOM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_FUZZER_RANDOM_H
end_define

begin_include
include|#
directive|include
file|<random>
end_include

begin_decl_stmt
name|namespace
name|fuzzer
block|{
name|class
name|Random
range|:
name|public
name|std
operator|::
name|mt19937
block|{
name|public
operator|:
name|Random
argument_list|(
argument|unsigned int seed
argument_list|)
operator|:
name|std
operator|::
name|mt19937
argument_list|(
argument|seed
argument_list|)
block|{}
name|result_type
name|operator
argument_list|()
operator|(
operator|)
block|{
return|return
name|this
operator|->
name|std
operator|::
name|mt19937
operator|::
name|operator
argument_list|()
argument_list|()
return|;
block|}
name|size_t
name|Rand
argument_list|()
block|{
return|return
name|this
operator|->
name|operator
argument_list|()
argument_list|()
return|;
block|}
name|size_t
name|RandBool
argument_list|()
block|{
return|return
name|Rand
argument_list|()
operator|%
literal|2
return|;
block|}
name|size_t
name|operator
argument_list|()
operator|(
name|size_t
name|n
operator|)
block|{
return|return
name|n
operator|?
name|Rand
argument_list|()
operator|%
name|n
operator|:
literal|0
return|;
block|}
name|intptr_t
name|operator
argument_list|()
operator|(
name|intptr_t
name|From
expr|,
name|intptr_t
name|To
operator|)
block|{
name|assert
argument_list|(
name|From
operator|<
name|To
argument_list|)
block|;
name|intptr_t
name|RangeSize
operator|=
name|To
operator|-
name|From
operator|+
literal|1
block|;
return|return
name|operator
argument_list|()
argument_list|(
name|RangeSize
argument_list|)
operator|+
name|From
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// namespace fuzzer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_FUZZER_RANDOM_H
end_comment

end_unit

