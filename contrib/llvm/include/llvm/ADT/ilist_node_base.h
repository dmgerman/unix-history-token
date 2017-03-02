begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/ilist_node_base.h - Intrusive List Node Base -----*- C++ -*-==//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ADT_ILIST_NODE_BASE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_ILIST_NODE_BASE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Base class for ilist nodes.
comment|///
comment|/// Optionally tracks whether this node is the sentinel.
name|template
operator|<
name|bool
name|EnableSentinelTracking
operator|>
name|class
name|ilist_node_base
expr_stmt|;
name|template
operator|<
operator|>
name|class
name|ilist_node_base
operator|<
name|false
operator|>
block|{
name|ilist_node_base
operator|*
name|Prev
operator|=
name|nullptr
block|;
name|ilist_node_base
operator|*
name|Next
operator|=
name|nullptr
block|;
name|public
operator|:
name|void
name|setPrev
argument_list|(
argument|ilist_node_base *Prev
argument_list|)
block|{
name|this
operator|->
name|Prev
operator|=
name|Prev
block|; }
name|void
name|setNext
argument_list|(
argument|ilist_node_base *Next
argument_list|)
block|{
name|this
operator|->
name|Next
operator|=
name|Next
block|; }
name|ilist_node_base
operator|*
name|getPrev
argument_list|()
specifier|const
block|{
return|return
name|Prev
return|;
block|}
name|ilist_node_base
operator|*
name|getNext
argument_list|()
specifier|const
block|{
return|return
name|Next
return|;
block|}
name|bool
name|isKnownSentinel
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|void
name|initializeSentinel
argument_list|()
block|{}
expr|}
block|;
name|template
operator|<
operator|>
name|class
name|ilist_node_base
operator|<
name|true
operator|>
block|{
name|PointerIntPair
operator|<
name|ilist_node_base
operator|*
block|,
literal|1
operator|>
name|PrevAndSentinel
block|;
name|ilist_node_base
operator|*
name|Next
operator|=
name|nullptr
block|;
name|public
operator|:
name|void
name|setPrev
argument_list|(
argument|ilist_node_base *Prev
argument_list|)
block|{
name|PrevAndSentinel
operator|.
name|setPointer
argument_list|(
name|Prev
argument_list|)
block|; }
name|void
name|setNext
argument_list|(
argument|ilist_node_base *Next
argument_list|)
block|{
name|this
operator|->
name|Next
operator|=
name|Next
block|; }
name|ilist_node_base
operator|*
name|getPrev
argument_list|()
specifier|const
block|{
return|return
name|PrevAndSentinel
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|ilist_node_base
operator|*
name|getNext
argument_list|()
specifier|const
block|{
return|return
name|Next
return|;
block|}
name|bool
name|isSentinel
argument_list|()
specifier|const
block|{
return|return
name|PrevAndSentinel
operator|.
name|getInt
argument_list|()
return|;
block|}
name|bool
name|isKnownSentinel
argument_list|()
specifier|const
block|{
return|return
name|isSentinel
argument_list|()
return|;
block|}
name|void
name|initializeSentinel
argument_list|()
block|{
name|PrevAndSentinel
operator|.
name|setInt
argument_list|(
name|true
argument_list|)
block|; }
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ADT_ILIST_NODE_BASE_H
end_comment

end_unit

