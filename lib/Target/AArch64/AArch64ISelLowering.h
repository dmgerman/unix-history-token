begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- AArch64ISelLowering.h - AArch64 DAG Lowering Interface ----*- C++ -*-==//
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
comment|// This file defines the interfaces that AArch64 uses to lower LLVM code into a
end_comment

begin_comment
comment|// selection DAG.
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
name|LLVM_TARGET_AArch64_ISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_AArch64_ISELLOWERING_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/CallingConvLower.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallingConv.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetLowering.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|AArch64ISD
block|{
enum|enum
block|{
name|FIRST_NUMBER
init|=
name|ISD
operator|::
name|BUILTIN_OP_END
block|,
name|WrapperLarge
block|,
comment|// 4-instruction MOVZ/MOVK sequence for 64-bit addresses.
name|CALL
block|,
comment|// Function call.
comment|// Almost the same as a normal call node, except that a TLSDesc relocation is
comment|// needed so the linker can relax it correctly if possible.
name|TLSDESC_CALL
block|,
name|ADRP
block|,
comment|// Page address of a TargetGlobalAddress operand.
name|ADDlow
block|,
comment|// Add the low 12 bits of a TargetGlobalAddress operand.
name|LOADgot
block|,
comment|// Load from automatically generated descriptor (e.g. Global
comment|// Offset Table, TLS record).
name|RET_FLAG
block|,
comment|// Return with a flag operand. Operand 0 is the chain operand.
name|BRCOND
block|,
comment|// Conditional branch instruction; "b.cond".
name|CSEL
block|,
name|FCSEL
block|,
comment|// Conditional move instruction.
name|CSINV
block|,
comment|// Conditional select invert.
name|CSNEG
block|,
comment|// Conditional select negate.
name|CSINC
block|,
comment|// Conditional select increment.
comment|// Pointer to the thread's local storage area. Materialised from TPIDR_EL0 on
comment|// ELF.
name|THREAD_POINTER
block|,
name|ADC
block|,
name|SBC
block|,
comment|// adc, sbc instructions
comment|// Arithmetic instructions which write flags.
name|ADDS
block|,
name|SUBS
block|,
name|ADCS
block|,
name|SBCS
block|,
name|ANDS
block|,
comment|// Floating point comparison
name|FCMP
block|,
comment|// Floating point max and min instructions.
name|FMAX
block|,
name|FMIN
block|,
comment|// Scalar extract
name|EXTR
block|,
comment|// Scalar-to-vector duplication
name|DUP
block|,
name|DUPLANE8
block|,
name|DUPLANE16
block|,
name|DUPLANE32
block|,
name|DUPLANE64
block|,
comment|// Vector immedate moves
name|MOVI
block|,
name|MOVIshift
block|,
name|MOVIedit
block|,
name|MOVImsl
block|,
name|FMOV
block|,
name|MVNIshift
block|,
name|MVNImsl
block|,
comment|// Vector immediate ops
name|BICi
block|,
name|ORRi
block|,
comment|// Vector bit select: similar to ISD::VSELECT but not all bits within an
comment|// element must be identical.
name|BSL
block|,
comment|// Vector arithmetic negation
name|NEG
block|,
comment|// Vector shuffles
name|ZIP1
block|,
name|ZIP2
block|,
name|UZP1
block|,
name|UZP2
block|,
name|TRN1
block|,
name|TRN2
block|,
name|REV16
block|,
name|REV32
block|,
name|REV64
block|,
name|EXT
block|,
comment|// Vector shift by scalar
name|VSHL
block|,
name|VLSHR
block|,
name|VASHR
block|,
comment|// Vector shift by scalar (again)
name|SQSHL_I
block|,
name|UQSHL_I
block|,
name|SQSHLU_I
block|,
name|SRSHR_I
block|,
name|URSHR_I
block|,
comment|// Vector comparisons
name|CMEQ
block|,
name|CMGE
block|,
name|CMGT
block|,
name|CMHI
block|,
name|CMHS
block|,
name|FCMEQ
block|,
name|FCMGE
block|,
name|FCMGT
block|,
comment|// Vector zero comparisons
name|CMEQz
block|,
name|CMGEz
block|,
name|CMGTz
block|,
name|CMLEz
block|,
name|CMLTz
block|,
name|FCMEQz
block|,
name|FCMGEz
block|,
name|FCMGTz
block|,
name|FCMLEz
block|,
name|FCMLTz
block|,
comment|// Vector bitwise negation
name|NOT
block|,
comment|// Vector bitwise selection
name|BIT
block|,
comment|// Compare-and-branch
name|CBZ
block|,
name|CBNZ
block|,
name|TBZ
block|,
name|TBNZ
block|,
comment|// Tail calls
name|TC_RETURN
block|,
comment|// Custom prefetch handling
name|PREFETCH
block|,
comment|// {s|u}int to FP within a FP register.
name|SITOF
block|,
name|UITOF
block|,
comment|// NEON Load/Store with post-increment base updates
name|LD2post
init|=
name|ISD
operator|::
name|FIRST_TARGET_MEMORY_OPCODE
block|,
name|LD3post
block|,
name|LD4post
block|,
name|ST2post
block|,
name|ST3post
block|,
name|ST4post
block|,
name|LD1x2post
block|,
name|LD1x3post
block|,
name|LD1x4post
block|,
name|ST1x2post
block|,
name|ST1x3post
block|,
name|ST1x4post
block|,
name|LD1DUPpost
block|,
name|LD2DUPpost
block|,
name|LD3DUPpost
block|,
name|LD4DUPpost
block|,
name|LD1LANEpost
block|,
name|LD2LANEpost
block|,
name|LD3LANEpost
block|,
name|LD4LANEpost
block|,
name|ST2LANEpost
block|,
name|ST3LANEpost
block|,
name|ST4LANEpost
block|}
enum|;
block|}
comment|// end namespace AArch64ISD
name|class
name|AArch64Subtarget
decl_stmt|;
name|class
name|AArch64TargetMachine
decl_stmt|;
name|class
name|AArch64TargetLowering
range|:
name|public
name|TargetLowering
block|{
name|bool
name|RequireStrictAlign
block|;
name|public
operator|:
name|explicit
name|AArch64TargetLowering
argument_list|(
name|TargetMachine
operator|&
name|TM
argument_list|)
block|;
comment|/// Selects the correct CCAssignFn for a the given CallingConvention
comment|/// value.
name|CCAssignFn
operator|*
name|CCAssignFnForCall
argument_list|(
argument|CallingConv::ID CC
argument_list|,
argument|bool IsVarArg
argument_list|)
specifier|const
block|;
comment|/// computeKnownBitsForTargetNode - Determine which of the bits specified in
comment|/// Mask are known to be either zero or one and return them in the
comment|/// KnownZero/KnownOne bitsets.
name|void
name|computeKnownBitsForTargetNode
argument_list|(
argument|const SDValue Op
argument_list|,
argument|APInt&KnownZero
argument_list|,
argument|APInt&KnownOne
argument_list|,
argument|const SelectionDAG&DAG
argument_list|,
argument|unsigned Depth =
literal|0
argument_list|)
specifier|const
name|override
block|;
name|MVT
name|getScalarShiftAmountTy
argument_list|(
argument|EVT LHSTy
argument_list|)
specifier|const
name|override
block|;
comment|/// allowsUnalignedMemoryAccesses - Returns true if the target allows
comment|/// unaligned memory accesses. of the specified type.
name|bool
name|allowsUnalignedMemoryAccesses
argument_list|(
argument|EVT VT
argument_list|,
argument|unsigned AddrSpace =
literal|0
argument_list|,
argument|bool *Fast = nullptr
argument_list|)
specifier|const
name|override
block|{
if|if
condition|(
name|RequireStrictAlign
condition|)
return|return
name|false
return|;
comment|// FIXME: True for Cyclone, but not necessary others.
if|if
condition|(
name|Fast
condition|)
operator|*
name|Fast
operator|=
name|true
expr_stmt|;
return|return
name|true
return|;
block|}
end_decl_stmt

begin_comment
comment|/// LowerOperation - Provide custom lowering hooks for some operations.
end_comment

begin_decl_stmt
name|SDValue
name|LowerOperation
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|getTargetNodeName
argument_list|(
name|unsigned
name|Opcode
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|PerformDAGCombine
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|DAGCombinerInfo
operator|&
name|DCI
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getFunctionAlignment - Return the Log2 alignment of this function.
end_comment

begin_decl_stmt
name|unsigned
name|getFunctionAlignment
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getMaximalGlobalOffset - Returns the maximal possible offset which can
end_comment

begin_comment
comment|/// be used for loads / stores from the global.
end_comment

begin_expr_stmt
name|unsigned
name|getMaximalGlobalOffset
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Returns true if a cast between SrcAS and DestAS is a noop.
end_comment

begin_decl_stmt
name|bool
name|isNoopAddrSpaceCast
argument_list|(
name|unsigned
name|SrcAS
argument_list|,
name|unsigned
name|DestAS
argument_list|)
decl|const
name|override
block|{
comment|// Addrspacecasts are always noops.
return|return
name|true
return|;
block|}
end_decl_stmt

begin_comment
comment|/// createFastISel - This method returns a target specific FastISel object,
end_comment

begin_comment
comment|/// or null if the target does not support "fast" ISel.
end_comment

begin_decl_stmt
name|FastISel
modifier|*
name|createFastISel
argument_list|(
name|FunctionLoweringInfo
operator|&
name|funcInfo
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|*
name|libInfo
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|isOffsetFoldingLegal
argument_list|(
specifier|const
name|GlobalAddressSDNode
operator|*
name|GA
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|isFPImmLegal
argument_list|(
specifier|const
name|APFloat
operator|&
name|Imm
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// isShuffleMaskLegal - Return true if the given shuffle mask can be
end_comment

begin_comment
comment|/// codegen'd directly, or if it should be stack expanded.
end_comment

begin_decl_stmt
name|bool
name|isShuffleMaskLegal
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|M
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getSetCCResultType - Return the ISD::SETCC ValueType
end_comment

begin_decl_stmt
name|EVT
name|getSetCCResultType
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|ReconstructShuffle
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MachineBasicBlock
modifier|*
name|EmitF128CSEL
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|,
name|MachineBasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MachineBasicBlock
modifier|*
name|EmitInstrWithCustomInserter
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|,
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|getTgtMemIntrinsic
argument_list|(
name|IntrinsicInfo
operator|&
name|Info
argument_list|,
specifier|const
name|CallInst
operator|&
name|I
argument_list|,
name|unsigned
name|Intrinsic
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|isTruncateFree
argument_list|(
name|EVT
name|VT1
argument_list|,
name|EVT
name|VT2
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|isZExtFree
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
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|isZExtFree
argument_list|(
name|EVT
name|VT1
argument_list|,
name|EVT
name|VT2
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|isZExtFree
argument_list|(
name|SDValue
name|Val
argument_list|,
name|EVT
name|VT2
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|hasPairedLoad
argument_list|(
name|Type
operator|*
name|LoadedType
argument_list|,
name|unsigned
operator|&
name|RequiredAligment
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|hasPairedLoad
argument_list|(
name|EVT
name|LoadedType
argument_list|,
name|unsigned
operator|&
name|RequiredAligment
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|isLegalAddImmediate
argument_list|(
name|int64_t
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|isLegalICmpImmediate
argument_list|(
name|int64_t
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EVT
name|getOptimalMemOpType
argument_list|(
name|uint64_t
name|Size
argument_list|,
name|unsigned
name|DstAlign
argument_list|,
name|unsigned
name|SrcAlign
argument_list|,
name|bool
name|IsMemset
argument_list|,
name|bool
name|ZeroMemset
argument_list|,
name|bool
name|MemcpyStrSrc
argument_list|,
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// isLegalAddressingMode - Return true if the addressing mode represented
end_comment

begin_comment
comment|/// by AM is legal for this target, for a load/store of the specified type.
end_comment

begin_decl_stmt
name|bool
name|isLegalAddressingMode
argument_list|(
specifier|const
name|AddrMode
operator|&
name|AM
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Return the cost of the scaling factor used in the addressing
end_comment

begin_comment
comment|/// mode represented by AM for this target, for a load/store
end_comment

begin_comment
comment|/// of the specified type.
end_comment

begin_comment
comment|/// If the AM is supported, the return value must be>= 0.
end_comment

begin_comment
comment|/// If the AM is not supported, it returns a negative value.
end_comment

begin_decl_stmt
name|int
name|getScalingFactorCost
argument_list|(
specifier|const
name|AddrMode
operator|&
name|AM
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// isFMAFasterThanFMulAndFAdd - Return true if an FMA operation is faster
end_comment

begin_comment
comment|/// than a pair of fmul and fadd instructions. fmuladd intrinsics will be
end_comment

begin_comment
comment|/// expanded to FMAs when this method returns true, otherwise fmuladd is
end_comment

begin_comment
comment|/// expanded to fmul + fadd.
end_comment

begin_decl_stmt
name|bool
name|isFMAFasterThanFMulAndFAdd
argument_list|(
name|EVT
name|VT
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|MCPhysReg
modifier|*
name|getScratchRegisters
argument_list|(
name|CallingConv
operator|::
name|ID
name|CC
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Returns false if N is a bit extraction pattern of (X>> C)& Mask.
end_comment

begin_decl_stmt
name|bool
name|isDesirableToCommuteWithShift
argument_list|(
specifier|const
name|SDNode
operator|*
name|N
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Returns true if it is beneficial to convert a load of a constant
end_comment

begin_comment
comment|/// to just the constant itself.
end_comment

begin_decl_stmt
name|bool
name|shouldConvertConstantLoadToIntImm
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
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Value
modifier|*
name|emitLoadLinked
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|Builder
argument_list|,
name|Value
operator|*
name|Addr
argument_list|,
name|AtomicOrdering
name|Ord
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Value
modifier|*
name|emitStoreConditional
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|Builder
argument_list|,
name|Value
operator|*
name|Val
argument_list|,
name|Value
operator|*
name|Addr
argument_list|,
name|AtomicOrdering
name|Ord
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|shouldExpandAtomicInIR
argument_list|(
name|Instruction
operator|*
name|Inst
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|TargetLoweringBase
operator|::
name|LegalizeTypeAction
name|getPreferredVectorAction
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|/// Subtarget - Keep a pointer to the AArch64Subtarget around so that we can
end_comment

begin_comment
comment|/// make the right decision when generating code for different targets.
end_comment

begin_decl_stmt
specifier|const
name|AArch64Subtarget
modifier|*
name|Subtarget
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|addTypeForNEON
parameter_list|(
name|EVT
name|VT
parameter_list|,
name|EVT
name|PromotedBitwiseVT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addDRTypeForNEON
parameter_list|(
name|MVT
name|VT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addQRTypeForNEON
parameter_list|(
name|MVT
name|VT
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|SDValue
name|LowerFormalArguments
argument_list|(
name|SDValue
name|Chain
argument_list|,
name|CallingConv
operator|::
name|ID
name|CallConv
argument_list|,
name|bool
name|isVarArg
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|InputArg
operator|>
operator|&
name|Ins
argument_list|,
name|SDLoc
name|DL
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|InVals
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerCall
argument_list|(
name|CallLoweringInfo
operator|&
comment|/*CLI*/
argument_list|,
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|InVals
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerCallResult
argument_list|(
name|SDValue
name|Chain
argument_list|,
name|SDValue
name|InFlag
argument_list|,
name|CallingConv
operator|::
name|ID
name|CallConv
argument_list|,
name|bool
name|isVarArg
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|InputArg
operator|>
operator|&
name|Ins
argument_list|,
name|SDLoc
name|DL
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|InVals
argument_list|,
name|bool
name|isThisReturn
argument_list|,
name|SDValue
name|ThisVal
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|isEligibleForTailCallOptimization
argument_list|(
name|SDValue
name|Callee
argument_list|,
name|CallingConv
operator|::
name|ID
name|CalleeCC
argument_list|,
name|bool
name|isVarArg
argument_list|,
name|bool
name|isCalleeStructRet
argument_list|,
name|bool
name|isCallerStructRet
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|OutputArg
operator|>
operator|&
name|Outs
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|OutVals
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|InputArg
operator|>
operator|&
name|Ins
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Finds the incoming stack arguments which overlap the given fixed stack
end_comment

begin_comment
comment|/// object and incorporates their load into the current chain. This prevents
end_comment

begin_comment
comment|/// an upcoming store from clobbering the stack argument before it's used.
end_comment

begin_decl_stmt
name|SDValue
name|addTokenForArgument
argument_list|(
name|SDValue
name|Chain
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|MachineFrameInfo
operator|*
name|MFI
argument_list|,
name|int
name|ClobberedFI
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|DoesCalleeRestoreStack
argument_list|(
name|CallingConv
operator|::
name|ID
name|CallCC
argument_list|,
name|bool
name|TailCallOpt
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|IsTailCallConvention
argument_list|(
name|CallingConv
operator|::
name|ID
name|CallCC
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|saveVarArgRegisters
argument_list|(
name|CCState
operator|&
name|CCInfo
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|SDLoc
name|DL
argument_list|,
name|SDValue
operator|&
name|Chain
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|CanLowerReturn
argument_list|(
name|CallingConv
operator|::
name|ID
name|CallConv
argument_list|,
name|MachineFunction
operator|&
name|MF
argument_list|,
name|bool
name|isVarArg
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|OutputArg
operator|>
operator|&
name|Outs
argument_list|,
name|LLVMContext
operator|&
name|Context
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerReturn
argument_list|(
name|SDValue
name|Chain
argument_list|,
name|CallingConv
operator|::
name|ID
name|CallConv
argument_list|,
name|bool
name|isVarArg
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|OutputArg
operator|>
operator|&
name|Outs
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|OutVals
argument_list|,
name|SDLoc
name|DL
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerGlobalAddress
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerGlobalTLSAddress
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerDarwinGlobalTLSAddress
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerELFGlobalTLSAddress
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerELFTLSDescCall
argument_list|(
name|SDValue
name|SymAddr
argument_list|,
name|SDValue
name|DescAddr
argument_list|,
name|SDLoc
name|DL
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerSETCC
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerBR_CC
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerSELECT
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerSELECT_CC
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerJumpTable
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerConstantPool
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerBlockAddress
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerAAPCS_VASTART
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerDarwin_VASTART
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerVASTART
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerVACOPY
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerVAARG
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerFRAMEADDR
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerRETURNADDR
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerINSERT_VECTOR_ELT
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerEXTRACT_VECTOR_ELT
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerSCALAR_TO_VECTOR
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerBUILD_VECTOR
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerVECTOR_SHUFFLE
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerEXTRACT_SUBVECTOR
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerVectorSRA_SRL_SHL
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerShiftLeftParts
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerShiftRightParts
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerVSETCC
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerCTPOP
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerF128Call
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|RTLIB
operator|::
name|Libcall
name|Call
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerFCOPYSIGN
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerFP_EXTEND
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerFP_ROUND
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerFP_TO_INT
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerINT_TO_FP
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerVectorAND
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerVectorOR
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerCONCAT_VECTORS
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerFSINCOS
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ConstraintType
name|getConstraintType
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Constraint
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|getRegisterByName
argument_list|(
specifier|const
name|char
operator|*
name|RegName
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Examine constraint string and operand type and determine a weight value.
end_comment

begin_comment
comment|/// The operand object must already have been set up with the operand type.
end_comment

begin_decl_stmt
name|ConstraintWeight
name|getSingleConstraintMatchWeight
argument_list|(
name|AsmOperandInfo
operator|&
name|info
argument_list|,
specifier|const
name|char
operator|*
name|constraint
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
specifier|const
name|TargetRegisterClass
operator|*
operator|>
name|getRegForInlineAsmConstraint
argument_list|(
argument|const std::string&Constraint
argument_list|,
argument|MVT VT
argument_list|)
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|LowerAsmOperandForConstraint
argument_list|(
name|SDValue
name|Op
argument_list|,
name|std
operator|::
name|string
operator|&
name|Constraint
argument_list|,
name|std
operator|::
name|vector
operator|<
name|SDValue
operator|>
operator|&
name|Ops
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|isUsedByReturnOnly
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|SDValue
operator|&
name|Chain
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|mayBeEmittedAsTailCall
argument_list|(
name|CallInst
operator|*
name|CI
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|getIndexedAddressParts
argument_list|(
name|SDNode
operator|*
name|Op
argument_list|,
name|SDValue
operator|&
name|Base
argument_list|,
name|SDValue
operator|&
name|Offset
argument_list|,
name|ISD
operator|::
name|MemIndexedMode
operator|&
name|AM
argument_list|,
name|bool
operator|&
name|IsInc
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|getPreIndexedAddressParts
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|SDValue
operator|&
name|Base
argument_list|,
name|SDValue
operator|&
name|Offset
argument_list|,
name|ISD
operator|::
name|MemIndexedMode
operator|&
name|AM
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|getPostIndexedAddressParts
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|SDNode
operator|*
name|Op
argument_list|,
name|SDValue
operator|&
name|Base
argument_list|,
name|SDValue
operator|&
name|Offset
argument_list|,
name|ISD
operator|::
name|MemIndexedMode
operator|&
name|AM
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ReplaceNodeResults
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|Results
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|};
name|namespace
name|AArch64
block|{
name|FastISel
modifier|*
name|createFastISel
parameter_list|(
name|FunctionLoweringInfo
modifier|&
name|funcInfo
parameter_list|,
specifier|const
name|TargetLibraryInfo
modifier|*
name|libInfo
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace AArch64
end_comment

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TARGET_AArch64_ISELLOWERING_H
end_comment

end_unit

