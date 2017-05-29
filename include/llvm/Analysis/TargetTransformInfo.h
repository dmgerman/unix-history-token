begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- TargetTransformInfo.h ------------------------------------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|/// This pass exposes codegen information to IR-level passes. Every
end_comment

begin_comment
comment|/// transformation that uses codegen information is broken into three parts:
end_comment

begin_comment
comment|/// 1. The IR-level analysis pass.
end_comment

begin_comment
comment|/// 2. The IR-level transformation interface which provides the needed
end_comment

begin_comment
comment|///    information.
end_comment

begin_comment
comment|/// 3. Codegen-level implementation which uses target-specific hooks.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This file defines #2, which is the interface that IR-level transformations
end_comment

begin_comment
comment|/// use for querying the codegen.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ANALYSIS_TARGETTRANSFORMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_TARGETTRANSFORMINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/IntrinsicInst.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Intrinsics.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Operator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|Loop
decl_stmt|;
name|class
name|ScalarEvolution
decl_stmt|;
name|class
name|SCEV
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|User
decl_stmt|;
name|class
name|Value
decl_stmt|;
comment|/// \brief Information about a load/store intrinsic defined by the target.
struct|struct
name|MemIntrinsicInfo
block|{
comment|/// This is the pointer that the intrinsic is loading from or storing to.
comment|/// If this is non-null, then analysis/optimization passes can assume that
comment|/// this intrinsic is functionally equivalent to a load/store from this
comment|/// pointer.
name|Value
modifier|*
name|PtrVal
init|=
name|nullptr
decl_stmt|;
comment|// Ordering for atomic operations.
name|AtomicOrdering
name|Ordering
init|=
name|AtomicOrdering
operator|::
name|NotAtomic
decl_stmt|;
comment|// Same Id is set by the target for corresponding load/store intrinsics.
name|unsigned
name|short
name|MatchingId
init|=
literal|0
decl_stmt|;
name|bool
name|ReadMem
init|=
name|false
decl_stmt|;
name|bool
name|WriteMem
init|=
name|false
decl_stmt|;
name|bool
name|IsVolatile
init|=
name|false
decl_stmt|;
name|bool
name|isUnordered
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Ordering
operator|==
name|AtomicOrdering
operator|::
name|NotAtomic
operator|||
name|Ordering
operator|==
name|AtomicOrdering
operator|::
name|Unordered
operator|)
operator|&&
operator|!
name|IsVolatile
return|;
block|}
block|}
struct|;
comment|/// \brief This pass provides access to the codegen interfaces that are needed
comment|/// for IR-level transformations.
name|class
name|TargetTransformInfo
block|{
name|public
label|:
comment|/// \brief Construct a TTI object using a type implementing the \c Concept
comment|/// API below.
comment|///
comment|/// This is used by targets to construct a TTI wrapping their target-specific
comment|/// implementaion that encodes appropriate costs for their target.
name|template
operator|<
name|typename
name|T
operator|>
name|TargetTransformInfo
argument_list|(
argument|T Impl
argument_list|)
expr_stmt|;
comment|/// \brief Construct a baseline TTI object using a minimal implementation of
comment|/// the \c Concept API below.
comment|///
comment|/// The TTI implementation will reflect the information in the DataLayout
comment|/// provided if non-null.
name|explicit
name|TargetTransformInfo
parameter_list|(
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|)
function_decl|;
comment|// Provide move semantics.
name|TargetTransformInfo
argument_list|(
name|TargetTransformInfo
operator|&&
name|Arg
argument_list|)
expr_stmt|;
name|TargetTransformInfo
modifier|&
name|operator
init|=
operator|(
name|TargetTransformInfo
operator|&&
name|RHS
operator|)
decl_stmt|;
comment|// We need to define the destructor out-of-line to define our sub-classes
comment|// out-of-line.
operator|~
name|TargetTransformInfo
argument_list|()
expr_stmt|;
comment|/// \brief Handle the invalidation of this information.
comment|///
comment|/// When used as a result of \c TargetIRAnalysis this method will be called
comment|/// when the function this was computed for changes. When it returns false,
comment|/// the information is preserved across those changes.
name|bool
name|invalidate
argument_list|(
name|Function
operator|&
argument_list|,
specifier|const
name|PreservedAnalyses
operator|&
argument_list|,
name|FunctionAnalysisManager
operator|::
name|Invalidator
operator|&
argument_list|)
block|{
comment|// FIXME: We should probably in some way ensure that the subtarget
comment|// information for a function hasn't changed.
return|return
name|false
return|;
block|}
comment|/// \name Generic Target Information
comment|/// @{
comment|/// \brief Underlying constants for 'cost' values in this interface.
comment|///
comment|/// Many APIs in this interface return a cost. This enum defines the
comment|/// fundamental values that should be used to interpret (and produce) those
comment|/// costs. The costs are returned as an int rather than a member of this
comment|/// enumeration because it is expected that the cost of one IR instruction
comment|/// may have a multiplicative factor to it or otherwise won't fit directly
comment|/// into the enum. Moreover, it is common to sum or average costs which works
comment|/// better as simple integral values. Thus this enum only provides constants.
comment|/// Also note that the returned costs are signed integers to make it natural
comment|/// to add, subtract, and test with zero (a common boundary condition). It is
comment|/// not expected that 2^32 is a realistic cost to be modeling at any point.
comment|///
comment|/// Note that these costs should usually reflect the intersection of code-size
comment|/// cost and execution cost. A free instruction is typically one that folds
comment|/// into another instruction. For example, reg-to-reg moves can often be
comment|/// skipped by renaming the registers in the CPU, but they still are encoded
comment|/// and thus wouldn't be considered 'free' here.
enum|enum
name|TargetCostConstants
block|{
name|TCC_Free
init|=
literal|0
block|,
comment|///< Expected to fold away in lowering.
name|TCC_Basic
init|=
literal|1
block|,
comment|///< The cost of a typical 'add' instruction.
name|TCC_Expensive
init|=
literal|4
comment|///< The cost of a 'div' instruction on x86.
block|}
enum|;
comment|/// \brief Estimate the cost of a specific operation when lowered.
comment|///
comment|/// Note that this is designed to work on an arbitrary synthetic opcode, and
comment|/// thus work for hypothetical queries before an instruction has even been
comment|/// formed. However, this does *not* work for GEPs, and must not be called
comment|/// for a GEP instruction. Instead, use the dedicated getGEPCost interface as
comment|/// analyzing a GEP's cost required more information.
comment|///
comment|/// Typically only the result type is required, and the operand type can be
comment|/// omitted. However, if the opcode is one of the cast instructions, the
comment|/// operand type is required.
comment|///
comment|/// The returned cost is defined in terms of \c TargetCostConstants, see its
comment|/// comments for a detailed explanation of the cost values.
name|int
name|getOperationCost
argument_list|(
name|unsigned
name|Opcode
argument_list|,
name|Type
operator|*
name|Ty
argument_list|,
name|Type
operator|*
name|OpTy
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Estimate the cost of a GEP operation when lowered.
comment|///
comment|/// The contract for this function is the same as \c getOperationCost except
comment|/// that it supports an interface that provides extra information specific to
comment|/// the GEP operation.
name|int
name|getGEPCost
argument_list|(
name|Type
operator|*
name|PointeeType
argument_list|,
specifier|const
name|Value
operator|*
name|Ptr
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Value
operator|*
operator|>
name|Operands
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Estimate the cost of a function call when lowered.
comment|///
comment|/// The contract for this is the same as \c getOperationCost except that it
comment|/// supports an interface that provides extra information specific to call
comment|/// instructions.
comment|///
comment|/// This is the most basic query for estimating call cost: it only knows the
comment|/// function type and (potentially) the number of arguments at the call site.
comment|/// The latter is only interesting for varargs function types.
name|int
name|getCallCost
argument_list|(
name|FunctionType
operator|*
name|FTy
argument_list|,
name|int
name|NumArgs
operator|=
operator|-
literal|1
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Estimate the cost of calling a specific function when lowered.
comment|///
comment|/// This overload adds the ability to reason about the particular function
comment|/// being called in the event it is a library call with special lowering.
name|int
name|getCallCost
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|,
name|int
name|NumArgs
operator|=
operator|-
literal|1
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Estimate the cost of calling a specific function when lowered.
comment|///
comment|/// This overload allows specifying a set of candidate argument values.
name|int
name|getCallCost
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Value
operator|*
operator|>
name|Arguments
argument_list|)
decl|const
decl_stmt|;
comment|/// \returns A value by which our inlining threshold should be multiplied.
comment|/// This is primarily used to bump up the inlining threshold wholesale on
comment|/// targets where calls are unusually expensive.
comment|///
comment|/// TODO: This is a rather blunt instrument.  Perhaps altering the costs of
comment|/// individual classes of instructions would be better.
name|unsigned
name|getInliningThresholdMultiplier
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Estimate the cost of an intrinsic when lowered.
comment|///
comment|/// Mirrors the \c getCallCost method but uses an intrinsic identifier.
name|int
name|getIntrinsicCost
argument_list|(
name|Intrinsic
operator|::
name|ID
name|IID
argument_list|,
name|Type
operator|*
name|RetTy
argument_list|,
name|ArrayRef
operator|<
name|Type
operator|*
operator|>
name|ParamTys
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Estimate the cost of an intrinsic when lowered.
comment|///
comment|/// Mirrors the \c getCallCost method but uses an intrinsic identifier.
name|int
name|getIntrinsicCost
argument_list|(
name|Intrinsic
operator|::
name|ID
name|IID
argument_list|,
name|Type
operator|*
name|RetTy
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Value
operator|*
operator|>
name|Arguments
argument_list|)
decl|const
decl_stmt|;
comment|/// \return The estimated number of case clusters when lowering \p 'SI'.
comment|/// \p JTSize Set a jump table size only when \p SI is suitable for a jump
comment|/// table.
name|unsigned
name|getEstimatedNumberOfCaseClusters
argument_list|(
specifier|const
name|SwitchInst
operator|&
name|SI
argument_list|,
name|unsigned
operator|&
name|JTSize
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Estimate the cost of a given IR user when lowered.
comment|///
comment|/// This can estimate the cost of either a ConstantExpr or Instruction when
comment|/// lowered. It has two primary advantages over the \c getOperationCost and
comment|/// \c getGEPCost above, and one significant disadvantage: it can only be
comment|/// used when the IR construct has already been formed.
comment|///
comment|/// The advantages are that it can inspect the SSA use graph to reason more
comment|/// accurately about the cost. For example, all-constant-GEPs can often be
comment|/// folded into a load or other instruction, but if they are used in some
comment|/// other context they may not be folded. This routine can distinguish such
comment|/// cases.
comment|///
comment|/// The returned cost is defined in terms of \c TargetCostConstants, see its
comment|/// comments for a detailed explanation of the cost values.
name|int
name|getUserCost
argument_list|(
specifier|const
name|User
operator|*
name|U
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return true if branch divergence exists.
comment|///
comment|/// Branch divergence has a significantly negative impact on GPU performance
comment|/// when threads in the same wavefront take different paths due to conditional
comment|/// branches.
name|bool
name|hasBranchDivergence
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Returns whether V is a source of divergence.
comment|///
comment|/// This function provides the target-dependent information for
comment|/// the target-independent DivergenceAnalysis. DivergenceAnalysis first
comment|/// builds the dependency graph, and then runs the reachability algorithm
comment|/// starting with the sources of divergence.
name|bool
name|isSourceOfDivergence
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|)
decl|const
decl_stmt|;
comment|/// Returns the address space ID for a target's 'flat' address space. Note
comment|/// this is not necessarily the same as addrspace(0), which LLVM sometimes
comment|/// refers to as the generic address space. The flat address space is a
comment|/// generic address space that can be used access multiple segments of memory
comment|/// with different address spaces. Access of a memory location through a
comment|/// pointer with this address space is expected to be legal but slower
comment|/// compared to the same memory location accessed through a pointer with a
comment|/// different address space.
comment|//
comment|/// This is for for targets with different pointer representations which can
comment|/// be converted with the addrspacecast instruction. If a pointer is converted
comment|/// to this address space, optimizations should attempt to replace the access
comment|/// with the source address space.
comment|///
comment|/// \returns ~0u if the target does not have such a flat address space to
comment|/// optimize away.
name|unsigned
name|getFlatAddressSpace
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Test whether calls to a function lower to actual program function
comment|/// calls.
comment|///
comment|/// The idea is to test whether the program is likely to require a 'call'
comment|/// instruction or equivalent in order to call the given function.
comment|///
comment|/// FIXME: It's not clear that this is a good or useful query API. Client's
comment|/// should probably move to simpler cost metrics using the above.
comment|/// Alternatively, we could split the cost interface into distinct code-size
comment|/// and execution-speed costs. This would allow modelling the core of this
comment|/// query more accurately as a call is a single small instruction, but
comment|/// incurs significant execution cost.
name|bool
name|isLoweredToCall
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|)
decl|const
decl_stmt|;
comment|/// Parameters that control the generic loop unrolling transformation.
struct|struct
name|UnrollingPreferences
block|{
comment|/// The cost threshold for the unrolled loop. Should be relative to the
comment|/// getUserCost values returned by this API, and the expectation is that
comment|/// the unrolled loop's instructions when run through that interface should
comment|/// not exceed this cost. However, this is only an estimate. Also, specific
comment|/// loops may be unrolled even with a cost above this threshold if deemed
comment|/// profitable. Set this to UINT_MAX to disable the loop body cost
comment|/// restriction.
name|unsigned
name|Threshold
decl_stmt|;
comment|/// If complete unrolling will reduce the cost of the loop, we will boost
comment|/// the Threshold by a certain percent to allow more aggressive complete
comment|/// unrolling. This value provides the maximum boost percentage that we
comment|/// can apply to Threshold (The value should be no less than 100).
comment|/// BoostedThreshold = Threshold * min(RolledCost / UnrolledCost,
comment|///                                    MaxPercentThresholdBoost / 100)
comment|/// E.g. if complete unrolling reduces the loop execution time by 50%
comment|/// then we boost the threshold by the factor of 2x. If unrolling is not
comment|/// expected to reduce the running time, then we do not increase the
comment|/// threshold.
name|unsigned
name|MaxPercentThresholdBoost
decl_stmt|;
comment|/// The cost threshold for the unrolled loop when optimizing for size (set
comment|/// to UINT_MAX to disable).
name|unsigned
name|OptSizeThreshold
decl_stmt|;
comment|/// The cost threshold for the unrolled loop, like Threshold, but used
comment|/// for partial/runtime unrolling (set to UINT_MAX to disable).
name|unsigned
name|PartialThreshold
decl_stmt|;
comment|/// The cost threshold for the unrolled loop when optimizing for size, like
comment|/// OptSizeThreshold, but used for partial/runtime unrolling (set to
comment|/// UINT_MAX to disable).
name|unsigned
name|PartialOptSizeThreshold
decl_stmt|;
comment|/// A forced unrolling factor (the number of concatenated bodies of the
comment|/// original loop in the unrolled loop body). When set to 0, the unrolling
comment|/// transformation will select an unrolling factor based on the current cost
comment|/// threshold and other factors.
name|unsigned
name|Count
decl_stmt|;
comment|/// A forced peeling factor (the number of bodied of the original loop
comment|/// that should be peeled off before the loop body). When set to 0, the
comment|/// unrolling transformation will select a peeling factor based on profile
comment|/// information and other factors.
name|unsigned
name|PeelCount
decl_stmt|;
comment|/// Default unroll count for loops with run-time trip count.
name|unsigned
name|DefaultUnrollRuntimeCount
decl_stmt|;
comment|// Set the maximum unrolling factor. The unrolling factor may be selected
comment|// using the appropriate cost threshold, but may not exceed this number
comment|// (set to UINT_MAX to disable). This does not apply in cases where the
comment|// loop is being fully unrolled.
name|unsigned
name|MaxCount
decl_stmt|;
comment|/// Set the maximum unrolling factor for full unrolling. Like MaxCount, but
comment|/// applies even if full unrolling is selected. This allows a target to fall
comment|/// back to Partial unrolling if full unrolling is above FullUnrollMaxCount.
name|unsigned
name|FullUnrollMaxCount
decl_stmt|;
comment|// Represents number of instructions optimized when "back edge"
comment|// becomes "fall through" in unrolled loop.
comment|// For now we count a conditional branch on a backedge and a comparison
comment|// feeding it.
name|unsigned
name|BEInsns
decl_stmt|;
comment|/// Allow partial unrolling (unrolling of loops to expand the size of the
comment|/// loop body, not only to eliminate small constant-trip-count loops).
name|bool
name|Partial
decl_stmt|;
comment|/// Allow runtime unrolling (unrolling of loops to expand the size of the
comment|/// loop body even when the number of loop iterations is not known at
comment|/// compile time).
name|bool
name|Runtime
decl_stmt|;
comment|/// Allow generation of a loop remainder (extra iterations after unroll).
name|bool
name|AllowRemainder
decl_stmt|;
comment|/// Allow emitting expensive instructions (such as divisions) when computing
comment|/// the trip count of a loop for runtime unrolling.
name|bool
name|AllowExpensiveTripCount
decl_stmt|;
comment|/// Apply loop unroll on any kind of loop
comment|/// (mainly to loops that fail runtime unrolling).
name|bool
name|Force
decl_stmt|;
comment|/// Allow using trip count upper bound to unroll loops.
name|bool
name|UpperBound
decl_stmt|;
comment|/// Allow peeling off loop iterations for loops with low dynamic tripcount.
name|bool
name|AllowPeeling
decl_stmt|;
block|}
struct|;
comment|/// \brief Get target-customized preferences for the generic loop unrolling
comment|/// transformation. The caller will initialize UP with the current
comment|/// target-independent defaults.
name|void
name|getUnrollingPreferences
argument_list|(
name|Loop
operator|*
name|L
argument_list|,
name|UnrollingPreferences
operator|&
name|UP
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
comment|/// \name Scalar Target Information
comment|/// @{
comment|/// \brief Flags indicating the kind of support for population count.
comment|///
comment|/// Compared to the SW implementation, HW support is supposed to
comment|/// significantly boost the performance when the population is dense, and it
comment|/// may or may not degrade performance if the population is sparse. A HW
comment|/// support is considered as "Fast" if it can outperform, or is on a par
comment|/// with, SW implementation when the population is sparse; otherwise, it is
comment|/// considered as "Slow".
enum|enum
name|PopcntSupportKind
block|{
name|PSK_Software
block|,
name|PSK_SlowHardware
block|,
name|PSK_FastHardware
block|}
enum|;
comment|/// \brief Return true if the specified immediate is legal add immediate, that
comment|/// is the target has add instructions which can add a register with the
comment|/// immediate without having to materialize the immediate into a register.
name|bool
name|isLegalAddImmediate
argument_list|(
name|int64_t
name|Imm
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return true if the specified immediate is legal icmp immediate,
comment|/// that is the target has icmp instructions which can compare a register
comment|/// against the immediate without having to materialize the immediate into a
comment|/// register.
name|bool
name|isLegalICmpImmediate
argument_list|(
name|int64_t
name|Imm
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return true if the addressing mode represented by AM is legal for
comment|/// this target, for a load/store of the specified type.
comment|/// The type may be VoidTy, in which case only return true if the addressing
comment|/// mode is legal for a load/store of any legal type.
comment|/// TODO: Handle pre/postinc as well.
name|bool
name|isLegalAddressingMode
argument_list|(
name|Type
operator|*
name|Ty
argument_list|,
name|GlobalValue
operator|*
name|BaseGV
argument_list|,
name|int64_t
name|BaseOffset
argument_list|,
name|bool
name|HasBaseReg
argument_list|,
name|int64_t
name|Scale
argument_list|,
name|unsigned
name|AddrSpace
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return true if the target supports masked load/store
comment|/// AVX2 and AVX-512 targets allow masks for consecutive load and store
name|bool
name|isLegalMaskedStore
argument_list|(
name|Type
operator|*
name|DataType
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isLegalMaskedLoad
argument_list|(
name|Type
operator|*
name|DataType
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return true if the target supports masked gather/scatter
comment|/// AVX-512 fully supports gather and scatter for vectors with 32 and 64
comment|/// bits scalar type.
name|bool
name|isLegalMaskedScatter
argument_list|(
name|Type
operator|*
name|DataType
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isLegalMaskedGather
argument_list|(
name|Type
operator|*
name|DataType
argument_list|)
decl|const
decl_stmt|;
comment|/// Return true if target doesn't mind addresses in vectors.
name|bool
name|prefersVectorizedAddressing
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Return the cost of the scaling factor used in the addressing
comment|/// mode represented by AM for this target, for a load/store
comment|/// of the specified type.
comment|/// If the AM is supported, the return value must be>= 0.
comment|/// If the AM is not supported, it returns a negative value.
comment|/// TODO: Handle pre/postinc as well.
name|int
name|getScalingFactorCost
argument_list|(
name|Type
operator|*
name|Ty
argument_list|,
name|GlobalValue
operator|*
name|BaseGV
argument_list|,
name|int64_t
name|BaseOffset
argument_list|,
name|bool
name|HasBaseReg
argument_list|,
name|int64_t
name|Scale
argument_list|,
name|unsigned
name|AddrSpace
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return true if target supports the load / store
comment|/// instruction with the given Offset on the form reg + Offset. It
comment|/// may be that Offset is too big for a certain type (register
comment|/// class).
name|bool
name|isFoldableMemAccessOffset
argument_list|(
name|Instruction
operator|*
name|I
argument_list|,
name|int64_t
name|Offset
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return true if it's free to truncate a value of type Ty1 to type
comment|/// Ty2. e.g. On x86 it's free to truncate a i32 value in register EAX to i16
comment|/// by referencing its sub-register AX.
name|bool
name|isTruncateFree
argument_list|(
name|Type
operator|*
name|Ty1
argument_list|,
name|Type
operator|*
name|Ty2
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return true if it is profitable to hoist instruction in the
comment|/// then/else to before if.
name|bool
name|isProfitableToHoist
argument_list|(
name|Instruction
operator|*
name|I
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return true if this type is legal.
name|bool
name|isTypeLegal
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Returns the target's jmp_buf alignment in bytes.
name|unsigned
name|getJumpBufAlignment
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Returns the target's jmp_buf size in bytes.
name|unsigned
name|getJumpBufSize
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Return true if switches should be turned into lookup tables for the
comment|/// target.
name|bool
name|shouldBuildLookupTables
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Return true if switches should be turned into lookup tables
comment|/// containing this constant value for the target.
name|bool
name|shouldBuildLookupTablesForConstant
argument_list|(
name|Constant
operator|*
name|C
argument_list|)
decl|const
decl_stmt|;
name|unsigned
name|getScalarizationOverhead
argument_list|(
name|Type
operator|*
name|Ty
argument_list|,
name|bool
name|Insert
argument_list|,
name|bool
name|Extract
argument_list|)
decl|const
decl_stmt|;
name|unsigned
name|getOperandsScalarizationOverhead
argument_list|(
name|ArrayRef
operator|<
specifier|const
name|Value
operator|*
operator|>
name|Args
argument_list|,
name|unsigned
name|VF
argument_list|)
decl|const
decl_stmt|;
comment|/// If target has efficient vector element load/store instructions, it can
comment|/// return true here so that insertion/extraction costs are not added to
comment|/// the scalarization cost of a load/store.
name|bool
name|supportsEfficientVectorElementLoadStore
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Don't restrict interleaved unrolling to small loops.
name|bool
name|enableAggressiveInterleaving
argument_list|(
name|bool
name|LoopHasReductions
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Enable matching of interleaved access groups.
name|bool
name|enableInterleavedAccessVectorization
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Indicate that it is potentially unsafe to automatically vectorize
comment|/// floating-point operations because the semantics of vector and scalar
comment|/// floating-point semantics may differ. For example, ARM NEON v7 SIMD math
comment|/// does not support IEEE-754 denormal numbers, while depending on the
comment|/// platform, scalar floating-point math does.
comment|/// This applies to floating-point math operations and calls, not memory
comment|/// operations, shuffles, or casts.
name|bool
name|isFPVectorizationPotentiallyUnsafe
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determine if the target supports unaligned memory accesses.
name|bool
name|allowsMisalignedMemoryAccesses
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|unsigned
name|BitWidth
argument_list|,
name|unsigned
name|AddressSpace
operator|=
literal|0
argument_list|,
name|unsigned
name|Alignment
operator|=
literal|1
argument_list|,
name|bool
operator|*
name|Fast
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return hardware support for population count.
name|PopcntSupportKind
name|getPopcntSupport
argument_list|(
name|unsigned
name|IntTyWidthInBit
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return true if the hardware has a fast square-root instruction.
name|bool
name|haveFastSqrt
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return the expected cost of supporting the floating point operation
comment|/// of the specified type.
name|int
name|getFPOpCost
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return the expected cost of materializing for the given integer
comment|/// immediate of the specified type.
name|int
name|getIntImmCost
argument_list|(
specifier|const
name|APInt
operator|&
name|Imm
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return the expected cost of materialization for the given integer
comment|/// immediate of the specified type for a given instruction. The cost can be
comment|/// zero if the immediate can be folded into the specified instruction.
name|int
name|getIntImmCost
argument_list|(
name|unsigned
name|Opc
argument_list|,
name|unsigned
name|Idx
argument_list|,
specifier|const
name|APInt
operator|&
name|Imm
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
name|int
name|getIntImmCost
argument_list|(
name|Intrinsic
operator|::
name|ID
name|IID
argument_list|,
name|unsigned
name|Idx
argument_list|,
specifier|const
name|APInt
operator|&
name|Imm
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return the expected cost for the given integer when optimising
comment|/// for size. This is different than the other integer immediate cost
comment|/// functions in that it is subtarget agnostic. This is useful when you e.g.
comment|/// target one ISA such as Aarch32 but smaller encodings could be possible
comment|/// with another such as Thumb. This return value is used as a penalty when
comment|/// the total costs for a constant is calculated (the bigger the cost, the
comment|/// more beneficial constant hoisting is).
name|int
name|getIntImmCodeSizeCost
argument_list|(
name|unsigned
name|Opc
argument_list|,
name|unsigned
name|Idx
argument_list|,
specifier|const
name|APInt
operator|&
name|Imm
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
comment|/// \name Vector Target Information
comment|/// @{
comment|/// \brief The various kinds of shuffle patterns for vector queries.
enum|enum
name|ShuffleKind
block|{
name|SK_Broadcast
block|,
comment|///< Broadcast element 0 to all other elements.
name|SK_Reverse
block|,
comment|///< Reverse the order of the vector.
name|SK_Alternate
block|,
comment|///< Choose alternate elements from vector.
name|SK_InsertSubvector
block|,
comment|///< InsertSubvector. Index indicates start offset.
name|SK_ExtractSubvector
block|,
comment|///< ExtractSubvector Index indicates start offset.
name|SK_PermuteTwoSrc
block|,
comment|///< Merge elements from two source vectors into one
comment|///< with any shuffle mask.
name|SK_PermuteSingleSrc
comment|///< Shuffle elements of single source vector with any
comment|///< shuffle mask.
block|}
enum|;
comment|/// \brief Additional information about an operand's possible values.
enum|enum
name|OperandValueKind
block|{
name|OK_AnyValue
block|,
comment|// Operand can have any value.
name|OK_UniformValue
block|,
comment|// Operand is uniform (splat of a value).
name|OK_UniformConstantValue
block|,
comment|// Operand is uniform constant.
name|OK_NonUniformConstantValue
comment|// Operand is a non uniform constant value.
block|}
enum|;
comment|/// \brief Additional properties of an operand's values.
enum|enum
name|OperandValueProperties
block|{
name|OP_None
init|=
literal|0
block|,
name|OP_PowerOf2
init|=
literal|1
block|}
enum|;
comment|/// \return The number of scalar or vector registers that the target has.
comment|/// If 'Vectors' is true, it returns the number of vector registers. If it is
comment|/// set to false, it returns the number of scalar registers.
name|unsigned
name|getNumberOfRegisters
argument_list|(
name|bool
name|Vector
argument_list|)
decl|const
decl_stmt|;
comment|/// \return The width of the largest scalar or vector register type.
name|unsigned
name|getRegisterBitWidth
argument_list|(
name|bool
name|Vector
argument_list|)
decl|const
decl_stmt|;
comment|/// \return The width of the smallest vector register type.
name|unsigned
name|getMinVectorRegisterBitWidth
argument_list|()
specifier|const
expr_stmt|;
comment|/// \return True if it should be considered for address type promotion.
comment|/// \p AllowPromotionWithoutCommonHeader Set true if promoting \p I is
comment|/// profitable without finding other extensions fed by the same input.
name|bool
name|shouldConsiderAddressTypePromotion
argument_list|(
specifier|const
name|Instruction
operator|&
name|I
argument_list|,
name|bool
operator|&
name|AllowPromotionWithoutCommonHeader
argument_list|)
decl|const
decl_stmt|;
comment|/// \return The size of a cache line in bytes.
name|unsigned
name|getCacheLineSize
argument_list|()
specifier|const
expr_stmt|;
comment|/// \return How much before a load we should place the prefetch instruction.
comment|/// This is currently measured in number of instructions.
name|unsigned
name|getPrefetchDistance
argument_list|()
specifier|const
expr_stmt|;
comment|/// \return Some HW prefetchers can handle accesses up to a certain constant
comment|/// stride.  This is the minimum stride in bytes where it makes sense to start
comment|/// adding SW prefetches.  The default is 1, i.e. prefetch with any stride.
name|unsigned
name|getMinPrefetchStride
argument_list|()
specifier|const
expr_stmt|;
comment|/// \return The maximum number of iterations to prefetch ahead.  If the
comment|/// required number of iterations is more than this number, no prefetching is
comment|/// performed.
name|unsigned
name|getMaxPrefetchIterationsAhead
argument_list|()
specifier|const
expr_stmt|;
comment|/// \return The maximum interleave factor that any transform should try to
comment|/// perform for this target. This number depends on the level of parallelism
comment|/// and the number of execution units in the CPU.
name|unsigned
name|getMaxInterleaveFactor
argument_list|(
name|unsigned
name|VF
argument_list|)
decl|const
decl_stmt|;
comment|/// \return The expected cost of arithmetic ops, such as mul, xor, fsub, etc.
comment|/// \p Args is an optional argument which holds the instruction operands
comment|/// values so the TTI can analyize those values searching for special
comment|/// cases\optimizations based on those values.
name|int
name|getArithmeticInstrCost
argument_list|(
name|unsigned
name|Opcode
argument_list|,
name|Type
operator|*
name|Ty
argument_list|,
name|OperandValueKind
name|Opd1Info
operator|=
name|OK_AnyValue
argument_list|,
name|OperandValueKind
name|Opd2Info
operator|=
name|OK_AnyValue
argument_list|,
name|OperandValueProperties
name|Opd1PropInfo
operator|=
name|OP_None
argument_list|,
name|OperandValueProperties
name|Opd2PropInfo
operator|=
name|OP_None
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Value
operator|*
operator|>
name|Args
operator|=
name|ArrayRef
operator|<
specifier|const
name|Value
operator|*
operator|>
operator|(
operator|)
argument_list|)
decl|const
decl_stmt|;
comment|/// \return The cost of a shuffle instruction of kind Kind and of type Tp.
comment|/// The index and subtype parameters are used by the subvector insertion and
comment|/// extraction shuffle kinds.
name|int
name|getShuffleCost
argument_list|(
name|ShuffleKind
name|Kind
argument_list|,
name|Type
operator|*
name|Tp
argument_list|,
name|int
name|Index
operator|=
literal|0
argument_list|,
name|Type
operator|*
name|SubTp
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// \return The expected cost of cast instructions, such as bitcast, trunc,
comment|/// zext, etc. If there is an existing instruction that holds Opcode, it
comment|/// may be passed in the 'I' parameter.
name|int
name|getCastInstrCost
argument_list|(
name|unsigned
name|Opcode
argument_list|,
name|Type
operator|*
name|Dst
argument_list|,
name|Type
operator|*
name|Src
argument_list|,
specifier|const
name|Instruction
operator|*
name|I
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// \return The expected cost of a sign- or zero-extended vector extract. Use
comment|/// -1 to indicate that there is no information about the index value.
name|int
name|getExtractWithExtendCost
argument_list|(
name|unsigned
name|Opcode
argument_list|,
name|Type
operator|*
name|Dst
argument_list|,
name|VectorType
operator|*
name|VecTy
argument_list|,
name|unsigned
name|Index
operator|=
operator|-
literal|1
argument_list|)
decl|const
decl_stmt|;
comment|/// \return The expected cost of control-flow related instructions such as
comment|/// Phi, Ret, Br.
name|int
name|getCFInstrCost
argument_list|(
name|unsigned
name|Opcode
argument_list|)
decl|const
decl_stmt|;
comment|/// \returns The expected cost of compare and select instructions. If there
comment|/// is an existing instruction that holds Opcode, it may be passed in the
comment|/// 'I' parameter.
name|int
name|getCmpSelInstrCost
argument_list|(
name|unsigned
name|Opcode
argument_list|,
name|Type
operator|*
name|ValTy
argument_list|,
name|Type
operator|*
name|CondTy
operator|=
name|nullptr
argument_list|,
specifier|const
name|Instruction
operator|*
name|I
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// \return The expected cost of vector Insert and Extract.
comment|/// Use -1 to indicate that there is no information on the index value.
name|int
name|getVectorInstrCost
argument_list|(
name|unsigned
name|Opcode
argument_list|,
name|Type
operator|*
name|Val
argument_list|,
name|unsigned
name|Index
operator|=
operator|-
literal|1
argument_list|)
decl|const
decl_stmt|;
comment|/// \return The cost of Load and Store instructions.
name|int
name|getMemoryOpCost
argument_list|(
name|unsigned
name|Opcode
argument_list|,
name|Type
operator|*
name|Src
argument_list|,
name|unsigned
name|Alignment
argument_list|,
name|unsigned
name|AddressSpace
argument_list|,
specifier|const
name|Instruction
operator|*
name|I
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// \return The cost of masked Load and Store instructions.
name|int
name|getMaskedMemoryOpCost
argument_list|(
name|unsigned
name|Opcode
argument_list|,
name|Type
operator|*
name|Src
argument_list|,
name|unsigned
name|Alignment
argument_list|,
name|unsigned
name|AddressSpace
argument_list|)
decl|const
decl_stmt|;
comment|/// \return The cost of Gather or Scatter operation
comment|/// \p Opcode - is a type of memory access Load or Store
comment|/// \p DataTy - a vector type of the data to be loaded or stored
comment|/// \p Ptr - pointer [or vector of pointers] - address[es] in memory
comment|/// \p VariableMask - true when the memory access is predicated with a mask
comment|///                   that is not a compile-time constant
comment|/// \p Alignment - alignment of single element
name|int
name|getGatherScatterOpCost
argument_list|(
name|unsigned
name|Opcode
argument_list|,
name|Type
operator|*
name|DataTy
argument_list|,
name|Value
operator|*
name|Ptr
argument_list|,
name|bool
name|VariableMask
argument_list|,
name|unsigned
name|Alignment
argument_list|)
decl|const
decl_stmt|;
comment|/// \return The cost of the interleaved memory operation.
comment|/// \p Opcode is the memory operation code
comment|/// \p VecTy is the vector type of the interleaved access.
comment|/// \p Factor is the interleave factor
comment|/// \p Indices is the indices for interleaved load members (as interleaved
comment|///    load allows gaps)
comment|/// \p Alignment is the alignment of the memory operation
comment|/// \p AddressSpace is address space of the pointer.
name|int
name|getInterleavedMemoryOpCost
argument_list|(
name|unsigned
name|Opcode
argument_list|,
name|Type
operator|*
name|VecTy
argument_list|,
name|unsigned
name|Factor
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Indices
argument_list|,
name|unsigned
name|Alignment
argument_list|,
name|unsigned
name|AddressSpace
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Calculate the cost of performing a vector reduction.
comment|///
comment|/// This is the cost of reducing the vector value of type \p Ty to a scalar
comment|/// value using the operation denoted by \p Opcode. The form of the reduction
comment|/// can either be a pairwise reduction or a reduction that splits the vector
comment|/// at every reduction level.
comment|///
comment|/// Pairwise:
comment|///  (v0, v1, v2, v3)
comment|///  ((v0+v1), (v2, v3), undef, undef)
comment|/// Split:
comment|///  (v0, v1, v2, v3)
comment|///  ((v0+v2), (v1+v3), undef, undef)
name|int
name|getReductionCost
argument_list|(
name|unsigned
name|Opcode
argument_list|,
name|Type
operator|*
name|Ty
argument_list|,
name|bool
name|IsPairwiseForm
argument_list|)
decl|const
decl_stmt|;
comment|/// \returns The cost of Intrinsic instructions. Analyses the real arguments.
comment|/// Three cases are handled: 1. scalar instruction 2. vector instruction
comment|/// 3. scalar instruction which is to be vectorized with VF.
name|int
name|getIntrinsicInstrCost
argument_list|(
name|Intrinsic
operator|::
name|ID
name|ID
argument_list|,
name|Type
operator|*
name|RetTy
argument_list|,
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|Args
argument_list|,
name|FastMathFlags
name|FMF
argument_list|,
name|unsigned
name|VF
operator|=
literal|1
argument_list|)
decl|const
decl_stmt|;
comment|/// \returns The cost of Intrinsic instructions. Types analysis only.
comment|/// If ScalarizationCostPassed is UINT_MAX, the cost of scalarizing the
comment|/// arguments and the return value will be computed based on types.
name|int
name|getIntrinsicInstrCost
argument_list|(
name|Intrinsic
operator|::
name|ID
name|ID
argument_list|,
name|Type
operator|*
name|RetTy
argument_list|,
name|ArrayRef
operator|<
name|Type
operator|*
operator|>
name|Tys
argument_list|,
name|FastMathFlags
name|FMF
argument_list|,
name|unsigned
name|ScalarizationCostPassed
operator|=
name|UINT_MAX
argument_list|)
decl|const
decl_stmt|;
comment|/// \returns The cost of Call instructions.
name|int
name|getCallInstrCost
argument_list|(
name|Function
operator|*
name|F
argument_list|,
name|Type
operator|*
name|RetTy
argument_list|,
name|ArrayRef
operator|<
name|Type
operator|*
operator|>
name|Tys
argument_list|)
decl|const
decl_stmt|;
comment|/// \returns The number of pieces into which the provided type must be
comment|/// split during legalization. Zero is returned when the answer is unknown.
name|unsigned
name|getNumberOfParts
argument_list|(
name|Type
operator|*
name|Tp
argument_list|)
decl|const
decl_stmt|;
comment|/// \returns The cost of the address computation. For most targets this can be
comment|/// merged into the instruction indexing mode. Some targets might want to
comment|/// distinguish between address computation for memory operations on vector
comment|/// types and scalar types. Such targets should override this function.
comment|/// The 'SE' parameter holds pointer for the scalar evolution object which
comment|/// is used in order to get the Ptr step value in case of constant stride.
comment|/// The 'Ptr' parameter holds SCEV of the access pointer.
name|int
name|getAddressComputationCost
argument_list|(
name|Type
operator|*
name|Ty
argument_list|,
name|ScalarEvolution
operator|*
name|SE
operator|=
name|nullptr
argument_list|,
specifier|const
name|SCEV
operator|*
name|Ptr
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// \returns The cost, if any, of keeping values of the given types alive
comment|/// over a callsite.
comment|///
comment|/// Some types may require the use of register classes that do not have
comment|/// any callee-saved registers, so would require a spill and fill.
name|unsigned
name|getCostOfKeepingLiveOverCall
argument_list|(
name|ArrayRef
operator|<
name|Type
operator|*
operator|>
name|Tys
argument_list|)
decl|const
decl_stmt|;
comment|/// \returns True if the intrinsic is a supported memory intrinsic.  Info
comment|/// will contain additional information - whether the intrinsic may write
comment|/// or read to memory, volatility and the pointer.  Info is undefined
comment|/// if false is returned.
name|bool
name|getTgtMemIntrinsic
argument_list|(
name|IntrinsicInst
operator|*
name|Inst
argument_list|,
name|MemIntrinsicInfo
operator|&
name|Info
argument_list|)
decl|const
decl_stmt|;
comment|/// \returns A value which is the result of the given memory intrinsic.  New
comment|/// instructions may be created to extract the result from the given intrinsic
comment|/// memory operation.  Returns nullptr if the target cannot create a result
comment|/// from the given intrinsic.
name|Value
modifier|*
name|getOrCreateResultFromMemIntrinsic
argument_list|(
name|IntrinsicInst
operator|*
name|Inst
argument_list|,
name|Type
operator|*
name|ExpectedType
argument_list|)
decl|const
decl_stmt|;
comment|/// \returns True if the two functions have compatible attributes for inlining
comment|/// purposes.
name|bool
name|areInlineCompatible
argument_list|(
specifier|const
name|Function
operator|*
name|Caller
argument_list|,
specifier|const
name|Function
operator|*
name|Callee
argument_list|)
decl|const
decl_stmt|;
comment|/// \returns The bitwidth of the largest vector type that should be used to
comment|/// load/store in the given address space.
name|unsigned
name|getLoadStoreVecRegBitWidth
argument_list|(
name|unsigned
name|AddrSpace
argument_list|)
decl|const
decl_stmt|;
comment|/// \returns True if the load instruction is legal to vectorize.
name|bool
name|isLegalToVectorizeLoad
argument_list|(
name|LoadInst
operator|*
name|LI
argument_list|)
decl|const
decl_stmt|;
comment|/// \returns True if the store instruction is legal to vectorize.
name|bool
name|isLegalToVectorizeStore
argument_list|(
name|StoreInst
operator|*
name|SI
argument_list|)
decl|const
decl_stmt|;
comment|/// \returns True if it is legal to vectorize the given load chain.
name|bool
name|isLegalToVectorizeLoadChain
argument_list|(
name|unsigned
name|ChainSizeInBytes
argument_list|,
name|unsigned
name|Alignment
argument_list|,
name|unsigned
name|AddrSpace
argument_list|)
decl|const
decl_stmt|;
comment|/// \returns True if it is legal to vectorize the given store chain.
name|bool
name|isLegalToVectorizeStoreChain
argument_list|(
name|unsigned
name|ChainSizeInBytes
argument_list|,
name|unsigned
name|Alignment
argument_list|,
name|unsigned
name|AddrSpace
argument_list|)
decl|const
decl_stmt|;
comment|/// \returns The new vector factor value if the target doesn't support \p
comment|/// SizeInBytes loads or has a better vector factor.
name|unsigned
name|getLoadVectorFactor
argument_list|(
name|unsigned
name|VF
argument_list|,
name|unsigned
name|LoadSize
argument_list|,
name|unsigned
name|ChainSizeInBytes
argument_list|,
name|VectorType
operator|*
name|VecTy
argument_list|)
decl|const
decl_stmt|;
comment|/// \returns The new vector factor value if the target doesn't support \p
comment|/// SizeInBytes stores or has a better vector factor.
name|unsigned
name|getStoreVectorFactor
argument_list|(
name|unsigned
name|VF
argument_list|,
name|unsigned
name|StoreSize
argument_list|,
name|unsigned
name|ChainSizeInBytes
argument_list|,
name|VectorType
operator|*
name|VecTy
argument_list|)
decl|const
decl_stmt|;
comment|/// Flags describing the kind of vector reduction.
struct|struct
name|ReductionFlags
block|{
name|ReductionFlags
argument_list|()
operator|:
name|IsMaxOp
argument_list|(
name|false
argument_list|)
operator|,
name|IsSigned
argument_list|(
name|false
argument_list|)
operator|,
name|NoNaN
argument_list|(
argument|false
argument_list|)
block|{}
name|bool
name|IsMaxOp
expr_stmt|;
comment|///< If the op a min/max kind, true if it's a max operation.
name|bool
name|IsSigned
decl_stmt|;
comment|///< Whether the operation is a signed int reduction.
name|bool
name|NoNaN
decl_stmt|;
comment|///< If op is an fp min/max, whether NaNs may be present.
block|}
struct|;
comment|/// \returns True if the target wants to handle the given reduction idiom in
comment|/// the intrinsics form instead of the shuffle form.
name|bool
name|useReductionIntrinsic
argument_list|(
name|unsigned
name|Opcode
argument_list|,
name|Type
operator|*
name|Ty
argument_list|,
name|ReductionFlags
name|Flags
argument_list|)
decl|const
decl_stmt|;
comment|/// \returns True if the target wants to expand the given reduction intrinsic
comment|/// into a shuffle sequence.
name|bool
name|shouldExpandReduction
argument_list|(
specifier|const
name|IntrinsicInst
operator|*
name|II
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
name|private
label|:
comment|/// \brief The abstract base class used to type erase specific TTI
comment|/// implementations.
name|class
name|Concept
decl_stmt|;
comment|/// \brief The template model for the base class which wraps a concrete
comment|/// implementation in a type erased interface.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|Model
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|Concept
operator|>
name|TTIImpl
expr_stmt|;
block|}
empty_stmt|;
name|class
name|TargetTransformInfo
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
name|virtual
specifier|const
name|DataLayout
operator|&
name|getDataLayout
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|int
name|getOperationCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Ty
argument_list|,
argument|Type *OpTy
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getGEPCost
argument_list|(
name|Type
operator|*
name|PointeeType
argument_list|,
specifier|const
name|Value
operator|*
name|Ptr
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Value
operator|*
operator|>
name|Operands
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getCallCost
argument_list|(
argument|FunctionType *FTy
argument_list|,
argument|int NumArgs
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getCallCost
argument_list|(
argument|const Function *F
argument_list|,
argument|int NumArgs
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getCallCost
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Value
operator|*
operator|>
name|Arguments
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|getInliningThresholdMultiplier
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|int
name|getIntrinsicCost
argument_list|(
argument|Intrinsic::ID IID
argument_list|,
argument|Type *RetTy
argument_list|,
argument|ArrayRef<Type *> ParamTys
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getIntrinsicCost
argument_list|(
argument|Intrinsic::ID IID
argument_list|,
argument|Type *RetTy
argument_list|,
argument|ArrayRef<const Value *> Arguments
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|getEstimatedNumberOfCaseClusters
argument_list|(
specifier|const
name|SwitchInst
operator|&
name|SI
argument_list|,
name|unsigned
operator|&
name|JTSize
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getUserCost
argument_list|(
specifier|const
name|User
operator|*
name|U
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|hasBranchDivergence
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|isSourceOfDivergence
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|getFlatAddressSpace
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|isLoweredToCall
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|getUnrollingPreferences
argument_list|(
name|Loop
operator|*
name|L
argument_list|,
name|UnrollingPreferences
operator|&
name|UP
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|isLegalAddImmediate
argument_list|(
argument|int64_t Imm
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|isLegalICmpImmediate
argument_list|(
argument|int64_t Imm
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|isLegalAddressingMode
argument_list|(
argument|Type *Ty
argument_list|,
argument|GlobalValue *BaseGV
argument_list|,
argument|int64_t BaseOffset
argument_list|,
argument|bool HasBaseReg
argument_list|,
argument|int64_t Scale
argument_list|,
argument|unsigned AddrSpace
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|isLegalMaskedStore
argument_list|(
name|Type
operator|*
name|DataType
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|isLegalMaskedLoad
argument_list|(
name|Type
operator|*
name|DataType
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|isLegalMaskedScatter
argument_list|(
name|Type
operator|*
name|DataType
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|isLegalMaskedGather
argument_list|(
name|Type
operator|*
name|DataType
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|prefersVectorizedAddressing
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|int
name|getScalingFactorCost
argument_list|(
argument|Type *Ty
argument_list|,
argument|GlobalValue *BaseGV
argument_list|,
argument|int64_t BaseOffset
argument_list|,
argument|bool HasBaseReg
argument_list|,
argument|int64_t Scale
argument_list|,
argument|unsigned AddrSpace
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|isFoldableMemAccessOffset
argument_list|(
argument|Instruction *I
argument_list|,
argument|int64_t Offset
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|isTruncateFree
argument_list|(
name|Type
operator|*
name|Ty1
argument_list|,
name|Type
operator|*
name|Ty2
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|isProfitableToHoist
argument_list|(
name|Instruction
operator|*
name|I
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|isTypeLegal
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|getJumpBufAlignment
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|getJumpBufSize
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|shouldBuildLookupTables
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|shouldBuildLookupTablesForConstant
argument_list|(
name|Constant
operator|*
name|C
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|getScalarizationOverhead
argument_list|(
argument|Type *Ty
argument_list|,
argument|bool Insert
argument_list|,
argument|bool Extract
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|getOperandsScalarizationOverhead
argument_list|(
argument|ArrayRef<const Value *> Args
argument_list|,
argument|unsigned VF
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|supportsEfficientVectorElementLoadStore
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|enableAggressiveInterleaving
argument_list|(
argument|bool LoopHasReductions
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|enableInterleavedAccessVectorization
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|isFPVectorizationPotentiallyUnsafe
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|allowsMisalignedMemoryAccesses
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|unsigned BitWidth
argument_list|,
argument|unsigned AddressSpace
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|bool *Fast
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|PopcntSupportKind
name|getPopcntSupport
argument_list|(
argument|unsigned IntTyWidthInBit
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|haveFastSqrt
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getFPOpCost
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getIntImmCodeSizeCost
argument_list|(
argument|unsigned Opc
argument_list|,
argument|unsigned Idx
argument_list|,
argument|const APInt&Imm
argument_list|,
argument|Type *Ty
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getIntImmCost
argument_list|(
specifier|const
name|APInt
operator|&
name|Imm
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getIntImmCost
argument_list|(
argument|unsigned Opc
argument_list|,
argument|unsigned Idx
argument_list|,
argument|const APInt&Imm
argument_list|,
argument|Type *Ty
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getIntImmCost
argument_list|(
argument|Intrinsic::ID IID
argument_list|,
argument|unsigned Idx
argument_list|,
argument|const APInt&Imm
argument_list|,
argument|Type *Ty
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|getNumberOfRegisters
argument_list|(
argument|bool Vector
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|getRegisterBitWidth
argument_list|(
argument|bool Vector
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|getMinVectorRegisterBitWidth
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|shouldConsiderAddressTypePromotion
argument_list|(
specifier|const
name|Instruction
operator|&
name|I
argument_list|,
name|bool
operator|&
name|AllowPromotionWithoutCommonHeader
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|getCacheLineSize
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|getPrefetchDistance
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|getMinPrefetchStride
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|getMaxPrefetchIterationsAhead
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|getMaxInterleaveFactor
argument_list|(
argument|unsigned VF
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|getArithmeticInstrCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Ty
argument_list|,
argument|OperandValueKind Opd1Info
argument_list|,
argument|OperandValueKind Opd2Info
argument_list|,
argument|OperandValueProperties Opd1PropInfo
argument_list|,
argument|OperandValueProperties Opd2PropInfo
argument_list|,
argument|ArrayRef<const Value *> Args
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getShuffleCost
argument_list|(
argument|ShuffleKind Kind
argument_list|,
argument|Type *Tp
argument_list|,
argument|int Index
argument_list|,
argument|Type *SubTp
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getCastInstrCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Dst
argument_list|,
argument|Type *Src
argument_list|,
argument|const Instruction *I
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getExtractWithExtendCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Dst
argument_list|,
argument|VectorType *VecTy
argument_list|,
argument|unsigned Index
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getCFInstrCost
argument_list|(
argument|unsigned Opcode
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getCmpSelInstrCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *ValTy
argument_list|,
argument|Type *CondTy
argument_list|,
argument|const Instruction *I
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getVectorInstrCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Val
argument_list|,
argument|unsigned Index
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getMemoryOpCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Src
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|unsigned AddressSpace
argument_list|,
argument|const Instruction *I
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getMaskedMemoryOpCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Src
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|unsigned AddressSpace
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getGatherScatterOpCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *DataTy
argument_list|,
argument|Value *Ptr
argument_list|,
argument|bool VariableMask
argument_list|,
argument|unsigned Alignment
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getInterleavedMemoryOpCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *VecTy
argument_list|,
argument|unsigned Factor
argument_list|,
argument|ArrayRef<unsigned> Indices
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|unsigned AddressSpace
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getReductionCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Ty
argument_list|,
argument|bool IsPairwiseForm
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getIntrinsicInstrCost
argument_list|(
argument|Intrinsic::ID ID
argument_list|,
argument|Type *RetTy
argument_list|,
argument|ArrayRef<Type *> Tys
argument_list|,
argument|FastMathFlags FMF
argument_list|,
argument|unsigned ScalarizationCostPassed
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getIntrinsicInstrCost
argument_list|(
argument|Intrinsic::ID ID
argument_list|,
argument|Type *RetTy
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|FastMathFlags FMF
argument_list|,
argument|unsigned VF
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getCallInstrCost
argument_list|(
name|Function
operator|*
name|F
argument_list|,
name|Type
operator|*
name|RetTy
argument_list|,
name|ArrayRef
operator|<
name|Type
operator|*
operator|>
name|Tys
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|getNumberOfParts
argument_list|(
name|Type
operator|*
name|Tp
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|getAddressComputationCost
argument_list|(
name|Type
operator|*
name|Ty
argument_list|,
name|ScalarEvolution
operator|*
name|SE
argument_list|,
specifier|const
name|SCEV
operator|*
name|Ptr
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|getCostOfKeepingLiveOverCall
argument_list|(
name|ArrayRef
operator|<
name|Type
operator|*
operator|>
name|Tys
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|getTgtMemIntrinsic
argument_list|(
name|IntrinsicInst
operator|*
name|Inst
argument_list|,
name|MemIntrinsicInfo
operator|&
name|Info
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|Value
operator|*
name|getOrCreateResultFromMemIntrinsic
argument_list|(
name|IntrinsicInst
operator|*
name|Inst
argument_list|,
name|Type
operator|*
name|ExpectedType
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|areInlineCompatible
argument_list|(
argument|const Function *Caller
argument_list|,
argument|const Function *Callee
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|getLoadStoreVecRegBitWidth
argument_list|(
argument|unsigned AddrSpace
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|isLegalToVectorizeLoad
argument_list|(
argument|LoadInst *LI
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|isLegalToVectorizeStore
argument_list|(
argument|StoreInst *SI
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|isLegalToVectorizeLoadChain
argument_list|(
argument|unsigned ChainSizeInBytes
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|unsigned AddrSpace
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|isLegalToVectorizeStoreChain
argument_list|(
argument|unsigned ChainSizeInBytes
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|unsigned AddrSpace
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|getLoadVectorFactor
argument_list|(
argument|unsigned VF
argument_list|,
argument|unsigned LoadSize
argument_list|,
argument|unsigned ChainSizeInBytes
argument_list|,
argument|VectorType *VecTy
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|getStoreVectorFactor
argument_list|(
argument|unsigned VF
argument_list|,
argument|unsigned StoreSize
argument_list|,
argument|unsigned ChainSizeInBytes
argument_list|,
argument|VectorType *VecTy
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|useReductionIntrinsic
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Ty
argument_list|,
argument|ReductionFlags
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|shouldExpandReduction
argument_list|(
argument|const IntrinsicInst *II
argument_list|)
specifier|const
operator|=
literal|0
block|; }
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|TargetTransformInfo
operator|::
name|Model
name|final
operator|:
name|public
name|TargetTransformInfo
operator|::
name|Concept
block|{
name|T
name|Impl
block|;
name|public
operator|:
name|Model
argument_list|(
argument|T Impl
argument_list|)
operator|:
name|Impl
argument_list|(
argument|std::move(Impl)
argument_list|)
block|{}
operator|~
name|Model
argument_list|()
name|override
block|{}
specifier|const
name|DataLayout
operator|&
name|getDataLayout
argument_list|()
specifier|const
name|override
block|{
return|return
name|Impl
operator|.
name|getDataLayout
argument_list|()
return|;
block|}
name|int
name|getOperationCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Ty
argument_list|,
argument|Type *OpTy
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getOperationCost
argument_list|(
name|Opcode
argument_list|,
name|Ty
argument_list|,
name|OpTy
argument_list|)
return|;
block|}
name|int
name|getGEPCost
argument_list|(
argument|Type *PointeeType
argument_list|,
argument|const Value *Ptr
argument_list|,
argument|ArrayRef<const Value *> Operands
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getGEPCost
argument_list|(
name|PointeeType
argument_list|,
name|Ptr
argument_list|,
name|Operands
argument_list|)
return|;
block|}
name|int
name|getCallCost
argument_list|(
argument|FunctionType *FTy
argument_list|,
argument|int NumArgs
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getCallCost
argument_list|(
name|FTy
argument_list|,
name|NumArgs
argument_list|)
return|;
block|}
name|int
name|getCallCost
argument_list|(
argument|const Function *F
argument_list|,
argument|int NumArgs
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getCallCost
argument_list|(
name|F
argument_list|,
name|NumArgs
argument_list|)
return|;
block|}
name|int
name|getCallCost
argument_list|(
argument|const Function *F
argument_list|,
argument|ArrayRef<const Value *> Arguments
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getCallCost
argument_list|(
name|F
argument_list|,
name|Arguments
argument_list|)
return|;
block|}
name|unsigned
name|getInliningThresholdMultiplier
argument_list|()
name|override
block|{
return|return
name|Impl
operator|.
name|getInliningThresholdMultiplier
argument_list|()
return|;
block|}
name|int
name|getIntrinsicCost
argument_list|(
argument|Intrinsic::ID IID
argument_list|,
argument|Type *RetTy
argument_list|,
argument|ArrayRef<Type *> ParamTys
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getIntrinsicCost
argument_list|(
name|IID
argument_list|,
name|RetTy
argument_list|,
name|ParamTys
argument_list|)
return|;
block|}
name|int
name|getIntrinsicCost
argument_list|(
argument|Intrinsic::ID IID
argument_list|,
argument|Type *RetTy
argument_list|,
argument|ArrayRef<const Value *> Arguments
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getIntrinsicCost
argument_list|(
name|IID
argument_list|,
name|RetTy
argument_list|,
name|Arguments
argument_list|)
return|;
block|}
name|int
name|getUserCost
argument_list|(
argument|const User *U
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getUserCost
argument_list|(
name|U
argument_list|)
return|;
block|}
name|bool
name|hasBranchDivergence
argument_list|()
name|override
block|{
return|return
name|Impl
operator|.
name|hasBranchDivergence
argument_list|()
return|;
block|}
name|bool
name|isSourceOfDivergence
argument_list|(
argument|const Value *V
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|isSourceOfDivergence
argument_list|(
name|V
argument_list|)
return|;
block|}
name|unsigned
name|getFlatAddressSpace
argument_list|()
name|override
block|{
return|return
name|Impl
operator|.
name|getFlatAddressSpace
argument_list|()
return|;
block|}
name|bool
name|isLoweredToCall
argument_list|(
argument|const Function *F
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|isLoweredToCall
argument_list|(
name|F
argument_list|)
return|;
block|}
name|void
name|getUnrollingPreferences
argument_list|(
argument|Loop *L
argument_list|,
argument|UnrollingPreferences&UP
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getUnrollingPreferences
argument_list|(
name|L
argument_list|,
name|UP
argument_list|)
return|;
block|}
name|bool
name|isLegalAddImmediate
argument_list|(
argument|int64_t Imm
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|isLegalAddImmediate
argument_list|(
name|Imm
argument_list|)
return|;
block|}
name|bool
name|isLegalICmpImmediate
argument_list|(
argument|int64_t Imm
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|isLegalICmpImmediate
argument_list|(
name|Imm
argument_list|)
return|;
block|}
name|bool
name|isLegalAddressingMode
argument_list|(
argument|Type *Ty
argument_list|,
argument|GlobalValue *BaseGV
argument_list|,
argument|int64_t BaseOffset
argument_list|,
argument|bool HasBaseReg
argument_list|,
argument|int64_t Scale
argument_list|,
argument|unsigned AddrSpace
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|isLegalAddressingMode
argument_list|(
name|Ty
argument_list|,
name|BaseGV
argument_list|,
name|BaseOffset
argument_list|,
name|HasBaseReg
argument_list|,
name|Scale
argument_list|,
name|AddrSpace
argument_list|)
return|;
block|}
name|bool
name|isLegalMaskedStore
argument_list|(
argument|Type *DataType
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|isLegalMaskedStore
argument_list|(
name|DataType
argument_list|)
return|;
block|}
name|bool
name|isLegalMaskedLoad
argument_list|(
argument|Type *DataType
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|isLegalMaskedLoad
argument_list|(
name|DataType
argument_list|)
return|;
block|}
name|bool
name|isLegalMaskedScatter
argument_list|(
argument|Type *DataType
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|isLegalMaskedScatter
argument_list|(
name|DataType
argument_list|)
return|;
block|}
name|bool
name|isLegalMaskedGather
argument_list|(
argument|Type *DataType
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|isLegalMaskedGather
argument_list|(
name|DataType
argument_list|)
return|;
block|}
name|bool
name|prefersVectorizedAddressing
argument_list|()
name|override
block|{
return|return
name|Impl
operator|.
name|prefersVectorizedAddressing
argument_list|()
return|;
block|}
name|int
name|getScalingFactorCost
argument_list|(
argument|Type *Ty
argument_list|,
argument|GlobalValue *BaseGV
argument_list|,
argument|int64_t BaseOffset
argument_list|,
argument|bool HasBaseReg
argument_list|,
argument|int64_t Scale
argument_list|,
argument|unsigned AddrSpace
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getScalingFactorCost
argument_list|(
name|Ty
argument_list|,
name|BaseGV
argument_list|,
name|BaseOffset
argument_list|,
name|HasBaseReg
argument_list|,
name|Scale
argument_list|,
name|AddrSpace
argument_list|)
return|;
block|}
name|bool
name|isFoldableMemAccessOffset
argument_list|(
argument|Instruction *I
argument_list|,
argument|int64_t Offset
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|isFoldableMemAccessOffset
argument_list|(
name|I
argument_list|,
name|Offset
argument_list|)
return|;
block|}
name|bool
name|isTruncateFree
argument_list|(
argument|Type *Ty1
argument_list|,
argument|Type *Ty2
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|isTruncateFree
argument_list|(
name|Ty1
argument_list|,
name|Ty2
argument_list|)
return|;
block|}
name|bool
name|isProfitableToHoist
argument_list|(
argument|Instruction *I
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|isProfitableToHoist
argument_list|(
name|I
argument_list|)
return|;
block|}
name|bool
name|isTypeLegal
argument_list|(
argument|Type *Ty
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|isTypeLegal
argument_list|(
name|Ty
argument_list|)
return|;
block|}
name|unsigned
name|getJumpBufAlignment
argument_list|()
name|override
block|{
return|return
name|Impl
operator|.
name|getJumpBufAlignment
argument_list|()
return|;
block|}
name|unsigned
name|getJumpBufSize
argument_list|()
name|override
block|{
return|return
name|Impl
operator|.
name|getJumpBufSize
argument_list|()
return|;
block|}
name|bool
name|shouldBuildLookupTables
argument_list|()
name|override
block|{
return|return
name|Impl
operator|.
name|shouldBuildLookupTables
argument_list|()
return|;
block|}
name|bool
name|shouldBuildLookupTablesForConstant
argument_list|(
argument|Constant *C
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|shouldBuildLookupTablesForConstant
argument_list|(
name|C
argument_list|)
return|;
block|}
name|unsigned
name|getScalarizationOverhead
argument_list|(
argument|Type *Ty
argument_list|,
argument|bool Insert
argument_list|,
argument|bool Extract
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getScalarizationOverhead
argument_list|(
name|Ty
argument_list|,
name|Insert
argument_list|,
name|Extract
argument_list|)
return|;
block|}
name|unsigned
name|getOperandsScalarizationOverhead
argument_list|(
argument|ArrayRef<const Value *> Args
argument_list|,
argument|unsigned VF
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getOperandsScalarizationOverhead
argument_list|(
name|Args
argument_list|,
name|VF
argument_list|)
return|;
block|}
name|bool
name|supportsEfficientVectorElementLoadStore
argument_list|()
name|override
block|{
return|return
name|Impl
operator|.
name|supportsEfficientVectorElementLoadStore
argument_list|()
return|;
block|}
name|bool
name|enableAggressiveInterleaving
argument_list|(
argument|bool LoopHasReductions
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|enableAggressiveInterleaving
argument_list|(
name|LoopHasReductions
argument_list|)
return|;
block|}
name|bool
name|enableInterleavedAccessVectorization
argument_list|()
name|override
block|{
return|return
name|Impl
operator|.
name|enableInterleavedAccessVectorization
argument_list|()
return|;
block|}
name|bool
name|isFPVectorizationPotentiallyUnsafe
argument_list|()
name|override
block|{
return|return
name|Impl
operator|.
name|isFPVectorizationPotentiallyUnsafe
argument_list|()
return|;
block|}
name|bool
name|allowsMisalignedMemoryAccesses
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|unsigned BitWidth
argument_list|,
argument|unsigned AddressSpace
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|bool *Fast
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|allowsMisalignedMemoryAccesses
argument_list|(
name|Context
argument_list|,
name|BitWidth
argument_list|,
name|AddressSpace
argument_list|,
name|Alignment
argument_list|,
name|Fast
argument_list|)
return|;
block|}
name|PopcntSupportKind
name|getPopcntSupport
argument_list|(
argument|unsigned IntTyWidthInBit
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getPopcntSupport
argument_list|(
name|IntTyWidthInBit
argument_list|)
return|;
block|}
name|bool
name|haveFastSqrt
argument_list|(
argument|Type *Ty
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|haveFastSqrt
argument_list|(
name|Ty
argument_list|)
return|;
block|}
name|int
name|getFPOpCost
argument_list|(
argument|Type *Ty
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getFPOpCost
argument_list|(
name|Ty
argument_list|)
return|;
block|}
name|int
name|getIntImmCodeSizeCost
argument_list|(
argument|unsigned Opc
argument_list|,
argument|unsigned Idx
argument_list|,
argument|const APInt&Imm
argument_list|,
argument|Type *Ty
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getIntImmCodeSizeCost
argument_list|(
name|Opc
argument_list|,
name|Idx
argument_list|,
name|Imm
argument_list|,
name|Ty
argument_list|)
return|;
block|}
name|int
name|getIntImmCost
argument_list|(
argument|const APInt&Imm
argument_list|,
argument|Type *Ty
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getIntImmCost
argument_list|(
name|Imm
argument_list|,
name|Ty
argument_list|)
return|;
block|}
name|int
name|getIntImmCost
argument_list|(
argument|unsigned Opc
argument_list|,
argument|unsigned Idx
argument_list|,
argument|const APInt&Imm
argument_list|,
argument|Type *Ty
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getIntImmCost
argument_list|(
name|Opc
argument_list|,
name|Idx
argument_list|,
name|Imm
argument_list|,
name|Ty
argument_list|)
return|;
block|}
name|int
name|getIntImmCost
argument_list|(
argument|Intrinsic::ID IID
argument_list|,
argument|unsigned Idx
argument_list|,
argument|const APInt&Imm
argument_list|,
argument|Type *Ty
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getIntImmCost
argument_list|(
name|IID
argument_list|,
name|Idx
argument_list|,
name|Imm
argument_list|,
name|Ty
argument_list|)
return|;
block|}
name|unsigned
name|getNumberOfRegisters
argument_list|(
argument|bool Vector
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getNumberOfRegisters
argument_list|(
name|Vector
argument_list|)
return|;
block|}
name|unsigned
name|getRegisterBitWidth
argument_list|(
argument|bool Vector
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getRegisterBitWidth
argument_list|(
name|Vector
argument_list|)
return|;
block|}
name|unsigned
name|getMinVectorRegisterBitWidth
argument_list|()
name|override
block|{
return|return
name|Impl
operator|.
name|getMinVectorRegisterBitWidth
argument_list|()
return|;
block|}
name|bool
name|shouldConsiderAddressTypePromotion
argument_list|(
argument|const Instruction&I
argument_list|,
argument|bool&AllowPromotionWithoutCommonHeader
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|shouldConsiderAddressTypePromotion
argument_list|(
name|I
argument_list|,
name|AllowPromotionWithoutCommonHeader
argument_list|)
return|;
block|}
name|unsigned
name|getCacheLineSize
argument_list|()
name|override
block|{
return|return
name|Impl
operator|.
name|getCacheLineSize
argument_list|()
return|;
block|}
name|unsigned
name|getPrefetchDistance
argument_list|()
name|override
block|{
return|return
name|Impl
operator|.
name|getPrefetchDistance
argument_list|()
return|;
block|}
name|unsigned
name|getMinPrefetchStride
argument_list|()
name|override
block|{
return|return
name|Impl
operator|.
name|getMinPrefetchStride
argument_list|()
return|;
block|}
name|unsigned
name|getMaxPrefetchIterationsAhead
argument_list|()
name|override
block|{
return|return
name|Impl
operator|.
name|getMaxPrefetchIterationsAhead
argument_list|()
return|;
block|}
name|unsigned
name|getMaxInterleaveFactor
argument_list|(
argument|unsigned VF
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getMaxInterleaveFactor
argument_list|(
name|VF
argument_list|)
return|;
block|}
name|unsigned
name|getEstimatedNumberOfCaseClusters
argument_list|(
argument|const SwitchInst&SI
argument_list|,
argument|unsigned&JTSize
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getEstimatedNumberOfCaseClusters
argument_list|(
name|SI
argument_list|,
name|JTSize
argument_list|)
return|;
block|}
name|unsigned
name|getArithmeticInstrCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Ty
argument_list|,
argument|OperandValueKind Opd1Info
argument_list|,
argument|OperandValueKind Opd2Info
argument_list|,
argument|OperandValueProperties Opd1PropInfo
argument_list|,
argument|OperandValueProperties Opd2PropInfo
argument_list|,
argument|ArrayRef<const Value *> Args
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getArithmeticInstrCost
argument_list|(
name|Opcode
argument_list|,
name|Ty
argument_list|,
name|Opd1Info
argument_list|,
name|Opd2Info
argument_list|,
name|Opd1PropInfo
argument_list|,
name|Opd2PropInfo
argument_list|,
name|Args
argument_list|)
return|;
block|}
name|int
name|getShuffleCost
argument_list|(
argument|ShuffleKind Kind
argument_list|,
argument|Type *Tp
argument_list|,
argument|int Index
argument_list|,
argument|Type *SubTp
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getShuffleCost
argument_list|(
name|Kind
argument_list|,
name|Tp
argument_list|,
name|Index
argument_list|,
name|SubTp
argument_list|)
return|;
block|}
name|int
name|getCastInstrCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Dst
argument_list|,
argument|Type *Src
argument_list|,
argument|const Instruction *I
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getCastInstrCost
argument_list|(
name|Opcode
argument_list|,
name|Dst
argument_list|,
name|Src
argument_list|,
name|I
argument_list|)
return|;
block|}
name|int
name|getExtractWithExtendCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Dst
argument_list|,
argument|VectorType *VecTy
argument_list|,
argument|unsigned Index
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getExtractWithExtendCost
argument_list|(
name|Opcode
argument_list|,
name|Dst
argument_list|,
name|VecTy
argument_list|,
name|Index
argument_list|)
return|;
block|}
name|int
name|getCFInstrCost
argument_list|(
argument|unsigned Opcode
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getCFInstrCost
argument_list|(
name|Opcode
argument_list|)
return|;
block|}
name|int
name|getCmpSelInstrCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *ValTy
argument_list|,
argument|Type *CondTy
argument_list|,
argument|const Instruction *I
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getCmpSelInstrCost
argument_list|(
name|Opcode
argument_list|,
name|ValTy
argument_list|,
name|CondTy
argument_list|,
name|I
argument_list|)
return|;
block|}
name|int
name|getVectorInstrCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Val
argument_list|,
argument|unsigned Index
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getVectorInstrCost
argument_list|(
name|Opcode
argument_list|,
name|Val
argument_list|,
name|Index
argument_list|)
return|;
block|}
name|int
name|getMemoryOpCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Src
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|unsigned AddressSpace
argument_list|,
argument|const Instruction *I
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getMemoryOpCost
argument_list|(
name|Opcode
argument_list|,
name|Src
argument_list|,
name|Alignment
argument_list|,
name|AddressSpace
argument_list|,
name|I
argument_list|)
return|;
block|}
name|int
name|getMaskedMemoryOpCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Src
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|unsigned AddressSpace
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getMaskedMemoryOpCost
argument_list|(
name|Opcode
argument_list|,
name|Src
argument_list|,
name|Alignment
argument_list|,
name|AddressSpace
argument_list|)
return|;
block|}
name|int
name|getGatherScatterOpCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *DataTy
argument_list|,
argument|Value *Ptr
argument_list|,
argument|bool VariableMask
argument_list|,
argument|unsigned Alignment
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getGatherScatterOpCost
argument_list|(
name|Opcode
argument_list|,
name|DataTy
argument_list|,
name|Ptr
argument_list|,
name|VariableMask
argument_list|,
name|Alignment
argument_list|)
return|;
block|}
name|int
name|getInterleavedMemoryOpCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *VecTy
argument_list|,
argument|unsigned Factor
argument_list|,
argument|ArrayRef<unsigned> Indices
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|unsigned AddressSpace
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getInterleavedMemoryOpCost
argument_list|(
name|Opcode
argument_list|,
name|VecTy
argument_list|,
name|Factor
argument_list|,
name|Indices
argument_list|,
name|Alignment
argument_list|,
name|AddressSpace
argument_list|)
return|;
block|}
name|int
name|getReductionCost
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Ty
argument_list|,
argument|bool IsPairwiseForm
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getReductionCost
argument_list|(
name|Opcode
argument_list|,
name|Ty
argument_list|,
name|IsPairwiseForm
argument_list|)
return|;
block|}
name|int
name|getIntrinsicInstrCost
argument_list|(
argument|Intrinsic::ID ID
argument_list|,
argument|Type *RetTy
argument_list|,
argument|ArrayRef<Type *> Tys
argument_list|,
argument|FastMathFlags FMF
argument_list|,
argument|unsigned ScalarizationCostPassed
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getIntrinsicInstrCost
argument_list|(
name|ID
argument_list|,
name|RetTy
argument_list|,
name|Tys
argument_list|,
name|FMF
argument_list|,
name|ScalarizationCostPassed
argument_list|)
return|;
block|}
name|int
name|getIntrinsicInstrCost
argument_list|(
argument|Intrinsic::ID ID
argument_list|,
argument|Type *RetTy
argument_list|,
argument|ArrayRef<Value *> Args
argument_list|,
argument|FastMathFlags FMF
argument_list|,
argument|unsigned VF
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getIntrinsicInstrCost
argument_list|(
name|ID
argument_list|,
name|RetTy
argument_list|,
name|Args
argument_list|,
name|FMF
argument_list|,
name|VF
argument_list|)
return|;
block|}
name|int
name|getCallInstrCost
argument_list|(
argument|Function *F
argument_list|,
argument|Type *RetTy
argument_list|,
argument|ArrayRef<Type *> Tys
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getCallInstrCost
argument_list|(
name|F
argument_list|,
name|RetTy
argument_list|,
name|Tys
argument_list|)
return|;
block|}
name|unsigned
name|getNumberOfParts
argument_list|(
argument|Type *Tp
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getNumberOfParts
argument_list|(
name|Tp
argument_list|)
return|;
block|}
name|int
name|getAddressComputationCost
argument_list|(
argument|Type *Ty
argument_list|,
argument|ScalarEvolution *SE
argument_list|,
argument|const SCEV *Ptr
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getAddressComputationCost
argument_list|(
name|Ty
argument_list|,
name|SE
argument_list|,
name|Ptr
argument_list|)
return|;
block|}
name|unsigned
name|getCostOfKeepingLiveOverCall
argument_list|(
argument|ArrayRef<Type *> Tys
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getCostOfKeepingLiveOverCall
argument_list|(
name|Tys
argument_list|)
return|;
block|}
name|bool
name|getTgtMemIntrinsic
argument_list|(
argument|IntrinsicInst *Inst
argument_list|,
argument|MemIntrinsicInfo&Info
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getTgtMemIntrinsic
argument_list|(
name|Inst
argument_list|,
name|Info
argument_list|)
return|;
block|}
name|Value
operator|*
name|getOrCreateResultFromMemIntrinsic
argument_list|(
argument|IntrinsicInst *Inst
argument_list|,
argument|Type *ExpectedType
argument_list|)
name|override
block|{
return|return
name|Impl
operator|.
name|getOrCreateResultFromMemIntrinsic
argument_list|(
name|Inst
argument_list|,
name|ExpectedType
argument_list|)
return|;
block|}
name|bool
name|areInlineCompatible
argument_list|(
argument|const Function *Caller
argument_list|,
argument|const Function *Callee
argument_list|)
specifier|const
name|override
block|{
return|return
name|Impl
operator|.
name|areInlineCompatible
argument_list|(
name|Caller
argument_list|,
name|Callee
argument_list|)
return|;
block|}
name|unsigned
name|getLoadStoreVecRegBitWidth
argument_list|(
argument|unsigned AddrSpace
argument_list|)
specifier|const
name|override
block|{
return|return
name|Impl
operator|.
name|getLoadStoreVecRegBitWidth
argument_list|(
name|AddrSpace
argument_list|)
return|;
block|}
name|bool
name|isLegalToVectorizeLoad
argument_list|(
argument|LoadInst *LI
argument_list|)
specifier|const
name|override
block|{
return|return
name|Impl
operator|.
name|isLegalToVectorizeLoad
argument_list|(
name|LI
argument_list|)
return|;
block|}
name|bool
name|isLegalToVectorizeStore
argument_list|(
argument|StoreInst *SI
argument_list|)
specifier|const
name|override
block|{
return|return
name|Impl
operator|.
name|isLegalToVectorizeStore
argument_list|(
name|SI
argument_list|)
return|;
block|}
name|bool
name|isLegalToVectorizeLoadChain
argument_list|(
argument|unsigned ChainSizeInBytes
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|unsigned AddrSpace
argument_list|)
specifier|const
name|override
block|{
return|return
name|Impl
operator|.
name|isLegalToVectorizeLoadChain
argument_list|(
name|ChainSizeInBytes
argument_list|,
name|Alignment
argument_list|,
name|AddrSpace
argument_list|)
return|;
block|}
name|bool
name|isLegalToVectorizeStoreChain
argument_list|(
argument|unsigned ChainSizeInBytes
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|unsigned AddrSpace
argument_list|)
specifier|const
name|override
block|{
return|return
name|Impl
operator|.
name|isLegalToVectorizeStoreChain
argument_list|(
name|ChainSizeInBytes
argument_list|,
name|Alignment
argument_list|,
name|AddrSpace
argument_list|)
return|;
block|}
name|unsigned
name|getLoadVectorFactor
argument_list|(
argument|unsigned VF
argument_list|,
argument|unsigned LoadSize
argument_list|,
argument|unsigned ChainSizeInBytes
argument_list|,
argument|VectorType *VecTy
argument_list|)
specifier|const
name|override
block|{
return|return
name|Impl
operator|.
name|getLoadVectorFactor
argument_list|(
name|VF
argument_list|,
name|LoadSize
argument_list|,
name|ChainSizeInBytes
argument_list|,
name|VecTy
argument_list|)
return|;
block|}
name|unsigned
name|getStoreVectorFactor
argument_list|(
argument|unsigned VF
argument_list|,
argument|unsigned StoreSize
argument_list|,
argument|unsigned ChainSizeInBytes
argument_list|,
argument|VectorType *VecTy
argument_list|)
specifier|const
name|override
block|{
return|return
name|Impl
operator|.
name|getStoreVectorFactor
argument_list|(
name|VF
argument_list|,
name|StoreSize
argument_list|,
name|ChainSizeInBytes
argument_list|,
name|VecTy
argument_list|)
return|;
block|}
name|bool
name|useReductionIntrinsic
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Ty
argument_list|,
argument|ReductionFlags Flags
argument_list|)
specifier|const
name|override
block|{
return|return
name|Impl
operator|.
name|useReductionIntrinsic
argument_list|(
name|Opcode
argument_list|,
name|Ty
argument_list|,
name|Flags
argument_list|)
return|;
block|}
name|bool
name|shouldExpandReduction
argument_list|(
argument|const IntrinsicInst *II
argument_list|)
specifier|const
name|override
block|{
return|return
name|Impl
operator|.
name|shouldExpandReduction
argument_list|(
name|II
argument_list|)
return|;
block|}
expr|}
block|;
name|template
operator|<
name|typename
name|T
operator|>
name|TargetTransformInfo
operator|::
name|TargetTransformInfo
argument_list|(
argument|T Impl
argument_list|)
operator|:
name|TTIImpl
argument_list|(
argument|new Model<T>(Impl)
argument_list|)
block|{}
comment|/// \brief Analysis pass providing the \c TargetTransformInfo.
comment|///
comment|/// The core idea of the TargetIRAnalysis is to expose an interface through
comment|/// which LLVM targets can analyze and provide information about the middle
comment|/// end's target-independent IR. This supports use cases such as target-aware
comment|/// cost modeling of IR constructs.
comment|///
comment|/// This is a function analysis because much of the cost modeling for targets
comment|/// is done in a subtarget specific way and LLVM supports compiling different
comment|/// functions targeting different subtargets in order to support runtime
comment|/// dispatch according to the observed subtarget.
name|class
name|TargetIRAnalysis
operator|:
name|public
name|AnalysisInfoMixin
operator|<
name|TargetIRAnalysis
operator|>
block|{
name|public
operator|:
typedef|typedef
name|TargetTransformInfo
name|Result
typedef|;
comment|/// \brief Default construct a target IR analysis.
comment|///
comment|/// This will use the module's datalayout to construct a baseline
comment|/// conservative TTI result.
name|TargetIRAnalysis
argument_list|()
block|;
comment|/// \brief Construct an IR analysis pass around a target-provide callback.
comment|///
comment|/// The callback will be called with a particular function for which the TTI
comment|/// is needed and must return a TTI object for that function.
name|TargetIRAnalysis
argument_list|(
name|std
operator|::
name|function
operator|<
name|Result
argument_list|(
specifier|const
name|Function
operator|&
argument_list|)
operator|>
name|TTICallback
argument_list|)
block|;
comment|// Value semantics. We spell out the constructors for MSVC.
name|TargetIRAnalysis
argument_list|(
specifier|const
name|TargetIRAnalysis
operator|&
name|Arg
argument_list|)
operator|:
name|TTICallback
argument_list|(
argument|Arg.TTICallback
argument_list|)
block|{}
name|TargetIRAnalysis
argument_list|(
name|TargetIRAnalysis
operator|&&
name|Arg
argument_list|)
operator|:
name|TTICallback
argument_list|(
argument|std::move(Arg.TTICallback)
argument_list|)
block|{}
name|TargetIRAnalysis
operator|&
name|operator
operator|=
operator|(
specifier|const
name|TargetIRAnalysis
operator|&
name|RHS
operator|)
block|{
name|TTICallback
operator|=
name|RHS
operator|.
name|TTICallback
block|;
return|return
operator|*
name|this
return|;
block|}
name|TargetIRAnalysis
operator|&
name|operator
operator|=
operator|(
name|TargetIRAnalysis
operator|&&
name|RHS
operator|)
block|{
name|TTICallback
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|TTICallback
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|Result
name|run
argument_list|(
specifier|const
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
argument_list|)
block|;
name|private
operator|:
name|friend
name|AnalysisInfoMixin
operator|<
name|TargetIRAnalysis
operator|>
block|;
specifier|static
name|AnalysisKey
name|Key
block|;
comment|/// \brief The callback used to produce a result.
comment|///
comment|/// We use a completely opaque callback so that targets can provide whatever
comment|/// mechanism they desire for constructing the TTI for a given function.
comment|///
comment|/// FIXME: Should we really use std::function? It's relatively inefficient.
comment|/// It might be possible to arrange for even stateful callbacks to outlive
comment|/// the analysis and thus use a function_ref which would be lighter weight.
comment|/// This may also be less error prone as the callback is likely to reference
comment|/// the external TargetMachine, and that reference needs to never dangle.
name|std
operator|::
name|function
operator|<
name|Result
argument_list|(
specifier|const
name|Function
operator|&
argument_list|)
operator|>
name|TTICallback
block|;
comment|/// \brief Helper function used as the callback in the default constructor.
specifier|static
name|Result
name|getDefaultTTI
argument_list|(
specifier|const
name|Function
operator|&
name|F
argument_list|)
block|; }
expr_stmt|;
comment|/// \brief Wrapper pass for TargetTransformInfo.
comment|///
comment|/// This pass can be constructed from a TTI object which it stores internally
comment|/// and is queried by passes.
name|class
name|TargetTransformInfoWrapperPass
range|:
name|public
name|ImmutablePass
block|{
name|TargetIRAnalysis
name|TIRA
block|;
name|Optional
operator|<
name|TargetTransformInfo
operator|>
name|TTI
block|;
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|/// \brief We must provide a default constructor for the pass but it should
comment|/// never be used.
comment|///
comment|/// Use the constructor below or call one of the creation routines.
name|TargetTransformInfoWrapperPass
argument_list|()
block|;
name|explicit
name|TargetTransformInfoWrapperPass
argument_list|(
argument|TargetIRAnalysis TIRA
argument_list|)
block|;
name|TargetTransformInfo
operator|&
name|getTTI
argument_list|(
specifier|const
name|Function
operator|&
name|F
argument_list|)
block|; }
decl_stmt|;
comment|/// \brief Create an analysis pass wrapper around a TTI object.
comment|///
comment|/// This analysis pass just holds the TTI instance and makes it available to
comment|/// clients.
name|ImmutablePass
modifier|*
name|createTargetTransformInfoWrapperPass
parameter_list|(
name|TargetIRAnalysis
name|TIRA
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

