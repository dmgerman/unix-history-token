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
file|<cstddef>
end_include

begin_comment
comment|// for std::size_t
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
name|less_ptr
operator|:
name|public
name|std
operator|::
name|binary_function
operator|<
name|Ty
operator|,
name|Ty
operator|,
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
specifier|static
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
typedef|typedef
name|mapped_iterator
operator|<
name|RootIt
operator|,
name|UnaryFunc
operator|>
name|_Self
expr_stmt|;
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
name|mapped_iterator
argument_list|(
specifier|const
name|mapped_iterator
operator|&
name|It
argument_list|)
operator|:
name|current
argument_list|(
name|It
operator|.
name|current
argument_list|)
operator|,
name|Fn
argument_list|(
argument|It.Fn
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
name|_Self
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
name|_Self
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
name|_Self
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|_Self
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
name|_Self
name|operator
operator|--
operator|(
name|int
operator|)
block|{
name|_Self
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
name|_Self
name|operator
operator|+
operator|(
name|difference_type
name|n
operator|)
specifier|const
block|{
return|return
name|_Self
argument_list|(
name|current
operator|+
name|n
argument_list|,
name|Fn
argument_list|)
return|;
block|}
name|_Self
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
name|_Self
name|operator
operator|-
operator|(
name|difference_type
name|n
operator|)
specifier|const
block|{
return|return
name|_Self
argument_list|(
name|current
operator|-
name|n
argument_list|,
name|Fn
argument_list|)
return|;
block|}
name|_Self
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
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|_Self
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
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|_Self
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
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|_Self
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
specifier|inline
name|difference_type
name|operator
operator|-
operator|(
specifier|const
name|_Self
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
name|_Iterator
operator|,
name|class
name|Func
operator|>
specifier|inline
name|mapped_iterator
operator|<
name|_Iterator
operator|,
name|Func
operator|>
name|operator
operator|+
operator|(
name|typename
name|mapped_iterator
operator|<
name|_Iterator
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
name|_Iterator
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
name|_Iterator
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
comment|// next/prior - These functions unlike std::advance do not modify the
end_comment

begin_comment
comment|// passed iterator but return a copy.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// next(myIt) returns copy of myIt incremented once
end_comment

begin_comment
comment|// next(myIt, n) returns copy of myIt incremented n times
end_comment

begin_comment
comment|// prior(myIt) returns copy of myIt decremented once
end_comment

begin_comment
comment|// prior(myIt, n) returns copy of myIt decremented n times
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|ItTy
operator|,
name|typename
name|Dist
operator|>
specifier|inline
name|ItTy
name|next
argument_list|(
argument|ItTy it
argument_list|,
argument|Dist n
argument_list|)
block|{
name|std
operator|::
name|advance
argument_list|(
name|it
argument_list|,
name|n
argument_list|)
block|;
return|return
name|it
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|ItTy
operator|>
specifier|inline
name|ItTy
name|next
argument_list|(
argument|ItTy it
argument_list|)
block|{
return|return
operator|++
name|it
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|ItTy
operator|,
name|typename
name|Dist
operator|>
specifier|inline
name|ItTy
name|prior
argument_list|(
argument|ItTy it
argument_list|,
argument|Dist n
argument_list|)
block|{
name|std
operator|::
name|advance
argument_list|(
name|it
argument_list|,
operator|-
name|n
argument_list|)
block|;
return|return
name|it
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|ItTy
operator|>
specifier|inline
name|ItTy
name|prior
argument_list|(
argument|ItTy it
argument_list|)
block|{
return|return
operator|--
name|it
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
comment|// tie - this function ties two objects and returns a temporary object
end_comment

begin_comment
comment|// that is assignable from a std::pair. This can be used to make code
end_comment

begin_comment
comment|// more readable when using values returned from functions bundled in
end_comment

begin_comment
comment|// a std::pair. Since an example is worth 1000 words:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// typedef std::map<int, int> Int2IntMap;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Int2IntMap myMap;
end_comment

begin_comment
comment|// Int2IntMap::iterator where;
end_comment

begin_comment
comment|// bool inserted;
end_comment

begin_comment
comment|// tie(where, inserted) = myMap.insert(std::make_pair(123,456));
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// if (inserted)
end_comment

begin_comment
comment|//   // do stuff
end_comment

begin_comment
comment|// else
end_comment

begin_comment
comment|//   // do other stuff
end_comment

begin_macro
name|namespace
end_macro

begin_block
block|{
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
expr|struct
name|tier
block|{
typedef|typedef
name|T1
modifier|&
name|first_type
typedef|;
typedef|typedef
name|T2
modifier|&
name|second_type
typedef|;
name|first_type
name|first
decl_stmt|;
name|second_type
name|second
decl_stmt|;
name|tier
argument_list|(
argument|first_type f
argument_list|,
argument|second_type s
argument_list|)
block|:
name|first
argument_list|(
name|f
argument_list|)
operator|,
name|second
argument_list|(
argument|s
argument_list|)
block|{ }
name|tier
operator|&
name|operator
operator|=
operator|(
specifier|const
name|std
operator|::
name|pair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|p
operator|)
block|{
name|first
operator|=
name|p
operator|.
name|first
block|;
name|second
operator|=
name|p
operator|.
name|second
block|;
return|return
operator|*
name|this
return|;
block|}
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
specifier|inline
name|tier
operator|<
name|T1
operator|,
name|T2
operator|>
name|tie
argument_list|(
argument|T1& f
argument_list|,
argument|T2& s
argument_list|)
block|{
return|return
name|tier
operator|<
name|T1
operator|,
name|T2
operator|>
operator|(
name|f
operator|,
name|s
operator|)
return|;
block|}
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
comment|/// Find where an array ends (for ending iterators)
end_comment

begin_comment
comment|/// This returns a pointer to the byte immediately
end_comment

begin_comment
comment|/// after the end of an array.
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
specifier|inline
name|T
operator|*
name|array_endof
argument_list|(
argument|T (&x)[N]
argument_list|)
block|{
return|return
name|x
operator|+
name|N
return|;
block|}
end_expr_stmt

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
specifier|inline
name|size_t
name|array_lengthof
argument_list|(
argument|T (&x)[N]
argument_list|)
block|{
return|return
name|N
return|;
block|}
end_expr_stmt

begin_comment
comment|/// array_pod_sort_comparator - This is helper function for array_pod_sort,
end_comment

begin_comment
comment|/// which just uses operator< on T.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
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
operator|<
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
condition|)
return|return
operator|-
literal|1
return|;
end_expr_stmt

begin_if
if|if
condition|(
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
operator|<
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
comment|/// get_array_pad_sort_comparator - This is an internal helper function used to
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
specifier|static
name|int
argument_list|(
argument|*get_array_pad_sort_comparator(const T&X)
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
comment|/// compared with operator< and can be moved with memcpy.  If this isn't true,
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
specifier|static
specifier|inline
name|void
name|array_pod_sort
argument_list|(
argument|IteratorTy Start
argument_list|,
argument|IteratorTy End
argument_list|)
block|{
comment|// Don't dereference start iterator of empty sequence.
if|if
condition|(
name|Start
operator|==
name|End
condition|)
return|return;
name|qsort
argument_list|(
operator|&
operator|*
name|Start
argument_list|,
name|End
operator|-
name|Start
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|Start
argument_list|)
argument_list|,
name|get_array_pad_sort_comparator
argument_list|(
operator|*
name|Start
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}  }
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

