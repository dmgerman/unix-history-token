begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- llvm/ADT/ilist_node.h - Intrusive Linked List Helper ------*- C++ -*-==//
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
comment|// This file defines the ilist_node class template, which is a convenient
end_comment

begin_comment
comment|// base class for creating classes that can be used with ilists.
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
name|LLVM_ADT_ILIST_NODE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_ILIST_NODE_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|typename
name|NodeTy
operator|>
expr|struct
name|ilist_traits
expr_stmt|;
name|template
operator|<
name|typename
name|NodeTy
operator|>
expr|struct
name|ilist_embedded_sentinel_traits
expr_stmt|;
name|template
operator|<
name|typename
name|NodeTy
operator|>
expr|struct
name|ilist_half_embedded_sentinel_traits
expr_stmt|;
comment|/// ilist_half_node - Base class that provides prev services for sentinels.
comment|///
name|template
operator|<
name|typename
name|NodeTy
operator|>
name|class
name|ilist_half_node
block|{
name|friend
expr|struct
name|ilist_traits
operator|<
name|NodeTy
operator|>
block|;
name|friend
expr|struct
name|ilist_half_embedded_sentinel_traits
operator|<
name|NodeTy
operator|>
block|;
name|NodeTy
operator|*
name|Prev
block|;
name|protected
operator|:
name|NodeTy
operator|*
name|getPrev
argument_list|()
block|{
return|return
name|Prev
return|;
block|}
specifier|const
name|NodeTy
operator|*
name|getPrev
argument_list|()
specifier|const
block|{
return|return
name|Prev
return|;
block|}
name|void
name|setPrev
argument_list|(
argument|NodeTy *P
argument_list|)
block|{
name|Prev
operator|=
name|P
block|; }
name|ilist_half_node
argument_list|()
operator|:
name|Prev
argument_list|(
argument|nullptr
argument_list|)
block|{}
expr|}
block|;
name|template
operator|<
name|typename
name|NodeTy
operator|>
expr|struct
name|ilist_nextprev_traits
block|;
name|template
operator|<
name|typename
name|NodeTy
operator|>
name|class
name|ilist_iterator
block|;
comment|/// ilist_node - Base class that provides next/prev services for nodes
comment|/// that use ilist_nextprev_traits or ilist_default_traits.
comment|///
name|template
operator|<
name|typename
name|NodeTy
operator|>
name|class
name|ilist_node
operator|:
name|private
name|ilist_half_node
operator|<
name|NodeTy
operator|>
block|{
name|friend
expr|struct
name|ilist_nextprev_traits
operator|<
name|NodeTy
operator|>
block|;
name|friend
expr|struct
name|ilist_traits
operator|<
name|NodeTy
operator|>
block|;
name|friend
expr|struct
name|ilist_half_embedded_sentinel_traits
operator|<
name|NodeTy
operator|>
block|;
name|friend
expr|struct
name|ilist_embedded_sentinel_traits
operator|<
name|NodeTy
operator|>
block|;
name|NodeTy
operator|*
name|Next
block|;
name|NodeTy
operator|*
name|getNext
argument_list|()
block|{
return|return
name|Next
return|;
block|}
specifier|const
name|NodeTy
operator|*
name|getNext
argument_list|()
specifier|const
block|{
return|return
name|Next
return|;
block|}
name|void
name|setNext
argument_list|(
argument|NodeTy *N
argument_list|)
block|{
name|Next
operator|=
name|N
block|; }
name|protected
operator|:
name|ilist_node
argument_list|()
operator|:
name|Next
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|public
operator|:
name|ilist_iterator
operator|<
name|NodeTy
operator|>
name|getIterator
argument_list|()
block|{
comment|// FIXME: Stop downcasting to create the iterator (potential UB).
return|return
name|ilist_iterator
operator|<
name|NodeTy
operator|>
operator|(
name|static_cast
operator|<
name|NodeTy
operator|*
operator|>
operator|(
name|this
operator|)
operator|)
return|;
block|}
name|ilist_iterator
operator|<
specifier|const
name|NodeTy
operator|>
name|getIterator
argument_list|()
specifier|const
block|{
comment|// FIXME: Stop downcasting to create the iterator (potential UB).
return|return
name|ilist_iterator
operator|<
specifier|const
name|NodeTy
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|NodeTy
operator|*
operator|>
operator|(
name|this
operator|)
operator|)
return|;
block|}
expr|}
block|;
comment|/// An ilist node that can access its parent list.
comment|///
comment|/// Requires \c NodeTy to have \a getParent() to find the parent node, and the
comment|/// \c ParentTy to have \a getSublistAccess() to get a reference to the list.
name|template
operator|<
name|typename
name|NodeTy
block|,
name|typename
name|ParentTy
operator|>
name|class
name|ilist_node_with_parent
operator|:
name|public
name|ilist_node
operator|<
name|NodeTy
operator|>
block|{
name|protected
operator|:
name|ilist_node_with_parent
argument_list|()
operator|=
expr|default
block|;
name|private
operator|:
comment|/// Forward to NodeTy::getParent().
comment|///
comment|/// Note: do not use the name "getParent()".  We want a compile error
comment|/// (instead of recursion) when the subclass fails to implement \a
comment|/// getParent().
specifier|const
name|ParentTy
operator|*
name|getNodeParent
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
specifier|const
name|NodeTy
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getParent
argument_list|()
return|;
block|}
name|public
operator|:
comment|/// @name Adjacent Node Accessors
comment|/// @{
comment|/// \brief Get the previous node, or \c nullptr for the list head.
name|NodeTy
operator|*
name|getPrevNode
argument_list|()
block|{
comment|// Should be separated to a reused function, but then we couldn't use auto
comment|// (and would need the type of the list).
specifier|const
name|auto
operator|&
name|List
operator|=
name|getNodeParent
argument_list|()
operator|->*
operator|(
name|ParentTy
operator|::
name|getSublistAccess
argument_list|(
operator|(
name|NodeTy
operator|*
operator|)
name|nullptr
argument_list|)
operator|)
block|;
return|return
name|List
operator|.
name|getPrevNode
argument_list|(
operator|*
name|static_cast
operator|<
name|NodeTy
operator|*
operator|>
operator|(
name|this
operator|)
argument_list|)
return|;
block|}
comment|/// \brief Get the previous node, or \c nullptr for the list head.
specifier|const
name|NodeTy
operator|*
name|getPrevNode
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|ilist_node_with_parent
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getPrevNode
argument_list|()
return|;
block|}
comment|/// \brief Get the next node, or \c nullptr for the list tail.
name|NodeTy
operator|*
name|getNextNode
argument_list|()
block|{
comment|// Should be separated to a reused function, but then we couldn't use auto
comment|// (and would need the type of the list).
specifier|const
name|auto
operator|&
name|List
operator|=
name|getNodeParent
argument_list|()
operator|->*
operator|(
name|ParentTy
operator|::
name|getSublistAccess
argument_list|(
operator|(
name|NodeTy
operator|*
operator|)
name|nullptr
argument_list|)
operator|)
block|;
return|return
name|List
operator|.
name|getNextNode
argument_list|(
operator|*
name|static_cast
operator|<
name|NodeTy
operator|*
operator|>
operator|(
name|this
operator|)
argument_list|)
return|;
block|}
comment|/// \brief Get the next node, or \c nullptr for the list tail.
specifier|const
name|NodeTy
operator|*
name|getNextNode
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|ilist_node_with_parent
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getNextNode
argument_list|()
return|;
block|}
comment|/// @}
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

