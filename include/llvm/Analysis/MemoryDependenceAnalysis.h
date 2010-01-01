begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/MemoryDependenceAnalysis.h - Memory Deps  --*- C++ -*-===//
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
comment|// This file defines the MemoryDependenceAnalysis analysis pass.
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
name|LLVM_ANALYSIS_MEMORY_DEPENDENCE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_MEMORY_DEPENDENCE_H
end_define

begin_include
include|#
directive|include
file|"llvm/BasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ValueHandle.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|CallSite
decl_stmt|;
name|class
name|AliasAnalysis
decl_stmt|;
name|class
name|TargetData
decl_stmt|;
name|class
name|MemoryDependenceAnalysis
decl_stmt|;
name|class
name|PredIteratorCache
decl_stmt|;
name|class
name|DominatorTree
decl_stmt|;
name|class
name|PHITransAddr
decl_stmt|;
comment|/// MemDepResult - A memory dependence query can return one of three different
comment|/// answers, described below.
name|class
name|MemDepResult
block|{
enum|enum
name|DepType
block|{
comment|/// Invalid - Clients of MemDep never see this.
name|Invalid
init|=
literal|0
block|,
comment|/// Clobber - This is a dependence on the specified instruction which
comment|/// clobbers the desired value.  The pointer member of the MemDepResult
comment|/// pair holds the instruction that clobbers the memory.  For example,
comment|/// this occurs when we see a may-aliased store to the memory location we
comment|/// care about.
name|Clobber
block|,
comment|/// Def - This is a dependence on the specified instruction which
comment|/// defines/produces the desired memory location.  The pointer member of
comment|/// the MemDepResult pair holds the instruction that defines the memory.
comment|/// Cases of interest:
comment|///   1. This could be a load or store for dependence queries on
comment|///      load/store.  The value loaded or stored is the produced value.
comment|///      Note that the pointer operand may be different than that of the
comment|///      queried pointer due to must aliases and phi translation.  Note
comment|///      that the def may not be the same type as the query, the pointers
comment|///      may just be must aliases.
comment|///   2. For loads and stores, this could be an allocation instruction. In
comment|///      this case, the load is loading an undef value or a store is the
comment|///      first store to (that part of) the allocation.
comment|///   3. Dependence queries on calls return Def only when they are
comment|///      readonly calls or memory use intrinsics with identical callees
comment|///      and no intervening clobbers.  No validation is done that the
comment|///      operands to the calls are the same.
name|Def
block|,
comment|/// NonLocal - This marker indicates that the query has no dependency in
comment|/// the specified block.  To find out more, the client should query other
comment|/// predecessor blocks.
name|NonLocal
block|}
enum|;
typedef|typedef
name|PointerIntPair
operator|<
name|Instruction
operator|*
operator|,
literal|2
operator|,
name|DepType
operator|>
name|PairTy
expr_stmt|;
name|PairTy
name|Value
decl_stmt|;
name|explicit
name|MemDepResult
argument_list|(
argument|PairTy V
argument_list|)
block|:
name|Value
argument_list|(
argument|V
argument_list|)
block|{}
name|public
label|:
name|MemDepResult
argument_list|()
operator|:
name|Value
argument_list|(
literal|0
argument_list|,
argument|Invalid
argument_list|)
block|{}
comment|/// get methods: These are static ctor methods for creating various
comment|/// MemDepResult kinds.
specifier|static
name|MemDepResult
name|getDef
argument_list|(
argument|Instruction *Inst
argument_list|)
block|{
return|return
name|MemDepResult
argument_list|(
name|PairTy
argument_list|(
name|Inst
argument_list|,
name|Def
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|MemDepResult
name|getClobber
parameter_list|(
name|Instruction
modifier|*
name|Inst
parameter_list|)
block|{
return|return
name|MemDepResult
argument_list|(
name|PairTy
argument_list|(
name|Inst
argument_list|,
name|Clobber
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|MemDepResult
name|getNonLocal
parameter_list|()
block|{
return|return
name|MemDepResult
argument_list|(
name|PairTy
argument_list|(
literal|0
argument_list|,
name|NonLocal
argument_list|)
argument_list|)
return|;
block|}
comment|/// isClobber - Return true if this MemDepResult represents a query that is
comment|/// a instruction clobber dependency.
name|bool
name|isClobber
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|getInt
argument_list|()
operator|==
name|Clobber
return|;
block|}
comment|/// isDef - Return true if this MemDepResult represents a query that is
comment|/// a instruction definition dependency.
name|bool
name|isDef
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|getInt
argument_list|()
operator|==
name|Def
return|;
block|}
comment|/// isNonLocal - Return true if this MemDepResult represents a query that
comment|/// is transparent to the start of the block, but where a non-local hasn't
comment|/// been done.
name|bool
name|isNonLocal
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|getInt
argument_list|()
operator|==
name|NonLocal
return|;
block|}
comment|/// getInst() - If this is a normal dependency, return the instruction that
comment|/// is depended on.  Otherwise, return null.
name|Instruction
operator|*
name|getInst
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|MemDepResult
operator|&
name|M
operator|)
specifier|const
block|{
return|return
name|Value
operator|==
name|M
operator|.
name|Value
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|MemDepResult
operator|&
name|M
operator|)
specifier|const
block|{
return|return
name|Value
operator|!=
name|M
operator|.
name|Value
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|MemDepResult
operator|&
name|M
operator|)
specifier|const
block|{
return|return
name|Value
operator|<
name|M
operator|.
name|Value
return|;
block|}
name|bool
name|operator
operator|>
operator|(
specifier|const
name|MemDepResult
operator|&
name|M
operator|)
specifier|const
block|{
return|return
name|Value
operator|>
name|M
operator|.
name|Value
return|;
block|}
name|private
label|:
name|friend
name|class
name|MemoryDependenceAnalysis
decl_stmt|;
comment|/// Dirty - Entries with this marker occur in a LocalDeps map or
comment|/// NonLocalDeps map when the instruction they previously referenced was
comment|/// removed from MemDep.  In either case, the entry may include an
comment|/// instruction pointer.  If so, the pointer is an instruction in the
comment|/// block where scanning can start from, saving some work.
comment|///
comment|/// In a default-constructed MemDepResult object, the type will be Dirty
comment|/// and the instruction pointer will be null.
comment|///
comment|/// isDirty - Return true if this is a MemDepResult in its dirty/invalid.
comment|/// state.
name|bool
name|isDirty
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|getInt
argument_list|()
operator|==
name|Invalid
return|;
block|}
specifier|static
name|MemDepResult
name|getDirty
parameter_list|(
name|Instruction
modifier|*
name|Inst
parameter_list|)
block|{
return|return
name|MemDepResult
argument_list|(
name|PairTy
argument_list|(
name|Inst
argument_list|,
name|Invalid
argument_list|)
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|/// NonLocalDepResult - This is a result from a NonLocal dependence query.
comment|/// For each BasicBlock (the BB entry) it keeps a MemDepResult and the
comment|/// (potentially phi translated) address that was live in the block.
name|class
name|NonLocalDepResult
block|{
name|BasicBlock
modifier|*
name|BB
decl_stmt|;
name|MemDepResult
name|Result
decl_stmt|;
name|Value
modifier|*
name|Address
decl_stmt|;
name|public
label|:
name|NonLocalDepResult
argument_list|(
argument|BasicBlock *bb
argument_list|,
argument|MemDepResult result
argument_list|,
argument|Value *address
argument_list|)
block|:
name|BB
argument_list|(
name|bb
argument_list|)
operator|,
name|Result
argument_list|(
name|result
argument_list|)
operator|,
name|Address
argument_list|(
argument|address
argument_list|)
block|{}
comment|// BB is the sort key, it can't be changed.
name|BasicBlock
operator|*
name|getBB
argument_list|()
specifier|const
block|{
return|return
name|BB
return|;
block|}
name|void
name|setResult
parameter_list|(
specifier|const
name|MemDepResult
modifier|&
name|R
parameter_list|,
name|Value
modifier|*
name|Addr
parameter_list|)
block|{
name|Result
operator|=
name|R
expr_stmt|;
name|Address
operator|=
name|Addr
expr_stmt|;
block|}
specifier|const
name|MemDepResult
operator|&
name|getResult
argument_list|()
specifier|const
block|{
return|return
name|Result
return|;
block|}
comment|/// getAddress - Return the address of this pointer in this block.  This can
comment|/// be different than the address queried for the non-local result because
comment|/// of phi translation.  This returns null if the address was not available
comment|/// in a block (i.e. because phi translation failed) or if this is a cached
comment|/// result and that address was deleted.
comment|///
comment|/// The address is always null for a non-local 'call' dependence.
name|Value
operator|*
name|getAddress
argument_list|()
specifier|const
block|{
return|return
name|Address
return|;
block|}
block|}
empty_stmt|;
comment|/// NonLocalDepEntry - This is an entry in the NonLocalDepInfo cache.  For
comment|/// each BasicBlock (the BB entry) it keeps a MemDepResult.
name|class
name|NonLocalDepEntry
block|{
name|BasicBlock
modifier|*
name|BB
decl_stmt|;
name|MemDepResult
name|Result
decl_stmt|;
name|public
label|:
name|NonLocalDepEntry
argument_list|(
argument|BasicBlock *bb
argument_list|,
argument|MemDepResult result
argument_list|)
block|:
name|BB
argument_list|(
name|bb
argument_list|)
operator|,
name|Result
argument_list|(
argument|result
argument_list|)
block|{}
comment|// This is used for searches.
name|NonLocalDepEntry
argument_list|(
name|BasicBlock
operator|*
name|bb
argument_list|)
operator|:
name|BB
argument_list|(
argument|bb
argument_list|)
block|{}
comment|// BB is the sort key, it can't be changed.
name|BasicBlock
operator|*
name|getBB
argument_list|()
specifier|const
block|{
return|return
name|BB
return|;
block|}
name|void
name|setResult
parameter_list|(
specifier|const
name|MemDepResult
modifier|&
name|R
parameter_list|)
block|{
name|Result
operator|=
name|R
expr_stmt|;
block|}
specifier|const
name|MemDepResult
operator|&
name|getResult
argument_list|()
specifier|const
block|{
return|return
name|Result
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|NonLocalDepEntry
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|BB
operator|<
name|RHS
operator|.
name|BB
return|;
block|}
block|}
empty_stmt|;
comment|/// MemoryDependenceAnalysis - This is an analysis that determines, for a
comment|/// given memory operation, what preceding memory operations it depends on.
comment|/// It builds on alias analysis information, and tries to provide a lazy,
comment|/// caching interface to a common kind of alias information query.
comment|///
comment|/// The dependency information returned is somewhat unusual, but is pragmatic.
comment|/// If queried about a store or call that might modify memory, the analysis
comment|/// will return the instruction[s] that may either load from that memory or
comment|/// store to it.  If queried with a load or call that can never modify memory,
comment|/// the analysis will return calls and stores that might modify the pointer,
comment|/// but generally does not return loads unless a) they are volatile, or
comment|/// b) they load from *must-aliased* pointers.  Returning a dependence on
comment|/// must-alias'd pointers instead of all pointers interacts well with the
comment|/// internal caching mechanism.
comment|///
name|class
name|MemoryDependenceAnalysis
range|:
name|public
name|FunctionPass
block|{
comment|// A map from instructions to their dependency.
typedef|typedef
name|DenseMap
operator|<
name|Instruction
operator|*
operator|,
name|MemDepResult
operator|>
name|LocalDepMapType
expr_stmt|;
name|LocalDepMapType
name|LocalDeps
decl_stmt|;
name|public
label|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|NonLocalDepEntry
operator|>
name|NonLocalDepInfo
expr_stmt|;
name|private
label|:
comment|/// ValueIsLoadPair - This is a pair<Value*, bool> where the bool is true if
comment|/// the dependence is a read only dependence, false if read/write.
typedef|typedef
name|PointerIntPair
operator|<
name|Value
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|ValueIsLoadPair
expr_stmt|;
comment|/// BBSkipFirstBlockPair - This pair is used when caching information for a
comment|/// block.  If the pointer is null, the cache value is not a full query that
comment|/// starts at the specified block.  If non-null, the bool indicates whether
comment|/// or not the contents of the block was skipped.
typedef|typedef
name|PointerIntPair
operator|<
name|BasicBlock
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|BBSkipFirstBlockPair
expr_stmt|;
comment|/// CachedNonLocalPointerInfo - This map stores the cached results of doing
comment|/// a pointer lookup at the bottom of a block.  The key of this map is the
comment|/// pointer+isload bit, the value is a list of<bb->result> mappings.
typedef|typedef
name|DenseMap
operator|<
name|ValueIsLoadPair
operator|,
name|std
operator|::
name|pair
operator|<
name|BBSkipFirstBlockPair
operator|,
name|NonLocalDepInfo
operator|>
expr|>
name|CachedNonLocalPointerInfo
expr_stmt|;
name|CachedNonLocalPointerInfo
name|NonLocalPointerDeps
decl_stmt|;
comment|// A map from instructions to their non-local pointer dependencies.
typedef|typedef
name|DenseMap
operator|<
name|Instruction
operator|*
operator|,
name|SmallPtrSet
operator|<
name|ValueIsLoadPair
operator|,
literal|4
operator|>
expr|>
name|ReverseNonLocalPtrDepTy
expr_stmt|;
name|ReverseNonLocalPtrDepTy
name|ReverseNonLocalPtrDeps
decl_stmt|;
comment|/// PerInstNLInfo - This is the instruction we keep for each cached access
comment|/// that we have for an instruction.  The pointer is an owning pointer and
comment|/// the bool indicates whether we have any dirty bits in the set.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|NonLocalDepInfo
operator|,
name|bool
operator|>
name|PerInstNLInfo
expr_stmt|;
comment|// A map from instructions to their non-local dependencies.
typedef|typedef
name|DenseMap
operator|<
name|Instruction
operator|*
operator|,
name|PerInstNLInfo
operator|>
name|NonLocalDepMapType
expr_stmt|;
name|NonLocalDepMapType
name|NonLocalDeps
decl_stmt|;
comment|// A reverse mapping from dependencies to the dependees.  This is
comment|// used when removing instructions to keep the cache coherent.
typedef|typedef
name|DenseMap
operator|<
name|Instruction
operator|*
operator|,
name|SmallPtrSet
operator|<
name|Instruction
operator|*
operator|,
literal|4
operator|>
expr|>
name|ReverseDepMapType
expr_stmt|;
name|ReverseDepMapType
name|ReverseLocalDeps
decl_stmt|;
comment|// A reverse mapping form dependencies to the non-local dependees.
name|ReverseDepMapType
name|ReverseNonLocalDeps
decl_stmt|;
comment|/// Current AA implementation, just a cache.
name|AliasAnalysis
modifier|*
name|AA
decl_stmt|;
name|TargetData
modifier|*
name|TD
decl_stmt|;
name|OwningPtr
operator|<
name|PredIteratorCache
operator|>
name|PredCache
expr_stmt|;
name|public
label|:
name|MemoryDependenceAnalysis
argument_list|()
expr_stmt|;
operator|~
name|MemoryDependenceAnalysis
argument_list|()
expr_stmt|;
specifier|static
name|char
name|ID
decl_stmt|;
comment|/// Pass Implementation stuff.  This doesn't do any analysis eagerly.
name|bool
name|runOnFunction
parameter_list|(
name|Function
modifier|&
parameter_list|)
function_decl|;
comment|/// Clean up memory in between runs
name|void
name|releaseMemory
parameter_list|()
function_decl|;
comment|/// getAnalysisUsage - Does not modify anything.  It uses Value Numbering
comment|/// and Alias Analysis.
comment|///
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
name|AU
argument_list|)
decl|const
decl_stmt|;
comment|/// getDependency - Return the instruction on which a memory operation
comment|/// depends.  See the class comment for more details.  It is illegal to call
comment|/// this on non-memory instructions.
name|MemDepResult
name|getDependency
parameter_list|(
name|Instruction
modifier|*
name|QueryInst
parameter_list|)
function_decl|;
comment|/// getNonLocalCallDependency - Perform a full dependency query for the
comment|/// specified call, returning the set of blocks that the value is
comment|/// potentially live across.  The returned set of results will include a
comment|/// "NonLocal" result for all blocks where the value is live across.
comment|///
comment|/// This method assumes the instruction returns a "NonLocal" dependency
comment|/// within its own block.
comment|///
comment|/// This returns a reference to an internal data structure that may be
comment|/// invalidated on the next non-local query or when an instruction is
comment|/// removed.  Clients must copy this data if they want it around longer than
comment|/// that.
specifier|const
name|NonLocalDepInfo
modifier|&
name|getNonLocalCallDependency
parameter_list|(
name|CallSite
name|QueryCS
parameter_list|)
function_decl|;
comment|/// getNonLocalPointerDependency - Perform a full dependency query for an
comment|/// access to the specified (non-volatile) memory location, returning the
comment|/// set of instructions that either define or clobber the value.
comment|///
comment|/// This method assumes the pointer has a "NonLocal" dependency within BB.
name|void
name|getNonLocalPointerDependency
argument_list|(
name|Value
operator|*
name|Pointer
argument_list|,
name|bool
name|isLoad
argument_list|,
name|BasicBlock
operator|*
name|BB
argument_list|,
name|SmallVectorImpl
operator|<
name|NonLocalDepResult
operator|>
operator|&
name|Result
argument_list|)
decl_stmt|;
comment|/// removeInstruction - Remove an instruction from the dependence analysis,
comment|/// updating the dependence of instructions that previously depended on it.
name|void
name|removeInstruction
parameter_list|(
name|Instruction
modifier|*
name|InstToRemove
parameter_list|)
function_decl|;
comment|/// invalidateCachedPointerInfo - This method is used to invalidate cached
comment|/// information about the specified pointer, because it may be too
comment|/// conservative in memdep.  This is an optional call that can be used when
comment|/// the client detects an equivalence between the pointer and some other
comment|/// value and replaces the other value with ptr. This can make Ptr available
comment|/// in more places that cached info does not necessarily keep.
name|void
name|invalidateCachedPointerInfo
parameter_list|(
name|Value
modifier|*
name|Ptr
parameter_list|)
function_decl|;
name|private
label|:
name|MemDepResult
name|getPointerDependencyFrom
argument_list|(
name|Value
operator|*
name|Pointer
argument_list|,
name|uint64_t
name|MemSize
argument_list|,
name|bool
name|isLoad
argument_list|,
name|BasicBlock
operator|::
name|iterator
name|ScanIt
argument_list|,
name|BasicBlock
operator|*
name|BB
argument_list|)
decl_stmt|;
name|MemDepResult
name|getCallSiteDependencyFrom
argument_list|(
name|CallSite
name|C
argument_list|,
name|bool
name|isReadOnlyCall
argument_list|,
name|BasicBlock
operator|::
name|iterator
name|ScanIt
argument_list|,
name|BasicBlock
operator|*
name|BB
argument_list|)
decl_stmt|;
name|bool
name|getNonLocalPointerDepFromBB
argument_list|(
specifier|const
name|PHITransAddr
operator|&
name|Pointer
argument_list|,
name|uint64_t
name|Size
argument_list|,
name|bool
name|isLoad
argument_list|,
name|BasicBlock
operator|*
name|BB
argument_list|,
name|SmallVectorImpl
operator|<
name|NonLocalDepResult
operator|>
operator|&
name|Result
argument_list|,
name|DenseMap
operator|<
name|BasicBlock
operator|*
argument_list|,
name|Value
operator|*
operator|>
operator|&
name|Visited
argument_list|,
name|bool
name|SkipFirstBlock
operator|=
name|false
argument_list|)
decl_stmt|;
name|MemDepResult
name|GetNonLocalInfoForBlock
parameter_list|(
name|Value
modifier|*
name|Pointer
parameter_list|,
name|uint64_t
name|PointeeSize
parameter_list|,
name|bool
name|isLoad
parameter_list|,
name|BasicBlock
modifier|*
name|BB
parameter_list|,
name|NonLocalDepInfo
modifier|*
name|Cache
parameter_list|,
name|unsigned
name|NumSortedEntries
parameter_list|)
function_decl|;
name|void
name|RemoveCachedNonLocalPointerDependencies
parameter_list|(
name|ValueIsLoadPair
name|P
parameter_list|)
function_decl|;
comment|/// verifyRemoved - Verify that the specified instruction does not occur
comment|/// in our internal data structures.
name|void
name|verifyRemoved
argument_list|(
name|Instruction
operator|*
name|Inst
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

