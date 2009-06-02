begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/ProfileInfo.h - Profile Info Interface -----*- C++ -*-===//
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
comment|//
end_comment

begin_comment
comment|// This file defines the generic ProfileInfo interface, which is used as the
end_comment

begin_comment
comment|// common interface used by all clients of profiling information, and
end_comment

begin_comment
comment|// implemented either by making static guestimations, or by actually reading in
end_comment

begin_comment
comment|// profiling information gathered by running the program.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note that to be useful, all profile-based optimizations should preserve
end_comment

begin_comment
comment|// ProfileInfo, which requires that they notify it when changes to the CFG are
end_comment

begin_comment
comment|// made.
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
name|LLVM_ANALYSIS_PROFILEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_PROFILEINFO_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BasicBlock
decl_stmt|;
name|class
name|Pass
decl_stmt|;
comment|/// ProfileInfo Class - This class holds and maintains edge profiling
comment|/// information for some unit of code.
name|class
name|ProfileInfo
block|{
name|protected
label|:
comment|// EdgeCounts - Count the number of times a transition between two blocks is
comment|// executed.  As a special case, we also hold an edge from the null
comment|// BasicBlock to the entry block to indicate how many times the function was
comment|// entered.
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|pair
operator|<
name|BasicBlock
operator|*
operator|,
name|BasicBlock
operator|*
operator|>
operator|,
name|unsigned
operator|>
name|EdgeCounts
expr_stmt|;
name|public
label|:
specifier|static
name|char
name|ID
decl_stmt|;
comment|// Class identification, replacement for typeinfo
name|virtual
operator|~
name|ProfileInfo
argument_list|()
expr_stmt|;
comment|// We want to be subclassed
comment|//===------------------------------------------------------------------===//
comment|/// Profile Information Queries
comment|///
name|unsigned
name|getExecutionCount
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
name|unsigned
name|getEdgeWeight
argument_list|(
name|BasicBlock
operator|*
name|Src
argument_list|,
name|BasicBlock
operator|*
name|Dest
argument_list|)
decl|const
block|{
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|pair
operator|<
name|BasicBlock
operator|*
operator|,
name|BasicBlock
operator|*
operator|>
operator|,
name|unsigned
operator|>
operator|::
name|const_iterator
name|I
operator|=
name|EdgeCounts
operator|.
name|find
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|Src
argument_list|,
name|Dest
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|I
operator|!=
name|EdgeCounts
operator|.
name|end
argument_list|()
condition|?
name|I
operator|->
name|second
else|:
literal|0
return|;
block|}
comment|//===------------------------------------------------------------------===//
comment|/// Analysis Update Methods
comment|///
block|}
empty_stmt|;
comment|/// createProfileLoaderPass - This function returns a Pass that loads the
comment|/// profiling information for the module from the specified filename, making
comment|/// it available to the optimizers.
name|Pass
modifier|*
name|createProfileLoaderPass
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Filename
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

