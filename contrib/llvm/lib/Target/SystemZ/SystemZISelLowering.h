begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SystemZISelLowering.h - SystemZ DAG lowering interface --*- C++ -*-===//
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
comment|// This file defines the interfaces that SystemZ uses to lower LLVM code into a
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
name|LLVM_TARGET_SystemZ_ISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_SystemZ_ISELLOWERING_H
end_define

begin_include
include|#
directive|include
file|"SystemZ.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAG.h"
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
name|SystemZISD
block|{
enum|enum
block|{
name|FIRST_NUMBER
init|=
name|ISD
operator|::
name|BUILTIN_OP_END
block|,
comment|// Return with a flag operand.  Operand 0 is the chain operand.
name|RET_FLAG
block|,
comment|// Calls a function.  Operand 0 is the chain operand and operand 1
comment|// is the target address.  The arguments start at operand 2.
comment|// There is an optional glue operand at the end.
name|CALL
block|,
name|SIBCALL
block|,
comment|// Wraps a TargetGlobalAddress that should be loaded using PC-relative
comment|// accesses (LARL).  Operand 0 is the address.
name|PCREL_WRAPPER
block|,
comment|// Used in cases where an offset is applied to a TargetGlobalAddress.
comment|// Operand 0 is the full TargetGlobalAddress and operand 1 is a
comment|// PCREL_WRAPPER for an anchor point.  This is used so that we can
comment|// cheaply refer to either the full address or the anchor point
comment|// as a register base.
name|PCREL_OFFSET
block|,
comment|// Integer comparisons.  There are three operands: the two values
comment|// to compare, and an integer of type SystemZICMP.
name|ICMP
block|,
comment|// Floating-point comparisons.  The two operands are the values to compare.
name|FCMP
block|,
comment|// Test under mask.  The first operand is ANDed with the second operand
comment|// and the condition codes are set on the result.  The third operand is
comment|// a boolean that is true if the condition codes need to distinguish
comment|// between CCMASK_TM_MIXED_MSB_0 and CCMASK_TM_MIXED_MSB_1 (which the
comment|// register forms do but the memory forms don't).
name|TM
block|,
comment|// Branches if a condition is true.  Operand 0 is the chain operand;
comment|// operand 1 is the 4-bit condition-code mask, with bit N in
comment|// big-endian order meaning "branch if CC=N"; operand 2 is the
comment|// target block and operand 3 is the flag operand.
name|BR_CCMASK
block|,
comment|// Selects between operand 0 and operand 1.  Operand 2 is the
comment|// mask of condition-code values for which operand 0 should be
comment|// chosen over operand 1; it has the same form as BR_CCMASK.
comment|// Operand 3 is the flag operand.
name|SELECT_CCMASK
block|,
comment|// Evaluates to the gap between the stack pointer and the
comment|// base of the dynamically-allocatable area.
name|ADJDYNALLOC
block|,
comment|// Extracts the value of a 32-bit access register.  Operand 0 is
comment|// the number of the register.
name|EXTRACT_ACCESS
block|,
comment|// Wrappers around the ISD opcodes of the same name.  The output and
comment|// first input operands are GR128s.  The trailing numbers are the
comment|// widths of the second operand in bits.
name|UMUL_LOHI64
block|,
name|SDIVREM32
block|,
name|SDIVREM64
block|,
name|UDIVREM32
block|,
name|UDIVREM64
block|,
comment|// Use a series of MVCs to copy bytes from one memory location to another.
comment|// The operands are:
comment|// - the target address
comment|// - the source address
comment|// - the constant length
comment|//
comment|// This isn't a memory opcode because we'd need to attach two
comment|// MachineMemOperands rather than one.
name|MVC
block|,
comment|// Like MVC, but implemented as a loop that handles X*256 bytes
comment|// followed by straight-line code to handle the rest (if any).
comment|// The value of X is passed as an additional operand.
name|MVC_LOOP
block|,
comment|// Similar to MVC and MVC_LOOP, but for logic operations (AND, OR, XOR).
name|NC
block|,
name|NC_LOOP
block|,
name|OC
block|,
name|OC_LOOP
block|,
name|XC
block|,
name|XC_LOOP
block|,
comment|// Use CLC to compare two blocks of memory, with the same comments
comment|// as for MVC and MVC_LOOP.
name|CLC
block|,
name|CLC_LOOP
block|,
comment|// Use an MVST-based sequence to implement stpcpy().
name|STPCPY
block|,
comment|// Use a CLST-based sequence to implement strcmp().  The two input operands
comment|// are the addresses of the strings to compare.
name|STRCMP
block|,
comment|// Use an SRST-based sequence to search a block of memory.  The first
comment|// operand is the end address, the second is the start, and the third
comment|// is the character to search for.  CC is set to 1 on success and 2
comment|// on failure.
name|SEARCH_STRING
block|,
comment|// Store the CC value in bits 29 and 28 of an integer.
name|IPM
block|,
comment|// Wrappers around the inner loop of an 8- or 16-bit ATOMIC_SWAP or
comment|// ATOMIC_LOAD_<op>.
comment|//
comment|// Operand 0: the address of the containing 32-bit-aligned field
comment|// Operand 1: the second operand of<op>, in the high bits of an i32
comment|//            for everything except ATOMIC_SWAPW
comment|// Operand 2: how many bits to rotate the i32 left to bring the first
comment|//            operand into the high bits
comment|// Operand 3: the negative of operand 2, for rotating the other way
comment|// Operand 4: the width of the field in bits (8 or 16)
name|ATOMIC_SWAPW
init|=
name|ISD
operator|::
name|FIRST_TARGET_MEMORY_OPCODE
block|,
name|ATOMIC_LOADW_ADD
block|,
name|ATOMIC_LOADW_SUB
block|,
name|ATOMIC_LOADW_AND
block|,
name|ATOMIC_LOADW_OR
block|,
name|ATOMIC_LOADW_XOR
block|,
name|ATOMIC_LOADW_NAND
block|,
name|ATOMIC_LOADW_MIN
block|,
name|ATOMIC_LOADW_MAX
block|,
name|ATOMIC_LOADW_UMIN
block|,
name|ATOMIC_LOADW_UMAX
block|,
comment|// A wrapper around the inner loop of an ATOMIC_CMP_SWAP.
comment|//
comment|// Operand 0: the address of the containing 32-bit-aligned field
comment|// Operand 1: the compare value, in the low bits of an i32
comment|// Operand 2: the swap value, in the low bits of an i32
comment|// Operand 3: how many bits to rotate the i32 left to bring the first
comment|//            operand into the high bits
comment|// Operand 4: the negative of operand 2, for rotating the other way
comment|// Operand 5: the width of the field in bits (8 or 16)
name|ATOMIC_CMP_SWAPW
block|,
comment|// Prefetch from the second operand using the 4-bit control code in
comment|// the first operand.  The code is 1 for a load prefetch and 2 for
comment|// a store prefetch.
name|PREFETCH
block|}
enum|;
comment|// Return true if OPCODE is some kind of PC-relative address.
specifier|inline
name|bool
name|isPCREL
parameter_list|(
name|unsigned
name|Opcode
parameter_list|)
block|{
return|return
name|Opcode
operator|==
name|PCREL_WRAPPER
operator|||
name|Opcode
operator|==
name|PCREL_OFFSET
return|;
block|}
block|}
name|namespace
name|SystemZICMP
block|{
comment|// Describes whether an integer comparison needs to be signed or unsigned,
comment|// or whether either type is OK.
enum|enum
block|{
name|Any
block|,
name|UnsignedOnly
block|,
name|SignedOnly
block|}
enum|;
block|}
name|class
name|SystemZSubtarget
decl_stmt|;
name|class
name|SystemZTargetMachine
decl_stmt|;
name|class
name|SystemZTargetLowering
range|:
name|public
name|TargetLowering
block|{
name|public
operator|:
name|explicit
name|SystemZTargetLowering
argument_list|(
name|SystemZTargetMachine
operator|&
name|TM
argument_list|)
block|;
comment|// Override TargetLowering.
name|virtual
name|MVT
name|getScalarShiftAmountTy
argument_list|(
argument|EVT LHSTy
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|{
return|return
name|MVT
operator|::
name|i32
return|;
block|}
name|virtual
name|EVT
name|getSetCCResultType
argument_list|(
argument|LLVMContext&
argument_list|,
argument|EVT
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|bool
name|isFMAFasterThanFMulAndFAdd
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|bool
name|isFPImmLegal
argument_list|(
argument|const APFloat&Imm
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|bool
name|isLegalAddressingMode
argument_list|(
argument|const AddrMode&AM
argument_list|,
argument|Type *Ty
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|bool
name|allowsUnalignedMemoryAccesses
argument_list|(
argument|EVT VT
argument_list|,
argument|bool *Fast
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|bool
name|isTruncateFree
argument_list|(
argument|Type *
argument_list|,
argument|Type *
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|bool
name|isTruncateFree
argument_list|(
argument|EVT
argument_list|,
argument|EVT
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
specifier|const
name|char
operator|*
name|getTargetNodeName
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
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
argument|MVT VT
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|TargetLowering
operator|::
name|ConstraintType
name|getConstraintType
argument_list|(
argument|const std::string&Constraint
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|TargetLowering
operator|::
name|ConstraintWeight
name|getSingleConstraintMatchWeight
argument_list|(
argument|AsmOperandInfo&info
argument_list|,
argument|const char *constraint
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
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
name|LLVM_OVERRIDE
block|;
name|virtual
name|MachineBasicBlock
operator|*
name|EmitInstrWithCustomInserter
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|SDValue
name|LowerOperation
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|bool
name|allowTruncateForTailCall
argument_list|(
argument|Type *
argument_list|,
argument|Type *
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|bool
name|mayBeEmittedAsTailCall
argument_list|(
argument|CallInst *CI
argument_list|)
specifier|const
name|LLVM_OVERRIDE
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
argument|SDLoc DL
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|SDValue
name|LowerCall
argument_list|(
argument|CallLoweringInfo&CLI
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|SDValue
name|LowerReturn
argument_list|(
argument|SDValue Chain
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|bool IsVarArg
argument_list|,
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|const SmallVectorImpl<SDValue>&OutVals
argument_list|,
argument|SDLoc DL
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|private
operator|:
specifier|const
name|SystemZSubtarget
operator|&
name|Subtarget
block|;
specifier|const
name|SystemZTargetMachine
operator|&
name|TM
block|;
comment|// Implement LowerOperation for individual opcodes.
name|SDValue
name|lowerSETCC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerBR_CC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerSELECT_CC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerGlobalAddress
argument_list|(
argument|GlobalAddressSDNode *Node
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerGlobalTLSAddress
argument_list|(
argument|GlobalAddressSDNode *Node
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerBlockAddress
argument_list|(
argument|BlockAddressSDNode *Node
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerJumpTable
argument_list|(
argument|JumpTableSDNode *JT
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerConstantPool
argument_list|(
argument|ConstantPoolSDNode *CP
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerVASTART
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerVACOPY
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerDYNAMIC_STACKALLOC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerSMUL_LOHI
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerUMUL_LOHI
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerSDIVREM
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerUDIVREM
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerBITCAST
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerOR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerATOMIC_LOAD
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerATOMIC_CMP_SWAP
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerSTACKSAVE
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerSTACKRESTORE
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerPREFETCH
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|// If the last instruction before MBBI in MBB was some form of COMPARE,
comment|// try to replace it with a COMPARE AND BRANCH just before MBBI.
comment|// CCMask and Target are the BRC-like operands for the branch.
comment|// Return true if the change was made.
name|bool
name|convertPrevCompareToBranch
argument_list|(
argument|MachineBasicBlock *MBB
argument_list|,
argument|MachineBasicBlock::iterator MBBI
argument_list|,
argument|unsigned CCMask
argument_list|,
argument|MachineBasicBlock *Target
argument_list|)
specifier|const
block|;
comment|// Implement EmitInstrWithCustomInserter for individual operation types.
name|MachineBasicBlock
operator|*
name|emitSelect
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitCondStore
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|,
argument|unsigned StoreOpcode
argument_list|,
argument|unsigned STOCOpcode
argument_list|,
argument|bool Invert
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitExt128
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *MBB
argument_list|,
argument|bool ClearEven
argument_list|,
argument|unsigned SubReg
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitAtomicLoadBinary
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|,
argument|unsigned BinOpcode
argument_list|,
argument|unsigned BitSize
argument_list|,
argument|bool Invert = false
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitAtomicLoadMinMax
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *MBB
argument_list|,
argument|unsigned CompareOpcode
argument_list|,
argument|unsigned KeepOldMask
argument_list|,
argument|unsigned BitSize
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitAtomicCmpSwapW
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitMemMemWrapper
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|,
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitStringWrapper
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|,
argument|unsigned Opcode
argument_list|)
specifier|const
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TARGET_SystemZ_ISELLOWERING_H
end_comment

end_unit

