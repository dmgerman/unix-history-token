begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/ADT/FoldingSet.h - Uniquing Hash Set ---------------*- C++ -*-===//
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
comment|// This file defines a hash set that can be used to remove duplication of nodes
end_comment

begin_comment
comment|// in a graph.  This code was originally created by Chris Lattner for use with
end_comment

begin_comment
comment|// SelectionDAGCSEMap, but was isolated to provide use across the llvm code set.
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
name|LLVM_ADT_FOLDINGSET_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_FOLDINGSET_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|APFloat
decl_stmt|;
name|class
name|APInt
decl_stmt|;
comment|/// This folding set used for two purposes:
comment|///   1. Given information about a node we want to create, look up the unique
comment|///      instance of the node in the set.  If the node already exists, return
comment|///      it, otherwise return the bucket it should be inserted into.
comment|///   2. Given a node that has already been created, remove it from the set.
comment|///
comment|/// This class is implemented as a single-link chained hash table, where the
comment|/// "buckets" are actually the nodes themselves (the next pointer is in the
comment|/// node).  The last node points back to the bucket to simplify node removal.
comment|///
comment|/// Any node that is to be included in the folding set must be a subclass of
comment|/// FoldingSetNode.  The node class must also define a Profile method used to
comment|/// establish the unique bits of data for the node.  The Profile method is
comment|/// passed a FoldingSetNodeID object which is used to gather the bits.  Just
comment|/// call one of the Add* functions defined in the FoldingSetImpl::NodeID class.
comment|/// NOTE: That the folding set does not own the nodes and it is the
comment|/// responsibility of the user to dispose of the nodes.
comment|///
comment|/// Eg.
comment|///    class MyNode : public FoldingSetNode {
comment|///    private:
comment|///      std::string Name;
comment|///      unsigned Value;
comment|///    public:
comment|///      MyNode(const char *N, unsigned V) : Name(N), Value(V) {}
comment|///       ...
comment|///      void Profile(FoldingSetNodeID&ID) const {
comment|///        ID.AddString(Name);
comment|///        ID.AddInteger(Value);
comment|///       }
comment|///       ...
comment|///     };
comment|///
comment|/// To define the folding set itself use the FoldingSet template;
comment|///
comment|/// Eg.
comment|///    FoldingSet<MyNode> MyFoldingSet;
comment|///
comment|/// Four public methods are available to manipulate the folding set;
comment|///
comment|/// 1) If you have an existing node that you want add to the set but unsure
comment|/// that the node might already exist then call;
comment|///
comment|///    MyNode *M = MyFoldingSet.GetOrInsertNode(N);
comment|///
comment|/// If The result is equal to the input then the node has been inserted.
comment|/// Otherwise, the result is the node existing in the folding set, and the
comment|/// input can be discarded (use the result instead.)
comment|///
comment|/// 2) If you are ready to construct a node but want to check if it already
comment|/// exists, then call FindNodeOrInsertPos with a FoldingSetNodeID of the bits to
comment|/// check;
comment|///
comment|///   FoldingSetNodeID ID;
comment|///   ID.AddString(Name);
comment|///   ID.AddInteger(Value);
comment|///   void *InsertPoint;
comment|///
comment|///    MyNode *M = MyFoldingSet.FindNodeOrInsertPos(ID, InsertPoint);
comment|///
comment|/// If found then M with be non-NULL, else InsertPoint will point to where it
comment|/// should be inserted using InsertNode.
comment|///
comment|/// 3) If you get a NULL result from FindNodeOrInsertPos then you can as a new
comment|/// node with FindNodeOrInsertPos;
comment|///
comment|///    InsertNode(N, InsertPoint);
comment|///
comment|/// 4) Finally, if you want to remove a node from the folding set call;
comment|///
comment|///    bool WasRemoved = RemoveNode(N);
comment|///
comment|/// The result indicates whether the node existed in the folding set.
name|class
name|FoldingSetNodeID
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// FoldingSetImpl - Implements the folding set functionality.  The main
comment|/// structure is an array of buckets.  Each bucket is indexed by the hash of
comment|/// the nodes it contains.  The bucket itself points to the nodes contained
comment|/// in the bucket via a singly linked list.  The last node in the list points
comment|/// back to the bucket to facilitate node removal.
comment|///
name|class
name|FoldingSetImpl
block|{
name|protected
label|:
comment|/// Buckets - Array of bucket chains.
comment|///
name|void
modifier|*
modifier|*
name|Buckets
decl_stmt|;
comment|/// NumBuckets - Length of the Buckets array.  Always a power of 2.
comment|///
name|unsigned
name|NumBuckets
decl_stmt|;
comment|/// NumNodes - Number of nodes in the folding set. Growth occurs when NumNodes
comment|/// is greater than twice the number of buckets.
name|unsigned
name|NumNodes
decl_stmt|;
name|public
label|:
name|explicit
name|FoldingSetImpl
parameter_list|(
name|unsigned
name|Log2InitSize
init|=
literal|6
parameter_list|)
function_decl|;
name|virtual
operator|~
name|FoldingSetImpl
argument_list|()
expr_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|/// Node - This class is used to maintain the singly linked bucket list in
comment|/// a folding set.
comment|///
name|class
name|Node
block|{
name|private
label|:
comment|// NextInFoldingSetBucket - next link in the bucket list.
name|void
modifier|*
name|NextInFoldingSetBucket
decl_stmt|;
name|public
label|:
name|Node
argument_list|()
operator|:
name|NextInFoldingSetBucket
argument_list|(
literal|0
argument_list|)
block|{}
comment|// Accessors
name|void
operator|*
name|getNextInBucket
argument_list|()
specifier|const
block|{
return|return
name|NextInFoldingSetBucket
return|;
block|}
name|void
name|SetNextInBucket
parameter_list|(
name|void
modifier|*
name|N
parameter_list|)
block|{
name|NextInFoldingSetBucket
operator|=
name|N
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|/// clear - Remove all nodes from the folding set.
name|void
name|clear
parameter_list|()
function_decl|;
comment|/// RemoveNode - Remove a node from the folding set, returning true if one
comment|/// was removed or false if the node was not in the folding set.
name|bool
name|RemoveNode
parameter_list|(
name|Node
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// GetOrInsertNode - If there is an existing simple Node exactly
comment|/// equal to the specified node, return it.  Otherwise, insert 'N' and return
comment|/// it instead.
name|Node
modifier|*
name|GetOrInsertNode
parameter_list|(
name|Node
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// FindNodeOrInsertPos - Look up the node specified by ID.  If it exists,
comment|/// return it.  If not, return the insertion token that will make insertion
comment|/// faster.
name|Node
modifier|*
name|FindNodeOrInsertPos
parameter_list|(
specifier|const
name|FoldingSetNodeID
modifier|&
name|ID
parameter_list|,
name|void
modifier|*
modifier|&
name|InsertPos
parameter_list|)
function_decl|;
comment|/// InsertNode - Insert the specified node into the folding set, knowing that
comment|/// it is not already in the folding set.  InsertPos must be obtained from
comment|/// FindNodeOrInsertPos.
name|void
name|InsertNode
parameter_list|(
name|Node
modifier|*
name|N
parameter_list|,
name|void
modifier|*
name|InsertPos
parameter_list|)
function_decl|;
comment|/// size - Returns the number of nodes in the folding set.
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|NumNodes
return|;
block|}
comment|/// empty - Returns true if there are no nodes in the folding set.
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|NumNodes
operator|==
literal|0
return|;
block|}
name|private
label|:
comment|/// GrowHashTable - Double the size of the hash table and rehash everything.
comment|///
name|void
name|GrowHashTable
parameter_list|()
function_decl|;
name|protected
label|:
comment|/// GetNodeProfile - Instantiations of the FoldingSet template implement
comment|/// this function to gather data bits for the given node.
name|virtual
name|void
name|GetNodeProfile
argument_list|(
name|FoldingSetNodeID
operator|&
name|ID
argument_list|,
name|Node
operator|*
name|N
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// FoldingSetTrait - This trait class is used to define behavior of how
comment|///  to "profile" (in the FoldingSet parlance) an object of a given type.
comment|///  The default behavior is to invoke a 'Profile' method on an object, but
comment|///  through template specialization the behavior can be tailored for specific
comment|///  types.  Combined with the FoldingSetNodeWrapper classs, one can add objects
comment|///  to FoldingSets that were not originally designed to have that behavior.
comment|///
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|FoldingSetTrait
block|{
specifier|static
specifier|inline
name|void
name|Profile
argument_list|(
argument|const T& X
argument_list|,
argument|FoldingSetNodeID& ID
argument_list|)
block|{
name|X
operator|.
name|Profile
argument_list|(
name|ID
argument_list|)
block|;}
specifier|static
specifier|inline
name|void
name|Profile
argument_list|(
argument|T& X
argument_list|,
argument|FoldingSetNodeID& ID
argument_list|)
block|{
name|X
operator|.
name|Profile
argument_list|(
name|ID
argument_list|)
block|; }
block|}
expr_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|/// FoldingSetNodeID - This class is used to gather all the unique data bits of
comment|/// a node.  When all the bits are gathered this class is used to produce a
comment|/// hash value for the node.
comment|///
name|class
name|FoldingSetNodeID
block|{
comment|/// Bits - Vector of all the data bits that make the node unique.
comment|/// Use a SmallVector to avoid a heap allocation in the common case.
name|SmallVector
operator|<
name|unsigned
operator|,
literal|32
operator|>
name|Bits
expr_stmt|;
name|public
label|:
name|FoldingSetNodeID
argument_list|()
block|{}
comment|/// getRawData - Return the ith entry in the Bits data.
comment|///
name|unsigned
name|getRawData
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
block|{
return|return
name|Bits
index|[
name|i
index|]
return|;
block|}
comment|/// Add* - Add various data types to Bit data.
comment|///
name|void
name|AddPointer
parameter_list|(
specifier|const
name|void
modifier|*
name|Ptr
parameter_list|)
function_decl|;
name|void
name|AddInteger
parameter_list|(
name|signed
name|I
parameter_list|)
function_decl|;
name|void
name|AddInteger
parameter_list|(
name|unsigned
name|I
parameter_list|)
function_decl|;
name|void
name|AddInteger
parameter_list|(
name|long
name|I
parameter_list|)
function_decl|;
name|void
name|AddInteger
parameter_list|(
name|unsigned
name|long
name|I
parameter_list|)
function_decl|;
name|void
name|AddInteger
parameter_list|(
name|long
name|long
name|I
parameter_list|)
function_decl|;
name|void
name|AddInteger
parameter_list|(
name|unsigned
name|long
name|long
name|I
parameter_list|)
function_decl|;
name|void
name|AddBoolean
parameter_list|(
name|bool
name|B
parameter_list|)
block|{
name|AddInteger
argument_list|(
name|B
condition|?
literal|1U
else|:
literal|0U
argument_list|)
expr_stmt|;
block|}
name|void
name|AddString
parameter_list|(
name|StringRef
name|String
parameter_list|)
function_decl|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|void
name|Add
argument_list|(
argument|const T& x
argument_list|)
block|{
name|FoldingSetTrait
operator|<
name|T
operator|>
operator|::
name|Profile
argument_list|(
name|x
argument_list|,
operator|*
name|this
argument_list|)
block|; }
comment|/// clear - Clear the accumulated profile, allowing this FoldingSetNodeID
comment|///  object to be used to compute a new profile.
specifier|inline
name|void
name|clear
argument_list|()
block|{
name|Bits
operator|.
name|clear
argument_list|()
block|; }
comment|/// ComputeHash - Compute a strong hash value for this FoldingSetNodeID, used
comment|///  to lookup the node in the FoldingSetImpl.
name|unsigned
name|ComputeHash
argument_list|()
specifier|const
expr_stmt|;
comment|/// operator== - Used to compare two nodes to each other.
comment|///
name|bool
name|operator
operator|==
operator|(
specifier|const
name|FoldingSetNodeID
operator|&
name|RHS
operator|)
specifier|const
expr_stmt|;
block|}
empty_stmt|;
comment|// Convenience type to hide the implementation of the folding set.
typedef|typedef
name|FoldingSetImpl
operator|::
name|Node
name|FoldingSetNode
expr_stmt|;
name|template
operator|<
name|class
name|T
operator|>
name|class
name|FoldingSetIterator
expr_stmt|;
name|template
operator|<
name|class
name|T
operator|>
name|class
name|FoldingSetBucketIterator
expr_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// FoldingSet - This template class is used to instantiate a specialized
comment|/// implementation of the folding set to the node class T.  T must be a
comment|/// subclass of FoldingSetNode and implement a Profile function.
comment|///
name|template
operator|<
name|class
name|T
operator|>
name|class
name|FoldingSet
operator|:
name|public
name|FoldingSetImpl
block|{
name|private
operator|:
comment|/// GetNodeProfile - Each instantiatation of the FoldingSet needs to provide a
comment|/// way to convert nodes into a unique specifier.
name|virtual
name|void
name|GetNodeProfile
argument_list|(
argument|FoldingSetNodeID&ID
argument_list|,
argument|Node *N
argument_list|)
specifier|const
block|{
name|T
operator|*
name|TN
operator|=
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|N
operator|)
block|;
name|FoldingSetTrait
operator|<
name|T
operator|>
operator|::
name|Profile
argument_list|(
operator|*
name|TN
argument_list|,
name|ID
argument_list|)
block|;   }
name|public
operator|:
name|explicit
name|FoldingSet
argument_list|(
argument|unsigned Log2InitSize =
literal|6
argument_list|)
operator|:
name|FoldingSetImpl
argument_list|(
argument|Log2InitSize
argument_list|)
block|{}
typedef|typedef
name|FoldingSetIterator
operator|<
name|T
operator|>
name|iterator
expr_stmt|;
name|iterator
name|begin
argument_list|()
block|{
return|return
name|iterator
argument_list|(
name|Buckets
argument_list|)
return|;
block|}
name|iterator
name|end
argument_list|()
block|{
return|return
name|iterator
argument_list|(
name|Buckets
operator|+
name|NumBuckets
argument_list|)
return|;
block|}
typedef|typedef
name|FoldingSetIterator
operator|<
specifier|const
name|T
operator|>
name|const_iterator
expr_stmt|;
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|Buckets
argument_list|)
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|Buckets
operator|+
name|NumBuckets
argument_list|)
return|;
block|}
typedef|typedef
name|FoldingSetBucketIterator
operator|<
name|T
operator|>
name|bucket_iterator
expr_stmt|;
name|bucket_iterator
name|bucket_begin
parameter_list|(
name|unsigned
name|hash
parameter_list|)
block|{
return|return
name|bucket_iterator
argument_list|(
name|Buckets
operator|+
operator|(
name|hash
operator|&
operator|(
name|NumBuckets
operator|-
literal|1
operator|)
operator|)
argument_list|)
return|;
block|}
name|bucket_iterator
name|bucket_end
parameter_list|(
name|unsigned
name|hash
parameter_list|)
block|{
return|return
name|bucket_iterator
argument_list|(
name|Buckets
operator|+
operator|(
name|hash
operator|&
operator|(
name|NumBuckets
operator|-
literal|1
operator|)
operator|)
argument_list|,
name|true
argument_list|)
return|;
block|}
comment|/// GetOrInsertNode - If there is an existing simple Node exactly
comment|/// equal to the specified node, return it.  Otherwise, insert 'N' and
comment|/// return it instead.
name|T
modifier|*
name|GetOrInsertNode
parameter_list|(
name|Node
modifier|*
name|N
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|FoldingSetImpl
operator|::
name|GetOrInsertNode
argument_list|(
name|N
argument_list|)
operator|)
return|;
block|}
comment|/// FindNodeOrInsertPos - Look up the node specified by ID.  If it exists,
comment|/// return it.  If not, return the insertion token that will make insertion
comment|/// faster.
name|T
modifier|*
name|FindNodeOrInsertPos
parameter_list|(
specifier|const
name|FoldingSetNodeID
modifier|&
name|ID
parameter_list|,
name|void
modifier|*
modifier|&
name|InsertPos
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|FoldingSetImpl
operator|::
name|FindNodeOrInsertPos
argument_list|(
name|ID
argument_list|,
name|InsertPos
argument_list|)
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// FoldingSetIteratorImpl - This is the common iterator support shared by all
end_comment

begin_comment
comment|/// folding sets, which knows how to walk the folding set hash table.
end_comment

begin_decl_stmt
name|class
name|FoldingSetIteratorImpl
block|{
name|protected
label|:
name|FoldingSetNode
modifier|*
name|NodePtr
decl_stmt|;
name|FoldingSetIteratorImpl
argument_list|(
name|void
operator|*
operator|*
name|Bucket
argument_list|)
expr_stmt|;
name|void
name|advance
parameter_list|()
function_decl|;
name|public
label|:
name|bool
name|operator
operator|==
operator|(
specifier|const
name|FoldingSetIteratorImpl
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|NodePtr
operator|==
name|RHS
operator|.
name|NodePtr
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|FoldingSetIteratorImpl
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|NodePtr
operator|!=
name|RHS
operator|.
name|NodePtr
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
name|T
operator|>
name|class
name|FoldingSetIterator
operator|:
name|public
name|FoldingSetIteratorImpl
block|{
name|public
operator|:
name|explicit
name|FoldingSetIterator
argument_list|(
name|void
operator|*
operator|*
name|Bucket
argument_list|)
operator|:
name|FoldingSetIteratorImpl
argument_list|(
argument|Bucket
argument_list|)
block|{}
name|T
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|NodePtr
operator|)
return|;
block|}
name|T
operator|*
name|operator
operator|->
expr|(
end_expr_stmt

begin_expr_stmt
unit|)
specifier|const
block|{
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|NodePtr
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|FoldingSetIterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// Preincrement
name|advance
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|FoldingSetIterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// Postincrement
name|FoldingSetIterator
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
unit|};
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// FoldingSetBucketIteratorImpl - This is the common bucket iterator support
end_comment

begin_comment
comment|///  shared by all folding sets, which knows how to walk a particular bucket
end_comment

begin_comment
comment|///  of a folding set hash table.
end_comment

begin_decl_stmt
name|class
name|FoldingSetBucketIteratorImpl
block|{
name|protected
label|:
name|void
modifier|*
name|Ptr
decl_stmt|;
name|explicit
name|FoldingSetBucketIteratorImpl
parameter_list|(
name|void
modifier|*
modifier|*
name|Bucket
parameter_list|)
function_decl|;
name|FoldingSetBucketIteratorImpl
argument_list|(
name|void
operator|*
operator|*
name|Bucket
argument_list|,
name|bool
argument_list|)
operator|:
name|Ptr
argument_list|(
argument|Bucket
argument_list|)
block|{}
name|void
name|advance
argument_list|()
block|{
name|void
operator|*
name|Probe
operator|=
name|static_cast
operator|<
name|FoldingSetNode
operator|*
operator|>
operator|(
name|Ptr
operator|)
operator|->
name|getNextInBucket
argument_list|()
block|;
name|uintptr_t
name|x
operator|=
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|Probe
operator|)
operator|&
operator|~
literal|0x1
block|;
name|Ptr
operator|=
name|reinterpret_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|x
operator|)
block|;   }
name|public
operator|:
name|bool
name|operator
operator|==
operator|(
specifier|const
name|FoldingSetBucketIteratorImpl
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|Ptr
operator|==
name|RHS
operator|.
name|Ptr
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|FoldingSetBucketIteratorImpl
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|Ptr
operator|!=
name|RHS
operator|.
name|Ptr
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
name|T
operator|>
name|class
name|FoldingSetBucketIterator
operator|:
name|public
name|FoldingSetBucketIteratorImpl
block|{
name|public
operator|:
name|explicit
name|FoldingSetBucketIterator
argument_list|(
name|void
operator|*
operator|*
name|Bucket
argument_list|)
operator|:
name|FoldingSetBucketIteratorImpl
argument_list|(
argument|Bucket
argument_list|)
block|{}
name|FoldingSetBucketIterator
argument_list|(
name|void
operator|*
operator|*
name|Bucket
argument_list|,
name|bool
argument_list|)
operator|:
name|FoldingSetBucketIteratorImpl
argument_list|(
argument|Bucket
argument_list|,
argument|true
argument_list|)
block|{}
name|T
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|Ptr
operator|)
return|;
block|}
name|T
operator|*
name|operator
operator|->
expr|(
end_expr_stmt

begin_expr_stmt
unit|)
specifier|const
block|{
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|Ptr
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|FoldingSetBucketIterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// Preincrement
name|advance
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|FoldingSetBucketIterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// Postincrement
name|FoldingSetBucketIterator
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
unit|};
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// FoldingSetNodeWrapper - This template class is used to "wrap" arbitrary
end_comment

begin_comment
comment|/// types in an enclosing object so that they can be inserted into FoldingSets.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|FoldingSetNodeWrapper
operator|:
name|public
name|FoldingSetNode
block|{
name|T
name|data
block|;
name|public
operator|:
name|explicit
name|FoldingSetNodeWrapper
argument_list|(
specifier|const
name|T
operator|&
name|x
argument_list|)
operator|:
name|data
argument_list|(
argument|x
argument_list|)
block|{}
name|virtual
operator|~
name|FoldingSetNodeWrapper
argument_list|()
block|{}
name|template
operator|<
name|typename
name|A1
operator|>
name|explicit
name|FoldingSetNodeWrapper
argument_list|(
specifier|const
name|A1
operator|&
name|a1
argument_list|)
operator|:
name|data
argument_list|(
argument|a1
argument_list|)
block|{}
name|template
operator|<
name|typename
name|A1
block|,
name|typename
name|A2
operator|>
name|explicit
name|FoldingSetNodeWrapper
argument_list|(
specifier|const
name|A1
operator|&
name|a1
argument_list|,
specifier|const
name|A2
operator|&
name|a2
argument_list|)
operator|:
name|data
argument_list|(
argument|a1
argument_list|,
argument|a2
argument_list|)
block|{}
name|template
operator|<
name|typename
name|A1
block|,
name|typename
name|A2
block|,
name|typename
name|A3
operator|>
name|explicit
name|FoldingSetNodeWrapper
argument_list|(
specifier|const
name|A1
operator|&
name|a1
argument_list|,
specifier|const
name|A2
operator|&
name|a2
argument_list|,
specifier|const
name|A3
operator|&
name|a3
argument_list|)
operator|:
name|data
argument_list|(
argument|a1
argument_list|,
argument|a2
argument_list|,
argument|a3
argument_list|)
block|{}
name|template
operator|<
name|typename
name|A1
block|,
name|typename
name|A2
block|,
name|typename
name|A3
block|,
name|typename
name|A4
operator|>
name|explicit
name|FoldingSetNodeWrapper
argument_list|(
specifier|const
name|A1
operator|&
name|a1
argument_list|,
specifier|const
name|A2
operator|&
name|a2
argument_list|,
specifier|const
name|A3
operator|&
name|a3
argument_list|,
specifier|const
name|A4
operator|&
name|a4
argument_list|)
operator|:
name|data
argument_list|(
argument|a1
argument_list|,
argument|a2
argument_list|,
argument|a3
argument_list|,
argument|a4
argument_list|)
block|{}
name|template
operator|<
name|typename
name|A1
block|,
name|typename
name|A2
block|,
name|typename
name|A3
block|,
name|typename
name|A4
block|,
name|typename
name|A5
operator|>
name|explicit
name|FoldingSetNodeWrapper
argument_list|(
specifier|const
name|A1
operator|&
name|a1
argument_list|,
specifier|const
name|A2
operator|&
name|a2
argument_list|,
specifier|const
name|A3
operator|&
name|a3
argument_list|,
specifier|const
name|A4
operator|&
name|a4
argument_list|,
specifier|const
name|A5
operator|&
name|a5
argument_list|)
operator|:
name|data
argument_list|(
argument|a1
argument_list|,
argument|a2
argument_list|,
argument|a3
argument_list|,
argument|a4
argument_list|,
argument|a5
argument_list|)
block|{}
name|void
name|Profile
argument_list|(
argument|FoldingSetNodeID& ID
argument_list|)
block|{
name|FoldingSetTrait
operator|<
name|T
operator|>
operator|::
name|Profile
argument_list|(
name|data
argument_list|,
name|ID
argument_list|)
block|; }
name|T
operator|&
name|getValue
argument_list|()
block|{
return|return
name|data
return|;
block|}
specifier|const
name|T
operator|&
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|data
return|;
block|}
end_expr_stmt

begin_function
name|operator
name|T
function|&()
block|{
return|return
name|data
return|;
block|}
end_function

begin_expr_stmt
name|operator
specifier|const
name|T
operator|&
operator|(
operator|)
specifier|const
block|{
return|return
name|data
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// FastFoldingSetNode - This is a subclass of FoldingSetNode which stores
end_comment

begin_comment
comment|/// a FoldingSetNodeID value rather than requiring the node to recompute it
end_comment

begin_comment
comment|/// each time it is needed. This trades space for speed (which can be
end_comment

begin_comment
comment|/// significant if the ID is long), and it also permits nodes to drop
end_comment

begin_comment
comment|/// information that would otherwise only be required for recomputing an ID.
end_comment

begin_decl_stmt
name|class
name|FastFoldingSetNode
range|:
name|public
name|FoldingSetNode
block|{
name|FoldingSetNodeID
name|FastID
block|;
name|protected
operator|:
name|explicit
name|FastFoldingSetNode
argument_list|(
specifier|const
name|FoldingSetNodeID
operator|&
name|ID
argument_list|)
operator|:
name|FastID
argument_list|(
argument|ID
argument_list|)
block|{}
name|public
operator|:
name|void
name|Profile
argument_list|(
argument|FoldingSetNodeID& ID
argument_list|)
block|{
name|ID
operator|=
name|FastID
block|; }
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Partial specializations of FoldingSetTrait.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|FoldingSetTrait
operator|<
name|T
operator|*
operator|>
block|{
specifier|static
specifier|inline
name|void
name|Profile
argument_list|(
argument|const T* X
argument_list|,
argument|FoldingSetNodeID& ID
argument_list|)
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|X
argument_list|)
block|;   }
specifier|static
specifier|inline
name|void
name|Profile
argument_list|(
argument|T* X
argument_list|,
argument|FoldingSetNodeID& ID
argument_list|)
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|X
argument_list|)
block|;   }
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|FoldingSetTrait
operator|<
specifier|const
name|T
operator|*
operator|>
block|{
specifier|static
specifier|inline
name|void
name|Profile
argument_list|(
argument|const T* X
argument_list|,
argument|FoldingSetNodeID& ID
argument_list|)
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|X
argument_list|)
block|;   }
block|}
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// End of namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

