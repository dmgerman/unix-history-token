begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/BreadthFirstIterator.h - Breadth First iterator -*- C++ -*-===//
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
comment|// This file builds on the ADT/GraphTraits.h file to build a generic breadth
end_comment

begin_comment
comment|// first graph iterator.  This file exposes the following functions/types:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// bf_begin/bf_end/bf_iterator
end_comment

begin_comment
comment|//   * Normal breadth-first iteration - visit a graph level-by-level.
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
name|LLVM_ADT_BREADTHFIRSTITERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_BREADTHFIRSTITERATOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/GraphTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/None.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_include
include|#
directive|include
file|<queue>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// bf_iterator_storage - A private class which is used to figure out where to
comment|// store the visited set. We only provide a non-external variant for now.
name|template
operator|<
name|class
name|SetType
operator|>
name|class
name|bf_iterator_storage
block|{
name|public
operator|:
name|SetType
name|Visited
block|; }
expr_stmt|;
comment|// The visited state for the iteration is a simple set.
name|template
operator|<
name|typename
name|NodeRef
operator|,
name|unsigned
name|SmallSize
operator|=
literal|8
operator|>
name|using
name|bf_iterator_default_set
operator|=
name|SmallPtrSet
operator|<
name|NodeRef
operator|,
name|SmallSize
operator|>
expr_stmt|;
comment|// Generic Breadth first search iterator.
name|template
operator|<
name|class
name|GraphT
operator|,
name|class
name|SetType
operator|=
name|bf_iterator_default_set
operator|<
name|typename
name|GraphTraits
operator|<
name|GraphT
operator|>
operator|::
name|NodeRef
operator|>
operator|,
name|class
name|GT
operator|=
name|GraphTraits
operator|<
name|GraphT
operator|>>
name|class
name|bf_iterator
operator|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
operator|,
name|typename
name|GT
operator|::
name|NodeRef
operator|>
operator|,
name|public
name|bf_iterator_storage
operator|<
name|SetType
operator|>
block|{
name|using
name|super
operator|=
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
block|,
name|typename
name|GT
operator|::
name|NodeRef
operator|>
block|;
name|using
name|NodeRef
operator|=
name|typename
name|GT
operator|::
name|NodeRef
block|;
name|using
name|ChildItTy
operator|=
name|typename
name|GT
operator|::
name|ChildIteratorType
block|;
comment|// First element is the node reference, second is the next child to visit.
name|using
name|QueueElement
operator|=
name|std
operator|::
name|pair
operator|<
name|NodeRef
block|,
name|Optional
operator|<
name|ChildItTy
operator|>>
block|;
comment|// Visit queue - used to maintain BFS ordering.
comment|// Optional<> because we need markers for levels.
name|std
operator|::
name|queue
operator|<
name|Optional
operator|<
name|QueueElement
operator|>>
name|VisitQueue
block|;
comment|// Current level.
name|unsigned
name|Level
block|;
name|private
operator|:
specifier|inline
name|bf_iterator
argument_list|(
argument|NodeRef Node
argument_list|)
block|{
name|this
operator|->
name|Visited
operator|.
name|insert
argument_list|(
name|Node
argument_list|)
block|;
name|Level
operator|=
literal|0
block|;
comment|// Also, insert a dummy node as marker.
name|VisitQueue
operator|.
name|push
argument_list|(
name|QueueElement
argument_list|(
name|Node
argument_list|,
name|None
argument_list|)
argument_list|)
block|;
name|VisitQueue
operator|.
name|push
argument_list|(
name|None
argument_list|)
block|;   }
specifier|inline
name|bf_iterator
argument_list|()
operator|=
expr|default
block|;
specifier|inline
name|void
name|toNext
argument_list|()
block|{
name|Optional
operator|<
name|QueueElement
operator|>
name|Head
operator|=
name|VisitQueue
operator|.
name|front
argument_list|()
block|;
name|QueueElement
name|H
operator|=
name|Head
operator|.
name|getValue
argument_list|()
block|;
name|NodeRef
name|Node
operator|=
name|H
operator|.
name|first
block|;
name|Optional
operator|<
name|ChildItTy
operator|>
operator|&
name|ChildIt
operator|=
name|H
operator|.
name|second
block|;
if|if
condition|(
operator|!
name|ChildIt
condition|)
name|ChildIt
operator|.
name|emplace
argument_list|(
name|GT
operator|::
name|child_begin
argument_list|(
name|Node
argument_list|)
argument_list|)
expr_stmt|;
while|while
condition|(
operator|*
name|ChildIt
operator|!=
name|GT
operator|::
name|child_end
argument_list|(
name|Node
argument_list|)
condition|)
block|{
name|NodeRef
name|Next
init|=
operator|*
operator|(
operator|*
name|ChildIt
operator|)
operator|++
decl_stmt|;
comment|// Already visited?
if|if
condition|(
name|this
operator|->
name|Visited
operator|.
name|insert
argument_list|(
name|Next
argument_list|)
operator|.
name|second
condition|)
name|VisitQueue
operator|.
name|push
argument_list|(
name|QueueElement
argument_list|(
name|Next
argument_list|,
name|None
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|VisitQueue
operator|.
name|pop
argument_list|()
expr_stmt|;
comment|// Go to the next element skipping markers if needed.
if|if
condition|(
operator|!
name|VisitQueue
operator|.
name|empty
argument_list|()
condition|)
block|{
name|Head
operator|=
name|VisitQueue
operator|.
name|front
argument_list|()
expr_stmt|;
if|if
condition|(
name|Head
operator|!=
name|None
condition|)
return|return;
name|Level
operator|+=
literal|1
expr_stmt|;
name|VisitQueue
operator|.
name|pop
argument_list|()
expr_stmt|;
comment|// Don't push another marker if this is the last
comment|// element.
if|if
condition|(
operator|!
name|VisitQueue
operator|.
name|empty
argument_list|()
condition|)
name|VisitQueue
operator|.
name|push
argument_list|(
name|None
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_decl_stmt
name|using
name|pointer
init|=
name|typename
name|super
operator|::
name|pointer
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Provide static begin and end methods as our public "constructors"
end_comment

begin_function
specifier|static
name|bf_iterator
name|begin
parameter_list|(
specifier|const
name|GraphT
modifier|&
name|G
parameter_list|)
block|{
return|return
name|bf_iterator
argument_list|(
name|GT
operator|::
name|getEntryNode
argument_list|(
name|G
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bf_iterator
name|end
parameter_list|(
specifier|const
name|GraphT
modifier|&
name|G
parameter_list|)
block|{
return|return
name|bf_iterator
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|bf_iterator
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|VisitQueue
operator|==
name|RHS
operator|.
name|VisitQueue
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|bf_iterator
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|RHS
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|NodeRef
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|VisitQueue
operator|.
name|front
argument_list|()
operator|->
name|first
return|;
block|}
end_expr_stmt

begin_comment
comment|// This is a nonstandard operator-> that dereferenfces the pointer an extra
end_comment

begin_comment
comment|// time so that you can actually call methods on the node, because the
end_comment

begin_comment
comment|// contained type is a pointer.
end_comment

begin_expr_stmt
name|NodeRef
name|operator
operator|->
expr|(
end_expr_stmt

begin_expr_stmt
unit|)
specifier|const
block|{
return|return
operator|*
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bf_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// Pre-increment
name|toNext
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bf_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// Post-increment
name|bf_iterator
name|ItCopy
operator|=
operator|*
name|this
block|;
operator|++
operator|*
name|this
block|;
return|return
name|ItCopy
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|unsigned
name|getLevel
argument_list|()
specifier|const
block|{
return|return
name|Level
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// Provide global constructors that automatically figure out correct types.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|bf_iterator
operator|<
name|T
operator|>
name|bf_begin
argument_list|(
argument|const T&G
argument_list|)
block|{
return|return
name|bf_iterator
operator|<
name|T
operator|>
operator|::
name|begin
argument_list|(
name|G
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|bf_iterator
operator|<
name|T
operator|>
name|bf_end
argument_list|(
argument|const T&G
argument_list|)
block|{
return|return
name|bf_iterator
operator|<
name|T
operator|>
operator|::
name|end
argument_list|(
name|G
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Provide an accessor method to use them in range-based patterns.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|iterator_range
operator|<
name|bf_iterator
operator|<
name|T
operator|>>
name|breadth_first
argument_list|(
argument|const T&G
argument_list|)
block|{
return|return
name|make_range
argument_list|(
name|bf_begin
argument_list|(
name|G
argument_list|)
argument_list|,
name|bf_end
argument_list|(
name|G
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ADT_BREADTHFIRSTITERATOR_H
end_comment

end_unit

