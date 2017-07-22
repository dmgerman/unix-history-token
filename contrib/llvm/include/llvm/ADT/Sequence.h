begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Sequence.h - Utility for producing sequences of values ---*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|/// This routine provides some synthesis utilities to produce sequences of
end_comment

begin_comment
comment|/// values. The names are intentionally kept very short as they tend to occur
end_comment

begin_comment
comment|/// in common and widely used contexts.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ADT_SEQUENCE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_SEQUENCE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/iterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<iterator>
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
name|namespace
name|detail
block|{
name|template
operator|<
name|typename
name|ValueT
operator|>
name|class
name|value_sequence_iterator
operator|:
name|public
name|iterator_facade_base
operator|<
name|value_sequence_iterator
operator|<
name|ValueT
operator|>
operator|,
name|std
operator|::
name|random_access_iterator_tag
operator|,
specifier|const
name|ValueT
operator|>
block|{
name|using
name|BaseT
operator|=
name|typename
name|value_sequence_iterator
operator|::
name|iterator_facade_base
block|;
name|ValueT
name|Value
block|;
name|public
operator|:
name|using
name|difference_type
operator|=
name|typename
name|BaseT
operator|::
name|difference_type
block|;
name|using
name|reference
operator|=
name|typename
name|BaseT
operator|::
name|reference
block|;
name|value_sequence_iterator
argument_list|()
operator|=
expr|default
block|;
name|value_sequence_iterator
argument_list|(
specifier|const
name|value_sequence_iterator
operator|&
argument_list|)
operator|=
expr|default
block|;
name|value_sequence_iterator
argument_list|(
name|value_sequence_iterator
operator|&&
name|Arg
argument_list|)
operator|:
name|Value
argument_list|(
argument|std::move(Arg.Value)
argument_list|)
block|{}
name|template
operator|<
name|typename
name|U
block|,
name|typename
name|Enabler
operator|=
name|decltype
argument_list|(
name|ValueT
argument_list|(
name|std
operator|::
name|declval
operator|<
name|U
operator|>
operator|(
operator|)
argument_list|)
argument_list|)
operator|>
name|value_sequence_iterator
argument_list|(
name|U
operator|&&
name|Value
argument_list|)
operator|:
name|Value
argument_list|(
argument|std::forward<U>(Value)
argument_list|)
block|{}
name|value_sequence_iterator
operator|&
name|operator
operator|+=
operator|(
name|difference_type
name|N
operator|)
block|{
name|Value
operator|+=
name|N
block|;
return|return
operator|*
name|this
return|;
block|}
name|value_sequence_iterator
operator|&
name|operator
operator|-=
operator|(
name|difference_type
name|N
operator|)
block|{
name|Value
operator|-=
name|N
block|;
return|return
operator|*
name|this
return|;
block|}
name|using
name|BaseT
operator|::
name|operator
operator|-
block|;
name|difference_type
name|operator
operator|-
operator|(
specifier|const
name|value_sequence_iterator
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|Value
operator|-
name|RHS
operator|.
name|Value
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|value_sequence_iterator
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|Value
operator|==
name|RHS
operator|.
name|Value
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|value_sequence_iterator
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|Value
operator|<
name|RHS
operator|.
name|Value
return|;
block|}
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|Value
return|;
block|}
expr|}
block|;  }
comment|// end namespace detail
name|template
operator|<
name|typename
name|ValueT
operator|>
name|iterator_range
operator|<
name|detail
operator|::
name|value_sequence_iterator
operator|<
name|ValueT
operator|>>
name|seq
argument_list|(
argument|ValueT Begin
argument_list|,
argument|ValueT End
argument_list|)
block|{
return|return
name|make_range
argument_list|(
name|detail
operator|::
name|value_sequence_iterator
operator|<
name|ValueT
operator|>
operator|(
name|Begin
operator|)
argument_list|,
name|detail
operator|::
name|value_sequence_iterator
operator|<
name|ValueT
operator|>
operator|(
name|End
operator|)
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ADT_SEQUENCE_H
end_comment

end_unit

