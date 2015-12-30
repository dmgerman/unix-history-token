begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/STLExtras.h - Useful STL related functions ------*- C++ -*-===//
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
comment|// This file contains some templates that are useful if you are working with the
end_comment

begin_comment
comment|// STL at all.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// No library is required when using these functions.
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
name|LLVM_ADT_STLEXTRAS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_STLEXTRAS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_comment
comment|// for std::all_of
end_comment

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

begin_comment
comment|// for std::size_t
end_comment

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_comment
comment|// for qsort
end_comment

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_comment
comment|// for std::pair
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|//===----------------------------------------------------------------------===//
comment|//     Extra additions to<functional>
comment|//===----------------------------------------------------------------------===//
name|template
operator|<
name|class
name|Ty
operator|>
expr|struct
name|identity
operator|:
name|public
name|std
operator|::
name|unary_function
operator|<
name|Ty
operator|,
name|Ty
operator|>
block|{
name|Ty
operator|&
name|operator
argument_list|()
operator|(
name|Ty
operator|&
name|self
operator|)
specifier|const
block|{
return|return
name|self
return|;
block|}
specifier|const
name|Ty
operator|&
name|operator
argument_list|()
operator|(
specifier|const
name|Ty
operator|&
name|self
operator|)
specifier|const
block|{
return|return
name|self
return|;
block|}
expr|}
block|;
name|template
operator|<
name|class
name|Ty
operator|>
expr|struct
name|less_ptr
operator|:
name|public
name|std
operator|::
name|binary_function
operator|<
name|Ty
block|,
name|Ty
block|,
name|bool
operator|>
block|{
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|Ty
operator|*
name|left
operator|,
specifier|const
name|Ty
operator|*
name|right
operator|)
specifier|const
block|{
return|return
operator|*
name|left
operator|<
operator|*
name|right
return|;
block|}
expr|}
block|;
name|template
operator|<
name|class
name|Ty
operator|>
expr|struct
name|greater_ptr
operator|:
name|public
name|std
operator|::
name|binary_function
operator|<
name|Ty
block|,
name|Ty
block|,
name|bool
operator|>
block|{
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|Ty
operator|*
name|left
operator|,
specifier|const
name|Ty
operator|*
name|right
operator|)
specifier|const
block|{
return|return
operator|*
name|right
operator|<
operator|*
name|left
return|;
block|}
expr|}
block|;
comment|/// An efficient, type-erasing, non-owning reference to a callable. This is
comment|/// intended for use as the type of a function parameter that is not used
comment|/// after the function in question returns.
comment|///
comment|/// This class does not own the callable, so it is not in general safe to store
comment|/// a function_ref.
name|template
operator|<
name|typename
name|Fn
operator|>
name|class
name|function_ref
block|;
name|template
operator|<
name|typename
name|Ret
block|,
name|typename
operator|...
name|Params
operator|>
name|class
name|function_ref
operator|<
name|Ret
argument_list|(
name|Params
operator|...
argument_list|)
operator|>
block|{
name|Ret
argument_list|(
argument|*callback
argument_list|)
operator|(
name|intptr_t
name|callable
operator|,
name|Params
operator|...
name|params
operator|)
block|;
name|intptr_t
name|callable
block|;
name|template
operator|<
name|typename
name|Callable
operator|>
specifier|static
name|Ret
name|callback_fn
argument_list|(
argument|intptr_t callable
argument_list|,
argument|Params ...params
argument_list|)
block|{
return|return
operator|(
operator|*
name|reinterpret_cast
operator|<
name|Callable
operator|*
operator|>
operator|(
name|callable
operator|)
operator|)
operator|(
name|std
operator|::
name|forward
operator|<
name|Params
operator|>
operator|(
name|params
operator|)
operator|...
operator|)
return|;
block|}
name|public
operator|:
name|template
operator|<
name|typename
name|Callable
operator|>
name|function_ref
argument_list|(
argument|Callable&&callable
argument_list|,
argument|typename std::enable_if<                    !std::is_same<typename std::remove_reference<Callable>::type
argument_list|,
argument|function_ref>::value>::type * = nullptr
argument_list|)
operator|:
name|callback
argument_list|(
argument|callback_fn<typename std::remove_reference<Callable>::type>
argument_list|)
block|,
name|callable
argument_list|(
argument|reinterpret_cast<intptr_t>(&callable)
argument_list|)
block|{}
name|Ret
name|operator
argument_list|()
operator|(
name|Params
operator|...
name|params
operator|)
specifier|const
block|{
return|return
name|callback
argument_list|(
name|callable
argument_list|,
name|std
operator|::
name|forward
operator|<
name|Params
operator|>
operator|(
name|params
operator|)
operator|...
argument_list|)
return|;
block|}
expr|}
block|;
comment|// deleter - Very very very simple method that is used to invoke operator
comment|// delete on something.  It is used like this:
comment|//
comment|//   for_each(V.begin(), B.end(), deleter<Interval>);
comment|//
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|void
name|deleter
argument_list|(
argument|T *Ptr
argument_list|)
block|{
name|delete
name|Ptr
block|; }
comment|//===----------------------------------------------------------------------===//
comment|//     Extra additions to<iterator>
comment|//===----------------------------------------------------------------------===//
comment|// mapped_iterator - This is a simple iterator adapter that causes a function to
comment|// be dereferenced whenever operator* is invoked on the iterator.
comment|//
name|template
operator|<
name|class
name|RootIt
block|,
name|class
name|UnaryFunc
operator|>
name|class
name|mapped_iterator
block|{
name|RootIt
name|current
block|;
name|UnaryFunc
name|Fn
block|;
name|public
operator|:
typedef|typedef
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|RootIt
operator|>
operator|::
name|iterator_category
name|iterator_category
expr_stmt|;
typedef|typedef
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|RootIt
operator|>
operator|::
name|difference_type
name|difference_type
expr_stmt|;
typedef|typedef
name|typename
name|UnaryFunc
operator|::
name|result_type
name|value_type
expr_stmt|;
typedef|typedef
name|void
name|pointer
typedef|;
comment|//typedef typename UnaryFunc::result_type *pointer;
typedef|typedef
name|void
name|reference
typedef|;
comment|// Can't modify value returned by fn
typedef|typedef
name|RootIt
name|iterator_type
typedef|;
specifier|inline
specifier|const
name|RootIt
operator|&
name|getCurrent
argument_list|()
specifier|const
block|{
return|return
name|current
return|;
block|}
specifier|inline
specifier|const
name|UnaryFunc
operator|&
name|getFunc
argument_list|()
specifier|const
block|{
return|return
name|Fn
return|;
block|}
specifier|inline
name|explicit
name|mapped_iterator
argument_list|(
argument|const RootIt&I
argument_list|,
argument|UnaryFunc F
argument_list|)
operator|:
name|current
argument_list|(
name|I
argument_list|)
operator|,
name|Fn
argument_list|(
argument|F
argument_list|)
block|{}
specifier|inline
name|value_type
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
comment|// All this work to do this
return|return
name|Fn
argument_list|(
operator|*
name|current
argument_list|)
return|;
comment|// little change
block|}
name|mapped_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|current
block|;
return|return
operator|*
name|this
return|;
block|}
name|mapped_iterator
operator|&
name|operator
operator|--
operator|(
operator|)
block|{
operator|--
name|current
block|;
return|return
operator|*
name|this
return|;
block|}
name|mapped_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|mapped_iterator
name|__tmp
operator|=
operator|*
name|this
block|;
operator|++
name|current
block|;
return|return
name|__tmp
return|;
block|}
name|mapped_iterator
name|operator
operator|--
operator|(
name|int
operator|)
block|{
name|mapped_iterator
name|__tmp
operator|=
operator|*
name|this
block|;
operator|--
name|current
block|;
return|return
name|__tmp
return|;
block|}
name|mapped_iterator
name|operator
operator|+
operator|(
name|difference_type
name|n
operator|)
specifier|const
block|{
return|return
name|mapped_iterator
argument_list|(
name|current
operator|+
name|n
argument_list|,
name|Fn
argument_list|)
return|;
block|}
name|mapped_iterator
operator|&
name|operator
operator|+=
operator|(
name|difference_type
name|n
operator|)
block|{
name|current
operator|+=
name|n
block|;
return|return
operator|*
name|this
return|;
block|}
name|mapped_iterator
name|operator
operator|-
operator|(
name|difference_type
name|n
operator|)
specifier|const
block|{
return|return
name|mapped_iterator
argument_list|(
name|current
operator|-
name|n
argument_list|,
name|Fn
argument_list|)
return|;
block|}
name|mapped_iterator
operator|&
name|operator
operator|-=
operator|(
name|difference_type
name|n
operator|)
block|{
name|current
operator|-=
name|n
block|;
return|return
operator|*
name|this
return|;
block|}
name|reference
name|operator
index|[]
argument_list|(
name|difference_type
name|n
argument_list|)
decl|const
block|{
return|return
operator|*
operator|(
operator|*
name|this
operator|+
name|n
operator|)
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|mapped_iterator
operator|&
name|X
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|X
operator|)
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|mapped_iterator
operator|&
name|X
operator|)
specifier|const
block|{
return|return
name|current
operator|==
name|X
operator|.
name|current
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|mapped_iterator
operator|&
name|X
operator|)
specifier|const
block|{
return|return
name|current
operator|<
name|X
operator|.
name|current
return|;
block|}
name|difference_type
name|operator
operator|-
operator|(
specifier|const
name|mapped_iterator
operator|&
name|X
operator|)
specifier|const
block|{
return|return
name|current
operator|-
name|X
operator|.
name|current
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|Iterator
operator|,
name|class
name|Func
operator|>
specifier|inline
name|mapped_iterator
operator|<
name|Iterator
operator|,
name|Func
operator|>
name|operator
operator|+
operator|(
name|typename
name|mapped_iterator
operator|<
name|Iterator
operator|,
name|Func
operator|>
operator|::
name|difference_type
name|N
operator|,
specifier|const
name|mapped_iterator
operator|<
name|Iterator
operator|,
name|Func
operator|>
operator|&
name|X
operator|)
block|{
return|return
name|mapped_iterator
operator|<
name|Iterator
operator|,
name|Func
operator|>
operator|(
name|X
operator|.
name|getCurrent
argument_list|()
operator|-
name|N
operator|,
name|X
operator|.
name|getFunc
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// map_iterator - Provide a convenient way to create mapped_iterators, just like
end_comment

begin_comment
comment|// make_pair is useful for creating pairs...
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ItTy
operator|,
name|class
name|FuncTy
operator|>
specifier|inline
name|mapped_iterator
operator|<
name|ItTy
operator|,
name|FuncTy
operator|>
name|map_iterator
argument_list|(
argument|const ItTy&I
argument_list|,
argument|FuncTy F
argument_list|)
block|{
return|return
name|mapped_iterator
operator|<
name|ItTy
operator|,
name|FuncTy
operator|>
operator|(
name|I
operator|,
name|F
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Metafunction to determine if type T has a member called rbegin().
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|has_rbegin
block|{
name|template
operator|<
name|typename
name|U
operator|>
specifier|static
name|char
argument_list|(
operator|&
name|f
argument_list|(
specifier|const
name|U
operator|&
argument_list|,
name|decltype
argument_list|(
operator|&
name|U
operator|::
name|rbegin
argument_list|)
argument_list|)
argument_list|)
index|[
literal|1
index|]
block|;
specifier|static
name|char
argument_list|(
operator|&
name|f
argument_list|(
operator|...
argument_list|)
argument_list|)
index|[
literal|2
index|]
block|;
specifier|const
specifier|static
name|bool
name|value
operator|=
sizeof|sizeof
argument_list|(
name|f
argument_list|(
name|std
operator|::
name|declval
operator|<
name|T
operator|>
operator|(
operator|)
argument_list|,
name|nullptr
argument_list|)
argument_list|)
operator|==
literal|1
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Returns an iterator_range over the given container which iterates in reverse.
end_comment

begin_comment
comment|// Note that the container must have rbegin()/rend() methods for this to work.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|ContainerTy
operator|>
name|auto
name|reverse
argument_list|(
argument|ContainerTy&&C
argument_list|,
argument|typename std::enable_if<has_rbegin<ContainerTy>::value>::type * =                  nullptr
argument_list|)
operator|->
name|decltype
argument_list|(
argument|make_range(C.rbegin(), C.rend())
argument_list|)
block|{
return|return
name|make_range
argument_list|(
name|C
operator|.
name|rbegin
argument_list|()
argument_list|,
name|C
operator|.
name|rend
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Returns a std::reverse_iterator wrapped around the given iterator.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|IteratorTy
operator|>
name|std
operator|::
name|reverse_iterator
operator|<
name|IteratorTy
operator|>
name|make_reverse_iterator
argument_list|(
argument|IteratorTy It
argument_list|)
block|{
return|return
name|std
operator|::
name|reverse_iterator
operator|<
name|IteratorTy
operator|>
operator|(
name|It
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Returns an iterator_range over the given container which iterates in reverse.
end_comment

begin_comment
comment|// Note that the container must have begin()/end() methods which return
end_comment

begin_comment
comment|// bidirectional iterators for this to work.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|ContainerTy
operator|>
name|auto
name|reverse
argument_list|(
argument|ContainerTy&&C
argument_list|,
argument|typename std::enable_if<!has_rbegin<ContainerTy>::value>::type * = nullptr
argument_list|)
operator|->
name|decltype
argument_list|(
argument|make_range(llvm::make_reverse_iterator(std::end(C)),                            llvm::make_reverse_iterator(std::begin(C)))
argument_list|)
block|{
return|return
name|make_range
argument_list|(
name|llvm
operator|::
name|make_reverse_iterator
argument_list|(
name|std
operator|::
name|end
argument_list|(
name|C
argument_list|)
argument_list|)
argument_list|,
name|llvm
operator|::
name|make_reverse_iterator
argument_list|(
name|std
operator|::
name|begin
argument_list|(
name|C
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//     Extra additions to<utility>
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// \brief Function object to check whether the first component of a std::pair
end_comment

begin_comment
comment|/// compares less than the first component of another std::pair.
end_comment

begin_struct
struct|struct
name|less_first
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|T
operator|&
name|lhs
operator|,
specifier|const
name|T
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
name|lhs
operator|.
name|first
operator|<
name|rhs
operator|.
name|first
return|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|/// \brief Function object to check whether the second component of a std::pair
end_comment

begin_comment
comment|/// compares less than the second component of another std::pair.
end_comment

begin_struct
struct|struct
name|less_second
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|T
operator|&
name|lhs
operator|,
specifier|const
name|T
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
name|lhs
operator|.
name|second
operator|<
name|rhs
operator|.
name|second
return|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|// A subset of N3658. More stuff can be added as-needed.
end_comment

begin_comment
comment|/// \brief Represents a compile-time sequence of integers.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
name|T
operator|...
name|I
operator|>
expr|struct
name|integer_sequence
block|{
typedef|typedef
name|T
name|value_type
typedef|;
specifier|static
name|LLVM_CONSTEXPR
name|size_t
name|size
argument_list|()
block|{
return|return
sizeof|sizeof...
argument_list|(
name|I
argument_list|)
return|;
block|}
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Alias for the common case of a sequence of size_ts.
end_comment

begin_expr_stmt
name|template
operator|<
name|size_t
operator|...
name|I
operator|>
expr|struct
name|index_sequence
operator|:
name|integer_sequence
operator|<
name|std
operator|::
name|size_t
operator|,
name|I
operator|...
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|std
operator|::
name|size_t
name|N
operator|,
name|std
operator|::
name|size_t
operator|...
name|I
operator|>
expr|struct
name|build_index_impl
operator|:
name|build_index_impl
operator|<
name|N
operator|-
literal|1
operator|,
name|N
operator|-
literal|1
operator|,
name|I
operator|...
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|std
operator|::
name|size_t
operator|...
name|I
operator|>
expr|struct
name|build_index_impl
operator|<
literal|0
operator|,
name|I
operator|...
operator|>
operator|:
name|index_sequence
operator|<
name|I
operator|...
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Creates a compile-time integer sequence for a parameter pack.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
operator|...
name|Ts
operator|>
expr|struct
name|index_sequence_for
operator|:
name|build_index_impl
operator|<
sizeof|sizeof...
argument_list|(
name|Ts
argument_list|)
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//     Extra additions for arrays
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// Find the length of an array.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
name|std
operator|::
name|size_t
name|N
operator|>
name|LLVM_CONSTEXPR
specifier|inline
name|size_t
name|array_lengthof
argument_list|(
argument|T (&)[N]
argument_list|)
block|{
return|return
name|N
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Adapt std::less<T> for array_pod_sort.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|int
name|array_pod_sort_comparator
argument_list|(
argument|const void *P1
argument_list|,
argument|const void *P2
argument_list|)
block|{
if|if
condition|(
name|std
operator|::
name|less
operator|<
name|T
operator|>
operator|(
operator|)
operator|(
operator|*
name|reinterpret_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|P1
operator|)
operator|,
operator|*
name|reinterpret_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|P2
operator|)
operator|)
condition|)
return|return
operator|-
literal|1
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|std
operator|::
name|less
operator|<
name|T
operator|>
operator|(
operator|)
operator|(
operator|*
name|reinterpret_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|P2
operator|)
operator|,
operator|*
name|reinterpret_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|P1
operator|)
operator|)
condition|)
return|return
literal|1
return|;
end_if

begin_return
return|return
literal|0
return|;
end_return

begin_comment
unit|}
comment|/// get_array_pod_sort_comparator - This is an internal helper function used to
end_comment

begin_comment
comment|/// get type deduction of T right.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|int
argument_list|(
argument|*get_array_pod_sort_comparator(const T&)
argument_list|)
operator|(
specifier|const
name|void
operator|*
operator|,
specifier|const
name|void
operator|*
operator|)
block|{
return|return
name|array_pod_sort_comparator
operator|<
name|T
operator|>
return|;
block|}
end_expr_stmt

begin_comment
comment|/// array_pod_sort - This sorts an array with the specified start and end
end_comment

begin_comment
comment|/// extent.  This is just like std::sort, except that it calls qsort instead of
end_comment

begin_comment
comment|/// using an inlined template.  qsort is slightly slower than std::sort, but
end_comment

begin_comment
comment|/// most sorts are not performance critical in LLVM and std::sort has to be
end_comment

begin_comment
comment|/// template instantiated for each type, leading to significant measured code
end_comment

begin_comment
comment|/// bloat.  This function should generally be used instead of std::sort where
end_comment

begin_comment
comment|/// possible.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function assumes that you have simple POD-like types that can be
end_comment

begin_comment
comment|/// compared with std::less and can be moved with memcpy.  If this isn't true,
end_comment

begin_comment
comment|/// you should use std::sort.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// NOTE: If qsort_r were portable, we could allow a custom comparator and
end_comment

begin_comment
comment|/// default to std::less.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|IteratorTy
operator|>
specifier|inline
name|void
name|array_pod_sort
argument_list|(
argument|IteratorTy Start
argument_list|,
argument|IteratorTy End
argument_list|)
block|{
comment|// Don't inefficiently call qsort with one element or trigger undefined
comment|// behavior with an empty sequence.
name|auto
name|NElts
operator|=
name|End
operator|-
name|Start
block|;
if|if
condition|(
name|NElts
operator|<=
literal|1
condition|)
return|return;
name|qsort
argument_list|(
operator|&
operator|*
name|Start
argument_list|,
name|NElts
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|Start
argument_list|)
argument_list|,
name|get_array_pod_sort_comparator
argument_list|(
operator|*
name|Start
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|class
name|IteratorTy
operator|>
specifier|inline
name|void
name|array_pod_sort
argument_list|(
argument|IteratorTy Start
argument_list|,
argument|IteratorTy End
argument_list|,
argument|int (*Compare)(         const typename std::iterator_traits<IteratorTy>::value_type *,         const typename std::iterator_traits<IteratorTy>::value_type *)
argument_list|)
block|{
comment|// Don't inefficiently call qsort with one element or trigger undefined
comment|// behavior with an empty sequence.
name|auto
name|NElts
operator|=
name|End
operator|-
name|Start
block|;
if|if
condition|(
name|NElts
operator|<=
literal|1
condition|)
return|return;
name|qsort
argument_list|(
operator|&
operator|*
name|Start
argument_list|,
name|NElts
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|Start
argument_list|)
argument_list|,
name|reinterpret_cast
operator|<
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
specifier|const
name|void
operator|*
argument_list|,
specifier|const
name|void
operator|*
argument_list|)
operator|>
operator|(
name|Compare
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//     Extra additions to<algorithm>
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// For a container of pointers, deletes the pointers and then clears the
end_comment

begin_comment
comment|/// container.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Container
operator|>
name|void
name|DeleteContainerPointers
argument_list|(
argument|Container&C
argument_list|)
block|{
for|for
control|(
name|typename
name|Container
operator|::
name|iterator
name|I
operator|=
name|C
operator|.
name|begin
argument_list|()
operator|,
name|E
operator|=
name|C
operator|.
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
name|delete
modifier|*
name|I
decl_stmt|;
name|C
operator|.
name|clear
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/// In a container of pairs (usually a map) whose second element is a pointer,
end_comment

begin_comment
comment|/// deletes the second elements and then clears the container.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Container
operator|>
name|void
name|DeleteContainerSeconds
argument_list|(
argument|Container&C
argument_list|)
block|{
for|for
control|(
name|typename
name|Container
operator|::
name|iterator
name|I
operator|=
name|C
operator|.
name|begin
argument_list|()
operator|,
name|E
operator|=
name|C
operator|.
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
name|delete
name|I
operator|->
name|second
decl_stmt|;
name|C
operator|.
name|clear
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/// Provide wrappers to std::all_of which take ranges instead of having to pass
end_comment

begin_comment
comment|/// begin/end explicitly.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|R
operator|,
name|class
name|UnaryPredicate
operator|>
name|bool
name|all_of
argument_list|(
argument|R&&Range
argument_list|,
argument|UnaryPredicate&&P
argument_list|)
block|{
return|return
name|std
operator|::
name|all_of
argument_list|(
name|Range
operator|.
name|begin
argument_list|()
argument_list|,
name|Range
operator|.
name|end
argument_list|()
argument_list|,
name|std
operator|::
name|forward
operator|<
name|UnaryPredicate
operator|>
operator|(
name|P
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Provide wrappers to std::any_of which take ranges instead of having to pass
end_comment

begin_comment
comment|/// begin/end explicitly.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|R
operator|,
name|class
name|UnaryPredicate
operator|>
name|bool
name|any_of
argument_list|(
argument|R&&Range
argument_list|,
argument|UnaryPredicate&&P
argument_list|)
block|{
return|return
name|std
operator|::
name|any_of
argument_list|(
name|Range
operator|.
name|begin
argument_list|()
argument_list|,
name|Range
operator|.
name|end
argument_list|()
argument_list|,
name|std
operator|::
name|forward
operator|<
name|UnaryPredicate
operator|>
operator|(
name|P
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Provide wrappers to std::find which take ranges instead of having to pass
end_comment

begin_comment
comment|/// begin/end explicitly.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|R
operator|,
name|class
name|T
operator|>
name|auto
name|find
argument_list|(
name|R
operator|&&
name|Range
argument_list|,
specifier|const
name|T
operator|&
name|val
argument_list|)
operator|->
name|decltype
argument_list|(
argument|Range.begin()
argument_list|)
block|{
return|return
name|std
operator|::
name|find
argument_list|(
name|Range
operator|.
name|begin
argument_list|()
argument_list|,
name|Range
operator|.
name|end
argument_list|()
argument_list|,
name|val
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//     Extra additions to<memory>
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Implement make_unique according to N3656.
end_comment

begin_comment
comment|/// \brief Constructs a `new T()` with the given args and returns a
end_comment

begin_comment
comment|///        `unique_ptr<T>` which owns the object.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Example:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     auto p = make_unique<int>();
end_comment

begin_comment
comment|///     auto p = make_unique<std::tuple<int, int>>(0, 1);
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
name|class
operator|...
name|Args
operator|>
name|typename
name|std
operator|::
name|enable_if
operator|<
operator|!
name|std
operator|::
name|is_array
operator|<
name|T
operator|>
operator|::
name|value
operator|,
name|std
operator|::
name|unique_ptr
operator|<
name|T
operator|>>
operator|::
name|type
name|make_unique
argument_list|(
argument|Args&&... args
argument_list|)
block|{
return|return
name|std
operator|::
name|unique_ptr
operator|<
name|T
operator|>
operator|(
name|new
name|T
argument_list|(
name|std
operator|::
name|forward
operator|<
name|Args
operator|>
operator|(
name|args
operator|)
operator|...
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Constructs a `new T[n]` with the given args and returns a
end_comment

begin_comment
comment|///        `unique_ptr<T[]>` which owns the object.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param n size of the new array.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Example:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     auto p = make_unique<int[]>(2); // value-initializes the array with 0's.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|typename
name|std
operator|::
name|enable_if
operator|<
name|std
operator|::
name|is_array
operator|<
name|T
operator|>
operator|::
name|value
operator|&&
name|std
operator|::
name|extent
operator|<
name|T
operator|>
operator|::
name|value
operator|==
literal|0
operator|,
name|std
operator|::
name|unique_ptr
operator|<
name|T
operator|>>
operator|::
name|type
name|make_unique
argument_list|(
argument|size_t n
argument_list|)
block|{
return|return
name|std
operator|::
name|unique_ptr
operator|<
name|T
operator|>
operator|(
name|new
name|typename
name|std
operator|::
name|remove_extent
operator|<
name|T
operator|>
operator|::
name|type
index|[
name|n
index|]
operator|(
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// This function isn't used and is only here to provide better compile errors.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
name|class
operator|...
name|Args
operator|>
name|typename
name|std
operator|::
name|enable_if
operator|<
name|std
operator|::
name|extent
operator|<
name|T
operator|>
operator|::
name|value
operator|!=
literal|0
operator|>
operator|::
name|type
name|make_unique
argument_list|(
name|Args
operator|&&
operator|...
argument_list|)
operator|=
name|delete
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|FreeDeleter
block|{
name|void
name|operator
argument_list|()
operator|(
name|void
operator|*
name|v
operator|)
block|{
operator|::
name|free
argument_list|(
name|v
argument_list|)
block|;   }
block|}
struct|;
end_struct

begin_expr_stmt
name|template
operator|<
name|typename
name|First
operator|,
name|typename
name|Second
operator|>
expr|struct
name|pair_hash
block|{
name|size_t
name|operator
argument_list|()
operator|(
specifier|const
name|std
operator|::
name|pair
operator|<
name|First
operator|,
name|Second
operator|>
operator|&
name|P
operator|)
specifier|const
block|{
return|return
name|std
operator|::
name|hash
operator|<
name|First
operator|>
operator|(
operator|)
operator|(
name|P
operator|.
name|first
operator|)
operator|*
literal|31
operator|+
name|std
operator|::
name|hash
operator|<
name|Second
operator|>
operator|(
operator|)
operator|(
name|P
operator|.
name|second
operator|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// A functor like C++14's std::less<void> in its absence.
end_comment

begin_struct
struct|struct
name|less
block|{
name|template
operator|<
name|typename
name|A
operator|,
name|typename
name|B
operator|>
name|bool
name|operator
argument_list|()
operator|(
name|A
operator|&&
name|a
operator|,
name|B
operator|&&
name|b
operator|)
specifier|const
block|{
return|return
name|std
operator|::
name|forward
operator|<
name|A
operator|>
operator|(
name|a
operator|)
operator|<
name|std
operator|::
name|forward
operator|<
name|B
operator|>
operator|(
name|b
operator|)
return|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|/// A functor like C++14's std::equal<void> in its absence.
end_comment

begin_struct
struct|struct
name|equal
block|{
name|template
operator|<
name|typename
name|A
operator|,
name|typename
name|B
operator|>
name|bool
name|operator
argument_list|()
operator|(
name|A
operator|&&
name|a
operator|,
name|B
operator|&&
name|b
operator|)
specifier|const
block|{
return|return
name|std
operator|::
name|forward
operator|<
name|A
operator|>
operator|(
name|a
operator|)
operator|==
name|std
operator|::
name|forward
operator|<
name|B
operator|>
operator|(
name|b
operator|)
return|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|/// Binary functor that adapts to any other binary functor after dereferencing
end_comment

begin_comment
comment|/// operands.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|deref
block|{
name|T
name|func
block|;
comment|// Could be further improved to cope with non-derivable functors and
comment|// non-binary functors (should be a variadic template member function
comment|// operator()).
name|template
operator|<
name|typename
name|A
block|,
name|typename
name|B
operator|>
name|auto
name|operator
argument_list|()
operator|(
name|A
operator|&
name|lhs
operator|,
name|B
operator|&
name|rhs
operator|)
specifier|const
operator|->
name|decltype
argument_list|(
argument|func(*lhs, *rhs)
argument_list|)
block|{
name|assert
argument_list|(
name|lhs
argument_list|)
block|;
name|assert
argument_list|(
name|rhs
argument_list|)
block|;
return|return
name|func
argument_list|(
operator|*
name|lhs
argument_list|,
operator|*
name|rhs
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};  }
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

