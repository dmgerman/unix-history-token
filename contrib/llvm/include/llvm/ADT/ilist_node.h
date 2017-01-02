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

begin_include
include|#
directive|include
file|"llvm/ADT/ilist_node_base.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist_node_options.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|ilist_detail
block|{
struct_decl|struct
name|NodeAccess
struct_decl|;
block|}
comment|// end namespace ilist_detail
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
expr_stmt|;
name|template
operator|<
name|class
name|OptionsT
operator|>
name|class
name|ilist_sentinel
expr_stmt|;
comment|/// Implementation for an ilist node.
comment|///
comment|/// Templated on an appropriate \a ilist_detail::node_options, usually computed
comment|/// by \a ilist_detail::compute_node_options.
comment|///
comment|/// This is a wrapper around \a ilist_node_base whose main purpose is to
comment|/// provide type safety: you can't insert nodes of \a ilist_node_impl into the
comment|/// wrong \a simple_ilist or \a iplist.
name|template
operator|<
name|class
name|OptionsT
operator|>
name|class
name|ilist_node_impl
operator|:
name|OptionsT
operator|::
name|node_base_type
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
name|node_base_type
name|node_base_type
expr_stmt|;
typedef|typedef
name|typename
name|OptionsT
operator|::
name|list_base_type
name|list_base_type
expr_stmt|;
name|friend
name|typename
name|OptionsT
operator|::
name|list_base_type
expr_stmt|;
name|friend
block|struct
name|ilist_detail
operator|::
name|NodeAccess
expr_stmt|;
name|friend
name|class
name|ilist_sentinel
operator|<
name|OptionsT
operator|>
expr_stmt|;
name|friend
name|class
name|ilist_iterator
operator|<
name|OptionsT
operator|,
name|false
operator|,
name|false
operator|>
expr_stmt|;
name|friend
name|class
name|ilist_iterator
operator|<
name|OptionsT
operator|,
name|false
operator|,
name|true
operator|>
expr_stmt|;
name|friend
name|class
name|ilist_iterator
operator|<
name|OptionsT
operator|,
name|true
operator|,
name|false
operator|>
expr_stmt|;
name|friend
name|class
name|ilist_iterator
operator|<
name|OptionsT
operator|,
name|true
operator|,
name|true
operator|>
expr_stmt|;
name|protected
label|:
name|ilist_node_impl
argument_list|()
operator|=
expr|default
expr_stmt|;
typedef|typedef
name|ilist_iterator
operator|<
name|OptionsT
operator|,
name|false
operator|,
name|false
operator|>
name|self_iterator
expr_stmt|;
typedef|typedef
name|ilist_iterator
operator|<
name|OptionsT
operator|,
name|false
operator|,
name|true
operator|>
name|const_self_iterator
expr_stmt|;
typedef|typedef
name|ilist_iterator
operator|<
name|OptionsT
operator|,
name|true
operator|,
name|false
operator|>
name|reverse_self_iterator
expr_stmt|;
typedef|typedef
name|ilist_iterator
operator|<
name|OptionsT
operator|,
name|true
operator|,
name|true
operator|>
name|const_reverse_self_iterator
expr_stmt|;
name|private
label|:
name|ilist_node_impl
modifier|*
name|getPrev
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|ilist_node_impl
operator|*
operator|>
operator|(
name|node_base_type
operator|::
name|getPrev
argument_list|()
operator|)
return|;
block|}
name|ilist_node_impl
modifier|*
name|getNext
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|ilist_node_impl
operator|*
operator|>
operator|(
name|node_base_type
operator|::
name|getNext
argument_list|()
operator|)
return|;
block|}
specifier|const
name|ilist_node_impl
operator|*
name|getPrev
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|ilist_node_impl
operator|*
operator|>
operator|(
name|node_base_type
operator|::
name|getPrev
argument_list|()
operator|)
return|;
block|}
specifier|const
name|ilist_node_impl
operator|*
name|getNext
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|ilist_node_impl
operator|*
operator|>
operator|(
name|node_base_type
operator|::
name|getNext
argument_list|()
operator|)
return|;
block|}
name|void
name|setPrev
parameter_list|(
name|ilist_node_impl
modifier|*
name|N
parameter_list|)
block|{
name|node_base_type
operator|::
name|setPrev
argument_list|(
name|N
argument_list|)
expr_stmt|;
block|}
name|void
name|setNext
parameter_list|(
name|ilist_node_impl
modifier|*
name|N
parameter_list|)
block|{
name|node_base_type
operator|::
name|setNext
argument_list|(
name|N
argument_list|)
expr_stmt|;
block|}
name|public
label|:
name|self_iterator
name|getIterator
parameter_list|()
block|{
return|return
name|self_iterator
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
name|const_self_iterator
name|getIterator
argument_list|()
specifier|const
block|{
return|return
name|const_self_iterator
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
name|reverse_self_iterator
name|getReverseIterator
parameter_list|()
block|{
return|return
name|reverse_self_iterator
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
name|const_reverse_self_iterator
name|getReverseIterator
argument_list|()
specifier|const
block|{
return|return
name|const_reverse_self_iterator
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
comment|// Under-approximation, but always available for assertions.
name|using
name|node_base_type
operator|::
name|isKnownSentinel
expr_stmt|;
comment|/// Check whether this is the sentinel node.
comment|///
comment|/// This requires sentinel tracking to be explicitly enabled.  Use the
comment|/// ilist_sentinel_tracking<true> option to get this API.
name|bool
name|isSentinel
argument_list|()
specifier|const
block|{
name|static_assert
argument_list|(
name|OptionsT
operator|::
name|is_sentinel_tracking_explicit
argument_list|,
literal|"Use ilist_sentinel_tracking<true> to enable isSentinel()"
argument_list|)
block|;
return|return
name|node_base_type
operator|::
name|isSentinel
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// An intrusive list node.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A base class to enable membership in intrusive lists, including \a
end_comment

begin_comment
comment|/// simple_ilist, \a iplist, and \a ilist.  The first template parameter is the
end_comment

begin_comment
comment|/// \a value_type for the list.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// An ilist node can be configured with compile-time options to change
end_comment

begin_comment
comment|/// behaviour and/or add API.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// By default, an \a ilist_node knows whether it is the list sentinel (an
end_comment

begin_comment
comment|/// instance of \a ilist_sentinel) if and only if
end_comment

begin_comment
comment|/// LLVM_ENABLE_ABI_BREAKING_CHECKS.  The function \a isKnownSentinel() always
end_comment

begin_comment
comment|/// returns \c false tracking is off.  Sentinel tracking steals a bit from the
end_comment

begin_comment
comment|/// "prev" link, which adds a mask operation when decrementing an iterator, but
end_comment

begin_comment
comment|/// enables bug-finding assertions in \a ilist_iterator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// To turn sentinel tracking on all the time, pass in the
end_comment

begin_comment
comment|/// ilist_sentinel_tracking<true> template parameter.  This also enables the \a
end_comment

begin_comment
comment|/// isSentinel() function.  The same option must be passed to the intrusive
end_comment

begin_comment
comment|/// list.  (ilist_sentinel_tracking<false> turns sentinel tracking off all the
end_comment

begin_comment
comment|/// time.)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A type can inherit from ilist_node multiple times by passing in different
end_comment

begin_comment
comment|/// \a ilist_tag options.  This allows a single instance to be inserted into
end_comment

begin_comment
comment|/// multiple lists simultaneously, where each list is given the same tag.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \example
end_comment

begin_comment
comment|/// struct A {};
end_comment

begin_comment
comment|/// struct B {};
end_comment

begin_comment
comment|/// struct N : ilist_node<N, ilist_tag<A>>, ilist_node<N, ilist_tag<B>> {};
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// void foo() {
end_comment

begin_comment
comment|///   simple_ilist<N, ilist_tag<A>> ListA;
end_comment

begin_comment
comment|///   simple_ilist<N, ilist_tag<B>> ListB;
end_comment

begin_comment
comment|///   N N1;
end_comment

begin_comment
comment|///   ListA.push_back(N1);
end_comment

begin_comment
comment|///   ListB.push_back(N1);
end_comment

begin_comment
comment|/// }
end_comment

begin_comment
comment|/// \endexample
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// See \a is_valid_option for steps on adding a new option.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
name|class
operator|...
name|Options
operator|>
name|class
name|ilist_node
operator|:
name|public
name|ilist_node_impl
operator|<
name|typename
name|ilist_detail
operator|::
name|compute_node_options
operator|<
name|T
operator|,
name|Options
operator|...
operator|>
operator|::
name|type
operator|>
block|{
name|static_assert
argument_list|(
name|ilist_detail
operator|::
name|check_options
operator|<
name|Options
operator|...
operator|>
operator|::
name|value
argument_list|,
literal|"Unrecognized node option!"
argument_list|)
block|; }
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|namespace
name|ilist_detail
block|{
comment|/// An access class for ilist_node private API.
comment|///
comment|/// This gives access to the private parts of ilist nodes.  Nodes for an ilist
comment|/// should friend this class if they inherit privately from ilist_node.
comment|///
comment|/// Using this class outside of the ilist implementation is unsupported.
struct|struct
name|NodeAccess
block|{
name|protected
label|:
name|template
operator|<
name|class
name|OptionsT
operator|>
specifier|static
name|ilist_node_impl
operator|<
name|OptionsT
operator|>
operator|*
name|getNodePtr
argument_list|(
argument|typename OptionsT::pointer N
argument_list|)
block|{
return|return
name|N
return|;
block|}
name|template
operator|<
name|class
name|OptionsT
operator|>
specifier|static
specifier|const
name|ilist_node_impl
operator|<
name|OptionsT
operator|>
operator|*
name|getNodePtr
argument_list|(
argument|typename OptionsT::const_pointer N
argument_list|)
block|{
return|return
name|N
return|;
block|}
name|template
operator|<
name|class
name|OptionsT
operator|>
specifier|static
name|typename
name|OptionsT
operator|::
name|pointer
name|getValuePtr
argument_list|(
argument|ilist_node_impl<OptionsT> *N
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|typename
name|OptionsT
operator|::
name|pointer
operator|>
operator|(
name|N
operator|)
return|;
block|}
name|template
operator|<
name|class
name|OptionsT
operator|>
specifier|static
name|typename
name|OptionsT
operator|::
name|const_pointer
name|getValuePtr
argument_list|(
argument|const ilist_node_impl<OptionsT> *N
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|typename
name|OptionsT
operator|::
name|const_pointer
operator|>
operator|(
name|N
operator|)
return|;
block|}
name|template
operator|<
name|class
name|OptionsT
operator|>
specifier|static
name|ilist_node_impl
operator|<
name|OptionsT
operator|>
operator|*
name|getPrev
argument_list|(
argument|ilist_node_impl<OptionsT>&N
argument_list|)
block|{
return|return
name|N
operator|.
name|getPrev
argument_list|()
return|;
block|}
name|template
operator|<
name|class
name|OptionsT
operator|>
specifier|static
name|ilist_node_impl
operator|<
name|OptionsT
operator|>
operator|*
name|getNext
argument_list|(
argument|ilist_node_impl<OptionsT>&N
argument_list|)
block|{
return|return
name|N
operator|.
name|getNext
argument_list|()
return|;
block|}
name|template
operator|<
name|class
name|OptionsT
operator|>
specifier|static
specifier|const
name|ilist_node_impl
operator|<
name|OptionsT
operator|>
operator|*
name|getPrev
argument_list|(
argument|const ilist_node_impl<OptionsT>&N
argument_list|)
block|{
return|return
name|N
operator|.
name|getPrev
argument_list|()
return|;
block|}
name|template
operator|<
name|class
name|OptionsT
operator|>
specifier|static
specifier|const
name|ilist_node_impl
operator|<
name|OptionsT
operator|>
operator|*
name|getNext
argument_list|(
argument|const ilist_node_impl<OptionsT>&N
argument_list|)
block|{
return|return
name|N
operator|.
name|getNext
argument_list|()
return|;
block|}
block|}
struct|;
name|template
operator|<
name|class
name|OptionsT
operator|>
expr|struct
name|SpecificNodeAccess
operator|:
name|NodeAccess
block|{
name|protected
operator|:
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
name|const_pointer
name|const_pointer
expr_stmt|;
typedef|typedef
name|ilist_node_impl
operator|<
name|OptionsT
operator|>
name|node_type
expr_stmt|;
specifier|static
name|node_type
modifier|*
name|getNodePtr
parameter_list|(
name|pointer
name|N
parameter_list|)
block|{
return|return
name|NodeAccess
operator|::
name|getNodePtr
operator|<
name|OptionsT
operator|>
operator|(
name|N
operator|)
return|;
block|}
specifier|static
specifier|const
name|node_type
modifier|*
name|getNodePtr
parameter_list|(
name|const_pointer
name|N
parameter_list|)
block|{
return|return
name|NodeAccess
operator|::
name|getNodePtr
operator|<
name|OptionsT
operator|>
operator|(
name|N
operator|)
return|;
block|}
specifier|static
name|pointer
name|getValuePtr
parameter_list|(
name|node_type
modifier|*
name|N
parameter_list|)
block|{
return|return
name|NodeAccess
operator|::
name|getValuePtr
operator|<
name|OptionsT
operator|>
operator|(
name|N
operator|)
return|;
block|}
specifier|static
name|const_pointer
name|getValuePtr
parameter_list|(
specifier|const
name|node_type
modifier|*
name|N
parameter_list|)
block|{
return|return
name|NodeAccess
operator|::
name|getValuePtr
operator|<
name|OptionsT
operator|>
operator|(
name|N
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace ilist_detail
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|OptionsT
operator|>
name|class
name|ilist_sentinel
operator|:
name|public
name|ilist_node_impl
operator|<
name|OptionsT
operator|>
block|{
name|public
operator|:
name|ilist_sentinel
argument_list|()
block|{
name|this
operator|->
name|initializeSentinel
argument_list|()
block|;
name|reset
argument_list|()
block|;   }
name|void
name|reset
argument_list|()
block|{
name|this
operator|->
name|setPrev
argument_list|(
name|this
argument_list|)
block|;
name|this
operator|->
name|setNext
argument_list|(
name|this
argument_list|)
block|;   }
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|this
operator|==
name|this
operator|->
name|getPrev
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// An ilist node that can access its parent list.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Requires \c NodeTy to have \a getParent() to find the parent node, and the
end_comment

begin_comment
comment|/// \c ParentTy to have \a getSublistAccess() to get a reference to the list.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|NodeTy
operator|,
name|typename
name|ParentTy
operator|,
name|class
operator|...
name|Options
operator|>
name|class
name|ilist_node_with_parent
operator|:
name|public
name|ilist_node
operator|<
name|NodeTy
operator|,
name|Options
operator|...
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
end_expr_stmt

begin_comment
comment|/// \brief Get the previous node, or \c nullptr for the list head.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Get the next node, or \c nullptr for the list tail.
end_comment

begin_function
name|NodeTy
modifier|*
name|getNextNode
parameter_list|()
block|{
comment|// Should be separated to a reused function, but then we couldn't use auto
comment|// (and would need the type of the list).
specifier|const
specifier|auto
modifier|&
name|List
init|=
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
decl_stmt|;
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
end_function

begin_comment
comment|/// \brief Get the next node, or \c nullptr for the list tail.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
unit|};  }
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

