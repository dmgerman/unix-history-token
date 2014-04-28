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
comment|// This API identifies memory regions with the Location class. The pointer
end_comment

begin_comment
comment|// component specifies the base memory address of the region. The Size specifies
end_comment

begin_comment
comment|// the maximum size (in address units) of the memory region, or UnknownSize if
end_comment

begin_comment
comment|// the size is not known. The TBAA tag identifies the "type" of the memory
end_comment

begin_comment
comment|// reference; see the TypeBasedAliasAnalysis class for details.
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
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CallSite.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
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
name|TargetLibraryInfo
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
name|AliasAnalysis
block|{
name|protected
label|:
specifier|const
name|DataLayout
modifier|*
name|TD
decl_stmt|;
specifier|const
name|TargetLibraryInfo
modifier|*
name|TLI
decl_stmt|;
name|private
label|:
name|AliasAnalysis
modifier|*
name|AA
decl_stmt|;
comment|// Previous Alias Analysis to chain to.
name|protected
label|:
comment|/// InitializeAliasAnalysis - Subclasses must call this method to initialize
comment|/// the AliasAnalysis interface before any other methods are called.  This is
comment|/// typically called by the run* methods of these subclasses.  This may be
comment|/// called multiple times.
comment|///
name|void
name|InitializeAliasAnalysis
parameter_list|(
name|Pass
modifier|*
name|P
parameter_list|)
function_decl|;
comment|/// getAnalysisUsage - All alias analysis implementations should invoke this
comment|/// directly (using AliasAnalysis::getAnalysisUsage(AU)).
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
name|public
label|:
specifier|static
name|char
name|ID
decl_stmt|;
comment|// Class identification, replacement for typeinfo
name|AliasAnalysis
argument_list|()
operator|:
name|TD
argument_list|(
literal|0
argument_list|)
operator|,
name|TLI
argument_list|(
literal|0
argument_list|)
operator|,
name|AA
argument_list|(
literal|0
argument_list|)
block|{}
name|virtual
operator|~
name|AliasAnalysis
argument_list|()
expr_stmt|;
comment|// We want to be subclassed
comment|/// UnknownSize - This is a special value which can be used with the
comment|/// size arguments in alias queries to indicate that the caller does not
comment|/// know the sizes of the potential memory references.
specifier|static
name|uint64_t
specifier|const
name|UnknownSize
init|=
operator|~
name|UINT64_C
argument_list|(
literal|0
argument_list|)
decl_stmt|;
comment|/// getDataLayout - Return a pointer to the current DataLayout object, or
comment|/// null if no DataLayout object is available.
comment|///
specifier|const
name|DataLayout
operator|*
name|getDataLayout
argument_list|()
specifier|const
block|{
return|return
name|TD
return|;
block|}
comment|/// getTargetLibraryInfo - Return a pointer to the current TargetLibraryInfo
comment|/// object, or null if no TargetLibraryInfo object is available.
comment|///
specifier|const
name|TargetLibraryInfo
operator|*
name|getTargetLibraryInfo
argument_list|()
specifier|const
block|{
return|return
name|TLI
return|;
block|}
comment|/// getTypeStoreSize - Return the DataLayout store size for the given type,
comment|/// if known, or a conservative value otherwise.
comment|///
name|uint64_t
name|getTypeStoreSize
parameter_list|(
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|/// Alias Queries...
comment|///
comment|/// Location - A description of a memory location.
struct|struct
name|Location
block|{
comment|/// Ptr - The address of the start of the location.
specifier|const
name|Value
modifier|*
name|Ptr
decl_stmt|;
comment|/// Size - The maximum size of the location, in address-units, or
comment|/// UnknownSize if the size is not known.  Note that an unknown size does
comment|/// not mean the pointer aliases the entire virtual address space, because
comment|/// there are restrictions on stepping out of one object and into another.
comment|/// See http://llvm.org/docs/LangRef.html#pointeraliasing
name|uint64_t
name|Size
decl_stmt|;
comment|/// TBAATag - The metadata node which describes the TBAA type of
comment|/// the location, or null if there is no known unique tag.
specifier|const
name|MDNode
modifier|*
name|TBAATag
decl_stmt|;
name|explicit
name|Location
argument_list|(
argument|const Value *P =
literal|0
argument_list|,
argument|uint64_t S = UnknownSize
argument_list|,
argument|const MDNode *N =
literal|0
argument_list|)
block|:
name|Ptr
argument_list|(
name|P
argument_list|)
operator|,
name|Size
argument_list|(
name|S
argument_list|)
operator|,
name|TBAATag
argument_list|(
argument|N
argument_list|)
block|{}
name|Location
name|getWithNewPtr
argument_list|(
argument|const Value *NewPtr
argument_list|)
specifier|const
block|{
name|Location
name|Copy
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|Copy
operator|.
name|Ptr
operator|=
name|NewPtr
block|;
return|return
name|Copy
return|;
block|}
name|Location
name|getWithNewSize
argument_list|(
name|uint64_t
name|NewSize
argument_list|)
decl|const
block|{
name|Location
name|Copy
argument_list|(
operator|*
name|this
argument_list|)
decl_stmt|;
name|Copy
operator|.
name|Size
operator|=
name|NewSize
expr_stmt|;
return|return
name|Copy
return|;
block|}
name|Location
name|getWithoutTBAATag
argument_list|()
specifier|const
block|{
name|Location
name|Copy
argument_list|(
operator|*
name|this
argument_list|)
block|;
name|Copy
operator|.
name|TBAATag
operator|=
literal|0
block|;
return|return
name|Copy
return|;
block|}
block|}
struct|;
comment|/// getLocation - Fill in Loc with information about the memory reference by
comment|/// the given instruction.
name|Location
name|getLocation
parameter_list|(
specifier|const
name|LoadInst
modifier|*
name|LI
parameter_list|)
function_decl|;
name|Location
name|getLocation
parameter_list|(
specifier|const
name|StoreInst
modifier|*
name|SI
parameter_list|)
function_decl|;
name|Location
name|getLocation
parameter_list|(
specifier|const
name|VAArgInst
modifier|*
name|VI
parameter_list|)
function_decl|;
name|Location
name|getLocation
parameter_list|(
specifier|const
name|AtomicCmpXchgInst
modifier|*
name|CXI
parameter_list|)
function_decl|;
name|Location
name|getLocation
parameter_list|(
specifier|const
name|AtomicRMWInst
modifier|*
name|RMWI
parameter_list|)
function_decl|;
specifier|static
name|Location
name|getLocationForSource
parameter_list|(
specifier|const
name|MemTransferInst
modifier|*
name|MTI
parameter_list|)
function_decl|;
specifier|static
name|Location
name|getLocationForDest
parameter_list|(
specifier|const
name|MemIntrinsic
modifier|*
name|MI
parameter_list|)
function_decl|;
comment|/// Alias analysis result - Either we know for sure that it does not alias, we
comment|/// know for sure it must alias, or we don't know anything: The two pointers
comment|/// _might_ alias.  This enum is designed so you can do things like:
comment|///     if (AA.alias(P1, P2)) { ... }
comment|/// to check to see if two pointers might alias.
comment|///
comment|/// See docs/AliasAnalysis.html for more information on the specific meanings
comment|/// of these values.
comment|///
enum|enum
name|AliasResult
block|{
name|NoAlias
init|=
literal|0
block|,
comment|///< No dependencies.
name|MayAlias
block|,
comment|///< Anything goes.
name|PartialAlias
block|,
comment|///< Pointers differ, but pointees overlap.
name|MustAlias
comment|///< Pointers are equal.
block|}
enum|;
comment|/// alias - The main low level interface to the alias analysis implementation.
comment|/// Returns an AliasResult indicating whether the two pointers are aliased to
comment|/// each other.  This is the interface that must be implemented by specific
comment|/// alias analysis implementations.
name|virtual
name|AliasResult
name|alias
parameter_list|(
specifier|const
name|Location
modifier|&
name|LocA
parameter_list|,
specifier|const
name|Location
modifier|&
name|LocB
parameter_list|)
function_decl|;
comment|/// alias - A convenience wrapper.
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
name|Location
argument_list|(
name|V1
argument_list|,
name|V1Size
argument_list|)
argument_list|,
name|Location
argument_list|(
name|V2
argument_list|,
name|V2Size
argument_list|)
argument_list|)
return|;
block|}
comment|/// alias - A convenience wrapper.
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
name|UnknownSize
argument_list|,
name|V2
argument_list|,
name|UnknownSize
argument_list|)
return|;
block|}
comment|/// isNoAlias - A trivial helper function to check to see if the specified
comment|/// pointers are no-alias.
name|bool
name|isNoAlias
parameter_list|(
specifier|const
name|Location
modifier|&
name|LocA
parameter_list|,
specifier|const
name|Location
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
comment|/// isNoAlias - A convenience wrapper.
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
name|Location
argument_list|(
name|V1
argument_list|,
name|V1Size
argument_list|)
argument_list|,
name|Location
argument_list|(
name|V2
argument_list|,
name|V2Size
argument_list|)
argument_list|)
return|;
block|}
comment|/// isNoAlias - A convenience wrapper.
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
name|Location
argument_list|(
name|V1
argument_list|)
argument_list|,
name|Location
argument_list|(
name|V2
argument_list|)
argument_list|)
return|;
block|}
comment|/// isMustAlias - A convenience wrapper.
name|bool
name|isMustAlias
parameter_list|(
specifier|const
name|Location
modifier|&
name|LocA
parameter_list|,
specifier|const
name|Location
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
comment|/// isMustAlias - A convenience wrapper.
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
comment|/// pointsToConstantMemory - If the specified memory location is
comment|/// known to be constant, return true. If OrLocal is true and the
comment|/// specified memory location is known to be "local" (derived from
comment|/// an alloca), return true. Otherwise return false.
name|virtual
name|bool
name|pointsToConstantMemory
parameter_list|(
specifier|const
name|Location
modifier|&
name|Loc
parameter_list|,
name|bool
name|OrLocal
init|=
name|false
parameter_list|)
function_decl|;
comment|/// pointsToConstantMemory - A convenient wrapper.
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
name|Location
argument_list|(
name|P
argument_list|)
argument_list|,
name|OrLocal
argument_list|)
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|/// Simple mod/ref information...
comment|///
comment|/// ModRefResult - Represent the result of a mod/ref query.  Mod and Ref are
comment|/// bits which may be or'd together.
comment|///
enum|enum
name|ModRefResult
block|{
name|NoModRef
init|=
literal|0
block|,
name|Ref
init|=
literal|1
block|,
name|Mod
init|=
literal|2
block|,
name|ModRef
init|=
literal|3
block|}
enum|;
comment|/// These values define additional bits used to define the
comment|/// ModRefBehavior values.
enum|enum
block|{
name|Nowhere
init|=
literal|0
block|,
name|ArgumentPointees
init|=
literal|4
block|,
name|Anywhere
init|=
literal|8
operator||
name|ArgumentPointees
block|}
enum|;
comment|/// ModRefBehavior - Summary of how a function affects memory in the program.
comment|/// Loads from constant globals are not considered memory accesses for this
comment|/// interface.  Also, functions may freely modify stack space local to their
comment|/// invocation without having to report it through these interfaces.
enum|enum
name|ModRefBehavior
block|{
comment|/// DoesNotAccessMemory - This function does not perform any non-local loads
comment|/// or stores to memory.
comment|///
comment|/// This property corresponds to the GCC 'const' attribute.
comment|/// This property corresponds to the LLVM IR 'readnone' attribute.
comment|/// This property corresponds to the IntrNoMem LLVM intrinsic flag.
name|DoesNotAccessMemory
init|=
name|Nowhere
operator||
name|NoModRef
block|,
comment|/// OnlyReadsArgumentPointees - The only memory references in this function
comment|/// (if it has any) are non-volatile loads from objects pointed to by its
comment|/// pointer-typed arguments, with arbitrary offsets.
comment|///
comment|/// This property corresponds to the IntrReadArgMem LLVM intrinsic flag.
name|OnlyReadsArgumentPointees
init|=
name|ArgumentPointees
operator||
name|Ref
block|,
comment|/// OnlyAccessesArgumentPointees - The only memory references in this
comment|/// function (if it has any) are non-volatile loads and stores from objects
comment|/// pointed to by its pointer-typed arguments, with arbitrary offsets.
comment|///
comment|/// This property corresponds to the IntrReadWriteArgMem LLVM intrinsic flag.
name|OnlyAccessesArgumentPointees
init|=
name|ArgumentPointees
operator||
name|ModRef
block|,
comment|/// OnlyReadsMemory - This function does not perform any non-local stores or
comment|/// volatile loads, but may read from any memory location.
comment|///
comment|/// This property corresponds to the GCC 'pure' attribute.
comment|/// This property corresponds to the LLVM IR 'readonly' attribute.
comment|/// This property corresponds to the IntrReadMem LLVM intrinsic flag.
name|OnlyReadsMemory
init|=
name|Anywhere
operator||
name|Ref
block|,
comment|/// UnknownModRefBehavior - This indicates that the function could not be
comment|/// classified into one of the behaviors above.
name|UnknownModRefBehavior
init|=
name|Anywhere
operator||
name|ModRef
block|}
enum|;
comment|/// getModRefBehavior - Return the behavior when calling the given call site.
name|virtual
name|ModRefBehavior
name|getModRefBehavior
parameter_list|(
name|ImmutableCallSite
name|CS
parameter_list|)
function_decl|;
comment|/// getModRefBehavior - Return the behavior when calling the given function.
comment|/// For use when the call site is not known.
name|virtual
name|ModRefBehavior
name|getModRefBehavior
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
comment|/// doesNotAccessMemory - If the specified call is known to never read or
comment|/// write memory, return true.  If the call only reads from known-constant
comment|/// memory, it is also legal to return true.  Calls that unwind the stack
comment|/// are legal for this predicate.
comment|///
comment|/// Many optimizations (such as CSE and LICM) can be performed on such calls
comment|/// without worrying about aliasing properties, and many calls have this
comment|/// property (e.g. calls to 'sin' and 'cos').
comment|///
comment|/// This property corresponds to the GCC 'const' attribute.
comment|///
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
name|DoesNotAccessMemory
return|;
block|}
comment|/// doesNotAccessMemory - If the specified function is known to never read or
comment|/// write memory, return true.  For use when the call site is not known.
comment|///
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
name|DoesNotAccessMemory
return|;
block|}
comment|/// onlyReadsMemory - If the specified call is known to only read from
comment|/// non-volatile memory (or not access memory at all), return true.  Calls
comment|/// that unwind the stack are legal for this predicate.
comment|///
comment|/// This property allows many common optimizations to be performed in the
comment|/// absence of interfering store instructions, such as CSE of strlen calls.
comment|///
comment|/// This property corresponds to the GCC 'pure' attribute.
comment|///
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
comment|/// onlyReadsMemory - If the specified function is known to only read from
comment|/// non-volatile memory (or not access memory at all), return true.  For use
comment|/// when the call site is not known.
comment|///
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
comment|/// onlyReadsMemory - Return true if functions with the specified behavior are
comment|/// known to only read from non-volatile memory (or not access memory at all).
comment|///
specifier|static
name|bool
name|onlyReadsMemory
parameter_list|(
name|ModRefBehavior
name|MRB
parameter_list|)
block|{
return|return
operator|!
operator|(
name|MRB
operator|&
name|Mod
operator|)
return|;
block|}
comment|/// onlyAccessesArgPointees - Return true if functions with the specified
comment|/// behavior are known to read and write at most from objects pointed to by
comment|/// their pointer-typed arguments (with arbitrary offsets).
comment|///
specifier|static
name|bool
name|onlyAccessesArgPointees
parameter_list|(
name|ModRefBehavior
name|MRB
parameter_list|)
block|{
return|return
operator|!
operator|(
name|MRB
operator|&
name|Anywhere
operator|&
operator|~
name|ArgumentPointees
operator|)
return|;
block|}
comment|/// doesAccessArgPointees - Return true if functions with the specified
comment|/// behavior are known to potentially read or write from objects pointed
comment|/// to be their pointer-typed arguments (with arbitrary offsets).
comment|///
specifier|static
name|bool
name|doesAccessArgPointees
parameter_list|(
name|ModRefBehavior
name|MRB
parameter_list|)
block|{
return|return
operator|(
name|MRB
operator|&
name|ModRef
operator|)
operator|&&
operator|(
name|MRB
operator|&
name|ArgumentPointees
operator|)
return|;
block|}
comment|/// getModRefInfo - Return information about whether or not an instruction may
comment|/// read or write the specified memory location.  An instruction
comment|/// that doesn't read or write memory may be trivially LICM'd for example.
name|ModRefResult
name|getModRefInfo
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|,
specifier|const
name|Location
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
default|default:
return|return
name|NoModRef
return|;
block|}
block|}
comment|/// getModRefInfo - A convenience wrapper.
name|ModRefResult
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
name|Location
argument_list|(
name|P
argument_list|,
name|Size
argument_list|)
argument_list|)
return|;
block|}
comment|/// getModRefInfo (for call sites) - Return information about whether
comment|/// a particular call site modifies or reads the specified memory location.
name|virtual
name|ModRefResult
name|getModRefInfo
parameter_list|(
name|ImmutableCallSite
name|CS
parameter_list|,
specifier|const
name|Location
modifier|&
name|Loc
parameter_list|)
function_decl|;
comment|/// getModRefInfo (for call sites) - A convenience wrapper.
name|ModRefResult
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
name|Location
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
name|ModRefResult
name|getModRefInfo
parameter_list|(
specifier|const
name|CallInst
modifier|*
name|C
parameter_list|,
specifier|const
name|Location
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
name|ModRefResult
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
name|Location
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
name|ModRefResult
name|getModRefInfo
parameter_list|(
specifier|const
name|InvokeInst
modifier|*
name|I
parameter_list|,
specifier|const
name|Location
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
name|ModRefResult
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
name|Location
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
name|ModRefResult
name|getModRefInfo
parameter_list|(
specifier|const
name|LoadInst
modifier|*
name|L
parameter_list|,
specifier|const
name|Location
modifier|&
name|Loc
parameter_list|)
function_decl|;
comment|/// getModRefInfo (for loads) - A convenience wrapper.
name|ModRefResult
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
name|Location
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
name|ModRefResult
name|getModRefInfo
parameter_list|(
specifier|const
name|StoreInst
modifier|*
name|S
parameter_list|,
specifier|const
name|Location
modifier|&
name|Loc
parameter_list|)
function_decl|;
comment|/// getModRefInfo (for stores) - A convenience wrapper.
name|ModRefResult
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
name|Location
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
name|ModRefResult
name|getModRefInfo
parameter_list|(
specifier|const
name|FenceInst
modifier|*
name|S
parameter_list|,
specifier|const
name|Location
modifier|&
name|Loc
parameter_list|)
block|{
comment|// Conservatively correct.  (We could possibly be a bit smarter if
comment|// Loc is a alloca that doesn't escape.)
return|return
name|ModRef
return|;
block|}
comment|/// getModRefInfo (for fences) - A convenience wrapper.
name|ModRefResult
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
name|Location
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
name|ModRefResult
name|getModRefInfo
parameter_list|(
specifier|const
name|AtomicCmpXchgInst
modifier|*
name|CX
parameter_list|,
specifier|const
name|Location
modifier|&
name|Loc
parameter_list|)
function_decl|;
comment|/// getModRefInfo (for cmpxchges) - A convenience wrapper.
name|ModRefResult
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
name|Location
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
name|ModRefResult
name|getModRefInfo
parameter_list|(
specifier|const
name|AtomicRMWInst
modifier|*
name|RMW
parameter_list|,
specifier|const
name|Location
modifier|&
name|Loc
parameter_list|)
function_decl|;
comment|/// getModRefInfo (for atomicrmws) - A convenience wrapper.
name|ModRefResult
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
name|Location
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
name|ModRefResult
name|getModRefInfo
parameter_list|(
specifier|const
name|VAArgInst
modifier|*
name|I
parameter_list|,
specifier|const
name|Location
modifier|&
name|Loc
parameter_list|)
function_decl|;
comment|/// getModRefInfo (for va_args) - A convenience wrapper.
name|ModRefResult
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
name|Location
argument_list|(
name|P
argument_list|,
name|Size
argument_list|)
argument_list|)
return|;
block|}
comment|/// getModRefInfo - Return information about whether two call sites may refer
comment|/// to the same set of memory locations.  See
comment|///   http://llvm.org/docs/AliasAnalysis.html#ModRefInfo
comment|/// for details.
name|virtual
name|ModRefResult
name|getModRefInfo
parameter_list|(
name|ImmutableCallSite
name|CS1
parameter_list|,
name|ImmutableCallSite
name|CS2
parameter_list|)
function_decl|;
comment|/// callCapturesBefore - Return information about whether a particular call
comment|/// site modifies or reads the specified memory location.
name|ModRefResult
name|callCapturesBefore
argument_list|(
specifier|const
name|Instruction
operator|*
name|I
argument_list|,
specifier|const
name|AliasAnalysis
operator|::
name|Location
operator|&
name|MemLoc
argument_list|,
name|DominatorTree
operator|*
name|DT
argument_list|)
decl_stmt|;
comment|/// callCapturesBefore - A convenience wrapper.
name|ModRefResult
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
parameter_list|)
block|{
return|return
name|callCapturesBefore
argument_list|(
name|I
argument_list|,
name|Location
argument_list|(
name|P
argument_list|,
name|Size
argument_list|)
argument_list|,
name|DT
argument_list|)
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|/// Higher level methods for querying mod/ref information.
comment|///
comment|/// canBasicBlockModify - Return true if it is possible for execution of the
comment|/// specified basic block to modify the value pointed to by Ptr.
name|bool
name|canBasicBlockModify
parameter_list|(
specifier|const
name|BasicBlock
modifier|&
name|BB
parameter_list|,
specifier|const
name|Location
modifier|&
name|Loc
parameter_list|)
function_decl|;
comment|/// canBasicBlockModify - A convenience wrapper.
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
name|Location
argument_list|(
name|P
argument_list|,
name|Size
argument_list|)
argument_list|)
return|;
block|}
comment|/// canInstructionRangeModify - Return true if it is possible for the
comment|/// execution of the specified instructions to modify the value pointed to by
comment|/// Ptr.  The instructions to consider are all of the instructions in the
comment|/// range of [I1,I2] INCLUSIVE.  I1 and I2 must be in the same basic block.
name|bool
name|canInstructionRangeModify
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
name|Location
modifier|&
name|Loc
parameter_list|)
function_decl|;
comment|/// canInstructionRangeModify - A convenience wrapper.
name|bool
name|canInstructionRangeModify
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
parameter_list|)
block|{
return|return
name|canInstructionRangeModify
argument_list|(
name|I1
argument_list|,
name|I2
argument_list|,
name|Location
argument_list|(
name|Ptr
argument_list|,
name|Size
argument_list|)
argument_list|)
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|/// Methods that clients should call when they transform the program to allow
comment|/// alias analyses to update their internal data structures.  Note that these
comment|/// methods may be called on any instruction, regardless of whether or not
comment|/// they have pointer-analysis implications.
comment|///
comment|/// deleteValue - This method should be called whenever an LLVM Value is
comment|/// deleted from the program, for example when an instruction is found to be
comment|/// redundant and is eliminated.
comment|///
name|virtual
name|void
name|deleteValue
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// copyValue - This method should be used whenever a preexisting value in the
comment|/// program is copied or cloned, introducing a new value.  Note that analysis
comment|/// implementations should tolerate clients that use this method to introduce
comment|/// the same value multiple times: if the analysis already knows about a
comment|/// value, it should ignore the request.
comment|///
name|virtual
name|void
name|copyValue
parameter_list|(
name|Value
modifier|*
name|From
parameter_list|,
name|Value
modifier|*
name|To
parameter_list|)
function_decl|;
comment|/// addEscapingUse - This method should be used whenever an escaping use is
comment|/// added to a pointer value.  Analysis implementations may either return
comment|/// conservative responses for that value in the future, or may recompute
comment|/// some or all internal state to continue providing precise responses.
comment|///
comment|/// Escaping uses are considered by anything _except_ the following:
comment|///  - GEPs or bitcasts of the pointer
comment|///  - Loads through the pointer
comment|///  - Stores through (but not of) the pointer
name|virtual
name|void
name|addEscapingUse
parameter_list|(
name|Use
modifier|&
name|U
parameter_list|)
function_decl|;
comment|/// replaceWithNewValue - This method is the obvious combination of the two
comment|/// above, and it provided as a helper to simplify client code.
comment|///
name|void
name|replaceWithNewValue
parameter_list|(
name|Value
modifier|*
name|Old
parameter_list|,
name|Value
modifier|*
name|New
parameter_list|)
block|{
name|copyValue
argument_list|(
name|Old
argument_list|,
name|New
argument_list|)
expr_stmt|;
name|deleteValue
argument_list|(
name|Old
argument_list|)
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|// Specialize DenseMapInfo for Location.
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|AliasAnalysis
operator|::
name|Location
operator|>
block|{
specifier|static
specifier|inline
name|AliasAnalysis
operator|::
name|Location
name|getEmptyKey
argument_list|()
block|{
return|return
name|AliasAnalysis
operator|::
name|Location
argument_list|(
name|DenseMapInfo
operator|<
specifier|const
name|Value
operator|*
operator|>
operator|::
name|getEmptyKey
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|AliasAnalysis
operator|::
name|Location
name|getTombstoneKey
argument_list|()
block|{
return|return
name|AliasAnalysis
operator|::
name|Location
argument_list|(
name|DenseMapInfo
operator|<
specifier|const
name|Value
operator|*
operator|>
operator|::
name|getTombstoneKey
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
argument_list|(
argument|const AliasAnalysis::Location&Val
argument_list|)
block|{
return|return
name|DenseMapInfo
operator|<
specifier|const
name|Value
operator|*
operator|>
operator|::
name|getHashValue
argument_list|(
name|Val
operator|.
name|Ptr
argument_list|)
operator|^
name|DenseMapInfo
operator|<
name|uint64_t
operator|>
operator|::
name|getHashValue
argument_list|(
name|Val
operator|.
name|Size
argument_list|)
operator|^
name|DenseMapInfo
operator|<
specifier|const
name|MDNode
operator|*
operator|>
operator|::
name|getHashValue
argument_list|(
name|Val
operator|.
name|TBAATag
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isEqual
argument_list|(
argument|const AliasAnalysis::Location&LHS
argument_list|,
argument|const AliasAnalysis::Location&RHS
argument_list|)
block|{
return|return
name|LHS
operator|.
name|Ptr
operator|==
name|RHS
operator|.
name|Ptr
operator|&&
name|LHS
operator|.
name|Size
operator|==
name|RHS
operator|.
name|Size
operator|&&
name|LHS
operator|.
name|TBAATag
operator|==
name|RHS
operator|.
name|TBAATag
return|;
block|}
expr|}
block|;
comment|/// isNoAliasCall - Return true if this pointer is returned by a noalias
comment|/// function.
name|bool
name|isNoAliasCall
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|)
block|;
comment|/// isNoAliasArgument - Return true if this is an argument with the noalias
comment|/// attribute.
name|bool
name|isNoAliasArgument
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|)
block|;
comment|/// isIdentifiedObject - Return true if this pointer refers to a distinct and
comment|/// identifiable object.  This returns true for:
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

