begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/AliasAnalysis.h - Alias Analysis Interface -*- C++ -*-===//
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
comment|// This file defines the generic AliasAnalysis interface, which is used as the
end_comment

begin_comment
comment|// common interface used by all clients of alias analysis information, and
end_comment

begin_comment
comment|// implemented by all alias analysis implementations.  Mod/Ref information is
end_comment

begin_comment
comment|// also captured by this interface.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Implementations of this interface must implement the various virtual methods,
end_comment

begin_comment
comment|// which automatically provides functionality for the entire suite of client
end_comment

begin_comment
comment|// APIs.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This API identifies memory regions with the MemoryLocation class. The pointer
end_comment

begin_comment
comment|// component specifies the base memory address of the region. The Size specifies
end_comment

begin_comment
comment|// the maximum size (in address units) of the memory region, or
end_comment

begin_comment
comment|// MemoryLocation::UnknownSize if the size is not known. The TBAA tag
end_comment

begin_comment
comment|// identifies the "type" of the memory reference; see the
end_comment

begin_comment
comment|// TypeBasedAliasAnalysis class for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Some non-obvious details include:
end_comment

begin_comment
comment|//  - Pointers that point to two completely different objects in memory never
end_comment

begin_comment
comment|//    alias, regardless of the value of the Size component.
end_comment

begin_comment
comment|//  - NoAlias doesn't imply inequal pointers. The most obvious example of this
end_comment

begin_comment
comment|//    is two pointers to constant memory. Even if they are equal, constant
end_comment

begin_comment
comment|//    memory is never stored to, so there will never be any dependencies.
end_comment

begin_comment
comment|//    In this and other situations, the pointers may be both NoAlias and
end_comment

begin_comment
comment|//    MustAlias at the same time. The current API can only return one result,
end_comment

begin_comment
comment|//    though this is rarely a problem in practice.
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
name|LLVM_ANALYSIS_ALIASANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_ALIASANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/CallSite.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Metadata.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/MemoryLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/TargetLibraryInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BasicAAResult
decl_stmt|;
name|class
name|LoadInst
decl_stmt|;
name|class
name|StoreInst
decl_stmt|;
name|class
name|VAArgInst
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|Pass
decl_stmt|;
name|class
name|AnalysisUsage
decl_stmt|;
name|class
name|MemTransferInst
decl_stmt|;
name|class
name|MemIntrinsic
decl_stmt|;
name|class
name|DominatorTree
decl_stmt|;
name|class
name|OrderedBasicBlock
decl_stmt|;
comment|/// The possible results of an alias query.
comment|///
comment|/// These results are always computed between two MemoryLocation objects as
comment|/// a query to some alias analysis.
comment|///
comment|/// Note that these are unscoped enumerations because we would like to support
comment|/// implicitly testing a result for the existence of any possible aliasing with
comment|/// a conversion to bool, but an "enum class" doesn't support this. The
comment|/// canonical names from the literature are suffixed and unique anyways, and so
comment|/// they serve as global constants in LLVM for these results.
comment|///
comment|/// See docs/AliasAnalysis.html for more information on the specific meanings
comment|/// of these values.
enum|enum
name|AliasResult
block|{
comment|/// The two locations do not alias at all.
comment|///
comment|/// This value is arranged to convert to false, while all other values
comment|/// convert to true. This allows a boolean context to convert the result to
comment|/// a binary flag indicating whether there is the possibility of aliasing.
name|NoAlias
init|=
literal|0
block|,
comment|/// The two locations may or may not alias. This is the least precise result.
name|MayAlias
block|,
comment|/// The two locations alias, but only due to a partial overlap.
name|PartialAlias
block|,
comment|/// The two locations precisely alias each other.
name|MustAlias
block|, }
enum|;
comment|/// Flags indicating whether a memory access modifies or references memory.
comment|///
comment|/// This is no access at all, a modification, a reference, or both
comment|/// a modification and a reference. These are specifically structured such that
comment|/// they form a two bit matrix and bit-tests for 'mod' or 'ref' work with any
comment|/// of the possible values.
enum|enum
name|ModRefInfo
block|{
comment|/// The access neither references nor modifies the value stored in memory.
name|MRI_NoModRef
init|=
literal|0
block|,
comment|/// The access references the value stored in memory.
name|MRI_Ref
init|=
literal|1
block|,
comment|/// The access modifies the value stored in memory.
name|MRI_Mod
init|=
literal|2
block|,
comment|/// The access both references and modifies the value stored in memory.
name|MRI_ModRef
init|=
name|MRI_Ref
operator||
name|MRI_Mod
block|}
enum|;
comment|/// The locations at which a function might access memory.
comment|///
comment|/// These are primarily used in conjunction with the \c AccessKind bits to
comment|/// describe both the nature of access and the locations of access for a
comment|/// function call.
enum|enum
name|FunctionModRefLocation
block|{
comment|/// Base case is no access to memory.
name|FMRL_Nowhere
init|=
literal|0
block|,
comment|/// Access to memory via argument pointers.
name|FMRL_ArgumentPointees
init|=
literal|4
block|,
comment|/// Memory that is inaccessible via LLVM IR.
name|FMRL_InaccessibleMem
init|=
literal|8
block|,
comment|/// Access to any memory.
name|FMRL_Anywhere
init|=
literal|16
operator||
name|FMRL_InaccessibleMem
operator||
name|FMRL_ArgumentPointees
block|}
enum|;
comment|/// Summary of how a function affects memory in the program.
comment|///
comment|/// Loads from constant globals are not considered memory accesses for this
comment|/// interface. Also, functions may freely modify stack space local to their
comment|/// invocation without having to report it through these interfaces.
enum|enum
name|FunctionModRefBehavior
block|{
comment|/// This function does not perform any non-local loads or stores to memory.
comment|///
comment|/// This property corresponds to the GCC 'const' attribute.
comment|/// This property corresponds to the LLVM IR 'readnone' attribute.
comment|/// This property corresponds to the IntrNoMem LLVM intrinsic flag.
name|FMRB_DoesNotAccessMemory
init|=
name|FMRL_Nowhere
operator||
name|MRI_NoModRef
block|,
comment|/// The only memory references in this function (if it has any) are
comment|/// non-volatile loads from objects pointed to by its pointer-typed
comment|/// arguments, with arbitrary offsets.
comment|///
comment|/// This property corresponds to the IntrReadArgMem LLVM intrinsic flag.
name|FMRB_OnlyReadsArgumentPointees
init|=
name|FMRL_ArgumentPointees
operator||
name|MRI_Ref
block|,
comment|/// The only memory references in this function (if it has any) are
comment|/// non-volatile loads and stores from objects pointed to by its
comment|/// pointer-typed arguments, with arbitrary offsets.
comment|///
comment|/// This property corresponds to the IntrArgMemOnly LLVM intrinsic flag.
name|FMRB_OnlyAccessesArgumentPointees
init|=
name|FMRL_ArgumentPointees
operator||
name|MRI_ModRef
block|,
comment|/// The only memory references in this function (if it has any) are
comment|/// references of memory that is otherwise inaccessible via LLVM IR.
comment|///
comment|/// This property corresponds to the LLVM IR inaccessiblememonly attribute.
name|FMRB_OnlyAccessesInaccessibleMem
init|=
name|FMRL_InaccessibleMem
operator||
name|MRI_ModRef
block|,
comment|/// The function may perform non-volatile loads and stores of objects
comment|/// pointed to by its pointer-typed arguments, with arbitrary offsets, and
comment|/// it may also perform loads and stores of memory that is otherwise
comment|/// inaccessible via LLVM IR.
comment|///
comment|/// This property corresponds to the LLVM IR
comment|/// inaccessiblemem_or_argmemonly attribute.
name|FMRB_OnlyAccessesInaccessibleOrArgMem
init|=
name|FMRL_InaccessibleMem
operator||
name|FMRL_ArgumentPointees
operator||
name|MRI_ModRef
block|,
comment|/// This function does not perform any non-local stores or volatile loads,
comment|/// but may read from any memory location.
comment|///
comment|/// This property corresponds to the GCC 'pure' attribute.
comment|/// This property corresponds to the LLVM IR 'readonly' attribute.
comment|/// This property corresponds to the IntrReadMem LLVM intrinsic flag.
name|FMRB_OnlyReadsMemory
init|=
name|FMRL_Anywhere
operator||
name|MRI_Ref
block|,
comment|// This function does not read from memory anywhere, but may write to any
comment|// memory location.
comment|//
comment|// This property corresponds to the LLVM IR 'writeonly' attribute.
comment|// This property corresponds to the IntrWriteMem LLVM intrinsic flag.
name|FMRB_DoesNotReadMemory
init|=
name|FMRL_Anywhere
operator||
name|MRI_Mod
block|,
comment|/// This indicates that the function could not be classified into one of the
comment|/// behaviors above.
name|FMRB_UnknownModRefBehavior
init|=
name|FMRL_Anywhere
operator||
name|MRI_ModRef
block|}
enum|;
name|class
name|AAResults
block|{
name|public
label|:
comment|// Make these results default constructable and movable. We have to spell
comment|// these out because MSVC won't synthesize them.
name|AAResults
argument_list|(
specifier|const
name|TargetLibraryInfo
operator|&
name|TLI
argument_list|)
operator|:
name|TLI
argument_list|(
argument|TLI
argument_list|)
block|{}
name|AAResults
argument_list|(
name|AAResults
operator|&&
name|Arg
argument_list|)
expr_stmt|;
operator|~
name|AAResults
argument_list|()
expr_stmt|;
comment|/// Register a specific AA result.
name|template
operator|<
name|typename
name|AAResultT
operator|>
name|void
name|addAAResult
argument_list|(
argument|AAResultT&AAResult
argument_list|)
block|{
comment|// FIXME: We should use a much lighter weight system than the usual
comment|// polymorphic pattern because we don't own AAResult. It should
comment|// ideally involve two pointers and no separate allocation.
name|AAs
operator|.
name|emplace_back
argument_list|(
argument|new Model<AAResultT>(AAResult, *this)
argument_list|)
block|;   }
comment|/// Register a function analysis ID that the results aggregation depends on.
comment|///
comment|/// This is used in the new pass manager to implement the invalidation logic
comment|/// where we must invalidate the results aggregation if any of our component
comment|/// analyses become invalid.
name|void
name|addAADependencyID
argument_list|(
argument|AnalysisKey *ID
argument_list|)
block|{
name|AADeps
operator|.
name|push_back
argument_list|(
name|ID
argument_list|)
block|; }
comment|/// Handle invalidation events in the new pass manager.
comment|///
comment|/// The aggregation is invalidated if any of the underlying analyses is
comment|/// invalidated.
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
comment|//===--------------------------------------------------------------------===//
comment|/// \name Alias Queries
comment|/// @{
comment|/// The main low level interface to the alias analysis implementation.
comment|/// Returns an AliasResult indicating whether the two pointers are aliased to
comment|/// each other. This is the interface that must be implemented by specific
comment|/// alias analysis implementations.
name|AliasResult
name|alias
parameter_list|(
specifier|const
name|MemoryLocation
modifier|&
name|LocA
parameter_list|,
specifier|const
name|MemoryLocation
modifier|&
name|LocB
parameter_list|)
function_decl|;
comment|/// A convenience wrapper around the primary \c alias interface.
name|AliasResult
name|alias
parameter_list|(
specifier|const
name|Value
modifier|*
name|V1
parameter_list|,
name|uint64_t
name|V1Size
parameter_list|,
specifier|const
name|Value
modifier|*
name|V2
parameter_list|,
name|uint64_t
name|V2Size
parameter_list|)
block|{
return|return
name|alias
argument_list|(
name|MemoryLocation
argument_list|(
name|V1
argument_list|,
name|V1Size
argument_list|)
argument_list|,
name|MemoryLocation
argument_list|(
name|V2
argument_list|,
name|V2Size
argument_list|)
argument_list|)
return|;
block|}
comment|/// A convenience wrapper around the primary \c alias interface.
name|AliasResult
name|alias
parameter_list|(
specifier|const
name|Value
modifier|*
name|V1
parameter_list|,
specifier|const
name|Value
modifier|*
name|V2
parameter_list|)
block|{
return|return
name|alias
argument_list|(
name|V1
argument_list|,
name|MemoryLocation
operator|::
name|UnknownSize
argument_list|,
name|V2
argument_list|,
name|MemoryLocation
operator|::
name|UnknownSize
argument_list|)
return|;
block|}
comment|/// A trivial helper function to check to see if the specified pointers are
comment|/// no-alias.
name|bool
name|isNoAlias
parameter_list|(
specifier|const
name|MemoryLocation
modifier|&
name|LocA
parameter_list|,
specifier|const
name|MemoryLocation
modifier|&
name|LocB
parameter_list|)
block|{
return|return
name|alias
argument_list|(
name|LocA
argument_list|,
name|LocB
argument_list|)
operator|==
name|NoAlias
return|;
block|}
comment|/// A convenience wrapper around the \c isNoAlias helper interface.
name|bool
name|isNoAlias
parameter_list|(
specifier|const
name|Value
modifier|*
name|V1
parameter_list|,
name|uint64_t
name|V1Size
parameter_list|,
specifier|const
name|Value
modifier|*
name|V2
parameter_list|,
name|uint64_t
name|V2Size
parameter_list|)
block|{
return|return
name|isNoAlias
argument_list|(
name|MemoryLocation
argument_list|(
name|V1
argument_list|,
name|V1Size
argument_list|)
argument_list|,
name|MemoryLocation
argument_list|(
name|V2
argument_list|,
name|V2Size
argument_list|)
argument_list|)
return|;
block|}
comment|/// A convenience wrapper around the \c isNoAlias helper interface.
name|bool
name|isNoAlias
parameter_list|(
specifier|const
name|Value
modifier|*
name|V1
parameter_list|,
specifier|const
name|Value
modifier|*
name|V2
parameter_list|)
block|{
return|return
name|isNoAlias
argument_list|(
name|MemoryLocation
argument_list|(
name|V1
argument_list|)
argument_list|,
name|MemoryLocation
argument_list|(
name|V2
argument_list|)
argument_list|)
return|;
block|}
comment|/// A trivial helper function to check to see if the specified pointers are
comment|/// must-alias.
name|bool
name|isMustAlias
parameter_list|(
specifier|const
name|MemoryLocation
modifier|&
name|LocA
parameter_list|,
specifier|const
name|MemoryLocation
modifier|&
name|LocB
parameter_list|)
block|{
return|return
name|alias
argument_list|(
name|LocA
argument_list|,
name|LocB
argument_list|)
operator|==
name|MustAlias
return|;
block|}
comment|/// A convenience wrapper around the \c isMustAlias helper interface.
name|bool
name|isMustAlias
parameter_list|(
specifier|const
name|Value
modifier|*
name|V1
parameter_list|,
specifier|const
name|Value
modifier|*
name|V2
parameter_list|)
block|{
return|return
name|alias
argument_list|(
name|V1
argument_list|,
literal|1
argument_list|,
name|V2
argument_list|,
literal|1
argument_list|)
operator|==
name|MustAlias
return|;
block|}
comment|/// Checks whether the given location points to constant memory, or if
comment|/// \p OrLocal is true whether it points to a local alloca.
name|bool
name|pointsToConstantMemory
parameter_list|(
specifier|const
name|MemoryLocation
modifier|&
name|Loc
parameter_list|,
name|bool
name|OrLocal
init|=
name|false
parameter_list|)
function_decl|;
comment|/// A convenience wrapper around the primary \c pointsToConstantMemory
comment|/// interface.
name|bool
name|pointsToConstantMemory
parameter_list|(
specifier|const
name|Value
modifier|*
name|P
parameter_list|,
name|bool
name|OrLocal
init|=
name|false
parameter_list|)
block|{
return|return
name|pointsToConstantMemory
argument_list|(
name|MemoryLocation
argument_list|(
name|P
argument_list|)
argument_list|,
name|OrLocal
argument_list|)
return|;
block|}
comment|/// @}
comment|//===--------------------------------------------------------------------===//
comment|/// \name Simple mod/ref information
comment|/// @{
comment|/// Get the ModRef info associated with a pointer argument of a callsite. The
comment|/// result's bits are set to indicate the allowed aliasing ModRef kinds. Note
comment|/// that these bits do not necessarily account for the overall behavior of
comment|/// the function, but rather only provide additional per-argument
comment|/// information.
name|ModRefInfo
name|getArgModRefInfo
parameter_list|(
name|ImmutableCallSite
name|CS
parameter_list|,
name|unsigned
name|ArgIdx
parameter_list|)
function_decl|;
comment|/// Return the behavior of the given call site.
name|FunctionModRefBehavior
name|getModRefBehavior
parameter_list|(
name|ImmutableCallSite
name|CS
parameter_list|)
function_decl|;
comment|/// Return the behavior when calling the given function.
name|FunctionModRefBehavior
name|getModRefBehavior
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
comment|/// Checks if the specified call is known to never read or write memory.
comment|///
comment|/// Note that if the call only reads from known-constant memory, it is also
comment|/// legal to return true. Also, calls that unwind the stack are legal for
comment|/// this predicate.
comment|///
comment|/// Many optimizations (such as CSE and LICM) can be performed on such calls
comment|/// without worrying about aliasing properties, and many calls have this
comment|/// property (e.g. calls to 'sin' and 'cos').
comment|///
comment|/// This property corresponds to the GCC 'const' attribute.
name|bool
name|doesNotAccessMemory
parameter_list|(
name|ImmutableCallSite
name|CS
parameter_list|)
block|{
return|return
name|getModRefBehavior
argument_list|(
name|CS
argument_list|)
operator|==
name|FMRB_DoesNotAccessMemory
return|;
block|}
comment|/// Checks if the specified function is known to never read or write memory.
comment|///
comment|/// Note that if the function only reads from known-constant memory, it is
comment|/// also legal to return true. Also, function that unwind the stack are legal
comment|/// for this predicate.
comment|///
comment|/// Many optimizations (such as CSE and LICM) can be performed on such calls
comment|/// to such functions without worrying about aliasing properties, and many
comment|/// functions have this property (e.g. 'sin' and 'cos').
comment|///
comment|/// This property corresponds to the GCC 'const' attribute.
name|bool
name|doesNotAccessMemory
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
block|{
return|return
name|getModRefBehavior
argument_list|(
name|F
argument_list|)
operator|==
name|FMRB_DoesNotAccessMemory
return|;
block|}
comment|/// Checks if the specified call is known to only read from non-volatile
comment|/// memory (or not access memory at all).
comment|///
comment|/// Calls that unwind the stack are legal for this predicate.
comment|///
comment|/// This property allows many common optimizations to be performed in the
comment|/// absence of interfering store instructions, such as CSE of strlen calls.
comment|///
comment|/// This property corresponds to the GCC 'pure' attribute.
name|bool
name|onlyReadsMemory
parameter_list|(
name|ImmutableCallSite
name|CS
parameter_list|)
block|{
return|return
name|onlyReadsMemory
argument_list|(
name|getModRefBehavior
argument_list|(
name|CS
argument_list|)
argument_list|)
return|;
block|}
comment|/// Checks if the specified function is known to only read from non-volatile
comment|/// memory (or not access memory at all).
comment|///
comment|/// Functions that unwind the stack are legal for this predicate.
comment|///
comment|/// This property allows many common optimizations to be performed in the
comment|/// absence of interfering store instructions, such as CSE of strlen calls.
comment|///
comment|/// This property corresponds to the GCC 'pure' attribute.
name|bool
name|onlyReadsMemory
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
block|{
return|return
name|onlyReadsMemory
argument_list|(
name|getModRefBehavior
argument_list|(
name|F
argument_list|)
argument_list|)
return|;
block|}
comment|/// Checks if functions with the specified behavior are known to only read
comment|/// from non-volatile memory (or not access memory at all).
specifier|static
name|bool
name|onlyReadsMemory
parameter_list|(
name|FunctionModRefBehavior
name|MRB
parameter_list|)
block|{
return|return
operator|!
operator|(
name|MRB
operator|&
name|MRI_Mod
operator|)
return|;
block|}
comment|/// Checks if functions with the specified behavior are known to only write
comment|/// memory (or not access memory at all).
specifier|static
name|bool
name|doesNotReadMemory
parameter_list|(
name|FunctionModRefBehavior
name|MRB
parameter_list|)
block|{
return|return
operator|!
operator|(
name|MRB
operator|&
name|MRI_Ref
operator|)
return|;
block|}
comment|/// Checks if functions with the specified behavior are known to read and
comment|/// write at most from objects pointed to by their pointer-typed arguments
comment|/// (with arbitrary offsets).
specifier|static
name|bool
name|onlyAccessesArgPointees
parameter_list|(
name|FunctionModRefBehavior
name|MRB
parameter_list|)
block|{
return|return
operator|!
operator|(
name|MRB
operator|&
name|FMRL_Anywhere
operator|&
operator|~
name|FMRL_ArgumentPointees
operator|)
return|;
block|}
comment|/// Checks if functions with the specified behavior are known to potentially
comment|/// read or write from objects pointed to be their pointer-typed arguments
comment|/// (with arbitrary offsets).
specifier|static
name|bool
name|doesAccessArgPointees
parameter_list|(
name|FunctionModRefBehavior
name|MRB
parameter_list|)
block|{
return|return
operator|(
name|MRB
operator|&
name|MRI_ModRef
operator|)
operator|&&
operator|(
name|MRB
operator|&
name|FMRL_ArgumentPointees
operator|)
return|;
block|}
comment|/// Checks if functions with the specified behavior are known to read and
comment|/// write at most from memory that is inaccessible from LLVM IR.
specifier|static
name|bool
name|onlyAccessesInaccessibleMem
parameter_list|(
name|FunctionModRefBehavior
name|MRB
parameter_list|)
block|{
return|return
operator|!
operator|(
name|MRB
operator|&
name|FMRL_Anywhere
operator|&
operator|~
name|FMRL_InaccessibleMem
operator|)
return|;
block|}
comment|/// Checks if functions with the specified behavior are known to potentially
comment|/// read or write from memory that is inaccessible from LLVM IR.
specifier|static
name|bool
name|doesAccessInaccessibleMem
parameter_list|(
name|FunctionModRefBehavior
name|MRB
parameter_list|)
block|{
return|return
operator|(
name|MRB
operator|&
name|MRI_ModRef
operator|)
operator|&&
operator|(
name|MRB
operator|&
name|FMRL_InaccessibleMem
operator|)
return|;
block|}
comment|/// Checks if functions with the specified behavior are known to read and
comment|/// write at most from memory that is inaccessible from LLVM IR or objects
comment|/// pointed to by their pointer-typed arguments (with arbitrary offsets).
specifier|static
name|bool
name|onlyAccessesInaccessibleOrArgMem
parameter_list|(
name|FunctionModRefBehavior
name|MRB
parameter_list|)
block|{
return|return
operator|!
operator|(
name|MRB
operator|&
name|FMRL_Anywhere
operator|&
operator|~
operator|(
name|FMRL_InaccessibleMem
operator||
name|FMRL_ArgumentPointees
operator|)
operator|)
return|;
block|}
comment|/// getModRefInfo (for call sites) - Return information about whether
comment|/// a particular call site modifies or reads the specified memory location.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
name|ImmutableCallSite
name|CS
parameter_list|,
specifier|const
name|MemoryLocation
modifier|&
name|Loc
parameter_list|)
function_decl|;
comment|/// getModRefInfo (for call sites) - A convenience wrapper.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
name|ImmutableCallSite
name|CS
parameter_list|,
specifier|const
name|Value
modifier|*
name|P
parameter_list|,
name|uint64_t
name|Size
parameter_list|)
block|{
return|return
name|getModRefInfo
argument_list|(
name|CS
argument_list|,
name|MemoryLocation
argument_list|(
name|P
argument_list|,
name|Size
argument_list|)
argument_list|)
return|;
block|}
comment|/// getModRefInfo (for calls) - Return information about whether
comment|/// a particular call modifies or reads the specified memory location.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
specifier|const
name|CallInst
modifier|*
name|C
parameter_list|,
specifier|const
name|MemoryLocation
modifier|&
name|Loc
parameter_list|)
block|{
return|return
name|getModRefInfo
argument_list|(
name|ImmutableCallSite
argument_list|(
name|C
argument_list|)
argument_list|,
name|Loc
argument_list|)
return|;
block|}
comment|/// getModRefInfo (for calls) - A convenience wrapper.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
specifier|const
name|CallInst
modifier|*
name|C
parameter_list|,
specifier|const
name|Value
modifier|*
name|P
parameter_list|,
name|uint64_t
name|Size
parameter_list|)
block|{
return|return
name|getModRefInfo
argument_list|(
name|C
argument_list|,
name|MemoryLocation
argument_list|(
name|P
argument_list|,
name|Size
argument_list|)
argument_list|)
return|;
block|}
comment|/// getModRefInfo (for invokes) - Return information about whether
comment|/// a particular invoke modifies or reads the specified memory location.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
specifier|const
name|InvokeInst
modifier|*
name|I
parameter_list|,
specifier|const
name|MemoryLocation
modifier|&
name|Loc
parameter_list|)
block|{
return|return
name|getModRefInfo
argument_list|(
name|ImmutableCallSite
argument_list|(
name|I
argument_list|)
argument_list|,
name|Loc
argument_list|)
return|;
block|}
comment|/// getModRefInfo (for invokes) - A convenience wrapper.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
specifier|const
name|InvokeInst
modifier|*
name|I
parameter_list|,
specifier|const
name|Value
modifier|*
name|P
parameter_list|,
name|uint64_t
name|Size
parameter_list|)
block|{
return|return
name|getModRefInfo
argument_list|(
name|I
argument_list|,
name|MemoryLocation
argument_list|(
name|P
argument_list|,
name|Size
argument_list|)
argument_list|)
return|;
block|}
comment|/// getModRefInfo (for loads) - Return information about whether
comment|/// a particular load modifies or reads the specified memory location.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
specifier|const
name|LoadInst
modifier|*
name|L
parameter_list|,
specifier|const
name|MemoryLocation
modifier|&
name|Loc
parameter_list|)
function_decl|;
comment|/// getModRefInfo (for loads) - A convenience wrapper.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
specifier|const
name|LoadInst
modifier|*
name|L
parameter_list|,
specifier|const
name|Value
modifier|*
name|P
parameter_list|,
name|uint64_t
name|Size
parameter_list|)
block|{
return|return
name|getModRefInfo
argument_list|(
name|L
argument_list|,
name|MemoryLocation
argument_list|(
name|P
argument_list|,
name|Size
argument_list|)
argument_list|)
return|;
block|}
comment|/// getModRefInfo (for stores) - Return information about whether
comment|/// a particular store modifies or reads the specified memory location.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
specifier|const
name|StoreInst
modifier|*
name|S
parameter_list|,
specifier|const
name|MemoryLocation
modifier|&
name|Loc
parameter_list|)
function_decl|;
comment|/// getModRefInfo (for stores) - A convenience wrapper.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
specifier|const
name|StoreInst
modifier|*
name|S
parameter_list|,
specifier|const
name|Value
modifier|*
name|P
parameter_list|,
name|uint64_t
name|Size
parameter_list|)
block|{
return|return
name|getModRefInfo
argument_list|(
name|S
argument_list|,
name|MemoryLocation
argument_list|(
name|P
argument_list|,
name|Size
argument_list|)
argument_list|)
return|;
block|}
comment|/// getModRefInfo (for fences) - Return information about whether
comment|/// a particular store modifies or reads the specified memory location.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
specifier|const
name|FenceInst
modifier|*
name|S
parameter_list|,
specifier|const
name|MemoryLocation
modifier|&
name|Loc
parameter_list|)
function_decl|;
comment|/// getModRefInfo (for fences) - A convenience wrapper.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
specifier|const
name|FenceInst
modifier|*
name|S
parameter_list|,
specifier|const
name|Value
modifier|*
name|P
parameter_list|,
name|uint64_t
name|Size
parameter_list|)
block|{
return|return
name|getModRefInfo
argument_list|(
name|S
argument_list|,
name|MemoryLocation
argument_list|(
name|P
argument_list|,
name|Size
argument_list|)
argument_list|)
return|;
block|}
comment|/// getModRefInfo (for cmpxchges) - Return information about whether
comment|/// a particular cmpxchg modifies or reads the specified memory location.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
specifier|const
name|AtomicCmpXchgInst
modifier|*
name|CX
parameter_list|,
specifier|const
name|MemoryLocation
modifier|&
name|Loc
parameter_list|)
function_decl|;
comment|/// getModRefInfo (for cmpxchges) - A convenience wrapper.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
specifier|const
name|AtomicCmpXchgInst
modifier|*
name|CX
parameter_list|,
specifier|const
name|Value
modifier|*
name|P
parameter_list|,
name|unsigned
name|Size
parameter_list|)
block|{
return|return
name|getModRefInfo
argument_list|(
name|CX
argument_list|,
name|MemoryLocation
argument_list|(
name|P
argument_list|,
name|Size
argument_list|)
argument_list|)
return|;
block|}
comment|/// getModRefInfo (for atomicrmws) - Return information about whether
comment|/// a particular atomicrmw modifies or reads the specified memory location.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
specifier|const
name|AtomicRMWInst
modifier|*
name|RMW
parameter_list|,
specifier|const
name|MemoryLocation
modifier|&
name|Loc
parameter_list|)
function_decl|;
comment|/// getModRefInfo (for atomicrmws) - A convenience wrapper.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
specifier|const
name|AtomicRMWInst
modifier|*
name|RMW
parameter_list|,
specifier|const
name|Value
modifier|*
name|P
parameter_list|,
name|unsigned
name|Size
parameter_list|)
block|{
return|return
name|getModRefInfo
argument_list|(
name|RMW
argument_list|,
name|MemoryLocation
argument_list|(
name|P
argument_list|,
name|Size
argument_list|)
argument_list|)
return|;
block|}
comment|/// getModRefInfo (for va_args) - Return information about whether
comment|/// a particular va_arg modifies or reads the specified memory location.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
specifier|const
name|VAArgInst
modifier|*
name|I
parameter_list|,
specifier|const
name|MemoryLocation
modifier|&
name|Loc
parameter_list|)
function_decl|;
comment|/// getModRefInfo (for va_args) - A convenience wrapper.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
specifier|const
name|VAArgInst
modifier|*
name|I
parameter_list|,
specifier|const
name|Value
modifier|*
name|P
parameter_list|,
name|uint64_t
name|Size
parameter_list|)
block|{
return|return
name|getModRefInfo
argument_list|(
name|I
argument_list|,
name|MemoryLocation
argument_list|(
name|P
argument_list|,
name|Size
argument_list|)
argument_list|)
return|;
block|}
comment|/// getModRefInfo (for catchpads) - Return information about whether
comment|/// a particular catchpad modifies or reads the specified memory location.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
specifier|const
name|CatchPadInst
modifier|*
name|I
parameter_list|,
specifier|const
name|MemoryLocation
modifier|&
name|Loc
parameter_list|)
function_decl|;
comment|/// getModRefInfo (for catchpads) - A convenience wrapper.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
specifier|const
name|CatchPadInst
modifier|*
name|I
parameter_list|,
specifier|const
name|Value
modifier|*
name|P
parameter_list|,
name|uint64_t
name|Size
parameter_list|)
block|{
return|return
name|getModRefInfo
argument_list|(
name|I
argument_list|,
name|MemoryLocation
argument_list|(
name|P
argument_list|,
name|Size
argument_list|)
argument_list|)
return|;
block|}
comment|/// getModRefInfo (for catchrets) - Return information about whether
comment|/// a particular catchret modifies or reads the specified memory location.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
specifier|const
name|CatchReturnInst
modifier|*
name|I
parameter_list|,
specifier|const
name|MemoryLocation
modifier|&
name|Loc
parameter_list|)
function_decl|;
comment|/// getModRefInfo (for catchrets) - A convenience wrapper.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
specifier|const
name|CatchReturnInst
modifier|*
name|I
parameter_list|,
specifier|const
name|Value
modifier|*
name|P
parameter_list|,
name|uint64_t
name|Size
parameter_list|)
block|{
return|return
name|getModRefInfo
argument_list|(
name|I
argument_list|,
name|MemoryLocation
argument_list|(
name|P
argument_list|,
name|Size
argument_list|)
argument_list|)
return|;
block|}
comment|/// Check whether or not an instruction may read or write memory (without
comment|/// regard to a specific location).
comment|///
comment|/// For function calls, this delegates to the alias-analysis specific
comment|/// call-site mod-ref behavior queries. Otherwise it delegates to the generic
comment|/// mod ref information query without a location.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|)
block|{
if|if
condition|(
name|auto
name|CS
init|=
name|ImmutableCallSite
argument_list|(
name|I
argument_list|)
condition|)
block|{
name|auto
name|MRB
init|=
name|getModRefBehavior
argument_list|(
name|CS
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
name|MRB
operator|&
name|MRI_ModRef
operator|)
operator|==
name|MRI_ModRef
condition|)
return|return
name|MRI_ModRef
return|;
if|if
condition|(
name|MRB
operator|&
name|MRI_Ref
condition|)
return|return
name|MRI_Ref
return|;
if|if
condition|(
name|MRB
operator|&
name|MRI_Mod
condition|)
return|return
name|MRI_Mod
return|;
return|return
name|MRI_NoModRef
return|;
block|}
return|return
name|getModRefInfo
argument_list|(
name|I
argument_list|,
name|MemoryLocation
argument_list|()
argument_list|)
return|;
block|}
comment|/// Check whether or not an instruction may read or write the specified
comment|/// memory location.
comment|///
comment|/// Note explicitly that getModRefInfo considers the effects of reading and
comment|/// writing the memory location, and not the effect of ordering relative to
comment|/// other instructions.  Thus, a volatile load is considered to be Ref,
comment|/// because it does not actually write memory, it just can't be reordered
comment|/// relative to other volatiles (or removed).  Atomic ordered loads/stores are
comment|/// considered ModRef ATM because conservatively, the visible effect appears
comment|/// as if memory was written, not just an ordering constraint.
comment|///
comment|/// An instruction that doesn't read or write memory may be trivially LICM'd
comment|/// for example.
comment|///
comment|/// This primarily delegates to specific helpers above.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|,
specifier|const
name|MemoryLocation
modifier|&
name|Loc
parameter_list|)
block|{
switch|switch
condition|(
name|I
operator|->
name|getOpcode
argument_list|()
condition|)
block|{
case|case
name|Instruction
operator|::
name|VAArg
case|:
return|return
name|getModRefInfo
argument_list|(
operator|(
specifier|const
name|VAArgInst
operator|*
operator|)
name|I
argument_list|,
name|Loc
argument_list|)
return|;
case|case
name|Instruction
operator|::
name|Load
case|:
return|return
name|getModRefInfo
argument_list|(
operator|(
specifier|const
name|LoadInst
operator|*
operator|)
name|I
argument_list|,
name|Loc
argument_list|)
return|;
case|case
name|Instruction
operator|::
name|Store
case|:
return|return
name|getModRefInfo
argument_list|(
operator|(
specifier|const
name|StoreInst
operator|*
operator|)
name|I
argument_list|,
name|Loc
argument_list|)
return|;
case|case
name|Instruction
operator|::
name|Fence
case|:
return|return
name|getModRefInfo
argument_list|(
operator|(
specifier|const
name|FenceInst
operator|*
operator|)
name|I
argument_list|,
name|Loc
argument_list|)
return|;
case|case
name|Instruction
operator|::
name|AtomicCmpXchg
case|:
return|return
name|getModRefInfo
argument_list|(
operator|(
specifier|const
name|AtomicCmpXchgInst
operator|*
operator|)
name|I
argument_list|,
name|Loc
argument_list|)
return|;
case|case
name|Instruction
operator|::
name|AtomicRMW
case|:
return|return
name|getModRefInfo
argument_list|(
operator|(
specifier|const
name|AtomicRMWInst
operator|*
operator|)
name|I
argument_list|,
name|Loc
argument_list|)
return|;
case|case
name|Instruction
operator|::
name|Call
case|:
return|return
name|getModRefInfo
argument_list|(
operator|(
specifier|const
name|CallInst
operator|*
operator|)
name|I
argument_list|,
name|Loc
argument_list|)
return|;
case|case
name|Instruction
operator|::
name|Invoke
case|:
return|return
name|getModRefInfo
argument_list|(
operator|(
specifier|const
name|InvokeInst
operator|*
operator|)
name|I
argument_list|,
name|Loc
argument_list|)
return|;
case|case
name|Instruction
operator|::
name|CatchPad
case|:
return|return
name|getModRefInfo
argument_list|(
operator|(
specifier|const
name|CatchPadInst
operator|*
operator|)
name|I
argument_list|,
name|Loc
argument_list|)
return|;
case|case
name|Instruction
operator|::
name|CatchRet
case|:
return|return
name|getModRefInfo
argument_list|(
operator|(
specifier|const
name|CatchReturnInst
operator|*
operator|)
name|I
argument_list|,
name|Loc
argument_list|)
return|;
default|default:
return|return
name|MRI_NoModRef
return|;
block|}
block|}
comment|/// A convenience wrapper for constructing the memory location.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|,
specifier|const
name|Value
modifier|*
name|P
parameter_list|,
name|uint64_t
name|Size
parameter_list|)
block|{
return|return
name|getModRefInfo
argument_list|(
name|I
argument_list|,
name|MemoryLocation
argument_list|(
name|P
argument_list|,
name|Size
argument_list|)
argument_list|)
return|;
block|}
comment|/// Return information about whether a call and an instruction may refer to
comment|/// the same memory locations.
name|ModRefInfo
name|getModRefInfo
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|,
name|ImmutableCallSite
name|Call
parameter_list|)
function_decl|;
comment|/// Return information about whether two call sites may refer to the same set
comment|/// of memory locations. See the AA documentation for details:
comment|///   http://llvm.org/docs/AliasAnalysis.html#ModRefInfo
name|ModRefInfo
name|getModRefInfo
parameter_list|(
name|ImmutableCallSite
name|CS1
parameter_list|,
name|ImmutableCallSite
name|CS2
parameter_list|)
function_decl|;
comment|/// \brief Return information about whether a particular call site modifies
comment|/// or reads the specified memory location \p MemLoc before instruction \p I
comment|/// in a BasicBlock. A ordered basic block \p OBB can be used to speed up
comment|/// instruction ordering queries inside the BasicBlock containing \p I.
name|ModRefInfo
name|callCapturesBefore
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|,
specifier|const
name|MemoryLocation
modifier|&
name|MemLoc
parameter_list|,
name|DominatorTree
modifier|*
name|DT
parameter_list|,
name|OrderedBasicBlock
modifier|*
name|OBB
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// \brief A convenience wrapper to synthesize a memory location.
name|ModRefInfo
name|callCapturesBefore
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|,
specifier|const
name|Value
modifier|*
name|P
parameter_list|,
name|uint64_t
name|Size
parameter_list|,
name|DominatorTree
modifier|*
name|DT
parameter_list|,
name|OrderedBasicBlock
modifier|*
name|OBB
init|=
name|nullptr
parameter_list|)
block|{
return|return
name|callCapturesBefore
argument_list|(
name|I
argument_list|,
name|MemoryLocation
argument_list|(
name|P
argument_list|,
name|Size
argument_list|)
argument_list|,
name|DT
argument_list|,
name|OBB
argument_list|)
return|;
block|}
comment|/// @}
comment|//===--------------------------------------------------------------------===//
comment|/// \name Higher level methods for querying mod/ref information.
comment|/// @{
comment|/// Check if it is possible for execution of the specified basic block to
comment|/// modify the location Loc.
name|bool
name|canBasicBlockModify
parameter_list|(
specifier|const
name|BasicBlock
modifier|&
name|BB
parameter_list|,
specifier|const
name|MemoryLocation
modifier|&
name|Loc
parameter_list|)
function_decl|;
comment|/// A convenience wrapper synthesizing a memory location.
name|bool
name|canBasicBlockModify
parameter_list|(
specifier|const
name|BasicBlock
modifier|&
name|BB
parameter_list|,
specifier|const
name|Value
modifier|*
name|P
parameter_list|,
name|uint64_t
name|Size
parameter_list|)
block|{
return|return
name|canBasicBlockModify
argument_list|(
name|BB
argument_list|,
name|MemoryLocation
argument_list|(
name|P
argument_list|,
name|Size
argument_list|)
argument_list|)
return|;
block|}
comment|/// Check if it is possible for the execution of the specified instructions
comment|/// to mod\ref (according to the mode) the location Loc.
comment|///
comment|/// The instructions to consider are all of the instructions in the range of
comment|/// [I1,I2] INCLUSIVE. I1 and I2 must be in the same basic block.
name|bool
name|canInstructionRangeModRef
parameter_list|(
specifier|const
name|Instruction
modifier|&
name|I1
parameter_list|,
specifier|const
name|Instruction
modifier|&
name|I2
parameter_list|,
specifier|const
name|MemoryLocation
modifier|&
name|Loc
parameter_list|,
specifier|const
name|ModRefInfo
name|Mode
parameter_list|)
function_decl|;
comment|/// A convenience wrapper synthesizing a memory location.
name|bool
name|canInstructionRangeModRef
parameter_list|(
specifier|const
name|Instruction
modifier|&
name|I1
parameter_list|,
specifier|const
name|Instruction
modifier|&
name|I2
parameter_list|,
specifier|const
name|Value
modifier|*
name|Ptr
parameter_list|,
name|uint64_t
name|Size
parameter_list|,
specifier|const
name|ModRefInfo
name|Mode
parameter_list|)
block|{
return|return
name|canInstructionRangeModRef
argument_list|(
name|I1
argument_list|,
name|I2
argument_list|,
name|MemoryLocation
argument_list|(
name|Ptr
argument_list|,
name|Size
argument_list|)
argument_list|,
name|Mode
argument_list|)
return|;
block|}
name|private
label|:
name|class
name|Concept
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|Model
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|friend
name|class
name|AAResultBase
expr_stmt|;
specifier|const
name|TargetLibraryInfo
modifier|&
name|TLI
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Concept
operator|>>
name|AAs
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|AnalysisKey
operator|*
operator|>
name|AADeps
expr_stmt|;
block|}
empty_stmt|;
comment|/// Temporary typedef for legacy code that uses a generic \c AliasAnalysis
comment|/// pointer or reference.
typedef|typedef
name|AAResults
name|AliasAnalysis
typedef|;
comment|/// A private abstract base class describing the concept of an individual alias
comment|/// analysis implementation.
comment|///
comment|/// This interface is implemented by any \c Model instantiation. It is also the
comment|/// interface which a type used to instantiate the model must provide.
comment|///
comment|/// All of these methods model methods by the same name in the \c
comment|/// AAResults class. Only differences and specifics to how the
comment|/// implementations are called are documented here.
name|class
name|AAResults
operator|::
name|Concept
block|{
name|public
operator|:
name|virtual
operator|~
name|Concept
argument_list|()
operator|=
literal|0
block|;
comment|/// An update API used internally by the AAResults to provide
comment|/// a handle back to the top level aggregation.
name|virtual
name|void
name|setAAResults
argument_list|(
name|AAResults
operator|*
name|NewAAR
argument_list|)
operator|=
literal|0
block|;
comment|//===--------------------------------------------------------------------===//
comment|/// \name Alias Queries
comment|/// @{
comment|/// The main low level interface to the alias analysis implementation.
comment|/// Returns an AliasResult indicating whether the two pointers are aliased to
comment|/// each other. This is the interface that must be implemented by specific
comment|/// alias analysis implementations.
name|virtual
name|AliasResult
name|alias
argument_list|(
specifier|const
name|MemoryLocation
operator|&
name|LocA
argument_list|,
specifier|const
name|MemoryLocation
operator|&
name|LocB
argument_list|)
operator|=
literal|0
block|;
comment|/// Checks whether the given location points to constant memory, or if
comment|/// \p OrLocal is true whether it points to a local alloca.
name|virtual
name|bool
name|pointsToConstantMemory
argument_list|(
argument|const MemoryLocation&Loc
argument_list|,
argument|bool OrLocal
argument_list|)
operator|=
literal|0
block|;
comment|/// @}
comment|//===--------------------------------------------------------------------===//
comment|/// \name Simple mod/ref information
comment|/// @{
comment|/// Get the ModRef info associated with a pointer argument of a callsite. The
comment|/// result's bits are set to indicate the allowed aliasing ModRef kinds. Note
comment|/// that these bits do not necessarily account for the overall behavior of
comment|/// the function, but rather only provide additional per-argument
comment|/// information.
name|virtual
name|ModRefInfo
name|getArgModRefInfo
argument_list|(
argument|ImmutableCallSite CS
argument_list|,
argument|unsigned ArgIdx
argument_list|)
operator|=
literal|0
block|;
comment|/// Return the behavior of the given call site.
name|virtual
name|FunctionModRefBehavior
name|getModRefBehavior
argument_list|(
argument|ImmutableCallSite CS
argument_list|)
operator|=
literal|0
block|;
comment|/// Return the behavior when calling the given function.
name|virtual
name|FunctionModRefBehavior
name|getModRefBehavior
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|)
operator|=
literal|0
block|;
comment|/// getModRefInfo (for call sites) - Return information about whether
comment|/// a particular call site modifies or reads the specified memory location.
name|virtual
name|ModRefInfo
name|getModRefInfo
argument_list|(
argument|ImmutableCallSite CS
argument_list|,
argument|const MemoryLocation&Loc
argument_list|)
operator|=
literal|0
block|;
comment|/// Return information about whether two call sites may refer to the same set
comment|/// of memory locations. See the AA documentation for details:
comment|///   http://llvm.org/docs/AliasAnalysis.html#ModRefInfo
name|virtual
name|ModRefInfo
name|getModRefInfo
argument_list|(
argument|ImmutableCallSite CS1
argument_list|,
argument|ImmutableCallSite CS2
argument_list|)
operator|=
literal|0
block|;
comment|/// @}
block|}
expr_stmt|;
comment|/// A private class template which derives from \c Concept and wraps some other
comment|/// type.
comment|///
comment|/// This models the concept by directly forwarding each interface point to the
comment|/// wrapped type which must implement a compatible interface. This provides
comment|/// a type erased binding.
name|template
operator|<
name|typename
name|AAResultT
operator|>
name|class
name|AAResults
operator|::
name|Model
name|final
operator|:
name|public
name|Concept
block|{
name|AAResultT
operator|&
name|Result
block|;
name|public
operator|:
name|explicit
name|Model
argument_list|(
name|AAResultT
operator|&
name|Result
argument_list|,
name|AAResults
operator|&
name|AAR
argument_list|)
operator|:
name|Result
argument_list|(
argument|Result
argument_list|)
block|{
name|Result
operator|.
name|setAAResults
argument_list|(
operator|&
name|AAR
argument_list|)
block|;   }
operator|~
name|Model
argument_list|()
name|override
block|{}
name|void
name|setAAResults
argument_list|(
argument|AAResults *NewAAR
argument_list|)
name|override
block|{
name|Result
operator|.
name|setAAResults
argument_list|(
name|NewAAR
argument_list|)
block|; }
name|AliasResult
name|alias
argument_list|(
argument|const MemoryLocation&LocA
argument_list|,
argument|const MemoryLocation&LocB
argument_list|)
name|override
block|{
return|return
name|Result
operator|.
name|alias
argument_list|(
name|LocA
argument_list|,
name|LocB
argument_list|)
return|;
block|}
name|bool
name|pointsToConstantMemory
argument_list|(
argument|const MemoryLocation&Loc
argument_list|,
argument|bool OrLocal
argument_list|)
name|override
block|{
return|return
name|Result
operator|.
name|pointsToConstantMemory
argument_list|(
name|Loc
argument_list|,
name|OrLocal
argument_list|)
return|;
block|}
name|ModRefInfo
name|getArgModRefInfo
argument_list|(
argument|ImmutableCallSite CS
argument_list|,
argument|unsigned ArgIdx
argument_list|)
name|override
block|{
return|return
name|Result
operator|.
name|getArgModRefInfo
argument_list|(
name|CS
argument_list|,
name|ArgIdx
argument_list|)
return|;
block|}
name|FunctionModRefBehavior
name|getModRefBehavior
argument_list|(
argument|ImmutableCallSite CS
argument_list|)
name|override
block|{
return|return
name|Result
operator|.
name|getModRefBehavior
argument_list|(
name|CS
argument_list|)
return|;
block|}
name|FunctionModRefBehavior
name|getModRefBehavior
argument_list|(
argument|const Function *F
argument_list|)
name|override
block|{
return|return
name|Result
operator|.
name|getModRefBehavior
argument_list|(
name|F
argument_list|)
return|;
block|}
name|ModRefInfo
name|getModRefInfo
argument_list|(
argument|ImmutableCallSite CS
argument_list|,
argument|const MemoryLocation&Loc
argument_list|)
name|override
block|{
return|return
name|Result
operator|.
name|getModRefInfo
argument_list|(
name|CS
argument_list|,
name|Loc
argument_list|)
return|;
block|}
name|ModRefInfo
name|getModRefInfo
argument_list|(
argument|ImmutableCallSite CS1
argument_list|,
argument|ImmutableCallSite CS2
argument_list|)
name|override
block|{
return|return
name|Result
operator|.
name|getModRefInfo
argument_list|(
name|CS1
argument_list|,
name|CS2
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// A CRTP-driven "mixin" base class to help implement the function alias
comment|/// analysis results concept.
comment|///
comment|/// Because of the nature of many alias analysis implementations, they often
comment|/// only implement a subset of the interface. This base class will attempt to
comment|/// implement the remaining portions of the interface in terms of simpler forms
comment|/// of the interface where possible, and otherwise provide conservatively
comment|/// correct fallback implementations.
comment|///
comment|/// Implementors of an alias analysis should derive from this CRTP, and then
comment|/// override specific methods that they wish to customize. There is no need to
comment|/// use virtual anywhere, the CRTP base class does static dispatch to the
comment|/// derived type passed into it.
name|template
operator|<
name|typename
name|DerivedT
operator|>
name|class
name|AAResultBase
block|{
comment|// Expose some parts of the interface only to the AAResults::Model
comment|// for wrapping. Specifically, this allows the model to call our
comment|// setAAResults method without exposing it as a fully public API.
name|friend
name|class
name|AAResults
operator|::
name|Model
operator|<
name|DerivedT
operator|>
block|;
comment|/// A pointer to the AAResults object that this AAResult is
comment|/// aggregated within. May be null if not aggregated.
name|AAResults
operator|*
name|AAR
block|;
comment|/// Helper to dispatch calls back through the derived type.
name|DerivedT
operator|&
name|derived
argument_list|()
block|{
return|return
name|static_cast
operator|<
name|DerivedT
operator|&
operator|>
operator|(
operator|*
name|this
operator|)
return|;
block|}
comment|/// A setter for the AAResults pointer, which is used to satisfy the
comment|/// AAResults::Model contract.
name|void
name|setAAResults
argument_list|(
argument|AAResults *NewAAR
argument_list|)
block|{
name|AAR
operator|=
name|NewAAR
block|; }
name|protected
operator|:
comment|/// This proxy class models a common pattern where we delegate to either the
comment|/// top-level \c AAResults aggregation if one is registered, or to the
comment|/// current result if none are registered.
name|class
name|AAResultsProxy
block|{
name|AAResults
operator|*
name|AAR
block|;
name|DerivedT
operator|&
name|CurrentResult
block|;
name|public
operator|:
name|AAResultsProxy
argument_list|(
name|AAResults
operator|*
name|AAR
argument_list|,
name|DerivedT
operator|&
name|CurrentResult
argument_list|)
operator|:
name|AAR
argument_list|(
name|AAR
argument_list|)
block|,
name|CurrentResult
argument_list|(
argument|CurrentResult
argument_list|)
block|{}
name|AliasResult
name|alias
argument_list|(
argument|const MemoryLocation&LocA
argument_list|,
argument|const MemoryLocation&LocB
argument_list|)
block|{
return|return
name|AAR
operator|?
name|AAR
operator|->
name|alias
argument_list|(
name|LocA
argument_list|,
name|LocB
argument_list|)
operator|:
name|CurrentResult
operator|.
name|alias
argument_list|(
name|LocA
argument_list|,
name|LocB
argument_list|)
return|;
block|}
name|bool
name|pointsToConstantMemory
argument_list|(
argument|const MemoryLocation&Loc
argument_list|,
argument|bool OrLocal
argument_list|)
block|{
return|return
name|AAR
condition|?
name|AAR
operator|->
name|pointsToConstantMemory
argument_list|(
name|Loc
argument_list|,
name|OrLocal
argument_list|)
else|:
name|CurrentResult
operator|.
name|pointsToConstantMemory
argument_list|(
name|Loc
argument_list|,
name|OrLocal
argument_list|)
return|;
block|}
name|ModRefInfo
name|getArgModRefInfo
argument_list|(
argument|ImmutableCallSite CS
argument_list|,
argument|unsigned ArgIdx
argument_list|)
block|{
return|return
name|AAR
condition|?
name|AAR
operator|->
name|getArgModRefInfo
argument_list|(
name|CS
argument_list|,
name|ArgIdx
argument_list|)
else|:
name|CurrentResult
operator|.
name|getArgModRefInfo
argument_list|(
name|CS
argument_list|,
name|ArgIdx
argument_list|)
return|;
block|}
name|FunctionModRefBehavior
name|getModRefBehavior
argument_list|(
argument|ImmutableCallSite CS
argument_list|)
block|{
return|return
name|AAR
condition|?
name|AAR
operator|->
name|getModRefBehavior
argument_list|(
name|CS
argument_list|)
else|:
name|CurrentResult
operator|.
name|getModRefBehavior
argument_list|(
name|CS
argument_list|)
return|;
block|}
name|FunctionModRefBehavior
name|getModRefBehavior
argument_list|(
argument|const Function *F
argument_list|)
block|{
return|return
name|AAR
condition|?
name|AAR
operator|->
name|getModRefBehavior
argument_list|(
name|F
argument_list|)
else|:
name|CurrentResult
operator|.
name|getModRefBehavior
argument_list|(
name|F
argument_list|)
return|;
block|}
name|ModRefInfo
name|getModRefInfo
argument_list|(
argument|ImmutableCallSite CS
argument_list|,
argument|const MemoryLocation&Loc
argument_list|)
block|{
return|return
name|AAR
condition|?
name|AAR
operator|->
name|getModRefInfo
argument_list|(
name|CS
argument_list|,
name|Loc
argument_list|)
else|:
name|CurrentResult
operator|.
name|getModRefInfo
argument_list|(
name|CS
argument_list|,
name|Loc
argument_list|)
return|;
block|}
name|ModRefInfo
name|getModRefInfo
argument_list|(
argument|ImmutableCallSite CS1
argument_list|,
argument|ImmutableCallSite CS2
argument_list|)
block|{
return|return
name|AAR
condition|?
name|AAR
operator|->
name|getModRefInfo
argument_list|(
name|CS1
argument_list|,
name|CS2
argument_list|)
else|:
name|CurrentResult
operator|.
name|getModRefInfo
argument_list|(
name|CS1
argument_list|,
name|CS2
argument_list|)
return|;
block|}
expr|}
block|;
name|explicit
name|AAResultBase
argument_list|()
block|{}
comment|// Provide all the copy and move constructors so that derived types aren't
comment|// constrained.
name|AAResultBase
argument_list|(
argument|const AAResultBase&Arg
argument_list|)
block|{}
name|AAResultBase
argument_list|(
argument|AAResultBase&&Arg
argument_list|)
block|{}
comment|/// Get a proxy for the best AA result set to query at this time.
comment|///
comment|/// When this result is part of a larger aggregation, this will proxy to that
comment|/// aggregation. When this result is used in isolation, it will just delegate
comment|/// back to the derived class's implementation.
comment|///
comment|/// Note that callers of this need to take considerable care to not cause
comment|/// performance problems when they use this routine, in the case of a large
comment|/// number of alias analyses being aggregated, it can be expensive to walk
comment|/// back across the chain.
name|AAResultsProxy
name|getBestAAResults
argument_list|()
block|{
return|return
name|AAResultsProxy
argument_list|(
name|AAR
argument_list|,
name|derived
argument_list|()
argument_list|)
return|;
block|}
name|public
operator|:
name|AliasResult
name|alias
argument_list|(
argument|const MemoryLocation&LocA
argument_list|,
argument|const MemoryLocation&LocB
argument_list|)
block|{
return|return
name|MayAlias
return|;
block|}
name|bool
name|pointsToConstantMemory
argument_list|(
argument|const MemoryLocation&Loc
argument_list|,
argument|bool OrLocal
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|ModRefInfo
name|getArgModRefInfo
argument_list|(
argument|ImmutableCallSite CS
argument_list|,
argument|unsigned ArgIdx
argument_list|)
block|{
return|return
name|MRI_ModRef
return|;
block|}
name|FunctionModRefBehavior
name|getModRefBehavior
argument_list|(
argument|ImmutableCallSite CS
argument_list|)
block|{
return|return
name|FMRB_UnknownModRefBehavior
return|;
block|}
name|FunctionModRefBehavior
name|getModRefBehavior
argument_list|(
argument|const Function *F
argument_list|)
block|{
return|return
name|FMRB_UnknownModRefBehavior
return|;
block|}
name|ModRefInfo
name|getModRefInfo
argument_list|(
argument|ImmutableCallSite CS
argument_list|,
argument|const MemoryLocation&Loc
argument_list|)
block|{
return|return
name|MRI_ModRef
return|;
block|}
name|ModRefInfo
name|getModRefInfo
argument_list|(
argument|ImmutableCallSite CS1
argument_list|,
argument|ImmutableCallSite CS2
argument_list|)
block|{
return|return
name|MRI_ModRef
return|;
block|}
expr|}
block|;
comment|/// Return true if this pointer is returned by a noalias function.
name|bool
name|isNoAliasCall
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|)
block|;
comment|/// Return true if this is an argument with the noalias attribute.
name|bool
name|isNoAliasArgument
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|)
block|;
comment|/// Return true if this pointer refers to a distinct and identifiable object.
comment|/// This returns true for:
comment|///    Global Variables and Functions (but not Global Aliases)
comment|///    Allocas
comment|///    ByVal and NoAlias Arguments
comment|///    NoAlias returns (e.g. calls to malloc)
comment|///
name|bool
name|isIdentifiedObject
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|)
block|;
comment|/// Return true if V is umabigously identified at the function-level.
comment|/// Different IdentifiedFunctionLocals can't alias.
comment|/// Further, an IdentifiedFunctionLocal can not alias with any function
comment|/// arguments other than itself, which is not necessarily true for
comment|/// IdentifiedObjects.
name|bool
name|isIdentifiedFunctionLocal
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|)
block|;
comment|/// A manager for alias analyses.
comment|///
comment|/// This class can have analyses registered with it and when run, it will run
comment|/// all of them and aggregate their results into single AA results interface
comment|/// that dispatches across all of the alias analysis results available.
comment|///
comment|/// Note that the order in which analyses are registered is very significant.
comment|/// That is the order in which the results will be aggregated and queried.
comment|///
comment|/// This manager effectively wraps the AnalysisManager for registering alias
comment|/// analyses. When you register your alias analysis with this manager, it will
comment|/// ensure the analysis itself is registered with its AnalysisManager.
name|class
name|AAManager
operator|:
name|public
name|AnalysisInfoMixin
operator|<
name|AAManager
operator|>
block|{
name|public
operator|:
typedef|typedef
name|AAResults
name|Result
typedef|;
comment|/// Register a specific AA result.
name|template
operator|<
name|typename
name|AnalysisT
operator|>
name|void
name|registerFunctionAnalysis
argument_list|()
block|{
name|ResultGetters
operator|.
name|push_back
argument_list|(
operator|&
name|getFunctionAAResultImpl
operator|<
name|AnalysisT
operator|>
argument_list|)
block|;   }
comment|/// Register a specific AA result.
name|template
operator|<
name|typename
name|AnalysisT
operator|>
name|void
name|registerModuleAnalysis
argument_list|()
block|{
name|ResultGetters
operator|.
name|push_back
argument_list|(
operator|&
name|getModuleAAResultImpl
operator|<
name|AnalysisT
operator|>
argument_list|)
block|;   }
name|Result
name|run
argument_list|(
argument|Function&F
argument_list|,
argument|FunctionAnalysisManager&AM
argument_list|)
block|{
name|Result
name|R
argument_list|(
name|AM
operator|.
name|getResult
operator|<
name|TargetLibraryAnalysis
operator|>
operator|(
name|F
operator|)
argument_list|)
block|;
for|for
control|(
name|auto
operator|&
name|Getter
operator|:
name|ResultGetters
control|)
call|(
modifier|*
name|Getter
call|)
argument_list|(
name|F
argument_list|,
name|AM
argument_list|,
name|R
argument_list|)
expr_stmt|;
return|return
name|R
return|;
block|}
name|private
operator|:
name|friend
name|AnalysisInfoMixin
operator|<
name|AAManager
operator|>
block|;
specifier|static
name|AnalysisKey
name|Key
block|;
name|SmallVector
operator|<
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
name|AM
argument_list|,
name|AAResults
operator|&
name|AAResults
argument_list|)
block|,
literal|4
operator|>
name|ResultGetters
block|;
name|template
operator|<
name|typename
name|AnalysisT
operator|>
specifier|static
name|void
name|getFunctionAAResultImpl
argument_list|(
argument|Function&F
argument_list|,
argument|FunctionAnalysisManager&AM
argument_list|,
argument|AAResults&AAResults
argument_list|)
block|{
name|AAResults
operator|.
name|addAAResult
argument_list|(
argument|AM.template getResult<AnalysisT>(F)
argument_list|)
block|;
name|AAResults
operator|.
name|addAADependencyID
argument_list|(
name|AnalysisT
operator|::
name|ID
argument_list|()
argument_list|)
block|;   }
name|template
operator|<
name|typename
name|AnalysisT
operator|>
specifier|static
name|void
name|getModuleAAResultImpl
argument_list|(
argument|Function&F
argument_list|,
argument|FunctionAnalysisManager&AM
argument_list|,
argument|AAResults&AAResults
argument_list|)
block|{
name|auto
operator|&
name|MAMProxy
operator|=
name|AM
operator|.
name|getResult
operator|<
name|ModuleAnalysisManagerFunctionProxy
operator|>
operator|(
name|F
operator|)
block|;
name|auto
operator|&
name|MAM
operator|=
name|MAMProxy
operator|.
name|getManager
argument_list|()
block|;
if|if
condition|(
name|auto
operator|*
name|R
operator|=
name|MAM
operator|.
name|template
name|getCachedResult
operator|<
name|AnalysisT
operator|>
operator|(
operator|*
name|F
operator|.
name|getParent
argument_list|()
operator|)
condition|)
block|{
name|AAResults
operator|.
name|addAAResult
argument_list|(
operator|*
name|R
argument_list|)
expr_stmt|;
name|MAMProxy
operator|.
name|template
name|registerOuterAnalysisInvalidation
operator|<
name|AnalysisT
operator|,
name|AAManager
operator|>
operator|(
operator|)
expr_stmt|;
block|}
block|}
block|}
block|;
comment|/// A wrapper pass to provide the legacy pass manager access to a suitably
comment|/// prepared AAResults object.
name|class
name|AAResultsWrapperPass
operator|:
name|public
name|FunctionPass
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|AAResults
operator|>
name|AAR
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|AAResultsWrapperPass
argument_list|()
block|;
name|AAResults
operator|&
name|getAAResults
argument_list|()
block|{
return|return
operator|*
name|AAR
return|;
block|}
specifier|const
name|AAResults
operator|&
name|getAAResults
argument_list|()
specifier|const
block|{
return|return
operator|*
name|AAR
return|;
block|}
name|bool
name|runOnFunction
argument_list|(
argument|Function&F
argument_list|)
name|override
block|;
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|; }
block|;
name|FunctionPass
operator|*
name|createAAResultsWrapperPass
argument_list|()
block|;
comment|/// A wrapper pass around a callback which can be used to populate the
comment|/// AAResults in the AAResultsWrapperPass from an external AA.
comment|///
comment|/// The callback provided here will be used each time we prepare an AAResults
comment|/// object, and will receive a reference to the function wrapper pass, the
comment|/// function, and the AAResults object to populate. This should be used when
comment|/// setting up a custom pass pipeline to inject a hook into the AA results.
name|ImmutablePass
operator|*
name|createExternalAAWrapperPass
argument_list|(
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|Pass
operator|&
argument_list|,
name|Function
operator|&
argument_list|,
name|AAResults
operator|&
argument_list|)
operator|>
name|Callback
argument_list|)
block|;
comment|/// A helper for the legacy pass manager to create a \c AAResults
comment|/// object populated to the best of our ability for a particular function when
comment|/// inside of a \c ModulePass or a \c CallGraphSCCPass.
comment|///
comment|/// If a \c ModulePass or a \c CallGraphSCCPass calls \p
comment|/// createLegacyPMAAResults, it also needs to call \p addUsedAAAnalyses in \p
comment|/// getAnalysisUsage.
name|AAResults
name|createLegacyPMAAResults
argument_list|(
name|Pass
operator|&
name|P
argument_list|,
name|Function
operator|&
name|F
argument_list|,
name|BasicAAResult
operator|&
name|BAR
argument_list|)
block|;
comment|/// A helper for the legacy pass manager to populate \p AU to add uses to make
comment|/// sure the analyses required by \p createLegacyPMAAResults are available.
name|void
name|getAAResultsAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
name|AU
argument_list|)
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

