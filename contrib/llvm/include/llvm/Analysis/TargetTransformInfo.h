begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/TargetTransformInfo.h ----------------------*- C++ -*-===//
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
comment|// This pass exposes codegen information to IR-level passes. Every
end_comment

begin_comment
comment|// transformation that uses codegen information is broken into three parts:
end_comment

begin_comment
comment|// 1. The IR-level analysis pass.
end_comment

begin_comment
comment|// 2. The IR-level transformation interface which provides the needed
end_comment

begin_comment
comment|//    information.
end_comment

begin_comment
comment|// 3. Codegen-level implementation which uses target-specific hooks.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file defines #2, which is the interface that IR-level transformations
end_comment

begin_comment
comment|// use for querying the codegen.
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
file|"llvm/IR/Intrinsics.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GlobalValue
decl_stmt|;
name|class
name|Loop
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
comment|/// TargetTransformInfo - This pass provides access to the codegen
comment|/// interfaces that are needed for IR-level transformations.
name|class
name|TargetTransformInfo
block|{
name|protected
label|:
comment|/// \brief The TTI instance one level down the stack.
comment|///
comment|/// This is used to implement the default behavior all of the methods which
comment|/// is to delegate up through the stack of TTIs until one can answer the
comment|/// query.
name|TargetTransformInfo
modifier|*
name|PrevTTI
decl_stmt|;
comment|/// \brief The top of the stack of TTI analyses available.
comment|///
comment|/// This is a convenience routine maintained as TTI analyses become available
comment|/// that complements the PrevTTI delegation chain. When one part of an
comment|/// analysis pass wants to query another part of the analysis pass it can use
comment|/// this to start back at the top of the stack.
name|TargetTransformInfo
modifier|*
name|TopTTI
decl_stmt|;
comment|/// All pass subclasses must in their initializePass routine call
comment|/// pushTTIStack with themselves to update the pointers tracking the previous
comment|/// TTI instance in the analysis group's stack, and the top of the analysis
comment|/// group's stack.
name|void
name|pushTTIStack
parameter_list|(
name|Pass
modifier|*
name|P
parameter_list|)
function_decl|;
comment|/// All pass subclasses must in their finalizePass routine call popTTIStack
comment|/// to update the pointers tracking the previous TTI instance in the analysis
comment|/// group's stack, and the top of the analysis group's stack.
name|void
name|popTTIStack
parameter_list|()
function_decl|;
comment|/// All pass subclasses must call TargetTransformInfo::getAnalysisUsage.
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
comment|/// This class is intended to be subclassed by real implementations.
name|virtual
operator|~
name|TargetTransformInfo
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|/// \name Generic Target Information
comment|/// @{
comment|/// \brief Underlying constants for 'cost' values in this interface.
comment|///
comment|/// Many APIs in this interface return a cost. This enum defines the
comment|/// fundamental values that should be used to interpret (and produce) those
comment|/// costs. The costs are returned as an unsigned rather than a member of this
comment|/// enumeration because it is expected that the cost of one IR instruction
comment|/// may have a multiplicative factor to it or otherwise won't fit directly
comment|/// into the enum. Moreover, it is common to sum or average costs which works
comment|/// better as simple integral values. Thus this enum only provides constants.
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
name|virtual
name|unsigned
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
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Estimate the cost of a GEP operation when lowered.
comment|///
comment|/// The contract for this function is the same as \c getOperationCost except
comment|/// that it supports an interface that provides extra information specific to
comment|/// the GEP operation.
name|virtual
name|unsigned
name|getGEPCost
argument_list|(
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
name|virtual
name|unsigned
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
name|virtual
name|unsigned
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
name|virtual
name|unsigned
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
comment|/// \brief Estimate the cost of an intrinsic when lowered.
comment|///
comment|/// Mirrors the \c getCallCost method but uses an intrinsic identifier.
name|virtual
name|unsigned
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
name|virtual
name|unsigned
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
name|virtual
name|unsigned
name|getUserCost
argument_list|(
specifier|const
name|User
operator|*
name|U
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief hasBranchDivergence - Return true if branch divergence exists.
comment|/// Branch divergence has a significantly negative impact on GPU performance
comment|/// when threads in the same wavefront take different paths due to conditional
comment|/// branches.
name|virtual
name|bool
name|hasBranchDivergence
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
comment|/// query more accurately as the a call is a single small instruction, but
comment|/// incurs significant execution cost.
name|virtual
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
comment|/// The cost threshold for the unrolled loop, compared to
comment|/// CodeMetrics.NumInsts aggregated over all basic blocks in the loop body.
comment|/// The unrolling factor is set such that the unrolled loop body does not
comment|/// exceed this cost. Set this to UINT_MAX to disable the loop body cost
comment|/// restriction.
name|unsigned
name|Threshold
decl_stmt|;
comment|/// The cost threshold for the unrolled loop when optimizing for size (set
comment|/// to UINT_MAX to disable).
name|unsigned
name|OptSizeThreshold
decl_stmt|;
comment|/// A forced unrolling factor (the number of concatenated bodies of the
comment|/// original loop in the unrolled loop body). When set to 0, the unrolling
comment|/// transformation will select an unrolling factor based on the current cost
comment|/// threshold and other factors.
name|unsigned
name|Count
decl_stmt|;
comment|/// Allow partial unrolling (unrolling of loops to expand the size of the
comment|/// loop body, not only to eliminate small constant-trip-count loops).
name|bool
name|Partial
decl_stmt|;
comment|/// Allow runtime unrolling (unrolling of loops to expand the size of the
comment|/// loop body even when the number of loop iterations is not known at compile
comment|/// time).
name|bool
name|Runtime
decl_stmt|;
block|}
struct|;
comment|/// \brief Get target-customized preferences for the generic loop unrolling
comment|/// transformation. The caller will initialize UP with the current
comment|/// target-independent defaults.
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
comment|/// isLegalAddImmediate - Return true if the specified immediate is legal
comment|/// add immediate, that is the target has add instructions which can add
comment|/// a register with the immediate without having to materialize the
comment|/// immediate into a register.
name|virtual
name|bool
name|isLegalAddImmediate
argument_list|(
name|int64_t
name|Imm
argument_list|)
decl|const
decl_stmt|;
comment|/// isLegalICmpImmediate - Return true if the specified immediate is legal
comment|/// icmp immediate, that is the target has icmp instructions which can compare
comment|/// a register against the immediate without having to materialize the
comment|/// immediate into a register.
name|virtual
name|bool
name|isLegalICmpImmediate
argument_list|(
name|int64_t
name|Imm
argument_list|)
decl|const
decl_stmt|;
comment|/// isLegalAddressingMode - Return true if the addressing mode represented by
comment|/// AM is legal for this target, for a load/store of the specified type.
comment|/// The type may be VoidTy, in which case only return true if the addressing
comment|/// mode is legal for a load/store of any legal type.
comment|/// TODO: Handle pre/postinc as well.
name|virtual
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
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return the cost of the scaling factor used in the addressing
comment|/// mode represented by AM for this target, for a load/store
comment|/// of the specified type.
comment|/// If the AM is supported, the return value must be>= 0.
comment|/// If the AM is not supported, it returns a negative value.
comment|/// TODO: Handle pre/postinc as well.
name|virtual
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
argument_list|)
decl|const
decl_stmt|;
comment|/// isTruncateFree - Return true if it's free to truncate a value of
comment|/// type Ty1 to type Ty2. e.g. On x86 it's free to truncate a i32 value in
comment|/// register EAX to i16 by referencing its sub-register AX.
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
decl|const
decl_stmt|;
comment|/// Is this type legal.
name|virtual
name|bool
name|isTypeLegal
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// getJumpBufAlignment - returns the target's jmp_buf alignment in bytes
name|virtual
name|unsigned
name|getJumpBufAlignment
argument_list|()
specifier|const
expr_stmt|;
comment|/// getJumpBufSize - returns the target's jmp_buf size in bytes.
name|virtual
name|unsigned
name|getJumpBufSize
argument_list|()
specifier|const
expr_stmt|;
comment|/// shouldBuildLookupTables - Return true if switches should be turned into
comment|/// lookup tables for the target.
name|virtual
name|bool
name|shouldBuildLookupTables
argument_list|()
specifier|const
expr_stmt|;
comment|/// getPopcntSupport - Return hardware support for population count.
name|virtual
name|PopcntSupportKind
name|getPopcntSupport
argument_list|(
name|unsigned
name|IntTyWidthInBit
argument_list|)
decl|const
decl_stmt|;
comment|/// haveFastSqrt -- Return true if the hardware has a fast square-root
comment|/// instruction.
name|virtual
name|bool
name|haveFastSqrt
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// getIntImmCost - Return the expected cost of materializing the given
comment|/// integer immediate of the specified type.
name|virtual
name|unsigned
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
name|SK_InsertSubvector
block|,
comment|///< InsertSubvector. Index indicates start offset.
name|SK_ExtractSubvector
comment|///< ExtractSubvector Index indicates start offset.
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
comment|// Operand is uniform constant.
block|}
enum|;
comment|/// \return The number of scalar or vector registers that the target has.
comment|/// If 'Vectors' is true, it returns the number of vector registers. If it is
comment|/// set to false, it returns the number of scalar registers.
name|virtual
name|unsigned
name|getNumberOfRegisters
argument_list|(
name|bool
name|Vector
argument_list|)
decl|const
decl_stmt|;
comment|/// \return The width of the largest scalar or vector register type.
name|virtual
name|unsigned
name|getRegisterBitWidth
argument_list|(
name|bool
name|Vector
argument_list|)
decl|const
decl_stmt|;
comment|/// \return The maximum unroll factor that the vectorizer should try to
comment|/// perform for this target. This number depends on the level of parallelism
comment|/// and the number of execution units in the CPU.
name|virtual
name|unsigned
name|getMaximumUnrollFactor
argument_list|()
specifier|const
expr_stmt|;
comment|/// \return The expected cost of arithmetic ops, such as mul, xor, fsub, etc.
name|virtual
name|unsigned
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
argument_list|)
decl|const
decl_stmt|;
comment|/// \return The cost of a shuffle instruction of kind Kind and of type Tp.
comment|/// The index and subtype parameters are used by the subvector insertion and
comment|/// extraction shuffle kinds.
name|virtual
name|unsigned
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
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// \return The expected cost of cast instructions, such as bitcast, trunc,
comment|/// zext, etc.
name|virtual
name|unsigned
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
argument_list|)
decl|const
decl_stmt|;
comment|/// \return The expected cost of control-flow related instructions such as
comment|/// Phi, Ret, Br.
name|virtual
name|unsigned
name|getCFInstrCost
argument_list|(
name|unsigned
name|Opcode
argument_list|)
decl|const
decl_stmt|;
comment|/// \returns The expected cost of compare and select instructions.
name|virtual
name|unsigned
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
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// \return The expected cost of vector Insert and Extract.
comment|/// Use -1 to indicate that there is no information on the index value.
name|virtual
name|unsigned
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
name|virtual
name|unsigned
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
name|virtual
name|unsigned
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
comment|/// \returns The cost of Intrinsic instructions.
name|virtual
name|unsigned
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
argument_list|)
decl|const
decl_stmt|;
comment|/// \returns The number of pieces into which the provided type must be
comment|/// split during legalization. Zero is returned when the answer is unknown.
name|virtual
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
comment|/// The 'IsComplex' parameter is a hint that the address computation is likely
comment|/// to involve multiple instructions and as such unlikely to be merged into
comment|/// the address indexing mode.
name|virtual
name|unsigned
name|getAddressComputationCost
argument_list|(
name|Type
operator|*
name|Ty
argument_list|,
name|bool
name|IsComplex
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
comment|/// Analysis group identification.
specifier|static
name|char
name|ID
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief Create the base case instance of a pass in the TTI analysis group.
comment|///
comment|/// This class provides the base case for the stack of TTI analyzes. It doesn't
comment|/// delegate to anything and uses the STTI and VTTI objects passed in to
comment|/// satisfy the queries.
name|ImmutablePass
modifier|*
name|createNoTargetTransformInfoPass
parameter_list|()
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

