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
literal|0
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
literal|0
argument_list|)
block|{}
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

