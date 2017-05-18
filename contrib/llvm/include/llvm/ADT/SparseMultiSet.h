begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/SparseMultiSet.h - Sparse multiset --------------*- C++ -*-===//
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
comment|// This file defines the SparseMultiSet class, which adds multiset behavior to
end_comment

begin_comment
comment|// the SparseSet.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A sparse multiset holds a small number of objects identified by integer keys
end_comment

begin_comment
comment|// from a moderately sized universe. The sparse multiset uses more memory than
end_comment

begin_comment
comment|// other containers in order to provide faster operations. Any key can map to
end_comment

begin_comment
comment|// multiple values. A SparseMultiSetNode class is provided, which serves as a
end_comment

begin_comment
comment|// convenient base class for the contents of a SparseMultiSet.
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
name|LLVM_ADT_SPARSEMULTISET_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_SPARSEMULTISET_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SparseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_include
include|#
directive|include
file|<limits>
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
comment|/// Fast multiset implementation for objects that can be identified by small
comment|/// unsigned keys.
comment|///
comment|/// SparseMultiSet allocates memory proportional to the size of the key
comment|/// universe, so it is not recommended for building composite data structures.
comment|/// It is useful for algorithms that require a single set with fast operations.
comment|///
comment|/// Compared to DenseSet and DenseMap, SparseMultiSet provides constant-time
comment|/// fast clear() as fast as a vector.  The find(), insert(), and erase()
comment|/// operations are all constant time, and typically faster than a hash table.
comment|/// The iteration order doesn't depend on numerical key values, it only depends
comment|/// on the order of insert() and erase() operations.  Iteration order is the
comment|/// insertion order. Iteration is only provided over elements of equivalent
comment|/// keys, but iterators are bidirectional.
comment|///
comment|/// Compared to BitVector, SparseMultiSet<unsigned> uses 8x-40x more memory, but
comment|/// offers constant-time clear() and size() operations as well as fast iteration
comment|/// independent on the size of the universe.
comment|///
comment|/// SparseMultiSet contains a dense vector holding all the objects and a sparse
comment|/// array holding indexes into the dense vector.  Most of the memory is used by
comment|/// the sparse array which is the size of the key universe. The SparseT template
comment|/// parameter provides a space/speed tradeoff for sets holding many elements.
comment|///
comment|/// When SparseT is uint32_t, find() only touches up to 3 cache lines, but the
comment|/// sparse array uses 4 x Universe bytes.
comment|///
comment|/// When SparseT is uint8_t (the default), find() touches up to 3+[N/256] cache
comment|/// lines, but the sparse array is 4x smaller.  N is the number of elements in
comment|/// the set.
comment|///
comment|/// For sets that may grow to thousands of elements, SparseT should be set to
comment|/// uint16_t or uint32_t.
comment|///
comment|/// Multiset behavior is provided by providing doubly linked lists for values
comment|/// that are inlined in the dense vector. SparseMultiSet is a good choice when
comment|/// one desires a growable number of entries per key, as it will retain the
comment|/// SparseSet algorithmic properties despite being growable. Thus, it is often a
comment|/// better choice than a SparseSet of growable containers or a vector of
comment|/// vectors. SparseMultiSet also keeps iterators valid after erasure (provided
comment|/// the iterators don't point to the element erased), allowing for more
comment|/// intuitive and fast removal.
comment|///
comment|/// @tparam ValueT      The type of objects in the set.
comment|/// @tparam KeyFunctorT A functor that computes an unsigned index from KeyT.
comment|/// @tparam SparseT     An unsigned integer type. See above.
comment|///
name|template
operator|<
name|typename
name|ValueT
operator|,
name|typename
name|KeyFunctorT
operator|=
name|identity
operator|<
name|unsigned
operator|>
operator|,
name|typename
name|SparseT
operator|=
name|uint8_t
operator|>
name|class
name|SparseMultiSet
block|{
name|static_assert
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
argument_list|,
literal|"SparseT must be an unsigned integer type"
argument_list|)
block|;
comment|/// The actual data that's stored, as a doubly-linked list implemented via
comment|/// indices into the DenseVector.  The doubly linked list is implemented
comment|/// circular in Prev indices, and INVALID-terminated in Next indices. This
comment|/// provides efficient access to list tails. These nodes can also be
comment|/// tombstones, in which case they are actually nodes in a single-linked
comment|/// freelist of recyclable slots.
block|struct
name|SMSNode
block|{
specifier|static
specifier|const
name|unsigned
name|INVALID
operator|=
operator|~
literal|0U
block|;
name|ValueT
name|Data
block|;
name|unsigned
name|Prev
block|;
name|unsigned
name|Next
block|;
name|SMSNode
argument_list|(
argument|ValueT D
argument_list|,
argument|unsigned P
argument_list|,
argument|unsigned N
argument_list|)
operator|:
name|Data
argument_list|(
name|D
argument_list|)
block|,
name|Prev
argument_list|(
name|P
argument_list|)
block|,
name|Next
argument_list|(
argument|N
argument_list|)
block|{}
comment|/// List tails have invalid Nexts.
name|bool
name|isTail
argument_list|()
specifier|const
block|{
return|return
name|Next
operator|==
name|INVALID
return|;
block|}
comment|/// Whether this node is a tombstone node, and thus is in our freelist.
name|bool
name|isTombstone
argument_list|()
specifier|const
block|{
return|return
name|Prev
operator|==
name|INVALID
return|;
block|}
comment|/// Since the list is circular in Prev, all non-tombstone nodes have a valid
comment|/// Prev.
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|Prev
operator|!=
name|INVALID
return|;
block|}
expr|}
block|;
name|using
name|KeyT
operator|=
name|typename
name|KeyFunctorT
operator|::
name|argument_type
block|;
name|using
name|DenseT
operator|=
name|SmallVector
operator|<
name|SMSNode
block|,
literal|8
operator|>
block|;
name|DenseT
name|Dense
block|;
name|SparseT
operator|*
name|Sparse
operator|=
name|nullptr
block|;
name|unsigned
name|Universe
operator|=
literal|0
block|;
name|KeyFunctorT
name|KeyIndexOf
block|;
name|SparseSetValFunctor
operator|<
name|KeyT
block|,
name|ValueT
block|,
name|KeyFunctorT
operator|>
name|ValIndexOf
block|;
comment|/// We have a built-in recycler for reusing tombstone slots. This recycler
comment|/// puts a singly-linked free list into tombstone slots, allowing us quick
comment|/// erasure, iterator preservation, and dense size.
name|unsigned
name|FreelistIdx
operator|=
name|SMSNode
operator|::
name|INVALID
block|;
name|unsigned
name|NumFree
operator|=
literal|0
block|;
name|unsigned
name|sparseIndex
argument_list|(
argument|const ValueT&Val
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|ValIndexOf
argument_list|(
name|Val
argument_list|)
operator|<
name|Universe
operator|&&
literal|"Invalid key in set. Did object mutate?"
argument_list|)
block|;
return|return
name|ValIndexOf
argument_list|(
name|Val
argument_list|)
return|;
block|}
name|unsigned
name|sparseIndex
argument_list|(
argument|const SMSNode&N
argument_list|)
specifier|const
block|{
return|return
name|sparseIndex
argument_list|(
name|N
operator|.
name|Data
argument_list|)
return|;
block|}
comment|/// Whether the given entry is the head of the list. List heads's previous
comment|/// pointers are to the tail of the list, allowing for efficient access to the
comment|/// list tail. D must be a valid entry node.
name|bool
name|isHead
argument_list|(
argument|const SMSNode&D
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|D
operator|.
name|isValid
argument_list|()
operator|&&
literal|"Invalid node for head"
argument_list|)
block|;
return|return
name|Dense
index|[
name|D
operator|.
name|Prev
index|]
operator|.
name|isTail
argument_list|()
return|;
block|}
comment|/// Whether the given entry is a singleton entry, i.e. the only entry with
comment|/// that key.
name|bool
name|isSingleton
argument_list|(
argument|const SMSNode&N
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|N
operator|.
name|isValid
argument_list|()
operator|&&
literal|"Invalid node for singleton"
argument_list|)
block|;
comment|// Is N its own predecessor?
return|return
operator|&
name|Dense
index|[
name|N
operator|.
name|Prev
index|]
operator|==
operator|&
name|N
return|;
block|}
comment|/// Add in the given SMSNode. Uses a free entry in our freelist if
comment|/// available. Returns the index of the added node.
name|unsigned
name|addValue
argument_list|(
argument|const ValueT& V
argument_list|,
argument|unsigned Prev
argument_list|,
argument|unsigned Next
argument_list|)
block|{
if|if
condition|(
name|NumFree
operator|==
literal|0
condition|)
block|{
name|Dense
operator|.
name|push_back
argument_list|(
name|SMSNode
argument_list|(
name|V
argument_list|,
name|Prev
argument_list|,
name|Next
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|Dense
operator|.
name|size
argument_list|()
operator|-
literal|1
return|;
block|}
comment|// Peel off a free slot
name|unsigned
name|Idx
init|=
name|FreelistIdx
decl_stmt|;
name|unsigned
name|NextFree
operator|=
name|Dense
index|[
name|Idx
index|]
operator|.
name|Next
block|;
name|assert
argument_list|(
name|Dense
index|[
name|Idx
index|]
operator|.
name|isTombstone
argument_list|()
operator|&&
literal|"Non-tombstone free?"
argument_list|)
block|;
name|Dense
index|[
name|Idx
index|]
operator|=
name|SMSNode
argument_list|(
name|V
argument_list|,
name|Prev
argument_list|,
name|Next
argument_list|)
block|;
name|FreelistIdx
operator|=
name|NextFree
block|;
operator|--
name|NumFree
block|;
return|return
name|Idx
return|;
block|}
comment|/// Make the current index a new tombstone. Pushes it onto the freelist.
name|void
name|makeTombstone
argument_list|(
argument|unsigned Idx
argument_list|)
block|{
name|Dense
index|[
name|Idx
index|]
operator|.
name|Prev
operator|=
name|SMSNode
operator|::
name|INVALID
block|;
name|Dense
index|[
name|Idx
index|]
operator|.
name|Next
operator|=
name|FreelistIdx
block|;
name|FreelistIdx
operator|=
name|Idx
block|;
operator|++
name|NumFree
block|;   }
name|public
operator|:
name|using
name|value_type
operator|=
name|ValueT
block|;
name|using
name|reference
operator|=
name|ValueT
operator|&
block|;
name|using
name|const_reference
operator|=
specifier|const
name|ValueT
operator|&
block|;
name|using
name|pointer
operator|=
name|ValueT
operator|*
block|;
name|using
name|const_pointer
operator|=
specifier|const
name|ValueT
operator|*
block|;
name|using
name|size_type
operator|=
name|unsigned
block|;
name|SparseMultiSet
argument_list|()
operator|=
expr|default
block|;
name|SparseMultiSet
argument_list|(
specifier|const
name|SparseMultiSet
operator|&
argument_list|)
operator|=
name|delete
block|;
name|SparseMultiSet
operator|&
name|operator
operator|=
operator|(
specifier|const
name|SparseMultiSet
operator|&
operator|)
operator|=
name|delete
block|;
operator|~
name|SparseMultiSet
argument_list|()
block|{
name|free
argument_list|(
name|Sparse
argument_list|)
block|; }
comment|/// Set the universe size which determines the largest key the set can hold.
comment|/// The universe must be sized before any elements can be added.
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
block|;
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
block|;
name|Universe
operator|=
name|U
block|;   }
comment|/// Our iterators are iterators over the collection of objects that share a
comment|/// key.
name|template
operator|<
name|typename
name|SMSPtrTy
operator|>
name|class
name|iterator_base
operator|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|bidirectional_iterator_tag
operator|,
name|ValueT
operator|>
block|{
name|friend
name|class
name|SparseMultiSet
block|;
name|SMSPtrTy
name|SMS
block|;
name|unsigned
name|Idx
block|;
name|unsigned
name|SparseIdx
block|;
name|iterator_base
argument_list|(
argument|SMSPtrTy P
argument_list|,
argument|unsigned I
argument_list|,
argument|unsigned SI
argument_list|)
operator|:
name|SMS
argument_list|(
name|P
argument_list|)
block|,
name|Idx
argument_list|(
name|I
argument_list|)
block|,
name|SparseIdx
argument_list|(
argument|SI
argument_list|)
block|{}
comment|/// Whether our iterator has fallen outside our dense vector.
name|bool
name|isEnd
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Idx
operator|==
name|SMSNode
operator|::
name|INVALID
condition|)
return|return
name|true
return|;
name|assert
argument_list|(
name|Idx
operator|<
name|SMS
operator|->
name|Dense
operator|.
name|size
argument_list|()
operator|&&
literal|"Out of range, non-INVALID Idx?"
argument_list|)
block|;
return|return
name|false
return|;
block|}
comment|/// Whether our iterator is properly keyed, i.e. the SparseIdx is valid
name|bool
name|isKeyed
argument_list|()
specifier|const
block|{
return|return
name|SparseIdx
operator|<
name|SMS
operator|->
name|Universe
return|;
block|}
name|unsigned
name|Prev
argument_list|()
specifier|const
block|{
return|return
name|SMS
operator|->
name|Dense
index|[
name|Idx
index|]
operator|.
name|Prev
return|;
block|}
name|unsigned
name|Next
argument_list|()
specifier|const
block|{
return|return
name|SMS
operator|->
name|Dense
index|[
name|Idx
index|]
operator|.
name|Next
return|;
block|}
name|void
name|setPrev
parameter_list|(
name|unsigned
name|P
parameter_list|)
block|{
name|SMS
operator|->
name|Dense
index|[
name|Idx
index|]
operator|.
name|Prev
operator|=
name|P
expr_stmt|;
block|}
name|void
name|setNext
parameter_list|(
name|unsigned
name|N
parameter_list|)
block|{
name|SMS
operator|->
name|Dense
index|[
name|Idx
index|]
operator|.
name|Next
operator|=
name|N
expr_stmt|;
block|}
name|public
label|:
name|using
name|super
init|=
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|bidirectional_iterator_tag
decl_stmt|,
name|ValueT
decl|>
decl_stmt|;
name|using
name|value_type
init|=
name|typename
name|super
operator|::
name|value_type
decl_stmt|;
name|using
name|difference_type
init|=
name|typename
name|super
operator|::
name|difference_type
decl_stmt|;
name|using
name|pointer
init|=
name|typename
name|super
operator|::
name|pointer
decl_stmt|;
name|using
name|reference
init|=
name|typename
name|super
operator|::
name|reference
decl_stmt|;
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|isKeyed
argument_list|()
operator|&&
name|SMS
operator|->
name|sparseIndex
argument_list|(
name|SMS
operator|->
name|Dense
index|[
name|Idx
index|]
operator|.
name|Data
argument_list|)
operator|==
name|SparseIdx
operator|&&
literal|"Dereferencing iterator of invalid key or index"
argument_list|)
block|;
return|return
name|SMS
operator|->
name|Dense
index|[
name|Idx
index|]
operator|.
name|Data
return|;
block|}
name|pointer
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
operator|&
name|operator
operator|*
operator|(
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Comparison operators
end_comment

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|iterator_base
operator|&
name|RHS
operator|)
specifier|const
block|{
comment|// end compares equal
if|if
condition|(
name|SMS
operator|==
name|RHS
operator|.
name|SMS
operator|&&
name|Idx
operator|==
name|RHS
operator|.
name|Idx
condition|)
block|{
name|assert
argument_list|(
operator|(
name|isEnd
argument_list|()
operator|||
name|SparseIdx
operator|==
name|RHS
operator|.
name|SparseIdx
operator|)
operator|&&
literal|"Same dense entry, but different keys?"
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_expr_stmt

begin_return
return|return
name|false
return|;
end_return

begin_expr_stmt
unit|}      bool
name|operator
operator|!=
operator|(
specifier|const
name|iterator_base
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|RHS
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Increment and decrement operators
end_comment

begin_expr_stmt
name|iterator_base
operator|&
name|operator
operator|--
operator|(
operator|)
block|{
comment|// predecrement - Back up
name|assert
argument_list|(
name|isKeyed
argument_list|()
operator|&&
literal|"Decrementing an invalid iterator"
argument_list|)
block|;
name|assert
argument_list|(
operator|(
name|isEnd
argument_list|()
operator|||
operator|!
name|SMS
operator|->
name|isHead
argument_list|(
name|SMS
operator|->
name|Dense
index|[
name|Idx
index|]
argument_list|)
operator|)
operator|&&
literal|"Decrementing head of list"
argument_list|)
block|;
comment|// If we're at the end, then issue a new find()
if|if
condition|(
name|isEnd
argument_list|()
condition|)
name|Idx
operator|=
name|SMS
operator|->
name|findIndex
argument_list|(
name|SparseIdx
argument_list|)
operator|.
name|Prev
argument_list|()
expr_stmt|;
else|else
name|Idx
operator|=
name|Prev
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_expr_stmt
unit|}     iterator_base
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// preincrement - Advance
name|assert
argument_list|(
operator|!
name|isEnd
argument_list|()
operator|&&
name|isKeyed
argument_list|()
operator|&&
literal|"Incrementing an invalid/end iterator"
argument_list|)
block|;
name|Idx
operator|=
name|Next
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|iterator_base
name|operator
operator|--
operator|(
name|int
operator|)
block|{
comment|// postdecrement
name|iterator_base
name|I
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|--
operator|*
name|this
block|;
return|return
name|I
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|iterator_base
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// postincrement
name|iterator_base
name|I
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|++
operator|*
name|this
block|;
return|return
name|I
return|;
block|}
end_expr_stmt

begin_decl_stmt
unit|};
name|using
name|iterator
init|=
name|iterator_base
operator|<
name|SparseMultiSet
operator|*
operator|>
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|using
name|const_iterator
init|=
name|iterator_base
operator|<
specifier|const
name|SparseMultiSet
operator|*
operator|>
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Convenience types
end_comment

begin_decl_stmt
name|using
name|RangePair
init|=
name|std
operator|::
name|pair
operator|<
name|iterator
decl_stmt|,
name|iterator
decl|>
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Returns an iterator past this container. Note that such an iterator cannot
end_comment

begin_comment
comment|/// be decremented, but will compare equal to other end iterators.
end_comment

begin_function
name|iterator
name|end
parameter_list|()
block|{
return|return
name|iterator
argument_list|(
name|this
argument_list|,
name|SMSNode
operator|::
name|INVALID
argument_list|,
name|SMSNode
operator|::
name|INVALID
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|this
argument_list|,
name|SMSNode
operator|::
name|INVALID
argument_list|,
name|SMSNode
operator|::
name|INVALID
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns true if the set is empty.
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
name|size
argument_list|()
operator|==
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns the number of elements in the set.
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
name|size_type
name|size
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|NumFree
operator|<=
name|Dense
operator|.
name|size
argument_list|()
operator|&&
literal|"Out-of-bounds free entries"
argument_list|)
block|;
return|return
name|Dense
operator|.
name|size
argument_list|()
operator|-
name|NumFree
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Clears the set.  This is a very fast constant time operation.
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
name|NumFree
operator|=
literal|0
expr_stmt|;
name|FreelistIdx
operator|=
name|SMSNode
operator|::
name|INVALID
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Find an element by its index.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param   Idx A valid index to find.
end_comment

begin_comment
comment|/// @returns An iterator to the element identified by key, or end().
end_comment

begin_comment
comment|///
end_comment

begin_function
name|iterator
name|findIndex
parameter_list|(
name|unsigned
name|Idx
parameter_list|)
block|{
name|assert
argument_list|(
name|Idx
operator|<
name|Universe
operator|&&
literal|"Key out of range"
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
name|Idx
index|]
init|,
name|e
init|=
name|Dense
operator|.
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
name|FoundIdx
init|=
name|sparseIndex
argument_list|(
name|Dense
index|[
name|i
index|]
argument_list|)
decl_stmt|;
comment|// Check that we're pointing at the correct entry and that it is the head
comment|// of a valid list.
if|if
condition|(
name|Idx
operator|==
name|FoundIdx
operator|&&
name|Dense
index|[
name|i
index|]
operator|.
name|isValid
argument_list|()
operator|&&
name|isHead
argument_list|(
name|Dense
index|[
name|i
index|]
argument_list|)
condition|)
return|return
name|iterator
argument_list|(
name|this
argument_list|,
name|i
argument_list|,
name|Idx
argument_list|)
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

begin_comment
comment|/// Find an element by its key.
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
specifier|const
name|KeyT
modifier|&
name|Key
parameter_list|)
block|{
return|return
name|findIndex
argument_list|(
name|KeyIndexOf
argument_list|(
name|Key
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
name|const_iterator
name|find
argument_list|(
specifier|const
name|KeyT
operator|&
name|Key
argument_list|)
decl|const
block|{
name|iterator
name|I
init|=
name|const_cast
operator|<
name|SparseMultiSet
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|findIndex
argument_list|(
name|KeyIndexOf
argument_list|(
name|Key
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|const_iterator
argument_list|(
name|I
operator|.
name|SMS
argument_list|,
name|I
operator|.
name|Idx
argument_list|,
name|KeyIndexOf
argument_list|(
name|Key
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Returns the number of elements identified by Key. This will be linear in
end_comment

begin_comment
comment|/// the number of elements of that key.
end_comment

begin_decl_stmt
name|size_type
name|count
argument_list|(
specifier|const
name|KeyT
operator|&
name|Key
argument_list|)
decl|const
block|{
name|unsigned
name|Ret
init|=
literal|0
decl_stmt|;
for|for
control|(
name|const_iterator
name|It
init|=
name|find
argument_list|(
name|Key
argument_list|)
init|;
name|It
operator|!=
name|end
argument_list|()
condition|;
operator|++
name|It
control|)
operator|++
name|Ret
expr_stmt|;
return|return
name|Ret
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Returns true if this set contains an element identified by Key.
end_comment

begin_decl_stmt
name|bool
name|contains
argument_list|(
specifier|const
name|KeyT
operator|&
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
comment|/// Return the head and tail of the subset's list, otherwise returns end().
end_comment

begin_function
name|iterator
name|getHead
parameter_list|(
specifier|const
name|KeyT
modifier|&
name|Key
parameter_list|)
block|{
return|return
name|find
argument_list|(
name|Key
argument_list|)
return|;
block|}
end_function

begin_function
name|iterator
name|getTail
parameter_list|(
specifier|const
name|KeyT
modifier|&
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
operator|!=
name|end
argument_list|()
condition|)
name|I
operator|=
name|iterator
argument_list|(
name|this
argument_list|,
name|I
operator|.
name|Prev
argument_list|()
argument_list|,
name|KeyIndexOf
argument_list|(
name|Key
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|I
return|;
block|}
end_function

begin_comment
comment|/// The bounds of the range of items sharing Key K. First member is the head
end_comment

begin_comment
comment|/// of the list, and the second member is a decrementable end iterator for
end_comment

begin_comment
comment|/// that key.
end_comment

begin_function
name|RangePair
name|equal_range
parameter_list|(
specifier|const
name|KeyT
modifier|&
name|K
parameter_list|)
block|{
name|iterator
name|B
init|=
name|find
argument_list|(
name|K
argument_list|)
decl_stmt|;
name|iterator
name|E
init|=
name|iterator
argument_list|(
name|this
argument_list|,
name|SMSNode
operator|::
name|INVALID
argument_list|,
name|B
operator|.
name|SparseIdx
argument_list|)
decl_stmt|;
return|return
name|make_pair
argument_list|(
name|B
argument_list|,
name|E
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Insert a new element at the tail of the subset list. Returns an iterator
end_comment

begin_comment
comment|/// to the newly added entry.
end_comment

begin_function
name|iterator
name|insert
parameter_list|(
specifier|const
name|ValueT
modifier|&
name|Val
parameter_list|)
block|{
name|unsigned
name|Idx
init|=
name|sparseIndex
argument_list|(
name|Val
argument_list|)
decl_stmt|;
name|iterator
name|I
init|=
name|findIndex
argument_list|(
name|Idx
argument_list|)
decl_stmt|;
name|unsigned
name|NodeIdx
init|=
name|addValue
argument_list|(
name|Val
argument_list|,
name|SMSNode
operator|::
name|INVALID
argument_list|,
name|SMSNode
operator|::
name|INVALID
argument_list|)
decl_stmt|;
if|if
condition|(
name|I
operator|==
name|end
argument_list|()
condition|)
block|{
comment|// Make a singleton list
name|Sparse
index|[
name|Idx
index|]
operator|=
name|NodeIdx
expr_stmt|;
name|Dense
index|[
name|NodeIdx
index|]
operator|.
name|Prev
operator|=
name|NodeIdx
expr_stmt|;
return|return
name|iterator
argument_list|(
name|this
argument_list|,
name|NodeIdx
argument_list|,
name|Idx
argument_list|)
return|;
block|}
comment|// Stick it at the end.
name|unsigned
name|HeadIdx
init|=
name|I
operator|.
name|Idx
decl_stmt|;
name|unsigned
name|TailIdx
init|=
name|I
operator|.
name|Prev
argument_list|()
decl_stmt|;
name|Dense
index|[
name|TailIdx
index|]
operator|.
name|Next
operator|=
name|NodeIdx
expr_stmt|;
name|Dense
index|[
name|HeadIdx
index|]
operator|.
name|Prev
operator|=
name|NodeIdx
expr_stmt|;
name|Dense
index|[
name|NodeIdx
index|]
operator|.
name|Prev
operator|=
name|TailIdx
expr_stmt|;
return|return
name|iterator
argument_list|(
name|this
argument_list|,
name|NodeIdx
argument_list|,
name|Idx
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Erases an existing element identified by a valid iterator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This invalidates iterators pointing at the same entry, but erase() returns
end_comment

begin_comment
comment|/// an iterator pointing to the next element in the subset's list. This makes
end_comment

begin_comment
comment|/// it possible to erase selected elements while iterating over the subset:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   tie(I, E) = Set.equal_range(Key);
end_comment

begin_comment
comment|///   while (I != E)
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
comment|/// Note that if the last element in the subset list is erased, this will
end_comment

begin_comment
comment|/// return an end iterator which can be decremented to get the new tail (if it
end_comment

begin_comment
comment|/// exists):
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///  tie(B, I) = Set.equal_range(Key);
end_comment

begin_comment
comment|///  for (bool isBegin = B == I; !isBegin; /* empty */) {
end_comment

begin_comment
comment|///    isBegin = (--I) == B;
end_comment

begin_comment
comment|///    if (test(I))
end_comment

begin_comment
comment|///      break;
end_comment

begin_comment
comment|///    I = erase(I);
end_comment

begin_comment
comment|///  }
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
name|I
operator|.
name|isKeyed
argument_list|()
operator|&&
operator|!
name|I
operator|.
name|isEnd
argument_list|()
operator|&&
operator|!
name|Dense
index|[
name|I
operator|.
name|Idx
index|]
operator|.
name|isTombstone
argument_list|()
operator|&&
literal|"erasing invalid/end/tombstone iterator"
argument_list|)
expr_stmt|;
comment|// First, unlink the node from its list. Then swap the node out with the
comment|// dense vector's last entry
name|iterator
name|NextI
init|=
name|unlink
argument_list|(
name|Dense
index|[
name|I
operator|.
name|Idx
index|]
argument_list|)
decl_stmt|;
comment|// Put in a tombstone.
name|makeTombstone
argument_list|(
name|I
operator|.
name|Idx
argument_list|)
expr_stmt|;
return|return
name|NextI
return|;
block|}
end_function

begin_comment
comment|/// Erase all elements with the given key. This invalidates all
end_comment

begin_comment
comment|/// iterators of that key.
end_comment

begin_function
name|void
name|eraseAll
parameter_list|(
specifier|const
name|KeyT
modifier|&
name|K
parameter_list|)
block|{
for|for
control|(
name|iterator
name|I
init|=
name|find
argument_list|(
name|K
argument_list|)
init|;
name|I
operator|!=
name|end
argument_list|()
condition|;
comment|/* empty */
control|)
name|I
operator|=
name|erase
argument_list|(
name|I
argument_list|)
expr_stmt|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_comment
comment|/// Unlink the node from its list. Returns the next node in the list.
end_comment

begin_function
name|iterator
name|unlink
parameter_list|(
specifier|const
name|SMSNode
modifier|&
name|N
parameter_list|)
block|{
if|if
condition|(
name|isSingleton
argument_list|(
name|N
argument_list|)
condition|)
block|{
comment|// Singleton is already unlinked
name|assert
argument_list|(
name|N
operator|.
name|Next
operator|==
name|SMSNode
operator|::
name|INVALID
operator|&&
literal|"Singleton has next?"
argument_list|)
expr_stmt|;
return|return
name|iterator
argument_list|(
name|this
argument_list|,
name|SMSNode
operator|::
name|INVALID
argument_list|,
name|ValIndexOf
argument_list|(
name|N
operator|.
name|Data
argument_list|)
argument_list|)
return|;
block|}
if|if
condition|(
name|isHead
argument_list|(
name|N
argument_list|)
condition|)
block|{
comment|// If we're the head, then update the sparse array and our next.
name|Sparse
index|[
name|sparseIndex
argument_list|(
name|N
argument_list|)
index|]
operator|=
name|N
operator|.
name|Next
expr_stmt|;
name|Dense
index|[
name|N
operator|.
name|Next
index|]
operator|.
name|Prev
operator|=
name|N
operator|.
name|Prev
expr_stmt|;
return|return
name|iterator
argument_list|(
name|this
argument_list|,
name|N
operator|.
name|Next
argument_list|,
name|ValIndexOf
argument_list|(
name|N
operator|.
name|Data
argument_list|)
argument_list|)
return|;
block|}
if|if
condition|(
name|N
operator|.
name|isTail
argument_list|()
condition|)
block|{
comment|// If we're the tail, then update our head and our previous.
name|findIndex
argument_list|(
name|sparseIndex
argument_list|(
name|N
argument_list|)
argument_list|)
operator|.
name|setPrev
argument_list|(
name|N
operator|.
name|Prev
argument_list|)
expr_stmt|;
name|Dense
index|[
name|N
operator|.
name|Prev
index|]
operator|.
name|Next
operator|=
name|N
operator|.
name|Next
expr_stmt|;
comment|// Give back an end iterator that can be decremented
name|iterator
name|I
argument_list|(
name|this
argument_list|,
name|N
operator|.
name|Prev
argument_list|,
name|ValIndexOf
argument_list|(
name|N
operator|.
name|Data
argument_list|)
argument_list|)
decl_stmt|;
return|return
operator|++
name|I
return|;
block|}
comment|// Otherwise, just drop us
name|Dense
index|[
name|N
operator|.
name|Next
index|]
operator|.
name|Prev
operator|=
name|N
operator|.
name|Prev
expr_stmt|;
name|Dense
index|[
name|N
operator|.
name|Prev
index|]
operator|.
name|Next
operator|=
name|N
operator|.
name|Next
expr_stmt|;
return|return
name|iterator
argument_list|(
name|this
argument_list|,
name|N
operator|.
name|Next
argument_list|,
name|ValIndexOf
argument_list|(
name|N
operator|.
name|Data
argument_list|)
argument_list|)
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

begin_comment
comment|// LLVM_ADT_SPARSEMULTISET_H
end_comment

end_unit

