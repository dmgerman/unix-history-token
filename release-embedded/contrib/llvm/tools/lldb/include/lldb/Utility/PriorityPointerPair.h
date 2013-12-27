begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PriorityPointerPair.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_PriorityPointerPair_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_PriorityPointerPair_h_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/SharingPtr.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_utility
block|{
comment|//----------------------------------------------------------------------
comment|// A prioritized pair of SharedPtr<T>. One of the two pointers is high
comment|// priority, the other is low priority.
comment|// The Get() method always returns high, if *high != NULL,
comment|// otherwise, low is returned (even if *low == NULL)
comment|//----------------------------------------------------------------------
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|PriorityPointerPair
block|{
name|public
operator|:
typedef|typedef
name|T
modifier|&
name|reference_type
typedef|;
typedef|typedef
name|T
modifier|*
name|pointer_type
typedef|;
typedef|typedef
name|typename
name|std
operator|::
name|shared_ptr
operator|<
name|T
operator|>
name|T_SP
expr_stmt|;
name|PriorityPointerPair
argument_list|()
operator|:
name|m_high
argument_list|()
operator|,
name|m_low
argument_list|()
block|{}
name|PriorityPointerPair
argument_list|(
argument|pointer_type high
argument_list|,
argument|pointer_type low
argument_list|)
operator|:
name|m_high
argument_list|(
name|high
argument_list|)
operator|,
name|m_low
argument_list|(
argument|low
argument_list|)
block|{}
name|PriorityPointerPair
argument_list|(
argument|pointer_type low
argument_list|)
operator|:
name|m_high
argument_list|()
operator|,
name|m_low
argument_list|(
argument|low
argument_list|)
block|{}
name|PriorityPointerPair
argument_list|(
name|T_SP
operator|&
name|high
argument_list|,
name|T_SP
operator|&
name|low
argument_list|)
operator|:
name|m_high
argument_list|(
name|high
argument_list|)
operator|,
name|m_low
argument_list|(
argument|low
argument_list|)
block|{}
name|PriorityPointerPair
argument_list|(
name|T_SP
operator|&
name|low
argument_list|)
operator|:
name|m_high
argument_list|()
operator|,
name|m_low
argument_list|(
argument|low
argument_list|)
block|{}
name|void
name|SwapLow
argument_list|(
argument|pointer_type l
argument_list|)
block|{
name|m_low
operator|.
name|swap
argument_list|(
name|l
argument_list|)
block|;     }
name|void
name|SwapHigh
argument_list|(
argument|pointer_type h
argument_list|)
block|{
name|m_high
operator|.
name|swap
argument_list|(
name|h
argument_list|)
block|;     }
name|void
name|SwapLow
argument_list|(
argument|T_SP l
argument_list|)
block|{
name|m_low
operator|.
name|swap
argument_list|(
name|l
argument_list|)
block|;     }
name|void
name|SwapHigh
argument_list|(
argument|T_SP h
argument_list|)
block|{
name|m_high
operator|.
name|swap
argument_list|(
name|h
argument_list|)
block|;     }
name|T_SP
name|GetLow
argument_list|()
block|{
return|return
name|m_low
return|;
block|}
name|T_SP
name|GetHigh
parameter_list|()
block|{
return|return
name|m_high
return|;
block|}
name|T_SP
name|Get
parameter_list|()
block|{
if|if
condition|(
name|m_high
operator|.
name|get
argument_list|()
condition|)
return|return
name|m_high
return|;
return|return
name|m_low
return|;
block|}
name|void
name|ResetHigh
parameter_list|()
block|{
name|m_high
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
name|void
name|ResetLow
parameter_list|()
block|{
name|m_low
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
name|void
name|Reset
parameter_list|()
block|{
name|ResetLow
argument_list|()
expr_stmt|;
name|ResetHigh
argument_list|()
expr_stmt|;
block|}
name|reference_type
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|Get
argument_list|()
operator|.
name|operator
operator|*
operator|(
operator|)
return|;
block|}
name|pointer_type
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|Get
argument_list|()
operator|.
name|operator
operator|->
expr|(
block|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|}          ~
name|PriorityPointerPair
argument_list|()
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|T_SP
name|m_high
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|T_SP
name|m_low
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|PriorityPointerPair
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};  }
comment|// namespace lldb_utility
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_PriorityPointerPair_h_
end_comment

end_unit

