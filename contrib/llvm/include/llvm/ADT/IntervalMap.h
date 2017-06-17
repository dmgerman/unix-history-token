begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/IntervalMap.h - A sorted interval map -----------*- C++ -*-===//
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
comment|// This file implements a coalescing interval map for small objects.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// KeyT objects are mapped to ValT objects. Intervals of keys that map to the
end_comment

begin_comment
comment|// same value are represented in a compressed form.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Iterators provide ordered access to the compressed intervals rather than the
end_comment

begin_comment
comment|// individual keys, and insert and erase operations use key intervals as well.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Like SmallVector, IntervalMap will store the first N intervals in the map
end_comment

begin_comment
comment|// object itself without any allocations. When space is exhausted it switches to
end_comment

begin_comment
comment|// a B+-tree representation with very small overhead for small key and value
end_comment

begin_comment
comment|// objects.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A Traits class specifies how keys are compared. It also allows IntervalMap to
end_comment

begin_comment
comment|// work with both closed and half-open intervals.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Keys and values are not stored next to each other in a std::pair, so we don't
end_comment

begin_comment
comment|// provide such a value_type. Dereferencing iterators only returns the mapped
end_comment

begin_comment
comment|// value. The interval bounds are accessible through the start() and stop()
end_comment

begin_comment
comment|// iterator methods.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IntervalMap is optimized for small key and value objects, 4 or 8 bytes each
end_comment

begin_comment
comment|// is the optimal size. For large objects use std::map instead.
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
comment|// Synopsis:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// template<typename KeyT, typename ValT, unsigned N, typename Traits>
end_comment

begin_comment
comment|// class IntervalMap {
end_comment

begin_comment
comment|// public:
end_comment

begin_comment
comment|//   typedef KeyT key_type;
end_comment

begin_comment
comment|//   typedef ValT mapped_type;
end_comment

begin_comment
comment|//   typedef RecyclingAllocator<...> Allocator;
end_comment

begin_comment
comment|//   class iterator;
end_comment

begin_comment
comment|//   class const_iterator;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   explicit IntervalMap(Allocator&);
end_comment

begin_comment
comment|//   ~IntervalMap():
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   bool empty() const;
end_comment

begin_comment
comment|//   KeyT start() const;
end_comment

begin_comment
comment|//   KeyT stop() const;
end_comment

begin_comment
comment|//   ValT lookup(KeyT x, Value NotFound = Value()) const;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   const_iterator begin() const;
end_comment

begin_comment
comment|//   const_iterator end() const;
end_comment

begin_comment
comment|//   iterator begin();
end_comment

begin_comment
comment|//   iterator end();
end_comment

begin_comment
comment|//   const_iterator find(KeyT x) const;
end_comment

begin_comment
comment|//   iterator find(KeyT x);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   void insert(KeyT a, KeyT b, ValT y);
end_comment

begin_comment
comment|//   void clear();
end_comment

begin_comment
comment|// };
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// template<typename KeyT, typename ValT, unsigned N, typename Traits>
end_comment

begin_comment
comment|// class IntervalMap::const_iterator :
end_comment

begin_comment
comment|//   public std::iterator<std::bidirectional_iterator_tag, ValT> {
end_comment

begin_comment
comment|// public:
end_comment

begin_comment
comment|//   bool operator==(const const_iterator&) const;
end_comment

begin_comment
comment|//   bool operator!=(const const_iterator&) const;
end_comment

begin_comment
comment|//   bool valid() const;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   const KeyT&start() const;
end_comment

begin_comment
comment|//   const KeyT&stop() const;
end_comment

begin_comment
comment|//   const ValT&value() const;
end_comment

begin_comment
comment|//   const ValT&operator*() const;
end_comment

begin_comment
comment|//   const ValT *operator->() const;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   const_iterator&operator++();
end_comment

begin_comment
comment|//   const_iterator&operator++(int);
end_comment

begin_comment
comment|//   const_iterator&operator--();
end_comment

begin_comment
comment|//   const_iterator&operator--(int);
end_comment

begin_comment
comment|//   void goToBegin();
end_comment

begin_comment
comment|//   void goToEnd();
end_comment

begin_comment
comment|//   void find(KeyT x);
end_comment

begin_comment
comment|//   void advanceTo(KeyT x);
end_comment

begin_comment
comment|// };
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// template<typename KeyT, typename ValT, unsigned N, typename Traits>
end_comment

begin_comment
comment|// class IntervalMap::iterator : public const_iterator {
end_comment

begin_comment
comment|// public:
end_comment

begin_comment
comment|//   void insert(KeyT a, KeyT b, Value y);
end_comment

begin_comment
comment|//   void erase();
end_comment

begin_comment
comment|// };
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
name|LLVM_ADT_INTERVALMAP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_INTERVALMAP_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/AlignOf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/RecyclingAllocator.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
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
file|<iterator>
end_include

begin_include
include|#
directive|include
file|<new>
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
comment|//===----------------------------------------------------------------------===//
comment|//---                              Key traits                              ---//
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// The IntervalMap works with closed or half-open intervals.
comment|// Adjacent intervals that map to the same value are coalesced.
comment|//
comment|// The IntervalMapInfo traits class is used to determine if a key is contained
comment|// in an interval, and if two intervals are adjacent so they can be coalesced.
comment|// The provided implementation works for closed integer intervals, other keys
comment|// probably need a specialized version.
comment|//
comment|// The point x is contained in [a;b] when !startLess(x, a)&& !stopLess(b, x).
comment|//
comment|// It is assumed that (a;b] half-open intervals are not used, only [a;b) is
comment|// allowed. This is so that stopLess(a, b) can be used to determine if two
comment|// intervals overlap.
comment|//
comment|//===----------------------------------------------------------------------===//
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|IntervalMapInfo
block|{
comment|/// startLess - Return true if x is not in [a;b].
comment|/// This is x< a both for closed intervals and for [a;b) half-open intervals.
specifier|static
specifier|inline
name|bool
name|startLess
argument_list|(
argument|const T&x
argument_list|,
argument|const T&a
argument_list|)
block|{
return|return
name|x
operator|<
name|a
return|;
block|}
comment|/// stopLess - Return true if x is not in [a;b].
comment|/// This is b< x for a closed interval, b<= x for [a;b) half-open intervals.
specifier|static
specifier|inline
name|bool
name|stopLess
argument_list|(
argument|const T&b
argument_list|,
argument|const T&x
argument_list|)
block|{
return|return
name|b
operator|<
name|x
return|;
block|}
comment|/// adjacent - Return true when the intervals [x;a] and [b;y] can coalesce.
comment|/// This is a+1 == b for closed intervals, a == b for half-open intervals.
specifier|static
specifier|inline
name|bool
name|adjacent
argument_list|(
argument|const T&a
argument_list|,
argument|const T&b
argument_list|)
block|{
return|return
name|a
operator|+
literal|1
operator|==
name|b
return|;
block|}
comment|/// nonEmpty - Return true if [a;b] is non-empty.
comment|/// This is a<= b for a closed interval, a< b for [a;b) half-open intervals.
specifier|static
specifier|inline
name|bool
name|nonEmpty
argument_list|(
argument|const T&a
argument_list|,
argument|const T&b
argument_list|)
block|{
return|return
name|a
operator|<=
name|b
return|;
block|}
expr|}
block|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|IntervalMapHalfOpenInfo
block|{
comment|/// startLess - Return true if x is not in [a;b).
specifier|static
specifier|inline
name|bool
name|startLess
argument_list|(
argument|const T&x
argument_list|,
argument|const T&a
argument_list|)
block|{
return|return
name|x
operator|<
name|a
return|;
block|}
comment|/// stopLess - Return true if x is not in [a;b).
specifier|static
specifier|inline
name|bool
name|stopLess
argument_list|(
argument|const T&b
argument_list|,
argument|const T&x
argument_list|)
block|{
return|return
name|b
operator|<=
name|x
return|;
block|}
comment|/// adjacent - Return true when the intervals [x;a) and [b;y) can coalesce.
specifier|static
specifier|inline
name|bool
name|adjacent
argument_list|(
argument|const T&a
argument_list|,
argument|const T&b
argument_list|)
block|{
return|return
name|a
operator|==
name|b
return|;
block|}
comment|/// nonEmpty - Return true if [a;b) is non-empty.
specifier|static
specifier|inline
name|bool
name|nonEmpty
argument_list|(
argument|const T&a
argument_list|,
argument|const T&b
argument_list|)
block|{
return|return
name|a
operator|<
name|b
return|;
block|}
expr|}
block|;
comment|/// IntervalMapImpl - Namespace used for IntervalMap implementation details.
comment|/// It should be considered private to the implementation.
name|namespace
name|IntervalMapImpl
block|{
name|using
name|IdxPair
operator|=
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|unsigned
operator|>
block|;
comment|//===----------------------------------------------------------------------===//
comment|//---                    IntervalMapImpl::NodeBase                         ---//
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// Both leaf and branch nodes store vectors of pairs.
comment|// Leaves store ((KeyT, KeyT), ValT) pairs, branches use (NodeRef, KeyT).
comment|//
comment|// Keys and values are stored in separate arrays to avoid padding caused by
comment|// different object alignments. This also helps improve locality of reference
comment|// when searching the keys.
comment|//
comment|// The nodes don't know how many elements they contain - that information is
comment|// stored elsewhere. Omitting the size field prevents padding and allows a node
comment|// to fill the allocated cache lines completely.
comment|//
comment|// These are typical key and value sizes, the node branching factor (N), and
comment|// wasted space when nodes are sized to fit in three cache lines (192 bytes):
comment|//
comment|//   T1  T2   N Waste  Used by
comment|//    4   4  24   0    Branch<4> (32-bit pointers)
comment|//    8   4  16   0    Leaf<4,4>, Branch<4>
comment|//    8   8  12   0    Leaf<4,8>, Branch<8>
comment|//   16   4   9  12    Leaf<8,4>
comment|//   16   8   8   0    Leaf<8,8>
comment|//
comment|//===----------------------------------------------------------------------===//
name|template
operator|<
name|typename
name|T1
block|,
name|typename
name|T2
block|,
name|unsigned
name|N
operator|>
name|class
name|NodeBase
block|{
name|public
operator|:
expr|enum
block|{
name|Capacity
operator|=
name|N
block|}
block|;
name|T1
name|first
index|[
name|N
index|]
block|;
name|T2
name|second
index|[
name|N
index|]
block|;
comment|/// copy - Copy elements from another node.
comment|/// @param Other Node elements are copied from.
comment|/// @param i     Beginning of the source range in other.
comment|/// @param j     Beginning of the destination range in this.
comment|/// @param Count Number of elements to copy.
name|template
operator|<
name|unsigned
name|M
operator|>
name|void
name|copy
argument_list|(
argument|const NodeBase<T1
argument_list|,
argument|T2
argument_list|,
argument|M>&Other
argument_list|,
argument|unsigned i
argument_list|,
argument|unsigned j
argument_list|,
argument|unsigned Count
argument_list|)
block|{
name|assert
argument_list|(
name|i
operator|+
name|Count
operator|<=
name|M
operator|&&
literal|"Invalid source range"
argument_list|)
block|;
name|assert
argument_list|(
name|j
operator|+
name|Count
operator|<=
name|N
operator|&&
literal|"Invalid dest range"
argument_list|)
block|;
for|for
control|(
name|unsigned
name|e
init|=
name|i
operator|+
name|Count
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
operator|,
operator|++
name|j
control|)
block|{
name|first
index|[
name|j
index|]
operator|=
name|Other
operator|.
name|first
index|[
name|i
index|]
expr_stmt|;
name|second
index|[
name|j
index|]
operator|=
name|Other
operator|.
name|second
index|[
name|i
index|]
expr_stmt|;
block|}
block|}
comment|/// moveLeft - Move elements to the left.
comment|/// @param i     Beginning of the source range.
comment|/// @param j     Beginning of the destination range.
comment|/// @param Count Number of elements to copy.
name|void
name|moveLeft
argument_list|(
argument|unsigned i
argument_list|,
argument|unsigned j
argument_list|,
argument|unsigned Count
argument_list|)
block|{
name|assert
argument_list|(
name|j
operator|<=
name|i
operator|&&
literal|"Use moveRight shift elements right"
argument_list|)
block|;
name|copy
argument_list|(
operator|*
name|this
argument_list|,
name|i
argument_list|,
name|j
argument_list|,
name|Count
argument_list|)
block|;   }
comment|/// moveRight - Move elements to the right.
comment|/// @param i     Beginning of the source range.
comment|/// @param j     Beginning of the destination range.
comment|/// @param Count Number of elements to copy.
name|void
name|moveRight
argument_list|(
argument|unsigned i
argument_list|,
argument|unsigned j
argument_list|,
argument|unsigned Count
argument_list|)
block|{
name|assert
argument_list|(
name|i
operator|<=
name|j
operator|&&
literal|"Use moveLeft shift elements left"
argument_list|)
block|;
name|assert
argument_list|(
name|j
operator|+
name|Count
operator|<=
name|N
operator|&&
literal|"Invalid range"
argument_list|)
block|;
while|while
condition|(
name|Count
operator|--
condition|)
block|{
name|first
index|[
name|j
operator|+
name|Count
index|]
operator|=
name|first
index|[
name|i
operator|+
name|Count
index|]
expr_stmt|;
name|second
index|[
name|j
operator|+
name|Count
index|]
operator|=
name|second
index|[
name|i
operator|+
name|Count
index|]
expr_stmt|;
block|}
block|}
comment|/// erase - Erase elements [i;j).
comment|/// @param i    Beginning of the range to erase.
comment|/// @param j    End of the range. (Exclusive).
comment|/// @param Size Number of elements in node.
name|void
name|erase
argument_list|(
argument|unsigned i
argument_list|,
argument|unsigned j
argument_list|,
argument|unsigned Size
argument_list|)
block|{
name|moveLeft
argument_list|(
name|j
argument_list|,
name|i
argument_list|,
name|Size
operator|-
name|j
argument_list|)
block|;   }
comment|/// erase - Erase element at i.
comment|/// @param i    Index of element to erase.
comment|/// @param Size Number of elements in node.
name|void
name|erase
argument_list|(
argument|unsigned i
argument_list|,
argument|unsigned Size
argument_list|)
block|{
name|erase
argument_list|(
name|i
argument_list|,
name|i
operator|+
literal|1
argument_list|,
name|Size
argument_list|)
block|;   }
comment|/// shift - Shift elements [i;size) 1 position to the right.
comment|/// @param i    Beginning of the range to move.
comment|/// @param Size Number of elements in node.
name|void
name|shift
argument_list|(
argument|unsigned i
argument_list|,
argument|unsigned Size
argument_list|)
block|{
name|moveRight
argument_list|(
name|i
argument_list|,
name|i
operator|+
literal|1
argument_list|,
name|Size
operator|-
name|i
argument_list|)
block|;   }
comment|/// transferToLeftSib - Transfer elements to a left sibling node.
comment|/// @param Size  Number of elements in this.
comment|/// @param Sib   Left sibling node.
comment|/// @param SSize Number of elements in sib.
comment|/// @param Count Number of elements to transfer.
name|void
name|transferToLeftSib
argument_list|(
argument|unsigned Size
argument_list|,
argument|NodeBase&Sib
argument_list|,
argument|unsigned SSize
argument_list|,
argument|unsigned Count
argument_list|)
block|{
name|Sib
operator|.
name|copy
argument_list|(
operator|*
name|this
argument_list|,
literal|0
argument_list|,
name|SSize
argument_list|,
name|Count
argument_list|)
block|;
name|erase
argument_list|(
literal|0
argument_list|,
name|Count
argument_list|,
name|Size
argument_list|)
block|;   }
comment|/// transferToRightSib - Transfer elements to a right sibling node.
comment|/// @param Size  Number of elements in this.
comment|/// @param Sib   Right sibling node.
comment|/// @param SSize Number of elements in sib.
comment|/// @param Count Number of elements to transfer.
name|void
name|transferToRightSib
argument_list|(
argument|unsigned Size
argument_list|,
argument|NodeBase&Sib
argument_list|,
argument|unsigned SSize
argument_list|,
argument|unsigned Count
argument_list|)
block|{
name|Sib
operator|.
name|moveRight
argument_list|(
literal|0
argument_list|,
name|Count
argument_list|,
name|SSize
argument_list|)
block|;
name|Sib
operator|.
name|copy
argument_list|(
operator|*
name|this
argument_list|,
name|Size
operator|-
name|Count
argument_list|,
literal|0
argument_list|,
name|Count
argument_list|)
block|;   }
comment|/// adjustFromLeftSib - Adjust the number if elements in this node by moving
comment|/// elements to or from a left sibling node.
comment|/// @param Size  Number of elements in this.
comment|/// @param Sib   Right sibling node.
comment|/// @param SSize Number of elements in sib.
comment|/// @param Add   The number of elements to add to this node, possibly< 0.
comment|/// @return      Number of elements added to this node, possibly negative.
name|int
name|adjustFromLeftSib
argument_list|(
argument|unsigned Size
argument_list|,
argument|NodeBase&Sib
argument_list|,
argument|unsigned SSize
argument_list|,
argument|int Add
argument_list|)
block|{
if|if
condition|(
name|Add
operator|>
literal|0
condition|)
block|{
comment|// We want to grow, copy from sib.
name|unsigned
name|Count
init|=
name|std
operator|::
name|min
argument_list|(
name|std
operator|::
name|min
argument_list|(
name|unsigned
argument_list|(
name|Add
argument_list|)
argument_list|,
name|SSize
argument_list|)
argument_list|,
name|N
operator|-
name|Size
argument_list|)
decl_stmt|;
name|Sib
operator|.
name|transferToRightSib
argument_list|(
name|SSize
argument_list|,
operator|*
name|this
argument_list|,
name|Size
argument_list|,
name|Count
argument_list|)
expr_stmt|;
return|return
name|Count
return|;
block|}
else|else
block|{
comment|// We want to shrink, copy to sib.
name|unsigned
name|Count
init|=
name|std
operator|::
name|min
argument_list|(
name|std
operator|::
name|min
argument_list|(
name|unsigned
argument_list|(
operator|-
name|Add
argument_list|)
argument_list|,
name|Size
argument_list|)
argument_list|,
name|N
operator|-
name|SSize
argument_list|)
decl_stmt|;
name|transferToLeftSib
argument_list|(
name|Size
argument_list|,
name|Sib
argument_list|,
name|SSize
argument_list|,
name|Count
argument_list|)
expr_stmt|;
return|return
operator|-
name|Count
return|;
block|}
block|}
block|}
block|;
comment|/// IntervalMapImpl::adjustSiblingSizes - Move elements between sibling nodes.
comment|/// @param Node  Array of pointers to sibling nodes.
comment|/// @param Nodes Number of nodes.
comment|/// @param CurSize Array of current node sizes, will be overwritten.
comment|/// @param NewSize Array of desired node sizes.
name|template
operator|<
name|typename
name|NodeT
operator|>
name|void
name|adjustSiblingSizes
argument_list|(
argument|NodeT *Node[]
argument_list|,
argument|unsigned Nodes
argument_list|,
argument|unsigned CurSize[]
argument_list|,
argument|const unsigned NewSize[]
argument_list|)
block|{
comment|// Move elements right.
for|for
control|(
name|int
name|n
init|=
name|Nodes
operator|-
literal|1
init|;
name|n
condition|;
operator|--
name|n
control|)
block|{
if|if
condition|(
name|CurSize
index|[
name|n
index|]
operator|==
name|NewSize
index|[
name|n
index|]
condition|)
continue|continue;
for|for
control|(
name|int
name|m
init|=
name|n
operator|-
literal|1
init|;
name|m
operator|!=
operator|-
literal|1
condition|;
operator|--
name|m
control|)
block|{
name|int
name|d
init|=
name|Node
index|[
name|n
index|]
operator|->
name|adjustFromLeftSib
argument_list|(
name|CurSize
index|[
name|n
index|]
argument_list|,
operator|*
name|Node
index|[
name|m
index|]
argument_list|,
name|CurSize
index|[
name|m
index|]
argument_list|,
name|NewSize
index|[
name|n
index|]
operator|-
name|CurSize
index|[
name|n
index|]
argument_list|)
decl_stmt|;
name|CurSize
index|[
name|m
index|]
operator|-=
name|d
expr_stmt|;
name|CurSize
index|[
name|n
index|]
operator|+=
name|d
expr_stmt|;
comment|// Keep going if the current node was exhausted.
if|if
condition|(
name|CurSize
index|[
name|n
index|]
operator|>=
name|NewSize
index|[
name|n
index|]
condition|)
break|break;
block|}
block|}
if|if
condition|(
name|Nodes
operator|==
literal|0
condition|)
return|return;
comment|// Move elements left.
for|for
control|(
name|unsigned
name|n
init|=
literal|0
init|;
name|n
operator|!=
name|Nodes
operator|-
literal|1
condition|;
operator|++
name|n
control|)
block|{
if|if
condition|(
name|CurSize
index|[
name|n
index|]
operator|==
name|NewSize
index|[
name|n
index|]
condition|)
continue|continue;
for|for
control|(
name|unsigned
name|m
init|=
name|n
operator|+
literal|1
init|;
name|m
operator|!=
name|Nodes
condition|;
operator|++
name|m
control|)
block|{
name|int
name|d
init|=
name|Node
index|[
name|m
index|]
operator|->
name|adjustFromLeftSib
argument_list|(
name|CurSize
index|[
name|m
index|]
argument_list|,
operator|*
name|Node
index|[
name|n
index|]
argument_list|,
name|CurSize
index|[
name|n
index|]
argument_list|,
name|CurSize
index|[
name|n
index|]
operator|-
name|NewSize
index|[
name|n
index|]
argument_list|)
decl_stmt|;
name|CurSize
index|[
name|m
index|]
operator|+=
name|d
expr_stmt|;
name|CurSize
index|[
name|n
index|]
operator|-=
name|d
expr_stmt|;
comment|// Keep going if the current node was exhausted.
if|if
condition|(
name|CurSize
index|[
name|n
index|]
operator|>=
name|NewSize
index|[
name|n
index|]
condition|)
break|break;
block|}
block|}
ifndef|#
directive|ifndef
name|NDEBUG
for|for
control|(
name|unsigned
name|n
init|=
literal|0
init|;
name|n
operator|!=
name|Nodes
condition|;
name|n
operator|++
control|)
name|assert
argument_list|(
name|CurSize
index|[
name|n
index|]
operator|==
name|NewSize
index|[
name|n
index|]
operator|&&
literal|"Insufficient element shuffle"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
comment|/// IntervalMapImpl::distribute - Compute a new distribution of node elements
comment|/// after an overflow or underflow. Reserve space for a new element at Position,
comment|/// and compute the node that will hold Position after redistributing node
comment|/// elements.
comment|///
comment|/// It is required that
comment|///
comment|///   Elements == sum(CurSize), and
comment|///   Elements + Grow<= Nodes * Capacity.
comment|///
comment|/// NewSize[] will be filled in such that:
comment|///
comment|///   sum(NewSize) == Elements, and
comment|///   NewSize[i]<= Capacity.
comment|///
comment|/// The returned index is the node where Position will go, so:
comment|///
comment|///   sum(NewSize[0..idx-1])<= Position
comment|///   sum(NewSize[0..idx])>= Position
comment|///
comment|/// The last equality, sum(NewSize[0..idx]) == Position, can only happen when
comment|/// Grow is set and NewSize[idx] == Capacity-1. The index points to the node
comment|/// before the one holding the Position'th element where there is room for an
comment|/// insertion.
comment|///
comment|/// @param Nodes    The number of nodes.
comment|/// @param Elements Total elements in all nodes.
comment|/// @param Capacity The capacity of each node.
comment|/// @param CurSize  Array[Nodes] of current node sizes, or NULL.
comment|/// @param NewSize  Array[Nodes] to receive the new node sizes.
comment|/// @param Position Insert position.
comment|/// @param Grow     Reserve space for a new element at Position.
comment|/// @return         (node, offset) for Position.
name|IdxPair
name|distribute
argument_list|(
argument|unsigned Nodes
argument_list|,
argument|unsigned Elements
argument_list|,
argument|unsigned Capacity
argument_list|,
argument|const unsigned *CurSize
argument_list|,
argument|unsigned NewSize[]
argument_list|,
argument|unsigned Position
argument_list|,
argument|bool Grow
argument_list|)
block|;
comment|//===----------------------------------------------------------------------===//
comment|//---                   IntervalMapImpl::NodeSizer                         ---//
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// Compute node sizes from key and value types.
comment|//
comment|// The branching factors are chosen to make nodes fit in three cache lines.
comment|// This may not be possible if keys or values are very large. Such large objects
comment|// are handled correctly, but a std::map would probably give better performance.
comment|//
comment|//===----------------------------------------------------------------------===//
block|enum
block|{
comment|// Cache line size. Most architectures have 32 or 64 byte cache lines.
comment|// We use 64 bytes here because it provides good branching factors.
name|Log2CacheLine
operator|=
literal|6
block|,
name|CacheLineBytes
operator|=
literal|1
operator|<<
name|Log2CacheLine
block|,
name|DesiredNodeBytes
operator|=
literal|3
operator|*
name|CacheLineBytes
block|}
block|;
name|template
operator|<
name|typename
name|KeyT
block|,
name|typename
name|ValT
operator|>
expr|struct
name|NodeSizer
block|{   enum
block|{
comment|// Compute the leaf node branching factor that makes a node fit in three
comment|// cache lines. The branching factor must be at least 3, or some B+-tree
comment|// balancing algorithms won't work.
comment|// LeafSize can't be larger than CacheLineBytes. This is required by the
comment|// PointerIntPair used by NodeRef.
name|DesiredLeafSize
operator|=
name|DesiredNodeBytes
operator|/
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|KeyT
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|ValT
argument_list|)
operator|)
block|,
name|MinLeafSize
operator|=
literal|3
block|,
name|LeafSize
operator|=
name|DesiredLeafSize
operator|>
name|MinLeafSize
operator|?
name|DesiredLeafSize
operator|:
name|MinLeafSize
block|}
block|;
name|using
name|LeafBase
operator|=
name|NodeBase
operator|<
name|std
operator|::
name|pair
operator|<
name|KeyT
block|,
name|KeyT
operator|>
block|,
name|ValT
block|,
name|LeafSize
operator|>
block|;    enum
block|{
comment|// Now that we have the leaf branching factor, compute the actual allocation
comment|// unit size by rounding up to a whole number of cache lines.
name|AllocBytes
operator|=
operator|(
sizeof|sizeof
argument_list|(
name|LeafBase
argument_list|)
operator|+
name|CacheLineBytes
operator|-
literal|1
operator|)
operator|&
operator|~
operator|(
name|CacheLineBytes
operator|-
literal|1
operator|)
block|,
comment|// Determine the branching factor for branch nodes.
name|BranchSize
operator|=
name|AllocBytes
operator|/
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
sizeof|sizeof
argument_list|(
name|KeyT
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
operator|)
block|}
block|;
comment|/// Allocator - The recycling allocator used for both branch and leaf nodes.
comment|/// This typedef is very likely to be identical for all IntervalMaps with
comment|/// reasonably sized entries, so the same allocator can be shared among
comment|/// different kinds of maps.
name|using
name|Allocator
operator|=
name|RecyclingAllocator
operator|<
name|BumpPtrAllocator
block|,
name|char
block|,
name|AllocBytes
block|,
name|CacheLineBytes
operator|>
block|; }
block|;
comment|//===----------------------------------------------------------------------===//
comment|//---                     IntervalMapImpl::NodeRef                         ---//
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// B+-tree nodes can be leaves or branches, so we need a polymorphic node
comment|// pointer that can point to both kinds.
comment|//
comment|// All nodes are cache line aligned and the low 6 bits of a node pointer are
comment|// always 0. These bits are used to store the number of elements in the
comment|// referenced node. Besides saving space, placing node sizes in the parents
comment|// allow tree balancing algorithms to run without faulting cache lines for nodes
comment|// that may not need to be modified.
comment|//
comment|// A NodeRef doesn't know whether it references a leaf node or a branch node.
comment|// It is the responsibility of the caller to use the correct types.
comment|//
comment|// Nodes are never supposed to be empty, and it is invalid to store a node size
comment|// of 0 in a NodeRef. The valid range of sizes is 1-64.
comment|//
comment|//===----------------------------------------------------------------------===//
name|class
name|NodeRef
block|{   struct
name|CacheAlignedPointerTraits
block|{
specifier|static
specifier|inline
name|void
operator|*
name|getAsVoidPointer
argument_list|(
argument|void *P
argument_list|)
block|{
return|return
name|P
return|;
block|}
specifier|static
specifier|inline
name|void
operator|*
name|getFromVoidPointer
argument_list|(
argument|void *P
argument_list|)
block|{
return|return
name|P
return|;
block|}
expr|enum
block|{
name|NumLowBitsAvailable
operator|=
name|Log2CacheLine
block|}
block|;   }
block|;
name|PointerIntPair
operator|<
name|void
operator|*
block|,
name|Log2CacheLine
block|,
name|unsigned
block|,
name|CacheAlignedPointerTraits
operator|>
name|pip
block|;
name|public
operator|:
comment|/// NodeRef - Create a null ref.
name|NodeRef
argument_list|()
operator|=
expr|default
block|;
comment|/// operator bool - Detect a null ref.
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|pip
operator|.
name|getOpaqueValue
argument_list|()
return|;
block|}
comment|/// NodeRef - Create a reference to the node p with n elements.
name|template
operator|<
name|typename
name|NodeT
operator|>
name|NodeRef
argument_list|(
argument|NodeT *p
argument_list|,
argument|unsigned n
argument_list|)
operator|:
name|pip
argument_list|(
argument|p
argument_list|,
argument|n -
literal|1
argument_list|)
block|{
name|assert
argument_list|(
name|n
operator|<=
name|NodeT
operator|::
name|Capacity
operator|&&
literal|"Size too big for node"
argument_list|)
block|;   }
comment|/// size - Return the number of elements in the referenced node.
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|pip
operator|.
name|getInt
argument_list|()
operator|+
literal|1
return|;
block|}
comment|/// setSize - Update the node size.
name|void
name|setSize
argument_list|(
argument|unsigned n
argument_list|)
block|{
name|pip
operator|.
name|setInt
argument_list|(
name|n
operator|-
literal|1
argument_list|)
block|; }
comment|/// subtree - Access the i'th subtree reference in a branch node.
comment|/// This depends on branch nodes storing the NodeRef array as their first
comment|/// member.
name|NodeRef
operator|&
name|subtree
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|NodeRef
operator|*
operator|>
operator|(
name|pip
operator|.
name|getPointer
argument_list|()
operator|)
index|[
name|i
index|]
return|;
block|}
comment|/// get - Dereference as a NodeT reference.
name|template
operator|<
name|typename
name|NodeT
operator|>
name|NodeT
operator|&
name|get
argument_list|()
specifier|const
block|{
return|return
operator|*
name|reinterpret_cast
operator|<
name|NodeT
operator|*
operator|>
operator|(
name|pip
operator|.
name|getPointer
argument_list|()
operator|)
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|NodeRef
operator|&
name|RHS
operator|)
specifier|const
block|{
if|if
condition|(
name|pip
operator|==
name|RHS
operator|.
name|pip
condition|)
return|return
name|true
return|;
name|assert
argument_list|(
name|pip
operator|.
name|getPointer
argument_list|()
operator|!=
name|RHS
operator|.
name|pip
operator|.
name|getPointer
argument_list|()
operator|&&
literal|"Inconsistent NodeRefs"
argument_list|)
block|;
return|return
name|false
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|NodeRef
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
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|//---                      IntervalMapImpl::LeafNode                       ---//
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// Leaf nodes store up to N disjoint intervals with corresponding values.
comment|//
comment|// The intervals are kept sorted and fully coalesced so there are no adjacent
comment|// intervals mapping to the same value.
comment|//
comment|// These constraints are always satisfied:
comment|//
comment|// - Traits::stopLess(start(i), stop(i))    - Non-empty, sane intervals.
comment|//
comment|// - Traits::stopLess(stop(i), start(i + 1) - Sorted.
comment|//
comment|// - value(i) != value(i + 1) || !Traits::adjacent(stop(i), start(i + 1))
comment|//                                          - Fully coalesced.
comment|//
comment|//===----------------------------------------------------------------------===//
name|template
operator|<
name|typename
name|KeyT
block|,
name|typename
name|ValT
block|,
name|unsigned
name|N
block|,
name|typename
name|Traits
operator|>
name|class
name|LeafNode
operator|:
name|public
name|NodeBase
operator|<
name|std
operator|::
name|pair
operator|<
name|KeyT
block|,
name|KeyT
operator|>
block|,
name|ValT
block|,
name|N
operator|>
block|{
name|public
operator|:
specifier|const
name|KeyT
operator|&
name|start
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|first
index|[
name|i
index|]
operator|.
name|first
return|;
block|}
specifier|const
name|KeyT
operator|&
name|stop
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|first
index|[
name|i
index|]
operator|.
name|second
return|;
block|}
specifier|const
name|ValT
operator|&
name|value
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|second
index|[
name|i
index|]
return|;
block|}
name|KeyT
operator|&
name|start
argument_list|(
argument|unsigned i
argument_list|)
block|{
return|return
name|this
operator|->
name|first
index|[
name|i
index|]
operator|.
name|first
return|;
block|}
name|KeyT
operator|&
name|stop
argument_list|(
argument|unsigned i
argument_list|)
block|{
return|return
name|this
operator|->
name|first
index|[
name|i
index|]
operator|.
name|second
return|;
block|}
name|ValT
operator|&
name|value
argument_list|(
argument|unsigned i
argument_list|)
block|{
return|return
name|this
operator|->
name|second
index|[
name|i
index|]
return|;
block|}
comment|/// findFrom - Find the first interval after i that may contain x.
comment|/// @param i    Starting index for the search.
comment|/// @param Size Number of elements in node.
comment|/// @param x    Key to search for.
comment|/// @return     First index with !stopLess(key[i].stop, x), or size.
comment|///             This is the first interval that can possibly contain x.
name|unsigned
name|findFrom
argument_list|(
argument|unsigned i
argument_list|,
argument|unsigned Size
argument_list|,
argument|KeyT x
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|i
operator|<=
name|Size
operator|&&
name|Size
operator|<=
name|N
operator|&&
literal|"Bad indices"
argument_list|)
block|;
name|assert
argument_list|(
operator|(
name|i
operator|==
literal|0
operator|||
name|Traits
operator|::
name|stopLess
argument_list|(
name|stop
argument_list|(
name|i
operator|-
literal|1
argument_list|)
argument_list|,
name|x
argument_list|)
operator|)
operator|&&
literal|"Index is past the needed point"
argument_list|)
block|;
while|while
condition|(
name|i
operator|!=
name|Size
operator|&&
name|Traits
operator|::
name|stopLess
argument_list|(
name|stop
argument_list|(
name|i
argument_list|)
argument_list|,
name|x
argument_list|)
condition|)
operator|++
name|i
expr_stmt|;
return|return
name|i
return|;
block|}
comment|/// safeFind - Find an interval that is known to exist. This is the same as
comment|/// findFrom except is it assumed that x is at least within range of the last
comment|/// interval.
comment|/// @param i Starting index for the search.
comment|/// @param x Key to search for.
comment|/// @return  First index with !stopLess(key[i].stop, x), never size.
comment|///          This is the first interval that can possibly contain x.
name|unsigned
name|safeFind
argument_list|(
argument|unsigned i
argument_list|,
argument|KeyT x
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|N
operator|&&
literal|"Bad index"
argument_list|)
block|;
name|assert
argument_list|(
operator|(
name|i
operator|==
literal|0
operator|||
name|Traits
operator|::
name|stopLess
argument_list|(
name|stop
argument_list|(
name|i
operator|-
literal|1
argument_list|)
argument_list|,
name|x
argument_list|)
operator|)
operator|&&
literal|"Index is past the needed point"
argument_list|)
block|;
while|while
condition|(
name|Traits
operator|::
name|stopLess
argument_list|(
name|stop
argument_list|(
name|i
argument_list|)
argument_list|,
name|x
argument_list|)
condition|)
operator|++
name|i
expr_stmt|;
name|assert
argument_list|(
name|i
operator|<
name|N
operator|&&
literal|"Unsafe intervals"
argument_list|)
block|;
return|return
name|i
return|;
block|}
comment|/// safeLookup - Lookup mapped value for a safe key.
comment|/// It is assumed that x is within range of the last entry.
comment|/// @param x        Key to search for.
comment|/// @param NotFound Value to return if x is not in any interval.
comment|/// @return         The mapped value at x or NotFound.
name|ValT
name|safeLookup
argument_list|(
argument|KeyT x
argument_list|,
argument|ValT NotFound
argument_list|)
specifier|const
block|{
name|unsigned
name|i
operator|=
name|safeFind
argument_list|(
literal|0
argument_list|,
name|x
argument_list|)
block|;
return|return
name|Traits
operator|::
name|startLess
argument_list|(
name|x
argument_list|,
name|start
argument_list|(
name|i
argument_list|)
argument_list|)
condition|?
name|NotFound
else|:
name|value
argument_list|(
name|i
argument_list|)
return|;
block|}
name|unsigned
name|insertFrom
argument_list|(
argument|unsigned&Pos
argument_list|,
argument|unsigned Size
argument_list|,
argument|KeyT a
argument_list|,
argument|KeyT b
argument_list|,
argument|ValT y
argument_list|)
block|; }
expr_stmt|;
comment|/// insertFrom - Add mapping of [a;b] to y if possible, coalescing as much as
comment|/// possible. This may cause the node to grow by 1, or it may cause the node
comment|/// to shrink because of coalescing.
comment|/// @param Pos  Starting index = insertFrom(0, size, a)
comment|/// @param Size Number of elements in node.
comment|/// @param a    Interval start.
comment|/// @param b    Interval stop.
comment|/// @param y    Value be mapped.
comment|/// @return     (insert position, new size), or (i, Capacity+1) on overflow.
name|template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|unsigned
name|LeafNode
operator|<
name|KeyT
operator|,
name|ValT
operator|,
name|N
operator|,
name|Traits
operator|>
operator|::
name|insertFrom
argument_list|(
argument|unsigned&Pos
argument_list|,
argument|unsigned Size
argument_list|,
argument|KeyT a
argument_list|,
argument|KeyT b
argument_list|,
argument|ValT y
argument_list|)
block|{
name|unsigned
name|i
operator|=
name|Pos
block|;
name|assert
argument_list|(
name|i
operator|<=
name|Size
operator|&&
name|Size
operator|<=
name|N
operator|&&
literal|"Invalid index"
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|Traits
operator|::
name|stopLess
argument_list|(
name|b
argument_list|,
name|a
argument_list|)
operator|&&
literal|"Invalid interval"
argument_list|)
block|;
comment|// Verify the findFrom invariant.
name|assert
argument_list|(
operator|(
name|i
operator|==
literal|0
operator|||
name|Traits
operator|::
name|stopLess
argument_list|(
name|stop
argument_list|(
name|i
operator|-
literal|1
argument_list|)
argument_list|,
name|a
argument_list|)
operator|)
argument_list|)
block|;
name|assert
argument_list|(
operator|(
name|i
operator|==
name|Size
operator|||
operator|!
name|Traits
operator|::
name|stopLess
argument_list|(
name|stop
argument_list|(
name|i
argument_list|)
argument_list|,
name|a
argument_list|)
operator|)
argument_list|)
block|;
name|assert
argument_list|(
operator|(
name|i
operator|==
name|Size
operator|||
name|Traits
operator|::
name|stopLess
argument_list|(
name|b
argument_list|,
name|start
argument_list|(
name|i
argument_list|)
argument_list|)
operator|)
operator|&&
literal|"Overlapping insert"
argument_list|)
block|;
comment|// Coalesce with previous interval.
if|if
condition|(
name|i
operator|&&
name|value
argument_list|(
name|i
operator|-
literal|1
argument_list|)
operator|==
name|y
operator|&&
name|Traits
operator|::
name|adjacent
argument_list|(
name|stop
argument_list|(
name|i
operator|-
literal|1
argument_list|)
argument_list|,
name|a
argument_list|)
condition|)
block|{
name|Pos
operator|=
name|i
operator|-
literal|1
expr_stmt|;
comment|// Also coalesce with next interval?
if|if
condition|(
name|i
operator|!=
name|Size
operator|&&
name|value
argument_list|(
name|i
argument_list|)
operator|==
name|y
operator|&&
name|Traits
operator|::
name|adjacent
argument_list|(
name|b
argument_list|,
name|start
argument_list|(
name|i
argument_list|)
argument_list|)
condition|)
block|{
name|stop
argument_list|(
name|i
operator|-
literal|1
argument_list|)
operator|=
name|stop
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|this
operator|->
name|erase
argument_list|(
name|i
argument_list|,
name|Size
argument_list|)
expr_stmt|;
return|return
name|Size
operator|-
literal|1
return|;
block|}
name|stop
argument_list|(
name|i
operator|-
literal|1
argument_list|)
operator|=
name|b
expr_stmt|;
return|return
name|Size
return|;
block|}
comment|// Detect overflow.
if|if
condition|(
name|i
operator|==
name|N
condition|)
return|return
name|N
operator|+
literal|1
return|;
comment|// Add new interval at end.
if|if
condition|(
name|i
operator|==
name|Size
condition|)
block|{
name|start
argument_list|(
name|i
argument_list|)
operator|=
name|a
expr_stmt|;
name|stop
argument_list|(
name|i
argument_list|)
operator|=
name|b
expr_stmt|;
name|value
argument_list|(
name|i
argument_list|)
operator|=
name|y
expr_stmt|;
return|return
name|Size
operator|+
literal|1
return|;
block|}
comment|// Try to coalesce with following interval.
if|if
condition|(
name|value
argument_list|(
name|i
argument_list|)
operator|==
name|y
operator|&&
name|Traits
operator|::
name|adjacent
argument_list|(
name|b
argument_list|,
name|start
argument_list|(
name|i
argument_list|)
argument_list|)
condition|)
block|{
name|start
argument_list|(
name|i
argument_list|)
operator|=
name|a
expr_stmt|;
return|return
name|Size
return|;
block|}
comment|// We must insert before i. Detect overflow.
if|if
condition|(
name|Size
operator|==
name|N
condition|)
return|return
name|N
operator|+
literal|1
return|;
comment|// Insert before i.
name|this
operator|->
name|shift
argument_list|(
name|i
argument_list|,
name|Size
argument_list|)
expr_stmt|;
name|start
argument_list|(
name|i
argument_list|)
operator|=
name|a
expr_stmt|;
name|stop
argument_list|(
name|i
argument_list|)
operator|=
name|b
expr_stmt|;
name|value
argument_list|(
name|i
argument_list|)
operator|=
name|y
expr_stmt|;
return|return
name|Size
operator|+
literal|1
return|;
block|}
end_decl_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//---                   IntervalMapImpl::BranchNode                        ---//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A branch node stores references to 1--N subtrees all of the same height.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The key array in a branch node holds the rightmost stop key of each subtree.
end_comment

begin_comment
comment|// It is redundant to store the last stop key since it can be found in the
end_comment

begin_comment
comment|// parent node, but doing so makes tree balancing a lot simpler.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// It is unusual for a branch node to only have one subtree, but it can happen
end_comment

begin_comment
comment|// in the root node if it is smaller than the normal nodes.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// When all of the leaf nodes from all the subtrees are concatenated, they must
end_comment

begin_comment
comment|// satisfy the same constraints as a single leaf node. They must be sorted,
end_comment

begin_comment
comment|// sane, and fully coalesced.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|class
name|BranchNode
operator|:
name|public
name|NodeBase
operator|<
name|NodeRef
operator|,
name|KeyT
operator|,
name|N
operator|>
block|{
name|public
operator|:
specifier|const
name|KeyT
operator|&
name|stop
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|second
index|[
name|i
index|]
return|;
block|}
specifier|const
name|NodeRef
operator|&
name|subtree
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|first
index|[
name|i
index|]
return|;
block|}
end_expr_stmt

begin_function
name|KeyT
modifier|&
name|stop
parameter_list|(
name|unsigned
name|i
parameter_list|)
block|{
return|return
name|this
operator|->
name|second
index|[
name|i
index|]
return|;
block|}
end_function

begin_function
name|NodeRef
modifier|&
name|subtree
parameter_list|(
name|unsigned
name|i
parameter_list|)
block|{
return|return
name|this
operator|->
name|first
index|[
name|i
index|]
return|;
block|}
end_function

begin_comment
comment|/// findFrom - Find the first subtree after i that may contain x.
end_comment

begin_comment
comment|/// @param i    Starting index for the search.
end_comment

begin_comment
comment|/// @param Size Number of elements in node.
end_comment

begin_comment
comment|/// @param x    Key to search for.
end_comment

begin_comment
comment|/// @return     First index with !stopLess(key[i], x), or size.
end_comment

begin_comment
comment|///             This is the first subtree that can possibly contain x.
end_comment

begin_decl_stmt
name|unsigned
name|findFrom
argument_list|(
name|unsigned
name|i
argument_list|,
name|unsigned
name|Size
argument_list|,
name|KeyT
name|x
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|i
operator|<=
name|Size
operator|&&
name|Size
operator|<=
name|N
operator|&&
literal|"Bad indices"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|(
name|i
operator|==
literal|0
operator|||
name|Traits
operator|::
name|stopLess
argument_list|(
name|stop
argument_list|(
name|i
operator|-
literal|1
argument_list|)
argument_list|,
name|x
argument_list|)
operator|)
operator|&&
literal|"Index to findFrom is past the needed point"
argument_list|)
expr_stmt|;
while|while
condition|(
name|i
operator|!=
name|Size
operator|&&
name|Traits
operator|::
name|stopLess
argument_list|(
name|stop
argument_list|(
name|i
argument_list|)
argument_list|,
name|x
argument_list|)
condition|)
operator|++
name|i
expr_stmt|;
return|return
name|i
return|;
block|}
end_decl_stmt

begin_comment
comment|/// safeFind - Find a subtree that is known to exist. This is the same as
end_comment

begin_comment
comment|/// findFrom except is it assumed that x is in range.
end_comment

begin_comment
comment|/// @param i Starting index for the search.
end_comment

begin_comment
comment|/// @param x Key to search for.
end_comment

begin_comment
comment|/// @return  First index with !stopLess(key[i], x), never size.
end_comment

begin_comment
comment|///          This is the first subtree that can possibly contain x.
end_comment

begin_decl_stmt
name|unsigned
name|safeFind
argument_list|(
name|unsigned
name|i
argument_list|,
name|KeyT
name|x
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|N
operator|&&
literal|"Bad index"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|(
name|i
operator|==
literal|0
operator|||
name|Traits
operator|::
name|stopLess
argument_list|(
name|stop
argument_list|(
name|i
operator|-
literal|1
argument_list|)
argument_list|,
name|x
argument_list|)
operator|)
operator|&&
literal|"Index is past the needed point"
argument_list|)
expr_stmt|;
while|while
condition|(
name|Traits
operator|::
name|stopLess
argument_list|(
name|stop
argument_list|(
name|i
argument_list|)
argument_list|,
name|x
argument_list|)
condition|)
operator|++
name|i
expr_stmt|;
name|assert
argument_list|(
name|i
operator|<
name|N
operator|&&
literal|"Unsafe intervals"
argument_list|)
expr_stmt|;
return|return
name|i
return|;
block|}
end_decl_stmt

begin_comment
comment|/// safeLookup - Get the subtree containing x, Assuming that x is in range.
end_comment

begin_comment
comment|/// @param x Key to search for.
end_comment

begin_comment
comment|/// @return  Subtree containing x
end_comment

begin_decl_stmt
name|NodeRef
name|safeLookup
argument_list|(
name|KeyT
name|x
argument_list|)
decl|const
block|{
return|return
name|subtree
argument_list|(
name|safeFind
argument_list|(
literal|0
argument_list|,
name|x
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// insert - Insert a new (subtree, stop) pair.
end_comment

begin_comment
comment|/// @param i    Insert position, following entries will be shifted.
end_comment

begin_comment
comment|/// @param Size Number of elements in node.
end_comment

begin_comment
comment|/// @param Node Subtree to insert.
end_comment

begin_comment
comment|/// @param Stop Last key in subtree.
end_comment

begin_function
name|void
name|insert
parameter_list|(
name|unsigned
name|i
parameter_list|,
name|unsigned
name|Size
parameter_list|,
name|NodeRef
name|Node
parameter_list|,
name|KeyT
name|Stop
parameter_list|)
block|{
name|assert
argument_list|(
name|Size
operator|<
name|N
operator|&&
literal|"branch node overflow"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|i
operator|<=
name|Size
operator|&&
literal|"Bad insert position"
argument_list|)
expr_stmt|;
name|this
operator|->
name|shift
argument_list|(
name|i
argument_list|,
name|Size
argument_list|)
expr_stmt|;
name|subtree
argument_list|(
name|i
argument_list|)
operator|=
name|Node
expr_stmt|;
name|stop
argument_list|(
name|i
argument_list|)
operator|=
name|Stop
expr_stmt|;
block|}
end_function

begin_comment
unit|};
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//---                         IntervalMapImpl::Path                        ---//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A Path is used by iterators to represent a position in a B+-tree, and the
end_comment

begin_comment
comment|// path to get there from the root.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The Path class also contains the tree navigation code that doesn't have to
end_comment

begin_comment
comment|// be templatized.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_decl_stmt
name|class
name|Path
block|{
comment|/// Entry - Each step in the path is a node pointer and an offset into that
comment|/// node.
struct|struct
name|Entry
block|{
name|void
modifier|*
name|node
decl_stmt|;
name|unsigned
name|size
decl_stmt|;
name|unsigned
name|offset
decl_stmt|;
name|Entry
argument_list|(
argument|void *Node
argument_list|,
argument|unsigned Size
argument_list|,
argument|unsigned Offset
argument_list|)
block|:
name|node
argument_list|(
name|Node
argument_list|)
operator|,
name|size
argument_list|(
name|Size
argument_list|)
operator|,
name|offset
argument_list|(
argument|Offset
argument_list|)
block|{}
name|Entry
argument_list|(
argument|NodeRef Node
argument_list|,
argument|unsigned Offset
argument_list|)
operator|:
name|node
argument_list|(
operator|&
name|Node
operator|.
name|subtree
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|,
name|size
argument_list|(
name|Node
operator|.
name|size
argument_list|()
argument_list|)
operator|,
name|offset
argument_list|(
argument|Offset
argument_list|)
block|{}
name|NodeRef
operator|&
name|subtree
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|NodeRef
operator|*
operator|>
operator|(
name|node
operator|)
index|[
name|i
index|]
return|;
block|}
block|}
struct|;
comment|/// path - The path entries, path[0] is the root node, path.back() is a leaf.
name|SmallVector
operator|<
name|Entry
operator|,
literal|4
operator|>
name|path
expr_stmt|;
name|public
label|:
comment|// Node accessors.
name|template
operator|<
name|typename
name|NodeT
operator|>
name|NodeT
operator|&
name|node
argument_list|(
argument|unsigned Level
argument_list|)
specifier|const
block|{
return|return
operator|*
name|reinterpret_cast
operator|<
name|NodeT
operator|*
operator|>
operator|(
name|path
index|[
name|Level
index|]
operator|.
name|node
operator|)
return|;
block|}
name|unsigned
name|size
argument_list|(
name|unsigned
name|Level
argument_list|)
decl|const
block|{
return|return
name|path
index|[
name|Level
index|]
operator|.
name|size
return|;
block|}
name|unsigned
name|offset
argument_list|(
name|unsigned
name|Level
argument_list|)
decl|const
block|{
return|return
name|path
index|[
name|Level
index|]
operator|.
name|offset
return|;
block|}
name|unsigned
modifier|&
name|offset
parameter_list|(
name|unsigned
name|Level
parameter_list|)
block|{
return|return
name|path
index|[
name|Level
index|]
operator|.
name|offset
return|;
block|}
comment|// Leaf accessors.
name|template
operator|<
name|typename
name|NodeT
operator|>
name|NodeT
operator|&
name|leaf
argument_list|()
specifier|const
block|{
return|return
operator|*
name|reinterpret_cast
operator|<
name|NodeT
operator|*
operator|>
operator|(
name|path
operator|.
name|back
argument_list|()
operator|.
name|node
operator|)
return|;
block|}
name|unsigned
name|leafSize
argument_list|()
specifier|const
block|{
return|return
name|path
operator|.
name|back
argument_list|()
operator|.
name|size
return|;
block|}
name|unsigned
name|leafOffset
argument_list|()
specifier|const
block|{
return|return
name|path
operator|.
name|back
argument_list|()
operator|.
name|offset
return|;
block|}
name|unsigned
modifier|&
name|leafOffset
parameter_list|()
block|{
return|return
name|path
operator|.
name|back
argument_list|()
operator|.
name|offset
return|;
block|}
comment|/// valid - Return true if path is at a valid node, not at end().
name|bool
name|valid
argument_list|()
specifier|const
block|{
return|return
operator|!
name|path
operator|.
name|empty
argument_list|()
operator|&&
name|path
operator|.
name|front
argument_list|()
operator|.
name|offset
operator|<
name|path
operator|.
name|front
argument_list|()
operator|.
name|size
return|;
block|}
comment|/// height - Return the height of the tree corresponding to this path.
comment|/// This matches map->height in a full path.
name|unsigned
name|height
argument_list|()
specifier|const
block|{
return|return
name|path
operator|.
name|size
argument_list|()
operator|-
literal|1
return|;
block|}
comment|/// subtree - Get the subtree referenced from Level. When the path is
comment|/// consistent, node(Level + 1) == subtree(Level).
comment|/// @param Level 0..height-1. The leaves have no subtrees.
name|NodeRef
modifier|&
name|subtree
argument_list|(
name|unsigned
name|Level
argument_list|)
decl|const
block|{
return|return
name|path
index|[
name|Level
index|]
operator|.
name|subtree
argument_list|(
name|path
index|[
name|Level
index|]
operator|.
name|offset
argument_list|)
return|;
block|}
comment|/// reset - Reset cached information about node(Level) from subtree(Level -1).
comment|/// @param Level 1..height. THe node to update after parent node changed.
name|void
name|reset
parameter_list|(
name|unsigned
name|Level
parameter_list|)
block|{
name|path
index|[
name|Level
index|]
operator|=
name|Entry
argument_list|(
name|subtree
argument_list|(
name|Level
operator|-
literal|1
argument_list|)
argument_list|,
name|offset
argument_list|(
name|Level
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// push - Add entry to path.
comment|/// @param Node Node to add, should be subtree(path.size()-1).
comment|/// @param Offset Offset into Node.
name|void
name|push
parameter_list|(
name|NodeRef
name|Node
parameter_list|,
name|unsigned
name|Offset
parameter_list|)
block|{
name|path
operator|.
name|push_back
argument_list|(
name|Entry
argument_list|(
name|Node
argument_list|,
name|Offset
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// pop - Remove the last path entry.
name|void
name|pop
parameter_list|()
block|{
name|path
operator|.
name|pop_back
argument_list|()
expr_stmt|;
block|}
comment|/// setSize - Set the size of a node both in the path and in the tree.
comment|/// @param Level 0..height. Note that setting the root size won't change
comment|///              map->rootSize.
comment|/// @param Size New node size.
name|void
name|setSize
parameter_list|(
name|unsigned
name|Level
parameter_list|,
name|unsigned
name|Size
parameter_list|)
block|{
name|path
index|[
name|Level
index|]
operator|.
name|size
operator|=
name|Size
expr_stmt|;
if|if
condition|(
name|Level
condition|)
name|subtree
argument_list|(
name|Level
operator|-
literal|1
argument_list|)
operator|.
name|setSize
argument_list|(
name|Size
argument_list|)
expr_stmt|;
block|}
comment|/// setRoot - Clear the path and set a new root node.
comment|/// @param Node New root node.
comment|/// @param Size New root size.
comment|/// @param Offset Offset into root node.
name|void
name|setRoot
parameter_list|(
name|void
modifier|*
name|Node
parameter_list|,
name|unsigned
name|Size
parameter_list|,
name|unsigned
name|Offset
parameter_list|)
block|{
name|path
operator|.
name|clear
argument_list|()
expr_stmt|;
name|path
operator|.
name|push_back
argument_list|(
name|Entry
argument_list|(
name|Node
argument_list|,
name|Size
argument_list|,
name|Offset
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// replaceRoot - Replace the current root node with two new entries after the
comment|/// tree height has increased.
comment|/// @param Root The new root node.
comment|/// @param Size Number of entries in the new root.
comment|/// @param Offsets Offsets into the root and first branch nodes.
name|void
name|replaceRoot
parameter_list|(
name|void
modifier|*
name|Root
parameter_list|,
name|unsigned
name|Size
parameter_list|,
name|IdxPair
name|Offsets
parameter_list|)
function_decl|;
comment|/// getLeftSibling - Get the left sibling node at Level, or a null NodeRef.
comment|/// @param Level Get the sibling to node(Level).
comment|/// @return Left sibling, or NodeRef().
name|NodeRef
name|getLeftSibling
argument_list|(
name|unsigned
name|Level
argument_list|)
decl|const
decl_stmt|;
comment|/// moveLeft - Move path to the left sibling at Level. Leave nodes below Level
comment|/// unaltered.
comment|/// @param Level Move node(Level).
name|void
name|moveLeft
parameter_list|(
name|unsigned
name|Level
parameter_list|)
function_decl|;
comment|/// fillLeft - Grow path to Height by taking leftmost branches.
comment|/// @param Height The target height.
name|void
name|fillLeft
parameter_list|(
name|unsigned
name|Height
parameter_list|)
block|{
while|while
condition|(
name|height
argument_list|()
operator|<
name|Height
condition|)
name|push
argument_list|(
name|subtree
argument_list|(
name|height
argument_list|()
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
comment|/// getLeftSibling - Get the left sibling node at Level, or a null NodeRef.
comment|/// @param Level Get the sinbling to node(Level).
comment|/// @return Left sibling, or NodeRef().
name|NodeRef
name|getRightSibling
argument_list|(
name|unsigned
name|Level
argument_list|)
decl|const
decl_stmt|;
comment|/// moveRight - Move path to the left sibling at Level. Leave nodes below
comment|/// Level unaltered.
comment|/// @param Level Move node(Level).
name|void
name|moveRight
parameter_list|(
name|unsigned
name|Level
parameter_list|)
function_decl|;
comment|/// atBegin - Return true if path is at begin().
name|bool
name|atBegin
argument_list|()
specifier|const
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|path
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|path
index|[
name|i
index|]
operator|.
name|offset
operator|!=
literal|0
condition|)
return|return
name|false
return|;
return|return
name|true
return|;
block|}
end_decl_stmt

begin_comment
comment|/// atLastEntry - Return true if the path is at the last entry of the node at
end_comment

begin_comment
comment|/// Level.
end_comment

begin_comment
comment|/// @param Level Node to examine.
end_comment

begin_decl_stmt
name|bool
name|atLastEntry
argument_list|(
name|unsigned
name|Level
argument_list|)
decl|const
block|{
return|return
name|path
index|[
name|Level
index|]
operator|.
name|offset
operator|==
name|path
index|[
name|Level
index|]
operator|.
name|size
operator|-
literal|1
return|;
block|}
end_decl_stmt

begin_comment
comment|/// legalizeForInsert - Prepare the path for an insertion at Level. When the
end_comment

begin_comment
comment|/// path is at end(), node(Level) may not be a legal node. legalizeForInsert
end_comment

begin_comment
comment|/// ensures that node(Level) is real by moving back to the last node at Level,
end_comment

begin_comment
comment|/// and setting offset(Level) to size(Level) if required.
end_comment

begin_comment
comment|/// @param Level The level where an insertion is about to take place.
end_comment

begin_function
name|void
name|legalizeForInsert
parameter_list|(
name|unsigned
name|Level
parameter_list|)
block|{
if|if
condition|(
name|valid
argument_list|()
condition|)
return|return;
name|moveLeft
argument_list|(
name|Level
argument_list|)
expr_stmt|;
operator|++
name|path
index|[
name|Level
index|]
operator|.
name|offset
expr_stmt|;
block|}
end_function

begin_comment
unit|};  }
comment|// end namespace IntervalMapImpl
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//---                          IntervalMap                                ----//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|=
name|IntervalMapImpl
operator|::
name|NodeSizer
operator|<
name|KeyT
operator|,
name|ValT
operator|>
operator|::
name|LeafSize
operator|,
name|typename
name|Traits
operator|=
name|IntervalMapInfo
operator|<
name|KeyT
operator|>>
name|class
name|IntervalMap
block|{
name|using
name|Sizer
operator|=
name|IntervalMapImpl
operator|::
name|NodeSizer
operator|<
name|KeyT
block|,
name|ValT
operator|>
block|;
name|using
name|Leaf
operator|=
name|IntervalMapImpl
operator|::
name|LeafNode
operator|<
name|KeyT
block|,
name|ValT
block|,
name|Sizer
operator|::
name|LeafSize
block|,
name|Traits
operator|>
block|;
name|using
name|Branch
operator|=
name|IntervalMapImpl
operator|::
name|BranchNode
operator|<
name|KeyT
block|,
name|ValT
block|,
name|Sizer
operator|::
name|BranchSize
block|,
name|Traits
operator|>
block|;
name|using
name|RootLeaf
operator|=
name|IntervalMapImpl
operator|::
name|LeafNode
operator|<
name|KeyT
block|,
name|ValT
block|,
name|N
block|,
name|Traits
operator|>
block|;
name|using
name|IdxPair
operator|=
name|IntervalMapImpl
operator|::
name|IdxPair
block|;
comment|// The RootLeaf capacity is given as a template parameter. We must compute the
comment|// corresponding RootBranch capacity.
block|enum
block|{
name|DesiredRootBranchCap
operator|=
operator|(
sizeof|sizeof
argument_list|(
name|RootLeaf
argument_list|)
operator|-
sizeof|sizeof
argument_list|(
name|KeyT
argument_list|)
operator|)
operator|/
operator|(
sizeof|sizeof
argument_list|(
name|KeyT
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|IntervalMapImpl
operator|::
name|NodeRef
argument_list|)
operator|)
block|,
name|RootBranchCap
operator|=
name|DesiredRootBranchCap
operator|?
name|DesiredRootBranchCap
operator|:
literal|1
block|}
block|;
name|using
name|RootBranch
operator|=
name|IntervalMapImpl
operator|::
name|BranchNode
operator|<
name|KeyT
block|,
name|ValT
block|,
name|RootBranchCap
block|,
name|Traits
operator|>
block|;
comment|// When branched, we store a global start key as well as the branch node.
block|struct
name|RootBranchData
block|{
name|KeyT
name|start
block|;
name|RootBranch
name|node
block|;   }
block|;
name|public
operator|:
name|using
name|Allocator
operator|=
name|typename
name|Sizer
operator|::
name|Allocator
block|;
name|using
name|KeyType
operator|=
name|KeyT
block|;
name|using
name|ValueType
operator|=
name|ValT
block|;
name|using
name|KeyTraits
operator|=
name|Traits
block|;
name|private
operator|:
comment|// The root data is either a RootLeaf or a RootBranchData instance.
name|AlignedCharArrayUnion
operator|<
name|RootLeaf
block|,
name|RootBranchData
operator|>
name|data
block|;
comment|// Tree height.
comment|// 0: Leaves in root.
comment|// 1: Root points to leaf.
comment|// 2: root->branch->leaf ...
name|unsigned
name|height
block|;
comment|// Number of entries in the root node.
name|unsigned
name|rootSize
block|;
comment|// Allocator used for creating external nodes.
name|Allocator
operator|&
name|allocator
block|;
comment|/// dataAs - Represent data as a node type without breaking aliasing rules.
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|&
name|dataAs
argument_list|()
specifier|const
block|{
expr|union
block|{
specifier|const
name|char
operator|*
name|d
block|;
name|T
operator|*
name|t
block|;     }
name|u
block|;
name|u
operator|.
name|d
operator|=
name|data
operator|.
name|buffer
block|;
return|return
operator|*
name|u
operator|.
name|t
return|;
block|}
specifier|const
name|RootLeaf
operator|&
name|rootLeaf
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|branched
argument_list|()
operator|&&
literal|"Cannot acces leaf data in branched root"
argument_list|)
block|;
return|return
name|dataAs
operator|<
name|RootLeaf
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_function
name|RootLeaf
modifier|&
name|rootLeaf
parameter_list|()
block|{
name|assert
argument_list|(
operator|!
name|branched
argument_list|()
operator|&&
literal|"Cannot acces leaf data in branched root"
argument_list|)
expr_stmt|;
return|return
name|dataAs
operator|<
name|RootLeaf
operator|>
operator|(
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|RootBranchData
operator|&
name|rootBranchData
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|branched
argument_list|()
operator|&&
literal|"Cannot access branch data in non-branched root"
argument_list|)
block|;
return|return
name|dataAs
operator|<
name|RootBranchData
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_function
name|RootBranchData
modifier|&
name|rootBranchData
parameter_list|()
block|{
name|assert
argument_list|(
name|branched
argument_list|()
operator|&&
literal|"Cannot access branch data in non-branched root"
argument_list|)
expr_stmt|;
return|return
name|dataAs
operator|<
name|RootBranchData
operator|>
operator|(
operator|)
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|RootBranch
operator|&
name|rootBranch
argument_list|()
specifier|const
block|{
return|return
name|rootBranchData
argument_list|()
operator|.
name|node
return|;
block|}
end_expr_stmt

begin_function
name|RootBranch
modifier|&
name|rootBranch
parameter_list|()
block|{
return|return
name|rootBranchData
argument_list|()
operator|.
name|node
return|;
block|}
end_function

begin_expr_stmt
name|KeyT
name|rootBranchStart
argument_list|()
specifier|const
block|{
return|return
name|rootBranchData
argument_list|()
operator|.
name|start
return|;
block|}
end_expr_stmt

begin_function
name|KeyT
modifier|&
name|rootBranchStart
parameter_list|()
block|{
return|return
name|rootBranchData
argument_list|()
operator|.
name|start
return|;
block|}
end_function

begin_expr_stmt
name|template
operator|<
name|typename
name|NodeT
operator|>
name|NodeT
operator|*
name|newNode
argument_list|()
block|{
return|return
name|new
argument_list|(
argument|allocator.template Allocate<NodeT>()
argument_list|)
name|NodeT
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|NodeT
operator|>
name|void
name|deleteNode
argument_list|(
argument|NodeT *P
argument_list|)
block|{
name|P
operator|->
expr|~
name|NodeT
argument_list|()
block|;
name|allocator
operator|.
name|Deallocate
argument_list|(
name|P
argument_list|)
block|;   }
name|IdxPair
name|branchRoot
argument_list|(
argument|unsigned Position
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|IdxPair
name|splitRoot
parameter_list|(
name|unsigned
name|Position
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|switchRootToBranch
parameter_list|()
block|{
name|rootLeaf
argument_list|()
operator|.
operator|~
name|RootLeaf
argument_list|()
expr_stmt|;
name|height
operator|=
literal|1
expr_stmt|;
name|new
argument_list|(
argument|&rootBranchData()
argument_list|)
name|RootBranchData
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|switchRootToLeaf
parameter_list|()
block|{
name|rootBranchData
argument_list|()
operator|.
operator|~
name|RootBranchData
argument_list|()
expr_stmt|;
name|height
operator|=
literal|0
expr_stmt|;
name|new
argument_list|(
argument|&rootLeaf()
argument_list|)
name|RootLeaf
argument_list|()
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|branched
argument_list|()
specifier|const
block|{
return|return
name|height
operator|>
literal|0
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|ValT
name|treeSafeLookup
argument_list|(
name|KeyT
name|x
argument_list|,
name|ValT
name|NotFound
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|visitNodes
argument_list|(
name|void
argument_list|(
argument|IntervalMap::*f
argument_list|)
operator|(
name|IntervalMapImpl
operator|::
name|NodeRef
operator|,
name|unsigned
name|Level
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|deleteNode
argument_list|(
name|IntervalMapImpl
operator|::
name|NodeRef
name|Node
argument_list|,
name|unsigned
name|Level
argument_list|)
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_macro
name|explicit
end_macro

begin_expr_stmt
name|IntervalMap
argument_list|(
name|Allocator
operator|&
name|a
argument_list|)
operator|:
name|height
argument_list|(
literal|0
argument_list|)
operator|,
name|rootSize
argument_list|(
literal|0
argument_list|)
operator|,
name|allocator
argument_list|(
argument|a
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|uintptr_t
argument_list|(
name|data
operator|.
name|buffer
argument_list|)
operator|&
operator|(
name|alignof
argument_list|(
name|RootLeaf
argument_list|)
operator|-
literal|1
operator|)
operator|)
operator|==
literal|0
operator|&&
literal|"Insufficient alignment"
argument_list|)
block|;
name|new
argument_list|(
argument|&rootLeaf()
argument_list|)
name|RootLeaf
argument_list|()
block|;   }
operator|~
name|IntervalMap
argument_list|()
block|{
name|clear
argument_list|()
block|;
name|rootLeaf
argument_list|()
operator|.
operator|~
name|RootLeaf
argument_list|()
block|;   }
comment|/// empty -  Return true when no intervals are mapped.
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|rootSize
operator|==
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/// start - Return the smallest mapped key in a non-empty map.
end_comment

begin_expr_stmt
name|KeyT
name|start
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|empty
argument_list|()
operator|&&
literal|"Empty IntervalMap has no start"
argument_list|)
block|;
return|return
operator|!
name|branched
argument_list|()
condition|?
name|rootLeaf
argument_list|()
operator|.
name|start
argument_list|(
literal|0
argument_list|)
else|:
name|rootBranchStart
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// stop - Return the largest mapped key in a non-empty map.
end_comment

begin_expr_stmt
name|KeyT
name|stop
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|empty
argument_list|()
operator|&&
literal|"Empty IntervalMap has no stop"
argument_list|)
block|;
return|return
operator|!
name|branched
argument_list|()
condition|?
name|rootLeaf
argument_list|()
operator|.
name|stop
argument_list|(
name|rootSize
operator|-
literal|1
argument_list|)
else|:
name|rootBranch
argument_list|()
operator|.
name|stop
argument_list|(
name|rootSize
operator|-
literal|1
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// lookup - Return the mapped value at x or NotFound.
end_comment

begin_decl_stmt
name|ValT
name|lookup
argument_list|(
name|KeyT
name|x
argument_list|,
name|ValT
name|NotFound
operator|=
name|ValT
argument_list|()
argument_list|)
decl|const
block|{
if|if
condition|(
name|empty
argument_list|()
operator|||
name|Traits
operator|::
name|startLess
argument_list|(
name|x
argument_list|,
name|start
argument_list|()
argument_list|)
operator|||
name|Traits
operator|::
name|stopLess
argument_list|(
name|stop
argument_list|()
argument_list|,
name|x
argument_list|)
condition|)
return|return
name|NotFound
return|;
return|return
name|branched
argument_list|()
condition|?
name|treeSafeLookup
argument_list|(
name|x
argument_list|,
name|NotFound
argument_list|)
else|:
name|rootLeaf
argument_list|()
operator|.
name|safeLookup
argument_list|(
name|x
argument_list|,
name|NotFound
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// insert - Add a mapping of [a;b] to y, coalesce with adjacent intervals.
end_comment

begin_comment
comment|/// It is assumed that no key in the interval is mapped to another value, but
end_comment

begin_comment
comment|/// overlapping intervals already mapped to y will be coalesced.
end_comment

begin_function
name|void
name|insert
parameter_list|(
name|KeyT
name|a
parameter_list|,
name|KeyT
name|b
parameter_list|,
name|ValT
name|y
parameter_list|)
block|{
if|if
condition|(
name|branched
argument_list|()
operator|||
name|rootSize
operator|==
name|RootLeaf
operator|::
name|Capacity
condition|)
return|return
name|find
argument_list|(
name|a
argument_list|)
operator|.
name|insert
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|y
argument_list|)
return|;
comment|// Easy insert into root leaf.
name|unsigned
name|p
init|=
name|rootLeaf
argument_list|()
operator|.
name|findFrom
argument_list|(
literal|0
argument_list|,
name|rootSize
argument_list|,
name|a
argument_list|)
decl_stmt|;
name|rootSize
operator|=
name|rootLeaf
argument_list|()
operator|.
name|insertFrom
argument_list|(
name|p
argument_list|,
name|rootSize
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// clear - Remove all entries.
end_comment

begin_function_decl
name|void
name|clear
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|class
name|const_iterator
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|iterator
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|const_iterator
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|iterator
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
name|const_iterator
name|I
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|I
operator|.
name|goToBegin
argument_list|()
block|;
return|return
name|I
return|;
block|}
end_expr_stmt

begin_function
name|iterator
name|begin
parameter_list|()
block|{
name|iterator
name|I
argument_list|(
operator|*
name|this
argument_list|)
decl_stmt|;
name|I
operator|.
name|goToBegin
argument_list|()
expr_stmt|;
return|return
name|I
return|;
block|}
end_function

begin_expr_stmt
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
name|const_iterator
name|I
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|I
operator|.
name|goToEnd
argument_list|()
block|;
return|return
name|I
return|;
block|}
end_expr_stmt

begin_function
name|iterator
name|end
parameter_list|()
block|{
name|iterator
name|I
argument_list|(
operator|*
name|this
argument_list|)
decl_stmt|;
name|I
operator|.
name|goToEnd
argument_list|()
expr_stmt|;
return|return
name|I
return|;
block|}
end_function

begin_comment
comment|/// find - Return an iterator pointing to the first interval ending at or
end_comment

begin_comment
comment|/// after x, or end().
end_comment

begin_decl_stmt
name|const_iterator
name|find
argument_list|(
name|KeyT
name|x
argument_list|)
decl|const
block|{
name|const_iterator
name|I
argument_list|(
operator|*
name|this
argument_list|)
decl_stmt|;
name|I
operator|.
name|find
argument_list|(
name|x
argument_list|)
expr_stmt|;
return|return
name|I
return|;
block|}
end_decl_stmt

begin_function
name|iterator
name|find
parameter_list|(
name|KeyT
name|x
parameter_list|)
block|{
name|iterator
name|I
argument_list|(
operator|*
name|this
argument_list|)
decl_stmt|;
name|I
operator|.
name|find
argument_list|(
name|x
argument_list|)
expr_stmt|;
return|return
name|I
return|;
block|}
end_function

begin_comment
unit|};
comment|/// treeSafeLookup - Return the mapped value at x or NotFound, assuming a
end_comment

begin_comment
comment|/// branched root.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|ValT
name|IntervalMap
operator|<
name|KeyT
operator|,
name|ValT
operator|,
name|N
operator|,
name|Traits
operator|>
operator|::
name|treeSafeLookup
argument_list|(
argument|KeyT x
argument_list|,
argument|ValT NotFound
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|branched
argument_list|()
operator|&&
literal|"treeLookup assumes a branched root"
argument_list|)
block|;
name|IntervalMapImpl
operator|::
name|NodeRef
name|NR
operator|=
name|rootBranch
argument_list|()
operator|.
name|safeLookup
argument_list|(
name|x
argument_list|)
block|;
for|for
control|(
name|unsigned
name|h
init|=
name|height
operator|-
literal|1
init|;
name|h
condition|;
operator|--
name|h
control|)
name|NR
operator|=
name|NR
operator|.
name|get
operator|<
name|Branch
operator|>
operator|(
operator|)
operator|.
name|safeLookup
argument_list|(
name|x
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|NR
operator|.
name|get
operator|<
name|Leaf
operator|>
operator|(
operator|)
operator|.
name|safeLookup
argument_list|(
name|x
argument_list|,
name|NotFound
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|// branchRoot - Switch from a leaf root to a branched root.
end_comment

begin_comment
comment|// Return the new (root offset, node offset) corresponding to Position.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|IntervalMapImpl
operator|::
name|IdxPair
name|IntervalMap
operator|<
name|KeyT
operator|,
name|ValT
operator|,
name|N
operator|,
name|Traits
operator|>
operator|::
name|branchRoot
argument_list|(
argument|unsigned Position
argument_list|)
block|{
name|using
name|namespace
name|IntervalMapImpl
block|;
comment|// How many external leaf nodes to hold RootLeaf+1?
specifier|const
name|unsigned
name|Nodes
operator|=
name|RootLeaf
operator|::
name|Capacity
operator|/
name|Leaf
operator|::
name|Capacity
operator|+
literal|1
block|;
comment|// Compute element distribution among new nodes.
name|unsigned
name|size
index|[
name|Nodes
index|]
block|;
name|IdxPair
name|NewOffset
argument_list|(
literal|0
argument_list|,
name|Position
argument_list|)
block|;
comment|// Is is very common for the root node to be smaller than external nodes.
if|if
condition|(
name|Nodes
operator|==
literal|1
condition|)
name|size
index|[
literal|0
index|]
operator|=
name|rootSize
expr_stmt|;
else|else
name|NewOffset
operator|=
name|distribute
argument_list|(
name|Nodes
argument_list|,
name|rootSize
argument_list|,
name|Leaf
operator|::
name|Capacity
argument_list|,
name|nullptr
argument_list|,
name|size
argument_list|,
name|Position
argument_list|,
name|true
argument_list|)
expr_stmt|;
comment|// Allocate new nodes.
name|unsigned
name|pos
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|NodeRef
name|node
index|[
name|Nodes
index|]
decl_stmt|;
end_decl_stmt

begin_for
for|for
control|(
name|unsigned
name|n
init|=
literal|0
init|;
name|n
operator|!=
name|Nodes
condition|;
operator|++
name|n
control|)
block|{
name|Leaf
modifier|*
name|L
init|=
name|newNode
operator|<
name|Leaf
operator|>
operator|(
operator|)
decl_stmt|;
name|L
operator|->
name|copy
argument_list|(
name|rootLeaf
argument_list|()
argument_list|,
name|pos
argument_list|,
literal|0
argument_list|,
name|size
index|[
name|n
index|]
argument_list|)
expr_stmt|;
name|node
index|[
name|n
index|]
operator|=
name|NodeRef
argument_list|(
name|L
argument_list|,
name|size
index|[
name|n
index|]
argument_list|)
expr_stmt|;
name|pos
operator|+=
name|size
index|[
name|n
index|]
expr_stmt|;
block|}
end_for

begin_comment
comment|// Destroy the old leaf node, construct branch node instead.
end_comment

begin_expr_stmt
name|switchRootToBranch
argument_list|()
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|unsigned
name|n
init|=
literal|0
init|;
name|n
operator|!=
name|Nodes
condition|;
operator|++
name|n
control|)
block|{
name|rootBranch
argument_list|()
operator|.
name|stop
argument_list|(
name|n
argument_list|)
operator|=
name|node
index|[
name|n
index|]
operator|.
name|template
name|get
operator|<
name|Leaf
operator|>
operator|(
operator|)
operator|.
name|stop
argument_list|(
name|size
index|[
name|n
index|]
operator|-
literal|1
argument_list|)
expr_stmt|;
name|rootBranch
argument_list|()
operator|.
name|subtree
argument_list|(
name|n
argument_list|)
operator|=
name|node
index|[
name|n
index|]
expr_stmt|;
block|}
end_for

begin_expr_stmt
name|rootBranchStart
argument_list|()
operator|=
name|node
index|[
literal|0
index|]
operator|.
name|template
name|get
operator|<
name|Leaf
operator|>
operator|(
operator|)
operator|.
name|start
argument_list|(
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|rootSize
operator|=
name|Nodes
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|NewOffset
return|;
end_return

begin_comment
unit|}
comment|// splitRoot - Split the current BranchRoot into multiple Branch nodes.
end_comment

begin_comment
comment|// Return the new (root offset, node offset) corresponding to Position.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|IntervalMapImpl
operator|::
name|IdxPair
name|IntervalMap
operator|<
name|KeyT
operator|,
name|ValT
operator|,
name|N
operator|,
name|Traits
operator|>
operator|::
name|splitRoot
argument_list|(
argument|unsigned Position
argument_list|)
block|{
name|using
name|namespace
name|IntervalMapImpl
block|;
comment|// How many external leaf nodes to hold RootBranch+1?
specifier|const
name|unsigned
name|Nodes
operator|=
name|RootBranch
operator|::
name|Capacity
operator|/
name|Branch
operator|::
name|Capacity
operator|+
literal|1
block|;
comment|// Compute element distribution among new nodes.
name|unsigned
name|Size
index|[
name|Nodes
index|]
block|;
name|IdxPair
name|NewOffset
argument_list|(
literal|0
argument_list|,
name|Position
argument_list|)
block|;
comment|// Is is very common for the root node to be smaller than external nodes.
if|if
condition|(
name|Nodes
operator|==
literal|1
condition|)
name|Size
index|[
literal|0
index|]
operator|=
name|rootSize
expr_stmt|;
else|else
name|NewOffset
operator|=
name|distribute
argument_list|(
name|Nodes
argument_list|,
name|rootSize
argument_list|,
name|Leaf
operator|::
name|Capacity
argument_list|,
name|nullptr
argument_list|,
name|Size
argument_list|,
name|Position
argument_list|,
name|true
argument_list|)
expr_stmt|;
comment|// Allocate new nodes.
name|unsigned
name|Pos
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|NodeRef
name|Node
index|[
name|Nodes
index|]
decl_stmt|;
end_decl_stmt

begin_for
for|for
control|(
name|unsigned
name|n
init|=
literal|0
init|;
name|n
operator|!=
name|Nodes
condition|;
operator|++
name|n
control|)
block|{
name|Branch
modifier|*
name|B
init|=
name|newNode
operator|<
name|Branch
operator|>
operator|(
operator|)
decl_stmt|;
name|B
operator|->
name|copy
argument_list|(
name|rootBranch
argument_list|()
argument_list|,
name|Pos
argument_list|,
literal|0
argument_list|,
name|Size
index|[
name|n
index|]
argument_list|)
expr_stmt|;
name|Node
index|[
name|n
index|]
operator|=
name|NodeRef
argument_list|(
name|B
argument_list|,
name|Size
index|[
name|n
index|]
argument_list|)
expr_stmt|;
name|Pos
operator|+=
name|Size
index|[
name|n
index|]
expr_stmt|;
block|}
end_for

begin_for
for|for
control|(
name|unsigned
name|n
init|=
literal|0
init|;
name|n
operator|!=
name|Nodes
condition|;
operator|++
name|n
control|)
block|{
name|rootBranch
argument_list|()
operator|.
name|stop
argument_list|(
name|n
argument_list|)
operator|=
name|Node
index|[
name|n
index|]
operator|.
name|template
name|get
operator|<
name|Branch
operator|>
operator|(
operator|)
operator|.
name|stop
argument_list|(
name|Size
index|[
name|n
index|]
operator|-
literal|1
argument_list|)
expr_stmt|;
name|rootBranch
argument_list|()
operator|.
name|subtree
argument_list|(
name|n
argument_list|)
operator|=
name|Node
index|[
name|n
index|]
expr_stmt|;
block|}
end_for

begin_expr_stmt
name|rootSize
operator|=
name|Nodes
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|++
name|height
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|NewOffset
return|;
end_return

begin_comment
unit|}
comment|/// visitNodes - Visit each external node.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|void
name|IntervalMap
operator|<
name|KeyT
operator|,
name|ValT
operator|,
name|N
operator|,
name|Traits
operator|>
operator|::
name|visitNodes
argument_list|(
argument|void (IntervalMap::*f)(IntervalMapImpl::NodeRef, unsigned Height)
argument_list|)
block|{
if|if
condition|(
operator|!
name|branched
argument_list|()
condition|)
return|return;
name|SmallVector
operator|<
name|IntervalMapImpl
operator|::
name|NodeRef
operator|,
literal|4
operator|>
name|Refs
operator|,
name|NextRefs
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Collect level 0 nodes from the root.
end_comment

begin_for
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|rootSize
condition|;
operator|++
name|i
control|)
name|Refs
operator|.
name|push_back
argument_list|(
name|rootBranch
argument_list|()
operator|.
name|subtree
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
end_for

begin_comment
comment|// Visit all branch nodes.
end_comment

begin_for
for|for
control|(
name|unsigned
name|h
init|=
name|height
operator|-
literal|1
init|;
name|h
condition|;
operator|--
name|h
control|)
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|Refs
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
block|{
for|for
control|(
name|unsigned
name|j
init|=
literal|0
init|,
name|s
init|=
name|Refs
index|[
name|i
index|]
operator|.
name|size
argument_list|()
init|;
name|j
operator|!=
name|s
condition|;
operator|++
name|j
control|)
name|NextRefs
operator|.
name|push_back
argument_list|(
name|Refs
index|[
name|i
index|]
operator|.
name|subtree
argument_list|(
name|j
argument_list|)
argument_list|)
expr_stmt|;
operator|(
name|this
operator|->*
name|f
operator|)
operator|(
name|Refs
index|[
name|i
index|]
operator|,
name|h
operator|)
expr_stmt|;
block|}
name|Refs
operator|.
name|clear
argument_list|()
expr_stmt|;
name|Refs
operator|.
name|swap
argument_list|(
name|NextRefs
argument_list|)
expr_stmt|;
block|}
end_for

begin_comment
comment|// Visit all leaf nodes.
end_comment

begin_for
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|Refs
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
operator|(
name|this
operator|->*
name|f
operator|)
operator|(
name|Refs
index|[
name|i
index|]
operator|,
literal|0
operator|)
expr_stmt|;
end_for

begin_expr_stmt
unit|}  template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|void
name|IntervalMap
operator|<
name|KeyT
operator|,
name|ValT
operator|,
name|N
operator|,
name|Traits
operator|>
operator|::
name|deleteNode
argument_list|(
argument|IntervalMapImpl::NodeRef Node
argument_list|,
argument|unsigned Level
argument_list|)
block|{
if|if
condition|(
name|Level
condition|)
name|deleteNode
argument_list|(
operator|&
name|Node
operator|.
name|get
operator|<
name|Branch
operator|>
operator|(
operator|)
argument_list|)
expr_stmt|;
else|else
name|deleteNode
argument_list|(
operator|&
name|Node
operator|.
name|get
operator|<
name|Leaf
operator|>
operator|(
operator|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|void
name|IntervalMap
operator|<
name|KeyT
operator|,
name|ValT
operator|,
name|N
operator|,
name|Traits
operator|>
operator|::
name|clear
argument_list|()
block|{
if|if
condition|(
name|branched
argument_list|()
condition|)
block|{
name|visitNodes
argument_list|(
operator|&
name|IntervalMap
operator|::
name|deleteNode
argument_list|)
expr_stmt|;
name|switchRootToLeaf
argument_list|()
expr_stmt|;
block|}
name|rootSize
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//---                   IntervalMap::const_iterator                       ----//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|class
name|IntervalMap
operator|<
name|KeyT
operator|,
name|ValT
operator|,
name|N
operator|,
name|Traits
operator|>
operator|::
name|const_iterator
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
name|ValT
operator|>
block|{
name|protected
operator|:
name|friend
name|class
name|IntervalMap
block|;
comment|// The map referred to.
name|IntervalMap
operator|*
name|map
operator|=
name|nullptr
block|;
comment|// We store a full path from the root to the current position.
comment|// The path may be partially filled, but never between iterator calls.
name|IntervalMapImpl
operator|::
name|Path
name|path
block|;
name|explicit
name|const_iterator
argument_list|(
specifier|const
name|IntervalMap
operator|&
name|map
argument_list|)
operator|:
name|map
argument_list|(
argument|const_cast<IntervalMap*>(&map)
argument_list|)
block|{}
name|bool
name|branched
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|map
operator|&&
literal|"Invalid iterator"
argument_list|)
block|;
return|return
name|map
operator|->
name|branched
argument_list|()
return|;
block|}
name|void
name|setRoot
argument_list|(
argument|unsigned Offset
argument_list|)
block|{
if|if
condition|(
name|branched
argument_list|()
condition|)
name|path
operator|.
name|setRoot
argument_list|(
operator|&
name|map
operator|->
name|rootBranch
argument_list|()
argument_list|,
name|map
operator|->
name|rootSize
argument_list|,
name|Offset
argument_list|)
expr_stmt|;
else|else
name|path
operator|.
name|setRoot
argument_list|(
operator|&
name|map
operator|->
name|rootLeaf
argument_list|()
argument_list|,
name|map
operator|->
name|rootSize
argument_list|,
name|Offset
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|pathFillFind
parameter_list|(
name|KeyT
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|treeFind
parameter_list|(
name|KeyT
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|treeAdvanceTo
parameter_list|(
name|KeyT
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// unsafeStart - Writable access to start() for iterator.
end_comment

begin_expr_stmt
name|KeyT
operator|&
name|unsafeStart
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|valid
argument_list|()
operator|&&
literal|"Cannot access invalid iterator"
argument_list|)
block|;
return|return
name|branched
argument_list|()
condition|?
name|path
operator|.
name|leaf
operator|<
name|Leaf
operator|>
operator|(
operator|)
operator|.
name|start
argument_list|(
name|path
operator|.
name|leafOffset
argument_list|()
argument_list|)
else|:
name|path
operator|.
name|leaf
operator|<
name|RootLeaf
operator|>
operator|(
operator|)
operator|.
name|start
argument_list|(
name|path
operator|.
name|leafOffset
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// unsafeStop - Writable access to stop() for iterator.
end_comment

begin_expr_stmt
name|KeyT
operator|&
name|unsafeStop
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|valid
argument_list|()
operator|&&
literal|"Cannot access invalid iterator"
argument_list|)
block|;
return|return
name|branched
argument_list|()
condition|?
name|path
operator|.
name|leaf
operator|<
name|Leaf
operator|>
operator|(
operator|)
operator|.
name|stop
argument_list|(
name|path
operator|.
name|leafOffset
argument_list|()
argument_list|)
else|:
name|path
operator|.
name|leaf
operator|<
name|RootLeaf
operator|>
operator|(
operator|)
operator|.
name|stop
argument_list|(
name|path
operator|.
name|leafOffset
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// unsafeValue - Writable access to value() for iterator.
end_comment

begin_expr_stmt
name|ValT
operator|&
name|unsafeValue
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|valid
argument_list|()
operator|&&
literal|"Cannot access invalid iterator"
argument_list|)
block|;
return|return
name|branched
argument_list|()
condition|?
name|path
operator|.
name|leaf
operator|<
name|Leaf
operator|>
operator|(
operator|)
operator|.
name|value
argument_list|(
name|path
operator|.
name|leafOffset
argument_list|()
argument_list|)
else|:
name|path
operator|.
name|leaf
operator|<
name|RootLeaf
operator|>
operator|(
operator|)
operator|.
name|value
argument_list|(
name|path
operator|.
name|leafOffset
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// const_iterator - Create an iterator that isn't pointing anywhere.
end_comment

begin_expr_stmt
name|const_iterator
argument_list|()
operator|=
expr|default
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// setMap - Change the map iterated over. This call must be followed by a
end_comment

begin_comment
comment|/// call to goToBegin(), goToEnd(), or find()
end_comment

begin_function
name|void
name|setMap
parameter_list|(
specifier|const
name|IntervalMap
modifier|&
name|m
parameter_list|)
block|{
name|map
operator|=
name|const_cast
operator|<
name|IntervalMap
operator|*
operator|>
operator|(
operator|&
name|m
operator|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// valid - Return true if the current position is valid, false for end().
end_comment

begin_expr_stmt
name|bool
name|valid
argument_list|()
specifier|const
block|{
return|return
name|path
operator|.
name|valid
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// atBegin - Return true if the current position is the first map entry.
end_comment

begin_expr_stmt
name|bool
name|atBegin
argument_list|()
specifier|const
block|{
return|return
name|path
operator|.
name|atBegin
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// start - Return the beginning of the current interval.
end_comment

begin_expr_stmt
specifier|const
name|KeyT
operator|&
name|start
argument_list|()
specifier|const
block|{
return|return
name|unsafeStart
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// stop - Return the end of the current interval.
end_comment

begin_expr_stmt
specifier|const
name|KeyT
operator|&
name|stop
argument_list|()
specifier|const
block|{
return|return
name|unsafeStop
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// value - Return the mapped value at the current interval.
end_comment

begin_expr_stmt
specifier|const
name|ValT
operator|&
name|value
argument_list|()
specifier|const
block|{
return|return
name|unsafeValue
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|ValT
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|value
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|const_iterator
operator|&
name|RHS
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|map
operator|==
name|RHS
operator|.
name|map
operator|&&
literal|"Cannot compare iterators from different maps"
argument_list|)
block|;
if|if
condition|(
operator|!
name|valid
argument_list|()
condition|)
return|return
operator|!
name|RHS
operator|.
name|valid
argument_list|()
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|path
operator|.
name|leafOffset
argument_list|()
operator|!=
name|RHS
operator|.
name|path
operator|.
name|leafOffset
argument_list|()
condition|)
return|return
name|false
return|;
end_if

begin_return
return|return
operator|&
name|path
operator|.
name|template
name|leaf
operator|<
name|Leaf
operator|>
operator|(
operator|)
operator|==
operator|&
name|RHS
operator|.
name|path
operator|.
name|template
name|leaf
operator|<
name|Leaf
operator|>
operator|(
operator|)
return|;
end_return

begin_expr_stmt
unit|}    bool
name|operator
operator|!=
operator|(
specifier|const
name|const_iterator
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
comment|/// goToBegin - Move to the first interval in map.
end_comment

begin_function
name|void
name|goToBegin
parameter_list|()
block|{
name|setRoot
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|branched
argument_list|()
condition|)
name|path
operator|.
name|fillLeft
argument_list|(
name|map
operator|->
name|height
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// goToEnd - Move beyond the last interval in map.
end_comment

begin_function
name|void
name|goToEnd
parameter_list|()
block|{
name|setRoot
argument_list|(
name|map
operator|->
name|rootSize
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// preincrement - move to the next interval.
end_comment

begin_expr_stmt
name|const_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|assert
argument_list|(
name|valid
argument_list|()
operator|&&
literal|"Cannot increment end()"
argument_list|)
block|;
if|if
condition|(
operator|++
name|path
operator|.
name|leafOffset
argument_list|()
operator|==
name|path
operator|.
name|leafSize
argument_list|()
operator|&&
name|branched
argument_list|()
condition|)
name|path
operator|.
name|moveRight
argument_list|(
name|map
operator|->
name|height
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_comment
unit|}
comment|/// postincrement - Dont do that!
end_comment

begin_expr_stmt
unit|const_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|const_iterator
name|tmp
operator|=
operator|*
name|this
block|;
name|operator
operator|++
operator|(
operator|)
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_comment
comment|/// predecrement - move to the previous interval.
end_comment

begin_expr_stmt
name|const_iterator
operator|&
name|operator
operator|--
operator|(
operator|)
block|{
if|if
condition|(
name|path
operator|.
name|leafOffset
argument_list|()
operator|&&
operator|(
name|valid
argument_list|()
operator|||
operator|!
name|branched
argument_list|()
operator|)
condition|)
operator|--
name|path
operator|.
name|leafOffset
argument_list|()
expr_stmt|;
else|else
name|path
operator|.
name|moveLeft
argument_list|(
name|map
operator|->
name|height
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_comment
unit|}
comment|/// postdecrement - Dont do that!
end_comment

begin_expr_stmt
unit|const_iterator
name|operator
operator|--
operator|(
name|int
operator|)
block|{
name|const_iterator
name|tmp
operator|=
operator|*
name|this
block|;
name|operator
operator|--
operator|(
operator|)
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_comment
comment|/// find - Move to the first interval with stop>= x, or end().
end_comment

begin_comment
comment|/// This is a full search from the root, the current position is ignored.
end_comment

begin_function
name|void
name|find
parameter_list|(
name|KeyT
name|x
parameter_list|)
block|{
if|if
condition|(
name|branched
argument_list|()
condition|)
name|treeFind
argument_list|(
name|x
argument_list|)
expr_stmt|;
else|else
name|setRoot
argument_list|(
name|map
operator|->
name|rootLeaf
argument_list|()
operator|.
name|findFrom
argument_list|(
literal|0
argument_list|,
name|map
operator|->
name|rootSize
argument_list|,
name|x
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// advanceTo - Move to the first interval with stop>= x, or end().
end_comment

begin_comment
comment|/// The search is started from the current position, and no earlier positions
end_comment

begin_comment
comment|/// can be found. This is much faster than find() for small moves.
end_comment

begin_function
name|void
name|advanceTo
parameter_list|(
name|KeyT
name|x
parameter_list|)
block|{
if|if
condition|(
operator|!
name|valid
argument_list|()
condition|)
return|return;
if|if
condition|(
name|branched
argument_list|()
condition|)
name|treeAdvanceTo
argument_list|(
name|x
argument_list|)
expr_stmt|;
else|else
name|path
operator|.
name|leafOffset
argument_list|()
operator|=
name|map
operator|->
name|rootLeaf
argument_list|()
operator|.
name|findFrom
argument_list|(
name|path
operator|.
name|leafOffset
argument_list|()
argument_list|,
name|map
operator|->
name|rootSize
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
unit|};
comment|/// pathFillFind - Complete path by searching for x.
end_comment

begin_comment
comment|/// @param x Key to search for.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|void
name|IntervalMap
operator|<
name|KeyT
operator|,
name|ValT
operator|,
name|N
operator|,
name|Traits
operator|>
operator|::
name|const_iterator
operator|::
name|pathFillFind
argument_list|(
argument|KeyT x
argument_list|)
block|{
name|IntervalMapImpl
operator|::
name|NodeRef
name|NR
operator|=
name|path
operator|.
name|subtree
argument_list|(
name|path
operator|.
name|height
argument_list|()
argument_list|)
block|;
for|for
control|(
name|unsigned
name|i
init|=
name|map
operator|->
name|height
operator|-
name|path
operator|.
name|height
argument_list|()
operator|-
literal|1
init|;
name|i
condition|;
operator|--
name|i
control|)
block|{
name|unsigned
name|p
init|=
name|NR
operator|.
name|get
operator|<
name|Branch
operator|>
operator|(
operator|)
operator|.
name|safeFind
argument_list|(
literal|0
argument_list|,
name|x
argument_list|)
decl_stmt|;
name|path
operator|.
name|push
argument_list|(
name|NR
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|NR
operator|=
name|NR
operator|.
name|subtree
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
name|path
operator|.
name|push
argument_list|(
name|NR
argument_list|,
name|NR
operator|.
name|get
operator|<
name|Leaf
operator|>
operator|(
operator|)
operator|.
name|safeFind
argument_list|(
literal|0
argument_list|,
name|x
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/// treeFind - Find in a branched tree.
end_comment

begin_comment
comment|/// @param x Key to search for.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|void
name|IntervalMap
operator|<
name|KeyT
operator|,
name|ValT
operator|,
name|N
operator|,
name|Traits
operator|>
operator|::
name|const_iterator
operator|::
name|treeFind
argument_list|(
argument|KeyT x
argument_list|)
block|{
name|setRoot
argument_list|(
name|map
operator|->
name|rootBranch
argument_list|()
operator|.
name|findFrom
argument_list|(
literal|0
argument_list|,
name|map
operator|->
name|rootSize
argument_list|,
name|x
argument_list|)
argument_list|)
block|;
if|if
condition|(
name|valid
argument_list|()
condition|)
name|pathFillFind
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
comment|/// treeAdvanceTo - Find position after the current one.
end_comment

begin_comment
comment|/// @param x Key to search for.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|void
name|IntervalMap
operator|<
name|KeyT
operator|,
name|ValT
operator|,
name|N
operator|,
name|Traits
operator|>
operator|::
name|const_iterator
operator|::
name|treeAdvanceTo
argument_list|(
argument|KeyT x
argument_list|)
block|{
comment|// Can we stay on the same leaf node?
if|if
condition|(
operator|!
name|Traits
operator|::
name|stopLess
argument_list|(
name|path
operator|.
name|leaf
operator|<
name|Leaf
operator|>
operator|(
operator|)
operator|.
name|stop
argument_list|(
name|path
operator|.
name|leafSize
argument_list|()
operator|-
literal|1
argument_list|)
argument_list|,
name|x
argument_list|)
condition|)
block|{
name|path
operator|.
name|leafOffset
argument_list|()
operator|=
name|path
operator|.
name|leaf
operator|<
name|Leaf
operator|>
operator|(
operator|)
operator|.
name|safeFind
argument_list|(
name|path
operator|.
name|leafOffset
argument_list|()
argument_list|,
name|x
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// Drop the current leaf.
name|path
operator|.
name|pop
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Search towards the root for a usable subtree.
end_comment

begin_if
if|if
condition|(
name|path
operator|.
name|height
argument_list|()
condition|)
block|{
for|for
control|(
name|unsigned
name|l
init|=
name|path
operator|.
name|height
argument_list|()
operator|-
literal|1
init|;
name|l
condition|;
operator|--
name|l
control|)
block|{
if|if
condition|(
operator|!
name|Traits
operator|::
name|stopLess
argument_list|(
name|path
operator|.
name|node
operator|<
name|Branch
operator|>
operator|(
name|l
operator|)
operator|.
name|stop
argument_list|(
name|path
operator|.
name|offset
argument_list|(
name|l
argument_list|)
argument_list|)
argument_list|,
name|x
argument_list|)
condition|)
block|{
comment|// The branch node at l+1 is usable
name|path
operator|.
name|offset
argument_list|(
name|l
operator|+
literal|1
argument_list|)
operator|=
name|path
operator|.
name|node
operator|<
name|Branch
operator|>
operator|(
name|l
operator|+
literal|1
operator|)
operator|.
name|safeFind
argument_list|(
name|path
operator|.
name|offset
argument_list|(
name|l
operator|+
literal|1
argument_list|)
argument_list|,
name|x
argument_list|)
expr_stmt|;
return|return
name|pathFillFind
argument_list|(
name|x
argument_list|)
return|;
block|}
name|path
operator|.
name|pop
argument_list|()
expr_stmt|;
block|}
comment|// Is the level-1 Branch usable?
if|if
condition|(
operator|!
name|Traits
operator|::
name|stopLess
argument_list|(
name|map
operator|->
name|rootBranch
argument_list|()
operator|.
name|stop
argument_list|(
name|path
operator|.
name|offset
argument_list|(
literal|0
argument_list|)
argument_list|)
argument_list|,
name|x
argument_list|)
condition|)
block|{
name|path
operator|.
name|offset
argument_list|(
literal|1
argument_list|)
operator|=
name|path
operator|.
name|node
operator|<
name|Branch
operator|>
operator|(
literal|1
operator|)
operator|.
name|safeFind
argument_list|(
name|path
operator|.
name|offset
argument_list|(
literal|1
argument_list|)
argument_list|,
name|x
argument_list|)
expr_stmt|;
return|return
name|pathFillFind
argument_list|(
name|x
argument_list|)
return|;
block|}
block|}
end_if

begin_comment
comment|// We reached the root.
end_comment

begin_expr_stmt
name|setRoot
argument_list|(
name|map
operator|->
name|rootBranch
argument_list|()
operator|.
name|findFrom
argument_list|(
name|path
operator|.
name|offset
argument_list|(
literal|0
argument_list|)
argument_list|,
name|map
operator|->
name|rootSize
argument_list|,
name|x
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|valid
argument_list|()
condition|)
name|pathFillFind
argument_list|(
name|x
argument_list|)
expr_stmt|;
end_if

begin_comment
unit|}
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//---                       IntervalMap::iterator                         ----//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|class
name|IntervalMap
operator|<
name|KeyT
operator|,
name|ValT
operator|,
name|N
operator|,
name|Traits
operator|>
operator|::
name|iterator
operator|:
name|public
name|const_iterator
block|{
name|friend
name|class
name|IntervalMap
block|;
name|using
name|IdxPair
operator|=
name|IntervalMapImpl
operator|::
name|IdxPair
block|;
name|explicit
name|iterator
argument_list|(
name|IntervalMap
operator|&
name|map
argument_list|)
operator|:
name|const_iterator
argument_list|(
argument|map
argument_list|)
block|{}
name|void
name|setNodeStop
argument_list|(
argument|unsigned Level
argument_list|,
argument|KeyT Stop
argument_list|)
block|;
name|bool
name|insertNode
argument_list|(
argument|unsigned Level
argument_list|,
argument|IntervalMapImpl::NodeRef Node
argument_list|,
argument|KeyT Stop
argument_list|)
block|;
name|template
operator|<
name|typename
name|NodeT
operator|>
name|bool
name|overflow
argument_list|(
argument|unsigned Level
argument_list|)
block|;
name|void
name|treeInsert
argument_list|(
argument|KeyT a
argument_list|,
argument|KeyT b
argument_list|,
argument|ValT y
argument_list|)
block|;
name|void
name|eraseNode
argument_list|(
argument|unsigned Level
argument_list|)
block|;
name|void
name|treeErase
argument_list|(
argument|bool UpdateRoot = true
argument_list|)
block|;
name|bool
name|canCoalesceLeft
argument_list|(
argument|KeyT Start
argument_list|,
argument|ValT x
argument_list|)
block|;
name|bool
name|canCoalesceRight
argument_list|(
argument|KeyT Stop
argument_list|,
argument|ValT x
argument_list|)
block|;
name|public
operator|:
comment|/// iterator - Create null iterator.
name|iterator
argument_list|()
operator|=
expr|default
block|;
comment|/// setStart - Move the start of the current interval.
comment|/// This may cause coalescing with the previous interval.
comment|/// @param a New start key, must not overlap the previous interval.
name|void
name|setStart
argument_list|(
argument|KeyT a
argument_list|)
block|;
comment|/// setStop - Move the end of the current interval.
comment|/// This may cause coalescing with the following interval.
comment|/// @param b New stop key, must not overlap the following interval.
name|void
name|setStop
argument_list|(
argument|KeyT b
argument_list|)
block|;
comment|/// setValue - Change the mapped value of the current interval.
comment|/// This may cause coalescing with the previous and following intervals.
comment|/// @param x New value.
name|void
name|setValue
argument_list|(
argument|ValT x
argument_list|)
block|;
comment|/// setStartUnchecked - Move the start of the current interval without
comment|/// checking for coalescing or overlaps.
comment|/// This should only be used when it is known that coalescing is not required.
comment|/// @param a New start key.
name|void
name|setStartUnchecked
argument_list|(
argument|KeyT a
argument_list|)
block|{
name|this
operator|->
name|unsafeStart
argument_list|()
operator|=
name|a
block|; }
comment|/// setStopUnchecked - Move the end of the current interval without checking
comment|/// for coalescing or overlaps.
comment|/// This should only be used when it is known that coalescing is not required.
comment|/// @param b New stop key.
name|void
name|setStopUnchecked
argument_list|(
argument|KeyT b
argument_list|)
block|{
name|this
operator|->
name|unsafeStop
argument_list|()
operator|=
name|b
block|;
comment|// Update keys in branch nodes as well.
if|if
condition|(
name|this
operator|->
name|path
operator|.
name|atLastEntry
argument_list|(
name|this
operator|->
name|path
operator|.
name|height
argument_list|()
argument_list|)
condition|)
name|setNodeStop
argument_list|(
name|this
operator|->
name|path
operator|.
name|height
argument_list|()
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
comment|/// setValueUnchecked - Change the mapped value of the current interval
comment|/// without checking for coalescing.
comment|/// @param x New value.
name|void
name|setValueUnchecked
argument_list|(
argument|ValT x
argument_list|)
block|{
name|this
operator|->
name|unsafeValue
argument_list|()
operator|=
name|x
block|; }
comment|/// insert - Insert mapping [a;b] -> y before the current position.
name|void
name|insert
argument_list|(
argument|KeyT a
argument_list|,
argument|KeyT b
argument_list|,
argument|ValT y
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// erase - Erase the current interval.
end_comment

begin_function_decl
name|void
name|erase
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|const_iterator
operator|::
name|operator
operator|++
operator|(
operator|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|iterator
name|tmp
operator|=
operator|*
name|this
block|;
name|operator
operator|++
operator|(
operator|)
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|iterator
operator|&
name|operator
operator|--
operator|(
operator|)
block|{
name|const_iterator
operator|::
name|operator
operator|--
operator|(
operator|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|iterator
name|operator
operator|--
operator|(
name|int
operator|)
block|{
name|iterator
name|tmp
operator|=
operator|*
name|this
block|;
name|operator
operator|--
operator|(
operator|)
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// canCoalesceLeft - Can the current interval coalesce to the left after
end_comment

begin_comment
comment|/// changing start or value?
end_comment

begin_comment
comment|/// @param Start New start of current interval.
end_comment

begin_comment
comment|/// @param Value New value for current interval.
end_comment

begin_comment
comment|/// @return True when updating the current interval would enable coalescing.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|bool
name|IntervalMap
operator|<
name|KeyT
operator|,
name|ValT
operator|,
name|N
operator|,
name|Traits
operator|>
operator|::
name|iterator
operator|::
name|canCoalesceLeft
argument_list|(
argument|KeyT Start
argument_list|,
argument|ValT Value
argument_list|)
block|{
name|using
name|namespace
name|IntervalMapImpl
block|;
name|Path
operator|&
name|P
operator|=
name|this
operator|->
name|path
block|;
if|if
condition|(
operator|!
name|this
operator|->
name|branched
argument_list|()
condition|)
block|{
name|unsigned
name|i
init|=
name|P
operator|.
name|leafOffset
argument_list|()
decl_stmt|;
name|RootLeaf
modifier|&
name|Node
init|=
name|P
operator|.
name|leaf
operator|<
name|RootLeaf
operator|>
operator|(
operator|)
decl_stmt|;
return|return
name|i
operator|&&
name|Node
operator|.
name|value
argument_list|(
name|i
operator|-
literal|1
argument_list|)
operator|==
name|Value
operator|&&
name|Traits
operator|::
name|adjacent
argument_list|(
name|Node
operator|.
name|stop
argument_list|(
name|i
operator|-
literal|1
argument_list|)
argument_list|,
name|Start
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Branched.
end_comment

begin_if
if|if
condition|(
name|unsigned
name|i
init|=
name|P
operator|.
name|leafOffset
argument_list|()
condition|)
block|{
name|Leaf
modifier|&
name|Node
init|=
name|P
operator|.
name|leaf
operator|<
name|Leaf
operator|>
operator|(
operator|)
decl_stmt|;
return|return
name|Node
operator|.
name|value
argument_list|(
name|i
operator|-
literal|1
argument_list|)
operator|==
name|Value
operator|&&
name|Traits
operator|::
name|adjacent
argument_list|(
name|Node
operator|.
name|stop
argument_list|(
name|i
operator|-
literal|1
argument_list|)
argument_list|,
name|Start
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|NodeRef
name|NR
init|=
name|P
operator|.
name|getLeftSibling
argument_list|(
name|P
operator|.
name|height
argument_list|()
argument_list|)
condition|)
block|{
name|unsigned
name|i
init|=
name|NR
operator|.
name|size
argument_list|()
operator|-
literal|1
decl_stmt|;
name|Leaf
modifier|&
name|Node
init|=
name|NR
operator|.
name|get
operator|<
name|Leaf
operator|>
operator|(
operator|)
decl_stmt|;
return|return
name|Node
operator|.
name|value
argument_list|(
name|i
argument_list|)
operator|==
name|Value
operator|&&
name|Traits
operator|::
name|adjacent
argument_list|(
name|Node
operator|.
name|stop
argument_list|(
name|i
argument_list|)
argument_list|,
name|Start
argument_list|)
return|;
block|}
end_if

begin_return
return|return
name|false
return|;
end_return

begin_comment
unit|}
comment|/// canCoalesceRight - Can the current interval coalesce to the right after
end_comment

begin_comment
comment|/// changing stop or value?
end_comment

begin_comment
comment|/// @param Stop New stop of current interval.
end_comment

begin_comment
comment|/// @param Value New value for current interval.
end_comment

begin_comment
comment|/// @return True when updating the current interval would enable coalescing.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|bool
name|IntervalMap
operator|<
name|KeyT
operator|,
name|ValT
operator|,
name|N
operator|,
name|Traits
operator|>
operator|::
name|iterator
operator|::
name|canCoalesceRight
argument_list|(
argument|KeyT Stop
argument_list|,
argument|ValT Value
argument_list|)
block|{
name|using
name|namespace
name|IntervalMapImpl
block|;
name|Path
operator|&
name|P
operator|=
name|this
operator|->
name|path
block|;
name|unsigned
name|i
operator|=
name|P
operator|.
name|leafOffset
argument_list|()
operator|+
literal|1
block|;
if|if
condition|(
operator|!
name|this
operator|->
name|branched
argument_list|()
condition|)
block|{
if|if
condition|(
name|i
operator|>=
name|P
operator|.
name|leafSize
argument_list|()
condition|)
return|return
name|false
return|;
name|RootLeaf
modifier|&
name|Node
init|=
name|P
operator|.
name|leaf
operator|<
name|RootLeaf
operator|>
operator|(
operator|)
decl_stmt|;
return|return
name|Node
operator|.
name|value
argument_list|(
name|i
argument_list|)
operator|==
name|Value
operator|&&
name|Traits
operator|::
name|adjacent
argument_list|(
name|Stop
argument_list|,
name|Node
operator|.
name|start
argument_list|(
name|i
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Branched.
end_comment

begin_if
if|if
condition|(
name|i
operator|<
name|P
operator|.
name|leafSize
argument_list|()
condition|)
block|{
name|Leaf
modifier|&
name|Node
init|=
name|P
operator|.
name|leaf
operator|<
name|Leaf
operator|>
operator|(
operator|)
decl_stmt|;
return|return
name|Node
operator|.
name|value
argument_list|(
name|i
argument_list|)
operator|==
name|Value
operator|&&
name|Traits
operator|::
name|adjacent
argument_list|(
name|Stop
argument_list|,
name|Node
operator|.
name|start
argument_list|(
name|i
argument_list|)
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|NodeRef
name|NR
init|=
name|P
operator|.
name|getRightSibling
argument_list|(
name|P
operator|.
name|height
argument_list|()
argument_list|)
condition|)
block|{
name|Leaf
modifier|&
name|Node
init|=
name|NR
operator|.
name|get
operator|<
name|Leaf
operator|>
operator|(
operator|)
decl_stmt|;
return|return
name|Node
operator|.
name|value
argument_list|(
literal|0
argument_list|)
operator|==
name|Value
operator|&&
name|Traits
operator|::
name|adjacent
argument_list|(
name|Stop
argument_list|,
name|Node
operator|.
name|start
argument_list|(
literal|0
argument_list|)
argument_list|)
return|;
block|}
end_if

begin_return
return|return
name|false
return|;
end_return

begin_comment
unit|}
comment|/// setNodeStop - Update the stop key of the current node at level and above.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|void
name|IntervalMap
operator|<
name|KeyT
operator|,
name|ValT
operator|,
name|N
operator|,
name|Traits
operator|>
operator|::
name|iterator
operator|::
name|setNodeStop
argument_list|(
argument|unsigned Level
argument_list|,
argument|KeyT Stop
argument_list|)
block|{
comment|// There are no references to the root node, so nothing to update.
if|if
condition|(
operator|!
name|Level
condition|)
return|return;
name|IntervalMapImpl
operator|::
name|Path
operator|&
name|P
operator|=
name|this
operator|->
name|path
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Update nodes pointing to the current node.
end_comment

begin_while
while|while
condition|(
operator|--
name|Level
condition|)
block|{
name|P
operator|.
name|node
operator|<
name|Branch
operator|>
operator|(
name|Level
operator|)
operator|.
name|stop
argument_list|(
name|P
operator|.
name|offset
argument_list|(
name|Level
argument_list|)
argument_list|)
operator|=
name|Stop
expr_stmt|;
if|if
condition|(
operator|!
name|P
operator|.
name|atLastEntry
argument_list|(
name|Level
argument_list|)
condition|)
return|return;
block|}
end_while

begin_comment
comment|// Update root separately since it has a different layout.
end_comment

begin_expr_stmt
name|P
operator|.
name|node
operator|<
name|RootBranch
operator|>
operator|(
name|Level
operator|)
operator|.
name|stop
argument_list|(
name|P
operator|.
name|offset
argument_list|(
name|Level
argument_list|)
argument_list|)
operator|=
name|Stop
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|void
name|IntervalMap
operator|<
name|KeyT
operator|,
name|ValT
operator|,
name|N
operator|,
name|Traits
operator|>
operator|::
name|iterator
operator|::
name|setStart
argument_list|(
argument|KeyT a
argument_list|)
block|{
name|assert
argument_list|(
name|Traits
operator|::
name|nonEmpty
argument_list|(
name|a
argument_list|,
name|this
operator|->
name|stop
argument_list|()
argument_list|)
operator|&&
literal|"Cannot move start beyond stop"
argument_list|)
block|;
name|KeyT
operator|&
name|CurStart
operator|=
name|this
operator|->
name|unsafeStart
argument_list|()
block|;
if|if
condition|(
operator|!
name|Traits
operator|::
name|startLess
argument_list|(
name|a
argument_list|,
name|CurStart
argument_list|)
operator|||
operator|!
name|canCoalesceLeft
argument_list|(
name|a
argument_list|,
name|this
operator|->
name|value
argument_list|()
argument_list|)
condition|)
block|{
name|CurStart
operator|=
name|a
expr_stmt|;
return|return;
block|}
comment|// Coalesce with the interval to the left.
operator|--
operator|*
name|this
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|a
operator|=
name|this
operator|->
name|start
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|erase
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|setStartUnchecked
argument_list|(
name|a
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|void
name|IntervalMap
operator|<
name|KeyT
operator|,
name|ValT
operator|,
name|N
operator|,
name|Traits
operator|>
operator|::
name|iterator
operator|::
name|setStop
argument_list|(
argument|KeyT b
argument_list|)
block|{
name|assert
argument_list|(
name|Traits
operator|::
name|nonEmpty
argument_list|(
name|this
operator|->
name|start
argument_list|()
argument_list|,
name|b
argument_list|)
operator|&&
literal|"Cannot move stop beyond start"
argument_list|)
block|;
if|if
condition|(
name|Traits
operator|::
name|startLess
argument_list|(
name|b
argument_list|,
name|this
operator|->
name|stop
argument_list|()
argument_list|)
operator|||
operator|!
name|canCoalesceRight
argument_list|(
name|b
argument_list|,
name|this
operator|->
name|value
argument_list|()
argument_list|)
condition|)
block|{
name|setStopUnchecked
argument_list|(
name|b
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// Coalesce with interval to the right.
name|KeyT
name|a
operator|=
name|this
operator|->
name|start
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|erase
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|setStartUnchecked
argument_list|(
name|a
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|void
name|IntervalMap
operator|<
name|KeyT
operator|,
name|ValT
operator|,
name|N
operator|,
name|Traits
operator|>
operator|::
name|iterator
operator|::
name|setValue
argument_list|(
argument|ValT x
argument_list|)
block|{
name|setValueUnchecked
argument_list|(
name|x
argument_list|)
block|;
if|if
condition|(
name|canCoalesceRight
argument_list|(
name|this
operator|->
name|stop
argument_list|()
argument_list|,
name|x
argument_list|)
condition|)
block|{
name|KeyT
name|a
init|=
name|this
operator|->
name|start
argument_list|()
decl_stmt|;
name|erase
argument_list|()
expr_stmt|;
name|setStartUnchecked
argument_list|(
name|a
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_if
if|if
condition|(
name|canCoalesceLeft
argument_list|(
name|this
operator|->
name|start
argument_list|()
argument_list|,
name|x
argument_list|)
condition|)
block|{
operator|--
operator|*
name|this
expr_stmt|;
name|KeyT
name|a
init|=
name|this
operator|->
name|start
argument_list|()
decl_stmt|;
name|erase
argument_list|()
expr_stmt|;
name|setStartUnchecked
argument_list|(
name|a
argument_list|)
expr_stmt|;
block|}
end_if

begin_comment
unit|}
comment|/// insertNode - insert a node before the current path at level.
end_comment

begin_comment
comment|/// Leave the current path pointing at the new node.
end_comment

begin_comment
comment|/// @param Level path index of the node to be inserted.
end_comment

begin_comment
comment|/// @param Node The node to be inserted.
end_comment

begin_comment
comment|/// @param Stop The last index in the new node.
end_comment

begin_comment
comment|/// @return True if the tree height was increased.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|bool
name|IntervalMap
operator|<
name|KeyT
operator|,
name|ValT
operator|,
name|N
operator|,
name|Traits
operator|>
operator|::
name|iterator
operator|::
name|insertNode
argument_list|(
argument|unsigned Level
argument_list|,
argument|IntervalMapImpl::NodeRef Node
argument_list|,
argument|KeyT Stop
argument_list|)
block|{
name|assert
argument_list|(
name|Level
operator|&&
literal|"Cannot insert next to the root"
argument_list|)
block|;
name|bool
name|SplitRoot
operator|=
name|false
block|;
name|IntervalMap
operator|&
name|IM
operator|=
operator|*
name|this
operator|->
name|map
block|;
name|IntervalMapImpl
operator|::
name|Path
operator|&
name|P
operator|=
name|this
operator|->
name|path
block|;
if|if
condition|(
name|Level
operator|==
literal|1
condition|)
block|{
comment|// Insert into the root branch node.
if|if
condition|(
name|IM
operator|.
name|rootSize
operator|<
name|RootBranch
operator|::
name|Capacity
condition|)
block|{
name|IM
operator|.
name|rootBranch
argument_list|()
operator|.
name|insert
argument_list|(
name|P
operator|.
name|offset
argument_list|(
literal|0
argument_list|)
argument_list|,
name|IM
operator|.
name|rootSize
argument_list|,
name|Node
argument_list|,
name|Stop
argument_list|)
expr_stmt|;
name|P
operator|.
name|setSize
argument_list|(
literal|0
argument_list|,
operator|++
name|IM
operator|.
name|rootSize
argument_list|)
expr_stmt|;
name|P
operator|.
name|reset
argument_list|(
name|Level
argument_list|)
expr_stmt|;
return|return
name|SplitRoot
return|;
block|}
comment|// We need to split the root while keeping our position.
name|SplitRoot
operator|=
name|true
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|IdxPair
name|Offset
init|=
name|IM
operator|.
name|splitRoot
argument_list|(
name|P
operator|.
name|offset
argument_list|(
literal|0
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|P
operator|.
name|replaceRoot
argument_list|(
operator|&
name|IM
operator|.
name|rootBranch
argument_list|()
argument_list|,
name|IM
operator|.
name|rootSize
argument_list|,
name|Offset
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Fall through to insert at the new higher level.
end_comment

begin_expr_stmt
operator|++
name|Level
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// When inserting before end(), make sure we have a valid path.
end_comment

begin_expr_stmt
unit|P
operator|.
name|legalizeForInsert
argument_list|(
operator|--
name|Level
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Insert into the branch node at Level-1.
end_comment

begin_if
if|if
condition|(
name|P
operator|.
name|size
argument_list|(
name|Level
argument_list|)
operator|==
name|Branch
operator|::
name|Capacity
condition|)
block|{
comment|// Branch node is full, handle handle the overflow.
name|assert
argument_list|(
operator|!
name|SplitRoot
operator|&&
literal|"Cannot overflow after splitting the root"
argument_list|)
expr_stmt|;
name|SplitRoot
operator|=
name|overflow
operator|<
name|Branch
operator|>
operator|(
name|Level
operator|)
expr_stmt|;
name|Level
operator|+=
name|SplitRoot
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|P
operator|.
name|node
operator|<
name|Branch
operator|>
operator|(
name|Level
operator|)
operator|.
name|insert
argument_list|(
name|P
operator|.
name|offset
argument_list|(
name|Level
argument_list|)
argument_list|,
name|P
operator|.
name|size
argument_list|(
name|Level
argument_list|)
argument_list|,
name|Node
argument_list|,
name|Stop
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P
operator|.
name|setSize
argument_list|(
name|Level
argument_list|,
name|P
operator|.
name|size
argument_list|(
name|Level
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|P
operator|.
name|atLastEntry
argument_list|(
name|Level
argument_list|)
condition|)
name|setNodeStop
argument_list|(
name|Level
argument_list|,
name|Stop
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
name|P
operator|.
name|reset
argument_list|(
name|Level
operator|+
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|SplitRoot
return|;
end_return

begin_comment
unit|}
comment|// insert
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|void
name|IntervalMap
operator|<
name|KeyT
operator|,
name|ValT
operator|,
name|N
operator|,
name|Traits
operator|>
operator|::
name|iterator
operator|::
name|insert
argument_list|(
argument|KeyT a
argument_list|,
argument|KeyT b
argument_list|,
argument|ValT y
argument_list|)
block|{
if|if
condition|(
name|this
operator|->
name|branched
argument_list|()
condition|)
return|return
name|treeInsert
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|y
argument_list|)
return|;
name|IntervalMap
operator|&
name|IM
operator|=
operator|*
name|this
operator|->
name|map
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|IntervalMapImpl
operator|::
name|Path
operator|&
name|P
operator|=
name|this
operator|->
name|path
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Try simple root leaf insert.
end_comment

begin_decl_stmt
name|unsigned
name|Size
init|=
name|IM
operator|.
name|rootLeaf
argument_list|()
operator|.
name|insertFrom
argument_list|(
name|P
operator|.
name|leafOffset
argument_list|()
argument_list|,
name|IM
operator|.
name|rootSize
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|y
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Was the root node insert successful?
end_comment

begin_if
if|if
condition|(
name|Size
operator|<=
name|RootLeaf
operator|::
name|Capacity
condition|)
block|{
name|P
operator|.
name|setSize
argument_list|(
literal|0
argument_list|,
name|IM
operator|.
name|rootSize
operator|=
name|Size
argument_list|)
expr_stmt|;
return|return;
block|}
end_if

begin_comment
comment|// Root leaf node is full, we must branch.
end_comment

begin_decl_stmt
name|IdxPair
name|Offset
init|=
name|IM
operator|.
name|branchRoot
argument_list|(
name|P
operator|.
name|leafOffset
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|P
operator|.
name|replaceRoot
argument_list|(
operator|&
name|IM
operator|.
name|rootBranch
argument_list|()
argument_list|,
name|IM
operator|.
name|rootSize
argument_list|,
name|Offset
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Now it fits in the new leaf.
end_comment

begin_expr_stmt
name|treeInsert
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|y
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|void
name|IntervalMap
operator|<
name|KeyT
operator|,
name|ValT
operator|,
name|N
operator|,
name|Traits
operator|>
operator|::
name|iterator
operator|::
name|treeInsert
argument_list|(
argument|KeyT a
argument_list|,
argument|KeyT b
argument_list|,
argument|ValT y
argument_list|)
block|{
name|using
name|namespace
name|IntervalMapImpl
block|;
name|Path
operator|&
name|P
operator|=
name|this
operator|->
name|path
block|;
if|if
condition|(
operator|!
name|P
operator|.
name|valid
argument_list|()
condition|)
name|P
operator|.
name|legalizeForInsert
argument_list|(
name|this
operator|->
name|map
operator|->
name|height
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Check if this insertion will extend the node to the left.
end_comment

begin_if
if|if
condition|(
name|P
operator|.
name|leafOffset
argument_list|()
operator|==
literal|0
operator|&&
name|Traits
operator|::
name|startLess
argument_list|(
name|a
argument_list|,
name|P
operator|.
name|leaf
operator|<
name|Leaf
operator|>
operator|(
operator|)
operator|.
name|start
argument_list|(
literal|0
argument_list|)
argument_list|)
condition|)
block|{
comment|// Node is growing to the left, will it affect a left sibling node?
if|if
condition|(
name|NodeRef
name|Sib
init|=
name|P
operator|.
name|getLeftSibling
argument_list|(
name|P
operator|.
name|height
argument_list|()
argument_list|)
condition|)
block|{
name|Leaf
modifier|&
name|SibLeaf
init|=
name|Sib
operator|.
name|get
operator|<
name|Leaf
operator|>
operator|(
operator|)
decl_stmt|;
name|unsigned
name|SibOfs
init|=
name|Sib
operator|.
name|size
argument_list|()
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|SibLeaf
operator|.
name|value
argument_list|(
name|SibOfs
argument_list|)
operator|==
name|y
operator|&&
name|Traits
operator|::
name|adjacent
argument_list|(
name|SibLeaf
operator|.
name|stop
argument_list|(
name|SibOfs
argument_list|)
argument_list|,
name|a
argument_list|)
condition|)
block|{
comment|// This insertion will coalesce with the last entry in SibLeaf. We can
comment|// handle it in two ways:
comment|//  1. Extend SibLeaf.stop to b and be done, or
comment|//  2. Extend a to SibLeaf, erase the SibLeaf entry and continue.
comment|// We prefer 1., but need 2 when coalescing to the right as well.
name|Leaf
modifier|&
name|CurLeaf
init|=
name|P
operator|.
name|leaf
operator|<
name|Leaf
operator|>
operator|(
operator|)
decl_stmt|;
name|P
operator|.
name|moveLeft
argument_list|(
name|P
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|Traits
operator|::
name|stopLess
argument_list|(
name|b
argument_list|,
name|CurLeaf
operator|.
name|start
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|&&
operator|(
name|y
operator|!=
name|CurLeaf
operator|.
name|value
argument_list|(
literal|0
argument_list|)
operator|||
operator|!
name|Traits
operator|::
name|adjacent
argument_list|(
name|b
argument_list|,
name|CurLeaf
operator|.
name|start
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|)
condition|)
block|{
comment|// Easy, just extend SibLeaf and we're done.
name|setNodeStop
argument_list|(
name|P
operator|.
name|height
argument_list|()
argument_list|,
name|SibLeaf
operator|.
name|stop
argument_list|(
name|SibOfs
argument_list|)
operator|=
name|b
argument_list|)
expr_stmt|;
return|return;
block|}
else|else
block|{
comment|// We have both left and right coalescing. Erase the old SibLeaf entry
comment|// and continue inserting the larger interval.
name|a
operator|=
name|SibLeaf
operator|.
name|start
argument_list|(
name|SibOfs
argument_list|)
expr_stmt|;
name|treeErase
argument_list|(
comment|/* UpdateRoot= */
name|false
argument_list|)
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
comment|// No left sibling means we are at begin(). Update cached bound.
name|this
operator|->
name|map
operator|->
name|rootBranchStart
argument_list|()
operator|=
name|a
expr_stmt|;
block|}
block|}
end_if

begin_comment
comment|// When we are inserting at the end of a leaf node, we must update stops.
end_comment

begin_decl_stmt
name|unsigned
name|Size
init|=
name|P
operator|.
name|leafSize
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|Grow
init|=
name|P
operator|.
name|leafOffset
argument_list|()
operator|==
name|Size
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|Size
operator|=
name|P
operator|.
name|leaf
operator|<
name|Leaf
operator|>
operator|(
operator|)
operator|.
name|insertFrom
argument_list|(
name|P
operator|.
name|leafOffset
argument_list|()
argument_list|,
name|Size
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|y
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Leaf insertion unsuccessful? Overflow and try again.
end_comment

begin_if
if|if
condition|(
name|Size
operator|>
name|Leaf
operator|::
name|Capacity
condition|)
block|{
name|overflow
operator|<
name|Leaf
operator|>
operator|(
name|P
operator|.
name|height
argument_list|()
operator|)
expr_stmt|;
name|Grow
operator|=
name|P
operator|.
name|leafOffset
argument_list|()
operator|==
name|P
operator|.
name|leafSize
argument_list|()
expr_stmt|;
name|Size
operator|=
name|P
operator|.
name|leaf
operator|<
name|Leaf
operator|>
operator|(
operator|)
operator|.
name|insertFrom
argument_list|(
name|P
operator|.
name|leafOffset
argument_list|()
argument_list|,
name|P
operator|.
name|leafSize
argument_list|()
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|Size
operator|<=
name|Leaf
operator|::
name|Capacity
operator|&&
literal|"overflow() didn't make room"
argument_list|)
expr_stmt|;
block|}
end_if

begin_comment
comment|// Inserted, update offset and leaf size.
end_comment

begin_expr_stmt
name|P
operator|.
name|setSize
argument_list|(
name|P
operator|.
name|height
argument_list|()
argument_list|,
name|Size
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Insert was the last node entry, update stops.
end_comment

begin_if
if|if
condition|(
name|Grow
condition|)
name|setNodeStop
argument_list|(
name|P
operator|.
name|height
argument_list|()
argument_list|,
name|b
argument_list|)
expr_stmt|;
end_if

begin_comment
unit|}
comment|/// erase - erase the current interval and move to the next position.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|void
name|IntervalMap
operator|<
name|KeyT
operator|,
name|ValT
operator|,
name|N
operator|,
name|Traits
operator|>
operator|::
name|iterator
operator|::
name|erase
argument_list|()
block|{
name|IntervalMap
operator|&
name|IM
operator|=
operator|*
name|this
operator|->
name|map
block|;
name|IntervalMapImpl
operator|::
name|Path
operator|&
name|P
operator|=
name|this
operator|->
name|path
block|;
name|assert
argument_list|(
name|P
operator|.
name|valid
argument_list|()
operator|&&
literal|"Cannot erase end()"
argument_list|)
block|;
if|if
condition|(
name|this
operator|->
name|branched
argument_list|()
condition|)
return|return
name|treeErase
argument_list|()
return|;
name|IM
operator|.
name|rootLeaf
argument_list|()
operator|.
name|erase
argument_list|(
name|P
operator|.
name|leafOffset
argument_list|()
argument_list|,
name|IM
operator|.
name|rootSize
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P
operator|.
name|setSize
argument_list|(
literal|0
argument_list|,
operator|--
name|IM
operator|.
name|rootSize
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/// treeErase - erase() for a branched tree.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|void
name|IntervalMap
operator|<
name|KeyT
operator|,
name|ValT
operator|,
name|N
operator|,
name|Traits
operator|>
operator|::
name|iterator
operator|::
name|treeErase
argument_list|(
argument|bool UpdateRoot
argument_list|)
block|{
name|IntervalMap
operator|&
name|IM
operator|=
operator|*
name|this
operator|->
name|map
block|;
name|IntervalMapImpl
operator|::
name|Path
operator|&
name|P
operator|=
name|this
operator|->
name|path
block|;
name|Leaf
operator|&
name|Node
operator|=
name|P
operator|.
name|leaf
operator|<
name|Leaf
operator|>
operator|(
operator|)
block|;
comment|// Nodes are not allowed to become empty.
if|if
condition|(
name|P
operator|.
name|leafSize
argument_list|()
operator|==
literal|1
condition|)
block|{
name|IM
operator|.
name|deleteNode
argument_list|(
operator|&
name|Node
argument_list|)
expr_stmt|;
name|eraseNode
argument_list|(
name|IM
operator|.
name|height
argument_list|)
expr_stmt|;
comment|// Update rootBranchStart if we erased begin().
if|if
condition|(
name|UpdateRoot
operator|&&
name|IM
operator|.
name|branched
argument_list|()
operator|&&
name|P
operator|.
name|valid
argument_list|()
operator|&&
name|P
operator|.
name|atBegin
argument_list|()
condition|)
name|IM
operator|.
name|rootBranchStart
argument_list|()
operator|=
name|P
operator|.
name|leaf
operator|<
name|Leaf
operator|>
operator|(
operator|)
operator|.
name|start
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// Erase current entry.
name|Node
operator|.
name|erase
argument_list|(
name|P
operator|.
name|leafOffset
argument_list|()
argument_list|,
name|P
operator|.
name|leafSize
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|unsigned
name|NewSize
init|=
name|P
operator|.
name|leafSize
argument_list|()
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|P
operator|.
name|setSize
argument_list|(
name|IM
operator|.
name|height
argument_list|,
name|NewSize
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// When we erase the last entry, update stop and move to a legal position.
end_comment

begin_if
if|if
condition|(
name|P
operator|.
name|leafOffset
argument_list|()
operator|==
name|NewSize
condition|)
block|{
name|setNodeStop
argument_list|(
name|IM
operator|.
name|height
argument_list|,
name|Node
operator|.
name|stop
argument_list|(
name|NewSize
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|P
operator|.
name|moveRight
argument_list|(
name|IM
operator|.
name|height
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|UpdateRoot
operator|&&
name|P
operator|.
name|atBegin
argument_list|()
condition|)
name|IM
operator|.
name|rootBranchStart
argument_list|()
operator|=
name|P
operator|.
name|leaf
operator|<
name|Leaf
operator|>
operator|(
operator|)
operator|.
name|start
argument_list|(
literal|0
argument_list|)
expr_stmt|;
end_if

begin_comment
unit|}
comment|/// eraseNode - Erase the current node at Level from its parent and move path to
end_comment

begin_comment
comment|/// the first entry of the next sibling node.
end_comment

begin_comment
comment|/// The node must be deallocated by the caller.
end_comment

begin_comment
comment|/// @param Level 1..height, the root node cannot be erased.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|void
name|IntervalMap
operator|<
name|KeyT
operator|,
name|ValT
operator|,
name|N
operator|,
name|Traits
operator|>
operator|::
name|iterator
operator|::
name|eraseNode
argument_list|(
argument|unsigned Level
argument_list|)
block|{
name|assert
argument_list|(
name|Level
operator|&&
literal|"Cannot erase root node"
argument_list|)
block|;
name|IntervalMap
operator|&
name|IM
operator|=
operator|*
name|this
operator|->
name|map
block|;
name|IntervalMapImpl
operator|::
name|Path
operator|&
name|P
operator|=
name|this
operator|->
name|path
block|;
if|if
condition|(
operator|--
name|Level
operator|==
literal|0
condition|)
block|{
name|IM
operator|.
name|rootBranch
argument_list|()
operator|.
name|erase
argument_list|(
name|P
operator|.
name|offset
argument_list|(
literal|0
argument_list|)
argument_list|,
name|IM
operator|.
name|rootSize
argument_list|)
expr_stmt|;
name|P
operator|.
name|setSize
argument_list|(
literal|0
argument_list|,
operator|--
name|IM
operator|.
name|rootSize
argument_list|)
expr_stmt|;
comment|// If this cleared the root, switch to height=0.
if|if
condition|(
name|IM
operator|.
name|empty
argument_list|()
condition|)
block|{
name|IM
operator|.
name|switchRootToLeaf
argument_list|()
expr_stmt|;
name|this
operator|->
name|setRoot
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
end_expr_stmt

begin_block
unit|} else
block|{
comment|// Remove node ref from branch node at Level.
name|Branch
modifier|&
name|Parent
init|=
name|P
operator|.
name|node
operator|<
name|Branch
operator|>
operator|(
name|Level
operator|)
decl_stmt|;
if|if
condition|(
name|P
operator|.
name|size
argument_list|(
name|Level
argument_list|)
operator|==
literal|1
condition|)
block|{
comment|// Branch node became empty, remove it recursively.
name|IM
operator|.
name|deleteNode
argument_list|(
operator|&
name|Parent
argument_list|)
expr_stmt|;
name|eraseNode
argument_list|(
name|Level
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// Branch node won't become empty.
name|Parent
operator|.
name|erase
argument_list|(
name|P
operator|.
name|offset
argument_list|(
name|Level
argument_list|)
argument_list|,
name|P
operator|.
name|size
argument_list|(
name|Level
argument_list|)
argument_list|)
expr_stmt|;
name|unsigned
name|NewSize
init|=
name|P
operator|.
name|size
argument_list|(
name|Level
argument_list|)
operator|-
literal|1
decl_stmt|;
name|P
operator|.
name|setSize
argument_list|(
name|Level
argument_list|,
name|NewSize
argument_list|)
expr_stmt|;
comment|// If we removed the last branch, update stop and move to a legal pos.
if|if
condition|(
name|P
operator|.
name|offset
argument_list|(
name|Level
argument_list|)
operator|==
name|NewSize
condition|)
block|{
name|setNodeStop
argument_list|(
name|Level
argument_list|,
name|Parent
operator|.
name|stop
argument_list|(
name|NewSize
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|P
operator|.
name|moveRight
argument_list|(
name|Level
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_block

begin_comment
comment|// Update path cache for the new right sibling position.
end_comment

begin_if
if|if
condition|(
name|P
operator|.
name|valid
argument_list|()
condition|)
block|{
name|P
operator|.
name|reset
argument_list|(
name|Level
operator|+
literal|1
argument_list|)
expr_stmt|;
name|P
operator|.
name|offset
argument_list|(
name|Level
operator|+
literal|1
argument_list|)
operator|=
literal|0
expr_stmt|;
block|}
end_if

begin_comment
unit|}
comment|/// overflow - Distribute entries of the current node evenly among
end_comment

begin_comment
comment|/// its siblings and ensure that the current node is not full.
end_comment

begin_comment
comment|/// This may require allocating a new node.
end_comment

begin_comment
comment|/// @tparam NodeT The type of node at Level (Leaf or Branch).
end_comment

begin_comment
comment|/// @param Level path index of the overflowing node.
end_comment

begin_comment
comment|/// @return True when the tree height was changed.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|KeyT
operator|,
name|typename
name|ValT
operator|,
name|unsigned
name|N
operator|,
name|typename
name|Traits
operator|>
name|template
operator|<
name|typename
name|NodeT
operator|>
name|bool
name|IntervalMap
operator|<
name|KeyT
operator|,
name|ValT
operator|,
name|N
operator|,
name|Traits
operator|>
operator|::
name|iterator
operator|::
name|overflow
argument_list|(
argument|unsigned Level
argument_list|)
block|{
name|using
name|namespace
name|IntervalMapImpl
block|;
name|Path
operator|&
name|P
operator|=
name|this
operator|->
name|path
block|;
name|unsigned
name|CurSize
index|[
literal|4
index|]
block|;
name|NodeT
operator|*
name|Node
index|[
literal|4
index|]
block|;
name|unsigned
name|Nodes
operator|=
literal|0
block|;
name|unsigned
name|Elements
operator|=
literal|0
block|;
name|unsigned
name|Offset
operator|=
name|P
operator|.
name|offset
argument_list|(
name|Level
argument_list|)
block|;
comment|// Do we have a left sibling?
name|NodeRef
name|LeftSib
operator|=
name|P
operator|.
name|getLeftSibling
argument_list|(
name|Level
argument_list|)
block|;
if|if
condition|(
name|LeftSib
condition|)
block|{
name|Offset
operator|+=
name|Elements
operator|=
name|CurSize
index|[
name|Nodes
index|]
operator|=
name|LeftSib
operator|.
name|size
argument_list|()
expr_stmt|;
name|Node
index|[
name|Nodes
operator|++
index|]
operator|=
operator|&
name|LeftSib
operator|.
name|get
operator|<
name|NodeT
operator|>
operator|(
operator|)
expr_stmt|;
block|}
comment|// Current node.
name|Elements
operator|+=
name|CurSize
index|[
name|Nodes
index|]
operator|=
name|P
operator|.
name|size
argument_list|(
name|Level
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Node
index|[
name|Nodes
operator|++
index|]
operator|=
operator|&
name|P
operator|.
name|node
operator|<
name|NodeT
operator|>
operator|(
name|Level
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Do we have a right sibling?
end_comment

begin_decl_stmt
name|NodeRef
name|RightSib
init|=
name|P
operator|.
name|getRightSibling
argument_list|(
name|Level
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
name|RightSib
condition|)
block|{
name|Elements
operator|+=
name|CurSize
index|[
name|Nodes
index|]
operator|=
name|RightSib
operator|.
name|size
argument_list|()
expr_stmt|;
name|Node
index|[
name|Nodes
operator|++
index|]
operator|=
operator|&
name|RightSib
operator|.
name|get
operator|<
name|NodeT
operator|>
operator|(
operator|)
expr_stmt|;
block|}
end_if

begin_comment
comment|// Do we need to allocate a new node?
end_comment

begin_decl_stmt
name|unsigned
name|NewNode
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
name|Elements
operator|+
literal|1
operator|>
name|Nodes
operator|*
name|NodeT
operator|::
name|Capacity
condition|)
block|{
comment|// Insert NewNode at the penultimate position, or after a single node.
name|NewNode
operator|=
name|Nodes
operator|==
literal|1
condition|?
literal|1
else|:
name|Nodes
operator|-
literal|1
expr_stmt|;
name|CurSize
index|[
name|Nodes
index|]
operator|=
name|CurSize
index|[
name|NewNode
index|]
expr_stmt|;
name|Node
index|[
name|Nodes
index|]
operator|=
name|Node
index|[
name|NewNode
index|]
expr_stmt|;
name|CurSize
index|[
name|NewNode
index|]
operator|=
literal|0
expr_stmt|;
name|Node
index|[
name|NewNode
index|]
operator|=
name|this
operator|->
name|map
operator|->
name|template
name|newNode
operator|<
name|NodeT
operator|>
operator|(
operator|)
expr_stmt|;
operator|++
name|Nodes
expr_stmt|;
block|}
end_if

begin_comment
comment|// Compute the new element distribution.
end_comment

begin_decl_stmt
name|unsigned
name|NewSize
index|[
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|IdxPair
name|NewOffset
init|=
name|distribute
argument_list|(
name|Nodes
argument_list|,
name|Elements
argument_list|,
name|NodeT
operator|::
name|Capacity
argument_list|,
name|CurSize
argument_list|,
name|NewSize
argument_list|,
name|Offset
argument_list|,
name|true
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|adjustSiblingSizes
argument_list|(
name|Node
argument_list|,
name|Nodes
argument_list|,
name|CurSize
argument_list|,
name|NewSize
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Move current location to the leftmost node.
end_comment

begin_if
if|if
condition|(
name|LeftSib
condition|)
name|P
operator|.
name|moveLeft
argument_list|(
name|Level
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|// Elements have been rearranged, now update node sizes and stops.
end_comment

begin_decl_stmt
name|bool
name|SplitRoot
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|Pos
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_while
while|while
condition|(
name|true
condition|)
block|{
name|KeyT
name|Stop
init|=
name|Node
index|[
name|Pos
index|]
operator|->
name|stop
argument_list|(
name|NewSize
index|[
name|Pos
index|]
operator|-
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|NewNode
operator|&&
name|Pos
operator|==
name|NewNode
condition|)
block|{
name|SplitRoot
operator|=
name|insertNode
argument_list|(
name|Level
argument_list|,
name|NodeRef
argument_list|(
name|Node
index|[
name|Pos
index|]
argument_list|,
name|NewSize
index|[
name|Pos
index|]
argument_list|)
argument_list|,
name|Stop
argument_list|)
expr_stmt|;
name|Level
operator|+=
name|SplitRoot
expr_stmt|;
block|}
else|else
block|{
name|P
operator|.
name|setSize
argument_list|(
name|Level
argument_list|,
name|NewSize
index|[
name|Pos
index|]
argument_list|)
expr_stmt|;
name|setNodeStop
argument_list|(
name|Level
argument_list|,
name|Stop
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|Pos
operator|+
literal|1
operator|==
name|Nodes
condition|)
break|break;
name|P
operator|.
name|moveRight
argument_list|(
name|Level
argument_list|)
expr_stmt|;
operator|++
name|Pos
expr_stmt|;
block|}
end_while

begin_comment
comment|// Where was I? Find NewOffset.
end_comment

begin_while
while|while
condition|(
name|Pos
operator|!=
name|NewOffset
operator|.
name|first
condition|)
block|{
name|P
operator|.
name|moveLeft
argument_list|(
name|Level
argument_list|)
expr_stmt|;
operator|--
name|Pos
expr_stmt|;
block|}
end_while

begin_expr_stmt
name|P
operator|.
name|offset
argument_list|(
name|Level
argument_list|)
operator|=
name|NewOffset
operator|.
name|second
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|SplitRoot
return|;
end_return

begin_comment
unit|}
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//---                       IntervalMapOverlaps                           ----//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// IntervalMapOverlaps - Iterate over the overlaps of mapped intervals in two
end_comment

begin_comment
comment|/// IntervalMaps. The maps may be different, but the KeyT and Traits types
end_comment

begin_comment
comment|/// should be the same.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Typical uses:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// 1. Test for overlap:
end_comment

begin_comment
comment|///    bool overlap = IntervalMapOverlaps(a, b).valid();
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// 2. Enumerate overlaps:
end_comment

begin_comment
comment|///    for (IntervalMapOverlaps I(a, b); I.valid() ; ++I) { ... }
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|MapA
operator|,
name|typename
name|MapB
operator|>
name|class
name|IntervalMapOverlaps
block|{
name|using
name|KeyType
operator|=
name|typename
name|MapA
operator|::
name|KeyType
block|;
name|using
name|Traits
operator|=
name|typename
name|MapA
operator|::
name|KeyTraits
block|;
name|typename
name|MapA
operator|::
name|const_iterator
name|posA
block|;
name|typename
name|MapB
operator|::
name|const_iterator
name|posB
block|;
comment|/// advance - Move posA and posB forward until reaching an overlap, or until
comment|/// either meets end.
comment|/// Don't move the iterators if they are already overlapping.
name|void
name|advance
argument_list|()
block|{
if|if
condition|(
operator|!
name|valid
argument_list|()
condition|)
return|return;
if|if
condition|(
name|Traits
operator|::
name|stopLess
argument_list|(
name|posA
operator|.
name|stop
argument_list|()
argument_list|,
name|posB
operator|.
name|start
argument_list|()
argument_list|)
condition|)
block|{
comment|// A ends before B begins. Catch up.
name|posA
operator|.
name|advanceTo
argument_list|(
name|posB
operator|.
name|start
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|posA
operator|.
name|valid
argument_list|()
operator|||
operator|!
name|Traits
operator|::
name|stopLess
argument_list|(
name|posB
operator|.
name|stop
argument_list|()
argument_list|,
name|posA
operator|.
name|start
argument_list|()
argument_list|)
condition|)
return|return;
block|}
end_expr_stmt

begin_elseif
elseif|else
if|if
condition|(
name|Traits
operator|::
name|stopLess
argument_list|(
name|posB
operator|.
name|stop
argument_list|()
argument_list|,
name|posA
operator|.
name|start
argument_list|()
argument_list|)
condition|)
block|{
comment|// B ends before A begins. Catch up.
name|posB
operator|.
name|advanceTo
argument_list|(
name|posA
operator|.
name|start
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|posB
operator|.
name|valid
argument_list|()
operator|||
operator|!
name|Traits
operator|::
name|stopLess
argument_list|(
name|posA
operator|.
name|stop
argument_list|()
argument_list|,
name|posB
operator|.
name|start
argument_list|()
argument_list|)
condition|)
return|return;
block|}
end_elseif

begin_else
else|else
comment|// Already overlapping.
return|return;
end_else

begin_while
while|while
condition|(
name|true
condition|)
block|{
comment|// Make a.end> b.start.
name|posA
operator|.
name|advanceTo
argument_list|(
name|posB
operator|.
name|start
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|posA
operator|.
name|valid
argument_list|()
operator|||
operator|!
name|Traits
operator|::
name|stopLess
argument_list|(
name|posB
operator|.
name|stop
argument_list|()
argument_list|,
name|posA
operator|.
name|start
argument_list|()
argument_list|)
condition|)
return|return;
comment|// Make b.end> a.start.
name|posB
operator|.
name|advanceTo
argument_list|(
name|posA
operator|.
name|start
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|posB
operator|.
name|valid
argument_list|()
operator|||
operator|!
name|Traits
operator|::
name|stopLess
argument_list|(
name|posA
operator|.
name|stop
argument_list|()
argument_list|,
name|posB
operator|.
name|start
argument_list|()
argument_list|)
condition|)
return|return;
block|}
end_while

begin_comment
unit|}  public:
comment|/// IntervalMapOverlaps - Create an iterator for the overlaps of a and b.
end_comment

begin_expr_stmt
name|IntervalMapOverlaps
argument_list|(
specifier|const
name|MapA
operator|&
name|a
argument_list|,
specifier|const
name|MapB
operator|&
name|b
argument_list|)
operator|:
name|posA
argument_list|(
name|b
operator|.
name|empty
argument_list|()
condition|?
name|a
operator|.
name|end
argument_list|()
else|:
name|a
operator|.
name|find
argument_list|(
name|b
operator|.
name|start
argument_list|()
argument_list|)
argument_list|)
operator|,
name|posB
argument_list|(
argument|posA.valid() ? b.find(posA.start()) : b.end()
argument_list|)
block|{
name|advance
argument_list|()
block|; }
comment|/// valid - Return true if iterator is at an overlap.
name|bool
name|valid
argument_list|()
specifier|const
block|{
return|return
name|posA
operator|.
name|valid
argument_list|()
operator|&&
name|posB
operator|.
name|valid
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// a - access the left hand side in the overlap.
end_comment

begin_expr_stmt
specifier|const
name|typename
name|MapA
operator|::
name|const_iterator
operator|&
name|a
argument_list|()
specifier|const
block|{
return|return
name|posA
return|;
block|}
end_expr_stmt

begin_comment
comment|/// b - access the right hand side in the overlap.
end_comment

begin_expr_stmt
specifier|const
name|typename
name|MapB
operator|::
name|const_iterator
operator|&
name|b
argument_list|()
specifier|const
block|{
return|return
name|posB
return|;
block|}
end_expr_stmt

begin_comment
comment|/// start - Beginning of the overlapping interval.
end_comment

begin_expr_stmt
name|KeyType
name|start
argument_list|()
specifier|const
block|{
name|KeyType
name|ak
operator|=
name|a
argument_list|()
operator|.
name|start
argument_list|()
block|;
name|KeyType
name|bk
operator|=
name|b
argument_list|()
operator|.
name|start
argument_list|()
block|;
return|return
name|Traits
operator|::
name|startLess
argument_list|(
name|ak
argument_list|,
name|bk
argument_list|)
condition|?
name|bk
else|:
name|ak
return|;
block|}
end_expr_stmt

begin_comment
comment|/// stop - End of the overlapping interval.
end_comment

begin_expr_stmt
name|KeyType
name|stop
argument_list|()
specifier|const
block|{
name|KeyType
name|ak
operator|=
name|a
argument_list|()
operator|.
name|stop
argument_list|()
block|;
name|KeyType
name|bk
operator|=
name|b
argument_list|()
operator|.
name|stop
argument_list|()
block|;
return|return
name|Traits
operator|::
name|startLess
argument_list|(
name|ak
argument_list|,
name|bk
argument_list|)
condition|?
name|ak
else|:
name|bk
return|;
block|}
end_expr_stmt

begin_comment
comment|/// skipA - Move to the next overlap that doesn't involve a().
end_comment

begin_function
name|void
name|skipA
parameter_list|()
block|{
operator|++
name|posA
expr_stmt|;
name|advance
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/// skipB - Move to the next overlap that doesn't involve b().
end_comment

begin_function
name|void
name|skipB
parameter_list|()
block|{
operator|++
name|posB
expr_stmt|;
name|advance
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Preincrement - Move to the next overlap.
end_comment

begin_expr_stmt
name|IntervalMapOverlaps
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// Bump the iterator that ends first. The other one may have more overlaps.
if|if
condition|(
name|Traits
operator|::
name|startLess
argument_list|(
name|posB
operator|.
name|stop
argument_list|()
argument_list|,
name|posA
operator|.
name|stop
argument_list|()
argument_list|)
condition|)
name|skipB
argument_list|()
expr_stmt|;
else|else
name|skipA
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_comment
unit|}
comment|/// advanceTo - Move to the first overlapping interval with
end_comment

begin_comment
comment|/// stopLess(x, stop()).
end_comment

begin_macro
unit|void
name|advanceTo
argument_list|(
argument|KeyType x
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
operator|!
name|valid
argument_list|()
condition|)
return|return;
comment|// Make sure advanceTo sees monotonic keys.
if|if
condition|(
name|Traits
operator|::
name|stopLess
argument_list|(
name|posA
operator|.
name|stop
argument_list|()
argument_list|,
name|x
argument_list|)
condition|)
name|posA
operator|.
name|advanceTo
argument_list|(
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|Traits
operator|::
name|stopLess
argument_list|(
name|posB
operator|.
name|stop
argument_list|()
argument_list|,
name|x
argument_list|)
condition|)
name|posB
operator|.
name|advanceTo
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|advance
argument_list|()
expr_stmt|;
block|}
end_block

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ADT_INTERVALMAP_H
end_comment

end_unit

