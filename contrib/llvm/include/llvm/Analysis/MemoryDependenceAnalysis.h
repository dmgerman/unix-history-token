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
file|"llvm/ADT/PointerIntPair.h"
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
name|AliasAnalysis
decl_stmt|;
name|class
name|DataLayout
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
comment|///
comment|/// There are several cases that may be interesting here:
comment|///   1. Loads are clobbered by may-alias stores.
comment|///   2. Loads are considered clobbered by partially-aliased loads.  The
comment|///      client may choose to analyze deeper into these cases.
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
comment|/// Other - This marker indicates that the query has no known dependency
comment|/// in the specified block.  More detailed state info is encoded in the
comment|/// upper part of the pair (i.e. the Instruction*)
name|Other
block|}
enum|;
comment|/// If DepType is "Other", the upper part of the pair
comment|/// (i.e. the Instruction* part) is instead used to encode more detailed
comment|/// type information as follows
enum|enum
name|OtherType
block|{
comment|/// NonLocal - This marker indicates that the query has no dependency in
comment|/// the specified block.  To find out more, the client should query other
comment|/// predecessor blocks.
name|NonLocal
init|=
literal|0x4
block|,
comment|/// NonFuncLocal - This marker indicates that the query has no
comment|/// dependency in the specified function.
name|NonFuncLocal
init|=
literal|0x8
block|,
comment|/// Unknown - This marker indicates that the query dependency
comment|/// is unknown.
name|Unknown
init|=
literal|0xc
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
argument|nullptr
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
name|reinterpret_cast
operator|<
name|Instruction
operator|*
operator|>
operator|(
name|NonLocal
operator|)
argument_list|,
name|Other
argument_list|)
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
name|PairTy
argument_list|(
name|reinterpret_cast
operator|<
name|Instruction
operator|*
operator|>
operator|(
name|NonFuncLocal
operator|)
argument_list|,
name|Other
argument_list|)
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
name|PairTy
argument_list|(
name|reinterpret_cast
operator|<
name|Instruction
operator|*
operator|>
operator|(
name|Unknown
operator|)
argument_list|,
name|Other
argument_list|)
argument_list|)
return|;
block|}
comment|/// isClobber - Return true if this MemDepResult represents a query that is
comment|/// an instruction clobber dependency.
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
comment|/// an instruction definition dependency.
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
name|Other
operator|&&
name|Value
operator|.
name|getPointer
argument_list|()
operator|==
name|reinterpret_cast
operator|<
name|Instruction
operator|*
operator|>
operator|(
name|NonLocal
operator|)
return|;
block|}
comment|/// isNonFuncLocal - Return true if this MemDepResult represents a query
comment|/// that is transparent to the start of the function.
name|bool
name|isNonFuncLocal
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|getInt
argument_list|()
operator|==
name|Other
operator|&&
name|Value
operator|.
name|getPointer
argument_list|()
operator|==
name|reinterpret_cast
operator|<
name|Instruction
operator|*
operator|>
operator|(
name|NonFuncLocal
operator|)
return|;
block|}
comment|/// isUnknown - Return true if this MemDepResult represents a query which
comment|/// cannot and/or will not be computed.
name|bool
name|isUnknown
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|getInt
argument_list|()
operator|==
name|Other
operator|&&
name|Value
operator|.
name|getPointer
argument_list|()
operator|==
name|reinterpret_cast
operator|<
name|Instruction
operator|*
operator|>
operator|(
name|Unknown
operator|)
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
if|if
condition|(
name|Value
operator|.
name|getInt
argument_list|()
operator|==
name|Other
condition|)
return|return
name|nullptr
return|;
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// NonLocalDepEntry - This is an entry in the NonLocalDepInfo cache.  For
end_comment

begin_comment
comment|/// each BasicBlock (the BB entry) it keeps a MemDepResult.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// NonLocalDepResult - This is a result from a NonLocal dependence query.
end_comment

begin_comment
comment|/// For each BasicBlock (the BB entry) it keeps a MemDepResult and the
end_comment

begin_comment
comment|/// (potentially phi translated) address that was live in the block.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// MemoryDependenceAnalysis - This is an analysis that determines, for a
end_comment

begin_comment
comment|/// given memory operation, what preceding memory operations it depends on.
end_comment

begin_comment
comment|/// It builds on alias analysis information, and tries to provide a lazy,
end_comment

begin_comment
comment|/// caching interface to a common kind of alias information query.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The dependency information returned is somewhat unusual, but is pragmatic.
end_comment

begin_comment
comment|/// If queried about a store or call that might modify memory, the analysis
end_comment

begin_comment
comment|/// will return the instruction[s] that may either load from that memory or
end_comment

begin_comment
comment|/// store to it.  If queried with a load or call that can never modify memory,
end_comment

begin_comment
comment|/// the analysis will return calls and stores that might modify the pointer,
end_comment

begin_comment
comment|/// but generally does not return loads unless a) they are volatile, or
end_comment

begin_comment
comment|/// b) they load from *must-aliased* pointers.  Returning a dependence on
end_comment

begin_comment
comment|/// must-alias'd pointers instead of all pointers interacts well with the
end_comment

begin_comment
comment|/// internal caching mechanism.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|NonLocalDepEntry
operator|>
name|NonLocalDepInfo
expr_stmt|;
end_typedef

begin_label
name|private
label|:
end_label

begin_comment
comment|/// ValueIsLoadPair - This is a pair<Value*, bool> where the bool is true if
end_comment

begin_comment
comment|/// the dependence is a read only dependence, false if read/write.
end_comment

begin_typedef
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
end_typedef

begin_comment
comment|/// BBSkipFirstBlockPair - This pair is used when caching information for a
end_comment

begin_comment
comment|/// block.  If the pointer is null, the cache value is not a full query that
end_comment

begin_comment
comment|/// starts at the specified block.  If non-null, the bool indicates whether
end_comment

begin_comment
comment|/// or not the contents of the block was skipped.
end_comment

begin_typedef
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
end_typedef

begin_comment
comment|/// NonLocalPointerInfo - This record is the information kept for each
end_comment

begin_comment
comment|/// (value, is load) pair.
end_comment

begin_struct
struct|struct
name|NonLocalPointerInfo
block|{
comment|/// Pair - The pair of the block and the skip-first-block flag.
name|BBSkipFirstBlockPair
name|Pair
decl_stmt|;
comment|/// NonLocalDeps - The results of the query for each relevant block.
name|NonLocalDepInfo
name|NonLocalDeps
decl_stmt|;
comment|/// Size - The maximum size of the dereferences of the
comment|/// pointer. May be UnknownSize if the sizes are unknown.
name|uint64_t
name|Size
decl_stmt|;
comment|/// TBAATag - The TBAA tag associated with dereferences of the
comment|/// pointer. May be null if there are no tags or conflicting tags.
specifier|const
name|MDNode
modifier|*
name|TBAATag
decl_stmt|;
name|NonLocalPointerInfo
argument_list|()
operator|:
name|Size
argument_list|(
name|AliasAnalysis
operator|::
name|UnknownSize
argument_list|)
operator|,
name|TBAATag
argument_list|(
argument|nullptr
argument_list|)
block|{}
block|}
struct|;
end_struct

begin_comment
comment|/// CachedNonLocalPointerInfo - This map stores the cached results of doing
end_comment

begin_comment
comment|/// a pointer lookup at the bottom of a block.  The key of this map is the
end_comment

begin_comment
comment|/// pointer+isload bit, the value is a list of<bb->result> mappings.
end_comment

begin_typedef
typedef|typedef
name|DenseMap
operator|<
name|ValueIsLoadPair
operator|,
name|NonLocalPointerInfo
operator|>
name|CachedNonLocalPointerInfo
expr_stmt|;
end_typedef

begin_decl_stmt
name|CachedNonLocalPointerInfo
name|NonLocalPointerDeps
decl_stmt|;
end_decl_stmt

begin_comment
comment|// A map from instructions to their non-local pointer dependencies.
end_comment

begin_typedef
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
end_typedef

begin_decl_stmt
name|ReverseNonLocalPtrDepTy
name|ReverseNonLocalPtrDeps
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// PerInstNLInfo - This is the instruction we keep for each cached access
end_comment

begin_comment
comment|/// that we have for an instruction.  The pointer is an owning pointer and
end_comment

begin_comment
comment|/// the bool indicates whether we have any dirty bits in the set.
end_comment

begin_typedef
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
end_typedef

begin_comment
comment|// A map from instructions to their non-local dependencies.
end_comment

begin_typedef
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
end_typedef

begin_decl_stmt
name|NonLocalDepMapType
name|NonLocalDeps
decl_stmt|;
end_decl_stmt

begin_comment
comment|// A reverse mapping from dependencies to the dependees.  This is
end_comment

begin_comment
comment|// used when removing instructions to keep the cache coherent.
end_comment

begin_typedef
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
end_typedef

begin_decl_stmt
name|ReverseDepMapType
name|ReverseLocalDeps
decl_stmt|;
end_decl_stmt

begin_comment
comment|// A reverse mapping from dependencies to the non-local dependees.
end_comment

begin_decl_stmt
name|ReverseDepMapType
name|ReverseNonLocalDeps
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Current AA implementation, just a cache.
end_comment

begin_decl_stmt
name|AliasAnalysis
modifier|*
name|AA
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|DataLayout
modifier|*
name|DL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DominatorTree
modifier|*
name|DT
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|PredIteratorCache
operator|>
name|PredCache
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|MemoryDependenceAnalysis
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|~
name|MemoryDependenceAnalysis
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|char
name|ID
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Pass Implementation stuff.  This doesn't do any analysis eagerly.
end_comment

begin_decl_stmt
name|bool
name|runOnFunction
argument_list|(
name|Function
operator|&
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Clean up memory in between runs
end_comment

begin_expr_stmt
name|void
name|releaseMemory
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getAnalysisUsage - Does not modify anything.  It uses Value Numbering
end_comment

begin_comment
comment|/// and Alias Analysis.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|void
name|getAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
name|AU
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getDependency - Return the instruction on which a memory operation
end_comment

begin_comment
comment|/// depends.  See the class comment for more details.  It is illegal to call
end_comment

begin_comment
comment|/// this on non-memory instructions.
end_comment

begin_function_decl
name|MemDepResult
name|getDependency
parameter_list|(
name|Instruction
modifier|*
name|QueryInst
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getNonLocalCallDependency - Perform a full dependency query for the
end_comment

begin_comment
comment|/// specified call, returning the set of blocks that the value is
end_comment

begin_comment
comment|/// potentially live across.  The returned set of results will include a
end_comment

begin_comment
comment|/// "NonLocal" result for all blocks where the value is live across.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This method assumes the instruction returns a "NonLocal" dependency
end_comment

begin_comment
comment|/// within its own block.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This returns a reference to an internal data structure that may be
end_comment

begin_comment
comment|/// invalidated on the next non-local query or when an instruction is
end_comment

begin_comment
comment|/// removed.  Clients must copy this data if they want it around longer than
end_comment

begin_comment
comment|/// that.
end_comment

begin_function_decl
specifier|const
name|NonLocalDepInfo
modifier|&
name|getNonLocalCallDependency
parameter_list|(
name|CallSite
name|QueryCS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getNonLocalPointerDependency - Perform a full dependency query for an
end_comment

begin_comment
comment|/// access to the specified (non-volatile) memory location, returning the
end_comment

begin_comment
comment|/// set of instructions that either define or clobber the value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This method assumes the pointer has a "NonLocal" dependency within BB.
end_comment

begin_decl_stmt
name|void
name|getNonLocalPointerDependency
argument_list|(
specifier|const
name|AliasAnalysis
operator|::
name|Location
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
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// removeInstruction - Remove an instruction from the dependence analysis,
end_comment

begin_comment
comment|/// updating the dependence of instructions that previously depended on it.
end_comment

begin_function_decl
name|void
name|removeInstruction
parameter_list|(
name|Instruction
modifier|*
name|InstToRemove
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// invalidateCachedPointerInfo - This method is used to invalidate cached
end_comment

begin_comment
comment|/// information about the specified pointer, because it may be too
end_comment

begin_comment
comment|/// conservative in memdep.  This is an optional call that can be used when
end_comment

begin_comment
comment|/// the client detects an equivalence between the pointer and some other
end_comment

begin_comment
comment|/// value and replaces the other value with ptr. This can make Ptr available
end_comment

begin_comment
comment|/// in more places that cached info does not necessarily keep.
end_comment

begin_function_decl
name|void
name|invalidateCachedPointerInfo
parameter_list|(
name|Value
modifier|*
name|Ptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// invalidateCachedPredecessors - Clear the PredIteratorCache info.
end_comment

begin_comment
comment|/// This needs to be done when the CFG changes, e.g., due to splitting
end_comment

begin_comment
comment|/// critical edges.
end_comment

begin_function_decl
name|void
name|invalidateCachedPredecessors
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// getPointerDependencyFrom - Return the instruction on which a memory
end_comment

begin_comment
comment|/// location depends.  If isLoad is true, this routine ignores may-aliases
end_comment

begin_comment
comment|/// with read-only operations.  If isLoad is false, this routine ignores
end_comment

begin_comment
comment|/// may-aliases with reads from read-only locations. If possible, pass
end_comment

begin_comment
comment|/// the query instruction as well; this function may take advantage of
end_comment

begin_comment
comment|/// the metadata annotated to the query instruction to refine the result.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that this is an uncached query, and thus may be inefficient.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|MemDepResult
name|getPointerDependencyFrom
argument_list|(
specifier|const
name|AliasAnalysis
operator|::
name|Location
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
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getLoadLoadClobberFullWidthSize - This is a little bit of analysis that
end_comment

begin_comment
comment|/// looks at a memory location for a load (specified by MemLocBase, Offs,
end_comment

begin_comment
comment|/// and Size) and compares it against a load.  If the specified load could
end_comment

begin_comment
comment|/// be safely widened to a larger integer load that is 1) still efficient,
end_comment

begin_comment
comment|/// 2) safe for the target, and 3) would provide the specified memory
end_comment

begin_comment
comment|/// location value, then this function returns the size in bytes of the
end_comment

begin_comment
comment|/// load width to use.  If not, this returns zero.
end_comment

begin_function_decl
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
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
name|bool
name|getNonLocalPointerDepFromBB
argument_list|(
specifier|const
name|PHITransAddr
operator|&
name|Pointer
argument_list|,
specifier|const
name|AliasAnalysis
operator|::
name|Location
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
end_decl_stmt

begin_decl_stmt
name|MemDepResult
name|GetNonLocalInfoForBlock
argument_list|(
specifier|const
name|AliasAnalysis
operator|::
name|Location
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
name|NonLocalDepInfo
operator|*
name|Cache
argument_list|,
name|unsigned
name|NumSortedEntries
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|RemoveCachedNonLocalPointerDependencies
parameter_list|(
name|ValueIsLoadPair
name|P
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// verifyRemoved - Verify that the specified instruction does not occur
end_comment

begin_comment
comment|/// in our internal data structures.
end_comment

begin_decl_stmt
name|void
name|verifyRemoved
argument_list|(
name|Instruction
operator|*
name|Inst
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
unit|};  }
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

