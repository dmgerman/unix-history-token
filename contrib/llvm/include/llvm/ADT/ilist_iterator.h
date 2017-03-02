begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/ilist_iterator.h - Intrusive List Iterator -------*- C++ -*-==//
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
name|LLVM_ADT_ILIST_ITERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_ILIST_ITERATOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ilist_node.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_include
include|#
directive|include
file|<type_traits>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|ilist_detail
block|{
comment|/// Find const-correct node types.
name|template
operator|<
name|class
name|OptionsT
operator|,
name|bool
name|IsConst
operator|>
expr|struct
name|IteratorTraits
expr_stmt|;
name|template
operator|<
name|class
name|OptionsT
operator|>
expr|struct
name|IteratorTraits
operator|<
name|OptionsT
operator|,
name|false
operator|>
block|{
typedef|typedef
name|typename
name|OptionsT
operator|::
name|value_type
name|value_type
expr_stmt|;
typedef|typedef
name|typename
name|OptionsT
operator|::
name|pointer
name|pointer
expr_stmt|;
typedef|typedef
name|typename
name|OptionsT
operator|::
name|reference
name|reference
expr_stmt|;
typedef|typedef
name|ilist_node_impl
operator|<
name|OptionsT
operator|>
operator|*
name|node_pointer
expr_stmt|;
typedef|typedef
name|ilist_node_impl
operator|<
name|OptionsT
operator|>
operator|&
name|node_reference
expr_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|class
name|OptionsT
operator|>
expr|struct
name|IteratorTraits
operator|<
name|OptionsT
operator|,
name|true
operator|>
block|{
typedef|typedef
specifier|const
name|typename
name|OptionsT
operator|::
name|value_type
name|value_type
expr_stmt|;
typedef|typedef
name|typename
name|OptionsT
operator|::
name|const_pointer
name|pointer
expr_stmt|;
typedef|typedef
name|typename
name|OptionsT
operator|::
name|const_reference
name|reference
expr_stmt|;
typedef|typedef
specifier|const
name|ilist_node_impl
operator|<
name|OptionsT
operator|>
operator|*
name|node_pointer
expr_stmt|;
typedef|typedef
specifier|const
name|ilist_node_impl
operator|<
name|OptionsT
operator|>
operator|&
name|node_reference
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|bool
name|IsReverse
operator|>
expr|struct
name|IteratorHelper
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|IteratorHelper
operator|<
name|false
operator|>
operator|:
name|ilist_detail
operator|::
name|NodeAccess
block|{
typedef|typedef
name|ilist_detail
operator|::
name|NodeAccess
name|Access
expr_stmt|;
name|template
operator|<
name|class
name|T
operator|>
specifier|static
name|void
name|increment
argument_list|(
argument|T *&I
argument_list|)
block|{
name|I
operator|=
name|Access
operator|::
name|getNext
argument_list|(
operator|*
name|I
argument_list|)
block|; }
name|template
operator|<
name|class
name|T
operator|>
specifier|static
name|void
name|decrement
argument_list|(
argument|T *&I
argument_list|)
block|{
name|I
operator|=
name|Access
operator|::
name|getPrev
argument_list|(
operator|*
name|I
argument_list|)
block|; }
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|IteratorHelper
operator|<
name|true
operator|>
operator|:
name|ilist_detail
operator|::
name|NodeAccess
block|{
typedef|typedef
name|ilist_detail
operator|::
name|NodeAccess
name|Access
expr_stmt|;
name|template
operator|<
name|class
name|T
operator|>
specifier|static
name|void
name|increment
argument_list|(
argument|T *&I
argument_list|)
block|{
name|I
operator|=
name|Access
operator|::
name|getPrev
argument_list|(
operator|*
name|I
argument_list|)
block|; }
name|template
operator|<
name|class
name|T
operator|>
specifier|static
name|void
name|decrement
argument_list|(
argument|T *&I
argument_list|)
block|{
name|I
operator|=
name|Access
operator|::
name|getNext
argument_list|(
operator|*
name|I
argument_list|)
block|; }
end_expr_stmt

begin_comment
unit|};  }
comment|// end namespace ilist_detail
end_comment

begin_comment
comment|/// Iterator for intrusive lists  based on ilist_node.
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|OptionsT
operator|,
name|bool
name|IsReverse
operator|,
name|bool
name|IsConst
operator|>
name|class
name|ilist_iterator
operator|:
name|ilist_detail
operator|::
name|SpecificNodeAccess
operator|<
name|OptionsT
operator|>
block|{
name|friend
name|ilist_iterator
operator|<
name|OptionsT
block|,
name|IsReverse
block|,
operator|!
name|IsConst
operator|>
block|;
name|friend
name|ilist_iterator
operator|<
name|OptionsT
block|,
operator|!
name|IsReverse
block|,
name|IsConst
operator|>
block|;
name|friend
name|ilist_iterator
operator|<
name|OptionsT
block|,
operator|!
name|IsReverse
block|,
operator|!
name|IsConst
operator|>
block|;
typedef|typedef
name|ilist_detail
operator|::
name|IteratorTraits
operator|<
name|OptionsT
operator|,
name|IsConst
operator|>
name|Traits
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|ilist_detail
operator|::
name|SpecificNodeAccess
operator|<
name|OptionsT
operator|>
name|Access
expr_stmt|;
end_typedef

begin_label
name|public
label|:
end_label

begin_typedef
typedef|typedef
name|typename
name|Traits
operator|::
name|value_type
name|value_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|Traits
operator|::
name|pointer
name|pointer
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|Traits
operator|::
name|reference
name|reference
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|ptrdiff_t
name|difference_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|bidirectional_iterator_tag
name|iterator_category
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|OptionsT
operator|::
name|const_pointer
name|const_pointer
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|OptionsT
operator|::
name|const_reference
name|const_reference
expr_stmt|;
end_typedef

begin_label
name|private
label|:
end_label

begin_typedef
typedef|typedef
name|typename
name|Traits
operator|::
name|node_pointer
name|node_pointer
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|Traits
operator|::
name|node_reference
name|node_reference
expr_stmt|;
end_typedef

begin_decl_stmt
name|node_pointer
name|NodePtr
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// Create from an ilist_node.
end_comment

begin_macro
name|explicit
end_macro

begin_macro
name|ilist_iterator
argument_list|(
argument|node_reference N
argument_list|)
end_macro

begin_macro
unit|:
name|NodePtr
argument_list|(
argument|&N
argument_list|)
end_macro

begin_block
block|{}
end_block

begin_macro
name|explicit
end_macro

begin_macro
name|ilist_iterator
argument_list|(
argument|pointer NP
argument_list|)
end_macro

begin_macro
unit|:
name|NodePtr
argument_list|(
argument|Access::getNodePtr(NP)
argument_list|)
end_macro

begin_block
block|{}
end_block

begin_macro
name|explicit
end_macro

begin_macro
name|ilist_iterator
argument_list|(
argument|reference NR
argument_list|)
end_macro

begin_macro
unit|:
name|NodePtr
argument_list|(
argument|Access::getNodePtr(&NR)
argument_list|)
end_macro

begin_block
block|{}
end_block

begin_expr_stmt
name|ilist_iterator
argument_list|()
operator|:
name|NodePtr
argument_list|(
argument|nullptr
argument_list|)
block|{}
comment|// This is templated so that we can allow constructing a const iterator from
comment|// a nonconst iterator...
name|template
operator|<
name|bool
name|RHSIsConst
operator|>
name|ilist_iterator
argument_list|(
argument|const ilist_iterator<OptionsT
argument_list|,
argument|IsReverse
argument_list|,
argument|RHSIsConst>&RHS
argument_list|,
argument|typename std::enable_if<IsConst || !RHSIsConst
argument_list|,
argument|void *>::type = nullptr
argument_list|)
operator|:
name|NodePtr
argument_list|(
argument|RHS.NodePtr
argument_list|)
block|{}
comment|// This is templated so that we can allow assigning to a const iterator from
comment|// a nonconst iterator...
name|template
operator|<
name|bool
name|RHSIsConst
operator|>
name|typename
name|std
operator|::
name|enable_if
operator|<
name|IsConst
operator|||
operator|!
name|RHSIsConst
operator|,
name|ilist_iterator
operator|&
operator|>
operator|::
name|type
name|operator
operator|=
operator|(
specifier|const
name|ilist_iterator
operator|<
name|OptionsT
operator|,
name|IsReverse
operator|,
name|RHSIsConst
operator|>
operator|&
name|RHS
operator|)
block|{
name|NodePtr
operator|=
name|RHS
operator|.
name|NodePtr
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Explicit conversion between forward/reverse iterators.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Translate between forward and reverse iterators without changing range
end_comment

begin_comment
comment|/// boundaries.  The resulting iterator will dereference (and have a handle)
end_comment

begin_comment
comment|/// to the previous node, which is somewhat unexpected; but converting the
end_comment

begin_comment
comment|/// two endpoints in a range will give the same range in reverse.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This matches std::reverse_iterator conversions.
end_comment

begin_decl_stmt
name|explicit
name|ilist_iterator
argument_list|(
specifier|const
name|ilist_iterator
operator|<
name|OptionsT
argument_list|,
operator|!
name|IsReverse
argument_list|,
name|IsConst
operator|>
operator|&
name|RHS
argument_list|)
range|:
name|ilist_iterator
argument_list|(
argument|++RHS.getReverse()
argument_list|)
block|{}
comment|/// Get a reverse iterator to the same node.
comment|///
comment|/// Gives a reverse iterator that will dereference (and have a handle) to the
comment|/// same node.  Converting the endpoint iterators in a range will give a
comment|/// different range; for range operations, use the explicit conversions.
name|ilist_iterator
operator|<
name|OptionsT
decl_stmt|, !
name|IsReverse
decl_stmt|,
name|IsConst
decl|>
name|getReverse
argument_list|()
decl|const
block|{
if|if
condition|(
name|NodePtr
condition|)
return|return
name|ilist_iterator
operator|<
name|OptionsT
operator|,
operator|!
name|IsReverse
operator|,
name|IsConst
operator|>
operator|(
operator|*
name|NodePtr
operator|)
return|;
return|return
name|ilist_iterator
operator|<
name|OptionsT
operator|,
operator|!
name|IsReverse
operator|,
name|IsConst
operator|>
operator|(
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Const-cast.
end_comment

begin_expr_stmt
name|ilist_iterator
operator|<
name|OptionsT
operator|,
name|IsReverse
operator|,
name|false
operator|>
name|getNonConst
argument_list|()
specifier|const
block|{
if|if
condition|(
name|NodePtr
condition|)
return|return
name|ilist_iterator
operator|<
name|OptionsT
operator|,
name|IsReverse
operator|,
name|false
operator|>
operator|(
name|const_cast
operator|<
name|typename
name|ilist_iterator
operator|<
name|OptionsT
operator|,
name|IsReverse
operator|,
name|false
operator|>
operator|::
name|node_reference
operator|>
operator|(
operator|*
name|NodePtr
operator|)
operator|)
return|;
end_expr_stmt

begin_return
return|return
name|ilist_iterator
operator|<
name|OptionsT
operator|,
name|IsReverse
operator|,
name|false
operator|>
operator|(
operator|)
return|;
end_return

begin_comment
unit|}
comment|// Accessors...
end_comment

begin_macro
unit|reference
name|operator
end_macro

begin_expr_stmt
operator|*
operator|(
operator|)
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|NodePtr
operator|->
name|isKnownSentinel
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|Access
operator|::
name|getValuePtr
argument_list|(
name|NodePtr
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|pointer
name|operator
operator|->
expr|(
end_expr_stmt

begin_expr_stmt
unit|)
specifier|const
block|{
return|return
operator|&
name|operator
operator|*
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Comparison operators
end_comment

begin_expr_stmt
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|ilist_iterator
operator|&
name|LHS
operator|,
specifier|const
name|ilist_iterator
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|NodePtr
operator|==
name|RHS
operator|.
name|NodePtr
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|ilist_iterator
operator|&
name|LHS
operator|,
specifier|const
name|ilist_iterator
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|NodePtr
operator|!=
name|RHS
operator|.
name|NodePtr
return|;
block|}
end_expr_stmt

begin_comment
comment|// Increment and decrement operators...
end_comment

begin_expr_stmt
name|ilist_iterator
operator|&
name|operator
operator|--
operator|(
operator|)
block|{
name|NodePtr
operator|=
name|IsReverse
operator|?
name|NodePtr
operator|->
name|getNext
argument_list|()
operator|:
name|NodePtr
operator|->
name|getPrev
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ilist_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|NodePtr
operator|=
name|IsReverse
operator|?
name|NodePtr
operator|->
name|getPrev
argument_list|()
operator|:
name|NodePtr
operator|->
name|getNext
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ilist_iterator
name|operator
operator|--
operator|(
name|int
operator|)
block|{
name|ilist_iterator
name|tmp
operator|=
operator|*
name|this
block|;
operator|--
operator|*
name|this
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ilist_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|ilist_iterator
name|tmp
operator|=
operator|*
name|this
block|;
operator|++
operator|*
name|this
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Get the underlying ilist_node.
end_comment

begin_expr_stmt
name|node_pointer
name|getNodePtr
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|node_pointer
operator|>
operator|(
name|NodePtr
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Check for end.  Only valid if ilist_sentinel_tracking<true>.
end_comment

begin_expr_stmt
name|bool
name|isEnd
argument_list|()
specifier|const
block|{
return|return
name|NodePtr
operator|?
name|NodePtr
operator|->
name|isSentinel
argument_list|()
operator|:
name|false
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|From
operator|>
expr|struct
name|simplify_type
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Allow ilist_iterators to convert into pointers to a node automatically when
end_comment

begin_comment
comment|/// used by the dyn_cast, cast, isa mechanisms...
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// FIXME: remove this, since there is no implicit conversion to NodeTy.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|OptionsT
operator|,
name|bool
name|IsConst
operator|>
expr|struct
name|simplify_type
operator|<
name|ilist_iterator
operator|<
name|OptionsT
operator|,
name|false
operator|,
name|IsConst
operator|>>
block|{
typedef|typedef
name|ilist_iterator
operator|<
name|OptionsT
operator|,
name|false
operator|,
name|IsConst
operator|>
name|iterator
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|iterator
operator|::
name|pointer
name|SimpleType
expr_stmt|;
end_typedef

begin_function
specifier|static
name|SimpleType
name|getSimplifiedValue
parameter_list|(
specifier|const
name|iterator
modifier|&
name|Node
parameter_list|)
block|{
return|return
operator|&
operator|*
name|Node
return|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|OptionsT
operator|,
name|bool
name|IsConst
operator|>
expr|struct
name|simplify_type
operator|<
specifier|const
name|ilist_iterator
operator|<
name|OptionsT
operator|,
name|false
operator|,
name|IsConst
operator|>>
operator|:
name|simplify_type
operator|<
name|ilist_iterator
operator|<
name|OptionsT
operator|,
name|false
operator|,
name|IsConst
operator|>>
block|{}
expr_stmt|;
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
comment|// LLVM_ADT_ILIST_ITERATOR_H
end_comment

end_unit

