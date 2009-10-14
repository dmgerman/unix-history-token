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
comment|// This API represents memory as a (Pointer, Size) pair.  The Pointer component
end_comment

begin_comment
comment|// specifies the base memory address of the region, the Size specifies how large
end_comment

begin_comment
comment|// of an area is being queried.  If Size is 0, two pointers only alias if they
end_comment

begin_comment
comment|// are exactly equal.  If size is greater than zero, but small, the two pointers
end_comment

begin_comment
comment|// alias if the areas pointed to overlap.  If the size is very large (ie, ~0U),
end_comment

begin_comment
comment|// then the two pointers alias if they may be pointing to components of the same
end_comment

begin_comment
comment|// memory object.  Pointers that point to two completely different objects in
end_comment

begin_comment
comment|// memory never alias, regardless of the value of the Size component.
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
name|LLVM_ANALYSIS_ALIAS_ANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_ALIAS_ANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/CallSite.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/IncludeFile.h"
end_include

begin_include
include|#
directive|include
file|<vector>
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
name|TargetData
decl_stmt|;
name|class
name|Pass
decl_stmt|;
name|class
name|AnalysisUsage
decl_stmt|;
name|class
name|AliasAnalysis
block|{
name|protected
label|:
specifier|const
name|TargetData
modifier|*
name|TD
decl_stmt|;
name|AliasAnalysis
modifier|*
name|AA
decl_stmt|;
comment|// Previous Alias Analysis to chain to.
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
comment|/// getTargetData - Return a pointer to the current TargetData object, or
comment|/// null if no TargetData object is available.
comment|///
specifier|const
name|TargetData
operator|*
name|getTargetData
argument_list|()
specifier|const
block|{
return|return
name|TD
return|;
block|}
comment|/// getTypeStoreSize - Return the TargetData store size for the given type,
comment|/// if known, or a conservative value otherwise.
comment|///
name|unsigned
name|getTypeStoreSize
parameter_list|(
specifier|const
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|/// Alias Queries...
comment|///
comment|/// Alias analysis result - Either we know for sure that it does not alias, we
comment|/// know for sure it must alias, or we don't know anything: The two pointers
comment|/// _might_ alias.  This enum is designed so you can do things like:
comment|///     if (AA.alias(P1, P2)) { ... }
comment|/// to check to see if two pointers might alias.
comment|///
enum|enum
name|AliasResult
block|{
name|NoAlias
init|=
literal|0
block|,
name|MayAlias
init|=
literal|1
block|,
name|MustAlias
init|=
literal|2
block|}
enum|;
comment|/// alias - The main low level interface to the alias analysis implementation.
comment|/// Returns a Result indicating whether the two pointers are aliased to each
comment|/// other.  This is the interface that must be implemented by specific alias
comment|/// analysis implementations.
comment|///
name|virtual
name|AliasResult
name|alias
parameter_list|(
specifier|const
name|Value
modifier|*
name|V1
parameter_list|,
name|unsigned
name|V1Size
parameter_list|,
specifier|const
name|Value
modifier|*
name|V2
parameter_list|,
name|unsigned
name|V2Size
parameter_list|)
function_decl|;
comment|/// getMustAliases - If there are any pointers known that must alias this
comment|/// pointer, return them now.  This allows alias-set based alias analyses to
comment|/// perform a form a value numbering (which is exposed by load-vn).  If an
comment|/// alias analysis supports this, it should ADD any must aliased pointers to
comment|/// the specified vector.
comment|///
name|virtual
name|void
name|getMustAliases
argument_list|(
name|Value
operator|*
name|P
argument_list|,
name|std
operator|::
name|vector
operator|<
name|Value
operator|*
operator|>
operator|&
name|RetVals
argument_list|)
decl_stmt|;
comment|/// pointsToConstantMemory - If the specified pointer is known to point into
comment|/// constant global memory, return true.  This allows disambiguation of store
comment|/// instructions from constant pointers.
comment|///
name|virtual
name|bool
name|pointsToConstantMemory
parameter_list|(
specifier|const
name|Value
modifier|*
name|P
parameter_list|)
function_decl|;
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
comment|/// ModRefBehavior - Summary of how a function affects memory in the program.
comment|/// Loads from constant globals are not considered memory accesses for this
comment|/// interface.  Also, functions may freely modify stack space local to their
comment|/// invocation without having to report it through these interfaces.
enum|enum
name|ModRefBehavior
block|{
comment|// DoesNotAccessMemory - This function does not perform any non-local loads
comment|// or stores to memory.
comment|//
comment|// This property corresponds to the GCC 'const' attribute.
name|DoesNotAccessMemory
block|,
comment|// AccessesArguments - This function accesses function arguments in well
comment|// known (possibly volatile) ways, but does not access any other memory.
comment|//
comment|// Clients may use the Info parameter of getModRefBehavior to get specific
comment|// information about how pointer arguments are used.
name|AccessesArguments
block|,
comment|// AccessesArgumentsAndGlobals - This function has accesses function
comment|// arguments and global variables well known (possibly volatile) ways, but
comment|// does not access any other memory.
comment|//
comment|// Clients may use the Info parameter of getModRefBehavior to get specific
comment|// information about how pointer arguments are used.
name|AccessesArgumentsAndGlobals
block|,
comment|// OnlyReadsMemory - This function does not perform any non-local stores or
comment|// volatile loads, but may read from any memory location.
comment|//
comment|// This property corresponds to the GCC 'pure' attribute.
name|OnlyReadsMemory
block|,
comment|// UnknownModRefBehavior - This indicates that the function could not be
comment|// classified into one of the behaviors above.
name|UnknownModRefBehavior
block|}
enum|;
comment|/// PointerAccessInfo - This struct is used to return results for pointers,
comment|/// globals, and the return value of a function.
struct|struct
name|PointerAccessInfo
block|{
comment|/// V - The value this record corresponds to.  This may be an Argument for
comment|/// the function, a GlobalVariable, or null, corresponding to the return
comment|/// value for the function.
name|Value
modifier|*
name|V
decl_stmt|;
comment|/// ModRefInfo - Whether the pointer is loaded or stored to/from.
comment|///
name|ModRefResult
name|ModRefInfo
decl_stmt|;
comment|/// AccessType - Specific fine-grained access information for the argument.
comment|/// If none of these classifications is general enough, the
comment|/// getModRefBehavior method should not return AccessesArguments*.  If a
comment|/// record is not returned for a particular argument, the argument is never
comment|/// dead and never dereferenced.
enum|enum
name|AccessType
block|{
comment|/// ScalarAccess - The pointer is dereferenced.
comment|///
name|ScalarAccess
block|,
comment|/// ArrayAccess - The pointer is indexed through as an array of elements.
comment|///
name|ArrayAccess
block|,
comment|/// ElementAccess ?? P->F only?
comment|/// CallsThrough - Indirect calls are made through the specified function
comment|/// pointer.
name|CallsThrough
block|}
enum|;
block|}
struct|;
comment|/// getModRefBehavior - Return the behavior when calling the given call site.
name|virtual
name|ModRefBehavior
name|getModRefBehavior
argument_list|(
name|CallSite
name|CS
argument_list|,
name|std
operator|::
name|vector
operator|<
name|PointerAccessInfo
operator|>
operator|*
name|Info
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// getModRefBehavior - Return the behavior when calling the given function.
comment|/// For use when the call site is not known.
name|virtual
name|ModRefBehavior
name|getModRefBehavior
argument_list|(
name|Function
operator|*
name|F
argument_list|,
name|std
operator|::
name|vector
operator|<
name|PointerAccessInfo
operator|>
operator|*
name|Info
operator|=
literal|0
argument_list|)
decl_stmt|;
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
name|CallSite
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
name|CallSite
name|CS
parameter_list|)
block|{
name|ModRefBehavior
name|MRB
init|=
name|getModRefBehavior
argument_list|(
name|CS
argument_list|)
decl_stmt|;
return|return
name|MRB
operator|==
name|DoesNotAccessMemory
operator|||
name|MRB
operator|==
name|OnlyReadsMemory
return|;
block|}
comment|/// onlyReadsMemory - If the specified function is known to only read from
comment|/// non-volatile memory (or not access memory at all), return true.  For use
comment|/// when the call site is not known.
comment|///
name|bool
name|onlyReadsMemory
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
block|{
name|ModRefBehavior
name|MRB
init|=
name|getModRefBehavior
argument_list|(
name|F
argument_list|)
decl_stmt|;
return|return
name|MRB
operator|==
name|DoesNotAccessMemory
operator|||
name|MRB
operator|==
name|OnlyReadsMemory
return|;
block|}
comment|/// getModRefInfo - Return information about whether or not an instruction may
comment|/// read or write memory specified by the pointer operand.  An instruction
comment|/// that doesn't read or write memory may be trivially LICM'd for example.
comment|/// getModRefInfo (for call sites) - Return whether information about whether
comment|/// a particular call site modifies or reads the memory specified by the
comment|/// pointer.
comment|///
name|virtual
name|ModRefResult
name|getModRefInfo
parameter_list|(
name|CallSite
name|CS
parameter_list|,
name|Value
modifier|*
name|P
parameter_list|,
name|unsigned
name|Size
parameter_list|)
function_decl|;
comment|/// getModRefInfo - Return information about whether two call sites may refer
comment|/// to the same set of memory locations.  This function returns NoModRef if
comment|/// the two calls refer to disjoint memory locations, Ref if CS1 reads memory
comment|/// written by CS2, Mod if CS1 writes to memory read or written by CS2, or
comment|/// ModRef if CS1 might read or write memory accessed by CS2.
comment|///
name|virtual
name|ModRefResult
name|getModRefInfo
parameter_list|(
name|CallSite
name|CS1
parameter_list|,
name|CallSite
name|CS2
parameter_list|)
function_decl|;
comment|/// hasNoModRefInfoForCalls - Return true if the analysis has no mod/ref
comment|/// information for pairs of function calls (other than "pure" and "const"
comment|/// functions).  This can be used by clients to avoid many pointless queries.
comment|/// Remember that if you override this and chain to another analysis, you must
comment|/// make sure that it doesn't have mod/ref info either.
comment|///
name|virtual
name|bool
name|hasNoModRefInfoForCalls
argument_list|()
specifier|const
expr_stmt|;
name|public
label|:
comment|/// Convenience functions...
name|ModRefResult
name|getModRefInfo
parameter_list|(
name|LoadInst
modifier|*
name|L
parameter_list|,
name|Value
modifier|*
name|P
parameter_list|,
name|unsigned
name|Size
parameter_list|)
function_decl|;
name|ModRefResult
name|getModRefInfo
parameter_list|(
name|StoreInst
modifier|*
name|S
parameter_list|,
name|Value
modifier|*
name|P
parameter_list|,
name|unsigned
name|Size
parameter_list|)
function_decl|;
name|ModRefResult
name|getModRefInfo
parameter_list|(
name|CallInst
modifier|*
name|C
parameter_list|,
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
name|CallSite
argument_list|(
name|C
argument_list|)
argument_list|,
name|P
argument_list|,
name|Size
argument_list|)
return|;
block|}
name|ModRefResult
name|getModRefInfo
parameter_list|(
name|InvokeInst
modifier|*
name|I
parameter_list|,
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
name|CallSite
argument_list|(
name|I
argument_list|)
argument_list|,
name|P
argument_list|,
name|Size
argument_list|)
return|;
block|}
name|ModRefResult
name|getModRefInfo
parameter_list|(
name|VAArgInst
modifier|*
name|I
parameter_list|,
name|Value
modifier|*
name|P
parameter_list|,
name|unsigned
name|Size
parameter_list|)
block|{
return|return
name|AliasAnalysis
operator|::
name|ModRef
return|;
block|}
name|ModRefResult
name|getModRefInfo
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|,
name|Value
modifier|*
name|P
parameter_list|,
name|unsigned
name|Size
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
name|VAArgInst
operator|*
operator|)
name|I
argument_list|,
name|P
argument_list|,
name|Size
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
name|LoadInst
operator|*
operator|)
name|I
argument_list|,
name|P
argument_list|,
name|Size
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
name|StoreInst
operator|*
operator|)
name|I
argument_list|,
name|P
argument_list|,
name|Size
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
name|CallInst
operator|*
operator|)
name|I
argument_list|,
name|P
argument_list|,
name|Size
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
name|InvokeInst
operator|*
operator|)
name|I
argument_list|,
name|P
argument_list|,
name|Size
argument_list|)
return|;
default|default:
return|return
name|NoModRef
return|;
block|}
block|}
comment|//===--------------------------------------------------------------------===//
comment|/// Higher level methods for querying mod/ref information.
comment|///
comment|/// canBasicBlockModify - Return true if it is possible for execution of the
comment|/// specified basic block to modify the value pointed to by Ptr.
comment|///
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
name|unsigned
name|Size
parameter_list|)
function_decl|;
comment|/// canInstructionRangeModify - Return true if it is possible for the
comment|/// execution of the specified instructions to modify the value pointed to by
comment|/// Ptr.  The instructions to consider are all of the instructions in the
comment|/// range of [I1,I2] INCLUSIVE.  I1 and I2 must be in the same basic block.
comment|///
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
name|unsigned
name|Size
parameter_list|)
function_decl|;
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
comment|/// isNoAliasCall - Return true if this pointer is returned by a noalias
comment|/// function.
name|bool
name|isNoAliasCall
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// isIdentifiedObject - Return true if this pointer refers to a distinct and
comment|/// identifiable object.  This returns true for:
comment|///    Global Variables and Functions (but not Global Aliases)
comment|///    Allocas and Mallocs
comment|///    ByVal and NoAlias Arguments
comment|///    NoAlias returns
comment|///
name|bool
name|isIdentifiedObject
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_comment
comment|// Because of the way .a files work, we must force the BasicAA implementation to
end_comment

begin_comment
comment|// be pulled in if the AliasAnalysis header is included.  Otherwise we run
end_comment

begin_comment
comment|// the risk of AliasAnalysis being used, but the default implementation not
end_comment

begin_comment
comment|// being linked into the tool that uses it.
end_comment

begin_macro
name|FORCE_DEFINING_FILE_TO_BE_LINKED
argument_list|(
argument|AliasAnalysis
argument_list|)
end_macro

begin_macro
name|FORCE_DEFINING_FILE_TO_BE_LINKED
argument_list|(
argument|BasicAliasAnalysis
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

