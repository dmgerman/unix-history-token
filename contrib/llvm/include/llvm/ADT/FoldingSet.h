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
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
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
file|<cstdint>
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
comment|/// call one of the Add* functions defined in the FoldingSetBase::NodeID class.
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
comment|///      }
comment|///      ...
comment|///    };
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
name|class
name|StringRef
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// FoldingSetBase - Implements the folding set functionality.  The main
comment|/// structure is an array of buckets.  Each bucket is indexed by the hash of
comment|/// the nodes it contains.  The bucket itself points to the nodes contained
comment|/// in the bucket via a singly linked list.  The last node in the list points
comment|/// back to the bucket to facilitate node removal.
comment|///
name|class
name|FoldingSetBase
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
comment|// Out of line virtual method.
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
name|explicit
name|FoldingSetBase
parameter_list|(
name|unsigned
name|Log2InitSize
init|=
literal|6
parameter_list|)
function_decl|;
name|FoldingSetBase
argument_list|(
name|FoldingSetBase
operator|&&
name|Arg
argument_list|)
expr_stmt|;
name|FoldingSetBase
modifier|&
name|operator
init|=
operator|(
name|FoldingSetBase
operator|&&
name|RHS
operator|)
decl_stmt|;
operator|~
name|FoldingSetBase
argument_list|()
expr_stmt|;
name|public
label|:
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
argument|nullptr
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
comment|/// reserve - Increase the number of buckets such that adding the
comment|/// EltCount-th node won't cause a rebucket operation. reserve is permitted
comment|/// to allocate more space than requested by EltCount.
name|void
name|reserve
parameter_list|(
name|unsigned
name|EltCount
parameter_list|)
function_decl|;
comment|/// capacity - Returns the number of nodes permitted in the folding set
comment|/// before a rebucket operation is performed.
name|unsigned
name|capacity
parameter_list|()
block|{
comment|// We allow a load factor of up to 2.0,
comment|// so that means our capacity is NumBuckets * 2
return|return
name|NumBuckets
operator|*
literal|2
return|;
block|}
name|private
label|:
comment|/// GrowHashTable - Double the size of the hash table and rehash everything.
name|void
name|GrowHashTable
parameter_list|()
function_decl|;
comment|/// GrowBucketCount - resize the hash table and rehash everything.
comment|/// NewBucketCount must be a power of two, and must be greater than the old
comment|/// bucket count.
name|void
name|GrowBucketCount
parameter_list|(
name|unsigned
name|NewBucketCount
parameter_list|)
function_decl|;
name|protected
label|:
comment|/// GetNodeProfile - Instantiations of the FoldingSet template implement
comment|/// this function to gather data bits for the given node.
name|virtual
name|void
name|GetNodeProfile
argument_list|(
name|Node
operator|*
name|N
argument_list|,
name|FoldingSetNodeID
operator|&
name|ID
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// NodeEquals - Instantiations of the FoldingSet template implement
comment|/// this function to compare the given node with the given ID.
name|virtual
name|bool
name|NodeEquals
argument_list|(
name|Node
operator|*
name|N
argument_list|,
specifier|const
name|FoldingSetNodeID
operator|&
name|ID
argument_list|,
name|unsigned
name|IDHash
argument_list|,
name|FoldingSetNodeID
operator|&
name|TempID
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// ComputeNodeHash - Instantiations of the FoldingSet template implement
comment|/// this function to compute a hash value for the given node.
name|virtual
name|unsigned
name|ComputeNodeHash
argument_list|(
name|Node
operator|*
name|N
argument_list|,
name|FoldingSetNodeID
operator|&
name|TempID
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|// The below methods are protected to encourage subclasses to provide a more
comment|// type-safe API.
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
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// DefaultFoldingSetTrait - This class provides default implementations
comment|/// for FoldingSetTrait implementations.
comment|///
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|DefaultFoldingSetTrait
block|{
specifier|static
name|void
name|Profile
argument_list|(
argument|const T&X
argument_list|,
argument|FoldingSetNodeID&ID
argument_list|)
block|{
name|X
operator|.
name|Profile
argument_list|(
name|ID
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|T&X
argument_list|,
argument|FoldingSetNodeID&ID
argument_list|)
block|{
name|X
operator|.
name|Profile
argument_list|(
name|ID
argument_list|)
block|;   }
comment|// Equals - Test if the profile for X would match ID, using TempID
comment|// to compute a temporary ID if necessary. The default implementation
comment|// just calls Profile and does a regular comparison. Implementations
comment|// can override this to provide more efficient implementations.
specifier|static
specifier|inline
name|bool
name|Equals
argument_list|(
argument|T&X
argument_list|,
argument|const FoldingSetNodeID&ID
argument_list|,
argument|unsigned IDHash
argument_list|,
argument|FoldingSetNodeID&TempID
argument_list|)
block|;
comment|// ComputeHash - Compute a hash value for X, using TempID to
comment|// compute a temporary ID if necessary. The default implementation
comment|// just calls Profile and does a regular hash computation.
comment|// Implementations can override this to provide more efficient
comment|// implementations.
specifier|static
specifier|inline
name|unsigned
name|ComputeHash
argument_list|(
name|T
operator|&
name|X
argument_list|,
name|FoldingSetNodeID
operator|&
name|TempID
argument_list|)
block|; }
expr_stmt|;
comment|/// FoldingSetTrait - This trait class is used to define behavior of how
comment|/// to "profile" (in the FoldingSet parlance) an object of a given type.
comment|/// The default behavior is to invoke a 'Profile' method on an object, but
comment|/// through template specialization the behavior can be tailored for specific
comment|/// types.  Combined with the FoldingSetNodeWrapper class, one can add objects
comment|/// to FoldingSets that were not originally designed to have that behavior.
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|FoldingSetTrait
operator|:
name|public
name|DefaultFoldingSetTrait
operator|<
name|T
operator|>
block|{}
expr_stmt|;
comment|/// DefaultContextualFoldingSetTrait - Like DefaultFoldingSetTrait, but
comment|/// for ContextualFoldingSets.
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|Ctx
operator|>
expr|struct
name|DefaultContextualFoldingSetTrait
block|{
specifier|static
name|void
name|Profile
argument_list|(
argument|T&X
argument_list|,
argument|FoldingSetNodeID&ID
argument_list|,
argument|Ctx Context
argument_list|)
block|{
name|X
operator|.
name|Profile
argument_list|(
name|ID
argument_list|,
name|Context
argument_list|)
block|;   }
specifier|static
specifier|inline
name|bool
name|Equals
argument_list|(
argument|T&X
argument_list|,
argument|const FoldingSetNodeID&ID
argument_list|,
argument|unsigned IDHash
argument_list|,
argument|FoldingSetNodeID&TempID
argument_list|,
argument|Ctx Context
argument_list|)
block|;
specifier|static
specifier|inline
name|unsigned
name|ComputeHash
argument_list|(
argument|T&X
argument_list|,
argument|FoldingSetNodeID&TempID
argument_list|,
argument|Ctx Context
argument_list|)
block|; }
expr_stmt|;
comment|/// ContextualFoldingSetTrait - Like FoldingSetTrait, but for
comment|/// ContextualFoldingSets.
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|Ctx
operator|>
expr|struct
name|ContextualFoldingSetTrait
operator|:
name|public
name|DefaultContextualFoldingSetTrait
operator|<
name|T
operator|,
name|Ctx
operator|>
block|{}
expr_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|/// FoldingSetNodeIDRef - This class describes a reference to an interned
comment|/// FoldingSetNodeID, which can be a useful to store node id data rather
comment|/// than using plain FoldingSetNodeIDs, since the 32-element SmallVector
comment|/// is often much larger than necessary, and the possibility of heap
comment|/// allocation means it requires a non-trivial destructor call.
name|class
name|FoldingSetNodeIDRef
block|{
specifier|const
name|unsigned
modifier|*
name|Data
init|=
name|nullptr
decl_stmt|;
name|size_t
name|Size
init|=
literal|0
decl_stmt|;
name|public
label|:
name|FoldingSetNodeIDRef
argument_list|()
operator|=
expr|default
expr_stmt|;
name|FoldingSetNodeIDRef
argument_list|(
argument|const unsigned *D
argument_list|,
argument|size_t S
argument_list|)
block|:
name|Data
argument_list|(
name|D
argument_list|)
operator|,
name|Size
argument_list|(
argument|S
argument_list|)
block|{}
comment|/// ComputeHash - Compute a strong hash value for this FoldingSetNodeIDRef,
comment|/// used to lookup the node in the FoldingSetBase.
name|unsigned
name|ComputeHash
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
name|FoldingSetNodeIDRef
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
name|FoldingSetNodeIDRef
name|RHS
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|RHS
operator|)
return|;
block|}
comment|/// Used to compare the "ordering" of two nodes as defined by the
comment|/// profiled bits and their ordering defined by memcmp().
name|bool
name|operator
operator|<
operator|(
name|FoldingSetNodeIDRef
operator|)
specifier|const
expr_stmt|;
specifier|const
name|unsigned
operator|*
name|getData
argument_list|()
specifier|const
block|{
return|return
name|Data
return|;
block|}
name|size_t
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|Size
return|;
block|}
block|}
empty_stmt|;
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
operator|=
expr|default
expr_stmt|;
name|FoldingSetNodeID
argument_list|(
argument|FoldingSetNodeIDRef Ref
argument_list|)
block|:
name|Bits
argument_list|(
argument|Ref.getData()
argument_list|,
argument|Ref.getData() + Ref.getSize()
argument_list|)
block|{}
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
name|void
name|AddNodeID
parameter_list|(
specifier|const
name|FoldingSetNodeID
modifier|&
name|ID
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
argument|const T&x
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
comment|/// object to be used to compute a new profile.
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
comment|/// to lookup the node in the FoldingSetBase.
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
name|bool
name|operator
operator|==
operator|(
specifier|const
name|FoldingSetNodeIDRef
name|RHS
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|FoldingSetNodeID
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|RHS
operator|)
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|FoldingSetNodeIDRef
name|RHS
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|RHS
operator|)
return|;
block|}
comment|/// Used to compare the "ordering" of two nodes as defined by the
comment|/// profiled bits and their ordering defined by memcmp().
name|bool
name|operator
operator|<
operator|(
specifier|const
name|FoldingSetNodeID
operator|&
name|RHS
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|<
operator|(
specifier|const
name|FoldingSetNodeIDRef
name|RHS
operator|)
specifier|const
expr_stmt|;
comment|/// Intern - Copy this node's data to a memory region allocated from the
comment|/// given allocator and return a FoldingSetNodeIDRef describing the
comment|/// interned data.
name|FoldingSetNodeIDRef
name|Intern
argument_list|(
name|BumpPtrAllocator
operator|&
name|Allocator
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
comment|// Convenience type to hide the implementation of the folding set.
typedef|typedef
name|FoldingSetBase
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
comment|// Definitions of FoldingSetTrait and ContextualFoldingSetTrait functions, which
comment|// require the definition of FoldingSetNodeID.
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|DefaultFoldingSetTrait
operator|<
name|T
operator|>
operator|::
name|Equals
argument_list|(
argument|T&X
argument_list|,
argument|const FoldingSetNodeID&ID
argument_list|,
argument|unsigned
comment|/*IDHash*/
argument_list|,
argument|FoldingSetNodeID&TempID
argument_list|)
block|{
name|FoldingSetTrait
operator|<
name|T
operator|>
operator|::
name|Profile
argument_list|(
name|X
argument_list|,
name|TempID
argument_list|)
block|;
return|return
name|TempID
operator|==
name|ID
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|unsigned
name|DefaultFoldingSetTrait
operator|<
name|T
operator|>
operator|::
name|ComputeHash
argument_list|(
argument|T&X
argument_list|,
argument|FoldingSetNodeID&TempID
argument_list|)
block|{
name|FoldingSetTrait
operator|<
name|T
operator|>
operator|::
name|Profile
argument_list|(
name|X
argument_list|,
name|TempID
argument_list|)
block|;
return|return
name|TempID
operator|.
name|ComputeHash
argument_list|()
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|Ctx
operator|>
specifier|inline
name|bool
name|DefaultContextualFoldingSetTrait
operator|<
name|T
operator|,
name|Ctx
operator|>
operator|::
name|Equals
argument_list|(
argument|T&X
argument_list|,
argument|const FoldingSetNodeID&ID
argument_list|,
argument|unsigned
comment|/*IDHash*/
argument_list|,
argument|FoldingSetNodeID&TempID
argument_list|,
argument|Ctx Context
argument_list|)
block|{
name|ContextualFoldingSetTrait
operator|<
name|T
block|,
name|Ctx
operator|>
operator|::
name|Profile
argument_list|(
name|X
argument_list|,
name|TempID
argument_list|,
name|Context
argument_list|)
block|;
return|return
name|TempID
operator|==
name|ID
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|Ctx
operator|>
specifier|inline
name|unsigned
name|DefaultContextualFoldingSetTrait
operator|<
name|T
operator|,
name|Ctx
operator|>
operator|::
name|ComputeHash
argument_list|(
argument|T&X
argument_list|,
argument|FoldingSetNodeID&TempID
argument_list|,
argument|Ctx Context
argument_list|)
block|{
name|ContextualFoldingSetTrait
operator|<
name|T
block|,
name|Ctx
operator|>
operator|::
name|Profile
argument_list|(
name|X
argument_list|,
name|TempID
argument_list|,
name|Context
argument_list|)
block|;
return|return
name|TempID
operator|.
name|ComputeHash
argument_list|()
return|;
block|}
comment|//===----------------------------------------------------------------------===//
comment|/// FoldingSetImpl - An implementation detail that lets us share code between
comment|/// FoldingSet and ContextualFoldingSet.
name|template
operator|<
name|class
name|T
operator|>
name|class
name|FoldingSetImpl
operator|:
name|public
name|FoldingSetBase
block|{
name|protected
operator|:
name|explicit
name|FoldingSetImpl
argument_list|(
argument|unsigned Log2InitSize
argument_list|)
operator|:
name|FoldingSetBase
argument_list|(
argument|Log2InitSize
argument_list|)
block|{}
name|FoldingSetImpl
argument_list|(
name|FoldingSetImpl
operator|&&
name|Arg
argument_list|)
operator|=
expr|default
block|;
name|FoldingSetImpl
operator|&
name|operator
operator|=
operator|(
name|FoldingSetImpl
operator|&&
name|RHS
operator|)
operator|=
expr|default
block|;
operator|~
name|FoldingSetImpl
argument_list|()
operator|=
expr|default
block|;
name|public
operator|:
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
comment|/// RemoveNode - Remove a node from the folding set, returning true if one
comment|/// was removed or false if the node was not in the folding set.
name|bool
name|RemoveNode
parameter_list|(
name|T
modifier|*
name|N
parameter_list|)
block|{
return|return
name|FoldingSetBase
operator|::
name|RemoveNode
argument_list|(
name|N
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
name|T
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
name|FoldingSetBase
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
name|FoldingSetBase
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
comment|/// InsertNode - Insert the specified node into the folding set, knowing that
comment|/// it is not already in the folding set.  InsertPos must be obtained from
comment|/// FindNodeOrInsertPos.
name|void
name|InsertNode
parameter_list|(
name|T
modifier|*
name|N
parameter_list|,
name|void
modifier|*
name|InsertPos
parameter_list|)
block|{
name|FoldingSetBase
operator|::
name|InsertNode
argument_list|(
name|N
argument_list|,
name|InsertPos
argument_list|)
expr_stmt|;
block|}
comment|/// InsertNode - Insert the specified node into the folding set, knowing that
comment|/// it is not already in the folding set.
name|void
name|InsertNode
parameter_list|(
name|T
modifier|*
name|N
parameter_list|)
block|{
name|T
modifier|*
name|Inserted
init|=
name|GetOrInsertNode
argument_list|(
name|N
argument_list|)
decl_stmt|;
operator|(
name|void
operator|)
name|Inserted
expr_stmt|;
name|assert
argument_list|(
name|Inserted
operator|==
name|N
operator|&&
literal|"Node already inserted!"
argument_list|)
expr_stmt|;
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
comment|/// FoldingSet - This template class is used to instantiate a specialized
end_comment

begin_comment
comment|/// implementation of the folding set to the node class T.  T must be a
end_comment

begin_comment
comment|/// subclass of FoldingSetNode and implement a Profile function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that this set type is movable and move-assignable. However, its
end_comment

begin_comment
comment|/// moved-from state is not a valid state for anything other than
end_comment

begin_comment
comment|/// move-assigning and destroying. This is primarily to enable movable APIs
end_comment

begin_comment
comment|/// that incorporate these objects.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|FoldingSet
name|final
operator|:
name|public
name|FoldingSetImpl
operator|<
name|T
operator|>
block|{
name|using
name|Super
operator|=
name|FoldingSetImpl
operator|<
name|T
operator|>
block|;
name|using
name|Node
operator|=
name|typename
name|Super
operator|::
name|Node
block|;
comment|/// GetNodeProfile - Each instantiatation of the FoldingSet needs to provide a
comment|/// way to convert nodes into a unique specifier.
name|void
name|GetNodeProfile
argument_list|(
argument|Node *N
argument_list|,
argument|FoldingSetNodeID&ID
argument_list|)
specifier|const
name|override
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
comment|/// NodeEquals - Instantiations may optionally provide a way to compare a
comment|/// node with a specified ID.
name|bool
name|NodeEquals
argument_list|(
argument|Node *N
argument_list|,
argument|const FoldingSetNodeID&ID
argument_list|,
argument|unsigned IDHash
argument_list|,
argument|FoldingSetNodeID&TempID
argument_list|)
specifier|const
name|override
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
return|return
name|FoldingSetTrait
operator|<
name|T
operator|>
operator|::
name|Equals
argument_list|(
operator|*
name|TN
argument_list|,
name|ID
argument_list|,
name|IDHash
argument_list|,
name|TempID
argument_list|)
return|;
block|}
comment|/// ComputeNodeHash - Instantiations may optionally provide a way to compute a
comment|/// hash value directly from a node.
name|unsigned
name|ComputeNodeHash
argument_list|(
argument|Node *N
argument_list|,
argument|FoldingSetNodeID&TempID
argument_list|)
specifier|const
name|override
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
return|return
name|FoldingSetTrait
operator|<
name|T
operator|>
operator|::
name|ComputeHash
argument_list|(
operator|*
name|TN
argument_list|,
name|TempID
argument_list|)
return|;
block|}
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_macro
name|explicit
end_macro

begin_macro
name|FoldingSet
argument_list|(
argument|unsigned Log2InitSize =
literal|6
argument_list|)
end_macro

begin_macro
unit|:
name|Super
argument_list|(
argument|Log2InitSize
argument_list|)
end_macro

begin_block
block|{}
end_block

begin_expr_stmt
name|FoldingSet
argument_list|(
name|FoldingSet
operator|&&
name|Arg
argument_list|)
operator|=
expr|default
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|FoldingSet
modifier|&
name|operator
init|=
operator|(
name|FoldingSet
operator|&&
name|RHS
operator|)
operator|=
expr|default
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// ContextualFoldingSet - This template class is a further refinement
end_comment

begin_comment
comment|/// of FoldingSet which provides a context argument when calling
end_comment

begin_comment
comment|/// Profile on its nodes.  Currently, that argument is fixed at
end_comment

begin_comment
comment|/// initialization time.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// T must be a subclass of FoldingSetNode and implement a Profile
end_comment

begin_comment
comment|/// function with signature
end_comment

begin_comment
comment|///   void Profile(FoldingSetNodeID&, Ctx);
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
name|class
name|Ctx
operator|>
name|class
name|ContextualFoldingSet
name|final
operator|:
name|public
name|FoldingSetImpl
operator|<
name|T
operator|>
block|{
comment|// Unfortunately, this can't derive from FoldingSet<T> because the
comment|// construction of the vtable for FoldingSet<T> requires
comment|// FoldingSet<T>::GetNodeProfile to be instantiated, which in turn
comment|// requires a single-argument T::Profile().
name|using
name|Super
operator|=
name|FoldingSetImpl
operator|<
name|T
operator|>
block|;
name|using
name|Node
operator|=
name|typename
name|Super
operator|::
name|Node
block|;
name|Ctx
name|Context
block|;
comment|/// GetNodeProfile - Each instantiatation of the FoldingSet needs to provide a
comment|/// way to convert nodes into a unique specifier.
name|void
name|GetNodeProfile
argument_list|(
argument|Node *N
argument_list|,
argument|FoldingSetNodeID&ID
argument_list|)
specifier|const
name|override
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
name|ContextualFoldingSetTrait
operator|<
name|T
block|,
name|Ctx
operator|>
operator|::
name|Profile
argument_list|(
operator|*
name|TN
argument_list|,
name|ID
argument_list|,
name|Context
argument_list|)
block|;   }
name|bool
name|NodeEquals
argument_list|(
argument|Node *N
argument_list|,
argument|const FoldingSetNodeID&ID
argument_list|,
argument|unsigned IDHash
argument_list|,
argument|FoldingSetNodeID&TempID
argument_list|)
specifier|const
name|override
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
return|return
name|ContextualFoldingSetTrait
operator|<
name|T
operator|,
name|Ctx
operator|>
operator|::
name|Equals
argument_list|(
operator|*
name|TN
argument_list|,
name|ID
argument_list|,
name|IDHash
argument_list|,
name|TempID
argument_list|,
name|Context
argument_list|)
return|;
block|}
name|unsigned
name|ComputeNodeHash
argument_list|(
argument|Node *N
argument_list|,
argument|FoldingSetNodeID&TempID
argument_list|)
specifier|const
name|override
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
return|return
name|ContextualFoldingSetTrait
operator|<
name|T
operator|,
name|Ctx
operator|>
operator|::
name|ComputeHash
argument_list|(
operator|*
name|TN
argument_list|,
name|TempID
argument_list|,
name|Context
argument_list|)
return|;
block|}
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_macro
name|explicit
end_macro

begin_macro
name|ContextualFoldingSet
argument_list|(
argument|Ctx Context
argument_list|,
argument|unsigned Log2InitSize =
literal|6
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|Super
argument_list|(
name|Log2InitSize
argument_list|)
operator|,
name|Context
argument_list|(
argument|Context
argument_list|)
block|{}
name|Ctx
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|Context
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// FoldingSetVector - This template class combines a FoldingSet and a vector
end_comment

begin_comment
comment|/// to provide the interface of FoldingSet but with deterministic iteration
end_comment

begin_comment
comment|/// order based on the insertion order. T must be a subclass of FoldingSetNode
end_comment

begin_comment
comment|/// and implement a Profile function.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
name|class
name|VectorT
operator|=
name|SmallVector
operator|<
name|T
operator|*
operator|,
literal|8
operator|>>
name|class
name|FoldingSetVector
block|{
name|FoldingSet
operator|<
name|T
operator|>
name|Set
block|;
name|VectorT
name|Vector
block|;
name|public
operator|:
name|explicit
name|FoldingSetVector
argument_list|(
argument|unsigned Log2InitSize =
literal|6
argument_list|)
operator|:
name|Set
argument_list|(
argument|Log2InitSize
argument_list|)
block|{   }
typedef|typedef
name|pointee_iterator
operator|<
name|typename
name|VectorT
operator|::
name|iterator
operator|>
name|iterator
expr_stmt|;
name|iterator
name|begin
argument_list|()
block|{
return|return
name|Vector
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
argument_list|()
block|{
return|return
name|Vector
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_typedef
typedef|typedef
name|pointee_iterator
operator|<
name|typename
name|VectorT
operator|::
name|const_iterator
operator|>
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
name|Vector
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
name|Vector
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// clear - Remove all nodes from the folding set.
end_comment

begin_function
name|void
name|clear
parameter_list|()
block|{
name|Set
operator|.
name|clear
argument_list|()
expr_stmt|;
name|Vector
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/// FindNodeOrInsertPos - Look up the node specified by ID.  If it exists,
end_comment

begin_comment
comment|/// return it.  If not, return the insertion token that will make insertion
end_comment

begin_comment
comment|/// faster.
end_comment

begin_function
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
name|Set
operator|.
name|FindNodeOrInsertPos
argument_list|(
name|ID
argument_list|,
name|InsertPos
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// GetOrInsertNode - If there is an existing simple Node exactly
end_comment

begin_comment
comment|/// equal to the specified node, return it.  Otherwise, insert 'N' and
end_comment

begin_comment
comment|/// return it instead.
end_comment

begin_function
name|T
modifier|*
name|GetOrInsertNode
parameter_list|(
name|T
modifier|*
name|N
parameter_list|)
block|{
name|T
modifier|*
name|Result
init|=
name|Set
operator|.
name|GetOrInsertNode
argument_list|(
name|N
argument_list|)
decl_stmt|;
if|if
condition|(
name|Result
operator|==
name|N
condition|)
name|Vector
operator|.
name|push_back
argument_list|(
name|N
argument_list|)
expr_stmt|;
return|return
name|Result
return|;
block|}
end_function

begin_comment
comment|/// InsertNode - Insert the specified node into the folding set, knowing that
end_comment

begin_comment
comment|/// it is not already in the folding set.  InsertPos must be obtained from
end_comment

begin_comment
comment|/// FindNodeOrInsertPos.
end_comment

begin_function
name|void
name|InsertNode
parameter_list|(
name|T
modifier|*
name|N
parameter_list|,
name|void
modifier|*
name|InsertPos
parameter_list|)
block|{
name|Set
operator|.
name|InsertNode
argument_list|(
name|N
argument_list|,
name|InsertPos
argument_list|)
expr_stmt|;
name|Vector
operator|.
name|push_back
argument_list|(
name|N
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// InsertNode - Insert the specified node into the folding set, knowing that
end_comment

begin_comment
comment|/// it is not already in the folding set.
end_comment

begin_function
name|void
name|InsertNode
parameter_list|(
name|T
modifier|*
name|N
parameter_list|)
block|{
name|Set
operator|.
name|InsertNode
argument_list|(
name|N
argument_list|)
expr_stmt|;
name|Vector
operator|.
name|push_back
argument_list|(
name|N
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// size - Returns the number of nodes in the folding set.
end_comment

begin_expr_stmt
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|Set
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// empty - Returns true if there are no nodes in the folding set.
end_comment

begin_expr_stmt
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Set
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
unit|};
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
comment|/// shared by all folding sets, which knows how to walk a particular bucket
end_comment

begin_comment
comment|/// of a folding set hash table.
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
name|template
operator|<
name|typename
operator|...
name|Ts
operator|>
name|explicit
name|FoldingSetNodeWrapper
argument_list|(
name|Ts
operator|&&
operator|...
name|Args
argument_list|)
operator|:
name|data
argument_list|(
argument|std::forward<Ts>(Args)...
argument_list|)
block|{}
name|void
name|Profile
argument_list|(
argument|FoldingSetNodeID&ID
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
argument|FoldingSetNodeID&ID
argument_list|)
specifier|const
block|{
name|ID
operator|.
name|AddNodeID
argument_list|(
name|FastID
argument_list|)
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
argument|T *X
argument_list|,
argument|FoldingSetNodeID&ID
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
name|T1
operator|,
name|typename
name|T2
operator|>
expr|struct
name|FoldingSetTrait
operator|<
name|std
operator|::
name|pair
operator|<
name|T1
operator|,
name|T2
operator|>>
block|{
specifier|static
specifier|inline
name|void
name|Profile
argument_list|(
argument|const std::pair<T1
argument_list|,
argument|T2>&P
argument_list|,
argument|FoldingSetNodeID&ID
argument_list|)
block|{
name|ID
operator|.
name|Add
argument_list|(
name|P
operator|.
name|first
argument_list|)
block|;
name|ID
operator|.
name|Add
argument_list|(
name|P
operator|.
name|second
argument_list|)
block|;   }
block|}
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
comment|// LLVM_ADT_FOLDINGSET_H
end_comment

end_unit

