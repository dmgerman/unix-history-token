begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- GRBlockCounter.h - ADT for counting block visits -------------*- C++ -*-//
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
comment|//  This file defines GRBlockCounter, an abstract data type used to count
end_comment

begin_comment
comment|//  the number of times a given block has been visited along a path
end_comment

begin_comment
comment|//  analyzed by GRCoreEngine.
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
name|LLVM_CLANG_ANALYSIS_GRBLOCKCOUNTER
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_GRBLOCKCOUNTER
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BumpPtrAllocator
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|GRBlockCounter
block|{
name|void
modifier|*
name|Data
decl_stmt|;
name|GRBlockCounter
argument_list|(
name|void
operator|*
name|D
argument_list|)
operator|:
name|Data
argument_list|(
argument|D
argument_list|)
block|{}
name|public
operator|:
name|GRBlockCounter
argument_list|()
operator|:
name|Data
argument_list|(
literal|0
argument_list|)
block|{}
name|unsigned
name|getNumVisited
argument_list|(
argument|unsigned BlockID
argument_list|)
specifier|const
expr_stmt|;
name|class
name|Factory
block|{
name|void
modifier|*
name|F
decl_stmt|;
name|public
label|:
name|Factory
argument_list|(
name|llvm
operator|::
name|BumpPtrAllocator
operator|&
name|Alloc
argument_list|)
expr_stmt|;
operator|~
name|Factory
argument_list|()
expr_stmt|;
name|GRBlockCounter
name|GetEmptyCounter
parameter_list|()
function_decl|;
name|GRBlockCounter
name|IncrementCount
parameter_list|(
name|GRBlockCounter
name|BC
parameter_list|,
name|unsigned
name|BlockID
parameter_list|)
function_decl|;
block|}
empty_stmt|;
name|friend
name|class
name|Factory
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

