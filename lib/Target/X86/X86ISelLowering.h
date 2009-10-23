begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- X86ISelLowering.h - X86 DAG Lowering Interface ----------*- C++ -*-===//
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
comment|// This file defines the interfaces that X86 uses to lower LLVM code into a
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
name|X86ISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|X86ISELLOWERING_H
end_define

begin_include
include|#
directive|include
file|"X86Subtarget.h"
end_include

begin_include
include|#
directive|include
file|"X86RegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"X86MachineFunctionInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetLowering.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/FastISel.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/CallingConvLower.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|X86ISD
block|{
comment|// X86 Specific DAG Nodes
enum|enum
name|NodeType
block|{
comment|// Start the numbering where the builtin ops leave off.
name|FIRST_NUMBER
init|=
name|ISD
operator|::
name|BUILTIN_OP_END
block|,
comment|/// BSF - Bit scan forward.
comment|/// BSR - Bit scan reverse.
name|BSF
block|,
name|BSR
block|,
comment|/// SHLD, SHRD - Double shift instructions. These correspond to
comment|/// X86::SHLDxx and X86::SHRDxx instructions.
name|SHLD
block|,
name|SHRD
block|,
comment|/// FAND - Bitwise logical AND of floating point values. This corresponds
comment|/// to X86::ANDPS or X86::ANDPD.
name|FAND
block|,
comment|/// FOR - Bitwise logical OR of floating point values. This corresponds
comment|/// to X86::ORPS or X86::ORPD.
name|FOR
block|,
comment|/// FXOR - Bitwise logical XOR of floating point values. This corresponds
comment|/// to X86::XORPS or X86::XORPD.
name|FXOR
block|,
comment|/// FSRL - Bitwise logical right shift of floating point values. These
comment|/// corresponds to X86::PSRLDQ.
name|FSRL
block|,
comment|/// FILD, FILD_FLAG - This instruction implements SINT_TO_FP with the
comment|/// integer source in memory and FP reg result.  This corresponds to the
comment|/// X86::FILD*m instructions. It has three inputs (token chain, address,
comment|/// and source type) and two outputs (FP value and token chain). FILD_FLAG
comment|/// also produces a flag).
name|FILD
block|,
name|FILD_FLAG
block|,
comment|/// FP_TO_INT*_IN_MEM - This instruction implements FP_TO_SINT with the
comment|/// integer destination in memory and a FP reg source.  This corresponds
comment|/// to the X86::FIST*m instructions and the rounding mode change stuff. It
comment|/// has two inputs (token chain and address) and two outputs (int value
comment|/// and token chain).
name|FP_TO_INT16_IN_MEM
block|,
name|FP_TO_INT32_IN_MEM
block|,
name|FP_TO_INT64_IN_MEM
block|,
comment|/// FLD - This instruction implements an extending load to FP stack slots.
comment|/// This corresponds to the X86::FLD32m / X86::FLD64m. It takes a chain
comment|/// operand, ptr to load from, and a ValueType node indicating the type
comment|/// to load to.
name|FLD
block|,
comment|/// FST - This instruction implements a truncating store to FP stack
comment|/// slots. This corresponds to the X86::FST32m / X86::FST64m. It takes a
comment|/// chain operand, value to store, address, and a ValueType to store it
comment|/// as.
name|FST
block|,
comment|/// CALL - These operations represent an abstract X86 call
comment|/// instruction, which includes a bunch of information.  In particular the
comment|/// operands of these node are:
comment|///
comment|///     #0 - The incoming token chain
comment|///     #1 - The callee
comment|///     #2 - The number of arg bytes the caller pushes on the stack.
comment|///     #3 - The number of arg bytes the callee pops off the stack.
comment|///     #4 - The value to pass in AL/AX/EAX (optional)
comment|///     #5 - The value to pass in DL/DX/EDX (optional)
comment|///
comment|/// The result values of these nodes are:
comment|///
comment|///     #0 - The outgoing token chain
comment|///     #1 - The first register result value (optional)
comment|///     #2 - The second register result value (optional)
comment|///
name|CALL
block|,
comment|/// RDTSC_DAG - This operation implements the lowering for
comment|/// readcyclecounter
name|RDTSC_DAG
block|,
comment|/// X86 compare and logical compare instructions.
name|CMP
block|,
name|COMI
block|,
name|UCOMI
block|,
comment|/// X86 bit-test instructions.
name|BT
block|,
comment|/// X86 SetCC. Operand 0 is condition code, and operand 1 is the flag
comment|/// operand produced by a CMP instruction.
name|SETCC
block|,
comment|/// X86 conditional moves. Operand 0 and operand 1 are the two values
comment|/// to select from. Operand 2 is the condition code, and operand 3 is the
comment|/// flag operand produced by a CMP or TEST instruction. It also writes a
comment|/// flag result.
name|CMOV
block|,
comment|/// X86 conditional branches. Operand 0 is the chain operand, operand 1
comment|/// is the block to branch if condition is true, operand 2 is the
comment|/// condition code, and operand 3 is the flag operand produced by a CMP
comment|/// or TEST instruction.
name|BRCOND
block|,
comment|/// Return with a flag operand. Operand 0 is the chain operand, operand
comment|/// 1 is the number of bytes of stack to pop.
name|RET_FLAG
block|,
comment|/// REP_STOS - Repeat fill, corresponds to X86::REP_STOSx.
name|REP_STOS
block|,
comment|/// REP_MOVS - Repeat move, corresponds to X86::REP_MOVSx.
name|REP_MOVS
block|,
comment|/// GlobalBaseReg - On Darwin, this node represents the result of the popl
comment|/// at function entry, used for PIC code.
name|GlobalBaseReg
block|,
comment|/// Wrapper - A wrapper node for TargetConstantPool,
comment|/// TargetExternalSymbol, and TargetGlobalAddress.
name|Wrapper
block|,
comment|/// WrapperRIP - Special wrapper used under X86-64 PIC mode for RIP
comment|/// relative displacements.
name|WrapperRIP
block|,
comment|/// PEXTRB - Extract an 8-bit value from a vector and zero extend it to
comment|/// i32, corresponds to X86::PEXTRB.
name|PEXTRB
block|,
comment|/// PEXTRW - Extract a 16-bit value from a vector and zero extend it to
comment|/// i32, corresponds to X86::PEXTRW.
name|PEXTRW
block|,
comment|/// INSERTPS - Insert any element of a 4 x float vector into any element
comment|/// of a destination 4 x floatvector.
name|INSERTPS
block|,
comment|/// PINSRB - Insert the lower 8-bits of a 32-bit value to a vector,
comment|/// corresponds to X86::PINSRB.
name|PINSRB
block|,
comment|/// PINSRW - Insert the lower 16-bits of a 32-bit value to a vector,
comment|/// corresponds to X86::PINSRW.
name|PINSRW
block|,
comment|/// PSHUFB - Shuffle 16 8-bit values within a vector.
name|PSHUFB
block|,
comment|/// FMAX, FMIN - Floating point max and min.
comment|///
name|FMAX
block|,
name|FMIN
block|,
comment|/// FRSQRT, FRCP - Floating point reciprocal-sqrt and reciprocal
comment|/// approximation.  Note that these typically require refinement
comment|/// in order to obtain suitable precision.
name|FRSQRT
block|,
name|FRCP
block|,
comment|// TLSADDR - Thread Local Storage.
name|TLSADDR
block|,
comment|// SegmentBaseAddress - The address segment:0
name|SegmentBaseAddress
block|,
comment|// EH_RETURN - Exception Handling helpers.
name|EH_RETURN
block|,
comment|/// TC_RETURN - Tail call return.
comment|///   operand #0 chain
comment|///   operand #1 callee (register or absolute)
comment|///   operand #2 stack adjustment
comment|///   operand #3 optional in flag
name|TC_RETURN
block|,
comment|// LCMPXCHG_DAG, LCMPXCHG8_DAG - Compare and swap.
name|LCMPXCHG_DAG
block|,
name|LCMPXCHG8_DAG
block|,
comment|// FNSTCW16m - Store FP control world into i16 memory.
name|FNSTCW16m
block|,
comment|// VZEXT_MOVL - Vector move low and zero extend.
name|VZEXT_MOVL
block|,
comment|// VZEXT_LOAD - Load, scalar_to_vector, and zero extend.
name|VZEXT_LOAD
block|,
comment|// VSHL, VSRL - Vector logical left / right shift.
name|VSHL
block|,
name|VSRL
block|,
comment|// CMPPD, CMPPS - Vector double/float comparison.
comment|// CMPPD, CMPPS - Vector double/float comparison.
name|CMPPD
block|,
name|CMPPS
block|,
comment|// PCMP* - Vector integer comparisons.
name|PCMPEQB
block|,
name|PCMPEQW
block|,
name|PCMPEQD
block|,
name|PCMPEQQ
block|,
name|PCMPGTB
block|,
name|PCMPGTW
block|,
name|PCMPGTD
block|,
name|PCMPGTQ
block|,
comment|// ADD, SUB, SMUL, UMUL, etc. - Arithmetic operations with FLAGS results.
name|ADD
block|,
name|SUB
block|,
name|SMUL
block|,
name|UMUL
block|,
name|INC
block|,
name|DEC
block|,
name|OR
block|,
name|XOR
block|,
name|AND
block|,
comment|// MUL_IMM - X86 specific multiply by immediate.
name|MUL_IMM
block|,
comment|// PTEST - Vector bitwise comparisons
name|PTEST
block|,
comment|// VASTART_SAVE_XMM_REGS - Save xmm argument registers to the stack,
comment|// according to %al. An operator is needed so that this can be expanded
comment|// with control flow.
name|VASTART_SAVE_XMM_REGS
block|,
comment|// ATOMADD64_DAG, ATOMSUB64_DAG, ATOMOR64_DAG, ATOMAND64_DAG,
comment|// ATOMXOR64_DAG, ATOMNAND64_DAG, ATOMSWAP64_DAG -
comment|// Atomic 64-bit binary operations.
name|ATOMADD64_DAG
init|=
name|ISD
operator|::
name|FIRST_TARGET_MEMORY_OPCODE
block|,
name|ATOMSUB64_DAG
block|,
name|ATOMOR64_DAG
block|,
name|ATOMXOR64_DAG
block|,
name|ATOMAND64_DAG
block|,
name|ATOMNAND64_DAG
block|,
name|ATOMSWAP64_DAG
block|}
enum|;
block|}
comment|/// Define some predicates that are used for node matching.
name|namespace
name|X86
block|{
comment|/// isPSHUFDMask - Return true if the specified VECTOR_SHUFFLE operand
comment|/// specifies a shuffle of elements that is suitable for input to PSHUFD.
name|bool
name|isPSHUFDMask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// isPSHUFHWMask - Return true if the specified VECTOR_SHUFFLE operand
comment|/// specifies a shuffle of elements that is suitable for input to PSHUFD.
name|bool
name|isPSHUFHWMask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// isPSHUFLWMask - Return true if the specified VECTOR_SHUFFLE operand
comment|/// specifies a shuffle of elements that is suitable for input to PSHUFD.
name|bool
name|isPSHUFLWMask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// isSHUFPMask - Return true if the specified VECTOR_SHUFFLE operand
comment|/// specifies a shuffle of elements that is suitable for input to SHUFP*.
name|bool
name|isSHUFPMask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// isMOVHLPSMask - Return true if the specified VECTOR_SHUFFLE operand
comment|/// specifies a shuffle of elements that is suitable for input to MOVHLPS.
name|bool
name|isMOVHLPSMask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// isMOVHLPS_v_undef_Mask - Special case of isMOVHLPSMask for canonical form
comment|/// of vector_shuffle v, v,<2, 3, 2, 3>, i.e. vector_shuffle v, undef,
comment|///<2, 3, 2, 3>
name|bool
name|isMOVHLPS_v_undef_Mask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// isMOVLPMask - Return true if the specified VECTOR_SHUFFLE operand
comment|/// specifies a shuffle of elements that is suitable for MOVLP{S|D}.
name|bool
name|isMOVLPMask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// isMOVHPMask - Return true if the specified VECTOR_SHUFFLE operand
comment|/// specifies a shuffle of elements that is suitable for MOVHP{S|D}.
comment|/// as well as MOVLHPS.
name|bool
name|isMOVHPMask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// isUNPCKLMask - Return true if the specified VECTOR_SHUFFLE operand
comment|/// specifies a shuffle of elements that is suitable for input to UNPCKL.
name|bool
name|isUNPCKLMask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|,
name|bool
name|V2IsSplat
init|=
name|false
parameter_list|)
function_decl|;
comment|/// isUNPCKHMask - Return true if the specified VECTOR_SHUFFLE operand
comment|/// specifies a shuffle of elements that is suitable for input to UNPCKH.
name|bool
name|isUNPCKHMask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|,
name|bool
name|V2IsSplat
init|=
name|false
parameter_list|)
function_decl|;
comment|/// isUNPCKL_v_undef_Mask - Special case of isUNPCKLMask for canonical form
comment|/// of vector_shuffle v, v,<0, 4, 1, 5>, i.e. vector_shuffle v, undef,
comment|///<0, 0, 1, 1>
name|bool
name|isUNPCKL_v_undef_Mask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// isUNPCKH_v_undef_Mask - Special case of isUNPCKHMask for canonical form
comment|/// of vector_shuffle v, v,<2, 6, 3, 7>, i.e. vector_shuffle v, undef,
comment|///<2, 2, 3, 3>
name|bool
name|isUNPCKH_v_undef_Mask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// isMOVLMask - Return true if the specified VECTOR_SHUFFLE operand
comment|/// specifies a shuffle of elements that is suitable for input to MOVSS,
comment|/// MOVSD, and MOVD, i.e. setting the lowest element.
name|bool
name|isMOVLMask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// isMOVSHDUPMask - Return true if the specified VECTOR_SHUFFLE operand
comment|/// specifies a shuffle of elements that is suitable for input to MOVSHDUP.
name|bool
name|isMOVSHDUPMask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// isMOVSLDUPMask - Return true if the specified VECTOR_SHUFFLE operand
comment|/// specifies a shuffle of elements that is suitable for input to MOVSLDUP.
name|bool
name|isMOVSLDUPMask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// isMOVDDUPMask - Return true if the specified VECTOR_SHUFFLE operand
comment|/// specifies a shuffle of elements that is suitable for input to MOVDDUP.
name|bool
name|isMOVDDUPMask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// isPALIGNRMask - Return true if the specified VECTOR_SHUFFLE operand
comment|/// specifies a shuffle of elements that is suitable for input to PALIGNR.
name|bool
name|isPALIGNRMask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// getShuffleSHUFImmediate - Return the appropriate immediate to shuffle
comment|/// the specified isShuffleMask VECTOR_SHUFFLE mask with PSHUF* and SHUFP*
comment|/// instructions.
name|unsigned
name|getShuffleSHUFImmediate
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// getShufflePSHUFHWImmediate - Return the appropriate immediate to shuffle
comment|/// the specified VECTOR_SHUFFLE mask with PSHUFHW instruction.
name|unsigned
name|getShufflePSHUFHWImmediate
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// getShufflePSHUFLWImmediate - Return the appropriate immediate to shuffle
comment|/// the specified VECTOR_SHUFFLE mask with PSHUFLW instruction.
name|unsigned
name|getShufflePSHUFLWImmediate
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// getShufflePALIGNRImmediate - Return the appropriate immediate to shuffle
comment|/// the specified VECTOR_SHUFFLE mask with the PALIGNR instruction.
name|unsigned
name|getShufflePALIGNRImmediate
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// isZeroNode - Returns true if Elt is a constant zero or a floating point
comment|/// constant +0.0.
name|bool
name|isZeroNode
parameter_list|(
name|SDValue
name|Elt
parameter_list|)
function_decl|;
comment|/// isOffsetSuitableForCodeModel - Returns true of the given offset can be
comment|/// fit into displacement field of the instruction.
name|bool
name|isOffsetSuitableForCodeModel
argument_list|(
name|int64_t
name|Offset
argument_list|,
name|CodeModel
operator|::
name|Model
name|M
argument_list|,
name|bool
name|hasSymbolicDisplacement
operator|=
name|true
argument_list|)
decl_stmt|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|//  X86TargetLowering - X86 Implementation of the TargetLowering interface
name|class
name|X86TargetLowering
range|:
name|public
name|TargetLowering
block|{
name|int
name|VarArgsFrameIndex
block|;
comment|// FrameIndex for start of varargs area.
name|int
name|RegSaveFrameIndex
block|;
comment|// X86-64 vararg func register save area.
name|unsigned
name|VarArgsGPOffset
block|;
comment|// X86-64 vararg func int reg offset.
name|unsigned
name|VarArgsFPOffset
block|;
comment|// X86-64 vararg func fp reg offset.
name|int
name|BytesToPopOnReturn
block|;
comment|// Number of arg bytes ret should pop.
name|int
name|BytesCallerReserves
block|;
comment|// Number of arg bytes caller makes.
name|public
operator|:
name|explicit
name|X86TargetLowering
argument_list|(
name|X86TargetMachine
operator|&
name|TM
argument_list|)
block|;
comment|/// getPICJumpTableRelocaBase - Returns relocation base for the given PIC
comment|/// jumptable.
name|SDValue
name|getPICJumpTableRelocBase
argument_list|(
argument|SDValue Table
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|// Return the number of bytes that a function should pop when it returns (in
comment|// addition to the space used by the return address).
comment|//
name|unsigned
name|getBytesToPopOnReturn
argument_list|()
specifier|const
block|{
return|return
name|BytesToPopOnReturn
return|;
block|}
comment|// Return the number of bytes that the caller reserves for arguments passed
comment|// to this function.
name|unsigned
name|getBytesCallerReserves
argument_list|()
specifier|const
block|{
return|return
name|BytesCallerReserves
return|;
block|}
comment|/// getStackPtrReg - Return the stack pointer register we are using: either
comment|/// ESP or RSP.
name|unsigned
name|getStackPtrReg
argument_list|()
specifier|const
block|{
return|return
name|X86StackPtr
return|;
block|}
comment|/// getByValTypeAlignment - Return the desired alignment for ByVal aggregate
comment|/// function arguments in the caller parameter area. For X86, aggregates
comment|/// that contains are placed at 16-byte boundaries while the rest are at
comment|/// 4-byte boundaries.
name|virtual
name|unsigned
name|getByValTypeAlignment
argument_list|(
argument|const Type *Ty
argument_list|)
specifier|const
block|;
comment|/// getOptimalMemOpType - Returns the target specific optimal type for load
comment|/// and store operations as a result of memset, memcpy, and memmove
comment|/// lowering. It returns EVT::iAny if SelectionDAG should be responsible for
comment|/// determining it.
name|virtual
name|EVT
name|getOptimalMemOpType
argument_list|(
argument|uint64_t Size
argument_list|,
argument|unsigned Align
argument_list|,
argument|bool isSrcConst
argument_list|,
argument|bool isSrcStr
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|/// allowsUnalignedMemoryAccesses - Returns true if the target allows
comment|/// unaligned memory accesses. of the specified type.
name|virtual
name|bool
name|allowsUnalignedMemoryAccesses
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// LowerOperation - Provide custom lowering hooks for some operations.
comment|///
name|virtual
name|SDValue
name|LowerOperation
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
comment|/// ReplaceNodeResults - Replace the results of node with an illegal result
comment|/// type with new values built out of custom code.
comment|///
name|virtual
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
block|;
name|virtual
name|SDValue
name|PerformDAGCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|virtual
name|MachineBasicBlock
operator|*
name|EmitInstrWithCustomInserter
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *MBB
argument_list|,
argument|DenseMap<MachineBasicBlock*
argument_list|,
argument|MachineBasicBlock*> *EM
argument_list|)
specifier|const
block|;
comment|/// getTargetNodeName - This method returns the name of a target specific
comment|/// DAG node.
name|virtual
specifier|const
name|char
operator|*
name|getTargetNodeName
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
comment|/// getSetCCResultType - Return the ISD::SETCC ValueType
name|virtual
name|MVT
operator|::
name|SimpleValueType
name|getSetCCResultType
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
block|;
comment|/// computeMaskedBitsForTargetNode - Determine which of the bits specified
comment|/// in Mask are known to be either zero or one and return them in the
comment|/// KnownZero/KnownOne bitsets.
name|virtual
name|void
name|computeMaskedBitsForTargetNode
argument_list|(
argument|const SDValue Op
argument_list|,
argument|const APInt&Mask
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
block|;
name|virtual
name|bool
name|isGAPlusOffset
argument_list|(
argument|SDNode *N
argument_list|,
argument|GlobalValue*&GA
argument_list|,
argument|int64_t&Offset
argument_list|)
specifier|const
block|;
name|SDValue
name|getReturnAddressFrameIndex
argument_list|(
name|SelectionDAG
operator|&
name|DAG
argument_list|)
block|;
name|virtual
name|bool
name|ExpandInlineAsm
argument_list|(
argument|CallInst *CI
argument_list|)
specifier|const
block|;
name|ConstraintType
name|getConstraintType
argument_list|(
argument|const std::string&Constraint
argument_list|)
specifier|const
block|;
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|getRegClassForInlineAsmConstraint
argument_list|(
argument|const std::string&Constraint
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|char
operator|*
name|LowerXConstraint
argument_list|(
argument|EVT ConstraintVT
argument_list|)
specifier|const
block|;
comment|/// LowerAsmOperandForConstraint - Lower the specified operand into the Ops
comment|/// vector.  If it is invalid, don't add anything to Ops. If hasMemory is
comment|/// true it means one of the asm constraint of the inline asm instruction
comment|/// being processed is 'm'.
name|virtual
name|void
name|LowerAsmOperandForConstraint
argument_list|(
argument|SDValue Op
argument_list|,
argument|char ConstraintLetter
argument_list|,
argument|bool hasMemory
argument_list|,
argument|std::vector<SDValue>&Ops
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|/// getRegForInlineAsmConstraint - Given a physical register constraint
comment|/// (e.g. {edx}), return the register number and the register class for the
comment|/// register.  This should only be used for C_Register constraints.  On
comment|/// error, this returns a register number of 0.
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
argument|const std::string&Constraint
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
block|;
comment|/// isLegalAddressingMode - Return true if the addressing mode represented
comment|/// by AM is legal for this target, for a load/store of the specified type.
name|virtual
name|bool
name|isLegalAddressingMode
argument_list|(
argument|const AddrMode&AM
argument_list|,
argument|const Type *Ty
argument_list|)
specifier|const
block|;
comment|/// isTruncateFree - Return true if it's free to truncate a value of
comment|/// type Ty1 to type Ty2. e.g. On x86 it's free to truncate a i32 value in
comment|/// register EAX to i16 by referencing its sub-register AX.
name|virtual
name|bool
name|isTruncateFree
argument_list|(
argument|const Type *Ty1
argument_list|,
argument|const Type *Ty2
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isTruncateFree
argument_list|(
argument|EVT VT1
argument_list|,
argument|EVT VT2
argument_list|)
specifier|const
block|;
comment|/// isZExtFree - Return true if any actual instruction that defines a
comment|/// value of type Ty1 implicit zero-extends the value to Ty2 in the result
comment|/// register. This does not necessarily include registers defined in
comment|/// unknown ways, such as incoming arguments, or copies from unknown
comment|/// virtual registers. Also, if isTruncateFree(Ty2, Ty1) is true, this
comment|/// does not necessarily apply to truncate instructions. e.g. on x86-64,
comment|/// all instructions that define 32-bit values implicit zero-extend the
comment|/// result out to 64 bits.
name|virtual
name|bool
name|isZExtFree
argument_list|(
argument|const Type *Ty1
argument_list|,
argument|const Type *Ty2
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isZExtFree
argument_list|(
argument|EVT VT1
argument_list|,
argument|EVT VT2
argument_list|)
specifier|const
block|;
comment|/// isNarrowingProfitable - Return true if it's profitable to narrow
comment|/// operations of type VT1 to VT2. e.g. on x86, it's profitable to narrow
comment|/// from i32 to i8 but not from i32 to i16.
name|virtual
name|bool
name|isNarrowingProfitable
argument_list|(
argument|EVT VT1
argument_list|,
argument|EVT VT2
argument_list|)
specifier|const
block|;
comment|/// isShuffleMaskLegal - Targets can use this to indicate that they only
comment|/// support *some* VECTOR_SHUFFLE operations, those with specific masks.
comment|/// By default, if a target supports the VECTOR_SHUFFLE node, all mask
comment|/// values are assumed to be legal.
name|virtual
name|bool
name|isShuffleMaskLegal
argument_list|(
argument|const SmallVectorImpl<int>&Mask
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
block|;
comment|/// isVectorClearMaskLegal - Similar to isShuffleMaskLegal. This is
comment|/// used by Targets can use this to indicate if there is a suitable
comment|/// VECTOR_SHUFFLE that can be used to replace a VAND with a constant
comment|/// pool entry.
name|virtual
name|bool
name|isVectorClearMaskLegal
argument_list|(
argument|const SmallVectorImpl<int>&Mask
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
block|;
comment|/// ShouldShrinkFPConstant - If true, then instruction selection should
comment|/// seek to shrink the FP constant of the specified type to a smaller type
comment|/// in order to save space and / or reduce runtime.
name|virtual
name|bool
name|ShouldShrinkFPConstant
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
block|{
comment|// Don't shrink FP constpool if SSE2 is available since cvtss2sd is more
comment|// expensive than a straight movsd. On the other hand, it's important to
comment|// shrink long double fp constant since fldt is very slow.
return|return
operator|!
name|X86ScalarSSEf64
operator|||
name|VT
operator|==
name|MVT
operator|::
name|f80
return|;
block|}
comment|/// IsEligibleForTailCallOptimization - Check whether the call is eligible
comment|/// for tail call optimization. Targets which want to do tail call
comment|/// optimization should implement this function.
name|virtual
name|bool
name|IsEligibleForTailCallOptimization
argument_list|(
argument|SDValue Callee
argument_list|,
argument|CallingConv::ID CalleeCC
argument_list|,
argument|bool isVarArg
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|SelectionDAG& DAG
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|X86Subtarget
operator|*
name|getSubtarget
argument_list|()
block|{
return|return
name|Subtarget
return|;
block|}
comment|/// isScalarFPTypeInSSEReg - Return true if the specified scalar FP type is
comment|/// computed in an SSE register, not on the X87 floating point stack.
name|bool
name|isScalarFPTypeInSSEReg
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
block|{
return|return
operator|(
name|VT
operator|==
name|MVT
operator|::
name|f64
operator|&&
name|X86ScalarSSEf64
operator|)
operator|||
comment|// f64 is when SSE2
operator|(
name|VT
operator|==
name|MVT
operator|::
name|f32
operator|&&
name|X86ScalarSSEf32
operator|)
return|;
comment|// f32 is when SSE1
block|}
comment|/// getWidenVectorType: given a vector type, returns the type to widen
comment|/// to (e.g., v7i8 to v8i8). If the vector type is legal, it returns itself.
comment|/// If there is no vector type that we want to widen to, returns EVT::Other
comment|/// When and were to widen is target dependent based on the cost of
comment|/// scalarizing vs using the wider vector type.
name|virtual
name|EVT
name|getWidenVectorType
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
block|;
comment|/// createFastISel - This method returns a target specific FastISel object,
comment|/// or null if the target does not support "fast" ISel.
name|virtual
name|FastISel
operator|*
name|createFastISel
argument_list|(
name|MachineFunction
operator|&
name|mf
argument_list|,
name|MachineModuleInfo
operator|*
name|mmi
argument_list|,
name|DwarfWriter
operator|*
name|dw
argument_list|,
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
argument_list|,
name|unsigned
operator|>
operator|&
argument_list|,
name|DenseMap
operator|<
specifier|const
name|BasicBlock
operator|*
argument_list|,
name|MachineBasicBlock
operator|*
operator|>
operator|&
argument_list|,
name|DenseMap
operator|<
specifier|const
name|AllocaInst
operator|*
argument_list|,
name|int
operator|>
operator|&
ifndef|#
directive|ifndef
name|NDEBUG
argument_list|,
name|SmallSet
operator|<
name|Instruction
operator|*
argument_list|,
literal|8
operator|>
operator|&
endif|#
directive|endif
argument_list|)
block|;
comment|/// getFunctionAlignment - Return the Log2 alignment of this function.
name|virtual
name|unsigned
name|getFunctionAlignment
argument_list|(
argument|const Function *F
argument_list|)
specifier|const
block|;
name|private
operator|:
comment|/// Subtarget - Keep a pointer to the X86Subtarget around so that we can
comment|/// make the right decision when generating code for different targets.
specifier|const
name|X86Subtarget
operator|*
name|Subtarget
block|;
specifier|const
name|X86RegisterInfo
operator|*
name|RegInfo
block|;
specifier|const
name|TargetData
operator|*
name|TD
block|;
comment|/// X86StackPtr - X86 physical register used as stack ptr.
name|unsigned
name|X86StackPtr
block|;
comment|/// X86ScalarSSEf32, X86ScalarSSEf64 - Select between SSE or x87
comment|/// floating point ops.
comment|/// When SSE is available, use it for f32 operations.
comment|/// When SSE2 is available, use it for f64 operations.
name|bool
name|X86ScalarSSEf32
block|;
name|bool
name|X86ScalarSSEf64
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
argument|DebugLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
block|;
name|SDValue
name|LowerMemArgument
argument_list|(
argument|SDValue Chain
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&ArgInfo
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|const CCValAssign&VA
argument_list|,
argument|MachineFrameInfo *MFI
argument_list|,
argument|unsigned i
argument_list|)
block|;
name|SDValue
name|LowerMemOpCallTo
argument_list|(
argument|SDValue Chain
argument_list|,
argument|SDValue StackPtr
argument_list|,
argument|SDValue Arg
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|const CCValAssign&VA
argument_list|,
argument|ISD::ArgFlagsTy Flags
argument_list|)
block|;
comment|// Call lowering helpers.
name|bool
name|IsCalleePop
argument_list|(
argument|bool isVarArg
argument_list|,
argument|CallingConv::ID CallConv
argument_list|)
block|;
name|SDValue
name|EmitTailCallLoadRetAddr
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDValue&OutRetAddr
argument_list|,
argument|SDValue Chain
argument_list|,
argument|bool IsTailCall
argument_list|,
argument|bool Is64Bit
argument_list|,
argument|int FPDiff
argument_list|,
argument|DebugLoc dl
argument_list|)
block|;
name|CCAssignFn
operator|*
name|CCAssignFnForNode
argument_list|(
argument|CallingConv::ID CallConv
argument_list|)
specifier|const
block|;
name|NameDecorationStyle
name|NameDecorationForCallConv
argument_list|(
argument|CallingConv::ID CallConv
argument_list|)
block|;
name|unsigned
name|GetAlignedArgumentStackSize
argument_list|(
argument|unsigned StackSize
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|std
operator|::
name|pair
operator|<
name|SDValue
block|,
name|SDValue
operator|>
name|FP_TO_INTHelper
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|bool isSigned
argument_list|)
block|;
name|SDValue
name|LowerBUILD_VECTOR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerVECTOR_SHUFFLE
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerEXTRACT_VECTOR_ELT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerEXTRACT_VECTOR_ELT_SSE4
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerINSERT_VECTOR_ELT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerINSERT_VECTOR_ELT_SSE4
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerSCALAR_TO_VECTOR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerConstantPool
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerGlobalAddress
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|int64_t Offset
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerGlobalAddress
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerGlobalTLSAddress
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerExternalSymbol
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerShift
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|BuildFILD
argument_list|(
argument|SDValue Op
argument_list|,
argument|EVT SrcVT
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue StackSlot
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerSINT_TO_FP
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerUINT_TO_FP
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerUINT_TO_FP_i64
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerUINT_TO_FP_i32
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerFP_TO_SINT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerFP_TO_UINT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerFABS
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerFNEG
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerFCOPYSIGN
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerSETCC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerVSETCC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerSELECT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerBRCOND
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerMEMSET
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerJumpTable
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerDYNAMIC_STACKALLOC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerVASTART
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerVAARG
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerVACOPY
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerINTRINSIC_WO_CHAIN
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerRETURNADDR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerFRAMEADDR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerFRAME_TO_ARGS_OFFSET
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerEH_RETURN
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerTRAMPOLINE
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerFLT_ROUNDS_
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerCTLZ
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerCTTZ
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerMUL_V2I64
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerXALUO
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerCMP_SWAP
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerLOAD_SUB
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|SDValue
name|LowerREADCYCLECOUNTER
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|virtual
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
argument|DebugLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
block|;
name|virtual
name|SDValue
name|LowerCall
argument_list|(
argument|SDValue Chain
argument_list|,
argument|SDValue Callee
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|bool isVarArg
argument_list|,
argument|bool isTailCall
argument_list|,
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
block|;
name|virtual
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
argument|DebugLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
name|void
name|ReplaceATOMIC_BINARY_64
argument_list|(
argument|SDNode *N
argument_list|,
argument|SmallVectorImpl<SDValue>&Results
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|unsigned NewOp
argument_list|)
block|;
name|SDValue
name|EmitTargetCodeForMemset
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Dst
argument_list|,
argument|SDValue Src
argument_list|,
argument|SDValue Size
argument_list|,
argument|unsigned Align
argument_list|,
argument|const Value *DstSV
argument_list|,
argument|uint64_t DstSVOff
argument_list|)
block|;
name|SDValue
name|EmitTargetCodeForMemcpy
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Dst
argument_list|,
argument|SDValue Src
argument_list|,
argument|SDValue Size
argument_list|,
argument|unsigned Align
argument_list|,
argument|bool AlwaysInline
argument_list|,
argument|const Value *DstSV
argument_list|,
argument|uint64_t DstSVOff
argument_list|,
argument|const Value *SrcSV
argument_list|,
argument|uint64_t SrcSVOff
argument_list|)
block|;
comment|/// Utility function to emit string processing sse4.2 instructions
comment|/// that return in xmm0.
comment|/// This takes the instruction to expand, the associated machine basic
comment|/// block, the number of args, and whether or not the second arg is
comment|/// in memory or not.
name|MachineBasicBlock
operator|*
name|EmitPCMP
argument_list|(
argument|MachineInstr *BInstr
argument_list|,
argument|MachineBasicBlock *BB
argument_list|,
argument|unsigned argNum
argument_list|,
argument|bool inMem
argument_list|)
specifier|const
block|;
comment|/// Utility function to emit atomic bitwise operations (and, or, xor).
comment|/// It takes the bitwise instruction to expand, the associated machine basic
comment|/// block, and the associated X86 opcodes for reg/reg and reg/imm.
name|MachineBasicBlock
operator|*
name|EmitAtomicBitwiseWithCustomInserter
argument_list|(
argument|MachineInstr *BInstr
argument_list|,
argument|MachineBasicBlock *BB
argument_list|,
argument|unsigned regOpc
argument_list|,
argument|unsigned immOpc
argument_list|,
argument|unsigned loadOpc
argument_list|,
argument|unsigned cxchgOpc
argument_list|,
argument|unsigned copyOpc
argument_list|,
argument|unsigned notOpc
argument_list|,
argument|unsigned EAXreg
argument_list|,
argument|TargetRegisterClass *RC
argument_list|,
argument|bool invSrc = false
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|EmitAtomicBit6432WithCustomInserter
argument_list|(
argument|MachineInstr *BInstr
argument_list|,
argument|MachineBasicBlock *BB
argument_list|,
argument|unsigned regOpcL
argument_list|,
argument|unsigned regOpcH
argument_list|,
argument|unsigned immOpcL
argument_list|,
argument|unsigned immOpcH
argument_list|,
argument|bool invSrc = false
argument_list|)
specifier|const
block|;
comment|/// Utility function to emit atomic min and max.  It takes the min/max
comment|/// instruction to expand, the associated basic block, and the associated
comment|/// cmov opcode for moving the min or max value.
name|MachineBasicBlock
operator|*
name|EmitAtomicMinMaxWithCustomInserter
argument_list|(
argument|MachineInstr *BInstr
argument_list|,
argument|MachineBasicBlock *BB
argument_list|,
argument|unsigned cmovOpc
argument_list|)
specifier|const
block|;
comment|/// Utility function to emit the xmm reg save portion of va_start.
name|MachineBasicBlock
operator|*
name|EmitVAStartSaveXMMRegsWithCustomInserter
argument_list|(
argument|MachineInstr *BInstr
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|EmitLoweredSelect
argument_list|(
argument|MachineInstr *I
argument_list|,
argument|MachineBasicBlock *BB
argument_list|,
argument|DenseMap<MachineBasicBlock*
argument_list|,
argument|MachineBasicBlock*> *EM
argument_list|)
specifier|const
block|;
comment|/// Emit nodes that will be selected as "test Op0,Op0", or something
comment|/// equivalent, for use with the given x86 condition code.
name|SDValue
name|EmitTest
argument_list|(
argument|SDValue Op0
argument_list|,
argument|unsigned X86CC
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;
comment|/// Emit nodes that will be selected as "cmp Op0,Op1", or something
comment|/// equivalent, for use with the given x86 condition code.
name|SDValue
name|EmitCmp
argument_list|(
argument|SDValue Op0
argument_list|,
argument|SDValue Op1
argument_list|,
argument|unsigned X86CC
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
block|;   }
decl_stmt|;
name|namespace
name|X86
block|{
name|FastISel
modifier|*
name|createFastISel
argument_list|(
name|MachineFunction
operator|&
name|mf
argument_list|,
name|MachineModuleInfo
operator|*
name|mmi
argument_list|,
name|DwarfWriter
operator|*
name|dw
argument_list|,
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
argument_list|,
name|unsigned
operator|>
operator|&
argument_list|,
name|DenseMap
operator|<
specifier|const
name|BasicBlock
operator|*
argument_list|,
name|MachineBasicBlock
operator|*
operator|>
operator|&
argument_list|,
name|DenseMap
operator|<
specifier|const
name|AllocaInst
operator|*
argument_list|,
name|int
operator|>
operator|&
ifndef|#
directive|ifndef
name|NDEBUG
argument_list|,
name|SmallSet
operator|<
name|Instruction
operator|*
argument_list|,
literal|8
operator|>
operator|&
endif|#
directive|endif
argument_list|)
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// X86ISELLOWERING_H
end_comment

end_unit

