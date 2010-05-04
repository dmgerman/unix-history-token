begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- FastISel.h - Definition of the FastISel class ---------------------===//
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
comment|// This file defines the FastISel class.
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

begin_ifndef
ifndef|#
directive|ifndef
name|NDEBUG
end_ifndef

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

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
name|ConstantFP
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|MachineBasicBlock
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
name|TargetData
decl_stmt|;
name|class
name|TargetInstrInfo
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
comment|/// FastISel - This is a fast-path instruction selection class that
comment|/// generates poor code and doesn't support illegal types or non-trivial
comment|/// lowering, but runs quickly.
name|class
name|FastISel
block|{
name|protected
label|:
name|MachineBasicBlock
modifier|*
name|MBB
decl_stmt|;
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
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
operator|,
name|unsigned
operator|>
operator|&
name|ValueMap
expr_stmt|;
name|DenseMap
operator|<
specifier|const
name|BasicBlock
operator|*
operator|,
name|MachineBasicBlock
operator|*
operator|>
operator|&
name|MBBMap
expr_stmt|;
name|DenseMap
operator|<
specifier|const
name|AllocaInst
operator|*
operator|,
name|int
operator|>
operator|&
name|StaticAllocaMap
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|MachineInstr
operator|*
operator|,
name|unsigned
operator|>
expr|>
operator|&
name|PHINodesToUpdate
expr_stmt|;
ifndef|#
directive|ifndef
name|NDEBUG
name|SmallSet
operator|<
specifier|const
name|Instruction
operator|*
operator|,
literal|8
operator|>
operator|&
name|CatchInfoLost
expr_stmt|;
endif|#
directive|endif
name|MachineFunction
modifier|&
name|MF
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
name|TargetData
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
name|public
label|:
comment|/// startNewBlock - Set the current block to which generated machine
comment|/// instructions will be appended, and clear the local CSE map.
comment|///
name|void
name|startNewBlock
parameter_list|(
name|MachineBasicBlock
modifier|*
name|mbb
parameter_list|)
block|{
name|setCurrentBlock
argument_list|(
name|mbb
argument_list|)
expr_stmt|;
name|LocalValueMap
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
comment|/// setCurrentBlock - Set the current block to which generated machine
comment|/// instructions will be appended.
comment|///
name|void
name|setCurrentBlock
parameter_list|(
name|MachineBasicBlock
modifier|*
name|mbb
parameter_list|)
block|{
name|MBB
operator|=
name|mbb
expr_stmt|;
block|}
comment|/// getCurDebugLoc() - Return current debug location information.
name|DebugLoc
name|getCurDebugLoc
argument_list|()
specifier|const
block|{
return|return
name|DL
return|;
block|}
comment|/// SelectInstruction - Do "fast" instruction selection for the given
comment|/// LLVM IR instruction, and append generated machine instructions to
comment|/// the current block. Return true if selection was successful.
comment|///
name|bool
name|SelectInstruction
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|)
function_decl|;
comment|/// SelectOperator - Do "fast" instruction selection for the given
comment|/// LLVM IR operator (Instruction or ConstantExpr), and append
comment|/// generated machine instructions to the current block. Return true
comment|/// if selection was successful.
comment|///
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
comment|/// getRegForValue - Create a virtual register and arrange for it to
comment|/// be assigned the value for the given LLVM value.
name|unsigned
name|getRegForValue
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// lookUpRegForValue - Look up the value to see if its value is already
comment|/// cached in a register. It may be defined by instructions across blocks or
comment|/// defined locally.
name|unsigned
name|lookUpRegForValue
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// getRegForGEPIndex - This is a wrapper around getRegForValue that also
comment|/// takes care of truncating or sign-extending the given getelementptr
comment|/// index value.
name|unsigned
name|getRegForGEPIndex
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
name|virtual
operator|~
name|FastISel
argument_list|()
expr_stmt|;
name|protected
label|:
name|FastISel
argument_list|(
name|MachineFunction
operator|&
name|mf
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
name|vm
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
name|bm
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
name|am
argument_list|,
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|MachineInstr
operator|*
argument_list|,
name|unsigned
operator|>
expr|>
operator|&
name|PHINodesToUpdate
ifndef|#
directive|ifndef
name|NDEBUG
argument_list|,
name|SmallSet
operator|<
specifier|const
name|Instruction
operator|*
argument_list|,
literal|8
operator|>
operator|&
name|cil
endif|#
directive|endif
argument_list|)
expr_stmt|;
comment|/// TargetSelectInstruction - This method is called by target-independent
comment|/// code when the normal FastISel process fails to select an instruction.
comment|/// This gives targets a chance to emit code for anything that doesn't
comment|/// fit into FastISel's framework. It returns true if it was successful.
comment|///
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
comment|/// FastEmit_r - This method is called by target-independent code
comment|/// to request that an instruction with the given type and opcode
comment|/// be emitted.
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
comment|/// FastEmit_r - This method is called by target-independent code
comment|/// to request that an instruction with the given type, opcode, and
comment|/// register operand be emitted.
comment|///
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
parameter_list|)
function_decl|;
comment|/// FastEmit_rr - This method is called by target-independent code
comment|/// to request that an instruction with the given type, opcode, and
comment|/// register operands be emitted.
comment|///
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
name|unsigned
name|Op1
parameter_list|)
function_decl|;
comment|/// FastEmit_ri - This method is called by target-independent code
comment|/// to request that an instruction with the given type, opcode, and
comment|/// register and immediate operands be emitted.
comment|///
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
name|uint64_t
name|Imm
parameter_list|)
function_decl|;
comment|/// FastEmit_rf - This method is called by target-independent code
comment|/// to request that an instruction with the given type, opcode, and
comment|/// register and floating-point immediate operands be emitted.
comment|///
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
specifier|const
name|ConstantFP
modifier|*
name|FPImm
parameter_list|)
function_decl|;
comment|/// FastEmit_rri - This method is called by target-independent code
comment|/// to request that an instruction with the given type, opcode, and
comment|/// register and immediate operands be emitted.
comment|///
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
name|unsigned
name|Op1
parameter_list|,
name|uint64_t
name|Imm
parameter_list|)
function_decl|;
comment|/// FastEmit_ri_ - This method is a wrapper of FastEmit_ri. It first tries
comment|/// to emit an instruction with an immediate operand using FastEmit_ri.
comment|/// If that fails, it materializes the immediate into a register and try
comment|/// FastEmit_rr instead.
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
name|uint64_t
name|Imm
parameter_list|,
name|MVT
name|ImmType
parameter_list|)
function_decl|;
comment|/// FastEmit_rf_ - This method is a wrapper of FastEmit_rf. It first tries
comment|/// to emit an instruction with an immediate operand using FastEmit_rf.
comment|/// If that fails, it materializes the immediate into a register and try
comment|/// FastEmit_rr instead.
name|unsigned
name|FastEmit_rf_
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
specifier|const
name|ConstantFP
modifier|*
name|FPImm
parameter_list|,
name|MVT
name|ImmType
parameter_list|)
function_decl|;
comment|/// FastEmit_i - This method is called by target-independent code
comment|/// to request that an instruction with the given type, opcode, and
comment|/// immediate operand be emitted.
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
comment|/// FastEmit_f - This method is called by target-independent code
comment|/// to request that an instruction with the given type, opcode, and
comment|/// floating-point immediate operand be emitted.
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
comment|/// FastEmitInst_ - Emit a MachineInstr with no operands and a
comment|/// result register in the given register class.
comment|///
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
comment|/// FastEmitInst_r - Emit a MachineInstr with one register operand
comment|/// and a result register in the given register class.
comment|///
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
parameter_list|)
function_decl|;
comment|/// FastEmitInst_rr - Emit a MachineInstr with two register operands
comment|/// and a result register in the given register class.
comment|///
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
name|unsigned
name|Op1
parameter_list|)
function_decl|;
comment|/// FastEmitInst_ri - Emit a MachineInstr with two register operands
comment|/// and a result register in the given register class.
comment|///
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
name|uint64_t
name|Imm
parameter_list|)
function_decl|;
comment|/// FastEmitInst_rf - Emit a MachineInstr with two register operands
comment|/// and a result register in the given register class.
comment|///
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
specifier|const
name|ConstantFP
modifier|*
name|FPImm
parameter_list|)
function_decl|;
comment|/// FastEmitInst_rri - Emit a MachineInstr with two register operands,
comment|/// an immediate, and a result register in the given register class.
comment|///
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
name|unsigned
name|Op1
parameter_list|,
name|uint64_t
name|Imm
parameter_list|)
function_decl|;
comment|/// FastEmitInst_i - Emit a MachineInstr with a single immediate
comment|/// operand, and a result register in the given register class.
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
comment|/// FastEmitInst_extractsubreg - Emit a MachineInstr for an extract_subreg
comment|/// from a specified index of a superregister to a specified type.
name|unsigned
name|FastEmitInst_extractsubreg
parameter_list|(
name|MVT
name|RetVT
parameter_list|,
name|unsigned
name|Op0
parameter_list|,
name|uint32_t
name|Idx
parameter_list|)
function_decl|;
comment|/// FastEmitZExtFromI1 - Emit MachineInstrs to compute the value of Op
comment|/// with all but the least significant bit set to zero.
name|unsigned
name|FastEmitZExtFromI1
parameter_list|(
name|MVT
name|VT
parameter_list|,
name|unsigned
name|Op
parameter_list|)
function_decl|;
comment|/// FastEmitBranch - Emit an unconditional branch to the given block,
comment|/// unless it is the immediate (fall-through) successor, and update
comment|/// the CFG.
name|void
name|FastEmitBranch
parameter_list|(
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
function_decl|;
name|unsigned
name|UpdateValueMap
parameter_list|(
specifier|const
name|Value
modifier|*
name|I
parameter_list|,
name|unsigned
name|Reg
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
comment|/// TargetMaterializeConstant - Emit a constant in a register using
comment|/// target-specific logic, such as constant pool loads.
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
comment|/// TargetMaterializeAlloca - Emit an alloca address in a register using
comment|/// target-specific logic.
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
comment|/// HandlePHINodesInSuccessorBlocks - Handle PHI nodes in successor blocks.
comment|/// Emit code to ensure constants are copied into registers when needed.
comment|/// Remember the virtual registers that need to be added to the Machine PHI
comment|/// nodes as input.  We cannot just directly add them, because expansion
comment|/// might result in multiple MBB's for one BB.  As such, the start of the
comment|/// BB might correspond to a different MBB than the end.
name|bool
name|HandlePHINodesInSuccessorBlocks
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|LLVMBB
parameter_list|)
function_decl|;
comment|/// materializeRegForValue - Helper for getRegForVale. This function is
comment|/// called when the value isn't already available in a register and must
comment|/// be materialized with new instructions.
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
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

