begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- FastISel.h - Definition of the FastISel class ---*- C++ -*---------===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// This file defines the FastISel class.
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
name|LLVM_CODEGEN_FASTISEL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_FASTISEL_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ValueTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AllocaInst
decl_stmt|;
name|class
name|Constant
decl_stmt|;
name|class
name|ConstantFP
decl_stmt|;
name|class
name|FunctionLoweringInfo
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|LoadInst
decl_stmt|;
name|class
name|MachineConstantPool
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineFrameInfo
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|TargetLibraryInfo
decl_stmt|;
name|class
name|TargetLowering
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|TargetRegisterClass
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|User
decl_stmt|;
name|class
name|Value
decl_stmt|;
comment|/// This is a fast-path instruction selection class that generates poor code and
comment|/// doesn't support illegal types or non-trivial lowering, but runs quickly.
name|class
name|FastISel
block|{
name|protected
label|:
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
operator|,
name|unsigned
operator|>
name|LocalValueMap
expr_stmt|;
name|FunctionLoweringInfo
modifier|&
name|FuncInfo
decl_stmt|;
name|MachineRegisterInfo
modifier|&
name|MRI
decl_stmt|;
name|MachineFrameInfo
modifier|&
name|MFI
decl_stmt|;
name|MachineConstantPool
modifier|&
name|MCP
decl_stmt|;
name|DebugLoc
name|DL
decl_stmt|;
specifier|const
name|TargetMachine
modifier|&
name|TM
decl_stmt|;
specifier|const
name|DataLayout
modifier|&
name|TD
decl_stmt|;
specifier|const
name|TargetInstrInfo
modifier|&
name|TII
decl_stmt|;
specifier|const
name|TargetLowering
modifier|&
name|TLI
decl_stmt|;
specifier|const
name|TargetRegisterInfo
modifier|&
name|TRI
decl_stmt|;
specifier|const
name|TargetLibraryInfo
modifier|*
name|LibInfo
decl_stmt|;
comment|/// The position of the last instruction for materializing constants for use
comment|/// in the current block. It resets to EmitStartPt when it makes sense (for
comment|/// example, it's usually profitable to avoid function calls between the
comment|/// definition and the use)
name|MachineInstr
modifier|*
name|LastLocalValue
decl_stmt|;
comment|/// The top most instruction in the current block that is allowed for emitting
comment|/// local variables. LastLocalValue resets to EmitStartPt when it makes sense
comment|/// (for example, on function calls)
name|MachineInstr
modifier|*
name|EmitStartPt
decl_stmt|;
name|public
label|:
comment|/// Return the position of the last instruction emitted for materializing
comment|/// constants for use in the current block.
name|MachineInstr
modifier|*
name|getLastLocalValue
parameter_list|()
block|{
return|return
name|LastLocalValue
return|;
block|}
comment|/// Update the position of the last instruction emitted for materializing
comment|/// constants for use in the current block.
name|void
name|setLastLocalValue
parameter_list|(
name|MachineInstr
modifier|*
name|I
parameter_list|)
block|{
name|EmitStartPt
operator|=
name|I
expr_stmt|;
name|LastLocalValue
operator|=
name|I
expr_stmt|;
block|}
comment|/// Set the current block to which generated machine instructions will be
comment|/// appended, and clear the local CSE map.
name|void
name|startNewBlock
parameter_list|()
function_decl|;
comment|/// Return current debug location information.
name|DebugLoc
name|getCurDebugLoc
argument_list|()
specifier|const
block|{
return|return
name|DL
return|;
block|}
comment|/// Do "fast" instruction selection for function arguments and append machine
comment|/// instructions to the current block. Return true if it is successful.
name|bool
name|LowerArguments
parameter_list|()
function_decl|;
comment|/// Do "fast" instruction selection for the given LLVM IR instruction, and
comment|/// append generated machine instructions to the current block. Return true if
comment|/// selection was successful.
name|bool
name|SelectInstruction
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|)
function_decl|;
comment|/// Do "fast" instruction selection for the given LLVM IR operator
comment|/// (Instruction or ConstantExpr), and append generated machine instructions
comment|/// to the current block. Return true if selection was successful.
name|bool
name|SelectOperator
parameter_list|(
specifier|const
name|User
modifier|*
name|I
parameter_list|,
name|unsigned
name|Opcode
parameter_list|)
function_decl|;
comment|/// Create a virtual register and arrange for it to be assigned the value for
comment|/// the given LLVM value.
name|unsigned
name|getRegForValue
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// Look up the value to see if its value is already cached in a register. It
comment|/// may be defined by instructions across blocks or defined locally.
name|unsigned
name|lookUpRegForValue
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// This is a wrapper around getRegForValue that also takes care of truncating
comment|/// or sign-extending the given getelementptr index value.
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|bool
operator|>
name|getRegForGEPIndex
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|)
expr_stmt|;
comment|/// \brief We're checking to see if we can fold \p LI into \p FoldInst. Note
comment|/// that we could have a sequence where multiple LLVM IR instructions are
comment|/// folded into the same machineinstr.  For example we could have:
comment|///
comment|///   A: x = load i32 *P
comment|///   B: y = icmp A, 42
comment|///   C: br y, ...
comment|///
comment|/// In this scenario, \p LI is "A", and \p FoldInst is "C".  We know about "B"
comment|/// (and any other folded instructions) because it is between A and C.
comment|///
comment|/// If we succeed folding, return true.
name|bool
name|tryToFoldLoad
parameter_list|(
specifier|const
name|LoadInst
modifier|*
name|LI
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|FoldInst
parameter_list|)
function_decl|;
comment|/// \brief The specified machine instr operand is a vreg, and that vreg is
comment|/// being provided by the specified load instruction.  If possible, try to
comment|/// fold the load as an operand to the instruction, returning true if
comment|/// possible.
comment|///
comment|/// This method should be implemented by targets.
name|virtual
name|bool
name|tryToFoldLoadIntoMI
parameter_list|(
name|MachineInstr
modifier|*
comment|/*MI*/
parameter_list|,
name|unsigned
comment|/*OpNo*/
parameter_list|,
specifier|const
name|LoadInst
modifier|*
comment|/*LI*/
parameter_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// Reset InsertPt to prepare for inserting instructions into the current
comment|/// block.
name|void
name|recomputeInsertPt
parameter_list|()
function_decl|;
comment|/// Remove all dead instructions between the I and E.
name|void
name|removeDeadCode
argument_list|(
name|MachineBasicBlock
operator|::
name|iterator
name|I
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|E
argument_list|)
decl_stmt|;
struct|struct
name|SavePoint
block|{
name|MachineBasicBlock
operator|::
name|iterator
name|InsertPt
expr_stmt|;
name|DebugLoc
name|DL
decl_stmt|;
block|}
struct|;
comment|/// Prepare InsertPt to begin inserting instructions into the local value area
comment|/// and return the old insert position.
name|SavePoint
name|enterLocalValueArea
parameter_list|()
function_decl|;
comment|/// Reset InsertPt to the given old insert position.
name|void
name|leaveLocalValueArea
parameter_list|(
name|SavePoint
name|Old
parameter_list|)
function_decl|;
name|virtual
operator|~
name|FastISel
argument_list|()
expr_stmt|;
name|protected
label|:
name|explicit
name|FastISel
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
comment|/// This method is called by target-independent code when the normal FastISel
comment|/// process fails to select an instruction.  This gives targets a chance to
comment|/// emit code for anything that doesn't fit into FastISel's framework. It
comment|/// returns true if it was successful.
name|virtual
name|bool
name|TargetSelectInstruction
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// This method is called by target-independent code to do target specific
comment|/// argument lowering. It returns true if it was successful.
name|virtual
name|bool
name|FastLowerArguments
parameter_list|()
function_decl|;
comment|/// This method is called by target-independent code to request that an
comment|/// instruction with the given type and opcode be emitted.
name|virtual
name|unsigned
name|FastEmit_
parameter_list|(
name|MVT
name|VT
parameter_list|,
name|MVT
name|RetVT
parameter_list|,
name|unsigned
name|Opcode
parameter_list|)
function_decl|;
comment|/// This method is called by target-independent code to request that an
comment|/// instruction with the given type, opcode, and register operand be emitted.
name|virtual
name|unsigned
name|FastEmit_r
parameter_list|(
name|MVT
name|VT
parameter_list|,
name|MVT
name|RetVT
parameter_list|,
name|unsigned
name|Opcode
parameter_list|,
name|unsigned
name|Op0
parameter_list|,
name|bool
name|Op0IsKill
parameter_list|)
function_decl|;
comment|/// This method is called by target-independent code to request that an
comment|/// instruction with the given type, opcode, and register operands be emitted.
name|virtual
name|unsigned
name|FastEmit_rr
parameter_list|(
name|MVT
name|VT
parameter_list|,
name|MVT
name|RetVT
parameter_list|,
name|unsigned
name|Opcode
parameter_list|,
name|unsigned
name|Op0
parameter_list|,
name|bool
name|Op0IsKill
parameter_list|,
name|unsigned
name|Op1
parameter_list|,
name|bool
name|Op1IsKill
parameter_list|)
function_decl|;
comment|/// This method is called by target-independent code to request that an
comment|/// instruction with the given type, opcode, and register and immediate
comment|/// operands be emitted.
name|virtual
name|unsigned
name|FastEmit_ri
parameter_list|(
name|MVT
name|VT
parameter_list|,
name|MVT
name|RetVT
parameter_list|,
name|unsigned
name|Opcode
parameter_list|,
name|unsigned
name|Op0
parameter_list|,
name|bool
name|Op0IsKill
parameter_list|,
name|uint64_t
name|Imm
parameter_list|)
function_decl|;
comment|/// This method is called by target-independent code to request that an
comment|/// instruction with the given type, opcode, and register and floating-point
comment|/// immediate operands be emitted.
name|virtual
name|unsigned
name|FastEmit_rf
parameter_list|(
name|MVT
name|VT
parameter_list|,
name|MVT
name|RetVT
parameter_list|,
name|unsigned
name|Opcode
parameter_list|,
name|unsigned
name|Op0
parameter_list|,
name|bool
name|Op0IsKill
parameter_list|,
specifier|const
name|ConstantFP
modifier|*
name|FPImm
parameter_list|)
function_decl|;
comment|/// This method is called by target-independent code to request that an
comment|/// instruction with the given type, opcode, and register and immediate
comment|/// operands be emitted.
name|virtual
name|unsigned
name|FastEmit_rri
parameter_list|(
name|MVT
name|VT
parameter_list|,
name|MVT
name|RetVT
parameter_list|,
name|unsigned
name|Opcode
parameter_list|,
name|unsigned
name|Op0
parameter_list|,
name|bool
name|Op0IsKill
parameter_list|,
name|unsigned
name|Op1
parameter_list|,
name|bool
name|Op1IsKill
parameter_list|,
name|uint64_t
name|Imm
parameter_list|)
function_decl|;
comment|/// \brief This method is a wrapper of FastEmit_ri.
comment|///
comment|/// It first tries to emit an instruction with an immediate operand using
comment|/// FastEmit_ri.  If that fails, it materializes the immediate into a register
comment|/// and try FastEmit_rr instead.
name|unsigned
name|FastEmit_ri_
parameter_list|(
name|MVT
name|VT
parameter_list|,
name|unsigned
name|Opcode
parameter_list|,
name|unsigned
name|Op0
parameter_list|,
name|bool
name|Op0IsKill
parameter_list|,
name|uint64_t
name|Imm
parameter_list|,
name|MVT
name|ImmType
parameter_list|)
function_decl|;
comment|/// This method is called by target-independent code to request that an
comment|/// instruction with the given type, opcode, and immediate operand be emitted.
name|virtual
name|unsigned
name|FastEmit_i
parameter_list|(
name|MVT
name|VT
parameter_list|,
name|MVT
name|RetVT
parameter_list|,
name|unsigned
name|Opcode
parameter_list|,
name|uint64_t
name|Imm
parameter_list|)
function_decl|;
comment|/// This method is called by target-independent code to request that an
comment|/// instruction with the given type, opcode, and floating-point immediate
comment|/// operand be emitted.
name|virtual
name|unsigned
name|FastEmit_f
parameter_list|(
name|MVT
name|VT
parameter_list|,
name|MVT
name|RetVT
parameter_list|,
name|unsigned
name|Opcode
parameter_list|,
specifier|const
name|ConstantFP
modifier|*
name|FPImm
parameter_list|)
function_decl|;
comment|/// Emit a MachineInstr with no operands and a result register in the given
comment|/// register class.
name|unsigned
name|FastEmitInst_
parameter_list|(
name|unsigned
name|MachineInstOpcode
parameter_list|,
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
parameter_list|)
function_decl|;
comment|/// Emit a MachineInstr with one register operand and a result register in the
comment|/// given register class.
name|unsigned
name|FastEmitInst_r
parameter_list|(
name|unsigned
name|MachineInstOpcode
parameter_list|,
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
parameter_list|,
name|unsigned
name|Op0
parameter_list|,
name|bool
name|Op0IsKill
parameter_list|)
function_decl|;
comment|/// Emit a MachineInstr with two register operands and a result register in
comment|/// the given register class.
name|unsigned
name|FastEmitInst_rr
parameter_list|(
name|unsigned
name|MachineInstOpcode
parameter_list|,
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
parameter_list|,
name|unsigned
name|Op0
parameter_list|,
name|bool
name|Op0IsKill
parameter_list|,
name|unsigned
name|Op1
parameter_list|,
name|bool
name|Op1IsKill
parameter_list|)
function_decl|;
comment|/// Emit a MachineInstr with three register operands and a result register in
comment|/// the given register class.
name|unsigned
name|FastEmitInst_rrr
parameter_list|(
name|unsigned
name|MachineInstOpcode
parameter_list|,
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
parameter_list|,
name|unsigned
name|Op0
parameter_list|,
name|bool
name|Op0IsKill
parameter_list|,
name|unsigned
name|Op1
parameter_list|,
name|bool
name|Op1IsKill
parameter_list|,
name|unsigned
name|Op2
parameter_list|,
name|bool
name|Op2IsKill
parameter_list|)
function_decl|;
comment|/// Emit a MachineInstr with a register operand, an immediate, and a result
comment|/// register in the given register class.
name|unsigned
name|FastEmitInst_ri
parameter_list|(
name|unsigned
name|MachineInstOpcode
parameter_list|,
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
parameter_list|,
name|unsigned
name|Op0
parameter_list|,
name|bool
name|Op0IsKill
parameter_list|,
name|uint64_t
name|Imm
parameter_list|)
function_decl|;
comment|/// Emit a MachineInstr with one register operand and two immediate operands.
name|unsigned
name|FastEmitInst_rii
parameter_list|(
name|unsigned
name|MachineInstOpcode
parameter_list|,
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
parameter_list|,
name|unsigned
name|Op0
parameter_list|,
name|bool
name|Op0IsKill
parameter_list|,
name|uint64_t
name|Imm1
parameter_list|,
name|uint64_t
name|Imm2
parameter_list|)
function_decl|;
comment|/// Emit a MachineInstr with two register operands and a result register in
comment|/// the given register class.
name|unsigned
name|FastEmitInst_rf
parameter_list|(
name|unsigned
name|MachineInstOpcode
parameter_list|,
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
parameter_list|,
name|unsigned
name|Op0
parameter_list|,
name|bool
name|Op0IsKill
parameter_list|,
specifier|const
name|ConstantFP
modifier|*
name|FPImm
parameter_list|)
function_decl|;
comment|/// Emit a MachineInstr with two register operands, an immediate, and a result
comment|/// register in the given register class.
name|unsigned
name|FastEmitInst_rri
parameter_list|(
name|unsigned
name|MachineInstOpcode
parameter_list|,
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
parameter_list|,
name|unsigned
name|Op0
parameter_list|,
name|bool
name|Op0IsKill
parameter_list|,
name|unsigned
name|Op1
parameter_list|,
name|bool
name|Op1IsKill
parameter_list|,
name|uint64_t
name|Imm
parameter_list|)
function_decl|;
comment|/// Emit a MachineInstr with two register operands, two immediates operands,
comment|/// and a result register in the given register class.
name|unsigned
name|FastEmitInst_rrii
parameter_list|(
name|unsigned
name|MachineInstOpcode
parameter_list|,
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
parameter_list|,
name|unsigned
name|Op0
parameter_list|,
name|bool
name|Op0IsKill
parameter_list|,
name|unsigned
name|Op1
parameter_list|,
name|bool
name|Op1IsKill
parameter_list|,
name|uint64_t
name|Imm1
parameter_list|,
name|uint64_t
name|Imm2
parameter_list|)
function_decl|;
comment|/// Emit a MachineInstr with a single immediate operand, and a result register
comment|/// in the given register class.
name|unsigned
name|FastEmitInst_i
parameter_list|(
name|unsigned
name|MachineInstrOpcode
parameter_list|,
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
parameter_list|,
name|uint64_t
name|Imm
parameter_list|)
function_decl|;
comment|/// Emit a MachineInstr with a two immediate operands.
name|unsigned
name|FastEmitInst_ii
parameter_list|(
name|unsigned
name|MachineInstrOpcode
parameter_list|,
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
parameter_list|,
name|uint64_t
name|Imm1
parameter_list|,
name|uint64_t
name|Imm2
parameter_list|)
function_decl|;
comment|/// Emit a MachineInstr for an extract_subreg from a specified index of a
comment|/// superregister to a specified type.
name|unsigned
name|FastEmitInst_extractsubreg
parameter_list|(
name|MVT
name|RetVT
parameter_list|,
name|unsigned
name|Op0
parameter_list|,
name|bool
name|Op0IsKill
parameter_list|,
name|uint32_t
name|Idx
parameter_list|)
function_decl|;
comment|/// Emit MachineInstrs to compute the value of Op with all but the least
comment|/// significant bit set to zero.
name|unsigned
name|FastEmitZExtFromI1
parameter_list|(
name|MVT
name|VT
parameter_list|,
name|unsigned
name|Op0
parameter_list|,
name|bool
name|Op0IsKill
parameter_list|)
function_decl|;
comment|/// Emit an unconditional branch to the given block, unless it is the
comment|/// immediate (fall-through) successor, and update the CFG.
name|void
name|FastEmitBranch
parameter_list|(
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|,
name|DebugLoc
name|DL
parameter_list|)
function_decl|;
name|void
name|UpdateValueMap
parameter_list|(
specifier|const
name|Value
modifier|*
name|I
parameter_list|,
name|unsigned
name|Reg
parameter_list|,
name|unsigned
name|NumRegs
init|=
literal|1
parameter_list|)
function_decl|;
name|unsigned
name|createResultReg
parameter_list|(
specifier|const
name|TargetRegisterClass
modifier|*
name|RC
parameter_list|)
function_decl|;
comment|/// Emit a constant in a register using target-specific logic, such as
comment|/// constant pool loads.
name|virtual
name|unsigned
name|TargetMaterializeConstant
parameter_list|(
specifier|const
name|Constant
modifier|*
name|C
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
comment|/// Emit an alloca address in a register using target-specific logic.
name|virtual
name|unsigned
name|TargetMaterializeAlloca
parameter_list|(
specifier|const
name|AllocaInst
modifier|*
name|C
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
name|virtual
name|unsigned
name|TargetMaterializeFloatZero
parameter_list|(
specifier|const
name|ConstantFP
modifier|*
name|CF
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
comment|/// \brief Check if \c Add is an add that can be safely folded into \c GEP.
comment|///
comment|/// \c Add can be folded into \c GEP if:
comment|/// - \c Add is an add,
comment|/// - \c Add's size matches \c GEP's,
comment|/// - \c Add is in the same basic block as \c GEP, and
comment|/// - \c Add has a constant operand.
name|bool
name|canFoldAddIntoGEP
parameter_list|(
specifier|const
name|User
modifier|*
name|GEP
parameter_list|,
specifier|const
name|Value
modifier|*
name|Add
parameter_list|)
function_decl|;
name|private
label|:
name|bool
name|SelectBinaryOp
parameter_list|(
specifier|const
name|User
modifier|*
name|I
parameter_list|,
name|unsigned
name|ISDOpcode
parameter_list|)
function_decl|;
name|bool
name|SelectFNeg
parameter_list|(
specifier|const
name|User
modifier|*
name|I
parameter_list|)
function_decl|;
name|bool
name|SelectGetElementPtr
parameter_list|(
specifier|const
name|User
modifier|*
name|I
parameter_list|)
function_decl|;
name|bool
name|SelectCall
parameter_list|(
specifier|const
name|User
modifier|*
name|I
parameter_list|)
function_decl|;
name|bool
name|SelectBitCast
parameter_list|(
specifier|const
name|User
modifier|*
name|I
parameter_list|)
function_decl|;
name|bool
name|SelectCast
parameter_list|(
specifier|const
name|User
modifier|*
name|I
parameter_list|,
name|unsigned
name|Opcode
parameter_list|)
function_decl|;
name|bool
name|SelectExtractValue
parameter_list|(
specifier|const
name|User
modifier|*
name|I
parameter_list|)
function_decl|;
name|bool
name|SelectInsertValue
parameter_list|(
specifier|const
name|User
modifier|*
name|I
parameter_list|)
function_decl|;
comment|/// \brief Handle PHI nodes in successor blocks.
comment|///
comment|/// Emit code to ensure constants are copied into registers when needed.
comment|/// Remember the virtual registers that need to be added to the Machine PHI
comment|/// nodes as input.  We cannot just directly add them, because expansion might
comment|/// result in multiple MBB's for one BB.  As such, the start of the BB might
comment|/// correspond to a different MBB than the end.
name|bool
name|HandlePHINodesInSuccessorBlocks
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|LLVMBB
parameter_list|)
function_decl|;
comment|/// Helper for getRegForVale. This function is called when the value isn't
comment|/// already available in a register and must be materialized with new
comment|/// instructions.
name|unsigned
name|materializeRegForValue
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|,
name|MVT
name|VT
parameter_list|)
function_decl|;
comment|/// Clears LocalValueMap and moves the area for the new local variables to the
comment|/// beginning of the block. It helps to avoid spilling cached variables across
comment|/// heavy instructions like calls.
name|void
name|flushLocalValueMap
parameter_list|()
function_decl|;
comment|/// Test whether the given value has exactly one use.
name|bool
name|hasTrivialKill
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

