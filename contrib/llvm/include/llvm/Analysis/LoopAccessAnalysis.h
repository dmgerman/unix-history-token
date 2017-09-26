begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/LoopAccessAnalysis.h -----------------------*- C++ -*-===//
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
comment|// This file defines the interface for the loop memory dependence framework that
end_comment

begin_comment
comment|// was originally developed for the Loop Vectorizer.
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
name|LLVM_ANALYSIS_LOOPACCESSANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_LOOPACCESSANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/EquivalenceClasses.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SetVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/AliasAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/AliasSetTracker.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/LoopAnalysisManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/ScalarEvolutionExpressions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DiagnosticInfo.h"
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

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Value
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|ScalarEvolution
decl_stmt|;
name|class
name|Loop
decl_stmt|;
name|class
name|SCEV
decl_stmt|;
name|class
name|SCEVUnionPredicate
decl_stmt|;
name|class
name|LoopAccessInfo
decl_stmt|;
name|class
name|OptimizationRemarkEmitter
decl_stmt|;
comment|/// \brief Collection of parameters shared beetween the Loop Vectorizer and the
comment|/// Loop Access Analysis.
struct|struct
name|VectorizerParams
block|{
comment|/// \brief Maximum SIMD width.
specifier|static
specifier|const
name|unsigned
name|MaxVectorWidth
decl_stmt|;
comment|/// \brief VF as overridden by the user.
specifier|static
name|unsigned
name|VectorizationFactor
decl_stmt|;
comment|/// \brief Interleave factor as overridden by the user.
specifier|static
name|unsigned
name|VectorizationInterleave
decl_stmt|;
comment|/// \brief True if force-vector-interleave was specified by the user.
specifier|static
name|bool
name|isInterleaveForced
parameter_list|()
function_decl|;
comment|/// \\brief When performing memory disambiguation checks at runtime do not
comment|/// make more than this number of comparisons.
specifier|static
name|unsigned
name|RuntimeMemoryCheckThreshold
decl_stmt|;
block|}
struct|;
comment|/// \brief Checks memory dependences among accesses to the same underlying
comment|/// object to determine whether there vectorization is legal or not (and at
comment|/// which vectorization factor).
comment|///
comment|/// Note: This class will compute a conservative dependence for access to
comment|/// different underlying pointers. Clients, such as the loop vectorizer, will
comment|/// sometimes deal these potential dependencies by emitting runtime checks.
comment|///
comment|/// We use the ScalarEvolution framework to symbolically evalutate access
comment|/// functions pairs. Since we currently don't restructure the loop we can rely
comment|/// on the program order of memory accesses to determine their safety.
comment|/// At the moment we will only deem accesses as safe for:
comment|///  * A negative constant distance assuming program order.
comment|///
comment|///      Safe: tmp = a[i + 1];     OR     a[i + 1] = x;
comment|///            a[i] = tmp;                y = a[i];
comment|///
comment|///   The latter case is safe because later checks guarantuee that there can't
comment|///   be a cycle through a phi node (that is, we check that "x" and "y" is not
comment|///   the same variable: a header phi can only be an induction or a reduction, a
comment|///   reduction can't have a memory sink, an induction can't have a memory
comment|///   source). This is important and must not be violated (or we have to
comment|///   resort to checking for cycles through memory).
comment|///
comment|///  * A positive constant distance assuming program order that is bigger
comment|///    than the biggest memory access.
comment|///
comment|///     tmp = a[i]        OR              b[i] = x
comment|///     a[i+2] = tmp                      y = b[i+2];
comment|///
comment|///     Safe distance: 2 x sizeof(a[0]), and 2 x sizeof(b[0]), respectively.
comment|///
comment|///  * Zero distances and all accesses have the same size.
comment|///
name|class
name|MemoryDepChecker
block|{
name|public
label|:
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
name|MemAccessInfo
expr_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|MemAccessInfo
operator|,
literal|8
operator|>
name|MemAccessInfoList
expr_stmt|;
comment|/// \brief Set of potential dependent memory accesses.
typedef|typedef
name|EquivalenceClasses
operator|<
name|MemAccessInfo
operator|>
name|DepCandidates
expr_stmt|;
comment|/// \brief Dependece between memory access instructions.
struct|struct
name|Dependence
block|{
comment|/// \brief The type of the dependence.
enum|enum
name|DepType
block|{
comment|// No dependence.
name|NoDep
block|,
comment|// We couldn't determine the direction or the distance.
name|Unknown
block|,
comment|// Lexically forward.
comment|//
comment|// FIXME: If we only have loop-independent forward dependences (e.g. a
comment|// read and write of A[i]), LAA will locally deem the dependence "safe"
comment|// without querying the MemoryDepChecker.  Therefore we can miss
comment|// enumerating loop-independent forward dependences in
comment|// getDependences.  Note that as soon as there are different
comment|// indices used to access the same array, the MemoryDepChecker *is*
comment|// queried and the dependence list is complete.
name|Forward
block|,
comment|// Forward, but if vectorized, is likely to prevent store-to-load
comment|// forwarding.
name|ForwardButPreventsForwarding
block|,
comment|// Lexically backward.
name|Backward
block|,
comment|// Backward, but the distance allows a vectorization factor of
comment|// MaxSafeDepDistBytes.
name|BackwardVectorizable
block|,
comment|// Same, but may prevent store-to-load forwarding.
name|BackwardVectorizableButPreventsForwarding
block|}
enum|;
comment|/// \brief String version of the types.
specifier|static
specifier|const
name|char
modifier|*
name|DepName
index|[]
decl_stmt|;
comment|/// \brief Index of the source of the dependence in the InstMap vector.
name|unsigned
name|Source
decl_stmt|;
comment|/// \brief Index of the destination of the dependence in the InstMap vector.
name|unsigned
name|Destination
decl_stmt|;
comment|/// \brief The type of the dependence.
name|DepType
name|Type
decl_stmt|;
name|Dependence
argument_list|(
argument|unsigned Source
argument_list|,
argument|unsigned Destination
argument_list|,
argument|DepType Type
argument_list|)
block|:
name|Source
argument_list|(
name|Source
argument_list|)
operator|,
name|Destination
argument_list|(
name|Destination
argument_list|)
operator|,
name|Type
argument_list|(
argument|Type
argument_list|)
block|{}
comment|/// \brief Return the source instruction of the dependence.
name|Instruction
operator|*
name|getSource
argument_list|(
argument|const LoopAccessInfo&LAI
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Return the destination instruction of the dependence.
name|Instruction
modifier|*
name|getDestination
argument_list|(
specifier|const
name|LoopAccessInfo
operator|&
name|LAI
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Dependence types that don't prevent vectorization.
specifier|static
name|bool
name|isSafeForVectorization
parameter_list|(
name|DepType
name|Type
parameter_list|)
function_decl|;
comment|/// \brief Lexically forward dependence.
name|bool
name|isForward
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Lexically backward dependence.
name|bool
name|isBackward
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief May be a lexically backward dependence type (includes Unknown).
name|bool
name|isPossiblyBackward
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Print the dependence.  \p Instr is used to map the instruction
comment|/// indices to instructions.
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|unsigned
name|Depth
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
name|Instrs
argument_list|)
decl|const
decl_stmt|;
block|}
struct|;
name|MemoryDepChecker
argument_list|(
name|PredicatedScalarEvolution
operator|&
name|PSE
argument_list|,
specifier|const
name|Loop
operator|*
name|L
argument_list|)
operator|:
name|PSE
argument_list|(
name|PSE
argument_list|)
operator|,
name|InnermostLoop
argument_list|(
name|L
argument_list|)
operator|,
name|AccessIdx
argument_list|(
literal|0
argument_list|)
operator|,
name|ShouldRetryWithRuntimeCheck
argument_list|(
name|false
argument_list|)
operator|,
name|SafeForVectorization
argument_list|(
name|true
argument_list|)
operator|,
name|RecordDependences
argument_list|(
argument|true
argument_list|)
block|{}
comment|/// \brief Register the location (instructions are given increasing numbers)
comment|/// of a write access.
name|void
name|addAccess
argument_list|(
argument|StoreInst *SI
argument_list|)
block|{
name|Value
operator|*
name|Ptr
operator|=
name|SI
operator|->
name|getPointerOperand
argument_list|()
block|;
name|Accesses
index|[
name|MemAccessInfo
argument_list|(
name|Ptr
argument_list|,
name|true
argument_list|)
index|]
operator|.
name|push_back
argument_list|(
name|AccessIdx
argument_list|)
block|;
name|InstMap
operator|.
name|push_back
argument_list|(
name|SI
argument_list|)
block|;
operator|++
name|AccessIdx
block|;   }
comment|/// \brief Register the location (instructions are given increasing numbers)
comment|/// of a write access.
name|void
name|addAccess
argument_list|(
argument|LoadInst *LI
argument_list|)
block|{
name|Value
operator|*
name|Ptr
operator|=
name|LI
operator|->
name|getPointerOperand
argument_list|()
block|;
name|Accesses
index|[
name|MemAccessInfo
argument_list|(
name|Ptr
argument_list|,
name|false
argument_list|)
index|]
operator|.
name|push_back
argument_list|(
name|AccessIdx
argument_list|)
block|;
name|InstMap
operator|.
name|push_back
argument_list|(
name|LI
argument_list|)
block|;
operator|++
name|AccessIdx
block|;   }
comment|/// \brief Check whether the dependencies between the accesses are safe.
comment|///
comment|/// Only checks sets with elements in \p CheckDeps.
name|bool
name|areDepsSafe
argument_list|(
name|DepCandidates
operator|&
name|AccessSets
argument_list|,
name|MemAccessInfoList
operator|&
name|CheckDeps
argument_list|,
specifier|const
name|ValueToValueMap
operator|&
name|Strides
argument_list|)
expr_stmt|;
comment|/// \brief No memory dependence was encountered that would inhibit
comment|/// vectorization.
name|bool
name|isSafeForVectorization
argument_list|()
specifier|const
block|{
return|return
name|SafeForVectorization
return|;
block|}
comment|/// \brief The maximum number of bytes of a vector register we can vectorize
comment|/// the accesses safely with.
name|uint64_t
name|getMaxSafeDepDistBytes
parameter_list|()
block|{
return|return
name|MaxSafeDepDistBytes
return|;
block|}
comment|/// \brief In same cases when the dependency check fails we can still
comment|/// vectorize the loop with a dynamic array access check.
name|bool
name|shouldRetryWithRuntimeCheck
parameter_list|()
block|{
return|return
name|ShouldRetryWithRuntimeCheck
return|;
block|}
comment|/// \brief Returns the memory dependences.  If null is returned we exceeded
comment|/// the MaxDependences threshold and this information is not
comment|/// available.
specifier|const
name|SmallVectorImpl
operator|<
name|Dependence
operator|>
operator|*
name|getDependences
argument_list|()
specifier|const
block|{
return|return
name|RecordDependences
operator|?
operator|&
name|Dependences
operator|:
name|nullptr
return|;
block|}
name|void
name|clearDependences
parameter_list|()
block|{
name|Dependences
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
comment|/// \brief The vector of memory access instructions.  The indices are used as
comment|/// instruction identifiers in the Dependence class.
specifier|const
name|SmallVectorImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
name|getMemoryInstructions
argument_list|()
specifier|const
block|{
return|return
name|InstMap
return|;
block|}
comment|/// \brief Generate a mapping between the memory instructions and their
comment|/// indices according to program order.
name|DenseMap
operator|<
name|Instruction
operator|*
operator|,
name|unsigned
operator|>
name|generateInstructionOrderMap
argument_list|()
specifier|const
block|{
name|DenseMap
operator|<
name|Instruction
operator|*
block|,
name|unsigned
operator|>
name|OrderMap
block|;
for|for
control|(
name|unsigned
name|I
init|=
literal|0
init|;
name|I
operator|<
name|InstMap
operator|.
name|size
argument_list|()
condition|;
operator|++
name|I
control|)
name|OrderMap
index|[
name|InstMap
index|[
name|I
index|]
index|]
operator|=
name|I
expr_stmt|;
return|return
name|OrderMap
return|;
block|}
comment|/// \brief Find the set of instructions that read or write via \p Ptr.
name|SmallVector
operator|<
name|Instruction
operator|*
operator|,
literal|4
operator|>
name|getInstructionsForAccess
argument_list|(
argument|Value *Ptr
argument_list|,
argument|bool isWrite
argument_list|)
specifier|const
expr_stmt|;
name|private
label|:
comment|/// A wrapper around ScalarEvolution, used to add runtime SCEV checks, and
comment|/// applies dynamic knowledge to simplify SCEV expressions and convert them
comment|/// to a more usable form. We need this in case assumptions about SCEV
comment|/// expressions need to be made in order to avoid unknown dependences. For
comment|/// example we might assume a unit stride for a pointer in order to prove
comment|/// that a memory access is strided and doesn't wrap.
name|PredicatedScalarEvolution
modifier|&
name|PSE
decl_stmt|;
specifier|const
name|Loop
modifier|*
name|InnermostLoop
decl_stmt|;
comment|/// \brief Maps access locations (ptr, read/write) to program order.
name|DenseMap
operator|<
name|MemAccessInfo
operator|,
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
expr|>
name|Accesses
expr_stmt|;
comment|/// \brief Memory access instructions in program order.
name|SmallVector
operator|<
name|Instruction
operator|*
operator|,
literal|16
operator|>
name|InstMap
expr_stmt|;
comment|/// \brief The program order index to be used for the next instruction.
name|unsigned
name|AccessIdx
decl_stmt|;
comment|// We can access this many bytes in parallel safely.
name|uint64_t
name|MaxSafeDepDistBytes
decl_stmt|;
comment|/// \brief If we see a non-constant dependence distance we can still try to
comment|/// vectorize this loop with runtime checks.
name|bool
name|ShouldRetryWithRuntimeCheck
decl_stmt|;
comment|/// \brief No memory dependence was encountered that would inhibit
comment|/// vectorization.
name|bool
name|SafeForVectorization
decl_stmt|;
comment|//// \brief True if Dependences reflects the dependences in the
comment|//// loop.  If false we exceeded MaxDependences and
comment|//// Dependences is invalid.
name|bool
name|RecordDependences
decl_stmt|;
comment|/// \brief Memory dependences collected during the analysis.  Only valid if
comment|/// RecordDependences is true.
name|SmallVector
operator|<
name|Dependence
operator|,
literal|8
operator|>
name|Dependences
expr_stmt|;
comment|/// \brief Check whether there is a plausible dependence between the two
comment|/// accesses.
comment|///
comment|/// Access \p A must happen before \p B in program order. The two indices
comment|/// identify the index into the program order map.
comment|///
comment|/// This function checks  whether there is a plausible dependence (or the
comment|/// absence of such can't be proved) between the two accesses. If there is a
comment|/// plausible dependence but the dependence distance is bigger than one
comment|/// element access it records this distance in \p MaxSafeDepDistBytes (if this
comment|/// distance is smaller than any other distance encountered so far).
comment|/// Otherwise, this function returns true signaling a possible dependence.
name|Dependence
operator|::
name|DepType
name|isDependent
argument_list|(
argument|const MemAccessInfo&A
argument_list|,
argument|unsigned AIdx
argument_list|,
argument|const MemAccessInfo&B
argument_list|,
argument|unsigned BIdx
argument_list|,
argument|const ValueToValueMap&Strides
argument_list|)
expr_stmt|;
comment|/// \brief Check whether the data dependence could prevent store-load
comment|/// forwarding.
comment|///
comment|/// \return false if we shouldn't vectorize at all or avoid larger
comment|/// vectorization factors by limiting MaxSafeDepDistBytes.
name|bool
name|couldPreventStoreLoadForward
parameter_list|(
name|uint64_t
name|Distance
parameter_list|,
name|uint64_t
name|TypeByteSize
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Holds information about the memory runtime legality checks to verify
end_comment

begin_comment
comment|/// that a group of pointers do not overlap.
end_comment

begin_decl_stmt
name|class
name|RuntimePointerChecking
block|{
name|public
label|:
struct|struct
name|PointerInfo
block|{
comment|/// Holds the pointer value that we need to check.
name|TrackingVH
operator|<
name|Value
operator|>
name|PointerValue
expr_stmt|;
comment|/// Holds the smallest byte address accessed by the pointer throughout all
comment|/// iterations of the loop.
specifier|const
name|SCEV
modifier|*
name|Start
decl_stmt|;
comment|/// Holds the largest byte address accessed by the pointer throughout all
comment|/// iterations of the loop, plus 1.
specifier|const
name|SCEV
modifier|*
name|End
decl_stmt|;
comment|/// Holds the information if this pointer is used for writing to memory.
name|bool
name|IsWritePtr
decl_stmt|;
comment|/// Holds the id of the set of pointers that could be dependent because of a
comment|/// shared underlying object.
name|unsigned
name|DependencySetId
decl_stmt|;
comment|/// Holds the id of the disjoint alias set to which this pointer belongs.
name|unsigned
name|AliasSetId
decl_stmt|;
comment|/// SCEV for the access.
specifier|const
name|SCEV
modifier|*
name|Expr
decl_stmt|;
name|PointerInfo
argument_list|(
argument|Value *PointerValue
argument_list|,
argument|const SCEV *Start
argument_list|,
argument|const SCEV *End
argument_list|,
argument|bool IsWritePtr
argument_list|,
argument|unsigned DependencySetId
argument_list|,
argument|unsigned AliasSetId
argument_list|,
argument|const SCEV *Expr
argument_list|)
block|:
name|PointerValue
argument_list|(
name|PointerValue
argument_list|)
operator|,
name|Start
argument_list|(
name|Start
argument_list|)
operator|,
name|End
argument_list|(
name|End
argument_list|)
operator|,
name|IsWritePtr
argument_list|(
name|IsWritePtr
argument_list|)
operator|,
name|DependencySetId
argument_list|(
name|DependencySetId
argument_list|)
operator|,
name|AliasSetId
argument_list|(
name|AliasSetId
argument_list|)
operator|,
name|Expr
argument_list|(
argument|Expr
argument_list|)
block|{}
block|}
struct|;
name|RuntimePointerChecking
argument_list|(
name|ScalarEvolution
operator|*
name|SE
argument_list|)
operator|:
name|Need
argument_list|(
name|false
argument_list|)
operator|,
name|SE
argument_list|(
argument|SE
argument_list|)
block|{}
comment|/// Reset the state of the pointer runtime information.
name|void
name|reset
argument_list|()
block|{
name|Need
operator|=
name|false
block|;
name|Pointers
operator|.
name|clear
argument_list|()
block|;
name|Checks
operator|.
name|clear
argument_list|()
block|;   }
comment|/// Insert a pointer and calculate the start and end SCEVs.
comment|/// We need \p PSE in order to compute the SCEV expression of the pointer
comment|/// according to the assumptions that we've made during the analysis.
comment|/// The method might also version the pointer stride according to \p Strides,
comment|/// and add new predicates to \p PSE.
name|void
name|insert
argument_list|(
argument|Loop *Lp
argument_list|,
argument|Value *Ptr
argument_list|,
argument|bool WritePtr
argument_list|,
argument|unsigned DepSetId
argument_list|,
argument|unsigned ASId
argument_list|,
argument|const ValueToValueMap&Strides
argument_list|,
argument|PredicatedScalarEvolution&PSE
argument_list|)
expr_stmt|;
comment|/// \brief No run-time memory checking is necessary.
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Pointers
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// A grouping of pointers. A single memcheck is required between
comment|/// two groups.
struct|struct
name|CheckingPtrGroup
block|{
comment|/// \brief Create a new pointer checking group containing a single
comment|/// pointer, with index \p Index in RtCheck.
name|CheckingPtrGroup
argument_list|(
argument|unsigned Index
argument_list|,
argument|RuntimePointerChecking&RtCheck
argument_list|)
block|:
name|RtCheck
argument_list|(
name|RtCheck
argument_list|)
operator|,
name|High
argument_list|(
name|RtCheck
operator|.
name|Pointers
index|[
name|Index
index|]
operator|.
name|End
argument_list|)
operator|,
name|Low
argument_list|(
argument|RtCheck.Pointers[Index].Start
argument_list|)
block|{
name|Members
operator|.
name|push_back
argument_list|(
name|Index
argument_list|)
block|;     }
comment|/// \brief Tries to add the pointer recorded in RtCheck at index
comment|/// \p Index to this pointer checking group. We can only add a pointer
comment|/// to a checking group if we will still be able to get
comment|/// the upper and lower bounds of the check. Returns true in case
comment|/// of success, false otherwise.
name|bool
name|addPointer
argument_list|(
argument|unsigned Index
argument_list|)
expr_stmt|;
comment|/// Constitutes the context of this pointer checking group. For each
comment|/// pointer that is a member of this group we will retain the index
comment|/// at which it appears in RtCheck.
name|RuntimePointerChecking
modifier|&
name|RtCheck
decl_stmt|;
comment|/// The SCEV expression which represents the upper bound of all the
comment|/// pointers in this group.
specifier|const
name|SCEV
modifier|*
name|High
decl_stmt|;
comment|/// The SCEV expression which represents the lower bound of all the
comment|/// pointers in this group.
specifier|const
name|SCEV
modifier|*
name|Low
decl_stmt|;
comment|/// Indices of all the pointers that constitute this grouping.
name|SmallVector
operator|<
name|unsigned
operator|,
literal|2
operator|>
name|Members
expr_stmt|;
block|}
struct|;
comment|/// \brief A memcheck which made up of a pair of grouped pointers.
comment|///
comment|/// These *have* to be const for now, since checks are generated from
comment|/// CheckingPtrGroups in LAI::addRuntimeChecks which is a const member
comment|/// function.  FIXME: once check-generation is moved inside this class (after
comment|/// the PtrPartition hack is removed), we could drop const.
typedef|typedef
name|std
operator|::
name|pair
operator|<
specifier|const
name|CheckingPtrGroup
operator|*
operator|,
specifier|const
name|CheckingPtrGroup
operator|*
operator|>
name|PointerCheck
expr_stmt|;
comment|/// \brief Generate the checks and store it.  This also performs the grouping
comment|/// of pointers to reduce the number of memchecks necessary.
name|void
name|generateChecks
argument_list|(
name|MemoryDepChecker
operator|::
name|DepCandidates
operator|&
name|DepCands
argument_list|,
name|bool
name|UseDependencies
argument_list|)
decl_stmt|;
comment|/// \brief Returns the checks that generateChecks created.
specifier|const
name|SmallVector
operator|<
name|PointerCheck
operator|,
literal|4
operator|>
operator|&
name|getChecks
argument_list|()
specifier|const
block|{
return|return
name|Checks
return|;
block|}
comment|/// \brief Decide if we need to add a check between two groups of pointers,
comment|/// according to needsChecking.
name|bool
name|needsChecking
argument_list|(
specifier|const
name|CheckingPtrGroup
operator|&
name|M
argument_list|,
specifier|const
name|CheckingPtrGroup
operator|&
name|N
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Returns the number of run-time checks required according to
comment|/// needsChecking.
name|unsigned
name|getNumberOfChecks
argument_list|()
specifier|const
block|{
return|return
name|Checks
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// \brief Print the list run-time memory checks necessary.
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|unsigned
name|Depth
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// Print \p Checks.
name|void
name|printChecks
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|PointerCheck
operator|>
operator|&
name|Checks
argument_list|,
name|unsigned
name|Depth
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// This flag indicates if we need to add the runtime check.
name|bool
name|Need
decl_stmt|;
comment|/// Information about the pointers that may require checking.
name|SmallVector
operator|<
name|PointerInfo
operator|,
literal|2
operator|>
name|Pointers
expr_stmt|;
comment|/// Holds a partitioning of pointers into "check groups".
name|SmallVector
operator|<
name|CheckingPtrGroup
operator|,
literal|2
operator|>
name|CheckingGroups
expr_stmt|;
comment|/// \brief Check if pointers are in the same partition
comment|///
comment|/// \p PtrToPartition contains the partition number for pointers (-1 if the
comment|/// pointer belongs to multiple partitions).
specifier|static
name|bool
name|arePointersInSamePartition
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|PtrToPartition
argument_list|,
name|unsigned
name|PtrIdx1
argument_list|,
name|unsigned
name|PtrIdx2
argument_list|)
decl_stmt|;
comment|/// \brief Decide whether we need to issue a run-time check for pointer at
comment|/// index \p I and \p J to prove their independence.
name|bool
name|needsChecking
argument_list|(
name|unsigned
name|I
argument_list|,
name|unsigned
name|J
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return PointerInfo for pointer at index \p PtrIdx.
specifier|const
name|PointerInfo
modifier|&
name|getPointerInfo
argument_list|(
name|unsigned
name|PtrIdx
argument_list|)
decl|const
block|{
return|return
name|Pointers
index|[
name|PtrIdx
index|]
return|;
block|}
name|private
label|:
comment|/// \brief Groups pointers such that a single memcheck is required
comment|/// between two different groups. This will clear the CheckingGroups vector
comment|/// and re-compute it. We will only group dependecies if \p UseDependencies
comment|/// is true, otherwise we will create a separate group for each pointer.
name|void
name|groupChecks
argument_list|(
name|MemoryDepChecker
operator|::
name|DepCandidates
operator|&
name|DepCands
argument_list|,
name|bool
name|UseDependencies
argument_list|)
decl_stmt|;
comment|/// Generate the checks and return them.
name|SmallVector
operator|<
name|PointerCheck
operator|,
literal|4
operator|>
name|generateChecks
argument_list|()
specifier|const
expr_stmt|;
comment|/// Holds a pointer to the ScalarEvolution analysis.
name|ScalarEvolution
modifier|*
name|SE
decl_stmt|;
comment|/// \brief Set of run-time checks required to establish independence of
comment|/// otherwise may-aliasing pointers in the loop.
name|SmallVector
operator|<
name|PointerCheck
operator|,
literal|4
operator|>
name|Checks
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Drive the analysis of memory accesses in the loop
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This class is responsible for analyzing the memory accesses of a loop.  It
end_comment

begin_comment
comment|/// collects the accesses and then its main helper the AccessAnalysis class
end_comment

begin_comment
comment|/// finds and categorizes the dependences in buildDependenceSets.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For memory dependences that can be analyzed at compile time, it determines
end_comment

begin_comment
comment|/// whether the dependence is part of cycle inhibiting vectorization.  This work
end_comment

begin_comment
comment|/// is delegated to the MemoryDepChecker class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For memory dependences that cannot be determined at compile time, it
end_comment

begin_comment
comment|/// generates run-time checks to prove independence.  This is done by
end_comment

begin_comment
comment|/// AccessAnalysis::canCheckPtrAtRT and the checks are maintained by the
end_comment

begin_comment
comment|/// RuntimePointerCheck class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If pointers can wrap or can't be expressed as affine AddRec expressions by
end_comment

begin_comment
comment|/// ScalarEvolution, we will generate run-time checks by emitting a
end_comment

begin_comment
comment|/// SCEVUnionPredicate.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Checks for both memory dependences and the SCEV predicates contained in the
end_comment

begin_comment
comment|/// PSE must be emitted in order for the results of this analysis to be valid.
end_comment

begin_decl_stmt
name|class
name|LoopAccessInfo
block|{
name|public
label|:
name|LoopAccessInfo
argument_list|(
name|Loop
operator|*
name|L
argument_list|,
name|ScalarEvolution
operator|*
name|SE
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|*
name|TLI
argument_list|,
name|AliasAnalysis
operator|*
name|AA
argument_list|,
name|DominatorTree
operator|*
name|DT
argument_list|,
name|LoopInfo
operator|*
name|LI
argument_list|)
expr_stmt|;
comment|/// Return true we can analyze the memory accesses in the loop and there are
comment|/// no memory dependence cycles.
name|bool
name|canVectorizeMemory
argument_list|()
specifier|const
block|{
return|return
name|CanVecMem
return|;
block|}
specifier|const
name|RuntimePointerChecking
operator|*
name|getRuntimePointerChecking
argument_list|()
specifier|const
block|{
return|return
name|PtrRtChecking
operator|.
name|get
argument_list|()
return|;
block|}
comment|/// \brief Number of memchecks required to prove independence of otherwise
comment|/// may-alias pointers.
name|unsigned
name|getNumRuntimePointerChecks
argument_list|()
specifier|const
block|{
return|return
name|PtrRtChecking
operator|->
name|getNumberOfChecks
argument_list|()
return|;
block|}
comment|/// Return true if the block BB needs to be predicated in order for the loop
comment|/// to be vectorized.
specifier|static
name|bool
name|blockNeedsPredication
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|,
name|Loop
modifier|*
name|TheLoop
parameter_list|,
name|DominatorTree
modifier|*
name|DT
parameter_list|)
function_decl|;
comment|/// Returns true if the value V is uniform within the loop.
name|bool
name|isUniform
argument_list|(
name|Value
operator|*
name|V
argument_list|)
decl|const
decl_stmt|;
name|uint64_t
name|getMaxSafeDepDistBytes
argument_list|()
specifier|const
block|{
return|return
name|MaxSafeDepDistBytes
return|;
block|}
name|unsigned
name|getNumStores
argument_list|()
specifier|const
block|{
return|return
name|NumStores
return|;
block|}
name|unsigned
name|getNumLoads
argument_list|()
specifier|const
block|{
return|return
name|NumLoads
return|;
block|}
comment|/// \brief Add code that checks at runtime if the accessed arrays overlap.
comment|///
comment|/// Returns a pair of instructions where the first element is the first
comment|/// instruction generated in possibly a sequence of instructions and the
comment|/// second value is the final comparator value or NULL if no check is needed.
name|std
operator|::
name|pair
operator|<
name|Instruction
operator|*
operator|,
name|Instruction
operator|*
operator|>
name|addRuntimeChecks
argument_list|(
argument|Instruction *Loc
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Generete the instructions for the checks in \p PointerChecks.
comment|///
comment|/// Returns a pair of instructions where the first element is the first
comment|/// instruction generated in possibly a sequence of instructions and the
comment|/// second value is the final comparator value or NULL if no check is needed.
name|std
operator|::
name|pair
operator|<
name|Instruction
operator|*
operator|,
name|Instruction
operator|*
operator|>
name|addRuntimeChecks
argument_list|(
argument|Instruction *Loc
argument_list|,
argument|const SmallVectorImpl<RuntimePointerChecking::PointerCheck>&PointerChecks
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief The diagnostics report generated for the analysis.  E.g. why we
comment|/// couldn't analyze the loop.
specifier|const
name|OptimizationRemarkAnalysis
operator|*
name|getReport
argument_list|()
specifier|const
block|{
return|return
name|Report
operator|.
name|get
argument_list|()
return|;
block|}
comment|/// \brief the Memory Dependence Checker which can determine the
comment|/// loop-independent and loop-carried dependences between memory accesses.
specifier|const
name|MemoryDepChecker
operator|&
name|getDepChecker
argument_list|()
specifier|const
block|{
return|return
operator|*
name|DepChecker
return|;
block|}
comment|/// \brief Return the list of instructions that use \p Ptr to read or write
comment|/// memory.
name|SmallVector
operator|<
name|Instruction
operator|*
operator|,
literal|4
operator|>
name|getInstructionsForAccess
argument_list|(
argument|Value *Ptr
argument_list|,
argument|bool isWrite
argument_list|)
specifier|const
block|{
return|return
name|DepChecker
operator|->
name|getInstructionsForAccess
argument_list|(
name|Ptr
argument_list|,
name|isWrite
argument_list|)
return|;
block|}
comment|/// \brief If an access has a symbolic strides, this maps the pointer value to
comment|/// the stride symbol.
specifier|const
name|ValueToValueMap
operator|&
name|getSymbolicStrides
argument_list|()
specifier|const
block|{
return|return
name|SymbolicStrides
return|;
block|}
comment|/// \brief Pointer has a symbolic stride.
name|bool
name|hasStride
argument_list|(
name|Value
operator|*
name|V
argument_list|)
decl|const
block|{
return|return
name|StrideSet
operator|.
name|count
argument_list|(
name|V
argument_list|)
return|;
block|}
comment|/// \brief Print the information about the memory accesses in the loop.
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|unsigned
name|Depth
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Checks existence of store to invariant address inside loop.
comment|/// If the loop has any store to invariant address, then it returns true,
comment|/// else returns false.
name|bool
name|hasStoreToLoopInvariantAddress
argument_list|()
specifier|const
block|{
return|return
name|StoreToLoopInvariantAddress
return|;
block|}
comment|/// Used to add runtime SCEV checks. Simplifies SCEV expressions and converts
comment|/// them to a more usable form.  All SCEV expressions during the analysis
comment|/// should be re-written (and therefore simplified) according to PSE.
comment|/// A user of LoopAccessAnalysis will need to emit the runtime checks
comment|/// associated with this predicate.
specifier|const
name|PredicatedScalarEvolution
operator|&
name|getPSE
argument_list|()
specifier|const
block|{
return|return
operator|*
name|PSE
return|;
block|}
name|private
label|:
comment|/// \brief Analyze the loop.
name|void
name|analyzeLoop
parameter_list|(
name|AliasAnalysis
modifier|*
name|AA
parameter_list|,
name|LoopInfo
modifier|*
name|LI
parameter_list|,
specifier|const
name|TargetLibraryInfo
modifier|*
name|TLI
parameter_list|,
name|DominatorTree
modifier|*
name|DT
parameter_list|)
function_decl|;
comment|/// \brief Check if the structure of the loop allows it to be analyzed by this
comment|/// pass.
name|bool
name|canAnalyzeLoop
parameter_list|()
function_decl|;
comment|/// \brief Save the analysis remark.
comment|///
comment|/// LAA does not directly emits the remarks.  Instead it stores it which the
comment|/// client can retrieve and presents as its own analysis
comment|/// (e.g. -Rpass-analysis=loop-vectorize).
name|OptimizationRemarkAnalysis
modifier|&
name|recordAnalysis
parameter_list|(
name|StringRef
name|RemarkName
parameter_list|,
name|Instruction
modifier|*
name|Instr
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// \brief Collect memory access with loop invariant strides.
comment|///
comment|/// Looks for accesses like "a[i * StrideA]" where "StrideA" is loop
comment|/// invariant.
name|void
name|collectStridedAccess
parameter_list|(
name|Value
modifier|*
name|LoadOrStoreInst
parameter_list|)
function_decl|;
name|std
operator|::
name|unique_ptr
operator|<
name|PredicatedScalarEvolution
operator|>
name|PSE
expr_stmt|;
comment|/// We need to check that all of the pointers in this list are disjoint
comment|/// at runtime. Using std::unique_ptr to make using move ctor simpler.
name|std
operator|::
name|unique_ptr
operator|<
name|RuntimePointerChecking
operator|>
name|PtrRtChecking
expr_stmt|;
comment|/// \brief the Memory Dependence Checker which can determine the
comment|/// loop-independent and loop-carried dependences between memory accesses.
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryDepChecker
operator|>
name|DepChecker
expr_stmt|;
name|Loop
modifier|*
name|TheLoop
decl_stmt|;
name|unsigned
name|NumLoads
decl_stmt|;
name|unsigned
name|NumStores
decl_stmt|;
name|uint64_t
name|MaxSafeDepDistBytes
decl_stmt|;
comment|/// \brief Cache the result of analyzeLoop.
name|bool
name|CanVecMem
decl_stmt|;
comment|/// \brief Indicator for storing to uniform addresses.
comment|/// If a loop has write to a loop invariant address then it should be true.
name|bool
name|StoreToLoopInvariantAddress
decl_stmt|;
comment|/// \brief The diagnostics report generated for the analysis.  E.g. why we
comment|/// couldn't analyze the loop.
name|std
operator|::
name|unique_ptr
operator|<
name|OptimizationRemarkAnalysis
operator|>
name|Report
expr_stmt|;
comment|/// \brief If an access has a symbolic strides, this maps the pointer value to
comment|/// the stride symbol.
name|ValueToValueMap
name|SymbolicStrides
decl_stmt|;
comment|/// \brief Set of symbolic strides values.
name|SmallPtrSet
operator|<
name|Value
operator|*
operator|,
literal|8
operator|>
name|StrideSet
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
name|Value
modifier|*
name|stripIntegerCast
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Return the SCEV corresponding to a pointer with the symbolic stride
end_comment

begin_comment
comment|/// replaced with constant one, assuming the SCEV predicate associated with
end_comment

begin_comment
comment|/// \p PSE is true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If necessary this method will version the stride of the pointer according
end_comment

begin_comment
comment|/// to \p PtrToStride and therefore add further predicates to \p PSE.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If \p OrigPtr is not null, use it to look up the stride value instead of \p
end_comment

begin_comment
comment|/// Ptr.  \p PtrToStride provides the mapping between the pointer value and its
end_comment

begin_comment
comment|/// stride as collected by LoopVectorizationLegality::collectStridedAccess.
end_comment

begin_function_decl
specifier|const
name|SCEV
modifier|*
name|replaceSymbolicStrideSCEV
parameter_list|(
name|PredicatedScalarEvolution
modifier|&
name|PSE
parameter_list|,
specifier|const
name|ValueToValueMap
modifier|&
name|PtrToStride
parameter_list|,
name|Value
modifier|*
name|Ptr
parameter_list|,
name|Value
modifier|*
name|OrigPtr
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief If the pointer has a constant stride return it in units of its
end_comment

begin_comment
comment|/// element size.  Otherwise return zero.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Ensure that it does not wrap in the address space, assuming the predicate
end_comment

begin_comment
comment|/// associated with \p PSE is true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If necessary this method will version the stride of the pointer according
end_comment

begin_comment
comment|/// to \p PtrToStride and therefore add further predicates to \p PSE.
end_comment

begin_comment
comment|/// The \p Assume parameter indicates if we are allowed to make additional
end_comment

begin_comment
comment|/// run-time assumptions.
end_comment

begin_function_decl
name|int64_t
name|getPtrStride
parameter_list|(
name|PredicatedScalarEvolution
modifier|&
name|PSE
parameter_list|,
name|Value
modifier|*
name|Ptr
parameter_list|,
specifier|const
name|Loop
modifier|*
name|Lp
parameter_list|,
specifier|const
name|ValueToValueMap
modifier|&
name|StridesMap
init|=
name|ValueToValueMap
argument_list|()
parameter_list|,
name|bool
name|Assume
init|=
name|false
parameter_list|,
name|bool
name|ShouldCheckWrap
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Returns true if the memory operations \p A and \p B are consecutive.
end_comment

begin_comment
comment|/// This is a simple API that does not depend on the analysis pass.
end_comment

begin_function_decl
name|bool
name|isConsecutiveAccess
parameter_list|(
name|Value
modifier|*
name|A
parameter_list|,
name|Value
modifier|*
name|B
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|,
name|ScalarEvolution
modifier|&
name|SE
parameter_list|,
name|bool
name|CheckType
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief This analysis provides dependence information for the memory accesses
end_comment

begin_comment
comment|/// of a loop.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// It runs the analysis for a loop on demand.  This can be initiated by
end_comment

begin_comment
comment|/// querying the loop access info via LAA::getInfo.  getInfo return a
end_comment

begin_comment
comment|/// LoopAccessInfo object.  See this class for the specifics of what information
end_comment

begin_comment
comment|/// is provided.
end_comment

begin_decl_stmt
name|class
name|LoopAccessLegacyAnalysis
range|:
name|public
name|FunctionPass
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|LoopAccessLegacyAnalysis
argument_list|()
operator|:
name|FunctionPass
argument_list|(
argument|ID
argument_list|)
block|{
name|initializeLoopAccessLegacyAnalysisPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;   }
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
block|;
comment|/// \brief Query the result of the loop access information for the loop \p L.
comment|///
comment|/// If there is no cached result available run the analysis.
specifier|const
name|LoopAccessInfo
operator|&
name|getInfo
argument_list|(
name|Loop
operator|*
name|L
argument_list|)
block|;
name|void
name|releaseMemory
argument_list|()
name|override
block|{
comment|// Invalidate the cache when the pass is freed.
name|LoopAccessInfoMap
operator|.
name|clear
argument_list|()
block|;   }
comment|/// \brief Print the result of the analysis when invoked with -analyze.
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const Module *M = nullptr
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
comment|/// \brief The cache.
name|DenseMap
operator|<
name|Loop
operator|*
block|,
name|std
operator|::
name|unique_ptr
operator|<
name|LoopAccessInfo
operator|>>
name|LoopAccessInfoMap
block|;
comment|// The used analysis passes.
name|ScalarEvolution
operator|*
name|SE
block|;
specifier|const
name|TargetLibraryInfo
operator|*
name|TLI
block|;
name|AliasAnalysis
operator|*
name|AA
block|;
name|DominatorTree
operator|*
name|DT
block|;
name|LoopInfo
operator|*
name|LI
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief This analysis provides dependence information for the memory
end_comment

begin_comment
comment|/// accesses of a loop.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// It runs the analysis for a loop on demand.  This can be initiated by
end_comment

begin_comment
comment|/// querying the loop access info via AM.getResult<LoopAccessAnalysis>.
end_comment

begin_comment
comment|/// getResult return a LoopAccessInfo object.  See this class for the
end_comment

begin_comment
comment|/// specifics of what information is provided.
end_comment

begin_decl_stmt
name|class
name|LoopAccessAnalysis
range|:
name|public
name|AnalysisInfoMixin
operator|<
name|LoopAccessAnalysis
operator|>
block|{
name|friend
name|AnalysisInfoMixin
operator|<
name|LoopAccessAnalysis
operator|>
block|;
specifier|static
name|AnalysisKey
name|Key
block|;
name|public
operator|:
typedef|typedef
name|LoopAccessInfo
name|Result
typedef|;
name|Result
name|run
argument_list|(
name|Loop
operator|&
name|L
argument_list|,
name|LoopAnalysisManager
operator|&
name|AM
argument_list|,
name|LoopStandardAnalysisResults
operator|&
name|AR
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
specifier|inline
name|Instruction
operator|*
name|MemoryDepChecker
operator|::
name|Dependence
operator|::
name|getSource
argument_list|(
argument|const LoopAccessInfo&LAI
argument_list|)
specifier|const
block|{
return|return
name|LAI
operator|.
name|getDepChecker
argument_list|()
operator|.
name|getMemoryInstructions
argument_list|()
index|[
name|Source
index|]
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|Instruction
operator|*
name|MemoryDepChecker
operator|::
name|Dependence
operator|::
name|getDestination
argument_list|(
argument|const LoopAccessInfo&LAI
argument_list|)
specifier|const
block|{
return|return
name|LAI
operator|.
name|getDepChecker
argument_list|()
operator|.
name|getMemoryInstructions
argument_list|()
index|[
name|Destination
index|]
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

