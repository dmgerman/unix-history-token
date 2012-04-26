begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- llvm/ADT/SparseSet.h - Sparse set ----------------------*- C++ -*-===//
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
comment|// This file defines the SparseSet class derived from the version described in
end_comment

begin_comment
comment|// Briggs, Torczon, "An efficient representation for sparse sets", ACM Letters
end_comment

begin_comment
comment|// on Programming Languages and Systems, Volume 2 Issue 1-4, March-Dec.  1993.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A sparse set holds a small number of objects identified by integer keys from
end_comment

begin_comment
comment|// a moderately sized universe. The sparse set uses more memory than other
end_comment

begin_comment
comment|// containers in order to provide faster operations.
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
name|LLVM_ADT_SPARSESET_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_SPARSESET_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<limits>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// SparseSetFunctor - Objects in a SparseSet are identified by small integer
comment|/// keys.  A functor object is used to compute the key of an object.  The
comment|/// functor's operator() must return an unsigned smaller than the universe.
comment|///
comment|/// The default functor implementation forwards to a getSparseSetKey() method
comment|/// on the object.  It is intended for sparse sets holding ad-hoc structs.
comment|///
name|template
operator|<
name|typename
name|ValueT
operator|>
expr|struct
name|SparseSetFunctor
block|{
name|unsigned
name|operator
argument_list|()
operator|(
specifier|const
name|ValueT
operator|&
name|Val
operator|)
block|{
return|return
name|Val
operator|.
name|getSparseSetKey
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// SparseSetFunctor<unsigned> - Provide a trivial identity functor for
comment|/// SparseSet<unsigned>.
comment|///
name|template
operator|<
operator|>
expr|struct
name|SparseSetFunctor
operator|<
name|unsigned
operator|>
block|{
name|unsigned
name|operator
argument_list|()
operator|(
name|unsigned
name|Val
operator|)
block|{
return|return
name|Val
return|;
block|}
expr|}
block|;
comment|/// SparseSet - Fast set implementation for objects that can be identified by
comment|/// small unsigned keys.
comment|///
comment|/// SparseSet allocates memory proportional to the size of the key universe, so
comment|/// it is not recommended for building composite data structures.  It is useful
comment|/// for algorithms that require a single set with fast operations.
comment|///
comment|/// Compared to DenseSet and DenseMap, SparseSet provides constant-time fast
comment|/// clear() and iteration as fast as a vector.  The find(), insert(), and
comment|/// erase() operations are all constant time, and typically faster than a hash
comment|/// table.  The iteration order doesn't depend on numerical key values, it only
comment|/// depends on the order of insert() and erase() operations.  When no elements
comment|/// have been erased, the iteration order is the insertion order.
comment|///
comment|/// Compared to BitVector, SparseSet<unsigned> uses 8x-40x more memory, but
comment|/// offers constant-time clear() and size() operations as well as fast
comment|/// iteration independent on the size of the universe.
comment|///
comment|/// SparseSet contains a dense vector holding all the objects and a sparse
comment|/// array holding indexes into the dense vector.  Most of the memory is used by
comment|/// the sparse array which is the size of the key universe.  The SparseT
comment|/// template parameter provides a space/speed tradeoff for sets holding many
comment|/// elements.
comment|///
comment|/// When SparseT is uint32_t, find() only touches 2 cache lines, but the sparse
comment|/// array uses 4 x Universe bytes.
comment|///
comment|/// When SparseT is uint8_t (the default), find() touches up to 2+[N/256] cache
comment|/// lines, but the sparse array is 4x smaller.  N is the number of elements in
comment|/// the set.
comment|///
comment|/// For sets that may grow to thousands of elements, SparseT should be set to
comment|/// uint16_t or uint32_t.
comment|///
comment|/// @param ValueT      The type of objects in the set.
comment|/// @param SparseT     An unsigned integer type. See above.
comment|/// @param KeyFunctorT A functor that computes the unsigned key of a ValueT.
comment|///
name|template
operator|<
name|typename
name|ValueT
block|,
name|typename
name|SparseT
operator|=
name|uint8_t
block|,
name|typename
name|KeyFunctorT
operator|=
name|SparseSetFunctor
operator|<
name|ValueT
operator|>
expr|>
name|class
name|SparseSet
block|{
typedef|typedef
name|SmallVector
operator|<
name|ValueT
operator|,
literal|8
operator|>
name|DenseT
expr_stmt|;
name|DenseT
name|Dense
block|;
name|SparseT
operator|*
name|Sparse
block|;
name|unsigned
name|Universe
block|;
name|KeyFunctorT
name|KeyOf
block|;
comment|// Disable copy construction and assignment.
comment|// This data structure is not meant to be used that way.
name|SparseSet
argument_list|(
specifier|const
name|SparseSet
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT.
name|SparseSet
operator|&
name|operator
operator|=
operator|(
specifier|const
name|SparseSet
operator|&
operator|)
block|;
comment|// DO NOT IMPLEMENT.
name|public
operator|:
typedef|typedef
name|ValueT
name|value_type
typedef|;
typedef|typedef
name|ValueT
modifier|&
name|reference
typedef|;
typedef|typedef
specifier|const
name|ValueT
modifier|&
name|const_reference
typedef|;
typedef|typedef
name|ValueT
modifier|*
name|pointer
typedef|;
typedef|typedef
specifier|const
name|ValueT
modifier|*
name|const_pointer
typedef|;
name|SparseSet
argument_list|()
operator|:
name|Sparse
argument_list|(
literal|0
argument_list|)
operator|,
name|Universe
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|SparseSet
argument_list|()
block|{
name|free
argument_list|(
name|Sparse
argument_list|)
block|; }
comment|/// setUniverse - Set the universe size which determines the largest key the
comment|/// set can hold.  The universe must be sized before any elements can be
comment|/// added.
comment|///
comment|/// @param U Universe size. All object keys must be less than U.
comment|///
name|void
name|setUniverse
argument_list|(
argument|unsigned U
argument_list|)
block|{
comment|// It's not hard to resize the universe on a non-empty set, but it doesn't
comment|// seem like a likely use case, so we can add that code when we need it.
name|assert
argument_list|(
name|empty
argument_list|()
operator|&&
literal|"Can only resize universe on an empty map"
argument_list|)
block|;
comment|// Hysteresis prevents needless reallocations.
if|if
condition|(
name|U
operator|>=
name|Universe
operator|/
literal|4
operator|&&
name|U
operator|<=
name|Universe
condition|)
return|return;
name|free
argument_list|(
name|Sparse
argument_list|)
expr_stmt|;
comment|// The Sparse array doesn't actually need to be initialized, so malloc
comment|// would be enough here, but that will cause tools like valgrind to
comment|// complain about branching on uninitialized data.
name|Sparse
operator|=
name|reinterpret_cast
operator|<
name|SparseT
operator|*
operator|>
operator|(
name|calloc
argument_list|(
name|U
argument_list|,
sizeof|sizeof
argument_list|(
name|SparseT
argument_list|)
argument_list|)
operator|)
expr_stmt|;
name|Universe
operator|=
name|U
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// Import trivial vector stuff from DenseT.
end_comment

begin_typedef
typedef|typedef
name|typename
name|DenseT
operator|::
name|iterator
name|iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|DenseT
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Dense
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Dense
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|Dense
operator|.
name|begin
argument_list|()
return|;
block|}
end_function

begin_function
name|iterator
name|end
parameter_list|()
block|{
return|return
name|Dense
operator|.
name|end
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// empty - Returns true if the set is empty.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is not the same as BitVector::empty().
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Dense
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// size - Returns the number of elements in the set.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is not the same as BitVector::size() which returns the size of the
end_comment

begin_comment
comment|/// universe.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|Dense
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// clear - Clears the set.  This is a very fast constant time operation.
end_comment

begin_comment
comment|///
end_comment

begin_function
name|void
name|clear
parameter_list|()
block|{
comment|// Sparse does not need to be cleared, see find().
name|Dense
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/// find - Find an element by its key.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param   Key A valid key to find.
end_comment

begin_comment
comment|/// @returns An iterator to the element identified by key, or end().
end_comment

begin_comment
comment|///
end_comment

begin_function
name|iterator
name|find
parameter_list|(
name|unsigned
name|Key
parameter_list|)
block|{
name|assert
argument_list|(
name|Key
operator|<
name|Universe
operator|&&
literal|"Key out of range"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|std
operator|::
name|numeric_limits
operator|<
name|SparseT
operator|>
operator|::
name|is_integer
operator|&&
operator|!
name|std
operator|::
name|numeric_limits
operator|<
name|SparseT
operator|>
operator|::
name|is_signed
operator|&&
literal|"SparseT must be an unsigned integer type"
argument_list|)
expr_stmt|;
specifier|const
name|unsigned
name|Stride
init|=
name|std
operator|::
name|numeric_limits
operator|<
name|SparseT
operator|>
operator|::
name|max
argument_list|()
operator|+
literal|1u
decl_stmt|;
for|for
control|(
name|unsigned
name|i
init|=
name|Sparse
index|[
name|Key
index|]
init|,
name|e
init|=
name|size
argument_list|()
init|;
name|i
operator|<
name|e
condition|;
name|i
operator|+=
name|Stride
control|)
block|{
specifier|const
name|unsigned
name|FoundKey
init|=
name|KeyOf
argument_list|(
name|Dense
index|[
name|i
index|]
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|FoundKey
operator|<
name|Universe
operator|&&
literal|"Invalid key in set. Did object mutate?"
argument_list|)
expr_stmt|;
if|if
condition|(
name|Key
operator|==
name|FoundKey
condition|)
return|return
name|begin
argument_list|()
operator|+
name|i
return|;
comment|// Stride is 0 when SparseT>= unsigned.  We don't need to loop.
if|if
condition|(
operator|!
name|Stride
condition|)
break|break;
block|}
return|return
name|end
argument_list|()
return|;
block|}
end_function

begin_decl_stmt
name|const_iterator
name|find
argument_list|(
name|unsigned
name|Key
argument_list|)
decl|const
block|{
return|return
name|const_cast
operator|<
name|SparseSet
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|find
argument_list|(
name|Key
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// count - Returns true if this set contains an element identified by Key.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|bool
name|count
argument_list|(
name|unsigned
name|Key
argument_list|)
decl|const
block|{
return|return
name|find
argument_list|(
name|Key
argument_list|)
operator|!=
name|end
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// insert - Attempts to insert a new element.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If Val is successfully inserted, return (I, true), where I is an iterator
end_comment

begin_comment
comment|/// pointing to the newly inserted element.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If the set already contains an element with the same key as Val, return
end_comment

begin_comment
comment|/// (I, false), where I is an iterator pointing to the existing element.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Insertion invalidates all iterators.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|iterator
operator|,
name|bool
operator|>
name|insert
argument_list|(
argument|const ValueT&Val
argument_list|)
block|{
name|unsigned
name|Key
operator|=
name|KeyOf
argument_list|(
name|Val
argument_list|)
block|;
name|iterator
name|I
operator|=
name|find
argument_list|(
name|Key
argument_list|)
block|;
if|if
condition|(
name|I
operator|!=
name|end
argument_list|()
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|I
argument_list|,
name|false
argument_list|)
return|;
name|Sparse
index|[
name|Key
index|]
operator|=
name|size
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Dense
operator|.
name|push_back
argument_list|(
name|Val
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|end
argument_list|()
operator|-
literal|1
argument_list|,
name|true
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// array subscript - If an element already exists with this key, return it.
end_comment

begin_comment
comment|/// Otherwise, automatically construct a new value from Key, insert it,
end_comment

begin_comment
comment|/// and return the newly inserted element.
end_comment

begin_expr_stmt
unit|ValueT
operator|&
name|operator
index|[]
operator|(
name|unsigned
name|Key
operator|)
block|{
return|return
operator|*
name|insert
argument_list|(
name|ValueT
argument_list|(
name|Key
argument_list|)
argument_list|)
operator|.
name|first
return|;
block|}
end_expr_stmt

begin_comment
comment|/// erase - Erases an existing element identified by a valid iterator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This invalidates all iterators, but erase() returns an iterator pointing
end_comment

begin_comment
comment|/// to the next element.  This makes it possible to erase selected elements
end_comment

begin_comment
comment|/// while iterating over the set:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   for (SparseSet::iterator I = Set.begin(); I != Set.end();)
end_comment

begin_comment
comment|///     if (test(*I))
end_comment

begin_comment
comment|///       I = Set.erase(I);
end_comment

begin_comment
comment|///     else
end_comment

begin_comment
comment|///       ++I;
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that end() changes when elements are erased, unlike std::list.
end_comment

begin_comment
comment|///
end_comment

begin_function
name|iterator
name|erase
parameter_list|(
name|iterator
name|I
parameter_list|)
block|{
name|assert
argument_list|(
name|unsigned
argument_list|(
name|I
operator|-
name|begin
argument_list|()
argument_list|)
operator|<
name|size
argument_list|()
operator|&&
literal|"Invalid iterator"
argument_list|)
expr_stmt|;
if|if
condition|(
name|I
operator|!=
name|end
argument_list|()
operator|-
literal|1
condition|)
block|{
operator|*
name|I
operator|=
name|Dense
operator|.
name|back
argument_list|()
expr_stmt|;
name|unsigned
name|BackKey
init|=
name|KeyOf
argument_list|(
name|Dense
operator|.
name|back
argument_list|()
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|BackKey
operator|<
name|Universe
operator|&&
literal|"Invalid key in set. Did object mutate?"
argument_list|)
expr_stmt|;
name|Sparse
index|[
name|BackKey
index|]
operator|=
name|I
operator|-
name|begin
argument_list|()
expr_stmt|;
block|}
comment|// This depends on SmallVector::pop_back() not invalidating iterators.
comment|// std::vector::pop_back() doesn't give that guarantee.
name|Dense
operator|.
name|pop_back
argument_list|()
expr_stmt|;
return|return
name|I
return|;
block|}
end_function

begin_comment
comment|/// erase - Erases an element identified by Key, if it exists.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param   Key The key identifying the element to erase.
end_comment

begin_comment
comment|/// @returns True when an element was erased, false if no element was found.
end_comment

begin_comment
comment|///
end_comment

begin_function
name|bool
name|erase
parameter_list|(
name|unsigned
name|Key
parameter_list|)
block|{
name|iterator
name|I
init|=
name|find
argument_list|(
name|Key
argument_list|)
decl_stmt|;
if|if
condition|(
name|I
operator|==
name|end
argument_list|()
condition|)
return|return
name|false
return|;
name|erase
argument_list|(
name|I
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_function

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

