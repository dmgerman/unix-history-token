begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/PriorityQueue.h - Priority queues ---------------*- C++ -*-===//
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
comment|// This file defines the PriorityQueue class.
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
name|LLVM_ADT_PRIORITY_QUEUE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_PRIORITY_QUEUE_H
end_define

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<queue>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// PriorityQueue - This class behaves like std::priority_queue and
comment|/// provides a few additional convenience functions.
comment|///
name|template
operator|<
name|class
name|T
operator|,
name|class
name|Sequence
operator|=
name|std
operator|::
name|vector
operator|<
name|T
operator|>
operator|,
name|class
name|Compare
operator|=
name|std
operator|::
name|less
operator|<
name|typename
name|Sequence
operator|::
name|value_type
operator|>
expr|>
name|class
name|PriorityQueue
operator|:
name|public
name|std
operator|::
name|priority_queue
operator|<
name|T
operator|,
name|Sequence
operator|,
name|Compare
operator|>
block|{
name|public
operator|:
name|explicit
name|PriorityQueue
argument_list|(
specifier|const
name|Compare
operator|&
name|compare
operator|=
name|Compare
argument_list|()
argument_list|,
specifier|const
name|Sequence
operator|&
name|sequence
operator|=
name|Sequence
argument_list|()
argument_list|)
operator|:
name|std
operator|::
name|priority_queue
operator|<
name|T
block|,
name|Sequence
block|,
name|Compare
operator|>
operator|(
name|compare
operator|,
name|sequence
operator|)
block|{}
name|template
operator|<
name|class
name|Iterator
operator|>
name|PriorityQueue
argument_list|(
argument|Iterator begin
argument_list|,
argument|Iterator end
argument_list|,
argument|const Compare&compare = Compare()
argument_list|,
argument|const Sequence&sequence = Sequence()
argument_list|)
operator|:
name|std
operator|::
name|priority_queue
operator|<
name|T
block|,
name|Sequence
block|,
name|Compare
operator|>
operator|(
name|begin
operator|,
name|end
operator|,
name|compare
operator|,
name|sequence
operator|)
block|{}
comment|/// erase_one - Erase one element from the queue, regardless of its
comment|/// position. This operation performs a linear search to find an element
comment|/// equal to t, but then uses all logarithmic-time algorithms to do
comment|/// the erase operation.
comment|///
name|void
name|erase_one
argument_list|(
argument|const T&t
argument_list|)
block|{
comment|// Linear-search to find the element.
name|typename
name|Sequence
operator|::
name|size_type
name|i
operator|=
name|std
operator|::
name|find
argument_list|(
name|this
operator|->
name|c
operator|.
name|begin
argument_list|()
argument_list|,
name|this
operator|->
name|c
operator|.
name|end
argument_list|()
argument_list|,
name|t
argument_list|)
operator|-
name|this
operator|->
name|c
operator|.
name|begin
argument_list|()
block|;
comment|// Logarithmic-time heap bubble-up.
while|while
condition|(
name|i
operator|!=
literal|0
condition|)
block|{
name|typename
name|Sequence
operator|::
name|size_type
name|parent
operator|=
operator|(
name|i
operator|-
literal|1
operator|)
operator|/
literal|2
expr_stmt|;
name|this
operator|->
name|c
index|[
name|i
index|]
operator|=
name|this
operator|->
name|c
index|[
name|parent
index|]
expr_stmt|;
name|i
operator|=
name|parent
expr_stmt|;
block|}
comment|// The element we want to remove is now at the root, so we can use
comment|// priority_queue's plain pop to remove it.
name|this
operator|->
name|pop
argument_list|()
expr_stmt|;
block|}
comment|/// reheapify - If an element in the queue has changed in a way that
comment|/// affects its standing in the comparison function, the queue's
comment|/// internal state becomes invalid. Calling reheapify() resets the
comment|/// queue's state, making it valid again. This operation has time
comment|/// complexity proportional to the number of elements in the queue,
comment|/// so don't plan to use it a lot.
comment|///
name|void
name|reheapify
argument_list|()
block|{
name|std
operator|::
name|make_heap
argument_list|(
name|this
operator|->
name|c
operator|.
name|begin
argument_list|()
argument_list|,
name|this
operator|->
name|c
operator|.
name|end
argument_list|()
argument_list|,
name|this
operator|->
name|comp
argument_list|)
block|;   }
comment|/// clear - Erase all elements from the queue.
comment|///
name|void
name|clear
argument_list|()
block|{
name|this
operator|->
name|c
operator|.
name|clear
argument_list|()
block|;   }
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

