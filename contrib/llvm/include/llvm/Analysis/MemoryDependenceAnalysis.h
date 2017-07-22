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
name|LLVM_ANALYSIS_MEMORYDEPENDENCEANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_MEMORYDEPENDENCEANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerEmbeddedInt.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerSumType.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/AliasAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/BasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PredIteratorCache.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueHandle.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
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
name|AssumptionCache
decl_stmt|;
name|class
name|MemoryDependenceResults
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
comment|/// A memory dependence query can return one of three different answers.
name|class
name|MemDepResult
block|{
enum|enum
name|DepType
block|{
comment|/// Clients of MemDep never see this.
comment|///
comment|/// Entries with this marker occur in a LocalDeps map or NonLocalDeps map
comment|/// when the instruction they previously referenced was removed from
comment|/// MemDep.  In either case, the entry may include an instruction pointer.
comment|/// If so, the pointer is an instruction in the block where scanning can
comment|/// start from, saving some work.
comment|///
comment|/// In a default-constructed MemDepResult object, the type will be Invalid
comment|/// and the instruction pointer will be null.
name|Invalid
init|=
literal|0
block|,
comment|/// This is a dependence on the specified instruction which clobbers the
comment|/// desired value.  The pointer member of the MemDepResult pair holds the
comment|/// instruction that clobbers the memory.  For example, this occurs when we
comment|/// see a may-aliased store to the memory location we care about.
comment|///
comment|/// There are several cases that may be interesting here:
comment|///   1. Loads are clobbered by may-alias stores.
comment|///   2. Loads are considered clobbered by partially-aliased loads.  The
comment|///      client may choose to analyze deeper into these cases.
name|Clobber
block|,
comment|/// This is a dependence on the specified instruction which defines or
comment|/// produces the desired memory location.  The pointer member of the
comment|/// MemDepResult pair holds the instruction that defines the memory.
comment|///
comment|/// Cases of interest:
comment|///   1. This could be a load or store for dependence queries on
comment|///      load/store.  The value loaded or stored is the produced value.
comment|///      Note that the pointer operand may be different than that of the
comment|///      queried pointer due to must aliases and phi translation. Note
comment|///      that the def may not be the same type as the query, the pointers
comment|///      may just be must aliases.
comment|///   2. For loads and stores, this could be an allocation instruction. In
comment|///      this case, the load is loading an undef value or a store is the
comment|///      first store to (that part of) the allocation.
comment|///   3. Dependence queries on calls return Def only when they are readonly
comment|///      calls or memory use intrinsics with identical callees and no
comment|///      intervening clobbers.  No validation is done that the operands to
comment|///      the calls are the same.
name|Def
block|,
comment|/// This marker indicates that the query has no known dependency in the
comment|/// specified block.
comment|///
comment|/// More detailed state info is encoded in the upper part of the pair (i.e.
comment|/// the Instruction*)
name|Other
block|}
enum|;
comment|/// If DepType is "Other", the upper part of the sum type is an encoding of
comment|/// the following more detailed type information.
enum|enum
name|OtherType
block|{
comment|/// This marker indicates that the query has no dependency in the specified
comment|/// block.
comment|///
comment|/// To find out more, the client should query other predecessor blocks.
name|NonLocal
init|=
literal|1
block|,
comment|/// This marker indicates that the query has no dependency in the specified
comment|/// function.
name|NonFuncLocal
block|,
comment|/// This marker indicates that the query dependency is unknown.
name|Unknown
block|}
enum|;
typedef|typedef
name|PointerSumType
operator|<
name|DepType
operator|,
name|PointerSumTypeMember
operator|<
name|Invalid
operator|,
name|Instruction
operator|*
operator|>
operator|,
name|PointerSumTypeMember
operator|<
name|Clobber
operator|,
name|Instruction
operator|*
operator|>
operator|,
name|PointerSumTypeMember
operator|<
name|Def
operator|,
name|Instruction
operator|*
operator|>
operator|,
name|PointerSumTypeMember
operator|<
name|Other
operator|,
name|PointerEmbeddedInt
operator|<
name|OtherType
operator|,
literal|3
operator|>>>
name|ValueTy
expr_stmt|;
name|ValueTy
name|Value
decl_stmt|;
name|explicit
name|MemDepResult
argument_list|(
argument|ValueTy V
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
argument_list|()
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
name|assert
argument_list|(
name|Inst
operator|&&
literal|"Def requires inst"
argument_list|)
block|;
return|return
name|MemDepResult
argument_list|(
name|ValueTy
operator|::
name|create
operator|<
name|Def
operator|>
operator|(
name|Inst
operator|)
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
name|assert
argument_list|(
name|Inst
operator|&&
literal|"Clobber requires inst"
argument_list|)
expr_stmt|;
return|return
name|MemDepResult
argument_list|(
name|ValueTy
operator|::
name|create
operator|<
name|Clobber
operator|>
operator|(
name|Inst
operator|)
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
name|ValueTy
operator|::
name|create
operator|<
name|Other
operator|>
operator|(
name|NonLocal
operator|)
argument_list|)
return|;
block|}
specifier|static
name|MemDepResult
name|getNonFuncLocal
parameter_list|()
block|{
return|return
name|MemDepResult
argument_list|(
name|ValueTy
operator|::
name|create
operator|<
name|Other
operator|>
operator|(
name|NonFuncLocal
operator|)
argument_list|)
return|;
block|}
specifier|static
name|MemDepResult
name|getUnknown
parameter_list|()
block|{
return|return
name|MemDepResult
argument_list|(
name|ValueTy
operator|::
name|create
operator|<
name|Other
operator|>
operator|(
name|Unknown
operator|)
argument_list|)
return|;
block|}
comment|/// Tests if this MemDepResult represents a query that is an instruction
comment|/// clobber dependency.
name|bool
name|isClobber
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|is
operator|<
name|Clobber
operator|>
operator|(
operator|)
return|;
block|}
comment|/// Tests if this MemDepResult represents a query that is an instruction
comment|/// definition dependency.
name|bool
name|isDef
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|is
operator|<
name|Def
operator|>
operator|(
operator|)
return|;
block|}
comment|/// Tests if this MemDepResult represents a query that is transparent to the
comment|/// start of the block, but where a non-local hasn't been done.
name|bool
name|isNonLocal
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|is
operator|<
name|Other
operator|>
operator|(
operator|)
operator|&&
name|Value
operator|.
name|cast
operator|<
name|Other
operator|>
operator|(
operator|)
operator|==
name|NonLocal
return|;
block|}
comment|/// Tests if this MemDepResult represents a query that is transparent to the
comment|/// start of the function.
name|bool
name|isNonFuncLocal
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|is
operator|<
name|Other
operator|>
operator|(
operator|)
operator|&&
name|Value
operator|.
name|cast
operator|<
name|Other
operator|>
operator|(
operator|)
operator|==
name|NonFuncLocal
return|;
block|}
comment|/// Tests if this MemDepResult represents a query which cannot and/or will
comment|/// not be computed.
name|bool
name|isUnknown
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|is
operator|<
name|Other
operator|>
operator|(
operator|)
operator|&&
name|Value
operator|.
name|cast
operator|<
name|Other
operator|>
operator|(
operator|)
operator|==
name|Unknown
return|;
block|}
comment|/// If this is a normal dependency, returns the instruction that is depended
comment|/// on.  Otherwise, returns null.
name|Instruction
operator|*
name|getInst
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|Value
operator|.
name|getTag
argument_list|()
condition|)
block|{
case|case
name|Invalid
case|:
return|return
name|Value
operator|.
name|cast
operator|<
name|Invalid
operator|>
operator|(
operator|)
return|;
case|case
name|Clobber
case|:
return|return
name|Value
operator|.
name|cast
operator|<
name|Clobber
operator|>
operator|(
operator|)
return|;
case|case
name|Def
case|:
return|return
name|Value
operator|.
name|cast
operator|<
name|Def
operator|>
operator|(
operator|)
return|;
case|case
name|Other
case|:
return|return
name|nullptr
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"Unknown discriminant!"
argument_list|)
expr_stmt|;
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
name|MemoryDependenceResults
decl_stmt|;
comment|/// Tests if this is a MemDepResult in its dirty/invalid. state.
name|bool
name|isDirty
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|is
operator|<
name|Invalid
operator|>
operator|(
operator|)
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
name|ValueTy
operator|::
name|create
operator|<
name|Invalid
operator|>
operator|(
name|Inst
operator|)
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|/// This is an entry in the NonLocalDepInfo cache.
comment|///
comment|/// For each BasicBlock (the BB entry) it keeps a MemDepResult.
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
comment|/// This is a result from a NonLocal dependence query.
comment|///
comment|/// For each BasicBlock (the BB entry) it keeps a MemDepResult and the
comment|/// (potentially phi translated) address that was live in the block.
name|class
name|NonLocalDepResult
block|{
name|NonLocalDepEntry
name|Entry
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
name|Entry
argument_list|(
name|bb
argument_list|,
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
name|Entry
operator|.
name|getBB
argument_list|()
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
name|Entry
operator|.
name|setResult
argument_list|(
name|R
argument_list|)
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
name|Entry
operator|.
name|getResult
argument_list|()
return|;
block|}
comment|/// Returns the address of this pointer in this block.
comment|///
comment|/// This can be different than the address queried for the non-local result
comment|/// because of phi translation.  This returns null if the address was not
comment|/// available in a block (i.e. because phi translation failed) or if this is
comment|/// a cached result and that address was deleted.
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
comment|/// Provides a lazy, caching interface for making common memory aliasing
comment|/// information queries, backed by LLVM's alias analysis passes.
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
name|class
name|MemoryDependenceResults
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
comment|/// A pair<Value*, bool> where the bool is true if the dependence is a read
comment|/// only dependence, false if read/write.
typedef|typedef
name|PointerIntPair
operator|<
specifier|const
name|Value
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|ValueIsLoadPair
expr_stmt|;
comment|/// This pair is used when caching information for a block.
comment|///
comment|/// If the pointer is null, the cache value is not a full query that starts
comment|/// at the specified block.  If non-null, the bool indicates whether or not
comment|/// the contents of the block was skipped.
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
comment|/// This record is the information kept for each (value, is load) pair.
struct|struct
name|NonLocalPointerInfo
block|{
comment|/// The pair of the block and the skip-first-block flag.
name|BBSkipFirstBlockPair
name|Pair
decl_stmt|;
comment|/// The results of the query for each relevant block.
name|NonLocalDepInfo
name|NonLocalDeps
decl_stmt|;
comment|/// The maximum size of the dereferences of the pointer.
comment|///
comment|/// May be UnknownSize if the sizes are unknown.
name|uint64_t
name|Size
decl_stmt|;
comment|/// The AA tags associated with dereferences of the pointer.
comment|///
comment|/// The members may be null if there are no tags or conflicting tags.
name|AAMDNodes
name|AATags
decl_stmt|;
name|NonLocalPointerInfo
argument_list|()
operator|:
name|Size
argument_list|(
argument|MemoryLocation::UnknownSize
argument_list|)
block|{}
block|}
struct|;
comment|/// Cache storing single nonlocal def for the instruction.
comment|/// It is set when nonlocal def would be found in function returning only
comment|/// local dependencies.
name|DenseMap
operator|<
name|Instruction
operator|*
operator|,
name|NonLocalDepResult
operator|>
name|NonLocalDefsCache
expr_stmt|;
comment|/// This map stores the cached results of doing a pointer lookup at the
comment|/// bottom of a block.
comment|///
comment|/// The key of this map is the pointer+isload bit, the value is a list of
comment|///<bb->result> mappings.
typedef|typedef
name|DenseMap
operator|<
name|ValueIsLoadPair
operator|,
name|NonLocalPointerInfo
operator|>
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
operator|>>
name|ReverseNonLocalPtrDepTy
expr_stmt|;
name|ReverseNonLocalPtrDepTy
name|ReverseNonLocalPtrDeps
decl_stmt|;
comment|/// This is the instruction we keep for each cached access that we have for
comment|/// an instruction.
comment|///
comment|/// The pointer is an owning pointer and the bool indicates whether we have
comment|/// any dirty bits in the set.
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
operator|>>
name|ReverseDepMapType
expr_stmt|;
name|ReverseDepMapType
name|ReverseLocalDeps
decl_stmt|;
comment|// A reverse mapping from dependencies to the non-local dependees.
name|ReverseDepMapType
name|ReverseNonLocalDeps
decl_stmt|;
comment|/// Current AA implementation, just a cache.
name|AliasAnalysis
modifier|&
name|AA
decl_stmt|;
name|AssumptionCache
modifier|&
name|AC
decl_stmt|;
specifier|const
name|TargetLibraryInfo
modifier|&
name|TLI
decl_stmt|;
name|DominatorTree
modifier|&
name|DT
decl_stmt|;
name|PredIteratorCache
name|PredCache
decl_stmt|;
name|public
label|:
name|MemoryDependenceResults
argument_list|(
name|AliasAnalysis
operator|&
name|AA
argument_list|,
name|AssumptionCache
operator|&
name|AC
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|&
name|TLI
argument_list|,
name|DominatorTree
operator|&
name|DT
argument_list|)
operator|:
name|AA
argument_list|(
name|AA
argument_list|)
operator|,
name|AC
argument_list|(
name|AC
argument_list|)
operator|,
name|TLI
argument_list|(
name|TLI
argument_list|)
operator|,
name|DT
argument_list|(
argument|DT
argument_list|)
block|{}
comment|/// Handle invalidation in the new PM.
name|bool
name|invalidate
argument_list|(
name|Function
operator|&
name|F
argument_list|,
specifier|const
name|PreservedAnalyses
operator|&
name|PA
argument_list|,
name|FunctionAnalysisManager
operator|::
name|Invalidator
operator|&
name|Inv
argument_list|)
expr_stmt|;
comment|/// Some methods limit the number of instructions they will examine.
comment|/// The return value of this method is the default limit that will be
comment|/// used if no limit is explicitly passed in.
name|unsigned
name|getDefaultBlockScanLimit
argument_list|()
specifier|const
expr_stmt|;
comment|/// Returns the instruction on which a memory operation depends.
comment|///
comment|/// See the class comment for more details. It is illegal to call this on
comment|/// non-memory instructions.
name|MemDepResult
name|getDependency
parameter_list|(
name|Instruction
modifier|*
name|QueryInst
parameter_list|)
function_decl|;
comment|/// Perform a full dependency query for the specified call, returning the set
comment|/// of blocks that the value is potentially live across.
comment|///
comment|/// The returned set of results will include a "NonLocal" result for all
comment|/// blocks where the value is live across.
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
comment|/// Perform a full dependency query for an access to the QueryInst's
comment|/// specified memory location, returning the set of instructions that either
comment|/// define or clobber the value.
comment|///
comment|/// Warning: For a volatile query instruction, the dependencies will be
comment|/// accurate, and thus usable for reordering, but it is never legal to
comment|/// remove the query instruction.
comment|///
comment|/// This method assumes the pointer has a "NonLocal" dependency within
comment|/// QueryInst's parent basic block.
name|void
name|getNonLocalPointerDependency
argument_list|(
name|Instruction
operator|*
name|QueryInst
argument_list|,
name|SmallVectorImpl
operator|<
name|NonLocalDepResult
operator|>
operator|&
name|Result
argument_list|)
decl_stmt|;
comment|/// Removes an instruction from the dependence analysis, updating the
comment|/// dependence of instructions that previously depended on it.
name|void
name|removeInstruction
parameter_list|(
name|Instruction
modifier|*
name|InstToRemove
parameter_list|)
function_decl|;
comment|/// Invalidates cached information about the specified pointer, because it
comment|/// may be too conservative in memdep.
comment|///
comment|/// This is an optional call that can be used when the client detects an
comment|/// equivalence between the pointer and some other value and replaces the
comment|/// other value with ptr. This can make Ptr available in more places that
comment|/// cached info does not necessarily keep.
name|void
name|invalidateCachedPointerInfo
parameter_list|(
name|Value
modifier|*
name|Ptr
parameter_list|)
function_decl|;
comment|/// Clears the PredIteratorCache info.
comment|///
comment|/// This needs to be done when the CFG changes, e.g., due to splitting
comment|/// critical edges.
name|void
name|invalidateCachedPredecessors
parameter_list|()
function_decl|;
comment|/// Returns the instruction on which a memory location depends.
comment|///
comment|/// If isLoad is true, this routine ignores may-aliases with read-only
comment|/// operations.  If isLoad is false, this routine ignores may-aliases
comment|/// with reads from read-only locations. If possible, pass the query
comment|/// instruction as well; this function may take advantage of the metadata
comment|/// annotated to the query instruction to refine the result. \p Limit
comment|/// can be used to set the maximum number of instructions that will be
comment|/// examined to find the pointer dependency. On return, it will be set to
comment|/// the number of instructions left to examine. If a null pointer is passed
comment|/// in, the limit will default to the value of -memdep-block-scan-limit.
comment|///
comment|/// Note that this is an uncached query, and thus may be inefficient.
name|MemDepResult
name|getPointerDependencyFrom
argument_list|(
specifier|const
name|MemoryLocation
operator|&
name|Loc
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
argument_list|,
name|Instruction
operator|*
name|QueryInst
operator|=
name|nullptr
argument_list|,
name|unsigned
operator|*
name|Limit
operator|=
name|nullptr
argument_list|)
decl_stmt|;
name|MemDepResult
name|getSimplePointerDependencyFrom
argument_list|(
specifier|const
name|MemoryLocation
operator|&
name|MemLoc
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
argument_list|,
name|Instruction
operator|*
name|QueryInst
argument_list|,
name|unsigned
operator|*
name|Limit
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|/// This analysis looks for other loads and stores with invariant.group
comment|/// metadata and the same pointer operand. Returns Unknown if it does not
comment|/// find anything, and Def if it can be assumed that 2 instructions load or
comment|/// store the same value and NonLocal which indicate that non-local Def was
comment|/// found, which can be retrieved by calling getNonLocalPointerDependency
comment|/// with the same queried instruction.
name|MemDepResult
name|getInvariantGroupPointerDependency
parameter_list|(
name|LoadInst
modifier|*
name|LI
parameter_list|,
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|/// Looks at a memory location for a load (specified by MemLocBase, Offs, and
comment|/// Size) and compares it against a load.
comment|///
comment|/// If the specified load could be safely widened to a larger integer load
comment|/// that is 1) still efficient, 2) safe for the target, and 3) would provide
comment|/// the specified memory location value, then this function returns the size
comment|/// in bytes of the load width to use.  If not, this returns zero.
specifier|static
name|unsigned
name|getLoadLoadClobberFullWidthSize
parameter_list|(
specifier|const
name|Value
modifier|*
name|MemLocBase
parameter_list|,
name|int64_t
name|MemLocOffs
parameter_list|,
name|unsigned
name|MemLocSize
parameter_list|,
specifier|const
name|LoadInst
modifier|*
name|LI
parameter_list|)
function_decl|;
comment|/// Release memory in caches.
name|void
name|releaseMemory
parameter_list|()
function_decl|;
name|private
label|:
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
name|Instruction
operator|*
name|QueryInst
argument_list|,
specifier|const
name|PHITransAddr
operator|&
name|Pointer
argument_list|,
specifier|const
name|MemoryLocation
operator|&
name|Loc
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
name|Instruction
modifier|*
name|QueryInst
parameter_list|,
specifier|const
name|MemoryLocation
modifier|&
name|Loc
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
empty_stmt|;
comment|/// An analysis that produces \c MemoryDependenceResults for a function.
comment|///
comment|/// This is essentially a no-op because the results are computed entirely
comment|/// lazily.
name|class
name|MemoryDependenceAnalysis
range|:
name|public
name|AnalysisInfoMixin
operator|<
name|MemoryDependenceAnalysis
operator|>
block|{
name|friend
name|AnalysisInfoMixin
operator|<
name|MemoryDependenceAnalysis
operator|>
block|;
specifier|static
name|AnalysisKey
name|Key
block|;
name|public
operator|:
typedef|typedef
name|MemoryDependenceResults
name|Result
typedef|;
name|MemoryDependenceResults
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
name|AM
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// A wrapper analysis pass for the legacy pass manager that exposes a \c
end_comment

begin_comment
comment|/// MemoryDepnedenceResults instance.
end_comment

begin_decl_stmt
name|class
name|MemoryDependenceWrapperPass
range|:
name|public
name|FunctionPass
block|{
name|Optional
operator|<
name|MemoryDependenceResults
operator|>
name|MemDep
block|;
name|public
operator|:
name|MemoryDependenceWrapperPass
argument_list|()
block|;
operator|~
name|MemoryDependenceWrapperPass
argument_list|()
name|override
block|;
specifier|static
name|char
name|ID
block|;
comment|/// Pass Implementation stuff.  This doesn't do any analysis eagerly.
name|bool
name|runOnFunction
argument_list|(
argument|Function&
argument_list|)
name|override
block|;
comment|/// Clean up memory in between runs
name|void
name|releaseMemory
argument_list|()
name|override
block|;
comment|/// Does not modify anything.  It uses Value Numbering and Alias Analysis.
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|;
name|MemoryDependenceResults
operator|&
name|getMemDep
argument_list|()
block|{
return|return
operator|*
name|MemDep
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

