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
name|LLVM_LIB_TARGET_AARCH64_AARCH64ISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AARCH64_AARCH64ISELLOWERING_H
end_define

begin_include
include|#
directive|include
file|"AArch64.h"
end_include

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
file|"llvm/IR/Instruction.h"
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
name|NodeType
enum|:
name|unsigned
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
comment|// Produces the full sequence of instructions for getting the thread pointer
comment|// offset of a variable into X0, using the TLSDesc model.
name|TLSDESC_CALLSEQ
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
comment|// Conditional compares. Operands: left,right,falsecc,cc,flags
name|CCMP
block|,
name|CCMN
block|,
name|FCCMP
block|,
comment|// Floating point comparison
name|FCMP
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
comment|// Vector across-lanes addition
comment|// Only the lower result lane is defined.
name|SADDV
block|,
name|UADDV
block|,
comment|// Vector across-lanes min/max
comment|// Only the lower result lane is defined.
name|SMINV
block|,
name|UMINV
block|,
name|SMAXV
block|,
name|UMAXV
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
comment|/// Natural vector cast. ISD::BITCAST is not natural in the big-endian
comment|/// world w.r.t vectors; which causes additional REV instructions to be
comment|/// generated to compensate for the byte-swapping. But sometimes we do
comment|/// need to re-interpret the data in SIMD vector registers in big-endian
comment|/// mode without emitting such REV instructions.
name|NVCAST
block|,
name|SMULL
block|,
name|UMULL
block|,
comment|// Reciprocal estimates and steps.
name|FRECPE
block|,
name|FRECPS
block|,
name|FRSQRTE
block|,
name|FRSQRTS
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
name|namespace
block|{
comment|// Any instruction that defines a 32-bit result zeros out the high half of the
comment|// register. Truncate can be lowered to EXTRACT_SUBREG. CopyFromReg may
comment|// be copying from a truncate. But any other 32-bit operation will zero-extend
comment|// up to 64 bits.
comment|// FIXME: X86 also checks for CMOV here. Do we need something similar?
specifier|static
specifier|inline
name|bool
name|isDef32
parameter_list|(
specifier|const
name|SDNode
modifier|&
name|N
parameter_list|)
block|{
name|unsigned
name|Opc
init|=
name|N
operator|.
name|getOpcode
argument_list|()
decl_stmt|;
return|return
name|Opc
operator|!=
name|ISD
operator|::
name|TRUNCATE
operator|&&
name|Opc
operator|!=
name|TargetOpcode
operator|::
name|EXTRACT_SUBREG
operator|&&
name|Opc
operator|!=
name|ISD
operator|::
name|CopyFromReg
return|;
block|}
block|}
comment|// end anonymous namespace
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
name|public
operator|:
name|explicit
name|AArch64TargetLowering
argument_list|(
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|,
specifier|const
name|AArch64Subtarget
operator|&
name|STI
argument_list|)
block|;
comment|/// Selects the correct CCAssignFn for a given CallingConvention value.
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
comment|/// Selects the correct CCAssignFn for a given CallingConvention value.
name|CCAssignFn
operator|*
name|CCAssignFnForReturn
argument_list|(
argument|CallingConv::ID CC
argument_list|)
specifier|const
block|;
comment|/// Determine which of the bits specified in Mask are known to be either zero
comment|/// or one and return them in the KnownZero/KnownOne bitsets.
name|void
name|computeKnownBitsForTargetNode
argument_list|(
argument|const SDValue Op
argument_list|,
argument|APInt&KnownZero
argument_list|,
argument|APInt&KnownOne
argument_list|,
argument|const APInt&DemandedElts
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
argument|const DataLayout&DL
argument_list|,
argument|EVT
argument_list|)
specifier|const
name|override
block|;
comment|/// Returns true if the target allows unaligned memory accesses of the
comment|/// specified type.
name|bool
name|allowsMisalignedMemoryAccesses
argument_list|(
argument|EVT VT
argument_list|,
argument|unsigned AddrSpace =
literal|0
argument_list|,
argument|unsigned Align =
literal|1
argument_list|,
argument|bool *Fast = nullptr
argument_list|)
specifier|const
name|override
block|;
comment|/// Provide custom lowering hooks for some operations.
name|SDValue
name|LowerOperation
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|char
operator|*
name|getTargetNodeName
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
name|override
block|;
name|SDValue
name|PerformDAGCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
name|override
block|;
comment|/// Returns true if a cast between SrcAS and DestAS is a noop.
name|bool
name|isNoopAddrSpaceCast
argument_list|(
argument|unsigned SrcAS
argument_list|,
argument|unsigned DestAS
argument_list|)
specifier|const
name|override
block|{
comment|// Addrspacecasts are always noops.
return|return
name|true
return|;
block|}
comment|/// This method returns a target specific FastISel object, or null if the
comment|/// target does not support "fast" ISel.
name|FastISel
operator|*
name|createFastISel
argument_list|(
argument|FunctionLoweringInfo&funcInfo
argument_list|,
argument|const TargetLibraryInfo *libInfo
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isOffsetFoldingLegal
argument_list|(
argument|const GlobalAddressSDNode *GA
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isFPImmLegal
argument_list|(
argument|const APFloat&Imm
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
comment|/// Return true if the given shuffle mask can be codegen'd directly, or if it
comment|/// should be stack expanded.
name|bool
name|isShuffleMaskLegal
argument_list|(
argument|const SmallVectorImpl<int>&M
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
comment|/// Return the ISD::SETCC ValueType.
name|EVT
name|getSetCCResultType
argument_list|(
argument|const DataLayout&DL
argument_list|,
argument|LLVMContext&Context
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
name|SDValue
name|ReconstructShuffle
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|EmitF128CSEL
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|EmitInstrWithCustomInserter
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|MachineBasicBlock *MBB
argument_list|)
specifier|const
name|override
block|;
name|bool
name|getTgtMemIntrinsic
argument_list|(
argument|IntrinsicInfo&Info
argument_list|,
argument|const CallInst&I
argument_list|,
argument|unsigned Intrinsic
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isTruncateFree
argument_list|(
argument|Type *Ty1
argument_list|,
argument|Type *Ty2
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isTruncateFree
argument_list|(
argument|EVT VT1
argument_list|,
argument|EVT VT2
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isProfitableToHoist
argument_list|(
argument|Instruction *I
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isZExtFree
argument_list|(
argument|Type *Ty1
argument_list|,
argument|Type *Ty2
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isZExtFree
argument_list|(
argument|EVT VT1
argument_list|,
argument|EVT VT2
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isZExtFree
argument_list|(
argument|SDValue Val
argument_list|,
argument|EVT VT2
argument_list|)
specifier|const
name|override
block|;
name|bool
name|hasPairedLoad
argument_list|(
argument|EVT LoadedType
argument_list|,
argument|unsigned&RequiredAligment
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getMaxSupportedInterleaveFactor
argument_list|()
specifier|const
name|override
block|{
return|return
literal|4
return|;
block|}
name|bool
name|lowerInterleavedLoad
argument_list|(
argument|LoadInst *LI
argument_list|,
argument|ArrayRef<ShuffleVectorInst *> Shuffles
argument_list|,
argument|ArrayRef<unsigned> Indices
argument_list|,
argument|unsigned Factor
argument_list|)
specifier|const
name|override
block|;
name|bool
name|lowerInterleavedStore
argument_list|(
argument|StoreInst *SI
argument_list|,
argument|ShuffleVectorInst *SVI
argument_list|,
argument|unsigned Factor
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isLegalAddImmediate
argument_list|(
argument|int64_t
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isLegalICmpImmediate
argument_list|(
argument|int64_t
argument_list|)
specifier|const
name|override
block|;
name|EVT
name|getOptimalMemOpType
argument_list|(
argument|uint64_t Size
argument_list|,
argument|unsigned DstAlign
argument_list|,
argument|unsigned SrcAlign
argument_list|,
argument|bool IsMemset
argument_list|,
argument|bool ZeroMemset
argument_list|,
argument|bool MemcpyStrSrc
argument_list|,
argument|MachineFunction&MF
argument_list|)
specifier|const
name|override
block|;
comment|/// Return true if the addressing mode represented by AM is legal for this
comment|/// target, for a load/store of the specified type.
name|bool
name|isLegalAddressingMode
argument_list|(
argument|const DataLayout&DL
argument_list|,
argument|const AddrMode&AM
argument_list|,
argument|Type *Ty
argument_list|,
argument|unsigned AS
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Return the cost of the scaling factor used in the addressing
comment|/// mode represented by AM for this target, for a load/store
comment|/// of the specified type.
comment|/// If the AM is supported, the return value must be>= 0.
comment|/// If the AM is not supported, it returns a negative value.
name|int
name|getScalingFactorCost
argument_list|(
argument|const DataLayout&DL
argument_list|,
argument|const AddrMode&AM
argument_list|,
argument|Type *Ty
argument_list|,
argument|unsigned AS
argument_list|)
specifier|const
name|override
block|;
comment|/// Return true if an FMA operation is faster than a pair of fmul and fadd
comment|/// instructions. fmuladd intrinsics will be expanded to FMAs when this method
comment|/// returns true, otherwise fmuladd is expanded to fmul + fadd.
name|bool
name|isFMAFasterThanFMulAndFAdd
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|MCPhysReg
operator|*
name|getScratchRegisters
argument_list|(
argument|CallingConv::ID CC
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Returns false if N is a bit extraction pattern of (X>> C)& Mask.
name|bool
name|isDesirableToCommuteWithShift
argument_list|(
argument|const SDNode *N
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Returns true if it is beneficial to convert a load of a constant
comment|/// to just the constant itself.
name|bool
name|shouldConvertConstantLoadToIntImm
argument_list|(
argument|const APInt&Imm
argument_list|,
argument|Type *Ty
argument_list|)
specifier|const
name|override
block|;
name|Value
operator|*
name|emitLoadLinked
argument_list|(
argument|IRBuilder<>&Builder
argument_list|,
argument|Value *Addr
argument_list|,
argument|AtomicOrdering Ord
argument_list|)
specifier|const
name|override
block|;
name|Value
operator|*
name|emitStoreConditional
argument_list|(
argument|IRBuilder<>&Builder
argument_list|,
argument|Value *Val
argument_list|,
argument|Value *Addr
argument_list|,
argument|AtomicOrdering Ord
argument_list|)
specifier|const
name|override
block|;
name|void
name|emitAtomicCmpXchgNoStoreLLBalance
argument_list|(
argument|IRBuilder<>&Builder
argument_list|)
specifier|const
name|override
block|;
name|TargetLoweringBase
operator|::
name|AtomicExpansionKind
name|shouldExpandAtomicLoadInIR
argument_list|(
argument|LoadInst *LI
argument_list|)
specifier|const
name|override
block|;
name|bool
name|shouldExpandAtomicStoreInIR
argument_list|(
argument|StoreInst *SI
argument_list|)
specifier|const
name|override
block|;
name|TargetLoweringBase
operator|::
name|AtomicExpansionKind
name|shouldExpandAtomicRMWInIR
argument_list|(
argument|AtomicRMWInst *AI
argument_list|)
specifier|const
name|override
block|;
name|bool
name|shouldExpandAtomicCmpXchgInIR
argument_list|(
argument|AtomicCmpXchgInst *AI
argument_list|)
specifier|const
name|override
block|;
name|bool
name|useLoadStackGuardNode
argument_list|()
specifier|const
name|override
block|;
name|TargetLoweringBase
operator|::
name|LegalizeTypeAction
name|getPreferredVectorAction
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
comment|/// If the target has a standard location for the stack protector cookie,
comment|/// returns the address of that location. Otherwise, returns nullptr.
name|Value
operator|*
name|getIRStackGuard
argument_list|(
argument|IRBuilder<>&IRB
argument_list|)
specifier|const
name|override
block|;
comment|/// If the target has a standard location for the unsafe stack pointer,
comment|/// returns the address of that location. Otherwise, returns nullptr.
name|Value
operator|*
name|getSafeStackPointerLocation
argument_list|(
argument|IRBuilder<>&IRB
argument_list|)
specifier|const
name|override
block|;
comment|/// If a physical register, this returns the register that receives the
comment|/// exception address on entry to an EH pad.
name|unsigned
name|getExceptionPointerRegister
argument_list|(
argument|const Constant *PersonalityFn
argument_list|)
specifier|const
name|override
block|{
comment|// FIXME: This is a guess. Has this been defined yet?
return|return
name|AArch64
operator|::
name|X0
return|;
block|}
comment|/// If a physical register, this returns the register that receives the
comment|/// exception typeid on entry to a landing pad.
name|unsigned
name|getExceptionSelectorRegister
argument_list|(
argument|const Constant *PersonalityFn
argument_list|)
specifier|const
name|override
block|{
comment|// FIXME: This is a guess. Has this been defined yet?
return|return
name|AArch64
operator|::
name|X1
return|;
block|}
name|bool
name|isIntDivCheap
argument_list|(
argument|EVT VT
argument_list|,
argument|AttributeList Attr
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isCheapToSpeculateCttz
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|bool
name|isCheapToSpeculateCtlz
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|bool
name|isMaskAndCmp0FoldingBeneficial
argument_list|(
argument|const Instruction&AndI
argument_list|)
specifier|const
name|override
block|;
name|bool
name|hasAndNotCompare
argument_list|(
argument|SDValue
argument_list|)
specifier|const
name|override
block|{
comment|// 'bics'
return|return
name|true
return|;
block|}
name|bool
name|hasBitPreservingFPLogic
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
name|override
block|{
comment|// FIXME: Is this always true? It should be true for vectors at least.
return|return
name|VT
operator|==
name|MVT
operator|::
name|f32
operator|||
name|VT
operator|==
name|MVT
operator|::
name|f64
return|;
block|}
name|bool
name|supportSplitCSR
argument_list|(
argument|MachineFunction *MF
argument_list|)
specifier|const
name|override
block|{
return|return
name|MF
operator|->
name|getFunction
argument_list|()
operator|->
name|getCallingConv
argument_list|()
operator|==
name|CallingConv
operator|::
name|CXX_FAST_TLS
operator|&&
name|MF
operator|->
name|getFunction
argument_list|()
operator|->
name|hasFnAttribute
argument_list|(
name|Attribute
operator|::
name|NoUnwind
argument_list|)
return|;
block|}
name|void
name|initializeSplitCSR
argument_list|(
argument|MachineBasicBlock *Entry
argument_list|)
specifier|const
name|override
block|;
name|void
name|insertCopiesSplitCSR
argument_list|(
argument|MachineBasicBlock *Entry
argument_list|,
argument|const SmallVectorImpl<MachineBasicBlock *>&Exits
argument_list|)
specifier|const
name|override
block|;
name|bool
name|supportSwiftError
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
comment|/// Returns the size of the platform's va_list object.
name|unsigned
name|getVaListSizeInBits
argument_list|(
argument|const DataLayout&DL
argument_list|)
specifier|const
name|override
block|;
comment|/// Returns true if \p VecTy is a legal interleaved access type. This
comment|/// function checks the vector element type and the overall width of the
comment|/// vector.
name|bool
name|isLegalInterleavedAccessType
argument_list|(
argument|VectorType *VecTy
argument_list|,
argument|const DataLayout&DL
argument_list|)
specifier|const
block|;
comment|/// Returns the number of interleaved accesses that will be generated when
comment|/// lowering accesses of the given type.
name|unsigned
name|getNumInterleavedAccesses
argument_list|(
argument|VectorType *VecTy
argument_list|,
argument|const DataLayout&DL
argument_list|)
specifier|const
block|;
name|private
operator|:
name|bool
name|isExtFreeImpl
argument_list|(
argument|const Instruction *Ext
argument_list|)
specifier|const
name|override
block|;
comment|/// Keep a pointer to the AArch64Subtarget around so that we can
comment|/// make the right decision when generating code for different targets.
specifier|const
name|AArch64Subtarget
operator|*
name|Subtarget
block|;
name|void
name|addTypeForNEON
argument_list|(
argument|MVT VT
argument_list|,
argument|MVT PromotedBitwiseVT
argument_list|)
block|;
name|void
name|addDRTypeForNEON
argument_list|(
argument|MVT VT
argument_list|)
block|;
name|void
name|addQRTypeForNEON
argument_list|(
argument|MVT VT
argument_list|)
block|;
name|SDValue
name|LowerFormalArguments
argument_list|(
argument|SDValue Chain
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|bool isVarArg
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|const SDLoc&DL
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
name|override
block|;
name|SDValue
name|LowerCall
argument_list|(
argument|CallLoweringInfo&
comment|/*CLI*/
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
name|override
block|;
name|SDValue
name|LowerCallResult
argument_list|(
argument|SDValue Chain
argument_list|,
argument|SDValue InFlag
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|bool isVarArg
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|const SDLoc&DL
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|,
argument|bool isThisReturn
argument_list|,
argument|SDValue ThisVal
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerINTRINSIC_WO_CHAIN
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|bool
name|isEligibleForTailCallOptimization
argument_list|(
argument|SDValue Callee
argument_list|,
argument|CallingConv::ID CalleeCC
argument_list|,
argument|bool isVarArg
argument_list|,
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|const SmallVectorImpl<SDValue>&OutVals
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|/// Finds the incoming stack arguments which overlap the given fixed stack
comment|/// object and incorporates their load into the current chain. This prevents
comment|/// an upcoming store from clobbering the stack argument before it's used.
name|SDValue
name|addTokenForArgument
argument_list|(
argument|SDValue Chain
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|MachineFrameInfo&MFI
argument_list|,
argument|int ClobberedFI
argument_list|)
specifier|const
block|;
name|bool
name|DoesCalleeRestoreStack
argument_list|(
argument|CallingConv::ID CallCC
argument_list|,
argument|bool TailCallOpt
argument_list|)
specifier|const
block|;
name|void
name|saveVarArgRegisters
argument_list|(
argument|CCState&CCInfo
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|const SDLoc&DL
argument_list|,
argument|SDValue&Chain
argument_list|)
specifier|const
block|;
name|bool
name|CanLowerReturn
argument_list|(
argument|CallingConv::ID CallConv
argument_list|,
argument|MachineFunction&MF
argument_list|,
argument|bool isVarArg
argument_list|,
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|LLVMContext&Context
argument_list|)
specifier|const
name|override
block|;
name|SDValue
name|LowerReturn
argument_list|(
argument|SDValue Chain
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|bool isVarArg
argument_list|,
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|const SmallVectorImpl<SDValue>&OutVals
argument_list|,
argument|const SDLoc&DL
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
name|override
block|;
name|SDValue
name|LowerGlobalAddress
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerGlobalTLSAddress
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerDarwinGlobalTLSAddress
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerELFGlobalTLSAddress
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerELFTLSDescCallSeq
argument_list|(
argument|SDValue SymAddr
argument_list|,
argument|const SDLoc&DL
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSETCC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerBR_CC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSELECT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSELECT_CC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSELECT_CC
argument_list|(
argument|ISD::CondCode CC
argument_list|,
argument|SDValue LHS
argument_list|,
argument|SDValue RHS
argument_list|,
argument|SDValue TVal
argument_list|,
argument|SDValue FVal
argument_list|,
argument|const SDLoc&dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerJumpTable
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerConstantPool
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerBlockAddress
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerAAPCS_VASTART
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerDarwin_VASTART
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerVASTART
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerVACOPY
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerVAARG
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFRAMEADDR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerRETURNADDR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerINSERT_VECTOR_ELT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerEXTRACT_VECTOR_ELT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSCALAR_TO_VECTOR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerBUILD_VECTOR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerVECTOR_SHUFFLE
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerEXTRACT_SUBVECTOR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerVectorSRA_SRL_SHL
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerShiftLeftParts
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerShiftRightParts
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerVSETCC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerCTPOP
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerF128Call
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|RTLIB::Libcall Call
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFCOPYSIGN
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFP_EXTEND
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFP_ROUND
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFP_TO_INT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerINT_TO_FP
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerVectorAND
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerVectorOR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerCONCAT_VECTORS
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFSINCOS
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|BuildSDIVPow2
argument_list|(
argument|SDNode *N
argument_list|,
argument|const APInt&Divisor
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|std::vector<SDNode *> *Created
argument_list|)
specifier|const
name|override
block|;
name|SDValue
name|getSqrtEstimate
argument_list|(
argument|SDValue Operand
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|int Enabled
argument_list|,
argument|int&ExtraSteps
argument_list|,
argument|bool&UseOneConst
argument_list|,
argument|bool Reciprocal
argument_list|)
specifier|const
name|override
block|;
name|SDValue
name|getRecipEstimate
argument_list|(
argument|SDValue Operand
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|int Enabled
argument_list|,
argument|int&ExtraSteps
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|combineRepeatedFPDivisors
argument_list|()
specifier|const
name|override
block|;
name|ConstraintType
name|getConstraintType
argument_list|(
argument|StringRef Constraint
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getRegisterByName
argument_list|(
argument|const char* RegName
argument_list|,
argument|EVT VT
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
name|override
block|;
comment|/// Examine constraint string and operand type and determine a weight value.
comment|/// The operand object must already have been set up with the operand type.
name|ConstraintWeight
name|getSingleConstraintMatchWeight
argument_list|(
argument|AsmOperandInfo&info
argument_list|,
argument|const char *constraint
argument_list|)
specifier|const
name|override
block|;
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
specifier|const
name|TargetRegisterClass
operator|*
operator|>
name|getRegForInlineAsmConstraint
argument_list|(
argument|const TargetRegisterInfo *TRI
argument_list|,
argument|StringRef Constraint
argument_list|,
argument|MVT VT
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|char
operator|*
name|LowerXConstraint
argument_list|(
argument|EVT ConstraintVT
argument_list|)
specifier|const
name|override
block|;
name|void
name|LowerAsmOperandForConstraint
argument_list|(
argument|SDValue Op
argument_list|,
argument|std::string&Constraint
argument_list|,
argument|std::vector<SDValue>&Ops
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getInlineAsmMemConstraint
argument_list|(
argument|StringRef ConstraintCode
argument_list|)
specifier|const
name|override
block|{
if|if
condition|(
name|ConstraintCode
operator|==
literal|"Q"
condition|)
return|return
name|InlineAsm
operator|::
name|Constraint_Q
return|;
comment|// FIXME: clang has code for 'Ump', 'Utf', 'Usa', and 'Ush' but these are
comment|//        followed by llvm_unreachable so we'll leave them unimplemented in
comment|//        the backend for now.
return|return
name|TargetLowering
operator|::
name|getInlineAsmMemConstraint
argument_list|(
name|ConstraintCode
argument_list|)
return|;
block|}
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
name|bool
name|mayBeEmittedAsTailCall
argument_list|(
specifier|const
name|CallInst
operator|*
name|CI
argument_list|)
decl|const
name|override
decl_stmt|;
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
name|bool
name|functionArgumentNeedsConsecutiveRegisters
argument_list|(
name|Type
operator|*
name|Ty
argument_list|,
name|CallingConv
operator|::
name|ID
name|CallConv
argument_list|,
name|bool
name|isVarArg
argument_list|)
decl|const
name|override
decl_stmt|;
name|bool
name|shouldNormalizeToSelectSequence
argument_list|(
name|LLVMContext
operator|&
argument_list|,
name|EVT
argument_list|)
decl|const
name|override
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
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

end_unit

